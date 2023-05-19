#include "smw_cpu_infra.h"
#include "smw_rtl.h"
#include "types.h"
#include "snes/cpu.h"
#include "snes/snes.h"
#include "tracing.h"
#include "variables.h"
#include "funcs.h"

#include "util.h"
#include <time.h>

uint8 bug_fix_counter;

void RtlRunFrameCompare(uint16 input, int run_what);

enum RunMode { RM_BOTH, RM_MINE, RM_THEIRS };
uint8 g_runmode = RM_BOTH;

extern int g_got_mismatch_count;

Snes *g_snes;
Cpu *g_cpu;

bool g_calling_asm_from_c;
int g_calling_asm_from_c_ret;
bool g_fail;
bool g_use_my_apu_code = false;
extern bool g_other_image;

typedef struct Snapshot {
  uint16 a, x, y, sp, dp, pc;
  uint8 k, db, flags;

  uint16_t vTimer;

  uint8 ram[0x20000];
  uint16 vram[0x8000];
  uint8 sram[0x2000];

  uint16 oam[0x120];
} Snapshot;

static Snapshot g_snapshot_mine, g_snapshot_theirs, g_snapshot_before;
static uint32 hookmode, hookcnt, hookadr;
static uint32 hooked_func_pc;
static uint8 hook_orgbyte[1024];
static uint8 hook_fixbug_orgbyte[1024];

static void VerifySnapshotsEq(Snapshot *b, Snapshot *a, Snapshot *prev);
static void MakeSnapshot(Snapshot *s);
static void RestoreSnapshot(Snapshot *s);

uint8_t *SnesRomPtr(uint32 v) {
  return (uint8*)RomPtr(v);
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

static const uint32 kPatchedCarrys[] = {
  0xFE1F,
  0xFE26,
  0xFE35,
  0x1807a,
  0x18081,
  0x1A2CC,
  0x1B066,

  0x0fe79,
  0x0fe80,
  0x0fe88,

  0x1DDFB,
  0x1E0DD,
  0x2AAFB,
  0x2B05B,
  0x2B0A2,
  0x2B0A4,
  0x2B1DD,
  0x2B29B,
  0x2B2F6,
  0x3AD9B,
  0x498A2,

  0x2FBF5,
  0x2FBF7,
  0x2FC11,
  0x2FC13,
  0x2FC34,
  0x2FBFA,
  0x1D021,
  0x1D028,
  0x1B182,
  0x1FDD6,
  0x2B368,
  0x2BB3E,

  0x2C061,
  0x2C06C,
  0x2AD15,
  0x02DDA1,
  0x0399DB,

  0x1BC75,
  0x1BC78,
  0x1BC7A,
  0x2B228,

  0x2f231,
  0x2f23d,
  0x2f245,
};

static uint8 kPatchedCarrysOrg[arraysize(kPatchedCarrys)];
static uint8 preserved_db;
uint32 PatchBugs(uint32 mode, uint32 addr) {
  hookmode = mode, hookadr = addr, hookcnt = 0;
  if (FixBugHook(0xA33C) || FixBugHook(0xa358) || FixBugHook(0xA378)) {
    if (g_cpu->a == 0x0)
      g_cpu->a = 0x2000;
    return 0;
  } else if (FixBugHook(0x1C641)) {
    // PowerUpAndItemGFXRt_DrawCoinSprite doesn't set B
    preserved_db = g_cpu->db;
    g_cpu->db = 1;
  } else if (FixBugHook(0x1C644)) {
    g_cpu->db = preserved_db;
  } else if (FixBugHook(0x4e686)) {
    // CheckIfDestroyTileEventIsActive doesn't zero Y
    g_cpu->y = 0;
  } else if (FixBugHook(0x058AFB) || FixBugHook(0x58CE0)) {

    int lvl_setting = misc_level_mode_setting;
    int max_n = (lvl_setting == 7 || lvl_setting == 8 || lvl_setting == 10 || lvl_setting == 13) ? 28 : 16;
    // BufferScrollingTiles_Layer1_VerticalLevel reads oob
    if ((uint8)g_cpu->a >= max_n)
      g_cpu->a = 0;
  } else if (FixBugHook(0xfda5)) {
    // SpawnPlayerWaterSplashAndManyBreathBubbles Y not inited
    g_cpu->y = 0;
  } else if (FixBugHook(0xCC32)) {
    // UpdateHDMAWindowBuffer_00CC14 reads bad ptr
    if (R6_W == 0) {
      g_cpu->a = 0;
      return 0xCC34;
    }
  } else if (FixBugHook(0x04FC00)) {  // OWSpr06_KoopaKid uninited Y
    g_cpu->y = owspr_table0df5[(uint8)g_cpu->x];
  } else if (FixBugHook(0x03B830)) {  //  CheckPlayerPositionRelativeToSprite_Y in bank 3 writes to R15 instead of R14
    R14_ = g_cpu->a;
    return 0x3b832;
  } else if (FixBugHook(0x2F2FC)) {  // Wiggler reads from spr_ylos_lo instead of hi
    g_cpu->a = spr_ypos_hi[g_cpu->x & 0xff];
    return 0x2F2Fe;
  } else if (FixBugHook(0xCAC7)) {
    // UpdateHDMAWindowBuffer_KeyholeEntry writes oob
    if (g_cpu->x >= 0x1e0)
      return 0xCAD6;
  } else if (FixBugHook(0xCA9F)) {
    // UpdateHDMAWindowBuffer_KeyholeEntry writes oob
    if (g_cpu->x >= 0x1e0)
      return 0xCAA5;
  } else if (FixBugHook(0xCA86)) {
    if (LOBYTE(g_cpu->a) == 255 || LOBYTE(g_cpu->a) == 0) g_cpu->a = 1;
  } else if (FixBugHook(0x4862E)) {
    // DrawOverworldPlayer doesn't init
    R0_W = 0;
    R4_W = 0;
  }
  return 0;
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
  for (size_t i = 0; i != arraysize(kPatchedCarrys); i++) {
    if (addr == kPatchedCarrys[i])
      return kPatchedCarrysOrg[i];
  }
  {
    int i = RunPatchBugHook(addr);
    if (i >= 0) return i;
  }
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
  memcpy(&b->ram[0x0], &a->ram[0x0], 16); // temps
  memcpy(&b->ram[0x10b], &a->ram[0x10b], 0x100 - 0xb);  // stack

  if (memcmp(b->ram, a->ram, 0x20000)) {
    fprintf(stderr, "@%d: Memory compare failed (mine != theirs, prev):\n", snes_frame_counter);
    int j = 0;
    for (size_t i = 0; i < 0x20000; i++) {
      if (a->ram[i] != b->ram[i]) {
        if (++j < 256) {
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
  memcpy(s->vram, g_snes->ppu->vram, sizeof(uint16) * 0x8000);
  memcpy(s->oam, g_snes->ppu->oam, sizeof(uint16) * 0x120);
}

static void MakeMySnapshot(Snapshot *s) {
  memcpy(s->ram, g_snes->ram, 0x20000);
  memcpy(s->sram, g_snes->cart->ram, g_snes->cart->ramSize);
  memcpy(s->vram, g_snes->ppu->vram, sizeof(uint16) * 0x8000);
  memcpy(s->oam, g_snes->ppu->oam, sizeof(uint16) * 0x120);
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
  memcpy(g_snes->ppu->vram, s->vram, sizeof(uint16) * 0x8000);
  memcpy(g_snes->ppu->oam, s->oam, sizeof(uint16) * 0x120);
}

static bool loadRom(const char *name, Snes *snes) {
  size_t length = 0;
  uint8_t *file = NULL;
  file = ReadWholeFile(name, &length);
  if (file == NULL) {
    puts("Failed to read file");
    return false;
  }
  bool result = snes_loadRom(snes, file, (int)length);
  free(file);
  return result;
}

void PatchBytes(uint32 addr, const uint8 *value, size_t n) {
  for(size_t i = 0; i != n; i++)
    SnesRomPtr(addr)[i] = value[i];
}

// Patches add/sub to ignore carry
void FixupCarry(uint32 addr) {
  *SnesRomPtr(addr) = 0;
}

uint16 currently_installed_bug_fix_counter;

void RtlUpdateSnesPatchForBugfix() {
  currently_installed_bug_fix_counter = bug_fix_counter;
}

Snes *SnesInit(const char *filename) {
  g_snes = snes_init(g_ram);

  g_cpu = g_snes->cpu;

  bool loaded = loadRom(filename, g_snes);
  if (!loaded) {
    return NULL;
  }

  g_sram = g_snes->cart->ram;
  g_rom = g_snes->cart->rom;

  RtlSetupEmuCallbacks(NULL, &RtlRunFrameCompare, NULL);

  *SnesRomPtr(0x843B) = 0x60; // remove WaitForHBlank_Entry2

  RtlUpdateSnesPatchForBugfix();

  for (size_t i = 0; i != arraysize(kPatchedCarrys); i++) {
    uint8 t = *SnesRomPtr(kPatchedCarrys[i]);
    if (t) {
      kPatchedCarrysOrg[i] = t;
      FixupCarry(kPatchedCarrys[i]);
    } else {
      printf("0x%x double patched!\n", kPatchedCarrys[i]);
    }
  }

  PatchBugs(1, 0);
  return g_snes;
}

uint32 RunCpuUntilPC(uint32 pc1, uint32 pc2) {
  uint32 addr_last = g_snes->cpu->k << 16 | g_snes->cpu->pc;

  for(;;) {
    snes_runCpu(g_snes);
//    snes_runCycle(g_snes);
    uint32 addr = g_snes->cpu->k << 16 | g_snes->cpu->pc;
    if (addr != addr_last && (addr == pc1 || addr == pc2)) {
      return addr;
    }
    addr_last = addr;
  }
}

void RunOneFrameOfGame_Emulated(void) {
  Snes *snes = g_snes;
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  // Execute until: mov.b   A, waiting_for_vblank
  RunCpuUntilPC(0x8077, 0x8077);

  g_snes->debug_cycles = 0; // turn off debuig prints if enabled

  // Trigger nmi
  snes->cpu->nmiWanted = true;
  RunCpuUntilPC(0x82C3, 0x83B9);
  snes_runCpu(snes);

  // Right after NMI completes, draw the frame, possibly triggering IRQ.
  assert(!snes->cpu->i);
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  while (!snes->inNmi) {
    snes_handle_pos_stuff(snes);

    if (snes->cpu->irqWanted) {
      RunCpuUntilPC(0x82C3, 0x83B9);
      snes_runCpu(snes);
    }
  }
}

void Vector_Reset();
void RunOneFrameOfGame_Internal();
void Vector_NMI();
void Vector_IRQ();

bool g_did_init;

void RunOneFrameOfGame() {
  Snes *snes = g_snes;
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  if (snes->cpu->pc == 0x8000) {
    g_did_init = true;
    Vector_Reset();
  }
  RunOneFrameOfGame_Internal();

  Vector_NMI();

  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  while (!snes->inNmi) {
    snes_handle_pos_stuff(snes);

    if (snes->cpu->irqWanted) {
      snes->cpu->irqWanted = false;
      Vector_IRQ();
    }
  }
}


void DrawFrameToPpu(void) {
  g_snes->hPos = g_snes->vPos = 0;
  while (!g_snes->cpu->nmiWanted) {
    do {
      snes_handle_pos_stuff(g_snes);
    } while (g_snes->hPos != 0);
    if (g_snes->vIrqEnabled && (g_snes->vPos - 1) == g_snes->vTimer) {
      Vector_IRQ();
    }
  }
  g_snes->cpu->nmiWanted = false;
}

void SaveBugSnapshot() {
  if (!g_debug_flag && g_got_mismatch_count == 0) {
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "saves/bug-%d.sav", (int)time(NULL));
    RtlSaveSnapshot(buffer, true);
  }
  g_got_mismatch_count = 5 * 60;
}

void RunOneFrameOfGame_Both(void) {
  g_snes->ppu = g_snes->snes_ppu;
  MakeSnapshot(&g_snapshot_before);

  // Run orig version then snapshot
again_theirs:
  g_snes->runningWhichVersion = 1;
  RunOneFrameOfGame_Emulated();
  MakeSnapshot(&g_snapshot_theirs);

  // Run my version and snapshot
//again_mine:
  g_snes->ppu = g_snes->my_ppu;
  RestoreSnapshot(&g_snapshot_before);

  g_snes->runningWhichVersion = 2;
  RunOneFrameOfGame();
  MakeSnapshot(&g_snapshot_mine);

  g_snes->runningWhichVersion = 0xff;

  // Compare both snapshots
  VerifySnapshotsEq(&g_snapshot_mine, &g_snapshot_theirs, &g_snapshot_before);

  if (g_fail) {
    g_fail = false;

    printf("Verify failure!\n");

    g_snes->ppu = g_snes->snes_ppu;
    RestoreSnapshot(&g_snapshot_before);

    if (g_debug_flag)
      goto again_theirs;

    SaveBugSnapshot();
    RunOneFrameOfGame_Emulated();
    goto getout;
  }

  g_snes->ppu = g_snes->snes_ppu;
  RestoreSnapshot(&g_snapshot_theirs);
getout:
  g_snes->ppu = g_other_image ? g_snes->my_ppu : g_snes->snes_ppu;
  g_snes->runningWhichVersion = 0;

  if (g_got_mismatch_count)
    g_got_mismatch_count--;
}

void RtlRunFrameCompare(uint16 input, int run_what) {
  g_snes->input1->currentState = input;

  if (g_runmode == RM_THEIRS) {
    g_use_my_apu_code = false;
    RunOneFrameOfGame_Emulated();

  } else if (g_runmode == RM_MINE) {
    g_use_my_apu_code = true;

    g_snes->runningWhichVersion = 0xff;
    RunOneFrameOfGame();
    g_snes->runningWhichVersion = 0;
  } else {
    g_use_my_apu_code = false;
    RunOneFrameOfGame_Both();
  }
}
