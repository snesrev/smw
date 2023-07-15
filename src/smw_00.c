#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"

static FuncV *const kInitAndMainLoop_GameModePtrs[42] = {
    &GameMode00_LoadNintendoPresents,
    &GameMode01_ShowNintendoPresents,
    &GameModeXX_FadeInOrOut,
    &GameMode11_LoadSublevel_GameMode03Entry,
    &GameMode04_PrepareTitleScreen,
    &GameModeXX_FadeInOrOut,
    &GameMode06_CircleEffect,
    &GameMode07_TitleScreenDemo,
    &GameMode08_FileSelect,
    &GameMode09_EraseFile,
    &GameMode0A_PlayerSelect,
    &GameModeXX_FadeInOrOut,
    &GameMode0C_LoadOverworld,
    &GameModeXX_FadeInOrOut,
    &GameMode0E_ShowOverworld,
    &GameModeXX_FadeInOrOut_MosaicFade,
    &GameMode10_BufferLevelLoadMessage,
    &GameMode11_LoadSublevel_SA1Pack_OptimizeThisRoutine1,
    &GameMode12_PrepareLevel,
    &GameModeXX_FadeInOrOut_MosaicFade,
    &GameMode14_InLevel,
    &GameModeXX_FadeInOrOut,
    &GameMode16_LoadDeathMessage,
    &GameMode17_ShowDeathMessage,
    &GameModeXX_FadeInOrOut,
    &GameMode19_Cutscene,
    &GameModeXX_FadeInOrOut,
    &GameMode19_Cutscene_GameMode1BEntry,
    &GameModeXX_FadeInOrOut,
    &GameMode1D_LoadYoshisHouse,
    &GameModeXX_FadeInOrOut,
    &GameMode1D_LoadYoshisHouse_GameMode1FEntry,
    &GameModeXX_FadeInOrOut,
    &GameMode21_DelayEnemyRollcall,
    &GameModeXX_FadeInOrOut,
    &GameMode23_LoadEnemyRollcallScreen,
    &GameModeXX_FadeInOrOut,
    &GameMode25_ShowEnemyRollcallScreen,
    &GameModeXX_FadeInOrOut,
    &GameMode27_LoadTheEnd,
    &GameMode28_ShowTheEnd,
    &GameMode29_DoNothingOnTheEndScreen,
};
static FuncV *const kGenerateTile_TileGenerationPtr[27] = {
    &sub_C074,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile_SetItemMemory,
    &GenericPage01Tile_SetItemMemory,
    &EraseYoshiCoin,
    &ChangeNetDoorTiles,
    &ChangeNetDoorTiles,
    &EraseLargeSwitch,
};
static FuncV *const kGameMode14_InLevel_PlayerStatePtrs[14] = {
    &PlayerState00,
    &PlayerStateXX_PowerupAnims_PowerDownEntry,
    &PlayerStateXX_PowerupAnims_GrowAnimationEntry,
    &PlayerStateXX_PowerupAnims_GotCape,
    &PlayerStateXX_PowerupAnims_GotFlower,
    &PlayerStateXX_EnterPipe_Horizontal,
    &PlayerStateXX_EnterPipe_Vertical,
    &PlayerState07_ShootOutOfPipe,
    &PlayerState08_WarpToYoshiWingsBonus,
    &PlayerState09_Death,
    &PlayerState0A_NoYoshiCutscene,
    &PlayerState0B_RescuedPeach,
    &PlayerState0C_CastleDestructionMoves,
    &GameMode14_InLevel_Return00C592,
};

void Vector_Reset() {
  WriteReg(NMITIMEN, 0);
  WriteReg(HDMAEN, 0);
  WriteReg(MDMAEN, 0);
  WriteReg(APUI00, 0);
  WriteReg(APUI01, 0);
  WriteReg(APUI02, 0);
  WriteReg(APUI03, 0);
  WriteReg(INIDISP, 0x80);
  *(uint16 *)reset_sprites_y_function_in_ram = 0xf0a9;
  uint16 v0 = 381;
  int16 v1 = 0x3fd;
  do {
    *(uint16 *)&reset_sprites_y_function_in_ram[v0 + 2] = 141;
    *(uint16 *)&reset_sprites_y_function_in_ram[v0 + 3] = v1;
    v1 -= 4;
    v0 -= 3;
  } while ((v0 & 0x8000) == 0);
  reset_sprites_y_function_in_ram[386] = 107;
  HandleSPCUploads_UploadSPCEngine();
  misc_game_mode = 0;
  misc_intro_level_flag = 0;
  InitializeFirst8KBOfRAM();
  HandleSPCUploads_UploadSamples();
  SetupHDMAWindowingEffects();
  WriteReg(OBSEL, 3);
  ++waiting_for_vblank;
}

void RunOneFrameOfGame_Internal() {
  assert(waiting_for_vblank != 0);
  ++counter_global_frames;
  InitAndMainLoop_ProcessGameMode();
  waiting_for_vblank = 0;
}

void ResetSpritesFunc(int wh) {
  for (; wh < 128; wh++)
    g_ram[0x201 + wh * 4] = 0xf0;
}

void HandleSPCUploads_SPC700UploadLoop() {  // 008079
  int16 v1;

  uint16 v0 = 0;
  while (ReadRegWord(APUI00) != 0xBBAA)
    ;
  LOBYTE(v1) = -52;
  while (1) {
    uint8 *v9 = IndirPtr(&R0_W, v0);
    uint16 v10 = v0 + 2;
    int16 v4 = *(uint16 *)v9;
    uint8 *v11 = IndirPtr(&R0_W, v10);
    uint16 v12 = v10 + 2;
    WriteRegWord(APUI02, *(uint16 *)v11);
    WriteReg(APUI01, v4 != 0);
    WriteReg(APUI00, v1);
    while ((uint8)v1 != ReadReg(APUI00))
      ;
    if (Unreachable())
      break;
    uint8 *v2 = IndirPtr(&R0_, v12);
    v0 = v12 + 1;
    HIBYTE(v1) = *v2;
    for (LOBYTE(v1) = 0;; LOBYTE(v1) = v1 + 1) {
      WriteRegWord(APUI00, v1);
      if (!--v4)
        break;
      uint8 *v3 = IndirPtr(&R0_, v0++);
      HIBYTE(v1) = *v3;
      while ((uint8)v1 != ReadReg(APUI00))
        ;
    }
    uint8 Reg;
    bool v6;
    do {
      Reg = ReadReg(APUI00);
      v6 = (uint8)v1 >= Reg;
    } while ((uint8)v1 != Reg);
    do {
      bool v8 = v6;
      v6 = ((uint8)v6 + (uint8)v1 >= 256);
      int8 v7 = v8 + v1;
      v6 |= ((uint8)v7 + 3 >= 256);
      LOBYTE(v1) = v7 + 3;
    } while (!(uint8)v1);
  }
  WriteReg(APUI00, 0);
  WriteReg(APUI01, 0);
  WriteReg(APUI02, 0);
  WriteReg(APUI03, 0);
}

void HandleSPCUploads_UploadSPCEngine() {  // 0080e8
  R0_ = 0;
  R1_ = 0x80;
  R2_ = 14;
  HandleSPCUploads_UploadDataToSPC();
}

void HandleSPCUploads_UploadDataToSPC() {  // 0080f7
  // HandleSPCUploads_SPC700UploadLoop();
}

void HandleSPCUploads_UploadSamples() {  // 0080fd
  R0_ = 0;
  R1_ = 0x80;
  R2_ = 15;
  HandleSPCUploads_StrtSPCMscUpld();
}

void HandleSPCUploads_UploadOverworldMusicBank() {  // 00810e
  R0_ = -79;
  R1_ = -104;
  R2_ = 14;
  HandleSPCUploads_StrtSPCMscUpld();
}

void HandleSPCUploads_StrtSPCMscUpld() {  // 00811d
  WriteReg(APUI01, 0xFF);
  HandleSPCUploads_UploadDataToSPC();
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    WriteReg((SnesRegs)(i + APUI00), 0);
    *(&io_sound_ch1 + i) = 0;
    *(&unusedram_7e1dfd + i) = 0;
  }
}

void HandleSPCUploads_008134() {  // 008134
  if (flag_active_bonus_game || misc_intro_level_flag == 0xE9 ||
      !(flag_show_player_start | (uint8)(counter_sublevels_entered | misc_intro_level_flag))) {
    R0_ = -42;
    R1_ = -82;
    R2_ = 14;
    HandleSPCUploads_StrtSPCMscUpld();
  }
}

void HandleSPCUploads_UploadCreditsMusicBank() {  // 008159
  R0_ = 0;
  R1_ = -28;
  R2_ = 3;
  HandleSPCUploads_StrtSPCMscUpld();
}

void Vector_NMI() {
  uint8 v2;
  uint8 v3;
  ReadReg(RDNMI);
  uint8 v0 = io_music_ch1;
  if (io_music_ch1 || ReadReg(APUI02) == io_copy_of_music_ch1) {
    WriteReg(APUI02, v0);
    io_copy_of_music_ch1 = v0;
    io_music_ch1 = 0;
  }
  WriteReg(APUI00, io_sound_ch1);
  WriteReg(APUI01, io_sound_ch2);
  WriteReg(APUI03, io_sound_ch3);
  io_sound_ch1 = 0;
  io_sound_ch2 = 0;
  io_sound_ch3 = 0;
  WriteReg(INIDISP, 0x80);
  WriteReg(HDMAEN, 0);
  WriteReg(W12SEL, mirror_bg1_and2_window_mask_settings);
  WriteReg(W34SEL, mirror_bg3_and4_window_mask_settings);
  WriteReg(WOBJSEL, mirror_object_and_color_window_settings);
  WriteReg(CGWSEL, mirror_color_math_initial_settings);
  if ((misc_nmito_use_flag & 0x80) == 0) {
    WriteReg(CGADSUB, mirror_color_math_select_and_enable & 0xFB);
    WriteReg(BGMODE, 9);
    if (waiting_for_vblank) {
      if (misc_nmito_use_flag >> 1) {
LABEL_25:
        v2 = 0x81;
        if (misc_currently_active_boss_end_cutscene == 8) {
          WriteReg(INIDISP, mirror_screen_display_register);
          WriteReg(HDMAEN, mirror_hdmaenable);
          WriteReg(NMITIMEN, 0x81);
          WriteReg(BG3HOFS, mirror_layer3_xpos);
          WriteReg(BG3HOFS, HIBYTE(mirror_layer3_xpos));
          WriteReg(BG3VOFS, mirror_layer3_ypos);
          WriteReg(BG3VOFS, HIBYTE(mirror_layer3_ypos));
          WriteReg(BGMODE, mirror_bgmode_and_tile_size_setting);
          WriteReg(CGADSUB, mirror_color_math_select_and_enable);
          return;
        }
        goto LABEL_29;
      }
      goto LABEL_24;
    }
    ++waiting_for_vblank;
    UpdatePaletteFromIndexedTable();
    if (misc_nmito_use_flag >> 1) {
      if (pointer_current_overworld_process == 10 && (uint8)(ow_submap_switch_process - 2) < 4) {
        UploadOverworldLayer1And2Tilemaps(ow_submap_switch_process - 2);
LABEL_23:
        PollJoypadInputs();
LABEL_24:
        WriteReg(BG1HOFS, mirror_current_layer1_xpos);
        WriteReg(BG1HOFS, HIBYTE(mirror_current_layer1_xpos));
        uint16 voffs1;
        voffs1 = shaking_layer1_disp_y + mirror_current_layer1_ypos;
        WriteReg(BG1VOFS, voffs1);
        WriteReg(BG1VOFS, voffs1 >> 8);
        WriteReg(BG2HOFS, mirror_current_layer2_xpos);
        WriteReg(BG2HOFS, HIBYTE(mirror_current_layer2_xpos));
        WriteReg(BG2VOFS, mirror_current_layer2_ypos);
        WriteReg(BG2VOFS, HIBYTE(mirror_current_layer2_ypos));
        if (misc_nmito_use_flag)
          goto LABEL_25;
        v3 = 36;
LABEL_28:
        ReadReg(TIMEUP);
        WriteReg(VTIMEL, v3);
        WriteReg(VTIMEH, 0);
        flag_irqto_use = 0;
        v2 = 0xa1;
LABEL_29:
        WriteReg(NMITIMEN, v2);
        WriteReg(BG3HOFS, 0);
        WriteReg(BG3HOFS, 0);
        WriteReg(BG3VOFS, 0);
        WriteReg(BG3VOFS, 0);
        WriteReg(INIDISP, mirror_screen_display_register);
        WriteReg(HDMAEN, mirror_hdmaenable);
        return;
      }
      UploadOverworldExAnimationData();
      UploadPlayerGFX();
    } else {
      if (!(misc_nmito_use_flag & 1))
        UploadStatusBarTilemap();
      if (misc_currently_active_boss_end_cutscene == 8) {
        if (flag_update_credits_background)
          UpdateCreditsBackground();
        goto LABEL_17;
      }
      UploadLevelLayer1And2Tilemaps();
      if (!flag_upload_load_screen_letters_tovram) {
        UploadLevelExAnimationData();
LABEL_17:
        RestoreSP1AfterMarioStart();
        UploadPlayerGFX();
        goto LABEL_22;
      }
      UploadLoadingLettersTiles();
    }
LABEL_22:
    LoadStripeImage();
    UploadOAMBuffer();
    goto LABEL_23;
  }
  if (!waiting_for_vblank) {
    ++waiting_for_vblank;
    if (flag_upload_load_screen_letters_tovram) {
      UploadLoadingLettersTiles();
    } else {
      RestoreSP1AfterMarioStart();
      UploadPlayerGFX();
      if ((misc_nmito_use_flag & 0x40) != 0) {
        UploadMode7KoopaBossesAndLavaAnimation();
        if (misc_nmito_use_flag & 1)
          goto LABEL_36;
      }
    }
    UploadStatusBarTilemap();
LABEL_36:
    UpdatePaletteFromIndexedTable();
    LoadStripeImage();
    UploadOAMBuffer();
    PollJoypadInputs();
  }
  WriteReg(BGMODE, 9);
  uint16 m7x = mirror_m7_center_xpos + 0x80;
  WriteReg(M7X, m7x);
  WriteReg(M7X, m7x >> 8);
  uint16 m7y = mirror_m7_center_ypos + 0x80;
  WriteReg(M7Y, m7y);
  WriteReg(M7Y, m7y >> 8);
  WriteReg(M7A, mirror_m7_matrix_alo);
  WriteReg(M7A, mirror_m7_matrix_ahi);
  WriteReg(M7B, mirror_m7_matrix_blo);
  WriteReg(M7B, mirror_m7_matrix_bhi);
  WriteReg(M7C, mirror_m7_matrix_clo);
  WriteReg(M7C, mirror_m7_matrix_chi);
  WriteReg(M7D, mirror_m7_matrix_dlo);
  WriteReg(M7D, mirror_m7_matrix_dhi);
  SetMode7PPUPointersAndLayer1Scroll();
  if (!(misc_nmito_use_flag & 1)) {
    v3 = 36;
    if ((misc_nmito_use_flag & 0x40) != 0 && kPlayerState00_DATA_00F8E8[misc_currently_active_boss] == 42) {
      v3 = 45;
    }
    goto LABEL_28;
  }
  WriteReg(INIDISP, mirror_screen_display_register);
  WriteReg(HDMAEN, mirror_hdmaenable);
  WriteReg(NMITIMEN, 0x81);
  WriteReg(BGMODE, 7);
  WriteReg(BG1HOFS, mirror_m7_xpos);
  WriteReg(BG1HOFS, HIBYTE(mirror_m7_xpos));
  WriteReg(BG1VOFS, mirror_m7_ypos);
  WriteReg(BG1VOFS, HIBYTE(mirror_m7_ypos));
}

void Vector_IRQ() {
  if ((ReadReg(TIMEUP) & 0x80) == 0)
    return;
  uint8 v0 = 0x81;
  if ((misc_nmito_use_flag & 0x80) != 0) {
    if ((misc_nmito_use_flag & 0x40) != 0) {
      if (flag_irqto_use) {
        WriteReg(NMITIMEN, 0x81);
        SetMode7PPUPointersAndLayer1Scroll();
        goto LABEL_4;
      }
      ++flag_irqto_use;
      ReadReg(TIMEUP);
      WriteReg(VTIMEL, -82 - shaking_layer1_disp_y);
      WriteReg(VTIMEH, 0);
      v0 = 0xA1;
    }
    if (!timer_end_level || timer_level_end_fade < 0x40) {
      WriteReg(NMITIMEN, v0);
      WriteReg(BGMODE, 7);
      WriteReg(BG1HOFS, mirror_m7_xpos);
      WriteReg(BG1HOFS, HIBYTE(mirror_m7_xpos));
      WriteReg(BG1VOFS, mirror_m7_ypos);
      WriteReg(BG1VOFS, HIBYTE(mirror_m7_ypos));
      return;
    }
  }
  WriteReg(NMITIMEN, 0x81);
  WriteReg(BG3HOFS, mirror_layer3_xpos);
  WriteReg(BG3HOFS, HIBYTE(mirror_layer3_xpos));
  WriteReg(BG3VOFS, mirror_layer3_ypos);
  WriteReg(BG3VOFS, HIBYTE(mirror_layer3_ypos));
LABEL_4:
  WriteReg(BGMODE, mirror_bgmode_and_tile_size_setting);
  WriteReg(CGADSUB, mirror_color_math_select_and_enable);
}

void SetMode7PPUPointersAndLayer1Scroll() {  // 008416
  WriteReg(BG1SC, 0x59);
  WriteReg(BG12NBA, 7);
  WriteReg(BG1HOFS, mirror_current_layer1_xpos);
  WriteReg(BG1HOFS, HIBYTE(mirror_current_layer1_xpos));
  WriteReg(BG1VOFS, shaking_layer1_disp_y + mirror_current_layer1_ypos);
  WriteReg(BG1VOFS, HIBYTE(mirror_current_layer1_ypos));
}

void UploadOAMBuffer() {  // 008449
  WriteReg(DMAP0, 0);
  WriteRegWord(OAMADDL, 0);
  WriteRegWord(BBAD0, 4);
  WriteRegWord(A1T0H, 2);
  WriteRegWord(DAS0L, 0x220);
  WriteReg(MDMAEN, 1);
  WriteReg(OAMADDH, 0x80);
  WriteReg(OAMADDL, mirror_oamaddress_lo);
}

void CompressOamEntExt() {  // 008494
  for (uint8 i = 30; (i & 0x80) == 0; i -= 2) {
    uint8 v1 = kCompressOAMTileSizeBuffer_DATA_008475[i];
    oam_buf_ext[i] =
        sprites_oamtile_size_buffer[v1] | (4 * (sprites_oamtile_size_buffer[v1 + 1] |
                                                (4 * (sprites_oamtile_size_buffer[v1 + 2] | (4 * sprites_oamtile_size_buffer[v1 + 3])))));
    oam_buf_ext[i + 1] = sprites_oamtile_size_buffer[v1 + 4] |
                         (4 * (sprites_oamtile_size_buffer[v1 + 5] |
                               (4 * (sprites_oamtile_size_buffer[v1 + 6] | (4 * sprites_oamtile_size_buffer[v1 + 7])))));
  }
}

void LoadStripeImage() {  // 0085d2
  R0_ = *((uint8 *)&kLoadStripeImage_StripeImagePtrs[0].addr + graphics_stripe_image_to_upload);
  R1_ = *((uint8 *)&kLoadStripeImage_StripeImagePtrs[0].addr + graphics_stripe_image_to_upload + 1);
  R2_ = *(&kLoadStripeImage_StripeImagePtrs[0].bank + graphics_stripe_image_to_upload);
  LoadStripeImage_UploadToVRAM(R2_);
  if (!graphics_stripe_image_to_upload) {
    LOBYTE(stripe_image_upload) = graphics_stripe_image_to_upload;
    HIBYTE(stripe_image_upload) = graphics_stripe_image_to_upload;
    stripe_image_upload_data[0] = graphics_stripe_image_to_upload - 1;
  }
  graphics_stripe_image_to_upload = 0;
}

void ClearLayer3Tilemap() {  // 0085fa
  TurnOffIO();
  R0_ = -4;
  WriteReg(VMAIN, 0);
  WriteReg(VMADDL, 0);
  WriteReg(VMADDH, 0x50);
  for (uint8 i = 6; (i & 0x80) == 0; --i)
    WriteReg((SnesRegs)(i + 0x4310), kClearLayer3Tilemap_PARAMS_008649[i]);
  WriteReg(MDMAEN, 2);
  R0_ = 56;
  WriteReg(VMAIN, 0x80);
  WriteReg(VMADDL, 0);
  WriteReg(VMADDH, 0x50);
  for (uint8 j = 6; (j & 0x80) == 0; --j)
    WriteReg((SnesRegs)(j + 0x4310), kClearLayer3Tilemap_PARAMS_008649[j]);
  WriteReg(BBAD1, 0x19);
  WriteReg(MDMAEN, 2);
  mirror_oamaddress_lo = 0;
  ResetSpritesFunc(0);
  UploadOAMBuffer();
}

void PollJoypadInputs() {  // 008650
  io_controller_hold2_copyp1 = ReadReg(JOY1L) & 0xF0;
  io_controller_press2_copyp1 = io_controller_hold2_copyp1 & (io_p1_ctrl_disable_hi ^ io_controller_hold2_copyp1);
  io_p1_ctrl_disable_hi = io_controller_hold2_copyp1;
  io_controller_hold1_copyp1 = ReadReg(JOY1H);
  io_controller_press1_copyp1 = io_controller_hold1_copyp1 & (io_p1_ctrl_disable_lo ^ io_controller_hold1_copyp1);
  io_p1_ctrl_disable_lo = io_controller_hold1_copyp1;
  io_controller_hold2_copyp2 = ReadReg(JOY2L) & 0xF0;
  io_controller_press2_copyp2 = io_controller_hold2_copyp2 & (io_p2_ctrl_disable_hi ^ io_controller_hold2_copyp2);
  io_p2_ctrl_disable_hi = io_controller_hold2_copyp2;
  io_controller_hold1_copyp2 = ReadReg(JOY2H);
  io_controller_press1_copyp2 = io_controller_hold1_copyp2 & (io_p2_ctrl_disable_lo ^ io_controller_hold1_copyp2);
  io_p2_ctrl_disable_lo = io_controller_hold1_copyp2;
  uint8 v0 = io_controllers_plugged_in;
  if ((io_controllers_plugged_in & 0x80) != 0)
    v0 = player_current_character;
  io_controller_hold1 = *(&io_controller_hold1_copyp1 + v0) | *(&io_controller_hold2_copyp1 + v0) & 0xC0;
  io_controller_hold2 = *(&io_controller_hold2_copyp1 + v0);
  io_controller_press1 = *(&io_controller_press1_copyp1 + v0) | *(&io_controller_press2_copyp1 + v0) & 0x40;
  io_controller_press2 = *(&io_controller_press2_copyp1 + v0);
}

void GameMode14_InLevel_0086C7() {  // 0086c7
  for (int16 i = 98; i >= 0; i -= 2)
    *(uint16 *)&sprites_oamtile_size_buffer[(uint16)i] = 514;
  ResetSpritesFunc(100);
}

void LoadStripeImage_UploadToVRAM(uint8 a) {  // 00871e
  int16 v5;

  WriteReg(A1B1, a);
  uint16 v1 = 0;
  while (1) {
    uint8 *v2 = IndirPtr(&R0_, v1);
    if ((*v2 & 0x80) != 0)
      break;
    R4_ = *v2;
    v1 = v1 + 1;
    R3_ = *IndirPtr(&R0_, v1++);
    R7_ = __CFSHL__(*IndirPtr(&R0_, v1), 1);
    WriteReg(BBAD1, 0x18);
    R5_ = (uint8)(*IndirPtr(&R0_, v1) & 0x40) >> 3;
    R6_ = 0;
    WriteReg(DMAP1, R5_ | 1);
    WriteRegWord(VMADDL, *(uint16 *)&R3_);
    uint8 *v4 = IndirPtr(&R0_W, v1);
    LOBYTE(v5) = HIBYTE(*(uint16 *)v4);
    HIBYTE(v5) = *(uint16 *)v4;
    uint16 v6 = (v5 & 0x3FFF) + 1;
    v1 = v1 + 2;
    WriteRegWord(A1T1L, R0_W + v1);
    WriteRegWord(DAS1L, v6);
    if (*(uint16 *)&R5_) {
      WriteReg(VMAIN, R7_);
      WriteReg(MDMAEN, 2);
      WriteReg(BBAD1, 0x19);
      WriteRegWord(VMADDL, *(uint16 *)&R3_);
      WriteRegWord(A1T1L, R0_W + v1 + 1);
      WriteRegWord(DAS1L, v6);
      v6 = 2;
    }
    *(uint16 *)&R3_ = v6;
    v1 = v6 + v1;
    WriteReg(VMAIN, R7_ | 0x80);
    WriteReg(MDMAEN, 2);
  }
}

void UploadLevelLayer1And2Tilemaps() {  // 0087ad
  if ((uint8)blocks_layer1_vramupload_address) {
    if ((misc_level_layout_flags & 1) != 0) {
      WriteReg(VMAIN, 0x80);
      WriteReg(VMADDL, HIBYTE(blocks_layer1_vramupload_address));
      WriteReg(VMADDH, blocks_layer1_vramupload_address);
      for (uint8 i = 6; (i & 0x80) == 0; --i)
        WriteReg((SnesRegs)(i + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A16[i]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x80);
      WriteReg(VMADDL, HIBYTE(blocks_layer1_vramupload_address));
      WriteReg(VMADDH, blocks_layer1_vramupload_address + 4);
      for (uint8 j = 6; (j & 0x80) == 0; --j)
        WriteReg((SnesRegs)(j + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A1D[j]);
      WriteReg(DAS1L, 0x40);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x80);
      WriteReg(VMADDL, HIBYTE(blocks_layer1_vramupload_address) + 32);
      WriteReg(VMADDH, blocks_layer1_vramupload_address);
      for (uint8 k = 6; (k & 0x80) == 0; --k)
        WriteReg((SnesRegs)(k + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A24[k]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x80);
      WriteReg(VMADDL, HIBYTE(blocks_layer1_vramupload_address) + 32);
      WriteReg(VMADDH, blocks_layer1_vramupload_address + 4);
      for (uint8 m = 6; (m & 0x80) == 0; --m)
        WriteReg((SnesRegs)(m + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A2B[m]);
      WriteReg(DAS1L, 0x40);
      WriteReg(MDMAEN, 2);
    } else {
      WriteReg(VMAIN, 0x81);
      WriteReg(VMADDL, HIBYTE(blocks_layer1_vramupload_address));
      WriteReg(VMADDH, blocks_layer1_vramupload_address);
      for (uint8 n = 6; (n & 0x80) == 0; --n)
        WriteReg((SnesRegs)(n + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A16[n]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x81);
      WriteReg(VMADDL, HIBYTE(blocks_layer1_vramupload_address));
      WriteReg(VMADDH, blocks_layer1_vramupload_address + 8);
      for (uint8 ii = 6; (ii & 0x80) == 0; --ii)
        WriteReg((SnesRegs)(ii + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A1D[ii]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x81);
      WriteReg(VMADDL, HIBYTE(blocks_layer1_vramupload_address) + 1);
      WriteReg(VMADDH, blocks_layer1_vramupload_address);
      for (uint8 jj = 6; (jj & 0x80) == 0; --jj)
        WriteReg((SnesRegs)(jj + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A24[jj]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x81);
      WriteReg(VMADDL, HIBYTE(blocks_layer1_vramupload_address) + 1);
      WriteReg(VMADDH, blocks_layer1_vramupload_address + 8);
      for (uint8 kk = 6; (kk & 0x80) == 0; --kk)
        WriteReg((SnesRegs)(kk + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A2B[kk]);
      WriteReg(MDMAEN, 2);
    }
  }
  LOBYTE(blocks_layer1_vramupload_address) = 0;
  if ((uint8)blocks_layer2_vramupload_address) {
    if ((misc_level_layout_flags & 2) != 0) {
      WriteReg(VMAIN, 0x80);
      WriteReg(VMADDL, HIBYTE(blocks_layer2_vramupload_address));
      WriteReg(VMADDH, blocks_layer2_vramupload_address);
      for (uint8 mm = 6; (mm & 0x80) == 0; --mm)
        WriteReg((SnesRegs)(mm + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A32[mm]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x80);
      WriteReg(VMADDL, HIBYTE(blocks_layer2_vramupload_address));
      WriteReg(VMADDH, blocks_layer2_vramupload_address + 4);
      for (uint8 nn = 6; (nn & 0x80) == 0; --nn)
        WriteReg((SnesRegs)(nn + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A39[nn]);
      WriteReg(DAS1L, 0x40);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x80);
      WriteReg(VMADDL, HIBYTE(blocks_layer2_vramupload_address) + 32);
      WriteReg(VMADDH, blocks_layer2_vramupload_address);
      for (uint8 i1 = 6; (i1 & 0x80) == 0; --i1)
        WriteReg((SnesRegs)(i1 + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A40[i1]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x80);
      WriteReg(VMADDL, HIBYTE(blocks_layer2_vramupload_address) + 32);
      WriteReg(VMADDH, blocks_layer2_vramupload_address + 4);
      for (uint8 i2 = 6; (i2 & 0x80) == 0; --i2)
        WriteReg((SnesRegs)(i2 + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A47[i2]);
      WriteReg(DAS1L, 0x40);
      WriteReg(MDMAEN, 2);
    } else {
      WriteReg(VMAIN, 0x81);
      WriteReg(VMADDL, HIBYTE(blocks_layer2_vramupload_address));
      WriteReg(VMADDH, blocks_layer2_vramupload_address);
      for (uint8 i3 = 6; (i3 & 0x80) == 0; --i3)
        WriteReg((SnesRegs)(i3 + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A32[i3]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x81);
      WriteReg(VMADDL, HIBYTE(blocks_layer2_vramupload_address));
      WriteReg(VMADDH, blocks_layer2_vramupload_address + 8);
      for (uint8 i4 = 6; (i4 & 0x80) == 0; --i4)
        WriteReg((SnesRegs)(i4 + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A39[i4]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x81);
      WriteReg(VMADDL, HIBYTE(blocks_layer2_vramupload_address) + 1);
      WriteReg(VMADDH, blocks_layer2_vramupload_address);
      for (uint8 i5 = 6; (i5 & 0x80) == 0; --i5)
        WriteReg((SnesRegs)(i5 + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A40[i5]);
      WriteReg(MDMAEN, 2);
      WriteReg(VMAIN, 0x81);
      WriteReg(VMADDL, HIBYTE(blocks_layer2_vramupload_address) + 1);
      WriteReg(VMADDH, blocks_layer2_vramupload_address + 8);
      for (uint8 i6 = 6; (i6 & 0x80) == 0; --i6)
        WriteReg((SnesRegs)(i6 + 0x4310), kUploadLevelLayer1And2Tilemaps_PARAMS_008A47[i6]);
      WriteReg(MDMAEN, 2);
    }
  }
  LOBYTE(blocks_layer2_vramupload_address) = 0;
}

void InitializeFirst8KBOfRAM() {  // 008a4e
  uint16 v0 = 0x1ffe;
  do {
    *(uint16 *)((int8 *)&R0_W + v0) = 0;
    do
      v0 -= 2;
    while ((int16)(v0 - 511) < 0 && (int16)(v0 - 256) >= 0);
  } while (v0 != 0xFFFE);
  stripe_image_upload = 0;
  *(uint16 *)&palettes_dynamic_palette_upload_index = 0;
  stripe_image_upload_data[0] = -1;
}

void SetStandardPPUSettings() {  // 008a79
  WriteReg(SETINI, 0);
  WriteReg(MOSAIC, 0);
  WriteReg(BG1SC, 0x23);
  WriteReg(BG2SC, 0x33);
  WriteReg(BG3SC, 0x53);
  WriteReg(BG12NBA, 0);
  WriteReg(BG34NBA, 4);
  mirror_bg1_and2_window_mask_settings = 0;
  mirror_bg3_and4_window_mask_settings = 0;
  mirror_object_and_color_window_settings = 0;
  WriteReg(WBGLOG, 0);
  WriteReg(WOBJLOG, 0);
  WriteReg(TMW, 0);
  WriteReg(TSW, 0);
  mirror_color_math_initial_settings = 2;
  WriteReg(M7SEL, 0x80);
}

void ManipulateMode7Image() {  // 008acd
  R0_ = HIBYTE(misc_m7_angle);
  ManipulateMode7Image_008AE8();
  R0_W = misc_m7_angle;
  *(uint16 *)&mirror_m7_matrix_dlo = *(uint16 *)&mirror_m7_matrix_alo;
  *(uint16 *)&mirror_m7_matrix_clo = -*(uint16 *)&mirror_m7_matrix_blo;
  ManipulateMode7Image_008AE8();
}

void ManipulateMode7Image_008AE8() {  // 008ae8
  uint16 v0 = 2 * ((misc_m7_rotation >> 7) & 3);
  int16 v2 = kManipulateMode7Image_DATA_008ABC[v0 >> 1] + (kManipulateMode7Image_DATA_008AB4[v0 >> 1] ^ (uint8)(2 * misc_m7_rotation));
  int16 v1 = v2;
  v2 = ManipulateMode7Image_008B2B(v2);
  if (v0 >= 4)
    v2 = -v2;
  *(uint16 *)&mirror_m7_matrix_blo = v2;
  int16 v3 = ((v1 ^ 0xFE) + 2) & 0x1FF;
  v3 = ManipulateMode7Image_008B2B(v3);
  if ((uint16)(v0 - 2) < 4)
    v3 = -v3;
  *(uint16 *)&mirror_m7_matrix_alo = v3;
}

uint16 ManipulateMode7Image_008B2B(uint16 k) {  // 008b2b
  uint16 v2;

  uint8 v1 = *((uint8 *)kManipulateMode7Image_DATA_008B57 + k + 1);
  if (v1)
    v1 = R0_;
  R1_ = v1;
  WriteReg(WRMPYA, *((uint8 *)kManipulateMode7Image_DATA_008B57 + k));
  WriteReg(WRMPYB, R0_);
  HIBYTE(v2) = R1_ + ReadReg(RDMPYH);
  LOBYTE(v2) = ReadReg(RDMPYL);
  return v2 >> 5;
}

void InitializeStatusBarTilemap() {  // 008cff
  WriteReg(VMAIN, 0x80);
  WriteReg(VMADDL, 0x2E);
  WriteReg(VMADDH, 0x50);
  for (uint8 i = 6; (i & 0x80) == 0; --i)
    WriteReg((SnesRegs)(i + 0x4310), kInitializeStatusBarTilemap_PARAMS_008D90[i]);
  WriteReg(MDMAEN, 2);
  WriteReg(VMAIN, 0x80);
  WriteReg(VMADDL, 0x42);
  WriteReg(VMADDH, 0x50);
  for (uint8 j = 6; (j & 0x80) == 0; --j)
    WriteReg((SnesRegs)(j + 0x4310), kInitializeStatusBarTilemap_PARAMS_008D97[j]);
  WriteReg(MDMAEN, 2);
  WriteReg(VMAIN, 0x80);
  WriteReg(VMADDL, 0x63);
  WriteReg(VMADDH, 0x50);
  for (uint8 k = 6; (k & 0x80) == 0; --k)
    WriteReg((SnesRegs)(k + 0x4310), kInitializeStatusBarTilemap_PARAMS_008D9E[k]);
  WriteReg(MDMAEN, 2);
  WriteReg(VMAIN, 0x80);
  WriteReg(VMADDL, 0x8E);
  WriteReg(VMADDH, 0x50);
  for (uint8 m = 6; (m & 0x80) == 0; --m)
    WriteReg((SnesRegs)(m + 0x4310), kInitializeStatusBarTilemap_PARAMS_008DA5[m]);
  WriteReg(MDMAEN, 2);
  int8 v4 = 54;
  uint8 v5 = 108;
  do {
    misc_status_bar_tilemap[(uint8)v4] = kStatusBarTilemap_SecondRow[v5];
    v5 -= 2;
    --v4;
  } while (v4 >= 0);
  misc_status_bar_tilemap[55] = 40;
}

void UploadStatusBarTilemap() {  // 008dac
  WriteReg(VMAIN, 0);
  WriteReg(VMADDL, 0x42);
  WriteReg(VMADDH, 0x50);
  for (uint8 i = 6; (i & 0x80) == 0; --i)
    WriteReg((SnesRegs)(i + 0x4310), kUploadStatusBarTilemap_PARAMS_StBr1[i]);
  WriteReg(MDMAEN, 2);
  WriteReg(VMAIN, 0);
  WriteReg(VMADDL, 0x63);
  WriteReg(VMADDH, 0x50);
  for (uint8 j = 6; (j & 0x80) == 0; --j)
    WriteReg((SnesRegs)(j + 0x4310), kUploadStatusBarTilemap_PARAMS_StBr2[j]);
  WriteReg(MDMAEN, 2);
}

void UpdateStatusBarCounters() {  // 008e1a
  if (!(flag_sprites_locked | timer_end_level) && misc_nmito_use_flag != 0xC1 && (--misc_status_bar_tilemap[55] & 0x80) != 0) {
    misc_status_bar_tilemap[55] = 40;
    if (counter_timer_ones | (uint8)(counter_timer_tens | counter_timer_hundreds)) {
      for (uint8 i = 2; (i & 0x80) == 0; --i) {
        if ((--*(&counter_timer_hundreds + i) & 0x80) == 0)
          break;
        *(&counter_timer_hundreds + i) = 9;
      }
      if (!counter_timer_hundreds && (counter_timer_ones & counter_timer_tens) == 9)
        io_sound_ch1 = -1;
      if (!(counter_timer_ones | (uint8)(counter_timer_tens | counter_timer_hundreds)))
        DamagePlayer_Kill();
    }
  }
  misc_status_bar_tilemap[44] = counter_timer_hundreds;
  misc_status_bar_tilemap[45] = counter_timer_tens;
  misc_status_bar_tilemap[46] = counter_timer_ones;
  uint8 v2 = 16;
  for (uint8 j = 0; j != 2; ++j) {
    if (*(&counter_timer_hundreds + j))
      break;
    misc_status_bar_tilemap[v2++ + 28] = -4;
  }
  for (uint8 k = 3; (k & 0x80) == 0; k -= 3) {
    R0_ = *(&player_mario_score_hi + k);
    R1_ = 0;
    if (__PAIR32__(R0_W, *(uint16 *)(&player_mario_score_lo + k)) >= 0xF423F) {
      *(&player_mario_score_hi + k) = 15;
      *(&player_mario_score_mid + k) = 66;
      *(&player_mario_score_lo + k) = 63;
    }
  }
  R0_ = player_mario_score_hi;
  R1_ = 0;
  R3_ = player_mario_score_mid;
  R2_ = player_mario_score_lo;
  UpdateStatusBarCounters_Loop2(0x14, 0);
  for (uint8 m = 0; m != 6; ++m) {
    if (misc_status_bar_tilemap[m + 48])
      break;
    misc_status_bar_tilemap[m + 48] = -4;
  }
  if (player_current_character) {
    R0_ = player_luigi_score_hi;
    R1_ = 0;
    R3_ = player_luigi_score_mid;
    R2_ = player_luigi_score_lo;
    UpdateStatusBarCounters_Loop2(0x14, 0);
    for (uint8 n = 0; n != 6; ++n) {
      if (misc_status_bar_tilemap[n + 48])
        break;
      misc_status_bar_tilemap[n + 48] = -4;
    }
  }
  if (counter_coin_handler) {
    --counter_coin_handler;
    if (++player_current_coin_count >= 0x64) {
      ++misc_1up_handler;
      player_current_coin_count -= 100;
    }
  }
  if ((int8)player_current_life_count >= 98)
    player_current_life_count = 98;
  PairU16 v7 = HexToDec(player_current_life_count + 1);
  uint8 second = v7.second;
  if (!LOBYTE(v7.second))
    second = -4;
  misc_status_bar_tilemap[29] = second;
  misc_status_bar_tilemap[30] = v7.first;
  if (*(&player_mario_bonus_stars + player_current_character) >= 0x64) {
    flag_active_bonus_game = -1;
    *(&player_mario_bonus_stars + player_current_character) -= 100;
  }
  PairU16 v9 = HexToDec(player_current_coin_count);
  uint8 v10 = v9.second;
  if (!LOBYTE(v9.second))
    v10 = -4;
  misc_status_bar_tilemap[27] = v9.first;
  misc_status_bar_tilemap[26] = v10;
  R0_ = 0;
  R1_ = 0;
  R3_ = 0;
  R2_ = *(&player_mario_bonus_stars + player_current_character);
  UpdateStatusBarCounters_009051(9, 0x10);
  uint8 ii;
  for (ii = 0; ii != 1; ++ii) {
    if (misc_status_bar_tilemap[ii + 37])
      break;
    misc_status_bar_tilemap[ii + 37] = -4;
    misc_status_bar_tilemap[ii + 10] = -4;
  }
  do {
    uint8 v12 = 2 * misc_status_bar_tilemap[ii + 37];
    misc_status_bar_tilemap[ii + 10] = kUpdateStatusBarCounters_BonusStarCounterNumberTiles[v12];
    misc_status_bar_tilemap[ii++ + 37] = kUpdateStatusBarCounters_BonusStarCounterNumberTiles[v12 + 1];
  } while (ii != 2);
  UpdateStatusBarCounters_DrawItemBoxItem();
  if (player_current_character) {
    for (uint8 jj = 4; (jj & 0x80) == 0; --jj)
      misc_status_bar_tilemap[jj] = kUpdateStatusBarCounters_DATA_008DF5[jj];
  }
  uint8 v14 = counter_yoshi_coins_to_display;
  if (counter_yoshi_coins_to_display >= 5)
    v14 = 0;
  R0_ = v14 - 1;
  for (uint8 kk = 0; kk != 4; ++kk) {
    uint8 v16 = -4;
    if ((R0_ & 0x80) == 0)
      v16 = 46;
    misc_status_bar_tilemap[kk + 6] = v16;
    --R0_;
  }
}

void UpdateStatusBarCounters_Loop2(uint8 k, uint8 j) {  // 009012
  do {
    for (misc_status_bar_tilemap[k + 28] = 0;; ++misc_status_bar_tilemap[k + 28]) {
      int v2 = j >> 1;
      bool v3 = R2_W >= kUpdateStatusBarCounters_DATA_008FFA[v2 + 1];
      R6_W = R2_W - kUpdateStatusBarCounters_DATA_008FFA[v2 + 1];
      uint16 v4 = !v3 + kUpdateStatusBarCounters_DATA_008FFA[v2];
      R4_W = R0_W - v4;
      if (R0_W < v4)
        break;
      R2_W = R6_W;
      R0_W = R4_W;
    }
    ++k;
    j += 4;
  } while (j != 24);
}

PairU16 HexToDec(uint8 a) {  // 009045
  uint8 v1 = 0;
  while (a >= 0xA) {
    a -= (a < 0xA) + 10;
    ++v1;
  }
  return MakePairU16_AX(a, v1);
}

void UpdateStatusBarCounters_009051(uint8 k, uint8 j) {  // 009051
  do {
    for (misc_status_bar_tilemap[k + 28] = 0;; ++misc_status_bar_tilemap[k + 28]) {
      int v2 = j >> 1;
      bool v3 = R2_W >= kUpdateStatusBarCounters_DATA_008FFA[v2 + 1];
      R6_W = R2_W - kUpdateStatusBarCounters_DATA_008FFA[v2 + 1];
      if (!v3)
        break;
      R2_W = R6_W;
    }
    ++k;
    j += 4;
  } while (j != 24);
}

void UpdateStatusBarCounters_DrawItemBoxItem() {  // 009079
  uint8 v0 = -32;
  if ((misc_nmito_use_flag & 0x40) != 0) {
    v0 = 0;
    if (misc_nmito_use_flag != 0xC1)
      get_OamEnt(oam_buf, 0)->ypos = -16;
  }
  R1_ = v0;
  if (player_current_item_box) {
    R0_ = kUpdateStatusBarCounters_ItemBoxItemProperties[player_current_item_box - 1];
    if (player_current_item_box == 3)
      R0_ = kUpdateStatusBarCounters_StarPaletteFrames[(counter_global_frames >> 1) & 3];
    uint8 v1 = R1_;
    OamEnt *oam = get_OamEnt(oam_buf, R1_);
    oam->xpos = 120;
    oam->ypos = 15;
    oam->flags = R0_ | 0x30;
    oam->charnum = kUpdateStatusBarCounters_ItemBoxItemTile[player_current_item_box - 1];
    sprites_oamtile_size_buffer[v1 >> 2] = 2;
  }
}

void GameMode12_PrepareLevel_00919B() {  // 00919b
  if (player_current_state == 10) {
    GameMode14_InLevel_HandlePlayerState();
  } else if (!counter_sublevels_entered) {
    counter_green_star_block = 30;
  }
}

void DrawLoadingLetters() {  // 0091b1
  BufferLoadingLetterTiles();
  uint8 v0 = 0;
  uint8 v1 = -80;
  if (flag_active_bonus_game) {
    counter_timer_hundreds = 0;
    counter_timer_tens = 0;
    counter_timer_ones = 0;
    v0 = 38;
    v1 = -92;
  }
  R0_ = v1;
  R1_ = 0;
  uint8 v2 = 112;
  do {
    DrawLoadingLetters_Draw(v0++, v2);
    if (v0 == 8 && player_current_character)
      v0 = 14;
    v2 -= 8;
  } while (v2);
  CompressOamEntExt();
}

void DrawLoadingLetters_Draw(uint8 k, uint8 j) {  // 0091e9
  OamEnt *oam = get_OamEnt(oam_buf, j);
  oam[66].flags = kDrawLoadingLetters_TileData_TopProp[k];
  oam[67].flags = kDrawLoadingLetters_TileData_BottomProp[k];
  uint8 v3 = R0_;
  oam[66].xpos = R0_;
  oam[67].xpos = v3;
  R0_ = v3 - 8;
  if (v3 < 8)
    --R1_;
  uint8 v4 = j >> 2;
  uint8 v5 = R1_ & 1;
  sprites_oamtile_size_buffer[v4 + 66] = R1_ & 1;
  sprites_oamtile_size_buffer[v4 + 67] = v5;
  int8 v6 = kDrawLoadingLetters_TileData[k];
  if (v6 >= 0) {
    OamEnt *v7 = get_OamEnt(oam_buf, j);
    v7[66].charnum = v6;
    v7[67].charnum = kDrawLoadingLetters_TileData_BottomTiles[k];
    v7[66].ypos = 104;
    v7[67].ypos = 112;
  }
}

void UpdateEntirePalette() {  // 00922f
  palettes_palette_mirror[0] = 0;
  WriteReg(CGADD, 0);
  for (uint8 i = 6; (i & 0x80) == 0; --i)
    WriteReg((SnesRegs)(i + DMAP2), kUpdateEntirePalette_PARAMS_009249[i]);
  WriteReg(MDMAEN, 4);
}

void SetupHDMAWindowingEffects() {  // 009250
  for (uint8 i = 4; (i & 0x80) == 0; --i)
    WriteReg((SnesRegs)(i + DMAP7), kSetupHDMAWindowingEffects_PARAMS_009277[i]);
  WriteReg(DAS70, 0);
  SetupHDMAWindowingEffects_EndHDMA();
}

void SetupHDMAWindowingEffects_EndHDMA() {  // 009260
  mirror_hdmaenable = 0;
  SetupHDMAWindowingEffects_ClearWindowTable();
}

void SetupHDMAWindowingEffects_ClearWindowTable() {  // 009263
  for (uint16 i = 446; (i & 0x8000) == 0; i -= 2) {
    misc_hdmawindow_effect_table[i] = -1;
    misc_hdmawindow_effect_table[i + 1] = 0;
  }
}

void sub_9291(uint16 k) {  // 009291
  do {
    misc_hdmawindow_effect_table[k] = 0;
    misc_hdmawindow_effect_table[k + 1] = -1;
    k += 2;
  } while (k < 0x1C0);
  SetupHDMAWindowingEffects_0092A0();
}

void SetupHDMAWindowingEffects_0092A0() {  // 0092a0
  mirror_hdmaenable = 0x80;
}

void SetupHDMAWindowingEffects_0092A8() {  // 0092a8
  SetupHDMAWindowingEffects_ClearWindowTable();
  sub_9291(0x198);
}

void SetEnemyRollcallParallaxHDMA_Init() {  // 0092b2
  misc_hdmawindow_effect_table[0] = 88;
  misc_hdmawindow_effect_table[10] = 88;
  misc_hdmawindow_effect_table[20] = 88;
  misc_hdmawindow_effect_table[9] = 0;
  misc_hdmawindow_effect_table[19] = 0;
  misc_hdmawindow_effect_table[29] = 0;
  for (uint8 i = 4; (i & 0x80) == 0; --i) {
    WriteReg((SnesRegs)(i + 0x4350), kSetEnemyRollcallParallaxHDMA_PARAMS_009313[i]);
    WriteReg((SnesRegs)(i + 0x4360), kSetEnemyRollcallParallaxHDMA_PARAMS_009318[i]);
    WriteReg((SnesRegs)(i + 0x4370), kSetEnemyRollcallParallaxHDMA_PARAMS_00931D[i]);
  }
  WriteReg(DAS50, 0);
  WriteReg(DAS60, 0);
  WriteReg(DAS70, 0);
  mirror_hdmaenable = -32;
  SetEnemyRollcallParallaxHDMA();
}

void SetEnemyRollcallParallaxHDMA() {  // 0092ed
  int16 v0 = 8;
  uint16 v1 = 20;
  do {
    int16 v2 = *(uint16 *)((int8 *)&mirror_current_layer1_xpos + (uint16)v0);
    *(uint16 *)&misc_hdmawindow_effect_table[v1 + 1] = v2;
    *(uint16 *)&misc_hdmawindow_effect_table[v1 + 4] = v2;
    *(uint16 *)&misc_hdmawindow_effect_table[v1 + 7] = get_PointU16(misc_layer1_pos, v0)->x;
    v1 -= 10;
    v0 -= 4;
  } while (v0 >= 0);
}

void InitAndMainLoop_ProcessGameMode() {  // 009322
  kInitAndMainLoop_GameModePtrs[misc_game_mode]();
}

void TurnOffIO() {  // 00937d
  WriteReg(NMITIMEN, 0);
  WriteReg(HDMAEN, 0);
  WriteReg(INIDISP, 0x80);
}

void GameMode00_LoadNintendoPresents() {  // 009391
  ClearLayer3Tilemap();
  SetStandardPPUSettings();
  UploadGraphicsFiles_Layer3();
  uint8 v0 = 12;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, v0);
    oam->xpos = kGameMode00_LoadNintendoPresents_XDisp[i];
    oam->ypos = 112;
    oam->charnum = kGameMode00_LoadNintendoPresents_Tiles[i];
    oam->flags = 48;
    v0 -= 4;
  }
  oam_buf_ext[0] = -86;
  io_sound_ch3 = 1;
  timer_title_screen_input_timer = 64;
  GameMode00_LoadNintendoPresents_0093CA();
}

void GameMode00_LoadNintendoPresents_0093CA() {  // 0093ca
  mirror_screen_display_register = 15;
  misc_mosaic_direction = 1;
  misc_sprite_palette_setting = 0;
  BufferPalettesRoutines_Levels();
  palettes_background_color = 0;
  UpdateEntirePalette();
  misc_blinking_cursor_pos = 0;
  GameMode00_LoadNintendoPresents_0093EA(0x10, 4);
}

void GameMode00_LoadNintendoPresents_0093EA(uint8 k, uint8 j) {  // 0093ea
  misc_nmito_use_flag = 1;
  SetVisibleLayers(0x20, k, j);
  GameMode00_LoadNintendoPresents_0093F4();
}

void GameMode00_LoadNintendoPresents_0093F4() {  // 0093f4
  ++misc_game_mode;
  GameMode00_LoadNintendoPresents_Mode04Finish();
}

void GameMode00_LoadNintendoPresents_Mode04Finish() {  // 0093f7
  WriteReg(NMITIMEN, 0x81);
}

void SetVisibleLayers(uint8 a, uint8 k, uint8 j) {  // 0093fd
  WriteReg(CGADSUB, a);
  mirror_color_math_select_and_enable = a;
  WriteReg(TM, k);
  WriteReg(TS, j);
  WriteReg(TMW, 0);
  WriteReg(TSW, 0);
}

void GameMode01_ShowNintendoPresents() {  // 00940f
  if (!--timer_title_screen_input_timer) {
    GraphicsDecompressionRoutines_DecompressGFX32And33();
    GameMode01_ShowNintendoPresents_009417();
  }
}

void GameMode01_ShowNintendoPresents_009417() {  // 009417
  ++misc_game_mode;
}

void GameMode01_ShowNintendoPresents_Return00941A() {  // 00941a
  ;
}

void GameMode06_CircleEffect() {  // 00941b
  CheckWhichControllersArePluggedIn();
  if (GameMode07_TitleScreenDemo_009CBE()) {
    GameMode06_CircleEffect_009440(0xEC);
    ++misc_game_mode;
    GameMode07_TitleScreenDemo_InitializeFileSelect();
  } else if (!--timer_title_screen_input_timer) {
    ++timer_title_screen_input_timer;
    if ((uint8)(timer_hdmawindow_scaling_factor + 4) < 0xF0)
      GameMode06_CircleEffect_009440(timer_hdmawindow_scaling_factor + 4);
    else
      GameMode01_ShowNintendoPresents_009417();
  }
}

void GameMode06_CircleEffect_009440(uint8 a) {  // 009440
  timer_hdmawindow_scaling_factor = a;
  GameMode06_CircleEffect_009443();
}

void GameMode06_CircleEffect_009443() {  // 009443
  UpdateHDMAWindowBuffer_SetCircleHDMAPointer();
  R0_ = 0x80;
  R1_ = 112;
  UpdateHDMAWindowBuffer_KeyholeEntry(0x70);
}

void GameMode19_Cutscene() {  // 009468
  ClearLayer3Tilemap();
  ClearOverworldAndCutsceneRAM();
  SetStandardPPUSettings();
  misc_level_tileset_setting = 24;
  graphics_level_sprite_graphics_setting = 20;
  misc_background_color_setting = kGameMode19_Cutscene_SkyColorSetting[misc_currently_active_boss_end_cutscene - 1];
  misc_bgpalette_setting = kGameMode19_Cutscene_BGPaletteSetting[misc_currently_active_boss_end_cutscene - 1];
  misc_sprite_palette_setting = 0;
  misc_fgpalette_setting = 1;
  if (misc_currently_active_boss_end_cutscene == 8) {
    UploadBigLayer3LettersToVRAM();
    graphics_stripe_image_to_upload = -46;
    LoadStripeImage();
    HandleSPCUploads_UploadCreditsMusicBank();
    BufferCreditsBackgrounds();
    SetupHDMAWindowingEffects_EndHDMA();
    ++misc_level_tileset_setting;
    ++graphics_level_sprite_graphics_setting;
  } else {
    io_music_ch1 = 21;
    graphics_stripe_image_to_upload = kGameMode19_Cutscene_BGToUse[misc_currently_active_boss_end_cutscene - 1];
    LoadStripeImage();
    graphics_stripe_image_to_upload = -49;
    LoadStripeImage();
    player_xpos = 144;
    player_ypos = 88;
    ++player_carrying_something_flag2;
  }
  UploadGraphicsFiles();
  BufferPalettesRoutines_Levels();
  UpdateEntirePalette();
  for (int8 i = 11; i >= 0; --i)
    *((uint8 *)&mirror_current_layer1_xpos + (uint8)i) = 0;
  sprites_tile_priority = 32;
  InitializeLevelRAM();
  player_facing_direction = 0;
  player_in_air_flag = 0;
  SetPlayerPose();
  GameMode23_LoadEnemyRollcallScreen_009622(0x17, 0);
  GameMode19_Cutscene_GameMode1BEntry();
}

void GameMode19_Cutscene_GameMode1BEntry() {  // 0094fd
  ResetSpritesFunc(0);
  if (misc_currently_active_boss_end_cutscene == 8) {
    GameMode1B_EndingCinema_Bank0C();
  } else {
    GameMode19_Cutscene_0CC97E();
    uint16 v1 = mirror_current_layer1_xpos;
    uint16 v0 = mirror_current_layer1_ypos;
    mirror_current_layer1_xpos = mirror_current_layer2_xpos;
    mirror_current_layer1_ypos = mirror_current_layer2_ypos;
    PlayerDraw();
    mirror_current_layer1_ypos = v0;
    mirror_current_layer1_xpos = v1;
    player_current_state = 12;
    GameMode14_InLevel_00C47E();
  }
  CompressOamEntExt();
}

void UploadBigLayer3LettersToVRAM() {  // 00955e
  GraphicsDecompressionRoutines(0x2F);
  WriteReg(VMAIN, 0x80);
  WriteRegWord(VMADDL, 0x4600);
  int16 v0 = 512;
  do {
    uint8 *v1 = IndirPtr(&R0_W, 0);
    WriteRegWord(VMDATAL, *(uint16 *)v1);
    ++R0_W;
    ++R0_W;
    --v0;
  } while (v0);
}

void GameMode1D_LoadYoshisHouse() {  // 009583
  ++misc_currently_active_boss_end_cutscene;
  GameMode11_LoadSublevel_0096CF(1, 0x28);
  --misc_game_mode;
  graphics_level_sprite_graphics_setting = 22;
  GameMode12_PrepareLevel();
  --misc_game_mode;
  TurnOffIO();
  ClearLayer3Tilemap();
  UploadGraphicsFiles_Layer3();
  GameMode1D_LoadYoshisHouse_InitializeYoshisHouseSceneRAM();
  GameMode23_LoadEnemyRollcallScreen_00961E();
  GameMode1D_LoadYoshisHouse_GameMode1FEntry();
}

void GameMode1D_LoadYoshisHouse_GameMode1FEntry() {  // 0095ab
  ResetSpritesFunc(0);
  GameMode1D_LoadYoshisHouse_Bank0C();
  ++counter_local_frames;
  HandleLevelTileAnimations();
  CompressOamEntExt();
}

void GameMode21_DelayEnemyRollcall() {  // 0095bc
  GameMode21_DelayEnemyRollcall_Bank03();
}

void GameMode23_LoadEnemyRollcallScreen() {  // 0095c1
  ClearLayer3Tilemap();
  ClearOverworldAndCutsceneRAM();
  SetStandardPPUSettings();
  GetLayer1And2PointersForEnemyRollcall();
  LoadSublevel();
  if (counter_enemy_rollcall_screen == 10) {
    graphics_level_sprite_graphics_setting = 19;
  } else if (counter_enemy_rollcall_screen == 12) {
    graphics_level_sprite_graphics_setting = 23;
  }
  UploadGraphicsFiles();
  BufferPalettesRoutines_Levels();
  InitializeLevelLayer1And2Tilemaps();
  InitializeLevelTileAnimations();
  InitializeEnemyRollcallLayerPositions();
  if (counter_enemy_rollcall_screen == 12) {
    for (uint8 i = 11; (i & 0x80) == 0; --i) {
      *((uint8 *)&palettes_palette_mirror[130] + i) = *((uint8 *)kGlobalPalettes_BowserEnd + i);
      *((uint8 *)&palettes_palette_mirror[146] + i) = *((uint8 *)kGlobalPalettes_B3CC + i);
    }
  }
  UpdateEntirePalette();
  SetEnemyRollcallParallaxHDMA_Init();
  LoadStripeImage();
  GameMode25_ShowEnemyRollcallScreen();
  GameMode23_LoadEnemyRollcallScreen_00961E();
}

void GameMode23_LoadEnemyRollcallScreen_00961E() {  // 00961e
  GameMode23_LoadEnemyRollcallScreen_009622(0x15, 2);
}

void GameMode23_LoadEnemyRollcallScreen_009622(uint8 k, uint8 j) {  // 009622
  SetKeepGameModeActiveTimer_OneFrame();
  mirror_bgmode_and_tile_size_setting = 9;
  GameMode00_LoadNintendoPresents_0093EA(k, j);
}

void GameMode25_ShowEnemyRollcallScreen() {  // 00962c
  player_number_of_tiles_to_update = 0;
  SetEnemyRollcallParallaxHDMA();
  ResetSpritesFunc(0);
  GameMode25_ShowEnemyRollcallScreen_Bank0C();
  CompressOamEntExt();
}

void GameMode27_LoadTheEnd() {  // 00963d
  ClearLayer3Tilemap();
  ClearOverworldAndCutsceneRAM();
  SetStandardPPUSettings();
  UploadBigLayer3LettersToVRAM();
  graphics_level_sprite_graphics_setting = 25;
  misc_background_color_setting = 3;
  misc_bgpalette_setting = 3;
  UploadGraphicsFiles();
  BufferPalettesRoutines_Levels();
  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    *((uint8 *)&palettes_palette_mirror[210] + i) = *((uint8 *)kGlobalPalettes_EndingLuigi + i);
    *((uint8 *)&palettes_palette_mirror[226] + i) = *((uint8 *)kGlobalPalettes_EndingMario + i);
    *((uint8 *)&palettes_palette_mirror[242] + i) = *((uint8 *)kGlobalPalettes_EndingToadstool + i);
  }
  UpdateEntirePalette();
  graphics_stripe_image_to_upload = -43;
  LoadStripeImage();
  DrawingTheEndMarioLuigiAndPeach();
  CompressOamEntExt();
  GameMode23_LoadEnemyRollcallScreen_009622(0x14, 0);
}

void GameMode29_DoNothingOnTheEndScreen() {  // 00968d
  ;
}

void GameMode10_BufferLevelLoadMessage() {  // 00968e
  ClearLayer3Tilemap();
  if (flag_active_bonus_game || !(misc_intro_level_flag | (uint8)(flag_show_player_start | counter_sublevels_entered)) &&
                                    (uint8)ow_tile_player_is_standing_on != 86) {
    DrawLoadingLetters();
  }
  GameMode00_LoadNintendoPresents_0093CA();
}

void GameMode11_LoadSublevel_GameMode03Entry() {  // 0096ae
  WriteReg(NMITIMEN, 0);
  InitializeFirst8KBOfRAM();
  for (int8 i = 7; i >= 0; --i)
    misc_currently_loaded_sprite_graphics_files[(uint8)i] = -1;
  if (!misc_intro_level_flag) {
    HandleSPCUploads_UploadOverworldMusicBank();
    io_music_ch1 = 1;
  }
  GameMode11_LoadSublevel_0096CF(0, 0xEB);
}

void GameMode11_LoadSublevel_0096CF(uint8 j, uint8 a) {  // 0096cf
  misc_intro_level_flag = a;
  ow_players_map[0] = j;
  GameMode11_LoadSublevel_SA1Pack_OptimizeThisRoutine1();
}

void GameMode11_LoadSublevel_SA1Pack_OptimizeThisRoutine1() {  // 0096d5
  WriteReg(NMITIMEN, 0);
  DamagePlayer_DisableButtons();
  if (!counter_sublevels_entered && flag_show_player_start)
    LoadOverworldLayer1AndEvents();
  flag_disable_layer3_scroll = 0;
  pointer_current_overworld_process = 0;
  timer_wait_before_score_tally = 80;
  SpecifySublevelToLoad();
  for (uint8 i = 7; (i & 0x80) == 0; --i)
    LOBYTE(get_PointU16(misc_layer1_pos, i)->x) = *((uint8 *)&mirror_current_layer1_xpos + i);
  HandleSPCUploads_008134();
  InitializeLevelRAM();
  camera_last_screen_horiz = 32;
  GameMode11_LoadSublevel_00A796();
  ++flag_scroll_up_to_player;
  HandleStandardLevelCameraScroll();
  LoadSublevel();
  if (misc_intro_level_flag) {
    if (misc_intro_level_flag != 0xE9)
      goto LABEL_14;
    misc_music_register_backup = 19;
  }
  uint8 v1 = misc_music_register_backup;
  if (misc_music_register_backup < 0x40) {
    if (misc_nmito_use_flag == 0xC1)
      v1 = 22;
    io_music_ch1 = v1;
  }
  misc_music_register_backup = v1 & 0xBF;
LABEL_14:
  mirror_screen_display_register = 0;
  misc_mosaic_direction = 0;
  ++misc_game_mode;
  GameMode00_LoadNintendoPresents_Mode04Finish();
}

PairU16 OwPrompt03_OverworldLifeExchanger_00974C(uint8 a) {  // 00974c
  PairU16 v1 = HexToDec(a);
  return MakePairU16_AX(LOBYTE(v1.first), LOBYTE(v1.second));
}

void GameMode16_LoadDeathMessage() {  // 009750
  ClearLayer3Tilemap();
  BufferLoadingLetterTiles();
  GameMode00_LoadNintendoPresents_0093CA();
}

void GameMode17_ShowDeathMessage() {  // 009759
  ResetSpritesFunc(0);
  uint8 v0 = timer_display_death_message_animation;
  if (timer_display_death_message_animation) {
    v0 = timer_display_death_message_animation - 4;
  } else if (!--timer_time_to_display_death_message) {
    if ((player_current_life_count & 0x80) != 0) {
      yoshi_carry_over_levels_flag = 0;
      if (((players_lives[1] | players_lives[0]) & 0x80) != 0) {
        for (uint8 i = 12; (i & 0x80) == 0; --i) {
          flag_collected5_yoshi_coins[i] = 0;
          *(&R6_ + i) = 0;
          flag_collected_moons[i] = 0;
        }
        ++flag_show_continue_and_end;
      }
    }
    GameMode0A_PlayerSelect_009E62();
    return;
  }
  timer_display_death_message_animation = v0;
  R0_ = v0 - 96;
  R1_ = 2 * R1_ + (v0 >= 0x60);
  uint8 v2 = misc_death_message_to_display;
  uint8 v3 = 72;
  do {
    if (v3 == 40) {
      R0_ = 120 - timer_display_death_message_animation;
      R1_ = (2 * (120 - timer_display_death_message_animation) + (timer_display_death_message_animation <= 0x78)) ^ 1;
    }
    DrawLoadingLetters_Draw(v2++, v3);
    v3 -= 8;
  } while (v3);
  CompressOamEntExt();
}

void GameMode12_PrepareLevel_PrepareMode7Level() {  // 0097bc
  uint8 v0;

  mirror_screen_display_register = 15;
  mirror_mosaic_size_and_bgenable = 0;
  GameModeXX_FadeInOrOut_GMMosaic();
  misc_m7_angle = 0x2020;
  LOBYTE(shaking_layer1_disp_y) = 0;
  ClearLayer3Tilemap();
  misc_level_tileset_setting = -1;
  GameMode12_PrepareLevel_UploadTiltingPlatformTilemap();
  if ((misc_nmito_use_flag & 0x40) == 0) {
    BufferPalettesRoutines_IggyLarryPlatform();
    SetupHDMAWindowingEffects_0092A8();
    GameMode12_PrepareLevel_009A3D(0x50);
    player_xpos = 80;
    player_ypos = -48;
    mirror_current_layer1_xpos = 0;
    PointU16 *pt = get_PointU16(misc_layer1_pos, 0);
    pt->x = 0;
    mirror_current_layer1_ypos = -112;
    pt->y = -112;
    mirror_m7_center_xpos = 128;
    mirror_m7_center_ypos = 80;
    mirror_m7_xpos = 128;
    mirror_m7_ypos = 16;
    goto LABEL_8;
  }
  GameMode12_PrepareLevel_PrepareNonIggyLarryRoom();
  if (misc_currently_active_boss < 3) {
    player_current_layer_priority = 3;
    mirror_oamaddress_lo = 0xc8;
    v0 = 18;
    goto LABEL_6;
  }
  if (misc_currently_active_boss != 3) {
LABEL_8:
    v0 = 19;
    goto LABEL_9;
  }
  v0 = 24;
LABEL_6:
  --misc_level_tileset_setting;
LABEL_9:
  graphics_level_sprite_graphics_setting = v0;
  UploadGraphicsFiles();
  WriteReg(TMW, 0x11);
  WriteReg(TS, 0);
  WriteReg(TSW, 0);
  mirror_bg1_and2_window_mask_settings = 2;
  mirror_object_and_color_window_settings = 50;
  mirror_color_math_initial_settings = 32;
  InitializeStatusBarTilemap();
  ManipulateMode7Image();
  GameMode12_PrepareLevel_009860();
}

void GameMode12_PrepareLevel_009860() {  // 009860
  PlayerDraw();
  UpdateCurrentPlayerPositionRAM();
  GameMode14_InLevel_HandlePlayerState();
  player_yspeed = 0;
  ProcessNormalSprites();
  ResetSpritesFunc(0);
}

void GameMode14_InLevel_InMode7Level() {  // 00987d
  ManipulateMode7Image();
  if ((misc_nmito_use_flag & 0x40) != 0) {
    if (misc_nmito_use_flag & 1 ||
        (HandleStandardLevelCameraScroll(), HandleScrollSpriteAndLayer3Scrolling(), misc_currently_active_boss == 4)) {
      ResetSpritesFunc(0);
    } else {
      GameMode14_InLevel_0086C7();
      GameMode14_InLevel_02827D();
    }
  } else {
    ResetSpritesFunc(0);
    GameMode14_InLevel_03C0C6();
  }
}

void UploadMode7KoopaBossesAndLavaAnimation() {  // 0098a9
  int8 v0 = misc_nmito_use_flag & 1;
  if (!(misc_nmito_use_flag & 1)) {
    uint8 v1 = (counter_local_frames >> 2) & 6;
    WriteReg(VMAIN, 0x80);
    WriteRegWord(DMAP2, 0x1801);
    WriteRegWord(VMADDL, 0x7800);
    WriteRegWord(A1T2L, kLevelTileAnimations_FrameData_Local1_Frame5[v1 >> 1]);
    WriteReg(A1B2, 0x7E);
    WriteRegWord(DAS2L, 0x80);
    WriteReg(MDMAEN, 4);
    v0 = 0;
  }
  uint16 v2 = 4;
  uint8 v3 = 6;
  if (v0) {
    v2 = 8;
    v3 = 22;
  }
  R0_W = v2;
  R2_W = 0xc680;
  WriteRegWord(VMAIN, 0);
  WriteRegWord(DMAP2, 0x1800);
  WriteReg(A1B2, 0x7E);
  do {
    WriteRegWord(VMADDL, kUploadMode7KoopaBossesAndLavaAnimation_VRAMAddressToUpload[v3 >> 1]);
    uint16 v4 = R2_W;
    WriteRegWord(A1T2L, R2_W);
    R2_W = R0_W + v4;
    WriteRegWord(DAS2L, R0_W);
    WriteReg(MDMAEN, 4);
    v3 -= 2;
  } while ((v3 & 0x80) == 0);
}

void GameMode12_PrepareLevel_PrepareNonIggyLarryRoom() {  // 009925
  int16 v7;
  int16 v10;

  HIBYTE(player_ypos) = 0;
  player_xpos = 32;
  mirror_current_layer1_xpos = 0;
  PointU16 *pt = get_PointU16(misc_layer1_pos, 0);
  pt->x = 0;
  mirror_current_layer1_ypos = 0;
  pt->y = 0;
  mirror_m7_center_xpos = 128;
  mirror_m7_center_ypos = 160;
  BufferPalettesRoutines_ReznorAndMode7KoopaBosses();
  ProcessNormalSprites();
  uint8 v1 = -64;
  int8 v2 = -96;
  if (misc_nmito_use_flag & 1) {
    flag_layer1_horiz_scroll_level_setting = 0;
  } else {
    uint16 v3 = 704;
    int16 v4 = kPlayerState00_DATA_00F8E8[misc_currently_active_boss];
    if (v4 < 0)
      v3 = 0xfb80;
    if (v4 == 18)
      v3 = 800;
    R0_W = v3;
    uint16 v5 = 0;
    int16 v6 = 0xc05a;
    do {
      *(uint16 *)&stripe_image_upload_data[v5] = v6;
      int8 v8 = v6;
      LOBYTE(v7) = HIBYTE(v6);
      HIBYTE(v7) = v8;
      v7 += 128;
      uint8 v9 = v7;
      LOBYTE(v7) = HIBYTE(v7);
      HIBYTE(v7) = v9;
      *(uint16 *)&stripe_image_upload_data[v5 + 132] = v7;
      v10 = __PAIR16__(v7, v9) - R0_W;
      int8 v11 = v10;
      LOBYTE(v10) = HIBYTE(v10);
      HIBYTE(v10) = v11;
      *(uint16 *)&stripe_image_upload_data[v5 + 264] = v10;
      *(uint16 *)&stripe_image_upload_data[v5 + 2] = 0x7f00;
      *(uint16 *)&stripe_image_upload_data[v5 + 134] = 0x7f00;
      *(uint16 *)&stripe_image_upload_data[v5 + 266] = 0x7f00;
      int16 v12 = 16;
      do {
        *(uint16 *)&stripe_image_upload_data[v5 + 4] = 0x38a2;
        *(uint16 *)&stripe_image_upload_data[v5 + 6] = 0x38a3;
        *(uint16 *)&stripe_image_upload_data[v5 + 68] = 0x38b2;
        *(uint16 *)&stripe_image_upload_data[v5 + 70] = 0x38b3;
        *(uint16 *)&stripe_image_upload_data[v5 + 136] = 0x2c80;
        *(uint16 *)&stripe_image_upload_data[v5 + 138] = 0x2c81;
        *(uint16 *)&stripe_image_upload_data[v5 + 200] = 0x2c82;
        *(uint16 *)&stripe_image_upload_data[v5 + 202] = 0x2c83;
        *(uint16 *)&stripe_image_upload_data[v5 + 268] = 0x28a0;
        *(uint16 *)&stripe_image_upload_data[v5 + 270] = 0x28a1;
        *(uint16 *)&stripe_image_upload_data[v5 + 332] = 0x28b0;
        *(uint16 *)&stripe_image_upload_data[v5 + 334] = 0x28b1;
        v5 += 4;
        --v12;
      } while (v12);
      v5 += 332;
      v6 = 0xc05e;
    } while (v5 < 0x318);
    *(uint16 *)&stripe_image_upload_data[v5] = 255;
    LoadStripeImage();
    v1 = -80;
    v2 = -112;
  }
  LOBYTE(player_ypos) = v2;
  GameMode12_PrepareLevel_009A1F(v1);
  SetupHDMAWindowingEffects_ClearWindowTable();
  if (misc_nmito_use_flag & 1)
    SetupHDMAWindowingEffects_0092A0();
  else
    sub_9291(0x1BE);
}

void GameMode12_PrepareLevel_009A1F(uint8 k) {  // 009a1f
  int8 v1 = 16;
  do {
    blocks_map16_table_lo[k] = 50;
    blocks_map16_table_lo[k + 432] = 50;
    blocks_map16_table_hi[k] = 50;
    blocks_map16_table_hi[k++ + 432] = 50;
    --v1;
  } while (v1);
  if (k == 0xC0)
    GameMode12_PrepareLevel_009A3D(0xD0);
}

void GameMode12_PrepareLevel_009A3D(uint8 k) {  // 009a3d
  int8 v1 = 16;
  do {
    blocks_map16_table_lo[k] = 5;
    blocks_map16_table_lo[k++ + 432] = 5;
    --v1;
  } while (v1);
}

void CheckWhichControllersArePluggedIn() {  // 009a74
  uint8 v1 = ReadReg(JOYA);
  uint8 Reg = ReadReg(JOYB);
  uint8 v2 = (2 * Reg + v1) & 3;
  if (v2) {
    if (v2 == 3)
      v2 = -125;
    --v2;
  }
  io_controllers_plugged_in = v2;
}

void GameMode04_PrepareTitleScreen() {  // 009a8b
  CheckWhichControllersArePluggedIn();
  GameMode12_PrepareLevel();
  counter_timer_hundreds = 0;
  ClearLayer3Tilemap();
  graphics_stripe_image_to_upload = 3;
  LoadStripeImage();
  BufferPalettesRoutines_TitleScreen();
  UpdateEntirePalette();
  LoadOverworldSprites();
  misc_nmito_use_flag = 1;
  mirror_bg1_and2_window_mask_settings = 51;
  mirror_bg3_and4_window_mask_settings = 0;
  mirror_object_and_color_window_settings = 35;
  mirror_color_math_initial_settings = 18;
  GameMode06_CircleEffect_009443();
  timer_title_screen_input_timer = 16;
  GameMode00_LoadNintendoPresents_Mode04Finish();
}

uint8 HandleMenuCursor_Main_ReturnsTwice(uint8 j) {  // 009ad0
  ++counter_blinking_cursor_frame;
  HandleMenuCursor_009E82(j);
  uint8 result = misc_blinking_cursor_pos;
  if ((io_controller_press1 & 0x90) != 0 || (io_controller_press2 & 0x80) != 0) {
    io_sound_ch3 = 1;
    misc_blinking_cursor_pos = 0;
    return result;
  } else {
    uint8 what = (io_controller_press1 | ((io_controller_press1 & 0x20) >> 3)) & 0xC;
    if (what != 0) {
      io_sound_ch3 = 6;
      counter_blinking_cursor_frame = 0;
      uint8 v2 = misc_blinking_cursor_pos + kHandleMenuCursor_DATA_009AC8[(what >> 2) - 1];
      if ((int8)v2 < 0)
        v2 = temp8a - 1;
      if (v2 >= temp8a)
        misc_blinking_cursor_pos = 0;
      else
        misc_blinking_cursor_pos = v2;
    }
    return 0xff;
  }
}

void GameMode09_EraseFile() {  // 009b1a
  uint8 v0;
  uint16 v3;

  FileSelectColorMath(0x39C9, 0x60);
  if (((io_controller_press2 | io_controller_press1) & 0x40) != 0) {
    Gamemode_9_A_Common();
  } else {
    if ((v0 = HandleMenuCursor_Main_ReturnsTwice(8)) == 0xff)
      return;
    if (v0 == 3) {
      for (uint8 i = 2; (i & 0x80) == 0; --i) {
        int8 v2 = misc_which_file_to_erase & 1;
        misc_which_file_to_erase >>= 1;
        if (v2) {
          uint8 v6 = i;
          HIBYTE(v3) = kSaveFileLocations_Hi[i];
          LOBYTE(v3) = kSaveFileLocations_Lo[i];
          uint16 v4 = v3;
          int16 v5 = 143;
          do {
            g_sram[v4] = 0;
            g_sram[v4++ + 429] = 0;
            --v5;
          } while (v5);
          i = v6;
        }
      }
      RtlWriteSram();
      GameMode07_TitleScreenDemo_FadeOutToTitleScreen();
    } else {
      misc_blinking_cursor_pos = v0;
      misc_which_file_to_erase |= kGameMode09_EraseFile_DATA_009B17[v0];
      R5_ = misc_which_file_to_erase;
      BufferFileSelectText_Entry3(0);
    }
  }
}

void Gamemode_9_A_Common() {  // 009b2c
  --misc_game_mode;
  --misc_game_mode;
  misc_blinking_cursor_pos = 0;
  GameMode07_TitleScreenDemo_InitializeSaveData();
}

void DisplayingContinueEnd(uint8 a) {  // 009b88
  uint8 t;

  int8 v1 = a - 1;
  if (v1) {
    if (v1 == 1) {
      if ((t = HandleMenuCursor_Main_ReturnsTwice(0)) == 0xff)
        return;
      if (t)
        GameMode07_TitleScreenDemo_FadeOutToTitleScreen();
      else
        GameMode0A_PlayerSelect_Entry2();
    } else {
      Unreachable();
    }
  } else {
    GameMode08_FileSelect_SetStripeImage(0xC);
    ++flag_show_continue_and_end;
  }
}

void OwPrompt07_DisplayingSavePrompt() {  // 009bb0
  uint8 t;
  if ((t = HandleMenuCursor_Main_ReturnsTwice(6)) == 0xff)
    return;
  if (!t) {
    io_sound_ch3 = 0;
    io_sound_ch1 = 5;
    SaveGame();
  }
  CloseOwPrompt();
}

void SaveGame() {  // 009bc9
  uint16 v0 = PAIR16(kSaveFileLocations_Hi[misc_current_save_file], kSaveFileLocations_Lo[misc_current_save_file]);
  for (int k = v0; ; k += 288) {
    uint16 j = 0;
    WORD(temp8a) = 0;
    do {
      uint8 v3 = ow_save_buffer[j];
      g_sram[k++] = v3;
      WORD(temp8a) += v3;
    } while (++j < 0x8D);
    WORD(g_sram[k]) = 0x5a5a - *(uint16 *)&temp8a;
    if (k >= 0x1ad)
      break;
  }
  RtlWriteSram();
}

void CloseOwPrompt() {  // 009c13
  ++pointer_display_overworld_prompt;
  ++flag_message_window_size_change_direction;
  GameMode08_FileSelect_SetStripeImage(0x1B);
}

void GameMode07_TitleScreenDemo() {  // 009c64
  CheckWhichControllersArePluggedIn();
  if (GameMode07_TitleScreenDemo_009CBE()) {
    GameMode07_TitleScreenDemo_InitializeFileSelect();
  } else {
    DamagePlayer_DisableButtons();
    uint8 v0 = misc_title_screen_movement_data_index;
    if (!--timer_title_screen_input_timer) {
      timer_title_screen_input_timer = kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[misc_title_screen_movement_data_index + 1];
      v0 = misc_title_screen_movement_data_index + 2;
      misc_title_screen_movement_data_index += 2;
    }
    if (kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[v0 - 2] == 0xFF) {
      GameMode07_TitleScreenDemo_FadeOutToTitleScreen();
    } else {
      uint8 v1 = kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[v0 - 2] & 0xDF;
      io_controller_hold1 = v1;
      if (v1 == kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[v0 - 2])
        v1 &= 0x9F;
      io_controller_press1 = v1;
      GameMode14_InLevel();
    }
  }
}

void GameMode07_TitleScreenDemo_FadeOutToTitleScreen() {  // 009c89
  misc_game_mode = 2;
}

void GameMode07_TitleScreenDemo_InitializeFileSelect() {  // 009c9f
  ResetSpritesFunc(0);
  WriteReg(TM, 4);
  WriteReg(TS, 0x13);
  
  // Ensure the black thing goes away at the intro
  WriteReg(WH0, 0);
  WriteReg(WH1, 0xff);

  mirror_hdmaenable = 0;
  GameMode07_TitleScreenDemo_InitializeSaveData();
}

void GameMode07_TitleScreenDemo_InitializeSaveData() {  // 009cb0
  misc_intro_level_flag = -23;
  InitializeSaveData();
  BufferFileSelectText();
  GameMode01_ShowNintendoPresents_009417();
}

uint8 GameMode07_TitleScreenDemo_009CBE() {  // 009cbe
  bool v0 = (io_controller_hold2 & 0xC0) == 0;
  if ((io_controller_hold2 & 0xC0) == 0)
    v0 = (io_controller_hold1 & 0xF0) == 0;
  return !v0;
}

void GameMode08_FileSelect() {  // 009cd1
  uint8 v0;

  FileSelectColorMath(0x7393, 0x20);
  CheckWhichControllersArePluggedIn();
  if ((v0 = HandleMenuCursor_Main_ReturnsTwice(2)) == 0xff)
    return;

  ++*(uint16 *)&misc_game_mode;
  if (v0 == 3) {
    misc_which_file_to_erase = 0;
    R5_ = 0;
    BufferFileSelectText_Entry3(0);
  } else {
    misc_current_save_file = v0;
    PairU16 v1 = BufferFileSelectText_009DB5(v0);
    uint16 first = v1.first;
    uint16 second = v1.second;
    if (first != 0xffff) {
      uint16 v6 = first;
      misc_intro_level_flag = 0;
      R0_ = -113;
      do {
        g_sram[second++] = g_sram[first++];
        --R0_;
      } while (R0_);
      uint16 v4 = v6;
      for (uint16 i = 0; i < 0x8D; ++i)
        ow_save_buffer[i] = g_sram[v4++];

      RtlWriteSram();
    }
    ++misc_game_mode;
    GameMode08_FileSelect_SetStripeImage(0x12);
  }
}

void GameMode08_FileSelect_SetStripeImage(uint8 j) {  // 009d29
  graphics_stripe_image_to_upload = j;
  HandleMenuCursor_009ED4(0);
}

void FileSelectColorMath(uint16 a, uint8 j) {  // 009d30
  palettes_background_color = a;
  mirror_color_math_select_and_enable = j;
}

void BufferFileSelectText() {  // 009d38
  R5_ = 0;
  BufferFileSelectText_Entry3(0xCB);
}

void BufferFileSelectText_Entry3(uint8 k) {  // 009d3c
  uint16 kk = k;

  int16 v1 = k;
  for (uint16 i = 0; i != 204; ++i) {
    stripe_image_upload_data[i] = kFileSelectText_EraseFile[kk];
    kk = kk + 1;
  }
  R0_ = -124;
  uint8 v3 = 2;
  do {
    R4_ = v3;
    int8 v4 = R5_ & 1;
    R5_ >>= 1;
    if (!v4) {
      uint16 first = BufferFileSelectText_009DB5(v3).first;
      if (first != 0xffff) {
        uint8 v7, second;
        if (g_sram[first + 140] < 0x60) {
          PairU16 v8 = HexToDec(g_sram[first + 140]);
          v7 = v8.first;
          second = v8.second;
        } else {
          second = -121;
          v7 = -120;
        }
        uint8 v9 = R0_;
        stripe_image_upload_data[R0_ + 4] = v7;
        if (!second)
          second = -4;
        stripe_image_upload_data[v9 + 2] = second;
        stripe_image_upload_data[v9 + 3] = 56;
        stripe_image_upload_data[v9 + 5] = 56;
        int8 v10 = 3;
        do {
          *(uint16 *)&stripe_image_upload_data[v9 + 6] = 0x38fc;
          v9 += 2;
          --v10;
        } while (v10);
      }
    }
    R0_ -= 36;
    v3 = R4_ - 1;
  } while ((int8)(R4_ - 1) >= 0);
}

PairU16 BufferFileSelectText_009DB5(uint8 k) {  // 009db5
  uint16 v1;

  HIBYTE(v1) = kSaveFileLocations_Hi[k];
  LOBYTE(v1) = kSaveFileLocations_Lo[k];
  uint16 v2 = v1;
  uint16 i = v1 + 429;
  for (;;) {
    uint16 v9 = v2;
    uint16 v8 = i;
    WORD(temp8a) = *(uint16 *)&g_sram[v2 + 141];
    uint16 v4 = 141;
    do {
      WORD(temp8a) += g_sram[v2++];
    } while (--v4);

    if (WORD(temp8a) == 0x5A5A)
      return MakePairU16(v9, v8);
    if (v9 >= 428)
      return MakePairU16(v9 == 428 ? v9 : 0xffff, v8);
    v2 = v8;
    i = v9;
  }
}

void GameMode0A_PlayerSelect() {  // 009dfa
  uint8 t;
  if (((io_controller_press2 | io_controller_press1) & 0x40) != 0) {
    --misc_game_mode;
    Gamemode_9_A_Common();
  } else {
    CheckWhichControllersArePluggedIn();
    if ((t = HandleMenuCursor_Main_ReturnsTwice(4)) == 0xff)
      return;
    flag_two_player_game = t;
    LoadSaveBufferData();
    LoadOverworldLayer2AndEventsTilemaps();
    GameMode0A_PlayerSelect_Entry2();
  }
}

void GameMode0A_PlayerSelect_Entry2() {  // 009e17
  io_music_ch1 = 0x80;
  players_lives[1] = -1;
  uint8 v0 = flag_two_player_game;
  do
    players_lives[v0--] = 4;
  while ((v0 & 0x80) == 0);
  player_current_life_count = 4;
  player_current_coin_count = 0;
  yoshi_carry_over_levels_flag = 0;
  player_current_power_up = 0;
  flag_show_continue_and_end = 0;
  *(uint16 *)players_coins = 0;
  *(uint16 *)players_power_up = 0;
  *(uint16 *)players_has_yoshi = 0;
  *(uint16 *)&player_current_item_box = 0;
  *(uint16 *)&player_mario_bonus_stars = 0;
  *(uint16 *)&player_mario_score_lo = 0;
  *(uint16 *)&player_luigi_score_lo = 0;
  player_mario_score_hi = 0;
  player_luigi_score_hi = 0;
  misc_exit_level_action = 0;
  player_current_character = 0;
  GameMode0A_PlayerSelect_009E62();
}

void GameMode0A_PlayerSelect_009E62() {  // 009e62
  SetKeepGameModeActiveTimer_OneFrame();
  misc_game_mode = 11;
}

void HandleMenuCursor_009E82(uint8 j) {  // 009e82
  int16 v5;

  uint8 v1 = kHandleMenuCursor_DATA_009E7E[misc_blinking_cursor_pos];
  if (((counter_blinking_cursor_frame ^ 0x1F) & 0x18) == 0)
    v1 = 0;
  R0_ = v1;
  uint8 v2 = stripe_image_upload;
  int v3 = j >> 1;
  *(uint16 *)&temp8a = kHandleMenuCursor_DATA_009E6A[v3];
  R2_W = *(uint16 *)&temp8a;
  uint16 v4 = kHandleMenuCursor_DATA_009E74[v3];
  do {
    int8 v6 = v4;
    LOBYTE(v5) = HIBYTE(v4);
    HIBYTE(v5) = v6;
    *(uint16 *)&stripe_image_upload_data[v2] = v5;
    int8 v7 = v5;
    LOBYTE(v5) = v6;
    HIBYTE(v5) = v7;
    uint16 v10 = v5 + 64;
    *(uint16 *)&stripe_image_upload_data[v2 + 2] = 256;
    int16 v8 = 0x38fc;
    int8 v9 = R0_W & 1;
    R0_W >>= 1;
    if (v9)
      v8 = 0x3d2e;
    *(uint16 *)&stripe_image_upload_data[v2 + 4] = v8;
    v4 = v10;
    v2 += 6;
    --R2_W;
  } while (R2_W);
  HandleMenuCursor_009ED4(v2);
}

void HandleMenuCursor_009ED4(uint8 k) {  // 009ed4
  LOBYTE(stripe_image_upload) = k;
  stripe_image_upload_data[k] = -1;
}

void InitializeSaveData() {  // 009f06
  uint8 v0 = -115;
  do
    ow_save_buffer[--v0] = 0;
  while (v0);
  for (uint8 i = 7; (i & 0x80) == 0; --i)
    ow_save_buffer[LOBYTE(kInitializeSaveData_InitialLevelFlags[i])] = HIBYTE(kInitializeSaveData_InitialLevelFlags[i]);
  for (uint8 j = 21; (j & 0x80) == 0; --j)
    ow_save_buffer[j + 111] = kInitializeSaveData_InitialOWPlayerPos[j];
}

void SetKeepGameModeActiveTimer_OneFrame() {  // 009f29
  SetKeepGameModeActiveTimer_VariableFrames(1);
}

void SetKeepGameModeActiveTimer_VariableFrames(uint8 a) {  // 009f2b
  timer_keep_game_mode_active = a;
}

void GameModeXX_FadeInOrOut_MosaicFade() {  // 009f37
  if ((--timer_keep_game_mode_active & 0x80) != 0) {
    SetKeepGameModeActiveTimer_OneFrame();
    mirror_mosaic_size_and_bgenable += kGameModeXX_FadeInOrOut_DATA_009F31[misc_mosaic_direction];
    sub_9F4C(misc_mosaic_direction);
  }
}

void sub_9F4C(uint8 j) {  // 009f4c
  mirror_screen_display_register += kGameModeXX_FadeInOrOut_DATA_009F2F[j];
  if (mirror_screen_display_register == kGameModeXX_FadeInOrOut_DATA_009F33[j])
    GameModeXX_FadeInOrOut_GMMosaic();
  else
    GameModeXX_FadeInOrOut_009F66();
}

void GameModeXX_FadeInOrOut_GMMosaic() {  // 009f5b
  ++misc_game_mode;
  misc_mosaic_direction ^= 1;
  GameModeXX_FadeInOrOut_009F66();
}

void GameModeXX_FadeInOrOut_009F66() {  // 009f66
  WriteReg(MOSAIC, mirror_mosaic_size_and_bgenable | 3);
}

void GameModeXX_FadeInOrOut() {  // 009f6f
  if ((--timer_keep_game_mode_active & 0x80) != 0) {
    SetKeepGameModeActiveTimer_OneFrame();
    GameModeXX_FadeInOrOut_009F77();
  }
}

void GameModeXX_FadeInOrOut_009F77() {  // 009f77
  sub_9F4C(misc_mosaic_direction);
}

void GameMode28_ShowTheEnd() {  // 009f7c
  if ((--timer_keep_game_mode_active & 0x80) != 0) {
    SetKeepGameModeActiveTimer_VariableFrames(8);
    GameModeXX_FadeInOrOut_009F77();
  }
}

void InitializeLevelLayer3() {  // 009fb8
  uint8 v4;
  R0_ = 3 * misc_level_tileset_setting;
  if (misc_level_layer3_settings) {
    uint8 v0 = R0_ + misc_level_layer3_settings - 1;
    int8 v1 = kInitializeLevelLayer3_DATA_009F88[v0];
    if (v1 >= 0) {
      flag_layer3_tide_level = kInitializeLevelLayer3_DATA_009F88[v0];
      InitializeLevelLayer3_GenerateInteractiveTideWater();
      mirror_layer3_ypos = (flag_layer3_tide_level & ~1) ? 64 : 112;
      ScrollSecondInteractiveLayer();
      goto LABEL_15;
    }
    int8 v3 = 2 * v1;
    if (v3 >= 0) {
      if (v3) {
        if (misc_level_tileset_setting != 1 && misc_level_tileset_setting != 3)
          goto LABEL_16;
        mirror_layer3_xpos = mirror_current_layer1_xpos >> 1;
        v4 = -64;
        goto LABEL_14;
      }
      for (uint8 i = 7; (i & 0x80) == 0; --i)
        *((uint8 *)&palettes_palette_mirror[12] + i) = *((uint8 *)kGlobalPalettes_Layer3Smasher + i);
    }
  }
  ++flag_disable_layer3_scroll;
  v4 = -48;
LABEL_14:
  mirror_layer3_ypos = v4;
LABEL_15:
  mirror_color_math_select_and_enable &= ~4;
LABEL_16:
  if (misc_level_layer3_settings) {
    R1_ = R0_ + misc_level_layer3_settings - 1;
    uint8 v6 = R1_;
    R0_ = *((uint8 *)&kInitializeLevelLayer3_Layer3ImagePtrs[0].addr + (uint8)(3 * R1_));
    R1_ = *((uint8 *)&kInitializeLevelLayer3_Layer3ImagePtrs[0].addr + (uint8)(3 * R1_) + 1);
    R2_ = kInitializeLevelLayer3_Layer3ImagePtrs[v6].bank;
    LoadStripeImage_UploadToVRAM(R2_);
  }
}

void InitializeLevelLayer3_GenerateInteractiveTideWater() {  // 00a045
  for (uint16 i = 256; i < 0x1B00; i += 256) {
    int16 v1 = 88;
    do {
      *(uint16 *)&ow_byte_7EE000[i + 768] = 0;
      i += 2;
      --v1;
    } while (v1);
  }
  misc_level_layout_flags |= 0x80;
}

void GameMode0C_LoadOverworld() {  // 00a087
  TurnOffIO();
  if (ow_warping_on_pipe_or_star_flag)
    HandleOverworldStarPipeWarp_SetPlayerDestination();
  ClearOverworldAndCutsceneRAM();
  if (misc_intro_level_flag) {
    timer_title_screen_input_timer = -80;
    ow_players_map[0] = 0;
    mirror_mosaic_size_and_bgenable = -16;
    misc_game_mode = 16;
    GameMode00_LoadNintendoPresents_Mode04Finish();
    return;
  }
  ClearLayer3Tilemap();
  HandleSPCUploads_UploadOverworldMusicBank();
  SetStandardPPUSettings();
  misc_music_register_backup = 0;
  uint8 v0 = player_current_character;
  if ((player_current_life_count & 0x80) != 0)
    ++pointer_display_overworld_prompt;
  players_lives[player_current_character] = player_current_life_count;
  players_power_up[v0] = player_current_power_up;
  players_coins[v0] = player_current_coin_count;
  uint8 v1 = yoshi_carry_over_levels_flag;
  if (yoshi_carry_over_levels_flag)
    v1 = yoshi_current_yoshi_color;
  players_has_yoshi[v0] = v1;
  players_item_box[v0] = player_current_item_box;
  mirror_color_math_initial_settings = 3;
  uint8 v2 = 48;
  uint8 v3 = 21;
  if (flag_show_continue_and_end) {
    LoadSaveBufferData();
    if (!counter_events_triggered) {
      GameMode07_TitleScreenDemo_FadeOutToTitleScreen();
      GameMode00_LoadNintendoPresents_0093F4();
      return;
    }
    LoadOverworldLayer2AndEventsTilemaps();
    palettes_background_color = 0x318c;
    mirror_object_and_color_window_settings = 48;
    mirror_color_math_initial_settings = 32;
    v2 = -77;
    v3 = 23;
  }
  SetVisibleLayers(v2, v3, 2);
  WriteReg(TMW, v3);
  WriteReg(TSW, 2);
  LoadOverworldLayer1AndEvents();
  int v4 = (uint8)(2 * ow_players_map[player_current_character]) >> 1;
  mirror_current_layer1_xpos = kGameMode0C_LoadOverworld_DATA_00A06B[v4];
  mirror_current_layer2_xpos = mirror_current_layer1_xpos;
  mirror_current_layer1_ypos = kGameMode0C_LoadOverworld_DATA_00A079[v4];
  mirror_current_layer2_ypos = mirror_current_layer1_ypos;
  UploadGraphicsFiles();
  GraphicsDecompressionRoutines(0x14);
  BufferPalettesRoutines_Overworld();
  UpdateEntirePalette();
  graphics_stripe_image_to_upload = 6;
  LoadStripeImage();
  LoadOverworldLifeCounter();
  LoadStripeImage();
  GameMode0C_LoadOverworld_048D91();
  InitializeOverworldTilemaps();
  mirror_oamaddress_lo = 0xf0;
  CompressOamEntExt();
  LoadStripeImage();
  pointer_current_overworld_process = 0;
  SetKeepGameModeActiveTimer_OneFrame();
  misc_nmito_use_flag = 2;
  for (uint16 i = 446; (i & 0x8000) == 0; i -= 2) {
    misc_hdmawindow_effect_table[i] = 0;
    misc_hdmawindow_effect_table[i + 1] = -1;
  }
  SetupHDMAWindowingEffects_0092A0();
  GameMode00_LoadNintendoPresents_0093F4();
}

void LoadSaveBufferData() {  // 00a195
  for (uint16 i = 140; (i & 0x8000) == 0; --i)
    ow_level_tile_settings[i] = ow_save_buffer[i];
}

void ClearOverworldAndCutsceneRAM() {  // 00a1a6
  for (int16 i = 189; i >= 0; --i)
    *((uint8 *)&mirror_current_layer1_xpos + (uint16)i) = 0;
  for (int16 j = 0x7ce; j >= 0; --j)
    *(&timer_prevent_pause + (uint16)j) = 0;
}

void GameMode0E_ShowOverworld() {  // 00a1be
  CheckWhichControllersArePluggedIn();
  ++counter_local_frames;
  ResetSpritesFunc(0);
  GameMode0E_ShowOverworld_Bank04();
  CompressOamEntExt();
}

void GameMode14_InLevel() {  // 00a1da
  if (misc_display_message) {
    DisplayMessage();
  } else {
    uint8 v0 = flag_active_bonus_game;
    if (flag_active_bonus_game) {
      v0 = timer_bonus_game_end;
      if (timer_bonus_game_end) {
        if (timer_bonus_game_end < 0x40) {
          DamagePlayer_DisableButtons();
          if (v0 < 0x1C) {
            PlayerState00_SetMarioPeaceImg();
            v0 = 13;
            player_current_state = 13;
          }
        }
      }
    }
    if (timer_end_level | (uint8)(player_current_state | v0)) {
      io_controller_hold1 &= ~4;
      io_controller_press1 &= ~0x40;
      io_controller_press2 &= ~0x40;
    }
    if (timer_prevent_pause) {
      --timer_prevent_pause;
    } else if ((io_controller_press1 & 0x10) != 0 && !timer_end_level && player_current_state < 9) {
      timer_prevent_pause = 60;
      uint8 v1 = 18;
      flag_pause ^= 1;
      if (flag_pause)
        v1 = 17;
      io_sound_ch1 = v1;
    }
    if (flag_pause) {
      if ((io_controller_hold1 & 0x20) != 0 && (ow_level_tile_settings[ow_level_number_lo] & 0x80) && (int8)misc_exit_level_action <= 0) {
        misc_exit_level_action = 0x80;
        ++counter_enemy_rollcall_screen;
        misc_game_mode = 11;
      }
    } else {
      if ((misc_nmito_use_flag & 0x80) == 0) {
        ResetSpritesFunc(0);
        HandleStandardLevelCameraScroll();
        HandleScrollSpriteAndLayer3Scrolling();
        CheckIfLevelTilemapsNeedScrollUpdate();
        HandleLevelTileAnimations();
      } else {
        GameMode14_InLevel_InMode7Level();
      }
      uint16 v2 = mirror_current_layer1_ypos;
      shaking_layer1_disp_y = 0;
      uint8 v3 = timer_shake_layer1;
      if (timer_shake_layer1) {
        --timer_shake_layer1;
        LOBYTE(shaking_layer1_disp_y) = kGameMode14_InLevel_GrndShakeDispYLo[v3 & 3];
        HIBYTE(shaking_layer1_disp_y) = kGameMode14_InLevel_GrndShakeDispYHi[v3 & 3];
        mirror_current_layer1_ypos += shaking_layer1_disp_y;
      }
      UpdateStatusBarCounters();
      PlayerDraw();
      UpdateCurrentPlayerPositionRAM();
      GameMode14_InLevel_00C47E();
      ProcessNormalSprites();
      GameMode14_InLevel_Bank02();
      mirror_current_layer1_ypos = v2;
      CompressOamEntExt();
    }
  }
}

void UpdateCurrentPlayerPositionRAM() {  // 00a2f3
  player_current_xpos = player_xpos;
  player_current_ypos = player_ypos;
}

void UploadPlayerGFX() {  // 00a300
  if (player_number_of_tiles_to_update) {
    WriteReg(CGADD, 0x86);
    WriteRegWord(DMAP2, 0x2200);
    WriteRegWord(A1T2L, pointer_player_palette);
    WriteReg(A1B2, 0);
    WriteRegWord(DAS2L, 0x14);
    WriteReg(MDMAEN, 4);
  }
  WriteReg(VMAIN, 0x80);
  WriteRegWord(DMAP2, 0x1801);
  WriteRegWord(VMADDL, 0x67F0);
  WriteRegWord(A1T2L, graphics_dynamic_sprite_tile7 ? graphics_dynamic_sprite_tile7 : 0x2000);
  WriteReg(A1B2, 0x7E);
  WriteRegWord(DAS2L, 0x20);
  WriteReg(MDMAEN, 4);
  WriteRegWord(VMADDL, 0x6000);
  uint8 v0 = 0;
  do {
    uint16 t = *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[v0];
    WriteRegWord(A1T2L, t ? t : 0x2000);  // bugfix to make predictable behavior
    WriteRegWord(DAS2L, 0x40);
    WriteReg(MDMAEN, 4);
    v0 += 2;
  } while (v0 < player_number_of_tiles_to_update);
  WriteRegWord(VMADDL, 0x6100);
  uint8 v1 = 0;
  do {
    uint16 t = *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[v1];
    WriteRegWord(A1T2L, t ? t : 0x2000);  // bugfix to make predictable behavior
    WriteRegWord(DAS2L, 0x40);
    WriteReg(MDMAEN, 4);
    v1 += 2;
  } while (v1 < player_number_of_tiles_to_update);
}

void UploadLevelExAnimationData() {  // 00a390
  WriteReg(VMAIN, 0x80);
  WriteRegWord(DMAP2, 0x1801);
  WriteReg(A1B2, 0x7E);
  if (graphics_tile_anim_vramaddress3) {
    WriteRegWord(VMADDL, graphics_tile_anim_vramaddress3);
    WriteRegWord(A1T2L, graphics_tile_anim_source_address3);
    WriteRegWord(DAS2L, 0x80);
    WriteReg(MDMAEN, 4);
  }
  if (graphics_tile_anim_vramaddress2) {
    WriteRegWord(VMADDL, graphics_tile_anim_vramaddress2);
    WriteRegWord(A1T2L, graphics_tile_anim_source_address2);
    WriteRegWord(DAS2L, 0x80);
    WriteReg(MDMAEN, 4);
  }
  uint16 v0 = graphics_tile_anim_vramaddress1;
  if (graphics_tile_anim_vramaddress1) {
    WriteRegWord(VMADDL, graphics_tile_anim_vramaddress1);
    WriteRegWord(A1T2L, graphics_tile_anim_source_address1);
    if (v0 == 0x800) {
      WriteRegWord(DAS2L, 0x40);
      WriteReg(MDMAEN, 4);
      WriteRegWord(VMADDL, 0x900);
      WriteRegWord(A1T2L, graphics_tile_anim_source_address1 + 64);
      WriteRegWord(DAS2L, 0x40);
    } else {
      WriteRegWord(DAS2L, 0x80);
    }
    WriteReg(MDMAEN, 4);
  }
  UploadLevelAnimations_YellowFlash(0x64);
}

void UploadLevelAnimations_YellowFlash(uint8 a) {  // 00a41c
  R0_ = 0;
  UploadLevelAnimations_RedFlash(a);
}

void UploadLevelAnimations_RedFlash(uint8 a) {  // 00a41e
  WriteReg(CGADD, a);
  uint8 v1 = R0_ + ((uint8)(counter_local_frames & 0x1C) >> 1);
  WriteReg(CGDATA, *((uint8 *)kGlobalPalettes_Flashing + v1));
  WriteReg(CGDATA, *((uint8 *)kGlobalPalettes_Flashing + v1 + 1));
}

void RestoreSP1AfterMarioStart() {  // 00a436
  if (flag_restoresp1_tiles_after_mario_start) {
    flag_restoresp1_tiles_after_mario_start = 0;
    WriteReg(VMAIN, 0x80);
    WriteRegWord(VMADDL, 0x64A0);
    WriteRegWord(DMAP2, 0x1801);
    WriteRegWord(A1T2L, 0xBF6);
    WriteReg(A1B2, 0);
    WriteRegWord(DAS2L, 0xC0);
    WriteReg(MDMAEN, 4);
    WriteRegWord(VMADDL, 0x65A0);
    WriteRegWord(A1T2L, 0xCB6);
    WriteRegWord(DAS2L, 0xC0);
    WriteReg(MDMAEN, 4);
  }
}

void UpdatePaletteFromIndexedTable() {  // 00a488
  uint16 v1;

  if (palettes_palette_upload_table_index == 0xff)
    return;

  uint16 v0 = kUpdatePaletteFromIndexedTable_DATA_00A47F[palettes_palette_upload_table_index + 2];
  R2_ = v0;
  R1_ = 0;
  R0_ = 0;
  R4_ = 0;
  v1 = WORD(kUpdatePaletteFromIndexedTable_DATA_00A47F[palettes_palette_upload_table_index]);
  uint16 v2 = v1;
  while (1) {
    uint8 v3 = *IndirPtr(&R0_, v2);
    if (!v3)
      break;
    WriteRegWord(A1B2, v0);
    WriteReg(DAS2L, v3);
    R3_ = v3;
    WriteReg(DAS2H, 0);
    uint16 v4 = v2 + 1;
    uint8 *v5 = IndirPtr(&R0_, v4);
    WriteReg(CGADD, *v5);
    WriteRegWord(DMAP2, 0x2200);
    WriteRegWord(A1T2L, ++v4);
    v2 = *(uint16 *)&R3_ + v4;
    WriteReg(MDMAEN, 4);
  }
  UpdatePaletteFromIndexedTable_00AE47();
  if (!palettes_palette_upload_table_index) {
    palettes_dynamic_palette_upload_index = 0;
    palettes_dynamic_palette_bytes_to_upload = 0;
  }
  palettes_palette_upload_table_index = 0;
}

void UploadOverworldExAnimationData() {  // 00a4e3
  WriteReg(VMAIN, 0x80);
  WriteRegWord(VMADDL, 0x750);
  WriteRegWord(DMAP2, 0x1801);
  WriteRegWord(A1T2L, 0xAF6);
  WriteReg(A1B2, 0);
  WriteRegWord(DAS2L, 0x160);
  WriteReg(MDMAEN, 4);
  if (pointer_current_overworld_process != 10) {
    UploadLevelAnimations_YellowFlash(0x6D);
    R0_ = 16;
    UploadLevelAnimations_RedFlash(0x7D);
  }
}

void UploadOverworldLayer1And2Tilemaps(uint8 j) {  // 00a529
  WriteReg(VMAIN, 0x80);
  WriteReg(VMADDL, 0);
  WriteReg(VMADDH, kUploadOverworldLayer1And2Tilemaps_DATA_00A521[j] + 48);
  for (uint8 i = 6; (i & 0x80) == 0; --i)
    WriteReg((SnesRegs)(i + 0x4310), kUploadOverworldLayer1And2Tilemaps_PARAMS_00A586[i]);
  if (ow_players_map[(uint8)player_current_characterx4 >> 2])
    WriteReg(A1T1H, 0x60);
  uint8 Reg = ReadReg(A1T1H);
  WriteReg(A1T1H, kUploadOverworldLayer1And2Tilemaps_DATA_00A525[j] + Reg);
  WriteReg(MDMAEN, 2);
  WriteReg(VMAIN, 0x80);
  WriteReg(VMADDL, 0);
  WriteReg(VMADDH, kUploadOverworldLayer1And2Tilemaps_DATA_00A521[j] + 32);
  for (uint8 k = 6; (k & 0x80) == 0; --k)
    WriteReg((SnesRegs)(k + 0x4310), kUploadOverworldLayer1And2Tilemaps_PARAMS_00A58D[k]);
  WriteReg(MDMAEN, 2);
}

void GameMode12_PrepareLevel() {  // 00a59c
  ClearLayer3Tilemap();
  DamagePlayer_DisableButtons();
  flag_upload_load_screen_letters_tovram = 0;
  SetStandardPPUSettings();
  InitializeStatusBarTilemap();
  InitializeLevelLayer1And2Tilemaps();
  if ((misc_nmito_use_flag & 0x80) == 0) {
    UploadGraphicsFiles();
    BufferPalettesRoutines_Levels();
    GameMode12_PrepareLevel_InitializeLayer3RAM();
    InitializeLevelLayer3();
    InitializeLevelTileAnimations();
    SetupHDMAWindowingEffects_EndHDMA();
    GameMode12_PrepareLevel_009860();
  } else {
    GameMode12_PrepareLevel_PrepareMode7Level();
  }
  UpdateEntirePalette();
  SetKeepGameModeActiveTimer_OneFrame();
  UpdateStatusBarCounters();
  uint8 *v0 = g_ram + 0x905;
  uint8 *v1 = g_ram + 0x703;
  MemCpy(v0, v1, 0x1F0);
  palettes_copy_of_background_color = palettes_background_color;
  GameMode12_PrepareLevel_00919B();
  CompressOamEntExt();
  GameMode00_LoadNintendoPresents_0093F4();
}

void InitializeLevelTileAnimations() {  // 00a5f9
  counter_local_frames &= 0x18;
  do {
    HandleLevelTileAnimations();
    UploadLevelExAnimationData();
    ++counter_local_frames;
  } while ((counter_local_frames & 7) != 0);
}

void InitializeLevelRAM() {  // 00a635
  if (spr45_directional_coins_despawn_timer | timer_silver_pswitch | timer_blue_pswitch)
    goto LABEL_4;
  if (!timer_star_power)
    goto LABEL_6;
  int8 v0 = misc_music_register_backup;
  if ((misc_music_register_backup & 0x80) != 0)
LABEL_4:
    v0 = misc_music_register_backup & 0x7F;
  misc_music_register_backup = v0 | 0x40;
  timer_blue_pswitch = 0;
  timer_silver_pswitch = 0;
  spr45_directional_coins_despawn_timer = 0;
  timer_star_power = 0;
LABEL_6:
  if (blocks_give_life_in_bonus_flags_row5 |
      blocks_give_life_in_bonus_flags_row4 | blocks_give_life_in_bonus_flags_row3 |
              blocks_give_life_in_bonus_flags_row2 | blocks_give_life_in_bonus_flags_row1)
    flag_prevent_coin_bonus_game_replay = blocks_give_life_in_bonus_flags_row5 | blocks_give_life_in_bonus_flags_row4 |
                                          blocks_give_life_in_bonus_flags_row3 | blocks_give_life_in_bonus_flags_row2 |
                                          blocks_give_life_in_bonus_flags_row1;
  uint8 v1 = 35;
  do
    *(&ptr_hi_map16_data_bank + v1--) = 0;
  while (v1);
  uint8 v2 = 55;
  do
    *(&pointer_current_overworld_process + v2--) = 0;
  while (v2);
  unusedram_got_invincible_star_from_goal *= 2;
  timer_display_player_kicking_pose = 0;
  timer_display_player_pick_up_pose = 0;
  timer_level_end_fade = 0;
  yoshi_in_pipe = 0;
  if (misc_level_tileset_setting < 0x10 && kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting] >> 1 &&
      !(flag_disable_no_yoshi_intro | (uint8)(counter_sublevels_entered | flag_show_player_start))) {
    if (flag_override_no_yoshi_intro_for_midway_entrance) {
      PlayerState0A_NoYoshiCutscene_00C90A();
      InitializeLevelRAM_00A6CC(1);
    } else {
      player_in_air_flag = 0;
      player_facing_direction = 1;
      player_pipe_action = 1;
      if (yoshi_carry_over_levels_flag)
        InitializeLevelRAM_00A6C7(0xA, 0xF);
      else
        InitializeLevelRAM_00A6C7(0xA, 0);
    }
  } else {
    InitializeLevelRAM_00A6CC(1);
  }
}

void InitializeLevelRAM_00A6C7(uint8 k, uint8 j) {  // 00a6c7
  player_current_state = k;
  player_timer_pipe_warping = j;
}

void InitializeLevelRAM_00A6CC(uint8 j) {  // 00a6cc
  uint8 v4;
  if ((uint8)mirror_current_layer1_ypos != 0xC0)
    ++flag_enable_vert_scroll;
  uint8 v1 = misc_level_header_entrance_settings;
  if (!misc_level_header_entrance_settings)
    goto LABEL_8;
  if (misc_level_header_entrance_settings == 5) {
    int8 v2 = 0;
    if (misc_level_header_entrance_settings >= 5)
      v2 = 0x80;
    flag_ice_level = (flag_ice_level >> 1) + v2;
LABEL_8:
    player_facing_direction = j;
    player_in_air_flag = 36;
    flag_sprites_locked = 0;
    if (timer_end_level_via_keyhole) {
      misc_music_register_backup |= 0x7F;
      temp1436 = player_xpos | 4;
      temp1438 = player_ypos + 16;
    }
    if (in_yoshi_wings_bonus_area) {
      player_current_state = 8;
      LOBYTE(player_ypos) = -96;
      player_yspeed = -112;
    }
    return;
  }
  if (misc_level_header_entrance_settings >= 6) {
    if (misc_level_header_entrance_settings == 6) {
      player_facing_direction = j;
      player_cape_image = j;
      yoshi_in_pipe = -1;
      LOBYTE(player_xpos) = player_xpos | 8;
      LOBYTE(player_ypos) = player_ypos | 2;
      InitializeLevelRAM_00A6C7(7, 0x20);
      return;
    }
    flag_underwater_level = j;
    if (timer_end_level_via_keyhole | flag_override_no_yoshi_intro_for_midway_entrance)
      goto LABEL_8;
    v1 = 4;
  }
  player_pipe_action = v1 + 3;
  yoshi_in_pipe = ((uint8)(v1 + 3) >> 1) - 1;
  player_facing_direction = kInitializeLevelRAM_DATA_00A60D[(uint8)(v1 + 3) - 4];
  uint8 v3 = 5;
  if ((uint8)(v1 + 3) < 6 ||
      (LOBYTE(player_xpos) = player_xpos | 8, v3 = 6, v4 = 30, (uint8)(v1 + 3) >= 7) && (v4 = 15, player_current_power_up)) {
    v4 = 28;
  }
  player_yspeed = v4;
  InitializeLevelRAM_00A6C7(v3, v4);
  if (player_riding_yoshi_flag) {
    player_timer_pipe_warping += kInitializeLevelRAM_DATA_00A61D[player_pipe_action];
    player_xpos += *(uint16 *)&kInitializeLevelRAM_DATA_00A60D[(uint8)(2 * player_pipe_action) - 4];
    player_ypos += kInitializeLevelRAM_DATA_00A611[player_pipe_action];
  }
}

void GameMode11_LoadSublevel_00A796() {  // 00a796
  uint16 v0;
  if (flag_layer2_vert_scroll_level_setting) {
    if (flag_layer2_vert_scroll_level_setting == 1) {
      v0 = mirror_current_layer2_ypos - mirror_current_layer1_ypos;
    } else {
      int16 v1 = mirror_current_layer1_ypos >> 1;
      if (flag_layer2_vert_scroll_level_setting != 2)
        v1 = mirror_current_layer1_ypos >> 3;
      v0 = mirror_current_layer2_ypos - v1;
    }
    camera_layer2_ypos_relative_to_layer1 = v0;
  }
  player_relative_position_needed_to_scroll_screen = 128;
}

void UploadLoadingLettersTiles() {  // 00a7c2
  WriteReg(VMAIN, 0x80);
  WriteRegWord(VMADDL, 0x6000);
  WriteRegWord(DMAP2, 0x1801);
  WriteRegWord(A1T2L, 0x977B);
  WriteReg(A1B2, 0x7F);
  WriteRegWord(DAS2L, 0xC0);
  WriteReg(MDMAEN, 4);
  WriteRegWord(VMADDL, 0x6100);
  WriteRegWord(A1T2L, 0x983B);
  WriteRegWord(DAS2L, 0xC0);
  WriteReg(MDMAEN, 4);
  WriteRegWord(VMADDL, 0x64A0);
  WriteRegWord(A1T2L, 0x98FB);
  WriteRegWord(DAS2L, 0xC0);
  WriteReg(MDMAEN, 4);
  WriteRegWord(VMADDL, 0x65A0);
  WriteRegWord(A1T2L, 0x99BB);
  WriteRegWord(DAS2L, 0xC0);
  WriteReg(MDMAEN, 4);
}

void BufferLoadingLetterTiles() {  // 00a82d
  GraphicsDecompressionRoutines(0xF);
  if (flag_active_bonus_game)
    R0_W += 48;
  uint16 v0 = 0;
  do {
    int16 v1 = 8;
    do {
      *(uint16 *)&graphics_decompressed_loading_letters[v0] = *(uint16 *)IndirPtr(&R0_W, 0);
      v0 += 2;
      ++R0_W;
      ++R0_W;
      --v1;
    } while (v1);
    int16 v2 = 8;
    do {
      *(uint16 *)&graphics_decompressed_loading_letters[v0] = *IndirPtr(&R0_W, 0);
      v0 += 2;
      ++R0_W;
      --v2;
    } while (v2);
  } while (v0 < 0x300);
  GraphicsDecompressionRoutines(0);
  R0_W = 0xb3f0;
  *(uint16 *)&R1_ = 0x7eb3;
  uint16 v3 = 0;
  do {
    int16 v4 = 8;
    do {
      decompressed_gfx_plus_256[v3 >> 1] = *(uint16 *)IndirPtr(&R0_W, 0);
      v3 += 2;
      ++R0_W;
      ++R0_W;
      --v4;
    } while (v4);
    int16 v5 = 8;
    do {
      decompressed_gfx_plus_256[v3 >> 1] = *IndirPtr(&R0_W, 0);
      v3 += 2;
      ++R0_W;
      --v5;
    } while (v5);
    if (v3 == 192)
      R0_W = 0xb570;
  } while (v3 < 0x180);
  flag_upload_load_screen_letters_tovram = 1;
  flag_restoresp1_tiles_after_mario_start = 1;
}

void UploadGraphicsFiles_Layer3() {  // 00a993
  WriteReg(VMADDL, 0);
  WriteReg(VMADDH, 0x40);
  R15_ = 3;
  R14_ = 40;
  do {
    GraphicsDecompressionRoutines(R14_);
    int16 v0 = 0x3ff;
    uint16 v1 = 0;
    do {
      uint8 *v2 = IndirPtr(&R0_W, v1);
      WriteRegWord(VMDATAL, *(uint16 *)v2);
      v1 += 2;
      --v0;
    } while (v0 >= 0);
    ++R14_;
    --R15_;
  } while ((R15_ & 0x80) == 0);
  WriteReg(VMADDL, 0);
  WriteReg(VMADDH, 0x60);
  UploadGraphicsFiles_UploadGFXFile(0);
}

void UploadGraphicsFiles() {  // 00a9da
  WriteReg(VMAIN, 0x80);
  int8 v0 = 3;
  uint8 v1 = 4 * graphics_level_sprite_graphics_setting;
  do
    *(&R4_ + (uint8)v0--) = kUploadGraphicsFiles_SpriteGFXList[v1++];
  while (v0 >= 0);
  R15_ = 3;
  do {
    uint8 v2 = R15_;
    WriteReg(VMADDL, 0);
    WriteReg(VMADDH, kUploadGraphicsFiles_DATA_00A9D2[v2]);
    if (misc_currently_loaded_sprite_graphics_files[v2] != *(&R4_ + v2))
      UploadGraphicsFiles_UploadGFXFile(*(&R4_ + v2));
    --R15_;
  } while ((R15_ & 0x80) == 0);
  for (uint8 i = 3; (i & 0x80) == 0; --i)
    misc_currently_loaded_sprite_graphics_files[i] = *(&R4_ + i);
  if (misc_level_tileset_setting >= 0xFE) {
    if (misc_level_tileset_setting != 0xFE)
      ConvertGFX27IntoNormallFormat();
    for (int8 j = 3; j >= 0; --j)
      misc_currently_loaded_sprite_graphics_files[(uint8)j + 4] = 0x80;
  } else {
    int8 v4 = 3;
    uint8 v5 = 4 * misc_level_tileset_setting;
    do
      *(&R4_ + (uint8)v4--) = kUploadGraphicsFiles_FGAndBGGFXList[v5++];
    while (v4 >= 0);
    R15_ = 3;
    do {
      uint8 v6 = R15_;
      WriteReg(VMADDL, 0);
      WriteReg(VMADDH, kUploadGraphicsFiles_DATA_00A9D6[v6]);
      if (misc_currently_loaded_sprite_graphics_files[v6 + 4] != *(&R4_ + v6))
        UploadGraphicsFiles_UploadGFXFile(*(&R4_ + v6));
      --R15_;
    } while ((R15_ & 0x80) == 0);
    for (uint8 k = 3; (k & 0x80) == 0; --k)
      misc_currently_loaded_sprite_graphics_files[k + 4] = *(&R4_ + k);
  }
}

void UploadGraphicsFiles_UploadGFXFile(uint8 j) {  // 00aa6b
  uint16 v4;
  int16 v8;
  uint16 v11;
  int16 v15;

  GraphicsDecompressionRoutines(j);
  if (j == 1 && (ow_level_tile_settings[73] & 0x80) != 0) {
    GraphicsDecompressionRoutines(0x31);
    j = 1;
  }
  if (misc_level_tileset_setting >= 0x11 && j == 8 || j == 30) {
    R10_W = -256;
    for (int8 i = 127; i >= 0; --i) {
      for (int8 k = 7; k >= 0; --k) {
        v11 = *(uint16 *)IndirPtr(&R0_W, 0);
        WriteRegWord(VMDATAL, v11);
        int8 v12 = v11;
        LOBYTE(v11) = HIBYTE(v11);
        HIBYTE(v11) = v12;
        *(uint16 *)&graphics_3_bppto4_bppbuffer[(uint8)k] = *(uint16 *)IndirPtr(&R0_W, 0) | v11;
        ++R0_W;
        ++R0_W;
      }
      for (int8 m = 7; m >= 0; --m) {
        R12_W = *IndirPtr(&R0_W, 0);
        uint8 *v14 = IndirPtr(&R0_W, 0);
        LOBYTE(v15) = HIBYTE(*(uint16 *)v14);
        HIBYTE(v15) = *(uint16 *)v14;
        WriteRegWord(VMDATAL, R12_W | R10_W & (*(uint16 *)&graphics_3_bppto4_bppbuffer[(uint8)m] | v15));
        ++R0_W;
      }
    }
  } else {
    R10_W = 0;
    int16 v1 = -1;
    if (j != 1 && j != 23)
      v1 = 0;
    *(uint16 *)flag_alter3_bppto4_bppconversion = v1;
    for (int8 n = 127; n >= 0; --n) {
      if (*(uint16 *)flag_alter3_bppto4_bppconversion) {
        if ((uint8)n >= 0x7E || (uint8)n >= 0x6E && (uint8)n < 0x70)
          R10_W = -256;
        else
          R10_W = 0;
      }
      for (int8 ii = 7; ii >= 0; --ii) {
        v4 = *(uint16 *)IndirPtr(&R0_W, 0);
        WriteRegWord(VMDATAL, v4);
        int8 v5 = v4;
        LOBYTE(v4) = HIBYTE(v4);
        HIBYTE(v4) = v5;
        *(uint16 *)&graphics_3_bppto4_bppbuffer[(uint8)ii] = *(uint16 *)IndirPtr(&R0_W, 0) | v4;
        ++R0_W;
        ++R0_W;
      }
      for (int8 jj = 7; jj >= 0; --jj) {
        R12_W = *IndirPtr(&R0_W, 0);
        uint8 *v7 = IndirPtr(&R0_W, 0);
        LOBYTE(v8) = HIBYTE(*(uint16 *)v7);
        HIBYTE(v8) = *(uint16 *)v7;
        WriteRegWord(VMDATAL, R12_W | R10_W & (*(uint16 *)&graphics_3_bppto4_bppbuffer[(uint8)jj] | v8));
        ++R0_W;
      }
    }
  }
}

void ConvertGFX27IntoNormallFormat() {  // 00ab42
  GraphicsDecompressionRoutines(0x27);
  uint8 *p = IndirPtr(&R0_, 0);
  for (int i = 0x3ff; i >= 0; --i) {
    uint32 d = p[0] << 16 | p[1] << 8 | p[2];
    WriteReg(VMDATAH, (d >> 21) & 7);
    WriteReg(VMDATAH, (d >> 18) & 7);
    WriteReg(VMDATAH, (d >> 15) & 7);
    WriteReg(VMDATAH, (d >> 12) & 7);
    WriteReg(VMDATAH, (d >> 9) & 7);
    WriteReg(VMDATAH, (d >> 6) & 7);
    WriteReg(VMDATAH, (d >> 3) & 7);
    WriteReg(VMDATAH, (d >> 0) & 7);
    p += 3;
  }
  int v11 = 0x2000;
  do {
    WriteReg(VMDATAH, 0);
  } while (--v11);
}

void BufferPalettesRoutines_Levels() {  // 00abed
  R4_W = 0x7fdd;
  BufferPalettesRoutines_LoadColorInVerticalStrip(2);
  R4_W = 0x7FFF;
  BufferPalettesRoutines_LoadColorInVerticalStrip(0x102);
  R0_W = 0xb170;
  R4_W = 16;
  R6_W = 7;
  R8_W = 1;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb250;
  R4_W = 132;
  R6_W = 5;
  R8_W = 9;
  BufferPalettesRoutines_LoadColors();
  palettes_background_color = *(uint16 *)((int8 *)&kGlobalPalettes_Sky + (uint16)(2 * (misc_background_color_setting & 0xF)));
  R0_W = 0xb190;
  R0_W = kBufferPalettesRoutines_DATA_00ABD3[misc_fgpalette_setting & 0xF] + 0xb190;
  R4_W = 68;
  R6_W = 5;
  R8_W = 1;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb318;
  R0_W = kBufferPalettesRoutines_DATA_00ABD3[misc_sprite_palette_setting & 0xF] + 0xb318;
  R4_W = 452;
  R6_W = 5;
  R8_W = 1;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb0b0;
  R0_W = kBufferPalettesRoutines_DATA_00ABD3[misc_bgpalette_setting & 0xF] + 0xb0b0;
  R4_W = 4;
  R6_W = 5;
  R8_W = 1;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb674;
  R4_W = 82;
  R6_W = 6;
  R8_W = 2;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb674;
  R4_W = 306;
  R6_W = 6;
  R8_W = 2;
  BufferPalettesRoutines_LoadColors();
}

void BufferPalettesRoutines_LoadColorInVerticalStrip(uint16 k) {  // 00aced
  for (int16 i = 7; i >= 0; --i) {
    palettes_palette_mirror[k >> 1] = R4_W;
    k += 32;
  }
}

void BufferPalettesRoutines_LoadColors() {  // 00acff
  do {
    uint16 v0 = R4_W;
    int16 v1 = R6_W;
    do {
      palettes_palette_mirror[v0 >> 1] = *(uint16 *)RomPtr_00(R0_W);
      ++R0_W;
      ++R0_W;
      v0 += 2;
      --v1;
    } while (v1 >= 0);
    R4_W += 32;
    --R8_W;
  } while ((R8_W & 0x8000) == 0);
}

void BufferPalettesRoutines_Overworld() {  // 00ad25
  uint16 v0 = 0xb3d8;
  if (*(int16 *)&ow_level_tile_settings[72] < 0)
    v0 = 0xb732;
  R0_W = v0;
  R0_W = v0 + kBufferPalettesRoutines_DATA_00ABDF
                  [(uint16)(2 * kBufferPalettesRoutines_DATA_00AD1E[(uint16)((misc_level_tileset_setting & 0xF) - 1)]) >> 1];
  R4_W = 130;
  R6_W = 6;
  R8_W = 3;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb528;
  R4_W = 82;
  R6_W = 6;
  R8_W = 5;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb57c;
  R4_W = 258;
  R6_W = 6;
  R8_W = 7;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb5ec;
  R4_W = 16;
  R6_W = 7;
  R8_W = 1;
  BufferPalettesRoutines_LoadColors();
}

void BufferPalettesRoutines_TitleScreen() {  // 00ada6
  R0_W = 0xb63c;
  R4_W = 16;
  R6_W = 7;
  R8_W = 0;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb62c;
  R4_W = 48;
  R6_W = 7;
  R8_W = 0;
  BufferPalettesRoutines_LoadColors();
}

void BufferPalettesRoutines_IggyLarryPlatform() {  // 00add9
  BufferPalettesRoutines_Levels();
  palettes_background_color = 23;
  R0_W = 0xb170;
  R4_W = 16;
  R6_W = 7;
  R8_W = 1;
  BufferPalettesRoutines_LoadColors();
  R0_W = 0xb65c;
  R4_W = 0;
  R6_W = 7;
  R8_W = 0;
  BufferPalettesRoutines_LoadColors();
}

void BufferPalettesRoutines_ReznorAndMode7KoopaBosses() {  // 00ae15
  misc_sprite_palette_setting = 2;
  misc_fgpalette_setting = 7;
  BufferPalettesRoutines_Levels();
  palettes_background_color = 23;
  R0_W = 0xb5f4;
  R4_W = 24;
  R6_W = 3;
  R8_W = 0;
  BufferPalettesRoutines_LoadColors();
}

void UpdatePaletteFromIndexedTable_00AE47() {  // 00ae47
  for (uint8 i = 2; (i & 0x80) == 0; --i) {
    uint16 v1 = palettes_background_color;
    uint8 v2 = kUpdatePaletteFromIndexedTable_DATA_00AE41[i];
    while ((--v2 & 0x80) == 0)
      v1 >>= 1;
    WriteReg(COLDATA, kUpdatePaletteFromIndexedTable_DATA_00AE44[i] | v1 & 0x1F);
  }
}

void HandlePaletteFades() {  // 00af17
  uint8 v0 = timer_end_level;
  if (counter_global_frames & 1) {
    v0 = timer_end_level - 1;
    if (timer_end_level != 1)
      --timer_end_level;
  }
  if (v0 < 0xA0) {
    mirror_color_math_select_and_enable &= ~4;
    mirror_bgmode_and_tile_size_setting = 9;
    ProcessLevelEndRoutines();
  }
  HandlePaletteFades_00AF35();
}

void HandlePaletteFades_00AF35() {  // 00af35
  if ((counter_global_frames & 3) == 0 && timer_level_end_fade < 0x40) {
    HandlePaletteFades_00AFA3(timer_level_end_fade);
    palettes_copy_of_palette_mirror[0] = 510;
    for (uint16 i = 238; (i & 0x8000) == 0; i -= 18) {
      R0_W = 7;
      do {
        int v1 = i >> 1;
        R2_W = palettes_copy_of_palette_mirror[v1];
        HandlePaletteFades_00AFC0(palettes_palette_mirror[v1]);
        palettes_copy_of_palette_mirror[v1] = R4_W;
        i -= 2;
        --R0_W;
      } while (R0_W);
    }
    for (uint16 j = 4; (j & 0x8000) == 0; j -= 2) {
      int v3 = j >> 1;
      R2_W = palettes_copy_of_palette_mirror[v3 + 13];
      HandlePaletteFades_00AFC0(palettes_palette_mirror[v3 + 13]);
      palettes_copy_of_palette_mirror[v3 + 13] = R4_W;
    }
    R2_W = palettes_background_color;
    HandlePaletteFades_00AFC0(palettes_copy_of_background_color);
    palettes_background_color = R4_W;
    LOBYTE(palettes_copy_of_palette_mirror[128]) = 0;
    palettes_palette_upload_table_index = 3;
  }
}

void HandlePaletteFades_00AFA3(uint8 a) {  // 00afa3
  timer_level_end_fade = a + 2;
  R12_W = (a >> 4) & 2;
  R14_W = kHandlePaletteFades_DATA_00AEF7[(uint8)(a & 0x1E) >> 1];
}

void HandlePaletteFades_00AFC0(uint16 a) {  // 00afc0
  R10_W = a;
  R6_W = 4 * (a & 0x1F);
  R8_W = (a & 0x3E0) >> 3;
  R10_W = R11_ & 0x7C;
  R4_W = 0;
  for (uint16 i = 4; (i & 0x8000) == 0; i -= 2) {
    uint16 t = R12_W | *(uint16 *)((uint8 *)&R6_W + i);
    uint16 v2 = R14_W & kHandlePaletteFades_DATA_00AE77[t >> 1];
    if (v2) {
      int v3 = i >> 1;
      v2 = kHandlePaletteFades_DATA_00AE6B[v3];
      if (*(int8 *)&palettes_level_end_color_fade_direction < 0)
        v2 = kHandlePaletteFades_DATA_00AE71[v3];
    }
    R4_W |= kHandlePaletteFades_DATA_00AE65[i >> 1] & (uint16)(R2_W + v2);
  }
}

void OwEventProcess04_FadeInLayer2Tile_00B006(uint8 a) {  // 00b006
  HandlePaletteFades_00AFA3(a);
  for (uint16 i = 110; (i & 0x8000) == 0; i -= 16) {
    int16 v2 = 8;
    int16 v4;
    do {
      int v3 = i >> 1;
      R2_W = palettes_copy_of_palette_mirror[v3 + 1];
      v4 = v2;
      HandlePaletteFades_00AFC0(palettes_palette_mirror[v3 + 64]);
      palettes_copy_of_palette_mirror[v3 + 1] = R4_W;
      palettes_copy_of_palette_mirror[v3 + 58] = palettes_palette_mirror[v3 + 64] - R4_W;
      i -= 2;
      --v2;
    } while (v4 != 1);
  }
}

void PlayerState00_00B03E() {  // 00b03e
  HandlePaletteFades_00AF35();
  if (palettes_palette_upload_table_index == 3) {
    R2_ = 0;
    R0_W = pointer_player_palette;
    for (uint16 i = 20; (i & 0x8000) == 0; i -= 2)
      palettes_copy_of_palette_mirror[(i >> 1) + 134] = *(uint16 *)IndirPtr(&R0_W, i);
    palettes_copy_of_palette_mirror[128] = 0x81ee;
    for (uint16 j = 206; (j & 0x8000) == 0; j -= 18) {
      R0_W = 7;
      do {
        int v2 = j >> 1;
        R2_W = palettes_copy_of_palette_mirror[v2 + 144];
        HandlePaletteFades_00AFC0(palettes_palette_mirror[v2 + 144]);
        palettes_copy_of_palette_mirror[v2 + 144] = R4_W;
        j -= 2;
        --R0_W;
      } while (R0_W);
    }
    unused_byte_7E0AF5 = 0;
  }
}

void GraphicsDecompressionRoutines_DecompressGFX32And33() {  // 00b888
  *(uint16 *)&temp8a = 0xbfc0;
  temp8c = 8;
  R0_W = 0x2000;
  R2_ = 126;
  GraphicsDecompressionRoutines_BeginDecompression();
  temp8f = 126;
  *(uint16 *)&temp8d = 0xacfe;
  int16 v0 = 0x23ff;
LABEL_2:;
  int16 v1 = 8;
  do {
    IndirWriteWord(&temp8d, 0, graphics_decompressedgfx32[(uint16)v0--]);
    --*(uint16 *)&temp8d;
    --*(uint16 *)&temp8d;
    --v1;
  } while (v1);
  int16 v2 = 8;
  while (1) {
    uint16 v3 = v0 - 1;
    IndirWriteWord(&temp8d, 0, *(uint16 *)&graphics_decompressedgfx32[v3]);
    v0 = v3 - 1;
    if (v0 < 0)
      break;
    --*(uint16 *)&temp8d;
    --*(uint16 *)&temp8d;
    if (!--v2)
      goto LABEL_2;
  }
  *(uint16 *)&temp8a = 0x8000;
  GraphicsDecompressionRoutines_BeginDecompression();
}

void GraphicsDecompressionRoutines_BeginDecompression() {  // 00b8de
  int16 v3;
  uint16 v17;
  int8 v20;

  uint16 v0 = 0;
  while (1) {
    uint8 Byte = GraphicsDecompressionRoutines_ReadByte();
    if (Byte == 0xFF)
      break;
    temp8f = Byte;
    int8 v2 = Byte & 0xE0;
    if (v2 == -32) {
      v20 = (8 * temp8f) & 0xE0;
      HIBYTE(v3) = temp8f & 3;
      LOBYTE(v3) = GraphicsDecompressionRoutines_ReadByte();
    } else {
      v20 = v2;
      v3 = temp8f & 0x1F;
    }
    *(uint16 *)&temp8d = v3 + 1;
    if (v20) {
      if (v20 < 0) {
        HIBYTE(v17) = GraphicsDecompressionRoutines_ReadByte();
        LOBYTE(v17) = GraphicsDecompressionRoutines_ReadByte();
        uint16 v18 = v17;
        do {
          uint8 *v19 = IndirPtr(&R0_, v18);
          IndirWriteByte(&R0_, v0++, *v19);
          ++v18;
          --*(uint16 *)&temp8d;
        } while (*(uint16 *)&temp8d);
      } else if ((v20 & 0x40) != 0) {
        if (((2 * v20) & 0x40) != 0) {
          uint8 v4 = GraphicsDecompressionRoutines_ReadByte();
          int16 v5 = *(uint16 *)&temp8d;
          do {
            IndirWriteByte(&R0_, v0++, v4++);
            --v5;
          } while (v5);
        } else {
          uint8 v9 = GraphicsDecompressionRoutines_ReadByte();
          uint8 v10 = GraphicsDecompressionRoutines_ReadByte();
          int16 v11 = *(uint16 *)&temp8d;
          do {
            uint8 v14 = v10;
            uint8 v12 = v9;
            uint8 v13 = v14;
            IndirWriteByte(&R0_, v0++, v12);
            int16 v15 = v11 - 1;
            if (!v15)
              break;
            uint8 v16 = v12;
            v10 = v13;
            v9 = v16;
            IndirWriteByte(&R0_, v0++, v10);
            v11 = v15 - 1;
          } while (v11);
        }
      } else {
        uint8 v7 = GraphicsDecompressionRoutines_ReadByte();
        int16 v8 = *(uint16 *)&temp8d;
        do {
          IndirWriteByte(&R0_, v0++, v7);
          --v8;
        } while (v8);
      }
    } else {
      do {
        uint8 v6 = GraphicsDecompressionRoutines_ReadByte();
        IndirWriteByte(&R0_, v0++, v6);
        --*(uint16 *)&temp8d;
      } while (*(uint16 *)&temp8d);
    }
  }
}

uint8 GraphicsDecompressionRoutines_ReadByte() {  // 00b983
  uint8 result = *IndirPtr(&temp8a, 0);
  int16 v1 = *(uint16 *)&temp8a + 1;
  if (*(uint16 *)&temp8a == 0xFFFF) {
    v1 = 0x8000;
    ++temp8c;
  }
  *(uint16 *)&temp8a = v1;
  return result;
}

void GraphicsDecompressionRoutines(uint8 j) {  // 00ba28
  temp8a = kGraphicsDecompressionRoutines_GraphicsPtrLo[j];
  temp8b = kGraphicsDecompressionRoutines_GraphicsPtrHi[j];
  temp8c = kGraphicsDecompressionRoutines_GraphicsPtrBank[j];
  R0_ = 0;
  R1_ = -83;
  R2_ = 126;
  GraphicsDecompressionRoutines_BeginDecompression();
}

void GenerateTile() {  // 00beb0
  uint16 v0;

  if (blocks_map16_to_generate) {
    R12_W = blocks_xpos;
    R14_W = blocks_ypos;
    HIBYTE(v0) = 0;
    R9_ = misc_level_layout_flags;
    if ((uint8)misc_current_layer_being_processed)
      R9_ >>= 1;
    uint16 v1 = R14_W;
    if ((R9_ & 1) != 0) {
      R0_ = HIBYTE(blocks_xpos);
      HIBYTE(blocks_xpos) = HIBYTE(blocks_ypos);
      HIBYTE(blocks_ypos) = R0_;
      v1 = R12_W;
    }
    if (v1 < 0x200) {
      v0 = 2 * misc_current_layer_being_processed;
      uint16 v2 = v0;
      WORD(temp65) = WORD(*((uint8 *)kLevelDataLayoutTables_LoTablePtrs + v0));
      temp67 = 0;
      v0 = 2 * misc_level_mode_setting;
      R4_ = *IndirPtr(&temp65, v0);
      R5_ = *IndirPtr(&temp65, v0 + 1);
      R6_ = 0;
      R7_ = HIBYTE(blocks_xpos);
      ptr_hi_map16_data = ptr_lo_map16_data = *(uint16*)IndirPtr(&R4_, 3 * HIBYTE(blocks_xpos));
      ptr_lo_map16_data_bank = 126;
      ptr_hi_map16_data_bank = 127;
      // @25: Write to 0x6 = 0x25: 0xbf67: r18=0x4100: r20=0xc19e: a = 0x25, x = 0x0, y = 0xd, c = 0, r4 = 24, r5 = 40, r6 = 25, r9=1, blocks_ypos = 482/15e
      uint8 v3, v4;
      if ((R9_ & 1) != 0) {
        v3 = HIBYTE(blocks_ypos) & 1;
        v4 = HIBYTE(blocks_xpos) & 1;
      } else {
        v3 = HIBYTE(blocks_xpos) & 1;
        v4 = HIBYTE(blocks_ypos);
      }
      R4_ = (4 * (2 * v4 + v3)) | 0x20;
      if (v2)
        R4_ += 16;
      bool v6 = __CFSHL__(blocks_ypos & 0xF0, 1);
      R5_ = 4 * (blocks_ypos & 0xF0) + v6;
      // todo: understand this
      R6_ = R4_ | (2 * (4 * (blocks_ypos & 0xF0) + v6) + __CFSHL__(2 * (blocks_ypos & 0xF0), 1)) & 3;
      R4_ = (blocks_xpos & 0xF0) >> 3;
      R7_ = R4_ | R5_ & 0xC0;
      uint16 v7, v8;
      if ((R9_ & 1) != 0) {
        v7 = mirror_current_layer1_xpos;
        v8 = mirror_current_layer1_ypos - 128;
        if (misc_current_layer_being_processed) {
          v7 = mirror_current_layer2_xpos - 128;
          v8 = mirror_current_layer2_ypos;
        }
      } else {
        v7 = mirror_current_layer1_xpos - 128;
        v8 = mirror_current_layer1_ypos;
        if (misc_current_layer_being_processed) {
          v7 = mirror_current_layer2_xpos;
          v8 = mirror_current_layer2_ypos - 128;
        }
      }
      R8_W = v7;
      R10_W = v8;
      GenerateTile_00BFBC();
    }
  }
}

void GenerateTile_00BFBC() {  // 00bfbc
  kGenerateTile_TileGenerationPtr[(uint8)(blocks_map16_to_generate - 1)]();
}

void SetItemMemoryBit() {  // 00c00d
  R4_W = (uint16)(blocks_xpos & 0xFF00) >> 6;
  R4_W |= (uint8)(blocks_xpos & 0x80) >> 7;
  if ((blocks_ypos & 0x100) != 0)
    R4_W |= 2;
  R4_W += kSetItemMemoryBit_DATA_00BFFF[(uint16)(2 * (misc_item_memory_setting & 0xF)) >> 1];
  misc_item_memory_bits[R4_W] |= kSetItemMemoryBit_DATA_00C005[(uint8)(blocks_xpos & 0x70) >> 4];
}

void sub_C074() {  // 00c074
  SetItemMemoryBit();
  sub_C077();
}

void sub_C077() {  // 00c077
  R4_W = blocks_ypos & 0x1F0;
  uint16 v0 = blocks_ypos & 0x1F0 | ((uint8)blocks_xpos >> 4);
  uint16 v1 = blocks_map16_to_generate;
  uint8 *v2 = IndirPtr(&ptr_hi_map16_data, v0);
  IndirWriteByte(&ptr_hi_map16_data, v0, *v2 & 0xFE);
  uint8 v3 = kGenericPage00Tile_Map16Page00TileLo[v1];
  IndirWriteByte(&ptr_lo_map16_data, v0, v3);
  GenericPage01Tile_00C0FB(2 * v3);
}

void GenericPage01Tile_SetItemMemory() {  // 00c0c1
  SetItemMemoryBit();
  GenericPage01Tile();
}

void GenericPage01Tile() {  // 00c0c4
  R4_W = blocks_ypos & 0x1F0;
  uint16 v0 = blocks_ypos & 0x1F0 | ((uint8)blocks_xpos >> 4);
  uint16 v1 = (uint8)(blocks_map16_to_generate - 9);
  uint8 *v2 = IndirPtr(&ptr_hi_map16_data, v0);
  IndirWriteByte(&ptr_hi_map16_data, v0, *v2 | 1);
  uint8 v3 = kGenericPage01Tile_Map16Page01TileLo[v1];
  IndirWriteByte(&ptr_lo_map16_data, v0, v3);
  GenericPage01Tile_00C0FB(2 * (v3 | 0x100));
}

void GenericPage01Tile_00C0FB(uint16 j) {  // 00c0fb
  R0_W = *(uint16 *)&misc_level_layout_flags;
  if (misc_current_layer_being_processed)
    R0_W >>= 1;
  if ((R0_W & 1) == 0) {
    uint16 v1 = R8_W & 0xFFF0;
    if ((R8_W & 0x8000) == 0) {
      if (v1 == R12_W)
        goto LABEL_15;
      if (v1 >= R12_W)
        return;
    }
    uint16 v2 = v1 + 512;
    if (v2 == R12_W || v2 < R12_W)
      return;
LABEL_15:;
    uint16 v5 = stripe_image_upload;
    uint8 v6 = R6_;
    stripe_image_upload_data[v5] = v6;
    stripe_image_upload_data[v5 + 8] = v6;
    uint8 v8 = R7_;
    stripe_image_upload_data[v5 + 1] = v8;
    stripe_image_upload_data[v5 + 9] = v8 + 32;
    stripe_image_upload_data[v5 + 2] = 0;
    stripe_image_upload_data[v5 + 10] = 0;
    stripe_image_upload_data[v5 + 3] = 3;
    stripe_image_upload_data[v5 + 11] = 3;
    stripe_image_upload_data[v5 + 16] = -1;
    R6_ = 13;
    R4_W = pointer_map16_tiles[j >> 1];
    *(uint16 *)&stripe_image_upload_data[v5 + 4] = *(uint16 *)IndirPtr(&R4_W, 0);
    *(uint16 *)&stripe_image_upload_data[v5 + 12] = *(uint16 *)IndirPtr(&R4_W, 2);
    *(uint16 *)&stripe_image_upload_data[v5 + 6] = *(uint16 *)IndirPtr(&R4_W, 4);
    *(uint16 *)&stripe_image_upload_data[v5 + 14] = *(uint16 *)IndirPtr(&R4_W, 6);
    stripe_image_upload = v5 + 16;
    return;
  }
  uint16 v3 = R10_W & 0xFFF0;
  if ((R10_W & 0x8000) == 0) {
    if (v3 == R14_W)
      goto LABEL_15;
    if (v3 >= R14_W)
      return;
  }
  uint16 v4 = v3 + 512;
  if (v4 != R14_W && v4 >= R14_W)
    goto LABEL_15;
}

void GenericPage01Tile_Return00C1AB() {  // 00c1ab
  ;
}

void EraseYoshiCoin() {  // 00c1ac
  SetItemMemoryBit();
  R4_W = blocks_ypos & 0x1F0;
  uint16 v0 = blocks_ypos & 0x1F0 | ((uint8)blocks_xpos >> 4);
  IndirWriteByte(&ptr_lo_map16_data, v0, 0x25);
  IndirWriteByte(&ptr_lo_map16_data, v0 + 16, 0x25);
  R0_W = *(uint16 *)&misc_level_layout_flags;
  if (misc_current_layer_being_processed)
    R0_W >>= 1;
  if ((R0_W & 1) == 0) {
    uint16 v1 = R8_W & 0xFFF0;
    if ((R8_W & 0x8000) != 0)
      goto LABEL_7;
    if (v1 != R12_W) {
      if (v1 >= R12_W)
        return;
LABEL_7:
      if ((uint16)(v1 + 512) <= R12_W)
        return;
    }
LABEL_14:;
    uint16 v4 = stripe_image_upload;
    uint8 v5 = R6_;
    int v6 = stripe_image_upload;
    stripe_image_upload_data[stripe_image_upload] = R6_;
    stripe_image_upload_data[v6 + 12] = v5;
    uint8 v7 = R7_;
    stripe_image_upload_data[v4 + 1] = R7_;
    stripe_image_upload_data[v4 + 13] = v7 + 1;
    stripe_image_upload_data[v4 + 2] = 0x80;
    stripe_image_upload_data[v4 + 14] = 0x80;
    stripe_image_upload_data[v4 + 3] = 7;
    stripe_image_upload_data[v4 + 15] = 7;
    stripe_image_upload_data[v4 + 24] = -1;
    R6_ = 13;
    R4_W = pointer_map16_tiles[37];
    uint8 *v8 = IndirPtr(&R4_W, 0);
    int16 v9 = *(uint16 *)v8;
    *(uint16 *)&stripe_image_upload_data[v4 + 4] = *(uint16 *)v8;
    *(uint16 *)&stripe_image_upload_data[v4 + 8] = v9;
    uint8 *v10 = IndirPtr(&R4_W, 2);
    int16 v11 = *(uint16 *)v10;
    *(uint16 *)&stripe_image_upload_data[v4 + 16] = *(uint16 *)v10;
    *(uint16 *)&stripe_image_upload_data[v4 + 20] = v11;
    uint8 *v12 = IndirPtr(&R4_W, 4);
    int16 v13 = *(uint16 *)v12;
    *(uint16 *)&stripe_image_upload_data[v4 + 6] = *(uint16 *)v12;
    *(uint16 *)&stripe_image_upload_data[v4 + 10] = v13;
    uint8 *v14 = IndirPtr(&R4_W, 6);
    int16 v15 = *(uint16 *)v14;
    *(uint16 *)&stripe_image_upload_data[v4 + 18] = *(uint16 *)v14;
    *(uint16 *)&stripe_image_upload_data[v4 + 22] = v15;
    stripe_image_upload = v4 + 24;
    return;
  }
  uint16 v2 = R10_W & 0xFFF0;
  if ((R10_W & 0x8000) == 0) {
    if (v2 == R14_W)
      goto LABEL_14;
    if (v2 >= R14_W)
      return;
  }
  uint16 v3 = v2 + 512;
  if (v3 != R14_W && v3 >= R14_W)
    goto LABEL_14;
}

void ChangeNetDoorTiles() {  // 00c334
  ++R7_;
  AddHiLo(&R6_, &R7_, 32);
  R0_ = blocks_map16_to_generate - 25;
  R4_ = *(&kChangeNetDoorTiles_DATA_00C32E[0].bank + (3 * (blocks_map16_to_generate - 25)));
  R2_W = *(uint16 *)((int8 *)&kChangeNetDoorTiles_DATA_00C32E[0].addr + (3 * (blocks_map16_to_generate - 25)));
  uint16 v1 = stripe_image_upload;
  for (int16 i = 5; i >= 0; --i) {
    stripe_image_upload_data[v1] = R6_;
    stripe_image_upload_data[v1 + 1] = R7_;
    stripe_image_upload_data[v1 + 2] = 0;
    stripe_image_upload_data[v1 + 3] = 11;
    AddHiLo(&R6_, &R7_, 32);
    v1 += 16;
  }
  uint16 v3 = stripe_image_upload;
  uint16 v4 = 0;
  do {
    R0_W = 5;
    do {
      *(uint16 *)&stripe_image_upload_data[v3 + 4] = *(uint16 *)IndirPtr(&R2_W, v4);
      v4 += 2;
      v3 += 2;
    } while ((--R0_W & 0x8000) == 0);
    v3 += 4;
  } while (v4 != 72);
  *(uint16 *)&stripe_image_upload_data[v3] = 255;
  stripe_image_upload += 96;
}

void EraseLargeSwitch() {  // 00c3d1
  R4_W = blocks_ypos & 0x1F0;
  uint16 v0 = blocks_ypos & 0x1F0 | ((uint8)blocks_xpos >> 4);
  uint16 v1 = stripe_image_upload;
  IndirWriteByte(&ptr_lo_map16_data, v0++, 0x25);
  IndirWriteByte(&ptr_lo_map16_data, v0, 0x25);
  v0 += 16;
  IndirWriteByte(&ptr_lo_map16_data, v0, 0x25);
  IndirWriteByte(&ptr_lo_map16_data, v0 - 1, 0x25);
  for (int16 i = 3; i >= 0; --i) {
    stripe_image_upload_data[v1] = R6_;
    stripe_image_upload_data[v1 + 1] = R7_;
    stripe_image_upload_data[v1 + 2] = 64;
    stripe_image_upload_data[v1 + 3] = 6;
    *(uint16 *)&stripe_image_upload_data[v1 + 4] = 0x18f8;
    v1 += 6;
    AddHiLo(&R6_, &R7_, 32);
  }
  stripe_image_upload_data[v1] = -1;
  stripe_image_upload = v1;
}

void GameMode14_InLevel_00C47E() {  // 00c47e
  player_hide_player_tile_flags = 0;
  if ((unusedram_got_invincible_star_from_goal & 0x80) != 0) {
    GivePlayerStarPower();
    unusedram_got_invincible_star_from_goal = 0;
  }
  if (timer_end_level_via_keyhole) {
    player_freeze_player_flag = timer_end_level_via_keyhole;
    flag_sprites_locked = timer_end_level_via_keyhole;
    uint8 v0 = flag_keyhole_anim_phase;
    if (timer_hdmawindow_scaling_factor == kGameMode14_InLevel_DATA_00C470[flag_keyhole_anim_phase]) {
      uint8 v1 = timer_end_level_via_keyhole - 1;
      if (timer_end_level_via_keyhole == 1) {
        ++flag_keyhole_anim_phase;
        if (!(v0 & 1))
          goto LABEL_11;
        ClearOutNormalSpriteSlots();
        PlayerState00_LevelFinished(0xB, 2);
        v1 = 0;
      }
      timer_end_level_via_keyhole = v1;
    } else {
      timer_hdmawindow_scaling_factor += kGameMode14_InLevel_DATA_00C474[flag_keyhole_anim_phase];
      mirror_bg1_and2_window_mask_settings = 34;
      mirror_bg3_and4_window_mask_settings = 2;
      mirror_object_and_color_window_settings = kGameMode14_InLevel_DATA_00C478[flag_keyhole_anim_phase];
      mirror_color_math_initial_settings = 18;
      R4_W = 0xCB93;
      R6_W = 0;
      R0_ = temp1436 - mirror_current_layer1_xpos + 4;
      R1_ = temp1438 - mirror_current_layer1_ypos + 16;
      UpdateHDMAWindowBuffer_KeyholeEntry(temp1438 - mirror_current_layer1_ypos + 16);
    }
  }
LABEL_11:
  if (!player_freeze_player_flag) {
    if (!flag_sprites_locked) {
      ++counter_local_frames;
      uint8 v2 = 19;
      do {
        if (*(&timer_level_end_fade + v2))
          --*(&timer_level_end_fade + v2);
      } while (--v2);
      if ((counter_local_frames & 3) == 0) {
        if (flag_active_bonus_game) {
          if (timer_bonus_game_end == 68)
            io_music_ch1 = 20;
          if (timer_bonus_game_end == 1)
            misc_game_mode = 11;
        }
        uint8 v3 = timer_blue_pswitch;
        if (timer_blue_pswitch < timer_silver_pswitch)
          v3 = timer_silver_pswitch;
        if ((misc_music_register_backup & 0x80) == 0 && v3 == 1) {
          v3 = spr45_directional_coins_despawn_timer;
          if (!spr45_directional_coins_despawn_timer)
            io_music_ch1 = misc_music_register_backup;
        }
        if (misc_music_register_backup != 0xFF && v3 == 30)
          io_sound_ch3 = 36;
        uint8 v4 = 6;
        do {
          if (*(&unusedram_7e14a8 + v4))
            --*(&unusedram_7e14a8 + v4);
        } while (--v4);
      }
    }
    GameMode14_InLevel_HandlePlayerState();
    if ((io_controller_press1 & 0x20) != 0)
      DropReservedItem();
  }
  blocks_note_block_bounce_flag = 0;
}

void GameMode14_InLevel_Return00C592() {  // 00c592
  ;
}

void GameMode14_InLevel_HandlePlayerState() {  // 00c593
  kGameMode14_InLevel_PlayerStatePtrs[player_current_state]();
}

void PlayerState0B_RescuedPeach() {  // 00c5b5
  player_override_walking_frames = 0;
  player_sliding_on_ground = 0;
  if (timer_end_level) {
    CreditsFadeOut();
    if (misc_game_mode != 20) {
      PlayerState00_00C95B();
      return;
    }
  } else {
    mirror_hdmaenable = 0;
  }
  flag_message_window_size_change_direction = 1;
  blocks_screen_to_place_current_object = 7;
  DamagePlayer_DisableButtons();
  PlayerState00_00CD24();
}

void PlayerState0C_CastleDestructionMoves() {  // 00c6e7
  int8 v0;
  uint8 v1, v2;

  DamagePlayer_DisableButtons();
  player_override_walking_frames = 0;
  UpdatePlayerSpritePosition();
  if ((player_yspeed & 0x80) == 0) {
    if ((uint8)player_ypos >= 0x58) {
      player_in_air_flag = 0;
      v0 = 88;
      goto LABEL_14;
    }
    if ((uint8)player_xpos >= 0x40) {
      if ((uint8)player_xpos < 0x60) {
        if ((uint8)player_ypos >= 0x4C) {
          io_sound_ch3 = 27;
          ++l1_l2_scroll_spr_spriteid[0];
          v0 = 76;
          v2 = -12;
          v1 = -64;
          goto LABEL_11;
        }
      } else if ((uint8)mirror_current_layer1_ypos && !sign8(mirror_current_layer1_ypos + player_ypos - 28)) {
        v0 = player_ypos;
        v1 = -48;
        if (!player_facing_direction) {
LABEL_12:
          player_yspeed = v1;
          io_sound_ch1 = 1;
LABEL_14:
          LOBYTE(player_ypos) = v0;
          goto LABEL_15;
        }
        v2 = 0;
LABEL_11:
        player_xspeed = v2;
        goto LABEL_12;
      }
    }
  }
LABEL_15:;
  uint8 v3 = *(&kPlayerState0C_CastleDestructionMoves_UNK_00C6DF + misc_currently_active_boss_end_cutscene) + temp8f;
  if (!player_timer_pipe_warping) {
    temp8f += 2;
    v3 += 2;
    player_timer_pipe_warping = kPlayerState0C_CastleDestructionMoves_DATA_00C5E9[v3];
    if (*(&kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData + v3) == 45)
      io_sound_ch1 = 30;
  }
  if (*(&kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData + v3) != 0xFF) {
    uint8 v10 = *(&kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData + v3);
    if ((v10 & 0x10) != 0)
      DrawQuestionMark();
    if ((v10 & 0x20) != 0) {
      uint8 v4 = v10 & 0xF;
      if ((v10 & 0xF) >= 7) {
        player_current_pose = kPlayerState0C_CastleDestructionMoves_DATA_00C5E1[v4 - 7];
        player_carrying_something_flag2 = 0;
        HandlePlayerPhysics_InAir();
        goto LABEL_40;
      }
      int8 v5 = v4 - 1;
      if (v5 >= 0) {
        if (!v5) {
          ++l1_l2_scroll_spr_timer[1];
          goto LABEL_40;
        }
        int8 v6 = v5 - 1;
        if (!v6) {
          io_sound_ch1 = 14;
          PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
          ++LOBYTE(pt->x);
          goto LABEL_40;
        }
        int8 v8 = v6 - 1;
        if (!v8) {
          l1_l2_scroll_spr_timer[1] = -120;
          goto LABEL_40;
        }
        int8 v9 = v8 - 1;
        if (!v9) {
          LOBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)->x) = 56;
          LOBYTE(player_xpos) = player_xpos & 0xF8;
          goto LABEL_40;
        }
        if (v9 != 1) {
          timer_display_player_pick_up_pose = 32;
          ++player_carrying_something_flag2;
          goto LABEL_40;
        }
        io_sound_ch3 = 9;
        player_xspeed = -40;
        ++l1_l2_scroll_spr_spriteid[0];
      } else if (timer_display_player_pick_up_pose) {
        io_sound_ch1 = 9;
      }
      ++l1_l2_scroll_spr_spriteid[0];
    } else {
      io_controller_hold1 = v10;
      io_controller_press1 = v10 & 0xBF;
      PlayerState00_00CD39();
    }
LABEL_40:
    --player_timer_pipe_warping;
  }
}

void PlayerState08_WarpToYoshiWingsBonus() {  // 00c7fd
  DamagePlayer_DisableButtons();
  player_in_air_flag = 11;
  HandlePlayerPhysics_InAir();
  if ((int8)player_yspeed >= -112)
    player_yspeed -= 13;
  int8 v0 = 2;
  if (player_xspeed) {
    if ((player_xspeed & 0x80) == 0)
      v0 = -2;
    uint8 old_speed = player_xspeed;
    player_xspeed += v0;
    if ((old_speed & 0x80) == (v0 & 0x80) && (v0 & 0x80) != (player_xspeed & 0x80))  // ovf
      player_xspeed = 0;
  }
  UpdatePlayerSpritePosition();
  if ((int16)(player_on_screen_pos_y - kPlayerState08_WarpToYoshiWingsBonus_DATA_00C7F9[in_yoshi_wings_bonus_area >> 1]) < 0) {
    player_current_state = 0;
    if (!in_yoshi_wings_bonus_area) {
      in_yoshi_wings_bonus_area = 2;
      IncrementSublevelsEnteredAndPrepareToLoadSublevel();
    }
  }
  PlayerState08_WarpToYoshiWingsBonus_00C845();
}

void PlayerState08_WarpToYoshiWingsBonus_00C845() {  // 00c845
  PlayerState00_00CD8F();
}

void PlayerState0A_NoYoshiCutscene() {  // 00c870
  player_spinjump_fireball_timer = 0;
  int8 v0 = kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting];
  if (v0 < 0) {
    DrawBigCastleGate();
  } else if ((v0 & 0x40) != 0) {
    DrawNoYoshiSign();
  } else {
    DrawGhostHouseEntranceDoor();
  }
  uint8 v1 = player_timer_pipe_warping;
  int8 v2 = io_controller_press2 | io_controller_press1;
  DamagePlayer_DisableButtons();
  if (v2 < 0)
    goto LABEL_23;
  player_override_walking_frames = 0;
  if (!--player_pipe_action) {
    v1 += 2;
    player_timer_pipe_warping = v1;
    player_pipe_action = kPlayerState0A_NoYoshiCutscene_DATA_00C848[v1 - 1];
  }
  if (kPlayerState0A_NoYoshiCutscene_DATA_00C848[v1 - 2] == 0xFF) {
LABEL_23:
    ++flag_show_player_start;
    misc_game_mode = 15;
    if (v1 >= 0x11)
      ++yoshi_carry_over_levels_flag;
    PlayerState0A_NoYoshiCutscene_00C90A();
  } else {
    uint8 v3 = kPlayerState0A_NoYoshiCutscene_DATA_00C848[v1 - 2] & 0xDF;
    io_controller_hold1 = v3;
    if (v3 != kPlayerState0A_NoYoshiCutscene_DATA_00C848[v1 - 2])
      io_controller_press2 = 0x80;
    if ((v3 & 0x40) != 0) {
      DamagePlayer_DisableButtons();
      uint8 v4 = -80;
      if ((kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting] & 0x80) == 0)
        v4 = 127;
      timer_no_yoshi_intro_door_timer = v4;
    }
    UpdatePlayerSpritePosition();
    player_in_air_flag = 36;
    uint8 v5 = player_riding_yoshi_flag ? 95 : 111;
    if ((kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting] & 0x40) != 0)
      v5 -= 16;
    if (v5 < (uint8)player_ypos) {
      LOBYTE(player_ypos) = v5 + 1;
      player_in_air_flag = 0;
      player_spin_jump_flag = 0;
    }
    PlayerState00_00CD82();
  }
}

void PlayerState0A_NoYoshiCutscene_00C90A() {  // 00c90a
  flag_prevent_yoshi_carry_over = 1;
  io_sound_ch2 = 3;
}

void PlayerState00_HandleEndOfLevel() {  // 00c915
  DamagePlayer_DisableButtons();
  flag_player_in_lakitus_cloud = 0;
  player_override_walking_frames = 0;
  player_sliding_on_ground = 0;
  if (!(misc_level_layout_flags & 1)) {
    if (!(misc_color_of_palace_switch_pressed1 | misc_currently_active_boss_end_cutscene)) {
      PlayerState00_00C96B();
      return;
    }
    if (player_in_air_flag)
      PlayerState00_00CCE0();
    if (misc_color_of_palace_switch_pressed1)
      goto LABEL_9;
    PlayerState00_00B03E();
    if (timer_level_end_fade < 0x40)
      return;
  }
  ProcessLevelEndRoutines();
LABEL_9:
  flag_sprites_locked = 1;
  if ((counter_global_frames & 1) && !--timer_end_level) {
    if (misc_color_of_palace_switch_pressed1)
      PlayerState00_00C962();
    else
      PlayerState00_00C95B();
  }
}

void PlayerState00_00C95B() {  // 00c95b
  PlayerState00_LevelFinished(0xB, 1);
}

void PlayerState00_00C962() {  // 00c962
  timer_title_screen_input_timer = -96;
  ++misc_display_message;
}

void PlayerState00_00C96B() {  // 00c96b
  HandlePaletteFades();
  if (flag_show_victory_pose_during_level_end) {
    PlayerState00_SetMarioPeaceImg();
    if (timer_show_victory_pose) {
      if (!--timer_show_victory_pose)
        io_music_ch1 = 17;
    } else {
      PlayerState00_00CA44();
      io_controller_hold1 = 1;
      PlayerState00_00CD24();
      if (!timer_hdmawindow_scaling_factor) {
        uint8 v0 = flag_secret_goal_sprite + 1;
        if (flag_secret_goal_sprite == 2) {
          ow_players_map[0] = 1;
          v0 = 0;
        }
        uint8 v1 = 12;
        if (flag_active_bonus_game) {
          flag_active_bonus_game = -1;
          mirror_mosaic_size_and_bgenable = -16;
          timer_end_level = 0;
          misc_music_register_backup = 0;
          v1 = 16;
        }
        mirror_screen_display_register = 0;
        misc_mosaic_direction = 0;
        PlayerState00_LevelFinished(v1, v0);
      }
    }
  } else {
    if (timer_end_level >= 0x28) {
      player_facing_direction = 1;
      io_controller_hold1 = 1;
      player_xspeed = 5;
    }
    if (player_in_air_flag)
      HandlePlayerPhysics_00D76B();
    if (!player_xspeed) {
      flag_layer1_horiz_scroll_level_setting = 0;
      PlayerState00_00CA3E();
      ++flag_show_victory_pose_during_level_end;
      timer_show_victory_pose = 64;
      palettes_level_end_color_fade_direction = 0x80;
      timer_level_end_fade = 0;
    }
    PlayerState00_00CD24();
  }
}

void PlayerState00_LevelFinished(uint8 j, uint8 a) {  // 00c9fe
  g_did_finish_level_hook = true;
  misc_exit_level_action = a;
  if (misc_currently_active_boss_end_cutscene) {
    uint8 v2 = 8;
    if (ow_level_number_lo == 19)
      ++misc_exit_level_action;
    if (ow_level_number_lo != 49) {
      while (ow_level_number_lo != kPlayerState00_LevelsThatTriggerCutscenes[v2 - 1]) {
        if (!--v2)
          goto LABEL_9;
      }
    }
    misc_currently_active_boss_end_cutscene = v2;
    j = 24;
  }
LABEL_9:
  misc_game_mode = j;
  ++counter_enemy_rollcall_screen;
  PlayerState00_SetMidpointFlag();
}

void PlayerState00_SetMidpointFlag() {  // 00ca2b
  flag_got_midpoint = 1;
}

void PlayerState00_SetMarioPeaceImg() {  // 00ca31
  player_current_pose = player_riding_yoshi_flag ? 20 : 38;
}

void PlayerState00_00CA3E() {  // 00ca3e
  timer_hdmawindow_scaling_factor = -16;
}

void PlayerState00_00CA44() {  // 00ca44
  if (timer_hdmawindow_scaling_factor) {
    UpdateHDMAWindowBuffer_SetCircleHDMAPointer();
    UpdateHDMAWindowBuffer_IrisInOnPlayerEntry(0xFC);
    mirror_bg1_and2_window_mask_settings = 51;
    mirror_object_and_color_window_settings = 51;
    mirror_bg3_and4_window_mask_settings = 3;
    mirror_color_math_initial_settings = 34;
  }
}

void UpdateHDMAWindowBuffer_SetCircleHDMAPointer() {  // 00ca61
  R4_W = 0xcb12;
  R6_W = 0xcb12;
}

void UpdateHDMAWindowBuffer_IrisInOnPlayerEntry(uint8 a) {  // 00ca6d
  timer_hdmawindow_scaling_factor += a;
  R0_ = player_on_screen_pos_x + 8;
  uint8 v1 = player_current_power_up ? 16 : 24;
  R1_ = player_on_screen_pos_y + v1;
  if (R1_ == 255 || R1_ == 0)
    R1_ = 1;
  UpdateHDMAWindowBuffer_KeyholeEntry(R1_);
}

void UpdateHDMAWindowBuffer_KeyholeEntry(uint8 a) {  // 00ca88
  uint16 v1 = 2 * (2 * a - 1);
  uint16 v2 = 0;
  while (R1_ >= timer_hdmawindow_scaling_factor) {
    if (v2 < 0x1E0) {
      misc_hdmawindow_effect_table[v2] = 255;
      misc_hdmawindow_effect_table[v2 + 1] = 0;
    }
    if (v1 < 0x1C0) {
      misc_hdmawindow_effect_table[v1] = 255;
      misc_hdmawindow_effect_table[v1 + 1] = 0;
    }
    v2 += 2;
    v1 -= 2;
    if (!R1_)
      goto LABEL_21;
    --R1_;
  }
  do {
    UpdateHDMAWindowBuffer_00CC14(v1);
    if (v2 < 0x1e0) {
      misc_hdmawindow_effect_table[v2 + 1] = R0_ + R2_ < 255 ? R0_ + R2_ : 255;
      misc_hdmawindow_effect_table[v2] = R0_ >= R2_ ? R0_ - R2_ : 0;
    }
    if (v1 < 0x1E0) {
      if (R7_) {
        misc_hdmawindow_effect_table[v1 + 1] = R0_ + R3_ < 255 ? R0_ + R3_ : 255;
        misc_hdmawindow_effect_table[v1] = R0_ >= R3_ ? R0_ - R3_ : 0;
      } else {
        misc_hdmawindow_effect_table[v1 + 1] = 0;
        misc_hdmawindow_effect_table[v1] = 255;
      }
    }
    v2 += 2;
    v1 -= 2;
    if (!R1_)
      break;
  } while (--R1_);
LABEL_21:
  mirror_hdmaenable = 0x80;
}

uint8 UpdateHDMAWindowBuffer_00CC14(uint16 j) {  // 00cc14
  uint16 v1 = SnesDivide(R1_ << 8, timer_hdmawindow_scaling_factor) >> 1;
  uint8 t = R6_W ? RomPtr_00(R6_W)[v1] : 0;
  R3_ = (t * timer_hdmawindow_scaling_factor) >> 8;
  uint8 *v3 = RomPtr_00(R4_W);
  uint8 result = (v3[v1] * timer_hdmawindow_scaling_factor) >> 8;
  R2_ = result;
  return result;
}

void PlayerState00() {  // 00cc68
  if ((io_controller_hold2 & 0x20) != 0 && io_controller_press2 == 0x80 && ++debug_free_movement >= 3)
    debug_free_movement = 0;
  if (timer_end_level) {
    PlayerState00_HandleEndOfLevel();
  } else {
    PlayerState00_HandleLRScrolling();
    if (!flag_sprites_locked) {
      flag_cape_to_sprite_interaction = 0;
      player_override_walking_frames = 0;
      if (timer_stun_player) {
        --timer_stun_player;
        player_xspeed = 0;
        player_current_pose = 15;
      } else {
        PlayerState00_00CCE0();
      }
    }
  }
}

void PlayerState00_00CCE0() {  // 00cce0
  if ((misc_nmito_use_flag & 0x80) == 0 || misc_nmito_use_flag & 1) {
    PlayerState00_00CD24();
  } else {
    if ((misc_nmito_use_flag & 0x40) != 0 || player_in_air_flag) {
      UpdatePlayerSpritePosition();
    } else {
      player_xpos = *(uint16 *)&temp1436;
      player_ypos = *(uint16 *)&temp1438;
      UpdatePlayerSpritePosition();
      *(uint16 *)&temp1436 = player_xpos;
      *(uint16 *)&temp14b4 = player_xpos;
      *(uint16 *)&temp1438 = player_ypos & 0xFFF0;
      *(uint16 *)&temp14b6 = player_ypos & 0xFFF0;
      PlayerState00_00F9C9();
    }
    PlayerState00_00F8F2();
    PlayerState00_00CD36();
  }
}

void PlayerState00_00CD24() {  // 00cd24
  if ((player_yspeed & 0x80) != 0 && (player_blocked_flags & 8) != 0)
    player_yspeed = 0;
  UpdatePlayerSpritePosition();
  HandlePlayerLevelCollision();
  PlayerState00_00CD36();
}

void PlayerState00_00CD36() {  // 00cd36
  PlayerState00_CheckPlayerPitFall();
  PlayerState00_00CD39();
}

void PlayerState00_00CD39() {  // 00cd39
  player_turning_around_flag = 0;
  if (timer_inflate_from_pballoon) {
    PlayerState00_00CD95(timer_inflate_from_pballoon);
  } else {
    if (flag_player_climb_on_air)
      temp8b = 31;
    if (player_climbing_flag || !(player_riding_yoshi_flag | player_carrying_something_flag2) && (temp8b & 0x1B) == 27 &&
                                    (io_controller_hold1 & 0xC) != 0 &&
                                    (player_in_air_flag || (io_controller_hold1 & 8) != 0 || (temp8b & 4) != 0)) {
      player_climbing_flag = temp8b;
      HandlePlayerPhysics_Climbing();
    } else if (player_swimming_flag) {
      HandlePlayerPhysics_Swimming();
      PlayerState00_00CD8F();
    } else {
      PlayerState00_00CD82();
    }
  }
}

void PlayerState00_00CD82() {  // 00cd82
  HandlePlayerPhysics();
  CheckPowerUpSpecificPlayerAttacks();
  HandlePlayerPhysics_InAir();
  PlayerState00_00CD8B();
}

void PlayerState00_00CD8B() {  // 00cd8b
  SetPlayerPose();
  PlayerState00_00CD8F();
}

void PlayerState00_00CD8F() {  // 00cd8f
  uint8 v0 = player_riding_yoshi_flag;
  if (player_riding_yoshi_flag) {
    if (timer_yoshi_tongue_is_out) {
      v0 = 3;
      if (timer_yoshi_tongue_is_out < 0xC)
        v0 = 4;
    }
    uint8 v1 = kPlayerState_OnYoshiAnimations[v0 - 1];
    if (v0 == 1 && player_ducking_flag)
      v1 = 29;
    player_current_pose = v1;
    if (yoshi_yoshi_has_wings == 1 && (io_controller_press1 & 0x40) != 0) {
      unusedram_7e18db = 8;
      SpawnPlayerFireball();
    }
  }
}

void PlayerState00_00CD95(uint8 j) {  // 00cd95
  uint8 v1 = player_current_power_up ? 67 : 66;
  uint8 v2 = j - 1;
  if (v2) {
    timer_inflate_from_pballoon = v2;
    v1 = 15;
  }
  player_current_pose = v1;
}

void PlayerState00_HandleLRScrolling() {  // 00cddd
  uint8 v4;

  if (flag_layer1_horiz_scroll_level_setting) {
    uint8 v0 = misc_lrscroll_direction;
    flag_sprites_locked = flag_lrscroll_flag;
    if (flag_lrscroll_flag)
      goto LABEL_17;
    uint8 v1 = camera_lrscroll_move_flag;
    if (camera_lrscroll_move_flag) {
      misc_lrscroll_direction = 0;
    } else {
      if (io_controller_hold1 | io_controller_hold2 & 0xCF)
        goto LABEL_16;
      uint8 v2 = io_controller_hold2 & 0x30;
      if ((io_controller_hold2 & 0x30) == 0 || v2 == 48)
        goto LABEL_16;
      uint8 v3 = v2 >> 3;
      if (++timer_time_before_lrscroll < 0x10 ||
          (v4 = v3, player_relative_position_needed_to_scroll_screen == kHandleStandardLevelCameraScroll_DATA_00F6CB[v3 >> 1])) {
LABEL_17:
        player_facing_directionx2 = 2 * player_facing_direction;
        uint16 v8 = player_relative_position_needed_to_scroll_screen;
        int v9 = v0 >> 1;
        if (player_relative_position_needed_to_scroll_screen != kHandleStandardLevelCameraScroll_DATA_00F6CB[v9]) {
          v8 = kHandleStandardLevelCameraScroll_DATA_00F6BF[v9] + player_relative_position_needed_to_scroll_screen;
          if (v8 != kHandleStandardLevelCameraScroll_DATA_00F6B3[player_facing_directionx2 >> 1]) {
LABEL_21:
            player_relative_position_needed_to_scroll_screen = v8;
            camera_lrscroll_move_flag = 0;
            return;
          }
          misc_lrscroll_direction = 0;
        }
        flag_lrscroll_flag = 0;
        goto LABEL_21;
      }
      player_relative_position_needed_to_scroll_screen &= ~1;
      ++flag_lrscroll_flag;
      uint8 v5 = (v4 == 2) ? camera_last_screen_horiz - 1 : 0;
      if ((v5 << 8) != mirror_current_layer1_xpos)
        io_sound_ch3 = 14;
      v1 = v4;
      misc_lrscroll_direction = v4;
    }
    v0 = v1;
LABEL_16:
    timer_time_before_lrscroll = 0;
    goto LABEL_17;
  }
}

void SetPlayerPose() {  // 00ceb1
  if (timer_cape_flap_animation)
    goto LABEL_26;
  uint8 v0 = player_cape_image;
  uint8 v1;
  if (player_in_air_flag) {
    v1 = 4;
    if ((player_yspeed & 0x80) == 0) {
      v0 = player_cape_image + 1;
      if ((uint8)(player_cape_image + 1) >= 5) {
        if (v0 >= 0xB)
          v0 = 7;
      } else {
        v0 = 5;
      }
      goto LABEL_23;
    }
    if (player_in_air_flag != 12 && !player_swimming_flag)
      goto LABEL_13;
LABEL_19:
    v0 = player_cape_image + 1;
    if ((uint8)(player_cape_image + 1) < 3)
      v0 = 5;
    if (v0 >= 7)
      v0 = 3;
    goto LABEL_23;
  }
  uint8 v2 = player_xspeed;
  if (player_xspeed) {
    if ((player_xspeed & 0x80) != 0)
      v2 = -player_xspeed;
    v1 = kSetPlayerPose_AnimationSpeedTable[v2 >> 3];
    goto LABEL_19;
  }
  v1 = 8;
LABEL_13:
  if (player_cape_image) {
    v0 = player_cape_image - 1;
    if ((uint8)(player_cape_image - 1) >= 3)
      v0 = 2;
  }
LABEL_23:
  player_cape_image = v0;
  uint8 v3 = v1;
  if (player_swimming_flag)
    v3 = 2 * v1;
  timer_cape_flap_animation = v3;
LABEL_26:
  if (!(timer_active_cape_spin | player_spin_jump_flag)) {
    uint8 v7 = player_sliding_on_ground;
    if (player_sliding_on_ground) {
      if ((player_sliding_on_ground & 0x80) != 0)
        v7 = kSetPlayerPose_DATA_00CE7F[player_facing_direction | (player_slope_player_is_on1 >> 2)];
      goto LABEL_57;
    }
    v7 = 60;
    if (player_carrying_something_flag2)
      v7 = 29;
    if (player_ducking_flag)
      goto LABEL_57;
    if (timer_display_player_shoot_fireball_pose) {
      v7 = 63;
      if (player_in_air_flag)
        v7 = 22;
      goto LABEL_57;
    }
    v7 = 14;
    if (!timer_display_player_kicking_pose) {
      v7 = 29;
      if (!timer_display_player_pick_up_pose) {
        v7 = 15;
        if (!timer_display_player_face_screen_pose) {
          if (flag_player_in_lakitus_cloud) {
            SetPlayerPose_Entry3(0);
            return;
          }
          v7 = player_in_air_flag;
          if (player_in_air_flag) {
            if (!timer_show_running_frames_before_take_off) {
              if (player_cape_flying_phase)
                v7 = kSetPlayerPose_DATA_00CE79[player_cape_flying_phase - 1];
              if (player_carrying_something_flag2) {
                SetPlayerPose_Entry4(9);
                return;
              }
              goto LABEL_57;
            }
LABEL_58:
            SetPlayerPose_Entry2();
            return;
          }
          v7 = player_turning_around_flag;
          if (!player_turning_around_flag)
            goto LABEL_58;
        }
      }
    }
LABEL_57:
    SetPlayerPose_Entry4(v7);
    return;
  }
  player_ducking_flag = 0;
  uint8 v4 = counter_local_frames & 6;
  uint8 v5 = counter_local_frames & 6;
  if (player_in_air_flag && (player_yspeed & 0x80) == 0)
    ++v5;
  player_cape_image = kSetPlayerPose_DATA_00CEA9[v5];
  if (player_current_power_up)
    ++v4;
  uint8 v6 = kSetPlayerPose_DATA_00CEA1[v4];
  player_facing_direction = v6;
  if (player_current_power_up == 2)
    InitializeCapeSwingOrNetPunch(v6);
  SetPlayerPose_Entry4(kSetPlayerPose_DATA_00CE99[v4]);
}

void SetPlayerPose_Entry2() {  // 00cfbc
  if ((player_xspeed & 0x80) != 0)
    SetPlayerPose_Entry3(-player_xspeed);
  else
    SetPlayerPose_Entry3(player_xspeed);
}

void SetPlayerPose_Entry3(uint8 a) {  // 00cfc3
  uint8 v2, v3;
  if (!a) {
    v2 = 0;
    if ((io_controller_hold1 & 8) != 0)
      player_override_walking_frames = 3;
LABEL_11:
    v3 = v2;
    goto LABEL_12;
  }
  if (flag_ice_level) {
    v3 = io_controller_hold1 & 3;
    if ((io_controller_hold1 & 3) == 0)
      goto LABEL_12;
    player_anim_speed_index = 104;
  }
  v3 = player_walking_frame;
  if (!player_anim_timer) {
    uint8 v4 = player_walking_frame - 1;
    if ((int8)v4 < 0)
      v4 = kSetPlayerPose_WalkingPoseCount[player_current_power_up];
    v2 = v4;
    player_anim_timer = kSetPlayerPose_AnimationSpeedTable[player_anim_speed_index | (a >> 3)];
    goto LABEL_11;
  }
LABEL_12:
  player_walking_frame = v3;
  uint8 v5 = player_override_walking_frames + v3;
  if (player_carrying_something_flag2) {
    SetPlayerPose_Entry4(v5 + 7);
  } else if (a >= 0x2F) {
    SetPlayerPose_Entry4((a >= 0x2F) + v5 + 3);
  } else {
    SetPlayerPose_Entry4(v5);
  }
}

void SetPlayerPose_Entry4(uint8 a) {  // 00d01a
  if (player_wall_walk_status) {
    player_facing_direction = player_wall_walk_status & 1;
    a = 16;
    if (player_wall_walk_status >= 6)
      a = player_walking_frame + 17;
  }
  player_current_pose = a;
}

void InitializeCapeSwingOrNetPunch(uint8 a) {  // 00d044
  flag_cape_to_sprite_interaction = 1;
  int v1 = (uint8)(2 * a) >> 1;
  player_cape_hitbox_x = kInitializeCapeSwingOrNetPunch_DATA_00D034[v1] + player_xpos;
  player_cape_hitbox_y = kInitializeCapeSwingOrNetPunch_DATA_00D03C[v1] + player_ypos;
}

void CheckPowerUpSpecificPlayerAttacks() {  // 00d062
  if (player_current_power_up == 2) {
    if ((io_controller_press1 & 0x40) != 0 && !(player_spin_jump_flag | (uint8)(player_riding_yoshi_flag | player_ducking_flag))) {
      timer_active_cape_spin = 18;
      io_sound_ch3 = 4;
    }
  } else if (player_current_power_up == 3 && !(player_riding_yoshi_flag | player_ducking_flag)) {
    if ((io_controller_press1 & 0x40) == 0) {
      if (!player_spin_jump_flag || (++player_spinjump_fireball_timer & 0xF) != 0)
        return;
      player_facing_direction = (player_spinjump_fireball_timer & 0x10) != 0;
    }
    SpawnPlayerFireball();
  }
}

void PlayerState09_Death() {  // 00d0b6
  player_current_power_up = 0;
  player_current_pose = 62;
  if ((counter_global_frames & 3) == 0)
    --player_anim_timer;
  if (!player_anim_timer) {
    misc_exit_level_action = 0x80;
    if (!flag_prevent_yoshi_carry_over)
      yoshi_carry_over_levels_flag = 0;
    if ((--player_current_life_count & 0x80) == 0) {
      if (counter_timer_ones | counter_timer_tens | counter_timer_hundreds) {
        misc_game_mode = 11;
        return;
      }
      misc_death_message_to_display = 29;
    } else {
      io_music_ch1 = 10;
      misc_death_message_to_display = 20;
    }
    timer_display_death_message_animation = -64;
    timer_time_to_display_death_message = -1;
    misc_game_mode = 21;
    return;
  }
  if (player_anim_timer < 0x26) {
    player_xspeed = 0;
    UpdatePlayerSpritePosition();
    HandlePlayerPhysics_D930(0);
    player_facing_direction = (counter_global_frames & 4) != 0;
  }
}

void PlayerStateXX_PowerupAnims_PowerDownEntry() {  // 00d129
  if (player_anim_timer) {
    player_current_pose = kPlayerStateXX_PowerupAnims_GrowingAniImgs[player_anim_timer >> 2];
    if (player_anim_timer)
      --player_anim_timer;
  } else {
    timer_player_hurt = 127;
    PlayerStateXX_PowerupAnims_Done();
  }
}

void PlayerStateXX_PowerupAnims_GrowAnimationEntry() {  // 00d147
  if (player_anim_timer) {
    player_current_pose = kPlayerStateXX_PowerupAnims_GrowingAniImgs[11 - (player_anim_timer >> 2)];
    if (player_anim_timer)
      --player_anim_timer;
  } else {
    ++player_current_power_up;
    PlayerStateXX_PowerupAnims_Done();
  }
}

void PlayerStateXX_PowerupAnims_Done() {  // 00d158
  player_current_state = 0;
  flag_sprites_locked = 0;
}

void PlayerStateXX_PowerupAnims_GotCape() {  // 00d15f
  player_hide_player_tile_flags = 127;
  if (!--player_anim_timer) {
    if (!(player_current_power_up >> 1))
      timer_player_hurt = 127;
    PlayerStateXX_PowerupAnims_Done();
  }
}

void PlayerStateXX_PowerupAnims_GotFlower() {  // 00d16f
  if (player_cape_flying_phase | player_sliding_on_ground & 0x80) {
    player_cape_flying_phase = 0;
    player_sliding_on_ground &= ~0x80;
    player_current_pose = 0;
  }
  if (!--timer_player_palette_cycle)
    PlayerStateXX_PowerupAnims_Done();
}

void PlayerStateXX_EnterPipe_Horizontal() {  // 00d197
  DamagePlayer_DisableButtons();
  player_override_walking_frames = 0;
  SetPlayerPose();
  SetPlayerPose_Entry2();
  PlayerStateXX_EnterPipe_00D1F4();
  if (player_riding_yoshi_flag)
    player_current_pose = 41;
  player_ypos = (player_ypos - 8) & 0xFFF0 | 0xE;
  uint8 v0 = (player_pipe_action >> 1) + 1;
  uint8 v1 = kPlayerStateXX_EnterPipe_HIDEPIPESETS[v0 - 1];
  if (player_carrying_something_flag2) {
    v1 ^= 0x1C;
    --timer_display_player_face_screen_pose;
    timer_display_player_face_screen_pose += (timer_display_player_face_screen_pose & 0x80) != 0;
  }
  if (player_timer_pipe_warping < 0x1D) {
    if (v0 >= 3) {
      ++player_ypos;
      ++player_ypos;
    }
    v1 = kPlayerStateXX_EnterPipe_HIDEPIPESETS[v0];
  }
  player_hide_player_tile_flags = v1;
  PlayerStateXX_EnterPipe_00D22D();
}

void PlayerStateXX_EnterPipe_00D1F4() {  // 00d1f4
  if (timer_cape_flap_animation)
    --timer_cape_flap_animation;
  if (player_anim_timer)
    --player_anim_timer;
}

void PlayerStateXX_EnterPipe_Vertical() {  // 00d203
  DamagePlayer_DisableButtons();
  player_cape_image = 0;
  uint8 pose = 15;
  if (player_riding_yoshi_flag) {
    uint8 v1 = 0;
    if ((player_xpos & 0xF) != kPlayerStateXX_EnterPipe_PipeCntrBoundryX[player_facing_direction]) {
      if ((int8)((player_xpos & 0xF) - kPlayerStateXX_EnterPipe_PipeCntrBoundryX[player_facing_direction]) < 0)
        v1 = 1;
      LOBYTE(player_xpos) = kPlayerStateXX_EnterPipe_PipeCntringSpeed[v1] + player_xpos;
    }
    pose = 33;
  }
  player_current_pose = pose;
  PlayerStateXX_EnterPipe_00D22D();
}

void PlayerStateXX_EnterPipe_00D22D() {  // 00d22d
  io_controller_hold1 = 64;
  player_current_layer_priority = 2;
  if (player_timer_pipe_warping) {
    uint8 v0 = player_pipe_action & 3;
    if (!--player_timer_pipe_warping && player_pipe_action < 4) {
      player_hide_player_tile_flags = 127;
      ++flag_about_to_warp_in_pipe;
    }
    if (!(player_yspeed | player_xspeed))
      io_sound_ch1 = 4;
    player_xspeed = kPlayerStateXX_EnterPipe_PipeXSpeed[v0];
    player_yspeed = kPlayerStateXX_EnterPipe_PipeYSpeed[v0];
    player_in_air_flag = 0;
    UpdatePlayerSpritePosition();
  } else {
    if (player_pipe_action < 4)
      IncrementSublevelsEnteredAndPrepareToLoadSublevel();
    else
      PlayerStateXX_EnterPipe_00D26A();
  }
}

void PlayerStateXX_EnterPipe_00D26A() {  // 00d26a
  player_current_layer_priority = 0;
  yoshi_in_pipe = 0;
  PlayerStateXX_PowerupAnims_Done();
}

void IncrementSublevelsEnteredAndPrepareToLoadSublevel() {  // 00d273
  ++counter_sublevels_entered;
  misc_game_mode = 15;
}

void UnusedAddToWarpPipeTimerRoutine() {  // 00d27c
  player_timer_pipe_warping += player_ypos - player_current_ypos;
}

void PlayerState07_ShootOutOfPipe() {  // 00d287
  DamagePlayer_DisableButtons();
  player_current_layer_priority = 2;
  player_in_air_flag = 12;
  PlayerState00_00CD8B();
  if (!--player_timer_pipe_warping) {
    PlayerStateXX_EnterPipe_00D26A();
    return;
  }
  if (player_timer_pipe_warping < 0x18)
    goto LABEL_6;
  if (player_timer_pipe_warping == 24) {
    io_sound_ch3 = 9;
LABEL_6:
    player_current_layer_priority = 0;
    yoshi_in_pipe = 0;
    flag_sprites_locked = 0;
  }
  player_xspeed = 64;
  player_yspeed = -64;
  UpdatePlayerSpritePosition();
}

void HandlePlayerPhysics() {  // 00d5f2
  uint8 v4;
  if (!player_in_air_flag) {
    player_ducking_flag = 0;
    if (!player_sliding_on_ground && (io_controller_hold1 & 4) != 0) {
      player_ducking_flag = io_controller_hold1 & 4;
      flag_cape_to_sprite_interaction = 0;
    }
    if (misc_player_on_solid_sprite == 2 || (player_blocked_flags & 8) != 0 ||
        ((io_controller_press2 | io_controller_press1) & 0x80) == 0) {
      if (player_ducking_flag) {
        if (player_xspeed) {
          if (!flag_ice_level)
            SpawnPlayerTurnAroundSmoke();
        }
        goto LABEL_12;
      }
    } else {
      uint8 v0 = player_xspeed;
      if ((player_xspeed & 0x80) != 0)
        v0 = -player_xspeed;
      uint8 v1 = (v0 >> 2) & 0xFE;
      if ((io_controller_press2 & 0x80) == 0 || player_carrying_something_flag2) {
        io_sound_ch2 = 1;
      } else {
        player_spin_jump_flag = player_carrying_something_flag2 + 1;
        io_sound_ch3 = 4;
        player_spinjump_fireball_timer = kHandlePlayerPhysics_DATA_00D5F0[player_facing_direction];
        if (player_riding_yoshi_flag)
          goto LABEL_25;
        ++v1;
      }
      player_yspeed = kHandlePlayerPhysics_JumpHeightTable[v1];
      uint8 v2 = 11;
      if (player_pmeter >= 0x70) {
        if (!timer_wait_before_cape_flight_begins)
          timer_wait_before_cape_flight_begins = 80;
        v2 = 12;
      }
      player_in_air_flag = v2;
      player_sliding_on_ground = 0;
    }
  }
LABEL_25:
  if ((player_sliding_on_ground & 0x80) != 0) {
LABEL_28:
    SpawnPlayerTurnAroundSmoke();
    if (player_slope_player_is_on2) {
      HandlePlayerPhysics_UpdatePMeter();
      HandlePlayerPhysics_00D742(((player_slope_player_is_on1 & 2) != 0) + (player_slope_player_is_on1 >> 2) + 118,
                                      ((player_slope_player_is_on1 & 4) != 0) + (player_slope_player_is_on1 >> 3) - 121);
      return;
    }
LABEL_12:
    HandlePlayerPhysics_00D764();
    return;
  }
  if ((io_controller_hold1 & 3) == 0) {
LABEL_27:
    if (!player_sliding_on_ground)
      goto LABEL_12;
    goto LABEL_28;
  }
  player_sliding_on_ground = 0;
  int8 v3 = io_controller_hold1 & 1;
  if (!player_cape_flying_phase) {
    if (v3 != player_facing_direction) {
      if (!player_carrying_something_flag2) {
LABEL_39:
        player_facing_direction = io_controller_hold1 & 1;
        goto LABEL_40;
      }
      if (!timer_display_player_face_screen_pose) {
        timer_display_player_face_screen_pose = 8;
        goto LABEL_39;
      }
    }
LABEL_40:
    R1_ = io_controller_hold1 & 1;
    v4 = player_slope_player_is_on1 | (4 * v3);
    if (player_xspeed && ((*((uint8 *)kHandlePlayerPhysics_MarioAccel + v4 + 1) ^ player_xspeed) & 0x80) != 0 &&
        !timer_player_slides_when_turing) {
      if (!flag_ice_level) {
        player_turning_around_flag = 13;
        SpawnPlayerTurnAroundSmoke();
      }
      v4 -= 112;
    }
    goto LABEL_46;
  }
  if (v3 != player_facing_direction && (io_controller_press1 & 0x80) == 0)
    goto LABEL_27;
  player_slope_player_is_on1 = kHandlePlayerPhysics_DATA_00D5EE[player_facing_direction];
  R1_ = io_controller_hold1 & 1;
  v4 = player_slope_player_is_on1 | (4 * v3);
LABEL_46:;
  uint8 v5 = 0;
  if ((io_controller_hold1 & 0x40) == 0)
    goto LABEL_54;
  v4 += 2;
  v5 = 1;
  uint8 v6 = player_xspeed;
  if ((player_xspeed & 0x80) != 0)
    v6 = -player_xspeed;
  if (sign8(v6 - 35))
    goto LABEL_54;
  if (!player_in_air_flag) {
    timer_show_running_frames_before_take_off = 16;
LABEL_53:
    v5 = 2;
    goto LABEL_54;
  }
  if (player_in_air_flag == 12)
    goto LABEL_53;
LABEL_54:
  v5 = HandlePlayerPhysics_UpdatePMeterEx(v5);
  HandlePlayerPhysics_00D742(v4, R1_ | player_slope_player_is_on1 | (2 * v5));
}

void HandlePlayerPhysics_00D742(uint8 k, uint8 j) {  // 00d742
  if (player_xspeed == kHandlePlayerPhysics_DATA_00D535[j] ||
      ((kHandlePlayerPhysics_DATA_00D535[j] ^ (player_xspeed - kHandlePlayerPhysics_DATA_00D535[j])) & 0x80) == 0) {
    HandlePlayerPhysics_00D76B();
  } else {
    int v2 = k >> 1;
    uint16 v3 = kHandlePlayerPhysics_MarioAccel[v2];
    if (flag_ice_level) {
      if (!player_in_air_flag)
        v3 = kHandlePlayerPhysics_DATA_00D43D[v2];
    }
    *(uint16 *)&player_sub_xspeed = *(uint16 *)&player_sub_xspeed + v3;
  }
}

void HandlePlayerPhysics_00D764() {  // 00d764
  HandlePlayerPhysics_UpdatePMeter();
  if (!player_in_air_flag)
    HandlePlayerPhysics_00D76B();
}

void HandlePlayerPhysics_00D76B() {  // 00d76b
  HandlePlayerPhysics_00D772(player_slope_player_is_on1 >> 2, player_slope_player_is_on1 >> 1);
}

void HandlePlayerPhysics_00D772(uint8 k, uint8 j) {  // 00d772
  uint16 v2;
  if ((int8)(player_xspeed - *((uint8 *)kHandlePlayerPhysics_DATA_00D5C9 + k + 1)) < 0)
    j += 2;
  if (player_in_air_flag | timer_end_level || (v2 = kHandlePlayerPhysics_DATA_00D309[j >> 1], *(int16 *)&flag_underwater_level >= 0)) {
    v2 = kHandlePlayerPhysics_DATA_00D2CD[j >> 1];
  }
  *(uint16 *)&player_sub_xspeed += v2;
  int v3 = k >> 1;
  if (((kHandlePlayerPhysics_DATA_00D2CD[j >> 1] ^ (*(uint16 *)&player_sub_xspeed - kHandlePlayerPhysics_DATA_00D5C9[v3])) & 0x8000) == 0)
    *(uint16 *)&player_sub_xspeed = kHandlePlayerPhysics_DATA_00D5C9[v3];
}

void HandlePlayerPhysics_InAir() {  // 00d7e4
  uint8 v0, v6;
  if (!player_cape_flying_phase) {
    if (!player_in_air_flag || player_spin_jump_flag | (uint8)(player_riding_yoshi_flag | player_carrying_something_flag2) ||
        (int8)player_sliding_on_ground > 0 || (player_sliding_on_ground = 0, player_current_power_up != 2) ||
        (player_yspeed & 0x80) != 0 || !timer_wait_before_cape_flight_begins) {
LABEL_43:
      if (player_in_air_flag) {
        uint8 v5 = 0;
        if (player_riding_yoshi_flag && yoshi_yoshi_has_wings >> 1) {
          v6 = 2;
          if (player_current_power_up != 2)
            v5 = 1;
          goto LABEL_54;
        }
        if (player_current_power_up == 2) {
          if (player_in_air_flag == 12) {
            v6 = 1;
            if (timer_wait_before_cape_flight_begins > 1)
              goto LABEL_54;
            ++timer_wait_before_cape_flight_begins;
          }
          v6 = 0;
LABEL_54:
          if (!timer_time_to_float_after_cape_flight) {
            if ((*(&io_controller_hold1 + v5) & 0x80) == 0) {
LABEL_60:
              if (v6 == 2) {
                HandlePlayerPhysics_D930(2);
                return;
              }
              goto LABEL_62;
            }
            timer_time_to_float_after_cape_flight = 16;
          }
          if (((player_yspeed & 0x80) == 0 ||
               (kHandlePlayerPhysics_DATA_00D7B9[v6] & 0x80) != 0 && player_yspeed >= kHandlePlayerPhysics_DATA_00D7B9[v6]) &&
              (int8)(kHandlePlayerPhysics_DATA_00D7B9[v6] - player_yspeed) <= 0) {
            player_yspeed = kHandlePlayerPhysics_DATA_00D7B9[v6];
            return;
          }
          goto LABEL_60;
        }
      }
LABEL_62:
      if ((io_controller_hold1 & 0x80) == 0)
        HandlePlayerPhysics_D930(0);
      else
        HandlePlayerPhysics_D930(1);
      return;
    }
    player_ducking_flag = 0;
    player_in_air_flag = 11;
    player_furthest_cape_dive_stage = 0;
    HandlePlayerPhysics_00D94F();
    v0 = 2;
    goto LABEL_21;
  }
  if (player_cape_flying_phase >= 2)
    HandlePlayerPhysics_00D94F();
  v0 = player_cape_glide_index;
  if (player_cape_glide_index == 4)
    goto LABEL_20;
  v0 = 3;
  if ((player_yspeed & 0x80) != 0)
    goto LABEL_20;
  if ((io_controller_hold1 & 3) == 0) {
    if (player_cape_flying_phase < 4)
      v0 = 2;
    goto LABEL_20;
  }
  uint8 v1 = (uint8)(io_controller_hold1 & 3) >> 1;
  if (player_facing_direction)
    v1 ^= 1;
  v0 = v1;
  if (v1 == player_cape_glide_index) {
LABEL_20:
    if (timer_change_diving_state)
      goto LABEL_27;
  }
LABEL_21:
  if ((io_controller_hold1 & 0x40) == 0)
    v0 = 4;
  if (player_cape_flying_phase != kHandlePlayerPhysics_DATA_00D7D4[v0]) {
    player_cape_flying_phase += kHandlePlayerPhysics_CapeSpeed[v0];
    uint8 v2 = 8;
    if (player_furthest_cape_dive_stage == 0xC8)
      v2 = 2;
    timer_change_diving_state = v2;
  }
LABEL_27:
  player_cape_glide_index = v0;
  uint8 v3 = player_cape_flying_phase;
  if (!player_cape_flying_phase)
    goto LABEL_43;
  uint8 v4 = player_yspeed;
  if ((player_yspeed & 0x80) == 0) {
    if (player_yspeed >= kHandlePlayerPhysics_DATA_00D7C8[player_cape_flying_phase])
      v4 = kHandlePlayerPhysics_DATA_00D7C8[player_cape_flying_phase];
  } else if (player_yspeed < 0xC8) {
    v4 = -56;
  }
  if (player_cape_flying_phase == 1) {
    if (!player_furthest_cape_dive_stage)
      goto LABEL_41;
    if ((player_yspeed & 0x80) != 0) {
      if (player_yspeed < player_furthest_cape_dive_stage) {
        player_yspeed = player_furthest_cape_dive_stage;
        player_furthest_cape_dive_stage = 0;
      }
    } else {
      io_sound_ch1 = 9;
    }
    if (!player_xspeed || ((kHandlePlayerPhysics_DATA_00D535[player_facing_direction] ^ player_xspeed) & 0x80) != 0)
LABEL_41:
      v3 = 2;
  }
  player_yspeed = kHandlePlayerPhysics_DATA_00D7A5[v3 + 3] + v4;
}

void HandlePlayerPhysics_D930(uint8 j) {  // 00d930
  uint8 v1 = player_yspeed;
  if ((player_yspeed & 0x80) == 0) {
    if (player_yspeed >= kHandlePlayerPhysics_DATA_00D7AF[j])
      v1 = kHandlePlayerPhysics_DATA_00D7AF[j];
    if (player_in_air_flag && player_in_air_flag == 11)
      player_in_air_flag = 36;
  }
  player_yspeed = kHandlePlayerPhysics_DATA_00D7A5[j] + v1;
}

void HandlePlayerPhysics_00D94F() {  // 00d94f
  unusedram_7e140a = 0;
  uint8 v0 = player_yspeed;
  if ((player_yspeed & 0x80) != 0)
    v0 = 0;
  if ((int8)(kHandlePlayerPhysics_DATA_00D7D9[v0 >> 3] - player_furthest_cape_dive_stage) < 0)
    player_furthest_cape_dive_stage = kHandlePlayerPhysics_DATA_00D7D9[v0 >> 3];
}

void HandlePlayerPhysics_UpdatePMeter() {  // 00d968
  HandlePlayerPhysics_UpdatePMeterEx(0);
}

uint8 HandlePlayerPhysics_UpdatePMeterEx(uint8 j) {  // 00d96a
  int8 v1 = kHandlePlayerPhysics_DATA_00D5EB[j] + player_pmeter;
  if (v1 < 0)
    v1 = 0;
  if ((uint8)v1 >= 0x70) {
    j += 1;
    v1 = 112;
  }
  player_pmeter = v1;
  return j;
}

void HandlePlayerPhysics_Swimming() {  // 00d988
  int8 v4;
  player_sliding_on_ground = 0;
  player_ducking_flag = 0;
  player_cape_flying_phase = 0;
  player_spin_jump_flag = 0;
  uint8 v0 = player_yspeed;
  if (player_carrying_something_flag2) {
    if (player_in_air_flag || ((io_controller_press2 | io_controller_press1) & 0x80) == 0) {
      if ((io_controller_hold1 & 4) == 0)
        goto LABEL_7;
    } else {
      player_in_air_flag = 11;
      player_sliding_on_ground = 0;
      v0 = -16;
    }
    HandlePlayerPhysics_00DAA9();
    v0 += 8;
LABEL_7:;
    int8 v1 = v0 + 1;
    if (!player_can_jump_out_of_water) {
      --v1;
      if ((counter_local_frames & 3) == 0)
        v1 -= 2;
    }
    uint8 v2 = v1;
    if ((int8)v1 < 0) {
      if ((uint8)v1 < 0xF0)
        v2 = -16;
    } else if ((uint8)v1 >= 0x10) {
      v2 = 16;
    }
    player_yspeed = v2;
    uint8 v3 = 0x80;
    v4 = io_controller_hold1 & 3;
    if ((io_controller_hold1 & 3) != 0)
      goto LABEL_34;
    v4 = player_facing_direction;
LABEL_33:
    v3 = 120;
LABEL_34:
    R0_ = v3;
    player_facing_direction = v4 & 1;
    uint8 v7 = 4 * (v4 & 1);
    uint8 v8 = v3 | v4 & 1;
    if (flag_layer3_tide_level)
      v8 += 4;
    uint8 v9 = v8;
    if (player_in_air_flag)
      v9 = v8 + 2;
    HandlePlayerPhysics_00D742(v7, v9);
    goto LABEL_43;
  }
  if (((io_controller_press2 | io_controller_press1) & 0x80) != 0 && !player_can_jump_out_of_water) {
    HandlePlayerPhysics_00DAA9();
    if (!player_in_air_flag) {
      player_in_air_flag = 11;
      player_sliding_on_ground = 0;
      v0 = -16;
    }
    v0 -= 32;
  }
  if ((counter_local_frames & 3) == 0)
    v0 += 2;
  uint8 v5 = (uint8)(io_controller_hold1 & 0xC) >> 2;
  uint8 v6 = v0;
  if ((v0 & 0x80) != 0) {
    if (v0 < kHandlePlayerPhysics_SwimYSpeed[v5])
      v6 = kHandlePlayerPhysics_SwimYSpeed[v5];
  } else if (v0 >= 0x40) {
    v6 = 64;
  }
  player_yspeed = v6;
  if (player_in_air_flag || (io_controller_hold1 & 4) == 0) {
    v4 = io_controller_hold1 & 3;
    if ((io_controller_hold1 & 3) != 0)
      goto LABEL_33;
  } else {
    flag_cape_to_sprite_interaction = 0;
    ++player_ducking_flag;
  }
  uint8 v10 = 0;
  if (flag_layer3_tide_level) {
    v10 = 30;
    if (!player_in_air_flag)
      v10 = 32;
  }
  HandlePlayerPhysics_00D772(v10, 0);
LABEL_43:
  CheckPowerUpSpecificPlayerAttacks();
  SetPlayerPose();
  if (!timer_active_cape_spin && player_in_air_flag) {
    uint8 v11 = 24;
    if (!timer_display_player_shoot_fireball_pose)
      v11 = kHandlePlayerPhysics_SwimPoses[(player_anim_timer >> 2) & 3];
    if (player_carrying_something_flag2)
      ++v11;
    player_current_pose = v11;
  }
}

void HandlePlayerPhysics_00DAA9() {  // 00daa9
  io_sound_ch1 = 14;
  player_anim_timer |= 0x10;
}

void HandlePlayerPhysics_Climbing() {  // 00db17
  uint8 v7;
  player_in_air_flag = 0;
  player_yspeed = 0;
  player_cape_image = 0;
  player_spin_jump_flag = 0;
  uint8 j = timer_on_swinging_climbing_net_door;
  if (j) {
    uint8 v1 = sprites_player_xspeed_on_swinging_net_door;
    if ((v1 & 0x80) != 0)
      v1 = -v1;
    uint8 k = v1;
    if (j >= 0x1E) {
      uint8 v3 = kHandlePlayerPhysics_DATA_00DADF[v1];
      if ((sprites_player_xspeed_on_swinging_net_door & 0x80) != 0)
        v3 = -v3;
      player_xspeed = v3;
      player_sub_xspeed = 0;
      player_sub_xpos = 0;
    }
    uint8 t = sprites_player_xspeed_on_swinging_net_door ^ (j < 8 ? 0x80 : 0);
    uint16 v4 = kHandlePlayerPhysics_DATA_00DAF1[k];
    if (!(t & 0x80))
      v4 = -v4;
    *(uint16 *)&player_sub_xspeed += v4;
    uint8 v5 = player_facing_direction_on_net_door | (j >> 1) & 0xE;
    uint8 v6 = kHandlePlayerPhysics_DATA_00DABD[v5];
    if ((sprites_player_xspeed_on_swinging_net_door & 0x80) == 0)
      v6 ^= 1;
    player_facing_direction = v6;
    v7 = kHandlePlayerPhysics_SwingOnNetDoorPoses[v5];
    goto LABEL_15;
  }
  player_xspeed = 0;
  player_sub_xspeed = 0;
  uint8 v8 = player_current_layer_priority;
  if (timer_display_player_net_punch_pose) {
    InitializeCapeSwingOrNetPunch(player_current_layer_priority + 2);
    v7 = kHandlePlayerPhysics_NetPunchingPoses[v8];
LABEL_15:
    player_current_pose = v7;
    return;
  }
  uint8 v9 = player_swimming_flag;
  if ((io_controller_press1 & 0x80) != 0) {
    player_in_air_flag = 11;
    player_yspeed = kHandlePlayerPhysics_JumpFromVineYSpeed[player_swimming_flag];
    io_sound_ch2 = 1;
LABEL_29:
    player_climbing_flag = 0;
    return;
  }
  if ((io_controller_press1 & 0x40) && (player_climbing_flag & 0x80) != 0) {
    io_sound_ch1 = 1;
    player_facing_direction_on_net_door = v8;
    player_facing_direction = ((uint8)(player_xpos & 8) >> 3) ^ 1;
    timer_display_player_net_punch_pose = 8;
  }
  player_current_pose = kHandlePlayerPhysics_ClimbingPoses[v8];
  if ((io_controller_hold1 & 3) != 0) {
    int8 v10 = (uint8)(io_controller_hold1 & 3) >> 1;
    if ((temp8b & 0x18) == 24)
      goto LABEL_25;
    if ((player_climbing_flag & 0x80) == 0)
      goto LABEL_29;
    if (v10 != temp8c)
LABEL_25:
      player_xspeed = kHandlePlayerPhysics_ClimbingSpeed[(uint8)(player_swimming_flag | (2 * v10))];
  }
  uint8 v11 = io_controller_hold1 & 0xC;
  if ((io_controller_hold1 & 0xC) != 0) {
    if ((io_controller_hold1 & 8) == 0) {
      int8 v12 = temp8b & 1;
      temp8b >>= 1;
      if (!v12)
        goto LABEL_29;
      goto LABEL_31;
    }
    v9 += 2;
    v11 = temp8b & 2;
    if ((temp8b & 2) != 0) {
LABEL_31:
      if ((player_climbing_flag & 0x80) == 0)
        player_xspeed = 0;
      v11 = kHandlePlayerPhysics_ClimbingSpeed[v9];
      player_yspeed = v11;
    }
  }
  if (player_xspeed | v11) {
    player_anim_timer |= 8;
    if ((player_anim_timer & 7) == 0)
      player_facing_direction ^= 1;
  }
}

void UpdatePlayerSpritePosition() {  // 00dc2d
  temp8a = player_yspeed;
  if (player_wall_walk_status) {
    uint8 v0 = player_xspeed;
    player_yspeed = (player_wall_walk_status & 1) ? -v0 : v0;
  }
  uint16 tx = player_sub_xpos + (uint8)(player_xspeed * 16);
  player_sub_xpos = tx;
  player_xpos += ((int8)player_xspeed >> 4) + (tx >> 8);

  uint16 ty = player_sub_ypos + (uint8)(player_yspeed * 16);
  player_sub_ypos = ty;
  player_ypos += ((int8)player_yspeed >> 4) + (ty >> 8);
  player_yspeed = temp8a;
}

void PlayerDraw() {  // 00e2bd
  int8 v4;
  if (player_hide_player_tile_flags != 0xFF)
    PlayerGFXRt_01EA70();
  if (timer_player_palette_cycle)
    goto LABEL_14;
  uint8 star = timer_star_power;
  if (timer_star_power) {
    if (player_hide_player_tile_flags != 0xFF && (counter_local_frames & 3) == 0)
      --timer_star_power;
    if (star >= 0x1E) {
      if (star != 30) {
        v4 = (counter_global_frames & 3) + 4;
        goto LABEL_18;
      } else {
        if (misc_music_register_backup != 0xFF) {
          misc_music_register_backup &= ~0x80;
          uint8 t = misc_music_register_backup;
          if (spr45_directional_coins_despawn_timer | timer_silver_pswitch | timer_blue_pswitch)
            t = 14;
          io_music_ch1 = t;
        }
      }
    }
LABEL_14:
    v4 = (counter_global_frames >> 2 & 3) + 4;
  } else {
    v4 = player_current_character | (2 * player_current_power_up);
  }
LABEL_18:
  pointer_player_palette = kPlayerGFXRt_PalettePointers[v4];
  uint8 v5 = player_current_pose;
  int8 v6 = player_wall_walk_status <= 5;
  if (player_wall_walk_status > 5) {
    int8 v7 = player_wall_walk_status;
    if (!player_current_power_up || player_current_pose == 19)
      v7 = player_wall_walk_status ^ 1;
    v6 = v7 & 1;
  }
  player_on_screen_pos_x = player_xpos - (!v6 + mirror_current_layer1_xpos);
  int16 v8 = player_ypos + player_relative_yposition_during_screen_shake;
  uint8 v9 = 1;
  if (player_current_power_up < 1) {
    --v8;
    v9 = 0;
  }
  bool v10 = v5 >= 0xA;
  if (v5 < 0xA)
    v10 = v9 >= player_walking_frame;
  uint16 v11 = v8 - (!v10 + mirror_current_layer1_ypos);
  if (v5 == 28)
    v11 += 2;
  player_on_screen_pos_y = v11;
  if (!timer_player_hurt ||
      player_freeze_player_flag | (uint8)(flag_sprites_locked | timer_player_hurt & kPlayerGFXRt_DATA_00E292[timer_player_hurt >> 3])) {
    uint8 v12 = -56;
    if (v5 == 67)
      v12 = -24;
    R4_ = v12;
    if (v5 == 41 && !player_current_power_up)
      v5 = 32;
    R5_ = kPlayerGFXRt_PlayerXYDispIndex[player_facing_direction | kPlayerGFXRt_PlayerXYDispIndexIndex[v5]];
    uint8 v13 = player_current_pose;
    if (player_current_pose < 0x3D)
      v13 = kPlayerGFXRt_PowerupTilesetIndex[player_current_power_up] + (player_current_pose >= 0x3D) + player_current_pose;
    R6_ = kPlayerGFXRt_TilesIndex[v13];
    R10_ = kPlayerGFXRt_HeadTilePointerIndex[v13];
    R11_ = kPlayerGFXRt_BodyTilePointerIndex[v13];
    uint8 v14 = sprites_tile_priority;
    if (player_current_layer_priority)
      v14 = kPlayerGFXRt_TilePriority[player_current_layer_priority - 1];
    uint8 v15 = kPlayerGFXRt_PlayerStartingOAMIndex[player_current_layer_priority];
    int8 v16 = kPlayerGFXRt_TileXFlip[player_facing_direction] | v14;
    OamEnt *oam = get_OamEnt(oam_buf, v15);
    oam[64].flags = v16;
    oam[65].flags = v16;
    oam[67].flags = v16;
    oam[68].flags = v16;
    oam[62].flags = v16;
    oam[63].flags = v16;
    if (R4_ == 0xE8)
      v16 ^= 0x40;
    oam[66].flags = v16;
    uint8 v18 = PlayerGFXRt_00E45D(v15);
    uint8 v19 = PlayerGFXRt_00E45D(v18);
    uint8 v20 = PlayerGFXRt_00E45D(v19);
    uint8 v21 = PlayerGFXRt_00E45D(v20);
    if (player_current_power_up == 2) {
      uint8 j = v21;
      R6_ = 44;
      uint8 v22 = kPlayerGFXRt_DATA_00E18E[player_current_pose];
      R13_ = kPlayerGFXRt_DATA_00E1D4[v22 + 3];
      R14_ = kPlayerGFXRt_DATA_00E1D4[v22 + 4];
      R12_ = kPlayerGFXRt_DATA_00E1D4[v22 + 1];
      uint8 v24;
      if (R12_ >= 4) {
        v24 = kPlayerGFXRt_DATA_00E1D4[v22 + 2];
      } else {
        uint8 v23 = R12_ | (4 * player_cape_image);
        R12_ = kPlayerGFXRt_CapeTilePointerIndex[v23];
        v24 = kPlayerGFXRt_DATA_00E266[v23];
      }
      R5_ = kPlayerGFXRt_CapeXYDispIndex[player_facing_direction | v24];
      player_hide_player_tile_flags |= kPlayerGFXRt_DATA_00E1D4[v22];
      if (!(kPlayerGFXRt_DATA_00E1D4[v22] & 0x80))
        PlayerGFXRt_00E45D(j);
      uint8 v25 = PlayerGFXRt_00E45D(kPlayerGFXRt_CapeStartingOAMIndex[player_current_layer_priority]);
      R6_ = R14_;
      PlayerGFXRt_00E45D(v25);
    }
    PlayerGFXRt_00F636();
  }
}

uint8 PlayerGFXRt_00E45D(uint8 j) {  // 00e45d
  bool xflag = true;

  bool v1 = player_hide_player_tile_flags & 1;
  player_hide_player_tile_flags >>= 1;
  if (!v1) {
    int8 v2 = kPlayerGFXRt_Tiles[R6_];
    if (v2 >= 0) {
      OamEnt *oam = get_OamEnt(oam_buf, j);
      oam[64].charnum = v2;
      int v4 = R5_ >> 1;
      uint16 v5 = kPlayerGFXRt_YDisp[v4] + player_on_screen_pos_y;
      if ((uint16)(v5 + 0x10) < 0x100) {
        oam[64].ypos = v5;
        uint16 v6 = kPlayerGFXRt_XDisp[v4] + player_on_screen_pos_x;
        if ((uint16)(v5 + 0x80) < 0x200) {
          oam[64].xpos = v6;
          xflag = (v6 >> 8) & 1;
        }
      }
    } else {
      xflag = false;
    }
  }
  bool v7 = __CFSHL__(R4_, 1);
  R4_ *= 2;
  sprites_oamtile_size_buffer[(j >> 2) + 64] = (2 * v7 + xflag) & 3;
  R5_ += 2;
  ++R6_;
  return j + 4;
}

void HandlePlayerLevelCollision() {  // 00e92b
  ResetPlayerLevelCollisionRAM();
  if (player_disable_object_interaction_flag) {
    RunPlayerBlockCode_00EE1D();
    HandlePlayerLevelColl_00E98C();
  } else {
    temp8d = player_on_ground_flag;
    player_on_ground_flag = 0;
    temp8f = player_in_air_flag;
    if ((misc_level_layout_flags & 0x80) != 0) {
      temp8e = misc_level_layout_flags & 0x82;
      LOBYTE(misc_current_layer_being_processed) = 1;
      player_xpos += misc_second_level_layer_xpos;
      player_ypos += misc_second_level_layer_ypos;
      RunPlayerBlockCode();
      player_xpos -= misc_second_level_layer_xpos;
      player_ypos -= misc_second_level_layer_ypos;
    }
    player_on_ground_flag *= 2;
    temp8e = misc_level_layout_flags & 0x41;
    if ((misc_level_layout_flags & 0x40) == 0) {
      LOBYTE(misc_current_layer_being_processed) = 0;
      temp8d *= 2;
      RunPlayerBlockCode();
    }
    HandlePlayerLevelColl_00E98C();
  }
}

void HandlePlayerLevelColl_00E98C() {  // 00e98c
  if (flag_side_exits) {
    if (player_on_screen_pos_x < 0xFA) {
LABEL_3:
      HandlePlayerLevelColl_00E9FB();
      return;
    }
    DisplayMessage_ExitToOverworldNoEvent();
  } else if ((uint8)player_on_screen_pos_x < 0xF0) {
    if ((player_blocked_flags & 3) != 0)
      goto LABEL_3;
    if ((int16)(misc_layer1_pos[0].x + 232 - player_xpos) > 0)
      HandlePlayerLevelColl_00E9C8(1, (int16)(player_xpos - 8 - misc_layer1_pos[0].x) < 0);
    else
      HandlePlayerLevelColl_00E9C8(0, (int16)(misc_layer1_pos[0].x + 232 - player_xpos) < 0);
  } else {
    HandlePlayerLevelColl_00EA08();
  }
}

void HandlePlayerLevelColl_00E9C8(uint8 j, uint8 sign) {  // 00e9c8
  if (sign) {
    if (!flag_layer1_horiz_scroll_level_setting) {
      player_blocked_flags |= 0x80;
      R0_ = get_PointU16(l1_l2_scroll_spr_speed, 0)->x >> 4;
      if (((kHandlePlayerLevelColl_DATA_00E90D[j + 1] ^ (R0_ - player_xspeed)) & 0x80) == 0) {
        player_xspeed = R0_;
        player_sub_xpos = get_PointU16(l1_l2_scroll_spr_sub_pos, 0)->x;
      }
    }
    player_blocked_flags |= kHandlePlayerLevelColl_DATA_00E90A[j];
  }
  HandlePlayerLevelColl_00E9FB();
}

void HandlePlayerLevelColl_00E9FB() {  // 00e9fb
  if ((player_blocked_flags & 0x1C) != 28 || misc_player_on_solid_sprite)
    HandlePlayerLevelColl_00EA0D();
  else
    HandlePlayerLevelColl_00EA08();
}

void HandlePlayerLevelColl_00EA08() {  // 00ea08
  DamagePlayer_KillAndDisableButtons();
  player_xspeed = 0;
  HandlePlayerLevelColl_00EA34();
}

void HandlePlayerLevelColl_00EA0D() {  // 00ea0d
  if ((player_blocked_flags & 3) != 0 &&
      (player_xpos += *(uint16 *)&kHandlePlayerLevelColl_DATA_00E90D[player_blocked_flags & 2], (player_blocked_flags & 0x80) == 0) &&
      (player_anim_speed_index = 3,
       ((kHandlePlayerLevelColl_DATA_00E90D[player_blocked_flags & 2] ^ player_xspeed) & 0x80) != 0)) {
    player_xspeed = 0;
  }
  HandlePlayerLevelColl_00EA34();
}

void HandlePlayerLevelColl_00EA34() {  // 00ea34
  if (player_current_layer_priority == 1 && !temp8b)
    player_current_layer_priority = 0;
  player_can_jump_out_of_water = 0;
  if (flag_underwater_level) {
    player_swimming_flag = 1;
    SpawnPlayerBreathBubble();
    return;
  }
  int8 v0 = temp8a & 1;
  temp8a >>= 1;
  if (!v0) {
    player_swimming_flag = 0;
    return;
  }
  if (!player_swimming_flag && (player_yspeed & 0x80) == 0) {
    v0 = temp8a & 1;
    temp8a >>= 1;
    if (!v0)
      return;
    SpawnPlayerWaterSplashAndBubbles();
    player_yspeed = 0;
    player_swimming_flag = 1;
    SpawnPlayerBreathBubble();
    return;
  }
  v0 = temp8a & 1;
  temp8a >>= 1;
  if (v0) {
    player_swimming_flag = 1;
    SpawnPlayerBreathBubble();
    return;
  }
  if (!player_swimming_flag)
    return;
  if (!sign8(-4 - player_yspeed))
    player_yspeed = -4;
  ++player_can_jump_out_of_water;
  if ((io_controller_hold1 & 0x88) != 0x88) {
    SpawnPlayerBreathBubble();
    return;
  }
  if ((io_controller_hold2 & 0x80) != 0 && !player_carrying_something_flag2) {
    player_spin_jump_flag = player_carrying_something_flag2 + 1;
    io_sound_ch3 = 4;
  }
  if ((player_blocked_flags & 8) != 0) {
    SpawnPlayerBreathBubble();
    return;
  }
  SpawnPlayerWaterSplashAndBubbles();
  player_in_air_flag = 11;
  player_yspeed = -86;
  player_swimming_flag = 0;
}

void ResetPlayerLevelCollisionRAM() {  // 00eaa6
  player_anim_speed_index = 0;
  player_blocked_flags = 0;
  player_slope_player_is_on1 = 0;
  player_slope_player_is_on2 = 0;
  temp8a = 0;
  temp8b = 0;
  sprites_layer2_is_touched_flag = 0;
}

void RunPlayerBlockCode() {  // 00eadb
  player_ypos_in_block = player_ypos & 0xF;
  if (!player_wall_walk_status) {
    RunPlayerBlockCode_EB77();
    return;
  }
  uint8 v0 = player_wall_walk_status & 1;
  if (((kRunPlayerBlockCode_DATA_00EAB9[v0] ^ (player_xspeed - kRunPlayerBlockCode_DATA_00EAB9[v0])) & 0x80) != 0 ||
      player_riding_yoshi_flag | (uint8)(player_ducking_flag | player_carrying_something_flag2 | player_in_air_flag)) {
    RunPlayerBlockCode_00EB48(v0);
    return;
  }
  if (player_wall_walk_status < 6) {
    if (player_ypos_in_block < 8)
      return;
    if (player_wall_walk_status >= 4) {
      RunPlayerBlockCode_00EB73();
      return;
    }
    player_wall_walk_status |= 4;
    goto LABEL_11;
  }
  uint8 v1 = 96;
  if (v0)
    v1 = 102;
  v1 += 2;
  if (RunPlayerBlockCode_00EFE8_ReturnsTwice(v1))
    return;
  v1 += 2;
  if (player_current_power_up && RunPlayerBlockCode_00EFE8_ReturnsTwice(v1))
    return;
  if ((uint8)GetPlayerLevelCollisionMap16ID_WallRun(v1 += 2).first) {
LABEL_11:
    LOBYTE(player_xpos) = player_xpos & 0xF0 | 8;
    return;
  }
  player_wall_walk_status &= ~2;
}

void RunPlayerBlockCode_00EB48(uint8 j) {  // 00eb48
  player_xspeed = kRunPlayerBlockCode_DATA_00EABB[j];
  player_xpos += kRunPlayerBlockCode_DATA_00EABD[j];
  player_ypos += (player_current_power_up) ? 16 : 8;
  player_in_air_flag = 36;
  player_yspeed = -32;
  RunPlayerBlockCode_00EB73();
}

void RunPlayerBlockCode_00EB73() {  // 00eb73
  player_wall_walk_status = 0;
}

void RunPlayerBlockCode_EB77() {  // 00eb77
  unsigned int v3;
  unsigned int v10;
  uint16 v13;
  int8 v14;
  uint8 v4;

  uint8 v0 = 0;
  if (player_current_power_up && !player_ducking_flag)
    v0 = 24;
  if (player_riding_yoshi_flag)
    v0 += 48;
  player_xpos_in_block = ((player_xpos & 0xF) + 8) & 0xF;
  player_hdir_block_touched = 0;
  if ((player_xpos & 0xF) >= 8) {
    v0 += ((player_xpos & 0xF) >= 8) + 11;
    ++player_hdir_block_touched;
  }
  player_vdir_push_out_of_block = (*((uint8 *)kRunPlayerBlockCode_UnknownData00E8A4 + v0) + player_ypos_in_block) & 0xF;
  PairU16 wr = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
  int8 v2 = wr.first;
  v3 = wr.second;
  if (!v2) {
    if ((uint8)v3 == 0x9C && misc_level_tileset_setting == 1) {
LABEL_26:
      if (!temp8f && (io_controller_press1 & 8) != 0) {
        io_sound_ch3 = 15;
        IncrementSublevelsEnteredAndPrepareToLoadSublevel();
        player_current_state = 13;
        DamagePlayer_DisableButtons();
      }
      goto LABEL_30;
    }
    if ((uint8)v3 != 32) {
      if ((uint8)v3 != 31) {
        if (!timer_blue_pswitch)
          goto LABEL_29;
        if ((uint8)v3 == 40)
          goto LABEL_25;
        if ((uint8)v3 != 39) {
LABEL_29:
          RunPlayerBlockCode_00F28C(v3);
          goto LABEL_30;
        }
      }
      if (player_current_power_up)
        goto LABEL_30;
    }
LABEL_25:
    if (RunPlayerBlockCode_00F443() & 1)
      goto LABEL_30;
    goto LABEL_26;
  }
  if ((uint8)v3 >= 0x11) {
    if ((uint8)v3 < 0x6E) {
      v0 += 4;
      v4 = 0;
      if ((uint8)v3 != 30 && (uint8)v3 != 82)
        v4 = 2;
      goto LABEL_42;
    }
    if (CheckWaterSlope(v3) & 1)
      temp8a |= 1;
  }
LABEL_30:;
  PairU16 v5 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
  uint8 second = v5.second;
  if (!LOBYTE(v5.first)) {
    RunPlayerBlockCode_00F2C9(v5.second, 0x10);
    goto LABEL_35;
  }
  if (LOBYTE(v5.second) < 0x11 || LOBYTE(v5.second) >= 0x6E) {
LABEL_35:;
    PairU16 v7 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
    second = v7.second;
    if (!LOBYTE(v7.first)) {
      RunPlayerBlockCode_00F2C9(v7.second, 8);
      goto LABEL_45;
    }
    if (LOBYTE(v7.second) < 0x11 || LOBYTE(v7.second) >= 0x6E)
      goto LABEL_45;
    goto LABEL_39;
  }
  v0 += 2;
LABEL_39:
  if (player_facing_direction != player_hdir_block_touched) {
    RunPlayerBlockCode_CheckIfEnteringHorizontalPipe(v0, second, player_facing_direction);
    RunPlayerBlockCode_CheckIfGrabbingThrowBlock(second);
  }
  player_anim_speed_index = 3;
  v4 = player_hdir_block_touched;
  if ((player_xpos & 0xF) != kHandlePlayerLevelColl_DATA_00E911[player_hdir_block_touched]) {
LABEL_42:
    if (!blocks_note_block_bounce_flag || blocks_currently_processed_map16_tile_lo != 82) {
      uint8 t = kHandlePlayerLevelColl_DATA_00E90A[v4];
      player_blocked_flags |= t;
      RunPlayerBlockCode_CheckIfPlayerTouchingHurtBlock(blocks_currently_processed_map16_tile_lo, t & 3, true);
    }
  }
LABEL_45:;
  PairU16 v8 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
  int8 v9 = v8.first;
  v10 = v8.second;
  int8 v11 = v10;
  if (!v9) {
    RunPlayerBlockCode_00F2C2(v10, 2);
    if ((player_yspeed & 0x80) == 0 || blocks_currently_processed_map16_tile_lo < 0x21 ||
        blocks_currently_processed_map16_tile_lo >= 0x25) {
      goto LABEL_73;
    }
    CheckIfBlockWasHit_Entry3(blocks_currently_processed_map16_tile_lo - 4, 0);
    goto LABEL_61;
  }
  if ((uint8)v10 < 0x11)
    goto LABEL_73;
  if ((uint8)v10 >= 0x6E) {
    if ((uint8)v10 >= 0xD8) {
      blocks_ypos += 16;
      PairU16 pair = GetPlayerLevelCollisionMap16ID_Entry2(v0);
      v11 = pair.second;
      if (!LOBYTE(pair.first) || LOBYTE(pair.second) < 0x6E ||
          LOBYTE(pair.second) >= 0xD8) {
        goto LABEL_73;
      }
      player_vdir_push_out_of_block -= (LOBYTE(pair.second) < 0xD8) + 15;
    }
    v13 = 16 * *IndirPtr(&ptr_slope_steepness, (uint8)(v11 - 110));
    LOBYTE(v13) = player_xpos_in_block | v13;
    v14 = kSlopeDataTables_ShapeOfSlope[v13];
    if (v14 >= 0)
      goto LABEL_73;
    goto LABEL_62;
  }
  v10 = RunPlayerBlockCode_00F3E9(2, v10);
  RunPlayerBlockCode_CheckIfPlayerTouchingHurtBlock(v10, 0, true);
  if (blocks_currently_processed_map16_tile_lo != 30) {
LABEL_61:
    v14 = -16;
LABEL_62:;
    int8 v15 = player_vdir_push_out_of_block + v14;
    if (v15 >= 0)
      goto LABEL_73;
    if ((uint8)v15 >= 0xF9 || player_in_air_flag) {
      if (player_in_air_flag) {
        player_ypos += (uint8)~v15;
      }
      player_blocked_flags |= 8;
    } else {
      player_blocked_flags = player_blocked_flags & 0xF4 | 9;
      player_xspeed = 0;
    }
  }
  if ((player_yspeed & 0x80) != 0) {
    player_yspeed = 0;
    if (!io_sound_ch1)
      io_sound_ch1 = 1;
  }
LABEL_73:;
  PairU16 v18 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
  uint8 v19 = v18.second;
  if (!LOBYTE(v18.first)) {
    if (LOBYTE(v18.second) == 5)
      DamagePlayer_KillAndDisableButtons();
    else
      RunPlayerBlockCode_00F2C2(v18.second, 4);
    goto LABEL_95;
  }
  if (LOBYTE(v18.second) < 0x6E) {
    RunPlayerBlockCode_00F3E9(3, v18.second);
    goto LABEL_99;
  }
  if (LOBYTE(v18.second) >= 0xD8) {
    if (LOBYTE(v18.second) >= 0xFB) {
      DamagePlayer_KillAndDisableButtons();
      return;
    }
    blocks_ypos -= 16;
    PairU16 v20 = GetPlayerLevelCollisionMap16ID_Entry2(v0);
    v19 = v20.second;
    if (!LOBYTE(v20.first) || LOBYTE(v20.second) < 0x6E || LOBYTE(v20.second) >= 0xD8) {
LABEL_95:;
      PairU16 v23 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
      if (!LOBYTE(v23.first)) {
        RunPlayerBlockCode_00F309(v23.second);
        RunPlayerBlockCode_00EE1D();
        return;
      }
      if (LOBYTE(v23.second) >= 0x6E) {
LABEL_106:
        RunPlayerBlockCode_00EE1D();
        return;
      }
LABEL_99:
      if ((player_yspeed & 0x80) != 0)
        return;
      if (misc_level_tileset_setting != 3 && misc_level_tileset_setting != 14 || blocks_currently_processed_map16_tile_lo < 0x59 ||
          blocks_currently_processed_map16_tile_lo >= 0x5C) {
        uint8 v24 = player_ypos_in_block & 0xF;
        player_ypos_in_block = 0;
        player_vdir_push_out_of_block = v24;
        if (v24 < 8) {
          RunPlayerBlockCode_00EE3A();
          return;
        }
      }
      goto LABEL_106;
    }
    player_ypos_in_block += (LOBYTE(v20.second) >= 0xD8) + 16;
  }
  if ((misc_level_tileset_setting == 3 || misc_level_tileset_setting == 14) && v19 >= 0xD2)
    goto LABEL_95;
  uint8 k = *IndirPtr(&ptr_slope_steepness, (uint8)(v19 - 110));
  uint8 v22 = player_ypos_in_block - kSlopeDataTables_ShapeOfSlope[player_xpos_in_block | 16 * k];
  if ((v22 & 0x80) != 0)
    ++player_on_ground_flag;
  if (v22 >= kSlopeDataTables_Player_SnapToSlopeDistance[k])
    goto LABEL_95;
  player_vdir_push_out_of_block = v22;
  player_ypos_in_block = 0;
  if (RunPlayerBlockCode_00F005_ReturnsTwice(k))
    return;
  if (k < 0x1C) {
    RunPlayerBlockCode_00EFBC();
    RunPlayerBlockCode_00EE85(k);
  } else {
    timer_player_slides_when_turing = 8;
    RunPlayerBlockCode_00EED1(k);
  }
}

void RunPlayerBlockCode_00EE1D() {  // 00ee1d
  if (misc_player_on_solid_sprite && (player_yspeed & 0x80) == 0) {
    temp8e = 0;
    RunPlayerBlockCode_00EEE1(0x20);
  } else if (!(player_in_air_flag | player_blocked_flags & 4)) {
    player_in_air_flag = 36;
  }
}

void RunPlayerBlockCode_00EE3A() {  // 00ee3a
  if ((misc_level_tileset_setting == 2 || misc_level_tileset_setting == 8) && (uint8)(blocks_currently_processed_map16_tile_lo - 12) < 2) {
    RunPlayerBlockCode_00EFCD(2 * (blocks_currently_processed_map16_tile_lo - 12));
  } else {
    RunPlayerBlockCode_CheckIfGrabbingThrowBlock(blocks_currently_processed_map16_tile_lo);
    if (blocks_currently_processed_map16_tile_lo == 30) {
      if (temp8f && player_current_power_up && player_spin_jump_flag) {
        CheckIfBlockWasHit_Entry3(0x21, 3);
        RunPlayerBlockCode_00EE1D();
        return;
      }
    } else {
      if (blocks_currently_processed_map16_tile_lo == 50)
        flag_active_create_eat_block = 0;
      RunPlayerBlockCode_CheckIfPlayerTouchingHurtBlock(blocks_currently_processed_map16_tile_lo, 3, false);
    }
  }
  RunPlayerBlockCode_00EE85(0x20);
}

void RunPlayerBlockCode_00EE85(uint8 j) {  // 00ee85
  if ((player_yspeed & 0x80) == 0 || temp8d >= 2) {
    if (!misc_color_of_palace_switch_pressed2) {
LABEL_10:
      RunPlayerBlockCode_00EED1(j);
      return;
    }
    if (((misc_color_of_palace_switch_pressed2 - 1) & 3) != 0) {
      if (((misc_color_of_palace_switch_pressed2 - 1) & 3) >= 2)
        goto LABEL_10;
      blocks_xpos -= 16;
    }
    uint8 v1 = (uint8)(misc_color_of_palace_switch_pressed2 - 1) >> 2;
    if (!flag_activated_switches[v1]) {
      flag_activated_switches[v1] = 1;
      misc_color_of_palace_switch_pressed1 = 1;
      sprites_color_of_flat_palace_switch_to_spawn = v1;
      RunPlayerBlockCode_SpawnFlatPalaceSwitch();
      io_music_ch1 = 12;
      misc_music_register_backup = -1;
      timer_end_level = 8;
    }
    goto LABEL_10;
  }
}

void RunPlayerBlockCode_00EED1(uint8 j) {  // 00eed1
  ++player_on_ground_flag;
  player_ypos -= player_vdir_push_out_of_block;
  RunPlayerBlockCode_00EEE1(j);
}

void RunPlayerBlockCode_00EEE1(uint8 j) {  // 00eee1
  int8 v5;

  if (kSlopeDataTables_SlopeType[j])
    goto LABEL_4;
  if (player_sliding_on_ground) {
    uint8 v1 = player_xspeed;
    if (!player_xspeed) {
LABEL_7:
      player_sliding_on_ground = v1;
      goto LABEL_8;
    }
LABEL_4:
    player_slope_player_is_on2 = kSlopeDataTables_SlopeType[j];
    if ((io_controller_hold1 & 4) == 0 || player_sliding_on_ground | player_carrying_something_flag2)
      goto LABEL_8;
    v1 = 28;
    goto LABEL_7;
  }
LABEL_8:;
  uint8 v2 = kSlopeDataTables_Player[j];
  player_slope_player_is_on1 = v2;
  if (j >= 0x1C)
    goto LABEL_18;
  if (player_xspeed) {
    uint8 v3 = kSlopeDataTables_SlopeType[j];
    if (v3) {
      if (((player_xspeed ^ v3) & 0x80) != 0) {
        player_anim_speed_index = v2;
        uint8 v4 = player_xspeed;
        if ((player_xspeed & 0x80) != 0)
          v4 = -player_xspeed;
        if (v4 >= 0x28) {
          v5 = kSlopeDataTables_Player_TowardsPeakYSpeed[j];
          goto LABEL_23;
        }
        j = 32;
      }
    }
  }
  v5 = player_yspeed;
  if (player_yspeed >= kSlopeDataTables_Player_StationaryYSpeed[j])
LABEL_18:
    v5 = kSlopeDataTables_Player_StationaryYSpeed[j];
  if ((temp8e & 0x80) != 0) {
    ++sprites_layer2_is_touched_flag;
    player_xpos -= (int8)misc_layer2_xdisp;
    v5 += 40;
  }
LABEL_23:
  player_yspeed = v5;
  if (v5 < 0)
    ++player_on_ground_flag;
  flag_standing_on_beta_cage = 0;
  player_in_air_flag = 0;
  player_climbing_flag = 0;
  camera_bounce_off_spring_flag = 0;
  player_spin_jump_flag = 0;
  player_blocked_flags |= 4;
  uint8 v9 = player_cape_flying_phase;
  if (player_cape_flying_phase) {
    counter_consecutive_enemies_stomped = 0;
    player_cape_flying_phase = 0;
    if (v9 >= 5) {
      if (temp8f) {
        RunPlayerBlockCode_TriggerCapeDiveGroundPound();
        io_sound_ch3 = 9;
      }
    } else if (player_current_power_up == 2) {
      player_sliding_on_ground = (player_sliding_on_ground >> 1) + 0x80;
    }
  } else {
    if (player_riding_yoshi_flag && temp8f) {
      if (yoshi_stomp_ground_flag) {
        YoshiStompRoutine();
        io_sound_ch3 = 37;
      }
    }
    counter_consecutive_enemies_stomped = 0;
  }
}

void RunPlayerBlockCode_00EFBC() {  // 00efbc
  if (blocks_currently_processed_map16_tile_lo >= 0xCE && blocks_currently_processed_map16_tile_lo < 0xD2)
    RunPlayerBlockCode_00EFCD(2 * (blocks_currently_processed_map16_tile_lo + 52));
}

void RunPlayerBlockCode_00EFCD(uint8 k) {  // 00efcd
  if ((counter_global_frames & 3) == 0) {
    int v1 = k >> 1;
    player_xpos += kHandlePlayerLevelColl_DATA_00E913[v1];
    player_ypos += kHandlePlayerLevelColl_DATA_00E91F[v1];
  }
}

bool RunPlayerBlockCode_00EFE8_ReturnsTwice(uint8 k) {  // 00efe8
  unsigned int v3;
  bool ret = false;

  PairU16 pair = GetPlayerLevelCollisionMap16ID_WallRun(k);
  int8 v2 = pair.first;
  v3 = HIWORD(pair.second);
  if (v2) {
    if ((uint8)v3 >= 0x11 && (uint8)v3 < 0x6E) {
      CheckIfBlockWasHit(v3, 0);
      ret = true;
      RunPlayerBlockCode_00EB48(player_wall_walk_status & 1);
    }
  } else {
    RunPlayerBlockCode_00F309(v3);
  }
  return ret;
}

bool RunPlayerBlockCode_00F005_ReturnsTwice(uint8 j) {  // 00f005
  if ((uint8)(j - 14) < 2 && ((uint8)(j - 14) ^ 1) == player_facing_direction) {
    uint8 v1 = (j - 14) ^ 1;
    uint8 v2 = player_xpos_in_block;
    if (v1 & 1)
      v2 ^= 0xF;
    if (v2 < 8) {
      if (player_riding_yoshi_flag) {
        io_sound_ch3 = 8;
        player_yspeed = 0x80;
        camera_bounce_off_spring_flag = 0x80;
        player_in_air_flag = 36;
        return true;
      } else if (((kRunPlayerBlockCode_DATA_00EAB9[v1] ^ (player_xspeed - kRunPlayerBlockCode_DATA_00EAB9[v1])) & 0x80) == 0 &&
                 !(player_ducking_flag | player_carrying_something_flag2)) {
        player_wall_walk_status = v1 + 2;
      }
    }
  }
  return false;
}

uint8 CheckWaterSlope(uint8 a) {  // 00f04d
  uint8 v1 = 25;
  while (1) {
    if (a == kRunPlayerBlockCode_WaterSlopeMap16Numbers[v1])
      return 1;
    if ((--v1 & 0x80) != 0)
      return 0;
  }
}

void RunPlayerBlockCode_CheckIfPlayerTouchingHurtBlock(uint8 a, uint8 j, bool ignore_yoshi) {  // 00f120
  if (ignore_yoshi || !player_riding_yoshi_flag) {
    if (a == 47 ||
      a >= 0x59 && a < 0x5C && (misc_level_tileset_setting == 5 || misc_level_tileset_setting == 13) ||
      (a >= 0x59 && a < 0x5d || a >= 0x66 && a < 0x6A) && misc_level_tileset_setting == 1) {
      DamagePlayer_Hurt();
      return;
    }
  }
  CheckIfBlockWasHit(a, j);
}

void CheckIfBlockWasHit(uint8 a, uint8 j) {  // 00f160
  a = a - 17;
  if (a >= 0x1D) {
    if ((kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting] & 3) == 0 && (uint8)(a - 89) < 2)
      CheckIfBlockWasHit_Entry3(a - 89 + 34, j);
  } else {
    CheckIfBlockWasHit_Entry3(a, j);
  }
}

void CheckIfBlockWasHit_Entry3(uint8 a, uint8 j) {  // 00f17f
  uint8 v3;
  int8 v5;

  if ((kCheckIfBlockWasHit_DATA_00F0A4[a] & kCheckIfBlockWasHit_DATA_00F0EC[j]) == 0)
    goto LABEL_20;
  R6_ = j;
  R7_ = kCheckIfBlockWasHit_DATA_00F0C8[a];
  R4_ = kCheckIfBlockWasHit_DATA_00F05C[a];
  int8 v2 = kCheckIfBlockWasHit_DATA_00F080[a];
  if (v2 >= 0)
    goto LABEL_9;
  if (v2 != -1) {
    uint8 v4 = (v2 & 1) ? 0x80 : 0;
    v2 = kCheckIfBlockWasHit_DATA_00F100[(uint8)(((uint8)blocks_xpos >> 1) + v4) >> 3];
LABEL_9:
    v5 = v2 & 1;
    v3 = (uint8)v2 >> 1;
    if (v5) {
      if (v3 != 3) {
        if (!player_current_power_up)
          v3 = 1;
        goto LABEL_15;
      }
      if (!timer_star_power)
        goto LABEL_14;
    }
    goto LABEL_15;
  }
  v3 = 5;
  if (counter_green_star_block)
LABEL_14:
    v3 = 6;
LABEL_15:
  R5_ = v3;
  if (v3 == 5) {
    v3 = 22;
    R7_ = 22;
  }
  blocks_xpos &= ~0xf;
  blocks_ypos &= ~0xf;
  if (v3 != 6 || misc_level_tileset_setting != 4)
    goto LABEL_19;
  uint8 v6 = (blocks_ypos >> 6) & 7;
  uint8 v7 = kCheckIfBlockWasHit_DATA_00F0EC[(uint8)blocks_xpos >> 4] | *(&timer_inflate_from_pballoon + v6);
  int8 v8 = *(&timer_inflate_from_pballoon + v6);
  *(&timer_inflate_from_pballoon + v6) = v7;
  if (v7 == 0xFF) {
    R5_ = 5;
LABEL_23:
    R7_ = 23;
LABEL_19:
    SpawnBounceSprite();
    goto LABEL_20;
  }
  if (!flag_prevent_coin_bonus_game_replay) {
    uint8 v9 = v8 ? 2 : 0;
    if ((counter_global_frames & (v9 ^ 3)) != 0)
      goto LABEL_23;
  }
  io_sound_ch3 = 42;
  R5_ = 0;
  SpawnBounceSprite();
  int8 v10 = 7;
  uint8 v11 = *(&timer_inflate_from_pballoon + v6);
  do {
    v5 = v11 & 1;
    v11 >>= 1;
    if (!v5) {
      uint8 v12 = v11;
      blocks_map16_to_generate = 13;
      LOBYTE(blocks_xpos) = kCheckIfBlockWasHit_DATA_00F0F8[(uint8)v10];
      GenerateTile();
      v11 = v12;
    }
  } while (--v10 >= 0);
LABEL_20:;
}

void RunPlayerBlockCode_CheckIfGrabbingThrowBlock(uint8 j) {  // 00f267
  if (j == 46 && (io_controller_press1 & 0x40) != 0 && !(player_riding_yoshi_flag | player_carrying_something_flag2) &&
      (GrabThrowBlockBlock() & 0x80) == 0) {
    blocks_map16_to_generate = 2;
    GenerateTile();
  }
}

void RunPlayerBlockCode_00F28C(uint8 j) {  // 00f28c
  int8 v1 = j - 111;
  if ((uint8)(j - 111) >= 4) {
    RunPlayerBlockCode_00F2C2(j, 1);
    return;
  }
  if (v1 == counter_1up_check_points_collected)
    goto LABEL_6;
  if (v1 + 1 != counter_1up_check_points_collected && counter_1up_check_points_collected < 4) {
    v1 = -1;
LABEL_6:
    counter_1up_check_points_collected = v1 + 1;
    if (v1 == 3) {
      TriggerHidden1up();
      flag_collected1up_checkpoints[ow_level_number_lo >> 3] |= kBitTable_Bank05[ow_level_number_lo & 7];
    }
  }
}

void RunPlayerBlockCode_00F2C2(uint8 j, uint8 a) {  // 00f2c2
  if (j < 6)
    temp8a |= a;
  else
    RunPlayerBlockCode_00F2C9(j, a);
}

void RunPlayerBlockCode_00F2C9(uint8 j, uint8 a) {  // 00f2c9
  if (j == 56) {
    blocks_map16_to_generate = 2;
    GenerateTile();
    SpawnGlitterEffectForCoin();
    if (unusedram_disable_midpoint)
      PlayerState00_SetMidpointFlag();
    if (!player_current_power_up)
      player_current_power_up = 1;
    io_sound_ch1 = 5;
  } else {
    if (j != 6) {
      if (j < 7 || j >= 0x1D) {
        RunPlayerBlockCode_00F309(j);
        return;
      }
      a |= 0x80;
    }
    if (a == 1)
      a = 25;
    temp8b |= a;
    temp8c = player_hdir_block_touched;
  }
}

void RunPlayerBlockCode_00F309(uint8 j) {  // 00f309
  if (j >= 0x2F || j < 0x2A) {
    if (j != 110)
      return;
    SpawnScoreSpriteAtPlayerPosition(0xF);
    ++unusedram_3up_moons_counter;
    flag_collected_moons[ow_level_number_lo >> 3] |= kBitTable_Bank05[ow_level_number_lo & 7];
    blocks_map16_to_generate = 1;
    goto LABEL_15;
  }
  if (j != 42 || timer_blue_pswitch) {
    if (j != 45) {
      if (j < 0x2D) {
        GiveCoins_OneCoin();
        blocks_map16_to_generate = 1;
LABEL_15:
        GenerateTile();
        SpawnGlitterEffectForCoin();
        return;
      }
      LOBYTE(blocks_ypos) = blocks_ypos - 16;
    }
    RunPlayerBlockCode_00F377();
    if (++counter_yoshi_coins_to_display >= 5)
      flag_collected5_yoshi_coins[ow_level_number_lo >> 3] |= kBitTable_Bank05[ow_level_number_lo & 7];
    io_sound_ch1 = 28;
    GiveCoins_MultipleCoins_NoCoinSound(1);
    blocks_map16_to_generate = 24;
    goto LABEL_15;
  }
}

void RunPlayerBlockCode_00F377() {  // 00f377
  uint8 v1 = 9 + counter_yoshi_coins_collected++;
  SpawnScoreSpriteAtPlayerPosition(v1 < 13 ? v1 : 13);
}

void SpawnScoreSpriteAtPlayerPosition_LakituEntry() {  // 00f388
  SpawnScoreSpriteAtPlayerPosition(0xD);
}

void SpawnScoreSpriteAtPlayerPosition(uint8 a) {  // 00f38a
  uint8 v1 = CheckAvailableScoreSpriteSlot();
  score_spr_spriteid[v1] = a;
  SetHiLo(&score_spr_xpos_hi[v1], &score_spr_xpos_lo[v1], player_xpos);
  SetHiLo(&score_spr_ypos_hi[v1], &score_spr_ypos_lo[v1], player_ypos);
  score_spr_yspeed[v1] = 48;
  score_spr_layer_index[v1] = 0;
}

void RunPlayerBlockCode_CheckIfEnteringHorizontalPipe(uint8 k, uint8 j, uint8 a) {  // 00f3c4
  if (j == 63) {
    if (temp8f) {
      RunPlayerBlockCode_00F43F();
    } else {
      int8 v4 = player_xpos;
      if (a)
        v4 = -player_xpos;
      sub_F40A(a, 5, 2 * (v4 & 0xF) + 32);
    }
  }
}

uint8 RunPlayerBlockCode_00F3E9(uint8 a, uint8 j) {  // 00f3e9
  if ((uint8)(j - 55) >= 2)
    return j;
  j -= 55;
  if ((uint8)(player_xpos_in_block - (1 + kRunPlayerBlockCode_DATA_00F3E3[j])) < 5) {
    uint8 v3 = player_riding_yoshi_flag ? 48 : 32;
    return sub_F40A(a, 6, v3);
  } else {
    return blocks_currently_processed_map16_tile_lo;
  }
}

uint8 sub_F40A(uint8 k, uint8 j, uint8 a) {  // 00f40a
  player_timer_pipe_warping = a;
  int8 v3 = kRunPlayerBlockCode_PIPE_BUTTONS[k] & io_controller_hold1;
  if (v3) {
    flag_sprites_locked = kRunPlayerBlockCode_PIPE_BUTTONS[k] & io_controller_hold1;
    player_facing_direction = v3 & 1;
    player_pipe_action = k;
    int8 v4 = k >> 1;
    if (!v4 && player_carrying_something_flag2) {
      player_facing_direction ^= 1;
      timer_display_player_face_screen_pose = 8;
    }
    yoshi_in_pipe = v4 + 1;
    player_current_state = j;
    DamagePlayer_DisableButtons();
    io_sound_ch1 = 4;
  }
  return blocks_currently_processed_map16_tile_lo;
}

uint8 RunPlayerBlockCode_00F43F() {  // 00f43f
  return blocks_currently_processed_map16_tile_lo;
}

uint8 RunPlayerBlockCode_00F443() {  // 00f443
  return (((uint8)player_xpos + 4) & 0xF) >= 8;
}

PairU16 GetPlayerLevelCollisionMap16ID_WallRun(uint8 k) {  // 00f44d
  uint8 v1 = k;  // moved incr to outside
  blocks_xpos = kGetPlayerLevelCollisionMap16ID_DATA_00E832[(v1 >> 1) - 1] + player_xpos;
  blocks_ypos = kGetPlayerLevelCollisionMap16ID_DATA_00E89C[v1 >> 1] + player_ypos;
  return GetPlayerLevelCollisionMap16ID_Entry2(v1);
}

PairU16 GetPlayerLevelCollisionMap16ID_Entry2(uint8 k) {  // 00f465
  misc_color_of_palace_switch_pressed2 = 0;
  if ((temp8e & 0x80) != 0) {
    if (temp8e & 0x7f) {
      if (HIBYTE(blocks_xpos) >= 2 || HIBYTE(blocks_ypos) >= 0xE)
        return MakePairU16_AY(0, 0x25);
      R0_W = PAIR16(kLevelDataLayoutTables_EightBitHi_Vertical_L2[HIBYTE(blocks_ypos)], kLevelDataLayoutTables_EightBitLo_Vertical_L2[HIBYTE(blocks_ypos)]) +
          (blocks_ypos & 0xF0 | ((uint8)blocks_xpos >> 4) | HIBYTE(blocks_xpos) << 8);
    } else if (blocks_ypos < 0x1B0) {
      if (HIBYTE(blocks_xpos) >= 0x10)
        return MakePairU16_AY(0, 0x25);
      R0_W = PAIR16(kLevelDataLayoutTables_EightBitHi_Horizontal_L2[HIBYTE(blocks_xpos)], kLevelDataLayoutTables_EightBitLo_Horizontal_L2[HIBYTE(blocks_xpos)]) +
          (blocks_ypos & 0xF0 | ((uint8)blocks_xpos >> 4) | HIBYTE(blocks_ypos) << 8);
    } else {
      return MakePairU16_AY(0, 0x25);
    }
  } else {
    if (temp8e) {
      if (HIBYTE(blocks_xpos) >= 2 || HIBYTE(blocks_ypos) >= misc_screens_in_lvl)
        return MakePairU16_AY(0, 0x25);
      R0_W = PAIR16(kLevelDataLayoutTables_EightBitHi_Vertical[HIBYTE(blocks_ypos)], kLevelDataLayoutTables_EightBitLo_Vertical[HIBYTE(blocks_ypos)]) +
        (blocks_ypos & 0xF0 | ((uint8)blocks_xpos >> 4) | HIBYTE(blocks_xpos) << 8);
    } else {
      if (blocks_ypos >= 0x1B0 || HIBYTE(blocks_xpos) >= misc_screens_in_lvl)
        return MakePairU16_AY(0, 0x25);
      R0_W = PAIR16(kLevelDataLayoutTables_EightBitHi[HIBYTE(blocks_xpos)], kLevelDataLayoutTables_EightBitLo[HIBYTE(blocks_xpos)]) +
        (blocks_ypos & 0xF0 | ((uint8)blocks_xpos >> 4) | HIBYTE(blocks_ypos) << 8);
    }
  }
  R2_ = 126;
  blocks_currently_processed_map16_tile_lo = *IndirPtr(&R0_, 0);
  ++R2_;
  uint8 *v6 = IndirPtr(&R0_, 0);
  uint8 v7 = ModifyMap16IDForSpecialBlocks(*v6);
  return MakePairU16_AY(v7, blocks_currently_processed_map16_tile_lo);
}

uint8 ModifyMap16IDForSpecialBlocks(uint8 a) {  // 00f545
  if (!a) {
    if (blocks_currently_processed_map16_tile_lo == 41) {
      if (timer_blue_pswitch)
        return blocks_currently_processed_map16_tile_lo = 36;
    } else if (blocks_currently_processed_map16_tile_lo == 43) {
      if (timer_blue_pswitch)
        return blocks_currently_processed_map16_tile_lo = 50;
    } else if ((uint8)(blocks_currently_processed_map16_tile_lo + 20) < 0x10) {
      misc_color_of_palace_switch_pressed2 = blocks_currently_processed_map16_tile_lo + 21;
      return blocks_currently_processed_map16_tile_lo = 50;
    }
    return 0;
  }
  if (blocks_currently_processed_map16_tile_lo == 50) {
    if (!timer_blue_pswitch)
      return a;
    blocks_currently_processed_map16_tile_lo = 43;
    return 0;
  }
  if (blocks_currently_processed_map16_tile_lo == 47 && timer_silver_pswitch) {
    blocks_currently_processed_map16_tile_lo = 43;
    return 0;
  }
  return a;
}

void PlayerState00_CheckPlayerPitFall() {  // 00f595
  if (!sign16(mirror_current_layer1_ypos - 128 - player_ypos))
    player_ypos = mirror_current_layer1_ypos - 128;
  if ((int8)(HIBYTE(player_on_screen_pos_y) - 1) >= 0) {
    if (in_yoshi_wings_bonus_area)
      PlayerState00_00C95B();
    else
      DamagePlayer_PitFall();
  }
}

void DamagePlayer_Hurt() {  // 00f5b7
  if (!player_current_state && !(timer_end_level | (uint8)(timer_star_power | timer_player_hurt))) {
    counter_pink_berry_cloud_coins = 0;
    if (player_wall_walk_status)
      RunPlayerBlockCode_00EB48(player_wall_walk_status & 1);
    if (player_current_power_up) {
      if (player_current_power_up == 2 && player_cape_flying_phase) {
        io_sound_ch1 = 15;
        player_spin_jump_flag = 1;
        timer_player_hurt = 48;
        DamagePlayer_00F622();
      } else {
        io_sound_ch1 = 4;
        DropReservedItem();
        player_current_state = 1;
        player_current_power_up = 0;
        DamagePlayer_SetHurtAnimationTimer(0x2F);
      }
    } else {
      DamagePlayer_Kill();
    }
  }
}

void DamagePlayer_Kill() {  // 00f606
  player_yspeed = -112;
  DamagePlayer_PitFall();
}

void DamagePlayer_PitFall() {  // 00f60a
  io_music_ch1 = 9;
  misc_music_register_backup = -1;
  player_current_state = 9;
  player_spin_jump_flag = 0;
  DamagePlayer_SetHurtAnimationTimer(0x30);
}

void DamagePlayer_SetHurtAnimationTimer(uint8 a) {  // 00f61d
  player_anim_timer = a;
  flag_sprites_locked = a;
  DamagePlayer_00F622();
}

void DamagePlayer_00F622() {  // 00f622
  player_cape_flying_phase = 0;
  unusedram_7e188a = 0;
}

void DamagePlayer_KillAndDisableButtons() {  // 00f629
  DamagePlayer_Kill();
  DamagePlayer_DisableButtons();
}

void DamagePlayer_DisableButtons() {  // 00f62d
  io_controller_hold1 = 0;
  io_controller_press1 = 0;
  io_controller_hold2 = 0;
  io_controller_press2 = 0;
}

void PlayerGFXRt_00F636() {  // 00f636
  uint16 t = (R10_ & 0xf7) << 6 | ((R10_ & 0x8) ? 0x4000 : 0);
  *(uint16 *)graphics_dynamic_sprite_pointers_top_lo = t + 0x2000;
  *(uint16 *)graphics_dynamic_sprite_pointers_bottom_lo = t + 0x2200;

  t = (R11_ & 0xf7) << 6 | ((R11_ & 0x8) ? 0x4000 : 0);
  *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[2] = t + 0x2000;
  *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[2] = t + 0x2200;

  t = 32 * R12_;
  *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[4] = t + 0x2000;
  *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[4] = t + 0x2200;

  graphics_dynamic_sprite_tile7 = 32 * R13_ + 0x2000;
  player_number_of_tiles_to_update = 10;
}

void HandleStandardLevelCameraScroll() {  // 00f6db
  camera_pos_for_scroll[0] = player_relative_position_needed_to_scroll_screen - 12;
  camera_pos_for_scroll[1] = player_relative_position_needed_to_scroll_screen - 12 + 24;
  PointU16 *pt = get_PointU16(misc_layer1_pos, 0);
  mirror_current_layer1_xpos = pt->x;
  mirror_current_layer1_ypos = pt->y;
  mirror_current_layer2_xpos = pt[1].x;
  mirror_current_layer2_ypos = pt[1].y;
  if (misc_level_layout_flags & 1) {
    HandleStandardLevelCameraScroll_00F7F4((camera_last_screen_vert - 1) << 8);
    if (flag_layer1_horiz_scroll_level_setting) {
      uint8 v7 = 0;
      R0_W = player_xpos - mirror_current_layer1_xpos;
      if ((int16)(player_xpos - mirror_current_layer1_xpos - player_relative_position_needed_to_scroll_screen) >= 0)
        v7 = 2;
      R2_W = player_xpos - mirror_current_layer1_xpos - camera_pos_for_scroll[v7 >> 1];
      if (((kHandleStandardLevelCameraScroll_DATA_00F6A3[v7 >> 1] ^ R2_W) & 0x8000) != 0) {
        HandleStandardLevelCameraScroll_00F8AB();
        uint16 v8 = mirror_current_layer1_xpos + R2_W;
        if ((int16)v8 < 0)
          v8 = 0;
        if (!sign16(v8 - 257))
          v8 = 256;
        mirror_current_layer1_xpos = v8;
      }
    }
  } else {
    HandleStandardLevelCameraScroll_00F7F4(0xC0);
    if (flag_layer1_horiz_scroll_level_setting) {
      R0_W = player_xpos - mirror_current_layer1_xpos;
      uint8 v1 = ((int16)(R0_W - player_relative_position_needed_to_scroll_screen) < 0) ? 0 : 2;
      camera_layer1_scrolling_direction = v1;
      camera_layer2_scrolling_direction = v1;
      int16 v2 = R0_W - camera_pos_for_scroll[v1 >> 1];
      if (v2) {
        R2_W = player_xpos - mirror_current_layer1_xpos - camera_pos_for_scroll[v1 >> 1];
        if (((kHandleStandardLevelCameraScroll_DATA_00F6A3[v1 >> 1] ^ v2) & 0x8000) != 0) {
          HandleStandardLevelCameraScroll_00F8AB();
          uint16 v3 = mirror_current_layer1_xpos + R2_W;
          if ((int16)(mirror_current_layer1_xpos + R2_W) < 0)
            v3 = 0;
          mirror_current_layer1_xpos = v3;
          int16 v5 = (camera_last_screen_horiz - 1) << 8;
          if (v5 < 0)
            v5 = 128;
          if (sign16(v5 - mirror_current_layer1_xpos))
            mirror_current_layer1_xpos = v5;
        }
      }
    }
  }
  if (flag_layer2_horiz_scroll_level_setting) {
    uint16 v9 = mirror_current_layer1_xpos;
    if (flag_layer2_horiz_scroll_level_setting != 1)
      v9 >>= 1;
    mirror_current_layer2_xpos = v9;
  }
  if (flag_layer2_vert_scroll_level_setting) {
    uint16 v10 = mirror_current_layer1_ypos;
    if (flag_layer2_vert_scroll_level_setting != 1)
      v10 = (flag_layer2_vert_scroll_level_setting != 2) ? v10 >> 5 : v10 >> 1;
    mirror_current_layer2_ypos = camera_layer2_ypos_relative_to_layer1 + v10;
  }
  misc_layer1_xdisp = mirror_current_layer1_xpos - LOBYTE(pt->x);
  misc_layer1_ydisp = mirror_current_layer1_ypos - LOBYTE(pt->y);
  misc_layer2_xdisp = mirror_current_layer2_xpos - LOBYTE(pt[1].x);
  misc_layer2_ydisp = mirror_current_layer2_ypos - LOBYTE(pt[1].y);
  for (uint8 i = 7; (i & 0x80) == 0; --i)
    LOBYTE(get_PointU16(misc_layer1_pos, i)->x) = *((uint8 *)&mirror_current_layer1_xpos + i);
}

void HandleStandardLevelCameraScroll_00F7F4(uint16 a) {  // 00f7f4
  if (flag_layer1_vert_scroll_level_setting) {
    R4_W = a;
    uint8 v1 = 0;
    R0_W = player_ypos - mirror_current_layer1_ypos;
    if (!sign16(player_ypos - mirror_current_layer1_ypos - 112))
      v1 = 2;
    camera_layer1_scrolling_direction = v1;
    camera_layer2_scrolling_direction = v1;
    int v2 = v1 >> 1;
    R2_W = player_ypos - mirror_current_layer1_ypos - kHandleStandardLevelCameraScroll_DATA_00F69F[v2];
    if (((kHandleStandardLevelCameraScroll_DATA_00F6A3[v2] ^ R2_W) & 0x8000) == 0) {
      v1 = 2;
      R2_W = 0;
    }
    if ((R2_W & 0x8000) != 0) {
      uint8 v3 = player_wall_walk_status;
      if (player_wall_walk_status < 6)
        v3 = camera_bounce_off_spring_flag | flag_player_in_lakitus_cloud | timer_inflate_from_pballoon | player_climbing_flag |
             timer_wait_before_cape_flight_begins | (flag_display_yoshis_wings >> 1);
      uint8 v4 = v3;
      if (v3 || player_riding_yoshi_flag && (v4 = yoshi_yoshi_has_wings, yoshi_yoshi_has_wings >= 2) ||
          player_swimming_flag && (v4 = player_in_air_flag) != 0 ||
          flag_layer1_vert_scroll_level_setting != 1 && (v4 = flag_enable_vert_scroll) == 0) {
        flag_enable_vert_scroll = v4;
        if (!v4)
          v1 = 4;
      } else if (!flag_scroll_up_to_player) {
        if (player_in_air_flag)
          return;
        ++*(uint16 *)&flag_scroll_up_to_player;
      }
    } else {
      flag_scroll_up_to_player = 0;
    }
    int v5 = v1 >> 1;
    uint16 v6 = R2_W;
    uint16 t = (v6 - kHandleStandardLevelCameraScroll_DATA_00F6A7[v5]) ^ kHandleStandardLevelCameraScroll_DATA_00F6A7[v5];
    if (!sign16(t))
      v6 = kHandleStandardLevelCameraScroll_DATA_00F6A7[v5];
    uint16 v7 = mirror_current_layer1_ypos + v6;
    if ((int16)(v7 - kHandleStandardLevelCameraScroll_DATA_00F6AD[v5]) < 0)
      v7 = kHandleStandardLevelCameraScroll_DATA_00F6AD[v5];
    mirror_current_layer1_ypos = v7;
    if (sign16(R4_W - v7)) {
      mirror_current_layer1_ypos = R4_W;
      *(uint16 *)&flag_enable_vert_scroll = 0;
    }
  }
}

void HandleStandardLevelCameraScroll_00F8AB() {  // 00f8ab
  if (!flag_lrscroll_flag) {
    uint8 v0 = 8;
    int v1 = player_facing_directionx2 >> 1;
    if ((int16)(player_relative_position_needed_to_scroll_screen - kHandleStandardLevelCameraScroll_DATA_00F6B3[v1]) < 0)
      v0 = 10;
    int v2 = v0 >> 1;
    if (((R2_W ^ kHandleStandardLevelCameraScroll_DATA_00F6BF[v2]) & 0x8000) != 0 &&
        ((R2_W ^ kHandleStandardLevelCameraScroll_DATA_00F6BF[v1]) & 0x8000) != 0) {
      if (kHandleStandardLevelCameraScroll_DATA_00F6CF[v2] + R2_W) {
        R2_W += kHandleStandardLevelCameraScroll_DATA_00F6CF[v2];
        camera_lrscroll_move_flag = v0;
      }
    }
  }
}

void PlayerState00_00F8F2() {  // 00f8f2
  ResetPlayerLevelCollisionRAM();
  if ((misc_nmito_use_flag & 0x40) != 0) {
    HandlePlayerLevelCollision();
    uint8 v0 = misc_currently_active_boss;
    if ((player_yspeed & 0x80) != 0 && (int16)(player_ypos - kPlayerState00_DATA_00F8E8[v0]) < 0) {
      player_ypos = kPlayerState00_DATA_00F8E8[v0];
      player_yspeed = 0;
      io_sound_ch1 = 1;
    }
    if (kPlayerState00_DATA_00F8E8[misc_currently_active_boss] == 42) {
      uint8 v1 = 0;
      int16 t = spr_table160e[9] + 1 - player_xpos;
      if (t > 0) {
        R0_W = spr_table1534[9];
        t = player_xpos + 15 - R0_W;
        v1 = 1;
      }
      HandlePlayerLevelColl_00E9C8(v1, t < 0);
    }
  } else {
    if (!(player_yspeed & 0x80)) {
      if (PlayerState00_00F9A8()) {
        if (player_in_air_flag) {
          *(uint16 *)&temp14b4 = temp14b8;
          *(uint16 *)&temp1436 = temp14b8;
          *(uint16 *)&temp14b6 = temp14ba & 0xF0;
          *(uint16 *)&temp1438 = temp14ba & 0xF0;
          PlayerState00_00F9C9();
        }
        uint8 v2 = kPlayerState00_DATA_00F8DF[(uint8)(misc_m7_rotation + 72) >> 4];
        temp8e = 0x80;
        RunPlayerBlockCode_00EEE1(v2);
      } else {
        RunPlayerBlockCode_00EE1D();
      }
    }
    if ((int16)(player_on_screen_pos_y - 174) >= 0)
      DamagePlayer_KillAndDisableButtons();
    HandlePlayerLevelColl_00E98C();
  }
}

uint8 PlayerState00_00F9A8() {  // 00f9a8
  *(uint16 *)&temp14b4 = player_xpos + 8;
  *(uint16 *)&temp14b6 = player_ypos + 32;
  return PlayerState00_00F9BC();
}

uint8 PlayerState00_00F9BC() {  // 00f9bc
  return CheckTiltingPlatformCollision();
}

void PlayerState00_00F9C9() {  // 00f9c9
  uint16 v0 = misc_m7_rotation;
  misc_m7_rotation = -misc_m7_rotation;
  PlayerState00_00F9BC();
  misc_m7_rotation = v0;
  player_xpos = temp14b8 - 8;
  player_ypos = temp14ba - 32;
}

uint8 CheckWhatSlopeSpriteIsOn(uint8 a) {  // 00fa19
  R5_ = 50;
  R6_ = -26;
  R7_ = 0;
  R8_ = *IndirPtr(&ptr_slope_steepness, (uint8)(a - 110));
  R1_ = 16 * R8_;
  if (__CFSHL__(8 * R8_, 1))
    ++R6_;
  R0_ = R12_ & 0xF;
  return R1_ | R10_ & 0xF;
}

void RunPlayerBlockCode_SpawnFlatPalaceSwitch() {  // 00fa45
  timer_shake_layer1 = 32;
  spr_spriteid[2] = 96;
  spr_current_status[2] = 8;
  SetSprXPos(2, blocks_xpos & ~0xf);
  SetSprYPos(2, (blocks_ypos & ~0xf) + 16);
  InitializeNormalSpriteRAMTables(2);
  spr_decrementing_table1540[2] = 95;
}

void Spr07B_GoalTape_TriggerGoalTape() {  // 00fa80
  timer_inflate_from_pballoon = 0;
  timer_player_has_pballoon = 0;
  timer_respawn_sprite = 0;
  gen_spr_spriteid = 0;
  counter_current_silver_coins = 0;
  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    if (spr_current_status[i] >= 8) {
      if (spr_current_status[i] == 11) {
        Spr07B_GoalTape_LvlEndPowerUp(i);
      } else if (spr_spriteid[i] != 123 && spr_yoffscreen_flag[i] | spr_xoffscreen_flag[i] || (spr_property_bits1686[i] & 0x20) != 0) {
        if ((spr_property_bits190f[i] & 2) == 0)
          spr_current_status[i] = 0;
      } else {
        spr_decrementing_table1540[i] = 16;
        spr_current_status[i] = 6;
      }
    }
  }
  for (int8 j = 7; j >= 0; --j)
    ext_spr_spriteid[(uint8)j] = 0;
}

void Spr07B_GoalTape_LvlEndPowerUp(uint8 j) {  // 00fb00
  uint8 v1 = player_current_power_up;
  if (timer_star_power)
    v1 = 4;
  if (player_riding_yoshi_flag)
    v1 = 5;
  uint8 v2 = spr_spriteid[j];
  switch (v2) {
  case 0x2F:
  case 0x3E: goto LABEL_11;
  case 0x80:
LABEL_10:
    v1 += 7;
LABEL_11:
    v1 += 7;
    break;
  case 0x2D: v1 += 7; goto LABEL_10;
  }
  uint8 v3 = kSpr07B_GoalTape_DATA_00FADF[v1];
  if (v3 == kSpr07B_GoalTape_DATA_00FAFB[player_current_item_box])
    v3 = 120;
  R15_ = 0;
  if (v3 >= 0xE0) {
    R15_ = v3 & 0xF;
    v3 = 120;
  }
  spr_spriteid[j] = v3;
  if (v3 == 118)
    ++unusedram_got_invincible_star_from_goal;
  InitializeNormalSpriteRAMTables(j);
  spr_table1594[j] = R15_;
  spr_current_status[j] = 12;
  spr_yspeed[j] = -48;
  spr_xspeed[j] = 5;
  spr_decrementing_table154c[j] = 32;
  io_sound_ch1 = 12;
  uint8 v4 = 3;
  while (smoke_spr_spriteid[v4]) {
    if ((--v4 & 0x80) != 0)
      return;
  }
  smoke_spr_spriteid[v4] = 1;
  smoke_spr_ypos_lo[v4] = spr_ypos_lo[j];
  smoke_spr_xpos_lo[v4] = spr_xpos_lo[j];
  smoke_spr_timer[v4] = 27;
}

void SprStatus06_GoalCoins(uint8 k) {  // 00fbb4
  AddSprXPos(k, (int8)misc_layer1_xdisp);
  uint8 v3 = spr_decrementing_table1540[k];
  if (v3) {
    if (v3 == 1)
      spr_yspeed[k] = -48;
    spr_table15f6[k] = 4;
    GenericGFXRtDraw1Tile16x16(k);
    get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = kSprStatus06_GoalCoins_SmokeTiles[spr_decrementing_table1540[k] >> 2];
  } else {
    ++spr_table1570[k];
    UpdateNormalSpritePosition_Y(k);
    spr_yspeed[k] += 2;
    if (!sign8(spr_yspeed[k] - 32)) {
      GiveCoins_OneCoin();
      uint8 v4 = counter_current_silver_coins;
      if (counter_current_silver_coins >= 0xD)
        v4 = 13;
      GivePoints(k, v4);
      counter_current_silver_coins += 2;
      spr_current_status[k] = 0;
    }
    PowerUpAndItemGFXRt_DrawCoinSprite(k);
  }
}

void UnusedYoshiRelatedRoutine() {  // 00fc23
  uint8 j = 11;
  while (spr_current_status[j] != 8 || spr_spriteid[j] != 53) {
    if ((--j & 0x80) != 0) {
      yoshi_carry_over_levels_flag = 0;
      return;
    }
  }
  yoshi_carry_over_levels_flag = 1;
  yoshi_yoshi_has_wings = 0;
  spr_table15f6[j] = spr_table15f6[j] & 0xF1 | 0xA;
  if (!player_riding_yoshi_flag) {
    SetSprXPos(j, mirror_current_layer1_xpos - 16);
    SetSprYPos(j, player_ypos);
    spr_table00c2[j] = 3;
    spr_table157c[j] = 0;
    spr_xspeed[j] = 16;
  }
}

void SpawnMountedYoshiOnLevelLoad() {  // 00fc7a
  io_sound_ch2 = 2;
  uint8 j = 0;
  if (!flag_disable_bonus_game_sprite) {
    j = 5;
    if (sprites_sprite_memory_setting != 10) {
      j = FindFreeNormalSpriteSlot_HighPriority();
      if ((j & 0x80) != 0)
        j = 3;
    }
  }
  spr_current_status[j] = 8;
  spr_spriteid[j] = 53;
  SetSprXPos(j, player_xpos);
  player_ypos -= 16;
  SetSprYPos(j, player_ypos);
  InitializeNormalSpriteRAMTables(j);
  spr_decrementing_table1fe2[j] = 4;
  spr_table15f6[j] = yoshi_current_yoshi_color;
  if (in_yoshi_wings_bonus_area)
    spr_table15f6[j] = 6;
  ++player_riding_yoshi_flag;
  ++spr_table00c2[j];
  spr_table157c[j] = player_facing_direction ^ 1;
  --spr_table160e[j];
  sprites_yoshi_slot_index = j + 1;
  yoshi_stray_yoshi_flag = j + 1;
}

void ClearOutNormalSpriteSlots() {  // 00fcec
  for (int8 i = 11; i >= 0; --i)
    spr_current_status[(uint8)i] = 0;
}

void Spr029_KoopaKids_Init_SetPosition(uint8 k) {  // 00fcf5
  SetSprXPos(k, 160);
  SetSprYPos(k, 0);
}

void SpawnPlayerBreathBubble() {  // 00fd08
  uint8 v3;
  uint8 v0 = 63;
  if ((io_controller_hold1 & 0x83) == 0)
    v0 = 127;
  if (!(flag_sprites_locked | (uint8)(counter_local_frames & v0))) {
    uint8 v1 = 7;
    while (ext_spr_spriteid[v1]) {
      if ((--v1 & 0x80) != 0)
        return;
    }
    ext_spr_spriteid[v1] = 18;
    SetHiLo(&ext_spr_xpos_hi[v1], &ext_spr_xpos_lo[v1],
        player_xpos + kSpawnPlayerBreathBubble_xlo[player_facing_direction]);
    if (!player_current_power_up || (v3 = 4, player_ducking_flag))
      v3 = 12;
    SetHiLo(&ext_spr_ypos_hi[v1], &ext_spr_ypos_lo[v1], player_ypos + v3);
    ext_spr_decrementing_table176f[v1] = 0;
  }
}

void SpawnGlitterEffectForCoin() {  // 00fd5a
  if (!(HIBYTE(player_on_screen_pos_y) | HIBYTE(player_on_screen_pos_x))) {
    uint8 v0 = 3;
    while (smoke_spr_spriteid[v0]) {
      if ((--v0 & 0x80) != 0)
        return;
    }
    smoke_spr_spriteid[v0] = 5;
    smoke_spr_xpos_lo[v0] = blocks_xpos & 0xF0;
    smoke_spr_ypos_lo[v0] = blocks_ypos & 0xF0;
    if ((uint8)misc_current_layer_being_processed) {
      smoke_spr_xpos_lo[v0] = (blocks_xpos - misc_second_level_layer_xpos) & 0xF0;
      smoke_spr_ypos_lo[v0] = (blocks_ypos - misc_second_level_layer_ypos) & 0xF0;
    }
    smoke_spr_timer[v0] = 16;
  }
}

void SpawnPlayerWaterSplashAndBubbles() {  // 00fda5
  uint8 j = 0;
  if (player_in_air_flag) {
    j = 11;
    while (mextspr_spriteid[j]) {
      if ((--j & 0x80) != 0)
        goto LABEL_5;
    }
  } else {
LABEL_5:
    j++;
  }
  uint8 v1 = player_current_power_up != 0;
  if (player_riding_yoshi_flag)
    v1 += 2;
  uint16 ypos = player_ypos + PAIR16(kSpawnPlayerWaterSplashAndBubbles_YHi[v1], kSpawnPlayerWaterSplashAndBubbles_YLo[v1]);
  SetHiLo(&mextspr_ypos_hi[j], &mextspr_ypos_lo[j], (ypos & ~0xf) + 3);
  SetHiLo(&mextspr_xpos_hi[j], &mextspr_xpos_lo[j], player_xpos);
  mextspr_spriteid[j] = 7;
  mextspr_timer[j] = 0;
  if ((player_yspeed & 0x80) == 0) {
    player_yspeed = 0;
    if (player_in_air_flag)
      player_xspeed = 0;
    uint8 v5 = player_current_power_up ? 3 : 2;
    do {
      if (!ext_spr_spriteid[v5]) {
        ext_spr_spriteid[v5] = 18;
        ext_spr_table1765[v5] = 8 * v5 + 0xf7;
        SetHiLo(&ext_spr_ypos_hi[v5], &ext_spr_ypos_lo[v5], player_ypos + kSpawnPlayerWaterSplashAndBubbles_Bubble_YLo[v5]);
        SetHiLo(&ext_spr_xpos_hi[v5], &ext_spr_xpos_lo[v5], player_xpos + kSpawnPlayerWaterSplashAndBubbles_Bubble_XLo[v5]);
        ext_spr_decrementing_table176f[v5] = 0;
      }
    } while ((--v5 & 0x80) == 0);
  }
}

void SpawnPlayerTurnAroundSmoke() {  // 00fe4a
  if (!(flag_sprites_locked | HIBYTE(player_on_screen_pos_y) | HIBYTE(player_on_screen_pos_x) | player_in_air_flag |
        counter_global_frames & 3) &&
      ((io_controller_hold1 & 4) == 0 || (uint8)(player_xspeed + 8) >= 0x10)) {
    uint8 v0 = 3;
    while (smoke_spr_spriteid[v0]) {
      if (!--v0)
        return;
    }
    SpawnPlayerTurnAroundSmoke_00FE72(v0);
  }
}

void SpawnPlayerTurnAroundSmoke_00FE72(uint8 j) {  // 00fe72
  smoke_spr_spriteid[j] = 3;
  smoke_spr_xpos_lo[j] = player_xpos + 4;
  smoke_spr_ypos_lo[j] = player_ypos + 26 + (player_riding_yoshi_flag ? 16 : 0);
  smoke_spr_timer[j] = 19;
}

void SpawnPlayerFireball() {  // 00fea8
  uint8 v0 = 9;
  while (ext_spr_spriteid[v0]) {
    if (--v0 == 7)
      return;
  }
  io_sound_ch3 = 6;
  timer_display_player_shoot_fireball_pose = 10;
  ext_spr_spriteid[v0] = 5;
  ext_spr_yspeed[v0] = 48;
  uint8 dir = player_facing_direction;
  ext_spr_xspeed[v0] = kSpawnPlayerFireball_InitialXSpeed[dir];
  if (player_riding_yoshi_flag)
    dir += yoshi_ducking_flag ? 4 : 2;
  SetHiLo(&ext_spr_xpos_hi[v0], &ext_spr_xpos_lo[v0], player_xpos + PAIR16(kSpawnPlayerFireball_xhi[dir], kSpawnPlayerFireball_xlo[dir]));
  SetHiLo(&ext_spr_ypos_hi[v0], &ext_spr_ypos_lo[v0], player_ypos + kSpawnPlayerFireball_ylo[dir]);
  ext_spr_table1779[v0] = player_current_layer_priority;
}

void Spr088_WingedCage_SyncPlayerPosToLayer1() {  // 00ff07
  player_xpos += (int8)misc_layer1_xdisp;
  player_ypos -= (int8)misc_layer1_ydisp;
}

void Spr088_WingedCage_SyncLayer3ScrollToLayer1(uint8 k) {  // 00ff32
  uint16 v1 = GetSprXPos(k);
  mirror_layer3_xpos = 48 - (v1 - mirror_current_layer1_xpos);
  v1 = GetSprYPos(k);
  mirror_layer3_ypos = 256 - (v1 - mirror_current_layer1_ypos);
}

void Spr089_Layer3Smasher_UpdatePos(uint8 k) {  // 00ff61
  uint16 v1 = GetSprXPos(k);
  if (sign16(v1 + 256) || !sign16(v1 - 256))
    v1 = 256;
  mirror_layer3_xpos = v1;
  uint16 v2 = GetSprYPos(k);
  mirror_layer3_ypos = shaking_layer1_disp_y + 160 - v2;
}
