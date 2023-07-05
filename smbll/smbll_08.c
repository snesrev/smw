#include "smbll_consts.h"
#include "smbll_funcs.h"
#include "smbll_rtl.h"
#include "smbll_variables.h"
void Smbll_UploadSpuData() {
  WriteReg(NMITIMEN, 0);
  WriteReg(HDMAEN, 0);
  WriteReg(APUI01, 0xFFu);
  R0_ = 67;
  R1_ = -96;
  R2_ = 8;
  Smbll_HandleSPCUploads_Main();
}

void Smbll_UploadSPCEngine() {
  R0_ = 0;
  R1_ = -48;
  R2_ = 9;
  Smbll_HandleSPCUploads_Main();
}

void Smbll_UploadMainSampleData() {
  WriteReg(NMITIMEN, 0);
  WriteReg(HDMAEN, 0);
  WriteReg(MDMAEN, 0);
  WriteReg(APUI00, 0);
  WriteReg(APUI01, 0xFFu);
  WriteReg(APUI02, 0);
  WriteReg(APUI03, 0);
  R0_ = 0;
  R1_ = 0x80;
  R2_ = 10;
  Smbll_HandleSPCUploads_Main();
}

void Smbll_HandleSPCUploads_Main() {
  if (g_use_my_apu_code)
    RtlApuUpload(RomPtr(load24(R0_)));
  return;
  uint16 v0;   // di
  uint16 v1;   // ax
  uint8 *v2;   // rdx
  uint8 *v3;   // rdx
  int16 v4;    // si
  uint8 Reg;   // dl
  bool v6;     // cf
  int8 v7;     // al
  bool v8;     // tt
  uint8 *v9;   // rdx
  uint16 v10;  // di
  uint16 v11;  // ax
  uint16 v12;  // di
  uint8 v13;   // [rsp+46h] [rbp-2h]

  v0 = 0;
  while (ReadRegWord(APUI00) != 0xBBAA)
    ;
  LOBYTE(v1) = -52;
  while (1) {
    v13 = v1;
    v9 = IndirPtr((LongPtr *)&R0_, v0);
    v10 = v0 + 2;
    v4 = *(uint16 *)v9;
    v11 = *(uint16 *)IndirPtr((LongPtr *)&R0_, v10);
    v12 = v10 + 2;
    WriteRegWord(APUI02, v11);
    WriteReg(APUI01, v4 != 0);
    WriteReg(APUI00, v13);
    while (v13 != ReadReg(APUI00))
      ;
    if (Unreachable())
      break;
    v2 = IndirPtr((LongPtr *)&R0_, v12);
    v0 = v12 + 1;
    HIBYTE(v1) = *v2;
    for (LOBYTE(v1) = 0;; LOBYTE(v1) = v1 + 1) {
      WriteRegWord(APUI00, v1);
      if (!--v4)
        break;
      v3 = IndirPtr((LongPtr *)&R0_, v0++);
      HIBYTE(v1) = *v3;
      while ((uint8)v1 != ReadReg(APUI00))
        ;
    }
    do {
      Reg = ReadReg(APUI00);
      v6 = (uint8)v1 >= Reg;
    } while ((uint8)v1 != Reg);
    do {
      v8 = v6;
      v6 = __CFADD__(v6, (uint8)v1);
      v7 = v8 + v1;
      v6 |= __CFADD__(v7, 3);
      LOBYTE(v1) = v7 + 3;
    } while (!(uint8)v1);
  }
  WriteReg(APUI00, 0);
  WriteReg(APUI01, 0);
  WriteReg(APUI02, 0);
  WriteReg(APUI03, 0);
}

void Smbll_SaveGame_Main() {
  uint8 v0;        // al
  uint16 v1;       // si
  uint16 v2;       // si
  uint16 v3;       // si
  uint16 updated;  // si
  uint16 v5;       // si
  uint8 v6;        // al
  uint16 v7;       // si
  uint16 k;        // [rsp+43h] [rbp-5h]

  *(uint16 *)&R0_ = 0;
  v0 = *(&g_byte_700010 + g_word_700004);
  if ((v0 & 0x80u) != 0 || v0 < world_number || v0 == world_number && *(&g_byte_700011 + g_word_700004) < level_number) {
    updated = Smbll_StoreToSramAndUpdateChecksum(g_word_700004, world_number);
    v5 = Smbll_StoreToSramAndUpdateChecksum(updated, level_number);
    v3 = Smbll_StoreToSramAndUpdateChecksum(v5, area_number);
  } else {
    v1 = Smbll_StoreToSramAndUpdateChecksum(g_word_700004, *(&g_byte_700010 + g_word_700004));
    v2 = Smbll_StoreToSramAndUpdateChecksum(v1, *(&g_byte_700010 + v1));
    v3 = Smbll_StoreToSramAndUpdateChecksum(v2, *(&g_byte_700010 + v2));
  }
  v6 = number_of_lives;
  if ((number_of_lives & 0x80u) != 0)
    v6 = 4;
  k = Smbll_StoreToSramAndUpdateChecksum(v3, v6);
  Smbll_SaveGame_CODE_009041();
  v7 = Smbll_StoreToSramAndUpdateChecksum(k, smbll_varF2B);
  uint16 tt = Smbll_StoreToSramAndUpdateChecksum(v7, save_buffer_2_player_flag);
  *(uint16 *)(&g_byte_700010 + tt) = -*(uint16 *)&R0_;

  RtlWriteSram();
}

void Smbll_SaveGame_CODE_009041() {
  uint16 v0;  // si
  bool v1;    // cf
  uint16 v2;  // si

  v0 = 5;
  v1 = 0;
  do {
    v1 = displayed_score[v0] < v1 + sram_top_score[v0];
    --v0;
  } while ((v0 & 0x8000u) == 0);
  if (!v1) {
    v2 = 0;
    do {
      sram_top_score[v2] = displayed_score[v2];
      ++v2;
    } while (v2 < 6u);
  }
}

uint16 Smbll_StoreToSramAndUpdateChecksum(uint16 k, uint8 a) {
  uint16 result;  // si
  bool v3;        // cf

  *(&g_byte_700010 + k) = a;
  result = k + 1;
  v3 = __CFADD__(R0_, a);
  R0_ += a;
  R1_ += v3;
  return result;
}

void Smbll_ResetGame_Main() {
  WriteReg(INIDISP, 0x80u);
  WriteReg(HDMAEN, 0);
  hdmaenable_mirror = 0;
  WriteReg(NMITIMEN, 0);
  WriteReg(NMITIMEN, 0);
  WriteReg(HDMAEN, 0);
  sound_ch1 = 0;
  sound_ch2 = 0;
  music_ch1 = 0;
  sound_ch3 = 0;
  WriteReg(APUI00, 0);
  WriteReg(APUI01, 0);
  WriteReg(APUI02, 0);
  WriteReg(APUI03, 0);
  WriteReg(APUI01, 0xF0u);
  g_smbll_want_reset = true;
}

void Smbll_InitializeSelectedRAM(uint8 j, uint16 a) {
  *(uint16 *)&R2_ = 0;
  Smbll_InitializeSelectedRAM_Entry2(j, a);
}

void Smbll_InitializeSelectedRAM_Entry2(uint8 j, uint16 a) {
  WriteRegWord(A1T0L, a);
  WriteReg(A1B0, j);
  WriteRegWord(DMAP0, 0x3480u);
  WriteRegWord(DAS0L, *(uint16 *)&R0_);
  WriteReg(M7A, 1u);
  WriteReg(M7A, 0);
  WriteReg(M7B, R2_);
  WriteReg(MDMAEN, 1u);
}

void Smbll_InitializeRAMOnStartup() {
  *(uint16 *)&R0_ = 336;
  Smbll_InitializeSelectedRAM(0, 0);
  *(uint16 *)&R0_ = 7680;
  Smbll_InitializeSelectedRAM(0, 0x200u);
  *(uint16 *)&R0_ = -8192;
  Smbll_InitializeSelectedRAM(0x7Eu, 0x2000u);
  *(uint16 *)&R0_ = 0;
  Smbll_InitializeSelectedRAM(0x7Fu, 0);
  *(uint16 *)vram_buffer1 = 0;
  *(uint16 *)&vram_buffer1[2] = -1;
  save_buffer_2_player_flag = -1;
  sram_hard_mode_flag = 0;
  sram_world_number2 = 0;
  sram_world_number = 0;
  WriteReg(BGMODE, 9u);
  bgmode_mirror = 9;
  WriteReg(MOSAIC, 0);
  WriteReg(W12SEL, 0);
  WriteReg(W34SEL, 0);
  WriteReg(TMW, 0);
  WriteReg(TSW, 0);
  WriteReg(BG1SC, 3u);
  WriteReg(BG2SC, 0x13u);
  WriteReg(BG3SC, 0x51u);
  WriteReg(BG4SC, 0);
  WriteReg(BG12NBA, 0x22u);
  WriteReg(BG34NBA, 5u);
  WriteReg(TM, 0x15u);
  tm_mirror = 21;
  WriteReg(TS, 2u);
  ts_mirror = 2;
  WriteReg(CGWSEL, 0);
  WriteReg(WOBJSEL, 0);
  WriteReg(CGADSUB, 0);
  WriteReg(COLDATA, 0x20u);
  WriteReg(COLDATA, 0x40u);
  WriteReg(COLDATA, 0x80u);
  WriteReg(SETINI, 0);
}

void Smbll_CheckWhichControllersArePluggedIn_Main() {
  sram_controller1_plugged_in = 0;
  sram_controller2_plugged_in = 2;
  //  sram_controller1_plugged_in = 2 * !(ReadReg(JOYA) & 1);
  //  sram_controller2_plugged_in = 2 * (ReadReg(JOYB) & 1);
}

void Smbll_LoadSplashScreen() {
  uint8 i;  // si

  WriteReg(VMAIN, 0x80u);
  WriteRegWord(DMAP0, 0x1801u);
  WriteRegWord(VMADDL, 0);
  WriteRegWord(A1T0L, 0x9043u);
  WriteReg(A1B0, 8u);
  WriteRegWord(DAS0L, 0x1000u);
  WriteReg(MDMAEN, 1u);
  for (i = 30; (i & 0x80u) == 0; i -= 2)
    palette_mirror[(i >> 1) + 240] = kLoadSplashScreen_SplashScreenPalette[i >> 1];
  coldata1_mirror = 32;
  coldata2_mirror = 64;
  coldata3_mirror = 0x80;
  WriteReg(TM, 0x10u);
  tm_mirror = 16;
  WriteReg(OBSEL, 0);
  inidisp_mirror = 0;
  WriteReg(INIDISP, 0);
  splash_screen_display_mario_coin_shine_flag = 0;
  splash_screen_palette_animation_index = 0;
  ++update_entire_palette_flag;
  player_state = 0;
  splash_screen_display_timer = -127;
  WriteReg(NMITIMEN, 0x81u);
  do
    Smbll_LoadSplashScreen_FadeIn();
  while (inidisp_mirror != 15);
  do {
    if (splash_screen_display_timer == 97) {
      WriteReg(APUI03, 1u);
      splash_screen_display_mario_coin_shine_flag = 1;
      splash_screen_palette_animation_timer = 2;
      splash_screen_palette_animation_index = 0;
    }
    Smbll_SplashScreenGFXRt_Main();
    if (splash_screen_display_mario_coin_shine_flag)
      Smbll_HandleSplashScreenMarioCoinShine_Main();
    Smbll_LoadSplashScreen_WaitForVBlank();
    --splash_screen_display_timer;
  } while (splash_screen_display_timer);
  do
    Smbll_LoadSplashScreen_FadeOut();
  while (inidisp_mirror);
  inidisp_mirror = 0x80;
  WriteReg(NMITIMEN, 0);
}

void Smbll_LoadSplashScreen_FadeIn() {
  ++inidisp_mirror;
  Smbll_sub_88AD8();
}

void Smbll_LoadSplashScreen_FadeOut() {
  --inidisp_mirror;
  Smbll_sub_88AD8();
}

void Smbll_sub_88AD8() {
  splash_screen_palette_animation_timer = 0;
  Smbll_SplashScreenGFXRt_Main();
  Smbll_LoadSplashScreen_WaitForVBlank();
}

void Smbll_LoadSplashScreen_WaitForVBlank() {
  wait_for_vblank = 0;
  while (!wait_for_vblank)
    ;
}

void Smbll_SplashScreenGFXRt_Main() {
  uint8 v0;     // di
  uint8 v1;     // si
  OamEnt *oam;  // rbp

  v0 = 0;
  v1 = 0;
  R0_ = 80;
  do {
    R1_ = 96;
    do {
      oam = get_OamEnt(oam_buf, v0);
      oam->xpos = R1_;
      oam->ypos = R0_;
      oam->charnum = kSplashScreenGFXRt_Tiles[v1++];
      oam->flags = 46;
      oam_tile_size_buffer[v0] = 2;
      v0 += 4;
      R1_ += 16;
    } while (R1_ < 0xA0u);
    R0_ += 16;
  } while (R0_ < 0xA0u);
  Smbll_CompressOAMTileSizeBuffer();
}

void Smbll_HandleSplashScreenMarioCoinShine_Main() {
  uint8 v0;  // di
  uint8 i;   // si

  R0_ = 2 * splash_screen_palette_animation_index;
  v0 = 6 * splash_screen_palette_animation_index;
  for (i = 0; i < 6u; ++i) {
    *((uint8 *)&palette_mirror[246] + i) = kHandleSplashScreenMarioCoinShine_DATA_009E75[v0];
    *((uint8 *)&palette_mirror[253] + i) = kHandleSplashScreenMarioCoinShine_DATA_009E8D[v0++];
  }
  ++update_entire_palette_flag;
  if (!--splash_screen_palette_animation_timer) {
    if (++splash_screen_palette_animation_index < 4u) {
      splash_screen_palette_animation_timer = 2;
    } else {
      splash_screen_palette_animation_index = 0;
      splash_screen_palette_animation_timer = 0;
      splash_screen_display_mario_coin_shine_flag = 0;
    }
  }
}

void Smbll_LoadFileSelectMenu_Main() {
  R6_ = 0;
  Smbll_LoadFileSelectMenu_Sub();
  title_screen_file_aselected_world = splash_screen_display_timer;
  title_screen_file_bselected_world = splash_screen_palette_animation_timer;
  title_screen_file_cselected_world = splash_screen_palette_animation_index;
}

void Smbll_LoadFileSelectMenu_Entry2() {
  R6_ = 1;
  Smbll_LoadFileSelectMenu_Sub();
}

void Smbll_LoadFileSelectMenu_Sub() {
  uint16 v0;                                // si
  uint16 v1;                                // di
  uint16 FileSelectMenu_BufferStripeImage;  // si
  int v3;                                   // rbx
  unsigned int v4;                          // edx
  uint16 v5;                                // ax
  uint16 v6;                                // ax
  uint16 v7;                                // di
  uint16 v8;                                // di
  uint16 v9;                                // si
  int16 v11;                                // [rsp+43h] [rbp-5h]

  v0 = *(uint16 *)vram_buffer1;
  v1 = 0;
  do {
    *(uint16 *)&R2_ = v1;
    FileSelectMenu_BufferStripeImage = Smbll_LoadFileSelectMenu_BufferStripeImage(v0, kLoadFileSelectMenu_FileSelectTextPtrs[v1 >> 1]);
    v3 = *(uint16 *)&R2_ >> 1;
    v4 = kSaveFileLocations_Main[v3];
    *(uint16 *)&R0_ = *(&g_byte_700011 + kSaveFileLocations_Main[v3]);
    v11 = *(uint16 *)(&g_byte_700010 + v4);
    *(uint16 *)&R4_ = *(uint16 *)&R0_ + 4 * (uint8)v11;
    if (v11 == -1)
      v5 = -29702;
    else
      v5 = -29681;
    v0 = Smbll_LoadFileSelectMenu_BufferStripeImage(FileSelectMenu_BufferStripeImage, v5);
    HIBYTE(v6) = 0;
    v7 = R2_ >> 1;
    if ((R4_ & 0x80u) != 0) {
      *(&splash_screen_display_timer + (R2_ >> 1)) = 0;
    } else {
      if (R6_) {
        LOBYTE(v6) = *(&title_screen_file_aselected_world + (R2_ >> 1));
      } else {
        LOBYTE(v6) = R4_;
        *(&splash_screen_display_timer + (R2_ >> 1)) = R4_;
        *(&title_screen_file_aselected_world + v7) = v6;
      }
      LOBYTE(v6) = (uint8)(v6 & 0xFC) >> 1;
      DUMMY_byte_7E16F4[v0 + 8] = *((uint8 *)kLoadFileSelectMenu_WorldNumberTiles + v6);
      DUMMY_byte_7E16F4[v0 + 9] = *((uint8 *)kLoadFileSelectMenu_WorldNumberTiles + v6 + 1);
      LOBYTE(v6) = 2 * (*(&title_screen_file_aselected_world + v7) & 3);
      vram_buffer1[v0] = *((uint8 *)kLoadFileSelectMenu_WorldNumberTiles + v6);
      vram_buffer1[v0 + 1] = *((uint8 *)kLoadFileSelectMenu_WorldNumberTiles + v6 + 1);
    }
    v1 = *(uint16 *)&R2_ + 2;
  } while (*(uint16 *)&R2_ != 4);
  v8 = -29660;
  if (title_screen_erase_file_process)
    v8 = -29633;
  v9 = Smbll_LoadFileSelectMenu_BufferStripeImage(v0, v8);
  vram_buffer1[v9 + 2] = 0xff;
  *(uint16 *)vram_buffer1 = v9;
}

uint16 Smbll_LoadFileSelectMenu_BufferStripeImage(uint16 k, uint16 a) {
  uint16 i;  // di
  uint8 v3;  // al

  *(uint16 *)&R0_ = a;
  for (i = 0;; ++i) {
    v3 = RomPtr_08(*(uint16 *)&R0_)[i];
    if (v3 == 0xFF)
      break;
    vram_buffer1[k++ + 2] = v3;
  }
  return k;
}

void Smbll_LoadPlayerSelectMenu_Main() {
  R6_ = 0;
  Smbll_LoadPlayerSelectMenu_Sub();
}

void Smbll_LoadPlayerSelectMenu_Entry2() {
  R6_ = 1;
  Smbll_LoadPlayerSelectMenu_Sub();
}

void Smbll_LoadPlayerSelectMenu_Sub() {
  uint16 v0;                                // si
  uint16 v1;                                // di
  uint16 i;                                 // di
  int16 v3;                                 // ax
  int8 v4;                                  // cf
  uint8 v5;                                 // al
  uint16 v6;                                // di
  uint16 FileSelectMenu_BufferStripeImage;  // si
  uint16 v9;                                // si

  R4_ = kLoadPlayerSelectMenu_ShowLineFlags[0];
  if (!R6_)
    number_of_players = kLoadPlayerSelectMenu_NewCursorPos[0];
  v0 = *(uint16 *)vram_buffer1;
  v1 = 0;
  do {
    *(uint16 *)&R2_ = v1;
    *(uint16 *)&R0_ = kLoadPlayerSelectMenu_PlayerSelectTextPtrs[v1 >> 1];
    for (i = 0; i != 4; i += 2) {
      v3 = *(uint16 *)&RomPtr_08(*(uint16 *)&R0_)[i];
      *(uint16 *)&vram_buffer1[v0 + 2] = v3;
      v0 += 2;
    }
    v4 = R4_ & 1;
    *(uint16 *)&R4_ >>= 1;
    if (!v4) {
      i = 0;
      HIBYTE(v3) = -115;
      *(uint16 *)&R0_ = -29311;
    }
    while (1) {
      v5 = RomPtr_08(*(uint16 *)&R0_)[i];
      if (v5 == 0xFF)
        break;
      vram_buffer1[v0++ + 2] = v5;
      ++i;
    }
    v1 = *(uint16 *)&R2_ + 2;
  } while (*(uint16 *)&R2_ != 2);
  v6 = -29274;
  if (sram_controller_type_x)
    v6 = -29233;
  FileSelectMenu_BufferStripeImage = Smbll_LoadFileSelectMenu_BufferStripeImage(v0, v6);
  vram_buffer1[FileSelectMenu_BufferStripeImage + 2] = 0xff;
  v9 = Smbll_LoadFileSelectMenu_BufferStripeImage(FileSelectMenu_BufferStripeImage, 0x8DF8u);
  vram_buffer1[v9 + 2] = 0xff;
  if (displayed_score[0])
    DUMMY_byte_7E16F4[v9] = displayed_score[0];
  DUMMY_byte_7E16F4[v9 + 2] = displayed_score[1];
  DUMMY_byte_7E16F4[v9 + 4] = displayed_score[2];
  DUMMY_byte_7E16F4[v9 + 6] = displayed_score[3];
  DUMMY_byte_7E16F4[v9 + 8] = displayed_score[4];
  DUMMY_byte_7E16F4[v9 + 10] = displayed_score[5];
  vram_buffer1[0] = v9;
}

void Smbll_ChangeSelectedWorld_Main(uint8 a) {
  uint8 v1;  // di
  int8 v2;   // al
  uint8 v3;  // al

  if (*(&splash_screen_display_timer + number_of_players)) {
    v1 = number_of_players;
    R2_ = *(&g_byte_700014 + *((uint8 *)kSaveFileLocations_Main + (uint8)(2 * number_of_players)));
    R0_ = *(&splash_screen_display_timer + number_of_players) + 1;
    while (1) {
      v2 = (a & 3) != 0 ? kChangeSelectedWorld_Main_AdditionTable[(uint8)((a & 3) - 1)] : 1;
      v3 = *(&title_screen_file_aselected_world + v1) + v2;
      if (v3 == 0xFF) {
        v3 = *(&splash_screen_display_timer + v1);
      } else if (v3 >= R0_) {
        v3 = 0;
      }
      *(&title_screen_file_aselected_world + v1) = v3;
      if (v3 < 0x20u || v3 >= 0x24u || !R2_)
        break;
      a = controller_press2p1 | controller_press1p1;
    }
    sound_ch3 = 76;
    Smbll_LoadFileSelectMenu_Entry2();
  } else {
    sound_ch3 = 42;
  }
}

void Smbll_LoadSaveFileData_Main() {
  uint16 v0;  // di
  uint16 v1;  // si

  *(uint16 *)&R4_ = 6;
  g_sram[0xe] = number_of_players;
  v0 = kSaveFileLocations_Main[(uint8)(2 * number_of_players) >> 1];
  g_sram[0x4] = v0;
  v1 = 0;
  do
    *(&save_buffer + v1++) = *(&g_byte_700010 + v0++);
  while (v1 != *(uint16 *)&R4_);
  original_level = sram_initial_selected_level;
  level_number = sram_initial_selected_level;
  g_byte_7FFB01 = sram_initial_selected_level;
  world_number = sram_world_number;
  save_buffer = sram_world_number;
  sram_initial_selected_level = kbyte_2E06D[(uint8)(sram_initial_selected_level + 4 * sram_world_number)];
  save_buffer_area_number_original = sram_initial_selected_level;
  other_player_num_lives = sram_initial_selected_level;
}

void Smbll_VerifySaveDataIsValid() {
  uint16 IsValid_CODE_008D41;  // si
  uint16 v1;                   // si
  int16 v2;                    // di
  int8 v3;                     // al
  bool v4;                     // cf

  while (1) {
    debug_flag = 0;
    sram_controller_type_x = 0;
    if (g_word_700002 == 0x9743 && g_word_701FFC == 21281)
      break;
    *(uint16 *)&R0_ = 0x2000;
    Smbll_InitializeSelectedRAM(0x70u, 0);
    IsValid_CODE_008D41 = 0;
    do {
      IsValid_CODE_008D41 = Smbll_VerifySaveDataIsValid_CODE_008D41(IsValid_CODE_008D41);
      ++g_word_700004;
    } while (g_word_700004 < 3u);
    g_word_700002 = -26813;
    g_word_701FFC = 21281;
  }
  g_word_700004 = 0;
  v1 = 0;
  do {
    v2 = 6;
    *(uint16 *)&R0_ = 0;
    *(uint16 *)&R2_ = v1;
    do {
      v3 = *(&g_byte_700010 + v1);
      v4 = __CFADD__(R0_, v3);
      R0_ += v3;
      R1_ += v4;
      ++v1;
      --v2;
    } while (v2);
    if ((uint16)(*(uint16 *)(&g_byte_700010 + v1) + *(uint16 *)&R0_)) {
      v1 = Smbll_VerifySaveDataIsValid_CODE_008D41(*(uint16 *)&R2_);
      *(uint16 *)&R2_ = v1;
    } else {
      v1 += 2;
    }
    ++g_word_700004;
  } while (g_word_700004 < 3u);
}

uint16 Smbll_VerifySaveDataIsValid_CODE_008D41(uint16 k) {
  uint16 v1;  // di
  uint8 v2;   // al
  bool v3;    // cf

  *(uint16 *)&R4_ = 6;
  v1 = 0;
  *(uint16 *)&R0_ = 0;
  do {
    do {
      v2 = kVerifySaveDataIsValid_PremadeSaveFileData[v1];
      *(&g_byte_700010 + k) = v2;
      v3 = __CFADD__(R0_, v2);
      R0_ += v2;
      R1_ += v3;
      ++k;
      ++v1;
      --R4_;
    } while (R4_);
    --R5_;
  } while ((R5_ & 0x80u) == 0);
  *(uint16 *)(&g_byte_700010 + k) = -*(uint16 *)&R0_;
  return k + 2;
}

void Smbll_ClearSaveData_Main() {
  uint16 v0;  // ax
  uint16 v1;  // di

  v1 = number_of_players;
  v0 = 2 * number_of_players;
  *(&title_screen_file_aselected_world + v1) = 0;
  *(&splash_screen_display_timer + v1) = 0;
  *(uint16 *)(&g_byte_700010 + kSaveFileLocations_Main[v0 >> 1]) = -1;
  Smbll_VerifySaveDataIsValid();
}

void Smbll_MoveTitleScreenMenuCursor_Main(uint8 a) {
  uint8 v1;  // al
  uint8 v2;  // al

  R0_ = 0;
  R1_ = a;
  if ((a & 0xC) != 0)
    v1 = kMoveTitleScreenMenuCursor_AdditionTable[(uint8)(a & 0xC) >> 3];
  else
    v1 = 1;
  v2 = number_of_players + v1;
  if (v2 == 0xFF) {
    v2 = *((uint8 *)&kMoveTitleScreenMenuCursor_NumberOfMenuItems + splash_screen_display_mario_coin_shine_flag) - 1;
  } else if (v2 >= *((uint8 *)&kMoveTitleScreenMenuCursor_NumberOfMenuItems + splash_screen_display_mario_coin_shine_flag)) {
    v2 = 0;
  }
  number_of_players = v2;
  sound_ch3 = 1;
}
