#include "common_cpu_infra.h"
#include "smw_rtl.h"
#include "snes/snes.h"
#include "variables.h"
#include "funcs.h"
#include "assets/smw_assets.h"

extern bool g_custom_music;

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

  0x3C073,
};

static uint8 preserved_db;

static uint32 get_24(uint32 a) {
  return *(uint32*)SnesRomPtr(a) & 0xffffff;
}

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
    if (WORD(g_ram[6]) == 0) {
      g_cpu->a = 0;
      return 0xCC34;
    }
  } else if (FixBugHook(0x04FC00)) {  // OWSpr06_KoopaKid uninited Y
    g_cpu->y = owspr_table0df5[(uint8)g_cpu->x];
  } else if (FixBugHook(0x03B830)) {  //  CheckPlayerPositionRelativeToSprite_Y in bank 3 writes to R15 instead of R14
    g_ram[0xe] = g_cpu->a;
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
    WORD(g_ram[0]) = 0;
    WORD(g_ram[4]) = 0;
  } else if (FixBugHook(0x3A0A7)) {  // Spr0A8_Blargg OOB
    g_ram[3] = (spr_table1602[g_cpu->x] != 0) * 5;
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
  } else if (FixBugHook(0xE3FB)) {
    g_ram[12] = g_ram[13] = 0; // R13 not initialized
  } else if (FixBugHook(0x1FD50)) {
    // Spr029_KoopaKid_Status08_IggyLarry_01FD50 may not init its outputs
    WORD(g_ram[0x14b8]) = spr_xpos_lo[g_cpu->x];
    WORD(g_ram[0x14ba]) = spr_ypos_lo[g_cpu->x]; 
  } else if (FixBugHook(0x1d7f4)) {
    WORD(g_ram[8]) = GetSprYPos(g_cpu->x);
    WORD(g_ram[10]) = GetSprXPos(g_cpu->x);
  } else if (FixBugHook(0x1ec36)) {
    g_cpu->a = 1;
  } else if (FixBugHook(0x19F1C)) {
    if (g_cpu->y >= 84)
      g_cpu->y = 0;
  } else if (FixBugHook(0x817e)) {
    g_cpu->y = g_ram[kSmwRam_APUI02];
    return 0x8181;
  } else if (g_lunar_magic) {

    static uint32 LmFunc_UpdateTilemapC_0, buffer_tilemap_L1_0, buffer_tilemap_L1_1, LmFunc_UpdateTilemapD_1, LmHook_BufferScrollingTiles_L2_1;
    static uint32 LmHook_HandleStandardLevelCameraScrollD;

    if (!LmFunc_UpdateTilemapC_0) {
      uint32 LmHook_BufferTilemap_L1 = get_24(0x580BF+1);
      buffer_tilemap_L1_0 = get_24(LmHook_BufferTilemap_L1 + 0xAB29 - 0xAB15);
      buffer_tilemap_L1_1 = get_24(LmHook_BufferTilemap_L1 + 0xAB29 - 0xAB15 + 3 * 7);

      uint32 LmHook_CheckIfLevelTilemapsNeedScrollUpdate = get_24(0x586F7 + 1);
      uint32 LmFunc_UpdateTilemapD = get_24(LmHook_CheckIfLevelTilemapsNeedScrollUpdate + 0xB5D0 - 0xB538);
      LmFunc_UpdateTilemapD_1 = get_24(LmFunc_UpdateTilemapD + 0xAD41 - 0xAD38 + 3 * 1);

      uint32 LmHook_BufferTilemap_L2 = get_24(0x580C3+1);
      LmHook_BufferScrollingTiles_L2_1 = get_24(LmHook_BufferTilemap_L2 + 0xAB9D - 0xAB89 + 3 * 1);

      uint32 LmFunc_UpdateTilemapC = get_24(LmHook_CheckIfLevelTilemapsNeedScrollUpdate + 0xB5A9 + 1 - 0xB538);
      LmFunc_UpdateTilemapC_0 = get_24(LmFunc_UpdateTilemapC + 0xACD8 - 0xACCF + 3 * 1);

      LmHook_HandleStandardLevelCameraScrollD = get_24(0xF70D + 1);
    }

    if (FixBugHook(LmFunc_UpdateTilemapC_0 + 0xAE7B - 0xAE28)) {
      g_cpu->a &= 0xf;
    } else if (FixBugHook(LmHook_HandleStandardLevelCameraScrollD + 0xBB7C - 0xBB6B)) {
      if (sign16(g_cpu->a))
        g_cpu->a = 0;
    } else if (FixBugHook(buffer_tilemap_L1_0 + 0xAFEE - 0xAFCF) || 
               FixBugHook(buffer_tilemap_L1_1 + 0xB099 - 0xB07A) ||
               FixBugHook(LmHook_BufferScrollingTiles_L2_1 + 0xB11E - 0xB0EE)) {
      if (sign16(g_cpu->a))
        return buffer_tilemap_L1_1 + 0xB0EB - 0xB07A;
    } else if (FixBugHook(LmFunc_UpdateTilemapD_1 + 0xB2B4 - 0xB28B)) {
      static const uint16 kLm10B483[2] = {0, 14};
      g_cpu->a = kLm10B483[lm_arr1831b[3] >> 1] + ((int16)mirror_current_layer2_ypos >> 4);
      if (sign16(g_cpu->a))
        return LmFunc_UpdateTilemapD_1 + 0xB33E - 0xB28B;
    }
  }
  return 0;
}

void SmwCpuInitialize(void) {
  g_lunar_magic = HAS_LM_FEATURE(kLmFeature_LmEnabled);
  if (g_rom) {
    *SnesRomPtr(0x843B) = 0x60; // remove WaitForHBlank_Entry2
    *SnesRomPtr(0x2DDA2) = 5;
    *SnesRomPtr(0xCA5AC) = 7;

    uint8 *music = SnesRomPtr(0x8052);
    g_custom_music = music[1] != 0xE8;
    if (g_custom_music) {
      music[0] = 0xea;
      music[1] = 0xea;
      music[2] = 0xea;

      *SnesRomPtr(0x8079) = 0x60;  // HandleSPCUploads_SPC700UploadLoop ret 

      uint8* p = SnesRomPtr(0x8075);
      p[0] = 0x64;
      p[1] = 0x10;
      p[2] = 0x80;
      p[3] = 0xF2;

      printf("Custom music not supported!\n");

      static const uint8 kRevertProcessNormalSprites[] = { 0xda, 0x8a, 0xae, 0x92, 0x16, 0x18, 0x7f, 0xb4, 0xf0, 0x07, 0xaa, 0xbf, 0x00, 0xf0, 0x07, 0xfa, 0x9d, 0xea, 0x15 };
      memcpy(SnesRomPtr(0x180d2), kRevertProcessNormalSprites, sizeof(kRevertProcessNormalSprites));
      static const uint8 kRevertStatusBar[] = { 0xad, 0x22, 0x14, 0xc9 };
      memcpy(SnesRomPtr(0x8FD8), kRevertStatusBar, sizeof(kRevertStatusBar));
      
      if (HAS_HACK(kHack_Walljump)) {
        uint8 *wallhack = SnesRomPtr(0xa2a1);
        wallhack[3] &= 0x7f;
        wallhack = SnesRomPtr(get_24(0xa2a2));
        wallhack[3] &= 0x7f;
      }

      // Reznor platform fix
      static const uint8 kRevert_0x39890[] = { 0xee, 0x0f, 0x14 };
      memcpy(SnesRomPtr(0x39890), kRevert_0x39890, sizeof(kRevert_0x39890));

      static const uint8 kRevert_0x2907a[] = { 0xbd, 0x9d, 0x16, 0xd0 };
      memcpy(SnesRomPtr(0x2907a), kRevert_0x2907a, sizeof(kRevert_0x2907a));
      static const uint8 kRevert_0xf5f3[] = { 0xa0, 0x04, 0x8c, 0xf9, 0x1d };
      memcpy(SnesRomPtr(0xf5f3), kRevert_0xf5f3, sizeof(kRevert_0xf5f3));
      static const uint8 kRevert_0x1bb33[] = { 0xa9, 0x30, 0x9d, 0xea, 0x15 };
      memcpy(SnesRomPtr(0x1bb33), kRevert_0x1bb33, sizeof(kRevert_0x1bb33));
      static const uint8 kRevert_0x2a129[] = { 0xa9, 0x21, 0x95, 0x9e, 0xa9, 0x08, 0x9d, 0xc8, 0x14, 0x22, 0xd2, 0xf7, 0x07 };
      memcpy(SnesRomPtr(0x2a129), kRevert_0x2a129, sizeof(kRevert_0x2a129));
      static const uint8 kRevert_0x2db82[] = { 0xbd, 0xe0, 0x14, 0x99, 0xe0, 0x14 };
      memcpy(SnesRomPtr(0x2db82), kRevert_0x2db82, sizeof(kRevert_0x2db82));
      static const uint8 kRevert_0x2e6ec[] = { 0xa9, 0x38, 0x9d, 0xea, 0x15 };
      memcpy(SnesRomPtr(0x2e6ec), kRevert_0x2e6ec, sizeof(kRevert_0x2e6ec));
    }
  }
}

static void SmwFixSnapshotForCompare(Snapshot *b, Snapshot *a) {
  memcpy(&b->ram[0x0], &a->ram[0x0], 16); // temps
  memcpy(&b->ram[0x10b], &a->ram[0x10b], 0x100 - 0xb);  // stack

  memcpy(&b->ram[0x17bb], &a->ram[0x17bb], 1); // unusedram_7e17bb

  memcpy(&b->ram[0x65], &a->ram[0x65], 12);  // temp66, etc
  memcpy(&b->ram[0x8a], &a->ram[0x8a], 6);  // temp8a, etc

  memcpy(&b->ram[0x14B0], &a->ram[0x14B0], 0x11);  // temp14b0 etc

  memcpy(&b->ram[0x1436], &a->ram[0x1436], 4);  // temp14b0 etc

  memcpy(&b->ram[0x1C00B], &a->ram[0x1C00B], 1);  // lm_varB

  if (g_custom_music) {
    memcpy(&b->ram[0x1DF9], &a->ram[0x1DF9], 8); // sound io
  }

}

static uint32 RunCpuUntilPC(uint32 pc1, uint32 pc2) {
  uint32 addr_last = g_snes->cpu->k << 16 | g_snes->cpu->pc;

  for(;;) {
    snes_runCpu(g_snes);
//    snes_runCycle(g_snes);
    uint32 addr = (g_snes->cpu->k << 16 | g_snes->cpu->pc) & 0x7fffff;
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

/*
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
  */
}


const RtlGameInfo kSmwGameInfo = {
  "smw",
  kGameID_SMW,
  kPatchedCarrys_SMW, arraysize(kPatchedCarrys_SMW),
  &PatchBugs_SMW1,
  &SmwCpuInitialize,
  &SmwRunOneFrameOfGame,
  &SmwRunOneFrameOfGame_Emulated,
  &SmwDrawPpuFrame,
  &SmwFixSnapshotForCompare,
};
