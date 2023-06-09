#include "common_cpu_infra.h"
#include "smw_rtl.h"
#include "snes/snes.h"
#include "variables.h"
#include "funcs.h"

static const uint32 kPatchedCarrys_SMW[] = {
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

static uint8 preserved_db;

uint32 PatchBugs_SMW1(void) {
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
  } else if (FixBugHook(0x3A0A7)) {  // Spr0A8_Blargg OOB
    R3_ = (spr_table1602[g_cpu->x] != 0) * 5;
  } else if (FixBugHook(0x811D)) {
    if (g_use_my_apu_code)
      return 0x8125;
    RtlSetUploadingApu(true);
  } else if (FixBugHook(0x80F7)) {
    if (g_use_my_apu_code)
      return 0x80fc;
    RtlSetUploadingApu(true);
  } else if (FixBugHook(0x80FB)) {
    RtlSetUploadingApu(false);
  }
  return 0;
}

void SmwCpuInitialize(void) {
  *SnesRomPtr(0x843B) = 0x60; // remove WaitForHBlank_Entry2
}

static void SmwFixSnapshotForCompare(Snapshot *b, Snapshot *a) {
  memcpy(&b->ram[0x0], &a->ram[0x0], 16); // temps
  memcpy(&b->ram[0x10b], &a->ram[0x10b], 0x100 - 0xb);  // stack
}

static uint32 RunCpuUntilPC(uint32 pc1, uint32 pc2) {
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

void SmwRunOneFrameOfGame_Emulated(void) {
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

void SmwRunOneFrameOfGame(void) {
  Snes *snes = g_snes;
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  if (snes->cpu->pc == 0x8000) {
    snes->cpu->pc = 0x8001;
    SmwVectorReset();
  }
  SmwRunOneFrameOfGame_Internal();

  SmwVectorNMI();

  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  while (!snes->inNmi) {
    snes_handle_pos_stuff(snes);

    if (snes->cpu->irqWanted) {
      snes->cpu->irqWanted = false;
      SmwVectorIRQ();
    }
  }
}

const RtlGameInfo kSmwGameInfo = {
  "smw",
  kGameID_SMW,
  kPatchedCarrys_SMW, arraysize(kPatchedCarrys_SMW),
  &PatchBugs_SMW1,
  &SmwCpuInitialize,
  &SmwRunOneFrameOfGame,
  &SmwRunOneFrameOfGame_Emulated,
  &SmwFixSnapshotForCompare,
};
