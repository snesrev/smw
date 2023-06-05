#include "../src/common_cpu_infra.h"
#include "smbll_rtl.h"
#include "../src/snes/snes.h"
#include "smbll_variables.h"
#include "smbll_funcs.h"

bool g_smbll_want_reset;

void SmbllRunOneFrameOfGame_Internal();

static const uint32 kPatchedCarrys_SMBLL[] = {
0xa180,
0xa183,
0xa196,
0xb52f,
0xb8f1,
0xba3e,
0xba21,
0xc47e,
0xcf84,
0xf39f,
0xf3a1,
0xf3c1,
0xf3c3,
0xfc54,
0xb872f,
0xb8732,
0xb8735,
0xb8866,
0xb8869,
0xb886c,
0xb8991,
0xb8994,
0xb8997,
};

static uint32 PatchBugs_SMBLL(void) {
  if (FixBugHook(0x088054) || FixBugHook(0x088007) || FixBugHook(0x088039) || FixBugHook(0x8817A)) {
    RtlSetUploadingApu(true);
  } else if (FixBugHook(0x880C2)) {
    RtlSetUploadingApu(false);
  } else if (FixBugHook(0x8092)) {
    wait_for_vblank = 1;
  } else if (FixBugHook(0x08869F)) {
    sram_controller1_plugged_in = 0;
    sram_controller2_plugged_in = 2;
  } else if (FixBugHook(0x805F)) {
    return 0x8063;
  } else if (FixBugHook(0xC495)) {
    //  Spr02F_Vine_Init reads from y
    g_cpu->y = 0;
  } else if (FixBugHook(0x802C)) {
    // Remove the copy detection check
    return 0x804F;
  } else if (FixBugHook(0xD9E8)) {
    g_cpu->a = 0;
  }
  return 0;
}

static void SmbllCpuInitialize(void) {
}

static void SmbllFixSnapshotForCompare(Snapshot *b, Snapshot *a) {
  memcpy(&b->ram[0x0], &a->ram[0x0], 8); // temps
  memcpy(&b->ram[0x155], &a->ram[0x155], 0x100 - 0x55);  // stack

}

static uint32 RunCpuUntilPC(uint32 pc1, uint32 pc2) {
  uint32 addr_last = g_snes->cpu->k << 16 | g_snes->cpu->pc;

  for (;;) {
    snes_runCpu(g_snes);
    //    snes_runCycle(g_snes);
    uint32 addr = g_snes->cpu->k << 16 | g_snes->cpu->pc;
    if (addr != addr_last && (addr == pc1 || addr == pc2)) {
      return addr;
    }
    addr_last = addr;
  }
}

void SmbllRunOneFrameOfGame_Emulated(void) {
  Snes *snes = g_snes;
  if (snes->cpu->pc == 0x8000)
    RtlApuReset();
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;
  wait_for_vblank = 1;

  // Execute until: mov.b   wait_for_vblank, #0
  RunCpuUntilPC(0x819D, 0x889E1);

  g_snes->debug_cycles = 0; // turn off debuig prints if enabled

  // Trigger nmi
  snes->cpu->nmiWanted = true;
  RunCpuUntilPC(0x83D0, 0x83D0);
  snes_runCpu(snes);

  // Right after NMI completes, draw the frame, possibly triggering IRQ.
 // assert(!snes->cpu->i);
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  while (!snes->inNmi) {
    snes_handle_pos_stuff(snes);

    if (snes->cpu->irqWanted) {
      RunCpuUntilPC(0x841B, 0x841B);
      snes_runCpu(snes);
    }
  }
}


void SmbllRunOneFrameOfGame(void) {
  Snes *snes = g_snes;
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  if (snes->cpu->pc == 0x8000) {
RESET_GAME:
    Smbll_VectorReset();
  }
  SmbllRunOneFrameOfGame_Internal();
  if (g_smbll_want_reset) {
    g_smbll_want_reset = false;
    goto RESET_GAME;
  }

  Smbll_VectorNMI();

  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  while (!snes->inNmi) {
    snes_handle_pos_stuff(snes);

    if (snes->cpu->irqWanted) {
      snes->cpu->irqWanted = false;
      Smbll_VectorIRQ();
    }
  }
}


const RtlGameInfo kSmbllGameInfo = {
  "smbll",
  kGameID_SMBLL,
  kPatchedCarrys_SMBLL, arraysize(kPatchedCarrys_SMBLL),
  &PatchBugs_SMBLL,
  &SmbllCpuInitialize,
  &SmbllRunOneFrameOfGame,
  &SmbllRunOneFrameOfGame_Emulated,
  &SmbllFixSnapshotForCompare,
};
