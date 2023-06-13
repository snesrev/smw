#include "smb1_consts.h"
#include "smb1_funcs.h"
#include "smb1_rtl.h"
#include "smb1_variables.h"
void UploadSpuData() {
  WriteReg(NMITIMEN, 0);
  WriteReg(HDMAEN, 0);
  WriteReg(APUI01, 0xFFu);
  R0_ = 0x46;
  R1_ = 0xa1;
  R2_ = 8;
  HandleSPCUploads_Main();
}

void UploadSPCEngine() {
  R0_ = 0;
  R1_ = 0xd0;
  R2_ = 9;
  HandleSPCUploads_Main();
}

void UploadMainSampleData() {
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
  HandleSPCUploads_Main();
}

void HandleSPCUploads_Main() {
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
    v9 = IndirPtr(&R0_, v0);
    v10 = v0 + 2;
    v4 = *(uint16 *)v9;
    v11 = *(uint16 *)IndirPtr(&R0_, v10);
    v12 = v10 + 2;
    WriteRegWord(APUI02, v11);
    WriteReg(APUI01, v4 != 0);
    WriteReg(APUI00, v13);
    while (v13 != ReadReg(APUI00))
      ;
    if (Unreachable())
      break;
    v2 = IndirPtr(&R0_, v12);
    v0 = v12 + 1;
    HIBYTE(v1) = *v2;
    for (LOBYTE(v1) = 0;; LOBYTE(v1) = v1 + 1) {
      WriteRegWord(APUI00, v1);
      if (!--v4)
        break;
      v3 = IndirPtr(&R0_, v0++);
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

void SaveGame_Main() {
  uint8 v0;        // al
  uint16 v1;       // si
  uint16 v2;       // si
  uint8 v3;        // al
  uint8 v4;        // al
  uint16 v5;       // si
  uint16 updated;  // si
  uint16 v7;       // si
  uint8 v8;        // di
  int8 v9;         // al
  uint16 v10;      // si
  uint16 v11;      // ax
  int8 v12;        // al
  uint16 v13;      // si
  uint16 v14;      // si
  uint16 v15;      // si
  uint16 v16;      // si
  uint8 v17;       // di
  int8 v18;        // al
  uint16 v19;      // si
  uint16 v20;      // ax
  int8 v21;        // al
  uint16 v22;      // si
  uint16 k;        // [rsp+43h] [rbp-5h]
  uint16 ka;       // [rsp+43h] [rbp-5h]

  if (!sram_hard_mode_flag) {
    *(uint16 *)&R0_ = 0;
    if (number_of_players) {
      if (player_hard_mode_flag == other_player_hard_mode) {
        if (world_number < offscreen_players_world)
          goto LABEL_13;
      } else if (player_hard_mode_flag != 1) {
LABEL_13:
        R2_ = other_player_hard_mode;
        if (other_player_hard_mode == *(&g_byte_700015 + g_word_700004)) {
          v4 = *(&g_byte_700010 + g_word_700004);
          if ((v4 & 0x80u) == 0 && v4 >= offscreen_players_world)
            goto LABEL_18;
        } else if (other_player_hard_mode != 1) {
          goto LABEL_18;
        }
        updated = StoreToSramAndUpdateChecksum(g_word_700004, offscreen_players_world);
        v2 = StoreToSramAndUpdateChecksum(updated, player_other_players_level_number_display);
        v3 = player_other_players_level;
        goto LABEL_20;
      }
    }
    R2_ = player_hard_mode_flag;
    if (player_hard_mode_flag == *(&g_byte_700015 + g_word_700004)) {
      v0 = *(&g_byte_700010 + g_word_700004);
      if ((v0 & 0x80u) == 0 && v0 >= world_number)
        goto LABEL_18;
    } else if (player_hard_mode_flag != 1) {
LABEL_18:
      v5 = StoreToSramAndUpdateChecksum(g_word_700004, *(&g_byte_700010 + g_word_700004));
      v2 = StoreToSramAndUpdateChecksum(v5, *(&g_byte_700010 + v5));
      v3 = *(&g_byte_700010 + v2);
      goto LABEL_20;
    }
    v1 = StoreToSramAndUpdateChecksum(g_word_700004, world_number);
    v2 = StoreToSramAndUpdateChecksum(v1, 0);
    v3 = 0;
LABEL_20:
    v7 = StoreToSramAndUpdateChecksum(v2, v3);
    R4_ = number_of_lives;
    R5_ = other_player_num_lives;
    v8 = current_player;
    v9 = *(&R4_ + current_player);
    if (v9 < 0)
      v9 = 4;
    v10 = StoreToSramAndUpdateChecksum(v7, v9);
    v11 = v8 ^ 1;
    v12 = *(&R4_ + v11);
    if (v12 < 0)
      v12 = 4;
    k = StoreToSramAndUpdateChecksum(v10, v12);
    SaveGame_CODE_009041();
    v13 = StoreToSramAndUpdateChecksum(k, R2_ | *(&g_byte_700010 + k));
    *(uint16 *)(&g_byte_700010 + StoreToSramAndUpdateChecksum(v13, number_of_players)) = -*(uint16 *)&R0_;
    RtlWriteSram();
    return;
  }
  *(uint16 *)&R0_ = 0;
  v14 = StoreToSramAndUpdateChecksum(g_word_700004, sram_world_number2);
  v15 = StoreToSramAndUpdateChecksum(v14, 0);
  v16 = StoreToSramAndUpdateChecksum(v15, 0);
  R4_ = number_of_lives;
  R5_ = other_player_num_lives;
  v17 = current_player;
  v18 = *(&R4_ + current_player);
  if (v18 < 0)
    v18 = 4;
  v19 = StoreToSramAndUpdateChecksum(v16, v18);
  v20 = v17 ^ 1;
  v21 = *(&R4_ + v20);
  if (v21 < 0)
    v21 = 4;
  ka = StoreToSramAndUpdateChecksum(v19, v21);
  SaveGame_CODE_009041();
  v22 = StoreToSramAndUpdateChecksum(ka, sram_hard_mode_flag);
  uint16 tt = StoreToSramAndUpdateChecksum(v22, number_of_players);
  *(uint16 *)(&g_byte_700010 + tt) = -*(uint16 *)&R0_;
  sram_hard_mode_flag = 0;
  sram_world_number2 = 0;

  RtlWriteSram();
}

void SaveGame_CODE_009041() {
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

uint16 StoreToSramAndUpdateChecksum(uint16 k, uint8 a) {
  uint16 result;  // si
  bool v3;        // cf

  *(&g_byte_700010 + k) = a;
  result = k + 1;
  v3 = __CFADD__(R0_, a);
  R0_ += a;
  R1_ += v3;
  return result;
}

void ResetGame_Main() {
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

  g_smb1_want_reset = true;
}

void InitializeSelectedRAM(uint8 j, uint16 a) {
  *(uint16 *)&R2_ = 0;
  InitializeSelectedRAM_Entry2(j, a);
}

void InitializeSelectedRAM_Entry2(uint8 j, uint16 a) {
  WriteRegWord(A1T0L, a);
  WriteReg(A1B0, j);
  WriteRegWord(DMAP0, 0x3480u);
  WriteRegWord(DAS0L, *(uint16 *)&R0_);
  WriteReg(M7A, 1u);
  WriteReg(M7A, 0);
  WriteReg(M7B, R2_);
  WriteReg(MDMAEN, 1u);
}

void InitializeRAMOnStartup() {
  *(uint16 *)&R0_ = 336;
  InitializeSelectedRAM(0, 0);
  *(uint16 *)&R0_ = 7680;
  InitializeSelectedRAM(0, 0x200u);
  *(uint16 *)&R0_ = -8192;
  InitializeSelectedRAM(0x7Eu, 0x2000u);
  *(uint16 *)&R0_ = 0;
  InitializeSelectedRAM(0x7Fu, 0);
  *(uint16 *)&vram_buffer1_offset = 0;
  *(uint16 *)&vram_buffer1[1] = -1;
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

void CheckWhichControllersArePluggedIn_Main() {
  sram_controller1_plugged_in = 0;
  sram_controller2_plugged_in = 2;

  // sram_controller1_plugged_in = 2 * !(ReadReg(JOYA) & 1);
  // sram_controller2_plugged_in = 2 * (ReadReg(JOYB) & 1);
}

void LoadSplashScreen() {
  uint8 i;  // si

  WriteReg(VMAIN, 0x80u);
  WriteRegWord(DMAP0, 0x1801u);
  WriteRegWord(VMADDL, 0);
  WriteRegWord(A1T0L, 0x9146u);
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
  do {
    ++inidisp_mirror;
    func_sub_88AD8();
    LoadSplashScreen_WaitForVBlank();
  } while (inidisp_mirror != 15);
  do {
    if (splash_screen_display_timer == 97) {
      WriteReg(APUI03, 1u);
      splash_screen_display_mario_coin_shine_flag = 1;
      splash_screen_palette_animation_timer = 2;
      splash_screen_palette_animation_index = 0;
    }
    SplashScreenGFXRt_Main();
    if (splash_screen_display_mario_coin_shine_flag)
      HandleSplashScreenMarioCoinShine_Main();
    LoadSplashScreen_WaitForVBlank();
    --splash_screen_display_timer;
  } while (splash_screen_display_timer);
  do {
    --inidisp_mirror;
    func_sub_88AD8();
    LoadSplashScreen_WaitForVBlank();
  } while (inidisp_mirror);
  inidisp_mirror = 0x80;
  WriteReg(NMITIMEN, 0);
}

void func_sub_88AD8() {
  splash_screen_palette_animation_timer = 0;
  SplashScreenGFXRt_Main();
}

void LoadSplashScreen_WaitForVBlank() {
  wait_for_vblank = 0;
  while (!wait_for_vblank)
    ;
}

void SplashScreenGFXRt_Main() {
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
  CompressOAMTileSizeBuffer();
}

void HandleSplashScreenMarioCoinShine_Main() {
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

void LoadFileSelectMenu_Main() {
  R6_ = 0;
  LoadFileSelectMenu_Sub();
  title_screen_file_aselected_world = splash_screen_display_timer;
  title_screen_file_bselected_world = splash_screen_palette_animation_timer;
  title_screen_file_cselected_world = splash_screen_palette_animation_index;
}

void LoadFileSelectMenu_Entry2() {
  R6_ = 1;
  LoadFileSelectMenu_Sub();
}

void LoadFileSelectMenu_Sub() {
  uint16 v0;                                // si
  uint16 v1;                                // di
  uint16 FileSelectMenu_BufferStripeImage;  // si
  int v3;                                   // rbx
  unsigned int v4;                          // edx
  uint16 v5;                                // ax
  uint16 v6;                                // ax
  uint16 v7;                                // di
  uint8 v8;                                 // al
  uint16 v9;                                // di
  uint16 v10;                               // si
  int16 v12;                                // [rsp+43h] [rbp-5h]

  v0 = *(uint16 *)&vram_buffer1_offset;
  v1 = 0;
  do {
    *(uint16 *)&R2_ = v1;
    FileSelectMenu_BufferStripeImage = LoadFileSelectMenu_BufferStripeImage(v0, kLoadFileSelectMenu_FileSelectTextPtrs[v1 >> 1]);
    v3 = *(uint16 *)&R2_ >> 1;
    v4 = kSaveFileLocations_Main[v3];
    v12 = *(uint16 *)(&g_byte_700010 + kSaveFileLocations_Main[v3]);
    *(uint16 *)&R0_ = (uint8)v12;
    *(uint16 *)&R4_ = (uint8)v12 + 8 * *(&g_byte_700015 + v4);
    if (v12 == -1)
      v5 = -29450;
    else
      v5 = -29429;
    v0 = LoadFileSelectMenu_BufferStripeImage(FileSelectMenu_BufferStripeImage, v5);
    HIBYTE(v6) = 0;
    v7 = R2_ >> 1;
    if ((R4_ & 0x80u) != 0) {
      *(&splash_screen_display_timer + (R2_ >> 1)) = 0;
    } else {
      if (R6_) {
        LOBYTE(v6) = *(&title_screen_file_aselected_world + (R2_ >> 1)) & 7;
      } else {
        v8 = R4_;
        *(&splash_screen_display_timer + (R2_ >> 1)) = R4_;
        *(&title_screen_file_aselected_world + v7) = v8;
        LOBYTE(v6) = v8 & 7;
      }
      LOBYTE(v6) = 2 * v6;
      vram_buffer1[v0 + 7 - 12] = *((uint8 *)kLoadFileSelectMenu_WorldNumberTiles + v6);
      vram_buffer1[v0 + 8 - 12] = *((uint8 *)kLoadFileSelectMenu_WorldNumberTiles + v6 + 1);
      if (*(&title_screen_file_aselected_world + v7) >= 8u) {
        vram_buffer1[v0 + 5 - 12] = -2;
        vram_buffer1[v0 + 6 - 12] = 8;
      }
    }
    v1 = *(uint16 *)&R2_ + 2;
  } while (*(uint16 *)&R2_ != 4);
  v9 = -29408;
  if (title_screen_erase_file_process)
    v9 = -29381;
  v10 = LoadFileSelectMenu_BufferStripeImage(v0, v9);
  vram_buffer1[v10 + 1] = 0xff;
  *(uint16 *)&vram_buffer1_offset = v10;
}
// 7E16F6: using guessed type uint8 byte_7E16F6[10];

uint16 LoadFileSelectMenu_BufferStripeImage(uint16 k, uint16 a) {
  uint16 i;  // di
  uint8 v3;  // al

  *(uint16 *)&R0_ = a;
  for (i = 0;; ++i) {
    v3 = RomPtr_08(*(uint16 *)&R0_)[i];
    if (v3 == 0xFF)
      break;
    vram_buffer1[++k] = v3;
  }
  return k;
}

void LoadPlayerSelectMenu_Main() {
  R6_ = 0;
  LoadPlayerSelectMenu_Sub();
}

void LoadPlayerSelectMenu_Entry2() {
  R6_ = 1;
  LoadPlayerSelectMenu_Sub();
}

void LoadPlayerSelectMenu_Sub() {
  uint16 v0;                                // ax
  uint16 v1;                                // si
  uint16 v2;                                // di
  uint16 i;                                 // di
  int16 v4;                                 // ax
  int8 v5;                                  // cf
  uint8 v6;                                 // al
  uint16 v7;                                // di
  uint16 FileSelectMenu_BufferStripeImage;  // si
  uint16 v10;                               // si

  v0 = (uint8)(save_buffer_2_player_flag + 1);
  R4_ = kLoadPlayerSelectMenu_ShowLineFlags[v0];
  if (!R6_)
    number_of_players = kLoadPlayerSelectMenu_NewCursorPos[v0];
  v1 = *(uint16 *)&vram_buffer1_offset;
  v2 = 0;
  do {
    *(uint16 *)&R2_ = v2;
    *(uint16 *)&R0_ = kLoadPlayerSelectMenu_PlayerSelectTextPtrs[v2 >> 1];
    for (i = 0; i != 4; i += 2) {
      v4 = *(uint16 *)&RomPtr_08(*(uint16 *)&R0_)[i];
      *(uint16 *)&vram_buffer1[v1 + 1] = v4;
      v1 += 2;
    }
    v5 = R4_ & 1;
    *(uint16 *)&R4_ >>= 1;
    if (!v5) {
      i = 0;
      HIBYTE(v4) = -114;
      *(uint16 *)&R0_ = -29055;
    }
    while (1) {
      v6 = RomPtr_08(*(uint16 *)&R0_)[i];
      if (v6 == 0xFF)
        break;
      vram_buffer1[++v1] = v6;
      ++i;
    }
    v2 = *(uint16 *)&R2_ + 2;
  } while (*(uint16 *)&R2_ != 2);
  v7 = -29018;
  if (sram_controller_type_x)
    v7 = -28977;
  FileSelectMenu_BufferStripeImage = LoadFileSelectMenu_BufferStripeImage(v1, v7);
  vram_buffer1[FileSelectMenu_BufferStripeImage + 1] = 0xff;
  v10 = LoadFileSelectMenu_BufferStripeImage(FileSelectMenu_BufferStripeImage, 0x8EF8u);
  vram_buffer1[v10 + 1] = 0xff;
  if (displayed_score[0])
    vram_buffer1[v10 + -1 - 12] = displayed_score[0];
  vram_buffer1[v10 + 1 - 12] = displayed_score[1];
  vram_buffer1[v10 + 3 - 12] = displayed_score[2];
  vram_buffer1[v10 + 5 - 12] = displayed_score[3];
  vram_buffer1[v10 + 7 - 12] = displayed_score[4];
  vram_buffer1[v10 + 9 - 12] = displayed_score[5];
  vram_buffer1_offset = v10;
}
// 7E16F4: using guessed type uint8[2];
// 7E16F6: using guessed type uint8 byte_7E16F6[10];

void ChangeSelectedWorld_Main(uint8 a) {
  uint8 v1;  // al
  uint8 v2;  // al

  if (*(&splash_screen_display_timer + number_of_players)) {
    R0_ = *(&splash_screen_display_timer + number_of_players) + 1;
    if ((a & 3) != 0)
      v1 = kChangeSelectedWorld_Main_AdditionTable[(uint8)((a & 3) - 1)];
    else
      v1 = 1;
    v2 = *(&title_screen_file_aselected_world + number_of_players) + v1;
    if (v2 == 0xFF) {
      v2 = *(&splash_screen_display_timer + number_of_players);
    } else if (v2 >= R0_) {
      v2 = 0;
    }
    *(&title_screen_file_aselected_world + number_of_players) = v2;
    sound_ch3 = 76;
    LoadFileSelectMenu_Entry2();
  } else {
    sound_ch3 = 42;
  }
}

void LoadSaveFileData_Main() {
  uint16 v0;  // di
  uint16 v1;  // si

  *(uint16 *)&R4_ = 7;
  g_sram[0xe] = number_of_players;
  v0 = kSaveFileLocations_Main[(uint8)(2 * number_of_players) >> 1];
  g_sram[0x4] = v0;
  v1 = 0;
  do
    *(&save_buffer + v1++) = *(&g_byte_700010 + v0++);
  while (v1 != *(uint16 *)&R4_);
  original_level = sram_initial_selected_level;
  save_buffer_current_level = sram_initial_selected_level;
  world_number = sram_world_number & 7;
  save_buffer = sram_world_number & 7;
  sram_initial_selected_level = kUNK_05D272[(uint8)(sram_initial_selected_level + 4 * (sram_world_number & 7))];
  save_buffer_area_number_original = sram_initial_selected_level;
  area_number = sram_initial_selected_level;
  save_buffer_hard_mode_active_flag = sram_world_number >= 8u;
}

void VerifySaveDataIsValid() {
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
    InitializeSelectedRAM(0x70u, 0);
    IsValid_CODE_008D41 = 0;
    do {
      IsValid_CODE_008D41 = VerifySaveDataIsValid_CODE_008D41(IsValid_CODE_008D41);
      ++g_word_700004;
    } while (g_word_700004 < 3u);
    g_word_700002 = -26813;
    g_word_701FFC = 21281;
  }
  g_word_700004 = 0;
  v1 = 0;
  do {
    v2 = 7;
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
      v1 = VerifySaveDataIsValid_CODE_008D41(*(uint16 *)&R2_);
      *(uint16 *)&R2_ = v1;
    } else {
      v1 += 2;
    }
    ++g_word_700004;
  } while (g_word_700004 < 3u);
}

uint16 VerifySaveDataIsValid_CODE_008D41(uint16 k) {
  uint16 v1;  // di
  uint8 v2;   // al
  bool v3;    // cf

  *(uint16 *)&R4_ = 7;
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

void ClearSaveData_Main() {
  uint16 v0;  // ax
  uint16 v1;  // di

  v0 = number_of_players;
  v1 = v0;
  v0 = (uint8)(2 * number_of_players);
  *(&title_screen_file_aselected_world + v1) = 0;
  *(&splash_screen_display_timer + v1) = 0;
  *(uint16 *)(&g_byte_700010 + kSaveFileLocations_Main[v0 >> 1]) = -1;
  VerifySaveDataIsValid();
}

void MoveTitleScreenMenuCursor_Main(uint8 a) {
  int8 v1;   // al
  uint8 v2;  // al

  R0_ = 0;
  for (R1_ = a;; a = R1_) {
    v1 = (a & 0xC) != 0 ? kMoveTitleScreenMenuCursor_AdditionTable[(uint8)(a & 0xC) >> 3] : 1;
    v2 = number_of_players + v1;
    if (v2 == 0xFF) {
      v2 = *((uint8 *)&kMoveTitleScreenMenuCursor_NumberOfMenuItems + splash_screen_display_mario_coin_shine_flag) - 1;
    } else if (v2 >= *((uint8 *)&kMoveTitleScreenMenuCursor_NumberOfMenuItems + splash_screen_display_mario_coin_shine_flag)) {
      v2 = 0;
    }
    number_of_players = v2;
    if (R0_)
      break;
    if (!splash_screen_display_mario_coin_shine_flag)
      break;
    ++R0_;
    if ((save_buffer_2_player_flag & 0x80u) != 0 ||
        *((uint8 *)&kMoveTitleScreenMenuCursor_BlankSettingLoc + save_buffer_2_player_flag) != number_of_players) {
      break;
    }
  }
  sound_ch3 = 1;
}
