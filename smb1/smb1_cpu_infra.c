#include "../src/common_cpu_infra.h"
#include "smb1_rtl.h"
#include "../src/snes/snes.h"
#include "smb1_variables.h"
#include "smb1_funcs.h"

bool g_smb1_want_reset;

void Smb1RunOneFrameOfGame_Internal();

static const uint32 kPatchedCarrys_SMB1[] = {
0xa492,
0xa495,
0xa4a7,
0xb7d3,
0xBB79,
0xbcc6,
0xbca9,
0xc627,
0xD0DB,
0xd27e,
0xd2b2,
0xf3c1,
0xf3c3,
0xf3e3,
0xf3e5,
0xfc50,
0x1df2f,
0x1df32,
0x1df35,
0x1e066,
0x1e069,
0x1e06c,
0x1e191,
0x1e194,
0x1e197,

};

uint32 PatchBugs_SMB1(void) {
  if (FixBugHook(0x088054)) {
    if (g_use_my_apu_code)
      return 0x88AEA; // ret
    RtlSetUploadingApu(true);
  } else if (FixBugHook(0x088007) || FixBugHook(0x088039) || FixBugHook(0x8827D)) {
    RtlSetUploadingApu(true);
  } else if (FixBugHook(0x880C2)) {
    RtlSetUploadingApu(false);
  } else if (FixBugHook(0x81ac)) {
    wait_for_vblank = 1;
  } else if (FixBugHook(0x0887A2)) {
    sram_controller1_plugged_in = 0;
    sram_controller2_plugged_in = 2;
  } else if (FixBugHook(0x8067)) {
    return 0x806B;
  } else if (FixBugHook(0xC63E)) {
    //  Spr02F_Vine_Init reads from y
    g_cpu->y = 0;
  } else if (FixBugHook(0x8034)) {
    // Remove the copy detection check
    return 0x8057;
  }
  return 0;
}

void Smb1CpuInitialize(void) {
}

static void Smb1FixSnapshotForCompare(Snapshot *b, Snapshot *a) {
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

void Smb1RunOneFrameOfGame_Emulated(void) {
  Snes *snes = g_snes;
  if (snes->cpu->pc == 0x8000)
    RtlApuReset();
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;
  wait_for_vblank = 1;

  // Execute until: mov.b   wait_for_vblank, #0
  RunCpuUntilPC(0x82BB, 0x88AE4);

  g_snes->debug_cycles = 0; // turn off debuig prints if enabled

  // Trigger nmi
  snes->cpu->nmiWanted = true;
  RunCpuUntilPC(0x8506, 0x8506);
  snes_runCpu(snes);

  // Right after NMI completes, draw the frame, possibly triggering IRQ.
 // assert(!snes->cpu->i);
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  while (!snes->inNmi) {
    snes_handle_pos_stuff(snes);

    if (snes->cpu->irqWanted) {
      RunCpuUntilPC(0x8551, 0x8551);
      snes_runCpu(snes);
    }
  }
}


void Smb1RunOneFrameOfGame(void) {
  Snes *snes = g_snes;
  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  if (snes->cpu->pc == 0x8000) {
RESET_GAME:
    snes->cpu->pc = 0x8001;
    Smb1VectorReset();
  }
  Smb1RunOneFrameOfGame_Internal();
  if (g_smb1_want_reset) {
    g_smb1_want_reset = false;
    goto RESET_GAME;
  }

  Smb1VectorNMI();

  snes->vPos = snes->hPos = 0;
  snes->cpu->nmiWanted = snes->cpu->irqWanted = false;
  snes->inVblank = snes->inNmi = false;

  while (!snes->inNmi) {
    snes_handle_pos_stuff(snes);

    if (snes->cpu->irqWanted) {
      snes->cpu->irqWanted = false;
      Smb1VectorIRQ();
    }
  }
}


const RtlGameInfo kSmb1GameInfo = {
  "smb1",
  kGameID_SMB1,
  kPatchedCarrys_SMB1, arraysize(kPatchedCarrys_SMB1),
  &PatchBugs_SMB1,
  &Smb1CpuInitialize,
  &Smb1RunOneFrameOfGame,
  &Smb1RunOneFrameOfGame_Emulated,
  &Smb1FixSnapshotForCompare,
};
