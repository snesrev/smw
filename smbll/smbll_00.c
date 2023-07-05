#include "smbll_consts.h"
#include "smbll_funcs.h"
#include "smbll_rtl.h"
#include "smbll_variables.h"
void (*funcs_E2B[4])(void) = {&Smbll_TitleScreen_0_InitializeGame, &Smbll_ScreenRoutines, &Smbll_TitleScreen_2_PrimaryGameSetup,
                              &Smbll_TitleScreen_3_GameMenuRoutine};  // weak
void (*funcs_4A7C[55])(uint8 k) = {
    &Smbll_ExtObj07_VerticalPipe,
    &Smbll_ExtObj01_GrassyOrMushroomPlatform,
    &Smbll_ExtObj02_RowOfBricks,
    &Smbll_ExtObj03_RowOfSolidBlocks,
    &Smbll_ExtObj04_RowOfCoins,
    &Smbll_ExtObj05_ColumnOfBricks,
    &Smbll_ExtObj06_ColumnOfSolidBlocks,
    &Smbll_ExtObj07_VerticalPipe,
    &Smbll_ExtObj08_Hole,
    &Smbll_ExtObj09_PulleyRope_,
    &Smbll_ExtObj0A_Bridge_High,
    &Smbll_ExtObj0B_Bridge_Middle,
    &Smbll_ExtObj0B_Bridge_Low,
    &Smbll_ExtObj0D_HoleWater,
    &Smbll_ExtObj0E_QuestionBlockHigh,
    &Smbll_ExtObj0E_QuestionBlockLow,
    &Smbll_nullsub_6,
    &Smbll_nullsub_6,
    &Smbll_nullsub_6,
    &Smbll_nullsub_6,
    &Smbll_nullsub_6,
    &Smbll_nullsub_6,
    &Smbll_nullsub_6,
    &Smbll_nullsub_6,
    &Smbll_ExtObj18_QuestionBlock,
    &Smbll_ExtObj18_QuestionBlock,
    &Smbll_ExtObj18_QuestionBlock,
    &Smbll_ExtObj18_QuestionBlock,
    &Smbll_ExtObj19_Hidden1upBlock,
    &Smbll_ExtObj18_QuestionBlock,
    &Smbll_ExtObj18_QuestionBlock,
    &Smbll_BrickWithItem,
    &Smbll_BrickWithItem,
    &Smbll_BrickWithItem,
    &Smbll_BrickWithItem,
    &Smbll_ExtObj1D_BrickWith10Coins,
    &Smbll_BrickWithItem,
    &Smbll_ExtObj1F_WaterPipe,
    &Smbll_ExtObj20_EmptyBlock,
    &Smbll_ExtObj21_Jumpspring,
    &Smbll_ExtObj22_IntroPipe,
    &Smbll_ExtObj23_FlagpoleObject,
    &Smbll_ExtObj24_AxeObj,
    &Smbll_ExtObj25_ChainObj,
    &Smbll_ExtObj26_CastleBridge,
    &Smbll_ExtObj27_ScrollLockObject_Warp,
    &Smbll_ExtObj28_ScrollLockObject,
    &Smbll_ExtObj28_ScrollLockObject,
    &Smbll_ExtObj2C_AreaFrenzy,
    &Smbll_ExtObj2C_AreaFrenzy,
    &Smbll_ExtObj2C_AreaFrenzy,
    &Smbll_ExtObj33,
    &Smbll_ExtObj34,
    &Smbll_ExtObj35,
    &Smbll_ExtObj2E_AlterAreaAttributes,
};  // weak
void (*funcs_A417[55])(uint8 k) = {
    &Smbll_NormalEnemy_Init,
    &Smbll_NormalEnemy_Init,
    &Smbll_NormalEnemy_Init,
    &Smbll_RedKoopa_Init,
    &Smbll_PiranhaPlant_Init,
    &Smbll_HammerBro_Init,
    &Smbll_Goomba_Init,
    &Smbll_Blooper_Init,
    &Smbll_BulletBill_Init,
    &Smbll_NoEnemyInit,
    &Smbll_CheepCheep_Init,
    &Smbll_CheepCheep_Init,
    &Smbll_Podoboo_Init,
    &Smbll_PiranhaPlant_Init,
    &Smbll_JumpGPTroopa_Init,
    &Smbll_RedPTroopa_Init,
    &Smbll_InitHorizFlySwimEnemy,
    &Smbll_Lakitu_Init,
    &Smbll_InitEnemyFrenzy,
    &Smbll_NoEnemyInit,
    &Smbll_InitEnemyFrenzy,
    &Smbll_InitEnemyFrenzy,
    &Smbll_InitEnemyFrenzy,
    &Smbll_InitEnemyFrenzy,
    &Smbll_EndFrenzy,
    &Smbll_NoEnemyInit,
    &Smbll_NoEnemyInit,
    &Smbll_ShortFirebar_Init,
    &Smbll_ShortFirebar_Init,
    &Smbll_ShortFirebar_Init,
    &Smbll_ShortFirebar_Init,
    &Smbll_LongFirebar_Init,
    &Smbll_NoEnemyInit,
    &Smbll_NoEnemyInit,
    &Smbll_NoEnemyInit,
    &Smbll_NoEnemyInit,
    &Smbll_BalPlatform_Init,
    &Smbll_VertPlatform_Init,
    &Smbll_LargeLiftUp_Init,
    &Smbll_LargeLiftDown_Init,
    &Smbll_InitHoriPlatform_Init,
    &Smbll_InitDropPlatform_Init,
    &Smbll_InitHoriPlatform_Init,
    &Smbll_PlatLiftUp_Init,
    &Smbll_PlatLiftDown_Init,
    &Smbll_Bowser_Init,
    &Smbll_Spr02E_Powerup_Init,
    &Smbll_Spr02F_Vine_Init2,
    &Smbll_NoEnemyInit,
    &Smbll_NoEnemyInit,
    &Smbll_NoEnemyInit,
    &Smbll_NoEnemyInit,
    &Smbll_NoEnemyInit,
    &Smbll_RetainerObj_Init,
    &Smbll_EndOfEnemyInitCode,
};  // weak
void (*funcs_B687[6])(uint8 k) = {
    &Smbll_LakituAndSpinyHandler, &Smbll_NoFrenzyCode,  &Smbll_FlyingCheepCheep_Init,
    &Smbll_BowserFlame_Init,      &Smbll_InitFireworks, &Smbll_BulletBillCheepCheep,
};  // weak
void (*funcs_BA2A[34])(uint8 k) = {
    &Smbll_RunNormalEnemies,  &Smbll_RunBowserFlame,    &Smbll_RunFireworks,      &Smbll_NoRunCode,        &Smbll_NoRunCode,
    &Smbll_NoRunCode,         &Smbll_NoRunCode,         &Smbll_RunFirebarObj,     &Smbll_RunFirebarObj,    &Smbll_RunFirebarObj,
    &Smbll_RunFirebarObj,     &Smbll_RunFirebarObj,     &Smbll_RunFirebarObj,     &Smbll_RunFirebarObj,    &Smbll_RunFirebarObj,
    &Smbll_NoRunCode,         &Smbll_RunLargePlatform,  &Smbll_RunLargePlatform,  &Smbll_RunLargePlatform, &Smbll_RunLargePlatform,
    &Smbll_RunLargePlatform,  &Smbll_RunLargePlatform,  &Smbll_RunLargePlatform,  &Smbll_RunSmallPlatform, &Smbll_RunSmallPlatform,
    &Smbll_RunBowser,         &Smbll_PowerUpObjHandler, &Smbll_VineObjectHandler, &Smbll_NoRunCode,        &Smbll_RunStarFlagObj,
    &Smbll_JumpspringHandler, &Smbll_NoRunCode,         &Smbll_WarpZoneObject,    &Smbll_RunRetainerObj,
};  // weak
void (*funcs_BC11[21])(uint8 k) = {
    &Smbll_MoveNormalEnemy,        &Smbll_MoveNormalEnemy,        &Smbll_MoveNormalEnemy, &Smbll_MoveNormalEnemy,  &Smbll_sub_AB13,
    &Smbll_ProcHammerBro,          &Smbll_MoveNormalEnemy,        &Smbll_MoveBloober,     &Smbll_MoveBulletBill,   &Smbll_NoMoveCode,
    &Smbll_MoveSwimmingCheepCheep, &Smbll_MoveSwimmingCheepCheep, &Smbll_MovePodoboo,     &Smbll_MovePiranhaPlant, &Smbll_MoveJumpingEnemy,
    &Smbll_ProcMoveRedPTroopa,     &Smbll_MoveFlyGreenPTroopa,    &Smbll_MoveLakitu,      &Smbll_MoveNormalEnemy,  &Smbll_NoMoveCode,
    &Smbll_MoveFlyingCheepCheep,
};  // weak
void (*funcs_BDDE[7])(uint8 k) = {
    &Smbll_BalancePlatform, &Smbll_YMovingPlatform, &Smbll_MoveLargeLiftPlat, &Smbll_MoveLargeLiftPlat,
    &Smbll_XMovingPlatform, &Smbll_DropPlatform,    &Smbll_RightPlatform,
};  // weak

void Smbll_Emulation_mode_RESET() {
  Smbll_VectorReset();
}

void Smbll_VectorReset() {
  WriteReg(NMITIMEN, 0);
  WriteReg(MDMAEN, 0);
  WriteReg(HDMAEN, 0);
  WriteReg(INIDISP, 0x80u);

  Smbll_UploadSPCEngine();
  Smbll_InitializeRAMOnStartup();
  Smbll_VerifySaveDataIsValid();
  Smbll_UploadMainSampleData();
  //  Smbll_LoadSplashScreen();
  Smbll_UploadSpuData();
  Smbll_InitGfxStuff();
  Smbll_Dma_FillWith0x28();
  Smbll_DrawLevelPreviewSprites_Sub_New();
  UNUSED_byte_7E1608 = 0;
  UNUSED_byte_7E1609 = 0;
  apui03_upper_bit = 0;
  UNUSED_byte_7E160E = 0;
  apui00_delay = 0;
  apui03_delay = 0;
  apui02_var160C = 1;
  frame_counter = -127;
  WriteReg(NMITIMEN, 0x81u);
}

void SmbllRunOneFrameOfGame_Internal() {
  int8 v1;   // r8
  int8 v2;   // cf
  int8 v3;   // r8
  int8 v4;   // r8
  int8 v5;   // r8
  int8 v6;   // r8
  int8 v7;   // r8
  int8 v8;   // r8
  uint8 v9;  // si

  Smbll_PollJoypadInputs();
  random_lfsr_temp = random_byte1 & 2;
  v1 = 0;
  if ((random_byte1 & 2) != (random_byte2 & 2))
    v1 = 0x80;
  v2 = random_byte1 & 1;
  random_byte1 = (random_byte1 >> 1) + v1;
  v3 = 0;
  if (v2)
    v3 = 0x80;
  v2 = random_byte2 & 1;
  random_byte2 = (random_byte2 >> 1) + v3;
  v4 = 0;
  if (v2)
    v4 = 0x80;
  v2 = random_byte3 & 1;
  random_byte3 = (random_byte3 >> 1) + v4;
  v5 = 0;
  if (v2)
    v5 = 0x80;
  v2 = random_byte4 & 1;
  random_byte4 = (random_byte4 >> 1) + v5;
  v6 = 0;
  if (v2)
    v6 = 0x80;
  v2 = random_byte5 & 1;
  random_byte5 = (random_byte5 >> 1) + v6;
  v7 = 0;
  if (v2)
    v7 = 0x80;
  v2 = random_byte6 & 1;
  random_byte6 = (random_byte6 >> 1) + v7;
  v8 = 0;
  if (v2)
    v8 = 0x80;
  random_byte7 = (random_byte7 >> 1) + v8;
  Smbll_HandleSfx();
  if (!debug_flag)
    goto LABEL_27;
  if ((controller_press2p1 & 0x20) != 0)
    ++global_frame_advance_debug_active_flag;
  if ((controller_press2p1 & 0x10) != 0 || (global_frame_advance_debug_active_flag & 1) == 0) {
LABEL_27:
    if (!pausemenu_var3)
      Smbll_HandleLevelTileAnimations();
    Smbll_HandlePauseMenu();
    Smbll_DoSomeDigitsStuff();
    if (!area_type)
      Smbll_HandleLayersScroll();
    if ((int8)game_loop_toggler > 0 && screen_timer && ((controller_press2p1 & 0x80u) != 0 || (controller_press1p1 & 0x90) != 0)) {
      screen_timer = 0;
      game_loop_toggler = 0;
    }
    if (fade_direction) {
      Smbll_HandleScreenTransition();
    } else {
      if (display_pause_menu_flag & 1)
        goto LABEL_54;
      if (!timer_control || (--timer_control, !timer_control)) {
        v9 = 24;
        if ((--interval_timer_control & 0x80u) != 0) {
          interval_timer_control = 20;
          v9 = 43;
        }
        do {
          if (*(&all_timers + v9))
            --*(&all_timers + v9);
          --v9;
        } while ((v9 & 0x80u) == 0);
      }
      if (!screen_timer)
        game_loop_toggler &= 0x80u;
      ++frame_counter;
      if ((++podoboo_animation_frame_counter & 0x18) == 24)
        podoboo_animation_frame_counter = 0;
      Smbll_CheckIfBowserTouchedLava();
      if (sprite0_hit_detect_flag) {
        if (!(disable_sprite_oamreset_flag & 1))
          Smbll_ResetMiscSpriteOamId();
      }
      Smbll_ProcessGameMode();
      if ((cutscene_var1680 & 0x80u) != 0) {
LABEL_54:
        Smbll_DrawLevelPreviewSprites_Sub_New();
        Smbll_MaybePauseMenuHandler();
      }
    }
  }
  Smbll_CompressOAMTileSizeBuffer();
  wait_for_vblank = 0;
}

void Smbll_VectorNMI() {
  uint8 v0;   // al
  uint8 v1;   // si
  uint16 v2;  // si
  int16 v3;   // ax
  uint16 v4;  // si
  int16 v5;   // ax
  uint8 v6;   // di
  uint16 v7;  // si
  uint8 v8;   // si
  int16 v9;   // [rsp+3Fh] [rbp-9h]

  v9 = *(uint16 *)&R0_;
  ReadReg(RDNMI);
  v0 = inidisp_mirror;
  if (!inidisp_mirror)
    v0 = 0x80;
  WriteReg(INIDISP, v0);
  WriteReg(HDMAEN, 0);
  if (!wait_for_vblank) {
    ++wait_for_vblank;
    v1 = vram_buffer_addr_ctrl;
    if (current_player) {
      if (vram_buffer_addr_ctrl == 12)
        v1 = 31;
      if (v1 == 16)
        v1 = 32;
      if (v1 == 19)
        v1 = 33;
    }
    R0_ = kbyte_2F370[v1];
    R1_ = kbyte_2F392[v1];
    WriteReg(A1B1, 2u);
    R2_ = 2;
    Smbll_UploadStripeImage();
    if (vram_buffer_addr_ctrl == 6) {
      R0_ = kbyte_2F370[0];
      R1_ = kbyte_2F392[0];
      WriteReg(A1B1, 2u);
      R2_ = 2;
      Smbll_UploadStripeImage();
    }
    WriteReg(VMAIN, 0x81u);
    WriteRegWord(DMAP0, 0x1801u);
    if (vblank_upload_from_7f0000_flag) {
      WriteReg(A1B0, 0x7Fu);
      v2 = 0;
      v3 = upload_buffer_3[1];
      do {
        WriteRegWord(VMADDL, v3);
        WriteRegWord(A1T0L, v2 + 4);
        WriteRegWord(DAS0L, 0x40u);
        v2 += 66;
        WriteRegWord(MDMAEN, 1u);
        v3 = upload_buffer_3[(v2 >> 1) + 1];
      } while (v3 >= 0);
      vblank_upload_from_7f0000_flag = 0;
    }
    if (vblank_flag_0ED4) {
      WriteReg(A1B0, 0x7Fu);
      v4 = 0;
      v5 = layer3_tilemap_upload_buf[1];
      do {
        WriteRegWord(VMADDL, v5);
        WriteRegWord(A1T0L, v4 + 8196);
        WriteRegWord(DAS0L, 0x38u);
        v4 += 58;
        WriteRegWord(MDMAEN, 1u);
        v5 = layer3_tilemap_upload_buf[(v4 >> 1) + 1];
      } while (v5 >= 0);
    }
    vblank_flag_0ED4 = 0;
    WriteReg(VMAIN, 0x80u);
    Smbll_VramFunc_9B5C();
    if (update_entire_palette_flag) {
      if ((update_entire_palette_flag & 0x80u) != 0) {
        update_entire_palette_flag = 1;
      } else {
        WriteReg(CGADD, 0);
        WriteRegWord(DMAP0, 0x2200u);
        WriteRegWord(A1T0L, 0x1000u);
        WriteReg(A1B0, 0);
        WriteRegWord(DAS0L, 0x200u);
        WriteReg(MDMAEN, 1u);
        update_entire_palette_flag = 0;
      }
    }
    v6 = 0;
    if (vram_buffer_addr_ctrl == 6)
      v6 = 2;
    v7 = kword_81A0[v6 >> 1];
    *(uint16 *)&vram_buffer1[v7] = 0;
    *(uint16 *)&vram_buffer1[v7 + 2] = -1;
    upload_buffer_3[0] = 0;
    if (area_type)
      layer3_tilemap_upload_buf[0] = 0;
    vram_buffer_addr_ctrl = 0;
  }
  WriteReg(HDMAEN, hdmaenable_mirror);
  WriteReg(CGWSEL, cgwsel_mirror);
  WriteReg(CGADSUB, cgadsub_mirror);
  WriteReg(W12SEL, w12sel_mirror);
  WriteReg(W34SEL, w34sel_mirror);
  WriteReg(WOBJSEL, wobjsel_mirror);
  WriteReg(TM, tm_mirror);
  WriteReg(TS, ts_mirror);
  WriteReg(TMW, tmw_mirror);
  WriteReg(TSW, tsw_mirror);
  WriteReg(COLDATA, coldata1_mirror);
  WriteReg(COLDATA, coldata2_mirror);
  WriteReg(COLDATA, coldata3_mirror);
  WriteReg(BGMODE, bgmode_mirror);
  WriteReg(MOSAIC, mosaic_mirror);
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3HOFS, 0);
  if (vblank_which_layer2_scroll_flag) {
    WriteReg(BG2HOFS, layer3_xpos);
    WriteReg(BG2HOFS, HIBYTE(layer3_xpos));
  }
  if (!fade_direction) {
    WriteReg(BG1HOFS, layer1_xpos_lo);
    WriteReg(BG1HOFS, screen_left_xpos_hi);
    if (!vblank_which_layer2_scroll_flag) {
      WriteReg(BG2HOFS, layer2_xpos);
      WriteReg(BG2HOFS, HIBYTE(layer2_xpos));
    }
    WriteReg(BG1VOFS, layer1_ypos_lo);
    WriteReg(BG1VOFS, 0);
    WriteReg(BG2VOFS, layer2_ypos);
    WriteReg(BG2VOFS, HIBYTE(layer2_ypos));
  }
  v8 = -127;
  if (vblank_enable_vtimel_flag) {
    ReadReg(TIMEUP);
    WriteReg(VTIMEL, vtimel_mirror);
    WriteReg(VTIMEH, 0);
    WriteReg(HTIMEL, 0);
    WriteReg(HTIMEH, 0);
    v8 = -95;
  }
  WriteReg(NMITIMEN, v8);
  *(uint16 *)&R0_ = v9;
}

void Smbll_VectorIRQ() {
  if ((ReadReg(TIMEUP) & 0x80u) != 0 && vblank_enable_vtimel_flag) {
    if (vblank_which_layer2_scroll_flag) {
      while ((ReadReg(HVBJOY) & 0x40) == 0)
        ;
      WriteReg(BG2HOFS, layer2_xpos);
      WriteReg(BG2HOFS, HIBYTE(layer2_xpos));
    } else {
      while ((ReadReg(HVBJOY) & 0x40) == 0)
        ;
      WriteReg(BG3HOFS, layer3_xpos);
      WriteReg(BG3HOFS, HIBYTE(layer3_xpos));
    }
  }
}

void Smbll_ProcessGameMode() {
  int16 v0;  // si

  v0 = 2 * *(uint16 *)&game_mode;
  if (2 * *(uint16 *)&game_mode) {
    switch (v0) {
    case 4: Smbll_GameMode02_Cutscene(); break;
    case 6: Smbll_GameMode03_GameOverScreen(); break;
    case 2: Smbll_GameMode01_Level(); break;
    default:
      Unreachable();
      while (1)
        ;
    }
  } else {
    Smbll_GameMode00_TitleScreen();
  }
}

void Smbll_ResetAllSpriteOams_Far() {
  Smbll_ResetAllSpriteOams();
}

void Smbll_ResetMiscSpriteOamId() {
  misc_spr_oam_id[0] = -112;
  misc_spr_oam_id[1] = -108;
  misc_spr_oam_id[2] = -104;
  misc_spr_oam_id[3] = -100;
  misc_spr_oam_id[4] = -96;
  misc_spr_oam_id[5] = -92;
  misc_spr_oam_id[6] = -88;
  misc_spr_oam_id[7] = -84;
  misc_spr_oam_id[8] = 88;
  if (bowser_var0096)
    Smbll_ResetAlmostAllSpriteOams();
  else
    Smbll_DrawLevelPreviewSprites_Sub_New();
}

void Smbll_DrawLevelPreviewSprites_Sub_New() {
  OamEnt *oam;  // rbp

  if (var0E67) {
    oam = get_OamEnt(oam_buf, 0);
    oam[20].ypos = -16;
    oam[21].ypos = -16;
    oam[44].ypos = -16;
    oam[45].ypos = -16;
    oam[46].ypos = -16;
    oam[47].ypos = -16;
    oam[48].ypos = -16;
    oam[49].ypos = -16;
    oam[50].ypos = -16;
    oam[51].ypos = -16;
  } else {
    Smbll_ResetAllSpriteOams();
  }
}

void Smbll_ResetAllSpriteOams() {
  uint8 i;      // si
  OamEnt *oam;  // rbp

  for (i = 0; i != 64; i += 4) {
    oam = get_OamEnt(oam_buf, i);
    oam->ypos = -16;
    oam[16].ypos = -16;
    oam[32].ypos = -16;
    oam[48].ypos = -16;
    oam[64].ypos = -16;
    oam[80].ypos = -16;
    oam[96].ypos = -16;
    oam[112].ypos = -16;
    oam_tile_size_buffer[i] = 0;
    oam_tile_size_buffer[i + 64] = 0;
    oam_tile_size_buffer[i + 128] = 0;
    oam_tile_size_buffer[i + 192] = 0;
    oam_tile_size_buffer[i + 256] = 0;
    oam_tile_size_buffer[i + 320] = 0;
    oam_tile_size_buffer[i + 384] = 0;
    oam_tile_size_buffer[i + 448] = 0;
  }
}

void Smbll_ResetAlmostAllSpriteOams() {
  uint8 i;      // si
  OamEnt *oam;  // rbp

  for (i = 0; i != 64; i += 4) {
    oam = get_OamEnt(oam_buf, i);
    oam[16].ypos = -16;
    oam[32].ypos = -16;
    oam[48].ypos = -16;
    oam[64].ypos = -16;
    oam[80].ypos = -16;
    oam[96].ypos = -16;
    oam[112].ypos = -16;
    oam_tile_size_buffer[i + 64] = 0;
    oam_tile_size_buffer[i + 128] = 0;
    oam_tile_size_buffer[i + 192] = 0;
    oam_tile_size_buffer[i + 256] = 0;
    oam_tile_size_buffer[i + 320] = 0;
    oam_tile_size_buffer[i + 384] = 0;
    oam_tile_size_buffer[i + 448] = 0;
  }
}

void Smbll_GameMode00_TitleScreen() {
  funcs_E2B[(uint8)(2 * game_mode_task) >> 1]();
  music_ch1 = 0;
}
// E33: using guessed type int (*funcs_E2B[4])();

void Smbll_TitleScreen_3_GameMenuRoutine() {
  int8 v0;   // al
  int8 i;    // si
  int8 v2;   // [rsp+47h] [rbp-1h]
  uint8 v3;  // [rsp+47h] [rbp-1h]

  if ((controller_press1p1 & 0x10) != 0) {
    Smbll_sub_AB68();
    if (demo_timer) {
      v0 = 0;
      printf("Wtf is A\n");
      if (__CFSHL__(v0, 1))
        Smbll_sub_86FC(9);
      sound_ch3 = 41;
      demo_timer = 24;
      if (splash_screen_display_mario_coin_shine_flag) {
        if (number_of_players == 2) {
          sram_controller_type_x = (sram_controller_type_x ^ 1) & 1;
          sound_ch3 = 1;
          Smbll_LoadPlayerSelectMenu_Entry2();
        } else {
          player_luigi_graphics = number_of_players;
          current_player = number_of_players;
          smbll_varF08 = 0;
          smbll_varF09 = 0;
          title_screen_hard_mode_flag = 0;
          Smbll_CODE_05C95B();
          number_of_players = 0;
          if (world_number >= 9u)
            ++title_screen_hard_mode_flag;
          var0E67 = 1;
          cutscene_var0BA5 = 1;
          Smbll_PlayerGfxHandler();
          Smbll_LoadAreaPointer();
          ++hidden_1up_flag;
          ++offscr_hidden_1up_flag;
          ++fetch_new_game_timer_flag;
          ++game_mode;
          primary_hard_mode = title_screen_hard_mode_flag;
          game_mode_task = 0;
          demo_timer = 0;
          for (i = 11; i >= 0; --i)
            score_and_coin_display[(uint8)i] = 0;
          tempE4 = 0;
          score_and_coin_display[5] = Smbll_ComputeDigitValue(player_coin_count);
          score_and_coin_display[4] = tempE4;
          unused_byte_7E0E1A = 1;
        }
      } else if (number_of_players == 3) {
        title_screen_erase_file_process ^= 1u;
        Smbll_LoadFileSelectMenu_Entry2();
      } else if (title_screen_erase_file_process) {
        Smbll_ClearSaveData_Main();
        Smbll_LoadFileSelectMenu_Entry2();
        sound_ch3 = 5;
      } else {
        ++splash_screen_display_mario_coin_shine_flag;
        sram_world_number = *(&title_screen_file_aselected_world + number_of_players) >> 2;
        sram_initial_selected_level = *(&title_screen_file_aselected_world + number_of_players) & 3;
        Smbll_LoadSaveFileData_Main();
        if (splash_screen_display_mario_coin_shine_flag)
          Smbll_LoadPlayerSelectMenu_Main();
        else
          Smbll_LoadFileSelectMenu_Main();
      }
      return;
    }
LABEL_26:
    game_mode = 0;
    game_mode_task = 0;
    sprite0_hit_detect_flag = 0;
    fade_direction = 1;
    ++disable_screen_flag;
    return;
  }
  Smbll_sub_2FB79();
  if (controller_hold2p1 == 0xB0 && saved_joypad_bits == 0x80) {
    sram_top_score[0] = 0;
    sram_top_score[1] = 0;
    sram_top_score[2] = 0;
    sram_top_score[3] = 0;
    sram_top_score[4] = 0;
    sram_top_score[5] = 0;
    displayed_score[0] = 0;
    displayed_score[1] = 0;
    displayed_score[2] = 0;
    displayed_score[3] = 0;
    displayed_score[4] = 0;
    displayed_score[5] = 0;
    sound_ch1 = 8;
    goto LABEL_26;
  }
  if ((save_buffer_2_player_flag & 0x80u) == 0)
    demo_timer = 64;
  if (demo_timer)
    Smbll_DrawMushroomIcon();
  if ((controller_press1p1 & 0x2C) != 0) {
    if (!demo_timer)
      goto LABEL_26;
    demo_timer = 24;
    Smbll_MoveTitleScreenMenuCursor_Main(controller_press1p1 & 0x2C);
    goto LABEL_16;
  }
  if (demo_timer) {
LABEL_16:
    saved_joypad_bits = 0;
    goto LABEL_17;
  }
  if (Smbll_TitleScreen_Func1() & 1)
    goto LABEL_26;
LABEL_17:
  v2 = controller_press2p1 | controller_press1p1;
  if (title_screen_erase_file_process | splash_screen_display_mario_coin_shine_flag) {
    if ((v2 & 0x40) != 0) {
      demo_timer = 24;
      if (splash_screen_display_mario_coin_shine_flag) {
        splash_screen_display_mario_coin_shine_flag = 0;
        Smbll_LoadFileSelectMenu_Main();
        number_of_players = 0;
        save_buffer_2_player_flag = -1;
      }
    }
  } else if ((v2 & 0x83) != 0) {
    Smbll_ChangeSelectedWorld_Main(v2 & 0x83);
    demo_timer = 24;
  }
  v3 = sound_ch3;
  Smbll_sub_AB68();
  sound_ch1 = 0;
  sound_ch2 = 0;
  sound_ch3 = v3;
  if (game_engine_subroutine == 6) {
    UNUSED_byte_7E0EC8 = 0;
    goto LABEL_26;
  }
}

uint8 Smbll_ComputeDigitValue(uint8 a) {
  while (a >= 0xAu) {
    ++tempE4;
    a -= 10;
  }
  return a;
}

void Smbll_sub_86FC(uint8 a) {
  world_number = a;
}

void Smbll_GameMode02_Cutscene() {
  Smbll_RunCutsceneTask();
  if (game_mode_task) {
    object_index = 0;
    Smbll_EnemiesAndLoopsCore(0);
  }
  Smbll_RelativePlayerPosition();
  Smbll_PlayerGfxHandler();
}

void Smbll_RunCutsceneTask() {
  uint8 v0;  // di
  bool v1;   // cf
  int8 v2;   // al
  uint8 v3;  // si
  uint8 v4;  // al

  if (cutscene_0EC4) {
    switch (game_mode_task) {
    case 0u:
LABEL_74:
      v3 = browser_front_offset;
      if (enemy_id[browser_front_offset] != 45)
        goto LABEL_78;
      object_index = browser_front_offset;
      v4 = enemy_state[browser_front_offset];
      if (v4) {
        if ((v4 & 0x40) != 0 && obj_ypos_lo.enemy[browser_front_offset] < 0xE0u) {
          Smbll_MoveEnemySlowVert(browser_front_offset);
          Smbll_BowserGfxHandler(v3);
        } else {
LABEL_78:
          if (!bridge_collapse_sfx_flag) {
            music_ch1 = 11;
            bridge_collapse_sfx_flag = 11;
          }
          ++game_mode_task;
          Smbll_KillAllEnemies();
        }
      } else {
        if (!--bowser_feet_counter) {
          bowser_feet_counter = 4;
          browser_body_controls ^= 1u;
          R5_ = 2;
          R4_ = kBridgeCollapseData[bridge_collapse_offset];
          Smbll_BridgeCollapse_Sub(R4_);
          Smbll_RemBridge(0x18u, vram_buffer1[0] + 1);
          v3 = object_index;
          Smbll_MoveVOffset();
          sound_ch3 = 22;
          if (!bridge_collapse_offset) {
            bowser_var014B = 8;
            bowser_var0F4C = -1;
          }
          if (++bridge_collapse_offset == 15) {
            Smbll_InitVStf(v3);
            enemy_state[v3] = 64;
          }
        }
        Smbll_BowserGfxHandler(v3);
      }
      return;
    case 1u:
      Smbll_CODE_04DE54();
LABEL_30:
      enemy_data_a[0] = screen_right_xpos_hi + 1;
      Smbll_IncModeTask_B();
      return;
    case 2u:
LABEL_32:
      if (bowser_var0096)
        return;
      if (cutscene_peach_var0F82)
        Smbll_Ending_SetGfxPtrToUpload();
      v0 = 0;
      enemy_data_a[1] = 0;
      if (obj_xpos_hi.player != enemy_data_a[0])
        goto LABEL_43;
      if (world_number == 7 || world_number == 12) {
        ++enemy_data_a[1];
        Smbll_CODE_04DBDA();
        goto LABEL_44;
      }
      if (world_number == 2) {
        if (obj_xpos_lo.player >= 0x44u)
          goto LABEL_44;
      } else if (obj_xpos_lo.player >= 0x54u) {
        goto LABEL_44;
      }
LABEL_43:
      ++enemy_data_a[1];
      v0 = 1;
LABEL_44:
      Smbll_AutoControlPlayer(v0);
      if (screen_left_xpos_hi != enemy_data_a[0]) {
        int t = cutscene_task_subpos + 0x180;
        cutscene_task_subpos = t;
        Smbll_ScrollHandler(t >> 8);
        Smbll_CODE_03AE2C();
        ++enemy_data_a[1];
      }
      if (!enemy_data_a[1])
LABEL_62:
        ++game_mode_task;
      break;
    case 3u:
      if (player_size)
        Smbll_SpawnMushroomDuringPeachCutscene();
      else
        ++game_mode_task;
      ++game_mode_task;
      return;
    case 4u:
      saved_joypad_bits = 0;
      controller_press1p1 = 0;
      controller_hold1p2 = 0;
      controller_press1p2 = 0;
      controller_hold2p1 = 0;
      controller_hold2p2 = 0;
      controller_press2p1 = 0;
      controller_press2p2 = 0;
      game_paused_timer = 2;
      Smbll_GameMode01_Level_GameCoreRoutine();
      if (!player_size)
        ++game_mode_task;
      return;
    case 5u:
LABEL_21:
      if (event_music_buffer < 6u) {
        if ((ReadReg(APUI03) & 0x7F) != 75)
          sound_ch3 = 75;
        Smbll_CODE_03D809();
        if (!(level_timer_ones | (uint8)(level_timer_tens | level_timer_hundreds))) {
          sound_ch3 = 76;
          unused_byte_7E0E1A = 76;
          all_timers = 48;
          event_music_buffer = 6;
          ++game_mode_task;
        }
      }
      return;
    case 6u:
      ++game_mode_task;
      ++cutscene_peach_current_state;
      return;
    case 7u:
      Smbll_ProcessPeachMovement();
      if (cutscene_peach_current_state >= 6u)
        ++game_mode_task;
      return;
    case 8u:
      music_ch1 = 16;
      Smbll_Ending_SetPaletteWriteText();
      Smbll_PauseMenu_Func5();
      ++game_mode_task;
      return;
    case 9u: Smbll_PeachCutscene_04DE8B(); return;
    case 0xAu: ++game_mode_task; return;
    case 0xBu: ++game_mode_task; return;
    case 0xCu:
LABEL_64:
      if (!event_music_buffer) {
        area_number = 0;
        level_number = 0;
        game_mode_task = 0;
        if (cutscene_var1680 != 0x90) {
          v2 = world_number + 1;
          if ((uint8)(world_number + 1) >= 0xCu)
            v2 = 12;
          if (v2 == 8 && smbll_varF2B) {
            title_screen_hard_mode_flag = 1;
            ++world_number;
          }
          ++world_number;
        }
        Smbll_LoadAreaPointer();
        ++fetch_new_game_timer_flag;
        game_mode = 1;
      }
      return;
    case 0xDu: Smbll_CODE_04862A(); return;
    case 0xEu: Smbll_WaitForMusicAndChangeTask(); return;
    }
  } else {
    switch (game_mode_task) {
    case 0u: goto LABEL_74;
    case 1u:
      if (pausemenu_var3) {
        Smbll_CutsceneToad_04ED07();
        goto LABEL_30;
      }
      Smbll_CutsceneBowserDefeat_04ECCA();
      break;
    case 2u: goto LABEL_32;
    case 3u:
      if (++cutscene_wait_before_toad_breaks_out_of_bag == 112) {
        cutscene_toad_popped_out_of_bag_flag = 1;
        cutscene_wait_before_toad_breaks_out_of_bag = 0;
        ++game_mode_task;
      }
      return;
    case 4u:
      if (cutscene_toad_text_timer ||
          cutscene_toad_line_to_display && (cutscene_toad_line_to_display >= 8u || !cutscene_toad_line_to_display)) {
        goto LABEL_59;
      }
      if (!cutscene_toad_line_to_display)
        goto LABEL_58;
      if (cutscene_toad_line_to_display < 3u) {
        if (cutscene_toad_line_to_display < 2u)
LABEL_58:
          vram_buffer_addr_ctrl = cutscene_toad_line_to_display + 12;
LABEL_59:
        v1 = __CFADD__(cutscene_toad_text_timer, 4);
        cutscene_toad_text_timer += 4;
        cutscene_toad_line_to_display += v1;
        if (cutscene_toad_line_to_display < 6)
          return;
      }
      event_music_buffer = 8;
      var0E67 = 8;
      goto LABEL_62;
    case 5u: goto LABEL_21;
    case 6u: goto LABEL_64;
    }
  }
}

void Smbll_sub_8932() {
  if (((controller_hold1p2 | saved_joypad_bits) & 0x40) != 0) {
    title_screen_hard_mode_flag = 1;
    number_of_lives = -1;
    Smbll_CODE_03A1EF();
  }
}

void Smbll_FloateyNumbersRoutine(uint8 k) {
  uint8 v1;     // al
  uint8 v2;     // di
  uint8 v3;     // al
  uint8 v4;     // si
  uint8 v5;     // di
  uint8 v6;     // si
  OamEnt *oam;  // rbp
  int v8;       // edx
  uint8 v9;     // al
  uint8 v10;    // si
  int8 v11;     // al

  v1 = floateynum_control[k];
  if (v1) {
    if (v1 >= 0xBu) {
      v1 = 11;
      floateynum_control[k] = 11;
      if (k != 9)
        stomp_chain_counter = 11;
    }
    v2 = v1;
    v3 = floateynum_timer[k];
    if (v3) {
      --floateynum_timer[k];
      if (v3 == 43) {
        if (v2 == 11) {
          Smbll_GiveExtraLife();
          sound_ch3 = 5;
        }
        digit_modifier[kbyte_8962[v2] >> 4] = kbyte_8962[v2] & 0xF;
        Smbll_AddToScore();
      }
      v4 = object_index;
      v5 = floatey_numbers_oam_id;
      while (get_OamEnt(oam_buf, v5)->ypos != 0xF0) {
        v5 += 8;
        if (v5 == 0x90) {
          v5 = floatey_numbers_oam_id;
          break;
        }
      }
      if (score_spr_ypos_lo[object_index] >= 0x18u)
        score_spr_ypos_lo[object_index] -= (score_spr_ypos_lo[object_index] < 0x18u) + 1;
      Smbll_DumpTwoSpr_(v5, score_spr_ypos_lo[v4]);
      tempE0 = v4;
      *(uint16 *)&tempE2 = floateynum_xpos_word[(uint8)(2 * v4) >> 1];
      *(uint16 *)&tempDE = *(uint16 *)&tempE2 + 8;
      v6 = tempE0;
      tempDD = 0;
      if (temp3D)
        tempDD |= 1u;
      oam_tile_size_buffer[v5] = tempDD;
      if (floateynum_control[v6] < 6u || floateynum_control[v6] == 11)
        tempDD = 0;
      else
        tempDD = 2;
      if (tempDF)
        tempDD |= 1u;
      oam_tile_size_buffer[v5 + 4] = tempDD;
      oam = get_OamEnt(oam_buf, v5);
      oam->xpos = tempE2;
      oam[1].xpos = tempDE;
      v8 = (uint8)(2 * floateynum_control[v6]);
      oam->charnum = kbyte_894A[(uint8)(2 * floateynum_control[v6])];
      v9 = kbyte_894A[v8 + 1];
      oam[1].charnum = v9;
      v10 = v9;
      v11 = 50;
      oam->flags = 50;
      if (v10 == 14)
        v11 = 51;
      oam[1].flags = v11;
    } else {
      floateynum_control[k] = 0;
    }
  }
}

void Smbll_ScreenRoutines() {
  int8 v0;    // si
  uint16 v1;  // si
  int v2;     // edx
  uint8 v3;   // [rsp+46h] [rbp-2h]
  uint8 v4;   // [rsp+47h] [rbp-1h]

  v0 = 2 * screen_routine_task;
  if (!(2 * screen_routine_task)) {
    if (game_mode) {
      vram_buffer_addr_ctrl = 0;
      update_entire_palette_flag = 1;
    }
    goto LABEL_52;
  }
  switch (v0) {
  case 2:
    v4 = background_color_ctrl;
    v3 = player_status;
    player_status = 0;
    background_color_ctrl = 2;
    Smbll_GetPlayerColors();
    player_status = v3;
    background_color_ctrl = v4;
    goto LABEL_52;
  case 20:
    Smbll_SetLevelMusic();
    Smbll_CODE_04956B();
    return;
  case 22: Smbll_GetBackgroundColor_0(); return;
  case 24: ++screen_routine_task; return;
  case 4:
    Smbll_WriteGameText(0);
    if (current_player) {
      vram_buffer1[6] = 21;
      vram_buffer1[8] = 30;
      vram_buffer1[10] = 18;
      vram_buffer1[14] = 18;
      vram_buffer1[12] = 16;
    }
    goto LABEL_52;
  case 6:
    Smbll_GetSBNibbles();
    v1 = *(uint16 *)vram_buffer1;
    v2 = *(uint16 *)vram_buffer1;
    *(uint16 *)&vram_buffer1[*(uint16 *)vram_buffer1 + 2] = 29528;
    *(uint16 *)&vram_buffer1[v2 + 4] = 1280;
    vram_buffer1[v1 + 6] = world_number + 1;
    vram_buffer1[v1 + 7] = 32;
    vram_buffer1[v1 + 9] = 32;
    vram_buffer1[v1 + 11] = 32;
    vram_buffer1[v1 + 8] = 36;
    vram_buffer1[v1 + 10] = level_number + 1;
    vram_buffer1[v1 + 12] = -1;
    if (!game_mode && (save_buffer_2_player_flag & 0x80u) == 0) {
      vram_buffer1[v1 + 6] = save_buffer + 1;
      vram_buffer1[v1 + 10] = g_byte_7FFB01 + 1;
    }
    *(uint16 *)vram_buffer1 = v1 + 10;
    goto LABEL_52;
  case 8:
    if (game_timer_expired_flag) {
      game_timer_expired_flag = 0;
      Smbll_DrawLevelPreviewSprites_Sub_New();
      Smbll_CODE_0491DD();
      game_loop_toggler = 1;
      Smbll_OutputInter(2u);
      return;
    }
    ++screen_routine_task;
    goto LABEL_52;
  }
  if (v0 != 12) {
    if (v0 == 18) {
      Smbll_AreaParserTaskControl();
      return;
    }
    if (v0 != 26) {
      switch (v0) {
      case 28: Smbll_ClearBuffersDrawIcon(); break;
      case 30: Smbll_WriteTopScore(); break;
      case 10:
      case 16: Smbll_ResetSpritesAndScreenTimer(); break;
      case 14:
        if (game_mode == 3) {
          screen_timer = 32;
          vram_buffer_addr_ctrl = 30;
          ++game_mode_task;
        } else {
          if (!smbll_varF07) {
            vram_buffer_addr_ctrl = 29;
            ++smbll_varF07;
          }
          disable_screen_flag = 0;
          ++screen_routine_task;
        }
        break;
      default:
        Unreachable();
        while (1)
          ;
      }
      return;
    }
    if (game_mode) {
      Smbll_IncModeTask_B();
      return;
    }
    Smbll_DrawTitleScreen_Sub();
    player_luigi_graphics = 0;
    game_loop_toggler = 0x80;
    vram_buffer_addr_ctrl = 5;
LABEL_52:
    ++screen_routine_task;
    return;
  }
  if (!game_mode)
    goto LABEL_47;
  if (game_mode == 3) {
    Smbll_CODE_8E50();
    return;
  }
  if (!alt_entrance_ctrl && (area_type == 3 || !screen_routines_flag0769)) {
    Smbll_DrawLevelPreviewSprites();
    Smbll_CODE_0492E7();
    Smbll_OutputInter(1u);
  } else {
LABEL_47:
    Smbll_NoInter();
  }
}

void Smbll_OutputInter(uint8 a) {
  Smbll_WriteGameText(a);
  Smbll_ResetScreenTimer();
  w12sel_mirror = 0;
  w34sel_mirror = 0;
  wobjsel_mirror = 0;
  cgwsel_mirror = 0;
  cgadsub_mirror = 32;
  hdmaenable_mirror = 0;
  fade_direction = 2;
  enable_mosaic_fades_flag = 0;
  inidisp_mirror = 0;
  mosaic_mirror = 0;
  disable_screen_flag = 0;
}

void Smbll_NoInter() {
  screen_routine_task = 9;
}

void Smbll_CODE_8E50() {
  w12sel_mirror = 0;
  w34sel_mirror = 0;
  wobjsel_mirror = 0;
  cgwsel_mirror = 0;
  cgadsub_mirror = 32;
  hdmaenable_mirror = 0;
  if (disable_screen_flag) {
    enable_mosaic_fades_flag = 0;
    disable_screen_flag = 0;
    inidisp_mirror = 0;
    fade_direction = 2;
    Smbll_CODE_0491DD();
  }
  Smbll_RunGameOver_Sub();
  screen_timer = 9;
  Smbll_WriteGameText(3u);
  Smbll_IncModeTask_B();
}

void Smbll_AreaParserTaskControl() {
  if (disable_screen_flag) {
    if (disable_screen_flag != 1)
      ++disable_screen_flag;
    do
      Smbll_AreaParserTaskHandler();
    while (area_parser_task_num);
    if ((--column_sets & 0x80u) != 0)
      ++screen_routine_task;
    vram_buffer_addr_ctrl = 6;
  } else {
    fade_direction = 1;
    enable_mosaic_fades_flag = 0;
  }
}

void Smbll_ClearBuffersDrawIcon() {
  uint8 v0;  // al
  uint8 v1;  // si

  v0 = game_mode;
  if (game_mode) {
    Smbll_IncModeTask_B();
  } else {
    v1 = 0;
    do {
      bridge_sprite_slot_exists_flag[v1] = v0;
      *(&g_byte_7E0400 + v1--) = v0;
    } while (v1);
    Smbll_DrawMushroomIcon();
    ++screen_routine_task;
  }
}

void Smbll_WriteTopScore() {
  Smbll_UpdateNumber(0xFAu);
  Smbll_IncModeTask_B();
}

void Smbll_IncModeTask_B() {
  ++game_mode_task;
}

uint8 Smbll_WriteGameText(uint8 a) {
  uint8 v1;   // al
  uint16 v2;  // di
  uint8 v3;   // si
  uint16 v4;  // si
  uint16 v5;  // di
  uint8 v6;   // al
  bool v7;    // cf
  uint8 v8;   // al
  int8 v9;    // al

  v1 = 2 * a;
  v2 = v1;
  if (v1) {
    if (v1 >= 4u) {
      if (v1 >= 8u)
        LOBYTE(v2) = 8;
      if (!number_of_players)
        LOBYTE(v2) = v2 + 1;
    }
  } else if (number_of_players) {
    LOBYTE(v2) = v1 + 1;
  }
  tempF3 = v2;
  v3 = kbyte_8E36[(uint8)v2];
  if (world_number == 8 && (uint8)v2 == 7) {
    LOBYTE(v2) = 6;
    v3 = kbyte_8E36[6];
    tempF3 = 6;
  }
  *(uint16 *)&tempDE = kbyte_8E40[v2] << 8;
  v4 = *(uint16 *)&tempDE | v3;
  v5 = 0;
  while (kGameText[v4] != 0xFF)
    vram_buffer1[v5++ + 2] = kGameText[v4++];
  vram_buffer1[v5 + 2] = -1;
  if (a < 4u) {
    if (a == 1) {
      v6 = number_of_lives + 1;
      if ((uint8)(number_of_lives + 1) >= 0xAu) {
        tempE4 = 0;
        tempE5 = 0;
        while (1) {
          v7 = v6 < 0x64u;
          v6 -= 100;
          if (v7)
            break;
          ++tempE4;
        }
        v8 = v6 + 100;
        while (1) {
          v7 = v8 < 0xAu;
          v8 -= 10;
          if (v7)
            break;
          ++tempE5;
        }
        tempE6 = v8 + 10;
        if (tempE4)
          vram_buffer1[14] = tempE4;
        vram_buffer1[16] = tempE5;
        v6 = tempE6;
      }
      vram_buffer1[18] = v6;
      vram_buffer1[44] = world_number + 1;
      LOBYTE(v5) = level_number + 1;
      vram_buffer1[48] = level_number + 1;
    } else if (number_of_players) {
      v9 = current_player;
      if (a == 2) {
        LOBYTE(v5) = game_mode;
        if (game_mode != 3) {
          if ((other_player_num_lives & 0x80u) != 0)
            v9 = current_player;
          else
            v9 = current_player ^ 1;
        }
      }
      if (v9 & 1) {
        LOBYTE(v5) = 9;
        if (tempF3 == 4 || tempF3 == 6) {
          do {
            vram_buffer1[(uint8)v5 + 6] = kbyte_8E0D[(uint8)v5];
            vram_buffer1[(uint8)v5 + 20] = kbyte_8E17[(uint8)v5];
            LOBYTE(v5) = v5 - 1;
          } while ((v5 & 0x80u) == 0);
        } else {
          do {
            vram_buffer1[(uint8)v5 + 6] = kbyte_8E21[(uint8)v5];
            LOBYTE(v5) = v5 - 1;
          } while ((v5 & 0x80u) == 0);
        }
      }
    }
  } else {
    Smbll_sub_8F46(a);
  }
  return v5;
}

void Smbll_sub_8F46(uint8 a) {
  uint8 v1;  // di
  uint8 v2;  // si
  uint8 v3;  // al

  v1 = vram_buffer1[0];
  v2 = 0;
  do {
    v3 = kbyte_8DCC[v2];
    vram_buffer1[v1 + 2] = v3;
    ++v2;
    ++v1;
  } while (v3 != 0xFF);
  vram_buffer1[0] = v1;
  DUMMY_byte_7E16F4[v1 + 5] = kWarpZoneNumbers[(uint8)(a + 0x80)];
}

void Smbll_ResetSpritesAndScreenTimer() {
  if (!screen_timer) {
    if (game_mode != 3)
      fade_direction = 1;
    Smbll_ResetScreenTimer();
  }
}

void Smbll_ResetScreenTimer() {
  screen_timer = 7;
  ++screen_routine_task;
}

void Smbll_RenderAreaGraphics() {
  uint16 v0;   // ax
  int v1;      // rbp
  int8 v2;     // t0
  uint8 v3;    // si
  int8 v4;     // al
  bool v5;     // cf
  bool v6;     // cl
  int8 v7;     // al
  uint16 v8;   // di
  int v9;      // rbp
  int v10;     // rbp
  uint16 v11;  // ax
  uint16 v12;  // di
  int16 v13;   // ax

  if (!render_graphics_var0EC9) {
    *(uint16 *)&R0_ = vram_buffer2[0];
    v0 = render_graphics_var0720;
    v1 = vram_buffer2[0] >> 1;
    vram_buffer2[v1 + 1] = render_graphics_var0720;
    v2 = v0;
    LOBYTE(v0) = HIBYTE(v0);
    HIBYTE(v0) = v2;
    render_graphics_var0ecc = v0;
    vram_buffer2[v1 + 2] = 15744;
    vram_buffer2[v1 + 3] = 36;
    vram_buffer2[v1 + 4] = 36;
    vram_buffer2[v1 + 5] = 36;
    vram_buffer2[v1 + 6] = 36;
    v3 = 0;
    if (render_graphics_var0EE7) {
      render_graphics_var0EE6 = render_graphics_var0EE7;
      UNUSED_render_graphics_var0EF5 = render_graphics_var0720;
      render_graphics_var0EF4 = HIBYTE(render_graphics_var0720) + 1;
    }
    do {
      R2_ = v3;
      v4 = metatile_buffer[v3] & 0xC0;
      v5 = __CFSHL__(v4, 1);
      v4 *= 2;
      v6 = v5;
      v5 = __CFSHL__(v4, 1);
      v7 = 2 * v4 + v6;
      R6_ = kMetatileGraphics_Low[(uint8)(2 * v7 + v5)];
      R7_ = kMetatileGraphics_High[(uint8)(2 * v7 + v5)];
      *(uint16 *)&R3_ = 8 * (metatile_buffer[v3] & 0x3F);
      v8 = *(uint16 *)&R3_ + __CFSHL__(2 * !(area_parser_task_num & 1), 1) + 4 * !(area_parser_task_num & 1);
      v9 = *(uint16 *)&R0_ >> 1;
      vram_buffer2[v9 + 7] = *(uint16 *)&RomPtr_00(*(uint16 *)&R6_)[v8];
      vram_buffer2[v9 + 8] = *(uint16 *)&RomPtr_00(*(uint16 *)&R6_)[(uint16)(v8 + 2)];
      ++*(uint16 *)&R0_;
      ++*(uint16 *)&R0_;
      ++*(uint16 *)&R0_;
      ++*(uint16 *)&R0_;
      v3 = R2_ + 1;
    } while ((uint8)(R2_ + 1) < 0xDu);
    v10 = vram_buffer2[0] >> 1;
    v11 = vram_buffer2[v10 + 7];
    if (v11 == 6306 || v11 == 6307) {
      vram_buffer2[v10 + 3] = v11;
      vram_buffer2[v10 + 4] = v11;
      vram_buffer2[v10 + 5] = v11;
      vram_buffer2[v10 + 6] = v11;
    }
    v12 = *(uint16 *)&R0_ + 14;
    vram_buffer2[((uint16)(*(uint16 *)&R0_ + 14) >> 1) + 1] = -1;
    vram_buffer2[0] = v12;
    if (!cloud_type_override && area_type && area_type != 3) {
      if (*(uint16 *)&vram_buffer1[v12 + 760] == 2154 || *(uint16 *)&vram_buffer1[v12 + 760] == 2147)
        ++render_area_gfx_0ECE;
      v13 = *(uint16 *)&vram_buffer1[v12 + 760];
      if (v13 == 36 || v13 == 4260) {
        render_area_gfx_0ECE |= 0x100u;
      } else if (v13 == 2568) {
        render_area_gfx_0ECE &= 0xFF00u;
      }
      Smbll_CODE_048D71();
    }
    if ((++HIBYTE(render_graphics_var0720) & 0x1F) == 0)
      render_graphics_var0720 = (uint8)render_graphics_var0720 ^ 4;
    vram_buffer_addr_ctrl = 6;
  }
}

void Smbll_nullsub_1() {
  ;
}

void Smbll_ColorRotation() {
  ;
}

void Smbll_RemoveCoin_Axe() {
  Smbll_PutBlockMetatile(3u, vram_buffer1[0] + 1);
  vram_buffer_addr_ctrl = 6;
  Smbll_MoveVOffset();
}

void Smbll_ReplaceBlockMetatile(uint8 k, uint8 a) {
  Smbll_WriteBlockMetatile(a);
  ++block_residual_counter_unused;
  --block_repflag[k];
}

void Smbll_DestroyBlockMetatile() {
  Smbll_WriteBlockMetatile(0);
}

void Smbll_WriteBlockMetatile(uint8 a) {
  uint8 v1;  // di

  v1 = 3;
  if (a) {
    v1 = 0;
    if (a != 84 && a != 73) {
      v1 = 1;
      if (a != 90 && a != 74)
        v1 = 2;
    }
  }
  Smbll_PutBlockMetatile(v1, vram_buffer1[0] + 1);
  Smbll_MoveVOffset();
}

void Smbll_MoveVOffset() {
  *(uint16 *)vram_buffer1 += 16;
}

void Smbll_PutBlockMetatile(uint8 a, uint8 j) {
  uint8 v2;  // si
  uint8 v3;  // di
  int8 v4;   // al
  bool v5;   // cf
  int8 v6;   // al

  R1_ = j;
  v2 = 8 * a;
  v3 = 0;
  if (R6_ >= 0xD0u)
    v3 = 4;
  R3_ = v3;
  R4_ = 2 * (R6_ & 0xF);
  R5_ = __CFSHL__(R2_ + 32, 1);
  v4 = 4 * (R2_ + 32);
  v5 = __CFADD__(__CFSHL__(R5_, 1), v4);
  v6 = __CFSHL__(R5_, 1) + v4;
  v5 |= __CFADD__(R4_, v6);
  R4_ += v6;
  R5_ = v3 + v5 + 2 * R5_ + __CFSHL__(2 * (R2_ + 32), 1);
  Smbll_RemBridge(v2, R1_);
}

void Smbll_RemBridge(uint8 k, uint8 j) {
  int16 v2;  // ax
  int v3;    // rbp

  LOBYTE(v2) = R5_;
  HIBYTE(v2) = R4_;
  *(uint16 *)&vram_buffer1[j + 1] = v2;
  *(uint16 *)&vram_buffer1[j + 9] = v2 + 0x2000;
  *(uint16 *)&vram_buffer1[j + 3] = 768;
  *(uint16 *)&vram_buffer1[j + 11] = 768;
  v3 = k >> 1;
  *(uint16 *)&vram_buffer1[j + 5] = kBlockGfxData[v3];
  *(uint16 *)&vram_buffer1[j + 7] = kBlockGfxData[v3 + 1];
  *(uint16 *)&vram_buffer1[j + 13] = kBlockGfxData[v3 + 2];
  *(uint16 *)&vram_buffer1[j + 15] = kBlockGfxData[v3 + 3];
  *(uint16 *)&vram_buffer1[j + 17] = -1;
}

void Smbll_PollJoypadInputs() {
  uint8 v0;  // si

  while (ReadReg(HVBJOY) & 1)
    ;
  WriteReg(JOYA, 0);
  v0 = sram_controller1_plugged_in;
  controller_hold2p1 = ReadReg((SnesRegs)(sram_controller1_plugged_in + 16920));
  controller_press2p1 = controller_hold2p1 & (HIBYTE(p1_ctrl_disable) ^ controller_hold2p1);
  HIBYTE(p1_ctrl_disable) = controller_hold2p1;
  saved_joypad_bits = ReadReg((SnesRegs)(v0 + 16921));
  controller_press1p1 = saved_joypad_bits & (p1_ctrl_disable ^ saved_joypad_bits);
  LOBYTE(p1_ctrl_disable) = saved_joypad_bits;
}

void Smbll_VramFunc_9B5C() {
  WriteReg(DMAP0, 0);
  WriteRegWord(OAMADDL, 0);
  WriteRegWord(BBAD0, 4u);
  WriteRegWord(A1T0H, 8u);
  WriteRegWord(DAS0L, 0x220u);
  WriteReg(MDMAEN, 1u);
  WriteReg(OAMADDH, 0x80u);
  WriteReg(OAMADDL, 0);
  if (pausemenu_var3 || (Smbll_VramFunc_9BD4(1u), !vram_flag_028c) && vram_flag_028d) {
    WriteRegWord(VMADDL, graphics_upload_vramaddress);
    WriteRegWord(DMAP0, 0x1801u);
    WriteRegWord(A1T0L, graphics_upload_ptr.addr);
    WriteReg(A1B0, graphics_upload_ptr.bank);
    WriteRegWord(DAS0L, graphics_upload_size);
    WriteReg(MDMAEN, 1u);
    if (pausemenu_var3) {
      if (--pausemenu_var3) {
        HIBYTE(graphics_upload_ptr.addr) += 8;
        HIBYTE(graphics_upload_vramaddress) += 4;
      }
    }
  }
  vram_flag_028c = 0;
}

void Smbll_VramFunc_9BD4(uint8 k) {
  if (vram_flag_028e) {
    WriteRegWord(VMADDL, player_vramaddress);
    WriteRegWord(DMAP0, 0x1801u);
    WriteRegWord(A1T0L, player_graphics_pointer.addr);
    WriteReg(A1B0, player_graphics_pointer.bank);
    WriteRegWord(DAS0L, player_graphics_upload_size);
    WriteReg(MDMAEN, k);
  }
}

void Smbll_UploadStripeImage() {
  uint16 v0;  // di
  int8 i;     // al
  uint16 v2;  // di
  int8 v3;    // al
  uint8 *v4;  // rdx
  int16 v5;   // ax
  uint16 v6;  // si
  int16 v7;   // di
  uint16 v8;  // si

  R6_ = 0;
  v0 = 0;
  for (i = *IndirPtr((LongPtr *)&R0_, 0); i >= 0; i = *IndirPtr((LongPtr *)&R0_, v0)) {
    R4_ = i;
    v2 = v0 + 1;
    R3_ = *IndirPtr((LongPtr *)&R0_, v2++);
    v3 = *IndirPtr((LongPtr *)&R0_, v2) & 0x80;
    R7_ = 4 * v3 + __CFSHL__(v3, 1);
    R5_ = *IndirPtr((LongPtr *)&R0_, v2) & 0x40;
    WriteReg(DMAP1, (R5_ >> 3) | 1);
    WriteReg(BBAD1, 0x18u);
    WriteRegWord(VMADDL, *(uint16 *)&R3_);
    v4 = IndirPtr((LongPtr *)&R0_, v2);
    LOBYTE(v5) = HIBYTE(*(uint16 *)v4);
    HIBYTE(v5) = *(uint16 *)v4;
    v6 = (v5 & 0x3FFF) + 1;
    WriteRegWord(DAS1L, v6);
    v7 = v2 + 2;
    WriteRegWord(A1T1L, *(uint16 *)&R0_ + v7);
    if (*(uint16 *)&R5_) {
      v8 = (uint16)((v5 & 0x3FFF) + 2) >> 1;
      WriteRegWord(DAS1L, v8);
      WriteReg(DMAP1, R5_ >> 3);
      WriteReg(VMAIN, R7_);
      WriteReg(MDMAEN, 2u);
      WriteReg(BBAD1, 0x19u);
      WriteRegWord(A1T1L, *(uint16 *)&R0_ + v7 + 1);
      WriteRegWord(VMADDL, *(uint16 *)&R3_);
      WriteRegWord(DAS1L, v8);
      v6 = 2;
    }
    *(uint16 *)&R3_ = v6;
    v0 = v6 + v7;
    WriteReg(VMAIN, R7_ | 0x80);
    WriteReg(MDMAEN, 2u);
  }
}

void Smbll_PrintStatusBarNumbers(uint8 a) {
  R0_ = a;
  Smbll_OutputNumbers(a);
  Smbll_OutputNumbers(R0_ >> 4);
}

void Smbll_OutputNumbers(uint8 a) {
  uint8 v1;  // al
  uint8 v2;  // di
  uint8 v3;  // si
  uint8 v4;  // di
  uint8 v5;  // si

  v1 = (a + 1) & 0xF;
  if (v1 < 6u) {
    v2 = 4 * v1;
    if (4 * v1) {
      tempF9 = 32;
      v3 = vram_buffer1[0];
      vram_buffer1[vram_buffer1[0] + 2] = 88;
      vram_buffer1[v3 + 3] = kStatusBarData[v2];
      vram_buffer1[v3 + 4] = kStatusBarData[v2 + 1];
      R3_ = kStatusBarData[v2 + 2];
      vram_buffer1[v3 + 5] = 2 * R3_ - 1;
      R2_ = v3;
      v4 = kStatusBarOffset[v1] - kStatusBarData[v2 + 2];
      v5 = R2_;
      do {
        vram_buffer1[v5 + 6] = displayed_score[v4];
        vram_buffer1[v5 + 7] = tempF9;
        v5 += 2;
        ++v4;
        --R3_;
      } while (R3_);
      vram_buffer1[v5 + 6] = -1;
      vram_buffer1[0] = v5 + 4;
    }
  }
}

void Smbll_DigitsMathRoutine(uint8 j) {
  uint8 i;  // si
  int8 v2;  // al
  int8 k;   // si
  bool v4;  // zf

  if (game_mode) {
    for (i = 5; (i & 0x80u) == 0; --i) {
      v2 = displayed_score[j] + digit_modifier[i];
      if (v2 < 0) {
        v4 = (*(&g_byte_7E0144 + i))-- == 1;
        v2 = 9;
        if (v4) {
LABEL_10:
          if (!i) {
            i = 5;
            do
              marios_score[i--] = 9;
            while (i);
            v2 = 19;
          }
          v2 -= 10;
          ++*(&g_byte_7E0144 + i);
        }
      } else if ((uint8)v2 >= 0xAu) {
        goto LABEL_10;
      }
      displayed_score[j--] = v2;
    }
  }
  for (k = 6; k >= 0; --k)
    *(&g_byte_7E0144 + (uint8)k) = 0;
}

void Smbll_DoSomeDigitsStuff() {
  uint8 v0;  // si
  int8 v1;   // di
  bool v2;   // cf
  uint8 v3;  // si
  uint8 v4;  // di

  v0 = 5;
  v1 = 5;
  v2 = 1;
  do
    v2 = marios_score[v0--] >= (uint8)(!v2 + displayed_score[(uint8)v1--]);
  while (v1 >= 0);
  if (v2) {
    v3 = v0 + 1;
    v4 = v1 + 1;
    do
      displayed_score[v4++] = marios_score[v3++];
    while (v4 < 6u);
  }
}

void Smbll_RunGameOver_() {
  uint8 v0;  // di
  int8 i;    // di

  if ((controller_press1p1 & 0xC) != 0) {
    sound_ch3 = 1;
    if ((controller_press1p1 & 8) != 0) {
      v0 = game_over_screen_blinking_cursor_pos - 1;
      if ((int8)(game_over_screen_blinking_cursor_pos - 1) < 0) {
        v0 = game_over_screen_blinking_cursor_pos;
LABEL_7:
        sound_ch3 = 0;
      }
    } else {
      v0 = game_over_screen_blinking_cursor_pos + 1;
      if (game_over_screen_blinking_cursor_pos == 2) {
        v0 = 2;
        goto LABEL_7;
      }
    }
    game_over_screen_blinking_cursor_pos = v0;
  }
  if (!pausemenu_var2) {
    if ((controller_press1p1 & 0x10) == 0) {
      if ((controller_press1p1 & 0x20) != 0) {
        sound_ch3 = 1;
        if (++game_over_screen_blinking_cursor_pos == 3)
          game_over_screen_blinking_cursor_pos = 0;
      }
      Smbll_RunGameOver_Sub();
      return;
    }
    pausemenu_var2 = 32;
    sound_ch1 = 67;
    music_ch1 = -13;
    if (game_over_screen_blinking_cursor_pos)
      sound_ch1 = 59;
  }
  Smbll_CODE_03A142();
  if (!--pausemenu_var2) {
    blinking_cursor_frame_counter = 0;
    number_of_lives = 4;
    player_coin_count = 0;
    for (i = 17; i >= 0; --i)
      marios_score[(uint8)i] = 0;
    ++hidden_1up_flag;
    if (!game_over_screen_blinking_cursor_pos || (Smbll_SaveGame_Main(), game_over_screen_blinking_cursor_pos == 1))
      Smbll_ContinueGame();
    else
      Smbll_ResetGame_Main();
  }
}

void Smbll_RunGameOver_Sub() {
  if (sound_ch3)
    blinking_cursor_frame_counter = 0;
  Smbll_CODE_03A142();
}

void Smbll_CODE_03A142() {
  uint8 i;  // di

  oam_tile_size_buffer[0] = ((uint8)(++blinking_cursor_frame_counter & 0x10) >> 4) | 2;
  for (i = 3; (i & 0x80u) == 0; --i)
    get_OamEnt(oam_buf, i)->xpos = kDATA_03A0C8[i];
  get_OamEnt(oam_buf, 0)->ypos = kDATA_03A0CC[game_over_screen_blinking_cursor_pos];
}

void Smbll_sub_9AF8() {
  bool v0;  // cf

  if (cutscene_toad_text_timer) {
LABEL_6:
    v0 = __CFADD__(cutscene_toad_text_timer, 4);
    cutscene_toad_text_timer += 4;
    cutscene_toad_line_to_display += v0;
    return;
  }
  if (cutscene_toad_line_to_display < 0xAu) {
    if (cutscene_toad_line_to_display == 2)
      area_data_ptr.bank = 4;
    vram_buffer_addr_ctrl = cutscene_toad_line_to_display + 15;
    goto LABEL_6;
  }
  event_music_buffer = 12;
  ++game_mode_task;
  Smbll_sub_9B31();
}

void Smbll_sub_9B31() {
  smbll_varF27 = 0;
  smbll_varF28 = 0;
  smbll_varF29 = 0;
}

void Smbll_sub_9B3D() {
  if (!event_music_buffer) {
    if ((number_of_lives & 0x80u) != 0) {
      smbll_varF2D = 5;
      smbll_varF2C = 0;
      smbll_varF2E = 0;
      smbll_varF2F = 0;
      ++game_mode_task;
      Smbll_sub_9B31();
    } else if (!all_timers) {
      all_timers = 48;
      sound_ch3 = 1;
      --number_of_lives;
      digit_modifier[1] = 1;
      Smbll_EndAreaPoints();
    }
  }
}

void Smbll_sub_9B73() {
  ++game_mode_task;
  Smbll_sub_9B31();
  smbll_varF2A = 96;
}

void Smbll_sub_9BDD() {
  uint8 v0;  // si
  uint8 v1;  // [rsp+0h] [rbp-4Ah]
  uint8 v2;  // [rsp+1h] [rbp-49h]

  smbll_varF09 = 0;
  game_mode_task = 0;
  if (world_number == 12)
    goto LABEL_4;
  if (smbll_varF2B) {
    smbll_varF08 = 0;
    number_of_lives = 0;
    ++world_number;
    Unreachable();
LABEL_4:
    smbll_varF08 = 0;
    game_mode = 0;
    Smbll_GameMode00_TitleScreen();
    return;
  }
  smbll_varF08 = 0;
  number_of_lives = 0;
  smbll_varF07 = 0;
  Unreachable();
  if (smbll_varF2A) {
    --smbll_varF2A;
  } else {
    Unreachable();
    if (smbll_varF28 == 7) {
      if ((smbll_varF27 & 0x1F) == 0 && ++smbll_varF29 >= 0xBu)
        smbll_varF29 = 4;
    } else if ((smbll_varF27 & 0x1F) == 0) {
      ++smbll_varF28;
      sound_ch3 = 1;
    }
    ++smbll_varF27;
    v2 = world_number;
    v1 = smbll_varF28;
    v0 = smbll_varF28;
    do {
      if (smbll_varF29 < 4u || kbyte_9C18[(uint8)(smbll_varF29 - ((smbll_varF29 < 4u) + 4))] != kbyte_9C1E[v0]) {
        enemy_obj_id[0] = kbyte_9C1E[v0];
        enemy_id[0] = 53;
        obj_ypos_lo.enemy[0] = kbyte_9C25[v0];
        rel_xpos_lo.enemy = kbyte_9C2C[v0];
        world_number = 0;
        object_index = 0;
        Smbll_EnemyGfxHandler_New(0);
        --level_preview_sprites_ctr;
      }
      v0 = --smbll_varF28;
    } while (smbll_varF28);
    ++level_preview_sprites_ctr;
    smbll_varF28 = v1;
    world_number = v2;
    enemy_obj_id[0] = 48;
    obj_ypos_lo.enemy[0] = -72;
  }
}

void Smbll_TitleScreen_0_InitializeGame() {
  uint8 v0;  // di
  uint8 v1;  // si

  inidisp_mirror = 0x80;
  palette_mirror[129] = 0x7FFF;
  ++update_entire_palette_flag;
  vram_buffer1[2] = -1;
  vram_buffer1[3] = -1;
  bgmode_mirror = 9;
  tm_mirror = 16;
  cgadsub_mirror = 32;
  coldata1_mirror = 32;
  coldata2_mirror = 64;
  coldata3_mirror = 0x80;
  v0 = -2;
  v1 = 5;
  while (displayed_score[v1] < 0xAu) {
    if ((--v1 & 0x80u) != 0) {
      if (title_screen_var07FF == 0xA5)
        v0 = -57;
      break;
    }
  }
  Smbll_CODE_039F3E(v0);
  title_screen_var07FF = -91;
  random_byte1 = -91;
  g_byte_7E0EF6 = 0;
  vblank_upload_from_7f0000_flag = 0;
  g_word_7E0EF7 = 0;
  Smbll_CODE_039F3E(0x6Fu);
  demo_timer = 24;
  Smbll_LoadAreaPointer();
  Smbll_GameMode01_Level_InitializeArea();
  fade_direction = 0;
}

void Smbll_GameMode01_Level_InitializeArea() {
  int8 i;    // si
  uint8 v2;  // al
  int16 v3;  // ax
  uint8 v4;  // t0
  uint8 v5;  // di
  int8 v6;   // al

  if (world_number >= 0xDu)
    Smbll_LoadAreaPointer();
  Smbll_CODE_039F3E(0x4Bu);
  for (i = 41; i >= 0; --i)
    *(&all_timers + (uint8)i) = 0;
  v2 = halfway_page;
  if (alt_entrance_ctrl)
    v2 = entrance_page;
  screen_left_xpos_hi = v2;
  column_pos_hi = v2;
  backloading_flag = v2;
  v4 = v2;
  LOBYTE(v3) = 0;
  HIBYTE(v3) = v4;
  screen_left_xpos16 = v3 & 0xFF00;
  layer2_xpos = (uint16)(v3 & 0xFF00) >> 1;
  layer3_xpos = (uint16)(v3 & 0xFF00) >> 2;
  v5 = 0;
  v6 = Smbll_GetScreenPosition() & 1;
  if (v6)
    v5 = 4;
  render_graphics_var0720 = v5;
  block_buffer_column_pos = 16 * v6;
  area_object_length[0] = -1;
  area_object_length[1] = -1;
  area_object_length[2] = -1;
  area_object_length[3] = -1;
  area_object_length[4] = -1;
  column_sets = 11;
  Smbll_GetAreaDataAddrs();
  if (title_screen_hard_mode_flag || world_number >= 3u && (world_number != 3 || level_number >= 3u))
    ++secondary_hard_mode;
  if (halfway_page)
    player_entrance_ctrl = 2;
  if (area_data_addr_index != 7 && area_data_addr_index != 65)
    music_ch1 = 0x80;
  fade_direction = 1;
  ++game_mode_task;
}

void Smbll_TitleScreen_2_PrimaryGameSetup() {
  if (ReadReg(APUI02) != 21) {
    Smbll_CheckWhichControllersArePluggedIn_Main();
    WriteReg(APUI02, 0x15u);
    apui02_var160C = 4;
  }
  fetch_new_game_timer_flag = 1;
  player_size = 1;
  level_free_movement_debug_flag = 0;
  Smbll_GameMode01_Level_SecondaryGameSetup();
}

void Smbll_GameMode01_Level_SecondaryGameSetup() {
  uint8 v0;  // di
  uint8 i;   // si

  fade_direction = 2;
  sound_ch2 |= 0x20u;
  inidisp_mirror = 0;
  disable_screen_flag = 0;
  smbll_varF04 = 0;
  smbll_varF02 = 0;
  v0 = 0;
  do
    bridge_sprite_slot_exists_flag[v0++] = 0;
  while (v0);
  game_timer_expired_flag = 0;
  screen_routines_flag0769 = 0;
  backloading_flag = 0;
  bal_platform_alignment = -1;
  vram_buffer1[2] = -1;
  smbll_varF05 = screen_left_xpos_hi & 1;
  unused_byte_7E0B43 = 56;
  unused_byte_7E0B42 = 72;
  unused_byte_7E0B41 = 88;
  for (i = 28; (i & 0x80u) == 0; --i)
    *(&spr_data_offset + i) = kDefaultSprOffsets[i];
  Smbll_CODE_03A28F();
  ++sprite0_hit_detect_flag;
  ++game_mode_task;
}

void Smbll_Entrance_GameTimerSetup() {
  uint8 v0;  // di
  uint8 v1;  // si
  uint8 v2;  // si

  obj_xpos_hi.player = screen_left_xpos_hi;
  vertical_force_down = 40;
  player_facing_dir = 1;
  obj_ypos_hi.player = 1;
  player_state = 0;
  --player_collision_bits;
  v0 = 0;
  halfway_page = 0;
  if (!area_type)
    v0 = 1;
  swimming_flag = v0;
  v1 = player_entrance_ctrl;
  if (alt_entrance_ctrl >= 2u)
    v1 = kAltYPosOffset[alt_entrance_ctrl - 2];
  obj_xpos_lo.player = kPlayerStarting_X_Pos[alt_entrance_ctrl];
  obj_ypos_lo.player = kPlayerStarting_Y_Pos[v1];
  player_sprattrib = kPlayerBgPriorityData[v1];
  v2 = 0;
  Smbll_BoundingBoxCore(0, alt_entrance_ctrl);
  Smbll_GetPlayerColors();
  if (game_timer_setting && fetch_new_game_timer_flag) {
    level_timer_hundreds = kGameTimerData[game_timer_setting];
    level_timer_ones = 1;
    level_timer_tens = 0;
    fetch_new_game_timer_flag = 0;
    player_star_power_timer = 0;
  }
  if (vine_screen_exit_flag) {
    player_state = 3;
    Smbll_InitBlock_XY_Pos(0);
    unused_block_y_pos[0] = -16;
    v2 = 9;
    Smbll_Spr02F_Vine_Init(9u, 0);
  }
  if (!area_type)
    Smbll_SetupBubble(v2);
  game_engine_subroutine = 7;
}

void Smbll_PlayerLoseLife() {
  uint8 v0;  // si
  uint8 v1;  // al
  uint8 v2;  // al

  fade_direction = 1;
  var0E67 = 1;
  sprite0_hit_detect_flag = 0;
  if ((--number_of_lives & 0x80u) == 0) {
    v0 = 2 * world_number;
    if ((level_number & 2) != 0)
      ++v0;
    v1 = kHalfwayPageNibbles[v0];
    if (!(level_number & 1))
      v1 >>= 4;
    v2 = v1 & 0xF;
    if (v2 != screen_left_xpos_hi && v2 >= screen_left_xpos_hi)
      v2 = 0;
    halfway_page = v2;
    Smbll_TransposePlayers();
    Smbll_ContinueGame();
  } else {
    game_mode_task = 0;
    game_mode = 3;
  }
}

void Smbll_GameMode03_GameOverScreen() {
  int8 v0;  // si

  v0 = 2 * game_mode_task;
  if (2 * game_mode_task == 2) {
    Smbll_ScreenRoutines();
  } else if (v0) {
    if (v0 != 4) {
      Unreachable();
      while (1)
        ;
    }
    Smbll_RunGameOver();
  } else {
    Smbll_SetupGameOver();
  }
}

void Smbll_SetupGameOver() {
  screen_routine_task = 0;
  sprite0_hit_detect_flag = 0;
  game_over_screen_blinking_cursor_pos = 0;
  blinking_cursor_frame_counter = 0;
  music_ch1 = 10;
  ++disable_screen_flag;
  ++game_mode_task;
}

void Smbll_RunGameOver() {
  Smbll_RunGameOver_();
}

void Smbll_CODE_03A1EF() {
  if (Smbll_TransposePlayers() & 1) {
    continue_world = world_number;
    game_mode_task = 0;
    screen_timer = 0;
    game_mode = 0;
  } else {
    Smbll_ContinueGame();
  }
}

void Smbll_ContinueGame() {
  Smbll_LoadAreaPointer();
  player_size = 1;
  ++fetch_new_game_timer_flag;
  timer_control = 0;
  player_status = 0;
  game_engine_subroutine = 0;
  game_mode_task = 0;
  game_mode = 1;
}

uint8 Smbll_TransposePlayers() {
  uint8 i;   // si
  uint8 v2;  // [rsp+47h] [rbp-1h]
  bool flag = true;
  if (number_of_players && (other_player_num_lives & 0x80u) == 0) {
    current_player ^= 1u;
    for (i = 6; (i & 0x80u) == 0; --i) {
      v2 = *(&number_of_lives + i);
      *(&number_of_lives + i) = *(&other_player_num_lives + i);
      *(&other_player_num_lives + i) = v2;
    }
    flag = false;
  }
  return flag;
}

void Smbll_CODE_03A28F() {
  unused_06C9 = -1;
}

void Smbll_AreaParserTaskHandler() {
  uint8 v0;  // di

  v0 = area_parser_task_num;
  if (!area_parser_task_num) {
    v0 = 8;
    area_parser_task_num = 8;
  }
  Smbll_AreaParserTasks(v0 - 1);
  if (!--area_parser_task_num) {
    R0_ = 32;
    if (obj_yspeed.bubble[0] == 3)
      R0_ *= 2;
    if (!vblank_which_layer2_scroll_flag) {
      if ((R0_ & (uint8)layer2_xpos) != 0) {
        if (area_parser_flag0EFC)
          goto LABEL_14;
        area_parser_flag0EFC = 1;
      } else {
        if (!area_parser_flag0EFC)
          goto LABEL_14;
        area_parser_flag0EFC = 0;
      }
      Smbll_CODE_049B35();
      Smbll_nullsub_1();
    }
  }
LABEL_14:
  if ((layer3_xpos & 0x10) == 0) {
    if (!area_parser_varEDD)
      return;
    area_parser_varEDD = 0;
    goto LABEL_20;
  }
  if (!area_parser_varEDD) {
    area_parser_varEDD = 1;
LABEL_20:
    Smbll_SMB3_BufferLayer3Tilemap();
  }
}

void Smbll_AreaParserTasks(uint8 a) {
  int8 v1;    // si
  int8 i;     // si
  int8 v3;    // al
  uint8 v4;   // al
  uint8 v5;   // si
  uint8 v6;   // di
  uint8 v7;   // di
  uint8 v8;   // si
  uint8 v9;   // al
  uint8 v10;  // al
  uint8 v11;  // si
  uint8 v12;  // di
  uint8 v13;  // di
  uint8 v14;  // al
  uint8 v15;  // al
  int16 v16;  // ax
  uint8 v17;  // si
  uint8 v18;  // di
  bool v19;   // cf
  int16 v20;  // cx
  int16 v21;  // ax
  uint8 v22;  // di
  uint8 v23;  // di

  v1 = 2 * a;
  if (2 * a == 2 || v1 == 4 || v1 == 10 || v1 == 12) {
    Smbll_RenderAreaGraphics();
    return;
  }
  if (!v1 || v1 == 8) {
    if ((++current_column_pos_lo & 0xF) == 0) {
      current_column_pos_lo = 0;
      ++column_pos_hi;
    }
    ++block_buffer_column_pos;
    block_buffer_column_pos &= 0x1Fu;
  } else {
    if (v1 != 6 && v1 != 14) {
      Unreachable();
      while (1)
        ;
    }
    if (backloading_flag)
      Smbll_ProcessAreaData();
    for (i = 12; i >= 0; --i)
      metatile_buffer[(uint8)i] = 0;
    if (background_scenery) {
      v3 = column_pos_hi;
      do {
        if (sign8(v3 - 3))
          break;
        v3 -= 3;
      } while (v3 >= 0);
      v4 = kBackSceneryData[(uint8)(current_column_pos_lo + kBSceneDataOffsets[background_scenery - 1] + 16 * v3)];
      if (v4) {
        R0_ = (v4 & 0xF) - 1;
        v5 = 3 * R0_;
        v6 = v4 >> 4;
        R0_ = 3;
        do {
          metatile_buffer[v6] = kBackSceneryMetatiles[v5++];
          if (++v6 == 11)
            break;
          --R0_;
        } while (R0_);
      }
    }
    if (foreground_scenery) {
      v7 = kbyte_A10A[foreground_scenery];
      v8 = 0;
      while (1) {
        v9 = kForeSceneryData[v7];
        if (v9)
          break;
LABEL_40:
        ++v7;
        if (++v8 == 13)
          goto LABEL_41;
      }
      if (!area_type) {
        if (area_data_addr_index != 69) {
          if (!area_parser_ctr1) {
            ++area_parser_ctr1;
            ++v9;
LABEL_38:
            v9 += 2;
            goto LABEL_39;
          }
          area_parser_ctr1 = 0;
        }
LABEL_39:
        metatile_buffer[v8] = v9;
        goto LABEL_40;
      }
      if (area_type != 3 || v9 != 0x86)
        goto LABEL_39;
      goto LABEL_38;
    }
LABEL_41:
    area_parser_var2 = 0;
    tempF9 = 0;
    area_parser_var4 = area_parser_var3++;
    if (area_type || area_data_addr_index != 65) {
      v10 = kTerrainMetatiles[area_type];
      if (cloud_type_override)
        v10 = -122;
    } else {
      v10 = 99;
    }
    R7_ = v10;
    v11 = 0;
    v12 = 2 * terrain_control;
LABEL_47:
    R0_ = kTerrainRenderBits[v12];
    R1_ = v12 + 1;
    if (cloud_type_override && v11)
      R0_ &= 8u;
    v13 = 0;
    while (1) {
      if ((R0_ & kBitmasks[v13]) != 0) {
        if (area_data_addr_index != 9 && obj_yspeed.bubble[0] == 3 && tempF9) {
          v14 = 102;
          R7_ = 102;
        } else {
          v14 = R7_;
        }
        metatile_buffer[v11] = v14;
        if (tempF9 && obj_yspeed.bubble[0] == 3) {
          v15 = tempF9++;
          if (v15 == 0xFF) {
            ++metatile_buffer[v11];
            ++R7_;
          }
        } else if (obj_yspeed.bubble[0] == 3 && !cloud_type_override && !area_parser_var2 && (area_parser_var4 & 1) == 0) {
          ++metatile_buffer[v11];
        }
      } else {
        tempF9 = -2;
        ++area_parser_var2;
      }
      if (++v11 == 13)
        break;
      if (area_type == 2 && v11 == 11)
        R7_ = 78;
      ++area_parser_var4;
      if (++v13 == 8) {
        v12 = R1_;
        if (R1_)
          goto LABEL_47;
        break;
      }
    }
    if (metatile_buffer[12] == 78 || metatile_buffer[12] == 113)
      ++metatile_buffer[12];
    Smbll_ProcessAreaData();
    Smbll_GetBlockBufferAddr(block_buffer_column_pos);
    if (metatile_buffer[11] == 112)
      metatile_buffer[12] = metatile_buffer[11];
    v17 = 0;
    v18 = 0;
    do {
      R0_ = v18;
      if (render_graphics_var0EC9)
        break;
      v16 = metatile_buffer[v17] & 0xC0;
      v19 = __CFSHL__(v16, 1);
      LOBYTE(v16) = 2 * v16;
      v20 = v19;
      v19 = __CFSHL__(v16, 1);
      LOBYTE(v16) = 2 * v16;
      v21 = v16 + v20;
      LOBYTE(v21) = 2 * v21;
      v16 = v21 + v19;
      v22 = v16;
      LOBYTE(v16) = metatile_buffer[v17];
      if ((uint8)v16 < kBlockBuffLowBounds[v22])
        LOBYTE(v16) = 0;
      v23 = R0_;
      RomPtr_RAM(*(uint16 *)&R6_)[R0_] = v16;
      v18 = v23 + 16;
      ++v17;
    } while (v17 < 0xDu);
  }
}
// 442D: variable 'v16' is possibly undefined

void Smbll_ProcessAreaData() {
  int16 i;    // si
  uint16 v1;  // di
  uint8 v2;   // al
  int8 v3;    // al
  uint8 *v4;  // rdx
  int16 v5;   // si

  do {
    for (i = 4; i >= 0; i = v5 - 1) {
      level_3_byte_object_flag = 0;
      *(uint16 *)&object_index = i;
      behind_area_parser_flag = 0;
      v1 = area_data_offset;
      v2 = *IndirPtr(&area_data_ptr, area_data_offset);
      if (v2 == 0xFD)
        goto LABEL_20;
      if ((v2 & 0xF) == 15)
        ++level_3_byte_object_flag;
      if ((area_object_length[(uint16)i] & 0x80u) == 0) {
LABEL_20:
        Smbll_DecodeAreaData(i, v1);
        goto LABEL_23;
      }
      if (level_3_byte_object_flag)
        ++v1;
      if (__CFSHL__(*IndirPtr(&area_data_ptr, v1 + 1), 1) && !area_object_page_sel) {
        ++area_object_page_sel;
        ++area_object_page_loc;
      }
      v1 = area_data_offset;
      v3 = *IndirPtr(&area_data_ptr, area_data_offset) & 0xF;
      if (v3 == 13) {
        v4 = IndirPtr(&area_data_ptr, v1 + 1);
        v1 = area_data_offset;
        if ((*v4 & 0x40) == 0 && !area_object_page_sel) {
          if (level_3_byte_object_flag)
            v1 = area_data_offset + 1;
          area_object_page_loc = *IndirPtr(&area_data_ptr, v1 + 1) & 0x1F;
          ++area_object_page_sel;
          goto LABEL_22;
        }
      } else if (v3 == 14 && backloading_flag) {
        goto LABEL_20;
      }
      if (area_object_page_loc >= column_pos_hi)
        goto LABEL_20;
      ++behind_area_parser_flag;
LABEL_22:
      Smbll_IncAreaObjOffset();
LABEL_23:
      v5 = *(uint16 *)&object_index;
      if ((area_object_length[*(uint16 *)&object_index] & 0x80u) == 0)
        --area_object_length[*(uint16 *)&object_index];
    }
  } while (behind_area_parser_flag || backloading_flag);
}

void Smbll_IncAreaObjOffset() {
  ++area_data_offset;
  ++area_data_offset;
  if (level_3_byte_object_flag)
    ++area_data_offset;
  area_object_page_sel = 0;
  level_3_byte_object_flag = 0;
}

void Smbll_DecodeAreaData(uint8 k, uint16 j) {
  int16 v2;    // di
  int16 v3;    // si
  uint8 *v4;   // rdx
  uint8 v5;    // al
  uint16 v6;   // si
  uint8 v7;    // al
  uint16 v8;   // di
  int8 v9;     // al
  uint16 v10;  // di
  uint8 *v11;  // rdx
  int8 v12;    // al
  uint8 v13;   // al
  uint8 v14;   // di

  v2 = j;
  if ((area_object_length[k] & 0x80u) == 0)
    *(uint16 *)&j = area_obj_offset_buffer[(uint16)(2 * k) >> 1];
  if (cutscene_peach_var0F82) {
    Smbll_DecodeAreaData_Sub_New();
    cutscene_peach_var0F82 = 0;
    return;
  }
  *(uint16 *)&tempF7 = j;
  tempF6 = 0;
  level_3_byte_object_flag = 0;
  v3 = 16;
  v4 = IndirPtr(&area_data_ptr, j);
  if (*v4 == 0xFD)
    return;
  v5 = *v4 & 0xF;
  if (v5 == 15) {
    ++tempF6;
  } else {
    v3 = 8;
    if (v5 != 12)
      v3 = 0;
  }
  *(uint16 *)&R7_ = v3;
  v6 = *(uint16 *)&object_index;
  if (v5 != 14) {
    if (v5 == 13) {
      R7_ = 40;
      if (tempF6)
        *(uint16 *)&j = j + 1;
      v8 = j + 1;
      if ((*IndirPtr(&area_data_ptr, v8) & 0x40) == 0)
        return;
      v9 = *IndirPtr(&area_data_ptr, v8) & 0x7F;
      if (v9 == 75)
        ++loop_command;
      v7 = v9 & 0x3F;
      goto LABEL_32;
    }
    if (v5 >= 0xCu) {
      if (tempF6)
        *(uint16 *)&j = j + 1;
      v13 = *IndirPtr(&area_data_ptr, j + 1) & 0x70;
    } else {
      if (tempF6)
        *(uint16 *)&j = j + 1;
      v10 = j + 1;
      v11 = IndirPtr(&area_data_ptr, v10);
      v12 = *v11 & 0x70;
      if (!v12) {
        R7_ = 24;
        v7 = *IndirPtr(&area_data_ptr, v10) & 0xF;
        goto LABEL_32;
      }
      R0_ = *v11 & 0x70;
      if (v12 == 112 && (*IndirPtr(&area_data_ptr, v10) & 8) != 0)
        R0_ = 0;
      v13 = R0_;
    }
    v7 = v13 >> 4;
    goto LABEL_32;
  }
  R7_ = 0;
  v7 = 54;
LABEL_32:
  R0_ = v7;
  if ((area_object_length[v6] & 0x80u) == 0) {
LABEL_43:
    if (tempF6) {
      Smbll_DecodeAreaData_Sub2_New(*(uint16 *)&tempF7);
    } else {
      v14 = R7_ + R0_;
      R4_ = koff_A507[v14];
      R5_ = HIBYTE(koff_A507[v14]);
      funcs_4A7C[(unsigned int)(v14 * 2) >> 1](v6);
    }
    return;
  }
  if (area_object_page_loc != column_pos_hi) {
    if ((*IndirPtr(&area_data_ptr, area_data_offset) & 0xF) != 14 || !backloading_flag)
      return;
    goto LABEL_40;
  }
  if (backloading_flag) {
    backloading_flag = 0;
    behind_area_parser_flag = 0;
    object_index = 0;
    object_index_upper_empty = 0;
    return;
  }
  if ((uint8)(*IndirPtr(&area_data_ptr, area_data_offset) & 0xF0) >> 4 == current_column_pos_lo) {
LABEL_40:
    area_obj_offset_buffer[(uint16)(2 * v6) >> 1] = area_data_offset;
    if (tempF6)
      ++level_3_byte_object_flag;
    Smbll_IncAreaObjOffset();
    goto LABEL_43;
  }
}
// 46C7: variables would overlap: di.1 and di.2
// 4A84: using guessed type int (*funcs_4A7C[55])();

void Smbll_ExtObj33(uint8 k) {
}

void Smbll_ExtObj34(uint8 k) {
  Smbll_ExtObj34_();
}

void Smbll_ExtObj35(uint8 k) {
  Smbll_ExtObj35_();
}

void Smbll_nullsub_6(uint8 k) {
  ;
}

void Smbll_ExtObj2E_AlterAreaAttributes(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // [rsp+47h] [rbp-1h]

  v2 = *IndirPtr(&area_data_ptr, area_obj_offset_buffer[(uint16)(2 * k) >> 1] + 1);
  if ((v2 & 0x40) != 0) {
    v1 = v2 & 7;
    if ((v2 & 7u) >= 4) {
      background_color_ctrl = v2 & 7;
      v1 = 0;
    }
    foreground_scenery = v1;
  } else {
    terrain_control = v2 & 0xF;
    background_scenery = (uint8)(v2 & 0x30) >> 4;
  }
}

void Smbll_ExtObj27_ScrollLockObject_Warp(uint8 k) {
  uint8 v1;  // si
  uint8 v2;  // al

  v1 = 0x80;
  if (!title_screen_hard_mode_flag) {
    if (!world_number) {
      if (area_type == 1) {
LABEL_6:
        ++v1;
        goto LABEL_17;
      }
      if (area_addrs_l_offset) {
        v1 = -127;
        goto LABEL_6;
      }
LABEL_17:
      v2 = v1;
      goto LABEL_18;
    }
LABEL_9:
    v1 = -125;
    if (world_number == 2)
      goto LABEL_17;
    v1 = -124;
    if (world_number == 4) {
      if (area_addrs_l_offset == 11)
        goto LABEL_17;
      if (area_type != 1) {
LABEL_16:
        ++v1;
        goto LABEL_17;
      }
    } else {
      v1 = -123;
    }
    ++v1;
    goto LABEL_16;
  }
  v2 = level_number - 121;
  if (level_number == 121)
    goto LABEL_9;
LABEL_18:
  warp_zone_control = v2;
  Smbll_sub_8F46(v2);
  Smbll_KillEnemies(0xDu);
  Smbll_ExtObj28_ScrollLockObject(v1);
}

void Smbll_ExtObj28_ScrollLockObject(uint8 k) {
  scroll_lock ^= 1u;
}

void Smbll_KillEnemies(uint8 a) {
  uint8 i;  // si

  R0_ = a;
  for (i = 8; (i & 0x80u) == 0; --i) {
    if (enemy_id[i] == R0_)
      enemy_flag[i] = 0;
  }
}

void Smbll_ExtObj2C_AreaFrenzy(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di

  v1 = kFrenzyIdData[R0_ - 8];
  v2 = 9;
  while ((--v2 & 0x80u) == 0) {
    if (v1 == enemy_id[v2]) {
      v1 = 0;
      break;
    }
  }
  enemy_frenzy_queue = v1;
}

void Smbll_ExtObj01_GrassyOrMushroomPlatform(uint8 k) {
  uint8 LrgObjAttrib;  // di
  int8 v2;             // al
  uint8 v3;            // al
  uint8 v4;            // si
  uint8 v5;            // di
  uint8 v6;            // al
  uint8 v7;            // di
  uint8 v8;            // si
  uint8 v9;            // si
  int8 v10;            // di
  uint8 v11;           // si
  int8 v12;            // di
  uint8 v13;           // si
  uint8 v14;           // si

  R4_ = *((uint8 *)koff_A64A + (uint8)(2 * area_style));
  R5_ = *((uint8 *)koff_A64A + (uint8)(2 * area_style) + 1);
  switch ((uint8)(2 * area_style) >> 1) {
  case 0:
    LrgObjAttrib = Smbll_GetLrgObjAttrib(k);
    tree_ledge_saved_x = k;
    v2 = area_object_length[k];
    if (!v2) {
      v3 = 32;
      goto LABEL_19;
    }
    if (v2 < 0) {
      area_object_length[k] = LrgObjAttrib;
      v2 = current_column_pos_lo | column_pos_hi;
      if (__PAIR16__(current_column_pos_lo, column_pos_hi)) {
        v3 = 30;
        goto LABEL_19;
      }
    }
    tree_ledge_countdown = v2;
    v4 = R7_;
    metatile_buffer[R7_] = 31;
    v5 = v4 + 1;
    if (--tree_ledge_countdown) {
      if (tree_ledge_arr130F[tree_ledge_saved_x]) {
        metatile_buffer[v5] = 15;
        v6 = 19;
      } else {
        ++tree_ledge_arr130F[tree_ledge_saved_x];
        metatile_buffer[v5] = 14;
        v6 = 18;
      }
    } else if (tree_ledge_arr130F[tree_ledge_saved_x]) {
      tree_ledge_arr130F[tree_ledge_saved_x] = 0;
      metatile_buffer[v5] = 16;
      v6 = 20;
    } else {
      tree_ledge_arr130F[tree_ledge_saved_x] = 0;
      metatile_buffer[v5] = 17;
      v6 = 21;
    }
    Smbll_RenderUnderPart(v4 + 2, 0xFu, v6);
    break;
  case 1:;
    uint16 t = Smbll_ChkLrgObjLength(k);
    R6_ = t;
    if (t & 0x100) {
      mushroom_ledge_half_len[k] = area_object_length[k] >> 1;
      v3 = 33;
    } else {
      v3 = 35;
      if (area_object_length[k]) {
        R6_ = mushroom_ledge_half_len[k];
        metatile_buffer[R7_] = 34;
        return;
      }
    }
LABEL_19:
    Smbll_RenderUnderPart(R7_, 0, v3);
    break;
  case 2:
    v7 = Smbll_GetLrgObjAttrib(k);
    v8 = R7_;
    metatile_buffer[R7_] = 107;
    v9 = v8 + 1;
    v10 = v7 - 1;
    if (v10 >= 0) {
      metatile_buffer[v9] = 108;
      v11 = v9 + 1;
      v12 = v10 - 1;
      if (v12 >= 0)
        Smbll_RenderUnderPart(v11, v12, 0x6Du);
    }
    v13 = cannon_offset;
    cannon_ypos_lo[v13] = Smbll_GetAreaObjYPosition();
    cannon_xpos_hi[v13] = column_pos_hi;
    cannon_xpos_lo[v13] = Smbll_GetAreaObjXPosition();
    v14 = v13 + 1;
    if (v14 >= 6u)
      v14 = 0;
    cannon_offset = v14;
    break;
  }
}

void Smbll_ExtObj09_PulleyRope_(uint8 k) {
  Smbll_ExtObj09_PulleyRope(k);
}

void Smbll_ExtObj1F_WaterPipe(uint8 k) {
  int v1;  // edx

  Smbll_GetLrgObjAttrib(k);
  v1 = R7_;
  metatile_buffer[R7_] = 118;
  metatile_buffer[v1 + 1] = 119;
}

void Smbll_ExtObj22_IntroPipe(uint8 k) {
  uint8 v1;  // si
  uint8 v2;  // di
  int8 i;    // si

  Smbll_ChkLrgObjFixedLength(k, 3u);
  R5_ = 8;
  R6_ = area_object_length[k];
  v1 = 9;
  bool flag = false;
  if (kDATA_03A9E3[R6_]) {
    v1 = Smbll_RenderUnderPart(0, R5_, kDATA_03A9E3[R6_]);
    flag = true;
  }
  v2 = R6_;
  metatile_buffer[v1] = kDATA_03A9E7[R6_];
  metatile_buffer[v1 + 1] = kDATA_03A9EB[v2];
  if (flag) {
    for (i = 6; i >= 0; --i)
      metatile_buffer[(uint8)i] = 0;
    metatile_buffer[7] = kDATA_03A9EF[v2];
  }
}

void Smbll_ExtObj07_VerticalPipe(uint8 k) {
  uint8 v1;                // di
  uint8 slot;              // si
  uint8 AreaObjXPosition;  // al
  uint8 v4;                // si

  v1 = Smbll_CODE_03AA4D(k);
  if (R0_)
    v1 += 4;
  if (area_object_length[k]) {
    slot = Smbll_FindEmptyEnemySlotRev();
    if (slot != 0xff) {
      AreaObjXPosition = Smbll_GetAreaObjXPosition();
      obj_xpos_lo.enemy[slot] = AreaObjXPosition + 8;
      obj_xpos_hi.enemy[slot] = __CFADD__(AreaObjXPosition, 8) + column_pos_hi;
      obj_ypos_hi.enemy[slot] = 1;
      enemy_flag[slot] = 1;
      obj_ypos_lo.enemy[slot] = Smbll_GetAreaObjYPosition();
      enemy_id[slot] = 13;
      Smbll_PiranhaPlant_Init(slot);
    }
  }
  v4 = R7_;
  metatile_buffer[R7_] = kDATA_03A9EF[v1];
  Smbll_RenderUnderPart(v4 + 1, R6_ - 1, kbyte_A75C[v1]);
}

uint8 Smbll_CODE_03AA4D(uint8 k) {
  Smbll_ChkLrgObjFixedLength(k, 1u);
  R6_ = Smbll_GetLrgObjAttrib(k) & 7;
  return area_object_length[k];
}

void Smbll_sub_A7C1(uint8 k, uint8 a) {
  uint8 AreaObjXPosition;  // al

  enemy_id[k] = a;
  AreaObjXPosition = Smbll_GetAreaObjXPosition();
  obj_xpos_lo.enemy[k] = AreaObjXPosition + 8;
  obj_xpos_hi.enemy[k] = __CFADD__(AreaObjXPosition, 8) + column_pos_hi;
  obj_ypos_hi.enemy[k] = 1;
  enemy_flag[k] = 1;
  obj_ypos_lo.enemy[k] = Smbll_GetAreaObjYPosition();
  Smbll_PiranhaPlant_Init(k);
}

uint8 Smbll_FindEmptyEnemySlot() {
  uint8 result;  // si

  for (result = 0; result != 8; ++result) {
    if (!enemy_flag[result])
      break;
  }
  return result;
}

uint8 Smbll_FindEmptyEnemySlotRev() {
  uint8 result;  // si

  for (result = 8; result != 0xFF; --result) {
    if (!enemy_flag[result])
      break;
  }
  return result;
}

void Smbll_ExtObj0D_HoleWater(uint8 k) {
  uint8 v1;  // si
  uint8 v2;  // di

  Smbll_ChkLrgObjLength(k);
  v1 = 10;
  if (area_type == 3)
    v1 = 11;
  v2 = area_type;
  metatile_buffer[v1] = kbyte_A7FF[area_type];
  Smbll_RenderUnderPart(v1 + 1, 1u, kbyte_A803[v2 >> 1]);
}

void Smbll_ExtObj0E_QuestionBlockHigh(uint8 k) {
  Smbll_CODE_03AAA4(k, 3u);
}

void Smbll_ExtObj0E_QuestionBlockLow(uint8 k) {
  Smbll_CODE_03AAA4(k, 7u);
}

void Smbll_CODE_03AAA4(uint8 k, uint8 a) {
  Smbll_ChkLrgObjLength(k);
  metatile_buffer[a] = -25;
}

void Smbll_ExtObj0A_Bridge_High(uint8 k) {
  Smbll_CODE_03AABA(k, 6u);
}

void Smbll_ExtObj0B_Bridge_Middle(uint8 k) {
  Smbll_CODE_03AABA(k, 7u);
}

void Smbll_ExtObj0B_Bridge_Low(uint8 k) {
  Smbll_CODE_03AABA(k, 9u);
}

void Smbll_CODE_03AABA(uint8 k, uint8 a) {
  uint8 v2;  // al

  Smbll_ChkLrgObjLength(k);
  if (area_object_length[k]) {
    if (tree_ledge_arr130F[k]) {
      v2 = 7;
    } else {
      ++tree_ledge_arr130F[k];
      v2 = 8;
    }
  } else {
    tree_ledge_arr130F[k] = 0;
    v2 = 9;
  }
  metatile_buffer[a] = v2;
  Smbll_RenderUnderPart(a + 1, 0, 0x6Au);
}

void Smbll_ExtObj23_FlagpoleObject(uint8 j) {
  uint8 AreaObjXPosition;  // al

  metatile_buffer[0] = 45;
  Smbll_RenderUnderPart(1u, 8u, 0x2Eu);
  metatile_buffer[10] = 98;
  AreaObjXPosition = Smbll_GetAreaObjXPosition();
  obj_xpos_lo.enemy[5] = AreaObjXPosition + 8;
  obj_xpos_hi.enemy[5] = __CFADD__(AreaObjXPosition, 8) + column_pos_hi;
  obj_ypos_lo.enemy[5] = 48;
  flagpole_score_ypos_lo = -80;
  enemy_id[5] = 48;
  ++enemy_flag[5];
  g_byte_7E0FB4 = -1;
  g_byte_7E0FB5 = -1;
  g_byte_7E0FB6 = -1;
  g_byte_7E0FB7 = -1;
}

void Smbll_ExtObj04_RowOfCoins(uint8 k) {
  Smbll_GetRow(k, kCoinMetatileData[area_type]);
}

void Smbll_ExtObj26_CastleBridge(uint8 k) {
  Smbll_ChkLrgObjFixedLength(k, 0xCu);
  Smbll_ExtObj25_ChainObj(k);
}

void Smbll_ExtObj24_AxeObj(uint8 k) {
  vram_buffer_addr_ctrl = 8;
  Smbll_ExtObj25_ChainObj(k);
}

void Smbll_ExtObj25_ChainObj(uint8 k) {
  Smbll_CODE_03AB55(kCObjectRow[R0_ - 2], kCObjectMetatile[R0_ - 2]);
}

void Smbll_ExtObj20_EmptyBlock(uint8 k) {
  Smbll_GetLrgObjAttrib(k);
  Smbll_CODE_03AB55(R7_, 0xFDu);
}

void Smbll_CODE_03AB55(uint8 k, uint8 a) {
  Smbll_RenderUnderPart(k, 0, a);
}

void Smbll_ExtObj02_RowOfBricks(uint8 k) {
  uint8 v1;  // di

  v1 = area_type;
  if (cloud_type_override)
    v1 = 4;
  Smbll_GetRow(k, kBrickMetatiles[v1]);
}

void Smbll_ExtObj03_RowOfSolidBlocks(uint8 k) {
  Smbll_GetRow(k, kSolidBlockMetatiles[area_type]);
}

void Smbll_GetRow(uint8 k, uint8 a) {
  Smbll_ChkLrgObjLength(k);
  Smbll_RenderUnderPart(R7_, 0, a);
}

void Smbll_ExtObj05_ColumnOfBricks(uint8 k) {
  uint8 LrgObjAttrib;  // di
  uint8 a;             // [rsp+47h] [rbp-1h]

  a = kBrickMetatiles[area_type];
  LrgObjAttrib = Smbll_GetLrgObjAttrib(k);
  Smbll_RenderUnderPart(R7_, LrgObjAttrib, a);
}

void Smbll_ExtObj06_ColumnOfSolidBlocks(uint8 k) {
  uint8 LrgObjAttrib;  // di
  uint8 a;             // [rsp+47h] [rbp-1h]

  a = kSolidBlockMetatiles[area_type];
  LrgObjAttrib = Smbll_GetLrgObjAttrib(k);
  Smbll_RenderUnderPart(R7_, LrgObjAttrib, a);
}

void Smbll_ExtObj21_Jumpspring(uint8 k) {
  uint8 i;                 // si
  uint8 AreaObjYPosition;  // al
  int v3;                  // edx

  Smbll_GetLrgObjAttrib(k);
  for (i = 0; i != 7; ++i) {
    if (!enemy_flag[i])
      break;
  }
  obj_xpos_lo.enemy[i] = Smbll_GetAreaObjXPosition();
  obj_xpos_hi.enemy[i] = column_pos_hi;
  AreaObjYPosition = Smbll_GetAreaObjYPosition();
  obj_ypos_lo.enemy[i] = AreaObjYPosition;
  obj_xspeed.enemy[i] = AreaObjYPosition;
  enemy_id[i] = 50;
  obj_ypos_hi.enemy[i] = 1;
  enemy_flag[i] = 1;
  v3 = R7_;
  metatile_buffer[R7_] = 110;
  metatile_buffer[v3 + 1] = 111;
}

void Smbll_ExtObj19_Hidden1upBlock(uint8 k) {
  if (hidden_1up_flag) {
    hidden_1up_flag = 0;
    Smbll_BrickWithItem(k);
  }
}

void Smbll_ExtObj18_QuestionBlock(uint8 k) {
  uint8 v1;  // [rsp+47h] [rbp-1h]

  v1 = kBrickQBlockMetatiles[Smbll_GetAreaObjectID()];
  Smbll_GetLrgObjAttrib(k);
  metatile_buffer[R7_] = v1;
}

void Smbll_ExtObj1D_BrickWith10Coins(uint8 k) {
  brick_coin_timer_flag[0] = 0;
  Smbll_BrickWithItem(k);
}

void Smbll_BrickWithItem(uint8 k) {
  int8 v1;   // al
  uint8 v2;  // [rsp+47h] [rbp-1h]

  R7_ = Smbll_GetAreaObjectID();
  v1 = 0;
  if (area_type != 1)
    v1 = 6;
  v2 = kBrickQBlockMetatiles[(uint8)(R7_ + v1)];
  Smbll_GetLrgObjAttrib(k);
  metatile_buffer[R7_] = v2;
}

uint8 Smbll_GetAreaObjectID() {
  return R0_;
}

void Smbll_ExtObj08_Hole(uint8 k) {
  uint16 v1;               // di
  uint8 v2;                // si
  uint8 AreaObjXPosition;  // al
  uint8 v4;                // si

  v1 = Smbll_ChkLrgObjLength(k);
  if ((v1 & 0x100) && !area_type) {
    v2 = cannon_offset;
    AreaObjXPosition = Smbll_GetAreaObjXPosition();
    cannon_xpos_lo[v2] = AreaObjXPosition - 16;
    cannon_xpos_hi[v2] = column_pos_hi - (AreaObjXPosition < 0x10u);
    cannon_ypos_lo[v2] = 16 * (v1 + 2);
    v4 = v2 + 1;
    if (v4 >= 5u)
      v4 = 0;
    cannon_offset = v4;
  }
  Smbll_RenderUnderPart(8u, 0xFu, 0);
}

uint8 Smbll_RenderUnderPart(uint8 k, uint8 j, uint8 a) {
  uint8 v3;  // di

  do {
    area_object_height = j;
    v3 = metatile_buffer[k];
    if (!v3 || v3 != 31 && v3 != 34 && (v3 == 0xE7 || v3 != 15 && v3 != 19 && v3 < 0xE7u && (v3 != 78 || a != 72)))
      metatile_buffer[k] = a;
    if (++k >= 0xDu)
      break;
    j = area_object_height - 1;
  } while ((int8)(area_object_height - 1) >= 0);
  return k;
}

uint16 Smbll_ChkLrgObjLength(uint8 k) {
  uint8 LrgObjAttrib;  // di

  LrgObjAttrib = Smbll_GetLrgObjAttrib(k);
  return Smbll_ChkLrgObjFixedLength(k, LrgObjAttrib);
}

uint16 Smbll_ChkLrgObjFixedLength(uint8 k, uint8 jin) {
  uint16 j = jin;
  if ((area_object_length[k] & 0x80u) != 0) {
    area_object_length[k] = j;
    j |= 0x100;
  }
  return j;
}

uint8 Smbll_GetLrgObjAttrib(uint8 k) {
  uint16 v1;  // di

  v1 = area_obj_offset_buffer[(uint16)(2 * k) >> 1];
  R7_ = *IndirPtr(&area_data_ptr, v1) & 0xF;
  return *IndirPtr(&area_data_ptr, v1 + 1) & 0xF;
}

uint8 Smbll_GetAreaObjXPosition() {
  return 16 * current_column_pos_lo;
}

uint8 Smbll_GetAreaObjYPosition() {
  return 16 * R7_ + 32;
}

void Smbll_GetBlockBufferAddr(uint8 a) {
  R7_ = kbyte_AA7F[(a >> 4) + 2];
  R6_ = kbyte_AA7F[a >> 4] + (a & 0xF);
}

uint8 Smbll_RenderUnderPart_Far(uint8 k, uint8 j, uint8 a) {
  return Smbll_RenderUnderPart(k, j, a);
}

uint8 Smbll_GetAreaObjXPosition_Far() {
  return Smbll_GetAreaObjXPosition();
}

uint8 Smbll_FindEmptyEnemySlot_Far() {
  return Smbll_FindEmptyEnemySlot();
}

uint8 Smbll_sub_AAC0(uint8 k, uint8 a) {
  uint8 v2;    // di
  uint8 slot;  // si
  uint8 v4;    // al
  uint8 v5;    // [rsp+46h] [rbp-2h]

  v5 = a;
  v2 = Smbll_CODE_03AA4D(k);
  R7_ = v5;
  if (area_object_length[k]) {
    slot = Smbll_FindEmptyEnemySlot();
    if (Unreachable()) {
      Smbll_sub_A7C1(slot, 4);
      v4 = obj_ypos_lo.enemy[slot] + 16 * R6_ - 10;
      obj_ypos_lo.enemy[slot] = v4;
      obj_sub_yspeed.enemy[slot] = v4;
      obj_sub_ypos.enemy[slot] = v4 + 24;
      ++obj_yspeed.enemy[slot];
    }
  }
  k = Smbll_RenderUnderPart(R7_, R6_ - 1, kbyte_A75C[v2]);
  metatile_buffer[k] = kDATA_03A9EF[v2];
  return k;
}

void Smbll_sub_AB13(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // al

  if (!enemy_state[k] && !enemy_frame_timer[k]) {
    if (!obj_yspeed.enemy[k]) {
      obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
      ++obj_yspeed.enemy[k];
    }
    v1 = obj_sub_ypos.enemy[k];
    if ((obj_xspeed.enemy[k] & 0x80u) != 0)
      v1 = obj_sub_yspeed.enemy[k];
    R0_ = v1;
    if (!timer_control) {
      v2 = obj_xspeed.enemy[k] + obj_ypos_lo.enemy[k];
      obj_ypos_lo.enemy[k] = v2;
      if (v2 == R0_) {
        obj_yspeed.enemy[k] = 0;
        enemy_frame_timer[k] = 32;
      }
    }
  }
}

void Smbll_GameMode01_Level() {
  int8 v0;  // si

  v0 = 2 * game_mode_task;
  if (2 * game_mode_task == 2) {
    Smbll_ScreenRoutines();
  } else if (v0) {
    if (v0 == 4) {
      Smbll_GameMode01_Level_SecondaryGameSetup();
    } else {
      if (v0 != 6) {
        Unreachable();
        while (1)
          ;
      }
      Smbll_GameMode01_Level_GameCoreRoutine();
    }
  } else {
    Smbll_GameMode01_Level_InitializeArea();
  }
}

void Smbll_sub_AB68() {
  if ((save_buffer_2_player_flag & 0x80u) == 0) {
    Smbll_GameRoutines();
    Smbll_GetPlayerOffscreenBits();
    Smbll_RelativePlayerPosition();
    Smbll_PlayerGfxHandler();
  } else {
    Smbll_CODE_03AD74();
  }
}

void Smbll_GameMode01_Level_GameCoreRoutine() {
  Smbll_ControllerStuff_05C860();
  Smbll_CODE_03AD74();
}

void Smbll_CODE_03AD74() {
  uint8 v0;  // si
  uint8 v1;  // al

  Smbll_GameRoutines();
  if (game_mode_task >= 3u) {
    Smbll_ProcFireball_Bubble();
    v0 = 0;
    while (1) {
      object_index = v0;
      if (var0E67 == 127)
        break;
      Smbll_EnemiesAndLoopsCore(v0);
      if (!var0E67)
        Smbll_FloateyNumbersRoutine(v0);
      if (++v0 == 10) {
        Smbll_ProcessContactSprites();
        if (var0E67)
          var0E67 = 127;
        break;
      }
    }
    Smbll_GetPlayerOffscreenBits();
    Smbll_RelativePlayerPosition();
    Smbll_PlayerGfxHandler();
    object_index = 1;
    Smbll_BlockObjectsCore(1u);
    object_index = 0;
    Smbll_BlockObjectsCore(0);
    Smbll_BlockObjMT_Updater();
    Smbll_MiscObjectsCore();
    Smbll_ProcessCannons();
    Smbll_ProcessWhirlpools();
    Smbll_FlagpoleRoutine();
    Smbll_RunGameTimer();
    Smbll_ColorRotation();
    if (smbll_varF04)
      Smbll_sub_2F282();
    if (sign8(obj_ypos_hi.player - 2)) {
      if (!player_star_power_timer) {
        if (interval_timer_control == 1 && game_engine_subroutine != 12)
          Smbll_GetPlayerColors();
        Smbll_ResetPalStar();
        goto LABEL_23;
      }
      if (player_star_power_timer == 4 && !interval_timer_control)
        Smbll_SetLevelMusic();
    }
    v1 = frame_counter;
    if (player_star_power_timer < 8u)
      v1 = frame_counter >> 2;
    Smbll_CyclePlayerPalette(v1);
LABEL_23:
    buttons_a_b_previous = buttons_a_b;
    buttons_left_right = 0;
    Smbll_CODE_03AE2C();
  }
}

void Smbll_CODE_03AE2C() {
  if (vram_buffer_addr_ctrl != 6) {
    if (!area_parser_task_num) {
      if (sign8(scroll_thirty_two - 32))
        return;
      scroll_thirty_two -= 32;
      LOBYTE(vram_buffer2[0]) = 0;
    }
    Smbll_AreaParserTaskHandler();
  }
}

void Smbll_ScrollHandler(int scrollamt) {
  uint8 v0;  // di
  uint8 v1;  // di
  uint8 v2;  // al
  bool v3;   // cf

  if (scrollamt >= 0) {
    v0 = scrollamt;
    goto LBL_ScrollScreen;
  }

  player_x_scroll += platform_x_scroll;
  if (scroll_lock || player_pos_for_scroll < 0x50u || side_collision_timer || (int8)(player_x_scroll - 1) < 0) {
    scroll_amount = 0;
  } else {
    v0 = player_x_scroll;
    if (player_x_scroll >= 2u)
      v0 = player_x_scroll - 1;
    if (player_pos_for_scroll >= 0x70u)
      v0 = player_x_scroll;
    while (delay_frames_while_scrolling_flag)
      ;
LBL_ScrollScreen:
    scroll_amount = v0;
    scroll_thirty_two += v0;
    R0_ = screen_left_xpos_lo;
    R1_ = screen_left_xpos_hi;
    *(uint16 *)&R0_ += v0;
    layer2_xpos = *(uint16 *)&R0_ >> 1;
    layer3_xpos = *(uint16 *)&R0_ >> 2;
    screen_left_xpos_lo = R0_;
    layer1_xpos_lo = R0_;
    screen_left_xpos16 = __PAIR16__(R1_, R0_);
    screen_left_xpos_hi = R1_;
    R0_ = R1_ & 1;
    mirror_ppu_ctrl_reg1 = R1_ & 1 | mirror_ppu_ctrl_reg1 & 0xFE;
    Smbll_GetScreenPosition();
    scroll_interval_timer = 8;
  }
  R0_ = Smbll_GetXOffscreenBits(0);
  v1 = 0;
  if (__CFSHL__(R0_, 1) || (v1 = 1, (R0_ & 0x20) != 0)) {
    v2 = *(&screen_left_xpos_lo + v1);
    v3 = v2 < kSubtracterData_X[v1];
    obj_xpos_lo.player = v2 - kSubtracterData_X[v1];
    obj_xpos_hi.player = *(&screen_left_xpos_hi + v1) - v3;
    if (buttons_left_right != kOffscrJoypadBitsData[v1])
      obj_xspeed.player = 0;
  }
  platform_x_scroll = 0;
}

uint8 Smbll_GetScreenPosition() {
  uint8 result;  // al

  screen_right_xpos = screen_left_xpos_lo - 1;
  result = (screen_left_xpos_lo != 0) + screen_left_xpos_hi;
  screen_right_xpos_hi = result;
  return result;
}

void Smbll_GameRoutines() {
  int8 v0;  // si

  v0 = 2 * game_engine_subroutine;
  if (2 * game_engine_subroutine) {
    switch (v0) {
    case 12: Smbll_PlayerLoseLife(); break;
    case 14: Smbll_PlayerEntrance(); break;
    case 16: Smbll_PlayerCtrlRoutine(); break;
    case 2: Smbll_Vine_AutoClimb(); break;
    case 6: Smbll_VerticalPipeEntry(); break;
    case 4: Smbll_SideExitPipeEntry(); break;
    case 18: Smbll_PlayerChangeSize(); break;
    case 20: Smbll_PlayerInjuryBlink(); break;
    case 22: Smbll_PlayerDeath(); break;
    case 24: Smbll_PlayerFireFlower(); break;
    case 8: Smbll_FlagpoleSlide(); break;
    case 10: Smbll_PlayerEndLevel(); break;
    default:
      Unreachable();
      while (1)
        ;
    }
  } else {
    Smbll_Entrance_GameTimerSetup();
  }
}

void Smbll_PlayerEntrance() {
  uint8 player;  // al
  uint8 v1;      // di
  uint8 v2;      // al

  if (alt_entrance_ctrl != 2) {
    if (obj_ypos_lo.player < 0x30u) {
      Smbll_AutoControlPlayer(0);
      return;
    }
    if (player_entrance_ctrl == 6 || player_entrance_ctrl == 7) {
      if ((player_sprattrib & 0xF0) != 0) {
        Smbll_AutoControlPlayer(1u);
      } else {
        Smbll_EnterSidePipe();
        if (!--change_area_timer) {
          fade_direction = 1;
          enable_mosaic_fades_flag = 1;
          ++screen_routines_flag0769;
          Smbll_sub_B092();
        }
      }
      return;
    }
LABEL_19:
    player_gfx_processing_flag = 0;
    game_engine_subroutine = 8;
    player_facing_dir = 1;
    alt_entrance_ctrl = 0;
    disable_collision_detection = 0;
    vine_screen_exit_flag = 0;
    return;
  }
  if (vine_screen_exit_flag) {
    if (vine_height == 96) {
      v1 = 0;
      v2 = 1;
      if (obj_ypos_lo.player >= 0x99u) {
        player_state = 3;
        v1 = 1;
        v2 = 8;
        level_data_map16_lo[180] = 8;
      }
      disable_collision_detection = v1;
      Smbll_AutoControlPlayer(v2);
      if (obj_xpos_lo.player >= 0x48u)
        goto LABEL_19;
    }
  } else {
    player = obj_ypos_lo.player;
    if (obj_ypos_lo.player == 0xB0) {
      player = 4;
      sound_ch1 = 4;
    }
    player_gfx_processing_flag = player;
    Smbll_MovePlayerYAxis(0xFFu);
    if (obj_ypos_lo.player < 0x91u)
      goto LABEL_19;
  }
}

void Smbll_AutoControlPlayer(uint8 a) {
  saved_joypad_bits = a;
  auto_control_player_var1 = 1;
  Smbll_sub_B02C();
}

void Smbll_PlayerCtrlRoutine() {
  auto_control_player_var1 = 0;
  Smbll_sub_B02C();
}

void Smbll_sub_B02C() {
  uint8 v0;  // di
  uint8 v1;  // al
  uint8 v3;  // al
  int8 v4;   // si

  if (game_engine_subroutine != 11) {
    if (!area_type && (obj_ypos_hi.player != 1 || obj_ypos_lo.player >= 0xD0u))
      saved_joypad_bits = 0;
    buttons_a_b = saved_joypad_bits & 0xC0;
    buttons_left_right = saved_joypad_bits & 3;
    buttons_up_down = saved_joypad_bits & 0xC;
    if ((saved_joypad_bits & 4) != 0 && !player_state && buttons_left_right) {
      buttons_left_right = 0;
      buttons_up_down = 0;
    }
  }
  if (!debug_flag || Smbll_DebugCode() & 1)
    Smbll_PlayerMovementSubs();
  v0 = 1;
  if (!player_size) {
    v0 = 0;
    if (crouching_flag)
      v0 = 2;
  }
  player_hitbox_ctrl = v0;
  v1 = 1;
  if (obj_xspeed.player) {
    if ((obj_xspeed.player & 0x80u) != 0)
      v1 = 2;
    player_moving_dir = v1;
  }
  Smbll_ScrollHandler(-1);
  Smbll_GetPlayerOffscreenBits();
  Smbll_RelativePlayerPosition();
  Smbll_BoundingBoxCore(0, 0);
  Smbll_PlayerBGCollision();
  if (obj_ypos_lo.player >= 0x40u && game_engine_subroutine != 5 && game_engine_subroutine != 7 && game_engine_subroutine >= 4u) {
    if (game_engine_subroutine == 11) {
      smbll_varF04 = 0;
      v3 = player_sprattrib & 0xCE | 0x30;
    } else {
      v3 = player_sprattrib & 0xCE | 0x20;
    }
    player_sprattrib = v3;
  }
  if (!sign8(obj_ypos_hi.player - 2)) {
    scroll_lock = 1;
    R7_ = 4;
    v4 = 0;
    if (game_timer_expired_flag || !cloud_type_override) {
      v4 = 1;
      if (game_engine_subroutine != 11) {
        if (!death_music_loaded) {
          ++death_music_loaded;
          music_ch1 = 9;
          sound_ch2 |= 0x20u;
          var0E67 = obj_ypos_hi.player;
        }
        R7_ = 6;
      }
    }
    if (!sign8(obj_ypos_hi.player - R7_)) {
      if ((int8)(v4 - 1) < 0) {
        vine_screen_exit_flag = 0;
        Smbll_SetEntr();
        ++alt_entrance_ctrl;
      } else if (!event_music_buffer) {
        game_engine_subroutine = 6;
      }
    }
  }
}

void Smbll_Vine_AutoClimb() {
  if (obj_ypos_hi.player || obj_ypos_lo.player >= 0xE4u) {
    vine_screen_exit_flag = 8;
    var0E67 = 8;
    player_state = 3;
    Smbll_AutoControlPlayer(8u);
  } else {
    Smbll_SetEntr();
  }
}

void Smbll_SetEntr() {
  alt_entrance_ctrl = 2;
  Smbll_ChgAreaMode();
}

void Smbll_VerticalPipeEntry() {
  uint8 v0;  // di

  enable_mosaic_fades_flag = 1;
  vertical_pipe_flag_var0218 = 1;
  if (frame_counter & 1)
    Smbll_MovePlayerYAxis(1u);
  Smbll_ScrollHandler(-1);
  v0 = 0;
  if (!warp_zone_control) {
    v0 = 1;
    if (area_type == 3)
      v0 = 2;
  }
  if (!--change_area_timer) {
    alt_entrance_ctrl = v0;
    Smbll_ChgAreaMode();
  }
}

void Smbll_MovePlayerYAxis(uint8 a) {
  obj_ypos_lo.player += a;
}

void Smbll_SideExitPipeEntry() {
  enable_mosaic_fades_flag = 1;
  var0E67 = 1;
  Smbll_EnterSidePipe();
  if (!--change_area_timer) {
    alt_entrance_ctrl = 2;
    Smbll_ChgAreaMode();
  }
}

void Smbll_ChgAreaMode() {
  fade_direction = 1;
  var0E67 = 1;
  if (player_entered_coin_heaven_flag)
    Smbll_DrawLargePlatform_Sub1();
  game_mode_task = 0;
  sprite0_hit_detect_flag = 0;
}

void Smbll_EnterSidePipe() {
  uint8 v0;  // di

  obj_xspeed.player = 8;
  v0 = 1;
  if ((obj_xpos_lo.player & 0xF) == 0) {
    obj_xspeed.player = 0;
    v0 = 0;
  }
  Smbll_AutoControlPlayer(v0);
}

void Smbll_PlayerChangeSize() {
  if (timer_control == 0xF8) {
    Smbll_InitChangeSize();
  } else if (timer_control == 0xC4) {
    Smbll_DonePlayerTask();
  }
}

void Smbll_PlayerInjuryBlink() {
  if (timer_control >= 0xF0u) {
    if (timer_control == 0xF0)
      Smbll_InitChangeSize();
  } else if (timer_control == 0xC8) {
    Smbll_DonePlayerTask();
  } else {
    Smbll_PlayerCtrlRoutine();
  }
}

void Smbll_InitChangeSize() {
  if (!player_change_size_flag) {
    player_anim_ctrl = player_change_size_flag++;
    player_size ^= 1u;
  }
}

void Smbll_PlayerDeath() {
  if (timer_control < 0xF0u)
    Smbll_PlayerCtrlRoutine();
}

void Smbll_DonePlayerTask() {
  timer_control = 0;
  Smbll_GetPlayerColors();
  game_engine_subroutine = 8;
}

void Smbll_PlayerFireFlower() {
  if (timer_control == 0xC0) {
    Smbll_DonePlayerTask();
    Smbll_ResetPalStar();
  } else {
    Smbll_CyclePlayerPalette(2 * ~timer_control);
  }
}

void Smbll_CyclePlayerPalette(uint8 a) {
  uint16 v1;  // si
  uint16 i;   // di

  v1 = (8 * a) & 0x60;
  if (current_player)
    v1 += 32;
  for (i = 480; i != 512; i += 2) {
    palette_mirror[i >> 1] = kword_C16B[v1 >> 1];
    v1 += 2;
  }
  update_entire_palette_flag = 1;
}

void Smbll_ResetPalStar() {
  player_sprattrib = player_sprattrib & 0xF1 | 0xE;
}

void Smbll_FlagpoleSlide() {
  uint8 v0;  // al

  if (enemy_id[5] == 48) {
    v0 = 0;
    flagpole_sound_queue = 0;
    if (obj_ypos_lo.player < 0x9Eu)
      v0 = 4;
    Smbll_AutoControlPlayer(v0);
  } else {
    ++game_engine_subroutine;
  }
}

void Smbll_PlayerEndLevel() {
  if (Smbll_HandleMarioGoalWalk()) {
    Smbll_AutoControlPlayer(1u);
    if (obj_ypos_lo.player >= 0xAEu)
      scroll_lock = 0;
  }
  if (star_flag_task_control == 5) {
    if (++level_number == 3 && coin_tally_for_1ups >= 0x10u)
      ++hidden_1up_flag;
    Smbll_sub_B092();
  }
}

void Smbll_sub_B092() {
  ++area_number;
  if (world_number == 8 && level_number == 4) {
    level_number = 0;
    area_number = 0;
    ++world_number;
    smbll_var7FA = -1;
    title_screen_hard_mode_flag = 1;
    primary_hard_mode = 1;
  }
  Smbll_LoadAreaPointer();
  ++fetch_new_game_timer_flag;
  Smbll_ChgAreaMode();
  halfway_page = 0;
}

void Smbll_PlayerMovementSubs() {
  uint8 v0;  // al
  int8 v1;   // si
  bool v3;   // cf
  uint8 v4;  // si

  v0 = 0;
  if (!player_size) {
    if (player_state)
      goto LABEL_5;
    v0 = buttons_up_down & 4;
  }
  crouching_flag = v0;
LABEL_5:
  Smbll_PlayerPhysicsSub();
  if (player_change_size_flag)
    return;
  if (player_state != 3)
    climb_side_timer = 24;
  v1 = 2 * player_state;
  if (!(2 * player_state)) {
    Smbll_GetPlayerAnimSpeed();
    if (buttons_left_right)
      player_facing_dir = buttons_left_right;
    Smbll_ImposeFriction(buttons_left_right);
    Smbll_MovePlayerHoriz2();
    return;
  }
  if (v1 == 4) {
    vertical_force = vertical_force_down;
LABEL_28:
    if (buttons_left_right)
      Smbll_ImposeFriction(buttons_left_right);
    Smbll_MovePlayerHoriz2();
    if (game_engine_subroutine == 11)
      vertical_force = 40;
    Smbll_MovePlayerVert();
    return;
  }
  if (v1 == 2) {
    if ((obj_yspeed.player & 0x80u) == 0 ||
        (buttons_a_b_previous & buttons_a_b & 0x80) == 0 && (uint8)(jump_origin_y_pos_lo - obj_ypos_lo.player) >= diff_to_halt_jump) {
      vertical_force = vertical_force_down;
    }
    if (swimming_flag) {
      Smbll_GetPlayerAnimSpeed();
      if (obj_ypos_lo.player < 0x14u)
        vertical_force = 24;
      if (buttons_left_right)
        player_facing_dir = buttons_left_right;
    }
    goto LABEL_28;
  }
  if (v1 != 6) {
    Unreachable();
    while (1)
      ;
  }
  uint16 t = obj_sub_ypos.player + obj_sub_yspeed.player;
  obj_sub_ypos.player = t;
  AddHiLo(&obj_ypos_hi.player, &obj_ypos_lo.player, (t >> 8) + (int8)obj_yspeed.player);
  if ((player_collision_bits & buttons_left_right) == 0) {
    climb_side_timer = 0;
    return;
  }
  if (!climb_side_timer) {
    climb_side_timer = 24;
    v4 = 0;
    if (!(player_collision_bits & buttons_left_right & 1)) {
      if (rel_xpos_lo.player < 0x10u)
        return;
      v4 = 2;
    }
    if (player_facing_dir != 1)
      ++v4;
    v3 = __CFADD__(kClimbAdderLow[v4], obj_xpos_lo.player);
    obj_xpos_lo.player += kClimbAdderLow[v4];
    obj_xpos_hi.player += kClimbAdderHigh[v4] + v3;
    player_facing_dir = buttons_left_right ^ 3;
  }
}

void Smbll_MovePlayerHoriz2() {
  player_x_scroll = Smbll_MovePlayerHoriz();
  if (smbll_varF04)
    Smbll_MovePlayerHoriz2_Sub();
}

void Smbll_PlayerPhysicsSub() {
  uint8 v0;  // di
  uint8 v1;  // al
  uint8 v2;  // di
  uint8 v3;  // di
  bool v4;   // cf

  if (player_state == 3) {
    v0 = 0;
    if ((player_collision_bits & buttons_up_down) != 0) {
      v0 = 1;
      if ((player_collision_bits & buttons_up_down & 8) != 0) {
        if ((frame_counter & 7) == 0)
          sound_ch1 = 48;
      } else {
        v0 = 2;
      }
    }
    obj_sub_yspeed.player = kClimb_Y_MForceData[v0];
    v1 = 8;
    obj_yspeed.player = kClimb_Y_SpeedData[v0];
    if ((obj_yspeed.player & 0x80u) == 0)
      v1 = 4;
    player_anim_timer_set = v1;
    return;
  }
  if (!jumpspring_anim_ctrl && (buttons_a_b & 0x80u) != 0 && (buttons_a_b_previous & buttons_a_b & 0x80) == 0 &&
      (!player_state || swimming_flag && (jump_swim_timer || (obj_yspeed.player & 0x80u) == 0))) {
    jump_swim_timer = 32;
    v2 = 0;
    obj_sub_ypos.player = 0;
    obj_sub_yspeed.player = 0;
    jump_origin_y_pos_hi = obj_ypos_hi.player;
    jump_origin_y_pos_lo = obj_ypos_lo.player;
    player_state = 1;
    if (player_x_speed_absolute >= 9u) {
      v2 = 1;
      if (player_x_speed_absolute >= 0x10u) {
        v2 = 2;
        if (player_x_speed_absolute >= 0x19u) {
          v2 = 3;
          if (player_x_speed_absolute >= 0x1Cu)
            v2 = 4;
        }
      }
    }
    diff_to_halt_jump = 1;
    if (swimming_flag) {
      v2 = 5;
      if (cannon_timer[0])
        v2 = 6;
    }
    if (current_player) {
      vertical_force = kJumpLForceData[v2];
      vertical_force_down = kFallLForceData[v2];
    } else {
      vertical_force = kJumpMForceData[v2];
      vertical_force_down = kFallMForceData[v2];
    }
    obj_sub_yspeed.player = kInitMForceData[v2];
    obj_yspeed.player = kPlayerYSpdData[v2];
    if (swimming_flag) {
      sound_ch1 = 14;
      if (obj_ypos_lo.player < 0x14u)
        obj_yspeed.player = 0;
    } else {
      sound_ch2 |= 1u;
    }
  }
  v3 = 0;
  R0_ = 0;
  if (player_state) {
    if (player_x_speed_absolute < 0x19u)
      goto LABEL_40;
  } else {
    v3 = 1;
    if (!area_type)
      goto LABEL_40;
    v3 = 0;
    if (buttons_left_right != player_moving_dir)
      goto LABEL_40;
    if ((buttons_a_b & 0x40) != 0) {
      running_timer = 10;
      goto LABEL_44;
    }
    if (!running_timer) {
LABEL_40:
      ++v3;
      ++R0_;
      if (running_speed || player_x_speed_absolute >= 0x21u)
        ++R0_;
    }
  }
LABEL_44:
  max_left_speed = kMaxLeftXSpdData[v3];
  if (game_engine_subroutine == 7)
    v3 = 3;
  max_right_speed = kMaxRightXSpdData[v3];
  friction_adder_low = kFrictionData[R0_];
  friction_adder_high = 0;
  if (player_facing_dir != player_moving_dir && !player_luigi_graphics) {
    v4 = __CFSHL__(friction_adder_low, 1);
    friction_adder_low *= 2;
    friction_adder_high = 2 * friction_adder_high + v4;
  }
}

void Smbll_GetPlayerAnimSpeed() {
  uint8 v0;  // di
  uint8 v1;  // al

  v0 = 0;
  v1 = player_x_speed_absolute;
  if (player_x_speed_absolute >= 0x1Cu)
    goto LABEL_7;
  v0 = 1;
  if (player_x_speed_absolute < 0xEu)
    v0 = 2;
  if ((saved_joypad_bits & 0x7F) != 0) {
    if ((saved_joypad_bits & 3) == player_moving_dir) {
      v1 = 0;
LABEL_7:
      running_speed = v1;
      goto LABEL_10;
    }
    if (player_x_speed_absolute < 0xBu) {
      player_moving_dir = player_facing_dir;
      obj_xspeed.player = 0;
      player_x_move_force = 0;
    }
  }
LABEL_10:
  player_anim_timer_set = kPlayerAnimTmrData[v0];
}

void Smbll_ImposeFriction(uint8 a) {
  int8 v1;       // al
  uint8 player;  // al
  bool v3;       // cf

  v1 = player_collision_bits & a;
  if (v1) {
    if (v1 & 1) {
LABEL_6:
      v3 = __CFADD__(friction_adder_low, player_x_move_force);
      player_x_move_force += friction_adder_low;
      player = friction_adder_high + v3 + obj_xspeed.player;
      obj_xspeed.player = player;
      if ((int8)(player - max_right_speed) >= 0) {
        player = max_right_speed;
        obj_xspeed.player = max_right_speed;
        goto LABEL_12;
      }
      goto LABEL_10;
    }
  } else {
    player = obj_xspeed.player;
    if (!obj_xspeed.player)
      goto LABEL_12;
    if ((obj_xspeed.player & 0x80u) != 0)
      goto LABEL_6;
  }
  v3 = player_x_move_force >= friction_adder_low;
  player_x_move_force -= friction_adder_low;
  player = obj_xspeed.player - (!v3 + friction_adder_high);
  obj_xspeed.player = player;
  if ((int8)(player - max_left_speed) < 0) {
    player = max_left_speed;
    obj_xspeed.player = max_left_speed;
  }
LABEL_10:
  if (sign8(player))
    player = -player;
LABEL_12:
  player_x_speed_absolute = player;
}

void Smbll_ProcFireball_Bubble() {
  int8 i;  // si

  if (player_status >= 2u) {
    if ((buttons_a_b & 0x40) != 0 && (buttons_a_b_previous & buttons_a_b & 0x40) == 0 && !fireball_state[fireball_counter & 1] &&
        obj_ypos_hi.player == 1 && !crouching_flag && player_state != 3) {
      sound_ch3 = 6;
      fireball_state[fireball_counter & 1] = 2;
      fireball_throwing_timer = player_anim_timer_set;
      player_anim_timer = player_anim_timer_set - 1;
      ++fireball_counter;
    }
    Smbll_ProcessPlayerFireballs(0);
    Smbll_ProcessPlayerFireballs(1u);
  }
  if (!area_type) {
    for (i = 2; i >= 0; --i) {
      object_index = i;
      Smbll_BubbleCheck(i);
      Smbll_RelativeBubblePosition(i);
      Smbll_GetBubbleOffscreenBits(i);
      Smbll_DrawBubble(i);
    }
  }
}

void Smbll_ProcessPlayerFireballs(uint8 k) {
  uint8 v1;  // di
  bool v2;   // cf
  uint8 v3;  // si
  uint8 v4;  // si

  object_index = k;
  if (__CFSHL__(fireball_state[k], 1)) {
    Smbll_RelativeFireballPosition(k);
    Smbll_DrawExplodingPlayerFireball(k);
  } else {
    v1 = fireball_state[k];
    if (v1) {
      if (v1 != 1) {
        v2 = __CFADD__(obj_xpos_lo.player, 4);
        obj_xpos_lo.fireball[k] = obj_xpos_lo.player + 4;
        obj_xpos_hi.fireball[k] = v2 + obj_xpos_hi.player;
        obj_ypos_lo.fireball[k] = obj_ypos_lo.player;
        obj_ypos_hi.fireball[k] = 1;
        obj_xspeed.fireball[k] = kFireballXSpdData[(uint8)(player_facing_dir - 1)];
        obj_yspeed.fireball[k] = 4;
        fireball_hitbox_size_index[k] = 7;
        --fireball_state[k];
      }
      v3 = k + 11;
      R0_ = 80;
      R2_ = 3;
      Smbll_ImposeGravity(v3, 0);
      Smbll_MoveObjectHoriz(v3);
      v4 = object_index;
      Smbll_RelativeFireballPosition(object_index);
      Smbll_GetFireballOffscreenBits(v4);
      Smbll_GetFireballBoundBox(v4);
      Smbll_FireballBGCollision(v4);
      if ((offscreen_bits.fireball & 0xFC) == 0) {
        Smbll_FireballEnemyCollision(v4);
LABEL_13:
        Smbll_DrawFireball(v4);
        return;
      }
      if ((offscreen_bits.fireball & 0xF0) == 0) {
        if ((obj_xspeed.fireball[v4] & 0x80u) != 0) {
          if ((offscreen_bits.fireball & 0xC) != 12)
            goto LABEL_13;
        } else if ((offscreen_bits.fireball & 0xF) != 15) {
          goto LABEL_13;
        }
      }
      fireball_state[v4] = 0;
    }
  }
}

void Smbll_BubbleCheck(uint8 k) {
  R7_ = *(&random_byte2 + k) & 1;
  if (obj_ypos_lo.bubble[k] == 0xF8) {
    if (!air_bubble_timer)
      Smbll_SetupBubble(k);
  } else {
    Smbll_sub_B7F4(k);
  }
}

void Smbll_SetupBubble(uint8 k) {
  int8 v1;  // di
  bool v2;  // cf

  v1 = 0;
  if (player_facing_dir & 1)
    v1 = 8;
  v2 = __CFADD__(obj_xpos_lo.player, v1);
  obj_xpos_lo.bubble[k] = obj_xpos_lo.player + v1;
  obj_xpos_hi.bubble[k] = v2 + obj_xpos_hi.player;
  obj_ypos_lo.bubble[k] = obj_ypos_lo.player + 8;
  obj_ypos_hi.bubble[k] = 1;
  air_bubble_timer = kBubbleTimerData[R7_];
  Smbll_sub_B7F4(k);
}

void Smbll_sub_B7F4(uint8 k) {
  uint8 v1;  // al
  bool v2;   // cf
  uint8 v3;  // al

  v1 = obj_sub_ypos.bubble[k];
  v2 = v1 < kBubble_MForceData[R7_];
  obj_sub_ypos.bubble[k] = v1 - kBubble_MForceData[R7_];
  v3 = obj_ypos_lo.bubble[k] - v2;
  if (v3 < 0x20u)
    v3 = -8;
  obj_ypos_lo.bubble[k] = v3;
}

void Smbll_RunGameTimer() {
  if (game_mode && game_engine_subroutine >= 8u && game_engine_subroutine != 11 && sign8(obj_ypos_hi.player - 2) && !game_paused_timer) {
    if (level_timer_ones | (uint8)(level_timer_tens | level_timer_hundreds)) {
      if (level_timer_hundreds == 1 && !__PAIR16__(level_timer_ones, level_timer_tens))
        sound_ch1 = -1;
      game_paused_timer = 24;
      digit_modifier[5] = -1;
      if (!level_free_movement_debug_flag)
        Smbll_DigitsMathRoutine(0x23u);
      Smbll_PrintStatusBarNumbers(0xA4u);
    } else {
      player_status = 0;
      Smbll_ForceInjury(0);
      ++game_timer_expired_flag;
    }
  }
}

void Smbll_WarpZoneObject(uint8 k) {
  if (scroll_lock) {
    if ((obj_ypos_hi.player & obj_ypos_lo.player) == 0) {
      scroll_lock = 0;
      Smbll_EraseEnemyObject(k);
    }
  }
}

void Smbll_ProcessWhirlpools() {
  uint8 v0;  // di
  uint8 v1;  // al
  bool v2;   // cf
  uint8 v3;  // al

  if (!area_type) {
    cannon_timer[0] = area_type;
    Smbll_AdjustUnderwaterHDMAGradient();
    if (!timer_control) {
      v0 = 4;
      while (1) {
        R2_ = cannon_ypos_lo[v0] + cannon_xpos_lo[v0];
        if (cannon_xpos_hi[v0]) {
          R1_ = cannon_xpos_hi[v0];
          if ((int8)(obj_xpos_hi.player - ((obj_xpos_lo.player < cannon_xpos_lo[v0]) + cannon_xpos_hi[v0])) >= 0 &&
              (int8)(R1_ - ((R2_ < obj_xpos_lo.player) + obj_xpos_hi.player)) >= 0) {
            break;
          }
        }
        if ((--v0 & 0x80u) != 0)
          return;
      }
      R0_ = cannon_ypos_lo[v0] >> 1;
      v1 = cannon_xpos_lo[v0];
      R1_ = R0_ + v1;
      R0_ = __CFADD__(R0_, v1) + cannon_xpos_hi[v0];
      if (!(frame_counter & 1))
        goto LABEL_15;
      if ((int8)(R0_ - ((R1_ < obj_xpos_lo.player) + obj_xpos_hi.player)) >= 0) {
        if (!(player_collision_bits & 1)) {
LABEL_15:
          R0_ = 16;
          cannon_timer[0] = 1;
          R2_ = 1;
          Smbll_ImposeGravity(0, 0);
          return;
        }
        v2 = __CFADD__(obj_xpos_lo.player++, 1);
        v3 = v2 + obj_xpos_hi.player;
      } else {
        v2 = obj_xpos_lo.player-- != 0;
        v3 = obj_xpos_hi.player - !v2;
      }
      obj_xpos_hi.player = v3;
      goto LABEL_15;
    }
  }
}

void Smbll_FlagpoleRoutine() {
  uint8 v0;  // si
  uint8 v1;  // al
  bool v2;   // cf
  int8 v3;   // al
  int8 v4;   // al

  v0 = 5;
  object_index = 5;
  if (enemy_id[5] == 48) {
    if (game_engine_subroutine == 4 && player_state == 3) {
      if (obj_ypos_lo.enemy[5] >= 0xAAu || obj_ypos_lo.player >= 0xA2u) {
        if (flagpole_score == 5) {
          Smbll_GiveExtraLife();
          sound_ch3 = 5;
        } else {
          int t0 = kFlagpoleScoreDigits[flagpole_score];
          digit_modifier[t0] = kFlagpoleScoreMods[flagpole_score];
          Smbll_AddToScore();
        }
        game_engine_subroutine = 5;
        music_ch1 = 12;
        if ((player_facing_dir & 2) != 0)
          v4 = 96;
        else
          v4 = 110;
        LOBYTE(some_xpos16_var02fd) = v4;
        LOBYTE(flagpole_player_xpos16) = obj_xpos_lo.player;
        HIBYTE(flagpole_player_xpos16) = obj_xpos_hi.player;
        flagpole_timer_var03fb = 32;
        flagpole_timer_var03fa = 32;
      } else {
        v1 = obj_sub_ypos.enemy[5];
        v2 = __CFADD__(obj_ypos_lo.player >= 0xA2u, v1);
        v3 = (obj_ypos_lo.player >= 0xA2u) + v1;
        obj_sub_ypos.enemy[5] = v3 - 1;
        obj_ypos_lo.enemy[5] += (v2 || v3 != 0) + 1;
        v2 = flagpole_score_sub_ypos++ == 0xFFu;
        flagpole_score_ypos_lo -= !v2 + 1;
      }
    }
    Smbll_GetEnemyOffscreenBits(v0);
    Smbll_RelativeEnemyPosition(v0);
    Smbll_FlagpoleGfxHandler(v0);
  }
}

void Smbll_JumpspringHandler(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al

  Smbll_GetEnemyOffscreenBits(k);
  if (!timer_control && jumpspring_anim_ctrl) {
    v1 = jumpspring_anim_ctrl - 1;
    if (((jumpspring_anim_ctrl - 1) & 2) != 0) {
      --obj_ypos_lo.player;
      --obj_ypos_lo.player;
    } else {
      ++obj_ypos_lo.player;
      ++obj_ypos_lo.player;
    }
    obj_ypos_lo.enemy[k] = kJumpspring_Y_PosData[v1] + obj_xspeed.enemy[k];
    if (v1 && (buttons_a_b & 0x80u) != 0 && (buttons_a_b_previous & buttons_a_b & 0x80) == 0) {
      v2 = -12;
      if (world_number == 11 || world_number == 1 || world_number == 2 || world_number == 6)
        v2 = -32;
      jumpspring_force = v2;
    }
    if (v1 == 3) {
      obj_yspeed.player = jumpspring_force;
      jumpspring_anim_ctrl = 0;
      sound_ch3 = 8;
    }
  }
  Smbll_RelativeEnemyPosition(k);
  Smbll_EnemyGfxHandler_New(k);
  Smbll_OffscreenBoundsCheck(k);
  if (jumpspring_anim_ctrl) {
    if (!jumpspring_timer) {
      jumpspring_timer = 4;
      ++jumpspring_anim_ctrl;
    }
  }
}

void Smbll_Spr02F_Vine_Init(uint8 k, uint8 j) {
  uint8 v2;  // al

  enemy_id[k] = 47;
  enemy_flag[k] = 1;
  obj_xpos_hi.enemy[k] = obj_xpos_hi.block[j];
  obj_xpos_lo.enemy[k] = obj_xpos_lo.block[j];
  v2 = obj_ypos_lo.block[j];
  if (!v2)
    v2 = -16;
  obj_ypos_lo.enemy[k] = v2;
  if (!vine_flag_offset)
    vinestart_y_pos = v2;
  vine_obj_offset[vine_flag_offset++] = k;
  sound_ch3 = 3;
}

void Smbll_Spr02F_Vine_Init2(uint8 k) {
  Smbll_Spr02F_Vine_Init(k, 0);
}

void Smbll_VineObjectHandler(uint8 k) {
  int8 v1;   // al
  uint8 v2;  // di

  if (k == 9) {
    if (vine_at_entrance_flag)
      v1 = 96;
    else
      v1 = -112;
    if (v1 != vine_height && frame_counter & 1) {
      --obj_ypos_lo.enemy[9];
      ++vine_height;
    }
    if (vine_height >= 8u) {
      Smbll_RelativeEnemyPosition(9u);
      Smbll_GetEnemyOffscreenBits(9u);
      Smbll_DrawVine(0);
      if ((offscreen_bits.enemy & 0xF) == 15) {
        Smbll_EraseEnemyObject(9u);
        vine_flag_offset = 0;
        vine_height = 0;
      }
      Smbll_BlockBufferCollision(0xAu, 0x1Bu, 1u);
      v2 = R2_;
      if (R2_ < 0xD0u && (vine_at_entrance_flag || (R2_ & 0x80u) == 0)) {
        while (!RomPtr_RAM(*(uint16 *)&R6_)[v2]) {
          RomPtr_RAM(*(uint16 *)&R6_)[v2] = 47;
          if ((v2 & 0x80u) != 0 || v2 == 16 || (int8)(v2 - 16) < 0)
            break;
          v2 -= 16;
        }
      }
    }
  }
}

void Smbll_ProcessCannons() {
  uint8 v0;  // si
  uint8 v1;  // di
  uint8 v2;  // al

  if (area_type) {
    v0 = 2;
    while (1) {
      object_index = v0;
      if (enemy_flag[v0])
        goto LABEL_10;
      if ((uint8)(kCannonBitmasks[secondary_hard_mode] & *(&random_byte2 + v0)) >= 6u)
        goto LABEL_10;
      v1 = kCannonBitmasks[secondary_hard_mode] & *(&random_byte2 + v0);
      if (!cannon_xpos_hi[v1])
        goto LABEL_10;
      v2 = cannon_timer[v1];
      if (v2)
        break;
      if (timer_control)
        goto LABEL_10;
      cannon_timer[v1] = 14;
      obj_xpos_hi.enemy[v0] = cannon_xpos_hi[v1];
      obj_xpos_lo.enemy[v0] = cannon_xpos_lo[v1];
      obj_ypos_lo.enemy[v0] = cannon_ypos_lo[v1] - 8;
      obj_ypos_hi.enemy[v0] = 1;
      enemy_flag[v0] = 1;
      enemy_state[v0] = 0;
      enemy_hitbox_ctrl[v0] = 9;
      enemy_id[v0] = 51;
LABEL_13:
      if ((--v0 & 0x80u) != 0)
        return;
    }
    cannon_timer[v1] = v2 - 1;
LABEL_10:
    if (enemy_id[v0] == 51) {
      Smbll_OffscreenBoundsCheck(v0);
      if (enemy_flag[v0]) {
        Smbll_GetEnemyOffscreenBits(v0);
        Smbll_BulletBillHandler(v0);
      }
    }
    goto LABEL_13;
  }
}

void Smbll_BulletBillHandler(uint8 k) {
  uint8 v1;  // di

  if (timer_control) {
LABEL_13:
    Smbll_GetEnemyOffscreenBits(k);
    Smbll_RelativeEnemyPosition(k);
    Smbll_GetEnemyBoundBox(k);
    Smbll_PlayerEnemyCollision(k);
    Smbll_EnemyGfxHandler_New(k);
    return;
  }
  if (!enemy_state[k]) {
    if ((offscreen_bits.enemy & 0xC) == 12)
      goto LABEL_14;
    v1 = 1;
    if ((Smbll_PlayerEnemyDiff(k) & 0x80u) == 0)
      v1 = 2;
    enemy_moving_dir[k] = v1;
    obj_xspeed.enemy[k] = kBulletBillXSpdData[(uint8)(v1 - 1)];
    if ((uint8)(R0_ + 40) < 0x50u)
      goto LABEL_14;
    enemy_state[k] = 1;
    enemy_frame_timer[k] = 10;
    sound_ch3 = 74;
    Smbll_BulletBillSfxHandler(k, 0x4Au);
  }
  if ((offscreen_bits.enemy & 0xF0) != 0xF0) {
    if ((enemy_state[k] & 0x20) != 0)
      Smbll_MoveD_EnemyVert(k);
    if (!var0E67) {
      Smbll_MoveEnemyHoriz(k);
      Smbll_BulletBill_MoveNew(k);
    }
    goto LABEL_13;
  }
LABEL_14:
  Smbll_EraseEnemyObject(k);
}

uint8 Smbll_SpawnThrownHammer(uint8 k) {
  uint8 v1;  // al

  v1 = random_byte2 & 7;
  if ((random_byte2 & 7) == 0)
    v1 = random_byte2 & 8;
  if (misc_state[v1] || enemy_flag[kHammerEnemyOfsData[v1]])
    return 0;
  hammer_enemy_offset[v1] = object_index;
  misc_state[v1] = -112;
  misc_boundboxctrl[v1] = 7;
  return 1;
}

void Smbll_ProcHammerObj(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // cl
  uint8 v3;  // si
  int8 v4;   // al
  bool v5;   // cf

  if (!timer_control) {
    v1 = hammer_enemy_offset[k];
    v2 = misc_state[k] & 0x7F;
    if (v2 == 2) {
      obj_yspeed.misc[k] = -2;
      enemy_state[v1] &= ~8u;
      k = object_index;
      obj_xspeed.misc[object_index] = kHammerXSpdData[(uint8)(enemy_moving_dir[v1] - 1)];
    } else if (v2 < 2u) {
      v3 = k + 17;
      R0_ = 16;
      R1_ = 15;
      R2_ = 4;
      Smbll_ImposeGravity(v3, 0);
      Smbll_MoveObjectHoriz(v3);
      k = object_index;
      Smbll_PlayerHammerCollision(object_index);
      goto LABEL_14;
    }
    if (--misc_state[k] == 0x81)
      sound_ch1 = 55;
    if (enemy_id[v1] == 45) {
      v4 = 8;
    } else if (enemy_moving_dir[v1] == 2) {
      v4 = 6;
    } else {
      v4 = 2;
    }
    v5 = __CFADD__(obj_xpos_lo.enemy[v1], v4);
    obj_xpos_lo.misc[k] = obj_xpos_lo.enemy[v1] + v4;
    obj_xpos_hi.misc[k] = v5 + obj_xpos_hi.enemy[v1];
    obj_ypos_lo.misc[k] = obj_ypos_lo.enemy[v1] - 10;
    obj_ypos_hi.misc[k] = 1;
  }
LABEL_14:
  Smbll_GetMiscOffscreenBits(k);
  Smbll_RelativeMiscPosition(k);
  Smbll_GetMiscBoundBox(k);
  Smbll_DrawHammer(k);
}

void Smbll_SetupJumpCoin(uint8 k) {
  uint8 EmptyMiscSlot;  // di

  EmptyMiscSlot = Smbll_FindEmptyMiscSlot();
  obj_xpos_hi.misc[EmptyMiscSlot] = block_xpos_hi2[k];
  obj_xpos_lo.misc[EmptyMiscSlot] = (16 * R6_) | 5;
  obj_ypos_lo.misc[EmptyMiscSlot] = R2_ + 32;
  Smbll_SetupCoinCommon(k, EmptyMiscSlot);
}

void Smbll_SetupCoinCommon(uint8 k, uint8 j) {
  obj_yspeed.misc[j] = -5;
  obj_ypos_hi.misc[j] = 1;
  misc_state[j] = 1;
  sound_ch3 = 1;
  object_index = k;
  Smbll_GiveOneCoin();
  ++coin_tally_for_1ups;
}

uint8 Smbll_FindEmptyMiscSlot() {
  uint8 result;  // di

  result = 8;
  while (misc_state[result]) {
    if (--result == 5) {
      result = 8;
      break;
    }
  }
  misc_slot_index = result;
  return result;
}

void Smbll_MiscObjectsCore() {
  uint8 i;   // si
  uint8 v1;  // al
  uint8 v2;  // al
  bool v3;   // cf

  for (i = 8; (i & 0x80u) == 0; --i) {
    object_index = i;
    v1 = misc_state[i];
    if (!v1)
      continue;
    if (__CFSHL__(v1, 1)) {
      Smbll_ProcHammerObj(i);
      continue;
    }
    if (misc_state[i] == 1) {
      R0_ = 80;
      R2_ = 6;
      R1_ = 3;
      Smbll_ImposeGravity(i + 17, 0);
      i = object_index;
      if (obj_yspeed.misc[object_index] == 5)
        ++misc_state[object_index];
    } else {
      ++misc_state[i];
      v2 = obj_xpos_lo.misc[i];
      v3 = __CFADD__(scroll_amount, v2);
      obj_xpos_lo.misc[i] = scroll_amount + v2;
      obj_xpos_hi.misc[i] += v3;
      if (misc_state[i] == 48) {
        misc_state[i] = 0;
        continue;
      }
    }
    if (!obj_yspeed.misc[i])
      Smbll_SpinningCoinSprite_Init(i);
    Smbll_RelativeMiscPosition(i);
    Smbll_GetMiscOffscreenBits(i);
    Smbll_GetMiscBoundBox(i);
    Smbll_DrawSpinningCoinSprite(i);
  }
}

void Smbll_GiveOneCoin() {
  digit_modifier[5] = 1;
  Smbll_DigitsMathRoutine(kbyte_BADB[0]);
  if (++player_coin_count == 100) {
    player_coin_count = 0;
    Smbll_GiveExtraLife();
    sound_ch3 = 5;
  }
  digit_modifier[4] = 2;
  Smbll_AddToScore();
}

void Smbll_AddToScore() {
  Smbll_DigitsMathRoutine(kScoreOffsets[0]);
  Smbll_GetSBNibbles();
}

void Smbll_GetSBNibbles() {
  Smbll_UpdateNumber(kStatusBarNybbles[0]);
}

void Smbll_UpdateNumber(uint8 a) {
  uint8 v1;  // al

  Smbll_PrintStatusBarNumbers(a);
  if (!DUMMY_byte_7E16F4[vram_buffer1[0] + 2]) {
    v1 = 40;
    if (*(&DUMMY_byte_7E16F2 + vram_buffer1[0]) == 2)
      v1 = 36;
    DUMMY_byte_7E16F4[vram_buffer1[0] + 2] = v1;
  }
}

void Smbll_Spr02E_Powerup_Init(uint8 k) {
  uint8 v1;  // al

  enemy_state[9] = 1;
  enemy_flag[9] = 1;
  enemy_hitbox_ctrl[9] = 3;
  if (power_up_type < 2u) {
    v1 = player_status;
    if (player_status >= 2u)
      v1 = player_status >> 1;
    power_up_type = v1;
  }
  enemy_sprattrib[9] = 48;
  sound_ch3 = 2;
}

void Smbll_PowerUpObjHandler(uint8 k) {
  uint8 v0;  // al

  object_index = 9;
  if (enemy_state[9]) {
    if (__CFSHL__(enemy_state[9], 1)) {
      if (!timer_control) {
        if (!power_up_type || power_up_type == 3 || power_up_type == 4 || power_up_type == 5) {
          Smbll_MoveNormalEnemy(9u);
          Smbll_EnemyToBGCollisionDet(9u);
        } else if (power_up_type == 2) {
          Smbll_MoveJumpingEnemy(9u);
          Smbll_EnemyJump(9u);
        }
      }
LABEL_15:
      Smbll_RelativeEnemyPosition(9u);
      Smbll_GetEnemyOffscreenBits(9u);
      Smbll_GetEnemyBoundBox(9u);
      Smbll_DrawPowerUp();
      Smbll_PlayerEnemyCollision(9u);
      Smbll_OffscreenBoundsCheck(9u);
      return;
    }
    if ((frame_counter & 3) == 0) {
      --obj_ypos_lo.enemy[9];
      v0 = enemy_state[9]++;
      if (v0 >= 0x11u) {
        obj_xspeed.enemy[9] = 16;
        enemy_state[9] = 0x80;
        enemy_sprattrib[9] = 0;
        enemy_moving_dir[9] = __CFSHL__(0x80, 1);
      }
    }
    if (enemy_state[9] >= 6u)
      goto LABEL_15;
  }
}

void Smbll_PlayerHeadCollision(uint8 a) {
  uint8 v1;  // al
  uint8 v2;  // si
  uint8 v3;  // al
  int v4;    // edx
  uint8 v5;  // al
  uint8 v6;  // di
  uint8 v7;  // di
  uint8 t;

  v1 = 17;
  if (!player_size)
    v1 = 18;
  block_state[spr_data_offset_ctrl] = v1;
  Smbll_DestroyBlockMetatile();
  v2 = spr_data_offset_ctrl;
  v3 = R2_;
  v4 = spr_data_offset_ctrl;
  block_orig_ypos[spr_data_offset_ctrl] = R2_;
  block_bbuf_low[v4] = R6_;
  v5 = RomPtr_RAM(*(uint16 *)&R6_)[v3];
  t = Smbll_BlockBumpedChk(v5);
  R0_ = v5;
  if (!player_size)
    v5 = player_size;
  if (t != 0xff) {
    block_state[v2] = 17;
    v5 = -3;
    v6 = R0_;
    if (R0_ == 84 || R0_ == 90) {
      if (!brick_coin_timer_flag[0]) {
        brick_coin_timer = 11;
        ++brick_coin_timer_flag[0];
      }
      if (!brick_coin_timer)
        v6 = -3;
      v5 = v6;
    }
  }
  block_metatile[v2] = v5;
  Smbll_InitBlock_XY_Pos(v2);
  RomPtr_RAM(*(uint16 *)&R6_)[R2_] = 44;
  block_bounce_timer = 16;
  R5_ = a;
  v7 = 0;
  if (crouching_flag || player_size)
    v7 = 1;
  obj_ypos_lo.block[v2] = (kbyte_BC29[v7] + obj_ypos_lo.player) & 0xF0;
  if (block_state[v2] == 17)
    Smbll_BumpBlock();
  else
    Smbll_BrickShatter();
  spr_data_offset_ctrl ^= 1u;
}

void Smbll_InitBlock_XY_Pos(uint8 k) {
  uint t = PAIR16(obj_xpos_hi.player, obj_xpos_lo.player) + 8;
  obj_xpos_lo.block[k] = t & ~0xf;
  LOBYTE(xpos_new_var0E16) = t & ~0xf;
  obj_xpos_hi.block[k] = t >> 8;
  block_xpos_hi2[k] = t >> 8;
  HIBYTE(xpos_new_var0E16) = t >> 8;
  obj_ypos_hi.block[k] = obj_ypos_hi.player;
}

void Smbll_BumpBlock() {
  uint8 v0;             // si
  uint8 v1;             // di
  uint8 v2;             // al
  uint8 v3;             // al
  uint8 EmptyMiscSlot;  // di

  v0 = Smbll_CheckTopOfBlock();
  sound_ch1 = 1;
  obj_xspeed.block[v0] = 0;
  obj_sub_yspeed.block[v0] = 0;
  obj_yspeed.player = 0;
  obj_yspeed.block[v0] = -2;
  v1 = Smbll_BlockBumpedChk(R5_);
  if (v1 != 0xff) {
    v2 = v1;
    if (v1 >= 0xDu)
      v2 = v1 - 6;
    R4_ = *((uint8 *)koff_BD15 + (uint8)(2 * v2));
    R5_ = *((uint8 *)koff_BD15 + (uint8)(2 * v2) + 1);
    switch ((uint8)(2 * v2) >> 1) {
    case 0:
    case 6:
    case 7: v3 = 0; goto LABEL_9;
    case 1:
    case 5:
    case 8: v3 = 4; goto LABEL_9;
    case 2:
    case 3:
    case 11:
      EmptyMiscSlot = Smbll_FindEmptyMiscSlot();
      obj_xpos_hi.misc[EmptyMiscSlot] = obj_xpos_hi.block[v0];
      obj_xpos_lo.misc[EmptyMiscSlot] = obj_xpos_lo.block[v0] | 5;
      obj_ypos_lo.misc[EmptyMiscSlot] = obj_ypos_lo.block[v0] - 16;
      Smbll_SetupCoinCommon(v0, EmptyMiscSlot);
      return;
    case 4:
    case 12: v3 = 3; goto LABEL_9;
    case 9:
    case 13: Smbll_Spr02F_Vine_Init(9u, spr_data_offset_ctrl); return;
    case 10:
    case 14:
      v3 = 2;
LABEL_9:
      power_up_type = v3;
      enemy_id[9] = 46;
      obj_xpos_hi.enemy[9] = obj_xpos_hi.block[v0];
      obj_xpos_lo.enemy[9] = obj_xpos_lo.block[v0];
      obj_ypos_hi.enemy[9] = 1;
      obj_ypos_lo.enemy[9] = obj_ypos_lo.block[v0] - 8;
      Smbll_Spr02E_Powerup_Init(v0);
      break;
    }
  }
}

uint8 Smbll_BlockBumpedChk(uint8 a) {
  uint8 result;  // di

  for (result = 20; (result & 0x80u) == 0; --result) {
    if (a == kBrickQBlockMetatiles[result])
      break;
  }
  return result;
}

void Smbll_BrickShatter() {
  uint8 v0;  // si

  v0 = Smbll_CheckTopOfBlock();
  block_repflag[v0] = 1;
  if (!sound_ch3)
    sound_ch3 = 7;
  Smbll_SpawnBrickChunks(v0);
  obj_yspeed.player = -2;
  digit_modifier[5] = 5;
  Smbll_AddToScore();
}

uint8 Smbll_CheckTopOfBlock() {
  uint8 result;  // si
  uint8 v1;      // di
  uint8 v2;      // di

  result = spr_data_offset_ctrl;
  v1 = R2_;
  if (R2_) {
    R2_ -= 16;
    v2 = v1 - 16;
    if (RomPtr_RAM(*(uint16 *)&R6_)[v2] == 0xEA) {
      RomPtr_RAM(*(uint16 *)&R6_)[v2] = 0;
      sound_ch3 = 1;
      Smbll_RemoveCoin_Axe();
      result = spr_data_offset_ctrl;
      Smbll_SetupJumpCoin(spr_data_offset_ctrl);
    }
  }
  return result;
}

void Smbll_SpawnBrickChunks(uint8 k) {
  block_orig_xpos_lo[k] = obj_xpos_lo.block[k];
  obj_xspeed.block[k] = -16;
  obj_xspeed.misc[k - 2] = -16;
  obj_yspeed.block[k] = -6;
  obj_yspeed.misc[k - 2] = -4;
  obj_sub_yspeed.block[k] = 0;
  obj_sub_yspeed.misc[k - 2] = 0;
  obj_xpos_hi.misc[k - 2] = obj_xpos_hi.block[k];
  obj_xpos_lo.misc[k - 2] = obj_xpos_lo.block[k];
  obj_ypos_lo.misc[k - 2] = obj_ypos_lo.block[k] + 8;
  obj_yspeed.block[k] = -6;
}

void Smbll_BlockObjectsCore(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // si
  uint8 v3;  // si
  uint8 v4;  // si

  v1 = block_state[k];
  if (v1) {
    v2 = k + 13;
    if ((v1 & 0xF) == 1) {
      Smbll_ImposeGravityBlock(v2);
      v4 = object_index;
      Smbll_RelativeBlockPosition(object_index);
      Smbll_GetBlockOffscreenBits(v4);
      Smbll_DrawBlock(v4);
      block_state[v4] = 1;
      if ((obj_ypos_lo.block[v4] & 0xFu) >= 5)
        return;
      block_repflag[v4] = 1;
      goto LABEL_10;
    }
    Smbll_ImposeGravityBlock(v2);
    Smbll_MoveObjectHoriz(v2);
    v3 = v2 + 2;
    Smbll_ImposeGravityBlock(v3);
    Smbll_MoveObjectHoriz(v3);
    v4 = object_index;
    Smbll_RelativeBlockPosition(object_index);
    Smbll_GetBlockOffscreenBits(v4);
    Smbll_DrawBrickChunks(v4);
    if (obj_ypos_hi.block[v4]) {
      if (obj_ypos_lo.misc[v4 - 2] > 0xF0u)
        obj_ypos_lo.misc[v4 - 2] = -16;
      if (obj_ypos_lo.block[v4] >= 0xF0u)
LABEL_10:
        block_state[v4] = 0;
    }
  }
}

void Smbll_BlockObjMT_Updater() {
  uint8 i;   // si
  uint8 v1;  // al

  for (i = 1; (i & 0x80u) == 0; --i) {
    object_index = i;
    if (block_repflag[i]) {
      R6_ = block_bbuf_low[i];
      R7_ = 5;
      R2_ = block_orig_ypos[i];
      v1 = block_metatile[i];
      RomPtr_RAM(*(uint16 *)&R6_)[R2_] = v1;
      Smbll_ReplaceBlockMetatile(i, v1);
      block_repflag[i] = 0;
    }
  }
}

uint8 Smbll_MoveEnemyHoriz(uint8 k) {
  return Smbll_MoveObjectHoriz(k + 1);
}

uint8 Smbll_MovePlayerHoriz() {
  uint8 result;  // al

  result = jumpspring_anim_ctrl;
  if (!jumpspring_anim_ctrl)
    return Smbll_MoveObjectHoriz(jumpspring_anim_ctrl);
  return result;
}

uint8 Smbll_MoveObjectHoriz(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di
  int8 v3;   // al
  bool v4;   // cf
  bool v5;   // cl
  int8 v6;   // al
  int8 v7;   // al

  R1_ = 16 * *(&obj_xspeed.player + k);
  v1 = *(&obj_xspeed.player + k) >> 4;
  if (v1 >= 8u)
    v1 |= 0xF0u;
  R0_ = v1;
  UNUSED_byte_7E0EB6 = v1;
  v2 = 0;
  if (sign8(v1))
    v2 = -1;
  R2_ = v2;
  v3 = *(&obj_xpos_fract.player + k);
  v4 = __CFADD__(R1_, v3);
  *(&obj_xpos_fract.player + k) = R1_ + v3;
  v5 = v4;
  v6 = *(&obj_xpos_lo.player + k);
  v4 = __CFADD__(v4, v6);
  v7 = v5 + v6;
  v4 |= __CFADD__(R0_, v7);
  *(&obj_xpos_lo.player + k) = R0_ + v7;
  *(&obj_xpos_hi.player + k) += R2_ + v4;
  return R0_ + v5;
}

void Smbll_MovePlayerVert() {
  if (timer_control || !jumpspring_anim_ctrl) {
    R0_ = vertical_force;
    Smbll_ImposeGravitySpr(0, 4u);
  }
}

void Smbll_MoveD_EnemyVert(uint8 k) {
  if (enemy_state[k] == 5)
    Smbll_MoveFallingPlatform(k);
  else
    Smbll_sub_C17F(k, 0x3Du);
}

void Smbll_MoveFallingPlatform(uint8 k) {
  Smbll_sub_C17F(k, 0x20u);
}

void Smbll_MoveRedPTroopaDown(uint8 k) {
  Smbll_MoveRedPTroopa(k, 0);
}

void Smbll_MoveRedPTroopaUp(uint8 k) {
  Smbll_MoveRedPTroopa(k, 1u);
}

void Smbll_MoveRedPTroopa(uint8 k, uint8 j) {
  R0_ = 3;
  R1_ = 6;
  R2_ = 2;
  Smbll_RedPTroopaGrav(k + 1, j);
}

void Smbll_MoveDropPlatform(uint8 k) {
  Smbll_sub_C179(k, 0x7Fu);
}

void Smbll_MoveEnemySlowVert(uint8 k) {
  Smbll_sub_C179(k, 0xFu);
}

void Smbll_sub_C179(uint8 k, uint8 j) {
  Smbll_SetXMoveAmt(k, j, 2u);
}

void Smbll_MoveJ_EnemyVert(uint8 k) {
  Smbll_sub_C17F(k, 0x1Cu);
}

void Smbll_sub_C17F(uint8 k, uint8 j) {
  Smbll_SetXMoveAmt(k, j, 3u);
}

void Smbll_SetXMoveAmt(uint8 k, uint8 j, uint8 a) {
  R0_ = j;
  Smbll_ImposeGravitySpr(k + 1, a);
}

void Smbll_sub_C18C(uint8 k) {
  Smbll_ImposeGravityBlock(k);
}

void Smbll_ImposeGravityBlock(uint8 k) {
  R0_ = 80;
  Smbll_ImposeGravitySpr(k, kMaxSpdBlockData[1]);
}

void Smbll_ImposeGravitySpr(uint8 k, uint8 a) {
  R2_ = a;
  Smbll_ImposeGravity(k, 0);
}

void Smbll_MovePlatformDown(uint8 k) {
  Smbll_MovePlatformCommon(k, 0);
}

void Smbll_MovePlatformUp(uint8 k) {
  Smbll_MovePlatformCommon(k, 1u);
}

void Smbll_MovePlatformCommon(uint8 k, uint8 a) {
  uint8 v2;  // di
  uint8 v3;  // si
  uint8 v4;  // al

  v2 = enemy_id[k];
  v3 = k + 1;
  v4 = 5;
  if (v2 == 41)
    v4 = 9;
  R0_ = v4;
  R1_ = 10;
  R2_ = 3;
  Smbll_RedPTroopaGrav(v3, a);
}

void Smbll_RedPTroopaGrav(uint8 k, uint8 a) {
  Smbll_ImposeGravity(k, a);
}

void Smbll_ImposeGravity_Far(uint8 k, uint8 a) {
  Smbll_ImposeGravity(k, a);
}

void Smbll_ImposeGravity(uint8 k, uint8 a) {
  bool v4;   // cf
  int8 v5;   // al
  uint8 v6;  // al
  uint8 v7;  // al
  uint8 v8;  // al

  uint16 t = *(&obj_sub_ypos.player + k) + *(&obj_sub_yspeed.player + k);
  *(&obj_sub_ypos.player + k) = t;
  AddHiLo((&obj_ypos_hi.player + k), (&obj_ypos_lo.player + k), (int8) * (&obj_yspeed.player + k) + (t >> 8));

  v5 = *(&obj_sub_yspeed.player + k);
  v4 = __CFADD__(R0_, v5);
  *(&obj_sub_yspeed.player + k) = R0_ + v5;
  v6 = v4 + *(&obj_yspeed.player + k);
  *(&obj_yspeed.player + k) = v6;
  if (!sign8(v6 - R2_) && *(&obj_sub_yspeed.player + k) >= 0x80u) {
    *(&obj_yspeed.player + k) = R2_;
    *(&obj_sub_yspeed.player + k) = 0;
  }
  if (a) {
    R7_ = -R2_;
    v7 = *(&obj_sub_yspeed.player + k);
    v4 = v7 < R1_;
    *(&obj_sub_yspeed.player + k) = v7 - R1_;
    v8 = *(&obj_yspeed.player + k) - v4;
    *(&obj_yspeed.player + k) = v8;
    if (sign8(v8 - R7_)) {
      if (*(&obj_sub_yspeed.player + k) < 0x80u) {
        *(&obj_yspeed.player + k) = R7_;
        *(&obj_sub_yspeed.player + k) = -1;
      }
    }
  }
}

void Smbll_BulletBill_MoveNew(uint8 k) {
  int16 v1;     // ax
  uint8 v2;     // di
  OamEnt *oam;  // rbp
  uint8 v4;     // si
  int16 v5;     // [rsp+46h] [rbp-2h]

  if (bullet_bill_arr0E9D[k]) {
    if (++bullet_bill_arr0EA2[k] >> 3 == 3) {
      bullet_bill_arr0E9D[k] = 0;
      tempE8 = 8 * k;
      v4 = 24 * k;
      get_OamEnt(oam_buf, v4)[64].ypos = -16;
      oam_tile_size_buffer[v4 + 256] = 0;
    } else {
      tempE4 = 2 * (bullet_bill_arr0EA2[k] >> 3) + 64;
      tempE5 = bullet_bill_arr0EAC[k];
      tempE6 = bullet_bill_arr0EA7[k];
      v5 = *(uint16 *)&tempE5 - screen_left_xpos16;
      if (*(int16 *)&bullet_bill_arr0EB1[4] < 0)
        v1 = v5 - 12;
      else
        v1 = v5 + 12;
      *(uint16 *)&tempE5 = v1;
      v2 = enemy_obj_id[k];
      oam = get_OamEnt(oam_buf, v2);
      oam[64].xpos = v1;
      oam[64].ypos = bullet_bill_arr0EB1[k];
      oam[64].charnum = tempE4;
      oam[64].flags = 45;
      oam_tile_size_buffer[v2 + 256] = 2;
      if (tempE6)
        oam_tile_size_buffer[v2 + 256] = 3;
    }
  }
}

void Smbll_BulletBillSfxHandler(uint8 k, uint8 a) {
  bullet_bill_arr0E9D[k] = a;
  bullet_bill_arr0EA2[k] = 0;
  bullet_bill_arr0EAC[k] = obj_xpos_lo.enemy[k];
  bullet_bill_arr0EA7[k] = obj_xpos_hi.enemy[k];
  bullet_bill_arr0EB1[k] = obj_ypos_lo.enemy[k] + 8;
}

void Smbll_HandleScreenTransition() {
  if (fade_direction & 1) {
    if ((inidisp_mirror & 0x80u) == 0) {
      if (--inidisp_mirror)
        goto LABEL_12;
      WriteReg(INIDISP, 0x80u);
      inidisp_mirror = 0x80;
      WriteReg(HDMAEN, 0);
      hdmaenable_mirror = 0;
      pause_menu_idx = 0;
      cutscene_var1680 = 0;
      Smbll_Dma_FillWith0x24();
      Smbll_ClearAllOams();
      Smbll_CODE_03C36E();
    }
    fade_direction = 0;
    disable_screen_flag = 1;
  } else {
    if (!override_player_xpos2_flag && !override_player_xpos_flag) {
      override_player_xpos_flag = 1;
      Smbll_GameMode01_Level_GameCoreRoutine();
    }
    var0E67 = 0;
    if (inidisp_mirror == 15 || (++inidisp_mirror, inidisp_mirror == 15)) {
      fade_direction = 0;
      disable_screen_flag = 0;
      override_player_xpos_flag = 0;
    }
  }
LABEL_12:
  if (enable_mosaic_fades_flag) {
    Smbll_ClearAllOams();
    mosaic_mirror = (16 * (inidisp_mirror ^ 0xF)) | 0xF;
    Smbll_CODE_03C35C();
    if (inidisp_mirror == 15)
      enable_mosaic_fades_flag = 0;
  }
}

void Smbll_ClearAllOams() {
  uint8 v0;     // si
  OamEnt *oam;  // rbp

  v0 = 0;
  do {
    oam = get_OamEnt(oam_buf, v0);
    oam->ypos = -16;
    oam[64].ypos = -16;
    oam_tile_size_buffer[v0] = 0;
    oam_tile_size_buffer[v0 + 256] = 0;
    v0 += 4;
  } while (v0);
}

void Smbll_CODE_03C35C() {
  uint8 i;  // di

  for (i = -48; i != 0xF0; i += 4)
    get_OamEnt(oam_buf, i)->ypos = -16;
}

void Smbll_CODE_03C36E() {
  Smbll_UploadSpriteGFX();
  cutscene_var0BA5 = 0;
  game_over_screen_blinking_cursor_pos = 0;
  cutscene_0EC4 = 0;
  if (world_number == 7 || world_number == 12)
    cutscene_0EC4 = 1;
  vblank_which_layer2_scroll_flag = 0;
  turn_around_smoke_flag = 0;
  turn_around_smoke_flag2 = 0;
  turn_around_smoke_bits[0] = 0;
  enable_layer3_bgflag = 0;
  render_area_gfx_0ECE = 1;
  if (override_player_xpos2_flag) {
    override_player_xpos2_flag = 0;
  } else {
    rel_ypos.player = obj_ypos_lo.player;
    rel_xpos_lo.player = obj_xpos_lo.player;
  }
  override_player_xpos_flag = 0;
}

void Smbll_EnemiesAndLoopsCore(uint8 k) {
  uint8 v1;   // di
  uint8 v2;   // di
  uint8 *v3;  // rdx
  int8 v4;    // di
  uint8 v5;   // di
  uint8 v6;   // al
  uint8 v7;   // al
  uint8 v8;   // di
  uint8 *v9;  // rdx
  uint8 v10;  // al
  uint8 v11;  // al
  uint8 v12;  // di
  uint8 v14;  // di

  if ((enemy_flag[k] & 0x80u) != 0) {
    if (!enemy_flag[enemy_flag[k] & 0xF])
      enemy_flag[k] = 0;
  } else {
    if (enemy_flag[k]) {
      Smbll_RunEnemyObjectsCore();
      return;
    }
    if ((area_parser_task_num & 7) != 7) {
      while (1) {
        if (loop_command && !current_column_pos_lo) {
          v1 = 12;
          while ((--v1 & 0x80u) == 0) {
            if (world_number == kLoopCmdWorldNumber[v1] && column_pos_hi == kLoopCmdPageNumber[v1]) {
              if (obj_ypos_lo.player != kLoopCmdYPosition[v1] || player_state) {
                if (!var0EDB) {
                  sound_ch3 = 42;
                  var0EDB = 42;
                }
              } else {
                ++multi_loop_correct_cntr;
                if (!var0EDB)
                  sound_ch3 = 41;
              }
              if (++multi_loop_pass_cntr == kbyte_C253[v1]) {
                if (multi_loop_correct_cntr != kbyte_C253[v1]) {
                  Smbll_ExecGameLoopback(v1);
                  Smbll_KillAllEnemies();
                }
                multi_loop_pass_cntr = 0;
                multi_loop_correct_cntr = 0;
              }
              loop_command = 0;
              break;
            }
          }
        }
        if (enemy_frenzy_queue) {
          enemy_id[k] = enemy_frenzy_queue;
          enemy_flag[k] = 1;
          enemy_state[k] = 0;
          enemy_frenzy_queue = 0;
          Smbll_InitEnemyObject(k);
          return;
        }
        v2 = enemy_data_offset2;
        v3 = IndirPtr(&enemy_data_ptr, enemy_data_offset2);
        if (*v3 == 0xFF)
          goto LABEL_56;
        if ((*v3 & 0xF) != 14 && k >= 5u && (*IndirPtr(&enemy_data_ptr, (uint8)(v2 + 1)) & 0x3F) != 46)
          return;
        uint16 t;
        t = PAIR16(screen_right_xpos_hi, screen_right_xpos) + 48;
        R7_ = t & 0xF0;
        R6_ = t >> 8;
        v4 = enemy_data_offset2 + 1;
        if (__CFSHL__(*IndirPtr(&enemy_data_ptr, (uint8)(enemy_data_offset2 + 1)), 1) && !enemy_object_page_sel) {
          ++enemy_object_page_sel;
          ++enemy_object_page_loc;
        }
        v5 = v4 - 1;
        if ((*IndirPtr(&enemy_data_ptr, v5) & 0xF) != 15 || enemy_object_page_sel)
          break;
        enemy_object_page_loc = *IndirPtr(&enemy_data_ptr, (uint8)(v5 + 1)) & 0x3F;
        ++enemy_data_offset2;
        ++enemy_data_offset2;
        ++enemy_object_page_sel;
      }
      obj_xpos_hi.enemy[k] = enemy_object_page_loc;
      v6 = *IndirPtr(&enemy_data_ptr, v5) & 0xF0;
      obj_xpos_lo.enemy[k] = v6;
      if (obj_xpos_hi.enemy[k] < ((v6 < screen_right_xpos) + screen_right_xpos_hi)) {
        if ((*IndirPtr(&enemy_data_ptr, v5) & 0xF) != 14) {
          if ((*IndirPtr(&enemy_data_ptr, enemy_data_offset2) & 0xF) != 14) {
LABEL_69:
            ++enemy_data_offset2;
            ++enemy_data_offset2;
            enemy_object_page_sel = 0;
            return;
          }
LABEL_68:
          ++enemy_data_offset2;
          goto LABEL_69;
        }
LABEL_63:
        v12 = v5 + 2;
        if (world_number == 8 || (Smbll_sub_C462(*IndirPtr(&enemy_data_ptr, v12)) == world_number)) {
          v14 = v12 - 1;
          area_pointer = *IndirPtr(&enemy_data_ptr, v14);
          entrance_page = *IndirPtr(&enemy_data_ptr, (uint8)(v14 + 1)) & 0x1F;
        }
        goto LABEL_68;
      }
      if (R6_ < ((R7_ < obj_xpos_lo.enemy[k]) + obj_xpos_hi.enemy[k])) {
LABEL_56:
        v11 = enemy_frenzy_buffer;
        if (!enemy_frenzy_buffer) {
          if (vine_flag_offset != 1)
            return;
          v11 = 0;
        }
        if (k == 9) {
          Smbll_InitEnemyObject(9u);
        } else {
          enemy_id[k] = v11;
          Smbll_InitEnemyObject(k);
        }
      } else {
        obj_ypos_hi.enemy[k] = 1;
        v7 = 16 * *IndirPtr(&enemy_data_ptr, v5);
        obj_ypos_lo.enemy[k] = v7;
        if (v7 == 0xE0)
          goto LABEL_63;
        v8 = v5 + 1;
        if ((*IndirPtr(&enemy_data_ptr, v8) & 0x40) != 0 && !secondary_hard_mode)
          goto LABEL_69;
        v9 = IndirPtr(&enemy_data_ptr, v8);
        v10 = *v9 & 0x3F;
        if (v10 >= 0x37u && (*v9 & 0x3F) != 63) {
          Smbll_HandleGroupEnemies(v10);
          return;
        }
        if (v10 == 6 && primary_hard_mode)
          v10 = 2;
        if (v10 == 45)
          Smbll_ClearBowserVar0F4();
        if (v10 == 53)
          level_preview_sprites_ctr = 0;
        enemy_id[k] = v10;
        enemy_flag[k] = 1;
        Smbll_InitEnemyObject(k);
        if (enemy_flag[k])
          goto LABEL_69;
      }
    }
  }
}

void Smbll_ExecGameLoopback(uint8 j) {
  obj_xpos_hi.player -= 4;
  column_pos_hi -= 4;
  screen_left_xpos_hi -= 4;
  screen_right_xpos_hi -= 4;
  area_object_page_loc -= 4;
  enemy_object_page_sel = 0;
  area_object_page_sel = 0;
  enemy_data_offset2 = 0;
  enemy_object_page_loc = 0;
  LOBYTE(area_data_offset) = kAreaDataOfsLoopback[j];
  var0EDB = 0;
}

void Smbll_InitEnemyObject(uint8 k) {
  enemy_state[k] = 0;
  Smbll_CheckpointEnemyID(k);
}

uint8 Smbll_sub_C462(uint8 a) {
  uint8 v2;  // [rsp+47h] [rbp-1h]

  v2 = a >> 5;
  if (title_screen_hard_mode_flag)
    v2 += 9;
  return v2;
}

void Smbll_CheckpointEnemyID(uint8 k) {
  uint8 v1;  // al

  v1 = enemy_id[k];
  if (v1 < 0x15u) {
    obj_ypos_lo.enemy[k] += 8;
    spr_array_D[k] = 1;
  }
  R4_ = *((uint8 *)koff_C498 + (uint8)(2 * v1));
  R5_ = *((uint8 *)koff_C498 + (uint8)(2 * v1) + 1);
  ((void (*)(uint8, uint8))funcs_A417[(uint8)(2 * v1) >> 1])(k, 2 * v1);
}
// A41F: using guessed type int (*funcs_A417[55])();

void Smbll_NoEnemyInit(uint8 k) {
  ;
}

void Smbll_Goomba_Init(uint8 k) {
  Smbll_NormalEnemy_Init(k);
  Smbll_SmallBBox(k);
}

void Smbll_Podoboo_Init(uint8 k) {
  obj_ypos_lo.enemy[k] = -48;
  obj_ypos_hi.enemy[k] = 1;
  *(&enemy_interval_timer + k) = 1;
  enemy_state[k] = 0;
  podoboo_array_1[k] = 1;
  podoboo_array_2[k] = 0;
  sound_ch3 = 39;
  Smbll_SmallBBox(k);
}

void Smbll_RetainerObj_Init(uint8 k) {
  if (world_number == 7 || world_number == 12)
    obj_ypos_lo.enemy[k] = 112;
  else
    obj_ypos_lo.enemy[k] = -72;
}

void Smbll_NormalEnemy_Init(uint8 k) {
  obj_xspeed.enemy[k] = kNormalXSpdData[primary_hard_mode != 0];
  Smbll_SetBBox_3(k);
}

void Smbll_RedKoopa_Init(uint8 k) {
  Smbll_NormalEnemy_Init(k);
  enemy_state[k] = 1;
}

void Smbll_HammerBro_Init(uint8 k) {
  enemy_data_d[k] = 0;
  obj_xspeed.enemy[k] = 0;
  if (world_number < 6u)
    *(&enemy_interval_timer + k) = kHBroWalkingTimerData[secondary_hard_mode];
  enemy_hitbox_ctrl[k] = 11;
  enemy_moving_dir[k] = 2;
  Smbll_InitVStf(k);
}

void Smbll_InitHorizFlySwimEnemy(uint8 k) {
  obj_xspeed.enemy[k] = 0;
  Smbll_SetBBox_3(k);
}

void Smbll_Blooper_Init(uint8 k) {
  obj_xspeed.enemy[k] = 0;
  Smbll_SmallBBox(k);
}

void Smbll_SmallBBox(uint8 k) {
  enemy_hitbox_ctrl[k] = 9;
  enemy_moving_dir[k] = 2;
  Smbll_InitVStf(k);
}

void Smbll_RedPTroopa_Init(uint8 k) {
  int8 v1;  // di
  int8 v2;  // al

  v1 = 48;
  v2 = obj_ypos_lo.enemy[k];
  obj_xpos_fract.enemy[k] = v2;
  if (v2 < 0)
    v1 = -32;
  obj_xspeed.enemy[k] = obj_ypos_lo.enemy[k] + v1;
  Smbll_SetBBox_3(k);
}

void Smbll_SetBBox_3(uint8 k) {
  enemy_hitbox_ctrl[k] = 3;
  enemy_moving_dir[k] = 2;
  Smbll_InitVStf(k);
}

void Smbll_InitVStf(uint8 k) {
  obj_yspeed.enemy[k] = 0;
  obj_sub_yspeed.enemy[k] = 0;
}

void Smbll_BulletBill_Init(uint8 k) {
  enemy_moving_dir[k] = 2;
  enemy_hitbox_ctrl[k] = 9;
}

void Smbll_CheepCheep_Init(uint8 k) {
  Smbll_SmallBBox(k);
  obj_xspeed.enemy[k] = *(&random_byte1 + k) & 0x10;
  obj_sub_yspeed.enemy[k] = obj_ypos_lo.enemy[k];
}

void Smbll_Lakitu_Init(uint8 k) {
  if (enemy_frenzy_buffer)
    Smbll_EraseEnemyObject(k);
  else
    Smbll_SetupLakitu(k);
}

void Smbll_SetupLakitu(uint8 k) {
  lakitu_reappear_timer = 0;
  Smbll_InitHorizFlySwimEnemy(k);
  Smbll_TallBBox2(k);
}

void Smbll_LakituAndSpinyHandler(uint8 k) {
  uint8 i;   // di
  uint8 v2;  // si
  uint8 v3;  // al

  if (!frenzy_enemy_timer && k < 9u) {
    frenzy_enemy_timer = 0x80;
    for (i = 8; (i & 0x80u) == 0; --i) {
      if (enemy_id[i] == 17) {
        Smbll_CreateSpiny(k, i);
        return;
      }
    }
    if (++lakitu_reappear_timer >= 3u) {
      v2 = 8;
      while (enemy_flag[v2]) {
        if ((--v2 & 0x80u) != 0)
          return;
      }
      enemy_state[v2] = 0;
      enemy_id[v2] = 17;
      Smbll_SetupLakitu(v2);
      v3 = 32;
      if (title_screen_hard_mode_flag || world_number >= 6u)
        v3 = 96;
      Smbll_PutAtRightExtent(v2, v3);
    }
  }
}
// A9BC: conditional instruction was optimized away because si.1<0

void Smbll_CreateSpiny(uint8 k, uint8 j) {
  uint8 v2;  // di
  uint8 v3;  // si
  uint8 v4;  // di

  if (obj_ypos_lo.player >= 0x2Cu && !enemy_state[j]) {
    obj_xpos_hi.enemy[k] = obj_xpos_hi.enemy[j];
    obj_xpos_lo.enemy[k] = obj_xpos_lo.enemy[j];
    obj_ypos_hi.enemy[k] = 1;
    obj_ypos_lo.enemy[k] = obj_ypos_lo.enemy[j] - 8;
    v2 = *(&random_byte1 + k) & 3;
    R3_ = kPRDiffAdjustData[v2];
    R2_ = kPRDiffAdjustData[v2 + 4];
    R1_ = kPRDiffAdjustData[v2 + 8];
    v3 = object_index;
    Smbll_PlayerLakituDiff(object_index);
    Smbll_SmallBBox(v3);
    v4 = 2;
    obj_xspeed.enemy[v3] = 0;
    if (!sign8(0))
      v4 = 1;
    enemy_moving_dir[v3] = v4;
    obj_yspeed.enemy[v3] = -3;
    enemy_flag[v3] = 1;
    enemy_state[v3] = 5;
  }
}

void Smbll_LongFirebar_Init(uint8 k) {
  Smbll_DuplicateEnemyObj(k);
  Smbll_ShortFirebar_Init(k);
}

void Smbll_ShortFirebar_Init(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al

  obj_xspeed.enemy[k] = 0;
  v1 = enemy_id[k] - 27;
  enemy_data_b[k] = kFirebarSpinSpdData[v1];
  enemy_data_a[k] = kFirebarSpinDirData[v1];
  obj_ypos_lo.enemy[k] += 4;
  v2 = obj_xpos_lo.enemy[k];
  obj_xpos_lo.enemy[k] = v2 + 4;
  obj_xpos_hi.enemy[k] += __CFADD__(v2, 4);
  Smbll_TallBBox2(k);
}

void Smbll_FlyingCheepCheep_Init(uint8 k) {
  uint8 v1;  // di
  int8 v2;   // al
  uint8 v3;  // di
  bool v4;   // cf
  uint8 v5;  // al

  if (!frenzy_enemy_timer) {
    Smbll_SmallBBox(k);
    frenzy_enemy_timer = kFlyCCTimerData[*(&random_byte2 + k) & 3];
    v1 = 3;
    if (secondary_hard_mode)
      v1 = 4;
    R0_ = v1;
    if (k < v1) {
      R0_ = *(&random_byte1 + k) & 3;
      R1_ = R0_;
      obj_yspeed.enemy[k] = -5;
      v2 = 0;
      if (obj_xspeed.player) {
        v2 = 4;
        if (obj_xspeed.player >= 0x19u)
          v2 = 8;
      }
      R0_ += v2;
      if ((*(&random_byte2 + k) & 3) != 0)
        R0_ = *(&random_byte3 + k) & 0xF;
      v3 = R1_ + v2;
      obj_xspeed.enemy[k] = kFlyCCXSpeedData[(uint8)(R1_ + v2)];
      enemy_moving_dir[k] = 1;
      if (!obj_xspeed.player) {
        v3 = R0_;
        if ((R0_ & 2) != 0) {
          obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
          ++enemy_moving_dir[k];
        }
      }
      if ((v3 & 2) != 0) {
        v4 = __CFADD__(kFlyCCXPositionData[v3], obj_xpos_lo.player);
        obj_xpos_lo.enemy[k] = kFlyCCXPositionData[v3] + obj_xpos_lo.player;
        v5 = v4 + obj_xpos_hi.player;
      } else {
        v4 = obj_xpos_lo.player >= kFlyCCXPositionData[v3];
        obj_xpos_lo.enemy[k] = obj_xpos_lo.player - kFlyCCXPositionData[v3];
        v5 = obj_xpos_hi.player - !v4;
      }
      obj_xpos_hi.enemy[k] = v5;
      enemy_flag[k] = 1;
      obj_ypos_hi.enemy[k] = 1;
      obj_ypos_lo.enemy[k] = -8;
    }
  }
}

void Smbll_Bowser_Init(uint8 k) {
  uint8 i;  // di

  for (i = 4; (i & 0x80u) == 0; --i) {
    if (i != object_index && enemy_id[i] == 45) {
      enemy_id[i] = 0;
      enemy_flag[i] = 0;
    }
  }
  Smbll_DuplicateEnemyObj(k);
  browser_front_offset = k;
  browser_body_controls = 0;
  bridge_collapse_offset = 0;
  bowser_orig_xpos = obj_xpos_lo.enemy[k];
  bowser_fire_breath_timer = -33;
  enemy_moving_dir[k] = -33;
  bowser_feet_counter = 32;
  enemy_frame_timer[k] = 32;
  enemy_sprattrib[k] = 32;
  bowser_hit_points = 5;
  bowser_movement_speed = 2;
}

void Smbll_DuplicateEnemyObj(uint8 k) {
  uint8 v1;  // di

  v1 = -1;
  do
    ++v1;
  while (enemy_flag[v1]);
  duplicate_obj_offset = v1;
  enemy_flag[v1] = k | 0x80;
  obj_xpos_hi.enemy[v1] = obj_xpos_hi.enemy[k];
  obj_xpos_lo.enemy[v1] = obj_xpos_lo.enemy[k];
  enemy_flag[k] = 1;
  obj_ypos_hi.enemy[v1] = 1;
  obj_ypos_lo.enemy[v1] = obj_ypos_lo.enemy[k];
}

void Smbll_BowserFlame_Init(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // al
  bool v3;   // cf

  if (!frenzy_enemy_timer) {
    obj_sub_yspeed.enemy[k] = frenzy_enemy_timer;
    bowser_var014B = 6;
    bowser_var0F4C = 24;
    var0F4D_new = k;
    if (enemy_id[browser_front_offset] != 45) {
      v1 = Smbll_SetFlameTimer() + 32;
      if (secondary_hard_mode)
        v1 -= 16;
      frenzy_enemy_timer = v1;
      v2 = *(&random_byte1 + k) & 3;
      obj_sub_ypos.enemy[k] = v2;
      obj_ypos_lo.enemy[k] = kFlameYPosData[v2];
      v3 = __CFADD__(screen_right_xpos, 32);
      obj_xpos_lo.enemy[k] = screen_right_xpos + 32;
      obj_xpos_hi.enemy[k] = v3 + screen_right_xpos_hi;
      bowser_var0F4C = 0;
      var0F4D_new = 0;
      bowser_var014B = 0;
      sound_ch3 = 23;
      enemy_hitbox_ctrl[k] = 8;
      obj_ypos_hi.enemy[k] = 1;
      enemy_flag[k] = 1;
      obj_xpos_fract.enemy[k] = 0;
      enemy_state[k] = 0;
    }
    bowser_flame_enemy_index = k;
  }
}

void Smbll_PutAtRightExtent(uint8 k, uint8 a) {
  bool v2;  // cf

  obj_ypos_lo.enemy[k] = a;
  v2 = __CFADD__(screen_right_xpos, 32);
  obj_xpos_lo.enemy[k] = screen_right_xpos + 32;
  obj_xpos_hi.enemy[k] = v2 + screen_right_xpos_hi;
  enemy_hitbox_ctrl[k] = 8;
  obj_ypos_hi.enemy[k] = 1;
  enemy_flag[k] = 1;
  obj_xpos_fract.enemy[k] = 0;
  enemy_state[k] = 0;
}

void Smbll_InitFireworks(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al
  uint8 v3;  // di
  bool v4;   // cf

  if (!frenzy_enemy_timer) {
    frenzy_enemy_timer = 32;
    --fireworks_counter;
    v1 = 10;
    do
      --v1;
    while (enemy_id[v1] != 49);
    v2 = obj_xpos_lo.enemy[v1];
    R0_ = obj_xpos_hi.enemy[v1] - (v2 < 0x30u);
    v3 = enemy_state[v1] + fireworks_counter;
    v2 -= 48;
    v4 = __CFADD__(kFireworksXPosData[v3], v2);
    obj_xpos_lo.enemy[k] = kFireworksXPosData[v3] + v2;
    obj_xpos_hi.enemy[k] = v4 + R0_;
    obj_ypos_lo.enemy[k] = kFireworksYPosData[v3];
    obj_ypos_hi.enemy[k] = 1;
    enemy_flag[k] = 1;
    obj_xspeed.enemy[k] = 0;
    obj_yspeed.enemy[k] = 8;
  }
}

void Smbll_BulletBillCheepCheep(uint8 k) {
  int8 v1;   // di
  uint8 v2;  // al
  uint8 i;   // al
  uint8 v4;  // di
  uint8 v5;  // al
  uint8 v6;  // di

  if (!frenzy_enemy_timer) {
    if (area_type) {
      v6 = -1;
      while (++v6 < 9u) {
        if (enemy_flag[v6] && enemy_id[v6] == 8)
          return;
      }
      sound_ch3 = 9;
      v2 = 8;
    } else {
      if (k >= 3u)
        return;
      v1 = *(&random_byte1 + k) >= 0xAAu;
      if (world_number != 1)
        ++v1;
      v2 = kSwimCC_IDData[v1 & 1];
    }
    enemy_id[k] = v2;
    if (bit_m_filter == 0xFF)
      bit_m_filter = 0;
    for (i = *(&random_byte1 + k) & 7;; i = (v4 + 1) & 7) {
      v4 = i;
      v5 = kBitmasks[i];
      if ((bit_m_filter & v5) == 0)
        break;
    }
    bit_m_filter |= v5;
    Smbll_PutAtRightExtent(k, kEnemy17YPosData[v4]);
    obj_sub_ypos.enemy[k] = 0;
    frenzy_enemy_timer = 32;
    Smbll_CheckpointEnemyID(k);
  }
}

void Smbll_HandleGroupEnemies(uint8 a) {
  uint8 v1;  // di
  uint8 v2;  // al
  uint8 v3;  // di
  uint8 v4;  // di
  uint8 v5;  // si
  uint8 v6;  // al

  v1 = 0;
  v2 = a - 55;
  if (v2 < 4u) {
    v1 = 6;
    if (primary_hard_mode)
      v1 = 2;
  }
  R1_ = v1;
  v3 = -80;
  if ((v2 & 2) != 0)
    v3 = 112;
  R0_ = v3;
  R2_ = screen_right_xpos_hi;
  R3_ = screen_right_xpos;
  v4 = 2;
  if (v2 & 1)
    v4 = 3;
  number_of_group_enemies = v4;
LABEL_9:
  v5 = -1;
  while (++v5 < 9u) {
    if (!enemy_flag[v5]) {
      enemy_id[v5] = R1_;
      obj_xpos_hi.enemy[v5] = R2_;
      v6 = R3_;
      obj_xpos_lo.enemy[v5] = R3_;
      R3_ = v6 + 24;
      R2_ += __CFADD__(v6, 24);
      obj_ypos_lo.enemy[v5] = R0_;
      obj_ypos_hi.enemy[v5] = 1;
      enemy_flag[v5] = 1;
      Smbll_CheckpointEnemyID(v5);
      if (--number_of_group_enemies)
        goto LABEL_9;
      break;
    }
  }
  ++enemy_data_offset2;
  ++enemy_data_offset2;
  enemy_object_page_sel = 0;
}

void Smbll_PiranhaPlant_Init(uint8 k) {
  uint8 v1;  // al

  R0_ = 44;
  R1_ = 19;
  smbll_varF25 = 19;
  if (!title_screen_hard_mode_flag && world_number < 3u) {
    --R0_;
    --R0_;
    R1_ = 33;
    smbll_varF25 = 33;
  }
  smbll_varF24 = R0_;
  obj_xspeed.enemy[k] = 1;
  enemy_state[k] = 0;
  obj_yspeed.enemy[k] = 0;
  v1 = obj_ypos_lo.enemy[k];
  obj_sub_yspeed.enemy[k] = v1;
  obj_sub_ypos.enemy[k] = v1 - 24;
  enemy_hitbox_ctrl[k] = 12;
}

void Smbll_InitEnemyFrenzy(uint8 k) {
  uint8 v1;  // di

  enemy_frenzy_buffer = enemy_id[k];
  v1 = enemy_frenzy_buffer - 18;
  R4_ = koff_CA95[v1];
  R5_ = HIBYTE(koff_CA95[v1]);
  ((void (*)(uint8))funcs_B687[(unsigned int)(v1 * 2) >> 1])(k);
}
// B68F: using guessed type int (*funcs_B687[6])();

void Smbll_NoFrenzyCode(uint8 k) {
  ;
}

void Smbll_EndFrenzy(uint8 k) {
  uint8 i;  // di

  for (i = 9; (i & 0x80u) == 0; --i) {
    if (enemy_id[i] == 17)
      enemy_state[i] = 1;
  }
  enemy_frenzy_buffer = 0;
  enemy_flag[k] = 0;
}

void Smbll_JumpGPTroopa_Init(uint8 k) {
  enemy_moving_dir[k] = 2;
  obj_xspeed.enemy[k] = -12;
  Smbll_TallBBox2(k);
}

void Smbll_TallBBox2(uint8 k) {
  enemy_hitbox_ctrl[k] = 3;
}

void Smbll_BalPlatform_Init(uint8 k) {
  uint8 v1;  // di
  int8 v2;   // al

  --obj_ypos_lo.enemy[k];
  --obj_ypos_lo.enemy[k];
  if (!secondary_hard_mode)
    Smbll_PosPlatform(k, 2);
  v1 = -1;
  v2 = bal_platform_alignment;
  enemy_state[k] = bal_platform_alignment;
  if (v2 < 0)
    v1 = k;
  bal_platform_alignment = v1;
  enemy_moving_dir[k] = 0;
  Smbll_PosPlatform(k, 0);
  Smbll_InitDropPlatform_Init(k);
}

void Smbll_InitDropPlatform_Init(uint8 k) {
  enemy_data_d[k] = -1;
  Smbll_InitVStf(k);
  Smbll_SPBBox(k);
}

void Smbll_InitHoriPlatform_Init(uint8 k) {
  obj_xspeed.enemy[k] = 0;
  Smbll_InitVStf(k);
  Smbll_SPBBox(k);
}

void Smbll_VertPlatform_Init(uint8 k) {
  int8 v1;  // di
  int8 v2;  // al

  v1 = 64;
  v2 = obj_ypos_lo.enemy[k];
  if (v2 < 0) {
    v2 = -v2;
    v1 = -64;
  }
  obj_xpos_fract.enemy[k] = v2;
  obj_xspeed.enemy[k] = obj_ypos_lo.enemy[k] + v1;
  Smbll_InitVStf(k);
  Smbll_SPBBox(k);
}

void Smbll_SPBBox(uint8 k) {
  uint8 v1;  // al

  v1 = 5;
  if (area_type != 3 && !secondary_hard_mode)
    v1 = 6;
  enemy_hitbox_ctrl[k] = v1;
}

void Smbll_LargeLiftUp_Init(uint8 k) {
  Smbll_PlatLiftUp_Init(k);
  Smbll_SPBBox(k);
}

void Smbll_LargeLiftDown_Init(uint8 k) {
  Smbll_PlatLiftDown_Init(k);
  Smbll_SPBBox(k);
}

void Smbll_PlatLiftUp_Init(uint8 k) {
  obj_sub_yspeed.enemy[k] = 16;
  obj_yspeed.enemy[k] = -1;
  Smbll_PosPlatform(k, 1);
  enemy_hitbox_ctrl[k] = 4;
}

void Smbll_PlatLiftDown_Init(uint8 k) {
  obj_sub_yspeed.enemy[k] = -16;
  obj_yspeed.enemy[k] = 0;
  Smbll_PosPlatform(k, 1);
  enemy_hitbox_ctrl[k] = 4;
}

void Smbll_PosPlatform(uint8 k, uint8 j) {
  uint8 v2;  // al
  bool v3;   // cf

  v2 = obj_xpos_lo.enemy[k];
  v3 = __CFADD__(kPlatPosDataLow[j], v2);
  obj_xpos_lo.enemy[k] = kPlatPosDataLow[j] + v2;
  obj_xpos_hi.enemy[k] += kPlatPosDataHigh[j] + v3;
}

void Smbll_EndOfEnemyInitCode(uint8 k) {
  ;
}

void Smbll_RunEnemyObjectsCore() {
  int8 v0;   // al
  uint8 v1;  // di

  v0 = 0;
  v1 = enemy_id[object_index];
  if (v1 >= 0x15u)
    v0 = v1 - 20;
  ((void (*)(uint8))funcs_BA2A[v0])(object_index);
}
// BA32: using guessed type int (*funcs_BA2A[34])();

void Smbll_NoRunCode(uint8 k) {
  ;
}

void Smbll_RunRetainerObj(uint8 k) {
  Smbll_GetEnemyOffscreenBits(k);
  Smbll_RelativeEnemyPosition(k);
  Smbll_EnemyGfxHandler_New(k);
}

void Smbll_RunNormalEnemies(uint8 k) {
  enemy_sprattrib[k] = 32;
  Smbll_GetEnemyOffscreenBits(k);
  Smbll_RelativeEnemyPosition(k);
  Smbll_EnemyGfxHandler_New(k);
  Smbll_GetEnemyBoundBox(k);
  Smbll_EnemyToBGCollisionDet(k);
  Smbll_EnemiesCollision(k);
  Smbll_PlayerEnemyCollision(k);
  if (!timer_control)
    Smbll_EnemyMovementSubs(k);
  Smbll_OffscreenBoundsCheck(k);
}

void Smbll_EnemyMovementSubs(uint8 k) {
  uint8 v1;  // di

  v1 = enemy_id[k];
  R4_ = koff_CC0B[v1];
  R5_ = HIBYTE(koff_CC0B[v1]);
  funcs_BC11[(unsigned int)(v1 * 2) >> 1](k);
}
// BC19: using guessed type int (*funcs_BC11[21])();

void Smbll_NoMoveCode(uint8 k) {
  ;
}

void Smbll_RunBowserFlame(uint8 k) {
  Smbll_ProcBowserFlame(k);
  Smbll_GetEnemyOffscreenBits(k);
  Smbll_RelativeEnemyPosition(k);
  Smbll_GetEnemyBoundBox(k);
  Smbll_PlayerEnemyCollision(k);
  Smbll_OffscreenBoundsCheck(k);
}

void Smbll_RunFirebarObj(uint8 k) {
  Smbll_ProcFirebar(k);
  Smbll_OffscreenBoundsCheck(k);
}

void Smbll_RunSmallPlatform(uint8 k) {
  Smbll_GetEnemyOffscreenBits(k);
  Smbll_RelativeEnemyPosition(k);
  Smbll_SmallPlatformBoundBox(k);
  Smbll_SmallPlatformCollision(k);
  Smbll_RelativeEnemyPosition(k);
  Smbll_DrawSmallPlatform(k);
  Smbll_MoveSmallPlatform(k);
  Smbll_OffscreenBoundsCheck(k);
}

void Smbll_RunLargePlatform(uint8 k) {
  Smbll_GetEnemyOffscreenBits(k);
  Smbll_RelativeEnemyPosition(k);
  Smbll_LargePlatformBoundBox(k);
  Smbll_LargePlatformCollision(k);
  if (!timer_control)
    Smbll_LargePlatformSubroutines(k);
  Smbll_RelativeEnemyPosition(k);
  Smbll_DrawLargePlatform(k);
  Smbll_OffscreenBoundsCheck(k);
}

void Smbll_LargePlatformSubroutines(uint8 k) {
  uint8 v1;  // di

  v1 = enemy_id[k] - 36;
  R4_ = koff_CC97[v1];
  R5_ = HIBYTE(koff_CC97[v1]);
  ((void (*)(uint8))funcs_BDDE[(unsigned int)(v1 * 2) >> 1])(k);
}
// BDE6: using guessed type int (*funcs_BDDE[7])();

void Smbll_EraseEnemyObject(uint8 k) {
  *(&enemy_interval_timer + k) = 0;
  Smbll_EraseEnemyObject2(k);
}

void Smbll_EraseEnemyObject2(uint8 k) {
  OamEnt *oam;  // rbp

  if (k == 9) {
    oam = get_OamEnt(oam_buf, 0);
    oam[120].ypos = -16;
    oam[121].ypos = -16;
    oam[122].ypos = -16;
    oam[123].ypos = -16;
    if (area_data_addr_index == 34)
      cloud_type_override = 0;
  }
  enemy_flag[k] = 0;
  enemy_id[k] = 0;
  enemy_state[k] = 0;
  floateynum_control[k] = 0;
  shell_chain_counter[k] = 0;
  enemy_frame_timer[k] = 0;
  enemy_data_d[k] = 0;
  enemy_sprattrib[k] = 32;
}

void Smbll_MovePodoboo(uint8 k) {
  uint8 v1;  // al

  if (!*(&enemy_interval_timer + k)) {
    Smbll_Podoboo_Init(k);
    v1 = *(&random_byte2 + k) | 0x80;
    obj_sub_yspeed.enemy[k] = v1;
    *(&enemy_interval_timer + k) = v1 & 9 | 6;
    obj_yspeed.enemy[k] = -7;
  }
  if ((obj_yspeed.enemy[k] & 0x80u) == 0 && obj_ypos_lo.enemy[k] >= 0xC0u && podoboo_array_1[k] == 2) {
    ++podoboo_array_1[k];
    podoboo_array_2[k] = 0;
    sound_ch3 = 39;
  }
  ++podoboo_array_2[k];
  Smbll_MovePodoboo_Sub1(k);
  Smbll_MoveJ_EnemyVert(k);
}

void Smbll_ProcHammerBro(uint8 k) {
  uint8 v1;  // di
  int8 v2;   // al

  if ((enemy_state[k] & 0x20) != 0) {
    Smbll_MoveD_EnemyVert(k);
    Smbll_MoveEnemyHoriz(k);
  } else if (enemy_data_c[k]) {
    --enemy_data_c[k];
    if ((offscreen_bits.enemy & 0xC) != 0) {
LABEL_4:
      Smbll_CODE_03CEE9(k);
      return;
    }
    if (enemy_data_d[k] || (enemy_data_d[k] = kHammerThrowTmrData[secondary_hard_mode], !(Smbll_SpawnThrownHammer(k) & 1))) {
      --enemy_data_d[k];
      Smbll_CODE_03CEE9(k);
    } else {
      enemy_state[k] |= 8u;
      Smbll_CODE_03CEE9(k);
    }
  } else {
    if ((enemy_state[k] & 7) == 1)
      goto LABEL_4;
    R0_ = 0;
    v1 = -6;
    v2 = obj_ypos_lo.enemy[k];
    if (v2 < 0 || (v1 = -3, ++R0_, (uint8)v2 < 0x70u) || (--R0_, (*(&random_byte2 + k) & 1) != 0))
      Smbll_CODE_03CEC7(k, v1);
    else
      Smbll_CODE_03CEC7(k, 0xFAu);
  }
}

void Smbll_CODE_03CEC7(uint8 k, uint8 j) {
  uint8 v2;  // di

  obj_yspeed.enemy[k] = j;
  enemy_state[k] |= 1u;
  v2 = *(&random_byte3 + k) & R0_;
  if (!secondary_hard_mode)
    v2 = secondary_hard_mode;
  enemy_frame_timer[k] = kHammerBroJumpLData[v2];
  enemy_data_c[k] = *(&random_byte2 + k) | 0xC0;
  Smbll_CODE_03CEE9(k);
}

void Smbll_CODE_03CEE9(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // di

  v1 = -4;
  if ((frame_counter & 0x40) == 0)
    v1 = 4;
  obj_xspeed.enemy[k] = v1;
  v2 = 1;
  if ((Smbll_PlayerEnemyDiff(k) & 0x80u) == 0) {
    v2 = 2;
    if (!*(&enemy_interval_timer + k))
      obj_xspeed.enemy[k] = -8;
  }
  enemy_moving_dir[k] = v2;
  Smbll_MoveNormalEnemy(k);
}

void Smbll_MoveNormalEnemy(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al
  int8 v3;   // al
  int8 v4;   // al
  uint8 v5;  // di
  uint8 v6;  // di
  uint8 v7;  // [rsp+47h] [rbp-1h]

  v1 = 0;
  if ((enemy_state[k] & 0x40) != 0)
    goto LABEL_7;
  if (__CFSHL__(enemy_state[k], 1))
    goto LABEL_12;
  if ((enemy_state[k] & 0x20) != 0) {
    Smbll_MoveD_EnemyVert(k);
    Smbll_MoveEnemyHoriz(k);
    return;
  }
  v2 = enemy_state[k] & 7;
  if (!v2)
    goto LABEL_12;
  if (v2 == 5 || v2 < 3u) {
LABEL_7:
    Smbll_MoveD_EnemyVert(k);
    v1 = 0;
    if (enemy_state[k] == 2) {
      Smbll_MoveEnemyHoriz(k);
      return;
    }
    if ((enemy_state[k] & 0x40) != 0 && enemy_id[k] != 46)
      v1 = 1;
LABEL_12:
    v3 = obj_xspeed.enemy[k];
    v7 = v3;
    if (v3 < 0)
      v1 += 2;
    obj_xspeed.enemy[k] = kXSpeedAdderData[v1] + v3;
    Smbll_MoveEnemyHoriz(k);
    obj_xspeed.enemy[k] = v7;
    return;
  }
  v4 = *(&enemy_interval_timer + k);
  if (v4) {
    if (v4 == 14 && enemy_id[k] == 6)
      Smbll_EraseEnemyObject(k);
  } else {
    enemy_state[k] = 0;
    v5 = (frame_counter & 1) + 1;
    enemy_moving_dir[k] = v5;
    v6 = v5 - 1;
    if (primary_hard_mode)
      v6 += 2;
    obj_xspeed.enemy[k] = kRevivedXSpeed[v6];
  }
}

void Smbll_MoveJumpingEnemy(uint8 k) {
  Smbll_MoveJ_EnemyVert(k);
  Smbll_MoveEnemyHoriz(k);
}

void Smbll_ProcMoveRedPTroopa(uint8 k) {
  if (obj_sub_yspeed.enemy[k] | obj_yspeed.enemy[k] || (obj_sub_ypos.enemy[k] = 0, obj_ypos_lo.enemy[k] >= obj_xpos_fract.enemy[k])) {
    if (obj_ypos_lo.enemy[k] < obj_xspeed.enemy[k])
      Smbll_MoveRedPTroopaDown(k);
    else
      Smbll_MoveRedPTroopaUp(k);
  } else if ((frame_counter & 7) == 0) {
    ++obj_ypos_lo.enemy[k];
  }
}

void Smbll_MoveFlyGreenPTroopa(uint8 k) {
  uint8 v1;  // di

  Smbll_XMoveCntr_GreenPTroopa(k);
  Smbll_MoveWithXMCntrs(k);
  v1 = 1;
  if ((frame_counter & 3) == 0) {
    if ((frame_counter & 0x40) == 0)
      v1 = -1;
    R0_ = v1;
    obj_ypos_lo.enemy[k] += v1;
  }
}

void Smbll_XMoveCntr_GreenPTroopa(uint8 k) {
  Smbll_XMoveCntr_Platform(k, 0x13u);
}

void Smbll_XMoveCntr_Platform(uint8 k, uint8 a) {
  uint8 v2;  // di

  R1_ = a;
  if ((frame_counter & 3) == 0) {
    v2 = obj_xspeed.enemy[k];
    if (obj_yspeed.enemy[k] & 1) {
      if (v2) {
        --obj_xspeed.enemy[k];
        return;
      }
    } else if (v2 != R1_) {
      ++obj_xspeed.enemy[k];
      return;
    }
    ++obj_yspeed.enemy[k];
  }
}

void Smbll_MoveWithXMCntrs(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // [rsp+47h] [rbp-1h]

  v2 = obj_xspeed.enemy[k];
  v1 = 1;
  if ((obj_yspeed.enemy[k] & 2) == 0) {
    obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
    v1 = 2;
  }
  enemy_moving_dir[k] = v1;
  R0_ = Smbll_MoveEnemyHoriz(k);
  obj_xspeed.enemy[k] = v2;
}

void Smbll_MoveBloober(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al
  bool v3;   // cf
  uint8 v4;  // al

  if ((enemy_state[k] & 0x20) != 0) {
    Smbll_MoveEnemySlowVert(k);
  } else {
    if ((kBlooberBitmasks[secondary_hard_mode] & *(&random_byte2 + k)) == 0) {
      if (k & 1) {
        v1 = player_moving_dir;
      } else {
        v1 = 2;
        if ((Smbll_PlayerEnemyDiff(k) & 0x80u) != 0)
          v1 = 1;
      }
      enemy_moving_dir[k] = v1;
    }
    Smbll_ProcSwimmingB(k);
    if ((uint8)(obj_ypos_lo.enemy[k] - obj_sub_yspeed.enemy[k]) >= 0x20u)
      obj_ypos_lo.enemy[k] -= obj_sub_yspeed.enemy[k];
    v2 = obj_xpos_lo.enemy[k];
    if (enemy_moving_dir[k] == 1) {
      v3 = __CFADD__(obj_xspeed.enemy[k], v2);
      obj_xpos_lo.enemy[k] = obj_xspeed.enemy[k] + v2;
      v4 = v3 + obj_xpos_hi.enemy[k];
    } else {
      v3 = v2 < obj_xspeed.enemy[k];
      obj_xpos_lo.enemy[k] = v2 - obj_xspeed.enemy[k];
      v4 = obj_xpos_hi.enemy[k] - v3;
    }
    obj_xpos_hi.enemy[k] = v4;
  }
}

void Smbll_ProcSwimmingB(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // al
  int8 v3;   // [rsp+47h] [rbp-1h]

  if ((obj_yspeed.enemy[k] & 2) != 0) {
    if (*(&enemy_interval_timer + k) || (uint8)(obj_ypos_lo.enemy[k] + 16) < obj_ypos_lo.player) {
      if (!(frame_counter & 1))
        ++obj_ypos_lo.enemy[k];
    } else {
      obj_yspeed.enemy[k] = 0;
    }
  } else {
    v3 = frame_counter & 7;
    if (obj_yspeed.enemy[k] & 1) {
      if (!v3) {
        v2 = --obj_sub_yspeed.enemy[k];
        obj_xspeed.enemy[k] = v2;
        if (!v2) {
          ++obj_yspeed.enemy[k];
          *(&enemy_interval_timer + k) = 2;
        }
      }
    } else if (!v3) {
      v1 = ++obj_sub_yspeed.enemy[k];
      obj_xspeed.enemy[k] = v1;
      if (v1 == 2)
        ++obj_yspeed.enemy[k];
    }
  }
}

void Smbll_MoveBulletBill(uint8 k) {
  if ((enemy_state[k] & 0x20) != 0) {
    Smbll_MoveJ_EnemyVert(k);
  } else {
    obj_xspeed.enemy[k] = -24;
    Smbll_MoveEnemyHoriz(k);
  }
}

void Smbll_MoveSwimmingCheepCheep(uint8 k) {
  uint8 v1;   // al
  bool v2;    // cf
  uint8 v3;   // al
  uint8 v4;   // al
  uint8 v5;   // al
  int8 v6;    // al
  bool v7;    // tt
  uint8 v8;   // al
  uint8 v9;   // al
  int8 v10;   // tt
  uint8 v11;  // di
  int8 v12;   // al

  if ((enemy_state[k] & 0x20) != 0) {
    Smbll_MoveEnemySlowVert(k);
  } else {
    R3_ = 0;
    R2_ = kSwimCCXMoveData[(uint8)(enemy_id[k] - 10)];
    v1 = obj_xpos_fract.enemy[k];
    v2 = v1 < R2_;
    obj_xpos_fract.enemy[k] = v1 - R2_;
    v3 = obj_xpos_lo.enemy[k];
    obj_xpos_lo.enemy[k] = v3 - v2;
    obj_xpos_hi.enemy[k] -= v3 < (uint8)v2;
    R2_ = 64;
    if (k >= 2u) {
      v4 = obj_sub_ypos.enemy[k];
      if (obj_xspeed.enemy[k] < 0x10u) {
        v2 = v4 < R2_;
        obj_sub_ypos.enemy[k] = v4 - R2_;
        v9 = obj_ypos_lo.enemy[k];
        v10 = v2 + R3_;
        v2 = v9 < (uint8)(v2 + R3_);
        obj_ypos_lo.enemy[k] = v9 - v10;
        v8 = obj_ypos_hi.enemy[k] - v2;
      } else {
        v2 = __CFADD__(R2_, v4);
        obj_sub_ypos.enemy[k] = R2_ + v4;
        v5 = obj_ypos_lo.enemy[k];
        v7 = v2;
        v2 = __CFADD__(v2, v5);
        v6 = v7 + v5;
        v2 |= __CFADD__(R3_, v6);
        obj_ypos_lo.enemy[k] = R3_ + v6;
        v8 = v2 + obj_ypos_hi.enemy[k];
      }
      obj_ypos_hi.enemy[k] = v8;
      v11 = 0;
      v12 = obj_ypos_lo.enemy[k] - obj_sub_yspeed.enemy[k];
      if (v12 < 0) {
        v11 = 16;
        v12 = obj_sub_yspeed.enemy[k] - obj_ypos_lo.enemy[k];
      }
      if ((uint8)v12 >= 0xFu)
        obj_xspeed.enemy[k] = v11;
    }
  }
}

void Smbll_ProcFirebar(uint8 k) {
  uint8 v1;     // al
  uint8 v2;     // al
  uint8 v3;     // di
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v6;     // al
  uint8 v7;     // di

  Smbll_GetEnemyOffscreenBits(k);
  if ((offscreen_bits.enemy & 8) == 0) {
    if (!timer_control)
      obj_yspeed.enemy[k] = Smbll_FirebarSpin(k, enemy_data_b[k]) & 0x1F;
    v1 = obj_yspeed.enemy[k];
    if (enemy_id[k] >= 0x1Fu && (v1 == 8 || v1 == 24))
      obj_yspeed.enemy[k] = ++v1;
    tempEF = v1;
    v2 = Smbll_RelativeEnemyPosition(k);
    Smbll_GetFirebarPosition(v2);
    v3 = enemy_obj_id[k];
    enemy = rel_ypos.enemy;
    oam = get_OamEnt(oam_buf, v3);
    oam[64].ypos = rel_ypos.enemy;
    R7_ = enemy;
    v6 = rel_xpos_lo.enemy;
    oam[64].xpos = rel_xpos_lo.enemy;
    R6_ = v6;
    R0_ = 1;
    Smbll_FirebarCollision(v3);
    v7 = 5;
    if (enemy_id[k] >= 0x1Fu)
      v7 = 11;
    tempED = v7;
    R0_ = 0;
    do {
      Smbll_GetFirebarPosition(tempEF);
      Smbll_DrawFirebar_Collision();
      if (R0_ == 4)
        R6_ = enemy_obj_id[duplicate_obj_offset];
      ++R0_;
    } while (R0_ < tempED);
  }
}

void Smbll_DrawFirebar_Collision() {
  uint8 v0;     // di
  uint8 v1;     // al
  uint8 v2;     // al
  OamEnt *oam;  // rdx
  uint8 v4;     // al
  uint8 enemy;  // al
  uint8 v6;     // al
  int8 v7;      // cf

  v0 = R6_;
  v1 = R1_;
  R5_ = R3_ >> 1;
  if (!(R3_ & 1))
    v1 = -R1_;
  v2 = rel_xpos_lo.enemy + v1;
  oam = get_OamEnt(oam_buf, R6_);
  oam[64].xpos = v2;
  R6_ = v2;
  if (v2 >= rel_xpos_lo.enemy)
    v4 = v2 - rel_xpos_lo.enemy;
  else
    v4 = rel_xpos_lo.enemy - R6_;
  if (v4 < 0x59u) {
    enemy = rel_ypos.enemy;
    if (rel_ypos.enemy != 0xF8) {
      v6 = R2_;
      v7 = R5_ & 1;
      R5_ >>= 1;
      if (!v7)
        v6 = -R2_;
      enemy = rel_ypos.enemy + v6;
    }
  } else {
    enemy = -8;
  }
  oam[64].ypos = enemy;
  R7_ = enemy;
  oam_tile_size_buffer[v0 + 256] = enemy >= 0xF0u;
  Smbll_FirebarCollision(v0);
}

void Smbll_FirebarCollision(uint8 j) {
  uint8 player;  // di
  uint8 i;       // al
  int8 v3;       // al
  int8 v4;       // al
  uint8 v5;      // si
  uint8 v6;      // [rsp+46h] [rbp-2h]

  Smbll_DrawFirebar(j);
  if (!(timer_control | player_star_power_timer)) {
    R5_ = 0;
    if (obj_ypos_hi.player == 1) {
      player = obj_ypos_lo.player;
      if (player_size || crouching_flag) {
        ++R5_;
        ++R5_;
        player = obj_ypos_lo.player + 24;
      }
      for (i = player;; i = kFirebarYPos[R5_++] + obj_ypos_lo.player) {
        v3 = i - R7_;
        if (v3 < 0)
          v3 = -v3;
        if ((uint8)v3 < 8u && R6_ < 0xF0u) {
          R4_ = rel_xpos_lo.player + 4;
          v4 = rel_xpos_lo.player + 4 - R6_;
          if (v4 < 0)
            v4 = R6_ - (rel_xpos_lo.player + 4);
          if ((uint8)v4 < 8u)
            break;
        }
        if (R5_ == 2)
          goto LABEL_19;
      }
      v5 = 1;
      if (R4_ < R6_)
        v5 = 2;
      enemy_moving_dir[object_index] = v5;
      v6 = R0_;
      Smbll_InjurePlayer();
      R0_ = v6;
    }
  }
LABEL_19:
  R6_ = j + 4;
}

void Smbll_GetFirebarPosition(uint8 a) {
  uint8 v1;  // al
  uint8 v2;  // al

  v1 = a & 0xF;
  if (v1 >= 9u)
    v1 = (v1 ^ 0xF) + 1;
  R1_ = v1;
  R1_ = kFirebarPosLookupTbl[(uint8)(v1 + kFirebarTblOffsets[R0_])];
  v2 = (a + 8) & 0xF;
  if (v2 >= 9u)
    v2 = (v2 ^ 0xF) + 1;
  R2_ = v2;
  R2_ = kFirebarPosLookupTbl[(uint8)(v2 + kFirebarTblOffsets[R0_])];
  R3_ = kFirebarMirrorData[a >> 3];
}

void Smbll_MoveFlyingCheepCheep(uint8 k) {
  uint8 v1;  // di
  int8 v2;   // al

  if ((enemy_state[k] & 0x20) != 0) {
    enemy_sprattrib[k] = 32;
    Smbll_MoveJ_EnemyVert(k);
  } else {
    Smbll_MoveEnemyHoriz(k);
    Smbll_SetXMoveAmt(k, 0xDu, 5u);
    v1 = obj_sub_yspeed.enemy[k] >> 4;
    v2 = obj_ypos_lo.enemy[k] - kPRandomSubtracter[v1];
    if (v2 < 0)
      v2 = kPRandomSubtracter[v1] - obj_ypos_lo.enemy[k];
    if ((uint8)v2 < 8u)
      v1 = (uint8)(obj_sub_yspeed.enemy[k] + 16) >> 4;
    enemy_sprattrib[k] = kFlyCCBPriority[v1];
  }
}

void Smbll_MoveLakitu(uint8 k) {
  uint8 v1;  // al
  uint8 i;   // di
  uint8 v3;  // di

  if ((enemy_state[k] & 0x20) != 0) {
    Smbll_MoveD_EnemyVert(k);
  } else {
    if (enemy_state[k]) {
      obj_yspeed.enemy[k] = 0;
      enemy_frenzy_buffer = 0;
      v1 = 16;
    } else {
      enemy_frenzy_buffer = 18;
      for (i = 2; (i & 0x80u) == 0; --i)
        *(&R1_ + i) = kLakituDiffAdj[i];
      v1 = Smbll_PlayerLakituDiff(k);
    }
    obj_xspeed.enemy[k] = v1;
    v3 = 1;
    if ((obj_yspeed.enemy[k] & 1) == 0) {
      obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
      v3 = 2;
    }
    enemy_moving_dir[k] = v3;
    Smbll_MoveEnemyHoriz(k);
  }
}

uint8 Smbll_PlayerLakituDiff(uint8 k) {
  uint8 v1;      // di
  uint8 result;  // al
  uint8 v3;      // di
  int8 v4;       // di

  v1 = 0;
  if ((Smbll_PlayerEnemyDiff(k) & 0x80u) != 0) {
    v1 = 1;
    R0_ = -R0_;
  }
  if (R0_ >= 0x3Cu) {
    R0_ = 60;
    if (enemy_id[k] == 17 && v1 != obj_yspeed.enemy[k]) {
      if (obj_yspeed.enemy[k]) {
        result = --obj_xspeed.enemy[k];
        if (result)
          return result;
      }
      obj_yspeed.enemy[k] = v1;
    }
  }
  R0_ = (uint8)(R0_ & 0x3C) >> 2;
  v3 = 0;
  if (obj_xspeed.player && scroll_amount) {
    v3 = 1;
    if (obj_xspeed.player >= 0x19u && scroll_amount >= 2u)
      v3 = 2;
    if ((enemy_id[k] != 18 || !obj_xspeed.player) && !obj_yspeed.enemy[k])
      v3 = 0;
  }
  result = *(&R1_ + v3);
  v4 = R0_;
  do {
    --result;
    --v4;
  } while (v4 >= 0);
  return result;
}

void Smbll_BridgeCollapse_Sub(uint8 a) {
  uint8 v1;  // si

  v1 = bridge_collapse_offset - 2;
  bridge_segment_index[0] = bridge_collapse_offset - 2;
  if ((a & 0x80) != 0) {
    bridge_animation_frame[v1] = 0;
    bridge_sprite_slot_exists_flag[v1] = 1;
    tempE4 = 8 * (R4_ & 0x1F);
    level_bridge_spr_xpos_lo[v1] = tempE4 - screen_left_xpos16;
    level_bridge_spr_animation_frame_timer[v1] = 3;
  }
}

void Smbll_BridgeCollapse() {
  uint8 v0;  // si
  uint8 v1;  // al

  v0 = browser_front_offset;
  if (enemy_id[browser_front_offset] != 45) {
LABEL_5:
    if (!bridge_collapse_sfx_flag) {
      music_ch1 = 11;
      bridge_collapse_sfx_flag = 11;
    }
    ++game_mode_task;
    Smbll_KillAllEnemies();
    return;
  }
  object_index = browser_front_offset;
  v1 = enemy_state[browser_front_offset];
  if (v1) {
    if ((v1 & 0x40) != 0 && obj_ypos_lo.enemy[browser_front_offset] < 0xE0u) {
      Smbll_MoveEnemySlowVert(browser_front_offset);
      Smbll_BowserGfxHandler(v0);
      return;
    }
    goto LABEL_5;
  }
  if (!--bowser_feet_counter) {
    bowser_feet_counter = 4;
    browser_body_controls ^= 1u;
    R5_ = 2;
    R4_ = kBridgeCollapseData[bridge_collapse_offset];
    Smbll_BridgeCollapse_Sub(R4_);
    Smbll_RemBridge(0x18u, vram_buffer1[0] + 1);
    v0 = object_index;
    Smbll_MoveVOffset();
    sound_ch3 = 22;
    if (!bridge_collapse_offset) {
      bowser_var014B = 8;
      bowser_var0F4C = -1;
    }
    if (++bridge_collapse_offset == 15) {
      Smbll_InitVStf(v0);
      enemy_state[v0] = 64;
    }
  }
  Smbll_BowserGfxHandler(v0);
}

void Smbll_RunBowser(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di
  uint8 v3;  // al
  uint8 v4;  // al
  uint8 v5;  // al

  if ((enemy_state[k] & 0x20) != 0) {
    if (obj_ypos_lo.enemy[k] < 0xE0u) {
      Smbll_MoveEnemySlowVert(k);
      Smbll_BowserGfxHandler(k);
    } else if (cutscene_0EC4 || bowser_var0201 == 2) {
      Smbll_KillAllEnemies();
    }
  } else {
    enemy_frenzy_buffer = 0;
    if (!timer_control) {
      if ((browser_body_controls & 0x80u) == 0) {
        if (!--bowser_feet_counter) {
          bowser_feet_counter = 32;
          browser_body_controls ^= 1u;
        }
        if ((frame_counter & 0xF) == 0)
          enemy_moving_dir[k] = 2;
        if (!enemy_frame_timer[k] || (Smbll_PlayerEnemyDiff(k) & 0x80u) == 0 ||
            (enemy_moving_dir[k] = 1, bowser_movement_speed = 2, enemy_frame_timer[k] = 32, bowser_fire_breath_timer = 32,
             obj_xpos_lo.enemy[k] < 0xB0u)) {
          if ((frame_counter & 3) == 0) {
            if (obj_xpos_lo.enemy[k] == bowser_orig_xpos)
              bowser_var06DC = kbyte_D3FF[*(&random_byte1 + k) & 3];
            v1 = bowser_movement_speed + obj_xpos_lo.enemy[k];
            obj_xpos_lo.enemy[k] = v1;
            if (enemy_moving_dir[k] != 1) {
              v2 = -1;
              v3 = v1 - bowser_orig_xpos;
              if ((v3 & 0x80u) != 0) {
                v3 = -v3;
                v2 = 1;
              }
              if (v3 >= bowser_var06DC)
                bowser_movement_speed = v2;
            }
          }
        }
      }
      v4 = enemy_frame_timer[k];
      if (v4) {
        if (v4 == 1) {
          --obj_ypos_lo.enemy[k];
          Smbll_InitVStf(k);
          obj_yspeed.enemy[k] = -2;
        }
      } else {
        Smbll_MoveEnemySlowVert(k);
        if (world_number >= 5u && (frame_counter & 3) == 0)
          Smbll_SpawnThrownHammer(k);
        if (obj_ypos_lo.enemy[k] >= 0x80u)
          enemy_frame_timer[k] = kbyte_D3FF[*(&random_byte1 + k) & 3];
      }
    }
    do {
      if (world_number != 7 && world_number >= 5u || bowser_fire_breath_timer) {
        Smbll_BowserGfxHandler(k);
        return;
      }
      bowser_fire_breath_timer = 32;
      browser_body_controls ^= 0x80u;
    } while ((browser_body_controls & 0x80u) != 0);
    v5 = Smbll_SetFlameTimer();
    if (secondary_hard_mode)
      v5 -= 16;
    bowser_fire_breath_timer = v5;
    enemy_frenzy_buffer = 21;
    Smbll_BowserGfxHandler(k);
  }
}

void Smbll_KillAllEnemies() {
  int8 i;  // si

  for (i = 8; i >= 0; --i)
    Smbll_EraseEnemyObject(i);
  enemy_frenzy_buffer = 0;
}

void Smbll_BowserGfxHandler(uint8 k) {
  int8 v1;   // di
  uint8 v2;  // al
  uint8 v3;  // di
  uint8 v4;  // si
  uint8 v5;  // al
  uint8 v6;  // [rsp+47h] [rbp-1h]

  Smbll_ProcessBowserHalf(k);
  v1 = 16;
  if (enemy_moving_dir[k] & 1)
    v1 = -16;
  v2 = obj_xpos_lo.enemy[k] + v1;
  v3 = duplicate_obj_offset;
  obj_xpos_lo.enemy[duplicate_obj_offset] = v2;
  obj_ypos_lo.enemy[v3] = obj_ypos_lo.enemy[k] + 8;
  enemy_state[v3] = enemy_state[k];
  enemy_moving_dir[v3] = enemy_moving_dir[k];
  v6 = object_index;
  v4 = duplicate_obj_offset;
  object_index = duplicate_obj_offset;
  if (!bowser_var0097) {
    if (cutscene_0EC4)
      v5 = 5;
    else
      v5 = 4;
    music_ch1 = v5;
    bowser_var0097 = v5;
  }
  enemy_id[duplicate_obj_offset] = 45;
  enemy_sprattrib[v4] = 32;
  object_index = v6;
  bowser_gfx_flag = 0;
}

void Smbll_ProcessBowserHalf(uint8 k) {
  ++bowser_gfx_flag;
  Smbll_RunRetainerObj(k);
  if (!enemy_state[k]) {
    enemy_hitbox_ctrl[k] = 10;
    Smbll_GetEnemyBoundBox(k);
    if (game_mode != 2)
      Smbll_PlayerEnemyCollision(k);
  }
}

uint8 Smbll_SetFlameTimer() {
  uint8 v0;  // di

  v0 = bowser_flame_timer_ctrl++;
  bowser_flame_timer_ctrl &= 7u;
  return kFlameTimerData[v0];
}

void Smbll_ProcBowserFlame(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // al
  bool v3;   // cf
  uint8 v4;  // al
  uint8 v5;  // al

  if (k != var0F4D_new || !bowser_var0F4C || bowser_var014B != 6) {
    if (!timer_control) {
      v1 = 64;
      if (secondary_hard_mode)
        v1 = 96;
      R0_ = v1;
      v2 = obj_xpos_fract.enemy[k];
      v3 = v2 < R0_;
      obj_xpos_fract.enemy[k] = v2 - R0_;
      v4 = obj_xpos_lo.enemy[k];
      obj_xpos_lo.enemy[k] = v4 - (v3 + 1);
      obj_xpos_hi.enemy[k] -= v4 < (uint8)(v3 + 1);
      v5 = obj_ypos_lo.enemy[k];
      if (v5 != kFlameYPosData[obj_sub_ypos.enemy[k]])
        obj_ypos_lo.enemy[k] = obj_sub_yspeed.enemy[k] + v5;
    }
    Smbll_RelativeEnemyPosition(k);
    if (!enemy_state[k])
      Smbll_ProcBowserFlame_Sub(k);
  }
}

void Smbll_RunFireworks(uint8 k) {
  uint8 v2;  // di

  if (obj_yspeed.enemy[k]-- != 1)
    goto LABEL_5;
  obj_yspeed.enemy[k] = 8;
  if (++obj_xspeed.enemy[k] == 1) {
    sound_ch1 = 41;
LABEL_5:
    Smbll_RelativeEnemyPosition(k);
    rel_ypos.fireball = rel_ypos.enemy;
    rel_xpos_lo.fireball = rel_xpos_lo.enemy;
    Smbll_DrawExplosion_Fireworks(enemy_obj_id[k], obj_xspeed.enemy[k]);
    return;
  }
  if (obj_xspeed.enemy[k] < 4u)
    goto LABEL_5;
  enemy_flag[k] = 0;
  v2 = enemy_obj_id[k];
  oam_tile_size_buffer[v2 + 256] = 3;
  oam_tile_size_buffer[v2 + 260] = 3;
  oam_tile_size_buffer[v2 + 264] = 3;
  oam_tile_size_buffer[v2 + 268] = 3;
  digit_modifier[4] = 5;
  Smbll_EndAreaPoints();
}

void Smbll_RunStarFlagObj(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al

  enemy_frenzy_buffer = 0;
  switch (star_flag_task_control) {
  case 1:
    if (level_timer_ones == score_and_coin_display[5]) {
      if ((level_timer_ones & 1) != 0) {
        v1 = 3;
        v2 = 3;
      } else {
        v1 = 0;
        v2 = 6;
      }
    } else {
      v1 = 0;
      v2 = -1;
    }
    fireworks_counter = v2;
    enemy_state[k] = v1;
    if ((ReadReg(APUI03) & 0x7F) != 75)
      sound_ch3 = 75;
    ++star_flag_task_control;
    break;
  case 2:
    if ((level_timer_hundreds | level_timer_tens | level_timer_ones) == 0) {
      unused_byte_7E0E1A = sound_ch3 = 0x4c;
      ++star_flag_task_control;
    } else {
      Smbll_CODE_03D809();
    }
    break;
  case 3: Smbll_RaiseFlagSetoffFWorks(k); break;
  case 4: Smbll_DelayToAreaEnd(k); break;
  }
}

void Smbll_CODE_03D809() {
  digit_modifier[5] = -1;
  Smbll_DigitsMathRoutine(0x23u);
  digit_modifier[5] = 5;
  Smbll_EndAreaPoints();
}

void Smbll_EndAreaPoints() {
  Smbll_DigitsMathRoutine(0xBu);
  Smbll_UpdateNumber((16 * current_player) | 4);
}

void Smbll_RaiseFlagSetoffFWorks(uint8 k) {
  disable_sprite_oamreset_flag = 1;
  if (obj_ypos_lo.enemy[k] < 0x72u) {
    if ((int8)fireworks_counter > 0) {
      enemy_frenzy_buffer = 22;
      Smbll_DrawStarFlag(k);
    } else {
      Smbll_DrawFlagSetTimer(k);
    }
  } else {
    --obj_ypos_lo.enemy[k];
    Smbll_DrawStarFlag(k);
  }
}

void Smbll_DrawStarFlag(uint8 k) {
  uint8 v1;     // di
  OamEnt *oam;  // rbp

  Smbll_RelativeEnemyPosition(k);
  v1 = enemy_obj_id[k];
  oam = get_OamEnt(oam_buf, v1);
  oam[64].ypos = rel_ypos.enemy;
  oam[64].charnum = ((uint8)(frame_counter & 0x18) >> 2) + 4;
  oam[64].flags = 11;
  oam[64].xpos = rel_xpos_lo.enemy;
  oam_tile_size_buffer[v1 + 256] = 2;
}

void Smbll_DrawFlagSetTimer(uint8 k) {
  Smbll_DrawStarFlag(k);
  *(&enemy_interval_timer + k) = 6;
  Smbll_IncrementSFTask2();
}

void Smbll_IncrementSFTask2() {
  ++star_flag_task_control;
}

void Smbll_DelayToAreaEnd(uint8 k) {
  Smbll_DrawStarFlag(k);
  if (!*(&enemy_interval_timer + k) && !event_music_buffer)
    Smbll_IncrementSFTask2();
}

void Smbll_MovePiranhaPlant(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // al

  if (enemy_state[k] || enemy_frame_timer[k])
    goto LABEL_16;
  if (obj_yspeed.enemy[k])
    goto LABEL_9;
  if ((obj_xspeed.enemy[k] & 0x80u) != 0)
    goto LABEL_8;
  if ((Smbll_PlayerEnemyDiff(k) & 0x80u) != 0)
    R0_ = -R0_;
  if (R0_ >= smbll_varF25) {
LABEL_8:
    obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
    ++obj_yspeed.enemy[k];
LABEL_9:
    v1 = obj_sub_yspeed.enemy[k];
    if ((obj_xspeed.enemy[k] & 0x80u) != 0)
      v1 = obj_sub_ypos.enemy[k];
    R0_ = v1;
    if ((smbll_varF24 == 44 || frame_counter & 1) && !timer_control) {
      v2 = obj_xspeed.enemy[k] + obj_ypos_lo.enemy[k];
      obj_ypos_lo.enemy[k] = v2;
      if (v2 == R0_) {
        obj_yspeed.enemy[k] = 0;
        enemy_frame_timer[k] = 64;
      }
    }
  }
LABEL_16:
  enemy_sprattrib[k] = 0;
}

uint8 Smbll_FirebarSpin(uint8 k, uint8 a) {
  uint8 v2;  // al
  bool v3;   // cf

  R7_ = a;
  v2 = obj_xspeed.enemy[k];
  if (enemy_data_a[k]) {
    v3 = v2 < R7_;
    obj_xspeed.enemy[k] = v2 - R7_;
    return obj_yspeed.enemy[k] - v3;
  } else {
    v3 = __CFADD__(R7_, v2);
    obj_xspeed.enemy[k] = R7_ + v2;
    return v3 + obj_yspeed.enemy[k];
  }
}

void Smbll_BalancePlatform(uint8 k) {
  uint8 v1;    // al
  uint8 v2;    // di
  int8 v3;     // al
  uint8 v4;    // al
  int8 v5;     // al
  int8 v6;     // al
  uint8 v7;    // di
  int8 v8;     // al
  uint16 v9;   // si
  int16 v10;   // ax
  int v11;     // edx
  int16 v12;   // ax
  uint16 v13;  // si
  int16 v14;   // ax
  int v15;     // edx
  int16 v16;   // ax
  uint8 v17;   // [rsp+47h] [rbp-1h]
  uint8 v18;   // [rsp+47h] [rbp-1h]

  if (obj_ypos_hi.enemy[k] == 3) {
    Smbll_EraseEnemyObject(k);
    return;
  }
  v1 = enemy_state[k];
  if ((v1 & 0x80u) != 0)
    return;
  v2 = enemy_state[k];
  if (enemy_id[v1] != 36)
    return;
  R0_ = enemy_data_d[k];
  if (enemy_moving_dir[k]) {
    Smbll_PlatformFall(k, v1);
    return;
  }
  if (obj_ypos_lo.enemy[k] <= 0x2Du) {
    if (v1 != R0_) {
      obj_ypos_lo.enemy[k] = 47;
      Smbll_StopPlatforms(k, v1);
      return;
    }
    goto LABEL_11;
  }
  if (obj_ypos_lo.enemy[v1] > 0x2Du) {
    v17 = obj_ypos_lo.enemy[k];
    v3 = enemy_data_d[k];
    if (v3 >= 0) {
      if (v3 != object_index)
        goto LABEL_21;
    } else {
      v4 = obj_sub_yspeed.enemy[k];
      R0_ = v4 + 5;
      v5 = __CFADD__(v4, 5) + obj_yspeed.enemy[k];
      if (v5 >= 0) {
        if (!v5 && R0_ < 0xBu) {
          Smbll_StopPlatforms(k, v2);
          goto LABEL_24;
        }
LABEL_21:
        Smbll_MovePlatformUp(k);
LABEL_24:
        obj_ypos_lo.enemy[enemy_state[k]] += v17 - obj_ypos_lo.enemy[k];
        v6 = enemy_data_d[k];
        if (v6 >= 0)
          Smbll_PositionPlayerOnVPlat(v6);
        v7 = object_index;
        if (obj_sub_yspeed.enemy[object_index] | obj_yspeed.enemy[object_index]) {
          v18 = obj_yspeed.enemy[object_index];
          Smbll_SetupPlatformRope(object_index, v18);
          tempF3 = (uint8)screen_left_xpos16 >> 3;
          tempF4 = (4 * (HIBYTE(screen_left_xpos16) & 1)) | 0x20;
          v8 = ((uint8)screen_left_xpos16 >> 3) + 31;
          tempF5 = v8 & 0x1F;
          if ((v8 & 0x20) != 0)
            tempF6 = tempF4 ^ 4;
          if ((unsigned int)(*(uint16 *)&R0_ & 0x241F) >= *(uint16 *)&tempF3 ||
              (unsigned int)(*(uint16 *)&R0_ & 0x241F) < *(uint16 *)&tempF5) {
            v9 = *(uint16 *)vram_buffer1;
            LOBYTE(v10) = (uint16)(*(uint16 *)&R0_ & 0x1FFF) >> 8;
            HIBYTE(v10) = R0_;
            v11 = *(uint16 *)vram_buffer1;
            *(uint16 *)&vram_buffer1[*(uint16 *)vram_buffer1 + 2] = v10;
            *(uint16 *)&vram_buffer1[v11 + 4] = 768;
            if ((obj_yspeed.enemy[v7] & 0x80) != 0) {
              *(uint16 *)&vram_buffer1[v9 + 6] = 36;
              *(uint16 *)&vram_buffer1[v9 + 8] = 36;
            } else {
              if ((*(uint16 *)&vram_buffer1[v9 + 2] & 0xF003) == 0xA000 || (*(uint16 *)&vram_buffer1[v9 + 2] & 0xF003) == 0xB000) {
                v12 = 6236;
              } else {
                v12 = 4258;
              }
              *(uint16 *)&vram_buffer1[v9 + 6] = v12;
              *(uint16 *)&vram_buffer1[v9 + 8] = 6307;
            }
            *(uint16 *)&vram_buffer1[v9 + 10] = -1;
            *(uint16 *)vram_buffer1 = v9 + 8;
          }
          Smbll_SetupPlatformRope(enemy_state[v7], ~v18);
          if ((unsigned int)(*(uint16 *)&R0_ & 0x241F) >= *(uint16 *)&tempF3 ||
              (unsigned int)(*(uint16 *)&R0_ & 0x241F) < *(uint16 *)&tempF5) {
            v13 = *(uint16 *)vram_buffer1;
            LOBYTE(v14) = (uint16)(*(uint16 *)&R0_ & 0x1FFF) >> 8;
            HIBYTE(v14) = R0_;
            v15 = *(uint16 *)vram_buffer1;
            *(uint16 *)&vram_buffer1[*(uint16 *)vram_buffer1 + 2] = v14;
            *(uint16 *)&vram_buffer1[v15 + 4] = 768;
            if ((v18 & 0x80) != 0) {
              *(uint16 *)&vram_buffer1[v13 + 6] = 4258;
              if ((*(uint16 *)&vram_buffer1[v13 + 2] & 0xF003) == 0xA000 || (*(uint16 *)&vram_buffer1[v13 + 2] & 0xF003) == 0xB000) {
                v16 = 6207;
              } else {
                v16 = 6307;
              }
              *(uint16 *)&vram_buffer1[v13 + 8] = v16;
            } else {
              *(uint16 *)&vram_buffer1[v13 + 6] = 36;
              *(uint16 *)&vram_buffer1[v13 + 8] = 36;
            }
            *(uint16 *)&vram_buffer1[v13 + 10] = -1;
            *(uint16 *)vram_buffer1 = v13 + 8;
          }
        }
        return;
      }
    }
    Smbll_MovePlatformDown(k);
    goto LABEL_24;
  }
  if (k == R0_) {
LABEL_11:
    Smbll_InitPlatformFall(k, v1);
    return;
  }
  obj_ypos_lo.enemy[v1] = 47;
  Smbll_StopPlatforms(k, v1);
}

void Smbll_SetupPlatformRope(uint8 j, uint8 a) {
  int8 v2;   // al
  bool v3;   // cf
  uint8 v4;  // si

  v2 = obj_xpos_lo.enemy[j] + 8;
  v3 = 0;
  if (!secondary_hard_mode) {
    v3 = __CFADD__(v2, 16);
    v2 = obj_xpos_lo.enemy[j] + 24;
  }
  R2_ = v3 + obj_xpos_hi.enemy[j];
  R0_ = (uint8)(v2 & 0xF0) >> 3;
  v4 = obj_ypos_lo.enemy[j];
  if ((a & 0x80u) != 0)
    v4 += 8;
  R1_ = (2 * (4 * v4 + __CFSHL__(v4, 1)) + __CFSHL__(2 * v4, 1)) & 3 | 0x20;
  R1_ |= 4 * (R2_ & 1);
  R0_ += (4 * v4 + __CFSHL__(v4, 1)) & 0xE0;
  if (obj_ypos_lo.enemy[j] >= 0xE8u)
    R0_ &= ~0x40u;
}

void Smbll_InitPlatformFall(uint8 k, uint8 j) {
  Smbll_GetEnemyOffscreenBits(j);
  Smbll_SetupFloateyNumber(k, 6u);
  score_spr_xpos_lo[k] = rel_xpos_lo.player;
  score_spr_ypos_lo[k] = obj_ypos_lo.player;
  enemy_moving_dir[k] = 1;
  Smbll_StopPlatforms(k, j);
}

void Smbll_StopPlatforms(uint8 k, uint8 j) {
  Smbll_InitVStf(k);
  obj_yspeed.enemy[j] = 0;
  obj_sub_yspeed.enemy[j] = 0;
}

void Smbll_PlatformFall(uint8 k, uint8 j) {
  int8 v2;  // al

  Smbll_MoveFallingPlatform(k);
  Smbll_MoveFallingPlatform(j);
  v2 = enemy_data_d[object_index];
  if (v2 >= 0)
    Smbll_PositionPlayerOnVPlat(v2);
}

void Smbll_YMovingPlatform(uint8 k) {
  if (obj_sub_yspeed.enemy[k] | obj_yspeed.enemy[k] || (obj_sub_ypos.enemy[k] = 0, obj_ypos_lo.enemy[k] >= obj_xpos_fract.enemy[k])) {
    if (obj_ypos_lo.enemy[k] < obj_xspeed.enemy[k])
      Smbll_MovePlatformDown(k);
    else
      Smbll_MovePlatformUp(k);
  } else if ((frame_counter & 7) == 0) {
    ++obj_ypos_lo.enemy[k];
  }
  Smbll_ChkYPCollision(k);
}

void Smbll_ChkYPCollision(uint8 k) {
  if ((enemy_data_d[k] & 0x80u) == 0)
    Smbll_PositionPlayerOnVPlat(k);
}

void Smbll_XMovingPlatform(uint8 k) {
  Smbll_XMoveCntr_Platform(k, 0xEu);
  Smbll_MoveWithXMCntrs(k);
  if ((enemy_data_d[k] & 0x80u) == 0)
    Smbll_PositionPlayerOnHPlat(k);
}

void Smbll_PositionPlayerOnHPlat(uint8 k) {
  uint8 player;  // al

  bool carry = __CFADD__uint8(obj_xpos_lo.player, R0_);

  obj_xpos_lo.player += R0_;
  if ((R0_ & 0x80u) != 0)
    player = obj_xpos_hi.player - 1 + carry;
  else
    player = obj_xpos_hi.player + carry;
  obj_xpos_hi.player = player;
  platform_x_scroll = R0_;
  Smbll_PositionPlayerOnVPlat(k);
}

void Smbll_DropPlatform(uint8 k) {
  if ((enemy_data_d[k] & 0x80u) == 0) {
    Smbll_MoveDropPlatform(k);
    Smbll_PositionPlayerOnVPlat(k);
  }
}

void Smbll_RightPlatform(uint8 k) {
  R0_ = Smbll_MoveEnemyHoriz(k);
  if ((enemy_data_d[k] & 0x80u) == 0) {
    obj_xspeed.enemy[k] = 16;
    Smbll_PositionPlayerOnHPlat(k);
  }
}

void Smbll_MoveLargeLiftPlat(uint8 k) {
  Smbll_MoveLiftPlatforms(k);
  Smbll_ChkYPCollision(k);
}

void Smbll_MoveSmallPlatform(uint8 k) {
  Smbll_MoveLiftPlatforms(k);
  Smbll_ChkSmallPlatCollision(k);
}

void Smbll_MoveLiftPlatforms(uint8 k) {
  uint8 v1;  // al
  bool v2;   // cf

  if (!timer_control) {
    v1 = obj_sub_ypos.enemy[k];
    v2 = __CFADD__(obj_sub_yspeed.enemy[k], v1);
    obj_sub_ypos.enemy[k] = obj_sub_yspeed.enemy[k] + v1;
    obj_ypos_lo.enemy[k] += obj_yspeed.enemy[k] + v2;
  }
}

void Smbll_ChkSmallPlatCollision(uint8 k) {
  uint8 v1;  // al

  v1 = enemy_data_d[k];
  if (v1) {
    if (v1 != 0xFF)
      Smbll_PositionPlayerOnS_Plat(k, v1);
  }
}

void Smbll_OffscreenBoundsCheck(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di
  int8 v3;   // cf
  int8 v4;   // tt

  if (enemy_id[k] != 20) {
    v1 = screen_left_xpos_lo;
    v2 = enemy_id[k];
    v3 = v2 >= 5u;
    if (v2 == 5 || (v3 = v2 >= 4u, v2 == 4) || (v3 = v2 >= 0xDu, v2 == 13)) {
      v4 = v3;
      v3 = __CFADD__(v3, screen_left_xpos_lo) | __CFADD__(v3 + screen_left_xpos_lo, 56);
      v1 = v4 + screen_left_xpos_lo + 56;
    }
    R1_ = v1 - (!v3 + 72);
    R0_ = screen_left_xpos_hi - (v1 < (uint8)(!v3 + 72));
    R3_ = screen_right_xpos + 72;
    R2_ = __CFADD__(screen_right_xpos, 72) + screen_right_xpos_hi;
    if ((int8)(obj_xpos_hi.enemy[k] - ((obj_xpos_lo.enemy[k] < R1_) + R0_)) < 0 ||
        (int8)(obj_xpos_hi.enemy[k] - ((obj_xpos_lo.enemy[k] < R3_) + R2_)) >= 0 && enemy_state[k] != 5 && v2 != 13 && v2 != 4 &&
            v2 != 48 && v2 != 49 && v2 != 50) {
      Smbll_EraseEnemyObject(k);
    }
  }
}

void Smbll_ClearBowserVar0F4() {
  if (cutscene_0EC4) {
    ++bowser_var0201;
    bowser_var0F4C = 0;
  }
}

void Smbll_FireballEnemyCollision(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di
  uint8 v3;  // si
  uint8 v4;  // al

  v1 = fireball_state[k];
  if (v1 && !__CFSHL__(v1, 1) && !(frame_counter & 1)) {
    v2 = 4 * k + 44;
    v3 = 8;
    do {
      R1_ = v3;
      if ((enemy_state[v3] & 0x20) == 0) {
        if (enemy_flag[v3]) {
          v4 = enemy_id[v3];
          if ((v4 < 0x24u || v4 >= 0x2Bu) && (v4 != 6 || enemy_state[v3] < 2u) && !spr_array_D[v3]) {
            tempE4 = v3;
            if (Smbll_SprObjectCollisionCore(4 * v3 + 4, v2) & 1) {
              fireball_state[object_index] = 0x80;
              Smbll_HandleEnemyFBallCol(R1_);
            }
          }
        }
      }
      v3 = R1_ - 1;
    } while ((int8)(R1_ - 1) >= 0);
  }
}

void Smbll_HandleEnemyFBallCol(uint8 k) {
  uint8 v1;   // si
  int8 v2;    // al
  uint8 v3;   // al
  uint8 v4;   // di
  uint8 v5;   // al
  int8 v6;    // si
  uint8 v7;   // al
  uint8 v8;   // si
  uint8 v9;   // al
  uint8 v10;  // [rsp+47h] [rbp-1h]

  Smbll_RelativeEnemyPosition(k);
  sound_ch1 = 1;
  v1 = R1_;
  v2 = enemy_flag[R1_];
  if (v2 < 0) {
    v1 = v2 & 0xF;
    if (enemy_id[v2 & 0xF] == 45)
      goto LABEL_6;
    v1 = R1_;
  }
  v3 = enemy_id[v1];
  if (v3 == 2)
    return;
  if (v3 != 45) {
    if (v3 != 8 && v3 != 12 && v3 < 0x15u)
      Smbll_ShellOrBlockDefeat(v1);
    return;
  }
LABEL_6:
  bowser_var014B = 8;
  bowser_var0F4C = 24;
  if (--bowser_hit_points) {
    if (bowser_hit_points == 1) {
      bowser_woozy_effect_animation_frame = 0;
      bowser_feeling_woozy_flag = 1;
    }
  } else {
    bowser_var014B = 8;
    bowser_var0F4C = -1;
    Smbll_InitVStf(v1);
    obj_xspeed.enemy[v1] = 0;
    enemy_frenzy_buffer = 0;
    obj_yspeed.enemy[v1] = -2;
    v4 = world_number;
    v5 = kBowserIdentities[world_number];
    enemy_id[v1] = v5;
    bowser_enemy_slot_plus1 = v1 + 1;
    if (v5 != 45) {
      v10 = v1;
      if (area_data_addr_index != 33) {
        obj_xspeed.bubble[0] = v1 + 1;
        v6 = 8;
        while (1) {
          v7 = enemy_id[(uint8)v6--];
          if (v6 < 0)
            break;
          if (v7 == 45) {
            v8 = v6 + 1;
            enemy_flag[v8] = 0;
            enemy_id[v8] = 0;
            break;
          }
        }
      }
      v1 = v10;
    }
    v9 = 32;
    if (v4 < 3u)
      v9 = 35;
    enemy_state[v1] = v9;
    Smbll_sub_DDAE(R1_, 9);
  }
}

void Smbll_ShellOrBlockDefeat(uint8 k) {
  uint8 v1;  // al
  bool v2;   // cf

  v1 = enemy_id[k];
  v2 = v1 >= 4u;
  if (v1 == 4 || (v2 = v1 >= 0xDu, v1 == 13)) {
    v1 = v2 + obj_ypos_lo.enemy[k] + 24;
    if (enemy_id[k] == 4)
      v1 = v2 + obj_ypos_lo.enemy[k] - 25;
    obj_ypos_lo.enemy[k] = v1;
  }
  Smbll_ChkToStunEnemies(k, v1);
  enemy_state[k] = enemy_state[k] & 0x1F | 0x20;
  uint8 v3 = 2;
  if (enemy_id[k] == 5)
    v3 = 6;
  else if (enemy_id[k] == 6)
    v3 = 1;
  Smbll_sub_DDAE(k, v3);
}

void Smbll_sub_DDAE(uint8 k, uint8 a) {
  if (Smbll_SetupFloateyNumber(k, a) != 3)
    sound_ch1 = 3;
}

void Smbll_PlayerHammerCollision(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // si

  if (frame_counter & 1 && !(offscreen_bits.misc | (uint8)(timer_control | offscreen_bits.player))) {
    v1 = Smbll_PlayerCollisionCore(4 * k + 52);
    v2 = object_index;
    if (v1 & 1) {
      if (!misc_collision_flag[object_index]) {
        misc_collision_flag[object_index] = 1;
        obj_xspeed.misc[v2] = -obj_xspeed.misc[v2];
        if (!player_star_power_timer)
          Smbll_InjurePlayer();
      }
    } else {
      misc_collision_flag[object_index] = 0;
    }
  }
}

void Smbll_HandlePowerUpCollision(uint8 k) {
  uint8 v1;  // al

  Smbll_EraseEnemyObject2(k);
  if (power_up_type == 4) {
    Smbll_InjurePlayer();
    return;
  }
  Smbll_SetupFloateyNumber1(k, 6u);
  sound_ch1 = 10;
  if (power_up_type < 2u) {
    if (player_status) {
      if (player_status != 1)
        return;
      player_status = 2;
      Smbll_GetPlayerColors();
      v1 = 12;
    } else {
      player_status = 1;
      v1 = 9;
    }
    Smbll_SetPRout(0, v1);
  } else if (power_up_type == 3) {
    floateynum_control[k] = 11;
    sound_ch1 = 0;
  } else {
    player_star_power_timer = 35;
    music_ch1 = 13;
  }
}

void Smbll_nullsub_3() {
  ;
}

void Smbll_PlayerEnemyCollision(uint8 k) {
  uint8 EnemyBoundBoxOfs;  // di
  uint8 v2;                // al
  uint8 v3;                // si
  uint8 v4;                // di
  uint8 v5;                // al
  uint8 v6;                // di

  if (!(frame_counter & 1) && !(Smbll_CheckPlayerVertical() & 1) && (k == 9 && rel_xpos_lo.enemy > 0xF3u || !spr_array_D[k]) &&
      game_engine_subroutine == 8 && (enemy_state[k] & 0x20) == 0) {
    EnemyBoundBoxOfs = Smbll_GetEnemyBoundBoxOfs();
    v2 = Smbll_PlayerCollisionCore(EnemyBoundBoxOfs);
    v3 = object_index;
    if (v2 & 1) {
      v4 = enemy_id[object_index];
      if (v4 == 46) {
        Smbll_HandlePowerUpCollision(object_index);
        return;
      }
      if (player_star_power_timer) {
        Smbll_ShellOrBlockDefeat(object_index);
        return;
      }
      if (!(spr_array_D[object_index] | enemy_collision_bits[object_index] & 1)) {
        enemy_collision_bits[object_index] |= 1u;
        if (v4 == 18 || v4 == 51)
          goto LABEL_19;
        if (v4 == 13 || v4 == 4 || v4 == 12 || v4 >= 0x15u || !area_type) {
          Smbll_InjurePlayer();
          return;
        }
        if (__CFSHL__(enemy_state[v3], 1) || (enemy_state[v3] & 7u) < 2) {
LABEL_19:
          Smbll_ChkForPlayerInjury(v3);
          return;
        }
        if (enemy_id[v3] != 6) {
          sound_ch1 = 3;
          Smbll_InitializeContactSprite(v3);
          enemy_array_F40[v3] = 0;
          enemy_state[v3] |= 0x80u;
          obj_xspeed.enemy[v3] = kKickedShellXSpdData[Smbll_EnemyFacePlayer(v3)];
          v5 = stomp_chain_counter + 3;
          v6 = *(&enemy_interval_timer + v3);
          if (v6 < 3u)
            v5 = kKickedShellPtsData[v6];
          Smbll_SetupFloateyNumber(v3, v5);
        }
      }
    } else {
      enemy_collision_bits[object_index] &= ~1u;
    }
  }
}

void Smbll_ChkForPlayerInjury(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di
  uint8 v4;  // [rsp+47h] [rbp-1h]

  if ((int8)(obj_yspeed.player - 1) >= 0 || enemy_id[k] >= 7u && (uint8)(obj_ypos_lo.player + 12) < obj_ypos_lo.enemy[k] || stomp_timer) {
    if (enemy_id[k] == 18)
      goto LABEL_24;
    sound_ch1 = 2;
    v1 = enemy_id[k];
    v2 = 0;
    if (v1 == 20 || v1 == 8 || v1 == 51 || v1 == 12 || (v2 = 1, v1 == 5) || (v2 = 2, v1 == 17) || (v2 = 3, v1 == 7)) {
      Smbll_SetupFloateyNumber(k, kbyte_DE95[v2]);
      v4 = enemy_moving_dir[k];
      Smbll_SetStun(k, v4);
      enemy_moving_dir[k] = v4;
      enemy_state[k] = 32;
      Smbll_InitVStf(k);
      obj_xspeed.enemy[k] = 0;
      Smbll_sub_DF21(k);
    } else if (v1 < 9u) {
      enemy_state[k] = 4;
      ++stomp_chain_counter;
      Smbll_SetupFloateyNumber(k, stomp_timer + stomp_chain_counter);
      ++stomp_timer;
      *(&enemy_interval_timer + k) = kbyte_DF02[primary_hard_mode];
      Smbll_sub_DF21(k);
    } else {
      Smbll_sub_DF21(k);
      enemy_id[k] = enemy_id[k] & 1;
      enemy_state[k] = 0;
      Smbll_SetupFloateyNumber(k, 3u);
      Smbll_InitVStf(k);
      obj_xspeed.enemy[k] = kDemotedKoopaXSpdData[Smbll_EnemyFacePlayer(k)];
    }
  } else if (!player_hurt_timer) {
    if (rel_xpos_lo.player >= rel_xpos_lo.enemy) {
      if (enemy_moving_dir[k] == 1) {
LABEL_24:
        Smbll_InjurePlayer();
        return;
      }
    } else if (enemy_moving_dir[k] != 1) {
      goto LABEL_24;
    }
    Smbll_EnemyTurnAround(k);
    Smbll_InjurePlayer();
  }
}

void Smbll_InjurePlayer() {
  if (!__PAIR16__(player_star_power_timer, player_hurt_timer))
    Smbll_ForceInjury(player_star_power_timer | player_hurt_timer);
}

void Smbll_ForceInjury(uint8 a) {
  if (player_status) {
    player_status = a;
    player_hurt_timer = 8;
    sound_ch1 = 4;
    Smbll_GetPlayerColors();
    Smbll_SetPROut_1(0xAu);
  } else {
    Smbll_KillPlayer(player_status);
  }
}

void Smbll_SetPROut_1(uint8 a) {
  Smbll_SetPRout(1u, a);
}

void Smbll_SetPRout(uint8 j, uint8 a) {
  game_engine_subroutine = a;
  player_state = j;
  timer_control = -1;
  scroll_amount = 0;
}

void Smbll_KillPlayer(uint8 k) {
  obj_xspeed.player = k;
  player_size = 1;
  Smbll_GetPlayerColors();
  sound_ch2 |= 0x20u;
  music_ch1 = 9;
  var0E67 = 9;
  scroll_lock = 9;
  obj_yspeed.player = -4;
  Smbll_SetPROut_1(0xBu);
}

void Smbll_sub_DF21(uint8 k) {
  uint8 v1;  // di

  v1 = -6;
  if (enemy_id[k] == 15 || enemy_id[k] == 16)
    v1 = -8;
  obj_yspeed.player = v1;
}

uint8 Smbll_EnemyFacePlayer(uint8 k) {
  uint8 v1;  // di

  v1 = 1;
  if ((Smbll_PlayerEnemyDiff(k) & 0x80u) != 0)
    v1 = 2;
  enemy_moving_dir[k] = v1;
  return v1 - 1;
}

void Smbll_SetupFloateyNumber1(uint8 k, uint8 a) {
  floateynum_control[k] = a;
  floateynum_timer[k] = 48;
  score_spr_ypos_lo[k] = obj_ypos_lo.enemy[k];
  score_spr_xpos_lo[k] = rel_xpos_lo.enemy;
  tempED = obj_xpos_lo.enemy[k];
  tempEE = obj_xpos_hi.enemy[k];
  floateynum_xpos_word[(uint8)(2 * k) >> 1] = *(uint16 *)&tempED - screen_left_xpos16;
}

uint8 Smbll_SetupFloateyNumber(uint8 k, uint8 a) {
  if (a >= floateynum_control[k]) {
    floateynum_control[k] = a;
    floateynum_timer[k] = 48;
    score_spr_ypos_lo[k] = obj_ypos_lo.enemy[k];
    tempE4 = obj_xpos_lo.enemy[k];
    tempE5 = obj_xpos_hi.enemy[k];
    a = tempE4 - screen_left_xpos16;
    floateynum_xpos_word[(uint8)(2 * k) >> 1] = *(uint16 *)&tempE4 - screen_left_xpos16;
    score_spr_xpos_lo[k] = a;
  }
  return a;
}

void Smbll_EnemiesCollision(uint8 k) {
  uint8 v1;                // al
  uint8 EnemyBoundBoxOfs;  // di
  uint8 v3;                // si
  uint8 v4;                // al
  uint8 v5;                // al
  uint8 v6;                // si
  uint8 v7;                // di
  uint8 v8;                // [rsp+47h] [rbp-1h]

  if (frame_counter & 1) {
    if (area_type) {
      v1 = enemy_id[k];
      if (v1 < 0x15u && v1 != 17 && v1 != 13 && v1 != 4 && !spr_array_D[k]) {
        EnemyBoundBoxOfs = Smbll_GetEnemyBoundBoxOfs();
        v3 = k - 1;
        if ((v3 & 0x80u) == 0) {
          while (1) {
            R1_ = v3;
            v8 = EnemyBoundBoxOfs;
            if (!enemy_flag[v3])
              goto LABEL_22;
            v4 = enemy_id[v3];
            if (v4 >= 0x15u || v4 == 17 || v4 == 13 || v4 == 4 || spr_array_D[v3])
              goto LABEL_22;
            v5 = Smbll_SprObjectCollisionCore(4 * v3 + 4, EnemyBoundBoxOfs);
            v6 = object_index;
            v7 = R1_;
            if (!(v5 & 1)) {
              enemy_collision_bits[R1_] &= kClearBitsMask[object_index];
              goto LABEL_22;
            }
            if (((enemy_state[R1_] | enemy_state[object_index]) & 0x80u) != 0)
              goto LABEL_20;
            if ((kSetBitsMask[object_index] & enemy_collision_bits[R1_]) == 0)
              break;
LABEL_22:
            EnemyBoundBoxOfs = v8;
            v3 = R1_ - 1;
            if ((int8)(R1_ - 1) < 0)
              return;
          }
          enemy_collision_bits[R1_] |= kSetBitsMask[object_index];
LABEL_20:
          Smbll_ProcEnemyCollisions(v6, v7);
          goto LABEL_22;
        }
      }
    }
  }
}

void Smbll_ProcEnemyCollisions(uint8 k, uint8 j) {
  uint8 v2;  // si
  uint8 v3;  // al

  if (((enemy_state[k] | enemy_state[j]) & 0x20) != 0)
    return;
  if (enemy_id[k] == 5)
    enemy_state[k] = 0;
  if (enemy_state[k] >= 6u) {
    if (__CFSHL__(enemy_state[j], 1)) {
      Smbll_SetupFloateyNumber(k, 6u);
      Smbll_ShellOrBlockDefeat(k);
      j = R1_;
    }
    Smbll_ShellOrBlockDefeat(j);
    Smbll_SetupFloateyNumber(R1_, shell_chain_counter[object_index] + 4);
    v2 = object_index;
    ++shell_chain_counter[object_index];
    goto LABEL_12;
  }
  if (enemy_state[j] < 6u) {
    Smbll_EnemyTurnAround(j);
    Smbll_EnemyTurnAround(object_index);
    return;
  }
  if (enemy_id[j] != 5) {
    Smbll_ShellOrBlockDefeat(k);
    Smbll_InitializeContactSprite(k);
    Smbll_SetupFloateyNumber(object_index, shell_chain_counter[R1_] + 4);
    v2 = R1_;
    ++shell_chain_counter[R1_];
LABEL_12:
    v3 = shell_chain_counter[v2] + 18;
    if (v3 >= 0x1Au)
      v3 = 0;
    sound_ch1 = v3;
  }
}

void Smbll_EnemyTurnAround(uint8 k) {
  uint8 v1;  // al

  v1 = enemy_id[k];
  if (v1 != 13 && v1 != 4 && v1 != 17 && v1 != 5 && (v1 == 18 || v1 == 14 || v1 < 7u))
    Smbll_ReverseXSpeed(k);
}

void Smbll_ReverseXSpeed(uint8 k) {
  obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
  enemy_moving_dir[k] ^= 3u;
}

void Smbll_LargePlatformCollision(uint8 k) {
  enemy_data_d[k] = -1;
  if (!timer_control && (enemy_state[k] & 0x80u) == 0) {
    if (enemy_id[k] == 36) {
      Smbll_ChkForPlayerC_LargeP(enemy_state[k]);
    }
    Smbll_ChkForPlayerC_LargeP(k);
  }
}

void Smbll_ChkForPlayerC_LargeP(uint8 k) {
  uint8 j;  // di

  if (!Smbll_CheckPlayerVertical()) {
    j = Smbll_GetEnemyBoundBoxOfsArg(k);
    R0_ = obj_ypos_lo.enemy[k];
    if (Smbll_PlayerCollisionCore(j))
      Smbll_ProcLPlatCollisions(k, j);
  }
}

void Smbll_SmallPlatformCollision(uint8 k) {
  uint8 EnemyBoundBoxOfs;  // di

  if (!timer_control) {
    enemy_data_d[k] = timer_control;
    if (!(Smbll_CheckPlayerVertical() & 1)) {
      R0_ = 2;
      do {
        EnemyBoundBoxOfs = Smbll_GetEnemyBoundBoxOfs();
        if ((offscreen_bits.enemy & 2) != 0)
          break;
        if (*(&player_hitbox_top + EnemyBoundBoxOfs) >= 0x20u && Smbll_PlayerCollisionCore(EnemyBoundBoxOfs) & 1) {
          Smbll_ProcLPlatCollisions(object_index, EnemyBoundBoxOfs);
          return;
        }
        *(&player_hitbox_top + EnemyBoundBoxOfs) += 0x80;
        *(&player_hitbox_bottom + EnemyBoundBoxOfs) += 0x80;
        --R0_;
      } while (R0_);
    }
  }
}

void Smbll_ProcLPlatCollisions(uint8 k, uint8 j) {
  uint8 v2;  // al
  uint8 v3;  // di

  if ((uint8)(*(&player_hitbox_bottom + j) - player_hitbox_top) < 4u && (obj_yspeed.player & 0x80u) != 0)
    obj_yspeed.player = 1;
  if ((uint8)(player_hitbox_bottom - *(&player_hitbox_top + j)) >= 6u || (obj_yspeed.player & 0x80u) != 0) {
    R0_ = 1;
    if ((uint8)(player_hitbox_right - *(&player_hitbox_left + j)) < 8u ||
        (++R0_, (uint8)(*(&player_hitbox_right + j) - (player_hitbox_left + 1)) < 9u)) {
      Smbll_ImpedePlayerMove();
    }
  } else {
    v2 = R0_;
    v3 = enemy_id[k];
    if (v3 != 43 && v3 != 44)
      v2 = k;
    enemy_data_d[object_index] = v2;
    player_state = 0;
  }
}

void Smbll_PositionPlayerOnS_Plat(uint8 k, uint8 a) {
  uint8 v2;  // al

  v2 = kPlayerPosSPlatData[a - 1] + obj_ypos_lo.enemy[k];
  if (v2)
    Smbll_CODE_03E2CE(k, v2);
  else
    obj_ypos_hi.player = 2;
}

void Smbll_PositionPlayerOnVPlat(uint8 k) {
  Smbll_CODE_03E2CE(k, obj_ypos_lo.enemy[k]);
}

void Smbll_CODE_03E2CE(uint8 k, uint8 a) {
  if (game_engine_subroutine != 11 && obj_ypos_hi.enemy[k] == 1) {
    obj_ypos_lo.player = a - 32;
    obj_ypos_hi.player = a >= 0x20u;
    if (a < 0x20u) {
      enemy_data_d[k] = 0;
      player_state = 1;
    }
    obj_yspeed.player = 0;
    obj_sub_yspeed.player = 0;
  }
}

uint8 Smbll_CheckPlayerVertical() {
  return (offscreen_bits.player & 0xF0) != 0;
}

uint8 Smbll_GetEnemyBoundBoxOfs() {
  return Smbll_GetEnemyBoundBoxOfsArg(object_index);
}

uint8 Smbll_GetEnemyBoundBoxOfsArg(uint8 a) {
  return 4 * a + 4;
}

void Smbll_PlayerBGCollision() {
  uint8 v0;  // al
  uint8 v1;  // di
  uint8 v2;  // si
  uint8 v3;  // al
  uint8 v6;  // al
  uint8 v8;
  uint8 v9;   // di
  uint8 v10;  // al
  uint8 v12;  // al
  uint8 v13;  // al
  uint8 v16;  // al
  uint8 v17;  // al
  uint8 v18;  // di
  uint8 v19;  // di
  uint8 v20;  // al
  uint8 v22;  // al
  uint8 v25;  // al
  uint8 v27;  // al
  int8 v29;   // al
  uint8 a;    // [rsp+47h] [rbp-1h]

  if (disable_collision_detection || game_engine_subroutine == 11 || game_engine_subroutine < 4u)
    return;
  v0 = 1;
  if (!swimming_flag) {
    if (player_state && player_state != 3)
      goto LABEL_9;
    v0 = 2;
  }
  player_state = v0;
LABEL_9:
  if (obj_ypos_hi.player != 1)
    return;
  player_collision_bits = -1;
  if (obj_ypos_lo.player >= 0xCFu)
    return;
  v1 = 2;
  if (!crouching_flag && !player_size)
    v1 = swimming_flag != 0;
  tempEB = kBlockBufferAdderData[v1];
  v2 = player_size;
  if (crouching_flag)
    v2 = player_size + 1;
  if (obj_ypos_lo.player < kbyte_E21C[v2])
    goto LABEL_29;
  tempE4 = 1;
  v3 = Smbll_BlockBufferColli_Head(tempEB);
  if (!v3)
    goto LABEL_29;
  v6 = v3;
  if (Smbll_CheckForCoinMTiles(v3))
    goto LABEL_61;
  if ((obj_yspeed.player & 0x80u) == 0 || R4_ < 4u)
    goto LABEL_29;
  v8 = v6;
  if (Smbll_CheckForSolidMTiles(v6)) {
    if (v8 != 47)
      sound_ch1 = 1;
  } else if (area_type && !block_bounce_timer) {
    Smbll_PlayerHeadCollision(v8);
    goto LABEL_29;
  }
  obj_yspeed.player = 1;
LABEL_29:
  v9 = tempEB;
  if (obj_ypos_lo.player >= 0xCFu)
    goto LABEL_45;
  tempE4 = 0;
  v10 = Smbll_BlockBufferColli_Feet(tempEB);
  v12 = v10;
  if (Smbll_CheckForCoinMTiles(v10)) {
LABEL_61:
    Smbll_HandleCoinMetatile();
    return;
  }
  a = v12;
  tempE4 = 0;
  R0_ = Smbll_BlockBufferColli_Feet(v9 + 1);
  v13 = a;
  R1_ = a;
  if (!a) {
    if (!R0_)
      goto LABEL_45;
    v13 = R0_;
    if (Smbll_CheckForCoinMTiles(v13))
      goto LABEL_61;
  }
  v16 = v13;
  if (!Smbll_CheckForClimbMTiles(v13) && (obj_yspeed.player & 0x80u) == 0) {
    if (v16 == 0xFE) {
      Smbll_HandleAxeMetatile();
      return;
    }
    v17 = v16;
    if (Smbll_ChkInvisibleMTiles(v16)) {
      if (!jumpspring_anim_ctrl) {
        if (R4_ >= 5u) {
          R0_ = player_moving_dir;
          Smbll_ImpedePlayerMove();
          return;
        }
        Smbll_ChkForLandJumpSpring(v17);
        obj_ypos_lo.player &= 0xF0u;
        Smbll_HandlePipeEntry();
        obj_yspeed.player = 0;
        obj_sub_yspeed.player = 0;
        stomp_chain_counter = 0;
      }
      player_state = 0;
    }
  }
LABEL_45:
  v18 = tempEB + 2;
  R0_ = 2;
  while (1) {
    v19 = v18 + 1;
    tempEB = v19;
    if (obj_ypos_lo.player >= 0x20u) {
      if (obj_ypos_lo.player >= 0xE4u)
        return;
      tempE4 = 0;
      v20 = Smbll_BlockBufferColli_Side(v19);
      if (v20) {
        if (v20 != 37 && v20 != 118) {
          v22 = v20;
          if (!Smbll_CheckForClimbMTiles(v20))
            break;
        }
      }
    }
    v18 = tempEB + 1;
    if (obj_ypos_lo.player < 8u || obj_ypos_lo.player >= 0xD0u)
      return;
    tempE4 = 0;
    v22 = Smbll_BlockBufferColli_Side(v18);
    if (v22)
      break;
    if (!--R0_)
      return;
  }
  if (Smbll_ChkInvisibleMTiles(v22)) {
    v25 = v22;
    if (Smbll_CheckForClimbMTiles(v22)) {
      Smbll_HandleClimbing(v25);
      return;
    }
    v27 = v25;
    if (Smbll_CheckForCoinMTiles(v25))
      goto LABEL_61;
    v29 = v27;
    if (Smbll_ChkJumpspringMetatiles(v27)) {
      if (jumpspring_anim_ctrl)
        return;
      goto LABEL_76;
    }
    if (player_state || player_facing_dir != 1 || v29 != 119 && v29 != 40) {
LABEL_76:
      Smbll_ImpedePlayerMove();
      return;
    }
    if (player_sprattrib && !play_sound_flag_var009a) {
      sound_ch1 = 4;
      play_sound_flag_var009a = 4;
      player_star_power_timer = 0;
    }
    player_sprattrib &= 0xCFu;
    if ((obj_xpos_lo.player & 0xF) != 0)
      change_area_timer = kAreaChangeTimerData[screen_left_xpos_hi != 0];
    if (game_engine_subroutine == 8)
      game_engine_subroutine = 2;
  }
}

void Smbll_HandleCoinMetatile() {
  Smbll_EraseCoinMetatile();
  ++coin_tally_for_1ups;
  Smbll_GiveOneCoin();
}

void Smbll_HandleAxeMetatile() {
  uint8 i;  // si

  game_mode_task = 0;
  game_mode = 2;
  if (ReadReg(APUI02) != 11)
    music_ch1 = -16;
  obj_xspeed.player = 24;
  for (i = 0; i != 9; ++i) {
    if (enemy_id[i] == 45 && enemy_flag[i] == 1) {
      rel_xpos_lo.enemy = obj_xpos_lo.enemy[i] - layer1_xpos_lo;
      rel_ypos.enemy = obj_ypos_lo.enemy[i];
      Smbll_BowserDraw(i);
    }
  }
  Smbll_EraseCoinMetatile();
}

void Smbll_EraseCoinMetatile() {
  RomPtr_RAM(*(uint16 *)&R6_)[R2_] = 0;
  Smbll_RemoveCoin_Axe();
}

void Smbll_HandleClimbing(uint8 a) {
  uint8 v1;  // si

  if (R4_ >= 6u && R4_ < 0xAu) {
    if (a == 45 || a == 46) {
      if (game_engine_subroutine != 5) {
        ++scroll_lock;
        if (game_engine_subroutine != 4) {
          Smbll_KillEnemies(0x33u);
          Smbll_SpawnCastleTilesWithPriority();
          music_ch1 = -16;
          sound_ch1 = 70;
          flagpole_sound_queue = 35;
          v1 = 4;
          climbing_ypos_unk = obj_ypos_lo.player;
          do {
            if (obj_ypos_lo.player >= kFlagpoleYPosData[v1])
              break;
            --v1;
          } while (v1);
          flagpole_score = v1;
          if (score_and_coin_display[4] == score_and_coin_display[5] && score_and_coin_display[4] == level_timer_ones)
            flagpole_score = 5;
        }
        game_engine_subroutine = 4;
      }
    } else if (a == 47 && obj_ypos_lo.player < 0x20u) {
      game_engine_subroutine = 1;
    }
    player_state = 3;
    obj_xspeed.player = 0;
    player_x_move_force = 0;
    if (vine_flag_offset && rel_xpos_lo.enemy >= 0xF8u) {
      tempE5 = obj_xpos_hi.enemy[9];
      tempE4 = obj_xpos_lo.enemy[9];
      *(uint16 *)&tempE4 += 7;
      obj_xpos_lo.player = tempE4;
      obj_xpos_hi.player = tempE5;
      player_facing_dir = 2;
    } else {
      if ((uint8)(obj_xpos_lo.player - screen_left_xpos_lo) < 0x10u)
        player_facing_dir = 2;
      obj_xpos_lo.player = kClimbXPosAdder[player_facing_dir - 1] + 16 * R6_;
      if (!R6_)
        obj_xpos_hi.player = kClimbPLocAdder[player_facing_dir - 1] + screen_right_xpos_hi;
    }
  }
}

uint8 Smbll_ChkInvisibleMTiles(uint8 a) {
  return a != 92 && a != 93 && a != 94 && a != 96 && a != 97;
}

void Smbll_ChkForLandJumpSpring(uint8 a) {
  if (Smbll_ChkJumpspringMetatiles(a) & 1) {
    vertical_force = 112;
    vertical_force_down = 112;
    jumpspring_force = -7;
    jumpspring_timer = 3;
    jumpspring_anim_ctrl = 1;
  }
}

uint8 Smbll_ChkJumpspringMetatiles(uint8 a) {
  uint8 v1;  // cf

  if (a == 110)
    return 1;
  v1 = 0;
  if (a == 111)
    return 1;
  return v1;
}

void Smbll_HandlePipeEntry() {
  if ((buttons_up_down & 4) != 0 && R0_ == 23 && R1_ == 22) {
    change_area_timer = 48;
    game_engine_subroutine = 3;
    player_hurt_timer = 4;
    player_star_power_timer = 0;
    player_sprattrib = 0;
    if (warp_zone_control) {
      if (world_number < 8u)
        smbll_varF2B = 1;
      world_number = kWarpZoneNumbers[warp_zone_control & 0xF] - 1;
      area_pointer = kAreaAddrOffsets[kWorldAddrOffsets[world_number]];
      entrance_page = 0;
      area_number = 0;
      level_number = 0;
      alt_entrance_ctrl = 0;
      ++hidden_1up_flag;
      ++fetch_new_game_timer_flag;
      music_ch1 = -13;
      unused_byte_7E0E1A = -13;
    }
    sound_ch1 = 4;
  }
}

void Smbll_ImpedePlayerMove() {
  uint8 v0;  // si
  uint8 v1;  // al
  uint8 v2;  // di
  bool v3;   // cf

  if (R0_ == 1) {
    v0 = R0_;
    if ((obj_xspeed.player & 0x80u) != 0)
      goto LABEL_9;
    v1 = -1;
  } else {
    v0 = 2;
    if ((int8)(obj_xspeed.player - 1) >= 0)
      goto LABEL_9;
    v1 = 1;
  }
  side_collision_timer = 16;
  v2 = 0;
  obj_xspeed.player = 0;
  if (sign8(v1))
    v2 = -1;
  R0_ = v2;
  v3 = __CFADD__(obj_xpos_lo.player, v1);
  obj_xpos_lo.player += v1;
  obj_xpos_hi.player += v2 + v3;
LABEL_9:
  player_collision_bits &= ~v0;
}

uint8 Smbll_CheckForSolidMTiles(uint8 a) {
  return a >= kSolidMTileUpperExt[Smbll_GetMTileAttrib(a)];
}

uint8 Smbll_CheckForClimbMTiles(uint8 a) {
  return a >= kClimbMTileUpperExt[Smbll_GetMTileAttrib(a)];
}

uint8 Smbll_CheckForCoinMTiles(uint8 a) {
  if (a != 0xEA && a != 0xEB)
    return 0;
  sound_ch3 = 1;
  return 1;
}

uint8 Smbll_GetMTileAttrib(uint8 a) {
  return 2 * (4 * (a & 0xC0) + __CFSHL__(a & 0xC0, 1)) + __CFSHL__(2 * (a & 0xC0), 1);
}

void Smbll_EnemyToBGCollisionDet(uint8 k) {
  uint8 v1;   // di
  uint8 v2;   // al
  uint8 v4;   // al
  uint8 v6;   // al
  uint8 v7;   // al
  int8 v8;    // di
  uint8 v9;   // di
  uint8 v10;  // al
  uint8 v11;  // al

  if ((enemy_state[k] & 0x20) != 0)
    return;
  if (!(Smbll_SubtEnemyYPos(k) & 1))
    return;
  v1 = enemy_id[k];
  if (v1 == 18 && obj_ypos_lo.enemy[k] < 0x25u)
    return;
  if (v1 == 14) {
    Smbll_EnemyJump(k);
    return;
  }
  if (v1 != 5) {
    if (v1 != 18 && v1 != 46 && (v1 == 4 || v1 >= 7u))
      return;
    v2 = Smbll_ChkUnderEnemy(k);
    if (!v2)
      goto LABEL_61;
    if (!Smbll_ChkForNonSolids(v2))
      goto LABEL_61;
    if (v2 == 44) {
      v4 = enemy_id[k];
      if (v4 < 0x15u) {
        if (v4 == 6)
          Smbll_KillEnemyAboveBlock(k);
        v4 = Smbll_SetupFloateyNumber(k, 1u);
      }
      Smbll_ChkToStunEnemies(k, v4);
      return;
    }
    if ((uint8)(R4_ - 8) >= 5u) {
LABEL_61:
      if (enemy_id[k] != 3 || enemy_state[k]) {
        v9 = enemy_state[k];
        if (__CFSHL__(v9, 1))
          v10 = enemy_state[k] | 0x40;
        else
          v10 = kEnemyBGCStateData[v9];
        enemy_state[k] = v10;
        Smbll_DoEnemySideCheck(k);
      } else {
        Smbll_ChkForBump_HammerBroJ(k);
      }
      return;
    }
    if ((enemy_state[k] & 0x40) == 0) {
      if (__CFSHL__(enemy_state[k], 1) || (v6 = enemy_state[k]) == 0) {
        Smbll_DoEnemySideCheck(k);
        return;
      }
      if (v6 != 5) {
        if (v6 >= 3u)
          return;
        if (enemy_state[k] == 2) {
          v7 = 16;
          if (enemy_id[k] == 18)
            v7 = 0;
          *(&enemy_interval_timer + k) = v7;
          enemy_state[k] = 3;
          Smbll_EnemyLanding(k);
          return;
        }
      }
      if (enemy_id[k] != 6) {
        if (enemy_id[k] != 18 || (enemy_moving_dir[k] = 1, obj_xspeed.enemy[k] = 8, (frame_counter & 7) != 0)) {
          v8 = 1;
          if ((Smbll_PlayerEnemyDiff(k) & 0x80u) != 0)
            v8 = 2;
          if (v8 == enemy_moving_dir[k])
            Smbll_ChkForBump_HammerBroJ(k);
        }
      }
    }
    Smbll_EnemyLanding(k);
    if ((enemy_state[k] & 0x80u) != 0)
      enemy_state[k] &= ~0x40u;
    else
      enemy_state[k] = 0;
    return;
  }
  v11 = Smbll_ChkUnderEnemy(k);
  if (!v11)
    goto LABEL_58;
  if (v11 == 44) {
    Smbll_KillEnemyAboveBlock(k);
    return;
  }
  if (enemy_frame_timer[k]) {
LABEL_58:
    enemy_state[k] |= 1u;
  } else {
    enemy_state[k] &= 0x88u;
    Smbll_EnemyLanding(k);
    Smbll_DoEnemySideCheck(k);
  }
}

void Smbll_ChkToStunEnemies(uint8 k, uint8 a) {
  uint8 v2;  // al

  v2 = enemy_id[k];
  if (v2 >= 9u && v2 < 0x11u) {
    if (v2 == 13) {
      Smbll_SetStun(k, 0xDu);
      return;
    }
    if (v2 == 4) {
      Smbll_SetStun(k, 4u);
      return;
    }
    if (v2 >= 0xDu) {
      v2 &= 1u;
      enemy_id[k] = v2;
    }
  }
  Smbll_SetStun(k, v2);
}

void Smbll_SetStun(uint8 k, uint8 a) {
  uint8 v2;  // al
  uint8 v3;  // di

  if (a != 46 && a != 6)
    enemy_state[k] = 2;
  --obj_ypos_lo.enemy[k];
  --obj_ypos_lo.enemy[k];
  if (enemy_id[k] == 7 || (v2 = -3, !area_type))
    v2 = -1;
  obj_yspeed.enemy[k] = v2;
  v3 = 1;
  if ((Smbll_PlayerEnemyDiff(k) & 0x80u) != 0)
    v3 = 2;
  if (enemy_id[k] != 51 && enemy_id[k] != 8)
    enemy_moving_dir[k] = v3;
  obj_xspeed.enemy[k] = kEnemyBGCXSpdData[(uint8)(v3 - 1)];
}

void Smbll_DoEnemySideCheck(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al

  if (obj_ypos_lo.enemy[k] >= 0x20u) {
    v1 = 22;
    tempEB = 2;
    while (1) {
      if (tempEB == enemy_moving_dir[k]) {
        v2 = Smbll_BlockBufferChk_Enemy(k, v1, 1u);
        if (v2) {
          if (Smbll_ChkForNonSolids(v2))
            break;
        }
      }
      --tempEB;
      if (++v1 >= 0x18u)
        return;
    }
    Smbll_ChkForBump_HammerBroJ(k);
  }
}

void Smbll_ChkForBump_HammerBroJ(uint8 k) {
  if (k != 9 && __CFSHL__(enemy_state[k], 1)) {
    sound_ch1 = 1;
    Smbll_InitializeContactSprite(k);
  }
  if (enemy_id[k] == 5) {
    R0_ = 0;
    Smbll_CODE_03CEC7(k, 0xFAu);
  } else {
    Smbll_ReverseXSpeed(k);
  }
}
// 11035: conditional instruction was optimized away because si.1!=9

uint8 Smbll_PlayerEnemyDiff(uint8 k) {
  uint8 v1;  // al

  v1 = obj_xpos_lo.enemy[k];
  R0_ = v1 - obj_xpos_lo.player;
  return obj_xpos_hi.enemy[k] - ((v1 < obj_xpos_lo.player) + obj_xpos_hi.player);
}

void Smbll_EnemyLanding(uint8 k) {
  Smbll_InitVStf(k);
  obj_ypos_lo.enemy[k] = obj_ypos_lo.enemy[k] & 0xF0 | 8;
}

uint8 Smbll_SubtEnemyYPos(uint8 k) {
  return (uint8)(obj_ypos_lo.enemy[k] + 62) >= 0x44u;
}

void Smbll_EnemyJump(uint8 k) {
  uint8 v1;  // al

  if (Smbll_SubtEnemyYPos(k) & 1) {
    if ((uint8)(obj_yspeed.enemy[k] + 2) >= 3u) {
      v1 = Smbll_ChkUnderEnemy(k);
      if (v1) {
        if (Smbll_ChkForNonSolids(v1)) {
          Smbll_EnemyLanding(k);
          obj_yspeed.enemy[k] = -3;
        }
      }
    }
  }
  Smbll_DoEnemySideCheck(k);
}

void Smbll_KillEnemyAboveBlock(uint8 k) {
  Smbll_ShellOrBlockDefeat(k);
  obj_yspeed.enemy[k] = -4;
}

uint8 Smbll_ChkUnderEnemy(uint8 k) {
  return Smbll_BlockBufferChk_Enemy(k, 0x15u, 0);
}

uint8 Smbll_ChkForNonSolids(uint8 a) {
  return (a != 47 && a != 0xEA && a != 0xEB && a != 92 && a != 93 && a != 94 && a != 96 && a != 97);
}

void Smbll_FireballBGCollision(uint8 k) {
  uint8 v1;  // al

  if (obj_ypos_lo.fireball[k] >= 0x18u && (v1 = Smbll_BlockBufferChk_FBall(k)) != 0 && Smbll_ChkForNonSolids(v1)) {
    if ((obj_yspeed.fireball[k] & 0x80u) != 0 || fire_spr_hit_ground_flag[k]) {
      fireball_state[k] = 0x80;
      sound_ch1 = 1;
    } else {
      obj_yspeed.fireball[k] = -3;
      fire_spr_hit_ground_flag[k] = 1;
      obj_ypos_lo.fireball[k] &= 0xF8u;
    }
  } else {
    fire_spr_hit_ground_flag[k] = 0;
  }
}

void Smbll_GetFireballBoundBox(uint8 k) {
  Smbll_FBallB(k + 11, 2u);
}

void Smbll_GetMiscBoundBox(uint8 k) {
  Smbll_FBallB(k + 13, 6u);
}

void Smbll_FBallB(uint8 k, uint8 j) {
  uint8 v2;  // di

  v2 = Smbll_BoundingBoxCore(k, j);
  Smbll_CheckRightScreenBBox(k, v2);
}

void Smbll_GetEnemyBoundBox(uint8 k) {
  R0_ = 72;
  Smbll_GetMaskedOffScrBits(k, 0x44u);
}

void Smbll_SmallPlatformBoundBox(uint8 k) {
  R0_ = 8;
  Smbll_GetMaskedOffScrBits(k, 4u);
}

void Smbll_GetMaskedOffScrBits(uint8 k, uint8 j) {
  uint8 v2;  // al
  int8 v3;   // al

  v2 = obj_xpos_lo.enemy[k];
  R1_ = v2 - screen_left_xpos_lo;
  v3 = obj_xpos_hi.enemy[k] - ((v2 < screen_left_xpos_lo) + screen_left_xpos_hi);
  if (v3 >= 0 && R1_ | (uint8)v3)
    j = R0_;
  spr_array_D[k] = offscreen_bits.enemy & j;
  if (k == 9) {
    Smbll_sub_EA11(9u);
  } else if (spr_array_D[k]) {
    Smbll_sub_EA1E(k);
  } else {
    Smbll_sub_EA11(k);
  }
}

void Smbll_LargePlatformBoundBox(uint8 k) {
  int v1;                // rsi
  uint8 XOffscreenBits;  // al
  uint8 v3;              // si

  v1 = (uint8)(k + 1);
  XOffscreenBits = Smbll_GetXOffscreenBits(v1);
  v3 = v1 - 1;
  if (XOffscreenBits < 0xFEu)
    Smbll_sub_EA11(v3);
  else
    Smbll_sub_EA1E(v3);
}

void Smbll_sub_EA11(uint8 k) {
  int v1;    // rsi
  uint8 v2;  // di

  v1 = (uint8)(k + 1);
  v2 = Smbll_BoundingBoxCore(v1, 1u);
  Smbll_CheckRightScreenBBox(v1, v2);
}

void Smbll_sub_EA1E(uint8 k) {
  uint8 v1;  // di

  v1 = 4 * k;
  *(&enemy_hitbox_left + v1) = -1;
  *(&enemy_hitbox_top + v1) = -1;
  *(&enemy_hitbox_right + v1) = -1;
  *(&enemy_hitbox_bottom + v1) = -1;
}

uint8 Smbll_BoundingBoxCore(uint8 k, uint8 j) {
  uint8 v2;  // di
  uint8 v3;  // si
  uint8 v5;  // [rsp+47h] [rbp-1h]

  R0_ = k;
  R2_ = *(&rel_ypos.player + j);
  R1_ = *(&rel_xpos_lo.player + j);
  v5 = 4 * k;
  v2 = 4 * k;
  v3 = 4 * *(&player_hitbox_ctrl + k);
  *(&player_hitbox_left + v2) = kBoundBoxCtrlData[v3] + R1_;
  *(&player_hitbox_right + v2) = kBoundBoxCtrlData[v3++ + 2] + R1_;
  *(&player_hitbox_left + ++v2) = kBoundBoxCtrlData[v3] + R2_;
  *(&player_hitbox_right + v2) = kBoundBoxCtrlData[v3 + 2] + R2_;
  return v5;
}

void Smbll_CheckRightScreenBBox(uint8 k, uint8 j) {
  R2_ = screen_left_xpos_lo + 0x80;
  R1_ = __CFADD__(screen_left_xpos_lo, 0x80) + screen_left_xpos_hi;
  if (*(&obj_xpos_hi.player + k) < ((*(&obj_xpos_lo.player + k) < (uint8)(screen_left_xpos_lo + 0x80)) + R1_)) {
    if (*(&player_hitbox_left + j) >= 0xA0u) {
      if ((*(&player_hitbox_right + j) & 0x80u) != 0)
        *(&player_hitbox_right + j) = 0;
      *(&player_hitbox_left + j) = 0;
    }
  } else if ((*(&player_hitbox_right + j) & 0x80u) == 0) {
    if ((*(&player_hitbox_left + j) & 0x80u) == 0)
      *(&player_hitbox_left + j) = -1;
    *(&player_hitbox_right + j) = -1;
  }
}

uint8 Smbll_PlayerCollisionCore(uint8 j) {
  return Smbll_SprObjectCollisionCore(0, j) & 1;
}

uint8 Smbll_SprObjectCollisionCore(uint8 k, uint8 j) {
  uint8 v2;  // al
  uint8 v3;  // al
  uint8 v5;  // al

  R6_ = j;
  R7_ = 1;
  do {
    v2 = *(&player_hitbox_left + j);
    if (v2 >= *(&player_hitbox_left + k)) {
      if (v2 != *(&player_hitbox_left + k) && v2 > *(&player_hitbox_right + k) &&
          (v2 <= *(&player_hitbox_right + j) || *(&player_hitbox_right + j) < *(&player_hitbox_left + k))) {
        return 0;
      }
    } else if (v2 < *(&player_hitbox_right + k)) {
      if (*(&player_hitbox_right + k) >= *(&player_hitbox_left + k)) {
        v5 = *(&player_hitbox_right + j);
        if (v5 < *(&player_hitbox_left + k))
          return v5 >= *(&player_hitbox_left + k);
      }
    } else if (v2 != *(&player_hitbox_right + k)) {
      v3 = *(&player_hitbox_right + j);
      if (v3 >= *(&player_hitbox_left + j) && v3 < *(&player_hitbox_left + k))
        return v3 >= *(&player_hitbox_left + k);
    }
    ++k;
    ++j;
    --R7_;
  } while ((R7_ & 0x80u) == 0);
  return 1;
}

uint8 Smbll_BlockBufferChk_Enemy(uint8 k, uint8 j, uint8 a) {
  return Smbll_BBChk_E(k + 1, j, a);
}

uint8 Smbll_BlockBufferChk_FBall(uint8 k) {
  return Smbll_BBChk_E(k + 11, 0x1Au, 0);
}

uint8 Smbll_BBChk_E(uint8 k, uint8 j, uint8 a) {
  return Smbll_BlockBufferCollision(k, j, a);
}

uint8 Smbll_BlockBufferColli_Feet(uint8 j) {
  return Smbll_BlockBufferColli_Head(j + 1);
}

uint8 Smbll_BlockBufferColli_Head(uint8 j) {
  return Smbll_CODE_03EB81(j, 0);
}

uint8 Smbll_BlockBufferColli_Side(uint8 j) {
  return Smbll_CODE_03EB81(j, 1u);
}

uint8 Smbll_CODE_03EB81(uint8 j, uint8 a) {
  return Smbll_BlockBufferCollision(0, j, a);
}

uint8 Smbll_BlockBufferCollision(uint8 k, uint8 j, uint8 a) {
  uint8 v3;  // al
  bool v4;   // cf
  int8 v5;   // al

  R4_ = j;
  v3 = kBlockBuffer_X_Adder[j];
  v4 = __CFADD__(*(&obj_xpos_lo.player + k), v3);
  R5_ = *(&obj_xpos_lo.player + k) + v3;
  uint8 t = ((v4 + *(&obj_xpos_hi.player + k)) & 1);
  Smbll_GetBlockBufferAddr((uint8)(R5_ >> 1 | t << 7) >> 3);
  R2_ = ((kBlockBuffer_Y_Adder[R4_] + *(&obj_ypos_lo.player + k)) & 0xF0) - 32;
  R3_ = RomPtr_RAM(*(uint16 *)&R6_)[R2_];
  if (a)
    v5 = *(&obj_xpos_lo.player + k);
  else
    v5 = *(&obj_ypos_lo.player + k);
  R4_ = v5 & 0xF;
  if (!tempE4 && R3_ >= 0x5Cu && R3_ < 0x62u)
    R3_ = 0;
  return R3_;
}

void Smbll_SixSpriteStacker(uint8 j, uint8 a) {
  int8 v2;  // si

  v2 = 6;
  do {
    get_OamEnt(oam_buf, j)[64].xpos = a;
    a += 8;
    j += 4;
    --v2;
  } while (v2);
}

void Smbll_CODE_03EC3C(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[3].ypos = a;
  oam[2].ypos = a;
  Smbll_DumpTwoSpr_(j, a);
}

void Smbll_DumpTwoSpr_(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[1].ypos = a;
  oam->ypos = a;
}

void Smbll_MoveSixSpritesOffscreen(uint8 j) {
  Smbll_DumpSixSpr(j, 0xF0u);
}

void Smbll_DumpSixSpr(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[69].ypos = a;
  oam[68].ypos = a;
  Smbll_DumpFourSpr(j, a);
}

void Smbll_DumpFourSpr(uint8 j, uint8 a) {
  get_OamEnt(oam_buf, j)[67].ypos = a;
  Smbll_DumpThreeSpr(j, a);
}

void Smbll_DumpThreeSpr(uint8 j, uint8 a) {
  get_OamEnt(oam_buf, j)[66].ypos = a;
  Smbll_DumpTwoSpr(j, a);
}

void Smbll_DumpTwoSpr(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[65].ypos = a;
  oam[64].ypos = a;
}

void Smbll_DrawLargePlatform(uint8 k) {
  uint8 v1;     // di
  uint8 v2;     // si
  uint8 v3;     // al
  uint8 v4;     // di
  OamEnt *oam;  // rbp
  uint8 v6;     // si
  uint8 v7;     // di
  uint8 v8;     // di
  uint8 v9;     // di
  uint8 v10;    // di
  uint8 v11;    // di
  uint8 v12;    // di
  uint8 j;      // [rsp+47h] [rbp-1h]

  if (cloud_type_override) {
    Smbll_DrawLargePlatform_Sub1();
  } else {
    R2_ = enemy_obj_id[k];
    v1 = R2_;
    Smbll_SixSpriteStacker(R2_, rel_xpos_lo.enemy);
    v2 = object_index;
    v3 = obj_ypos_lo.enemy[object_index];
    Smbll_DumpFourSpr(v1, v3);
    if (area_type == 3 || secondary_hard_mode)
      v3 = -16;
    v4 = enemy_obj_id[v2];
    oam = get_OamEnt(oam_buf, v4);
    oam[68].ypos = v3;
    oam[69].ypos = v3;
    v6 = object_index;
    Smbll_DumpSixSpr(++v4, 0x87u);
    Smbll_DumpSixSpr(v4 + 1, 0x2Cu);
    Smbll_GetXOffscreenBits(v6);
    v7 = enemy_obj_id[v6];
    Smbll_GetEnemyXPos(v6);
    Smbll_DrawLargePlatform_DrawOne(v7);
    j = v7;
    v8 = Smbll_DrawLargePlatform_Next(v7);
    Smbll_DrawLargePlatform_DrawOne(v8);
    v9 = Smbll_DrawLargePlatform_Next(v8);
    Smbll_DrawLargePlatform_DrawOne(v9);
    v10 = Smbll_DrawLargePlatform_Next(v9);
    Smbll_DrawLargePlatform_DrawOne(v10);
    v11 = Smbll_DrawLargePlatform_Next(v10);
    Smbll_DrawLargePlatform_DrawOne(v11);
    v12 = Smbll_DrawLargePlatform_Next(v11);
    Smbll_DrawLargePlatform_DrawOne(v12);
    if (__CFSHL__(offscreen_bits.enemy, 1) && enemy_id[v6] != 39 && enemy_id[v6] != 38 &&
        (obj_ypos_hi.enemy[v6] != 1 || rel_ypos.enemy >= 0xF0u)) {
      Smbll_MoveSixSpritesOffscreen(j);
    }
  }
}

void Smbll_DrawPowerUp() {
  uint8 v0;     // di
  uint8 v1;     // si
  int8 v2;      // al
  uint8 v3;     // al
  OamEnt *oam;  // rdx
  uint8 v5;     // [rsp+47h] [rbp-1h]

  v0 = enemy_obj_id[9] + 8;
  R2_ = rel_ypos.enemy + 8;
  R5_ = rel_xpos_lo.enemy;
  R4_ = enemy_sprattrib[9] ^ kPowerUpAttributes[power_up_type];
  v5 = power_up_type;
  v1 = 4 * power_up_type;
  R7_ = 1;
  R3_ = 1;
  do {
    R0_ = kPowerUpGfxTable[v1];
    v0 = Smbll_DrawOneSpriteRow(v1, v0, kPowerUpGfxTable[v1 + 1]);
    v1 += 2;
    --R7_;
  } while ((R7_ & 0x80u) == 0);
  if (v5 && v5 != 3 && v5 != 4) {
    R0_ = v5;
    v2 = frame_counter & 6;
    if ((frame_counter & 6) == 6)
      v2 = 14;
    v3 = (enemy_sprattrib[9] | v2) ^ 0x28;
    oam = get_OamEnt(oam_buf, (uint8)(enemy_obj_id[9] + 8));
    oam[64].flags = v3;
    oam[65].flags = v3;
    oam[66].flags = v3;
    oam[67].flags = v3;
    if (R0_ != 1) {
      oam[66].flags = v3;
      oam[67].flags = v3;
    }
    oam[65].flags |= 0x40u;
    oam[67].flags |= 0x40u;
  }
  Smbll_SprObjectOffscrChk(enemy_obj_id[9] + 8);
}

void Smbll_EnemyGfxHandler_New(uint8 k) {
  uint8 v1;  // al

  v1 = enemy_id[k];
  switch (v1) {
  case 0xCu: Smbll_EnemyGfxHandler_Sub4(k); return;
  case 8u:
    if (obj_ypos_hi.enemy[k] == 2)
      Smbll_EraseEnemyObject(k);
    break;
  case 0x33u:
    if (obj_ypos_hi.enemy[k] == 2)
      Smbll_EraseEnemyObject(k);
    break;
  default: Smbll_DrawLevelPreviewSprites_Sub3(k, v1); return;
  }
  Smbll_EnemyGfxHandler_Sub1(k);
}

void Smbll_DrawLevelPreviewSprites_Sub3(uint8 k, uint8 a) {
  uint8 v2;       // al
  uint8 v3;       // di
  uint8 v4;       // al
  uint8 v5;       // al
  uint8 v6;       // di
  uint8 v7;       // al
  uint8 v8;       // al
  uint8 v9;       // al
  uint8 v10;      // al
  uint8 v11;      // si
  uint8 v12;      // di
  uint8 v13;      // si
  uint8 v14;      // di
  uint8 v15;      // al
  uint8 v16;      // si
  OamEnt *oam;    // rbp
  OamEnt *v18;    // rdx
  uint8 v19;      // di
  uint8 v20;      // si
  OamEnt *v21;    // rbp
  OamEnt *v22;    // rbx
  uint8 v23;      // si
  OamEnt *v24;    // rdx
  uint8 v25;      // al
  uint8 v26;      // al
  uint8 v27;      // al
  OamEnt *v28;    // rdx
  uint8 v29;      // al
  OamEnt *v30;    // rbp
  int8 v31;       // al
  OamEnt *v32;    // rbp
  uint8 v33;      // al
  OamEnt *v34;    // rbp
  OamEnt *v35;    // rbp
  OamEnt *v36;    // rbp
  uint8 v37;      // [rsp+46h] [rbp-2h]
  uint8 charnum;  // [rsp+47h] [rbp-1h]

  if (a == 45) {
    Smbll_BowserDraw(k);
    return;
  }
  if (a == 53) {
    if (world_number == 7 || world_number == 12)
      Smbll_DrawLevelPreviewSprites_Sub7();
    else
      Smbll_DrawToadAndRelatedSprites(k);
    return;
  }
  v2 = 2;
  if (world_number == 1 || world_number == 2 || world_number == 6 || world_number == 11)
    v2 = 1;
  smbll_varF30 = v2;
  smbll_varF31 = v2;
  smbll_varF32 = v2;
  R2_ = obj_ypos_lo.enemy[k];
  R5_ = rel_xpos_lo.enemy;
  tempEB = enemy_obj_id[k];
  tempF0 = 0;
  R3_ = enemy_moving_dir[k];
  R4_ = enemy_sprattrib[k];
  if (enemy_id[k] != 13 || (obj_xspeed.enemy[k] & 0x80u) != 0 || !enemy_frame_timer[k]) {
    tempED = enemy_state[k];
    v3 = tempED & 0x1F;
    v4 = enemy_id[k];
    if (v4 == 53) {
      v3 = 0;
      R3_ = 1;
      v4 = 21;
    }
    if (v4 == 51) {
      --R2_;
      v5 = 32;
      if (enemy_frame_timer[k])
        v5 = 16;
      R4_ = v5;
      v3 = 0;
      tempED = 0;
      v4 = 8;
    }
    if (v4 == 50) {
      v3 = 3;
      v4 = kJumpspringFrameOffsets[jumpspring_anim_ctrl];
    }
    tempEF = v4;
    tempEC = v3;
    if (v4 == 12 && (obj_yspeed.enemy[object_index] & 0x80u) == 0)
      ++tempF0;
    if (bowser_gfx_flag) {
      v6 = 22;
      if (bowser_gfx_flag != 1)
        v6 = 23;
      tempEF = v6;
    }
    if (tempEF == 6) {
      v7 = enemy_state[object_index];
      if (v7 >= 2u)
        tempEC = 4;
      if (!(timer_control | v7 & 0x20) && (frame_counter & 8) == 0)
        R3_ ^= 3u;
    }
    if (tempEF == 13) {
      v8 = smbll_varF24;
    } else {
      v8 = kbyte_EDB5[tempEF];
      if (tempEF == 20) {
        v9 = 60;
LABEL_47:
        R4_ = v9;
        if (tempEF == 21 && (world_number == 7 || world_number == 12))
          R4_ = R4_ & 0xF0 | 4;
        if (which_enemy_gfx_offs)
          v10 = kEnemyGfxTableOffsets[tempEF] + 6;
        else
          v10 = kEnemyGfxTableOffsets[tempEF];
        v11 = v10;
        if (bowser_gfx_flag) {
          if (bowser_gfx_flag == 1) {
            if ((browser_body_controls & 0x80u) != 0)
              v11 = -34;
            if ((tempED & 0x20) != 0)
              goto LABEL_59;
          } else {
            if ((browser_body_controls & 1) != 0)
              v11 = -28;
            if ((tempED & 0x20) != 0) {
              R2_ -= 16;
LABEL_59:
              tempF0 = v11;
            }
          }
LABEL_108:
          v12 = tempEB;
          if (!(Smbll_CODE_05E8CA(tempEB) & 1)) {
            Smbll_DrawEnemyObjRow(v11, v12);
            Smbll_DrawEnemyObjRow(v11 + 2, v12 + 8);
            Smbll_DrawEnemyObjRow(v11 + 4, v12 + 16);
            Smbll_DrawLevelPreviewSprites_Sub8();
          }
          v13 = object_index;
          v14 = enemy_obj_id[object_index];
          if (enemy_id[object_index] == 12) {
            ++enemy_arr_0E1B[object_index];
            v15 = enemy_arr_0E1B[v13];
            if (v15 >= 0x12u) {
              enemy_arr_0E1B[v13] = 0;
              v15 = enemy_arr_0E1B[v13];
            }
            v16 = kbyte_EDD7[v15];
            oam = get_OamEnt(oam_buf, v14);
            oam[64].charnum = kbyte_EDE9[v16];
            oam[65].charnum = kbyte_EDE9[v16 + 1];
            oam[66].charnum = kbyte_EDE9[v16 + 2];
            oam[67].charnum = kbyte_EDE9[v16 + 3];
            oam[68].charnum = kbyte_EDE9[v16 + 4];
            oam[69].charnum = kbyte_EDE9[v16 + 5];
          }
          if (tempEF == 8)
            goto LABEL_148;
          if (tempF0) {
            v18 = get_OamEnt(oam_buf, v14);
            v19 = v14 + 2;
            Smbll_DumpSixSpr(v19, v18[64].flags | 0x80);
            v14 = v19 - 2;
            v20 = v14;
            if (tempEF != 5 && tempEF != 4 && tempEF != 17 && tempEF < 0x15u)
              v20 = v14 + 8;
            v21 = get_OamEnt(oam_buf, v20);
            charnum = v21[64].charnum;
            v37 = v21[65].charnum;
            v22 = get_OamEnt(oam_buf, v14);
            v21[64].charnum = v22[68].charnum;
            v21[65].charnum = v22[69].charnum;
            v22[69].charnum = v37;
            v22[68].charnum = charnum;
          }
          if (bowser_gfx_flag)
            goto LABEL_148;
          v23 = tempEC;
          if (tempEF == 5)
            goto LABEL_148;
          if ((tempEF == 7 || tempEF == 13 || tempEF == 4 || tempEF == 12 || (tempEF != 18 || tempEC == 5) && tempEC >= 2u) &&
              !bowser_gfx_flag && !enemy_array_F40[9]) {
            v24 = get_OamEnt(oam_buf, v14);
            v25 = v24[64].flags & 0xBE;
            v24[64].flags = v25;
            v24[66].flags = v25;
            v24[68].flags = v25;
            v26 = v25 | 0x40;
            if (v23 == 5)
              v26 |= 0x80u;
            v24[65].flags = v26;
            v24[67].flags = v26;
            v24[69].flags = v26;
            if (v23 == 4) {
              v27 = v24[66].flags | 0x80;
              v24[66].flags = v27;
              v24[68].flags = v27;
              v27 |= 0x40u;
              v24[67].flags = v27;
              v24[69].flags = v27;
            }
          }
          if (tempEF == 17) {
            if (!tempF0) {
              v28 = get_OamEnt(oam_buf, v14);
              v28[68].flags &= ~0x40u;
              v29 = v28[69].flags | 0x40;
              v28[69].flags = v29;
              if (frenzy_enemy_timer < 0x10u) {
                v28[67].flags = v29;
                v28[66].flags = v29 & 0xBF;
              }
LABEL_148:
              if (tempEF == 13) {
                if ((enemy_state[object_index] & 0x20) == 0) {
                  v34 = get_OamEnt(oam_buf, v14);
                  v34[68].flags = v34[68].flags & 0xF0 | 8;
                  v34[69].flags = v34[69].flags & 0xF0 | 8;
                  Smbll_SprObjectOffscrChk(v14);
                  return;
                }
              } else {
                if (tempEF != 4) {
                  Smbll_SprObjectOffscrChk(v14);
                  return;
                }
                if ((enemy_state[object_index] & 0x20) == 0) {
                  v35 = get_OamEnt(oam_buf, v14);
                  v35[64].flags = v35[64].flags & 0xF0 | 8;
                  v35[65].flags = v35[65].flags & 0xF0 | 8;
                  Smbll_SprObjectOffscrChk(v14);
                  return;
                }
              }
              v36 = get_OamEnt(oam_buf, v14);
              v36[64].ypos = -16;
              v36[65].ypos = -16;
              v36[66].ypos = -16;
              v36[67].ypos = -16;
              v36[68].ypos = -16;
              v36[69].ypos = -16;
              Smbll_SprObjectOffscrChk(v14);
              return;
            }
            v30 = get_OamEnt(oam_buf, v14);
            v30[64].flags &= ~0x40u;
            v30[65].flags |= 0x40u;
          }
          if (tempEF >= 0x18u) {
            if (smbll_varF30 & 1)
              v31 = -86;
            else
              v31 = -84;
            v32 = get_OamEnt(oam_buf, v14);
            v32[66].flags = v31;
            v32[68].flags = v31;
            v33 = v31 | 0x40;
            v32[67].flags = v33;
            v32[69].flags = v33;
            v33 &= 0x3Fu;
            v32[64].flags = v33;
            v32[65].flags = v33 | 0x40;
          }
          goto LABEL_148;
        }
        if (v10 == 36) {
          if (tempEC == 5) {
            v11 = 48;
            R3_ = 2;
            tempEC = 5;
          }
        } else {
          if (v10 == 0x90) {
            if ((tempED & 0x20) == 0 && frenzy_enemy_timer < 0x10u)
              v11 = -106;
            goto LABEL_104;
          }
          if (tempEF < 4u && tempEC >= 2u) {
            v11 = 90;
            if (tempEF == 2) {
              v11 = 126;
              ++R2_;
            }
          }
          if (tempEC == 4) {
            v11 = 114;
            ++R2_;
            if (tempEF != 2) {
              v11 = 102;
              ++R2_;
            }
            if (tempEF == 6) {
              v11 = 84;
              if ((tempED & 0x20) == 0) {
                v11 = -118;
                --R2_;
              }
            }
          }
        }
        if (tempEF == 5) {
          if (tempED) {
            if ((tempED & 8) == 0)
              goto LABEL_104;
            v11 = -76;
          }
        } else if (v11 != 72) {
          if (*(&enemy_interval_timer + object_index) >= 5u)
            goto LABEL_104;
          if (v11 == 60) {
            if (*(&enemy_interval_timer + object_index) != 1) {
              ++R2_;
              ++R2_;
              ++R2_;
              goto LABEL_102;
            }
LABEL_104:
            if (tempEF == 4 || (tempED & 0x20) != 0 && tempEF >= 4u) {
              tempF0 = 1;
              tempEC = 0;
            }
            goto LABEL_108;
          }
        }
        if (tempEF != 6 && tempEF != 8 && tempEF != 12 && tempEF < 0x18u) {
          if (tempEF == 21) {
            if (world_number != 7 && world_number != 12) {
              v11 = -94;
              tempEC = 3;
            }
            goto LABEL_104;
          }
          if ((kEnemyAnimTimingBMask[0] & frame_counter) == 0) {
LABEL_102:
            if (!(timer_control | tempED & 0xA0))
              v11 += 6;
            goto LABEL_104;
          }
        }
        goto LABEL_104;
      }
      if (tempEF == 22 || tempEF == 23) {
        if (bowser_var0201 & 1)
          v8 = 6;
        else
          v8 = 0;
      }
    }
    v9 = R4_ ^ v8;
    goto LABEL_47;
  }
}

void Smbll_SprObjectOffscrChk(uint8 j) {
  uint8 v1;  // si
  uint8 v2;  // di
  int8 v3;   // cf
  uint8 v4;  // [rsp+47h] [rbp-1h]
  uint8 v5;  // [rsp+47h] [rbp-1h]

  v1 = object_index;
  Smbll_GetEnemyXPos(object_index);
  R4_ = 0;
  Smbll_CODE_03FEE5(j);
  v2 = Smbll_DrawLargePlatform_Next(j);
  R4_ = 0;
  Smbll_CODE_03FEE5(v2);
  v4 = offscreen_bits.enemy >> 6;
  if ((offscreen_bits.enemy & 0x20) != 0)
    Smbll_CODE_03F313(v1, 0x10u);
  v3 = v4 & 1;
  v5 = v4 >> 1;
  if (v3)
    Smbll_CODE_03F313(v1, 8u);
  if (v5 & 1) {
    Smbll_CODE_03F313(v1, v5 >> 1);
    if (enemy_id[v1] != 12 && obj_ypos_hi.enemy[v1] == 2)
      Smbll_EraseEnemyObject(v1);
  }
}

void Smbll_DrawEnemyObjRow(uint8 k, uint8 j) {
  R0_ = kEnemyGraphicsTable[k];
  Smbll_DrawOneSpriteRow(k, j, kEnemyGraphicsTable[k + 1]);
}

uint8 Smbll_DrawOneSpriteRow(uint8 k, uint8 j, uint8 a) {
  R1_ = a;
  if (R2_ == 0xF9)
    R2_ = -16;
  return Smbll_DrawOneSpriteRow_Sub(j);
}

uint8 Smbll_DrawOneSpriteRow_(uint8 j, uint8 a) {
  OamEnt *oam;  // rdx
  int8 v3;      // al
  uint8 v4;     // al
  OamEnt *v5;   // rbp
  uint8 v6;     // al
  uint8 v7;     // al

  R1_ = a;
  oam = get_OamEnt(oam_buf, j);
  if ((R3_ & 2) != 0) {
    oam[1].charnum = R0_;
    oam->charnum = R1_;
    v3 = 64;
  } else {
    oam->charnum = R0_;
    oam[1].charnum = R1_;
    v3 = 0;
  }
  v4 = R4_ | v3;
  v5 = get_OamEnt(oam_buf, j);
  v5->flags = v4;
  v5[1].flags = v4;
  v6 = R2_;
  v5->ypos = R2_;
  v5[1].ypos = v6;
  v7 = R5_;
  v5->xpos = R5_;
  v5[1].xpos = v7 + 8;
  R2_ += 8;
  return j + 8;
}

void Smbll_CODE_03F313(uint8 k, uint8 a) {
  object_index = k;
  if (k == 10)
    k = 9;
  Smbll_DumpTwoSpr(enemy_obj_id[k] + a, 0xF0u);
}

void Smbll_CODE_03F326(uint8 k, uint8 a) {
  OamEnt *oam;  // rbp

  object_index = k;
  if (k == 10)
    k = 9;
  oam = get_OamEnt(oam_buf, (uint8)(enemy_obj_id[k] + a));
  oam[64].ypos = -16;
  oam[66].ypos = -16;
  oam[68].ypos = -16;
}

void Smbll_DrawBlock(uint8 k) {
  uint8 v1;     // di
  OamEnt *oam;  // rbp
  int8 v3;      // al

  v1 = block_obj_id[k];
  oam = get_OamEnt(oam_buf, v1);
  oam->xpos = rel_xpos_lo.block;
  oam->ypos = rel_ypos.block;
  oam->flags = 43;
  oam_tile_size_buffer[v1] = 2;
  if (block_metatile[k] == 0xFD)
    v3 = 0;
  else
    v3 = 2;
  oam->charnum = v3;
  tempE5 = obj_xpos_hi.block[k];
  tempE4 = obj_xpos_lo.block[k];
  *(uint16 *)&tempE4 -= screen_left_xpos16;
  if (tempE5)
    oam_tile_size_buffer[v1] = 3;
}

void Smbll_DrawBrickChunks(uint8 k) {
  uint8 v1;     // al
  uint8 v2;     // di
  uint8 v3;     // di
  uint8 block;  // al
  OamEnt *oam;  // rbp
  uint8 unk5;   // al

  R0_ = 44;
  v1 = 117;
  if (game_engine_subroutine != 5) {
    R0_ = 42;
    v1 = -124;
  }
  v2 = block_obj_id[k] + 1;
  Smbll_CODE_03EC3C(v2++, v1);
  Smbll_CODE_03EC3C(v2, R0_ | (16 * frame_counter) & 0xC0);
  v3 = v2 - 2;
  block = rel_ypos.block;
  if (rel_ypos.block >= 0xF0u)
    block = -16;
  Smbll_DumpTwoSpr_(v3, block);
  oam = get_OamEnt(oam_buf, v3);
  oam->xpos = rel_xpos_lo.block;
  R0_ = block_orig_xpos_lo[k] - screen_left_xpos_lo;
  oam[1].xpos = R0_ + R0_ - rel_xpos_lo.block + 6;
  unk5 = rel_ypos.unk5;
  if (rel_ypos.unk5 >= 0xF0u)
    unk5 = -16;
  oam[2].ypos = unk5;
  oam[3].ypos = unk5;
  oam[2].xpos = rel_xpos_lo.unk5;
  oam[3].xpos = R0_ + R0_ - rel_xpos_lo.unk5 + 6;
  if (__CFSHL__(offscreen_bits.block, 1))
    Smbll_DumpTwoSpr_(v3, 0xF0u);
  if (offscreen_bits.block) {
    oam_tile_size_buffer[v3] = 1;
    oam_tile_size_buffer[v3 + 8] = 1;
  }
  if (offscreen_bits.unk5) {
    oam_tile_size_buffer[v3 + 4] = 1;
    oam_tile_size_buffer[v3 + 12] = 1;
  }
}

void Smbll_DrawFireball(uint8 k) {
  uint8 v1;     // di
  OamEnt *oam;  // rdx
  int8 v3;      // al
  int8 v4;      // [rsp+47h] [rbp-1h]

  v1 = fireball_oam_id[k];
  oam = get_OamEnt(oam_buf, v1);
  oam->ypos = rel_ypos.fireball;
  oam->xpos = rel_xpos_lo.fireball;
  v4 = frame_counter >> 2;
  oam->charnum = ((frame_counter & 4) != 0) ^ 0xBE;
  v3 = 40;
  if ((v4 & 2) != 0)
    v3 = -24;
  oam->flags = v3;
  if ((obj_xspeed.fireball[k] & 0x80u) != 0 && rel_xpos_lo.fireball >= 0xF8u)
    oam_tile_size_buffer[v1] = 1;
}

void Smbll_DrawFirebar(uint8 j) {
  OamEnt *oam;  // rdx
  int8 v2;      // al
  int8 v3;      // [rsp+47h] [rbp-1h]

  v3 = frame_counter >> 2;
  oam = get_OamEnt(oam_buf, j);
  oam[64].charnum = ((frame_counter & 4) != 0) ^ 0xBE;
  v2 = 56;
  if ((v3 & 2) != 0)
    v2 = -8;
  oam[64].flags = v2;
}

void Smbll_DrawExplodingPlayerFireball(uint8 k) {
  uint8 v1;        // di
  uint8 v2;        // al
  uint8 v3;        // al
  uint8 v4;        // di
  uint8 v5;        // al
  OamEnt *oam;     // rbp
  uint8 fireball;  // al

  v1 = block_obj_id[k];
  if ((obj_xspeed.fireball[k] & 0x80u) == 0) {
    rel_xpos_lo.fireball -= 4;
    if (rel_xpos_lo.fireball < 0xF8u)
      goto LABEL_8;
    goto LABEL_3;
  }
  if (rel_xpos_lo.fireball >= 0xF0u) {
    if (rel_xpos_lo.fireball < 0xF8u) {
      oam_tile_size_buffer[v1] = 1;
      oam_tile_size_buffer[v1 + 4] = 1;
LABEL_3:
      oam_tile_size_buffer[v1 + 8] = 1;
      oam_tile_size_buffer[v1 + 12] = 1;
      goto LABEL_8;
    }
    oam_tile_size_buffer[v1] = 1;
    oam_tile_size_buffer[v1 + 4] = 1;
  }
LABEL_8:
  v2 = fireball_state[k];
  fireball_state[k] = v2 + 1;
  v3 = (v2 >> 1) & 7;
  if (v3 >= 3u) {
    fireball_state[k] = 0;
  } else {
    v4 = v1 + 1;
    Smbll_CODE_03EC3C(v4, kbyte_F44F[v3]);
    v5 = rel_ypos.fireball - 4;
    oam = get_OamEnt(oam_buf, (uint8)(v4 - 1));
    oam->ypos = rel_ypos.fireball - 4;
    oam[2].ypos = v5;
    v5 += 8;
    oam[1].ypos = v5;
    oam[3].ypos = v5;
    fireball = rel_xpos_lo.fireball;
    oam->xpos = rel_xpos_lo.fireball;
    oam[1].xpos = fireball;
    fireball += 8;
    oam[2].xpos = fireball;
    oam[3].xpos = fireball;
    oam->flags = 40;
    oam[1].flags = -88;
    oam[2].flags = 104;
    oam[3].flags = -24;
  }
}

void Smbll_DrawExplosion_Fireworks(uint8 j, uint8 a) {
  int v2;       // rdi
  uint8 v3;     // si
  uint8 v4;     // al
  OamEnt *oam;  // rbp
  uint8 v6;     // al
  uint8 v7;     // si

  v2 = (uint8)(j + 1);
  Smbll_DumpFourSpr(v2, kDATA_03F53B[a]);
  LOBYTE(v2) = v2 - 1;
  v3 = object_index;
  v4 = rel_ypos.fireball - 16;
  oam = get_OamEnt(oam_buf, (uint8)v2);
  oam[64].ypos = rel_ypos.fireball - 16;
  oam[66].ypos = v4;
  v4 += 16;
  oam[65].ypos = v4;
  oam[67].ypos = v4;
  v6 = rel_xpos_lo.fireball - 8;
  oam[64].xpos = rel_xpos_lo.fireball - 8;
  oam[65].xpos = v6;
  v6 += 16;
  oam[66].xpos = v6;
  oam[67].xpos = v6;
  oam_tile_size_buffer[(uint8)v2 + 256] = 2;
  oam_tile_size_buffer[(uint8)v2 + 260] = 2;
  oam_tile_size_buffer[(uint8)v2 + 264] = 2;
  oam_tile_size_buffer[(uint8)v2 + 268] = 2;
  v7 = obj_yspeed.enemy[v3] - 1;
  oam[64].flags = kbyte_F4EA[v7] | 0x20;
  oam[65].flags = kbyte_F4EA[v7] | 0xA0;
  oam[66].flags = kbyte_F4EA[v7] | 0x60;
  oam[67].flags = kbyte_F4EA[v7] | 0xE0;
}

void Smbll_DrawSmallPlatform(uint8 k) {
  uint8 v1;     // di
  uint8 v2;     // di
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v5;     // [rsp+47h] [rbp-1h]
  uint8 v6;     // [rsp+47h] [rbp-1h]

  v1 = enemy_obj_id[k] + 1;
  Smbll_DumpSixSpr(v1++, 0x87u);
  Smbll_DumpSixSpr(v1, 0x2Cu);
  v2 = v1 - 2;
  enemy = rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, v2);
  oam[64].xpos = rel_xpos_lo.enemy;
  oam[67].xpos = enemy;
  enemy += 8;
  oam[65].xpos = enemy;
  oam[68].xpos = enemy;
  enemy += 8;
  oam[66].xpos = enemy;
  oam[69].xpos = enemy;
  v5 = obj_ypos_lo.enemy[k];
  Smbll_DumpThreeSpr(v2, v5);
  oam[67].ypos = v5 + 0x80;
  oam[68].ypos = v5 + 0x80;
  oam[69].ypos = v5 + 0x80;
  v6 = offscreen_bits.enemy;
  if ((offscreen_bits.enemy & 8) != 0) {
    oam_tile_size_buffer[v2 + 256] = 1;
    oam_tile_size_buffer[v2 + 268] = 1;
  }
  if ((v6 & 4) != 0) {
    oam_tile_size_buffer[v2 + 260] = 1;
    oam_tile_size_buffer[v2 + 272] = 1;
  }
  if ((v6 & 2) != 0) {
    oam_tile_size_buffer[v2 + 264] = 1;
    oam_tile_size_buffer[v2 + 276] = 1;
  }
}

void Smbll_PlayerGfxHandler() {
  uint8 v0;     // di
  OamEnt *oam;  // rdx
  uint8 xpos;   // al
  uint8 v3;     // al
  OamEnt *v4;   // rdx

  if (turn_around_smoke_flag2)
    goto LABEL_5;
  if (player_gfx_offset == 24 || player_gfx_offset == 120) {
    ++turn_around_smoke_flag2;
    turn_around_smoke_flag = 0;
LABEL_5:
    Smbll_HandleTurnAroundSmoke();
  }
  if (game_engine_subroutine == 3 || !player_hurt_timer || !(frame_counter & 1)) {
    if (game_engine_subroutine == 11) {
      Smbll_PlayerKilled();
    } else if (player_change_size_flag) {
      Smbll_DoChangeSize();
    } else if (swimming_flag && player_state) {
      Smbll_FindPlayerAction();
      v0 = spr_data_offset;
      if (!(player_facing_dir & 1))
        v0 = spr_data_offset + 4;
      if (!player_size && player_state != 3 && game_engine_subroutine != 11) {
        if (player_facing_dir == 2 || (oam = get_OamEnt(oam_buf, v0), xpos = oam[4].xpos, oam[4].xpos = xpos - 8, xpos >= 8u)) {
          v3 = 2;
        } else {
          v3 = 3;
        }
        oam_tile_size_buffer[v0 + 16] = v3;
        v4 = get_OamEnt(oam_buf, v0);
        v4[4].charnum = ((uint8)(player_gfx_offset - 40) >> 2) + 8;
        if (v4[6].ypos >= 0xF0u)
          v4[4].ypos = -16;
        v4[6].ypos = -16;
      }
    } else {
      Smbll_FindPlayerAction();
    }
  }
}

void Smbll_FindPlayerAction() {
  uint8 v0;  // al

  v0 = Smbll_ProcessPlayerAction();
  Smbll_PlayerGfxProcessing(v0);
}

void Smbll_DoChangeSize() {
  uint8 v0;  // al

  v0 = Smbll_HandleChangeSize();
  Smbll_PlayerGfxProcessing(v0);
}

void Smbll_PlayerKilled() {
  Smbll_PlayerGfxProcessing(kPlayerGfxTblOffsets[14]);
}

void Smbll_PlayerGfxProcessing(uint8 a) {
  uint8 v1;  // al
  int8 v2;   // cf
  uint8 v3;  // di
  int8 v4;   // si
  uint8 v5;  // di

  player_gfx_offset = a;
  v1 = mario_goal_walk_var03ce;
  if (mario_goal_walk_var03ce)
    goto LABEL_6;
  if (vertical_pipe_flag_var0218) {
    if (!player_size) {
      player_gfx_offset = -40;
      goto LABEL_7;
    }
    v1 = -32;
LABEL_6:
    player_gfx_offset = v1;
  }
LABEL_7:
  Smbll_RenderPlayerSub(4u);
  Smbll_UNUSED_ChkForPlayerAttrib();
  if (R2_ == 3 && obj_xpos_hi.player != (obj_xpos_lo.player < (uint8)screen_left_xpos16) + HIBYTE(screen_left_xpos16)) {
    oam_tile_size_buffer[208] = 1;
    oam_tile_size_buffer[216] = 1;
    oam_tile_size_buffer[224] = 1;
    oam_tile_size_buffer[232] = 1;
  }
  if (fireball_throwing_timer) {
    v2 = player_anim_timer >= fireball_throwing_timer;
    fireball_throwing_timer = 0;
    if (!v2) {
      fireball_throwing_timer = player_anim_timer;
      if (player_state != 1)
        player_gfx_offset = kPlayerGfxTblOffsets[7];
      v3 = 4;
      if (buttons_left_right | obj_xspeed.player)
        v3 = 3;
      Smbll_RenderPlayerSub(v3);
    }
  }
  R0_ = offscreen_bits.player >> 4;
  v4 = 3;
  v5 = spr_data_offset + 24;
  do {
    v2 = R0_ & 1;
    R0_ >>= 1;
    if (v2)
      Smbll_DumpTwoSpr_(v5, 0xF0u);
    v5 -= 8;
    --v4;
  } while (v4 >= 0);
  Smbll_PlayerGfxProcessing_Sub_New();
}

void Smbll_DrawLevelPreviewSprites() {
  uint8 i;   // si
  uint8 v1;  // di

  Smbll_DrawLevelPreviewSprites_Sub_New();
  player_gfx_offset = -48;
  Smbll_RenderPlayerSub_New();
  for (i = 5; (i & 0x80u) == 0; --i)
    *(&R2_ + i) = kIntermediatePlayerData[i];
  v1 = Smbll_DrawPlayerLoop(0xB8u, 0xD0u);
  Smbll_DrawLevelPreviewSprites_Sub(v1);
  Smbll_Entrance_GameTimerSetup();
}

void Smbll_DrawLevelPreviewSprites_Sub(uint8 j) {
  OamEnt *oam;  // rbp
  uint8 v2;     // di
  uint8 v3;     // si
  uint8 v4;     // di
  uint8 v5;     // si
  OamEnt *v6;   // rdx
  int8 i;       // si
  uint8 v8;     // [rsp+45h] [rbp-3h]

  do {
    oam = get_OamEnt(oam_buf, j);
    oam->ypos = -16;
    oam[64].ypos = -16;
    ++j;
  } while (j);
  v2 = Smbll_DrawLevelPreviewSprites_Sub2();
  v3 = 0;
  tempE2 = 48;
  do {
    if (Smbll_DrawLevelPreviewSprites_Sub4(v3, v2) == 2) {
      if (enemy_id[v3] == 22) {
        Smbll_DrawLevelPreviewSprites_Sub5(v3);
        goto LABEL_16;
      }
      v8 = v2;
      Smbll_DrawLevelPreviewSprites_Sub3(v3, enemy_id[v3]);
      v4 = enemy_obj_id[v3];
      oam_tile_size_buffer[v4 + 256] = 0;
      oam_tile_size_buffer[v4 + 260] = 0;
      oam_tile_size_buffer[v4 + 264] = 0;
      oam_tile_size_buffer[v4 + 268] = 0;
      oam_tile_size_buffer[v4 + 272] = 0;
      oam_tile_size_buffer[v4 + 276] = 0;
      obj_xpos_hi.enemy[v3] = HIBYTE(screen_left_xpos16);
      v2 = v8;
      if (enemy_id[v3] == 18)
        Smbll_DrawLakituAboveSpinyInLevelPreview(v3);
    }
    ++v2;
    ++v3;
  } while (v3 != 5);
  if (area_type != 3) {
    v5 = 0;
    do {
      v6 = get_OamEnt(oam_buf, v5);
      if (v6[64].charnum == v6[65].charnum) {
        v6[64].flags &= 0x3Fu;
        v6[65].flags |= 0x40u;
      } else {
        v6[64].flags = v6[65].flags;
      }
      v5 += 8;
    } while (v5);
  }
LABEL_16:
  for (i = 4; i >= 0; --i)
    enemy_id[(uint8)i] = 0;
  which_enemy_gfx_offs = 0;
}

uint8 Smbll_DrawLevelPreviewSprites_Sub4(uint8 k, uint8 j) {
  uint8 v2;      // al
  uint8 result;  // al
  uint8 v4;      // al
  uint8 v5;      // al

  which_enemy_gfx_offs = 0;
  if (world_number < 8u)
    v2 = kbyte_2F83A[j];
  else
    v2 = kbyte_2F8DF[j];
  if (v2 == 0xFF) {
    result = tempE2 + 24;
    tempE2 += 24;
  } else {
    obj_ypos_hi.enemy[k] = 0;
    enemy_id[k] = v2;
    if (v2 == 14 || v2 == 15 || v2 == 16 || v2 == 20 || v2 == 8)
      v4 = -120;
    else
      v4 = -104;
    obj_ypos_lo.enemy[k] = v4;
    tempE2 += 24;
    rel_xpos_lo.enemy = tempE2;
    enemy_sprattrib[k] = 32;
    if (world_number < 8u)
      v5 = kbyte_2F83A[j];
    else
      v5 = kbyte_2F8DF[j];
    if (v5 == 5) {
      which_enemy_gfx_offs = 5;
      Smbll_DrawLevelPreviewSprites_Sub6(k);
    }
    result = 2;
    enemy_moving_dir[k] = 2;
  }
  return result;
}

uint8 Smbll_DrawLevelPreviewSprites_Sub2() {
  uint8 v0;      // si
  uint8 v1;      // al
  uint8 result;  // di
  uint8 v3;      // [rsp+47h] [rbp-1h]

  v0 = area_number + 5 * world_number;
  background_color_ctrl_0 = kbyte_18E86[v0];
  v1 = kbyte_18EC7[v0];
  level_level_preview_image_to_use = v1;
  v3 = v1;
  if (v1 >= 0x21u) {
    v1 -= 33;
    level_level_preview_image_to_use = v1;
  }
  result = level_level_preview_image_to_use * 5;
  level_level_preview_image_to_use = v3;
  LOBYTE(screen_left_xpos16_b) = screen_left_xpos_lo;
  HIBYTE(screen_left_xpos16_b) = screen_left_xpos_hi;
  ++draw_level_preview_sprites_var009B;
  screen_left_xpos_hi = 0;
  layer1_xpos_lo = 0;
  layer2_xpos = 0;
  layer3_xpos = 0;
  WriteReg(BG1HOFS, 0);
  WriteReg(BG1HOFS, 0);
  WriteReg(BG2HOFS, 0);
  WriteReg(BG2HOFS, 0);
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3HOFS, 0);
  return result;
}

void Smbll_sub_F9BD() {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, 0);
  oam[88].charnum = kbyte_F9B7[0];
  oam[89].charnum = kbyte_F9B7[1];
  oam[90].charnum = kbyte_F9B7[2];
  oam[91].charnum = kbyte_F9B7[3];
  oam[92].charnum = kbyte_F9B7[4];
  oam[93].charnum = kbyte_F9B7[5];
}

void Smbll_DrawLakituAboveSpinyInLevelPreview(uint8 k) {
  uint8 v1;     // di
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v4;     // al
  int v5;       // edx

  R3_ = 3;
  obj_ypos_lo.enemy[k] -= 40;
  temp3D = 0;
  v1 = 0;
  do {
    enemy = rel_xpos_lo.enemy;
    oam = get_OamEnt(oam_buf, v1);
    oam[100].xpos = rel_xpos_lo.enemy;
    oam[101].xpos = enemy + 8;
    v4 = obj_ypos_lo.enemy[k];
    oam[100].ypos = v4;
    oam[101].ypos = v4;
    obj_ypos_lo.enemy[k] = v4 + 8;
    oam[100].flags = 42;
    oam[101].flags = 42;
    v5 = temp3D;
    oam[100].charnum = kbyte_F9E2[temp3D];
    oam[101].charnum = kbyte_F9E2[v5 + 1];
    ++temp3D;
    ++temp3D;
    v1 += 8;
    --R3_;
  } while (R3_);
}

void Smbll_DrawLevelPreviewSprites_Sub5(uint8 k) {
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v3;     // al
  OamEnt *v4;   // rbx

  rel_ypos.enemy = obj_ypos_lo.enemy[k] - 8;
  rel_xpos_lo.enemy -= 16;
  enemy = rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, 0x90u);
  oam[64].xpos = rel_xpos_lo.enemy;
  oam[66].xpos = enemy;
  enemy += 8;
  oam[68].xpos = enemy;
  enemy += 8;
  oam[65].xpos = enemy;
  oam[67].xpos = enemy;
  oam[69].xpos = enemy;
  v3 = rel_ypos.enemy;
  oam[64].ypos = rel_ypos.enemy;
  oam[65].ypos = v3;
  v3 += 16;
  oam[66].ypos = v3;
  oam[67].ypos = v3;
  v3 -= 24;
  oam[68].ypos = v3;
  oam[69].ypos = v3;
  oam_tile_size_buffer[160] = 0;
  oam_tile_size_buffer[164] = 0;
  oam_tile_size_buffer[400] = 2;
  oam_tile_size_buffer[404] = 2;
  oam_tile_size_buffer[408] = 2;
  oam_tile_size_buffer[412] = 2;
  oam[64].flags = 97;
  oam[65].flags = 97;
  oam[66].flags = 97;
  oam[67].flags = 97;
  oam[68].flags = 97;
  oam[69].flags = 97;
  oam[68].charnum = -59;
  oam[69].charnum = -60;
  oam[64].charnum = -18;
  oam[65].charnum = -64;
  oam[66].charnum = -30;
  oam[67].charnum = -32;
  v4 = get_OamEnt(oam_buf, 0);
  v4[124].xpos = 112;
  v4[125].xpos = 120;
  v4[124].ypos = -104;
  v4[125].ypos = -104;
  v4[124].charnum = -122;
  v4[125].charnum = -121;
  v4[124].flags = 33;
  v4[125].flags = 33;
  oam_tile_size_buffer[496] = 2;
  oam_tile_size_buffer[500] = 2;
}

void Smbll_DrawLevelPreviewSprites_Sub6(uint8 k) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, 0);
  oam[32].ypos = obj_ypos_lo.enemy[k] - 10;
  oam[32].xpos = rel_xpos_lo.enemy + 3;
  oam[32].flags = 42;
  oam[32].charnum = 68;
  oam_tile_size_buffer[128] = 2;
}

void Smbll_RenderPlayerSub(uint8 a) {
  R7_ = a;
  player_pos_for_scroll = rel_xpos_lo.player;
  R5_ = rel_xpos_lo.player;
  R2_ = rel_ypos.player;
  R3_ = player_facing_dir;
  Smbll_RenderPlayerSub_New();
  R4_ = player_sprattrib;
  Smbll_DrawPlayerLoop(player_gfx_offset & 7, spr_data_offset);
}

uint8 Smbll_DrawPlayerLoop(uint8 k, uint8 j) {
  do {
    R0_ = kPlayerGraphicsTable[k];
    j = Smbll_DrawOneSpriteRow_(j, kPlayerGraphicsTable[k + 1]);
    k += 2;
    --R7_;
  } while (R7_);
  if (R5_ >= 0xF8u) {
    oam_tile_size_buffer[208] = 1;
    oam_tile_size_buffer[216] = 1;
    oam_tile_size_buffer[224] = 1;
    oam_tile_size_buffer[232] = 1;
  }
  return j;
}

uint8 Smbll_ProcessPlayerAction() {
  uint8 v0;                 // di
  uint8 v1;                 // di
  uint8 GfxOffsetAdder;     // di
  uint8 v4;                 // di
  uint8 v5;                 // al
  uint8 v6;                 // al
  uint8 CurrentAnimOffset;  // [rsp+47h] [rbp-1h]

  if (player_state != 3) {
    if (player_state == 2) {
      GfxOffsetAdder = Smbll_GetGfxOffsetAdder(4u);
      return Smbll_GetCurrentAnimOffset(GfxOffsetAdder);
    }
    if (player_state == 1) {
      if (!swimming_flag) {
        v0 = 6;
        if (!crouching_flag)
          v0 = 0;
        goto LABEL_12;
      }
      v4 = Smbll_GetGfxOffsetAdder(1u);
      if (!(player_anim_ctrl | jump_swim_timer) && !__CFSHL__(buttons_a_b, 1))
        return Smbll_GetCurrentAnimOffset(v4);
      goto LABEL_20;
    }
    v0 = 6;
    if (crouching_flag)
      goto LABEL_12;
    v0 = 2;
    if (!(buttons_left_right | obj_xspeed.player))
      goto LABEL_12;
    if (player_x_speed_absolute < 9u || (player_facing_dir & player_moving_dir) != 0) {
      v4 = Smbll_GetGfxOffsetAdder(4u);
LABEL_20:
      v5 = 3;
      goto LABEL_21;
    }
    v0 = 3;
LABEL_12:
    v1 = Smbll_GetGfxOffsetAdder(v0);
    player_anim_ctrl = 0;
    return kPlayerGfxTblOffsets[v1];
  }
  v0 = 5;
  if (!obj_yspeed.player)
    goto LABEL_12;
  v4 = Smbll_GetGfxOffsetAdder(5u);
  v5 = 2;
LABEL_21:
  R0_ = v5;
  CurrentAnimOffset = Smbll_GetCurrentAnimOffset(v4);
  if (!player_anim_timer) {
    player_anim_timer = player_anim_timer_set;
    v6 = player_anim_ctrl + 1;
    if ((uint8)(player_anim_ctrl + 1) >= R0_)
      v6 = 0;
    player_anim_ctrl = v6;
  }
  return CurrentAnimOffset;
}

uint8 Smbll_GetCurrentAnimOffset(uint8 j) {
  return kPlayerGfxTblOffsets[j] + 8 * player_anim_ctrl;
}

uint8 Smbll_GetGfxOffsetAdder(uint8 j) {
  if (player_size)
    j += 8;
  return j;
}

uint8 Smbll_HandleChangeSize() {
  uint8 v0;  // di
  uint8 v2;  // si
  uint8 v3;  // di

  v0 = player_anim_ctrl;
  if ((frame_counter & 3) == 0) {
    v0 = player_anim_ctrl + 1;
    if ((uint8)(player_anim_ctrl + 1) >= 0xAu) {
      v0 = 0;
      player_change_size_flag = 0;
    }
    player_anim_ctrl = v0;
  }
  if (!player_size)
    return kPlayerGfxTblOffsets[15] + 8 * kChangeSizeOffsetAdder[v0];
  v2 = v0 + 10;
  v3 = 9;
  if (!kChangeSizeOffsetAdder[v2])
    v3 = 1;
  return kPlayerGfxTblOffsets[v3];
}

void Smbll_UNUSED_ChkForPlayerAttrib() {
  ;
}

void Smbll_PlayerGfxProcessing_Sub_New() {
  uint8 i;      // si
  OamEnt *oam;  // rbp
  OamEnt *v2;   // rbx

  if (player_gfx_processing_flag) {
    for (i = 0; i != 32; ++i) {
      oam = get_OamEnt(oam_buf, i);
      oam[120].xpos = oam[52].xpos;
    }
    v2 = get_OamEnt(oam_buf, 0);
    v2[52].ypos = -16;
    v2[53].ypos = -16;
    v2[54].ypos = -16;
    v2[55].ypos = -16;
    v2[56].ypos = -16;
    v2[57].ypos = -16;
    v2[58].ypos = -16;
    v2[59].ypos = -16;
    oam_tile_size_buffer[480] = oam_tile_size_buffer[208];
    oam_tile_size_buffer[484] = oam_tile_size_buffer[212];
    oam_tile_size_buffer[488] = oam_tile_size_buffer[216];
    oam_tile_size_buffer[492] = oam_tile_size_buffer[220];
    oam_tile_size_buffer[496] = oam_tile_size_buffer[224];
    oam_tile_size_buffer[500] = oam_tile_size_buffer[228];
    oam_tile_size_buffer[504] = oam_tile_size_buffer[232];
    oam_tile_size_buffer[508] = oam_tile_size_buffer[236];
  }
}

void Smbll_RelativePlayerPosition() {
  Smbll_RelWOfs(0, 0);
}

void Smbll_RelativeBubblePosition(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = Smbll_GetProperObjOffset(k, 1u);
  Smbll_RelWOfs(ProperObjOffset, 3u);
}

void Smbll_RelativeFireballPosition(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = Smbll_GetProperObjOffset(k, 0);
  Smbll_RelWOfs(ProperObjOffset, 2u);
}

void Smbll_RelWOfs(uint8 k, uint8 j) {
  Smbll_GetObjRelativePosition(k, j);
}

void Smbll_RelativeMiscPosition(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = Smbll_GetProperObjOffset(k, 2u);
  Smbll_RelWOfs(ProperObjOffset, 6u);
}

uint8 Smbll_RelativeEnemyPosition(uint8 k) {
  return Smbll_VariableObjOfsRelPos(k, 1u, 1u);
}

void Smbll_RelativeBlockPosition(uint8 k) {
  Smbll_VariableObjOfsRelPos(k, 4u, 0xDu);
  Smbll_VariableObjOfsRelPos(k + 2, 5u, 0xDu);
}

uint8 Smbll_VariableObjOfsRelPos(uint8 k, uint8 j, uint8 a) {
  R0_ = k;
  return Smbll_GetObjRelativePosition(k + a, j);
}

uint8 Smbll_GetObjRelativePosition(uint8 k, uint8 j) {
  uint8 v2;      // al
  bool v3;       // cf
  uint8 result;  // al

  *(&rel_ypos.player + j) = *(&obj_ypos_lo.player + k);
  if (!override_player_xpos_flag || obj_xpos_lo.player) {
    v2 = *(&obj_xpos_lo.player + k);
    v3 = v2 < screen_left_xpos_lo;
    *(&rel_xpos_lo.player + j) = v2 - screen_left_xpos_lo;
    *(&rel_xpos_hi.player + j) = *(&obj_xpos_hi.player + k) - (v3 + screen_left_xpos_hi);
  } else {
    obj_xpos_lo.player = 40;
  }
  tempE4 = *(&obj_xpos_lo.player + k);
  tempE5 = *(&obj_xpos_hi.player + k);
  result = tempE4 - screen_left_xpos16;
  spr_rel_xpos16[(uint8)(2 * j) >> 1] = *(uint16 *)&tempE4 - screen_left_xpos16;
  return result;
}

void Smbll_GetPlayerOffscreenBits() {
  Smbll_GetOffScreenBitsSet(0, 0);
}

void Smbll_GetFireballOffscreenBits(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = Smbll_GetProperObjOffset(k, 0);
  Smbll_GetOffScreenBitsSet(ProperObjOffset, 2u);
}

void Smbll_GetBubbleOffscreenBits(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = Smbll_GetProperObjOffset(k, 1u);
  Smbll_GetOffScreenBitsSet(ProperObjOffset, 3u);
}

void Smbll_GetMiscOffscreenBits(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = Smbll_GetProperObjOffset(k, 2u);
  Smbll_GetOffScreenBitsSet(ProperObjOffset, 6u);
}

uint8 Smbll_GetProperObjOffset(uint8 k, uint8 j) {
  return kObjOffsetData[j] + k;
}

void Smbll_GetEnemyOffscreenBits(uint8 k) {
  Smbll_SetOffscrBitsOffset(k, 1u, 1u);
}

void Smbll_GetBlockOffscreenBits(uint8 k) {
  Smbll_SetOffscrBitsOffset(k, 0xDu, 4u);
}

void Smbll_SetOffscrBitsOffset(uint8 k, uint8 a, uint8 j) {
  R0_ = k;
  Smbll_GetOffScreenBitsSet(k + a, j);
}

void Smbll_GetOffScreenBitsSet(uint8 k, uint8 j) {
  uint8 v2;  // al

  R0_ |= 16 * Smbll_RunOffscrBitsSubs(k);
  v2 = R0_;
  *(&offscreen_bits.player + j) = R0_;
  *(&offscreen_bits_and1.player + j) = (v2 & 4) != 0;
  *(&offscreen_bits_shr1.player + j) = v2 >> 3;
}

uint8 Smbll_RunOffscrBitsSubs(uint8 k) {
  uint8 i;       // di
  uint8 v2;      // al
  bool v3;       // cf
  uint8 v4;      // al
  uint8 v5;      // si
  uint8 result;  // al

  R0_ = Smbll_GetXOffscreenBits(k) >> 4;
  R4_ = k;
  for (i = 1; (i & 0x80u) == 0; --i) {
    v2 = kHighPosUnitData[i];
    v3 = v2 < *(&obj_ypos_lo.player + k);
    R7_ = v2 - *(&obj_ypos_lo.player + k);
    v4 = 1 - (v3 + *(&obj_ypos_hi.player + k));
    v5 = kDefaultYOnscreenOfs[i];
    if (!sign8(v4)) {
      v5 = kDefaultYOnscreenOfs[i + 1];
      if (sign8(v4 - 1)) {
        R6_ = 32;
        v5 = Smbll_DividePDiff(v5, i, 4u);
      }
    }
    result = kYOffscreenBitsData[v5];
    k = R4_;
    if (result)
      break;
  }
  return result;
}

uint8 Smbll_GetXOffscreenBits(uint8 k) {
  uint8 i;       // di
  uint8 v2;      // al
  bool v3;       // cf
  uint8 v4;      // al
  uint8 v5;      // si
  uint8 result;  // al

  R4_ = k;
  for (i = 1; (i & 0x80u) == 0; --i) {
    v2 = *(&screen_left_xpos_lo + i);
    v3 = v2 < *(&obj_xpos_lo.player + k);
    R7_ = v2 - *(&obj_xpos_lo.player + k);
    v4 = *(&screen_left_xpos_hi + i) - (v3 + *(&obj_xpos_hi.player + k));
    v5 = kDefaultXOnscreenOfs[i];
    if (!sign8(v4)) {
      v5 = kDefaultXOnscreenOfs[i + 1];
      if (sign8(v4 - 1)) {
        R6_ = 56;
        v5 = Smbll_DividePDiff(v5, i, 8u);
      }
    }
    result = kXOffscreenBitsData[v5];
    k = R4_;
    if (result)
      break;
  }
  return result;
}

uint8 Smbll_DividePDiff(uint8 k, uint8 j, uint8 a) {
  uint8 v3;  // al

  R5_ = a;
  if (R7_ < R6_) {
    v3 = (R7_ >> 3) & 7;
    if (!j)
      v3 += R5_;
    return v3;
  }
  return k;
}

void Smbll_GetEnemyXPos(uint8 k) {
  HIBYTE(xpos16) = obj_xpos_hi.enemy[k];
  LOBYTE(xpos16) = obj_xpos_lo.enemy[k];
}

void Smbll_GetSomeXpos(uint8 k) {
  xpos16 = xpos_new_var0E16;
}

void Smbll_DrawLargePlatform_DrawOne(uint8 j) {
  R4_ = 6;
  some_xpos_0E12 = xpos16 - screen_left_xpos16;
  oam_tile_size_buffer[j + 256] = (uint16)(xpos16 - screen_left_xpos16) >> 8 != 0;
}

void Smbll_CODE_03FEE5(uint8 j) {
  bool v1;  // al

  some_xpos_0E12 = xpos16 - screen_left_xpos16;
  v1 = (uint16)(xpos16 - screen_left_xpos16) >> 8 != 0;
  oam_tile_size_buffer[j + 272] = v1;
  oam_tile_size_buffer[j + 264] = v1;
  oam_tile_size_buffer[j + 256] = v1;
}

void Smbll_Unused_CODE_03FF07(uint8 j) {
  bool v1;  // al

  some_xpos_0E12 = xpos16 - screen_left_xpos16;
  v1 = (uint16)(xpos16 - screen_left_xpos16) >> 8 != 0;
  oam_tile_size_buffer[j + 8] = v1;
  oam_tile_size_buffer[j] = v1;
}

void Smbll_Unused_CODE_03FF26(uint8 j, uint8 a) {
  oam_tile_size_buffer[j] = a;
  oam_tile_size_buffer[j + 8] = a;
}

uint8 Smbll_DrawLargePlatform_Next(uint8 j) {
  xpos16 += 8;
  return j + 4;
}

uint8 Smbll_DrawOneSpriteRow_Sub(uint8 j) {
  OamEnt *oam;  // rdx
  int8 v2;      // al
  uint8 v3;     // al
  OamEnt *v4;   // rbp
  uint8 v5;     // al
  uint8 v6;     // al

  oam = get_OamEnt(oam_buf, j);
  if ((R3_ & 2) != 0) {
    oam[65].charnum = R0_;
    oam[64].charnum = R1_;
    v2 = 64;
  } else {
    oam[64].charnum = R0_;
    oam[65].charnum = R1_;
    v2 = 0;
  }
  v3 = R4_ | v2;
  v4 = get_OamEnt(oam_buf, j);
  v4[64].flags = v3;
  v4[65].flags = v3;
  v5 = R2_;
  v4[64].ypos = R2_;
  v4[65].ypos = v5;
  v6 = R5_;
  v4[64].xpos = R5_;
  v4[65].xpos = v6 + 8;
  R2_ += 8;
  return j + 8;
}
