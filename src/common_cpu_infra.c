#include "common_cpu_infra.h"
#include "types.h"
#include "common_rtl.h"
#include "snes/cpu.h"
#include "snes/snes.h"
#include "tracing.h"
#include "util.h"
#include <time.h>

enum RunMode { RM_BOTH, RM_MINE, RM_THEIRS };
uint8 g_runmode = RM_BOTH;

extern int g_got_mismatch_count;

Snes *g_snes;
Cpu *g_cpu;

bool g_calling_asm_from_c;
int g_calling_asm_from_c_ret;
bool g_fail;
bool g_use_my_apu_code = true;
extern bool g_other_image;
const RtlGameInfo *g_rtl_game_info;

static Snapshot g_snapshot_mine, g_snapshot_theirs, g_snapshot_before;
static uint32 hookmode, hookcnt, hookadr;
static uint32 hooked_func_pc;
static uint8 hook_orgbyte[1024];
static uint8 hook_fixbug_orgbyte[1024];
static uint8 kPatchedCarrysOrg[1024];

static void VerifySnapshotsEq(Snapshot *b, Snapshot *a, Snapshot *prev);
static void MakeSnapshot(Snapshot *s);
static void RestoreSnapshot(Snapshot *s);

uint8_t *SnesRomPtr(uint32 v) {
  return (uint8 *)RomPtr(v);
}

bool ProcessHook(uint32 v) {
  uint8_t *rombyte = SnesRomPtr(v);
  switch (hookmode) {
  case 0: // remove hooks
    *rombyte = hook_orgbyte[hookcnt++];
    return false;
  case 1: // install hooks
    hook_orgbyte[hookcnt++] = *rombyte;
    *rombyte = 0;
    return false;
  case 2:  // run hook
    if (v == hookadr) {
      hookmode = 3;
      return true;
    }
    return false;
  }
  return false;
}

bool FixBugHook(uint32 addr) {
  switch (hookmode) {
  case 1: { // install hooks
    uint8_t *rombyte = SnesRomPtr(addr);
    hook_fixbug_orgbyte[hookcnt++] = *rombyte;
    *rombyte = 0;
    return false;
  }
  case 2:  // run hook
    if (addr == hookadr) {
      hookmode = 3;
      return true;
    }
    hookcnt++;
    return false;
  }
  return false;
}

uint32 PatchBugs(uint32 mode, uint32 addr) {
  hookmode = mode, hookadr = addr, hookcnt = 0;
  return g_rtl_game_info->patch_bugs();
}

int RunPatchBugHook(uint32 addr) {
  uint32 new_pc = PatchBugs(2, addr);
  if (hookmode == 3) {
    if (new_pc == 0) {
      return hook_fixbug_orgbyte[hookcnt];
    } else {
      g_cpu->k = new_pc >> 16;
      g_cpu->pc = (new_pc & 0xffff) + 1;
      return *SnesRomPtr(new_pc);
    }
  }
  return -1;
}

int CpuOpcodeHook(uint32 addr) {
  for (size_t i = 0; i != g_rtl_game_info->patch_carrys_count; i++) {
    if (addr == g_rtl_game_info->patch_carrys[i]) {
      return kPatchedCarrysOrg[i];
    }
  }
  {
    int i = RunPatchBugHook(addr);
    if (i >= 0) return i;
  }
  printf("Bad hook at 0x%x!\n", addr);
  assert(0);
  return 0;
}

bool HookedFunctionRts(int is_long) {
  if (g_calling_asm_from_c) {
    g_calling_asm_from_c_ret = is_long;
    g_calling_asm_from_c = false;
    return false;
  }
  assert(0);
  return false;
}

static void VerifySnapshotsEq(Snapshot *b, Snapshot *a, Snapshot *prev) {
  if (memcmp(b->ram, a->ram, 0x20000)) {
    fprintf(stderr, "@%d: Memory compare failed (mine != theirs, prev):\n", snes_frame_counter);
    int j = 0;
    for (size_t i = 0; i < 0x20000; i++) {
      if (a->ram[i] != b->ram[i]) {
        if (++j < 256*10) {
          if (((i & 1) == 0 || i < 0x10000) && a->ram[i + 1] != b->ram[i + 1]) {
            fprintf(stderr, "0x%.6X: %.4X != %.4X (%.4X)\n", (int)i,
              WORD(b->ram[i]), WORD(a->ram[i]), WORD(prev->ram[i]));
            i++, j++;
          } else {
            fprintf(stderr, "0x%.6X: %.2X != %.2X (%.2X)\n", (int)i, b->ram[i], a->ram[i], prev->ram[i]);
          }
        }
      }
    }
    if (j)
      g_fail = true;
    fprintf(stderr, "  total of %d failed bytes\n", (int)j);
  }

  if (memcmp(b->sram, a->sram, 0x2000)) {
    fprintf(stderr, "@%d: SRAM compare failed (mine != theirs, prev):\n", snes_frame_counter);
    int j = 0;
    for (size_t i = 0; i < 0x2000; i++) {
      if (a->sram[i] != b->sram[i]) {
        if (++j < 128) {
          if ((i & 1) == 0 && a->sram[i + 1] != b->sram[i + 1]) {
            fprintf(stderr, "0x%.6X: %.4X != %.4X (%.4X)\n", (int)i,
              WORD(b->sram[i]), WORD(a->sram[i]), WORD(prev->sram[i]));
            i++, j++;
          } else {
            fprintf(stderr, "0x%.6X: %.2X != %.2X (%.2X)\n", (int)i, b->sram[i], a->sram[i], prev->sram[i]);
          }
        }
      }
    }
    if (j)
      g_fail = true;
    fprintf(stderr, "  total of %d failed bytes\n", (int)j);
  }
#if 1
  if (memcmp(b->vram, a->vram, sizeof(uint16) * 0x8000)) {
    fprintf(stderr, "@%d: VRAM compare failed (mine != theirs, prev):\n", snes_frame_counter);
    for (size_t i = 0, j = 0; i < 0x8000; i++) {
      if (a->vram[i] != b->vram[i]) {
        fprintf(stderr, "0x%.6X: %.4X != %.4X (%.4X)\n", (int)i, b->vram[i], a->vram[i], prev->vram[i]);
        g_fail = true;
        if (++j >= 32)
          break;
      }
    }
  }
  if (memcmp(b->oam, a->oam, sizeof(uint16) * 0x120)) {
    fprintf(stderr, "@%d: VRAM OAM compare failed (mine != theirs, prev):\n", snes_frame_counter);
    for (size_t i = 0, j = 0; i < 0x120; i++) {
      if (a->oam[i] != b->oam[i]) {
        fprintf(stderr, "0x%.6X: %.4X != %.4X (%.4X)\n", (int)i, b->oam[i], a->oam[i], prev->oam[i]);
        g_fail = true;
        if (++j >= 16)
          break;
      }
    }
  }

  if (memcmp(b->cgram, a->cgram, sizeof(uint16) * 0x100)) {
    fprintf(stderr, "@%d: VRAM cgram compare failed (mine != theirs, prev):\n", snes_frame_counter);
    for (size_t i = 0, j = 0; i < 0x100; i++) {
      if (a->cgram[i] != b->cgram[i]) {
        fprintf(stderr, "0x%.6X: %.4X != %.4X (%.4X)\n", (int)i, b->cgram[i], a->cgram[i], prev->cgram[i]);
        g_fail = true;
        if (++j >= 16)
          break;
      }
    }
  }


#endif
}

static void MakeSnapshot(Snapshot *s) {
  Cpu *c = g_cpu;
  s->a = c->a, s->x = c->x, s->y = c->y;
  s->sp = c->sp, s->dp = c->dp, s->db = c->db;
  s->pc = c->pc, s->k = c->k;
  s->flags = cpu_getFlags(c);
  s->vTimer = g_snes->vTimer;
  memcpy(s->ram, g_snes->ram, 0x20000);
  memcpy(s->sram, g_snes->cart->ram, g_snes->cart->ramSize);
  memcpy(s->vram, g_ppu->vram, sizeof(uint16) * 0x8000);
  memcpy(s->oam, g_ppu->oam, sizeof(uint16) * 0x120);
  memcpy(s->cgram, g_ppu->cgram, sizeof(uint16) * 0x100);
}

static void MakeMySnapshot(Snapshot *s) {
  memcpy(s->ram, g_snes->ram, 0x20000);
  memcpy(s->sram, g_snes->cart->ram, g_snes->cart->ramSize);
  memcpy(s->vram, g_ppu->vram, sizeof(uint16) * 0x8000);
  memcpy(s->oam, g_ppu->oam, sizeof(uint16) * 0x120);
  memcpy(s->cgram, g_ppu->cgram, sizeof(uint16) * 0x100);
}

static void RestoreSnapshot(Snapshot *s) {
  Cpu *c = g_cpu;
  c->a = s->a, c->x = s->x, c->y = s->y;
  c->sp = s->sp, c->dp = s->dp, c->db = s->db;
  c->pc = s->pc, c->k = s->k;
  g_snes->vTimer = s->vTimer;
  cpu_setFlags(c, s->flags);
  memcpy(g_snes->ram, s->ram, 0x20000);
  memcpy(g_snes->cart->ram, s->sram, g_snes->cart->ramSize);
  memcpy(g_ppu->vram, s->vram, sizeof(uint16) * 0x8000);
  memcpy(g_ppu->oam, s->oam, sizeof(uint16) * 0x120);
  memcpy(g_ppu->cgram, s->cgram, sizeof(uint16) * 0x100);
}

static void FixupCarry(uint32 addr) {
  *SnesRomPtr(addr) = 0;
}
  
Snes *SnesInit(const uint8 *data, int data_size) {
  g_my_ppu = ppu_init();
  ppu_reset(g_my_ppu);

  g_snes = snes_init(g_ram);
  g_cpu = g_snes->cpu;
  g_dma = g_snes->dma;
  g_use_my_apu_code = (g_runmode != RM_THEIRS);

  if (data_size != 0 && g_runmode != RM_MINE) {
    bool loaded = snes_loadRom(g_snes, data, data_size);
    if (!loaded) {
      return NULL;
    }
    g_rom = g_snes->cart->rom;

    if (memcmp(g_rom + 0x7fc0, "Super Mario Bros. LL ", 21) == 0) {
      g_rtl_game_info = &kSmbllGameInfo;
    } else if (memcmp(g_rom + 0x7fc0, "Super Mario Bros. 1  ", 21) == 0) {
      g_rtl_game_info = &kSmb1GameInfo;
    } else {
      g_rtl_game_info = &kSmwGameInfo;
    }

    for (size_t i = 0; i != g_rtl_game_info->patch_carrys_count; i++) {
      uint8 t = *SnesRomPtr(g_rtl_game_info->patch_carrys[i]);
      if (t) {
        kPatchedCarrysOrg[i] = t;
        FixupCarry(g_rtl_game_info->patch_carrys[i]);
      } else {
        printf("0x%x double patched!\n", g_rtl_game_info->patch_carrys[i]);
      }
    }
    g_rtl_game_info->initialize();
    snes_reset(g_snes, true); // reset after loading
    PatchBugs(1, 0);
  } else {
    g_runmode = RM_MINE;
    g_snes->cart->ramSize = 2048;
    g_snes->cart->ram = calloc(1, 2048);
    g_rtl_game_info = &kSmwGameInfo;
    g_rtl_game_info->initialize();
    ppu_reset(g_snes->ppu);
    dma_reset(g_snes->dma);
  }

  g_sram = g_snes->cart->ram;
  g_sram_size = g_snes->cart->ramSize;
  game_id = g_rtl_game_info->game_id;
  

  return g_snes;
}

void SaveBugSnapshot() {
  if (!g_debug_flag && g_got_mismatch_count == 0) {
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "saves/%s-bug-%d.sav", g_rtl_game_info->title, (int)time(NULL));
    RtlSaveSnapshot(buffer, true);
  }
  g_got_mismatch_count = 5 * 60;
}

int g_dbg_ctr_mine, g_dbg_ctr_theirs;

void RunOneFrameOfGame_Both(void) {
  g_ppu = g_snes->ppu;
  MakeSnapshot(&g_snapshot_before);

  // Run orig version then snapshot
again_theirs:
  g_dbg_ctr_mine = g_dbg_ctr_theirs = 0;
  g_snes->runningWhichVersion = 1;
  g_rtl_game_info->run_frame_emulated();
  MakeSnapshot(&g_snapshot_theirs);

  // Run my version and snapshot
//again_mine:
  g_ppu = g_my_ppu;
  RestoreSnapshot(&g_snapshot_before);

  g_snes->runningWhichVersion = 2;
  g_rtl_game_info->run_frame();
  MakeSnapshot(&g_snapshot_mine);

  g_snes->runningWhichVersion = 0xff;

  // Compare both snapshots
  g_rtl_game_info->fix_snapshot_for_compare(&g_snapshot_mine, &g_snapshot_theirs);
  VerifySnapshotsEq(&g_snapshot_mine, &g_snapshot_theirs, &g_snapshot_before);

  if (g_fail) {
    g_fail = false;

    printf("Verify failure!\n");

    g_ppu = g_snes->ppu;
    RestoreSnapshot(&g_snapshot_before);

    if (g_debug_flag)
      goto again_theirs;

    SaveBugSnapshot();
    g_rtl_game_info->run_frame_emulated();
    goto getout;
  }

  g_ppu = g_snes->ppu;
  RestoreSnapshot(&g_snapshot_theirs);
getout:
  g_ppu = g_other_image ? g_my_ppu : g_snes->ppu;
  g_snes->runningWhichVersion = 0;

  if (g_got_mismatch_count)
    g_got_mismatch_count--;
}

void RtlRunFrameCompare() {
  g_use_my_apu_code = (g_runmode != RM_THEIRS);

  if (g_runmode == RM_THEIRS) {
    g_ppu = g_snes->ppu;
    g_snes->runningWhichVersion = 1;
    g_rtl_game_info->run_frame_emulated();
    g_snes->runningWhichVersion = 0;
  } else if (g_runmode == RM_MINE) {
    g_ppu = g_my_ppu;
    g_snes->runningWhichVersion = 2;
    g_rtl_game_info->run_frame();
    g_snes->runningWhichVersion = 0;
  } else {
    RunOneFrameOfGame_Both();
  }
}
