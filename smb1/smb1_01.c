#include "smb1_rtl.h"
#include "smb1_consts.h"
#include "smb1_funcs.h"
#include "smb1_variables.h"

void (*funcs_1948B[13])() = {
    &CutsceneToad_Func0, &CutsceneToad_Func1, &CutsceneToad_Func2,
    &CutsceneToad_Func3, &CutsceneToad_Func4, &CutsceneToad_Func5,
    &CutsceneToad_Func6, &CutsceneToad_Func0, &CutsceneToad_Func0,
    &CutsceneToad_Func4, &CutsceneToad_Func5, &CutsceneToad_Func6,
    &CutsceneToad_Func0};  // weak

void Dma_FillWith0x24() {
  R0_ = 36;
  WriteReg(VMAIN, 0);
  WriteRegWord(VMADDL, 0x800u);
  WriteRegWord(DMAP0, 0x1808u);
  WriteRegWord(A1T0L, 0);
  WriteRegWord(A1B0, 0);
  WriteRegWord(DAS0L, 0x400u);
  WriteReg(MDMAEN, 1u);
  WriteRegWord(DAS0L, 0x400u);
  WriteRegWord(VMADDL, 0x800u);
  *(uint16 *)&R0_ = 0;
  WriteReg(VMAIN, 0x80u);
  WriteReg(BBAD0, 0x19u);
  WriteReg(MDMAEN, 1u);
  R0_ = 36;
  WriteRegWord(VMAIN, 0);
  WriteRegWord(VMADDL, 0);
  WriteRegWord(DMAP0, 0x1808u);
  WriteRegWord(A1T0L, 0);
  WriteRegWord(A1B0, 0);
  WriteRegWord(DAS0L, 0x800u);
  WriteReg(MDMAEN, 1u);
  WriteRegWord(DAS0L, 0x800u);
  WriteRegWord(VMADDL, 0);
  *(uint16 *)&R0_ = 0;
  WriteReg(VMAIN, 0x80u);
  WriteReg(BBAD0, 0x19u);
  WriteReg(MDMAEN, 1u);
  R0_ = 40;
  WriteRegWord(VMAIN, 0);
  WriteRegWord(VMADDL, 0x5878u);
  WriteRegWord(DMAP0, 0x1808u);
  WriteRegWord(A1T0L, 0);
  WriteRegWord(A1B0, 0);
  WriteRegWord(DAS0L, 0x788u);
  WriteReg(MDMAEN, 1u);
  WriteRegWord(DAS0L, 0x788u);
  WriteRegWord(VMADDL, 0x5878u);
  *(uint16 *)&R0_ = 0;
  WriteReg(VMAIN, 0x80u);
  WriteReg(BBAD0, 0x19u);
  WriteReg(MDMAEN, 1u);
}

void Dma_FillWith0x28() {
  R0_ = 40;
  WriteReg(VMAIN, 0);
  WriteRegWord(VMADDL, 0x5800u);
  WriteRegWord(DMAP0, 0x1808u);
  WriteRegWord(A1T0L, 0);
  WriteRegWord(A1B0, 0);
  WriteRegWord(DAS0L, 0x200u);
  WriteReg(MDMAEN, 1u);
  WriteRegWord(DAS0L, 0x200u);
  WriteRegWord(VMADDL, 0x5800u);
  R0_ = 0;
  WriteReg(VMAIN, 0x80u);
  WriteReg(BBAD0, 0x19u);
  WriteReg(MDMAEN, 1u);
}

void Dma_CODE_0480EF() {
  R0_ = 39;
  WriteReg(VMAIN, 0);
  WriteRegWord(VMADDL, 0);
  WriteRegWord(DMAP0, 0x1808u);
  WriteRegWord(A1T0L, 0);
  WriteRegWord(A1B0, 0);
  WriteRegWord(DAS0L, 0x400u);
  WriteReg(MDMAEN, 1u);
  WriteRegWord(DAS0L, 0x400u);
  WriteRegWord(VMADDL, 0);
  R0_ = 12;
  WriteReg(VMAIN, 0x80u);
  WriteReg(BBAD0, 0x19u);
  WriteReg(UNUSED0, 1u);
  R0_ = 36;
  WriteRegWord(VMAIN, 0);
  WriteRegWord(VMADDL, 0x800u);
  WriteRegWord(A1T0L, 0);
  WriteRegWord(A1B0, 0);
  WriteRegWord(DAS0L, 0x400u);
  WriteReg(MDMAEN, 1u);
  WriteRegWord(DAS0L, 0x400u);
  WriteRegWord(VMADDL, 0x800u);
  R0_ = 0;
  WriteReg(VMAIN, 0x80u);
  WriteReg(BBAD0, 0x19u);
  WriteReg(MDMAEN, 1u);
}

void HandleSfx() {
  uint8 v0;  // al
  uint8 v1;  // al
  uint8 v2;  // al
  uint8 v3;  // al

  v0 = sound_ch1;
  if (sound_ch1) goto LABEL_5;
  if (ReadReg(APUI00) == apui00_last || (++apui00_delay, apui00_delay >= 3u)) {
    v0 = 0;
  LABEL_5:
    WriteReg(APUI00, v0);
    apui00_last = v0;
    apui00_delay = 0;
  }
  v1 = sound_ch2;
  if (sound_ch2) {
  LABEL_10:
    WriteReg(APUI01, v1);
    apui01_last = v1 & 0xF;
    apui01_delay = 0;
    goto LABEL_11;
  }
  if ((ReadReg(APUI01) & 0xF) == apui01_last ||
      (++apui01_delay, apui01_delay >= 3u)) {
    v1 = 0;
    goto LABEL_10;
  }
LABEL_11:
  v2 = music_ch1;
  if (music_ch1) {
    apui02_var160C = 4;
    WriteReg(APUI02, music_ch1);
    if (v2 < 0xF0u) apui02_var1606 = v2;
  } else if (ReadReg(APUI02) == apui02_var1606) {
    v3 = --apui02_var160C;
    if (!apui02_var160C) {
      ++apui02_var160C;
      WriteReg(APUI02, v3);
    }
  }
  if (!sound_ch3) {
    if ((ReadReg(APUI03) & 0x7F) == apui03_var1607 ||
        (++apui03_delay, apui03_delay >= 3u)) {
      WriteReg(APUI03, 0);
      apui03_var1607 = 0;
      apui03_delay = 0;
    }
    goto LABEL_23;
  }
  apui03_var1607 = sound_ch3;
  if (sound_ch3 == 1 || sound_ch3 == 5 || sound_ch3 == 6 || sound_ch3 == 74) {
    WriteReg(APUI03, apui03_upper_bit | sound_ch3);
    apui03_upper_bit ^= 0x80u;
    apui03_delay = 0;
  LABEL_23:
    sound_ch1 = 0;
    sound_ch2 = 0;
    music_ch1 = 0;
    sound_ch3 = 0;
    return;
  }
  WriteReg(APUI03, sound_ch3);
  sound_ch1 = 0;
  sound_ch2 = 0;
  music_ch1 = 0;
  sound_ch3 = 0;
}

void InitializeGradientHDMA(uint8 a) {
  uint8 v1;  // al
  uint8 v2;  // si
  uint8 v3;  // di
  uint8 v4;  // si
  uint8 v5;  // di

  WriteReg(HDMAEN, 0);
  hdmaenable_mirror = 0;
  tmw_mirror = 0;
  tsw_mirror = 0;
  w12sel_mirror = 0;
  w34sel_mirror = 0;
  wobjsel_mirror = 0;
  cgwsel_mirror = 0;
  cgadsub_mirror = 32;
  if (a != 0xFF) {
    R0_ = a;
    v1 = 2 * a;
    R1_ = kDATA_04824E[v1];
    v2 = kDATA_04823E[v1];
    v3 = 0;
    do {
      hdmagradient_red_channel_scanlines_and_ptrs_table[v3] = kDATA_0483AC[v2];
      hdmagradient_green_channel_scanlines_and_ptrs_table[v3] =
          kDATA_04840E[v2];
      hdmagradient_blue_channel_scanlines_and_ptrs_table[v3++] =
          kDATA_048470[v2++];
    } while (v3 != R1_);
    R1_ = kDATA_048256[v1];
    v4 = kDATA_048246[v1];
    v5 = 0;
    do {
      hdmagradient_red_channel_data[v5] = kDATA_0484D2[v4];
      hdmagradient_green_channel_data[v5] = kDATA_048512[v4];
      hdmagradient_blue_channel_data[v5++] = kDATA_048552[v4++];
    } while (v5 != R1_);
    WriteRegWord(DMAP5, 0x3240u);
    WriteRegWord(DMAP6, 0x3240u);
    WriteRegWord(DMAP7, 0x3240u);
    WriteRegWord(A1T5L, 0x1520u);
    WriteRegWord(A1T6L, 0x1560u);
    WriteRegWord(A1T7L, 0x15A0u);
    WriteReg(A1B5, 0);
    WriteReg(A1B6, 0);
    WriteReg(A1B7, 0);
    WriteReg(DAS50, 0);
    WriteReg(DAS60, 0);
    WriteReg(DAS70, 0);
    underwater_hdma_gradient_timer = 1;
    if (R0_ == 2) {
      WriteRegWord(DMAP4, 0x2841u);
      WriteRegWord(A1T4L, 0x83A5u);
      WriteReg(A1B4, 1u);
      WriteReg(DAS40, 1u);
      tmw_mirror = 23;
      tsw_mirror = 0;
      w12sel_mirror = 0;
      w34sel_mirror = 0;
      wobjsel_mirror = 0x80;
      cgwsel_mirror = 16;
      cgadsub_mirror = 51;
      hdmaenable_mirror = -16;
      palette_mirror[0] = 0;
      ++update_entire_palette_flag;
    } else {
      hdmaenable_mirror = -32;
    }
  }
}

void AdjustUnderwaterHDMAGradient() {
  uint8 v0;  // si
  uint8 v1;  // di
  uint8 v2;  // al

  if (!--underwater_hdma_gradient_timer) {
    v0 = underwater_hdma_gradient_index;
    underwater_hdma_gradient_timer =
        kDATA_048368[underwater_hdma_gradient_index];
    v1 = kDATA_048360[underwater_hdma_gradient_index];
    v2 = kDATA_048370[underwater_hdma_gradient_index] +
         hdmagradient_red_channel_scanlines_and_ptrs_table[v1];
    hdmagradient_red_channel_scanlines_and_ptrs_table[v1] = v2;
    hdmagradient_green_channel_scanlines_and_ptrs_table[v1] = v2;
    hdmagradient_blue_channel_scanlines_and_ptrs_table[v1] = v2;
    underwater_hdma_gradient_index = (v0 + 1) & 7;
  }
}

void GiveExtraLife() {
  if (++number_of_lives >= 0x80u) number_of_lives = 127;
}

void CODE_048600() {
  if ((cutscene_var1680 & 0x80u) == 0) {
    if (!cutscene_var1680) {
      if ((*(&controller_press1p1 + current_player) & 0x10) == 0) return;
      ++cutscene_var1680;
      sound_ch1 = 67;
    }
    LOBYTE(cutscene_hdma_varB9A) = cutscene_hdma_varB9A - 1;
    LOBYTE(cutscene_hdma_varB9A) = cutscene_hdma_varB9A - 1;
    if ((cutscene_hdma_varB9A & 0x80u) != 0) game_mode_task = 13;
  }
}

void CODE_04862A() {
  PauseMenu_Func6();
  CODE_05EBAB();
  w12sel_mirror = 34;
  w34sel_mirror = 2;
  ++game_mode_task;
}

void WaitForMusicAndChangeTask() {
  if (!ReadReg(APUI00)) {
    game_mode_task = 15;
    cutscene_var1680 = 0x80;
  }
}

uint8 RunGameOver_Sub() {
  uint8 i;       // di
  OamEnt *oam;   // rbx
  uint8 result;  // si
  uint8 v3;      // si
  int8 v4;       // di

  if ((*(&controller_press1p1 + current_player) & 0x2C) != 0) {
    sound_ch3 = 1;
    blinking_cursor_frame_counter = 0;
    game_over_screen_blinking_cursor_pos ^= 0x10u;
  }
  for (i = 3; (i & 0x80u) == 0; --i)
    get_OamEnt(oam_buf, i)->xpos = kGameOver_Xpos[i];
  oam = get_OamEnt(oam_buf, 0);
  oam->ypos += game_over_screen_blinking_cursor_pos;
  oam_tile_size_buffer[0] =
      ((uint8)(++blinking_cursor_frame_counter & 0x10) >> 4) | 2;
  result = 0;
  if ((*(&controller_press1p1 + current_player) & 0x10) != 0) {
    sound_ch3 = 41;
    halfway_page = 0;
    player_coin_count = 0;
    area_number = 0;
    level_number = 0;
    if (game_over_screen_blinking_cursor_pos) world_number = 0;
    v3 = kMult6[current_player];
    v4 = 6;
    do {
      score_and_coin_display[v3] = 0;
      marios_score[v3++] = 0;
      --v4;
    } while (v4);
    result = 2;
    if (!game_over_screen_blinking_cursor_pos) {
      number_of_lives = 4;
      ++hidden_1up_flag;
    }
  }
  return result;
}

// local variable allocation has failed, the output may be wrong!
void CODE_0486DF(uint8 jin) {
  uint16 j = jin;
  int16 v1;   // di
  uint16 v2;  // si
  int16 v3;   // ax

  v1 = j;
  v2 = 0;
  do {
    v3 = *(uint16 *)&kDATA_0486FD[v2];
    *(uint16 *)&vram_buffer1[j + 1] = v3;
    *(uint16 *)&j = j + 2;
    v2 += 2;
  } while (v3 != -1);
  *(uint16 *)&vram_buffer1_offset = j;
}
// 15605: variables would overlap: di.1 and di.2

void CutsceneHdma() {
  uint16 v0;  // si
  uint8 v1;   // di
  int8 v2;    // di
  int16 v3;   // ax
  uint16 v4;  // ax
  uint16 v5;  // ax

  if ((uint8)cutscene_hdma_varB9A < 0x30u) {
    cutscene_hdma_varB84 = 0;
    cutscene_hdma_varB8E = 0;
    cutscene_hdma_varB90 = 0;
    cutscene_hdma_varB92 = 0;
    cutscene_hdma_varB94 =
        kCircleHDMAData_DATA_00973E[(uint16)(2 * (uint8)cutscene_hdma_varB9A) >>
                                    1];
    cutscene_hdma_varB96 = 120;
    cutscene_hdma_varB98 = 176;
    while (1) {
      cutscene_hdma_varB80 = 256;
      cutscene_hdma_varB82 = 256;
      if ((uint16)(cutscene_hdma_varB90 + 1) < cutscene_hdma_varB9A) {
        cutscene_hdma_varB92 += cutscene_hdma_varB94;
        WriteReg(WRMPYA,
                 kCircleHDMAData_DATA_0096BD[cutscene_hdma_varB92 >> 9]);
        WriteReg(WRMPYB, cutscene_hdma_varB9A);
        cutscene_hdma_varB88 = ReadReg(RDMPYH);
        cutscene_hdma_varB82 = cutscene_hdma_varB98 + cutscene_hdma_varB88;
        cutscene_hdma_varB80 = cutscene_hdma_varB98 - cutscene_hdma_varB88;
      }
      cutscene_hdma_varB84 =
          2 * (cutscene_hdma_varB96 - cutscene_hdma_varB90 - 1);
      v0 = 2 * (cutscene_hdma_varB96 - cutscene_hdma_varB90 - 1);
      v1 = cutscene_hdma_varB80;
      if ((cutscene_hdma_varB80 & 0x8000u) != 0) break;
      if ((cutscene_hdma_varB80 & 0xFF00) != 0) {
        if ((cutscene_hdma_varB80 & 0xFF00) != 256) break;
        v1 = -1;
      }
    LABEL_10:
      cutscene_hdma_varB86 = v1;
      v2 = cutscene_hdma_varB82;
      if ((cutscene_hdma_varB82 & 0xFF00) != 0) v2 = -1;
      LOBYTE(v3) = 0;
      HIBYTE(v3) = v2;
      v4 = cutscene_hdma_varB86 | v3;
      cutscene_hdma_varB86 = v4;
      if (v0 < 0x1C0u) {
        if (v4 == 0xFFFF) v4 = 255;
        hdma_data_array[v0 >> 1] = v4;
      }
      cutscene_hdma_varB8E =
          2 * (cutscene_hdma_varB90 + cutscene_hdma_varB96 - 1);
      if ((uint16)(2 * (cutscene_hdma_varB90 + cutscene_hdma_varB96 - 1)) <
          0x1C0u) {
        v5 = cutscene_hdma_varB86;
        if (cutscene_hdma_varB86 == 0xFFFF) v5 = 255;
        hdma_data_array[(uint16)(2 * (cutscene_hdma_varB90 +
                                      cutscene_hdma_varB96 - 1)) >>
                        1] = v5;
      }
      ++cutscene_hdma_varB90;
      if (cutscene_hdma_varB84 >= 0x1C0u && cutscene_hdma_varB8E >= 0x1C0u) {
        LOBYTE(cutscene_hdma_varB9A) = cutscene_hdma_varB9A + 1;
        return;
      }
    }
    v1 = 0;
    goto LABEL_10;
  }
}

void DecodeAreaData_Sub_New() {
  uint8 v0;  // si

  v0 = 0;
  do {
    level_data_map16_hi[v0] = 0;
    level_data_map16_hi[v0 + 16] = 0;
    level_data_map16_hi[v0 + 32] = 0;
    level_data_map16_hi[v0 + 48] = 0;
    level_data_map16_hi[v0 + 64] = 0;
    level_data_map16_hi[v0 + 80] = 0;
    level_data_map16_hi[v0 + 96] = 0;
    level_data_map16_hi[v0 + 112] = 0;
    level_data_map16_hi[v0 + 128] = 0;
    level_data_map16_hi[v0 + 144] = 0;
    level_data_map16_hi[v0 + 160] = 0;
    level_data_map16_hi[v0 + 176] = 0;
    level_data_map16_hi[v0++ + 192] = 0;
  } while ((v0 & 0xF) != 0);
  level_data_map16_hi[112] = 104;
  level_data_map16_hi[113] = 104;
  level_data_map16_hi[114] = 104;
  level_data_map16_hi[163] = 104;
  level_data_map16_hi[164] = 104;
  level_data_map16_hi[165] = 104;
  level_data_map16_hi[166] = 104;
  level_data_map16_hi[121] = 104;
  level_data_map16_hi[122] = 104;
  level_data_map16_hi[123] = 104;
  level_data_map16_hi[124] = 104;
  level_data_map16_hi[125] = 104;
  level_data_map16_hi[126] = 104;
  render_graphics_var0EC9 = 1;
}

uint8 CODE_048895(uint8 j) {
  uint8 v1;  // si
  uint8 v2;  // al
  uint8 v3;  // si
  uint8 v4;  // al

  if (current_player) {
    v3 = 0;
    do {
      v4 = kDATA_048886[v3];
      vram_buffer1[++j] = v4;
      ++v3;
    } while (v4 != 0xFF);
  } else {
    v1 = 0;
    do {
      v2 = kDATA_048877[v1];
      vram_buffer1[++j] = v2;
      ++v1;
    } while (v2 != 0xFF);
  }
  return j;
}

void HandleLayersScroll() {
  int8 v0;     // al
  int8 v1;     // cl
  bool v2;     // cf
  int8 v3;     // al
  uint16 v4;   // ax
  uint8 i;     // di
  int v6;  // rbp
  uint16 v7;   // ax

  tempF6 = 0;
  *(uint16 *)&tempF3 = layers_scroll_0EEC;
  *(uint16 *)&tempF7 = 0;
  do {
    v0 = *((uint8 *)kDATA_048949 + *(uint16 *)&tempF3);
    v1 = 0;
    v2 = __CFSHL__(v0, 1);
    v3 = 2 * v0;
    if (v2) v1 = 1;
    tempF5 = (2 * v3 + v1) & 1;
    v4 =
        (uint8)(tempF5 + 2 * *((uint8 *)kDATA_048949 + *(uint16 *)&tempF3 + 1));
    if (v4 >= 0x80u) v4 |= 0xFF00u;
    layer3_tilemap_upload_buf[*(uint16 *)&tempF7 >> 1] = layer2_xpos + v4 + 8;
    *(uint16 *)&tempF3 = (*(uint16 *)&tempF3 + 16) & 0x1FF;
    ++*(uint16 *)&tempF7;
    ++*(uint16 *)&tempF7;
  } while (*(uint16 *)&tempF7 != 64);
  layers_scroll_0EEC = (layers_scroll_0EEC + 4) & 0x1FF;
  for (i = 62; (i & 0x80u) == 0; i -= 2) {
    v6 = i >> 1;
    v7 = layer3_tilemap_upload_buf[v6];
    layer3_tilemap_upload_buf[v6 + 32] = v7;
    layer3_tilemap_upload_buf[v6 + 64] = v7;
    layer3_tilemap_upload_buf[v6 + 96] = v7;
    layer3_tilemap_upload_buf[v6 + 128] = v7;
    layer3_tilemap_upload_buf[v6 + 160] = v7;
    layer3_tilemap_upload_buf[v6 + 192] = v7;
    layer3_tilemap_upload_buf[v6 + 224] = v7;
  }
}

void CODE_048B49() { CODE_048B59(); }

void SMB3_BufferLayer3Tilemap() {
  if (enable_layer3_bgflag) {
    CODE_048C77();
    CODE_048B59();
  }
}

void CODE_048B59() {
  game_loop_toggler &= 0x80u;
  if (area_type) {
    if (area_type != 1) return;
    SMB3_BufferLayer3CloudTilemap();
    vblank_flag_0ED4 = 1;
  } else {
    BufferAnimatedWaterSurfaceTiles();
    vram_buffer_addr_ctrl = 6;
  }
  vblank_enable_vtimel_flag = 1;
}

void SMB3_BufferLayer3CloudTilemap() {
  uint16 v0;   // si
  uint16 v1;   // ax
  int v2;  // rbp
  int v3;  // rbp
  int v4;  // rbx

  *(uint16 *)&tempF7 = 14;
  *(uint16 *)&R0_ = buffer_layer3_cloud_tilemap_offs;
  v0 = layer3_tilemap_upload_buf[0];
  LOBYTE(v1) = tempF4;
  HIBYTE(v1) = tempF3;
  v2 = layer3_tilemap_upload_buf[0] >> 1;
  layer3_tilemap_upload_buf[v2 + 1] = v1;
  layer3_tilemap_upload_buf[v2 + 30] = v1 + 1;
  do {
    v3 = (uint16)(8 * g_byte_7F3000[*(uint16 *)&R0_]) >> 1;
    v4 = v0 >> 1;
    layer3_tilemap_upload_buf[v4 + 2] = kLayer3CloudBGTilemap[v3];
    layer3_tilemap_upload_buf[v4 + 3] = kLayer3CloudBGTilemap[v3 + 1];
    layer3_tilemap_upload_buf[v4 + 31] = kLayer3CloudBGTilemap[v3 + 2];
    layer3_tilemap_upload_buf[v4 + 32] = kLayer3CloudBGTilemap[v3 + 3];
    v0 += 4;
    *(uint16 *)&R0_ += 16;
    --*(uint16 *)&tempF7;
  } while (*(uint16 *)&tempF7);
  layer3_tilemap_upload_buf[(layer3_tilemap_upload_buf[0] >> 1) + 59] = -1;
  layer3_tilemap_upload_buf[0] += 116;
  if ((((uint8)buffer_layer3_cloud_tilemap_offs + 1) & 0xF) != 0)
    ++buffer_layer3_cloud_tilemap_offs;
  else
    buffer_layer3_cloud_tilemap_offs =
        (buffer_layer3_cloud_tilemap_offs & 0xFFF0) + 224;
  if (buffer_layer3_cloud_tilemap_offs >= 0xA80u)
    buffer_layer3_cloud_tilemap_offs = 0;
  *(uint16 *)&tempF3 += 512;
}

void BufferAnimatedWaterSurfaceTiles() {
  uint16 v0;   // ax
  int v1;  // rbp
  uint16 v2;   // ax
  uint16 v3;   // di

  v0 = *(uint16 *)&tempF3;
  v1 = vram_buffer2_offset >> 1;
  vram_buffer2[v1] = *(uint16 *)&tempF3;
  v0 += 256;
  vram_buffer2[v1 + 3] = v0;
  *(uint16 *)&tempF3 = v0 + 256;
  vram_buffer2[v1 + 1] = 256;
  vram_buffer2[v1 + 4] = 256;
  if ((*(uint16 *)&tempF3 & 0x200) != 0) {
    v2 = 11310;
    v3 = 11311;
  } else {
    v2 = 11308;
    v3 = 11309;
  }
  vram_buffer2[v1 + 2] = v2;
  vram_buffer2[v1 + 5] = v3;
  vram_buffer2[v1 + 6] = -1;
  vram_buffer2_offset += 12;
}

void CODE_048C77() {
  int16 v0;  // ax

  LOBYTE(v0) = (uint16)(layer3_xpos + 288) >> 8;
  HIBYTE(v0) = layer3_xpos + 32;
  *(uint16 *)&tempF3 = v0;
  CODE_048C85();
}

void CODE_048C85() {
  uint8 v0;  // al

  if ((tempF3 & 1) != 0)
    v0 = 92;
  else
    v0 = 88;
  tempF3 = v0;
  tempF4 = (tempF4 >> 3) + 0x80;
}

void SpawnCastleTilesWithPriority() {
  uint16 v0;  // si
  uint16 v1;  // di
  uint8 *v2;  // rdx
  int16 v3;   // ax
  uint16 v4;  // si
  int16 v5;   // ax
  int16 v6;   // di
  int16 v7;   // ax
  int16 v8;   // di

  tempF5 = 1;
  *(uint16 *)&tempF3 =
      kDATA_048CEA[(uint8)((2 * (render_graphics_var0EE6 & 1)) & 2) >> 1];
  v0 = *(uint16 *)&vram_buffer1_offset;
  v1 = 0;
  do {
    v2 = IndirPtr(&tempF3, v1);
    v3 = *(uint16 *)v2;
    *(uint16 *)&vram_buffer1[v0 + 1] = *(uint16 *)v2;
    v1 += 2;
    v0 += 2;
  } while (v3 != -1);
  v4 = *(uint16 *)&vram_buffer1_offset;
  if ((render_graphics_var0EF4 & 0x20) != 0)
    *(uint16 *)&render_graphics_var0EF4 =
        *(uint16 *)&render_graphics_var0EF4 & 0xFDF ^ 0x400;
  LOBYTE(v5) =
      (uint16)((*(uint16 *)&render_graphics_var0EF4 + 705) & 0xFDF) >> 8;
  HIBYTE(v5) = (render_graphics_var0EF4 - 63) & 0xDF;
  *(uint16 *)&vram_buffer1[*(uint16 *)&vram_buffer1_offset + 1] = v5;
  v6 = __PAIR16__(v5, HIBYTE(v5)) + 1;
  if (((HIBYTE(v5) + 1) & 0x20) != 0) v6 = v6 & 0xFDF ^ 0x400;
  LOBYTE(v7) = HIBYTE(v6);
  HIBYTE(v7) = v6;
  *(uint16 *)&vram_buffer1[v4 + 13] = v7;
  v8 = v6 + 1;
  LOBYTE(v7) = HIBYTE(v8);
  HIBYTE(v7) = v8;
  *(uint16 *)&vram_buffer1[v4 + 25] = v7;
  *(uint16 *)&vram_buffer1_offset += 36;
  render_graphics_var0EE6 = 0;
  vram_buffer_addr_ctrl = 6;
}

void CODE_048D71() {
  int16 v0;  // ax
  uint8 v1;  // si
  int16 v2;  // ax
  int v3;    // edx
  int16 v4;  // ax
  int v5;    // edx

  v0 = *(uint16 *)&vram_buffer1[2 * ((uint8)vram_buffer2_offset >> 1) + 759];
  if (v0 == 36 || v0 == 4260) {
    if ((uint8)render_area_gfx_0ECE) return;
    ++render_area_gfx_0ECE;
    v1 = vram_buffer1_offset;
    LOBYTE(v2) = (uint16)(((render_graphics_var0ecc - 1) & 0x41F) + 832) >> 8;
    HIBYTE(v2) = ((render_graphics_var0ecc - 1) & 0x1F) + 64;
    v3 = vram_buffer1_offset;
    *(uint16 *)&vram_buffer1[vram_buffer1_offset + 1] = v2;
    *(uint16 *)&vram_buffer1[v3 + 3] = 1920;
    *(uint16 *)&vram_buffer1[v1 + 5] = 2573;
    *(uint16 *)&vram_buffer1[v1 + 7] = 2589;
    *(uint16 *)&vram_buffer1[v1 + 9] = 2575;
    *(uint16 *)&vram_buffer1[v1 + 11] = 2591;
    goto LABEL_10;
  }
  if (v0 == 2568) {
    if (HIBYTE(render_area_gfx_0ECE)) {
      render_area_gfx_0ECE = 0;
      if (*(uint16 *)((int8 *)&screen_left_xpos16 + 1) ||
          render_graphics_var0ecc) {
        v1 = vram_buffer1_offset;
        LOBYTE(v4) = (uint16)(render_graphics_var0ecc + 832) >> 8;
        HIBYTE(v4) = render_graphics_var0ecc + 64;
        v5 = vram_buffer1_offset;
        *(uint16 *)&vram_buffer1[vram_buffer1_offset + 1] = v4;
        *(uint16 *)&vram_buffer1[v5 + 3] = 1920;
        *(uint16 *)&vram_buffer1[v1 + 5] = 2572;
        *(uint16 *)&vram_buffer1[v1 + 7] = 2588;
        *(uint16 *)&vram_buffer1[v1 + 9] = 2574;
        *(uint16 *)&vram_buffer1[v1 + 11] = 2590;
      LABEL_10:
        *(uint16 *)&vram_buffer1[v1 + 13] = -1;
        *(uint16 *)&vram_buffer1_offset = v1 + 12;
      }
    }
  }
}

void DecodeAreaData_Sub2_New(uint16 j) {
  int16 v1;                    // ax
  uint8 v2;                    // si
  uint8 v3;                    // di
  uint8 v4;                    // si
  uint8 v5;                    // di
  uint8 v6;                    // di
  uint8 v7;                    // di
  uint8 v8;                    // si
  uint8 EmptyEnemySlot_Far;    // si
  uint8 v10;                   // di
  uint8 v11;                   // al
  uint8 v12;                   // di
  bool v13;                    // sf
  uint8 v14;                   // di
  uint8 v15;                   // di
  uint8 v16;                   // di
  uint8 v17;                   // di
  uint8 v18;                   // di
  uint8 i;                     // di
  uint8 v20;                   // di
  uint8 v21;                   // di
  uint8 v22;                   // di
  uint8 v23;                   // di
  uint8 v24;                   // di
  uint8 v25;                   // di
  uint8 v26;                   // di
  uint8 v27;                   // di
  uint8 v28;                   // al
  uint8 v29;                   // di
  uint8 v30;                   // di
  uint8 v31;                   // al
  uint8 v32;                   // di
  uint8 v33;                   // di
  uint8 v34;                   // si
  uint8 v35;                   // di
  uint8 v36;                   // di
  uint8 v37;                   // [rsp+46h] [rbp-2h]
  uint8 v38;                   // [rsp+46h] [rbp-2h]
  uint8 AreaObjXPosition_Far;  // [rsp+46h] [rbp-2h]
  uint8 t0;

  *(uint16 *)&tempF3 = area_data_ptr.addr;
  *(uint16 *)&tempF4 = *(uint16 *)((int8 *)&area_data_ptr.addr + 1);
  *(uint16 *)&tempF5 = *(uint16 *)&area_data_ptr.bank;
  v1 = *(uint16 *)IndirPtr(&tempF3, (j + 2)) & 0x7F;
  R0_ = *((uint8 *)kDATA_048E43 + v1);
  R1_ = *((uint8 *)kDATA_048E43 + v1 + 1);
  v2 = object_index;
  switch ((uint8)v1 >> 1) {
    case 0:
      v4 = 0;
      v5 = 15;
      goto LABEL_5;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 17:
    case 18:
    case 19:
    case 21:
    case 22:
    case 23:
    case 33:
    case 34:
    case 35:
    case 36:
    case 37:
    case 38:
    case 39:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
      return;
    case 8:
      v37 = object_index;
      RenderUnderPart_Far(1u, 0xFu, 0x44u);
      v5 = CODE_0491C0(v37);
      v4 = 1;
    LABEL_5:
      RenderUnderPart_Far(v4, v5, 0x40u);
      return;
    case 9:
      v3 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v3);
      metatile_buffer[R7_] = 0;
      return;
    case 16:
      v6 = CODE_0491C0(object_index);
      R7_ = v6;
      render_graphics_var0EE7 = 0;
      if (!v6) v6 = 8;
      ChkLrgObjFixedLength_Far(v2, v6 + 1);
      v38 = v2;
      v7 = area_object_length[v2];
      v8 = R7_;
      R6_ = 22;
      do {
        metatile_buffer[v8++] = kDATA_048ED6[v7];
        if (R6_) {
          v7 += 10;
          --R6_;
        }
      } while (v8 != 11);
      if (R7_ && !area_object_length[v38]) metatile_buffer[10] = 0;
      if (column_pos_hi) {
        if (area_object_length[v38] == 5) {
          AreaObjXPosition_Far = GetAreaObjXPosition_Far();
          EmptyEnemySlot_Far = FindEmptyEnemySlot_Far();
          obj_xpos_lo.enemy[EmptyEnemySlot_Far] = AreaObjXPosition_Far + 8;
          obj_xpos_hi.enemy[EmptyEnemySlot_Far] =
              __CFADD__(AreaObjXPosition_Far, 8) + column_pos_hi;
          obj_ypos_hi.enemy[EmptyEnemySlot_Far] = 1;
          enemy_flag[EmptyEnemySlot_Far] = 1;
          obj_ypos_lo.enemy[EmptyEnemySlot_Far] = -112;
          enemy_id[EmptyEnemySlot_Far] = 49;
          ++render_graphics_var0EE7;
          if (R7_) ++render_graphics_var0EE7;
        }
      }
      if (column_pos_hi) {
        if (metatile_buffer[11] == 86) metatile_buffer[11] = -5;
      }
      return;
    case 20:
      v10 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v10);
      tempF3 = metatile_buffer[0];
      if (metatile_buffer[0] == 101)
        v11 = metatile_buffer[0] + 1;
      else
        v11 = metatile_buffer[0] - 1;
      tempF4 = v11;
      v12 = R7_;
      if ((R7_ & 1) != 0) goto LABEL_27;
      while (1) {
        metatile_buffer[v12] = tempF3;
        v13 = (--area_object_length[v2] & 0x80u) != 0;
        if (v13) break;
        ++v12;
      LABEL_27:
        metatile_buffer[v12] = tempF4;
        v13 = (--area_object_length[v2] & 0x80u) != 0;
        if (v13) break;
        ++v12;
      }
      return;
    case 24:
      v14 = CODE_0491C0(object_index);
      t0 = area_object_length[v2];
      ChkLrgObjFixedLength_Far(v2, v14);
      if (t0 & 0x80) decode_area_data_var0734 = 9;
      --decode_area_data_var0734;
      RenderUnderPart_Far(kDATA_049012[decode_area_data_var0734],
                          kDATA_049009[decode_area_data_var0734], 0x64u);
      return;
    case 25:
      v15 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v15);
      v16 = R7_;
      if (area_object_length[v2]) {
        if (metatile_buffer[R7_]) goto LABEL_42;
        metatile_buffer[R7_] = -11;
      } else {
        metatile_buffer[R7_] = -13;
        if (!metatile_buffer[++v16]) metatile_buffer[v16++] = -12;
      }
      do {
        if (!metatile_buffer[v16]) metatile_buffer[v16] = -10;
      LABEL_42:
        ++v16;
      } while (v16 != 13);
      return;
    case 26:
      v17 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v17);
      v18 = R7_;
      metatile_buffer[R7_] = 103;
      for (i = v18 + 2; metatile_buffer[i] == 101 || metatile_buffer[i] == 102;
           i += 2)
        metatile_buffer[i] = 103;
      return;
    case 27:
      v20 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v20);
      v21 = R7_;
      metatile_buffer[R7_] = -9;
      v22 = v21 + 1;
      do {
        if (metatile_buffer[v22] == 0xEB) break;
        metatile_buffer[v22++] = -8;
      } while (v22 != 13);
      return;
    case 28:
      v23 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v23);
      v24 = R7_;
      if (metatile_buffer[R7_] != 0xFC) metatile_buffer[R7_] = -7;
      v25 = v24 + 1;
      do {
        if (metatile_buffer[v25] == 0xF0) break;
        metatile_buffer[v25++] = -6;
      } while (v25 != 13);
      return;
    case 29:
      v26 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v26);
      v27 = R7_;
      if (area_object_length[v2]) {
        if (metatile_buffer[R7_] == 104)
          v28 = -18;
        else
          v28 = -21;
        metatile_buffer[R7_] = v28;
        metatile_buffer[v27 + 1] = -20;
        metatile_buffer[12] = 105;
      } else {
        metatile_buffer[R7_] = 2;
        metatile_buffer[v27 + 1] = -19;
      }
      return;
    case 30:
      v29 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v29);
      v30 = R7_;
      if (area_object_length[v2]) {
        metatile_buffer[R7_] = 3;
        metatile_buffer[v30 + 1] = -17;
      } else {
        if (metatile_buffer[R7_] == 104)
          v31 = -14;
        else
          v31 = -16;
        metatile_buffer[R7_] = v31;
        for (metatile_buffer[v30 + 1] = -15; ++v30 != 12;
             metatile_buffer[v30 + 1] = 105)
          ;
      }
      return;
    case 31:
      v32 = CODE_0491C0(object_index);
      ChkLrgObjFixedLength_Far(v2, v32);
      v33 = R7_;
      do {
        metatile_buffer[v33++] = 113;
        v13 = (--area_object_length[v2] & 0x80u) != 0;
      } while (!v13);
      return;
    case 32:
      ChkLrgObjFixedLength_Far(object_index, 3u);
      R5_ = CODE_0491C0(v2) - 2;
      R6_ = area_object_length[v2];
      v34 = R5_ + 1;
      if (kDATA_049172[R6_]) {
        v34 = RenderUnderPart_Far(0, R5_, kDATA_049172[R6_]);
      }
      v35 = R6_;
      metatile_buffer[v34] = kDATA_049176[R6_];
      metatile_buffer[v34 + 1] = kDATA_04917A[v35];
      return;
    case 40:
      v36 = CODE_0491C0(object_index);
      RenderUnderPart_Far(2u, v36, 0x77u);
      return;
  }
}

uint8 CODE_0491C0(uint8 k) {
  uint16 v1;  // di

  v1 = area_obj_offset_buffer[(uint16)(2 * k) >> 1] + 1;
  R7_ = *IndirPtr(&tempF3, v1) >> 4;
  return *IndirPtr(&tempF3, v1) & 0xF;
}

uint8 CODE_0491DD() {
  uint16 v0;     // si
  uint16 v1;     // di
  uint16 v2;     // ax
  uint16 v3;     // ax
  uint16 i;      // si
  uint16 v5;     // ax
  PairU16 v6;    // edx
  PairU16 v7;    // edx
  uint8 result;  // di

  v0 = 0;
  v1 = vram_buffer2_offset;
  if (current_player_mirror) {
    while (1) {
      v2 = *(uint16 *)&kGameOverScreenStripeImage_Luigi[v0];
      vram_buffer2[v1 >> 1] = v2;
      if (v2 == 0xFFFF) break;
      v0 += 2;
      v1 += 2;
    }
  } else {
    while (1) {
      v3 = *(uint16 *)&kGameOverScreenStripeImage[v0];
      vram_buffer2[v1 >> 1] = v3;
      if (v3 == 0xFFFF) break;
      v0 += 2;
      v1 += 2;
    }
  }
  for (i = 0;; i += 2) {
    v5 = *(uint16 *)&kGameOverScreenStripeImage_TitleLogo[i];
    vram_buffer2[v1 >> 1] = v5;
    if (v5 == 0xFFFF) break;
    v1 += 2;
  }
  vram_buffer2_offset = v1;
  *(uint16 *)&R2_ = -18909;
  v6 = CODE_049724(0xA0u, 0);
  v7 = CODE_049724(v6.first, v6.second);
  result = CODE_049724(v7.first, v7.second).second;
  layer2_xpos = 0;
  layer3_xpos = 0;
  vram_buffer_addr_ctrl = 6;
  vblank_which_layer2_scroll_flag = 0;
  WriteReg(BG2HOFS, 0);
  WriteReg(BG2HOFS, 0);
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3HOFS, 0);
  tm_mirror = 23;
  tileset_graphics_type = 10;
  palette_anim0E20 = 10;
  update_entire_palette_flag = 1;
  HandleTilesetGraphicsUploads();
  override_player_xpos2_flag = -1;
  layer2_ypos = 0;
  WriteReg(BG2VOFS, 0);
  WriteReg(BG2VOFS, 0);
  return result;
}

void CODE_0492E7() {
  uint8 v0;    // di
  uint8 v1;    // di
  uint16 v2;   // di
  int v3;  // rbp
  uint16 v4;   // di
  uint16 v5;   // si
  uint16 v6;   // ax
  uint16 v7;   // di
  uint16 v8;   // si
  uint16 v9;   // ax
  uint16 v10;  // si
  uint16 v11;  // ax
  uint16 v12;  // si
  uint16 v13;  // ax
  uint8 v14;   // al
  uint8 v15;   // [rsp+44h] [rbp-4h]

  if (unused_byte_7E0E1A) unused_byte_7E0E1A = 0;
  music_ch1 = 0x80;
  v15 = kCODE_0492C6[(uint8)(level_level_preview_image_to_use - 1) + 1];
  tileset_graphics_type = v15 & 0x1F;
  unused_byte_7E0E23 = v15 & 0xE0;
  disable_screen_flag = 1;
  game_loop_toggler = 1;
  HandleTilesetGraphicsUploads();
  render_graphics_var0EC9 = 0;
  area_parser_ctr1 = 0;
  tree_ledge_saved_x = 0;
  tree_ledge_arr130F[0] = 0;
  set_level_music_flag = 0;
  LOBYTE(render_area_gfx_0ECE) = render_area_gfx_0ECE + 1;
  render_area_gfx_0ECE = (uint8)render_area_gfx_0ECE;
  vblank_which_layer2_scroll_flag = 0;
  LOBYTE(cutscene_hdma_varB9A) = 0;
  cutscene_var1680 = 0;
  UNUSED_byte_7E1681 = 0;
  enable_layer3_bgflag = 0;
  Dma_CODE_0480EF();
  current_player_mirror = current_player;
  PrintStatusBarNumbers_Far(kStatusBarNybbles[current_player]);
  v0 = vram_buffer1_offset;
  if (!vram_buffer1[vram_buffer1_offset - 11])
    vram_buffer1[vram_buffer1_offset - 11] = 40;
  if (number_of_players) {
    if ((other_player_num_lives & 0x80u) == 0) {
      *(uint16 *)&vram_buffer1[v0 + 1] = 29272;
      *(uint16 *)&vram_buffer1[v0 + 3] = 1792;
      *(uint16 *)&vram_buffer1[v0 + 5] = 8232;
      vram_buffer1[v0 + 7] = world_number + 1;
      vram_buffer1[v0 + 8] = 32;
      vram_buffer1[v0 + 10] = 32;
      vram_buffer1[v0 + 12] = 32;
      vram_buffer1[v0 + 9] = 36;
      vram_buffer1[v0 + 11] = level_number + 1;
      vram_buffer1[v0 + 13] = -1;
      *(uint16 *)&vram_buffer1_offset = v0 + 12;
      v1 = v0 + 12;
      if (player_hard_mode_flag) vram_buffer1[v1 + 5 - 12] = 42;
    }
  }
  vram_buffer_addr_ctrl = 6;
  *(uint16 *)&tree_ledge_countdown = 0;
  *(uint16 *)&tree_ledge_arr130F[1] = 0;
  *(uint16 *)&tree_ledge_arr130F[3] = 0;
  v2 = vram_buffer2_offset;
  v3 = vram_buffer2_offset >> 1;
  vram_buffer2[v3] = -14583;
  vram_buffer2[v3 + 1] = 4800;
  vram_buffer2[v3 + 2] = 12450;
  vram_buffer2[v3 + 3] = -10231;
  vram_buffer2[v3 + 4] = 4800;
  vram_buffer2[v3 + 5] = 28834;
  vram_buffer2[v3 + 6] = -22519;
  vram_buffer2[v3 + 7] = 7744;
  vram_buffer2[v3 + 8] = 12408;
  vram_buffer2[v3 + 9] = 2059;
  vram_buffer2[v3 + 10] = 7744;
  vram_buffer2[v3 + 11] = -20360;
  v4 = v2 + 24;
  v5 = 0;
  do {
    v6 = *(uint16 *)&kLevelPreviewStripeImages[v5];
    vram_buffer2[v4 >> 1] = v6;
    v5 += 2;
    v4 += 2;
  } while (v6 != 0xFFFF);
  v7 = v4 - 2;
  v8 = kDATA_04927E[(uint16)(2 *
                             (uint8)(level_level_preview_image_to_use - 1)) >>
                    1];
  do {
    v9 = *(uint16 *)&kLevelPreviewStripeImages_Main[v8];
    vram_buffer2[v7 >> 1] = v9;
    v8 += 2;
    v7 += 2;
  } while (v9 != 0xFFFF);
  if (background_color_ctrl_0 == 17) {
    v7 -= 2;
    v10 = 0;
    do {
      v11 = *(uint16 *)&kDATA_04AD6F[v10];
      vram_buffer2[v7 >> 1] = v11;
      v10 += 2;
      v7 += 2;
    } while (v11 != 0xFFFF);
  }
  if ((background_color_ctrl_0 & 0xF0) != 0 && background_color_ctrl_0 != 22) {
    v7 -= 2;
    v12 = 0;
    do {
      v13 = *(uint16 *)&kDATA_04AD9B[v12];
      vram_buffer2[v7 >> 1] = v13;
      v12 += 2;
      v7 += 2;
    } while (v13 != 0xFFFF);
  }
  vram_buffer2_offset = v7;
  CODE_0495E2();
  --screen_routine_task;
  update_entire_palette_flag = 1;
  palette_mirror[0] = 0;
  tempEB = player_status;
  player_status = 1;
  v14 = background_color_ctrl_0 & 0xF0;
  if ((background_color_ctrl_0 & 0xF0) != 0) v14 = 4;
  background_color_ctrl = v14;
  if (background_color_ctrl_0 == 2) background_color_ctrl = 3;
  GetPlayerColors();
  --update_entire_palette_flag;
  player_status = tempEB;
  background_color_ctrl_0 = 0;
  tm_mirror = 23;
  vram_buffer_addr_ctrl = 6;
  palette_anim0E20 = 0;
  vblank_enable_vtimel_flag = 0;
  layer2_ypos = 0;
  WriteReg(BG2VOFS, 0);
  WriteReg(BG2VOFS, 0);
}
// 7E16F6: using guessed type uint8 byte_7E16F6[10];

void CODE_0494EA() {
  uint16 v0;  // kr00_2

  if (draw_level_preview_sprites_var009B) {
    draw_level_preview_sprites_var009B = 0;
    v0 = screen_left_xpos16_b;
    screen_left_xpos_hi = HIBYTE(v0);
    screen_left_xpos_lo = v0;
    layer1_xpos_lo = screen_left_xpos16_b;
    layer2_xpos = screen_left_xpos16_b >> 1;
    layer3_xpos = screen_left_xpos16_b >> 2;
    UNUSED_word_7E0ED7 = screen_left_xpos16_b >> 2;
  }
  g_byte_7E0EF6 = HIBYTE(layer2_xpos) & 1;
  area_parser_flag0EFC = 0;
  HIBYTE(g_word_7E0EF7) = 0;
  SetupLayer2Bg();
  CODE_049B96();
  CODE_049BBC();
  CODE_049BBC();
  CODE_049BBC();
  CODE_049BBC();
  CODE_049BBC();
  CODE_049BBC();
  if (obj_yspeed.bubble[0] != 3) {
    CODE_049BBC();
    CODE_049BBC();
    CODE_049BBC();
    CODE_049BBC();
    if (vblank_which_layer2_scroll_flag) {
      CODE_049BBC();
      CODE_049BBC();
      CODE_049BBC();
      CODE_049BBC();
      CODE_049BBC();
      CODE_049BBC();
    }
  }
}

void CODE_04956B() {
  uint8 v0;  // al
  uint8 v1;  // si

  CODE_0494EA();
  layer2_ypos = 0;
  if (area_type) {
    if (area_type == 1 && area_data_addr_index != 10) LOBYTE(layer2_ypos) = -8;
    v0 = 6;
    cgwsel_mirror = 6;
    v1 = 17;
  } else {
    WriteRegWord(DMAP2, 0xF42u);
    WriteRegWord(A1T2L, 0x9564u);
    WriteReg(A1B2, 1u);
    WriteReg(DAS20, 0x7Fu);
    LOBYTE(layers_scroll_0EEC) = 0;
    UNUSED_byte_7E0EF3 = 0;
    hdmaenable_mirror |= 4u;
    v0 = 0;
    v1 = 23;
  }
  tm_mirror = v1;
  ts_mirror = v0;
  LOBYTE(buffer_layer3_cloud_tilemap_offs) = 0;
  vtimel_mirror = 31;
  if (vblank_which_layer2_scroll_flag) {
    vtimel_mirror = -81;
    vblank_enable_vtimel_flag = 2;
  }
  CODE_0495E2();
}

void CODE_0495E2() {
  int16 v0;    // ax
  uint16 v1;   // di
  uint16 v2;   // si
  int v3;  // rbp
  int v4;  // rbx
  uint16 v5;   // di
  uint16 v6;   // si
  uint16 v7;   // ax

  if (override_area_data_addr_index) {
    area_data_addr_index = override_area_data_addr_index;
    override_area_data_addr_index = 0;
  } else if (area_data_addr_index == 12) {
    override_area_data_addr_index = area_data_addr_index;
    if (!world_number || world_number == 3)
      area_data_addr_index = 25;
    else
      area_data_addr_index = 1;
  }
  *(uint16 *)&R6_ = 16 * area_data_addr_index;
  *(uint16 *)&R2_ = 0;
  do {
    v0 = kLevelPaletteIndexes[*(uint16 *)&R6_];
    ++*(uint16 *)&R6_;
    v1 = kDATA_04AE3F[(uint16)(2 * v0) >> 1];
    v2 = *(uint16 *)&R2_;
    *(uint16 *)&R4_ = 7;
    do {
      v3 = v1 >> 1;
      v4 = v2 >> 1;
      palette_mirror[v4] = kDATA_04AEC3[v3];
      palette_mirror[v4 + 8] = kword_1AED3[v3];
      v2 += 2;
      v1 += 2;
      --*(uint16 *)&R4_;
    } while (*(int16 *)&R4_ >= 0);
    *(uint16 *)&R2_ = v2 + 16;
  } while (v2 != 464);
  if (tileset_graphics_flag_var2f8 && current_player) {
    v5 = 0;
    v6 = 224;
    do {
      palette_mirror[v6 >> 1] = kDATA_049679[v5 >> 1];
      v6 += 2;
      v5 += 2;
    } while (v5 != 32);
  }
  layer3_xpos = screen_left_xpos16 >> 2;
  *(uint16 *)&tempF3 = (uint16)((screen_left_xpos16 >> 2) & 0xFF00) >> 8;
  v7 = 2 * world_number;
  if (v7 >= 0xCu) v7 = 0;
  *(uint16 *)&tempF3 += v7;
  buffer_layer3_cloud_tilemap_offs = 0;
  while (*(uint16 *)&tempF3) {
    buffer_layer3_cloud_tilemap_offs += 224;
    --*(uint16 *)&tempF3;
  }
  buffer_layer3_cloud_tilemap_offs += (uint8)(layer3_xpos & 0xF0) >> 4;
  if (buffer_layer3_cloud_tilemap_offs >= 0xA80u)
    buffer_layer3_cloud_tilemap_offs = 0;
  CODE_04973C();
  if (enable_layer3_bgflag) {
    tempF3 = HIBYTE(layer3_xpos);
    tempF4 = layer3_xpos;
    CODE_048C85();
    tempF5 = 19;
    do {
      CODE_048B49();
      if (tempF4 >= 0xA0u) {
        tempF3 ^= 4u;
        tempF4 = 0x80;
      }
      --tempF5;
    } while (tempF5);
  }
  update_entire_palette_flag = 1;
  ++screen_routine_task;
}

PairU16 CODE_049724(uint8 k, uint8 j) {
  *(uint16 *)&R4_ = 1;
  *(uint16 *)&R0_ = 16;
  do {
    palette_mirror[k >> 1] = *(uint16 *)IndirPtr(&R2_, j);
    j += 2;
    k += 2;
    --*(uint16 *)&R0_;
  } while (*(uint16 *)&R0_);
  return MakePairU16(k, j);
}

void CODE_04973C() {
  uint8 v0;   // si
  uint16 v1;  // ax
  uint16 v2;  // di
  int16 v3;   // cx

  v0 = 0;
  do {
    g_byte_7F3000[v0] = 0;
    g_byte_7F3000[v0 + 256] = 0;
    g_byte_7F3000[v0 + 512] = 0;
    g_byte_7F3000[v0 + 768] = 0;
    g_byte_7F3000[v0 + 1024] = 0;
    g_byte_7F3000[v0 + 1280] = 0;
    g_byte_7F3000[v0 + 1536] = 0;
    g_byte_7F3000[v0 + 1792] = 0;
    g_byte_7F3000[v0 + 2048] = 0;
    g_byte_7F3000[v0 + 2304] = 0;
    g_byte_7F3000[v0-- + 2560] = 0;
  } while (v0);
  tempF5 = 127;
  tempF6 = 0;
  *(uint16 *)&tempF3 = 12288;
  for (*(uint16 *)&tempF8 = 0;;) {
    v1 = kDATA_04B683[*(uint16 *)&tempF8 >> 1];
    if (v1 == 0xFFFF) break;
    if ((int16)v1 < 0) *(uint16 *)&tempF3 += 224;
    v2 = (uint8)v1;
    v3 = __CFSHL__uint16(2 * v1);
    HIBYTE(v1) = 0;
    *(uint16 *)&tempF6 = v3;
    tempF7 = *((uint8 *)kDATA_04B683 + (uint16)(*(uint16 *)&tempF8 + 1)) & 0x3F;
    while (1) {
      uint16 t = g_ram[0xf3] | g_ram[0xf4] << 8;
      IndirWriteByte(&tempF3, v2, tempF7);
      if (!tempF6 || (v2 & 0xF0) == 0xD0) break;
      LOBYTE(v1) = v2 + 16;
      v2 = v1;
    }
    ++*(uint16 *)&tempF8;
    ++*(uint16 *)&tempF8;
  }
}

void GetBackgroundColor_0() {
  if (!background_color_ctrl_0) {
    ++screen_routine_task;
    GetPlayerColors();
  }
}

void GetPlayerColors() {
  uint8 bubble;  // al
  uint16 v1;     // ax
  int16 v2;      // ax
  int8 v3;       // t0
  uint8 v4;      // di
  uint8 i;       // si
  int v6;    // rbp
  int v7;    // rbx

  bubble = background_color_ctrl;
  if (!background_color_ctrl) bubble = obj_yspeed.bubble[0];
  if (!cloud_type_override || (background_color_ctrl & 4) != 0 ||
      (number_of_lives & 0x80) != 0)
    v1 = kDATA_0499ED[(uint16)(2 * bubble) >> 1];
  else
    v1 = 21034;
  palette_mirror[0] = v1;
  *(uint16 *)&coldata1_mirror = (v1 & 0x1F) + 32;
  v2 = 8 * (v1 & 0x3E0);
  v3 = v2;
  LOBYTE(v2) = HIBYTE(v2);
  HIBYTE(v2) = v3;
  *(uint16 *)&coldata2_mirror = v2 + 64;
  LOBYTE(v2) = (uint16)((uint16)(palette_mirror[0] & 0x7C00) >> 2) >> 8;
  HIBYTE(v2) = 0;
  *(uint16 *)&coldata3_mirror = v2 + 128;
  palette_mirror[0] = 0;
  if (!player_disable_auto_palette_update) {
    v4 = 0;
    if (current_player) v4 = 32;
    if (player_status == 2) v4 += 64;
    for (i = 0; i != 16; i += 2) {
      v6 = v4 >> 1;
      v7 = i >> 1;
      palette_mirror[v7 + 240] = kDATA_0499FD[v6];
      palette_mirror[v7 + 248] = kDATA_0499FD[v6 + 8];
      v4 += 2;
    }
    ++update_entire_palette_flag;
  }
}
// 7E00BA: using guessed type int8;

void CODE_049B35() {
  uint8 v0;  // al
  int8 v1;   // al

  R0_ = 32;
  if (obj_yspeed.bubble[0] == 3) R0_ *= 2;
  LOBYTE(g_word_7E0EF7) = (uint8)((R0_ + layer2_xpos) & 0xF0) >> 2;
  R0_ = (uint8)((R0_ + layer2_xpos) & 0xF0) >> 3;
  if (R0_) {
    if ((layer2_xpos & 0x100) != 0)
      v0 = 16;
    else
      v0 = 20;
  } else if (g_byte_7E0EF6) {
    g_byte_7E0EF6 = 0;
    v0 = 20;
  } else {
    v0 = 16;
    g_byte_7E0EF6 = 16;
  }
  R1_ = v0;
  v1 = HIBYTE(layer2_xpos) & 0xF;
  if (!R0_) ++v1;
  HIBYTE(g_word_7E0EF7) = 8 * (v1 + 1);
  CODE_049BBC();
}

void CODE_049B96() {
  uint8 v0;  // al

  LOBYTE(g_word_7E0EF7) = (uint8)(layer2_xpos & 0xF0) >> 2;
  R0_ = (uint8)(layer2_xpos & 0xF0) >> 3;
  HIBYTE(g_word_7E0EF7) = 8 * HIBYTE(layer2_xpos);
  if ((layer2_xpos & 0x100) != 0)
    v0 = 20;
  else
    v0 = 16;
  R1_ = v0;
}

void CODE_049BBC() {
  uint16 v0;  // di
  uint16 v1;  // si

  g_word_7E0EFA = 4;
  if (obj_yspeed.bubble[0] == 3) g_word_7E0EFA *= 2;
  v0 = upload_buffer_3[0];
  do {
    if ((R0_ & 0x20) != 0) *(uint16 *)&R0_ = (*(uint16 *)&R0_ + 1024) & 0x1400;
    upload_buffer_3[(v0 >> 1) + 1] = *(uint16 *)&R0_ - 2048;
    *(uint16 *)&R2_ = 32;
    if ((g_word_7E0EF7 & 0x40) != 0)
      g_word_7E0EF7 = (g_word_7E0EF7 + 2048) & 0xFF00;
    v1 = g_word_7E0EF7;
    *(uint16 *)&R4_ = g_word_7E0EF7;
    do {
      upload_buffer_3[(v0 >> 1) + 2] = layer2_map16_table[v1 >> 1];
      v0 += 2;
      *(uint16 *)&R4_ += 64;
      v1 = *(uint16 *)&R4_;
      --*(uint16 *)&R2_;
    } while (*(int16 *)&R2_ >= 0);
    upload_buffer_3[v0 >> 1] = 36;
    ++g_word_7E0EF7;
    ++g_word_7E0EF7;
    ++*(uint16 *)&R0_;
    --g_word_7E0EFA;
  } while (g_word_7E0EFA);
  upload_buffer_3[0] = v0;
  upload_buffer_3[(v0 >> 1) + 1] = -1;
  vblank_upload_from_7f0000_flag = 1;
}

void LoadAreaPointer() {
  int8 v0;  // al

  area_pointer = FindAreaPointer();
  v0 = 4 * (area_pointer & 0x60) + __CFSHL__(area_pointer & 0x60, 1);
  area_type =
      2 * (2 * v0 + __CFSHL__(2 * (area_pointer & 0x60), 1)) + __CFSHL__(v0, 1);
}

uint8 FindAreaPointer() {
  uint8 v0;  // di

  v0 = world_number;
  if (world_number >= 8u) {
    area_number = 0;
    level_number = 0;
    v0 = 0;
    world_number = 0;
  }
  return kAreaAddrOffsets[(uint8)(area_number + kWorldAddrOffsets[v0])];
}

void GetAreaDataAddrs() {
  int8 v0;   // al
  int v1;    // edx
  uint8 v2;  // al
  uint8 v3;  // al
  uint8 v4;  // al
  uint8 v5;  // al
  bool v6;   // cf
  uint8 v7;  // [rsp+46h] [rbp-2h]
  uint8 v8;  // [rsp+46h] [rbp-2h]

  obj_yspeed.bubble[0] = 0;
  v0 = 4 * (area_pointer & 0x60) + __CFSHL__(area_pointer & 0x60, 1);
  area_type =
      2 * (2 * v0 + __CFSHL__(2 * (area_pointer & 0x60), 1)) + __CFSHL__(v0, 1);
  area_addrs_l_offset = area_pointer & 0x1F;
  v1 = (uint8)((area_pointer & 0x1F) + kEnemyAddrHOffsets[area_type]);
  LOBYTE(enemy_data_ptr.addr) = kEnemyDataAddrLow[(
      uint8)((area_pointer & 0x1F) + kEnemyAddrHOffsets[area_type])];
  HIBYTE(enemy_data_ptr.addr) = kEnemyDataAddrHigh[v1];
  enemy_data_ptr.bank = 1;
  v2 = (area_pointer & 0x1F) + kAreaDataHOffsets[area_type];
  area_data_addr_index = v2;
  if (v2 >= 0x1Cu) {
  LABEL_5:
    ++obj_yspeed.bubble[0];
    goto LABEL_6;
  }
  if (v2 >= 0x19u) {
  LABEL_6:
    ++obj_yspeed.bubble[0];
    goto LABEL_7;
  }
  if (v2 < 3u) {
    if (v2 < 2u) goto LABEL_8;
    goto LABEL_5;
  }
LABEL_7:
  ++obj_yspeed.bubble[0];
LABEL_8:
  LOBYTE(area_data_ptr.addr) = kAreaDataAddrLow[v2];
  HIBYTE(area_data_ptr.addr) = kAreaDataAddrHigh[v2];
  area_data_ptr.bank = 1;
  v7 = *IndirPtr(&area_data_ptr, 0);
  v3 = v7 & 7;
  if ((v7 & 7u) >= 4) {
    background_color_ctrl = v7 & 4;
    v3 = 0;
  }
  foreground_scenery = v3;
  player_entrance_ctrl = (uint8)(v7 & 0x38) >> 3;
  game_timer_setting = 2 * (4 * (v7 & 0xC0) + __CFSHL__(v7 & 0xC0, 1)) +
                       __CFSHL__(2 * (v7 & 0xC0), 1);
  v8 = *IndirPtr(&area_data_ptr, 1u);
  terrain_control = v8 & 0xF;
  v4 = (uint8)(v8 & 0x30) >> 4;
  if (v4 == 1) v4 = 0;
  background_scenery = v4;
  v5 = 2 * (4 * (v8 & 0xC0) + __CFSHL__(v8 & 0xC0, 1)) +
       __CFSHL__(2 * (v8 & 0xC0), 1);
  if (v5 == 3) {
    cloud_type_override = 3;
    v5 = 0;
  }
  area_style = v5;
  UpdateVineAtEntrance_New();
  v6 = __CFADD__(area_data_ptr.addr, 2);
  LOBYTE(area_data_ptr.addr) += 2;
  HIBYTE(area_data_ptr.addr) += v6;
  area_parser_var3 = 0;
}
// 7E00BA: using guessed type int8;

void UpdateVineAtEntrance_New() {
  if (cloud_type_override || area_data_addr_index == 18)
    vine_at_entrance_flag = 1;
}

void RenderPlayerSub_New() {
  int16 v0;  // ax

  if (!cutscene_var0BA5) {
    if ((player_gfx_offset == 24 || player_gfx_offset == 120) &&
        (frame_counter & 7) == 0 && !sound_ch2)
      sound_ch2 = 4;
    vram_flag_028e = 1;
    LOBYTE(v0) = 0;
    HIBYTE(v0) = player_gfx_offset >> 3;
    player_graphics_pointer.addr = v0 + 0x8000;
    player_vramaddress = 24576;
    player_graphics_upload_size = 256;
    if (player_luigi_graphics) HIBYTE(player_graphics_pointer.addr) |= 0x40u;
    player_graphics_pointer.bank = 7;
  }
}

void CODE_04D85A() { level_preview_sprites_ctr = 0; }

void Ending_SetPaletteWriteText() {
  uint8 i;    // si
  uint16 v1;  // ax

  for (i = 30; (i & 0x80u) == 0; i -= 2) {
    if (*(uint16 *)&current_player)
      v1 = kLuigiPalette[i >> 1];
    else
      v1 = kMarioPalette[i >> 1];
    palette_mirror[(i >> 1) + 176] = v1;
  }
  ++update_entire_palette_flag;
  Ending_WriteText();
}

void Ending_WriteText() {
  uint16 v0;  // di
  uint16 v1;  // di
  uint16 i;   // si
  uint8 v3;   // al
  uint8 v4;   // [rsp+45h] [rbp-3h]

  layer3_xpos = 255;
  cutscene_toad_var0BA3 = 0;
  tm_mirror = 21;
  ts_mirror = 2;
  v4 = world_number;
  if (!sram_cutscene_heart_eyes_flag && player_hard_mode_flag)
    world_number = 12;
  R0_ = 4 * current_player;
  v0 = (uint8)((4 * current_player) | ((uint8)(world_number & 8) >> 2));
  world_number = v4;
  v1 = kEndingTextOffs[v0 >> 1];
  for (i = *(uint16 *)&vram_buffer1_offset;; ++i) {
    v3 = *((uint8 *)kEndingTextThankYou + v1);
    vram_buffer1[i + 1] = v3;
    if (v3 == 0xFF) break;
    ++v1;
  }
  *(uint16 *)&vram_buffer1_offset = i;
}

void CODE_04DBDA() {
  uint8 v0;  // al
  uint8 v1;  // si
  int8 v2;   // al

  if (!(uint8)cutscene_peach_var0F85) {
    v0 = sram_cutscene_heart_eyes_flag;
    if (sram_cutscene_heart_eyes_flag) v0 = current_player;
    v1 = cutscene_peach_var0F84++ | (8 * v0);
    if (cutscene_peach_var0F84 == 3) {
      obj_yspeed.enemy[0] = -1;
      obj_sub_yspeed.enemy[0] = 0;
    }
    v2 = *((uint8 *)kDATA_04DC3F + v1);
    if (!v2) {
      ++game_mode_task;
      player_x_move_force = 0;
      obj_xspeed.player = 0;
    }
    LOBYTE(cutscene_peach_var0F85) = v2;
    HIBYTE(cutscene_peach_var0F85) = kDATA_04DC4F[v1];
  }
  LOBYTE(cutscene_peach_var0F85) = cutscene_peach_var0F85 - 1;
  buttons_a_b_previous = 16 * (HIBYTE(cutscene_peach_var0F85) & 8);
  if (scroll_lock) {
    if (obj_xpos_lo.player >= 0xA2u) obj_xpos_lo.player = -94;
  }
}

void ProcessPeachMovement() {
  if ((--cutscene_peach_state_timer & 0x80u) != 0) {
    if (++cutscene_peach_current_state == 5) obj_xpos_lo.player = -96;
    cutscene_peach_state_timer = kDATA_04DCB4[cutscene_peach_current_state];
  }
  R0_ = *((uint8 *)kDATA_04DC91 + (uint8)(2 * cutscene_peach_current_state));
  R1_ =
      *((uint8 *)kDATA_04DC91 + (uint8)(2 * cutscene_peach_current_state) + 1);
  switch ((uint8)(2 * cutscene_peach_current_state) >> 1) {
    case 0:
    case 1:
    case 2:
    case 5:
    case 6:
      return;
    case 3:
      goto LABEL_7;
    case 4:
      R0_ = 32;
      R2_ = 4;
      ImposeGravity_Far(1u, 0);
    LABEL_7:
      --obj_xpos_lo.enemy[0];
      break;
  }
}

void DrawLevelPreviewSprites_Sub7() {
  uint8 v0;     // al
  OamEnt *oam;  // rbp
  uint8 enemy;  // al
  uint8 v3;     // al
  OamEnt *v4;   // rdx

  v0 = rel_xpos_lo.enemy + 7;
  oam = get_OamEnt(oam_buf, 0);
  oam[44].xpos = rel_xpos_lo.enemy + 7;
  oam[45].xpos = v0;
  enemy = rel_ypos.enemy;
  oam[44].ypos = rel_ypos.enemy;
  oam[45].ypos = enemy + 16;
  if (cutscene_peach_current_state != 3 || (frame_counter & 4) != 0)
    v3 = kDATA_04DD4E[cutscene_peach_current_state];
  else
    v3 = kDATA_04DD4E[cutscene_peach_current_state] + 2;
  oam[44].charnum = v3;
  oam[45].charnum = v3 + 32;
  oam[44].flags = 37;
  oam[45].flags = 37;
  oam_tile_size_buffer[176] =
      (obj_xpos_hi.enemy[0] -
       (((uint8)(obj_xpos_lo.enemy[0] + 7) < (uint8)screen_left_xpos16) +
        HIBYTE(screen_left_xpos16))) |
      2;
  oam_tile_size_buffer[180] = oam_tile_size_buffer[176];
  v4 = get_OamEnt(oam_buf, floatey_numbers_oam_id);
  if (v4->charnum == 0xF6) {
    v4->ypos = -16;
    v4[1].ypos = -16;
  }
  if (enemy_id[9]) {
    oam[120].flags = 28;
    oam[121].flags = 28;
    oam[122].flags = 28;
    oam[123].flags = 28;
    oam[120].charnum = 0x80;
    oam[121].charnum = -127;
    oam[122].charnum = -112;
    oam[123].charnum = -111;
  }
}
// 7E03B9: using guessed type int8;

void Ending_SetGfxPtrToUpload() {
  uint8 v0;    // si
  int v1;  // rbp

  if (cutscene_peach_var0F83 < 0xAu) {
    v0 = cutscene_peach_var0F83++;
    graphics_upload_ptr.bank = kDATA_04DD87[v0];
    graphics_upload_size = 2048;
    v1 = (unsigned int)(v0 * 2) >> 1;
    graphics_upload_vramaddress = kDATA_04DDAF[v1];
    graphics_upload_ptr.addr = kDATA_04DD9B[v1];
    ++pausemenu_var3;
  }
}

void MaybeUnused_CODE_04DDC3() {
  uint8 v0;    // si
  int v1;  // rbp

  v0 = 2 * cutscene_peach_var0F83++;
  graphics_upload_ptr.bank = kDATA_04DDF1[v0];
  graphics_upload_size = 2048;
  v1 = v0 >> 1;
  graphics_upload_vramaddress = kDATA_04DE19[v1];
  graphics_upload_ptr.addr = kDATA_04DE05[v1];
  ++pausemenu_var3;
}

void SpawnMushroomDuringPeachCutscene() {
  enemy_id[9] = 46;
  enemy_state[9] = 0x80;
  enemy_flag[9] = 1;
  obj_xpos_hi.enemy[9] = obj_xpos_hi.player;
  obj_xpos_lo.enemy[9] = obj_xpos_lo.player;
  obj_ypos_hi.enemy[9] = 1;
  obj_ypos_lo.enemy[9] = 24;
  obj_xspeed.enemy[9] = 0;
  power_up_type = 0;
}
// 7E0067: using guessed type int8;
// 7E0082: using guessed type int8;
// 7E00C5: using guessed type int8;
// 7E0223: using guessed type int8;
// 7E0241: using guessed type int8;

void CODE_04DE54() {
  uint8 v0;  // [rsp+46h] [rbp-2h]
  uint8 v1;  // [rsp+47h] [rbp-1h]

  if (!sram_cutscene_heart_eyes_flag) {
    v1 = world_number;
    v0 = original_level;
    if (!player_hard_mode_flag) {
      original_level = 0;
      world_number = 0;
    }
    original_level = v0;
    world_number = v1;
  }
  cutscene_peach_var0F82 = 1;
  cutscene_peach_var0F83 = 0;
  title_screen_menu_var0717 = 0;
}

void PeachCutscene_04DE8B() {
  int v0;   // rbp
  uint16 v1;    // si
  uint16 v2;    // di
  OamEnt *v3;   // rbp
  uint16 v4;    // si
  uint8 v5;     // al
  uint16 v6;    // si
  uint16 v7;    // si
  OamEnt *v8;   // rbp
  uint16 v9;    // si
  uint8 v10;    // al
  uint16 v11;   // si
  OamEnt *v12;  // rbp
  uint8 v13;    // si
  int v14;  // rbp
  uint16 v15;   // si
  uint16 v16;   // di
  OamEnt *v17;  // rbp
  uint16 v18;   // si
  uint8 v19;    // al
  uint16 v20;   // si
  uint16 v21;   // si
  OamEnt *v22;  // rbp
  uint16 v23;   // si
  uint8 v24;    // al
  uint16 v25;   // si
  OamEnt *v26;  // rbp
  uint8 v27;    // si
  int v28;  // rbp
  uint16 v29;   // si
  uint16 v30;   // di
  OamEnt *oam;  // rbp
  uint16 v32;   // si
  uint8 v33;    // al
  uint16 v34;   // si
  uint16 v35;   // si
  OamEnt *v36;  // rbp
  uint16 v37;   // si
  uint8 v38;    // al
  uint16 v39;   // si
  OamEnt *v40;  // rbp
  uint8 v41;    // si

  if (sram_cutscene_heart_eyes_flag) {
    if (world_number >= 8u) {
      CutsceneHdma();
      if (cutscene_peach_var0F81 >=
          kDATA_04E276[cutscene_peach_close_up_animation_frame]) {
        cutscene_peach_var0F81 = 0;
        if (++cutscene_peach_close_up_animation_frame >= 9u) {
          if (cutscene_peach_close_up_animation_frame == 9)
            cutscene_peach_var0F89 = 0;
          cutscene_peach_close_up_animation_frame = 9;
        }
      }
      ++cutscene_peach_var0F81;
      v28 = (uint8)(2 * cutscene_peach_close_up_animation_frame) >> 1;
      *(uint16 *)&tempED = kDATA_04E2E6[v28];
      v29 = kDATA_04E2A0[v28];
      v30 = 4;
      while (*((uint8 *)kDATA_04E2FA + v29) != 0xFF) {
        oam = get_OamEnt(oam_buf, v30);
        oam->ypos = *((uint8 *)kDATA_04E2FA + v29) + 0x80;
        v32 = v29 + 1;
        oam->xpos = *((uint8 *)kDATA_04E2FA + v32++) - 64;
        v33 = *((uint8 *)kDATA_04E2FA + v32);
        oam->charnum = v33;
        v34 = v32 + 1;
        R0_ = 0;
        if (v33 < 0x80u) R0_ = current_player;
        oam->flags = R0_ | *((uint8 *)kDATA_04E2FA + v34) | 0x20;
        v29 = v34 + 1;
        oam_tile_size_buffer[v30] = 2;
        v30 += 4;
      }
      v35 = *(uint16 *)&tempED;
      while (*((uint8 *)kDATA_04E2FA + v35) != 0xFF) {
        v36 = get_OamEnt(oam_buf, v30);
        v36->ypos = *((uint8 *)kDATA_04E2FA + v35) + 0x80;
        v37 = v35 + 1;
        v36->xpos = current_player + current_player + current_player +
                    current_player + *((uint8 *)kDATA_04E2FA + v37++) - 64;
        v38 = *((uint8 *)kDATA_04E2FA + v37);
        v36->charnum = v38;
        v39 = v37 + 1;
        R0_ = 0;
        if (v38 < 0x80u) R0_ = current_player;
        v36->flags = R0_ | *((uint8 *)kDATA_04E2FA + v39) | 0x20;
        v35 = v39 + 1;
        oam_tile_size_buffer[v30] = 2;
        v30 += 4;
      }
      if (cutscene_peach_close_up_animation_frame == 9) {
        DrawToadAndRelatedSprites_Func16();
        v40 = get_OamEnt(oam_buf, 0);
        v40->xpos = kDATA_04E259[(cutscene_peach_var0F89 >> 3) & 3] - 80;
        R0_ = cutscene_peach_var0F89 >> 2;
        v40->ypos = 96 - (cutscene_peach_var0F89 >> 2);
        v41 = (cutscene_peach_var0F89 >> 5) & 3;
        v40->charnum = kDATA_04E255[v41];
        v40->flags = 38;
        oam_tile_size_buffer[0] = 0;
        ++cutscene_peach_var0F89;
        if (v41 == 3) cutscene_peach_var0F89 = 0;
      }
    } else {
      CutsceneHdma();
      if (cutscene_peach_var0F81 >=
          kDATA_04E266[cutscene_peach_close_up_animation_frame]) {
        cutscene_peach_var0F81 = 0;
        if (++cutscene_peach_close_up_animation_frame == 5)
          cutscene_peach_var0F89 = 0;
        if (cutscene_peach_close_up_animation_frame >= 0xFu)
          cutscene_peach_close_up_animation_frame = 6;
      }
      ++cutscene_peach_var0F81;
      v14 = (uint8)(2 * cutscene_peach_close_up_animation_frame) >> 1;
      *(uint16 *)&tempED = kDATA_04E2C6[v14];
      v15 = kDATA_04E280[v14];
      v16 = 4;
      while (*((uint8 *)kDATA_04E2FA + v15) != 0xFF) {
        v17 = get_OamEnt(oam_buf, v16);
        v17->ypos = *((uint8 *)kDATA_04E2FA + v15) + 0x80;
        v18 = v15 + 1;
        v17->xpos = *((uint8 *)kDATA_04E2FA + v18++) - 64;
        v19 = *((uint8 *)kDATA_04E2FA + v18);
        v17->charnum = v19;
        v20 = v18 + 1;
        R0_ = 0;
        if (v19 < 0x80u) R0_ = current_player;
        v17->flags = R0_ | *((uint8 *)kDATA_04E2FA + v20) | 0x20;
        v15 = v20 + 1;
        oam_tile_size_buffer[v16] = 2;
        v16 += 4;
      }
      v21 = *(uint16 *)&tempED;
      while (*((uint8 *)kDATA_04E2FA + v21) != 0xFF) {
        v22 = get_OamEnt(oam_buf, v16);
        v22->ypos = *((uint8 *)kDATA_04E2FA + v21) + 0x80;
        v23 = v21 + 1;
        v22->xpos = current_player + current_player + current_player +
                    current_player + *((uint8 *)kDATA_04E2FA + v23++) - 64;
        v24 = *((uint8 *)kDATA_04E2FA + v23);
        v22->charnum = v24;
        v25 = v23 + 1;
        R0_ = 0;
        if (v24 < 0x80u) R0_ = current_player;
        v22->flags = R0_ | *((uint8 *)kDATA_04E2FA + v25) | 0x20;
        v21 = v25 + 1;
        oam_tile_size_buffer[v16] = 2;
        v16 += 4;
      }
      if (cutscene_peach_close_up_animation_frame >= 6u) {
        DrawToadAndRelatedSprites_Func16();
        v26 = get_OamEnt(oam_buf, 0);
        v26->xpos = kDATA_04E259[(cutscene_peach_var0F89 >> 3) & 3] - 80;
        R0_ = cutscene_peach_var0F89 >> 2;
        v26->ypos = 96 - (cutscene_peach_var0F89 >> 2);
        v27 = (cutscene_peach_var0F89 >> 5) & 3;
        v26->charnum = kDATA_04E255[v27];
        v26->flags = 38;
        oam_tile_size_buffer[0] = 0;
        ++cutscene_peach_var0F89;
        if (v27 == 3) cutscene_peach_var0F89 = 0;
      }
    }
  } else {
    CutsceneHdma();
    if (cutscene_peach_var0F81 >=
        kDATA_04E25D[cutscene_peach_close_up_animation_frame]) {
      cutscene_peach_var0F81 = 0;
      if (++cutscene_peach_close_up_animation_frame >= 8u) {
        if (cutscene_peach_close_up_animation_frame == 8)
          cutscene_peach_var0F89 = 0;
        cutscene_peach_close_up_animation_frame = 8;
      }
    }
    ++cutscene_peach_var0F81;
    v0 = (uint8)(2 * cutscene_peach_close_up_animation_frame) >> 1;
    *(uint16 *)&tempED = kDATA_04E2B4[v0];
    v1 = kDATA_04E280[v0];
    v2 = 4;
    while (*((uint8 *)kDATA_04E2FA + v1) != 0xFF) {
      v3 = get_OamEnt(oam_buf, v2);
      v3->ypos = *((uint8 *)kDATA_04E2FA + v1) + 0x80;
      v4 = v1 + 1;
      v3->xpos = *((uint8 *)kDATA_04E2FA + v4++) - 64;
      v5 = *((uint8 *)kDATA_04E2FA + v4);
      v3->charnum = v5;
      v6 = v4 + 1;
      R0_ = 0;
      if (v5 < 0x80u) R0_ = current_player;
      v3->flags = R0_ | *((uint8 *)kDATA_04E2FA + v6) | 0x20;
      v1 = v6 + 1;
      oam_tile_size_buffer[v2] = 2;
      v2 += 4;
    }
    v7 = *(uint16 *)&tempED;
    while (*((uint8 *)kDATA_04E2FA + v7) != 0xFF) {
      v8 = get_OamEnt(oam_buf, v2);
      v8->ypos = *((uint8 *)kDATA_04E2FA + v7) + 0x80;
      v9 = v7 + 1;
      v8->xpos = current_player + current_player + current_player +
                 current_player + *((uint8 *)kDATA_04E2FA + v9++) - 64;
      v10 = *((uint8 *)kDATA_04E2FA + v9);
      v8->charnum = v10;
      v11 = v9 + 1;
      R0_ = 0;
      if (v10 < 0x80u) R0_ = current_player;
      v8->flags = R0_ | *((uint8 *)kDATA_04E2FA + v11) | 0x20;
      v7 = v11 + 1;
      oam_tile_size_buffer[v2] = 2;
      v2 += 4;
    }
    if (cutscene_peach_close_up_animation_frame == 8) {
      DrawToadAndRelatedSprites_Func16();
      v12 = get_OamEnt(oam_buf, 0);
      v12->xpos = kDATA_04E259[(cutscene_peach_var0F89 >> 3) & 3] - 80;
      R0_ = cutscene_peach_var0F89 >> 2;
      v12->ypos = 96 - (cutscene_peach_var0F89 >> 2);
      v13 = (cutscene_peach_var0F89 >> 5) & 3;
      v12->charnum = kDATA_04E255[v13];
      v12->flags = 38;
      oam_tile_size_buffer[0] = 0;
      ++cutscene_peach_var0F89;
      if (v13 == 3) cutscene_peach_var0F89 = 0;
    }
  }
  PeachCutscene_04E221();
}

void PeachCutscene_04E221() {
  OamEnt *oam;  // rdx
  uint8 v1;     // al

  if (current_player) {
    oam = get_OamEnt(oam_buf, 0);
    if (oam[1].charnum == 0xEE) {
      v1 = oam[1].xpos - 2;
      oam[1].xpos = v1;
      oam[2].xpos = v1;
      oam[1].charnum = -126;
      oam[2].charnum = -125;
      oam[2].xpos = oam[1].xpos + 8;
      oam[3].charnum = -123;
      oam[4].charnum = -119;
    }
  }
}

void CutsceneBowserDefeat_04ECCA() {
  uint16 v0;  // ax

  graphics_upload_ptr.bank = 4;
  graphics_upload_size = 2048;
  graphics_upload_vramaddress = 30720;
  if (world_number == 7)
    v0 = -12288;
  else
    v0 = -16384;
  graphics_upload_ptr.addr = v0;
  cutscene_rustling_bag_animation_frame = 0;
  cutscene_toad_popped_out_of_bag_flag = 0;
  cutscene_wait_before_toad_breaks_out_of_bag = 0;
  cutscene_toad_has_been_initialized_flag = 0;
  pausemenu_var3 = 2;
}

void CutsceneToad_04ED07() {
  graphics_upload_ptr.bank = 4;
  graphics_upload_size = 2048;
  graphics_upload_vramaddress = 31744;
  graphics_upload_ptr.addr = kDATA_04ED5A[(uint8)(2 * world_number) >> 1];
}

void UploadSpriteGFX() {
  WriteReg(VMAIN, 0x80u);
  WriteRegWord(VMADDL, 0x6000u);
  WriteRegWord(DMAP0, 0x1801u);
  WriteRegWord(A1T0L, 0x8000u);
  WriteReg(A1B0, 4u);
  WriteRegWord(DAS0L, 0x4000u);
  WriteReg(MDMAEN, 1u);
}

void DrawToadAndRelatedSprites(uint8 k) {
  uint8 v1;     // al
  int8 v2;      // al
  OamEnt *v3;   // rbp
  uint8 v4;     // al
  OamEnt *oam;  // rbp
  uint8 v6;     // si

  if (cutscene_toad_popped_out_of_bag_flag) {
    v6 = world_number;
    if (!cutscene_toad_has_been_initialized_flag)
      DrawToadAndRelatedSprites_Func13();
    R0_ = kDATA_04EE45[v6];
    R1_ = HIBYTE(kDATA_04EE45[v6]);
    funcs_1948B[(unsigned int)(v6 * 2) >> 1]();
  } else {
    if ((frame_counter & 7) != 0) {
      v1 = cutscene_rustling_bag_animation_frame;
    } else {
      v1 = ++cutscene_rustling_bag_animation_frame;
      if (cutscene_rustling_bag_animation_frame >= 3u) {
        if (((random_byte4 ^ random_byte3) & 1) != 0) {
          v1 = 0;
          cutscene_rustling_bag_animation_frame = 0;
        } else {
          cutscene_rustling_bag_animation_frame = 3;
          v1 = 1;
        }
      }
    }
    R0_ = v1;
    DrawToadAndRelatedSprites_Func14(
        0, PAIR16(obj_xpos_hi.enemy[0], obj_xpos_lo.enemy[0]));
    DrawToadAndRelatedSprites_Func14(
        4, PAIR16(obj_xpos_hi.enemy[0], obj_xpos_lo.enemy[0]) + 8);
    if (R0_ == 2) {
      oam = get_OamEnt(oam_buf, 0);
      oam[64].charnum = -122;
      oam[65].charnum = -121;
      oam[66].charnum = -106;
      oam[67].charnum = -105;
      oam[64].ypos = -72;
      oam[65].ypos = -72;
      oam[66].ypos = -64;
      oam[67].ypos = -64;
    } else {
      if (R0_)
        v2 = 0x80;
      else
        v2 = -125;
      v3 = get_OamEnt(oam_buf, 0);
      v3[64].charnum = v2;
      v4 = v2 + 1;
      v3[65].charnum = v4;
      v4 += 31;
      v3[66].charnum = v4;
      v3[67].charnum = v4 + 1;
      v3[64].ypos = -80;
      v3[65].ypos = -80;
      v3[66].ypos = -64;
      v3[67].ypos = -64;
    }
  }
}
// 19498: using guessed type int (*funcs_19490[13])();

void CutsceneToad_Func0() {
  uint8 v0;  // al

  DrawToadAndRelatedSprites_Func12();
  if (cutscene_wait_before_toad_breaks_out_of_bag) {
    if (cutscene_wait_before_toad_breaks_out_of_bag == 3 && !cutscene_var0B9F) {
      DrawToadAndRelatedSprites_Func18();
      R0_ = 32;
      R2_ = 4;
      ImposeGravity_Far(1u, 0);
      v0 = obj_ypos_lo.enemy[0];
      if (obj_ypos_lo.enemy[0] < 0xB0u) {
        cutscene_var0B9D_oam_id = 1;
        v0 = obj_ypos_lo.enemy[0];
      }
      if (v0 >= 0xB8u) {
        obj_ypos_lo.enemy[0] = -72;
        obj_yspeed.enemy[0] = -2;
        obj_sub_yspeed.enemy[0] = 0;
        obj_sub_ypos.enemy[0] = 0;
        cutscene_var0B9E = 0;
        cutscene_var0B9F = 24;
        cutscene_var0BA4 = 0;
        DrawToadAndRelatedSprites_Func15();
      }
    }
    if (cutscene_var0B9F)
      --cutscene_var0B9F;
    else
      cutscene_var0B9E = 1;
    R0_ = rel_xpos_lo.enemy;
    R1_ = obj_ypos_lo.enemy[0];
    DrawToadAndRelatedSprites_Func11(kDATA_04EE5F[cutscene_var0B9D_oam_id],
                                     cutscene_var0B9E);
    DrawToadAndRelatedSprites_Func10();
  } else {
    DrawToadAndRelatedSprites_Func10();
  }
}

void CutsceneToad_Func1() {
  uint8 v0;  // al
  uint8 v1;  // di
  uint8 v2;  // di
  uint8 v3;  // al

  DrawToadAndRelatedSprites_Func12();
  if (!cutscene_wait_before_toad_breaks_out_of_bag) {
    DrawToadAndRelatedSprites_Func10();
    return;
  }
  if (cutscene_wait_before_toad_breaks_out_of_bag == 3) {
    if (!cutscene_var0B9F) {
      if (cutscene_toad_has_been_initialized_flag == 2) {
        cutscene_var0B9E = cutscene_toad_has_been_initialized_flag;
        goto LABEL_12;
      }
      DrawToadAndRelatedSprites_Func18();
      cutscene_var0B9E = 1;
      R0_ = 32;
      R2_ = 4;
      ImposeGravity_Far(1u, 0);
      v0 = obj_ypos_lo.enemy[0];
      if (obj_ypos_lo.enemy[0] < 0xB0u) {
        cutscene_var0B9D_oam_id = 1;
        v0 = obj_ypos_lo.enemy[0];
      }
      if (v0 < 0xB8u) goto LABEL_12;
      obj_ypos_lo.enemy[0] = -72;
      obj_yspeed.enemy[0] = 0;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.enemy[0] = 0;
      cutscene_var0B9F = 40;
      cutscene_toad_has_been_initialized_flag = 2;
      cutscene_var0B9E = 0;
    }
    --cutscene_var0B9F;
  }
LABEL_12:
  R0_ = rel_xpos_lo.enemy;
  R1_ = obj_ypos_lo.enemy[0];
  v1 = kDATA_04EE5F[cutscene_var0B9D_oam_id];
  DrawToadAndRelatedSprites_Func11(v1, cutscene_var0B9E);
  v2 = v1 + 16;
  R0_ = rel_xpos_lo.enemy + 16;
  v3 = cutscene_var0B9E;
  if (cutscene_var0B9E == 2) {
    DrawToadAndRelatedSprites_Func15();
    v3 = 3;
  }
  DrawToadAndRelatedSprites_Func11(v2, v3);
  DrawToadAndRelatedSprites_Func10();
}

void CutsceneToad_Func2() {
  DrawToadAndRelatedSprites_Func12();
  if (!cutscene_wait_before_toad_breaks_out_of_bag) {
    DrawToadAndRelatedSprites_Func10();
    return;
  }
  if (cutscene_wait_before_toad_breaks_out_of_bag != 3) goto LABEL_21;
  if (cutscene_var0BA0 < 0x28u) {
  LABEL_20:
    ++cutscene_var0BA0;
  LABEL_21:
    R0_ = rel_xpos_lo.enemy;
    R1_ = obj_ypos_lo.enemy[0];
    DrawToadAndRelatedSprites_Func11(kDATA_04EE5F[cutscene_var0B9D_oam_id],
                                     cutscene_var0B9E);
    DrawToadAndRelatedSprites_Func10();
    return;
  }
  if (cutscene_var0BA0 < 0x50u) {
    if (cutscene_var0BA0 < 0x2Cu) {
      CODE_04F124(0xA0u);
    } else if (cutscene_var0BA0 < 0x30u) {
      CODE_04F0ED(0xA0u);
    } else {
      CODE_04F091(0xA0u);
    }
    goto LABEL_20;
  }
  if (cutscene_var0BA0 >= 0x58u) {
    DrawToadAndRelatedSprites_Func18();
    R0_ = 32;
    R2_ = 4;
    ImposeGravity_Far(1u, 0);
    cutscene_var0B9E = 1;
    if (obj_ypos_lo.enemy[0] >= 0xB0u) {
      if (obj_ypos_lo.enemy[0] >= 0xB8u) {
        obj_yspeed.enemy[0] = 0;
        obj_sub_yspeed.enemy[0] = 0;
        obj_sub_ypos.enemy[0] = 0;
        obj_ypos_lo.enemy[0] = -72;
        cutscene_var0B9E = 0;
        cutscene_var0B9F = 1;
        DrawToadAndRelatedSprites_Func15();
      }
    } else {
      cutscene_var0B9D_oam_id = 1;
    }
    if (!cutscene_var0B9F && (frame_counter & 1) == 0) ++obj_xpos_lo.enemy[3];
  }
  CODE_04F031();
  DrawToadAndRelatedSprites_Func10();
}
// 7E021D: using guessed type int8;

void CODE_04F031() {
  uint8 v0;  // di
  uint8 v1;  // di
  uint8 v2;  // al
  uint8 v3;  // di
  uint8 v4;  // al

  R0_ = rel_xpos_lo.enemy;
  R1_ = obj_ypos_lo.enemy[0];
  v0 = kDATA_04EE5F[cutscene_var0B9D_oam_id];
  DrawToadAndRelatedSprites_Func11(v0, cutscene_var0B9E);
  v1 = v0 + 16;
  R0_ = rel_xpos_lo.enemy - obj_xpos_lo.enemy[3] - 7;
  v2 = cutscene_var0B9F - 1;
  if (cutscene_var0B9F != 1) v2 = cutscene_var0B9E + 4;
  DrawToadAndRelatedSprites_Func11(v1, v2);
  v3 = v1 + 16;
  R0_ = obj_xpos_lo.enemy[3] + rel_xpos_lo.enemy + 7;
  v4 = cutscene_var0B9F - 1;
  if (cutscene_var0B9F != 1) v4 = cutscene_var0B9E + 6;
  DrawToadAndRelatedSprites_Func11(v3, v4);
  if ((cutscene_var0BA0 & 0x80u) == 0) ++cutscene_var0BA0;
}

void CODE_04F091(uint8 j) {
  uint8 v1;     // al
  OamEnt *oam;  // rbp
  int8 v3;      // al
  int8 v4;      // al

  v1 = obj_ypos_lo.enemy[0] + 1;
  oam = get_OamEnt(oam_buf, j);
  oam[65].ypos = obj_ypos_lo.enemy[0] + 1;
  oam[67].ypos = v1;
  v1 += 7;
  oam[64].ypos = v1;
  oam[66].ypos = v1;
  v3 = rel_xpos_lo.enemy - 13;
  oam[65].xpos = rel_xpos_lo.enemy - 13;
  oam[64].xpos = v3 - 1;
  v4 = rel_xpos_lo.enemy + 13;
  oam[67].xpos = rel_xpos_lo.enemy + 13;
  oam[66].xpos = v4 + 1;
  oam[65].charnum = -32;
  oam[67].charnum = -32;
  oam[64].charnum = -50;
  oam[66].charnum = -50;
  oam[66].flags = 45;
  oam[67].flags = 45;
  oam[64].flags = 109;
  oam[65].flags = 109;
  oam_tile_size_buffer[j + 256] = 2;
  oam_tile_size_buffer[j + 260] = 2;
  oam_tile_size_buffer[j + 264] = 2;
  oam_tile_size_buffer[j + 268] = 2;
}

void CODE_04F0ED(uint8 j) {
  OamEnt *oam;  // rbp
  uint8 v2;     // al

  oam = get_OamEnt(oam_buf, j);
  oam[64].xpos = rel_xpos_lo.enemy - 9;
  oam[65].xpos = rel_xpos_lo.enemy + 9;
  v2 = obj_ypos_lo.enemy[0] + 1;
  oam[64].ypos = obj_ypos_lo.enemy[0] + 1;
  oam[65].ypos = v2;
  oam[64].charnum = -32;
  oam[65].charnum = -32;
  oam[64].flags = 109;
  oam[65].flags = 45;
  oam_tile_size_buffer[j + 256] = 2;
  oam_tile_size_buffer[j + 260] = 2;
}

void CODE_04F124(uint8 j) {
  OamEnt *oam;  // rbp
  uint8 v2;     // al

  oam = get_OamEnt(oam_buf, j);
  oam[64].xpos = rel_xpos_lo.enemy - 5;
  oam[65].xpos = rel_xpos_lo.enemy + 5;
  v2 = obj_ypos_lo.enemy[0];
  oam[64].ypos = obj_ypos_lo.enemy[0];
  oam[65].ypos = v2;
  oam[64].charnum = -32;
  oam[65].charnum = -32;
  oam[64].flags = 109;
  oam[65].flags = 45;
  oam_tile_size_buffer[j + 256] = 2;
  oam_tile_size_buffer[j + 260] = 2;
}

void CutsceneToad_Func3() {
  uint8 v0;  // al
  int8 v1;   // si
  uint8 v2;  // di

  DrawToadAndRelatedSprites_Func12();
  if (cutscene_wait_before_toad_breaks_out_of_bag) {
    if (++cutscene_var0B9F >= 0xC0u) {
      cutscene_var0B9F = -64;
      cutscene_toad_has_been_initialized_flag = 2;
      cutscene_arr0BB8[0] = 1;
      cutscene_arr0BB8[1] = 1;
      cutscene_arr0BB8[2] = 1;
      cutscene_arr0BB8[3] = 1;
    }
    var0E67 = 0;
    if (cutscene_arr0BB4[0]) {
      if (cutscene_var0BA1) {
        --cutscene_var0BA1;
        v0 = 0;
      } else {
        DrawToadAndRelatedSprites_Func15();
        v0 = 2;
      }
      cutscene_var0B9E = v0;
      v1 = 3;
      v2 = 0;
      do {
        R0_ = cutscene_arr0BB0[(uint8)v1];
        R1_ = -72;
        DrawToadAndRelatedSprites_Func11(v2, cutscene_var0B9E);
        v2 += 16;
        var0E67 = v2;
        --v1;
      } while (v1 >= 0);
    } else if (cutscene_toad_has_been_initialized_flag == 2) {
      CODE_04F1D7();
    } else {
      CODE_04F2AB();
    }
  }
  DrawToadAndRelatedSprites_Func10();
}

void CODE_04F1D7() {
  uint8 v0;  // di
  uint8 v1;  // al
  uint8 v2;  // al
  uint8 v3;  // di
  uint8 v4;  // al
  uint8 v5;  // di
  uint8 v6;  // al

  DrawToadAndRelatedSprites_Func18();
  R0_ = 32;
  R2_ = 4;
  ImposeGravity_Far(1u, 0);
  if (obj_ypos_lo.enemy[0] < 0xB0u) cutscene_var0B9D_oam_id = 1;
  v0 = kDATA_04EE5F[cutscene_var0B9D_oam_id];
  R0_ = rel_xpos_lo.enemy;
  v1 = obj_ypos_lo.enemy[0];
  if (obj_ypos_lo.enemy[0] >= 0xB8u) {
    v1 = -72;
    cutscene_arr0BB8[0] = 0;
  }
  R1_ = v1;
  DrawToadAndRelatedSprites_Func11(v0, cutscene_arr0BB8[0]);
  R0_ = cutscene_arr0BB0[1];
  if ((uint8)(obj_ypos_lo.enemy[0] - 12) < 0xB8u) {
    if (frame_counter & 1) ++cutscene_arr0BB0[1];
    v2 = obj_ypos_lo.enemy[0] - 12;
  } else {
    v2 = -72;
    cutscene_arr0BB8[1] = 0;
  }
  R1_ = v2;
  v3 = v0 + 16;
  DrawToadAndRelatedSprites_Func11(v3, cutscene_arr0BB8[1] + 6);
  R0_ = cutscene_arr0BB0[2];
  v4 = obj_ypos_lo.enemy[0] - 24;
  if ((uint8)(obj_ypos_lo.enemy[0] - 24) < 0xB8u) {
    --cutscene_arr0BB0[2];
  } else {
    v4 = -72;
    cutscene_arr0BB8[2] = 0;
  }
  R1_ = v4;
  v5 = v3 + 16;
  DrawToadAndRelatedSprites_Func11(v5, cutscene_arr0BB8[2] + 4);
  R0_ = cutscene_arr0BB0[3];
  v6 = obj_ypos_lo.enemy[0] - 36;
  if ((uint8)(obj_ypos_lo.enemy[0] - 36) < 0xB8u) {
    ++cutscene_arr0BB0[3];
  } else {
    cutscene_arr0BB8[3] = 0;
    ++cutscene_arr0BB4[0];
    cutscene_var0BA1 = 40;
    v6 = obj_ypos_lo.enemy[0] - 36;
  }
  R1_ = v6;
  DrawToadAndRelatedSprites_Func11(v5 + 16, cutscene_arr0BB8[3] + 6);
}

void CODE_04F2AB() {
  uint8 v0;     // di
  uint8 i;      // si
  OamEnt *oam;  // rbp
  OamEnt *v3;   // rbx
  uint8 j;      // si
  uint8 v5;     // si

  v0 = -80;
  for (i = 0; i < 9u; ++i) {
    oam = get_OamEnt(oam_buf, v0);
    oam[64].xpos = rel_xpos_lo.enemy;
    oam[64].ypos = kDATA_04F38F[i];
    oam[64].charnum = HIBYTE(kDATA_04F38F[i]);
    oam[64].flags = 45;
    oam_tile_size_buffer[v0 + 256] = 2;
    v0 += 4;
  }
  v3 = get_OamEnt(oam_buf, 0);
  v3[112].flags = 109;
  oam_tile_size_buffer[448] = 0;
  oam_tile_size_buffer[444] = 0;
  v3[112].xpos = v3[111].xpos + 8;
  for (j = 0; j != 6; ++j) {
    if (kDATA_04F388[j] >= cutscene_var0B9F) break;
  }
  v5 = j;
  R0_ = kDATA_04F37A[v5];
  R1_ = HIBYTE(kDATA_04F37A[v5]);
  switch ((unsigned int)(v5 * 2) >> 1) {
    case 0u:
      oam_tile_size_buffer[432] = 1;
      oam_tile_size_buffer[436] = 1;
      oam_tile_size_buffer[440] = 1;
      oam_tile_size_buffer[456] = 1;
      oam_tile_size_buffer[460] = 1;
      oam_tile_size_buffer[464] = 1;
      break;
    case 1u:
      oam_tile_size_buffer[432] = 1;
      oam_tile_size_buffer[436] = 1;
      oam_tile_size_buffer[440] = 1;
      oam_tile_size_buffer[460] = 1;
      oam_tile_size_buffer[464] = 1;
      sound_ch1 = 9;
      break;
    case 2u:
      oam_tile_size_buffer[432] = 1;
      oam_tile_size_buffer[436] = 1;
      oam_tile_size_buffer[456] = 1;
      oam_tile_size_buffer[460] = 1;
      oam_tile_size_buffer[464] = 1;
      break;
    case 3u:
      oam_tile_size_buffer[432] = 1;
      oam_tile_size_buffer[436] = 1;
      oam_tile_size_buffer[456] = 1;
      oam_tile_size_buffer[464] = 1;
      sound_ch1 = 9;
      break;
    case 4u:
      oam_tile_size_buffer[432] = 1;
      oam_tile_size_buffer[456] = 1;
      oam_tile_size_buffer[460] = 1;
      oam_tile_size_buffer[464] = 1;
      break;
    case 5u:
      oam_tile_size_buffer[432] = 1;
      oam_tile_size_buffer[456] = 1;
      oam_tile_size_buffer[460] = 1;
      sound_ch1 = 9;
      break;
    case 6u:
      oam_tile_size_buffer[456] = 1;
      oam_tile_size_buffer[460] = 1;
      oam_tile_size_buffer[464] = 1;
      break;
  }
}

void CutsceneToad_Func4() {
  uint8 v0;  // al

  DrawToadAndRelatedSprites_Func12();
  if (cutscene_wait_before_toad_breaks_out_of_bag) {
    DrawToadAndRelatedSprites_Func18();
    R0_ = 32;
    R2_ = 4;
    ImposeGravity_Far(1u, 0);
    if (obj_ypos_lo.enemy[0] < 0xA0u) cutscene_var0B9D_oam_id = 1;
    if (obj_ypos_lo.enemy[0] >= 0xB0u) {
      obj_ypos_lo.enemy[0] = -80;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.player = 0;
      v0 = ++cutscene_var0B9E;
      if ((cutscene_var0B9E & 0x80u) == 0) {
        v0 = 0;
        cutscene_var0B9E = 0;
      }
      obj_yspeed.enemy[0] = v0;
    }
    if (++cutscene_var0B9F < 0x44u) {
      CODE_04F586();
      DrawToadAndRelatedSprites_Func10();
    } else {
      if (cutscene_var0B9F == 68) sound_ch1 = 8;
      cutscene_var0B9F = 69;
      CODE_04F412();
      DrawToadAndRelatedSprites_Func15();
      DrawToadAndRelatedSprites_Func10();
    }
  } else {
    DrawToadAndRelatedSprites_Func10();
  }
}

void CODE_04F412() {
  uint8 v0;     // al
  OamEnt *oam;  // rdx
  uint8 v2;     // al
  uint8 v3;     // al
  uint8 v4;     // al
  uint8 v5;     // al
  uint8 i;      // si
  uint8 v7;     // al
  uint8 v8;     // si
  uint8 v9;     // di
  uint8 j;      // si
  OamEnt *v11;  // rbp

  R0_ = cutscene_var0B9F + rel_xpos_lo.enemy;
  v0 = cutscene_var0B9F + rel_xpos_lo.enemy + 6;
  oam = get_OamEnt(oam_buf, 0);
  oam[64].xpos = v0;
  oam[65].xpos = v0 + 16;
  v2 = R0_;
  oam[68].xpos = R0_;
  oam[70].xpos = v2;
  oam[69].xpos = v2 + 8;
  v3 = R0_ + 28;
  oam[72].xpos = R0_ + 28;
  oam[74].xpos = v3;
  oam[73].xpos = v3 + 8;
  v4 = R0_ + 6;
  oam[76].xpos = R0_ + 6;
  oam[78].xpos = v4;
  oam[77].xpos = v4 + 8;
  v5 = R0_ + 22;
  oam[80].xpos = R0_ + 22;
  oam[82].xpos = v5;
  oam[81].xpos = v5 + 8;
  oam[68].ypos = -72;
  oam[69].ypos = -72;
  oam[72].ypos = -72;
  oam[73].ypos = -72;
  oam[76].ypos = -72;
  oam[77].ypos = -72;
  oam[80].ypos = -72;
  oam[81].ypos = -72;
  oam[64].ypos = -64;
  oam[65].ypos = -64;
  oam[70].ypos = -64;
  oam[74].ypos = -64;
  oam[78].ypos = -64;
  oam[82].ypos = -64;
  oam[68].charnum = -66;
  oam[73].charnum = -66;
  oam[69].charnum = -65;
  oam[72].charnum = -65;
  oam[70].charnum = -20;
  oam[74].charnum = -20;
  oam[64].charnum = -22;
  oam[65].charnum = -22;
  oam[76].charnum = -74;
  oam[77].charnum = -74;
  oam[80].charnum = -74;
  oam[81].charnum = -74;
  oam[78].charnum = -55;
  oam[82].charnum = -55;
  oam[64].flags = 45;
  oam[68].flags = 45;
  oam[69].flags = 45;
  oam[70].flags = 45;
  oam[76].flags = 45;
  oam[78].flags = 45;
  oam[80].flags = 45;
  oam[82].flags = 45;
  oam[65].flags = 109;
  oam[72].flags = 109;
  oam[73].flags = 109;
  oam[74].flags = 109;
  oam[77].flags = 109;
  oam[81].flags = 109;
  oam_tile_size_buffer[256] = 2;
  oam_tile_size_buffer[260] = 2;
  oam_tile_size_buffer[280] = 2;
  oam_tile_size_buffer[296] = 2;
  oam_tile_size_buffer[312] = 2;
  oam_tile_size_buffer[328] = 2;
  for (i = 3; (i & 0x80u) == 0; --i) {
    v7 = cutscene_arr0BB8[i];
    if (v7) {
      if (v7 < 0x1Eu)
        ++cutscene_arr0BB8[i];
      else
        cutscene_arr0BB8[i] = 0;
    }
  }
  if ((frame_counter & 7) == 0) {
    v8 = 3;
    do {
      if (!cutscene_arr0BB8[v8]) break;
      --v8;
    } while (v8);
    v9 = frame_counter & 3;
    cutscene_arr0BB0[v8] =
        ((frame_counter ^ *(&random_byte3 + (frame_counter & 3))) & 0x1F) - 52;
    cutscene_arr0BB4[v8] = ((frame_counter ^ *(&random_byte4 + v9)) & 7) - 80;
    ++cutscene_arr0BB8[v8];
  }
  for (j = 3; (j & 0x80u) == 0; --j) {
    R0_ = kDATA_04F582[cutscene_arr0BB8[j] >> 3];
    v11 = get_OamEnt(oam_buf, (uint8)(4 * j));
    v11->xpos = cutscene_arr0BB0[j];
    v11->ypos = cutscene_arr0BB4[j];
    v11->charnum = R0_;
    v11->flags = 37;
  }
}

void CODE_04F586() {
  uint8 v0;     // di
  uint8 v1;     // al
  OamEnt *oam;  // rdx
  uint8 v3;     // al
  uint8 v4;     // si
  OamEnt *v5;   // rbp

  v0 = kDATA_04EE5F[cutscene_var0B9D_oam_id];
  v1 = cutscene_var0B9F + rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, v0);
  oam[64].xpos = cutscene_var0B9F + rel_xpos_lo.enemy;
  oam[66].xpos = v1;
  v1 += 16;
  oam[65].xpos = v1;
  oam[67].xpos = v1;
  v3 = obj_ypos_lo.enemy[0];
  oam[64].ypos = obj_ypos_lo.enemy[0];
  oam[65].ypos = v3;
  v3 += 16;
  oam[66].ypos = v3;
  oam[67].ypos = v3;
  v4 = cutscene_var0B9F & 0xC;
  R0_ = 4;
  do {
    v5 = get_OamEnt(oam_buf, v0);
    v5[64].charnum = kDATA_04F5DA[v4];
    v5[64].flags = kDATA_04F5EA[v4];
    oam_tile_size_buffer[v0 + 256] = 2;
    v0 += 4;
    ++v4;
    --R0_;
  } while (R0_);
}

void CutsceneToad_Func5() {
  DrawToadAndRelatedSprites_Func12();
  if (!cutscene_wait_before_toad_breaks_out_of_bag) {
    DrawToadAndRelatedSprites_Func10();
    return;
  }
  DrawToadAndRelatedSprites_Func18();
  R0_ = 32;
  R1_ = 4;
  R2_ = 3;
  ImposeGravity_Far(1u, 0);
  if (obj_ypos_lo.enemy[0] < 0xA0u) cutscene_var0B9D_oam_id = 1;
  if (obj_ypos_lo.enemy[0] < 0xB8u) {
    CODE_04F6F9(kDATA_04EE5F[cutscene_var0B9D_oam_id]);
    DrawToadAndRelatedSprites_Func10();
    return;
  }
  obj_ypos_lo.enemy[0] = -72;
  obj_yspeed.enemy[0] = 0;
  obj_sub_yspeed.enemy[0] = 0;
  obj_sub_ypos.enemy[0] = 0;
  if (cutscene_var0BA4 == 1) {
    sound_ch1 = 32;
    cutscene_var0BA4 = 32;
  }
  if (cutscene_toad_has_been_initialized_flag != 2) {
    ++cutscene_toad_has_been_initialized_flag;
    rel_xpos_lo.enemy -= 8;
    obj_xpos_lo.enemy[0] -= 8;
    frame_counter = 0;
  }
  if (cutscene_var0BA0) goto LABEL_14;
  if (++cutscene_var0B9F >= 0x40u) {
    cutscene_var0B9F = 64;
  LABEL_14:
    if (++cutscene_var0BA0 >= 0x88u) cutscene_var0BA0 = -120;
  }
  CODE_04F74C();
  DrawToadAndRelatedSprites_Func15();
  DrawToadAndRelatedSprites_Func10();
}

void CODE_04F6A4(uint8 j) {
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v3;     // al

  enemy = rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, j);
  oam[64].xpos = rel_xpos_lo.enemy;
  oam[66].xpos = enemy;
  enemy += 16;
  oam[65].xpos = enemy;
  oam[67].xpos = enemy;
  v3 = obj_ypos_lo.enemy[0];
  oam[64].ypos = obj_ypos_lo.enemy[0];
  oam[65].ypos = v3;
  v3 += 16;
  oam[66].ypos = v3;
  oam[67].ypos = v3;
  oam[64].charnum = -50;
  oam[65].charnum = -50;
  oam[66].charnum = -50;
  oam[67].charnum = -50;
  oam[64].flags = 45;
  oam[65].flags = 109;
  oam[66].flags = -83;
  oam[67].flags = -51;
  oam_tile_size_buffer[j + 256] = 2;
  oam_tile_size_buffer[j + 260] = 2;
  oam_tile_size_buffer[j + 264] = 2;
  oam_tile_size_buffer[j + 268] = 2;
}

void CODE_04F6F9(uint8 j) {
  uint8 enemy;  // al
  OamEnt *oam;  // rbp
  uint8 v3;     // al

  enemy = rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, j);
  oam[64].xpos = rel_xpos_lo.enemy;
  oam[66].xpos = enemy;
  enemy += 16;
  oam[65].xpos = enemy;
  oam[67].xpos = enemy;
  v3 = obj_ypos_lo.enemy[0];
  oam[66].ypos = obj_ypos_lo.enemy[0];
  oam[67].ypos = v3;
  v3 += 8;
  oam[64].ypos = v3;
  oam[65].ypos = v3;
  oam[66].charnum = -50;
  oam[67].charnum = -50;
  oam[64].charnum = -34;
  oam[65].charnum = -34;
  oam[64].flags = 45;
  oam[66].flags = 45;
  oam[65].flags = 109;
  oam[67].flags = 109;
  oam_tile_size_buffer[j + 256] = 2;
  oam_tile_size_buffer[j + 260] = 2;
  oam_tile_size_buffer[j + 264] = 2;
  oam_tile_size_buffer[j + 268] = 2;
}

void CODE_04F74C() {
  uint8 v0;     // al
  uint8 v1;     // al
  OamEnt *oam;  // rdx
  uint8 v3;     // al
  uint8 v4;     // al
  uint8 v5;     // al
  uint8 v6;     // al
  uint8 v7;     // al
  uint8 v8;     // di
  OamEnt *v9;   // rdx

  v0 = cutscene_var0B9F - 40;
  if ((int8)(cutscene_var0B9F - 40) < 0) v0 = 0;
  R0_ = v0 >> 2;
  R1_ = (uint8)(cutscene_var0BA0 & 8) >> 3;
  v1 = R1_ + cutscene_var0BA0 + rel_xpos_lo.enemy;
  oam = get_OamEnt(oam_buf, 0);
  oam[64].xpos = v1;
  oam[68].xpos = v1;
  v3 = v1 + 16 - R1_;
  oam[65].xpos = v3;
  oam[69].xpos = v3;
  v4 = v3 + 16 - R1_;
  oam[66].xpos = v4;
  oam[70].xpos = v4;
  v5 = R1_ + obj_ypos_lo.enemy[0] - R0_;
  oam[68].ypos = v5;
  oam[69].ypos = v5;
  oam[70].ypos = v5;
  v5 += 8;
  oam[64].ypos = v5;
  oam[65].ypos = v5;
  oam[66].ypos = v5;
  oam[64].charnum = -34;
  oam[66].charnum = -34;
  oam[65].charnum = -20;
  oam[68].charnum = -50;
  oam[70].charnum = -50;
  oam[69].charnum = -22;
  oam[64].flags = 45;
  oam[65].flags = 45;
  oam[68].flags = 45;
  oam[69].flags = 45;
  oam[66].flags = 109;
  oam[70].flags = 109;
  oam_tile_size_buffer[256] = 2;
  oam_tile_size_buffer[260] = 2;
  oam_tile_size_buffer[264] = 2;
  oam_tile_size_buffer[272] = 2;
  oam_tile_size_buffer[276] = 2;
  oam_tile_size_buffer[280] = 2;
  v6 = cutscene_var0BA0 + rel_xpos_lo.enemy + 2;
  oam[72].xpos = v6;
  v6 += 8;
  oam[73].xpos = v6++;
  oam[74].xpos = v6;
  v6 += 8;
  oam[75].xpos = v6++;
  oam[76].xpos = v6;
  v6 += 8;
  oam[77].xpos = v6++;
  oam[78].xpos = v6;
  oam[79].xpos = v6 + 8;
  oam[72].ypos = -56;
  oam[73].ypos = -56;
  oam[74].ypos = -56;
  oam[75].ypos = -56;
  oam[76].ypos = -56;
  oam[77].ypos = -56;
  oam[78].ypos = -56;
  oam[79].ypos = -56;
  if ((cutscene_var0BA0 & 0xF) == 15) sound_ch1 = 14;
  v7 = (2 * (cutscene_var0BA0 & 8)) | 0xCB;
  oam[72].charnum = v7;
  oam[74].charnum = v7;
  oam[76].charnum = v7;
  oam[78].charnum = v7++;
  oam[73].charnum = v7;
  oam[75].charnum = v7;
  oam[77].charnum = v7;
  oam[79].charnum = v7;
  oam[72].flags = 45;
  oam[73].flags = 45;
  oam[74].flags = 45;
  oam[75].flags = 45;
  oam[76].flags = 45;
  oam[77].flags = 45;
  oam[78].flags = 45;
  oam[79].flags = 45;
  v8 = 0;
  do {
    v9 = get_OamEnt(oam_buf, v8);
    if (v9[64].xpos < 0x40u) v9[64].ypos = -16;
    v8 += 4;
  } while (v8);
}

void CutsceneToad_Func6() {
  uint8 v0;  // al
  uint8 v1;  // al
  uint8 v2;  // [rsp+47h] [rbp-1h]

  v0 = ++cutscene_wait_before_toad_breaks_out_of_bag;
  if (cutscene_wait_before_toad_breaks_out_of_bag < 0xD0u) {
    if (cutscene_wait_before_toad_breaks_out_of_bag >= 0x20u) {
      if ((cutscene_wait_before_toad_breaks_out_of_bag & 0xF) == 0)
        sound_ch1 = 14;
      v0 = cutscene_wait_before_toad_breaks_out_of_bag;
    }
  } else {
    DrawToadAndRelatedSprites_Func15();
    v0 = -48;
    cutscene_wait_before_toad_breaks_out_of_bag = -48;
  }
  v1 = v0 >> 3;
  if (v1 >= 3u) v1 = 3;
  v2 = v1;
  CODE_04F8DC(v1);
  if (v2 == 2 && !cutscene_var0BA4) {
    sound_ch1 = 43;
    cutscene_var0BA4 = 43;
  }
  DrawToadAndRelatedSprites_Func10();
}

void CODE_04F8DC(uint8 a) {
  uint8 v1;     // si
  OamEnt *oam;  // rdx
  uint8 i;      // di
  uint8 v4;     // al
  OamEnt *v5;   // rdx
  int8 v6;      // al
  uint8 v7;     // di
  int8 v8;      // si
  uint8 v9;     // al
  OamEnt *v10;  // rdx
  int8 v11;     // al

  v1 = 8 * a;
  oam = get_OamEnt(oam_buf, 8u);
  oam[64].xpos = -120;
  oam[66].xpos = -120;
  oam[65].xpos = -112;
  oam[64].ypos = -80;
  oam[65].ypos = -80;
  oam[66].ypos = -64;
  oam[64].charnum = 0x80;
  oam[65].charnum = -127;
  oam[66].charnum = -96;
  oam[64].flags = 45;
  oam[65].flags = 45;
  oam[66].flags = 45;
  for (i = 0; i < 8u; ++i) get_OamEnt(oam_buf, i)[64].xpos = kDATA_04F9B5[v1++];
  oam_tile_size_buffer[256] = 2;
  oam_tile_size_buffer[260] = 2;
  oam_tile_size_buffer[264] = 2;
  oam_tile_size_buffer[268] = 2;
  oam_tile_size_buffer[272] = 2;
  v4 = cutscene_wait_before_toad_breaks_out_of_bag + 126;
  v5 = get_OamEnt(oam_buf, 0);
  v5[71].xpos = cutscene_wait_before_toad_breaks_out_of_bag + 126;
  if (v4 >= 0x88u)
    v6 = -64;
  else
    v6 = -16;
  v5[71].ypos = v6;
  R1_ = (frame_counter >> 2) & 2;
  v5[71].charnum = R1_ - 26;
  v5[71].flags = 45;
  oam_tile_size_buffer[284] = 2;
  v7 = 32;
  v8 = 6;
  R0_ = cutscene_wait_before_toad_breaks_out_of_bag + 120;
  do {
    v9 = R0_;
    v10 = get_OamEnt(oam_buf, v7);
    v10[64].xpos = R0_;
    v10[65].xpos = v9;
    if (v9 >= 0x91u) {
      v10[64].ypos = -64;
      v10[65].ypos = -56;
    } else {
      v10[64].ypos = -16;
      v10[65].ypos = -16;
    }
    v11 = R1_ - 70;
    v10[64].charnum = R1_ - 70;
    v10[65].charnum = v11 + 1;
    v10[64].flags = 45;
    v10[65].flags = 45;
    v7 += 8;
    R0_ -= 10;
    --v8;
  } while (v8);
}

void DrawToadAndRelatedSprites_Func10() {
  if (cutscene_toad_var0BA6) {
    if ((cutscene_toad_var0BA6 & 0x80u) == 0) --cutscene_toad_var0BA6;
  } else if (!cutscene_var0BA7) {
    ++cutscene_var0BA7;
    mario_goal_walk_var03ce = -72;
    if (!player_size) mario_goal_walk_var03ce = -56;
  }
}

void DrawToadAndRelatedSprites_Func11(uint8 j, uint8 a) {
  uint8 v2;     // si
  uint8 v3;     // al
  OamEnt *oam;  // rbp
  uint8 v5;     // al

  R2_ = a;
  v2 = 3 * a;
  v3 = R0_;
  oam = get_OamEnt(oam_buf, j);
  oam[64].xpos = R0_;
  oam[66].xpos = v3;
  oam[65].xpos = v3 + 8;
  v5 = R1_;
  oam[64].ypos = R1_;
  oam[65].ypos = v5;
  oam[66].ypos = v5 + 8;
  oam[64].charnum = kDATA_04FA4B[v2];
  oam[65].charnum = kDATA_04FA4B[v2 + 1];
  oam[66].charnum = kDATA_04FA4B[v2 + 2];
  oam[64].flags = kDATA_04FA63[v2];
  oam[65].flags = kDATA_04FA63[v2 + 1];
  oam[66].flags = kDATA_04FA63[v2 + 2];
  oam_tile_size_buffer[j + 264] = 2;
}

void DrawToadAndRelatedSprites_Func12() {
  uint8 v0;     // al
  OamEnt *oam;  // rbp
  OamEnt *v2;   // rbp
  OamEnt *v3;   // rdx
  OamEnt *v4;   // rbp

  if ((--cutscene_rustling_bag_animation_frame & 0x80u) != 0) {
    ++cutscene_wait_before_toad_breaks_out_of_bag;
    cutscene_rustling_bag_animation_frame = 7;
  }
  v0 = cutscene_wait_before_toad_breaks_out_of_bag;
  if (cutscene_wait_before_toad_breaks_out_of_bag >= 3u) {
    v0 = 3;
    cutscene_wait_before_toad_breaks_out_of_bag = 3;
  }
  R0_ = *((uint8 *)kDATA_04FAA7 + (uint8)(2 * v0));
  R1_ = *((uint8 *)kDATA_04FAA7 + (uint8)(2 * v0) + 1);
  switch ((uint8)(2 * v0) >> 1) {
    case 0:
      oam = get_OamEnt(oam_buf, 0);
      oam[86].xpos = -108;
      oam[86].ypos = -69;
      oam[86].charnum = -64;
      oam[86].flags = 45;
      oam_tile_size_buffer[344] = 2;
      oam[88].xpos = -120;
      oam[92].xpos = -120;
      oam[89].xpos = -112;
      oam[93].xpos = -112;
      oam[92].ypos = -64;
      oam[93].ypos = -64;
      oam[92].charnum = -100;
      oam[93].charnum = -99;
      oam[88].ypos = -72;
      oam[89].ypos = -72;
      oam[88].charnum = -116;
      oam[89].charnum = -115;
      oam[92].flags = 45;
      oam[93].flags = 45;
      oam[88].flags = 45;
      oam[89].flags = 45;
      oam_tile_size_buffer[368] = 2;
      oam_tile_size_buffer[372] = 2;
      oam_tile_size_buffer[352] = 2;
      oam_tile_size_buffer[356] = 2;
      break;
    case 1:
      v2 = get_OamEnt(oam_buf, 0);
      v2[86].xpos = -102;
      v2[86].ypos = -66;
      v2[86].charnum = -62;
      v2[86].flags = 45;
      oam_tile_size_buffer[344] = 2;
      v2[92].xpos = -120;
      v2[93].xpos = -112;
      v2[92].ypos = -64;
      v2[93].ypos = -64;
      v2[92].charnum = -103;
      v2[93].charnum = -102;
      v2[92].flags = 45;
      v2[93].flags = 45;
      oam_tile_size_buffer[368] = 2;
      oam_tile_size_buffer[372] = 2;
      break;
    case 2:
      v3 = get_OamEnt(oam_buf, 0);
      v3[86].xpos = -100;
      v3[86].ypos = -63;
      v3[86].charnum = -60;
      v3[86].flags = 45;
      oam_tile_size_buffer[344] = 2;
      goto LABEL_9;
    case 3:
    LABEL_9:
      v4 = get_OamEnt(oam_buf, 0);
      v4[92].xpos = -120;
      v4[93].xpos = -112;
      v4[92].ypos = -64;
      v4[93].ypos = -64;
      v4[92].charnum = -58;
      v4[93].charnum = -57;
      v4[92].flags = 45;
      v4[93].flags = 45;
      oam_tile_size_buffer[368] = 2;
      oam_tile_size_buffer[372] = 2;
      break;
  }
}

void DrawToadAndRelatedSprites_Func13() {
  uint8 v0;  // di

  sound_ch1 = 15;
  mario_goal_walk_var03ce = 16 * (player_size ^ 1) - 32 + 8;
  v0 = -100;
  R1_ = 11;
  R0_ = 0;
  do RomPtr_RAM(*(uint16 *)&R0_)[v0++] = 0;
  while (v0 != 0xBF);
  ++cutscene_toad_has_been_initialized_flag;
  --cutscene_toad_var0BA6;
  R0_ = *((uint8 *)kDATA_04FBE4 + (uint8)(2 * world_number));
  R1_ = *((uint8 *)kDATA_04FBE4 + (uint8)(2 * world_number) + 1);
  switch ((uint8)(2 * world_number) >> 1) {
    case 0:
    case 7:
    case 8:
    case 12:
      obj_xpos_lo.enemy[0] -= 4;
      rel_xpos_lo.enemy -= 4;
      cutscene_rustling_bag_animation_frame = 8;
      sound_ch2 = 1;
      obj_yspeed.enemy[0] = -2;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.enemy[0] = 0;
      break;
    case 1:
      obj_xpos_lo.enemy[0] -= 12;
      rel_xpos_lo.enemy -= 12;
      cutscene_rustling_bag_animation_frame = 8;
      sound_ch2 = 1;
      obj_yspeed.enemy[0] = -2;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.enemy[0] = 0;
      break;
    case 2:
      obj_xpos_lo.enemy[0] -= 4;
      rel_xpos_lo.enemy -= 4;
      cutscene_rustling_bag_animation_frame = 8;
      obj_xpos_lo.enemy[3] = 0;
      sound_ch2 = 1;
      obj_yspeed.enemy[0] = -2;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.enemy[0] = 0;
      cutscene_var0BA0 = 0;
      break;
    case 3:
      obj_xpos_lo.enemy[0] -= 4;
      rel_xpos_lo.enemy -= 4;
      cutscene_arr0BB0[0] = rel_xpos_lo.enemy;
      cutscene_arr0BB0[1] = rel_xpos_lo.enemy;
      cutscene_arr0BB0[2] = rel_xpos_lo.enemy;
      cutscene_arr0BB0[3] = rel_xpos_lo.enemy;
      sound_ch2 = 1;
      obj_yspeed.enemy[0] = -2;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.enemy[0] = 0;
      var0E67 = 0;
      break;
    case 4:
    case 9:
      obj_xpos_lo.enemy[0] -= 12;
      obj_ypos_lo.enemy[0] -= 12;
      sound_ch2 = 1;
      cutscene_var0B9E = -2;
      obj_yspeed.enemy[0] = -2;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.enemy[0] = 0;
      break;
    case 5:
    case 10:
      obj_xpos_lo.enemy[0] -= 12;
      sound_ch2 = 1;
      obj_yspeed.enemy[0] = -3;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.enemy[0] = 0;
      break;
    case 6:
    case 11:
      sound_ch1 = 0;
      obj_yspeed.enemy[0] = -2;
      obj_sub_yspeed.enemy[0] = 0;
      obj_sub_ypos.enemy[0] = 0;
      break;
  }
}
// 7E021D: using guessed type int8;

// local variable allocation has failed, the output may be wrong!
void DrawToadAndRelatedSprites_Func14(uint8 j, uint16 a) {
  int16 v2;     // ax
  OamEnt *oam;  // rbp

  v2 = a - 8 - screen_left_xpos16;
  *(uint16 *)&R1_ = v2;
  oam = get_OamEnt(oam_buf, j);
  oam[64].xpos = v2;
  oam[66].xpos = v2;
  oam[64].flags = 45;
  oam[66].flags = 45;
  LOBYTE(v2) = (HIBYTE(v2) != 0) | 2;
  oam_tile_size_buffer[j + 256] = v2;
  oam_tile_size_buffer[j + 264] = v2;
}
// 1B549: variables would overlap: al.1 and ax.2

void DrawToadAndRelatedSprites_Func15() {
  if (mario_goal_walk_var03ce >= 0xD0u && (mario_goal_walk_var03ce & 8) != 0) {
    mario_goal_walk_var03ce -= 8;
    cutscene_toad_var0BA6 = 48;
  }
}

void DrawToadAndRelatedSprites_Func16() {
  if ((uint8)layer3_xpos) {
    LOBYTE(layer3_xpos) = layer3_xpos - 1;
  } else if (cutscene_toad_var0BA3 >= 0xC0u) {
    CODE_048600();
  } else if (++cutscene_toad_var0BA3 == 0xC0) {
    DrawToadAndRelatedSprites_Func17();
  }
}

void DrawToadAndRelatedSprites_Func18() {
  if (!cutscene_var0BA4) {
    sound_ch2 = 1;
    cutscene_var0BA4 = 1;
  }
}

void DrawToadAndRelatedSprites_Func17() {
  *(uint16 *)&vram_buffer1[1] = -3750;
  *(uint16 *)&vram_buffer1[3] = 4864;
  *(uint16 *)&vram_buffer1[5] = 25;
  *(uint16 *)&vram_buffer1[7] = 30;
  *(uint16 *)&vram_buffer1[9] = 28;
  *(uint16 *)&vram_buffer1[11] = 17;
  *(uint16 *)&vram_buffer1[13] = 40;
  *(uint16 *)&vram_buffer1[15] = 28;
  *(uint16 *)&vram_buffer1[17] = 29;
  *(uint16 *)&vram_buffer1[19] = 10;
  *(uint16 *)&vram_buffer1[21] = 27;
  *(uint16 *)&vram_buffer1[23] = 29;
  vram_buffer1[25] = -1;
  sound_ch3 = 21;
}

void ResetScrollRegs() {
  layer1_xpos_lo = 0;
  layer1_ypos_lo = 0;
  WriteReg(BG1HOFS, 0);
  WriteReg(BG1HOFS, 0);
  WriteReg(BG1VOFS, 0);
  WriteReg(BG1VOFS, 0);
  WriteReg(BG2HOFS, 0);
  WriteReg(BG2HOFS, 0);
  WriteReg(BG2VOFS, 0);
  WriteReg(BG2VOFS, 0);
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3HOFS, 0);
  WriteReg(BG3VOFS, 0);
  WriteReg(BG3VOFS, 0);
}
