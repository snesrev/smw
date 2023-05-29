#include "smb1_consts.h"
#include "smb1_funcs.h"
#include "smb1_rtl.h"
#include "smb1_variables.h"

void (*funcs_11F7[4])(void) = {
    &TitleScreen_0_InitializeGame,
    &ScreenRoutines,
    &TitleScreen_2_PrimaryGameSetup,
    &TitleScreen_3_GameMenuRoutine,
};  // weak
void (*funcs_4FCB[47])(uint8 k) = {
    &ExtObj07_VerticalPipe,
    &ExtObj01_GrassyOrMushroomPlatform,
    &ExtObj02_RowOfBricks,
    &ExtObj03_RowOfSolidBlocks,
    &ExtObj04_RowOfCoins,
    &ExtObj05_ColumnOfBricks,
    &ExtObj06_ColumnOfSolidBlocks,
    &ExtObj07_VerticalPipe,
    &ExtObj08_Hole,
    &ExtObj09_PulleyRope,
    &ExtObj0A_Bridge_High,
    &ExtObj0B_Bridge_Middle,
    &ExtObj0B_Bridge_Low,
    &ExtObj0D_HoleWater,
    &ExtObj0E_QuestionBlockHigh,
    &ExtObj0E_QuestionBlockLow,
    &nullsub_A85C,
    &nullsub_A85C,
    &nullsub_A85C,
    &nullsub_A85C,
    &nullsub_A85C,
    &nullsub_A85C,
    &ExtObj18_QuestionBlock,
    &ExtObj18_QuestionBlock,
    &ExtObj18_QuestionBlock,
    &ExtObj19_Hidden1upBlock,
    &BrickWithItem,
    &BrickWithItem,
    &BrickWithItem,
    &ExtObj1D_BrickWith10Coins,
    &BrickWithItem,
    &ExtObj1F_WaterPipe,
    &ExtObj20_EmptyBlock,
    &ExtObj21_Jumpspring,
    &ExtObj22_IntroPipe,
    &ExtObj23_FlagpoleObject,
    &ExtObj24_AxeObj,
    &ExtObj25_ChainObj,
    &ExtObj26_CastleBridge,
    &ExtObj27_ScrollLockObject_Warp,
    &ExtObj28_ScrollLockObject,
    &ExtObj28_ScrollLockObject,
    &ExtObj2C_AreaFrenzy,
    &ExtObj2C_AreaFrenzy,
    &ExtObj2C_AreaFrenzy,
    &ExtObj2D_LoopCmdE,
    &ExtObj2E_AlterAreaAttributes,
};  // weak
void (*funcs_A6DE[55])(uint8) = {
    &NormalEnemy_Init,      &NormalEnemy_Init,      &NormalEnemy_Init,      &RedKoopa_Init,     &NoEnemyInit,
    &HammerBro_Init,        &Goomba_Init,           &Blooper_Init,          &BulletBill_Init,   &NoEnemyInit,
    &CheepCheep_Init,       &CheepCheep_Init,       &Podoboo_Init,          &PiranhaPlant_Init, &JumpGPTroopa_Init,
    &RedPTroopa_Init,       &InitHorizFlySwimEnemy, &Lakitu_Init,           &InitEnemyFrenzy,   &NoEnemyInit,
    &InitEnemyFrenzy,       &InitEnemyFrenzy,       &InitEnemyFrenzy,       &InitEnemyFrenzy,   &EndFrenzy,
    &NoEnemyInit,           &NoEnemyInit,           &ShortFirebar_Init,     &ShortFirebar_Init, &ShortFirebar_Init,
    &ShortFirebar_Init,     &LongFirebar_Init,      &NoEnemyInit,           &NoEnemyInit,       &NoEnemyInit,
    &NoEnemyInit,           &BalPlatform_Init,      &VertPlatform_Init,     &LargeLiftUp_Init,  &LargeLiftDown_Init,
    &InitHoriPlatform_Init, &InitDropPlatform_Init, &InitHoriPlatform_Init, &PlatLiftUp_Init,   &PlatLiftDown_Init,
    &Bowser_Init,           &Spr02E_Powerup_Init,   &Spr02F_Vine_Init2,     &NoEnemyInit,       &NoEnemyInit,
    &NoEnemyInit,           &NoEnemyInit,           &NoEnemyInit,           &RetainerObj_Init,  &EndOfEnemyInitCode,
};  // weak
void (*funcs_B851[6])(uint8) = {&LakituAndSpinyHandler, &NoFrenzyCode,  &FlyingCheepCheep_Init,
                                &BowserFlame_Init,      &InitFireworks, &BulletBillCheepCheep};  // weak
void (*funcs_BC01[34])(uint8) = {
    &RunNormalEnemies, &RunBowserFlame,   &RunFireworks,      &NoRunCode,        &NoRunCode,        &NoRunCode,         &NoRunCode,
    &RunFirebarObj,    &RunFirebarObj,    &RunFirebarObj,     &RunFirebarObj,    &RunFirebarObj,    &RunFirebarObj,     &RunFirebarObj,
    &RunFirebarObj,    &NoRunCode,        &RunLargePlatform,  &RunLargePlatform, &RunLargePlatform, &RunLargePlatform,  &RunLargePlatform,
    &RunLargePlatform, &RunLargePlatform, &RunSmallPlatform,  &RunSmallPlatform, &RunBowser,        &PowerUpObjHandler, &VineObjectHandler,
    &NoRunCode,        &RunStarFlagObj,   &JumpspringHandler, &NoRunCode,        &WarpZoneObject,   &RunRetainerObj};  // weak
void (*funcs_BDE8[21])(uint8) = {
    &MoveNormalEnemy, &MoveNormalEnemy,  &MoveNormalEnemy,      &MoveNormalEnemy,    &MoveNormalEnemy,        &ProcHammerBro,
    &MoveNormalEnemy, &MoveBloober,      &MoveBulletBill,       &NoMoveCode,         &MoveSwimmingCheepCheep, &MoveSwimmingCheepCheep,
    &MovePodoboo,     &MovePiranhaPlant, &MoveJumpingEnemy,     &ProcMoveRedPTroopa, &MoveFlyGreenPTroopa,    &MoveLakitu,
    &MoveNormalEnemy, &NoMoveCode,       &MoveFlyingCheepCheep,
};  // weak
void (*funcs_BFB5[7])(uint8) = {&BalancePlatform, &YMovingPlatform, &MoveLargeLiftPlat, &MoveLargeLiftPlat,
                                &XMovingPlatform, &DropPlatform,    &RightPlatform};  // weak

void Smb1VectorReset() {
  WriteReg(NMITIMEN, 0);
  WriteReg(MDMAEN, 0);
  WriteReg(HDMAEN, 0);
  WriteReg(INIDISP, 0x80u);

  UploadSPCEngine();
  InitializeRAMOnStartup();
  VerifySaveDataIsValid();
  UploadMainSampleData();
  // LoadSplashScreen();
  UploadSpuData();
  vram_flag_028c = 1;
  var0F0B = 3;
  vram_flag_028e = 0;
  var0E67 = 0;
  WriteReg(OBSEL, 3u);
  WriteReg(BG1SC, 1u);
  WriteReg(BG2SC, 9u);
  WriteReg(BG3SC, 0x59u);
  WriteReg(BG4SC, 0);
  WriteReg(BG12NBA, 0x11u);
  WriteReg(BG34NBA, 5u);
  WriteReg(SETINI, 0);
  UNUSED_byte_7E1681 = 0;
  game_mode = 0;
  game_mode_task = 0;
  g_byte_7FFFFF = 0;
  ResetScrollRegs();
  bgmode_mirror = 9;
  mosaic_mirror = 0;
  tm_mirror = 16;
  ts_mirror = 0;
  w12sel_mirror = 0;
  w34sel_mirror = 0;
  wobjsel_mirror = 0;
  cgwsel_mirror = 0;
  cgadsub_mirror = 32;
  coldata1_mirror = 32;
  coldata2_mirror = 64;
  coldata3_mirror = 0x80;
  hdmaenable_mirror = 0;
  inidisp_mirror = 0x80;
  wait_for_vblank = 0;
  global_frame_advance_debug_active_flag = 0;
  fade_direction = 0;
  display_pause_menu_flag = 0;
  sprite0_hit_detect_flag = 0x80;
  var0E67 = 0;
  obj_yspeed.bubble[0] = 0;
  game_loop_toggler = 0;
  vblank_upload_from_7f0000_flag = 0;
  vblank_flag_0ED4 = 0;
  update_entire_palette_flag = 0;
  vram_buffer_addr_ctrl = 0;
  vram_flag_028d = 0;
  palette_mirror[0] = 0;
  palette_mirror[128] = 0;
  *(uint16 *)&vram_buffer1[1] = -1;
  upload_buffer_3[1] = -1;
  layer3_tilemap_upload_buf[1] = -1;
  WriteReg(VMAIN, 0x80u);
  WriteRegWord(VMADDL, 0x1000u);
  WriteRegWord(DMAP0, 0x1801u);
  WriteRegWord(A1T0L, 0x8000u);
  WriteReg(A1B0, 3u);
  WriteRegWord(DAS0L, 0x4000u);
  WriteReg(MDMAEN, 1u);
  WriteRegWord(VMADDL, 0x6000u);
  WriteRegWord(A1T0L, 0x8000u);
  WriteReg(A1B0, 4u);
  WriteRegWord(DAS0L, 0x4000u);
  WriteReg(MDMAEN, 1u);
  WriteRegWord(VMADDL, 0x5000u);
  WriteRegWord(A1T0L, 0xB000u);
  WriteReg(A1B0, 9u);
  WriteRegWord(DAS0L, 0x800u);
  WriteReg(MDMAEN, 1u);
  Dma_FillWith0x28();
  UNUSED_byte_7E1608 = 0;
  UNUSED_byte_7E1609 = 0;
  apui03_upper_bit = 0;
  UNUSED_byte_7E160E = 0;
  apui00_delay = 0;
  apui03_delay = 0x19;
  apui02_var160C = 1;
  frame_counter = -127;
  WriteReg(NMITIMEN, 0x81u);
}
// 7E00BA: using guessed type int8;

void Smb1RunOneFrameOfGame_Internal() {
  int8 v0;   // r8
  int8 v1;   // cf
  int8 v2;   // r8
  int8 v3;   // r8
  int8 v4;   // r8
  int8 v5;   // r8
  int8 v6;   // r8
  int8 v7;   // r8
  uint8 v8;  // si

  Smb1PollJoypadInputs();
  random_lfsr_tmp = random_byte1 & 2;
  v0 = 0;
  if ((random_byte1 & 2) != (random_byte2 & 2))
    v0 = 0x80;
  v1 = random_byte1 & 1;
  random_byte1 = (random_byte1 >> 1) + v0;
  v2 = 0;
  if (v1)
    v2 = 0x80;
  v1 = random_byte2 & 1;
  random_byte2 = (random_byte2 >> 1) + v2;
  v3 = 0;
  if (v1)
    v3 = 0x80;
  v1 = random_byte3 & 1;
  random_byte3 = (random_byte3 >> 1) + v3;
  v4 = 0;
  if (v1)
    v4 = 0x80;
  v1 = random_byte4 & 1;
  random_byte4 = (random_byte4 >> 1) + v4;
  v5 = 0;
  if (v1)
    v5 = 0x80;
  v1 = random_byte5 & 1;
  random_byte5 = (random_byte5 >> 1) + v5;
  v6 = 0;
  if (v1)
    v6 = 0x80;
  v1 = random_byte6 & 1;
  random_byte6 = (random_byte6 >> 1) + v6;
  v7 = 0;
  if (v1)
    v7 = 0x80;
  random_byte7 = (random_byte7 >> 1) + v7;
  HandleSfx();
  if (!debug_flag)
    goto LABEL_27;
  if ((*(&controller_press2p1 + current_player_mirror) & 0x20) != 0)
    ++global_frame_advance_debug_active_flag;
  if ((*(&controller_press2p1 + current_player_mirror) & 0x10) != 0 || (global_frame_advance_debug_active_flag & 1) == 0) {
LABEL_27:
    Smb1HandleLevelTileAnimations();
    HandlePauseMenu();
    DoSomeDigitsStuff();
    if (!area_type)
      HandleLayersScroll();
    if ((int8)game_loop_toggler > 0 && screen_timer &&
        ((*(&controller_press2p1 + current_player) & 0x80u) != 0 || (*(&controller_press1p1 + current_player) & 0x90) != 0)) {
      screen_timer = 0;
      game_loop_toggler = 0;
    }
    if (fade_direction) {
      HandleScreenTransition();
    } else {
      if (display_pause_menu_flag & 1)
        goto LABEL_52;
      if (!timer_control || (--timer_control, !timer_control)) {
        v8 = 24;
        if ((--interval_timer_control & 0x80u) != 0) {
          interval_timer_control = 20;
          v8 = 43;
        }
        do {
          if (*(&all_timers + v8))
            --*(&all_timers + v8);
          --v8;
        } while ((v8 & 0x80u) == 0);
      }
      if (!screen_timer)
        game_loop_toggler &= 0x80u;
      ++frame_counter;
      if ((++podoboo_animation_frame_counter & 0x18) == 24)
        podoboo_animation_frame_counter = 0;
      CheckIfBowserTouchedLava();
      if (sprite0_hit_detect_flag) {
        if (!(disable_sprite_oamreset_flag & 1))
          ResetMiscSpriteOamId();
      }
      ProcessGameMode();
      if ((cutscene_var1680 & 0x80u) != 0) {
LABEL_52:
        DrawLevelPreviewSprites_Sub_New();
        MaybePauseMenuHandler();
      }
    }
  }
  CompressOAMTileSizeBuffer();
  wait_for_vblank = 0;
}

void Smb1VectorNMI() {
  uint8 v0;   // al
  uint16 v1;  // si
  int16 v2;   // ax
  uint16 v3;  // si
  int16 v4;   // ax
  uint8 v5;   // di
  uint16 v6;  // si
  uint8 v7;   // si
  int16 v8;   // [rsp+3Fh] [rbp-9h]

  v8 = *(uint16 *)&R0_;
  ReadReg(RDNMI);
  v0 = inidisp_mirror;
  if (!inidisp_mirror)
    v0 = 0x80;
  WriteReg(INIDISP, v0);
  WriteReg(HDMAEN, 0);
  if (!wait_for_vblank) {
    ++wait_for_vblank;
    R0_ = kDATA_0382DE[vram_buffer_addr_ctrl];
    R1_ = kDATA_0382F1[vram_buffer_addr_ctrl];
    R2_ = 0;
    UploadStripeImage();
    if (vram_buffer_addr_ctrl == 6) {
      R0_ = kDATA_0382DE[0];
      R1_ = kDATA_0382F1[0];
      R2_ = 0;
      UploadStripeImage();
    }
    WriteReg(VMAIN, 0x81u);
    WriteRegWord(DMAP0, 0x1801u);
    if (vblank_upload_from_7f0000_flag) {
      WriteReg(A1B0, 0x7Fu);
      v1 = 0;
      v2 = upload_buffer_3[1];
      do {
        WriteRegWord(VMADDL, v2);
        WriteRegWord(A1T0L, v1 + 4);
        WriteRegWord(DAS0L, 0x40u);
        v1 += 66;
        WriteRegWord(MDMAEN, 1u);
        v2 = upload_buffer_3[(v1 >> 1) + 1];
      } while (v2 >= 0);
      vblank_upload_from_7f0000_flag = 0;
    }
    if (vblank_flag_0ED4) {
      WriteReg(A1B0, 0x7Fu);
      v3 = 0;
      v4 = layer3_tilemap_upload_buf[1];
      do {
        WriteRegWord(VMADDL, v4);
        WriteRegWord(A1T0L, v3 + 8196);
        WriteRegWord(DAS0L, 0x38u);
        v3 += 58;
        WriteRegWord(MDMAEN, 1u);
        v4 = layer3_tilemap_upload_buf[(v3 >> 1) + 1];
      } while (v4 >= 0);
      *(uint16 *)&vblank_flag_0ED4 = 0;
    }
    WriteReg(VMAIN, 0x80u);
    VramFunc_9B5C();
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
    v5 = 0;
    if (vram_buffer_addr_ctrl == 6)
      v5 = 2;
    v6 = kDATA_038304[v5 >> 1];
    *(uint16 *)(&vram_buffer1_offset + v6) = 0;
    *(uint16 *)&vram_buffer1[v6 + 1] = -1;
    upload_buffer_3[0] = 0;
    if (area_type)
      layer3_tilemap_upload_buf[0] = 0;
    vram_buffer_addr_ctrl = 0;
  }
  WriteReg(WH2, wh2_mirror);
  WriteReg(WH3, wh3_mirror);
  WriteReg(COLDATA, coldata_mirror);
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
  WriteReg(HDMAEN, hdmaenable_mirror);
  v7 = -127;
  if (vblank_enable_vtimel_flag) {
    ReadReg(TIMEUP);
    WriteReg(VTIMEL, vtimel_mirror);
    WriteReg(VTIMEH, 0);
    WriteReg(HTIMEL, 0);
    WriteReg(HTIMEH, 0);
    v7 = -95;
  }
  WriteReg(NMITIMEN, v7);
  *(uint16 *)&R0_ = v8;
}

void Smb1VectorIRQ() {
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

void ProcessGameMode() {
  int16 v0;  // si

  v0 = 2 * *(uint16 *)&game_mode;
  if (2 * *(uint16 *)&game_mode) {
    switch (v0) {
    case 4: GameMode02_Cutscene(); break;
    case 6: GameMode03_GameOverScreen(); break;
    case 2: GameMode01_Level(); break;
    default:
      Unreachable();
      while (1)
        ;
    }
  } else {
    GameMode00_TitleScreen();
  }
}

void HandlePauseMenu() {
  if (game_mode != 2 && game_mode == 1 && game_mode_task == 3 && !var0E67 && inidisp_mirror == 15) {
    if (pausemenu_delay) {
      --pausemenu_delay;
    } else if (game_engine_subroutine != 2 && game_engine_subroutine != 3 && !auto_control_player_var1 && pause_menu_idx < 2u) {
      if (pausemenu_var2) {
        --pausemenu_var2;
      } else if (!pause_menu_idx && (*(&controller_press1p1 + current_player) & 0x10) != 0) {
        pausemenu_delay = 17;
        music_ch1 = -15;
        sound_ch1 = 67;
        PauseMenu_Func6();
      }
    }
  }
}

void ResetAllSpriteOams_Far() {
  ResetAllSpriteOams();
}

void ResetMiscSpriteOamId() {
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
    ResetAlmostAllSpriteOams();
  else
    DrawLevelPreviewSprites_Sub_New();
}

void DrawLevelPreviewSprites_Sub_New() {
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
    ResetAllSpriteOams();
  }
}

void ResetAllSpriteOams() {
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

void ResetAlmostAllSpriteOams() {
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

void GameMode00_TitleScreen() {
  funcs_11F7[(uint8)(2 * game_mode_task) >> 1]();
  music_ch1 = 0;
}
// 11FF: using guessed type int (*funcs_11F7[4])();

void TitleScreen_3_GameMenuRoutine() {
  int8 i;    // si
  int8 v1;   // [rsp+47h] [rbp-1h]
  uint8 v2;  // [rsp+47h] [rbp-1h]

  if (sram_controller1_plugged_in || !sram_controller2_plugged_in || (controller_press1p2 & 0x10) == 0) {
    if (((controller_press1p2 | controller_press1p1) & 0x10) != 0)
      goto LABEL_8;
    if ((controller_hold2p1 != 0xB0 || saved_joypad_bits != 0x80) && (controller_hold2p2 != 0xB0 || controller_hold1p2 != 0x80)) {
      if ((save_buffer_2_player_flag & 0x80u) == 0)
        demo_timer = 64;
      if (demo_timer)
        DrawMushroomIcon();
      if (((controller_press1p2 | controller_press1p1) & 0x2C) != 0) {
        if (!demo_timer)
          goto LABEL_33;
        demo_timer = 24;
        MoveTitleScreenMenuCursor_Main(controller_press1p2 | controller_press1p1);
      } else if (!demo_timer) {
        if (!(TitleScreen_Func1() & 1)) {
LABEL_31:
          v2 = sound_ch3;
          CODE_03AD74();
          sound_ch1 = 0;
          sound_ch2 = 0;
          sound_ch3 = v2;
          if (game_engine_subroutine != 6)
            return;
          UNUSED_byte_7E0EC8 = 0;
        }
LABEL_33:
        game_mode = 0;
        game_mode_task = 0;
        sprite0_hit_detect_flag = 0;
        fade_direction = 1;
        ++disable_screen_flag;
        return;
      }
LABEL_24:
      saved_joypad_bits = 0;
      v1 = controller_press2p1 | controller_press1p1;
      if (title_screen_erase_file_process | splash_screen_display_mario_coin_shine_flag) {
        if ((v1 & 0x40) != 0) {
          demo_timer = 24;
          if (splash_screen_display_mario_coin_shine_flag) {
            splash_screen_display_mario_coin_shine_flag = 0;
            LoadFileSelectMenu_Main();
            number_of_players = 0;
            save_buffer_2_player_flag = -1;
          }
        }
      } else if ((v1 & 0x83) != 0) {
        ChangeSelectedWorld_Main(v1 & 0x83);
        demo_timer = 24;
      }
      goto LABEL_31;
    }
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
    goto LABEL_33;
  }
  if (!number_of_players && demo_timer) {
    sound_ch3 = 42;
    goto LABEL_24;
  }
LABEL_8:
  CODE_03AD74();
  if (!demo_timer)
    goto LABEL_33;
  sound_ch3 = 41;
  demo_timer = 24;
  if (splash_screen_display_mario_coin_shine_flag) {
    if (number_of_players == 2) {
      sram_controller_type_x = (sram_controller_type_x ^ 1) & 1;
      sound_ch3 = 1;
      LoadPlayerSelectMenu_Entry2();
    } else {
      GoContinue(sram_world_number);
      var0E67 = 1;
      PlayerGfxHandler();
      LoadAreaPointer();
      ++hidden_1up_flag;
      ++offscr_hidden_1up_flag;
      ++fetch_new_game_timer_flag;
      ++game_mode;
      primary_hard_mode = player_hard_mode_flag;
      game_mode_task = 0;
      demo_timer = 0;
      for (i = 11; i >= 0; --i)
        score_and_coin_display[(uint8)i] = 0;
      tempE4 = 0;
      score_and_coin_display[5] = ComputeDigitValue(player_coin_count);
      score_and_coin_display[4] = tempE4;
      tempE4 = 0;
      score_and_coin_display[11] = ComputeDigitValue(g_byte_7E06BB);
      score_and_coin_display[10] = tempE4;
      unused_byte_7E0E1A = 1;
    }
  } else if (number_of_players == 3) {
    title_screen_erase_file_process ^= 1u;
    LoadFileSelectMenu_Entry2();
  } else if (title_screen_erase_file_process) {
    ClearSaveData_Main();
    LoadFileSelectMenu_Entry2();
    sound_ch3 = 5;
  } else {
    ++splash_screen_display_mario_coin_shine_flag;
    sram_world_number = *(&title_screen_file_aselected_world + number_of_players);
    sram_initial_selected_level = 0;
    LoadSaveFileData_Main();
    if (splash_screen_display_mario_coin_shine_flag)
      LoadPlayerSelectMenu_Main();
    else
      LoadFileSelectMenu_Main();
  }
}

uint8 ComputeDigitValue(uint8 a) {
  while (a >= 0xAu) {
    ++tempE4;
    a -= 10;
  }
  return a;
}

void GoContinue(uint8 a) {
  world_number = a;
  offscreen_players_world = a;
  CODE_05C95B();
}

void DrawMushroomIcon() {
  uint8 i;  // di

  for (i = 20; (i & 0x80u) == 0; i -= 2)
    *(uint16 *)(&vram_buffer1_offset + i) = kTitleScreenMenuCursorStripeImage[i >> 1];
  *(uint16 *)&vram_buffer1[(uint8)(4 * number_of_players) + 5] = 4654;
  --*(uint16 *)&vram_buffer1_offset;
  --*(uint16 *)&vram_buffer1_offset;
}

uint8 TitleScreen_Func1() {
  uint8 v0;  // si
  uint8 v1;  // al
  uint8 v2;  // cf
  uint8 v3;  // al
  bool rv = false;

  v0 = title_screen_menu_var0717;
  if (title_screen_menu_var0718 ||
      ((v0 = title_screen_menu_var0717 + 1, ++title_screen_menu_var0717, rv = true, !title_screen_hard_mode_flag) ? (v1 = kDATA_05EE45[v0])
                                                                                                                  : (v1 = kDATA_05EE72[v0]),
       title_screen_menu_var0718 = v1, v2 = 0, v1)) {
    if (title_screen_hard_mode_flag)
      v3 = kDATA_05EE5B[v0];
    else
      v3 = kDATA_05EE30[v0];
    saved_joypad_bits = v3;
    --title_screen_menu_var0718;
    rv = false;
  }
  return rv;
}
// 17E1: variable 'v2' is possibly undefined

void GameMode02_Cutscene() {
  RunCutsceneTask();
  if (game_mode_task) {
    object_index = 0;
    EnemiesAndLoopsCore(0);
  }
  RelativePlayerPosition();
  PlayerGfxHandler();
}

void RunCutsceneTask() {
  int8 v0;   // si
  int8 v1;   // si
  uint8 v2;  // di
  uint8 v3;  // al
  uint8 v4;  // di
  bool v5;   // cf

  if (cutscene_var1680 || world_number == 7) {
    v1 = 2 * game_mode_task;
    if (2 * game_mode_task == 6) {
      if (player_size)
        SpawnMushroomDuringPeachCutscene();
      else
        ++game_mode_task;
      ++game_mode_task;
      return;
    }
    switch (v1) {
    case 8:
      saved_joypad_bits = 0;
      controller_press1p1 = 0;
      controller_hold1p2 = 0;
      controller_press1p2 = 0;
      controller_hold2p1 = 0;
      controller_hold2p2 = 0;
      controller_press2p1 = 0;
      controller_press2p2 = 0;
      game_paused_timer = 2;
      GameMode01_Level_GameCoreRoutine();
      if (!player_size)
        ++game_mode_task;
      return;
    case 12:
      ++game_mode_task;
      ++cutscene_peach_current_state;
      return;
    case 14:
      ProcessPeachMovement();
      if (cutscene_peach_current_state >= 6u)
        ++game_mode_task;
      return;
    case 16:
      music_ch1 = 14;
      Ending_SetPaletteWriteText();
      PauseMenu_Func5();
      ++game_mode_task;
      return;
    case 18: PeachCutscene_04DE8B(); return;
    case 20: ++game_mode_task; return;
    case 22: ++game_mode_task; return;
    case 30:
      if (!--inidisp_mirror)
        game_mode_task = 12;
      return;
    case 26: CODE_04862A(); return;
    case 28: WaitForMusicAndChangeTask(); return;
    }
    if (v1 != 10) {
      if (v1 != 2) {
        if (v1 != 4) {
          if (v1 != 24) {
            if (v1) {
              Unreachable();
              while (1)
                ;
            }
            goto LABEL_10;
          }
          goto LABEL_99;
        }
LABEL_62:
        if (bowser_var0096)
          return;
        if (cutscene_peach_var0F82)
          Ending_SetGfxPtrToUpload();
        v2 = 0;
        enemy_data_a[1] = 0;
        if (obj_xpos_hi.player == enemy_data_a[0]) {
          if (world_number == 7) {
            ++enemy_data_a[1];
            CODE_04DBDA();
            goto LABEL_73;
          }
          if (world_number == 2) {
            if (obj_xpos_lo.player >= 0x44u)
              goto LABEL_73;
          } else if (obj_xpos_lo.player >= 0x54u) {
            goto LABEL_73;
          }
        }
        ++enemy_data_a[1];
        v2 = 1;
LABEL_73:
        AutoControlPlayer(v2);
        if (screen_left_xpos_hi != enemy_data_a[0]) {
          int t = cutscene_task_subpos + 0x180;
          cutscene_task_subpos = t;
          ScrollHandler(t >> 8);
          CODE_03AE2C();
          ++enemy_data_a[1];
        }
        if (!enemy_data_a[1]) {
LABEL_97:
          ++game_mode_task;
          return;
        }
        return;
      }
      CODE_04DE54();
LABEL_60:
      enemy_data_a[0] = screen_right_xpos_hi + 1;
      IncModeTask_B();
      return;
    }
LABEL_51:
    if (event_music_buffer < 6u) {
      if ((ReadReg(APUI03) & 0x7F) != 75)
        sound_ch3 = 75;
      CODE_03D809();
      if (!(level_timer_ones | (uint8)(level_timer_tens | level_timer_hundreds))) {
        sound_ch3 = 76;
        unused_byte_7E0E1A = 76;
        all_timers = 48;
        event_music_buffer = 6;
        ++game_mode_task;
      }
    }
    return;
  }
  v0 = 2 * game_mode_task;
  if (2 * game_mode_task == 10)
    goto LABEL_51;
  if (v0 == 2) {
    if (!pausemenu_var3) {
      CutsceneBowserDefeat_04ECCA();
      return;
    }
    CutsceneToad_04ED07();
    goto LABEL_60;
  }
  if (v0 == 4)
    goto LABEL_62;
  if (v0 != 6) {
    if (v0 != 8) {
      if (v0 != 12) {
        if (v0) {
          Unreachable();
          while (1)
            ;
        }
LABEL_10:
        BridgeCollapse();
        return;
      }
LABEL_99:
      if (!event_music_buffer) {
        if (cutscene_var1680 || world_number >= 7u) {
          ContinueGame();
        } else {
          area_number = 0;
          level_number = 0;
          game_mode_task = 0;
          ++world_number;
          cutscene_var0BA5 = 1;
          TransposePlayers();
          LoadAreaPointer();
          ++fetch_new_game_timer_flag;
          game_mode = 1;
        }
      }
      return;
    }
    if (cutscene_toad_text_timer)
      goto LABEL_94;
    v3 = cutscene_toad_line_to_display;
    if (cutscene_toad_line_to_display) {
      if (cutscene_toad_line_to_display >= 9u)
        goto LABEL_94;
      if (world_number == 7) {
        if (cutscene_toad_line_to_display < 3u)
          goto LABEL_94;
        v3 = cutscene_toad_line_to_display - ((cutscene_toad_line_to_display < 3u) + 1);
      } else if (cutscene_toad_line_to_display < 2u) {
        goto LABEL_94;
      }
    }
    v4 = v3;
    if (!v3) {
      if (current_player)
        v4 = v3 + 1;
LABEL_93:
      vram_buffer_addr_ctrl = v4 + 12;
      goto LABEL_94;
    }
    v4 = v3 + 1;
    if (world_number == 7)
      goto LABEL_93;
    v4 = v3;
    if (v3 >= 4u) {
LABEL_95:
      event_music_buffer = 6;
      var0E67 = 6;
      goto LABEL_97;
    }
    if (v3 < 3u)
      goto LABEL_93;
LABEL_94:
    v5 = __CFADD__(cutscene_toad_text_timer, 4);
    cutscene_toad_text_timer += 4;
    cutscene_toad_line_to_display += v5;
    if (v5 < 7)
      return;
    goto LABEL_95;
  }
  if (++cutscene_wait_before_toad_breaks_out_of_bag == 112) {
    cutscene_toad_popped_out_of_bag_flag = 1;
    cutscene_wait_before_toad_breaks_out_of_bag = 0;
    ++game_mode_task;
  }
}
// 1CFE: conditional instruction was optimized away because al.1==0

void FloateyNumbersRoutine(uint8 k) {
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
          GiveExtraLife();
          sound_ch3 = 5;
        }
        digit_modifier[kDATA_038B31[v2] >> 4] = kDATA_038B31[v2] & 0xF;
        AddToScore();
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
      DumpTwoSpr_(v5, score_spr_ypos_lo[v4]);
      tempE0 = v4;
      *(uint16 *)&tempE2 = floateynum_xpos_word[(uint8)(2 * v4) >> 1];
      *(uint16 *)&tempDE = *(uint16 *)&tempE2 + 8;
      v6 = tempE0;
      tempDD = 0;
      if (tempE3)
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
      oam->charnum = kDATA_038B19[(uint8)(2 * floateynum_control[v6])];
      v9 = kDATA_038B19[v8 + 1];
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

void ScreenRoutines() {
  int8 v0;    // si
  uint16 v1;  // si
  int v2;     // edx
  uint16 v3;  // si
  uint8 v4;   // di
  uint8 v5;   // di
  uint8 v6;   // [rsp+46h] [rbp-2h]
  uint8 v7;   // [rsp+47h] [rbp-1h]

  v0 = 2 * screen_routine_task;
  if (!(2 * screen_routine_task)) {
    if (game_mode) {
      vram_buffer_addr_ctrl = 0;
      update_entire_palette_flag = 1;
    }
    goto LABEL_53;
  }
  switch (v0) {
  case 2:
    v7 = background_color_ctrl;
    v6 = player_status;
    player_status = 0;
    background_color_ctrl = 2;
    GetPlayerColors();
    player_status = v6;
    background_color_ctrl = v7;
    goto LABEL_53;
  case 18:
    SetLevelMusic();
    CODE_04956B();
    return;
  case 20: GetBackgroundColor_0(); return;
  case 22: ++screen_routine_task; return;
  case 4: WriteGameText(0); goto LABEL_53;
  case 6:
    GetSBNibbles();
    v1 = *(uint16 *)&vram_buffer1_offset;
    v2 = *(uint16 *)&vram_buffer1_offset;
    *(uint16 *)&vram_buffer1[*(uint16 *)&vram_buffer1_offset + 1] = 29272;
    *(uint16 *)&vram_buffer1[v2 + 3] = 1792;
    *(uint16 *)&vram_buffer1[v1 + 5] = 8232;
    vram_buffer1[v1 + 7] = world_number + 1;
    vram_buffer1[v1 + 8] = 32;
    vram_buffer1[v1 + 10] = 32;
    vram_buffer1[v1 + 12] = 32;
    vram_buffer1[v1 + 9] = 36;
    vram_buffer1[v1 + 11] = level_number + 1;
    vram_buffer1[v1 + 13] = -1;
    if (!game_mode && (save_buffer_2_player_flag & 0x80u) == 0)
      vram_buffer1[v1 + 7] = save_buffer + 1;
    *(uint16 *)&vram_buffer1_offset = v1 + 12;
    v3 = v1 + 12;
    if (player_hard_mode_flag)
      vram_buffer1[v3 + 5 - 12] = 42;
    goto LABEL_53;
  case 8:
    if (game_timer_expired_flag) {
      game_timer_expired_flag = 0;
      DrawLevelPreviewSprites_Sub_New();
      v4 = CODE_0491DD();
      game_loop_toggler = 1;
      OutputInter(2u);
      if (number_of_players) {
        if ((other_player_num_lives & 0x80u) == 0) {
          *(uint16 *)&vram_buffer1[v4 + 1] = 29272;
          *(uint16 *)&vram_buffer1[v4 + 3] = 1792;
          *(uint16 *)&vram_buffer1[v4 + 5] = 8232;
          vram_buffer1[v4 + 7] = offscreen_players_world + 1;
          vram_buffer1[v4 + 8] = 32;
          vram_buffer1[v4 + 10] = 32;
          vram_buffer1[v4 + 12] = 32;
          vram_buffer1[v4 + 9] = 36;
          vram_buffer1[v4 + 11] = player_other_players_level_number_display + 1;
          vram_buffer1[v4 + 13] = -1;
          *(uint16 *)&vram_buffer1_offset = v4 + 12;
          v5 = v4 + 12;
          if (other_player_hard_mode)
            vram_buffer1[v5 + 5 - 12] = 42;
        }
      }
      return;
    }
    ++screen_routine_task;
LABEL_53:
    ++screen_routine_task;
    return;
  case 12:
    if (!game_mode)
      goto LABEL_51;
    if (game_mode == 3) {
      func_sub_8E50();
      return;
    }
    if (!alt_entrance_ctrl && (area_type == 3 || !screen_routines_flag0769)) {
      DrawLevelPreviewSprites();
      CODE_0492E7();
      OutputInter(1u);
    } else {
LABEL_51:
      NoInter();
    }
    break;
  case 16: AreaParserTaskControl(); break;
  case 24: DrawTitleScreen(); break;
  case 26: ClearBuffersDrawIcon(); break;
  case 28: WriteTopScore(); break;
  case 10:
  case 14: ResetSpritesAndScreenTimer(); break;
  default:
    Unreachable();
    while (1)
      ;
  }
}
// 7E16F6: using guessed type uint8 byte_7E16F6[10];

void OutputInter(uint8 a) {
  WriteGameText(a);
  ResetScreenTimer();
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

void NoInter() {
  screen_routine_task = 8;
}

void func_sub_8E50() {
  uint8 v0;   // di
  uint16 v1;  // si
  uint16 v2;  // di
  uint8 v3;   // al

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
    CODE_0491DD();
  }
  screen_timer = 9;
  v0 = WriteGameText(3u);
  if (number_of_players && (other_player_num_lives & 0x80u) == 0) {
    CODE_0486DF(v0);
  } else {
    v1 = 0;
    tempE5 = 0;
    v2 = *(uint16 *)&tempE4;
    do {
      v3 = *((uint8 *)kDATA_03903D + v1);
      vram_buffer1[v2 + 1] = v3;
      ++v1;
      ++v2;
    } while (v3 != 0xFF);
    *(uint16 *)&vram_buffer1_offset = v2;
  }
  current_player_mirror = 0;
  IncModeTask_B();
}
// 262B: variable 'v0' is possibly undefined

void AreaParserTaskControl() {
  if (disable_screen_flag) {
    if (disable_screen_flag != 1)
      ++disable_screen_flag;
    do
      AreaParserTaskHandler();
    while (area_parser_task_num);
    if ((--column_sets & 0x80u) != 0)
      ++screen_routine_task;
    vram_buffer_addr_ctrl = 6;
  } else {
    fade_direction = 1;
    enable_mosaic_fades_flag = 0;
  }
}

void DrawTitleScreen() {
  uint16 v0;  // si
  uint16 i;   // di
  uint16 v2;  // ax

  if (game_mode) {
    IncModeTask_B();
  } else {
    UNUSED_byte_7E0EC8 = 1;
    v0 = *(uint16 *)&vram_buffer1_offset;
    for (i = 0;; i += 2) {
      v2 = kTitleScreenLogoAndMenuStripeImage[i >> 1];
      *(uint16 *)&vram_buffer1[v0 + 1] = v2;
      if (v2 == 0xFFFF)
        break;
      v0 += 2;
    }
    *(uint16 *)&vram_buffer1_offset = v0;
    palette_anim0E20 = 0;
    music_ch1 = 0x80;
    game_loop_toggler = 0x80;
    vram_buffer_addr_ctrl = 5;
    LoadFileSelectMenu_Main();
    ++screen_routine_task;
  }
}

void ClearBuffersDrawIcon() {
  uint8 v0;  // al
  uint8 v1;  // si

  v0 = game_mode;
  if (game_mode) {
    IncModeTask_B();
  } else {
    v1 = 0;
    do {
      bridge_sprite_slot_exists_flag[v1] = v0;
      *(&g_byte_7E0400 + v1--) = v0;
    } while (v1);
    if ((save_buffer_2_player_flag & 0x80u) == 0)
      number_of_players = save_buffer_2_player_flag;
    DrawMushroomIcon();
    ++screen_routine_task;
  }
}

void WriteTopScore() {
  UpdateNumber(0xFAu);
  IncModeTask_B();
}

void IncModeTask_B() {
  ++game_mode_task;
}

uint8 WriteGameText(uint8 a) {
  uint8 v1;   // di
  uint16 v2;  // si
  uint16 v3;  // di
  uint8 v4;   // si
  uint8 v5;   // al
  bool v6;    // cf
  uint8 v7;   // al
  uint8 v8;   // di
  uint8 v9;   // si
  uint8 v10;  // di

  v1 = 2 * a;
  if ((uint8)(2 * a) >= 4u) {
    if (v1 >= 8u)
      v1 = 8;
    if (!number_of_players)
      ++v1;
  }
  tempF3 = v1;
  v2 = kGameTextOffsets[(uint8)(2 * v1) >> 1];
  v3 = *(uint16 *)&vram_buffer1_offset;
  while (kGameText[v2] != 0xFF)
    vram_buffer1[++v3] = kGameText[v2++];
  vram_buffer1[v3 + 1] = -1;
  *(uint16 *)&tempE4 = v3;
  if (a >= 4u) {
    v9 = 4 * (a - ((a < 4u) + 4));
    v10 = vram_buffer1_offset;
    tempE6 = vram_buffer1_offset + 18;
    do {
      vram_buffer1[v10 + 51] = kWarpZoneNumbers[v9++];
      v10 += 6;
    } while (v10 < tempE6);
    *(uint16 *)&vram_buffer1_offset += 64;
    v3 = v10;
  } else if (a == 1) {
    CODE_048895(v3);
    v4 = vram_buffer1_offset;
    v5 = number_of_lives + 1;
    if ((uint8)(number_of_lives + 1) >= 0xAu) {
      tempE4 = 0;
      tempE5 = 0;
      while (1) {
        v6 = v5 < 0x64u;
        v5 -= 100;
        if (v6)
          break;
        ++tempE4;
      }
      v7 = v5 + 100;
      while (1) {
        v6 = v7 < 0xAu;
        v7 -= 10;
        if (v6)
          break;
        ++tempE5;
      }
      tempE6 = v7 + 10;
      if (tempE4)
        vram_buffer1[vram_buffer1_offset + 13] = tempE4;
      vram_buffer1[v4 + 15] = tempE5;
      v5 = tempE6;
    }
    vram_buffer1[v4 + 17] = v5;
    vram_buffer1[v4 + 45] = world_number + 1;
    vram_buffer1[v4 + 49] = level_number + 1;
    if (player_hard_mode_flag)
      vram_buffer1[v4 + 43] = 42;
    v3 = (uint8)(level_number + 1);
  } else if (number_of_players && current_player_mirror) {
    v8 = vram_buffer1_offset + 9;
    if (tempF3 == 4 || tempF3 == 6) {
      do {
        vram_buffer1[v8 + 5] = *((uint8 *)kDATA_0390C7 + v8);
        vram_buffer1[v8 + 19] = kDATA_0390D1[v8];
        --v8;
      } while ((v8 & 0x80u) == 0);
    } else {
      do {
        vram_buffer1[v8 + 5] = *((uint8 *)kLuigiName + v8);
        --v8;
      } while ((v8 & 0x80u) == 0);
    }
  }
  return v3;
}

void ResetSpritesAndScreenTimer() {
  if (!screen_timer) {
    if (game_mode != 3)
      fade_direction = 1;
    ResetScreenTimer();
  }
}

void ResetScreenTimer() {
  screen_timer = 7;
  ++screen_routine_task;
}

void RenderAreaGraphics() {
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
  int v13;     // rbx
  int16 v14;   // ax

  if (!render_graphics_var0EC9) {
    *(uint16 *)&R0_ = vram_buffer2_offset;
    v0 = render_graphics_var0720;
    v1 = vram_buffer2_offset >> 1;
    vram_buffer2[v1] = render_graphics_var0720;
    v2 = v0;
    LOBYTE(v0) = HIBYTE(v0);
    HIBYTE(v0) = v2;
    render_graphics_var0ecc = v0;
    vram_buffer2[v1 + 1] = 15744;
    vram_buffer2[v1 + 2] = 36;
    vram_buffer2[v1 + 3] = 36;
    vram_buffer2[v1 + 4] = 36;
    vram_buffer2[v1 + 5] = 36;
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
      vram_buffer2[v9 + 6] = *(uint16 *)&RomPtr_00(*(uint16 *)&R6_)[v8];
      vram_buffer2[v9 + 7] = *(uint16 *)&RomPtr_00(*(uint16 *)&R6_)[(uint16)(v8 + 2)];
      ++*(uint16 *)&R0_;
      ++*(uint16 *)&R0_;
      ++*(uint16 *)&R0_;
      ++*(uint16 *)&R0_;
      v3 = R2_ + 1;
    } while ((uint8)(R2_ + 1) < 0xDu);
    v10 = vram_buffer2_offset >> 1;
    v11 = vram_buffer2[v10 + 6];
    if (v11 == 6306 || v11 == 6307) {
      vram_buffer2[v10 + 2] = v11;
      vram_buffer2[v10 + 3] = v11;
      vram_buffer2[v10 + 4] = v11;
      vram_buffer2[v10 + 5] = v11;
    }
    v12 = *(uint16 *)&R0_ + 14;
    v13 = (uint16)(*(uint16 *)&R0_ + 14) >> 1;
    vram_buffer2[v13] = -1;
    vram_buffer2_offset = v12;
    if (!cloud_type_override && area_type && area_type != 3) {
      v14 = *(uint16 *)&vram_buffer1[2 * v13 + 759];
      if (v14 == 36 || v14 == 4260) {
        render_area_gfx_0ECE |= 0x100u;
      } else if (v14 == 2568) {
        render_area_gfx_0ECE &= 0xFF00u;
      }
      CODE_048D71();
    }
    if ((++HIBYTE(render_graphics_var0720) & 0x1F) == 0)
      render_graphics_var0720 = (uint8)render_graphics_var0720 ^ 4;
    vram_buffer_addr_ctrl = 6;
  }
}

void nullsub_9390() {
  ;
}

void ColorRotation() {
  ;
}

void RemoveCoin_Axe() {
  PutBlockMetatile(3u, vram_buffer1_offset + 1);
  vram_buffer_addr_ctrl = 6;
  MoveVOffset();
}

void ReplaceBlockMetatile(uint8 k, uint8 a) {
  WriteBlockMetatile(a);
  ++block_residual_counter_unused;
  --block_repflag[k];
}

void DestroyBlockMetatile() {
  WriteBlockMetatile(0);
}

void WriteBlockMetatile(uint8 a) {
  uint8 v1;  // di

  v1 = 3;
  if (a) {
    v1 = 0;
    if (a != 91 && a != 81) {
      v1 = 1;
      if (a != 96 && a != 82)
        v1 = 2;
    }
  }
  PutBlockMetatile(v1, vram_buffer1_offset + 1);
  MoveVOffset();
}

void MoveVOffset() {
  *(uint16 *)&vram_buffer1_offset += 16;
}

void PutBlockMetatile(uint8 a, uint8 j) {
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
  RemBridge(v2, R1_);
}

void RemBridge(uint8 k, uint8 j) {
  int16 v2;  // ax
  int v3;    // rbp

  LOBYTE(v2) = R5_;
  HIBYTE(v2) = R4_;
  *(uint16 *)&vram_buffer1[j] = v2;
  *(uint16 *)&vram_buffer1[j + 8] = v2 + 0x2000;
  *(uint16 *)&vram_buffer1[j + 2] = 768;
  *(uint16 *)&vram_buffer1[j + 10] = 768;
  v3 = k >> 1;
  *(uint16 *)&vram_buffer1[j + 4] = kBlockGfxData[v3];
  *(uint16 *)&vram_buffer1[j + 6] = kBlockGfxData[v3 + 1];
  *(uint16 *)&vram_buffer1[j + 12] = kBlockGfxData[v3 + 2];
  *(uint16 *)&vram_buffer1[j + 14] = kBlockGfxData[v3 + 3];
  *(uint16 *)&vram_buffer1[j + 16] = -1;
}

void VramFunc_9B5C() {
  WriteReg(DMAP0, 0);
  WriteRegWord(OAMADDL, 0);
  WriteRegWord(BBAD0, 4u);
  WriteRegWord(A1T0H, 8u);
  WriteRegWord(DAS0L, 0x220u);
  WriteReg(MDMAEN, 1u);
  WriteReg(OAMADDH, 0x80u);
  WriteReg(OAMADDL, 0);
  if (pausemenu_var3 || (VramFunc_9BD4(1u), !vram_flag_028c) && vram_flag_028d) {
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

void VramFunc_9BD4(uint8 k) {
  if (vram_flag_028e) {
    WriteRegWord(VMADDL, player_vramaddress);
    WriteRegWord(DMAP0, 0x1801u);
    WriteRegWord(A1T0L, player_graphics_pointer.addr);
    WriteReg(A1B0, player_graphics_pointer.bank);
    WriteRegWord(DAS0L, player_graphics_upload_size);
    WriteReg(MDMAEN, k);
  }
}

void UploadStripeImage() {
  uint16 v0;  // di
  int8 i;     // al
  uint16 v2;  // di
  int8 v3;    // al
  uint8 *v4;  // rdx
  int16 v5;   // ax
  uint16 v6;  // si
  int16 v7;   // di
  uint16 v8;  // si

  WriteReg(A1B1, 0);
  R6_ = 0;
  v0 = 0;
  for (i = *IndirPtr(&R0_, 0); i >= 0; i = *IndirPtr(&R0_, v0)) {
    R4_ = i;
    v2 = v0 + 1;
    R3_ = *IndirPtr(&R0_, v2++);
    v3 = *IndirPtr(&R0_, v2) & 0x80;
    R7_ = 4 * v3 + __CFSHL__(v3, 1);
    R5_ = *IndirPtr(&R0_, v2) & 0x40;
    WriteReg(DMAP1, (R5_ >> 3) | 1);
    WriteReg(BBAD1, 0x18u);
    WriteRegWord(VMADDL, *(uint16 *)&R3_);
    v4 = IndirPtr(&R0_, v2);
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

void PrintStatusBarNumbers(uint8 a) {
  R0_ = a;
  OutputNumbers(a);
  OutputNumbers(R0_ >> 4);
}

void OutputNumbers(uint8 a) {
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
      v3 = vram_buffer1_offset;
      vram_buffer1[vram_buffer1_offset + 1] = 88;
      vram_buffer1[v3 + 2] = kStatusBarData[v2];
      vram_buffer1[v3 + 3] = kStatusBarData[v2 + 1];
      R3_ = kStatusBarData[v2 + 2];
      vram_buffer1[v3 + 4] = 2 * R3_ - 1;
      R2_ = v3;
      v4 = kStatusBarOffset[v1] - kStatusBarData[v2 + 2];
      v5 = R2_;
      do {
        vram_buffer1[v5 + 5] = displayed_score[v4];
        vram_buffer1[v5 + 6] = tempF9;
        v5 += 2;
        ++v4;
        --R3_;
      } while (R3_);
      vram_buffer1[v5 + 5] = -1;
      vram_buffer1_offset = v5 + 4;
    }
  }
}

void PrintStatusBarNumbers_Far(uint8 a) {
  PrintStatusBarNumbers(a);
}

void DigitsMathRoutine(uint8 j) {
  uint8 i;  // si
  int8 v2;  // al
  int8 k;   // si
  bool v4;  // zf

  if (game_mode && (game_mode != 2 || game_mode_task == 5)) {
    for (i = 5; (i & 0x80u) == 0; --i) {
      v2 = displayed_score[j] + digit_modifier[i];
      if (v2 < 0) {
        v4 = digit_modifier[i - 1]-- == 1;
        v2 = 9;
        if (v4) {
LABEL_12:
          if (!i) {
            i = 5;
            do
              marios_score[i--] = 9;
            while (i);
            v2 = 19;
          }
          v2 -= 10;
          ++digit_modifier[i - 1];
        }
      } else if ((uint8)v2 >= 0xAu) {
        goto LABEL_12;
      }
      displayed_score[j--] = v2;
    }
  }
  for (k = 6; k >= 0; --k)
    digit_modifier[k - 1] = 0;
}

void TitleScreen_0_InitializeGame() {
  uint8 v0;  // di
  uint8 v1;  // si

  inidisp_mirror = 0x80;
  palette_mirror[129] = 0x7FFF;
  ++update_entire_palette_flag;
  vram_buffer1[1] = -1;
  vram_buffer1[2] = -1;
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
  CODE_039F3E(v0);
  title_screen_var07FF = -91;
  random_byte1 = -91;
  g_byte_7E0EF6 = 0;
  vblank_upload_from_7f0000_flag = 0;
  g_word_7E0EF7 = 0;
  CODE_039F3E(0x6Fu);
  demo_timer = 24;
  LoadAreaPointer();
  GameMode01_Level_InitializeArea();
  fade_direction = 0;
}

void GameMode01_Level_InitializeArea() {
  int8 i;    // si
  uint8 v2;  // al
  int16 v3;  // ax
  uint8 v4;  // t0
  uint8 v5;  // di
  int8 v6;   // al

  if (world_number >= 8u)
    LoadAreaPointer();
  CODE_039F3E(0x4Bu);
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
  v6 = GetScreenPosition() & 1;
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
  GetAreaDataAddrs();
  if (primary_hard_mode || world_number >= 4u && (world_number != 4 || level_number >= 2u))
    ++secondary_hard_mode;
  if (halfway_page)
    player_entrance_ctrl = 2;
  if (area_data_addr_index != 33 && area_data_addr_index != 2)
    music_ch1 = 0x80;
  fade_direction = 1;
  ++game_mode_task;
}

void TitleScreen_2_PrimaryGameSetup() {
  if (ReadReg(APUI02) != 20) {
    CheckWhichControllersArePluggedIn_Main();
    WriteReg(APUI02, 0x14u);
    apui02_var160C = 4;
  }
  fetch_new_game_timer_flag = 1;
  player_size = 1;
  other_player_size = 1;
  level_free_movement_debug_flag = 0;
  GameMode01_Level_SecondaryGameSetup();
}

void GameMode01_Level_SecondaryGameSetup() {
  uint8 v0;  // di
  uint8 i;   // si

  fade_direction = 2;
  inidisp_mirror = 0;
  disable_screen_flag = 0;
  v0 = 0;
  do
    bridge_sprite_slot_exists_flag[v0++] = 0;
  while (v0);
  game_timer_expired_flag = 0;
  screen_routines_flag0769 = 0;
  backloading_flag = 0;
  bal_platform_alignment = -1;
  vram_buffer1[1] = -1;
  mirror_ppu_ctrl_reg1 >>= 1;
  mirror_ppu_ctrl_reg1 = 2 * mirror_ppu_ctrl_reg1 + (screen_left_xpos_hi & 1);
  unused_byte_7E0B43 = 56;
  unused_byte_7E0B42 = 72;
  unused_byte_7E0B41 = 88;
  for (i = 28; (i & 0x80u) == 0; --i)
    *(&spr_data_offset + i) = kDefaultSprOffsets[i];
  nullsub_A2C9();
  CODE_03A28F();
  ++sprite0_hit_detect_flag;
  ++game_mode_task;
}

void UNUSED_InitializeMemory(uint8 j, uint8 k) {
  R6_ = 0;
  R7_ = k;
  do
    RomPtr_RAM(*(uint16 *)&R6_)[j--] = 0;
  while (j != 0xFF);
}

void CODE_039F3E(uint8 j) {
  int8 v1;   // si
  uint8 v2;  // si

  if (area_data_addr_index == 33)
    ++fade_direction;
  v1 = 7;
  R6_ = 0;
  do {
    R7_ = v1;
    do {
      if (v1 != 1 || j < 0x50u)
        RomPtr_RAM(*(uint16 *)&R6_)[j] = 0;
      --j;
    } while (j != 0xFF);
    --v1;
  } while (v1 >= 0);
  vram_buffer1[1] = -1;
  contact_sprite_arr1[0] = 0;
  contact_sprite_arr1[1] = 0;
  contact_sprite_arr1[2] = 0;
  contact_sprite_arr1[3] = 0;
  contact_sprite_arr1[4] = 0;
  primary_hard_mode = player_hard_mode_flag;
  v2 = 64;
  do
    *(&g_byte_7E0F00 + v2++) = 0;
  while (v2);
  if (var0F0B) {
    if (!--var0F0B) {
      title_screen_hard_mode_flag = save_buffer_hard_mode_active_flag;
      primary_hard_mode = save_buffer_hard_mode_active_flag;
      player_hard_mode_flag = save_buffer_hard_mode_active_flag;
      LoadTopScoreFromSram();
    }
  }
}

void Entrance_GameTimerSetup() {
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
  BoundingBoxCore(0, alt_entrance_ctrl);
  GetPlayerColors();
  if (game_timer_setting && fetch_new_game_timer_flag) {
    level_timer_hundreds = kGameTimerData[game_timer_setting];
    level_timer_ones = 1;
    level_timer_tens = 0;
    fetch_new_game_timer_flag = 0;
    player_star_power_timer = 0;
  }
  if (vine_screen_exit_flag) {
    player_state = 3;
    InitBlock_XY_Pos(0);
    unused_block_y_pos = -16;
    v2 = 9;
    Spr02F_Vine_Init(9u, 0);
  }
  if (!area_type)
    SetupBubble(v2);
  game_engine_subroutine = 7;
}

void PlayerLoseLife() {
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
    TransposePlayers();
    ContinueGame();
  } else {
    game_mode_task = 0;
    game_mode = 3;
  }
}

void GameMode03_GameOverScreen() {
  int8 v0;  // si

  v0 = 2 * game_mode_task;
  if (2 * game_mode_task == 2) {
    ScreenRoutines();
  } else if (v0) {
    if (v0 != 4) {
      Unreachable();
      while (1)
        ;
    }
    RunGameOver();
  } else {
    SetupGameOver();
  }
}

void SetupGameOver() {
  screen_routine_task = 0;
  sprite0_hit_detect_flag = 0;
  music_ch1 = 10;
  ++disable_screen_flag;
  ++game_mode_task;
}

void RunGameOver_() {
  uint8 v0;  // di
  int8 i;    // di
  uint8 v2;  // si

  if (!number_of_players || (other_player_num_lives & 0x80u) != 0) {
    controller_press1p1 |= controller_press1p2;
    if ((controller_press1p1 & 0xC) == 0) {
LABEL_11:
      if (!pausemenu_var2) {
        if (((controller_press1p2 | controller_press1p1) & 0x10) == 0) {
          if (((controller_press1p2 | controller_press1p1) & 0x20) != 0) {
            sound_ch3 = 1;
            if (++game_over_screen_blinking_cursor_pos == 3)
              game_over_screen_blinking_cursor_pos = 0;
          }
          if (world_number != 8) {
            if (sound_ch3)
              blinking_cursor_frame_counter = 0;
            CODE_03A142();
          }
          return;
        }
        pausemenu_var2 = 32;
        sound_ch1 = 67;
        music_ch1 = -13;
        if (game_over_screen_blinking_cursor_pos)
          sound_ch1 = 59;
      }
      CODE_03A142();
      if (--pausemenu_var2)
        return;
      blinking_cursor_frame_counter = 0;
      number_of_lives = 4;
      some_flag_for_transpose_players = 0;
      player_coin_count = 0;
      player_other_players_coin_count = 0;
      sram_world_number = world_number;
      level_number = 0;
      original_level = 0;
      player_other_players_level_number_display = 0;
      player_other_players_level = 0;
      area_number = 0;
      sram_initial_selected_level = 0;
      for (i = 23; i >= 0; --i)
        marios_score[(uint8)i] = 0;
      ++hidden_1up_flag;
      if (game_over_screen_blinking_cursor_pos) {
        SaveGame_Main();
        if (game_over_screen_blinking_cursor_pos != 1) {
          ResetGame_Main();
          return;
        }
      }
LABEL_33:
      if (TransposePlayers() & 1) {
        continue_world = world_number;
        game_mode_task = 0;
        screen_timer = 0;
        game_mode = 0;
      } else {
        ContinueGame();
      }
      return;
    }
    sound_ch3 = 1;
    if ((controller_press1p1 & 8) != 0) {
      v0 = game_over_screen_blinking_cursor_pos - 1;
      if ((int8)(game_over_screen_blinking_cursor_pos - 1) < 0) {
        v0 = game_over_screen_blinking_cursor_pos;
LABEL_9:
        sound_ch3 = 0;
      }
    } else {
      v0 = game_over_screen_blinking_cursor_pos + 1;
      if (game_over_screen_blinking_cursor_pos == 2) {
        v0 = 2;
        goto LABEL_9;
      }
    }
    game_over_screen_blinking_cursor_pos = v0;
    goto LABEL_11;
  }
  v2 = RunGameOver_Sub();
  if (v2 == 2)
    goto LABEL_33;
  if (v2) {
    Unreachable();
    while (1)
      ;
  }
}

void CODE_03A142() {
  uint8 i;  // di

  oam_tile_size_buffer[0] = ((uint8)(++blinking_cursor_frame_counter & 0x10) >> 4) | 2;
  for (i = 3; (i & 0x80u) == 0; --i)
    get_OamEnt(oam_buf, i)->xpos = kDATA_03A0C8[i];
  get_OamEnt(oam_buf, 0)->ypos = kDATA_03A0CC[game_over_screen_blinking_cursor_pos];
}

void RunGameOver() {
  RunGameOver_();
}

void ContinueGame() {
  LoadAreaPointer();
  if (!cutscene_var1680 && !number_of_players) {
    player_size = 1;
    player_status = 0;
  }
  ++fetch_new_game_timer_flag;
  timer_control = 0;
  game_engine_subroutine = 0;
  game_mode_task = 0;
  game_mode = 1;
}

uint8 TransposePlayers() {
  uint8 i;   // si
  uint8 v2;  // [rsp+47h] [rbp-1h]
  uint8 v3;  // [rsp+47h] [rbp-1h]
  uint8 v4;  // [rsp+47h] [rbp-1h]
  uint8 v5;  // [rsp+47h] [rbp-1h]

  if (number_of_players && (other_player_num_lives & 0x80u) == 0) {
    v2 = player_size;
    player_size = other_player_size;
    other_player_size = v2;
    v3 = player_status;
    player_status = other_player_power_up;
    other_player_power_up = v3;
    v4 = player_hard_mode_flag;
    player_hard_mode_flag = other_player_hard_mode;
    other_player_hard_mode = v4;
    current_player ^= 1u;
    player_luigi_graphics = current_player;
    for (i = 6; (i & 0x80u) == 0; --i) {
      v5 = *(&number_of_lives + i);
      *(&number_of_lives + i) = *(&other_player_num_lives + i);
      *(&other_player_num_lives + i) = v5;
    }
    return 0;
  }
  if (some_flag_for_transpose_players)
    return 1;
  return 0;
}

uint8 TransposePlayers_Far() {
  return TransposePlayers() & 1;
}

void CODE_03A28F() {
  unused_06C9 = -1;
}

void nullsub_A2C9() {
  ;
}

void AreaParserTaskHandler() {
  uint8 v0;  // di

  v0 = area_parser_task_num;
  if (!area_parser_task_num) {
    v0 = 8;
    area_parser_task_num = 8;
  }
  AreaParserTasks(v0 - 1);
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
      CODE_049B35();
      nullsub_9390();
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
    SMB3_BufferLayer3Tilemap();
  }
}

void AreaParserTasks(uint8 a) {
  int8 v1;        // si
  int8 i;         // si
  int8 v3;        // al
  uint8 v4;       // al
  uint8 v5;       // si
  uint8 v6;       // di
  uint8 v7;       // di
  uint8 v8;       // si
  uint8 v9;       // al
  uint8 v10;      // al
  uint8 v11;      // si
  uint8 v12;      // di
  uint8 v13;      // di
  uint8 v14;      // al
  uint8 v15;      // al
  int16 v16 = 0;  // ax
  uint8 v17;      // si
  uint8 v18;      // di
  bool v19;       // cf
  int16 v20;      // cx
  int16 v21;      // ax
  uint8 v22;      // di
  uint8 v23;      // di

  v1 = 2 * a;
  if (2 * a == 2 || v1 == 4 || v1 == 10 || v1 == 12) {
    RenderAreaGraphics();
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
      ProcessAreaData();
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
      v7 = kFSceneDataOffsets[foreground_scenery - 1];
      v8 = 0;
      while (1) {
        v9 = kForeSceneryData[v7];
        if (v9)
          break;
LABEL_39:
        ++v7;
        if (++v8 == 13)
          goto LABEL_40;
      }
      if (area_type) {
        if (area_type != 3 || v9 != 0x86)
          goto LABEL_38;
      } else {
        if (area_parser_ctr1) {
          area_parser_ctr1 = 0;
LABEL_38:
          metatile_buffer[v8] = v9;
          goto LABEL_39;
        }
        ++area_parser_ctr1;
        ++v9;
      }
      v9 += 2;
      goto LABEL_38;
    }
LABEL_40:
    area_parser_var2 = 0;
    tempF9 = 0;
    area_parser_var4 = area_parser_var3++;
    if (area_type || world_number != 7) {
      v10 = kTerrainMetatiles[area_type];
      if (cloud_type_override)
        v10 = -116;
    } else {
      v10 = 101;
    }
    R7_ = v10;
    v11 = 0;
    v12 = 2 * terrain_control;
LABEL_46:
    R0_ = kTerrainRenderBits[v12];
    R1_ = v12 + 1;
    if (cloud_type_override && v11)
      R0_ &= 8u;
    v13 = 0;
    while (1) {
      if ((R0_ & kBitmasks[v13]) != 0) {
        if (obj_yspeed.bubble[0] == 3 && tempF9) {
          v14 = 104;
          R7_ = 104;
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
        } else if (obj_yspeed.bubble[0] == 3 && !area_parser_var2 && (area_parser_var4 & 1) == 0) {
          ++metatile_buffer[v11];
        }
      } else {
        tempF9 = -2;
        ++area_parser_var2;
      }
      if (++v11 == 13)
        break;
      if (area_type == 2 && v11 == 11)
        R7_ = 86;
      ++area_parser_var4;
      if (++v13 == 8) {
        v12 = R1_;
        if (R1_)
          goto LABEL_46;
        break;
      }
    }
    if (metatile_buffer[12] == 86 || metatile_buffer[12] == 114)
      ++metatile_buffer[12];
    ProcessAreaData();
    GetBlockBufferAddr(block_buffer_column_pos);
    v17 = 0;
    v18 = 0;
    do {
      R0_ = v18;
      if (render_graphics_var0EC9)
        break;
      LOBYTE(v16) = metatile_buffer[v17] & 0xC0;
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
// 4978: variable 'v16' is possibly undefined

void ProcessAreaData() {
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
        DecodeAreaData(i, v1);
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
      IncAreaObjOffset();
LABEL_23:
      v5 = *(uint16 *)&object_index;
      if ((area_object_length[*(uint16 *)&object_index] & 0x80u) == 0)
        --area_object_length[*(uint16 *)&object_index];
    }
  } while (behind_area_parser_flag || backloading_flag);
}

void IncAreaObjOffset() {
  ++area_data_offset;
  ++area_data_offset;
  if (level_3_byte_object_flag)
    ++area_data_offset;
  area_object_page_sel = 0;
  level_3_byte_object_flag = 0;
}

// local variable allocation has failed, the output may be wrong!
void DecodeAreaData(uint8 k, uint16 j) {
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
    DecodeAreaData_Sub_New();
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
      R7_ = 34;
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
        R7_ = 22;
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
  v7 = 46;
LABEL_32:
  R0_ = v7;
  if ((area_object_length[v6] & 0x80u) == 0) {
LABEL_43:
    if (tempF6) {
      DecodeAreaData_Sub2_New(WORD(tempF7));
    } else {
      v14 = R7_ + R0_;
      R4_ = kDATA_03A7C9[v14];
      R5_ = HIBYTE(kDATA_03A7C9[v14]);
      ((void (*)(uint8))funcs_4FCB[(unsigned int)(v14 * 2) >> 1])(v6);
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
    area_obj_offset_buffer[(uint8)(2 * v6) >> 1] = area_data_offset;
    if (tempF6)
      ++level_3_byte_object_flag;
    IncAreaObjOffset();
    goto LABEL_43;
  }
}
// 4C12: variables would overlap: di.1 and di.2
// 4FD3: using guessed type int (*funcs_4FCB[47])();

void ExtObj2D_LoopCmdE(uint8 k) {
  ;
}

void nullsub_A85C(uint8 k) {
  ;
}

void ExtObj2E_AlterAreaAttributes(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // [rsp+47h] [rbp-1h]

  v2 = *IndirPtr(&area_data_ptr, area_obj_offset_buffer[(uint16)(2 * k) >> 1] + 1);
  if ((v2 & 0x40) != 0) {
    v1 = v2 & 7;
    if ((v2 & 7u) >= 4) {
      background_color_ctrl = v2 & 4;
      v1 = 0;
    }
    foreground_scenery = v1;
  } else {
    terrain_control = v2 & 0xF;
    background_scenery = (uint8)(v2 & 0x30) >> 4;
  }
}

void ExtObj27_ScrollLockObject_Warp(uint8 k) {
  uint8 v1;  // si

  v1 = 4;
  if (world_number) {
    v1 = 5;
    if (area_type == 1)
      v1 = 6;
  }
  warp_zone_control = v1;
  WriteGameText(v1);
  KillEnemies(0xDu);
  ExtObj28_ScrollLockObject(v1);
}

void ExtObj28_ScrollLockObject(uint8 k) {
  scroll_lock ^= 1u;
}

void KillEnemies(uint8 a) {
  uint8 i;  // si

  R0_ = a;
  for (i = 8; (i & 0x80u) == 0; --i) {
    if (enemy_id[i] == R0_)
      enemy_flag[i] = 0;
  }
}

void ExtObj2C_AreaFrenzy(uint8 k) {
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

void ExtObj01_GrassyOrMushroomPlatform(uint8 k) {
  uint8 LrgObjAttrib;  // di
  int8 v2;             // al
  uint8 v3;            // al
  uint8 v4;            // si
  uint8 v5;            // di
  uint8 v6;            // al
  uint8 v7;            // si
  uint8 v8;            // di
  uint8 v9;            // si
  uint8 v10;           // di
  uint8 v11;           // si
  uint8 v12;           // si
  int8 v13;            // di
  uint8 v14;           // si
  int8 v15;            // di
  uint8 v16;           // si
  uint8 v17;           // si

  R4_ = *((uint8 *)kDATA_03A8C1 + (uint8)(2 * area_style));
  R5_ = *((uint8 *)kDATA_03A8C1 + (uint8)(2 * area_style) + 1);
  switch ((uint8)(2 * area_style) >> 1) {
  case 0:
    LrgObjAttrib = GetLrgObjAttrib(k);
    tree_ledge_saved_x = k;
    v2 = area_object_length[k];
    if (!v2) {
      v3 = 28;
      goto LABEL_21;
    }
    if (v2 < 0) {
      area_object_length[k] = LrgObjAttrib;
      v2 = current_column_pos_lo | column_pos_hi;
      if (__PAIR16__(current_column_pos_lo, column_pos_hi)) {
        v3 = 26;
        goto LABEL_21;
      }
    }
    tree_ledge_countdown = v2;
    v4 = R7_;
    metatile_buffer[R7_] = 27;
    v5 = v4 + 1;
    if (--tree_ledge_countdown) {
      if (tree_ledge_arr130F[tree_ledge_saved_x]) {
        metatile_buffer[v5] = 70;
        v6 = 74;
      } else {
        ++tree_ledge_arr130F[tree_ledge_saved_x];
        metatile_buffer[v5] = 69;
        v6 = 73;
      }
    } else if (tree_ledge_arr130F[tree_ledge_saved_x]) {
      tree_ledge_arr130F[tree_ledge_saved_x] = 0;
      metatile_buffer[v5] = 71;
      v6 = 75;
    } else {
      tree_ledge_arr130F[tree_ledge_saved_x] = 0;
      metatile_buffer[v5] = 72;
      v6 = 76;
    }
    v7 = v4 + 1;
    goto LABEL_20;
  case 1:;
    uint16 t = ChkLrgObjLength(k);
    R6_ = t;
    if (t & 0x100) {
      mushroom_ledge_half_len[k] = area_object_length[k] >> 1;
      v3 = 29;
LABEL_21:
      RenderUnderPart(R7_, 0, v3);
      return;
    }
    v3 = 31;
    v8 = area_object_length[k];
    if (!v8)
      goto LABEL_21;
    R6_ = mushroom_ledge_half_len[k];
    v9 = R7_;
    metatile_buffer[R7_] = 30;
    if (v8 == R6_) {
      v7 = v9 + 1;
      metatile_buffer[v7] = 79;
      v6 = 80;
LABEL_20:
      RenderUnderPart(v7 + 1, 0xFu, v6);
    }
    return;
  case 2:
    v10 = GetLrgObjAttrib(k);
    v11 = R7_;
    metatile_buffer[R7_] = 108;
    v12 = v11 + 1;
    v13 = v10 - 1;
    if (v13 >= 0) {
      metatile_buffer[v12] = 109;
      v14 = v12 + 1;
      v15 = v13 - 1;
      if (v15 >= 0)
        RenderUnderPart(v14, v15, 0x6Eu);
    }
    v16 = cannon_offset;
    cannon_ypos_lo[v16] = GetAreaObjYPosition();
    cannon_xpos_hi[v16] = column_pos_hi;
    cannon_xpos_lo[v16] = GetAreaObjXPosition();
    v17 = v16 + 1;
    if (v17 >= 6u)
      v17 = 0;
    cannon_offset = v17;
    return;
  }
}

void ExtObj09_PulleyRope(uint8 k) {
  uint8 v1;  // di

  uint8 v2 = ChkLrgObjLength(k) >> 8;
  v1 = 0;
  if (!v2) {
    v1 = 1;
    if (!area_object_length[k])
      v1 = 2;
  }
  metatile_buffer[0] = kPulleyRopeMetatiles[v1];
}

void ExtObj1F_WaterPipe(uint8 k) {
  int v1;  // edx

  GetLrgObjAttrib(k);
  v1 = R7_;
  metatile_buffer[R7_] = 117;
  metatile_buffer[v1 + 1] = 118;
}

void ExtObj22_IntroPipe(uint8 k) {
  uint8 v1;  // si
  uint8 v2;  // di
  int8 i;    // si

  ChkLrgObjFixedLength(k, 3u);
  R5_ = 8;
  R6_ = area_object_length[k];
  v1 = 9;
  bool flag = false;
  if (kDATA_03A9E3[R6_]) {
    v1 = RenderUnderPart(0, R5_, kDATA_03A9E3[R6_]);
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

void ExtObj07_VerticalPipe(uint8 k) {
  uint8 v1;                // di
  uint8 slot;              // si
  uint8 AreaObjXPosition;  // al
  uint8 v4;                // si

  v1 = CODE_03AA4D(k);
  if (R0_)
    v1 += 4;
  if (__PAIR16__(area_number, world_number)) {
    if (area_object_length[k]) {
      slot = FindEmptyEnemySlotRev();
      if (slot != 0xff) {
        AreaObjXPosition = GetAreaObjXPosition();
        obj_xpos_lo.enemy[slot] = AreaObjXPosition + 8;
        obj_xpos_hi.enemy[slot] = __CFADD__(AreaObjXPosition, 8) + column_pos_hi;
        obj_ypos_hi.enemy[slot] = 1;
        enemy_flag[slot] = 1;
        obj_ypos_lo.enemy[slot] = GetAreaObjYPosition();
        enemy_id[slot] = 13;
        PiranhaPlant_Init(slot);
      }
    }
  }
  v4 = R7_;
  metatile_buffer[R7_] = kDATA_03A9EF[v1];
  RenderUnderPart(v4 + 1, R6_ - 1, kDATA_03A9F1[v1]);
}

uint8 CODE_03AA4D(uint8 k) {
  ChkLrgObjFixedLength(k, 1u);
  R6_ = GetLrgObjAttrib(k) & 7;
  return area_object_length[k];
}

uint8 FindEmptyEnemySlot() {
  uint8 result;  // si

  for (result = 0; result != 8; ++result) {
    if (!enemy_flag[result])
      break;
  }
  return result;
}

uint8 FindEmptyEnemySlotRev() {
  uint8 result;  // si

  for (result = 8; result != 0xFF; --result) {
    if (!enemy_flag[result])
      break;
  }
  return result;
}

void ExtObj0D_HoleWater(uint8 k) {
  uint8 v1;  // si
  uint8 v2;  // di

  ChkLrgObjLength(k);
  v1 = 10;
  if (area_type == 3)
    v1 = 11;
  v2 = area_type;
  metatile_buffer[v1] = kDATA_03AA78[area_type];
  RenderUnderPart(v1 + 1, 1u, kDATA_03AA7C[v2 >> 1]);
}

void ExtObj0E_QuestionBlockHigh(uint8 k) {
  CODE_03AAA4(k, 3u);
}

void ExtObj0E_QuestionBlockLow(uint8 k) {
  CODE_03AAA4(k, 7u);
}

void CODE_03AAA4(uint8 k, uint8 a) {
  ChkLrgObjLength(k);
  metatile_buffer[a] = -25;
}

void ExtObj0A_Bridge_High(uint8 k) {
  CODE_03AABA(k, 6u);
}

void ExtObj0B_Bridge_Middle(uint8 k) {
  CODE_03AABA(k, 7u);
}

void ExtObj0B_Bridge_Low(uint8 k) {
  CODE_03AABA(k, 9u);
}

void CODE_03AABA(uint8 k, uint8 a) {
  uint8 v2;  // al

  ChkLrgObjLength(k);
  if (area_object_length[k]) {
    if (tree_ledge_arr130F[k]) {
      v2 = 13;
    } else {
      ++tree_ledge_arr130F[k];
      v2 = 14;
    }
  } else {
    tree_ledge_arr130F[k] = 0;
    v2 = 15;
  }
  metatile_buffer[a] = v2;
  RenderUnderPart(a + 1, 0, 0x6Bu);
}

void ExtObj23_FlagpoleObject(uint8 j) {
  uint8 AreaObjXPosition;  // al

  metatile_buffer[0] = 40;
  RenderUnderPart(1u, 8u, 0x29u);
  metatile_buffer[10] = 100;
  AreaObjXPosition = GetAreaObjXPosition();
  obj_xpos_lo.enemy[5] = AreaObjXPosition - 8;
  obj_xpos_hi.enemy[5] = column_pos_hi - (AreaObjXPosition < 8u);
  obj_ypos_lo.enemy[5] = 48;
  flagpole_score_ypos_lo = -80;
  enemy_id[5] = 48;
  ++enemy_flag[5];
  g_byte_7E0FB4 = -1;
  g_byte_7E0FB5 = -1;
  g_byte_7E0FB6 = -1;
  g_byte_7E0FB7 = -1;
}
// 7E023D: using guessed type int8;

void ExtObj04_RowOfCoins(uint8 k) {
  GetRow(k, kCoinMetatileData[area_type]);
}

void ExtObj26_CastleBridge(uint8 k) {
  ChkLrgObjFixedLength(k, 0xCu);
  ExtObj25_ChainObj(k);
}

void ExtObj24_AxeObj(uint8 k) {
  vram_buffer_addr_ctrl = 8;
  ExtObj25_ChainObj(k);
}

void ExtObj25_ChainObj(uint8 k) {
  CODE_03AB55(kCObjectRow[R0_ - 2], kCObjectMetatile[R0_ - 2]);
}

void ExtObj20_EmptyBlock(uint8 k) {
  GetLrgObjAttrib(k);
  CODE_03AB55(R7_, 0xFCu);
}

void CODE_03AB55(uint8 k, uint8 a) {
  RenderUnderPart(k, 0, a);
}

void ExtObj02_RowOfBricks(uint8 k) {
  uint8 v1;  // di

  v1 = area_type;
  if (cloud_type_override)
    v1 = 4;
  GetRow(k, kBrickMetatiles[v1]);
}

void ExtObj03_RowOfSolidBlocks(uint8 k) {
  GetRow(k, kSolidBlockMetatiles[area_type]);
}

void GetRow(uint8 k, uint8 a) {
  ChkLrgObjLength(k);
  RenderUnderPart(R7_, 0, a);
}

void ExtObj05_ColumnOfBricks(uint8 k) {
  uint8 LrgObjAttrib;  // di
  uint8 a;             // [rsp+47h] [rbp-1h]

  a = kBrickMetatiles[area_type];
  LrgObjAttrib = GetLrgObjAttrib(k);
  RenderUnderPart(R7_, LrgObjAttrib, a);
}

void ExtObj06_ColumnOfSolidBlocks(uint8 k) {
  uint8 LrgObjAttrib;  // di
  uint8 a;             // [rsp+47h] [rbp-1h]

  a = kSolidBlockMetatiles[area_type];
  LrgObjAttrib = GetLrgObjAttrib(k);
  RenderUnderPart(R7_, LrgObjAttrib, a);
}

void ExtObj21_Jumpspring(uint8 k) {
  uint8 EmptyEnemySlot;    // si
  uint8 AreaObjYPosition;  // al
  int v3;                  // edx

  GetLrgObjAttrib(k);
  EmptyEnemySlot = FindEmptyEnemySlot();
  obj_xpos_lo.enemy[EmptyEnemySlot] = GetAreaObjXPosition();
  obj_xpos_hi.enemy[EmptyEnemySlot] = column_pos_hi;
  AreaObjYPosition = GetAreaObjYPosition();
  obj_ypos_lo.enemy[EmptyEnemySlot] = AreaObjYPosition;
  obj_xspeed.enemy[EmptyEnemySlot] = AreaObjYPosition;
  enemy_id[EmptyEnemySlot] = 50;
  obj_ypos_hi.enemy[EmptyEnemySlot] = 1;
  ++enemy_flag[EmptyEnemySlot];
  v3 = R7_;
  metatile_buffer[R7_] = 111;
  metatile_buffer[v3 + 1] = 112;
}

void ExtObj19_Hidden1upBlock(uint8 k) {
  if (hidden_1up_flag) {
    hidden_1up_flag = 0;
    BrickWithItem(k);
  }
}

void ExtObj18_QuestionBlock(uint8 k) {
  uint8 v1;  // [rsp+47h] [rbp-1h]

  v1 = kBrickQBlockMetatiles[GetAreaObjectID()];
  GetLrgObjAttrib(k);
  metatile_buffer[R7_] = v1;
}

void ExtObj1D_BrickWith10Coins(uint8 k) {
  brick_coin_timer_flag = 0;
  BrickWithItem(k);
}

void BrickWithItem(uint8 k) {
  int8 v1;   // al
  uint8 v2;  // [rsp+47h] [rbp-1h]

  R7_ = GetAreaObjectID();
  v1 = 0;
  if (area_type != 1)
    v1 = 5;
  v2 = kBrickQBlockMetatiles[(uint8)(R7_ + v1)];
  GetLrgObjAttrib(k);
  metatile_buffer[R7_] = v2;
}

uint8 GetAreaObjectID() {
  return R0_;
}

void ExtObj08_Hole(uint8 k) {
  uint16 v1;   // di
  uint8 v2;    // si
  uint8 xpos;  // al
  uint8 v4;    // si

  uint8 was_unk = sign8(area_object_length[k]);
  v1 = ChkLrgObjLength(k);
  if ((v1 & 0x100) && !area_type) {
    v2 = cannon_offset;
    xpos = GetAreaObjXPosition();
    cannon_xpos_lo[v2] = xpos - 16;
    cannon_xpos_hi[v2] = column_pos_hi - (xpos < 0x10u);
    cannon_ypos_lo[v2] = 16 * (v1 + 2);
    v4 = v2 + 1;
    if (v4 >= 5u)
      v4 = 0;
    cannon_offset = v4;
  }
  RenderUnderPart(8u, 0xFu, 0);
}

uint8 RenderUnderPart(uint8 k, uint8 j, uint8 a) {
  uint8 v3;  // di

  do {
    area_object_height = j;
    v3 = metatile_buffer[k];
    if (!v3 || v3 != 27 && v3 != 30 && (v3 == 0xE7 || v3 != 70 && v3 != 74 && v3 < 0xE7u && (v3 != 87 && v3 != 86 || a != 80))) {
      metatile_buffer[k] = a;
    }
    if (++k >= 0xDu)
      break;
    j = area_object_height - 1;
  } while ((int8)(area_object_height - 1) >= 0);
  return k;
}

uint16 ChkLrgObjLength(uint8 k) {
  uint8 j;  // di

  j = GetLrgObjAttrib(k);
  return ChkLrgObjFixedLength(k, j);
}

uint16 ChkLrgObjFixedLength(uint8 k, uint8 jin) {
  uint16 j = jin;
  if ((area_object_length[k] & 0x80u) != 0) {
    area_object_length[k] = j;
    j |= 0x100;
  }
  return j;
}

uint8 GetLrgObjAttrib(uint8 k) {
  uint16 v1;  // di

  v1 = area_obj_offset_buffer[(uint16)(2 * k) >> 1];
  R7_ = *IndirPtr(&area_data_ptr, v1) & 0xF;
  return *IndirPtr(&area_data_ptr, v1 + 1) & 0xF;
}

uint8 GetAreaObjXPosition() {
  return 16 * current_column_pos_lo;
}

uint8 GetAreaObjYPosition() {
  return 16 * R7_ + 32;
}

void GetBlockBufferAddr(uint8 a) {
  R7_ = kBlockBufferAddr[(a >> 4) + 2];
  R6_ = kBlockBufferAddr[a >> 4] + (a & 0xF);
}

uint8 RenderUnderPart_Far(uint8 k, uint8 j, uint8 a) {
  return RenderUnderPart(k, j, a);
}

uint16 ChkLrgObjFixedLength_Far(uint8 k, uint8 j) {
  return ChkLrgObjFixedLength(k, j);
}

uint8 GetAreaObjXPosition_Far() {
  return GetAreaObjXPosition();
}

uint8 FindEmptyEnemySlot_Far() {
  return FindEmptyEnemySlot();
}

void GameMode01_Level() {
  int8 v0;  // si

  v0 = 2 * game_mode_task;
  if (2 * game_mode_task == 2) {
    ScreenRoutines();
  } else if (v0) {
    if (v0 == 4) {
      GameMode01_Level_SecondaryGameSetup();
    } else {
      if (v0 != 6) {
        Unreachable();
        while (1)
          ;
      }
      GameMode01_Level_GameCoreRoutine();
    }
  } else {
    GameMode01_Level_InitializeArea();
  }
}

void GameMode01_Level_GameCoreRoutine() {
  ControllerStuff_05C860();
  CODE_03AD74();
}

void CODE_03AD74() {
  uint8 v0;  // si
  uint8 v1;  // al

  if (!player_state)
    var0E67 = 0;
  saved_joypad_bits = *(&saved_joypad_bits + current_player);
  GameRoutines();
  if (game_mode_task >= 3u) {
    ProcFireball_Bubble();
    v0 = 0;
    while (1) {
      object_index = v0;
      if (var0E67 == 127)
        break;
      EnemiesAndLoopsCore(v0);
      if (!var0E67)
        FloateyNumbersRoutine(v0);
      if (++v0 == 10) {
        ProcessContactSprites();
        if (var0E67)
          var0E67 = 127;
        break;
      }
    }
    GetPlayerOffscreenBits();
    RelativePlayerPosition();
    PlayerGfxHandler();
    object_index = 1;
    BlockObjectsCore(1u);
    object_index = 0;
    BlockObjectsCore(0);
    BlockObjMT_Updater();
    MiscObjectsCore();
    ProcessCannons();
    ProcessWhirlpools();
    FlagpoleRoutine();
    RunGameTimer();
    ColorRotation();
    if (sign8(obj_ypos_hi.player - 2)) {
      if (!player_star_power_timer) {
        if (interval_timer_control == 1 && game_engine_subroutine != 12)
          GetPlayerColors();
        ResetPalStar();
        goto LABEL_23;
      }
      if (player_star_power_timer == 4 && !interval_timer_control)
        SetLevelMusic();
    }
    v1 = frame_counter;
    if (player_star_power_timer < 8u)
      v1 = frame_counter >> 2;
    CyclePlayerPalette(v1);
LABEL_23:
    buttons_a_b_previous = buttons_a_b;
    buttons_left_right = 0;
    CODE_03AE2C();
  }
}

void CODE_03AE2C() {
  if (vram_buffer_addr_ctrl != 6) {
    if (!area_parser_task_num) {
      if (sign8(scroll_thirty_two - 32))
        return;
      scroll_thirty_two -= 32;
      LOBYTE(vram_buffer2_offset) = 0;
    }
    AreaParserTaskHandler();
  }
}

void ScrollHandler(int scrollamt) {
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
    GetScreenPosition();
    scroll_interval_timer = 8;
  }
  R0_ = GetXOffscreenBits(0);
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

uint8 GetScreenPosition() {
  uint8 result;  // al

  screen_right_xpos = screen_left_xpos_lo - 1;
  result = (screen_left_xpos_lo != 0) + screen_left_xpos_hi;
  screen_right_xpos_hi = result;
  return result;
}

void GameRoutines() {
  int8 v0;  // si

  v0 = 2 * game_engine_subroutine;
  if (2 * game_engine_subroutine) {
    switch (v0) {
    case 12: PlayerLoseLife(); break;
    case 14: PlayerEntrance(); break;
    case 16: PlayerCtrlRoutine(); break;
    case 2: Vine_AutoClimb(); break;
    case 6: VerticalPipeEntry(); break;
    case 4: SideExitPipeEntry(); break;
    case 18: PlayerChangeSize(); break;
    case 20: PlayerInjuryBlink(); break;
    case 22: PlayerDeath(); break;
    case 24: PlayerFireFlower(); break;
    case 8: FlagpoleSlide(); break;
    case 10: PlayerEndLevel(); break;
    default:
      Unreachable();
      while (1)
        ;
    }
  } else {
    Entrance_GameTimerSetup();
  }
}

void PlayerEntrance() {
  uint8 player;  // al
  uint8 v1;      // di
  uint8 v2;      // al

  if (alt_entrance_ctrl != 2) {
    if (obj_ypos_lo.player < 0x30u) {
      AutoControlPlayer(0);
      return;
    }
    if (player_entrance_ctrl == 6 || player_entrance_ctrl == 7) {
      if ((player_sprattrib & 0xF0) != 0) {
        AutoControlPlayer(1u);
      } else {
        EnterSidePipe();
        if (!--change_area_timer) {
          fade_direction = 1;
          enable_mosaic_fades_flag = 1;
          ++screen_routines_flag0769;
          ++area_number;
          LoadAreaPointer();
          ++fetch_new_game_timer_flag;
          ChgAreaMode();
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
      AutoControlPlayer(v2);
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
    MovePlayerYAxis(0xFFu);
    if (obj_ypos_lo.player < 0x91u)
      goto LABEL_19;
  }
}

void AutoControlPlayer(uint8 a) {
  saved_joypad_bits = a;
  auto_control_player_var1 = 1;
  func_sub_B02C();
}

void PlayerCtrlRoutine() {
  auto_control_player_var1 = 0;
  func_sub_B02C();
}

void func_sub_B02C() {
  uint8 v0;  // al
  bool v1;   // cf
  uint8 v2;  // di
  uint8 v3;  // di
  uint8 v4;  // al
  uint8 v6;  // al
  uint8 v7;  // al
  int8 v8;   // si

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
  if (!debug_flag)
    goto LABEL_36;
  if ((*(&controller_hold2p1 + current_player_mirror) & 0xC0) != 0) {
    if ((*(&controller_hold2p1 + current_player_mirror) & 0x80) != 0) {
      player_size = 0;
      player_status = 1;
    } else {
      player_size = 0;
      player_status = 2;
    }
  }
  if ((controller_press1p1 & 0x20) != 0) {
    level_free_movement_debug_flag ^= controller_press1p1 & 0x20;
    disable_collision_detection = level_free_movement_debug_flag >> 5;
  }
  if (level_free_movement_debug_flag) {
    player_star_power_timer = 16;
    if ((*(&controller_hold2p1 + current_player) & 0x10) == 0 || (frame_counter & 7) != 0) {
      if ((frame_counter & 7) == 0 && (saved_joypad_bits & 0x80u) != 0) {
        player_size ^= 1u;
        player_status ^= 2u;
        GetPlayerColors();
      }
      v0 = saved_joypad_bits & 3;
      if ((saved_joypad_bits & 3) != 0) {
        player_facing_dir = buttons_left_right;
        v1 = __CFADD__(kDATA_03AFE6[v0 - 1], obj_xpos_lo.player);
        obj_xpos_lo.player += kDATA_03AFE6[v0 - 1];
        obj_xpos_hi.player += kDATA_03AFE8[v0 - 1] + v1;
      }
      if ((saved_joypad_bits & 0xC) != 0) {
        v2 = (uint8)(saved_joypad_bits & 0xC) >> 2;
        v1 = __CFADD__(kDATA_03AFE6[v2 - 1], obj_ypos_lo.player);
        obj_ypos_lo.player += kDATA_03AFE6[v2 - 1];
        obj_ypos_hi.player += kDATA_03AFE8[v2 - 1] + v1;
      }
    } else if (saved_joypad_bits & 1) {
      level_timer_tens = 9;
      level_timer_ones = 9;
      level_timer_hundreds = 9;
    } else if ((saved_joypad_bits & 2) != 0) {
      level_timer_tens = 0;
      level_timer_ones = 0;
      level_timer_hundreds = 0;
      level_free_movement_debug_flag = 0;
    } else if ((saved_joypad_bits & 4) == 0 && (saved_joypad_bits & 8) != 0) {
      GiveExtraLife();
    }
  } else {
LABEL_36:
    PlayerMovementSubs();
  }
  v3 = 1;
  if (!player_size) {
    v3 = 0;
    if (crouching_flag)
      v3 = 2;
  }
  player_hitbox_ctrl = v3;
  v4 = 1;
  if (obj_xspeed.player) {
    if ((obj_xspeed.player & 0x80u) != 0)
      v4 = 2;
    player_moving_dir = v4;
  }
  ScrollHandler(-1);
  GetPlayerOffscreenBits();
  RelativePlayerPosition();
  BoundingBoxCore(0, 0);
  PlayerBGCollision();
  if (obj_ypos_lo.player >= 0x40u && game_engine_subroutine != 5 && game_engine_subroutine != 7 && game_engine_subroutine >= 4u) {
    if (game_engine_subroutine == 11)
      v6 = player_sprattrib & 0xCE | 0x30;
    else
      v6 = player_sprattrib & 0xCE | 0x20;
    player_sprattrib = v6;
  }
  v7 = obj_ypos_hi.player;
  if (!sign8(obj_ypos_hi.player - 2)) {
    scroll_lock = 1;
    R7_ = 4;
    v8 = 0;
    if (game_timer_expired_flag || !cloud_type_override) {
      v8 = 1;
      if (game_engine_subroutine != 11) {
        if (!death_music_loaded) {
          ++death_music_loaded;
          music_ch1 = 9;
          var0E67 = obj_ypos_hi.player;
          v7 = 1;
          player_size = 1;
          player_status = 0;
        }
        R7_ = 6;
      }
    }
    if (!sign8(v7 - R7_)) {
      if ((int8)(v8 - 1) < 0) {
        vine_screen_exit_flag = 0;
        SetEntr();
        ++alt_entrance_ctrl;
      } else if (!event_music_buffer) {
        game_engine_subroutine = 6;
      }
    }
  }
}

void Vine_AutoClimb() {
  if (obj_ypos_hi.player || obj_ypos_lo.player >= 0xE4u) {
    vine_screen_exit_flag = 8;
    var0E67 = 8;
    player_state = 3;
    AutoControlPlayer(8u);
  } else {
    SetEntr();
  }
}

void SetEntr() {
  alt_entrance_ctrl = 2;
  ChgAreaMode();
}

void VerticalPipeEntry() {
  uint8 v0;  // di

  enable_mosaic_fades_flag = 1;
  vertical_pipe_flag_var0218 = 1;
  if (frame_counter & 1)
    MovePlayerYAxis(1u);
  ScrollHandler(-1);
  v0 = 0;
  if (!warp_zone_control) {
    v0 = 1;
    if (area_type == 3)
      v0 = 2;
  }
  if (!--change_area_timer) {
    alt_entrance_ctrl = v0;
    ChgAreaMode();
  }
}

void MovePlayerYAxis(uint8 a) {
  obj_ypos_lo.player += a;
}

void SideExitPipeEntry() {
  var0E67 = 1;
  enable_mosaic_fades_flag = 1;
  EnterSidePipe();
  if (!--change_area_timer) {
    alt_entrance_ctrl = 2;
    ChgAreaMode();
  }
}

void ChgAreaMode() {
  fade_direction = 1;
  var0E67 = 1;
  game_mode_task = 0;
  sprite0_hit_detect_flag = 0;
}

void EnterSidePipe() {
  uint8 v0;  // di

  obj_xspeed.player = 8;
  v0 = 1;
  if ((obj_xpos_lo.player & 0xF) == 0) {
    obj_xspeed.player = 0;
    v0 = 0;
  }
  AutoControlPlayer(v0);
}

void PlayerChangeSize() {
  if (timer_control == 0xF8) {
    InitChangeSize();
  } else if (timer_control == 0xC4) {
    DonePlayerTask();
  }
}

void PlayerInjuryBlink() {
  if (timer_control >= 0xF0u) {
    if (timer_control == 0xF0)
      InitChangeSize();
  } else if (timer_control == 0xC8) {
    DonePlayerTask();
  } else {
    PlayerCtrlRoutine();
  }
}

void InitChangeSize() {
  if (!player_change_size_flag) {
    player_anim_ctrl = player_change_size_flag++;
    player_size ^= 1u;
  }
}

void PlayerDeath() {
  if (timer_control < 0xF0u)
    PlayerCtrlRoutine();
}

void DonePlayerTask() {
  timer_control = 0;
  GetPlayerColors();
  game_engine_subroutine = 8;
}

void PlayerFireFlower() {
  if (timer_control == 0xC0) {
    DonePlayerTask();
    ResetPalStar();
  } else {
    CyclePlayerPalette(2 * ~timer_control);
  }
}

void CyclePlayerPalette(uint8 a) {
  uint16 v1;  // si
  uint16 i;   // di

  v1 = (8 * a) & 0x60;
  if (current_player)
    v1 += 32;
  for (i = 480; i != 512; i += 2) {
    palette_mirror[i >> 1] = kDATA_05ED91[v1 >> 1];
    v1 += 2;
  }
  update_entire_palette_flag = 1;
}

void ResetPalStar() {
  player_sprattrib = player_sprattrib & 0xF1 | 0xE;
}

void FlagpoleSlide() {
  uint8 v0;  // al

  if (enemy_id[5] == 48) {
    v0 = 0;
    flagpole_sound_queue = 0;
    if (obj_ypos_lo.player < 0x9Eu)
      v0 = 4;
    AutoControlPlayer(v0);
  } else {
    ++game_engine_subroutine;
  }
}

void PlayerEndLevel() {
  if (HandleMarioGoalWalk()) {
    AutoControlPlayer(1u);
    if (obj_ypos_lo.player >= 0xAEu)
      scroll_lock = 0;
  }
  if (star_flag_task_control == 5) {
    if (++level_number == 3 && coin_tally_for_1ups >= kHidden1UpCoinAmts[world_number])
      ++hidden_1up_flag;
    ++area_number;
    halfway_page = 0;
    TransposePlayers();
    LoadAreaPointer();
    ++fetch_new_game_timer_flag;
    ChgAreaMode();
  }
}

void PlayerMovementSubs() {
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
  PlayerPhysicsSub();
  if (player_change_size_flag)
    return;
  if (player_state != 3)
    climb_side_timer = 24;
  v1 = 2 * player_state;
  if (!(2 * player_state)) {
    GetPlayerAnimSpeed();
    if (buttons_left_right)
      player_facing_dir = buttons_left_right;
    ImposeFriction(buttons_left_right);
    player_x_scroll = MovePlayerHoriz();
    return;
  }
  if (v1 == 4) {
    vertical_force = vertical_force_down;
LABEL_28:
    if (buttons_left_right)
      ImposeFriction(buttons_left_right);
    player_x_scroll = MovePlayerHoriz();
    if (game_engine_subroutine == 11)
      vertical_force = 40;
    MovePlayerVert();
    return;
  }
  if (v1 == 2) {
    if ((obj_yspeed.player & 0x80u) == 0 ||
        (buttons_a_b_previous & buttons_a_b & 0x80) == 0 && (uint8)(jump_origin_y_pos_lo - obj_ypos_lo.player) >= diff_to_halt_jump) {
      vertical_force = vertical_force_down;
    }
    if (swimming_flag) {
      GetPlayerAnimSpeed();
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

void PlayerPhysicsSub() {
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
    vertical_force = kJumpMForceData[v2];
    vertical_force_down = kFallMForceData[v2];
    obj_sub_yspeed.player = kInitMForceData[v2];
    obj_yspeed.player = kPlayerYSpdData[v2];
    if (swimming_flag) {
      sound_ch1 = 14;
      if (obj_ypos_lo.player < 0x14u)
        obj_yspeed.player = 0;
    } else {
      sound_ch2 = 1;
    }
  }
  v3 = 0;
  R0_ = 0;
  if (player_state) {
    if (player_x_speed_absolute < 0x19u)
      goto LABEL_37;
  } else {
    v3 = 1;
    if (!area_type)
      goto LABEL_37;
    v3 = 0;
    if (buttons_left_right != player_moving_dir)
      goto LABEL_37;
    if ((buttons_a_b & 0x40) != 0) {
      running_timer = 10;
      goto LABEL_41;
    }
    if (!running_timer) {
LABEL_37:
      ++v3;
      ++R0_;
      if (running_speed || player_x_speed_absolute >= 0x21u)
        ++R0_;
    }
  }
LABEL_41:
  max_left_speed = kMaxLeftXSpdData[v3];
  if (game_engine_subroutine == 7)
    v3 = 3;
  max_right_speed = kMaxRightXSpdData[v3];
  friction_adder_low = kFrictionData[R0_];
  friction_adder_high = 0;
  if (player_facing_dir != player_moving_dir) {
    v4 = __CFSHL__(friction_adder_low, 1);
    friction_adder_low *= 2;
    friction_adder_high = 2 * friction_adder_high + v4;
  }
}

void GetPlayerAnimSpeed() {
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

void ImposeFriction(uint8 a) {
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

void ProcFireball_Bubble() {
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
    ProcessPlayerFireballs(0);
    ProcessPlayerFireballs(1u);
  }
  if (!area_type) {
    for (i = 2; i >= 0; --i) {
      object_index = i;
      BubbleCheck(i);
      RelativeBubblePosition(i);
      GetBubbleOffscreenBits(i);
      DrawBubble(i);
    }
  }
}

void ProcessPlayerFireballs(uint8 k) {
  uint8 v1;  // di
  bool v2;   // cf
  uint8 v3;  // si
  uint8 v4;  // si

  object_index = k;
  if (__CFSHL__(fireball_state[k], 1)) {
    RelativeFireballPosition(k);
    DrawExplodingPlayerFireball(k);
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
      ImposeGravity(v3, 0);
      MoveObjectHoriz(v3);
      v4 = object_index;
      RelativeFireballPosition(object_index);
      GetFireballOffscreenBits(v4);
      GetFireballBoundBox(v4);
      FireballBGCollision(v4);
      if ((offscreen_bits.fireball & 0xFC) == 0) {
        FireballEnemyCollision(v4);
LABEL_13:
        DrawFireball(v4);
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

void BubbleCheck(uint8 k) {
  R7_ = *(&random_byte2 + k) & 1;
  if (obj_ypos_lo.bubble[k] == 0xF8) {
    if (!air_bubble_timer)
      SetupBubble(k);
  } else {
    func_sub_B7F4(k);
  }
}

void SetupBubble(uint8 k) {
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
  func_sub_B7F4(k);
}

void func_sub_B7F4(uint8 k) {
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

void RunGameTimer() {
  if (game_mode && game_engine_subroutine >= 8u && game_engine_subroutine != 11 && sign8(obj_ypos_hi.player - 2) && !game_paused_timer) {
    if (level_timer_ones | (uint8)(level_timer_tens | level_timer_hundreds)) {
      if (level_timer_hundreds == 1 && !__PAIR16__(level_timer_ones, level_timer_tens))
        sound_ch1 = -1;
      game_paused_timer = 24;
      digit_modifier[5] = -1;
      if (!level_free_movement_debug_flag)
        DigitsMathRoutine(0x23u);
      PrintStatusBarNumbers(0xA4u);
    } else {
      player_status = 0;
      ForceInjury(0);
      ++game_timer_expired_flag;
    }
  }
}

void WarpZoneObject(uint8 k) {
  if (scroll_lock) {
    if ((obj_ypos_hi.player & obj_ypos_lo.player) == 0) {
      scroll_lock = 0;
      ++warp_zone_control;
      EraseEnemyObject(k);
    }
  }
}

void ProcessWhirlpools() {
  uint8 v0;  // di
  uint8 v1;  // al
  bool v2;   // cf
  uint8 v3;  // al

  if (!area_type) {
    cannon_timer[0] = area_type;
    AdjustUnderwaterHDMAGradient();
    if (!timer_control) {
      v0 = 4;
      while (1) {
        uint16 t = cannon_ypos_lo[v0] + cannon_xpos_lo[v0];
        R2_ = t;
        if (cannon_xpos_hi[v0]) {
          R1_ = cannon_xpos_hi[v0] + (t >> 8);
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
          ImposeGravity(0, 0);
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

void FlagpoleRoutine() {
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
        int t0 = kFlagpoleScoreDigits[flagpole_score];
        digit_modifier[t0] = kFlagpoleScoreMods[flagpole_score];
        AddToScore();
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
    GetEnemyOffscreenBits(v0);
    RelativeEnemyPosition(v0);
    FlagpoleGfxHandler(v0);
  }
}

void JumpspringHandler(uint8 k) {
  uint8 v1;  // di

  GetEnemyOffscreenBits(k);
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
    if (v1 && (buttons_a_b & 0x80u) != 0 && (buttons_a_b_previous & buttons_a_b & 0x80) == 0)
      jumpspring_force = -12;
    if (v1 == 3) {
      obj_yspeed.player = jumpspring_force;
      jumpspring_anim_ctrl = 0;
      sound_ch3 = 8;
    }
  }
  RelativeEnemyPosition(k);
  EnemyGfxHandler_New(k);
  OffscreenBoundsCheck(k);
  if (jumpspring_anim_ctrl) {
    if (!jumpspring_timer) {
      jumpspring_timer = 4;
      ++jumpspring_anim_ctrl;
    }
  }
}

void Spr02F_Vine_Init(uint8 k, uint8 j) {
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

void Spr02F_Vine_Init2(uint8 k) {
  Spr02F_Vine_Init(k, 0);
}

void VineObjectHandler(uint8 k) {
  uint8 v1;  // al

  if (k == 9) {
    if (vine_at_entrance_flag)
      v1 = kVineHeightData[0];
    else
      v1 = kVineHeightData[1];
    if (v1 != vine_height && frame_counter & 1) {
      obj_ypos_lo.enemy[9] -= !(frame_counter & 1) + 1;
      ++vine_height;
    }
    if (vine_height >= 8u) {
      RelativeEnemyPosition(9u);
      GetEnemyOffscreenBits(9u);
      DrawVine(0);
      if ((offscreen_bits.enemy & 0xF) == 15) {
        EraseEnemyObject(9u);
        vine_flag_offset = 0;
        vine_height = 0;
      }
      if (vine_height >= 0x20u) {
        BlockBufferCollision(0xAu, 0x1Bu, 1u);
        if (R2_ < 0xD0u && (vine_at_entrance_flag || (R2_ & 0x80u) == 0) && !RomPtr_RAM(*(uint16 *)&R6_)[R2_])
          RomPtr_RAM(*(uint16 *)&R6_)[R2_] = 42;
      }
    }
  }
}

void ProcessCannons() {
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
      OffscreenBoundsCheck(v0);
      if (enemy_flag[v0]) {
        GetEnemyOffscreenBits(v0);
        BulletBillHandler(v0);
      }
    }
    goto LABEL_13;
  }
}

void BulletBillHandler(uint8 k) {
  uint8 v1;  // di

  if (timer_control) {
LABEL_13:
    GetEnemyOffscreenBits(k);
    RelativeEnemyPosition(k);
    GetEnemyBoundBox(k);
    PlayerEnemyCollision(k);
    EnemyGfxHandler_New(k);
    return;
  }
  if (!enemy_state[k]) {
    if ((offscreen_bits.enemy & 0xC) == 12)
      goto LABEL_14;
    v1 = 1;
    if ((PlayerEnemyDiff(k) & 0x80u) == 0)
      v1 = 2;
    enemy_moving_dir[k] = v1;
    obj_xspeed.enemy[k] = kBulletBillXSpdData[(uint8)(v1 - 1)];
    if ((uint8)(R0_ + 40) < 0x50u)
      goto LABEL_14;
    enemy_state[k] = 1;
    enemy_frame_timer[k] = 10;
    sound_ch3 = 74;
    BulletBillSfxHandler(k, 0x4Au);
  }
  if ((offscreen_bits.enemy & 0xF0) != 0xF0) {
    if ((enemy_state[k] & 0x20) != 0)
      MoveD_EnemyVert(k);
    if (!var0E67) {
      MoveEnemyHoriz(k);
      BulletBill_MoveNew(k);
    }
    goto LABEL_13;
  }
LABEL_14:
  EraseEnemyObject(k);
}

uint8 SpawnThrownHammer(uint8 k) {
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

void ProcHammerObj(uint8 k) {
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
      ImposeGravity(v3, 0);
      MoveObjectHoriz(v3);
      k = object_index;
      PlayerHammerCollision(object_index);
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
  GetMiscOffscreenBits(k);
  RelativeMiscPosition(k);
  GetMiscBoundBox(k);
  DrawHammer(k);
}

void SetupJumpCoin(uint8 k) {
  uint8 EmptyMiscSlot;  // di

  EmptyMiscSlot = FindEmptyMiscSlot();
  obj_xpos_hi.misc[EmptyMiscSlot] = block_xpos_hi2[k];
  obj_xpos_lo.misc[EmptyMiscSlot] = (16 * R6_) | 5;
  obj_ypos_lo.misc[EmptyMiscSlot] = R2_ + 32;
  SetupCoinCommon(k, EmptyMiscSlot);
}

void SetupCoinCommon(uint8 k, uint8 j) {
  obj_yspeed.misc[j] = -5;
  obj_ypos_hi.misc[j] = 1;
  misc_state[j] = 1;
  sound_ch3 = 1;
  object_index = k;
  GiveOneCoin();
  ++coin_tally_for_1ups;
}

uint8 FindEmptyMiscSlot() {
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

void MiscObjectsCore() {
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
      ProcHammerObj(i);
      continue;
    }
    if (misc_state[i] == 1) {
      R0_ = 80;
      R2_ = 6;
      R1_ = 3;
      ImposeGravity(i + 17, 0);
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
      SpinningCoinSprite_Init(i);
    RelativeMiscPosition(i);
    GetMiscOffscreenBits(i);
    GetMiscBoundBox(i);
    DrawSpinningCoinSprite(i);
  }
}

void GiveOneCoin() {
  digit_modifier[5] = 1;
  DigitsMathRoutine(kCoinTallyOffsets[current_player]);
  if (++player_coin_count == 100) {
    player_coin_count = 0;
    GiveExtraLife();
    sound_ch3 = 5;
  }
  digit_modifier[4] = 2;
  AddToScore();
}

void AddToScore() {
  DigitsMathRoutine(kScoreOffsets[current_player]);
  GetSBNibbles();
}

void GetSBNibbles() {
  UpdateNumber(kStatusBarNybbles[current_player_mirror]);
}

void UpdateNumber(uint8 a) {
  int8 v1;  // al

  PrintStatusBarNumbers(a);
  if (!vram_buffer1[vram_buffer1_offset - 11]) {
    v1 = 40;
    if (vram_buffer1[vram_buffer1_offset - 15] == 2)
      v1 = 36;
    vram_buffer1[vram_buffer1_offset - 11] = v1;
  }
}
// 7E16F6: using guessed type uint8[10];

void Spr02E_Powerup_Init(uint8 k) {
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

void PowerUpObjHandler(uint8 k) {
  uint8 v1;  // al

  object_index = 9;
  if (enemy_state[9]) {
    if (__CFSHL__(enemy_state[9], 1)) {
      if (!timer_control) {
        if (!power_up_type || power_up_type == 3) {
          MoveNormalEnemy(9u);
          EnemyToBGCollisionDet(9u);
        } else if (power_up_type == 2) {
          MoveJumpingEnemy(9u);
          EnemyJump(9u);
        }
      }
LABEL_13:
      RelativeEnemyPosition(9u);
      GetEnemyOffscreenBits(9u);
      GetEnemyBoundBox(9u);
      DrawPowerUp();
      PlayerEnemyCollision(9u);
      OffscreenBoundsCheck(9u);
      return;
    }
    if ((frame_counter & 3) == 0) {
      --obj_ypos_lo.enemy[9];
      v1 = enemy_state[9]++;
      if (v1 >= 0x11u) {
        obj_xspeed.enemy[9] = 16;
        enemy_state[9] = 0x80;
        enemy_sprattrib[9] = 0;
        enemy_moving_dir[9] = __CFSHL__(0x80, 1);
      }
    }
    if (enemy_state[9] >= 6u)
      goto LABEL_13;
  }
}
// 7E0241: using guessed type int8;

void PlayerHeadCollision(uint8 a) {
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
  DestroyBlockMetatile();
  v2 = spr_data_offset_ctrl;
  v3 = R2_;
  v4 = spr_data_offset_ctrl;
  block_orig_ypos[spr_data_offset_ctrl] = R2_;
  block_bbuf_low[v4] = R6_;
  v5 = RomPtr_RAM(*(uint16 *)&R6_)[v3];
  t = BlockBumpedChk(v5);
  R0_ = v5;
  if (!player_size)
    v5 = player_size;
  if (t != 0xff) {
    block_state[v2] = 17;
    v5 = -4;
    v6 = R0_;
    if (R0_ == 91 || R0_ == 96) {
      if (!brick_coin_timer_flag) {
        brick_coin_timer = 11;
        ++brick_coin_timer_flag;
      }
      if (!brick_coin_timer)
        v6 = -4;
      v5 = v6;
    }
  }
  block_metatile[v2] = v5;
  InitBlock_XY_Pos(v2);
  RomPtr_RAM(*(uint16 *)&R6_)[R2_] = 39;
  block_bounce_timer = 16;
  R5_ = a;
  v7 = 0;
  if (crouching_flag || player_size)
    v7 = 1;
  obj_ypos_lo.block[v2] = (kBlockYPosAdderData[v7] + obj_ypos_lo.player) & 0xF0;
  if (block_state[v2] == 17)
    BumpBlock();
  else
    BrickShatter();
  spr_data_offset_ctrl ^= 1u;
}

void InitBlock_XY_Pos(uint8 k) {
  uint t = PAIR16(obj_xpos_hi.player, obj_xpos_lo.player) + 8;
  obj_xpos_lo.block[k] = t & ~0xf;
  LOBYTE(xpos_new_var0E16) = t & ~0xf;
  obj_xpos_hi.block[k] = t >> 8;
  block_xpos_hi2[k] = t >> 8;
  HIBYTE(xpos_new_var0E16) = t >> 8;
  obj_ypos_hi.block[k] = obj_ypos_hi.player;
}

void BumpBlock() {
  uint8 v0;             // si
  uint8 v1;             // di
  uint8 v2;             // al
  uint8 v3;             // al
  uint8 EmptyMiscSlot;  // di

  v0 = CheckTopOfBlock();
  sound_ch1 = 1;
  obj_xspeed.block[v0] = 0;
  obj_sub_yspeed.block[v0] = 0;
  obj_yspeed.player = 0;
  obj_yspeed.block[v0] = -2;
  v1 = BlockBumpedChk(R5_);
  if (v1 != 0xff) {
    v2 = v1;
    if (v1 >= 9u)
      v2 = v1 - ((v1 < 9u) + 5);
    R4_ = *((uint8 *)kDATA_03BF64 + (uint8)(2 * v2));
    R5_ = *((uint8 *)kDATA_03BF64 + (uint8)(2 * v2) + 1);
    switch ((uint8)(2 * v2) >> 1) {
    case 0:
    case 4: v3 = 0; goto LABEL_8;
    case 1:
    case 2:
    case 7:
      EmptyMiscSlot = FindEmptyMiscSlot();
      obj_xpos_hi.misc[EmptyMiscSlot] = obj_xpos_hi.block[v0];
      obj_xpos_lo.misc[EmptyMiscSlot] = obj_xpos_lo.block[v0] | 5;
      obj_ypos_lo.misc[EmptyMiscSlot] = obj_ypos_lo.block[v0] - 16;
      SetupCoinCommon(v0, EmptyMiscSlot);
      return;
    case 3:
    case 8: v3 = 3; goto LABEL_8;
    case 5: Spr02F_Vine_Init(9u, spr_data_offset_ctrl); return;
    case 6:
      v3 = 2;
LABEL_8:
      power_up_type = v3;
      enemy_id[9] = 46;
      obj_xpos_hi.enemy[9] = obj_xpos_hi.block[v0];
      obj_xpos_lo.enemy[9] = obj_xpos_lo.block[v0];
      obj_ypos_hi.enemy[9] = 1;
      obj_ypos_lo.enemy[9] = obj_ypos_lo.block[v0] - 8;
      Spr02E_Powerup_Init(v0);
      break;
    }
  }
}
// 7E0082: using guessed type int8;
// 7E00C5: using guessed type int8;
// 7E0223: using guessed type int8;

uint8 BlockBumpedChk(uint8 a) {
  uint8 result;  // di

  for (result = 13; (result & 0x80u) == 0; --result) {
    if (a == kBrickQBlockMetatiles[result])
      break;
  }
  return result;
}

void BrickShatter() {
  uint8 v0;  // si

  v0 = CheckTopOfBlock();
  block_repflag[v0] = 1;
  if (!sound_ch3)
    sound_ch3 = 7;
  SpawnBrickChunks(v0);
  obj_yspeed.player = -2;
  digit_modifier[5] = 5;
  AddToScore();
}

uint8 CheckTopOfBlock() {
  uint8 result;  // si
  uint8 v1;      // di
  uint8 v2;      // di

  result = spr_data_offset_ctrl;
  v1 = R2_;
  if (R2_) {
    R2_ -= 16;
    v2 = v1 - 16;
    if (RomPtr_RAM(*(uint16 *)&R6_)[v2] == 0xE9) {
      RomPtr_RAM(*(uint16 *)&R6_)[v2] = 0;
      sound_ch3 = 1;
      RemoveCoin_Axe();
      result = spr_data_offset_ctrl;
      SetupJumpCoin(spr_data_offset_ctrl);
    }
  }
  return result;
}

void SpawnBrickChunks(uint8 k) {
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

void BlockObjectsCore(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // si
  uint8 v3;  // si
  uint8 v4;  // si

  v1 = block_state[k];
  if (v1) {
    v2 = k + 13;
    if ((v1 & 0xF) == 1) {
      ImposeGravityBlock(v2);
      v4 = object_index;
      RelativeBlockPosition(object_index);
      GetBlockOffscreenBits(v4);
      DrawBlock(v4);
      block_state[v4] = 1;
      if ((obj_ypos_lo.block[v4] & 0xFu) >= 5)
        return;
      block_repflag[v4] = 1;
      goto LABEL_10;
    }
    ImposeGravityBlock(v2);
    MoveObjectHoriz(v2);
    v3 = v2 + 2;
    ImposeGravityBlock(v3);
    MoveObjectHoriz(v3);
    v4 = object_index;
    RelativeBlockPosition(object_index);
    GetBlockOffscreenBits(v4);
    DrawBrickChunks(v4);
    if (obj_ypos_hi.block[v4]) {
      if (obj_ypos_lo.misc[v4 - 2] > 0xF0u)
        obj_ypos_lo.misc[v4 - 2] = -16;
      if (obj_ypos_lo.block[v4] >= 0xF0u)
LABEL_10:
        block_state[v4] = 0;
    }
  }
}

void BlockObjMT_Updater() {
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
      ReplaceBlockMetatile(i, v1);
      block_repflag[i] = 0;
    }
  }
}

uint8 MoveEnemyHoriz(uint8 k) {
  return MoveObjectHoriz(k + 1);
}

uint8 MovePlayerHoriz() {
  uint8 result;  // al

  result = jumpspring_anim_ctrl;
  if (!jumpspring_anim_ctrl)
    return MoveObjectHoriz(jumpspring_anim_ctrl);
  return result;
}

uint8 MoveObjectHoriz(uint8 k) {
  uint8 v1;  // al

  v1 = (int8) * (&obj_xspeed.player + k) >> 4;
  uint16 t = *(&obj_xpos_fract.player + k) + (uint8)(16 * *(&obj_xspeed.player + k));
  *(&obj_xpos_fract.player + k) = t;
  t = (t >> 8) + (int8)v1;
  AddHiLo(&obj_xpos_hi.player + k, &obj_xpos_lo.player + k, t);
  UNUSED_byte_7E0EB6 = v1;
  return t;
}

void MovePlayerVert() {
  if (timer_control || !jumpspring_anim_ctrl) {
    R0_ = vertical_force;
    ImposeGravitySpr(0, 4u);
  }
}

void MoveD_EnemyVert(uint8 k) {
  if (enemy_state[k] == 5)
    MoveFallingPlatform(k);
  else
    func_sub_C17F(k, 0x3Du);
}

void MoveFallingPlatform(uint8 k) {
  func_sub_C17F(k, 0x20u);
}

void MoveRedPTroopaDown(uint8 k) {
  MoveRedPTroopa(k, 0);
}

void MoveRedPTroopaUp(uint8 k) {
  MoveRedPTroopa(k, 1u);
}

void MoveRedPTroopa(uint8 k, uint8 j) {
  R0_ = 3;
  R1_ = 6;
  R2_ = 2;
  RedPTroopaGrav(k + 1, j);
}

void MoveDropPlatform(uint8 k) {
  func_sub_C179(k, 0x7Fu);
}

void MoveEnemySlowVert(uint8 k) {
  func_sub_C179(k, 0xFu);
}

void func_sub_C179(uint8 k, uint8 j) {
  SetXMoveAmt(k, j, 2u);
}

void MoveJ_EnemyVert(uint8 k) {
  func_sub_C17F(k, 0x1Cu);
}

void func_sub_C17F(uint8 k, uint8 j) {
  SetXMoveAmt(k, j, 3u);
}

void SetXMoveAmt(uint8 k, uint8 j, uint8 a) {
  R0_ = j;
  ImposeGravitySpr(k + 1, a);
}

void func_sub_C18C(uint8 k) {
  ImposeGravityBlock(k);
}

void ImposeGravityBlock(uint8 k) {
  R0_ = 80;
  ImposeGravitySpr(k, kMaxSpdBlockData[1]);
}

void ImposeGravitySpr(uint8 k, uint8 a) {
  R2_ = a;
  ImposeGravity(k, 0);
}

void MovePlatformDown(uint8 k) {
  MovePlatformCommon(k, 0);
}

void MovePlatformUp(uint8 k) {
  MovePlatformCommon(k, 1u);
}

void MovePlatformCommon(uint8 k, uint8 a) {
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
  RedPTroopaGrav(v3, a);
}

void RedPTroopaGrav(uint8 k, uint8 a) {
  ImposeGravity(k, a);
}

void ImposeGravity_Far(uint8 k, uint8 a) {
  ImposeGravity(k, a);
}

void ImposeGravity(uint8 k, uint8 a) {
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

void BulletBill_MoveNew(uint8 k) {
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

void BulletBillSfxHandler(uint8 k, uint8 a) {
  bullet_bill_arr0E9D[k] = a;
  bullet_bill_arr0EA2[k] = 0;
  bullet_bill_arr0EAC[k] = obj_xpos_lo.enemy[k];
  bullet_bill_arr0EA7[k] = obj_xpos_hi.enemy[k];
  bullet_bill_arr0EB1[k] = obj_ypos_lo.enemy[k] + 8;
}

void HandleScreenTransition() {
  if (fade_direction & 1) {
    if ((inidisp_mirror & 0x80u) == 0) {
      if (!cutscene_var1680 || inidisp_mirror) {
        if (--inidisp_mirror)
          goto LABEL_14;
      }
      WriteReg(INIDISP, 0x80u);
      inidisp_mirror = 0x80;
      WriteReg(HDMAEN, 0);
      hdmaenable_mirror = 0;
      pause_menu_idx = 0;
      cutscene_var1680 = 0;
      Dma_FillWith0x24();
      ClearAllOams();
      CODE_03C36E();
    }
    fade_direction = 0;
    disable_screen_flag = 1;
  } else {
    if (!override_player_xpos2_flag && !override_player_xpos_flag) {
      override_player_xpos_flag = 1;
      GameMode01_Level_GameCoreRoutine();
    }
    var0E67 = 0;
    if (inidisp_mirror == 15 || (++inidisp_mirror, inidisp_mirror == 15)) {
      fade_direction = 0;
      disable_screen_flag = 0;
      override_player_xpos_flag = 0;
    }
  }
LABEL_14:
  if (enable_mosaic_fades_flag) {
    ClearAllOams();
    mosaic_mirror = (16 * (inidisp_mirror ^ 0xF)) | 0xF;
    CODE_03C35C();
    if (inidisp_mirror == 15)
      enable_mosaic_fades_flag = 0;
  }
}

void ClearAllOams() {
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

void CODE_03C35C() {
  uint8 i;  // di

  for (i = -48; i != 0xF0; i += 4)
    get_OamEnt(oam_buf, i)->ypos = -16;
}

void CODE_03C36E() {
  UploadSpriteGFX();
  cutscene_var0BA5 = 0;
  game_over_screen_blinking_cursor_pos = 0;
  vblank_which_layer2_scroll_flag = 0;
  turn_around_smoke_flag = 0;
  turn_around_smoke_flag2 = 0;
  turn_around_smoke_bits[0] = 0;
  enable_layer3_bgflag = 0;
  if (override_player_xpos2_flag) {
    override_player_xpos2_flag = 0;
  } else {
    rel_ypos.player = obj_ypos_lo.player;
    rel_xpos_lo.player = obj_xpos_lo.player;
  }
  override_player_xpos_flag = 0;
}

void EnemiesAndLoopsCore(uint8 k) {
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
  uint8 v13;  // di
  uint8 v14;  // [rsp+47h] [rbp-1h]

  v14 = enemy_flag[k];
  if (__CFSHL__(v14, 1)) {
    if (!enemy_flag[v14 & 0xF])
      enemy_flag[k] = 0;
    return;
  }
  if (v14) {
    RunEnemyObjectsCore();
    return;
  }
  if ((area_parser_task_num & 7) != 7) {
    while (!loop_command || current_column_pos_lo) {
LABEL_31:
      if (enemy_frenzy_queue) {
        enemy_id[k] = enemy_frenzy_queue;
        enemy_flag[k] = 1;
        enemy_state[k] = 0;
        enemy_frenzy_queue = 0;
        InitEnemyObject(k);
        return;
      }
      v2 = enemy_data_offset2;
      v3 = IndirPtr(&enemy_data_ptr, enemy_data_offset2);
      if (*v3 == 0xFF)
        goto LABEL_59;
      if ((*v3 & 0xF) != 14 && k >= 8u && (*IndirPtr(&enemy_data_ptr, (uint8)(v2 + 1)) & 0x3F) != 46)
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
      if ((*IndirPtr(&enemy_data_ptr, v5) & 0xF) != 15 || enemy_object_page_sel) {
        obj_xpos_hi.enemy[k] = enemy_object_page_loc;
        v6 = *IndirPtr(&enemy_data_ptr, v5) & 0xF0;
        obj_xpos_lo.enemy[k] = v6;
        if (obj_xpos_hi.enemy[k] >= ((v6 < screen_right_xpos) + screen_right_xpos_hi)) {
          if (R6_ < ((R7_ < obj_xpos_lo.enemy[k]) + obj_xpos_hi.enemy[k])) {
LABEL_59:
            v11 = enemy_frenzy_buffer;
            if (!enemy_frenzy_buffer) {
              if (vine_flag_offset != 1)
                return;
              v11 = 0;
            }
            if (k == 9) {
              InitEnemyObject(9u);
            } else {
              enemy_id[k] = v11;
              InitEnemyObject(k);
            }
          } else {
            obj_ypos_hi.enemy[k] = 1;
            v7 = 16 * *IndirPtr(&enemy_data_ptr, v5);
            obj_ypos_lo.enemy[k] = v7;
            if (v7 == 0xE0)
              goto LABEL_66;
            v8 = v5 + 1;
            if ((*IndirPtr(&enemy_data_ptr, v8) & 0x40) != 0 && !secondary_hard_mode)
              goto LABEL_71;
            v9 = IndirPtr(&enemy_data_ptr, v8);
            v10 = *v9 & 0x3F;
            if (v10 < 0x37u || (*v9 & 0x3F) == 63) {
              if (v10 == 6 && primary_hard_mode)
                v10 = 2;
              enemy_id[k] = v10;
              if (v10 == 45)
                bowser_var0F4C = 0;
              enemy_flag[k] = 1;
              InitEnemyObject(k);
              if (enemy_flag[k])
                goto LABEL_71;
            } else {
              HandleGroupEnemies(v10);
            }
          }
        } else {
          if ((*IndirPtr(&enemy_data_ptr, v5) & 0xF) != 14) {
            if ((*IndirPtr(&enemy_data_ptr, enemy_data_offset2) & 0xF) == 14)
              goto LABEL_70;
            goto LABEL_71;
          }
LABEL_66:
          v12 = v5 + 2;
          if (*IndirPtr(&enemy_data_ptr, v12) >> 5 == world_number) {
            v13 = v12 - 1;
            area_pointer = *IndirPtr(&enemy_data_ptr, v13);
            entrance_page = *IndirPtr(&enemy_data_ptr, (uint8)(v13 + 1)) & 0x1F;
          }
LABEL_70:
          ++enemy_data_offset2;
LABEL_71:
          ++enemy_data_offset2;
          ++enemy_data_offset2;
          enemy_object_page_sel = 0;
        }
        return;
      }
      enemy_object_page_loc = *IndirPtr(&enemy_data_ptr, (uint8)(v5 + 1)) & 0x3F;
      ++enemy_data_offset2;
      ++enemy_data_offset2;
      ++enemy_object_page_sel;
    }
    v1 = 11;
    do {
      if ((--v1 & 0x80u) != 0)
        goto LABEL_31;
    } while (world_number != kLoopCmdWorldNumber[v1] || column_pos_hi != kLoopCmdPageNumber[v1]);
    if (obj_ypos_lo.player != kLoopCmdYPosition[v1] || player_state) {
      if (world_number != 6) {
        if (!var0EDB) {
          sound_ch3 = 42;
          var0EDB = 42;
        }
        goto LABEL_28;
      }
      if (!var0EDB) {
        sound_ch3 = 42;
        var0EDB = 42;
      }
    } else if (!var0EDB) {
      sound_ch3 = 41;
      if (world_number != 6)
        goto LABEL_29;
      ++multi_loop_correct_cntr;
    }
    if (++multi_loop_pass_cntr != 3) {
LABEL_30:
      loop_command = 0;
      goto LABEL_31;
    }
    if (multi_loop_correct_cntr == 3) {
LABEL_29:
      multi_loop_pass_cntr = 0;
      multi_loop_correct_cntr = 0;
      goto LABEL_30;
    }
LABEL_28:
    ExecGameLoopback(v1);
    KillAllEnemies();
    goto LABEL_29;
  }
}

void ExecGameLoopback(uint8 j) {
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

void InitEnemyObject(uint8 k) {
  enemy_state[k] = 0;
  CheckpointEnemyID(k);
}

void CheckpointEnemyID(uint8 k) {
  uint8 v1;  // al

  v1 = enemy_id[k];
  if (v1 < 0x15u) {
    obj_ypos_lo.enemy[k] += 8;
    spr_array_D[k] = 1;
  }
  R4_ = *((uint8 *)kDATA_03C62F + (uint8)(2 * v1));
  R5_ = *((uint8 *)kDATA_03C62F + (uint8)(2 * v1) + 1);
  ((void (*)(uint8, uint8))funcs_A6DE[(uint8)(2 * v1) >> 1])(k, 2 * v1);
}
// A6E6: using guessed type int (*funcs_A6DE[55])();

void NoEnemyInit(uint8 k) {
  ;
}

void Goomba_Init(uint8 k) {
  NormalEnemy_Init(k);
  SmallBBox(k);
}

void Podoboo_Init(uint8 k) {
  obj_ypos_lo.enemy[k] = -48;
  obj_ypos_hi.enemy[k] = 1;
  *(&enemy_interval_timer + k) = 1;
  enemy_state[k] = 0;
  podoboo_array_1[k] = 1;
  podoboo_array_2[k] = 0;
  sound_ch3 = 39;
  SmallBBox(k);
}

void RetainerObj_Init(uint8 k) {
  uint8 v1;  // al

  if (world_number == 7)
    v1 = 112;
  else
    v1 = -72;
  obj_ypos_lo.enemy[k] = v1;
}

void NormalEnemy_Init(uint8 k) {
  obj_xspeed.enemy[k] = kNormalXSpdData[primary_hard_mode != 0];
  SetBBox_3(k);
}

void RedKoopa_Init(uint8 k) {
  NormalEnemy_Init(k);
  enemy_state[k] = 1;
}

void HammerBro_Init(uint8 k) {
  enemy_data_d[k] = 0;
  obj_xspeed.enemy[k] = 0;
  *(&enemy_interval_timer + k) = kHBroWalkingTimerData[secondary_hard_mode];
  enemy_hitbox_ctrl[k] = 11;
  enemy_moving_dir[k] = 2;
  InitVStf(k);
}

void InitHorizFlySwimEnemy(uint8 k) {
  obj_xspeed.enemy[k] = 0;
  SetBBox_3(k);
}

void Blooper_Init(uint8 k) {
  obj_xspeed.enemy[k] = 0;
  SmallBBox(k);
}

void SmallBBox(uint8 k) {
  enemy_hitbox_ctrl[k] = 9;
  enemy_moving_dir[k] = 2;
  InitVStf(k);
}

void RedPTroopa_Init(uint8 k) {
  int8 v1;  // di
  int8 v2;  // al

  v1 = 48;
  v2 = obj_ypos_lo.enemy[k];
  obj_xpos_fract.enemy[k] = v2;
  if (v2 < 0)
    v1 = -32;
  obj_xspeed.enemy[k] = obj_ypos_lo.enemy[k] + v1;
  SetBBox_3(k);
}

void SetBBox_3(uint8 k) {
  enemy_hitbox_ctrl[k] = 3;
  enemy_moving_dir[k] = 2;
  InitVStf(k);
}

void InitVStf(uint8 k) {
  obj_yspeed.enemy[k] = 0;
  obj_sub_yspeed.enemy[k] = 0;
}

void BulletBill_Init(uint8 k) {
  enemy_moving_dir[k] = 2;
  enemy_hitbox_ctrl[k] = 9;
}

void CheepCheep_Init(uint8 k) {
  SmallBBox(k);
  obj_xspeed.enemy[k] = *(&random_byte1 + k) & 0x10;
  obj_sub_yspeed.enemy[k] = obj_ypos_lo.enemy[k];
}

void Lakitu_Init(uint8 k) {
  if (enemy_frenzy_buffer)
    EraseEnemyObject(k);
  else
    SetupLakitu(k);
}

void SetupLakitu(uint8 k) {
  lakitu_reappear_timer = 0;
  InitHorizFlySwimEnemy(k);
  TallBBox2(k);
}

void LakituAndSpinyHandler(uint8 k) {
  uint8 i;   // di
  uint8 v2;  // si

  if (!frenzy_enemy_timer && k < 9u) {
    frenzy_enemy_timer = 0x80;
    for (i = 8; (i & 0x80u) == 0; --i) {
      if (enemy_id[i] == 17) {
        CreateSpiny(k, i);
        return;
      }
    }
    if (++lakitu_reappear_timer >= 7u) {
      v2 = 8;
      while (enemy_flag[v2]) {
        if ((--v2 & 0x80u) != 0)
          return;
      }
      enemy_state[v2] = 0;
      enemy_id[v2] = 17;
      SetupLakitu(v2);
      PutAtRightExtent(v2, 0x20u);
    }
  }
}
// AC5C: conditional instruction was optimized away because si.1<0

void CreateSpiny(uint8 k, uint8 j) {
  uint8 v2;  // di
  int8 i;    // si
  uint8 v4;  // si
  uint8 v5;  // di

  if (obj_ypos_lo.player >= 0x2Cu && !enemy_state[j]) {
    obj_xpos_hi.enemy[k] = obj_xpos_hi.enemy[j];
    obj_xpos_lo.enemy[k] = obj_xpos_lo.enemy[j];
    obj_ypos_hi.enemy[k] = 1;
    obj_ypos_lo.enemy[k] = obj_ypos_lo.enemy[j] - 8;
    v2 = *(&random_byte1 + k) & 3;
    for (i = 2; i >= 0; --i) {
      *(&R1_ + (uint8)i) = kPRDiffAdjustData[v2];
      v2 += 4;
    }
    v4 = object_index;
    PlayerLakituDiff(object_index);
    SmallBBox(v4);
    v5 = 2;
    obj_xspeed.enemy[v4] = 0;
    if (!sign8(0))
      v5 = 1;
    enemy_moving_dir[v4] = v5;
    obj_yspeed.enemy[v4] = -3;
    enemy_flag[v4] = 1;
    enemy_state[v4] = 5;
  }
}

void LongFirebar_Init(uint8 k) {
  DuplicateEnemyObj(k);
  ShortFirebar_Init(k);
}

void ShortFirebar_Init(uint8 k) {
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
  TallBBox2(k);
}

void FlyingCheepCheep_Init(uint8 k) {
  uint8 v1;  // di
  int8 v2;   // al
  uint8 v3;  // di
  bool v4;   // cf
  uint8 v5;  // al

  if (!frenzy_enemy_timer) {
    SmallBBox(k);
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

void Bowser_Init(uint8 k) {
  DuplicateEnemyObj(k);
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

void DuplicateEnemyObj(uint8 k) {
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

void BowserFlame_Init(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // al
  bool v3;   // cf

  if (!frenzy_enemy_timer) {
    obj_sub_yspeed.enemy[k] = frenzy_enemy_timer;
    bowser_var014B = 6;
    bowser_var0F4C = 24;
    var0F4D_new = k;
    if (enemy_id[browser_front_offset] != 45) {
      v1 = SetFlameTimer() + 32;
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

void PutAtRightExtent(uint8 k, uint8 a) {
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

void InitFireworks(uint8 k) {
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

void BulletBillCheepCheep(uint8 k) {
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
    PutAtRightExtent(k, kEnemy17YPosData[v4]);
    obj_sub_ypos.enemy[k] = 0;
    frenzy_enemy_timer = 32;
    CheckpointEnemyID(k);
  }
}

void HandleGroupEnemies(uint8 a) {
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
      CheckpointEnemyID(v5);
      if (--number_of_group_enemies)
        goto LABEL_9;
      break;
    }
  }
  ++enemy_data_offset2;
  ++enemy_data_offset2;
  enemy_object_page_sel = 0;
}

void PiranhaPlant_Init(uint8 k) {
  uint8 v1;  // al

  obj_xspeed.enemy[k] = 1;
  enemy_state[k] = 0;
  obj_yspeed.enemy[k] = 0;
  v1 = obj_ypos_lo.enemy[k];
  obj_sub_yspeed.enemy[k] = v1;
  obj_sub_ypos.enemy[k] = v1 - 24;
  enemy_hitbox_ctrl[k] = 12;
}

void InitEnemyFrenzy(uint8 k) {
  uint8 v1;  // di

  enemy_frenzy_buffer = enemy_id[k];
  v1 = enemy_frenzy_buffer - 18;
  R4_ = kDATA_03CBCC[v1];
  R5_ = HIBYTE(kDATA_03CBCC[v1]);
  ((void (*)(uint8))funcs_B851[(unsigned int)(v1 * 2) >> 1])(k);
}
// B859: using guessed type int (*funcs_B851[6])();

void NoFrenzyCode(uint8 k) {
  ;
}

void EndFrenzy(uint8 k) {
  uint8 i;  // di

  for (i = 9; (i & 0x80u) == 0; --i) {
    if (enemy_id[i] == 17)
      enemy_state[i] = 1;
  }
  enemy_frenzy_buffer = 0;
  enemy_flag[k] = 0;
}

void JumpGPTroopa_Init(uint8 k) {
  enemy_moving_dir[k] = 2;
  obj_xspeed.enemy[k] = -8;
  TallBBox2(k);
}

void TallBBox2(uint8 k) {
  enemy_hitbox_ctrl[k] = 3;
}

void BalPlatform_Init(uint8 k) {
  uint8 v1;  // di
  int8 v2;   // al

  --obj_ypos_lo.enemy[k];
  --obj_ypos_lo.enemy[k];
  if (!secondary_hard_mode)
    PosPlatform(k, 2u);
  v1 = -1;
  v2 = bal_platform_alignment;
  enemy_state[k] = bal_platform_alignment;
  if (v2 < 0)
    v1 = k;
  bal_platform_alignment = v1;
  enemy_moving_dir[k] = 0;
  PosPlatform(k, 0);
  InitDropPlatform_Init(k);
}

void InitDropPlatform_Init(uint8 k) {
  enemy_data_d[k] = -1;
  InitVStf(k);
  SPBBox(k);
}

void InitHoriPlatform_Init(uint8 k) {
  obj_xspeed.enemy[k] = 0;
  InitVStf(k);
  SPBBox(k);
}

void VertPlatform_Init(uint8 k) {
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
  InitVStf(k);
  SPBBox(k);
}

void SPBBox(uint8 k) {
  uint8 v1;  // al

  v1 = 5;
  if (area_type != 3 && !secondary_hard_mode)
    v1 = 6;
  enemy_hitbox_ctrl[k] = v1;
}

void LargeLiftUp_Init(uint8 k) {
  PlatLiftUp_Init(k);
  SPBBox(k);
}

void LargeLiftDown_Init(uint8 k) {
  PlatLiftDown_Init(k);
  SPBBox(k);
}

void PlatLiftUp_Init(uint8 k) {
  obj_sub_yspeed.enemy[k] = 16;
  obj_yspeed.enemy[k] = -1;
  PosPlatform(k, 1u);
  enemy_hitbox_ctrl[k] = 4;
}

void PlatLiftDown_Init(uint8 k) {
  obj_sub_yspeed.enemy[k] = -16;
  obj_yspeed.enemy[k] = 0;
  PosPlatform(k, 1u);
  enemy_hitbox_ctrl[k] = 4;
}

void PosPlatform(uint8 k, uint8 j) {
  uint8 v2;  // al
  bool v3;   // cf

  v2 = obj_xpos_lo.enemy[k];
  v3 = __CFADD__(kPlatPosDataLow[j], v2);
  obj_xpos_lo.enemy[k] = kPlatPosDataLow[j] + v2;
  obj_xpos_hi.enemy[k] += kPlatPosDataHigh[j] + v3;
}

void EndOfEnemyInitCode(uint8 k) {
  ;
}

void RunEnemyObjectsCore() {
  int8 v0;   // al
  uint8 v1;  // di

  v0 = 0;
  v1 = enemy_id[object_index];
  if (v1 >= 0x15u)
    v0 = v1 - 20;
  ((void (*)(uint8))funcs_BC01[v0])(object_index);
}
// BC09: using guessed type int (*funcs_BC01[34])();

void NoRunCode(uint8 k) {
  ;
}

void RunRetainerObj(uint8 k) {
  GetEnemyOffscreenBits(k);
  RelativeEnemyPosition(k);
  EnemyGfxHandler_New(k);
}

void RunNormalEnemies(uint8 k) {
  enemy_sprattrib[k] = 32;
  GetEnemyOffscreenBits(k);
  RelativeEnemyPosition(k);
  EnemyGfxHandler_New(k);
  GetEnemyBoundBox(k);
  EnemyToBGCollisionDet(k);
  EnemiesCollision(k);
  PlayerEnemyCollision(k);
  if (!timer_control)
    EnemyMovementSubs(k);
  OffscreenBoundsCheck(k);
}

void EnemyMovementSubs(uint8 k) {
  uint8 v1;  // di

  v1 = enemy_id[k];
  R4_ = kDATA_03CD48[v1];
  R5_ = HIBYTE(kDATA_03CD48[v1]);
  ((void (*)(uint8))funcs_BDE8[(unsigned int)(v1 * 2) >> 1])(k);
}
// BDF0: using guessed type int (*funcs_BDE8[21])();

void NoMoveCode(uint8 k) {
  ;
}

void RunBowserFlame(uint8 k) {
  ProcBowserFlame(k);
  GetEnemyOffscreenBits(k);
  RelativeEnemyPosition(k);
  GetEnemyBoundBox(k);
  PlayerEnemyCollision(k);
  OffscreenBoundsCheck(k);
}

void RunFirebarObj(uint8 k) {
  ProcFirebar(k);
  OffscreenBoundsCheck(k);
}

void RunSmallPlatform(uint8 k) {
  GetEnemyOffscreenBits(k);
  RelativeEnemyPosition(k);
  SmallPlatformBoundBox(k);
  SmallPlatformCollision(k);
  RelativeEnemyPosition(k);
  DrawSmallPlatform(k);
  MoveSmallPlatform(k);
  OffscreenBoundsCheck(k);
}

void RunLargePlatform(uint8 k) {
  GetEnemyOffscreenBits(k);
  RelativeEnemyPosition(k);
  LargePlatformBoundBox(k);
  LargePlatformCollision(k);
  if (!timer_control)
    LargePlatformSubroutines(k);
  RelativeEnemyPosition(k);
  DrawLargePlatform(k);
  OffscreenBoundsCheck(k);
}

void LargePlatformSubroutines(uint8 k) {
  uint8 v1;  // di

  v1 = enemy_id[k] - 36;
  R4_ = kDATA_03CDD4[v1];
  R5_ = HIBYTE(kDATA_03CDD4[v1]);
  ((void (*)(uint8))funcs_BFB5[(unsigned int)(v1 * 2) >> 1])(k);
}
// BFBD: using guessed type int (*funcs_BFB5[7])();

void EraseEnemyObject(uint8 k) {
  *(&enemy_interval_timer + k) = 0;
  EraseEnemyObject2(k);
}

void EraseEnemyObject2(uint8 k) {
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

void MovePodoboo(uint8 k) {
  uint8 v1;  // al

  if (!*(&enemy_interval_timer + k)) {
    Podoboo_Init(k);
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
  MovePodoboo_Sub1(k);
  MoveJ_EnemyVert(k);
}

void ProcHammerBro(uint8 k) {
  uint8 v1;  // di
  int8 v2;   // al

  if ((enemy_state[k] & 0x20) != 0) {
    MoveD_EnemyVert(k);
    MoveEnemyHoriz(k);
  } else if (enemy_data_c[k]) {
    --enemy_data_c[k];
    if ((offscreen_bits.enemy & 0xC) != 0) {
LABEL_4:
      CODE_03CEE9(k);
      return;
    }
    if (enemy_data_d[k] || (enemy_data_d[k] = kHammerThrowTmrData[secondary_hard_mode], !(SpawnThrownHammer(k) & 1))) {
      --enemy_data_d[k];
      CODE_03CEE9(k);
    } else {
      enemy_state[k] |= 8u;
      CODE_03CEE9(k);
    }
  } else {
    if ((enemy_state[k] & 7) == 1)
      goto LABEL_4;
    R0_ = 0;
    v1 = -6;
    v2 = obj_ypos_lo.enemy[k];
    if (v2 < 0 || (v1 = -3, ++R0_, (uint8)v2 < 0x70u) || (--R0_, (*(&random_byte2 + k) & 1) != 0))
      CODE_03CEC7(k, v1);
    else
      CODE_03CEC7(k, 0xFAu);
  }
}

void CODE_03CEC7(uint8 k, uint8 j) {
  uint8 v2;  // di

  obj_yspeed.enemy[k] = j;
  enemy_state[k] |= 1u;
  v2 = *(&random_byte3 + k) & R0_;
  if (!secondary_hard_mode)
    v2 = secondary_hard_mode;
  enemy_frame_timer[k] = kHammerBroJumpLData[v2];
  enemy_data_c[k] = *(&random_byte2 + k) | 0xC0;
  CODE_03CEE9(k);
}

void CODE_03CEE9(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // di

  v1 = -4;
  if ((frame_counter & 0x40) == 0)
    v1 = 4;
  obj_xspeed.enemy[k] = v1;
  v2 = 1;
  if ((PlayerEnemyDiff(k) & 0x80u) == 0) {
    v2 = 2;
    if (!*(&enemy_interval_timer + k))
      obj_xspeed.enemy[k] = -8;
  }
  enemy_moving_dir[k] = v2;
  MoveNormalEnemy(k);
}

void MoveNormalEnemy(uint8 k) {
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
    MoveD_EnemyVert(k);
    MoveEnemyHoriz(k);
    return;
  }
  v2 = enemy_state[k] & 7;
  if (!v2)
    goto LABEL_12;
  if (v2 == 5 || v2 < 3u) {
LABEL_7:
    MoveD_EnemyVert(k);
    v1 = 0;
    if (enemy_state[k] == 2) {
      MoveEnemyHoriz(k);
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
    MoveEnemyHoriz(k);
    obj_xspeed.enemy[k] = v7;
    return;
  }
  v4 = *(&enemy_interval_timer + k);
  if (v4) {
    if (v4 == 14 && enemy_id[k] == 6)
      EraseEnemyObject(k);
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

void MoveJumpingEnemy(uint8 k) {
  MoveJ_EnemyVert(k);
  MoveEnemyHoriz(k);
}

void ProcMoveRedPTroopa(uint8 k) {
  if (obj_sub_yspeed.enemy[k] | obj_yspeed.enemy[k] || (obj_sub_ypos.enemy[k] = 0, obj_ypos_lo.enemy[k] >= obj_xpos_fract.enemy[k])) {
    if (obj_ypos_lo.enemy[k] < obj_xspeed.enemy[k])
      MoveRedPTroopaDown(k);
    else
      MoveRedPTroopaUp(k);
  } else if ((frame_counter & 7) == 0) {
    ++obj_ypos_lo.enemy[k];
  }
}

void MoveFlyGreenPTroopa(uint8 k) {
  uint8 v1;  // di

  XMoveCntr_GreenPTroopa(k);
  MoveWithXMCntrs(k);
  v1 = 1;
  if ((frame_counter & 3) == 0) {
    if ((frame_counter & 0x40) == 0)
      v1 = -1;
    R0_ = v1;
    obj_ypos_lo.enemy[k] += v1;
  }
}

void XMoveCntr_GreenPTroopa(uint8 k) {
  XMoveCntr_Platform(k, 0x13u);
}

void XMoveCntr_Platform(uint8 k, uint8 a) {
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

void MoveWithXMCntrs(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // [rsp+47h] [rbp-1h]

  v2 = obj_xspeed.enemy[k];
  v1 = 1;
  if ((obj_yspeed.enemy[k] & 2) == 0) {
    obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
    v1 = 2;
  }
  enemy_moving_dir[k] = v1;
  R0_ = MoveEnemyHoriz(k);
  obj_xspeed.enemy[k] = v2;
}

void MoveBloober(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al
  bool v3;   // cf
  uint8 v4;  // al

  if ((enemy_state[k] & 0x20) != 0) {
    MoveEnemySlowVert(k);
  } else {
    if ((kBlooberBitmasks[secondary_hard_mode] & *(&random_byte2 + k)) == 0) {
      if (k & 1) {
        v1 = player_moving_dir;
      } else {
        v1 = 2;
        if ((PlayerEnemyDiff(k) & 0x80u) != 0)
          v1 = 1;
      }
      enemy_moving_dir[k] = v1;
    }
    ProcSwimmingB(k);
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

void ProcSwimmingB(uint8 k) {
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
        v2 = obj_sub_yspeed.enemy[k] - 1;
        obj_sub_yspeed.enemy[k] = v2;
        obj_xspeed.enemy[k] = v2;
        if (!v2) {
          ++obj_yspeed.enemy[k];
          *(&enemy_interval_timer + k) = 2;
        }
      }
    } else if (!v3) {
      v1 = obj_sub_yspeed.enemy[k] + 1;
      obj_sub_yspeed.enemy[k] = v1;
      obj_xspeed.enemy[k] = v1;
      if (v1 == 2)
        ++obj_yspeed.enemy[k];
    }
  }
}

void MoveBulletBill(uint8 k) {
  if ((enemy_state[k] & 0x20) != 0) {
    MoveJ_EnemyVert(k);
  } else {
    obj_xspeed.enemy[k] = -24;
    MoveEnemyHoriz(k);
  }
}

void MoveSwimmingCheepCheep(uint8 k) {
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
    MoveEnemySlowVert(k);
  } else {
    R3_ = 0;
    R2_ = kSwimCCXMoveData[(uint8)(enemy_id[k] - 10)];
    v1 = obj_xpos_fract.enemy[k];
    v2 = v1 < R2_;
    obj_xpos_fract.enemy[k] = v1 - R2_;
    v3 = obj_xpos_lo.enemy[k];
    obj_xpos_lo.enemy[k] = v3 - v2;
    obj_xpos_hi.enemy[k] -= v3 < (uint8)v2;
    R2_ = 32;
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

void ProcFirebar(uint8 k) {
  uint8 v1;     // al
  uint8 v2;     // al
  uint8 v3;     // di
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v6;     // al
  uint8 v7;     // di

  GetEnemyOffscreenBits(k);
  if ((offscreen_bits.enemy & 8) == 0) {
    if (!timer_control)
      obj_yspeed.enemy[k] = FirebarSpin(k, enemy_data_b[k]) & 0x1F;
    v1 = obj_yspeed.enemy[k];
    if (enemy_id[k] >= 0x1Fu && (v1 == 8 || v1 == 24))
      obj_yspeed.enemy[k] = ++v1;
    tempEF = v1;
    v2 = RelativeEnemyPosition(k);
    GetFirebarPosition(v2);
    v3 = enemy_obj_id[k];
    enemy = rel_ypos.enemy;
    oam = get_OamEnt(oam_buf, v3);
    oam[64].ypos = rel_ypos.enemy;
    R7_ = enemy;
    v6 = rel_xpos_lo.enemy;
    oam[64].xpos = rel_xpos_lo.enemy;
    R6_ = v6;
    R0_ = 1;
    FirebarCollision(v3);
    v7 = 5;
    if (enemy_id[k] >= 0x1Fu)
      v7 = 11;
    tempED = v7;
    R0_ = 0;
    do {
      GetFirebarPosition(tempEF);
      DrawFirebar_Collision();
      if (R0_ == 4)
        R6_ = enemy_obj_id[duplicate_obj_offset];
      ++R0_;
    } while (R0_ < tempED);
  }
}
// 7E03B9: using guessed type int8;

void DrawFirebar_Collision() {
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
  FirebarCollision(v0);
}
// 7E03B9: using guessed type int8;

void FirebarCollision(uint8 j) {
  uint8 player;  // di
  uint8 i;       // al
  int8 v3;       // al
  int8 v4;       // al
  uint8 v5;      // si
  uint8 v6;      // [rsp+46h] [rbp-2h]

  DrawFirebar(j);
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
      enemy_moving_dir[0] = v5;
      v6 = R0_;
      InjurePlayer();
      R0_ = v6;
    }
  }
LABEL_19:
  R6_ = j + 4;
}

void GetFirebarPosition(uint8 a) {
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

void MoveFlyingCheepCheep(uint8 k) {
  uint8 v1;  // di
  int8 v2;   // al

  if ((enemy_state[k] & 0x20) != 0) {
    enemy_sprattrib[k] = 32;
    MoveJ_EnemyVert(k);
  } else {
    MoveEnemyHoriz(k);
    SetXMoveAmt(k, 0xDu, 5u);
    v1 = obj_sub_yspeed.enemy[k] >> 4;
    v2 = obj_ypos_lo.enemy[k] - kPRandomSubtracter[v1];
    if (v2 < 0)
      v2 = kPRandomSubtracter[v1] - obj_ypos_lo.enemy[k];
    if ((uint8)v2 < 8u)
      v1 = (uint8)(obj_sub_yspeed.enemy[k] + 16) >> 4;
    enemy_sprattrib[k] = kFlyCCBPriority[v1];
  }
}

void MoveLakitu(uint8 k) {
  uint8 v1;  // al
  uint8 i;   // di
  uint8 v3;  // di

  if ((enemy_state[k] & 0x20) != 0) {
    MoveD_EnemyVert(k);
  } else {
    if (enemy_state[k]) {
      obj_yspeed.enemy[k] = 0;
      enemy_frenzy_buffer = 0;
      v1 = 16;
    } else {
      enemy_frenzy_buffer = 18;
      for (i = 2; (i & 0x80u) == 0; --i)
        *(&R1_ + i) = kLakituDiffAdj[i];
      v1 = PlayerLakituDiff(k);
    }
    obj_xspeed.enemy[k] = v1;
    v3 = 1;
    if ((obj_yspeed.enemy[k] & 1) == 0) {
      obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
      v3 = 2;
    }
    enemy_moving_dir[k] = v3;
    MoveEnemyHoriz(k);
  }
}

uint8 PlayerLakituDiff(uint8 k) {
  uint8 v1;      // di
  uint8 result;  // al
  uint8 v3;      // di
  int8 v4;       // di

  v1 = 0;
  if ((PlayerEnemyDiff(k) & 0x80u) != 0) {
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

void BridgeCollapse_Sub(uint8 a) {
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

void BridgeCollapse() {
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
    KillAllEnemies();
    return;
  }
  object_index = browser_front_offset;
  v1 = enemy_state[browser_front_offset];
  if (v1) {
    if ((v1 & 0x40) != 0 && obj_ypos_lo.enemy[browser_front_offset] < 0xE0u) {
      MoveEnemySlowVert(browser_front_offset);
      BowserGfxHandler(v0);
      return;
    }
    goto LABEL_5;
  }
  if (!--bowser_feet_counter) {
    bowser_feet_counter = 4;
    browser_body_controls ^= 1u;
    R5_ = 2;
    R4_ = kBridgeCollapseData[bridge_collapse_offset];
    BridgeCollapse_Sub(R4_);
    RemBridge(0x18u, vram_buffer1_offset + 1);
    v0 = object_index;
    MoveVOffset();
    sound_ch3 = 22;
    if (!bridge_collapse_offset) {
      bowser_var014B = 8;
      bowser_var0F4C = -1;
    }
    if (++bridge_collapse_offset == 15) {
      InitVStf(v0);
      enemy_state[v0] = 64;
    }
  }
  BowserGfxHandler(v0);
}

void RunBowser(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di
  uint8 v3;  // al
  uint8 v4;  // al
  uint8 v5;  // al

  if ((enemy_state[k] & 0x20) != 0) {
    if (obj_ypos_lo.enemy[k] < 0xE0u) {
      MoveEnemySlowVert(k);
      BowserGfxHandler(k);
    } else {
      KillAllEnemies();
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
        if (!enemy_frame_timer[k] || (PlayerEnemyDiff(k) & 0x80u) == 0 ||
            (enemy_moving_dir[k] = 1, bowser_movement_speed = 2, enemy_frame_timer[k] = 32, bowser_fire_breath_timer = 32,
             obj_xpos_lo.enemy[k] < 0xB0u)) {
          if ((frame_counter & 3) == 0) {
            if (obj_xpos_lo.enemy[k] == bowser_orig_xpos)
              bowser_var06DC = kDATA_03D55A[*(&random_byte1 + k) & 3];
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
          InitVStf(k);
          obj_yspeed.enemy[k] = -2;
        }
      } else {
        MoveEnemySlowVert(k);
        if (world_number >= 5u && (frame_counter & 3) == 0)
          SpawnThrownHammer(k);
        if (obj_ypos_lo.enemy[k] >= 0x80u)
          enemy_frame_timer[k] = kDATA_03D55A[*(&random_byte1 + k) & 3];
      }
    }
    do {
      if (world_number != 7 && world_number >= 5u || bowser_fire_breath_timer) {
        BowserGfxHandler(k);
        return;
      }
      bowser_fire_breath_timer = 32;
      browser_body_controls ^= 0x80u;
    } while ((browser_body_controls & 0x80u) != 0);
    v5 = SetFlameTimer();
    if (secondary_hard_mode)
      v5 -= 16;
    bowser_fire_breath_timer = v5;
    enemy_frenzy_buffer = 21;
    BowserGfxHandler(k);
  }
}

void KillAllEnemies() {
  int8 i;  // si

  for (i = 8; i >= 0; --i)
    EraseEnemyObject(i);
  enemy_frenzy_buffer = 0;
}

void BowserGfxHandler(uint8 k) {
  int8 v1;   // di
  uint8 v2;  // al
  uint8 v3;  // di
  uint8 v4;  // si
  uint8 v5;  // al
  uint8 v6;  // [rsp+47h] [rbp-1h]

  ProcessBowserHalf(k);
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
    if (world_number == 7)
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

void ProcessBowserHalf(uint8 k) {
  ++bowser_gfx_flag;
  RunRetainerObj(k);
  if (!enemy_state[k]) {
    enemy_hitbox_ctrl[k] = 10;
    GetEnemyBoundBox(k);
    if (game_mode != 2)
      PlayerEnemyCollision(k);
  }
}

uint8 SetFlameTimer() {
  uint8 v0;  // di

  v0 = bowser_flame_timer_ctrl++;
  bowser_flame_timer_ctrl &= 7u;
  return kFlameTimerData[v0];
}

void ProcBowserFlame(uint8 k) {
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
    RelativeEnemyPosition(k);
    if (!enemy_state[k])
      ProcBowserFlame_Sub(k);
  }
}

void RunFireworks(uint8 k) {
  uint8 v2;  // di

  if (obj_yspeed.enemy[k]-- != 1)
    goto LABEL_5;
  obj_yspeed.enemy[k] = 8;
  if (++obj_xspeed.enemy[k] == 1) {
    sound_ch1 = 41;
LABEL_5:
    RelativeEnemyPosition(k);
    rel_ypos.fireball = rel_ypos.enemy;
    rel_xpos_lo.fireball = rel_xpos_lo.enemy;
    DrawExplosion_Fireworks(enemy_obj_id[k], obj_xspeed.enemy[k]);
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
  EndAreaPoints();
}
// 7E03AF: using guessed type int8;
// 7E03B9: using guessed type int8;
// 7E03BA: using guessed type int8;

void RunStarFlagObj(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al

  enemy_frenzy_buffer = 0;
  switch (star_flag_task_control) {
  case 1:
    v1 = 5;
    v2 = level_timer_ones;
    if (level_timer_ones != 1) {
      v1 = 3;
      if (level_timer_ones != 3) {
        v1 = 0;
        if (level_timer_ones != 6)
          v2 = -1;
      }
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
      CODE_03D809();
    }
    break;
  case 3: RaiseFlagSetoffFWorks(k); break;
  case 4: DelayToAreaEnd(k); break;
  }
}

void CODE_03D809() {
  digit_modifier[5] = -1;
  DigitsMathRoutine(0x23u);
  digit_modifier[5] = 5;
  EndAreaPoints();
}

void EndAreaPoints() {
  uint8 v0;  // di

  v0 = 11;
  if (current_player)
    v0 = 17;
  DigitsMathRoutine(v0);
  UpdateNumber((16 * current_player) | 4);
}

void RaiseFlagSetoffFWorks(uint8 k) {
  disable_sprite_oamreset_flag = 1;
  if (obj_ypos_lo.enemy[k] < 0x72u) {
    if ((int8)fireworks_counter > 0) {
      enemy_frenzy_buffer = 22;
      DrawStarFlag(k);
    } else {
      DrawFlagSetTimer(k);
    }
  } else {
    --obj_ypos_lo.enemy[k];
    DrawStarFlag(k);
  }
}

void DrawStarFlag(uint8 k) {
  uint8 v1;     // di
  OamEnt *oam;  // rbp

  RelativeEnemyPosition(k);
  v1 = enemy_obj_id[k];
  oam = get_OamEnt(oam_buf, v1);
  oam[64].ypos = rel_ypos.enemy;
  oam[64].charnum = ((uint8)(frame_counter & 0x18) >> 2) + 4;
  oam[64].flags = 11;
  oam[64].xpos = rel_xpos_lo.enemy;
  oam_tile_size_buffer[v1 + 256] = 2;
}
// 7E03B9: using guessed type int8;

void DrawFlagSetTimer(uint8 k) {
  DrawStarFlag(k);
  *(&enemy_interval_timer + k) = 6;
  IncrementSFTask2();
}

void IncrementSFTask2() {
  ++star_flag_task_control;
}

void DelayToAreaEnd(uint8 k) {
  DrawStarFlag(k);
  if (!*(&enemy_interval_timer + k) && !event_music_buffer)
    IncrementSFTask2();
}

void MovePiranhaPlant(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // al

  if (enemy_state[k] || enemy_frame_timer[k])
    goto LABEL_15;
  if (obj_yspeed.enemy[k])
    goto LABEL_9;
  if ((obj_xspeed.enemy[k] & 0x80u) != 0)
    goto LABEL_8;
  if ((PlayerEnemyDiff(k) & 0x80u) != 0)
    R0_ = -R0_;
  if (R0_ >= 0x21u) {
LABEL_8:
    obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
    ++obj_yspeed.enemy[k];
LABEL_9:
    v1 = obj_sub_yspeed.enemy[k];
    if ((obj_xspeed.enemy[k] & 0x80u) != 0)
      v1 = obj_sub_ypos.enemy[k];
    R0_ = v1;
    if (frame_counter & 1) {
      if (!timer_control) {
        v2 = obj_xspeed.enemy[k] + obj_ypos_lo.enemy[k];
        obj_ypos_lo.enemy[k] = v2;
        if (v2 == R0_) {
          obj_yspeed.enemy[k] = 0;
          enemy_frame_timer[k] = 64;
        }
      }
    }
  }
LABEL_15:
  enemy_sprattrib[k] = 0;
}

uint8 FirebarSpin(uint8 k, uint8 a) {
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

void BalancePlatform(uint8 k) {
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
    EraseEnemyObject(k);
    return;
  }
  v1 = enemy_state[k];
  if ((v1 & 0x80u) != 0)
    return;
  v2 = enemy_state[k];
  R0_ = enemy_data_d[k];
  if (enemy_moving_dir[k]) {
    PlatformFall(k, v1);
    return;
  }
  if (obj_ypos_lo.enemy[k] <= 0x2Du) {
    if (v1 != R0_) {
      obj_ypos_lo.enemy[k] = 47;
      StopPlatforms(k, v1);
      return;
    }
    goto LABEL_9;
  }
  if (obj_ypos_lo.enemy[v1] > 0x2Du) {
    v17 = obj_ypos_lo.enemy[k];
    v3 = enemy_data_d[k];
    if (v3 >= 0) {
      if (v3 != object_index)
        goto LABEL_19;
    } else {
      v4 = obj_sub_yspeed.enemy[k];
      R0_ = v4 + 5;
      v5 = __CFADD__(v4, 5) + obj_yspeed.enemy[k];
      if (v5 >= 0) {
        if (!v5 && R0_ < 0xBu) {
          StopPlatforms(k, v2);
          goto LABEL_22;
        }
LABEL_19:
        MovePlatformUp(k);
LABEL_22:
        obj_ypos_lo.enemy[enemy_state[k]] += v17 - obj_ypos_lo.enemy[k];
        v6 = enemy_data_d[k];
        if (v6 >= 0)
          PositionPlayerOnVPlat(v6);
        v7 = object_index;
        if (obj_sub_yspeed.enemy[object_index] | obj_yspeed.enemy[object_index]) {
          v18 = obj_yspeed.enemy[object_index];
          SetupPlatformRope(object_index, v18);
          tempF3 = (uint8)screen_left_xpos16 >> 3;
          tempF4 = (4 * (HIBYTE(screen_left_xpos16) & 1)) | 0x20;
          v8 = ((uint8)screen_left_xpos16 >> 3) + 31;
          tempF5 = v8 & 0x1F;
          if ((v8 & 0x20) != 0)
            tempF6 = tempF4 ^ 4;
          if ((unsigned int)(*(uint16 *)&R0_ & 0x241F) >= *(uint16 *)&tempF3 ||
              (unsigned int)(*(uint16 *)&R0_ & 0x241F) < *(uint16 *)&tempF5) {
            v9 = *(uint16 *)&vram_buffer1_offset;
            LOBYTE(v10) = (uint16)(*(uint16 *)&R0_ & 0x1FFF) >> 8;
            HIBYTE(v10) = R0_;
            v11 = *(uint16 *)&vram_buffer1_offset;
            *(uint16 *)&vram_buffer1[*(uint16 *)&vram_buffer1_offset + 1] = v10;
            *(uint16 *)&vram_buffer1[v11 + 3] = 768;
            if ((obj_yspeed.enemy[v7] & 0x80) != 0) {
              *(uint16 *)&vram_buffer1[v9 + 5] = 36;
              *(uint16 *)&vram_buffer1[v9 + 7] = 36;
            } else {
              if ((*(uint16 *)&vram_buffer1[v9 + 1] & 0xF003) == 0xA000 || (*(uint16 *)&vram_buffer1[v9 + 1] & 0xF003) == 0xB000) {
                v12 = 6236;
              } else {
                v12 = 4258;
              }
              *(uint16 *)&vram_buffer1[v9 + 5] = v12;
              *(uint16 *)&vram_buffer1[v9 + 7] = 6307;
            }
            *(uint16 *)&vram_buffer1[v9 + 9] = -1;
            *(uint16 *)&vram_buffer1_offset = v9 + 8;
          }
          SetupPlatformRope(enemy_state[v7], ~v18);
          if ((unsigned int)(*(uint16 *)&R0_ & 0x241F) >= *(uint16 *)&tempF3 ||
              (unsigned int)(*(uint16 *)&R0_ & 0x241F) < *(uint16 *)&tempF5) {
            v13 = *(uint16 *)&vram_buffer1_offset;
            LOBYTE(v14) = (uint16)(*(uint16 *)&R0_ & 0x1FFF) >> 8;
            HIBYTE(v14) = R0_;
            v15 = *(uint16 *)&vram_buffer1_offset;
            *(uint16 *)&vram_buffer1[*(uint16 *)&vram_buffer1_offset + 1] = v14;
            *(uint16 *)&vram_buffer1[v15 + 3] = 768;
            if ((v18 & 0x80) != 0) {
              *(uint16 *)&vram_buffer1[v13 + 5] = 4258;
              if ((*(uint16 *)&vram_buffer1[v13 + 1] & 0xF003) == 0xA000 || (*(uint16 *)&vram_buffer1[v13 + 1] & 0xF003) == 0xB000) {
                v16 = 6207;
              } else {
                v16 = 6307;
              }
              *(uint16 *)&vram_buffer1[v13 + 7] = v16;
            } else {
              *(uint16 *)&vram_buffer1[v13 + 5] = 36;
              *(uint16 *)&vram_buffer1[v13 + 7] = 36;
            }
            *(uint16 *)&vram_buffer1[v13 + 9] = -1;
            *(uint16 *)&vram_buffer1_offset = v13 + 8;
          }
        }
        return;
      }
    }
    MovePlatformDown(k);
    goto LABEL_22;
  }
  if (k == R0_) {
LABEL_9:
    InitPlatformFall(k, v1);
    return;
  }
  obj_ypos_lo.enemy[v1] = 47;
  StopPlatforms(k, v1);
}

void SetupPlatformRope(uint8 j, uint8 a) {
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

void InitPlatformFall(uint8 k, uint8 j) {
  GetEnemyOffscreenBits(j);
  SetupFloateyNumber(k, 6u);
  score_spr_xpos_lo[k] = rel_xpos_lo.player;
  score_spr_ypos_lo[k] = obj_ypos_lo.player;
  enemy_moving_dir[k] = 1;
  StopPlatforms(k, j);
}

void StopPlatforms(uint8 k, uint8 j) {
  InitVStf(k);
  obj_yspeed.enemy[j] = 0;
  obj_sub_yspeed.enemy[j] = 0;
}

void PlatformFall(uint8 k, uint8 j) {
  int8 v2;  // al

  MoveFallingPlatform(k);
  if ((enemy_state[j] & 0x80u) != 0)
    MoveFallingPlatform(j);
  v2 = enemy_data_d[object_index];
  if (v2 >= 0)
    PositionPlayerOnVPlat(v2);
}

void YMovingPlatform(uint8 k) {
  if (obj_sub_yspeed.enemy[k] | obj_yspeed.enemy[k] || (obj_sub_ypos.enemy[k] = 0, obj_ypos_lo.enemy[k] >= obj_xpos_fract.enemy[k])) {
    if (obj_ypos_lo.enemy[k] < obj_xspeed.enemy[k])
      MovePlatformDown(k);
    else
      MovePlatformUp(k);
  } else if ((frame_counter & 7) == 0) {
    ++obj_ypos_lo.enemy[k];
  }
  ChkYPCollision(k);
}

void ChkYPCollision(uint8 k) {
  if ((enemy_data_d[k] & 0x80u) == 0)
    PositionPlayerOnVPlat(k);
}

void XMovingPlatform(uint8 k) {
  XMoveCntr_Platform(k, 0xEu);
  MoveWithXMCntrs(k);
  if ((enemy_data_d[k] & 0x80u) == 0)
    PositionPlayerOnHPlat(k);
}

void PositionPlayerOnHPlat(uint8 k) {
  uint8 player;  // al

  bool carry = __CFADD__uint8(obj_xpos_lo.player, R0_);

  obj_xpos_lo.player += R0_;
  if ((R0_ & 0x80u) != 0)
    player = obj_xpos_hi.player - 1 + carry;
  else
    player = obj_xpos_hi.player + carry;
  obj_xpos_hi.player = player;
  platform_x_scroll = R0_;
  PositionPlayerOnVPlat(k);
}

void DropPlatform(uint8 k) {
  if ((enemy_data_d[k] & 0x80u) == 0) {
    MoveDropPlatform(k);
    PositionPlayerOnVPlat(k);
  }
}

void RightPlatform(uint8 k) {
  R0_ = MoveEnemyHoriz(k);
  if ((enemy_data_d[k] & 0x80u) == 0) {
    obj_xspeed.enemy[k] = 16;
    PositionPlayerOnHPlat(k);
  }
}

void MoveLargeLiftPlat(uint8 k) {
  MoveLiftPlatforms(k);
  ChkYPCollision(k);
}

void MoveSmallPlatform(uint8 k) {
  MoveLiftPlatforms(k);
  ChkSmallPlatCollision(k);
}

void MoveLiftPlatforms(uint8 k) {
  uint8 v1;  // al
  bool v2;   // cf

  if (!timer_control) {
    v1 = obj_sub_ypos.enemy[k];
    v2 = __CFADD__(obj_sub_yspeed.enemy[k], v1);
    obj_sub_ypos.enemy[k] = obj_sub_yspeed.enemy[k] + v1;
    obj_ypos_lo.enemy[k] += obj_yspeed.enemy[k] + v2;
  }
}

void ChkSmallPlatCollision(uint8 k) {
  uint8 v1;  // al

  v1 = enemy_data_d[k];
  if (v1) {
    if (v1 != 0xFF)
      PositionPlayerOnS_Plat(k, v1);
  }
}

void OffscreenBoundsCheck(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di
  int8 v3;   // cf
  int8 v4;   // tt

  if (enemy_id[k] != 20) {
    v1 = screen_left_xpos_lo;
    v2 = enemy_id[k];
    v3 = v2 >= 5u;
    if (v2 == 5 || (v3 = v2 >= 0xDu, v2 == 13)) {
      v4 = v3;
      v3 = __CFADD__(v3, screen_left_xpos_lo) | __CFADD__(v3 + screen_left_xpos_lo, 56);
      v1 = v4 + screen_left_xpos_lo + 56;
    }
    R1_ = v1 - (!v3 + 72);
    R0_ = screen_left_xpos_hi - (v1 < (uint8)(!v3 + 72));
    R3_ = screen_right_xpos + 72;
    R2_ = __CFADD__(screen_right_xpos, 72) + screen_right_xpos_hi;
    if ((int8)(obj_xpos_hi.enemy[k] - ((obj_xpos_lo.enemy[k] < R1_) + R0_)) < 0 ||
        (int8)(obj_xpos_hi.enemy[k] - ((obj_xpos_lo.enemy[k] < R3_) + R2_)) >= 0 && enemy_state[k] != 5 && v2 != 13 && v2 != 48 &&
            v2 != 49 && v2 != 50) {
      EraseEnemyObject(k);
    }
  }
}

void FireballEnemyCollision(uint8 k) {
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
            if (SprObjectCollisionCore(4 * v3 + 4, v2) & 1) {
              fireball_state[object_index] = 0x80;
              HandleEnemyFBallCol(R1_);
            }
          }
        }
      }
      v3 = R1_ - 1;
    } while ((int8)(R1_ - 1) >= 0);
  }
}

void HandleEnemyFBallCol(uint8 k) {
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

  RelativeEnemyPosition(k);
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
      ShellOrBlockDefeat(v1);
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
    InitVStf(v1);
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
    func_sub_DDAE(R1_, 9u);
  }
}

void ShellOrBlockDefeat(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // al
  uint8 v3;  // di

  v1 = enemy_id[k];
  if (v1 == 13) {
    v1 = obj_ypos_lo.enemy[k] + 25;
    obj_ypos_lo.enemy[k] = v1;
  }
  ChkToStunEnemies(k, v1);
  enemy_state[k] = enemy_state[k] & 0x1F | 0x20;
  v2 = 2;
  v3 = enemy_id[k];
  if (v3 == 5)
    v2 = 6;
  if (v3 == 6)
    func_sub_DDAE(k, 1u);
  else
    func_sub_DDAE(k, v2);
}

void func_sub_DDAE(uint8 k, uint8 a) {
  SetupFloateyNumber(k, a);
  if (sound_ch1 != 3) {
    sound_ch1 = 3;
    InitializeContactSprite(k);
  }
}

void PlayerHammerCollision(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // si

  if (frame_counter & 1 && !(offscreen_bits.misc | timer_control)) {
    v1 = PlayerCollisionCore(4 * k + 52);
    v2 = object_index;
    if (v1 & 1) {
      if (!misc_collision_flag[object_index]) {
        misc_collision_flag[object_index] = 1;
        obj_xspeed.misc[v2] = -obj_xspeed.misc[v2];
        if (!player_star_power_timer)
          InjurePlayer();
      }
    } else {
      misc_collision_flag[object_index] = 0;
    }
  }
}

void HandlePowerUpCollision(uint8 k) {
  uint8 v1;  // al

  EraseEnemyObject2(k);
  SetupFloateyNumber1(k, 6u);
  sound_ch1 = 10;
  if (power_up_type < 2u) {
    if (player_status) {
      if (player_status != 1)
        return;
      player_status = 2;
      GetPlayerColors();
      v1 = 12;
    } else {
      player_status = 1;
      v1 = 9;
    }
    SetPRout(0, v1);
  } else if (power_up_type == 3) {
    floateynum_control[k] = 11;
    sound_ch1 = 0;
  } else {
    player_star_power_timer = 35;
    music_ch1 = 13;
  }
}

void PlayerEnemyCollision(uint8 k) {
  uint8 EnemyBoundBoxOfs;  // di
  uint8 v2;                // al
  uint8 v3;                // si
  uint8 v4;                // di
  uint8 v5;                // al
  uint8 v6;                // di

  if (!(frame_counter & 1) && !(CheckPlayerVertical() & 1) && (k == 9 && rel_xpos_lo.enemy > 0xF3u || !spr_array_D[k]) &&
      game_engine_subroutine == 8 && (enemy_state[k] & 0x20) == 0) {
    EnemyBoundBoxOfs = GetEnemyBoundBoxOfs();
    v2 = PlayerCollisionCore(EnemyBoundBoxOfs);
    v3 = object_index;
    if (!(v2 & 1)) {
      enemy_collision_bits[object_index] &= ~1u;
      return;
    }
    v4 = enemy_id[object_index];
    if (v4 == 46) {
      HandlePowerUpCollision(object_index);
      return;
    }
    if (player_star_power_timer) {
      ShellOrBlockDefeat(object_index);
      return;
    }
    if (!(spr_array_D[object_index] | enemy_collision_bits[object_index] & 1)) {
      enemy_collision_bits[object_index] |= 1u;
      switch (v4) {
      case 0x12u: goto LABEL_23;
      case 0xDu:
      case 0xCu: goto LABEL_21;
      case 0x33u:
LABEL_23:
        ChkForPlayerInjury(v3);
        return;
      }
      if (v4 >= 0x15u || !area_type) {
LABEL_21:
        InjurePlayer();
        return;
      }
      if (__CFSHL__(enemy_state[v3], 1) || (enemy_state[v3] & 7u) < 2)
        goto LABEL_23;
      if (enemy_id[v3] != 6) {
        sound_ch1 = 3;
        InitializeContactSprite(v3);
        enemy_array_F40[v3] = 0;
        enemy_state[v3] |= 0x80u;
        uint8 yy = EnemyFacePlayer(v3);
        obj_xspeed.enemy[v3] = kKickedShellXSpdData[yy];
        v5 = stomp_chain_counter + 3;
        v6 = *(&enemy_interval_timer + v3);
        if (v6 < 3u)
          v5 = kKickedShellPtsData[v6];
        SetupFloateyNumber(v3, v5);
      }
    }
  }
}

void ChkForPlayerInjury(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di
  uint8 v3;  // [rsp+47h] [rbp-1h]

  if ((int8)obj_yspeed.player > 0 || enemy_id[k] >= 7u && (uint8)(obj_ypos_lo.player + 12) < obj_ypos_lo.enemy[k] || stomp_timer) {
    if (enemy_id[k] == 18)
      goto LABEL_25;
    sound_ch1 = 2;
    v1 = enemy_id[k];
    v2 = 0;
    if (v1 == 20 || v1 == 8 || v1 == 51 || v1 == 12 || (v2 = 1, v1 == 5) || (v2 = 2, v1 == 17) || (v2 = 3, v1 == 7)) {
      SetupFloateyNumber(k, kStompedEnemyPtsData[v2]);
      v3 = enemy_moving_dir[k];
      SetStun(k);
      enemy_moving_dir[k] = v3;
      enemy_state[k] = 32;
      InitVStf(k);
      obj_xspeed.enemy[k] = 0;
      obj_yspeed.player = -3;
    } else {
      if (v1 < 9u) {
        enemy_state[k] = 4;
        ++stomp_chain_counter;
        SetupFloateyNumber(k, stomp_timer + stomp_chain_counter);
        ++stomp_timer;
        *(&enemy_interval_timer + k) = kRevivalRateData[primary_hard_mode];
      } else {
        enemy_id[k] = v1 & 1;
        enemy_state[k] = 0;
        SetupFloateyNumber(k, 3u);
        InitVStf(k);
        uint8 yy = EnemyFacePlayer(k);
        obj_xspeed.enemy[k] = kDemotedKoopaXSpdData[yy];
      }
      obj_yspeed.player = -5;
    }
  } else if (!player_hurt_timer) {
    if (rel_xpos_lo.player >= rel_xpos_lo.enemy) {
      if (enemy_moving_dir[k] == 1) {
LABEL_25:
        InjurePlayer();
        return;
      }
    } else if (enemy_moving_dir[k] != 1) {
      goto LABEL_25;
    }
    EnemyTurnAround(k);
    InjurePlayer();
  }
}

void InjurePlayer() {
  if (!player_hurt_timer)
    ForceInjury(player_hurt_timer);
}

void ForceInjury(uint8 a) {
  if (player_status) {
    player_status = a;
    player_hurt_timer = 8;
    sound_ch1 = 4;
    GetPlayerColors();
    SetPROut_1(0xAu);
  } else {
    KillPlayer(player_status);
  }
}

void SetPROut_1(uint8 a) {
  SetPRout(1u, a);
}

void SetPRout(uint8 j, uint8 a) {
  game_engine_subroutine = a;
  player_state = j;
  timer_control = -1;
  scroll_amount = 0;
}

void KillPlayer(uint8 k) {
  obj_xspeed.player = k;
  player_size = 1;
  GetPlayerColors();
  music_ch1 = 9;
  var0E67 = 9;
  scroll_lock = 9;
  obj_yspeed.player = -4;
  SetPROut_1(0xBu);
}

uint8 EnemyFacePlayer(uint8 k) {
  uint8 v1;  // di

  v1 = 1;
  if ((PlayerEnemyDiff(k) & 0x80u) != 0)
    v1 = 2;
  enemy_moving_dir[k] = v1;
  return v1 - 1;
}

void SetupFloateyNumber1(uint8 k, uint8 a) {
  floateynum_control[k] = a;
  floateynum_timer[k] = 48;
  score_spr_ypos_lo[k] = obj_ypos_lo.enemy[k];
  score_spr_xpos_lo[k] = rel_xpos_lo.enemy;
  tempED = obj_xpos_lo.enemy[k];
  tempEE = obj_xpos_hi.enemy[k];
  floateynum_xpos_word[(uint8)(2 * k) >> 1] = *(uint16 *)&tempED - screen_left_xpos16;
}

uint8 SetupFloateyNumber(uint8 k, uint8 a) {
  if (a >= floateynum_control[k]) {
    floateynum_control[k] = a;
    floateynum_timer[k] = 48;
    score_spr_ypos_lo[k] = obj_ypos_lo.enemy[k];
    score_spr_xpos_lo[k] = rel_xpos_lo.enemy;
    tempE4 = obj_xpos_lo.enemy[k];
    tempE5 = obj_xpos_hi.enemy[k];
    a = tempE4 - screen_left_xpos16;
    floateynum_xpos_word[(uint8)(2 * k) >> 1] = *(uint16 *)&tempE4 - screen_left_xpos16;
    score_spr_xpos_lo[k] = a;
  }
  return a;
}

void EnemiesCollision(uint8 k) {
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
      if (v1 < 0x15u && v1 != 17 && v1 != 13 && !spr_array_D[k]) {
        EnemyBoundBoxOfs = GetEnemyBoundBoxOfs();
        v3 = k - 1;
        if ((v3 & 0x80u) == 0) {
          while (1) {
            R1_ = v3;
            v8 = EnemyBoundBoxOfs;
            if (!enemy_flag[v3])
              goto LABEL_20;
            v4 = enemy_id[v3];
            if (v4 >= 0x15u || v4 == 17 || v4 == 13 || spr_array_D[v3])
              goto LABEL_20;
            v5 = SprObjectCollisionCore(4 * v3 + 4, EnemyBoundBoxOfs);
            v6 = object_index;
            v7 = R1_;
            if (!(v5 & 1)) {
              enemy_collision_bits[R1_] &= kClearBitsMask[object_index];
              goto LABEL_20;
            }
            if (((enemy_state[R1_] | enemy_state[object_index]) & 0x80u) != 0)
              goto LABEL_18;
            if ((kSetBitsMask[object_index] & enemy_collision_bits[R1_]) == 0)
              break;
LABEL_20:
            EnemyBoundBoxOfs = v8;
            v3 = R1_ - 1;
            if ((int8)(R1_ - 1) < 0)
              return;
          }
          enemy_collision_bits[R1_] |= kSetBitsMask[object_index];
LABEL_18:
          ProcEnemyCollisions(v6, v7);
          goto LABEL_20;
        }
      }
    }
  }
}

void ProcEnemyCollisions(uint8 k, uint8 j) {
  uint8 v2;  // si
  uint8 v3;  // al

  if (((enemy_state[k] | enemy_state[j]) & 0x20) != 0)
    return;
  if (enemy_id[k] == 5)
    enemy_state[k] = 0;
  if (enemy_state[k] >= 6u) {
    if (__CFSHL__(enemy_state[j], 1)) {
      SetupFloateyNumber(k, 6u);
      ShellOrBlockDefeat(k);
      j = R1_;
    }
    ShellOrBlockDefeat(j);
    SetupFloateyNumber(R1_, shell_chain_counter[object_index] + 4);
    v2 = object_index;
    ++shell_chain_counter[object_index];
    goto LABEL_12;
  }
  if (enemy_state[j] < 6u) {
    EnemyTurnAround(j);
    EnemyTurnAround(object_index);
    return;
  }
  if (enemy_id[j] != 5) {
    ShellOrBlockDefeat(k);
    SetupFloateyNumber(object_index, shell_chain_counter[R1_] + 4);
    v2 = R1_;
    ++shell_chain_counter[R1_];
LABEL_12:
    v3 = shell_chain_counter[v2] + 18;
    if (v3 >= 0x1Au)
      v3 = 0;
    sound_ch1 = v3;
  }
}

void EnemyTurnAround(uint8 k) {
  uint8 v1;  // al

  v1 = enemy_id[k];
  if (v1 != 13 && v1 != 17 && v1 != 5 && (v1 == 18 || v1 == 14 || v1 < 7u))
    ReverseXSpeed(k);
}

void ReverseXSpeed(uint8 k) {
  obj_xspeed.enemy[k] = -obj_xspeed.enemy[k];
  enemy_moving_dir[k] ^= 3u;
}

void LargePlatformCollision(uint8 k) {
  enemy_data_d[k] = -1;
  if (timer_control || (enemy_state[k] & 0x80u) != 0) {
    DoReturn();
  } else {
    if (enemy_id[k] == 36) {
      ChkForPlayerC_LargeP(enemy_state[k]);
    }
    ChkForPlayerC_LargeP(k);
  }
}

void ChkForPlayerC_LargeP(uint8 k) {
  uint8 EnemyBoundBoxOfsArg;  // di

  if (!(CheckPlayerVertical() & 1)) {
    EnemyBoundBoxOfsArg = GetEnemyBoundBoxOfsArg(k);
    R0_ = obj_ypos_lo.enemy[k];
    if (PlayerCollisionCore(EnemyBoundBoxOfsArg) & 1)
      ProcLPlatCollisions(k, EnemyBoundBoxOfsArg);
  }
  DoReturn();
}

void DoReturn() {
  ;
}

void SmallPlatformCollision(uint8 k) {
  uint8 EnemyBoundBoxOfs;  // di

  if (!timer_control) {
    enemy_data_d[k] = timer_control;
    if (!(CheckPlayerVertical() & 1)) {
      R0_ = 2;
      do {
        EnemyBoundBoxOfs = GetEnemyBoundBoxOfs();
        if ((offscreen_bits.enemy & 2) != 0)
          break;
        if (*(&player_hitbox_top + EnemyBoundBoxOfs) >= 0x20u && PlayerCollisionCore(EnemyBoundBoxOfs) & 1) {
          ProcLPlatCollisions(object_index, EnemyBoundBoxOfs);
          return;
        }
        *(&player_hitbox_top + EnemyBoundBoxOfs) += 0x80;
        *(&player_hitbox_bottom + EnemyBoundBoxOfs) += 0x80;
        --R0_;
      } while (R0_);
    }
  }
}

void ProcLPlatCollisions(uint8 k, uint8 j) {
  uint8 v2;  // al
  uint8 v3;  // di

  if ((uint8)(*(&player_hitbox_bottom + j) - player_hitbox_top) < 4u && (obj_yspeed.player & 0x80u) != 0)
    obj_yspeed.player = 1;
  if ((uint8)(player_hitbox_bottom - *(&player_hitbox_top + j)) >= 6u || (obj_yspeed.player & 0x80u) != 0) {
    R0_ = 1;
    if ((uint8)(player_hitbox_right - *(&player_hitbox_left + j)) < 8u ||
        (++R0_, (uint8)(*(&player_hitbox_right + j) - (player_hitbox_left + 1)) < 9u)) {
      ImpedePlayerMove();
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

void PositionPlayerOnS_Plat(uint8 k, uint8 a) {
  uint8 v2;  // al

  v2 = kPlayerPosSPlatData[a - 1] + obj_ypos_lo.enemy[k];
  if (v2)
    CODE_03E2CE(k, v2);
  else
    obj_ypos_hi.player = 2;
}

void PositionPlayerOnVPlat(uint8 k) {
  CODE_03E2CE(k, obj_ypos_lo.enemy[k]);
}

void CODE_03E2CE(uint8 k, uint8 a) {
  if (game_engine_subroutine != 11 && obj_ypos_hi.enemy[k] == 1) {
    obj_ypos_lo.player = a - 32;
    obj_ypos_hi.player = a >= 0x20u;
    obj_yspeed.player = 0;
    obj_sub_yspeed.player = 0;
  }
}

uint8 CheckPlayerVertical() {
  return (offscreen_bits.player & 0xF0) != 0;
}

uint8 GetEnemyBoundBoxOfs() {
  return GetEnemyBoundBoxOfsArg(object_index);
}

uint8 GetEnemyBoundBoxOfsArg(uint8 a) {
  return 4 * a + 4;
}

void PlayerBGCollision() {
  uint8 v0;   // al
  uint8 v1;   // di
  uint8 v2;   // si
  uint8 v3;   // al
  uint8 v6;   // al
  uint8 v8;   // al
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
  if (obj_ypos_lo.player < kPlayerBGUpperExtent[v2])
    goto LABEL_29;
  tempE4 = 1;
  v3 = BlockBufferColli_Head(tempEB);
  if (!v3)
    goto LABEL_29;
  v6 = v3;
  if (CheckForCoinMTiles(v3))
    goto LABEL_61;
  if ((obj_yspeed.player & 0x80u) == 0 || R4_ < 4u)
    goto LABEL_29;
  v8 = v6;
  if (CheckForSolidMTiles(v6)) {
    if (v8 != 42)
      sound_ch1 = 1;
  } else if (area_type && !block_bounce_timer) {
    PlayerHeadCollision(v8);
    goto LABEL_29;
  }
  obj_yspeed.player = 1;
LABEL_29:
  v9 = tempEB;
  if (obj_ypos_lo.player >= 0xCFu)
    goto LABEL_45;
  tempE4 = 0;
  v10 = BlockBufferColli_Feet(tempEB);
  v12 = v10;
  if (CheckForCoinMTiles(v10)) {
LABEL_61:
    HandleCoinMetatile();
    return;
  }
  a = v12;
  tempE4 = 0;
  R0_ = BlockBufferColli_Feet(v9 + 1);
  v13 = a;
  R1_ = a;
  if (!a) {
    if (!R0_)
      goto LABEL_45;
    v13 = R0_;
    if (CheckForCoinMTiles(v13))
      goto LABEL_61;
  }
  v16 = v13;
  if (!CheckForClimbMTiles(v13) && (obj_yspeed.player & 0x80u) == 0) {
    if (v16 == 0xFD) {
      HandleAxeMetatile();
      return;
    }
    v17 = v16;
    if (ChkInvisibleMTiles(v16)) {
      if (!jumpspring_anim_ctrl) {
        if (R4_ >= 5u) {
          R0_ = player_moving_dir;
          ImpedePlayerMove();
          return;
        }
        ChkForLandJumpSpring(v17);
        obj_ypos_lo.player &= 0xF0u;
        HandlePipeEntry();
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
      v20 = BlockBufferColli_Side(v19);
      if (v20) {
        if (v20 != 32 && v20 != 117) {
          v22 = v20;
          if (!CheckForClimbMTiles(v20))
            break;
        }
      }
    }
    v18 = tempEB + 1;
    if (obj_ypos_lo.player < 8u || obj_ypos_lo.player >= 0xD0u)
      return;
    tempE4 = 0;
    v22 = BlockBufferColli_Side(v18);
    if (v22)
      break;
    if (!--R0_)
      return;
  }
  if (ChkInvisibleMTiles(v22)) {
    v25 = v22;
    if (CheckForClimbMTiles(v22)) {
      HandleClimbing(v25);
      return;
    }
    v27 = v25;
    if (CheckForCoinMTiles(v25))
      goto LABEL_61;
    v29 = v27;
    if (ChkJumpspringMetatiles(v27)) {
      if (jumpspring_anim_ctrl)
        return;
      goto LABEL_76;
    }
    if (player_state || player_facing_dir != 1 || v29 != 118 && v29 != 35) {
LABEL_76:
      ImpedePlayerMove();
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

void HandleCoinMetatile() {
  EraseCoinMetatile();
  ++coin_tally_for_1ups;
  GiveOneCoin();
}

void HandleAxeMetatile() {
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
      BowserDraw(i);
    }
  }
  EraseCoinMetatile();
}
// 7E03B9: using guessed type int8;

void EraseCoinMetatile() {
  RomPtr_RAM(*(uint16 *)&R6_)[R2_] = 0;
  RemoveCoin_Axe();
}

void HandleClimbing(uint8 a) {
  uint8 v1;  // si

  if (R4_ >= 6u && R4_ < 0xAu) {
    if (a == 40 || a == 41) {
      if (game_engine_subroutine != 5) {
        player_facing_dir = 1;
        ++scroll_lock;
        if (game_engine_subroutine != 4) {
          KillEnemies(0x33u);
          SpawnCastleTilesWithPriority();
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
        }
        game_engine_subroutine = 4;
      }
    } else if (a == 42 && obj_ypos_lo.player < 0x20u) {
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
// 7E0082: using guessed type int8;
// 7E0223: using guessed type int8;

uint8 ChkInvisibleMTiles(uint8 a) {
  return a != 0x62 && a != 0x63;
}

void ChkForLandJumpSpring(uint8 a) {
  if (ChkJumpspringMetatiles(a)) {
    vertical_force = 112;
    jumpspring_force = -7;
    jumpspring_timer = 3;
    jumpspring_anim_ctrl = 1;
  }
}

uint8 ChkJumpspringMetatiles(uint8 a) {
  return (a == 111 || a == 112);
}

void HandlePipeEntry() {
  uint8 v0;  // al
  uint8 v1;  // si
  uint8 v2;  // si

  if ((buttons_up_down & 4) != 0 && R0_ == 21 && R1_ == 20) {
    change_area_timer = 48;
    game_engine_subroutine = 3;
    player_hurt_timer = 4;
    player_star_power_timer = 0;
    player_sprattrib = 0;
    v0 = warp_zone_control;
    if (warp_zone_control) {
      if (warp_zone_control < 4u) {
        v1 = 4;
        if (world_number) {
          v1 = 5;
          if (area_type == 1)
            v1 = 6;
        }
        v0 = v1;
        warp_zone_control = v1;
      }
      v2 = 4 * (v0 & 3);
      if (obj_xpos_lo.player >= 0x60u) {
        ++v2;
        if (obj_xpos_lo.player >= 0xA0u)
          ++v2;
      }
      world_number = kWarpZoneNumbers[v2] - 1;
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

void ImpedePlayerMove() {
  uint8 v0;  // si
  uint8 v1;  // al
  uint8 v2;  // di
  bool v3;   // cf

  if (R0_ == 1) {
    v0 = 1;
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

uint8 CheckForSolidMTiles(uint8 a) {
  return a >= kSolidMTileUpperExt[GetMTileAttrib(a)];
}

uint8 CheckForClimbMTiles(uint8 a) {
  uint8 t = kClimbMTileUpperExt[GetMTileAttrib(a)];
  return a >= t;
}

uint8 CheckForCoinMTiles(uint8 a) {
  if (a != 0xE9 && a != 0xEA)
    return 0;
  sound_ch3 = 1;
  return 1;
}

uint8 GetMTileAttrib(uint8 a) {
  return 2 * (4 * (a & 0xC0) + __CFSHL__(a & 0xC0, 1)) + __CFSHL__(2 * (a & 0xC0), 1);
}

void EnemyToBGCollisionDet(uint8 k) {
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
  if (!(SubtEnemyYPos(k) & 1))
    return;
  v1 = enemy_id[k];
  if (v1 == 18 && obj_ypos_lo.enemy[k] < 0x25u)
    return;
  if (v1 == 14) {
    EnemyJump(k);
    return;
  }
  if (v1 != 5) {
    if (v1 != 18 && v1 != 46 && v1 >= 7u)
      return;
    v2 = ChkUnderEnemy(k);
    if (!v2)
      goto LABEL_58;
    if (!ChkForNonSolids(v2))
      goto LABEL_58;
    if (v2 == 39) {
      RomPtr_RAM(*(uint16 *)&R6_)[R2_] = 0;
      v4 = enemy_id[k];
      if (v4 < 0x15u) {
        if (v4 == 6)
          KillEnemyAboveBlock(k);
        v4 = SetupFloateyNumber(k, 1u);
      }
      ChkToStunEnemies(k, v4);
      return;
    }
    if ((uint8)(R4_ - 8) >= 5u) {
LABEL_58:
      if (enemy_id[k] != 3 || enemy_state[k]) {
        v9 = enemy_state[k];
        if (__CFSHL__(v9, 1))
          v10 = enemy_state[k] | 0x40;
        else
          v10 = kEnemyBGCStateData[v9];
        enemy_state[k] = v10;
        DoEnemySideCheck(k);
      } else {
        ChkForBump_HammerBroJ(k);
      }
      return;
    }
    if ((enemy_state[k] & 0x40) == 0) {
      if (__CFSHL__(enemy_state[k], 1) || (v6 = enemy_state[k]) == 0) {
        DoEnemySideCheck(k);
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
          EnemyLanding(k);
          return;
        }
      }
      if (enemy_id[k] != 6) {
        if (enemy_id[k] != 18 || (enemy_moving_dir[k] = 1, obj_xspeed.enemy[k] = 8, (frame_counter & 7) != 0)) {
          v8 = 1;
          if ((PlayerEnemyDiff(k) & 0x80u) != 0)
            v8 = 2;
          if (v8 == enemy_moving_dir[k])
            ChkForBump_HammerBroJ(k);
        }
      }
    }
    EnemyLanding(k);
    if ((enemy_state[k] & 0x80u) != 0)
      enemy_state[k] &= ~0x40u;
    else
      enemy_state[k] = 0;
    return;
  }
  v11 = ChkUnderEnemy(k);
  if (!v11)
    goto LABEL_55;
  if (v11 == 39) {
    KillEnemyAboveBlock(k);
    return;
  }
  if (enemy_frame_timer[k]) {
LABEL_55:
    enemy_state[k] |= 1u;
  } else {
    enemy_state[k] &= 0x88u;
    EnemyLanding(k);
    DoEnemySideCheck(k);
  }
}

void ChkToStunEnemies(uint8 k, uint8 a) {
  if (a >= 9u && a < 0x11u && (a < 0xAu || a >= 0xDu)) {
    enemy_id[k] = a & 1;
    SetStun(k);
  } else {
    SetStun(k);
  }
}

void SetStun(uint8 k) {
  uint8 v1;  // al
  uint8 v2;  // di

  enemy_state[k] = enemy_state[k] & 0xF0 | 2;
  --obj_ypos_lo.enemy[k];
  --obj_ypos_lo.enemy[k];
  if (enemy_id[k] == 7 || (v1 = -3, !area_type))
    v1 = -1;
  obj_yspeed.enemy[k] = v1;
  v2 = 1;
  if ((PlayerEnemyDiff(k) & 0x80u) != 0)
    v2 = 2;
  if (enemy_id[k] != 51 && enemy_id[k] != 8)
    enemy_moving_dir[k] = v2;
  obj_xspeed.enemy[k] = kEnemyBGCXSpdData[(uint8)(v2 - 1)];
}

void DoEnemySideCheck(uint8 k) {
  uint8 v1;  // di
  uint8 v2;  // al

  if (obj_ypos_lo.enemy[k] >= 0x20u) {
    v1 = 22;
    tempEB = 2;
    while (1) {
      if (tempEB == enemy_moving_dir[k]) {
        v2 = BlockBufferChk_Enemy(k, v1, 1u);
        if (v2) {
          if (ChkForNonSolids(v2))
            break;
        }
      }
      --tempEB;
      if (++v1 >= 0x18u)
        return;
    }
    ChkForBump_HammerBroJ(k);
  }
}

void ChkForBump_HammerBroJ(uint8 k) {
  if (k != 9 && __CFSHL__(enemy_state[k], 1)) {
    sound_ch1 = 1;
    InitializeContactSprite(k);
  }
  if (enemy_id[k] == 5) {
    R0_ = 0;
    CODE_03CEC7(k, 0xFAu);
  } else {
    ReverseXSpeed(k);
  }
}
// 110B3: conditional instruction was optimized away because si.1!=9

uint8 PlayerEnemyDiff(uint8 k) {
  uint8 v1;  // al

  v1 = obj_xpos_lo.enemy[k];
  R0_ = v1 - obj_xpos_lo.player;
  return obj_xpos_hi.enemy[k] - ((v1 < obj_xpos_lo.player) + obj_xpos_hi.player);
}

void EnemyLanding(uint8 k) {
  InitVStf(k);
  obj_ypos_lo.enemy[k] = obj_ypos_lo.enemy[k] & 0xF0 | 8;
}

uint8 SubtEnemyYPos(uint8 k) {
  return (uint8)(obj_ypos_lo.enemy[k] + 62) >= 0x44u;
}

void EnemyJump(uint8 k) {
  uint8 v1;  // al

  if (SubtEnemyYPos(k) & 1) {
    if ((uint8)(obj_yspeed.enemy[k] + 2) >= 3u) {
      v1 = ChkUnderEnemy(k);
      if (v1) {
        if (ChkForNonSolids(v1)) {
          EnemyLanding(k);
          obj_yspeed.enemy[k] = -3;
        }
      }
    }
  }
  DoEnemySideCheck(k);
}

void KillEnemyAboveBlock(uint8 k) {
  ShellOrBlockDefeat(k);
  obj_yspeed.enemy[k] = -4;
}

uint8 ChkUnderEnemy(uint8 k) {
  return BlockBufferChk_Enemy(k, 0x15u, 0);
}

uint8 ChkForNonSolids(uint8 a) {
  return (a != 42 && a != 0xE9 && a != 0xEA && a != 98);
}

void FireballBGCollision(uint8 k) {
  uint8 v1;  // al

  if (obj_ypos_lo.fireball[k] >= 0x18u && (v1 = BlockBufferChk_FBall(k)) != 0 && ChkForNonSolids(v1)) {
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

void GetFireballBoundBox(uint8 k) {
  FBallB(k + 11, 2u);
}

void GetMiscBoundBox(uint8 k) {
  FBallB(k + 13, 6u);
}

void FBallB(uint8 k, uint8 j) {
  j = BoundingBoxCore(k, j);
  CheckRightScreenBBox(k, j);
}

void GetEnemyBoundBox(uint8 k) {
  R0_ = 72;
  GetMaskedOffScrBits(k, 0x44u);
}

void SmallPlatformBoundBox(uint8 k) {
  R0_ = 8;
  GetMaskedOffScrBits(k, 4u);
}

void GetMaskedOffScrBits(uint8 k, uint8 j) {
  uint8 v2;  // al
  int8 v3;   // al

  v2 = obj_xpos_lo.enemy[k];
  R1_ = v2 - screen_left_xpos_lo;
  v3 = obj_xpos_hi.enemy[k] - ((v2 < screen_left_xpos_lo) + screen_left_xpos_hi);
  if (v3 >= 0 && R1_ | (uint8)v3)
    j = R0_;
  spr_array_D[k] = offscreen_bits.enemy & j;
  if (k == 9) {
    func_sub_EA11(9u);
  } else if (spr_array_D[k]) {
    func_sub_EA1E(k);
  } else {
    func_sub_EA11(k);
  }
}

void LargePlatformBoundBox(uint8 k) {
  int v1;                // rsi
  uint8 XOffscreenBits;  // al
  uint8 v3;              // si

  v1 = (uint8)(k + 1);
  XOffscreenBits = GetXOffscreenBits(v1);
  v3 = v1 - 1;
  if (XOffscreenBits < 0xFEu)
    func_sub_EA11(v3);
  else
    func_sub_EA1E(v3);
}

void func_sub_EA11(uint8 k) {
  uint8 j = BoundingBoxCore(k + 1, 1u);
  CheckRightScreenBBox(k + 1, j);
}

void func_sub_EA1E(uint8 k) {
  uint8 v1;  // di

  v1 = 4 * k;
  *(&enemy_hitbox_left + v1) = -1;
  *(&enemy_hitbox_top + v1) = -1;
  *(&enemy_hitbox_right + v1) = -1;
  *(&enemy_hitbox_bottom + v1) = -1;
}

uint8 BoundingBoxCore(uint8 k, uint8 j) {
  uint8 v2;  // di
  uint8 v3;  // si

  R0_ = k;
  R2_ = *(&rel_ypos.player + j);
  R1_ = *(&rel_xpos_lo.player + j);
  v2 = 4 * k;
  v3 = 4 * *(&player_hitbox_ctrl + k);
  *(&player_hitbox_left + v2) = kBoundBoxCtrlData[v3] + R1_;
  *(&player_hitbox_right + v2) = kBoundBoxCtrlData[v3++ + 2] + R1_;
  *(&player_hitbox_left + ++v2) = kBoundBoxCtrlData[v3] + R2_;
  *(&player_hitbox_right + v2) = kBoundBoxCtrlData[v3 + 2] + R2_;
  return 4 * k;
}

void CheckRightScreenBBox(uint8 k, uint8 j) {
  R2_ = screen_left_xpos_lo + 0x80;
  R1_ = __CFADD__(screen_left_xpos_lo, 0x80) + screen_left_xpos_hi;
  if (*(&obj_xpos_hi.player + k) < (*(&obj_xpos_lo.player + k) < R2_) + R1_) {
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

uint8 PlayerCollisionCore(uint8 j) {
  return SprObjectCollisionCore(0, j) & 1;
}

uint8 SprObjectCollisionCore(uint8 k, uint8 j) {
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

uint8 BlockBufferChk_Enemy(uint8 k, uint8 j, uint8 a) {
  return BBChk_E(k + 1, j, a);
}

uint8 BlockBufferChk_FBall(uint8 k) {
  return BBChk_E(k + 11, 0x1Au, 0);
}

uint8 BBChk_E(uint8 k, uint8 j, uint8 a) {
  return BlockBufferCollision(k, j, a);
}

uint8 BlockBufferColli_Feet(uint8 j) {
  return BlockBufferColli_Head(j + 1);
}

uint8 BlockBufferColli_Head(uint8 j) {
  return CODE_03EB81(j, 0);
}

uint8 BlockBufferColli_Side(uint8 j) {
  return CODE_03EB81(j, 1u);
}

uint8 CODE_03EB81(uint8 j, uint8 a) {
  return BlockBufferCollision(0, j, a);
}

uint8 BlockBufferCollision(uint8 k, uint8 j, uint8 a) {
  uint8 v3;  // al
  bool v4;   // cf
  int8 v5;   // al

  R4_ = j;
  v3 = kBlockBuffer_X_Adder[j];
  v4 = __CFADD__(*(&obj_xpos_lo.player + k), v3);
  R5_ = *(&obj_xpos_lo.player + k) + v3;

  uint8 t = ((v4 + *(&obj_xpos_hi.player + k)) & 1);
  GetBlockBufferAddr((uint8)(R5_ >> 1 | t << 7) >> 3);
  R2_ = ((kBlockBuffer_Y_Adder[R4_] + *(&obj_ypos_lo.player + k)) & 0xF0) - 32;
  R3_ = RomPtr_RAM(*(uint16 *)&R6_)[R2_];
  if (a)
    v5 = *(&obj_xpos_lo.player + k);
  else
    v5 = *(&obj_ypos_lo.player + k);
  R4_ = v5 & 0xF;
  if (!tempE4 && (R3_ == 98 || R3_ == 99))
    R3_ = 0;
  return R3_;
}

void SixSpriteStacker(uint8 j, uint8 a) {
  int8 v2;  // si

  v2 = 6;
  do {
    get_OamEnt(oam_buf, j)[64].xpos = a;
    a += 8;
    j += 4;
    --v2;
  } while (v2);
}

void CODE_03EC3C(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[3].ypos = a;
  oam[2].ypos = a;
  DumpTwoSpr_(j, a);
}

void DumpTwoSpr_(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[1].ypos = a;
  oam->ypos = a;
}

void MoveSixSpritesOffscreen(uint8 j) {
  DumpSixSpr(j, 0xF0u);
}

void DumpSixSpr(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[69].ypos = a;
  oam[68].ypos = a;
  DumpFourSpr(j, a);
}

void DumpFourSpr(uint8 j, uint8 a) {
  get_OamEnt(oam_buf, j)[67].ypos = a;
  DumpThreeSpr(j, a);
}

void DumpThreeSpr(uint8 j, uint8 a) {
  get_OamEnt(oam_buf, j)[66].ypos = a;
  DumpTwoSpr(j, a);
}

void DumpTwoSpr(uint8 j, uint8 a) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, j);
  oam[65].ypos = a;
  oam[64].ypos = a;
}

void DrawLargePlatform(uint8 k) {
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
    DrawLargePlatform_Sub1();
  } else {
    R2_ = enemy_obj_id[k];
    v1 = R2_;
    SixSpriteStacker(R2_, rel_xpos_lo.enemy);
    v2 = object_index;
    v3 = obj_ypos_lo.enemy[object_index];
    DumpFourSpr(v1, v3);
    if (area_type == 3 || secondary_hard_mode)
      v3 = -16;
    v4 = enemy_obj_id[v2];
    oam = get_OamEnt(oam_buf, v4);
    oam[68].ypos = v3;
    oam[69].ypos = v3;
    v6 = object_index;
    DumpSixSpr(++v4, 0x87u);
    DumpSixSpr(v4 + 1, 0x2Cu);
    GetXOffscreenBits(v6);
    v7 = enemy_obj_id[v6];
    GetEnemyXPos(v6);
    DrawLargePlatform_DrawOne(v7);
    j = v7;
    v8 = DrawLargePlatform_Next(v7);
    DrawLargePlatform_DrawOne(v8);
    v9 = DrawLargePlatform_Next(v8);
    DrawLargePlatform_DrawOne(v9);
    v10 = DrawLargePlatform_Next(v9);
    DrawLargePlatform_DrawOne(v10);
    v11 = DrawLargePlatform_Next(v10);
    DrawLargePlatform_DrawOne(v11);
    v12 = DrawLargePlatform_Next(v11);
    DrawLargePlatform_DrawOne(v12);
    if (__CFSHL__(offscreen_bits.enemy, 1) && enemy_id[v6] != 39 && enemy_id[v6] != 38 &&
        (obj_ypos_hi.enemy[v6] != 1 || rel_ypos.enemy >= 0xF0u)) {
      MoveSixSpritesOffscreen(j);
    }
  }
}

void DrawPowerUp() {
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
    v0 = DrawOneSpriteRow(v1, v0, kPowerUpGfxTable[v1 + 1]);
    v1 += 2;
    --R7_;
  } while ((R7_ & 0x80u) == 0);
  if (v5 && v5 != 3) {
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
  SprObjectOffscrChk(enemy_obj_id[9] + 8);
}
// 7E03B9: using guessed type int8;

void EnemyGfxHandler_New(uint8 k) {
  uint8 v1;  // al

  v1 = enemy_id[k];
  switch (v1) {
  case 0xCu: EnemyGfxHandler_Sub4(k); return;
  case 8u:
    if (obj_ypos_hi.enemy[k] == 2)
      EraseEnemyObject(k);
    break;
  case 0x33u:
    if (obj_ypos_hi.enemy[k] == 2)
      EraseEnemyObject(k);
    break;
  default: DrawLevelPreviewSprites_Sub3(k, v1); return;
  }
  EnemyGfxHandler_Sub1(k);
}

void DrawLevelPreviewSprites_Sub3(uint8 k, uint8 a) {
  uint8 v2;       // di
  uint8 v3;       // al
  uint8 v4;       // al
  uint8 v5;       // di
  uint8 v6;       // al
  uint8 v7;       // al
  uint8 v8;       // al
  uint8 v9;       // si
  uint8 v10;      // di
  uint8 v11;      // si
  uint8 v12;      // di
  uint8 v13;      // al
  uint8 v14;      // si
  OamEnt *oam;    // rbp
  OamEnt *v16;    // rdx
  uint8 v17;      // di
  uint8 v18;      // si
  OamEnt *v19;    // rbp
  OamEnt *v20;    // rbx
  uint8 v21;      // si
  OamEnt *v22;    // rdx
  uint8 v23;      // al
  uint8 v24;      // al
  uint8 v25;      // al
  OamEnt *v26;    // rdx
  uint8 v27;      // al
  OamEnt *v28;    // rbp
  OamEnt *v29;    // rbp
  OamEnt *v30;    // rbp
  uint8 v31;      // [rsp+46h] [rbp-2h]
  uint8 charnum;  // [rsp+47h] [rbp-1h]

  if (a == 45) {
    BowserDraw(k);
    return;
  }
  if (a == 53) {
    if (world_number == 7)
      DrawLevelPreviewSprites_Sub7();
    else
      DrawToadAndRelatedSprites(k);
    return;
  }
  R2_ = obj_ypos_lo.enemy[k];
  R5_ = rel_xpos_lo.enemy;
  tempEB = enemy_obj_id[k];
  tempF0 = 0;
  R3_ = enemy_moving_dir[k];
  R4_ = enemy_sprattrib[k];
  if (enemy_id[k] != 13 || (obj_xspeed.enemy[k] & 0x80u) != 0 || !enemy_frame_timer[k]) {
    tempED = enemy_state[k];
    v2 = tempED & 0x1F;
    v3 = enemy_id[k];
    if (v3 == 53) {
      v2 = 0;
      R3_ = 1;
      v3 = 21;
    }
    if (v3 == 51) {
      --R2_;
      v4 = 32;
      if (enemy_frame_timer[k])
        v4 = 16;
      R4_ = v4;
      v2 = 0;
      tempED = 0;
      v3 = 8;
    }
    if (v3 == 50) {
      v2 = 3;
      v3 = kJumpspringFrameOffsets[jumpspring_anim_ctrl];
    }
    tempEF = v3;
    tempEC = v2;
    if (v3 == 12 && (obj_yspeed.enemy[object_index] & 0x80u) == 0)
      ++tempF0;
    if (bowser_gfx_flag) {
      v5 = 22;
      if (bowser_gfx_flag != 1)
        v5 = 23;
      tempEF = v5;
    }
    if (tempEF == 6) {
      v6 = enemy_state[object_index];
      if (v6 >= 2u)
        tempEC = 4;
      if (!(timer_control | v6 & 0x20) && (frame_counter & 8) == 0)
        R3_ ^= 3u;
    }
    if (tempEF == 20)
      v7 = 60;
    else
      v7 = R4_ ^ kEnemyAttributeData[tempEF];
    R4_ = v7;
    if (tempEF == 21 && world_number == 7)
      R4_ = R4_ & 0xF0 | 4;
    if (which_enemy_gfx_offs)
      v8 = kEnemyGfxTableOffsets[tempEF] + 6;
    else
      v8 = kEnemyGfxTableOffsets[tempEF];
    v9 = v8;
    if (bowser_gfx_flag) {
      if (bowser_gfx_flag == 1) {
        if ((browser_body_controls & 0x80u) != 0)
          v9 = -34;
        if ((tempED & 0x20) != 0)
          goto LABEL_45;
      } else {
        if ((browser_body_controls & 1) != 0)
          v9 = -28;
        if ((tempED & 0x20) != 0) {
          R2_ -= 16;
LABEL_45:
          tempF0 = v9;
        }
      }
LABEL_92:
      v10 = tempEB;
      if (!(CODE_05E8CA(tempEB) & 1)) {
        DrawEnemyObjRow(v9, v10);
        DrawEnemyObjRow(v9 + 2, v10 + 8);
        DrawEnemyObjRow(v9 + 4, v10 + 16);
        DrawLevelPreviewSprites_Sub8();
      }
      v11 = object_index;
      v12 = enemy_obj_id[object_index];
      if (enemy_id[object_index] == 12) {
        ++enemy_arr_0E1B[object_index];
        v13 = enemy_arr_0E1B[v11];
        if (v13 >= 0x12u) {
          enemy_arr_0E1B[v11] = 0;
          v13 = enemy_arr_0E1B[v11];
        }
        v14 = kDATA_03EECB[v13];
        oam = get_OamEnt(oam_buf, v12);
        oam[64].charnum = kDATA_03EEDD[v14];
        oam[65].charnum = kDATA_03EEDD[v14 + 1];
        oam[66].charnum = kDATA_03EEDD[v14 + 2];
        oam[67].charnum = kDATA_03EEDD[v14 + 3];
        oam[68].charnum = kDATA_03EEDD[v14 + 4];
        oam[69].charnum = kDATA_03EEDD[v14 + 5];
      }
      if (tempEF == 8)
        goto LABEL_127;
      if (tempF0) {
        v16 = get_OamEnt(oam_buf, v12);
        v17 = v12 + 2;
        DumpSixSpr(v17, v16[64].flags | 0x80);
        v12 = v17 - 2;
        v18 = v12;
        if (tempEF != 5 && tempEF != 17 && tempEF < 0x15u)
          v18 = v12 + 8;
        v19 = get_OamEnt(oam_buf, v18);
        charnum = v19[64].charnum;
        v31 = v19[65].charnum;
        v20 = get_OamEnt(oam_buf, v12);
        v19[64].charnum = v20[68].charnum;
        v19[65].charnum = v20[69].charnum;
        v20[69].charnum = v31;
        v20[68].charnum = charnum;
      }
      if (bowser_gfx_flag)
        goto LABEL_127;
      v21 = tempEC;
      if (tempEF == 5)
        goto LABEL_127;
      if ((tempEF == 7 || tempEF == 13 || tempEF == 12 || (tempEF != 18 || tempEC == 5) && tempEC >= 2u) && !bowser_gfx_flag &&
          !enemy_array_F40[9]) {
        v22 = get_OamEnt(oam_buf, v12);
        v23 = v22[64].flags & 0xBE;
        v22[64].flags = v23;
        v22[66].flags = v23;
        v22[68].flags = v23;
        v24 = v23 | 0x40;
        if (v21 == 5)
          v24 |= 0x80u;
        v22[65].flags = v24;
        v22[67].flags = v24;
        v22[69].flags = v24;
        if (v21 == 4) {
          v25 = v22[66].flags | 0x80;
          v22[66].flags = v25;
          v22[68].flags = v25;
          v25 |= 0x40u;
          v22[67].flags = v25;
          v22[69].flags = v25;
        }
      }
      if (tempEF == 17) {
        if (!tempF0) {
          v26 = get_OamEnt(oam_buf, v12);
          v26[68].flags &= ~0x40u;
          v27 = v26[69].flags | 0x40;
          v26[69].flags = v27;
          if (frenzy_enemy_timer < 0x10u) {
            v26[67].flags = v27;
            v26[66].flags = v27 & 0xBF;
          }
LABEL_127:
          if (tempEF == 13) {
            v30 = get_OamEnt(oam_buf, v12);
            v30[68].flags = v30[68].flags & 0xF0 | 8;
            v30[69].flags = v30[69].flags & 0xF0 | 8;
          }
          SprObjectOffscrChk(v12);
          return;
        }
        v28 = get_OamEnt(oam_buf, v12);
        v28[64].flags &= ~0x40u;
        v28[65].flags |= 0x40u;
      }
      if (tempEF >= 0x18u) {
        v29 = get_OamEnt(oam_buf, v12);
        v29[66].flags = -84;
        v29[68].flags = -84;
        v29[67].flags = -20;
        v29[69].flags = -20;
        v29[64].flags = 44;
        v29[65].flags = 108;
      }
      goto LABEL_127;
    }
    if (v8 == 36) {
      if (tempEC == 5) {
        v9 = 48;
        R3_ = 2;
        tempEC = 5;
      }
    } else {
      if (v8 == 0x90) {
        if ((tempED & 0x20) == 0 && frenzy_enemy_timer < 0x10u)
          v9 = -106;
        goto LABEL_89;
      }
      if (tempEF < 4u && tempEC >= 2u) {
        v9 = 90;
        if (tempEF == 2) {
          v9 = 126;
          ++R2_;
        }
      }
      if (tempEC == 4) {
        v9 = 114;
        ++R2_;
        if (tempEF != 2) {
          v9 = 102;
          ++R2_;
        }
        if (tempEF == 6) {
          v9 = 84;
          if ((tempED & 0x20) == 0) {
            v9 = -118;
            --R2_;
          }
        }
      }
    }
    if (tempEF == 5) {
      if (tempED) {
        if ((tempED & 8) == 0)
          goto LABEL_89;
        v9 = -76;
      }
    } else if (v9 != 72) {
      if (*(&enemy_interval_timer + object_index) >= 5u)
        goto LABEL_89;
      if (v9 == 60) {
        if (*(&enemy_interval_timer + object_index) != 1) {
          ++R2_;
          ++R2_;
          ++R2_;
          goto LABEL_87;
        }
LABEL_89:
        if ((tempED & 0x20) != 0 && tempEF >= 4u) {
          tempF0 = 1;
          tempEC = 0;
        }
        goto LABEL_92;
      }
    }
    if (tempEF != 6 && tempEF != 8 && tempEF != 12 && tempEF < 0x18u) {
      if (tempEF == 21) {
        if (world_number < 7u) {
          v9 = -94;
          tempEC = 3;
        }
        goto LABEL_89;
      }
      if ((kEnemyAnimTimingBMask[0] & frame_counter) == 0) {
LABEL_87:
        if (!(timer_control | tempED & 0xA0))
          v9 += 6;
        goto LABEL_89;
      }
    }
    goto LABEL_89;
  }
}

void SprObjectOffscrChk(uint8 j) {
  uint8 v1;  // si
  uint8 v2;  // di
  int8 v3;   // cf
  uint8 v4;  // [rsp+47h] [rbp-1h]
  uint8 v5;  // [rsp+47h] [rbp-1h]

  v1 = object_index;
  GetEnemyXPos(object_index);
  R4_ = 0;
  CODE_03FEE5(j);
  v2 = DrawLargePlatform_Next(j);
  R4_ = 0;
  CODE_03FEE5(v2);
  v4 = offscreen_bits.enemy >> 6;
  if ((offscreen_bits.enemy & 0x20) != 0)
    CODE_03F313(v1, 0x10u);
  v3 = v4 & 1;
  v5 = v4 >> 1;
  if (v3)
    CODE_03F313(v1, 8u);
  if (v5 & 1) {
    CODE_03F313(v1, v5 >> 1);
    if (enemy_id[v1] != 12 && obj_ypos_hi.enemy[v1] == 2)
      EraseEnemyObject(v1);
  }
}

void DrawEnemyObjRow(uint8 k, uint8 j) {
  R0_ = kEnemyGraphicsTable[k];
  DrawOneSpriteRow(k, j, kEnemyGraphicsTable[k + 1]);
}

uint8 DrawOneSpriteRow(uint8 k, uint8 j, uint8 a) {
  R1_ = a;
  if (R2_ == 0xF9)
    R2_ = -16;
  return DrawOneSpriteRow_Sub(j);
}

uint8 DrawOneSpriteRow_(uint8 j, uint8 a) {
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

void CODE_03F313(uint8 k, uint8 a) {
  object_index = k;
  if (k == 10)
    k = 9;
  DumpTwoSpr(enemy_obj_id[k] + a, 0xF0u);
}

void CODE_03F326(uint8 k, uint8 a) {
  OamEnt *oam;  // rbp

  object_index = k;
  if (k == 10)
    k = 9;
  oam = get_OamEnt(oam_buf, (uint8)(enemy_obj_id[k] + a));
  oam[64].ypos = -16;
  oam[66].ypos = -16;
  oam[68].ypos = -16;
}

void DrawBlock(uint8 k) {
  uint8 v1;     // di
  OamEnt *oam;  // rbp
  int8 v3;      // al

  v1 = block_obj_id[k];
  oam = get_OamEnt(oam_buf, v1);
  oam->xpos = rel_xpos_lo.block;
  oam->ypos = rel_ypos.block;
  oam->flags = 43;
  oam_tile_size_buffer[v1] = 2;
  if (block_metatile[k] == 0xFC)
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
// 7E03B1: using guessed type int8;
// 7E03BC: using guessed type int8;

void DrawBrickChunks(uint8 k) {
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
  CODE_03EC3C(v2++, v1);
  CODE_03EC3C(v2, R0_ | (16 * frame_counter) & 0xC0);
  v3 = v2 - 2;
  block = rel_ypos.block;
  if (rel_ypos.block >= 0xF0u)
    block = -16;
  DumpTwoSpr_(v3, block);
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
    DumpTwoSpr_(v3, 0xF0u);
  if (offscreen_bits.block) {
    oam_tile_size_buffer[v3] = 1;
    oam_tile_size_buffer[v3 + 8] = 1;
  }
  if (offscreen_bits.unk5) {
    oam_tile_size_buffer[v3 + 4] = 1;
    oam_tile_size_buffer[v3 + 12] = 1;
  }
}
// 7E03B1: using guessed type int8;
// 7E03B2: using guessed type int8;
// 7E03BC: using guessed type int8;
// 7E03BD: using guessed type int8;

void DrawFireball(uint8 k) {
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
// 7E03AF: using guessed type int8;
// 7E03BA: using guessed type int8;

void DrawFirebar(uint8 j) {
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

void DrawExplodingPlayerFireball(uint8 k) {
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
    CODE_03EC3C(v4, kDATA_03F4A4[v3]);
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
// 7E03AF: using guessed type int8;
// 7E03BA: using guessed type int8;

void DrawExplosion_Fireworks(uint8 j, uint8 a) {
  int v2;       // rdi
  uint8 v3;     // si
  uint8 v4;     // al
  OamEnt *oam;  // rbp
  uint8 v6;     // al
  uint8 v7;     // si

  v2 = (uint8)(j + 1);
  DumpFourSpr(v2, kDATA_03F53B[a]);
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
  oam[64].flags = kDATA_03F53F[v7] | 0x20;
  oam[65].flags = kDATA_03F53F[v7] | 0xA0;
  oam[66].flags = kDATA_03F53F[v7] | 0x60;
  oam[67].flags = kDATA_03F53F[v7] | 0xE0;
}
// 7E03AF: using guessed type int8;
// 7E03BA: using guessed type int8;

void DrawSmallPlatform(uint8 k) {
  uint8 v1;     // di
  uint8 v2;     // di
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v5;     // [rsp+47h] [rbp-1h]
  uint8 v6;     // [rsp+47h] [rbp-1h]

  v1 = enemy_obj_id[k] + 1;
  DumpSixSpr(v1++, 0x87u);
  DumpSixSpr(v1, 0x2Cu);
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
  DumpThreeSpr(v2, v5);
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
// 7E03D1: using guessed type int8;

void PlayerGfxHandler() {
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
    HandleTurnAroundSmoke();
  }
  if (game_engine_subroutine == 3 || !player_hurt_timer || !(frame_counter & 1)) {
    if (game_engine_subroutine == 11) {
      PlayerKilled();
    } else if (player_change_size_flag) {
      DoChangeSize();
    } else if (swimming_flag && player_state) {
      FindPlayerAction();
      v0 = spr_data_offset;
      if (!(player_facing_dir & 1))
        v0 = spr_data_offset + 4;
      if (!player_size) {
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
      FindPlayerAction();
    }
  }
}

void FindPlayerAction() {
  uint8 v0;  // al

  v0 = ProcessPlayerAction();
  PlayerGfxProcessing(v0);
}

void DoChangeSize() {
  uint8 v0;  // al

  v0 = HandleChangeSize();
  PlayerGfxProcessing(v0);
}

void PlayerKilled() {
  PlayerGfxProcessing(kPlayerGfxTblOffsets[14]);
}

void PlayerGfxProcessing(uint8 a) {
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
  RenderPlayerSub(4u);
  UNUSED_ChkForPlayerAttrib();
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
      RenderPlayerSub(v3);
    }
  }
  R0_ = offscreen_bits.player >> 4;
  v4 = 3;
  v5 = spr_data_offset + 24;
  do {
    v2 = R0_ & 1;
    R0_ >>= 1;
    if (v2)
      DumpTwoSpr_(v5, 0xF0u);
    v5 -= 8;
    --v4;
  } while (v4 >= 0);
  PlayerGfxProcessing_Sub_New();
}

void DrawLevelPreviewSprites() {
  uint8 i;  // si

  DrawLevelPreviewSprites_Sub_New();
  player_gfx_offset = -48;
  RenderPlayerSub_New();
  for (i = 5; (i & 0x80u) == 0; --i)
    *(&R2_ + i) = kIntermediatePlayerData[i];
  uint8 j = DrawPlayerLoop(0xB8u, 0xD0u);
  DrawLevelPreviewSprites_Sub(j);
  Entrance_GameTimerSetup();
}

void DrawLevelPreviewSprites_Sub(uint8 j) {
  OamEnt *oam;  // rbp
  uint8 v2;     // si
  uint8 v3;     // di
  uint8 v4;     // si
  OamEnt *v5;   // rdx
  int8 i;       // si
  uint8 v7;     // [rsp+45h] [rbp-3h]

  do {
    oam = get_OamEnt(oam_buf, j);
    oam->ypos = -16;
    oam[64].ypos = -16;
    ++j;
  } while (j);
  j = DrawLevelPreviewSprites_Sub2();
  v2 = 0;
  tempE2 = 48;
  do {
    if (DrawLevelPreviewSprites_Sub4(v2, j) == 2) {
      if (enemy_id[v2] == 22) {
        DrawLevelPreviewSprites_Sub5(v2);
        goto LABEL_16;
      }
      v7 = j;
      DrawLevelPreviewSprites_Sub3(v2, enemy_id[v2]);
      v3 = enemy_obj_id[v2];
      oam_tile_size_buffer[v3 + 256] = 0;
      oam_tile_size_buffer[v3 + 260] = 0;
      oam_tile_size_buffer[v3 + 264] = 0;
      oam_tile_size_buffer[v3 + 268] = 0;
      oam_tile_size_buffer[v3 + 272] = 0;
      oam_tile_size_buffer[v3 + 276] = 0;
      obj_xpos_hi.enemy[v2] = HIBYTE(screen_left_xpos16);
      j = v7;
      if (enemy_id[v2] == 18)
        DrawLakituAboveSpinyInLevelPreview(v2);
    }
    ++j;
    ++v2;
  } while (v2 != 5);
  if (area_type != 3) {
    v4 = 0;
    do {
      v5 = get_OamEnt(oam_buf, v4);
      if (v5[64].charnum == v5[65].charnum) {
        v5[64].flags &= 0x3Fu;
        v5[65].flags |= 0x40u;
      } else {
        v5[64].flags = v5[65].flags;
      }
      v4 += 8;
    } while (v4);
  }
LABEL_16:
  for (i = 4; i >= 0; --i)
    enemy_id[(uint8)i] = 0;
  which_enemy_gfx_offs = 0;
}

uint8 DrawLevelPreviewSprites_Sub4(uint8 k, uint8 j) {
  uint8 v2;      // al
  uint8 result;  // al
  uint8 v4;      // al

  which_enemy_gfx_offs = 0;
  if (player_hard_mode_flag)
    v2 = kDATA_05EC92[j];
  else
    v2 = kDATA_05EBED[j];
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
    if (kDATA_05EBED[j] == 5) {
      which_enemy_gfx_offs = kDATA_05EBED[j];
      DrawLevelPreviewSprites_Sub6(k);
    }
    result = 2;
    enemy_moving_dir[k] = 2;
  }
  return result;
}

uint8 DrawLevelPreviewSprites_Sub2() {
  uint8 v0;  // si

  v0 = area_number + 5 * world_number;
  background_color_ctrl_0 = kDATA_05ED37[v0];
  level_level_preview_image_to_use = kDATA_05ED64[v0];
  uint8 rv = level_level_preview_image_to_use * 5;
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
  return rv;
}

void Unused_CODE_03F9EC() {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, 0);
  oam[88].charnum = kDATA_03F9E6[0];
  oam[89].charnum = kDATA_03F9E6[1];
  oam[90].charnum = kDATA_03F9E6[2];
  oam[91].charnum = kDATA_03F9E6[3];
  oam[92].charnum = kDATA_03F9E6[4];
  oam[93].charnum = kDATA_03F9E6[5];
}

void DrawLakituAboveSpinyInLevelPreview(uint8 k) {
  uint8 v1;     // di
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v4;     // al
  int v5;       // edx

  R3_ = 3;
  obj_ypos_lo.enemy[k] -= 40;
  tempE3 = 0;
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
    v5 = tempE3;
    oam[100].charnum = kDATA_03FA11[tempE3];
    oam[101].charnum = kDATA_03FA11[v5 + 1];
    ++tempE3;
    ++tempE3;
    v1 += 8;
    --R3_;
  } while (R3_);
}

void DrawLevelPreviewSprites_Sub5(uint8 k) {
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
// 7E03B9: using guessed type int8;

void DrawLevelPreviewSprites_Sub6(uint8 k) {
  OamEnt *oam;  // rbp

  oam = get_OamEnt(oam_buf, 0);
  oam[32].ypos = obj_ypos_lo.enemy[k] - 10;
  oam[32].xpos = rel_xpos_lo.enemy + 3;
  oam[32].flags = 42;
  oam[32].charnum = 68;
  oam_tile_size_buffer[128] = 2;
}

void RenderPlayerSub(uint8 a) {
  R7_ = a;
  player_pos_for_scroll = rel_xpos_lo.player;
  R5_ = rel_xpos_lo.player;
  R2_ = rel_ypos.player;
  R3_ = player_facing_dir;
  RenderPlayerSub_New();
  R4_ = player_sprattrib;
  DrawPlayerLoop(player_gfx_offset & 7, spr_data_offset);
}

uint8 DrawPlayerLoop(uint8 k, uint8 j) {
  do {
    R0_ = kPlayerGraphicsTable[k];
    j = DrawOneSpriteRow_(j, kPlayerGraphicsTable[k + 1]);
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

uint8 ProcessPlayerAction() {
  uint8 v0;                 // di
  uint8 v1;                 // di
  uint8 GfxOffsetAdder;     // di
  uint8 v4;                 // di
  uint8 v5;                 // al
  uint8 v6;                 // al
  uint8 CurrentAnimOffset;  // [rsp+47h] [rbp-1h]

  if (player_state != 3) {
    if (player_state == 2) {
      GfxOffsetAdder = GetGfxOffsetAdder(4u);
      return GetCurrentAnimOffset(GfxOffsetAdder);
    }
    if (player_state == 1) {
      if (!swimming_flag) {
        v0 = 6;
        if (!crouching_flag)
          v0 = 0;
        goto LABEL_12;
      }
      v4 = GetGfxOffsetAdder(1u);
      if (!(player_anim_ctrl | jump_swim_timer) && !__CFSHL__(buttons_a_b, 1))
        return GetCurrentAnimOffset(v4);
      goto LABEL_20;
    }
    v0 = 6;
    if (crouching_flag)
      goto LABEL_12;
    v0 = 2;
    if (!(buttons_left_right | obj_xspeed.player))
      goto LABEL_12;
    if (player_x_speed_absolute < 9u || (player_facing_dir & player_moving_dir) != 0) {
      v4 = GetGfxOffsetAdder(4u);
LABEL_20:
      v5 = 3;
      goto LABEL_21;
    }
    v0 = 3;
LABEL_12:
    v1 = GetGfxOffsetAdder(v0);
    player_anim_ctrl = 0;
    return kPlayerGfxTblOffsets[v1];
  }
  v0 = 5;
  if (!obj_yspeed.player)
    goto LABEL_12;
  v4 = GetGfxOffsetAdder(5u);
  v5 = 2;
LABEL_21:
  R0_ = v5;
  CurrentAnimOffset = GetCurrentAnimOffset(v4);
  if (!player_anim_timer) {
    player_anim_timer = player_anim_timer_set;
    v6 = player_anim_ctrl + 1;
    if ((uint8)(player_anim_ctrl + 1) >= R0_)
      v6 = 0;
    player_anim_ctrl = v6;
  }
  return CurrentAnimOffset;
}

uint8 GetCurrentAnimOffset(uint8 j) {
  return kPlayerGfxTblOffsets[j] + 8 * player_anim_ctrl;
}

uint8 GetGfxOffsetAdder(uint8 j) {
  if (player_size)
    j += 8;
  return j;
}

uint8 HandleChangeSize() {
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

void UNUSED_ChkForPlayerAttrib() {
  ;
}

void PlayerGfxProcessing_Sub_New() {
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

void RelativePlayerPosition() {
  RelWOfs(0, kRelPos_Player);
}

void RelativeBubblePosition(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = GetProperObjOffset(k, 1u);
  RelWOfs(ProperObjOffset, kRelPos_Bubble);
}

void RelativeFireballPosition(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = GetProperObjOffset(k, 0);
  RelWOfs(ProperObjOffset, kRelPos_Fireball);
}

void RelWOfs(uint8 k, uint8 j) {
  GetObjRelativePosition(k, j);
}

void RelativeMiscPosition(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = GetProperObjOffset(k, 2u);
  RelWOfs(ProperObjOffset, kRelPos_Misc);
}

uint8 RelativeEnemyPosition(uint8 k) {
  return VariableObjOfsRelPos(k, kRelPos_Enemy, 1u);
}

void RelativeBlockPosition(uint8 k) {
  VariableObjOfsRelPos(k, kRelPos_Block, 0xDu);
  VariableObjOfsRelPos(k + 2, 5u, 0xDu);
}

uint8 VariableObjOfsRelPos(uint8 k, uint8 j, uint8 a) {
  R0_ = k;
  return GetObjRelativePosition(k + a, j);
}

uint8 GetObjRelativePosition(uint8 k, uint8 j) {
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

void GetPlayerOffscreenBits() {
  GetOffScreenBitsSet(0, kRelPos_Player);
}

void GetFireballOffscreenBits(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = GetProperObjOffset(k, 0);
  GetOffScreenBitsSet(ProperObjOffset, kRelPos_Fireball);
}

void GetBubbleOffscreenBits(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = GetProperObjOffset(k, 1u);
  GetOffScreenBitsSet(ProperObjOffset, kRelPos_Bubble);
}

void GetMiscOffscreenBits(uint8 k) {
  uint8 ProperObjOffset;  // si

  ProperObjOffset = GetProperObjOffset(k, 2u);
  GetOffScreenBitsSet(ProperObjOffset, kRelPos_Misc);
}

uint8 GetProperObjOffset(uint8 k, uint8 j) {
  return kObjOffsetData[j] + k;
}

void GetEnemyOffscreenBits(uint8 k) {
  SetOffscrBitsOffset(k, 1u, kRelPos_Enemy);
}

void GetBlockOffscreenBits(uint8 k) {
  SetOffscrBitsOffset(k, 0xDu, kRelPos_Block);
}

void SetOffscrBitsOffset(uint8 k, uint8 a, uint8 j) {
  R0_ = k;
  GetOffScreenBitsSet(k + a, j);
}

void GetOffScreenBitsSet(uint8 k, uint8 j) {
  uint8 v2;  // al

  R0_ |= 16 * RunOffscrBitsSubs(k);
  v2 = R0_;
  *(&offscreen_bits.player + j) = R0_;
  *(&offscreen_bits_and1.player + j) = (v2 & 4) != 0;
  *(&offscreen_bits_shr1.player + j) = v2 >> 3;
}

uint8 RunOffscrBitsSubs(uint8 k) {
  uint8 i;       // di
  uint8 v2;      // al
  bool v3;       // cf
  uint8 v4;      // al
  uint8 v5;      // si
  uint8 result;  // al

  R0_ = GetXOffscreenBits(k) >> 4;
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
        v5 = DividePDiff(v5, i, 4u);
      }
    }
    result = kYOffscreenBitsData[v5];
    k = R4_;
    if (result)
      break;
  }
  return result;
}

uint8 GetXOffscreenBits(uint8 k) {
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
        v5 = DividePDiff(v5, i, 8u);
      }
    }
    result = kXOffscreenBitsData[v5];
    k = R4_;
    if (result)
      break;
  }
  return result;
}

uint8 DividePDiff(uint8 k, uint8 j, uint8 a) {
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

void GetEnemyXPos(uint8 k) {
  HIBYTE(xpos16) = obj_xpos_hi.enemy[k];
  LOBYTE(xpos16) = obj_xpos_lo.enemy[k];
}

void GetSomeXpos_(uint8 k) {
  xpos16 = xpos_new_var0E16;
}

void DrawLargePlatform_DrawOne(uint8 j) {
  R4_ = 6;
  some_xpos_0E12 = xpos16 - screen_left_xpos16;
  oam_tile_size_buffer[j + 256] = (uint16)(xpos16 - screen_left_xpos16) >> 8 != 0;
}

void CODE_03FEE5(uint8 j) {
  bool v1;  // al

  some_xpos_0E12 = xpos16 - screen_left_xpos16;
  v1 = (uint16)(xpos16 - screen_left_xpos16) >> 8 != 0;
  oam_tile_size_buffer[j + 272] = v1;
  oam_tile_size_buffer[j + 264] = v1;
  oam_tile_size_buffer[j + 256] = v1;
}

void Unused_CODE_03FF07(uint8 j) {
  bool v1;  // al

  some_xpos_0E12 = xpos16 - screen_left_xpos16;
  v1 = (uint16)(xpos16 - screen_left_xpos16) >> 8 != 0;
  oam_tile_size_buffer[j + 8] = v1;
  oam_tile_size_buffer[j] = v1;
}

void Unused_CODE_03FF26(uint8 j, uint8 a) {
  oam_tile_size_buffer[j] = a;
  oam_tile_size_buffer[j + 8] = a;
}

uint8 DrawLargePlatform_Next(uint8 j) {
  xpos16 += 8;
  return j + 4;
}

uint8 DrawOneSpriteRow_Sub(uint8 j) {
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
