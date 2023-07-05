#include "smbll_consts.h"
#include "smbll_funcs.h"
#include "smbll_rtl.h"
#include "smbll_variables.h"
void Smbll_InitGfxStuff() {
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
  game_mode = 0;
  game_mode_task = 0;
  g_byte_7FFFFF = 0;
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
  render_graphics_var0EC9 = 0;
  game_loop_toggler = 0;
  vblank_upload_from_7f0000_flag = 0;
  vblank_flag_0ED4 = 0;
  update_entire_palette_flag = 0;
  vram_buffer_addr_ctrl = 0;
  vram_flag_028d = 0;
  palette_mirror[0] = 0;
  palette_mirror[128] = 0;
  *(uint16 *)&vram_buffer1[2] = -1;
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
}

void Smbll_CODE_048600() {
  if ((cutscene_var1680 & 0x80u) == 0) {
    if (!cutscene_var1680) {
      if ((controller_press1p1 & 0x10) == 0)
        return;
      ++cutscene_var1680;
      sound_ch1 = 67;
    }
    --cutscene_hdma_varB9A;
    if ((--cutscene_hdma_varB9A & 0x80u) != 0) {
      game_mode_task = 13;
      player_hard_mode_flag = 1;
    }
  }
}

void Smbll_CODE_04862A() {
  Smbll_PauseMenu_Func6();
  if (world_number < 8u) {
    cutscene_var1680 = 16;
    area_number = 0;
    level_number = 0;
    if (smbll_varF2B) {
      title_screen_hard_mode_flag = 1;
      ++world_number;
    }
    ++world_number;
  }
  w12sel_mirror = 34;
  w34sel_mirror = 2;
  ++game_mode_task;
  if (number_of_players) {
    tsw_mirror = 2;
    display_pause_menu_flag = 0;
    cutscene_var1680 = 4;
  }
}

void Smbll_WaitForMusicAndChangeTask() {
  if (!ReadReg(APUI00)) {
    game_mode_task = 10;
    cutscene_var1680 |= 0x80u;
  }
}

void Smbll_CutsceneHdma() {
  uint16 v0;  // si
  uint8 v1;   // di
  int8 v2;    // di
  int16 v3;   // ax
  uint16 v4;  // ax
  uint16 v5;  // ax

  if (cutscene_hdma_varB9A < 0x30u) {
    cutscene_hdma_varB84 = 0;
    cutscene_hdma_varB8E = 0;
    cutscene_hdma_varB90 = 0;
    cutscene_hdma_varB92 = 0;
    cutscene_hdma_varB94 = kCircleHDMAData_DATA_00973E[(uint16)(2 * cutscene_hdma_varB9A) >> 1];
    cutscene_hdma_varB96 = 120;
    cutscene_hdma_varB98 = 176;
    while (1) {
      cutscene_hdma_varB80 = 256;
      cutscene_hdma_varB82 = 256;
      if ((uint16)(cutscene_hdma_varB90 + 1) < *(uint16 *)&cutscene_hdma_varB9A) {
        cutscene_hdma_varB92 += cutscene_hdma_varB94;
        WriteReg(WRMPYA, kCircleHDMAData_DATA_0096BD[cutscene_hdma_varB92 >> 9]);
        WriteReg(WRMPYB, cutscene_hdma_varB9A);
        cutscene_hdma_varB88 = ReadReg(RDMPYH);
        cutscene_hdma_varB82 = cutscene_hdma_varB98 + cutscene_hdma_varB88;
        cutscene_hdma_varB80 = cutscene_hdma_varB98 - cutscene_hdma_varB88;
      }
      cutscene_hdma_varB84 = 2 * (cutscene_hdma_varB96 - cutscene_hdma_varB90 - 1);
      v0 = 2 * (cutscene_hdma_varB96 - cutscene_hdma_varB90 - 1);
      v1 = cutscene_hdma_varB80;
      if ((cutscene_hdma_varB80 & 0x8000u) != 0)
        break;
      if ((cutscene_hdma_varB80 & 0xFF00) != 0) {
        if ((cutscene_hdma_varB80 & 0xFF00) != 256)
          break;
        v1 = -1;
      }
LABEL_10:
      cutscene_hdma_varB86 = v1;
      v2 = cutscene_hdma_varB82;
      if ((cutscene_hdma_varB82 & 0xFF00) != 0)
        v2 = -1;
      LOBYTE(v3) = 0;
      HIBYTE(v3) = v2;
      v4 = cutscene_hdma_varB86 | v3;
      cutscene_hdma_varB86 = v4;
      if (v0 < 0x1C0u) {
        if (v4 == 0xFFFF)
          v4 = 255;
        hdma_data_array[v0 >> 1] = v4;
      }
      cutscene_hdma_varB8E = 2 * (cutscene_hdma_varB90 + cutscene_hdma_varB96 - 1);
      if ((uint16)(2 * (cutscene_hdma_varB90 + cutscene_hdma_varB96 - 1)) < 0x1C0u) {
        v5 = cutscene_hdma_varB86;
        if (cutscene_hdma_varB86 == 0xFFFF)
          v5 = 255;
        hdma_data_array[(uint16)(2 * (cutscene_hdma_varB90 + cutscene_hdma_varB96 - 1)) >> 1] = v5;
      }
      ++cutscene_hdma_varB90;
      if (cutscene_hdma_varB84 >= 0x1C0u && cutscene_hdma_varB8E >= 0x1C0u) {
        ++cutscene_hdma_varB9A;
        return;
      }
    }
    v1 = 0;
    goto LABEL_10;
  }
}

void Smbll_DecodeAreaData_Sub_New() {
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
  level_data_map16_hi[112] = 102;
  level_data_map16_hi[113] = 102;
  level_data_map16_hi[114] = 102;
  level_data_map16_hi[163] = 102;
  level_data_map16_hi[164] = 102;
  level_data_map16_hi[165] = 102;
  level_data_map16_hi[166] = 102;
  level_data_map16_hi[121] = 102;
  level_data_map16_hi[122] = 102;
  level_data_map16_hi[123] = 102;
  level_data_map16_hi[124] = 102;
  level_data_map16_hi[125] = 102;
  level_data_map16_hi[126] = 102;
  render_graphics_var0EC9 = 1;
}

void Smbll_HandleLayersScroll() {
  int8 v0;    // al
  int8 v1;    // cl
  bool v2;    // cf
  int8 v3;    // al
  uint16 v4;  // ax
  uint8 i;    // di
  int v6;     // rbp
  uint16 v7;  // ax

  tempF6 = 0;
  *(uint16 *)&tempF3 = layers_scroll_0EEC;
  *(uint16 *)&tempF7 = 0;
  do {
    v0 = *((uint8 *)kDATA_048949 + *(uint16 *)&tempF3);
    v1 = 0;
    v2 = __CFSHL__(v0, 1);
    v3 = 2 * v0;
    if (v2)
      v1 = 1;
    tempF5 = (2 * v3 + v1) & 1;
    v4 = (uint8)(tempF5 + 2 * *((uint8 *)kDATA_048949 + *(uint16 *)&tempF3 + 1));
    if (v4 >= 0x80u)
      v4 |= 0xFF00u;
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

void Smbll_CODE_048B49() {
  Smbll_CODE_048B59();
}

void Smbll_SMB3_BufferLayer3Tilemap() {
  if (enable_layer3_bgflag) {
    Smbll_CODE_048C77();
    Smbll_CODE_048B59();
  }
}

void Smbll_CODE_048B59() {
  game_loop_toggler &= 0x80u;
  if (area_type) {
    if (area_type != 1)
      return;
    Smbll_SMB3_BufferLayer3CloudTilemap();
    vblank_flag_0ED4 = 1;
  } else {
    Smbll_BufferAnimatedWaterSurfaceTiles();
    vram_buffer_addr_ctrl = 6;
  }
  vblank_enable_vtimel_flag = 1;
}

void Smbll_SMB3_BufferLayer3CloudTilemap() {
  uint16 v0;  // si
  uint16 v1;  // ax
  int v2;     // rbp
  int v3;     // rbp
  int v4;     // rbx

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
    layer3_tilemap_upload_buf[v4 + 2] = kword_1BB40[v3];
    layer3_tilemap_upload_buf[v4 + 3] = kword_1BB40[v3 + 1];
    layer3_tilemap_upload_buf[v4 + 31] = kword_1BB40[v3 + 2];
    layer3_tilemap_upload_buf[v4 + 32] = kword_1BB40[v3 + 3];
    v0 += 4;
    *(uint16 *)&R0_ += 16;
    --*(uint16 *)&tempF7;
  } while (*(uint16 *)&tempF7);
  layer3_tilemap_upload_buf[(layer3_tilemap_upload_buf[0] >> 1) + 59] = -1;
  layer3_tilemap_upload_buf[0] += 116;
  if ((((uint8)buffer_layer3_cloud_tilemap_offs + 1) & 0xF) != 0)
    ++buffer_layer3_cloud_tilemap_offs;
  else
    buffer_layer3_cloud_tilemap_offs = (buffer_layer3_cloud_tilemap_offs & 0xFFF0) + 224;
  if (buffer_layer3_cloud_tilemap_offs >= 0xA80u)
    buffer_layer3_cloud_tilemap_offs = 0;
  *(uint16 *)&tempF3 += 512;
}

void Smbll_BufferAnimatedWaterSurfaceTiles() {
  uint16 v0;  // ax
  int v1;     // rbp
  uint16 v2;  // ax
  uint16 v3;  // di

  v0 = *(uint16 *)&tempF3;
  v1 = vram_buffer2[0] >> 1;
  vram_buffer2[v1 + 1] = *(uint16 *)&tempF3;
  v0 += 256;
  vram_buffer2[v1 + 4] = v0;
  *(uint16 *)&tempF3 = v0 + 256;
  vram_buffer2[v1 + 2] = 256;
  vram_buffer2[v1 + 5] = 256;
  if ((*(uint16 *)&tempF3 & 0x200) != 0) {
    v2 = 11310;
    v3 = 11311;
  } else {
    v2 = 11308;
    v3 = 11309;
  }
  vram_buffer2[v1 + 3] = v2;
  vram_buffer2[v1 + 6] = v3;
  vram_buffer2[v1 + 7] = -1;
  vram_buffer2[0] += 12;
}

void Smbll_CODE_048C77() {
  int16 v0;  // ax

  LOBYTE(v0) = (uint16)(layer3_xpos + 288) >> 8;
  HIBYTE(v0) = layer3_xpos + 32;
  *(uint16 *)&tempF3 = v0;
  Smbll_CODE_048C85();
}

void Smbll_CODE_048C85() {
  uint8 v0;  // al

  if ((tempF3 & 1) != 0)
    v0 = 92;
  else
    v0 = 88;
  tempF3 = v0;
  tempF4 = (tempF4 >> 3) + 0x80;
}

void Smbll_SpawnCastleTilesWithPriority() {
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
  *(uint16 *)&tempF3 = koff_1874C[(uint8)((2 * (render_graphics_var0EE6 & 1)) & 2) >> 1];
  v0 = *(uint16 *)vram_buffer1;
  v1 = 0;
  do {
    v2 = IndirPtr((LongPtr *)&tempF3, v1);
    v3 = *(uint16 *)v2;
    *(uint16 *)&vram_buffer1[v0 + 2] = *(uint16 *)v2;
    v1 += 2;
    v0 += 2;
  } while (v3 != -1);
  v4 = *(uint16 *)vram_buffer1;
  if ((render_graphics_var0EF4 & 0x20) != 0)
    *(uint16 *)&render_graphics_var0EF4 = *(uint16 *)&render_graphics_var0EF4 & 0xFDF ^ 0x400;
  LOBYTE(v5) = (uint16)((*(uint16 *)&render_graphics_var0EF4 + 705) & 0xFDF) >> 8;
  HIBYTE(v5) = (render_graphics_var0EF4 - 63) & 0xDF;
  *(uint16 *)&vram_buffer1[*(uint16 *)vram_buffer1 + 2] = v5;
  v6 = __PAIR16__(v5, HIBYTE(v5)) + 1;
  if (((HIBYTE(v5) + 1) & 0x20) != 0)
    v6 = v6 & 0xFDF ^ 0x400;
  LOBYTE(v7) = HIBYTE(v6);
  HIBYTE(v7) = v6;
  *(uint16 *)&vram_buffer1[v4 + 14] = v7;
  v8 = v6 + 1;
  LOBYTE(v7) = HIBYTE(v8);
  HIBYTE(v7) = v8;
  *(uint16 *)&vram_buffer1[v4 + 26] = v7;
  *(uint16 *)vram_buffer1 += 36;
  render_graphics_var0EE6 = 0;
  vram_buffer_addr_ctrl = 6;
}

void Smbll_CODE_048D71() {
  int16 v0;  // ax
  uint8 v1;  // si
  int16 v2;  // ax
  int v3;    // edx
  int16 v4;  // ax
  int v5;    // edx

  v0 = *(uint16 *)&vram_buffer1[LOBYTE(vram_buffer2[0]) + 760];
  if (v0 == 36 || v0 == 4260) {
    if ((uint8)render_area_gfx_0ECE)
      return;
    ++render_area_gfx_0ECE;
    v1 = vram_buffer1[0];
    LOBYTE(v2) = (uint16)(((render_graphics_var0ecc - 1) & 0x41F) + 832) >> 8;
    HIBYTE(v2) = ((render_graphics_var0ecc - 1) & 0x1F) + 64;
    v3 = vram_buffer1[0];
    *(uint16 *)&vram_buffer1[vram_buffer1[0] + 2] = v2;
    *(uint16 *)&vram_buffer1[v3 + 4] = 1920;
    *(uint16 *)&vram_buffer1[v1 + 6] = 2573;
    *(uint16 *)&vram_buffer1[v1 + 8] = 2589;
    *(uint16 *)&vram_buffer1[v1 + 10] = 2575;
    *(uint16 *)&vram_buffer1[v1 + 12] = 2591;
    goto LABEL_10;
  }
  if (v0 == 2568) {
    if (HIBYTE(render_area_gfx_0ECE)) {
      render_area_gfx_0ECE = 0;
      if (*(uint16 *)((int8 *)&screen_left_xpos16 + 1) || render_graphics_var0ecc) {
        v1 = vram_buffer1[0];
        LOBYTE(v4) = (uint16)(render_graphics_var0ecc + 832) >> 8;
        HIBYTE(v4) = render_graphics_var0ecc + 64;
        v5 = vram_buffer1[0];
        *(uint16 *)&vram_buffer1[vram_buffer1[0] + 2] = v4;
        *(uint16 *)&vram_buffer1[v5 + 4] = 1920;
        *(uint16 *)&vram_buffer1[v1 + 6] = 2572;
        *(uint16 *)&vram_buffer1[v1 + 8] = 2588;
        *(uint16 *)&vram_buffer1[v1 + 10] = 2574;
        *(uint16 *)&vram_buffer1[v1 + 12] = 2590;
LABEL_10:
        *(uint16 *)&vram_buffer1[v1 + 14] = -1;
        *(uint16 *)vram_buffer1 = v1 + 12;
      }
    }
  }
}

void Smbll_ExtObj09_PulleyRope(uint8 k) {
  uint8 v1;  // di

  uint8 v2 = Smbll_ChkLrgObjLength(k) >> 8;
  v1 = 0;
  if (!v2) {
    v1 = 1;
    if (!area_object_length[k])
      v1 = 2;
  }
  metatile_buffer[0] = kPulleyRopeMetatiles[v1];
}

void Smbll_DecodeAreaData_Sub2_New(uint16 j) {
  uint16 addr;  // kr00_2
  uint8 *v3;    // rdx
  uint16 v4;    // si
  int v5;       // r14
  uint8 v6;     // si
  uint8 v7;     // di
  uint8 v8;     // di
  uint8 v9;     // di
  uint8 v10;    // si
  uint8 v11;    // di
  uint8 v12;    // di
  uint8 v13;    // di
  uint8 v14;    // si
  uint8 slot;   // si
  uint8 v16;    // al
  int8 v17;     // al
  uint8 v18;    // di
  uint8 v19;    // di
  uint8 v20;    // al
  uint8 v21;    // di
  bool v22;     // sf
  uint8 v23;    // di
  uint8 v24;    // di
  uint8 v25;    // di
  uint8 v26;    // di
  uint8 v27;    // di
  uint8 i;      // di
  uint8 v29;    // di
  uint8 v30;    // di
  uint8 v31;    // di
  uint8 v32;    // di
  uint8 v33;    // di
  uint8 v34;    // di
  uint8 v35;    // di
  uint8 v36;    // di
  uint8 v37;    // al
  uint8 v38;    // di
  uint8 v39;    // di
  uint8 v40;    // al
  uint8 v41;    // di
  uint8 v42;    // di
  uint8 v43;    // di
  uint8 v44;    // si
  uint8 v45;    // di
  uint8 v46;    // di
  uint8 v47;    // [rsp+46h] [rbp-2h]
  uint8 v48;    // [rsp+46h] [rbp-2h]
  uint8 xpos;   // [rsp+46h] [rbp-2h]
  uint8 v50;    // [rsp+46h] [rbp-2h]
  uint8 t0;

  addr = area_data_ptr.addr;
  tempF4 = HIBYTE(addr);
  tempF3 = addr;
  tempF5 = area_data_ptr.bank;
  v3 = IndirPtr((LongPtr *)&tempF3, j + 2);
  v4 = *v3 & 0x7F;
  v5 = (int)(uint8)v4 >> 1;
  R0_ = *((uint8 *)koff_188C1 + (*v3 & 0x7F));
  R1_ = *((uint8 *)koff_188C1 + v4 + 1);
  v6 = object_index;
  switch ((int8)v5) {
  case 0:
    v10 = 0;
    v11 = 15;
    goto LABEL_10;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
  case 10:
  case 13:
  case 14:
  case 15:
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
  case 49:
  case 50:
  case 51:
  case 52:
  case 53:
  case 54:
  case 55:
  case 57:
  case 58:
  case 59:
  case 60:
  case 61:
  case 62:
  case 63: return;
  case 8:
    v47 = object_index;
    Smbll_RenderUnderPart_Far(1u, 0xFu, 0x44u);
    v11 = Smbll_CODE_0491C0(v47);
    v10 = 1;
LABEL_10:
    Smbll_RenderUnderPart_Far(v10, v11, 0x40u);
    return;
  case 9:
    v7 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v7);
    metatile_buffer[R7_] = 0;
    return;
  case 11:
    v8 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v8);
    metatile_buffer[R7_] = 96;
    return;
  case 12:
    v9 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v9);
    metatile_buffer[R7_] = 97;
    return;
  case 16:
    v12 = Smbll_CODE_0491C0(object_index);
    R7_ = v12;
    render_graphics_var0EE7 = 0;
    if (!v12)
      v12 = 8;
    Smbll_ChkLrgObjFixedLength(v6, v12 + 1);
    v48 = v6;
    v13 = area_object_length[v6];
    v14 = R7_;
    R6_ = 22;
    do {
      metatile_buffer[v14++] = kbyte_189AF[v13];
      if (R6_) {
        v13 += 10;
        --R6_;
      }
    } while (v14 != 11);
    if (R7_ && !area_object_length[v48])
      metatile_buffer[10] = 0;
    if (column_pos_hi) {
      if (area_object_length[v48] == 5) {
        xpos = Smbll_GetAreaObjXPosition_Far();
        slot = Smbll_FindEmptyEnemySlot_Far();
        obj_xpos_lo.enemy[slot] = xpos + 8;
        obj_xpos_hi.enemy[slot] = __CFADD__(xpos, 8) + column_pos_hi;
        obj_ypos_hi.enemy[slot] = 1;
        enemy_flag[slot] = 1;
        obj_ypos_lo.enemy[slot] = -112;
        enemy_id[slot] = 49;
        ++render_graphics_var0EE7;
        if (R7_)
          ++render_graphics_var0EE7;
      }
    }
    if (column_pos_hi) {
      switch (metatile_buffer[11]) {
      case 'N': v16 = -4; break;
      case '"': v16 = 36; break;
      case 'p':
        v16 = 115;
        metatile_buffer[12] = 115;
        break;
      case 'f': v16 = 105; break;
      default: v16 = 116; break;
      }
      metatile_buffer[11] = v16;
    }
    return;
  case 17: v17 = 6; goto LABEL_39;
  case 18: v17 = 7; goto LABEL_39;
  case 19:
    v17 = 9;
LABEL_39:
    v50 = v17;
    v18 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v18);
    metatile_buffer[v50] = 7;
    return;
  case 20:
    v19 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v19);
    tempF3 = metatile_buffer[0];
    if (metatile_buffer[0] == 99)
      v20 = metatile_buffer[0] + 1;
    else
      v20 = metatile_buffer[0] - 1;
    tempF4 = v20;
    v21 = R7_;
    if ((R7_ & 1) != 0)
      goto LABEL_44;
    while (1) {
      metatile_buffer[v21] = tempF3;
      v22 = (--area_object_length[v6] & 0x80u) != 0;
      if (v22)
        break;
      ++v21;
LABEL_44:
      metatile_buffer[v21] = tempF4;
      v22 = (--area_object_length[v6] & 0x80u) != 0;
      if (v22)
        break;
      ++v21;
    }
    return;
  case 24:
    v23 = Smbll_CODE_0491C0(object_index);
    t0 = area_object_length[v6];
    Smbll_ChkLrgObjFixedLength(v6, v23);
    if (t0 & 0x80)
      decode_area_data_var0734 = 9;
    --decode_area_data_var0734;
    Smbll_RenderUnderPart_Far(kbyte_18B24[decode_area_data_var0734], kbyte_18B1B[decode_area_data_var0734], 0x62u);
    return;
  case 25:
    v24 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v24);
    v25 = R7_;
    if (area_object_length[v6]) {
      if (metatile_buffer[R7_])
        goto LABEL_59;
      metatile_buffer[R7_] = -10;
    } else {
      metatile_buffer[R7_] = -12;
      if (!metatile_buffer[++v25])
        metatile_buffer[v25++] = -11;
    }
    do {
      if (!metatile_buffer[v25])
        metatile_buffer[v25] = -9;
LABEL_59:
      ++v25;
    } while (v25 != 13);
    return;
  case 26:
    v26 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v26);
    v27 = R7_;
    metatile_buffer[R7_] = 101;
    for (i = v27 + 2; metatile_buffer[i] == 99 || metatile_buffer[i] == 100; i += 2)
      metatile_buffer[i] = 101;
    return;
  case 27:
    v29 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v29);
    v30 = R7_;
    metatile_buffer[R7_] = -8;
    v31 = v30 + 1;
    do {
      if (metatile_buffer[v31] == 0xEC)
        break;
      metatile_buffer[v31++] = -7;
    } while (v31 != 13);
    return;
  case 28:
    v32 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v32);
    v33 = R7_;
    if (metatile_buffer[R7_] != 0xFD)
      metatile_buffer[R7_] = -6;
    v34 = v33 + 1;
    do {
      if (metatile_buffer[v34] == 0xF1)
        break;
      metatile_buffer[v34++] = -5;
    } while (v34 != 13);
    return;
  case 29:
    v35 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v35);
    v36 = R7_;
    if (area_object_length[v6]) {
      if (metatile_buffer[R7_] == 102)
        v37 = -17;
      else
        v37 = -20;
      metatile_buffer[R7_] = v37;
      metatile_buffer[v36 + 1] = -19;
      metatile_buffer[12] = 103;
    } else {
      if (metatile_buffer[R7_] != 104)
        metatile_buffer[R7_] = 2;
      metatile_buffer[v36 + 1] = -18;
    }
    return;
  case 30:
    v38 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v38);
    v39 = R7_;
    if (area_object_length[v6]) {
      if (metatile_buffer[R7_] != 104)
        metatile_buffer[R7_] = 3;
      metatile_buffer[v39 + 1] = -16;
    } else {
      if (metatile_buffer[R7_] == 102) {
        v40 = -13;
      } else {
        v41 = R7_ + 2;
        do
          metatile_buffer[v41++] = 103;
        while (v41 != 13);
        v39 = R7_;
        v40 = -15;
      }
      metatile_buffer[v39] = v40;
      metatile_buffer[v39 + 1] = -14;
    }
    return;
  case 31:
    v42 = Smbll_CODE_0491C0(object_index);
    Smbll_ChkLrgObjFixedLength(v6, v42);
    v43 = R7_;
    do {
      metatile_buffer[v43++] = 112;
      v22 = (--area_object_length[v6] & 0x80u) != 0;
    } while (!v22);
    return;
  case 32:
    Smbll_ChkLrgObjFixedLength(object_index, 3u);
    R5_ = Smbll_CODE_0491C0(v6) - 2;
    R6_ = area_object_length[v6];
    v44 = R5_ + 1;
    if (kbyte_18C96[R6_]) {
      v44 = Smbll_RenderUnderPart_Far(0, R5_, kbyte_18C96[R6_]);
    }
    v45 = R6_;
    metatile_buffer[v44] = kbyte_18C9A[R6_];
    metatile_buffer[v44 + 1] = kbyte_18C9E[v45];
    return;
  case 40:
    v46 = Smbll_CODE_0491C0(object_index);
    Smbll_RenderUnderPart_Far(2u, v46, 0x78u);
    return;
  case 48: Smbll_sub_AAC0(v6, 1); goto lbl_56;
  case 56:
    Smbll_sub_AAC0(v6, 4);
lbl_56:
    metatile_buffer[v6] = 28;
    if (*(&block_buffer_column_pos + v6) == 27)
      ++metatile_buffer[v6];
    return;
  }
}

uint8 Smbll_CODE_0491C0(uint8 k) {
  uint16 v1;  // di

  v1 = area_obj_offset_buffer[(uint16)(2 * k) >> 1] + 1;
  R7_ = *IndirPtr((LongPtr *)&tempF3, v1) >> 4;
  return *IndirPtr((LongPtr *)&tempF3, v1) & 0xF;
}

uint8 Smbll_CODE_0491DD() {
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
  v1 = vram_buffer2[0];
  if (current_player) {
    while (1) {
      v2 = kGameOverScreenStripeImage_Luigi[v0 >> 1];
      vram_buffer2[(v1 >> 1) + 1] = v2;
      if (v2 == 0xFFFF)
        break;
      v0 += 2;
      v1 += 2;
    }
  } else {
    while (1) {
      v3 = kGameOverScreenStripeImage[v0 >> 1];
      vram_buffer2[(v1 >> 1) + 1] = v3;
      if (v3 == 0xFFFF)
        break;
      v0 += 2;
      v1 += 2;
    }
  }
  for (i = 0;; i += 2) {
    v5 = kGameOverScreenStripeImage_TitleLogo[i >> 1];
    vram_buffer2[(v1 >> 1) + 1] = v5;
    if (v5 == 0xFFFF)
      break;
    v1 += 2;
  }
  vram_buffer2[0] = v1;
  *(uint16 *)&R2_ = -19366;
  v6 = Smbll_CODE_049724(0xA0u, 0);
  v7 = Smbll_CODE_049724(v6.first, v6.second);
  result = Smbll_CODE_049724(v7.first, v7.second).second;
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
  update_entire_palette_flag = 1;
  Smbll_HandleTilesetGraphicsUploads();
  override_player_xpos2_flag = -1;
  smbll_varF26 = 0;
  layer2_ypos = 0;
  WriteReg(BG2VOFS, 0);
  WriteReg(BG2VOFS, 0);
  return result;
}

void Smbll_sub_18F08() {
  smbll_varF26 = kbyte_18E0A[area_data_addr_index];
}

void Smbll_CODE_0492E7() {
  uint16 v0;   // di
  int v1;      // rbp
  uint16 v2;   // di
  uint16 v3;   // si
  uint16 v4;   // ax
  uint16 v5;   // di
  uint16 v6;   // si
  uint16 v7;   // ax
  uint16 v8;   // si
  uint16 v9;   // ax
  uint16 v10;  // si
  uint16 v11;  // ax
  uint8 v12;   // al

  if (unused_byte_7E0E1A)
    unused_byte_7E0E1A = 0;
  Smbll_sub_18F08();
  music_ch1 = 0x80;
  tileset_graphics_type = kbyte_18E52[(uint8)(level_level_preview_image_to_use - 1)] & 0x1F;
  disable_screen_flag = 1;
  game_loop_toggler = 1;
  Smbll_HandleTilesetGraphicsUploads();
  area_parser_ctr1 = 0;
  tree_ledge_saved_x = 0;
  tree_ledge_arr130F[0] = 0;
  set_level_music_flag = 0;
  vblank_which_layer2_scroll_flag = 0;
  render_graphics_var0EC9 = 0;
  var0EDB = 0;
  cutscene_hdma_varB9A = 0;
  cutscene_var1680 = 0;
  enable_layer3_bgflag = 0;
  Smbll_Dma_CODE_0480EF();
  *(uint16 *)&tree_ledge_countdown = 0;
  *(uint16 *)&tree_ledge_arr130F[1] = 0;
  *(uint16 *)&tree_ledge_arr130F[3] = 0;
  v0 = vram_buffer2[0];
  v1 = vram_buffer2[0] >> 1;
  vram_buffer2[v1 + 1] = -14583;
  vram_buffer2[v1 + 2] = 4800;
  vram_buffer2[v1 + 3] = 12450;
  vram_buffer2[v1 + 4] = -10231;
  vram_buffer2[v1 + 5] = 4800;
  vram_buffer2[v1 + 6] = 28834;
  vram_buffer2[v1 + 7] = -22519;
  vram_buffer2[v1 + 8] = 7744;
  vram_buffer2[v1 + 9] = 12408;
  vram_buffer2[v1 + 10] = 2059;
  vram_buffer2[v1 + 11] = 7744;
  vram_buffer2[v1 + 12] = -20360;
  v2 = v0 + 24;
  v3 = 0;
  do {
    v4 = kLevelPreviewStripeImages[v3 >> 1];
    vram_buffer2[(v2 >> 1) + 1] = v4;
    v3 += 2;
    v2 += 2;
  } while (v4 != 0xFFFF);
  v5 = v2 - 2;
  v6 = koff_18DA2[(uint16)(2 * (uint8)(level_level_preview_image_to_use - 1)) >> 1];
  do {
    v7 = kLevelPreviewStripeImages_Main[v6 >> 1];
    vram_buffer2[(v5 >> 1) + 1] = v7;
    v6 += 2;
    v5 += 2;
  } while (v7 != 0xFFFF);
  if (background_color_ctrl_0 == 17) {
    v5 -= 2;
    v8 = 0;
    do {
      v9 = kword_1ABA6[v8 >> 1];
      vram_buffer2[(v5 >> 1) + 1] = v9;
      v8 += 2;
      v5 += 2;
    } while (v9 != 0xFFFF);
  }
  if ((background_color_ctrl_0 & 0xF0) != 0 && background_color_ctrl_0 != 22) {
    v5 -= 2;
    v10 = 0;
    do {
      v11 = kword_1ABD2[v10 >> 1];
      vram_buffer2[(v5 >> 1) + 1] = v11;
      v10 += 2;
      v5 += 2;
    } while (v11 != 0xFFFF);
  }
  vram_buffer2[0] = v5;
  Smbll_CODE_0495E2();
  --screen_routine_task;
  update_entire_palette_flag = 1;
  palette_mirror[0] = 0;
  tempEB = player_status;
  player_status = 1;
  v12 = background_color_ctrl_0 & 0xF0;
  if ((background_color_ctrl_0 & 0xF0) != 0)
    v12 = 4;
  background_color_ctrl = v12;
  if (background_color_ctrl_0 == 2)
    background_color_ctrl = 3;
  if (area_data_addr_index == 8)
    background_color_ctrl = 1;
  Smbll_GetPlayerColors();
  --update_entire_palette_flag;
  player_status = tempEB;
  background_color_ctrl_0 = 0;
  tm_mirror = 23;
  vram_buffer_addr_ctrl = 6;
  vblank_enable_vtimel_flag = 0;
  layer2_ypos = 0;
  WriteReg(BG2VOFS, 0);
  WriteReg(BG2VOFS, 0);
}

void Smbll_CODE_0494EA() {
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
  Smbll_SetupLayer2Bg();
  Smbll_CODE_049B96();
  Smbll_CODE_049BBC();
  Smbll_CODE_049BBC();
  Smbll_CODE_049BBC();
  Smbll_CODE_049BBC();
  Smbll_CODE_049BBC();
  Smbll_CODE_049BBC();
  if (obj_yspeed.bubble[0] != 3) {
    Smbll_CODE_049BBC();
    Smbll_CODE_049BBC();
    Smbll_CODE_049BBC();
    Smbll_CODE_049BBC();
    if (vblank_which_layer2_scroll_flag) {
      Smbll_CODE_049BBC();
      Smbll_CODE_049BBC();
      Smbll_CODE_049BBC();
      Smbll_CODE_049BBC();
      Smbll_CODE_049BBC();
      Smbll_CODE_049BBC();
    }
  }
}

void Smbll_CODE_04956B() {
  uint8 v0;  // al
  uint8 v1;  // si

  Smbll_CODE_0494EA();
  layer2_ypos = 0;
  if (area_type) {
    if (area_type == 1)
      LOBYTE(layer2_ypos) = -8;
    v0 = 6;
    cgwsel_mirror = 6;
    v1 = 17;
  } else {
    WriteRegWord(DMAP2, 0xF42u);
    WriteRegWord(A1T2L, 0x9113u);
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
    if (cloud_type_override) {
      vblank_which_layer2_scroll_flag = 0;
    } else {
      vtimel_mirror = -81;
      vblank_enable_vtimel_flag = 1;
    }
  }
  Smbll_CODE_0495E2();
}

void Smbll_CODE_0495E2() {
  int16 v0;   // ax
  uint16 v1;  // di
  uint16 v2;  // si
  int v3;     // rbp
  int v4;     // rbx
  uint16 v5;  // di
  uint16 v6;  // si
  uint16 v7;  // ax

  if (override_area_data_addr_index) {
    area_data_addr_index = override_area_data_addr_index;
    override_area_data_addr_index = 0;
  } else if (area_data_addr_index == 23 || area_data_addr_index == 38) {
    override_area_data_addr_index = area_data_addr_index;
    if (!world_number || world_number == 4 || world_number == 9) {
      area_data_addr_index = 55;
      smbll_varF26 = 3;
    } else {
      area_data_addr_index = 62;
    }
  }
  *(uint16 *)&R6_ = 16 * area_data_addr_index;
  *(uint16 *)&R2_ = 0;
  do {
    v0 = kbyte_1938B[*(uint16 *)&R6_];
    ++*(uint16 *)&R6_;
    v1 = kword_1AC76[(uint16)(2 * v0) >> 1];
    v2 = *(uint16 *)&R2_;
    *(uint16 *)&R4_ = 7;
    do {
      v3 = v1 >> 1;
      v4 = v2 >> 1;
      palette_mirror[v4] = kword_1ACFA[v3];
      palette_mirror[v4 + 8] = kword_1AD0A[v3];
      v2 += 2;
      v1 += 2;
      --*(uint16 *)&R4_;
    } while (*(int16 *)&R4_ >= 0);
    *(uint16 *)&R2_ = v2 + 16;
  } while (v2 != 464);
  if (*(uint16 *)&tileset_graphics_flag_var2f8 && current_player) {
    v5 = 0;
    v6 = 224;
    do {
      palette_mirror[v6 >> 1] = kword_19237[v5 >> 1];
      v6 += 2;
      v5 += 2;
    } while (v5 != 32);
  }
  layer3_xpos = screen_left_xpos16 >> 2;
  *(uint16 *)&tempF3 = (uint16)((screen_left_xpos16 >> 2) & 0xFF00) >> 8;
  v7 = 2 * world_number;
  if (v7 >= 0xCu)
    v7 = 0;
  *(uint16 *)&tempF3 += v7;
  buffer_layer3_cloud_tilemap_offs = 0;
  while (*(uint16 *)&tempF3) {
    buffer_layer3_cloud_tilemap_offs += 224;
    --*(uint16 *)&tempF3;
  }
  buffer_layer3_cloud_tilemap_offs += (uint8)(layer3_xpos & 0xF0) >> 4;
  if (buffer_layer3_cloud_tilemap_offs >= 0xA80u)
    buffer_layer3_cloud_tilemap_offs = 0;
  Smbll_CODE_04973C();
  if (enable_layer3_bgflag) {
    tempF3 = HIBYTE(layer3_xpos);
    tempF4 = layer3_xpos;
    Smbll_CODE_048C85();
    tempF5 = 19;
    do {
      Smbll_CODE_048B49();
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

PairU16 Smbll_CODE_049724(uint8 k, uint8 j) {
  *(uint16 *)&R4_ = 1;
  *(uint16 *)&R0_ = 16;
  do {
    palette_mirror[k >> 1] = *(uint16 *)IndirPtr((LongPtr *)&R2_, j);
    j += 2;
    k += 2;
    --*(uint16 *)&R0_;
  } while (*(uint16 *)&R0_);
  return MakePairU16(k, j);
}

void Smbll_CODE_04973C() {
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
    v1 = kword_1B4BA[*(uint16 *)&tempF8 >> 1];
    if (v1 == 0xFFFF)
      break;
    if ((int16)(v1 + 1) < 0)
      *(uint16 *)&tempF3 += 224;
    v2 = (uint8)v1;
    v3 = __CFSHL__uint16(2 * v1);
    HIBYTE(v1) = 0;
    *(uint16 *)&tempF6 = v3;
    tempF7 = *((uint8 *)kword_1B4BA + (uint16)(*(uint16 *)&tempF8 + 1)) & 0x3F;
    while (1) {
      IndirWriteByte((LongPtr *)&tempF3, v2, tempF7);
      if (!tempF6 || (v2 & 0xF0) == 0xD0)
        break;
      LOBYTE(v1) = v2 + 16;
      v2 = v1;
    }
    ++*(uint16 *)&tempF8;
    ++*(uint16 *)&tempF8;
  }
}

void Smbll_GetBackgroundColor_0() {
  if (!background_color_ctrl_0) {
    ++screen_routine_task;
    Smbll_GetPlayerColors();
  }
}

void Smbll_GetPlayerColors() {
  uint8 bubble;  // al
  uint16 v1;     // ax
  int16 v2;      // ax
  int8 v3;       // t0
  uint8 v4;      // di
  uint8 i;       // si
  int v6;        // rbp
  int v7;        // rbx

  bubble = background_color_ctrl;
  if (!background_color_ctrl)
    bubble = obj_yspeed.bubble[0];
  if (!cloud_type_override || (background_color_ctrl & 4) != 0 || (number_of_lives & 0x80) != 0)
    v1 = kword_197FB[(uint16)(2 * bubble) >> 1];
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
    if (current_player)
      v4 = 32;
    if (player_status == 2)
      v4 += 64;
    for (i = 0; i != 16; i += 2) {
      v6 = v4 >> 1;
      v7 = i >> 1;
      palette_mirror[v7 + 240] = kword_1980B[v6];
      palette_mirror[v7 + 248] = kword_1981B[v6];
      v4 += 2;
    }
    ++update_entire_palette_flag;
  }
}

void Smbll_CODE_049B35() {
  uint8 v0;  // al
  uint8 v1;  // al
  int8 v2;   // al

  v0 = HIBYTE(layer2_xpos);
  if (HIBYTE(layer2_xpos) == 127)
    v0 = smbll_varED0;
  else
    smbll_varED0 = HIBYTE(layer2_xpos);
  tempF3 = v0;
  R0_ = 32;
  if (obj_yspeed.bubble[0] == 3)
    R0_ *= 2;
  LOBYTE(g_word_7E0EF7) = (uint8)((R0_ + layer2_xpos) & 0xF0) >> 2;
  R0_ = (uint8)((R0_ + layer2_xpos) & 0xF0) >> 3;
  if (R0_) {
    if ((tempF3 & 1) != 0)
      v1 = 16;
    else
      v1 = 20;
  } else if (g_byte_7E0EF6) {
    g_byte_7E0EF6 = 0;
    v1 = 20;
  } else {
    v1 = 16;
    g_byte_7E0EF6 = 16;
  }
  R1_ = v1;
  v2 = tempF3 & 0xF;
  if (!R0_)
    ++v2;
  HIBYTE(g_word_7E0EF7) = 8 * (v2 + 1);
  Smbll_CODE_049BBC();
}

void Smbll_CODE_049B96() {
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

void Smbll_CODE_049BBC() {
  uint16 v0;  // di
  uint16 v1;  // si

  g_word_7E0EFA = 4;
  if (obj_yspeed.bubble[0] == 3)
    g_word_7E0EFA *= 2;
  v0 = upload_buffer_3[0];
  do {
    if ((R0_ & 0x20) != 0)
      *(uint16 *)&R0_ = (*(uint16 *)&R0_ + 1024) & 0x16C0;
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

void Smbll_LoadAreaPointer() {
  int8 v0;  // al

  area_pointer = Smbll_FindAreaPointer();
  v0 = 4 * (area_pointer & 0x60) + __CFSHL__(area_pointer & 0x60, 1);
  area_type = 2 * (2 * v0 + __CFSHL__(2 * (area_pointer & 0x60), 1)) + __CFSHL__(v0, 1);
  obj_yspeed.bubble[0] = area_type;
  if (world_number == 7 && area_number == 3)
    obj_yspeed.bubble[0] = 3;
}

uint8 Smbll_FindAreaPointer() {
  uint8 v0;  // di

  v0 = world_number;
  if (world_number >= 0xDu) {
    area_number = 0;
    level_number = 0;
    v0 = 0;
    world_number = 0;
  }
  return kAreaAddrOffsets[(uint8)(area_number + kWorldAddrOffsets[v0])];
}

uint8 Smbll_sub_1C396(uint8 a) {
  if (world_number >= 9u && (area_pointer & 0x60) == 32) {
    if (a == 31) {
      return 9;
    } else if (a == 30) {
      return 27;
    } else {
      a += 29;
    }
  }
  return a;
}

void Smbll_GetAreaDataAddrs() {
  int8 v0;   // al
  uint8 v1;  // di
  int v3;    // edx
  uint8 v4;  // al
  uint8 v5;  // al
  bool v6;   // cf
  uint8 v7;  // [rsp+46h] [rbp-2h]
  uint8 v8;  // [rsp+46h] [rbp-2h]

  v0 = 4 * (area_pointer & 0x60) + __CFSHL__(area_pointer & 0x60, 1);
  area_type = 2 * (2 * v0 + __CFSHL__(2 * (area_pointer & 0x60), 1)) + __CFSHL__(v0, 1);
  obj_yspeed.bubble[0] = area_type;
  v1 = area_type;
  if (world_number == 7 && area_number == 3)
    obj_yspeed.bubble[0] = 3;
  area_addrs_l_offset = Smbll_sub_1C396(area_pointer & 0x1f);
  v3 = (uint8)(area_addrs_l_offset + kbyte_1C4EC[v1]);
  LOBYTE(enemy_data_ptr.addr) = kbyte_1C4F0[v3];
  HIBYTE(enemy_data_ptr.addr) = kbyte_1C537[v3];
  enemy_data_ptr.bank = 1;
  area_data_addr_index = area_addrs_l_offset + kbyte_1C57E[area_type];
  LOBYTE(area_data_ptr.addr) = kbyte_1C582[area_data_addr_index];
  HIBYTE(area_data_ptr.addr) = kbyte_1C5C9[area_data_addr_index];
  area_data_ptr.bank = 1;
  v7 = *IndirPtr(&area_data_ptr, 0);
  v4 = v7 & 7;
  if ((v7 & 7u) >= 4) {
    background_color_ctrl = v7 & 7;
    v4 = 0;
  }
  foreground_scenery = v4;
  player_entrance_ctrl = (uint8)(v7 & 0x38) >> 3;
  game_timer_setting = 2 * (4 * (v7 & 0xC0) + __CFSHL__(v7 & 0xC0, 1)) + __CFSHL__(2 * (v7 & 0xC0), 1);
  v8 = *IndirPtr(&area_data_ptr, 1u);
  terrain_control = v8 & 0xF;
  background_scenery = (uint8)(v8 & 0x30) >> 4;
  v5 = 2 * (4 * (v8 & 0xC0) + __CFSHL__(v8 & 0xC0, 1)) + __CFSHL__(2 * (v8 & 0xC0), 1);
  if (v5 == 3) {
    cloud_type_override = 3;
    v5 = 0;
  }
  area_style = v5;
  Smbll_UpdateVineAtEntrance_New();
  v6 = __CFADD__(area_data_ptr.addr, 2);
  LOBYTE(area_data_ptr.addr) += 2;
  HIBYTE(area_data_ptr.addr) += v6;
  area_parser_var3 = 0;
}

void Smbll_UpdateVineAtEntrance_New() {
  if (cloud_type_override)
    goto LABEL_6;
  if (area_data_addr_index == 35) {
    if ((uint8)screen_left_xpos16)
      return;
    goto LABEL_6;
  }
  if (area_data_addr_index == 34)
LABEL_6:
    vine_at_entrance_flag = 1;
}
