#include "smbll_consts.h"
#include "smbll_funcs.h"
#include "smbll_rtl.h"
#include "smbll_variables.h"
void (*funcs_2195C[13])() = {&Smbll_CutsceneToad_Func0, &Smbll_CutsceneToad_Func1, &Smbll_CutsceneToad_Func2, &Smbll_CutsceneToad_Func3,
                             &Smbll_CutsceneToad_Func4, &Smbll_CutsceneToad_Func5, &Smbll_CutsceneToad_Func6, &Smbll_CutsceneToad_Func0,
                             &Smbll_CutsceneToad_Func0, &Smbll_CutsceneToad_Func4, &Smbll_CutsceneToad_Func5, &Smbll_CutsceneToad_Func6,
                             &Smbll_CutsceneToad_Func0};  // weak

void Smbll_RenderPlayerSub_New() {
  int16 v0;  // ax

  if (!cutscene_var0BA5) {
    if ((player_gfx_offset == 24 || player_gfx_offset == 120) && (frame_counter & 7) == 0 && !sound_ch2)
      sound_ch2 = 4;
    vram_flag_028e = 1;
    LOBYTE(v0) = 0;
    HIBYTE(v0) = player_gfx_offset >> 3;
    player_graphics_pointer.addr = v0 + 0x8000;
    player_vramaddress = 24576;
    player_graphics_upload_size = 256;
    if (player_luigi_graphics)
      HIBYTE(player_graphics_pointer.addr) |= 0x40u;
    player_graphics_pointer.bank = 7;
  }
}

void Smbll_CODE_04D85A() {
  level_preview_sprites_ctr = 0;
}

void Smbll_Ending_SetPaletteWriteText() {
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
  Smbll_Ending_WriteText();
}

void Smbll_Ending_WriteText() {
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
  for (i = *(uint16 *)vram_buffer1;; ++i) {
    v3 = kEndingTextThankYou[v1];
    vram_buffer1[i + 2] = v3;
    if (v3 == 0xFF)
      break;
    ++v1;
  }
  *(uint16 *)vram_buffer1 = i;
}

void Smbll_CODE_04DBDA() {
  uint8 v0;  // al
  uint8 v1;  // si
  uint8 v2;  // al

  if (!cutscene_peach_var0F85) {
    v0 = sram_cutscene_heart_eyes_flag;
    if (sram_cutscene_heart_eyes_flag)
      v0 = current_player;
    v1 = cutscene_peach_var0F84++ | (8 * v0);
    if (cutscene_peach_var0F84 == 3) {
      obj_yspeed.enemy[0] = -1;
      obj_sub_yspeed.enemy[0] = 0;
    }
    v2 = kbyte_B843F[v1];
    if (!v2) {
      ++game_mode_task;
      player_x_move_force = 0;
      obj_xspeed.player = 0;
    }
    cutscene_peach_var0F85 = v2;
    cutscene_peach_var0F86 = kbyte_B844F[v1];
  }
  --cutscene_peach_var0F85;
  buttons_a_b_previous = 16 * (cutscene_peach_var0F86 & 8);
  if (scroll_lock) {
    if (obj_xpos_lo.player >= 0xA2u)
      obj_xpos_lo.player = -94;
  }
}

void Smbll_ProcessPeachMovement() {
  if ((--cutscene_peach_state_timer & 0x80u) != 0) {
    if (!++cutscene_peach_current_state)
      obj_xpos_lo.player = -96;
    cutscene_peach_state_timer = kbyte_B84B4[cutscene_peach_current_state];
  }
  R0_ = *((uint8 *)koff_B8491 + (uint8)(2 * cutscene_peach_current_state));
  R1_ = *((uint8 *)koff_B8491 + (uint8)(2 * cutscene_peach_current_state) + 1);
  switch ((uint8)(2 * cutscene_peach_current_state) >> 1) {
  case 0:
  case 1:
  case 2:
  case 5:
  case 6: return;
  case 3: goto LABEL_7;
  case 4:
    R0_ = 32;
    R2_ = 4;
    Smbll_ImposeGravity_Far(1u, 0);
LABEL_7:
    --obj_xpos_lo.enemy[0];
    break;
  }
}

void Smbll_DrawLevelPreviewSprites_Sub7() {
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
    v3 = kbyte_B854E[cutscene_peach_current_state];
  else
    v3 = kbyte_B854E[cutscene_peach_current_state] + 2;
  oam[44].charnum = v3;
  oam[45].charnum = v3 + 32;
  oam[44].flags = 37;
  oam[45].flags = 37;
  oam_tile_size_buffer[176] =
      (obj_xpos_hi.enemy[0] - (((uint8)(obj_xpos_lo.enemy[0] + 7) < (uint8)screen_left_xpos16) + HIBYTE(screen_left_xpos16))) | 2;
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

void Smbll_Ending_SetGfxPtrToUpload() {
  uint8 v0;  // si
  int v1;    // rbp

  if (cutscene_peach_var0F83 < 0xAu) {
    v0 = 2 * cutscene_peach_var0F83++;
    graphics_upload_ptr.bank = kbyte_B8587[v0];
    graphics_upload_size = 2048;
    v1 = v0 >> 1;
    graphics_upload_vramaddress = kword_B85AF[v1];
    graphics_upload_ptr.addr = kword_B859B[v1];
    ++pausemenu_var3;
  }
}

void Smbll_SpawnMushroomDuringPeachCutscene() {
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

void Smbll_CODE_04DE54() {
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

void Smbll_PeachCutscene_04DE8B() {
  int v0;       // rbp
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
  int v14;      // rbp
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
  int v28;      // rbp
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
      Smbll_CutsceneHdma();
      if (cutscene_peach_var0F81 >= kbyte_B8A76[cutscene_peach_close_up_animation_frame]) {
        cutscene_peach_var0F81 = 0;
        if (++cutscene_peach_close_up_animation_frame >= 9u) {
          if (cutscene_peach_close_up_animation_frame == 9)
            cutscene_peach_var0F89 = 0;
          cutscene_peach_close_up_animation_frame = 9;
        }
      }
      ++cutscene_peach_var0F81;
      v28 = (uint8)(2 * cutscene_peach_close_up_animation_frame) >> 1;
      *(uint16 *)&tempED = kword_B8AE6[v28];
      v29 = kword_B8AA0[v28];
      v30 = 4;
      while (kbyte_B8AFA[v29] != 0xFF) {
        oam = get_OamEnt(oam_buf, v30);
        oam->ypos = kbyte_B8AFA[v29] + 0x80;
        v32 = v29 + 1;
        oam->xpos = kbyte_B8AFA[v32++] - 64;
        v33 = kbyte_B8AFA[v32];
        oam->charnum = v33;
        v34 = v32 + 1;
        R0_ = 0;
        if (v33 < 0x80u)
          R0_ = current_player;
        oam->flags = R0_ | kbyte_B8AFA[v34] | 0x20;
        v29 = v34 + 1;
        oam_tile_size_buffer[v30] = 2;
        v30 += 4;
      }
      v35 = *(uint16 *)&tempED;
      while (kbyte_B8AFA[v35] != 0xFF) {
        v36 = get_OamEnt(oam_buf, v30);
        v36->ypos = kbyte_B8AFA[v35] + 0x80;
        v37 = v35 + 1;
        v36->xpos = current_player + current_player + current_player + current_player + kbyte_B8AFA[v37++] - 64;
        v38 = kbyte_B8AFA[v37];
        v36->charnum = v38;
        v39 = v37 + 1;
        R0_ = 0;
        if (v38 < 0x80u)
          R0_ = current_player;
        v36->flags = R0_ | kbyte_B8AFA[v39] | 0x20;
        v35 = v39 + 1;
        oam_tile_size_buffer[v30] = 2;
        v30 += 4;
      }
      if (cutscene_peach_close_up_animation_frame == 9) {
        Smbll_DrawToadAndRelatedSprites_Func16();
        v40 = get_OamEnt(oam_buf, 0);
        v40->xpos = kbyte_B8A59[(cutscene_peach_var0F89 >> 3) & 3] - 80;
        R0_ = cutscene_peach_var0F89 >> 2;
        v40->ypos = 96 - (cutscene_peach_var0F89 >> 2);
        v41 = (cutscene_peach_var0F89 >> 5) & 3;
        v40->charnum = kbyte_B8A55[v41];
        v40->flags = 38;
        oam_tile_size_buffer[0] = 0;
        ++cutscene_peach_var0F89;
        if (v41 == 3)
          cutscene_peach_var0F89 = 0;
      }
    } else {
      Smbll_CutsceneHdma();
      if (cutscene_peach_var0F81 >= kbyte_B8A66[cutscene_peach_close_up_animation_frame]) {
        cutscene_peach_var0F81 = 0;
        if (++cutscene_peach_close_up_animation_frame == 5)
          cutscene_peach_var0F89 = 0;
        if (cutscene_peach_close_up_animation_frame >= 0xFu)
          cutscene_peach_close_up_animation_frame = 6;
      }
      ++cutscene_peach_var0F81;
      v14 = (uint8)(2 * cutscene_peach_close_up_animation_frame) >> 1;
      *(uint16 *)&tempED = kword_B8AC6[v14];
      v15 = kword_B8A80[v14];
      v16 = 4;
      while (kbyte_B8AFA[v15] != 0xFF) {
        v17 = get_OamEnt(oam_buf, v16);
        v17->ypos = kbyte_B8AFA[v15] + 0x80;
        v18 = v15 + 1;
        v17->xpos = kbyte_B8AFA[v18++] - 64;
        v19 = kbyte_B8AFA[v18];
        v17->charnum = v19;
        v20 = v18 + 1;
        R0_ = 0;
        if (v19 < 0x80u)
          R0_ = current_player;
        v17->flags = R0_ | kbyte_B8AFA[v20] | 0x20;
        v15 = v20 + 1;
        oam_tile_size_buffer[v16] = 2;
        v16 += 4;
      }
      v21 = *(uint16 *)&tempED;
      while (kbyte_B8AFA[v21] != 0xFF) {
        v22 = get_OamEnt(oam_buf, v16);
        v22->ypos = kbyte_B8AFA[v21] + 0x80;
        v23 = v21 + 1;
        v22->xpos = current_player + current_player + current_player + current_player + kbyte_B8AFA[v23++] - 64;
        v24 = kbyte_B8AFA[v23];
        v22->charnum = v24;
        v25 = v23 + 1;
        R0_ = 0;
        if (v24 < 0x80u)
          R0_ = current_player;
        v22->flags = R0_ | kbyte_B8AFA[v25] | 0x20;
        v21 = v25 + 1;
        oam_tile_size_buffer[v16] = 2;
        v16 += 4;
      }
      if (cutscene_peach_close_up_animation_frame >= 6u) {
        Smbll_DrawToadAndRelatedSprites_Func16();
        v26 = get_OamEnt(oam_buf, 0);
        v26->xpos = kbyte_B8A59[(cutscene_peach_var0F89 >> 3) & 3] - 80;
        R0_ = cutscene_peach_var0F89 >> 2;
        v26->ypos = 96 - (cutscene_peach_var0F89 >> 2);
        v27 = (cutscene_peach_var0F89 >> 5) & 3;
        v26->charnum = kbyte_B8A55[v27];
        v26->flags = 38;
        oam_tile_size_buffer[0] = 0;
        ++cutscene_peach_var0F89;
        if (v27 == 3)
          cutscene_peach_var0F89 = 0;
      }
    }
  } else {
    Smbll_CutsceneHdma();
    if (cutscene_peach_var0F81 >= kbyte_B8A5D[cutscene_peach_close_up_animation_frame]) {
      cutscene_peach_var0F81 = 0;
      if (++cutscene_peach_close_up_animation_frame >= 8u) {
        if (cutscene_peach_close_up_animation_frame == 8)
          cutscene_peach_var0F89 = 0;
        cutscene_peach_close_up_animation_frame = 8;
      }
    }
    ++cutscene_peach_var0F81;
    v0 = (uint8)(2 * cutscene_peach_close_up_animation_frame) >> 1;
    *(uint16 *)&tempED = kword_B8AB4[v0];
    v1 = kword_B8A80[v0];
    v2 = 4;
    while (kbyte_B8AFA[v1] != 0xFF) {
      v3 = get_OamEnt(oam_buf, v2);
      v3->ypos = kbyte_B8AFA[v1] + 0x80;
      v4 = v1 + 1;
      v3->xpos = kbyte_B8AFA[v4++] - 64;
      v5 = kbyte_B8AFA[v4];
      v3->charnum = v5;
      v6 = v4 + 1;
      R0_ = 0;
      if (v5 < 0x80u)
        R0_ = current_player;
      v3->flags = R0_ | kbyte_B8AFA[v6] | 0x20;
      v1 = v6 + 1;
      oam_tile_size_buffer[v2] = 2;
      v2 += 4;
    }
    v7 = *(uint16 *)&tempED;
    while (kbyte_B8AFA[v7] != 0xFF) {
      v8 = get_OamEnt(oam_buf, v2);
      v8->ypos = kbyte_B8AFA[v7] + 0x80;
      v9 = v7 + 1;
      v8->xpos = current_player + current_player + current_player + current_player + kbyte_B8AFA[v9++] - 64;
      v10 = kbyte_B8AFA[v9];
      v8->charnum = v10;
      v11 = v9 + 1;
      R0_ = 0;
      if (v10 < 0x80u)
        R0_ = current_player;
      v8->flags = R0_ | kbyte_B8AFA[v11] | 0x20;
      v7 = v11 + 1;
      oam_tile_size_buffer[v2] = 2;
      v2 += 4;
    }
    if (cutscene_peach_close_up_animation_frame == 8) {
      Smbll_DrawToadAndRelatedSprites_Func16();
      v12 = get_OamEnt(oam_buf, 0);
      v12->xpos = kbyte_B8A59[(cutscene_peach_var0F89 >> 3) & 3] - 80;
      R0_ = cutscene_peach_var0F89 >> 2;
      v12->ypos = 96 - (cutscene_peach_var0F89 >> 2);
      v13 = (cutscene_peach_var0F89 >> 5) & 3;
      v12->charnum = kbyte_B8A55[v13];
      v12->flags = 38;
      oam_tile_size_buffer[0] = 0;
      ++cutscene_peach_var0F89;
      if (v13 == 3)
        cutscene_peach_var0F89 = 0;
    }
  }
  Smbll_PeachCutscene_04E221();
}

void Smbll_PeachCutscene_04E221() {
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

void Smbll_CutsceneBowserDefeat_04ECCA() {
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

void Smbll_CutsceneToad_04ED07() {
  graphics_upload_ptr.bank = 4;
  graphics_upload_size = 2048;
  graphics_upload_vramaddress = 31744;
  graphics_upload_ptr.addr = kword_B955A[(uint8)(2 * world_number) >> 1];
}

void Smbll_UploadSpriteGFX() {
  WriteReg(VMAIN, 0x80u);
  WriteRegWord(VMADDL, 0x6000u);
  WriteRegWord(DMAP0, 0x1801u);
  WriteRegWord(A1T0L, 0x8000u);
  WriteReg(A1B0, 4u);
  WriteRegWord(DAS0L, 0x4000u);
  WriteReg(MDMAEN, 1u);
}

void Smbll_DrawToadAndRelatedSprites(uint8 k) {
  uint8 v1;     // al
  int8 v2;      // al
  OamEnt *v3;   // rbp
  uint8 v4;     // al
  OamEnt *oam;  // rbp
  uint8 v6;     // si

  if (cutscene_toad_popped_out_of_bag_flag) {
    v6 = world_number;
    if (!cutscene_toad_has_been_initialized_flag)
      Smbll_DrawToadAndRelatedSprites_Func13();
    R0_ = koff_B9645[v6];
    R1_ = HIBYTE(koff_B9645[v6]);
    funcs_2195C[(unsigned int)(v6 * 2) >> 1]();
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
    Smbll_DrawToadAndRelatedSprites_Func14(0, PAIR16(obj_xpos_hi.enemy[0], obj_xpos_lo.enemy[0]));
    Smbll_DrawToadAndRelatedSprites_Func14(4u, PAIR16(obj_xpos_hi.enemy[0], obj_xpos_lo.enemy[0]) + 8);
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
// 21964: using guessed type int (*funcs_2195C[13])();

void Smbll_CutsceneToad_Func0() {
  uint8 v0;  // al

  Smbll_DrawToadAndRelatedSprites_Func12();
  if (cutscene_wait_before_toad_breaks_out_of_bag) {
    if (cutscene_wait_before_toad_breaks_out_of_bag == 3 && !cutscene_var0B9F) {
      Smbll_DrawToadAndRelatedSprites_Func18();
      R0_ = 32;
      R2_ = 4;
      Smbll_ImposeGravity_Far(1u, 0);
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
        Smbll_DrawToadAndRelatedSprites_Func15();
      }
    }
    if (cutscene_var0B9F)
      --cutscene_var0B9F;
    else
      cutscene_var0B9E = 1;
    R0_ = rel_xpos_lo.enemy;
    R1_ = obj_ypos_lo.enemy[0];
    Smbll_DrawToadAndRelatedSprites_Func11(kbyte_B965F[cutscene_var0B9D_oam_id], cutscene_var0B9E);
    Smbll_DrawToadAndRelatedSprites_Func10();
  } else {
    Smbll_DrawToadAndRelatedSprites_Func10();
  }
}

void Smbll_CutsceneToad_Func1() {
  uint8 v0;  // al
  uint8 v1;  // di
  uint8 v2;  // di
  uint8 v3;  // al

  Smbll_DrawToadAndRelatedSprites_Func12();
  if (!cutscene_wait_before_toad_breaks_out_of_bag) {
    Smbll_DrawToadAndRelatedSprites_Func10();
    return;
  }
  if (cutscene_wait_before_toad_breaks_out_of_bag == 3) {
    if (!cutscene_var0B9F) {
      if (cutscene_toad_has_been_initialized_flag == 2) {
        cutscene_var0B9E = cutscene_toad_has_been_initialized_flag;
        goto LABEL_12;
      }
      Smbll_DrawToadAndRelatedSprites_Func18();
      cutscene_var0B9E = 1;
      R0_ = 32;
      R2_ = 4;
      Smbll_ImposeGravity_Far(1u, 0);
      v0 = obj_ypos_lo.enemy[0];
      if (obj_ypos_lo.enemy[0] < 0xB0u) {
        cutscene_var0B9D_oam_id = 1;
        v0 = obj_ypos_lo.enemy[0];
      }
      if (v0 < 0xB8u)
        goto LABEL_12;
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
  v1 = kbyte_B965F[cutscene_var0B9D_oam_id];
  Smbll_DrawToadAndRelatedSprites_Func11(v1, cutscene_var0B9E);
  v2 = v1 + 16;
  R0_ = rel_xpos_lo.enemy + 16;
  v3 = cutscene_var0B9E;
  if (cutscene_var0B9E == 2) {
    Smbll_DrawToadAndRelatedSprites_Func15();
    v3 = 3;
  }
  Smbll_DrawToadAndRelatedSprites_Func11(v2, v3);
  Smbll_DrawToadAndRelatedSprites_Func10();
}

void Smbll_CutsceneToad_Func2() {
  Smbll_DrawToadAndRelatedSprites_Func12();
  if (!cutscene_wait_before_toad_breaks_out_of_bag) {
    Smbll_DrawToadAndRelatedSprites_Func10();
    return;
  }
  if (cutscene_wait_before_toad_breaks_out_of_bag != 3)
    goto LABEL_21;
  if (cutscene_var0BA0 < 0x28u) {
LABEL_20:
    ++cutscene_var0BA0;
LABEL_21:
    R0_ = rel_xpos_lo.enemy;
    R1_ = obj_ypos_lo.enemy[0];
    Smbll_DrawToadAndRelatedSprites_Func11(kbyte_B965F[cutscene_var0B9D_oam_id], cutscene_var0B9E);
    Smbll_DrawToadAndRelatedSprites_Func10();
    return;
  }
  if (cutscene_var0BA0 < 0x50u) {
    if (cutscene_var0BA0 < 0x2Cu) {
      Smbll_CODE_04F124(0xA0u);
    } else if (cutscene_var0BA0 < 0x30u) {
      Smbll_CODE_04F0ED(0xA0u);
    } else {
      Smbll_CODE_04F091(0xA0u);
    }
    goto LABEL_20;
  }
  if (cutscene_var0BA0 >= 0x58u) {
    Smbll_DrawToadAndRelatedSprites_Func18();
    R0_ = 32;
    R2_ = 4;
    Smbll_ImposeGravity_Far(1u, 0);
    cutscene_var0B9E = 1;
    if (obj_ypos_lo.enemy[0] >= 0xB0u) {
      if (obj_ypos_lo.enemy[0] >= 0xB8u) {
        obj_yspeed.enemy[0] = 0;
        obj_sub_yspeed.enemy[0] = 0;
        obj_sub_ypos.enemy[0] = 0;
        obj_ypos_lo.enemy[0] = -72;
        cutscene_var0B9E = 0;
        cutscene_var0B9F = 1;
        Smbll_DrawToadAndRelatedSprites_Func15();
      }
    } else {
      cutscene_var0B9D_oam_id = 1;
    }
    if (!cutscene_var0B9F && (frame_counter & 1) == 0)
      ++obj_xpos_lo.enemy[3];
  }
  Smbll_CODE_04F031();
  Smbll_DrawToadAndRelatedSprites_Func10();
}

void Smbll_CODE_04F031() {
  uint8 v0;  // di
  uint8 v1;  // di
  uint8 v2;  // al
  uint8 v3;  // di
  uint8 v4;  // al

  R0_ = rel_xpos_lo.enemy;
  R1_ = obj_ypos_lo.enemy[0];
  v0 = kbyte_B965F[cutscene_var0B9D_oam_id];
  Smbll_DrawToadAndRelatedSprites_Func11(v0, cutscene_var0B9E);
  v1 = v0 + 16;
  R0_ = rel_xpos_lo.enemy - obj_xpos_lo.enemy[3] - 7;
  v2 = cutscene_var0B9F - 1;
  if (cutscene_var0B9F != 1)
    v2 = cutscene_var0B9E + 4;
  Smbll_DrawToadAndRelatedSprites_Func11(v1, v2);
  v3 = v1 + 16;
  R0_ = obj_xpos_lo.enemy[3] + rel_xpos_lo.enemy + 7;
  v4 = cutscene_var0B9F - 1;
  if (cutscene_var0B9F != 1)
    v4 = cutscene_var0B9E + 6;
  Smbll_DrawToadAndRelatedSprites_Func11(v3, v4);
  if ((cutscene_var0BA0 & 0x80u) == 0)
    ++cutscene_var0BA0;
}

void Smbll_CODE_04F091(uint8 j) {
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

void Smbll_CODE_04F0ED(uint8 j) {
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

void Smbll_CODE_04F124(uint8 j) {
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

void Smbll_CutsceneToad_Func3() {
  uint8 v0;  // al
  int8 v1;   // si
  uint8 v2;  // di

  Smbll_DrawToadAndRelatedSprites_Func12();
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
        Smbll_DrawToadAndRelatedSprites_Func15();
        v0 = 2;
      }
      cutscene_var0B9E = v0;
      v1 = 3;
      v2 = 0;
      do {
        R0_ = cutscene_arr0BB0[(uint8)v1];
        R1_ = -72;
        Smbll_DrawToadAndRelatedSprites_Func11(v2, cutscene_var0B9E);
        v2 += 16;
        var0E67 = v2;
        --v1;
      } while (v1 >= 0);
    } else if (cutscene_toad_has_been_initialized_flag == 2) {
      Smbll_CODE_04F1D7();
    } else {
      Smbll_CODE_04F2AB();
    }
  }
  Smbll_DrawToadAndRelatedSprites_Func10();
}

void Smbll_CODE_04F1D7() {
  uint8 v0;  // di
  uint8 v1;  // al
  uint8 v2;  // al
  uint8 v3;  // di
  uint8 v4;  // al
  uint8 v5;  // di
  uint8 v6;  // al

  Smbll_DrawToadAndRelatedSprites_Func18();
  R0_ = 32;
  R2_ = 4;
  Smbll_ImposeGravity_Far(1u, 0);
  if (obj_ypos_lo.enemy[0] < 0xB0u)
    cutscene_var0B9D_oam_id = 1;
  v0 = kbyte_B965F[cutscene_var0B9D_oam_id];
  R0_ = rel_xpos_lo.enemy;
  v1 = obj_ypos_lo.enemy[0];
  if (obj_ypos_lo.enemy[0] >= 0xB8u) {
    v1 = -72;
    cutscene_arr0BB8[0] = 0;
  }
  R1_ = v1;
  Smbll_DrawToadAndRelatedSprites_Func11(v0, cutscene_arr0BB8[0]);
  R0_ = cutscene_arr0BB0[1];
  if ((uint8)(obj_ypos_lo.enemy[0] - 12) < 0xB8u) {
    if (frame_counter & 1)
      ++cutscene_arr0BB0[1];
    v2 = obj_ypos_lo.enemy[0] - 12;
  } else {
    v2 = -72;
    cutscene_arr0BB8[1] = 0;
  }
  R1_ = v2;
  v3 = v0 + 16;
  Smbll_DrawToadAndRelatedSprites_Func11(v3, cutscene_arr0BB8[1] + 6);
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
  Smbll_DrawToadAndRelatedSprites_Func11(v5, cutscene_arr0BB8[2] + 4);
  R0_ = cutscene_arr0BB0[3];
  v6 = obj_ypos_lo.enemy[0] - 36;
  if ((uint8)(obj_ypos_lo.enemy[0] - 36) < 0xB8u) {
    ++cutscene_arr0BB0[3];
  } else {
    cutscene_arr0BB8[3] = 0;
    ++cutscene_arr0BB4[0];
    cutscene_var0BA1 = 40;
    v6 = 4;
  }
  R1_ = v6;
  Smbll_DrawToadAndRelatedSprites_Func11(v5 + 16, cutscene_arr0BB8[3] + 6);
}

void Smbll_CODE_04F2AB() {
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
    oam[64].ypos = koff_B9B8F[i];
    oam[64].charnum = HIBYTE(koff_B9B8F[i]);
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
    if (kbyte_B9B88[j] >= cutscene_var0B9F)
      break;
  }
  v5 = j;
  R0_ = koff_B9B7A[v5];
  R1_ = HIBYTE(koff_B9B7A[v5]);
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

void Smbll_CutsceneToad_Func4() {
  uint8 v0;  // al

  Smbll_DrawToadAndRelatedSprites_Func12();
  if (cutscene_wait_before_toad_breaks_out_of_bag) {
    Smbll_DrawToadAndRelatedSprites_Func18();
    R0_ = 32;
    R2_ = 4;
    Smbll_ImposeGravity_Far(1u, 0);
    if (obj_ypos_lo.enemy[0] < 0xA0u)
      cutscene_var0B9D_oam_id = 1;
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
      Smbll_CODE_04F586();
      Smbll_DrawToadAndRelatedSprites_Func10();
    } else {
      if (cutscene_var0B9F == 68)
        sound_ch1 = 8;
      cutscene_var0B9F = 69;
      Smbll_CODE_04F412();
      Smbll_DrawToadAndRelatedSprites_Func15();
      Smbll_DrawToadAndRelatedSprites_Func10();
    }
  } else {
    Smbll_DrawToadAndRelatedSprites_Func10();
  }
}

void Smbll_CODE_04F412() {
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
      if (!cutscene_arr0BB8[v8])
        break;
      --v8;
    } while (v8);
    v9 = frame_counter & 3;
    cutscene_arr0BB0[v8] = ((frame_counter ^ *(&random_byte3 + (frame_counter & 3))) & 0x1F) - 52;
    cutscene_arr0BB4[v8] = ((frame_counter ^ *(&random_byte4 + v9)) & 7) - 80;
    ++cutscene_arr0BB8[v8];
  }
  for (j = 3; (j & 0x80u) == 0; --j) {
    R0_ = kbyte_B9D82[cutscene_arr0BB8[j] >> 3];
    v11 = get_OamEnt(oam_buf, (uint8)(4 * j));
    v11->xpos = cutscene_arr0BB0[j];
    v11->ypos = cutscene_arr0BB4[j];
    v11->charnum = R0_;
    v11->flags = 37;
  }
}

void Smbll_CODE_04F586() {
  uint8 v0;     // di
  uint8 v1;     // al
  OamEnt *oam;  // rdx
  uint8 v3;     // al
  uint8 v4;     // si
  OamEnt *v5;   // rbp

  v0 = kbyte_B965F[cutscene_var0B9D_oam_id];
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
    v5[64].charnum = kbyte_B9DDA[v4];
    v5[64].flags = kbyte_B9DEA[v4];
    oam_tile_size_buffer[v0 + 256] = 2;
    v0 += 4;
    ++v4;
    --R0_;
  } while (R0_);
}

void Smbll_CutsceneToad_Func5() {
  Smbll_DrawToadAndRelatedSprites_Func12();
  if (!cutscene_wait_before_toad_breaks_out_of_bag) {
    Smbll_DrawToadAndRelatedSprites_Func10();
    return;
  }
  Smbll_DrawToadAndRelatedSprites_Func18();
  R0_ = 32;
  R1_ = 4;
  Smbll_ImposeGravity_Far(1u, 0);
  if (obj_ypos_lo.enemy[0] < 0xA0u)
    cutscene_var0B9D_oam_id = 1;
  if (obj_ypos_lo.enemy[0] < 0xB8u) {
    Smbll_CODE_04F6F9(kbyte_B965F[cutscene_var0B9D_oam_id]);
    Smbll_DrawToadAndRelatedSprites_Func10();
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
  if (cutscene_var0BA0)
    goto LABEL_14;
  if (++cutscene_var0B9F >= 0x40u) {
    cutscene_var0B9F = 64;
LABEL_14:
    if (++cutscene_var0BA0 >= 0x88u)
      cutscene_var0BA0 = -120;
  }
  Smbll_CODE_04F74C();
  Smbll_DrawToadAndRelatedSprites_Func15();
  Smbll_DrawToadAndRelatedSprites_Func10();
}

void Smbll_CODE_04F6A4(uint8 j) {
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

void Smbll_CODE_04F6F9(uint8 j) {
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

void Smbll_CODE_04F74C() {
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
  if ((int8)(cutscene_var0B9F - 40) < 0)
    v0 = 0;
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
  if ((cutscene_var0BA0 & 0xF) == 15)
    sound_ch1 = 14;
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
    if (v9[64].xpos < 0x40u)
      v9[64].ypos = -16;
    v8 += 4;
  } while (v8);
}

void Smbll_CutsceneToad_Func6() {
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
    Smbll_DrawToadAndRelatedSprites_Func15();
    v0 = -48;
    cutscene_wait_before_toad_breaks_out_of_bag = -48;
  }
  v1 = v0 >> 3;
  if (v1 >= 3u)
    v1 = 3;
  v2 = v1;
  Smbll_CODE_04F8DC(v1);
  if (v2 == 2 && !cutscene_var0BA4) {
    sound_ch1 = 43;
    cutscene_var0BA4 = 43;
  }
  Smbll_DrawToadAndRelatedSprites_Func10();
}

void Smbll_CODE_04F8DC(uint8 a) {
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
  for (i = 0; i < 8u; ++i)
    get_OamEnt(oam_buf, i)[64].xpos = kbyte_BA1B5[v1++];
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

void Smbll_DrawToadAndRelatedSprites_Func10() {
  if (cutscene_toad_var0BA6) {
    if ((cutscene_toad_var0BA6 & 0x80u) == 0)
      --cutscene_toad_var0BA6;
  } else if (!cutscene_var0BA7) {
    ++cutscene_var0BA7;
    mario_goal_walk_var03ce = -72;
    if (!player_size)
      mario_goal_walk_var03ce = -56;
  }
}

void Smbll_DrawToadAndRelatedSprites_Func11(uint8 j, uint8 a) {
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
  oam[64].charnum = kbyte_BA24B[v2];
  oam[65].charnum = kbyte_BA24B[v2 + 1];
  oam[66].charnum = kbyte_BA24B[v2 + 2];
  oam[64].flags = kbyte_BA263[v2];
  oam[65].flags = kbyte_BA263[v2 + 1];
  oam[66].flags = kbyte_BA263[v2 + 2];
  oam_tile_size_buffer[j + 264] = 2;
}

void Smbll_DrawToadAndRelatedSprites_Func12() {
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
  R0_ = *((uint8 *)koff_BA2A7 + (uint8)(2 * v0));
  R1_ = *((uint8 *)koff_BA2A7 + (uint8)(2 * v0) + 1);
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

void Smbll_DrawToadAndRelatedSprites_Func13() {
  uint8 v0;  // di

  sound_ch1 = 15;
  mario_goal_walk_var03ce = 16 * (player_size ^ 1) - 32 + 8;
  v0 = -100;
  R1_ = 11;
  R0_ = 0;
  do
    RomPtr_RAM(*(uint16 *)&R0_)[v0++] = 0;
  while (v0 != 0xBF);
  ++cutscene_toad_has_been_initialized_flag;
  --cutscene_toad_var0BA6;
  R0_ = *((uint8 *)koff_BA3E4 + (uint8)(2 * world_number));
  R1_ = *((uint8 *)koff_BA3E4 + (uint8)(2 * world_number) + 1);
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

// local variable allocation has failed, the output may be wrong!
void Smbll_DrawToadAndRelatedSprites_Func14(uint8 j, uint16 a) {
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
// 23A0D: variables would overlap: al.1 and ax.2

void Smbll_DrawToadAndRelatedSprites_Func15() {
  if (mario_goal_walk_var03ce >= 0xD0u && (mario_goal_walk_var03ce & 8) != 0) {
    mario_goal_walk_var03ce -= 8;
    cutscene_toad_var0BA6 = 48;
  }
}

void Smbll_DrawToadAndRelatedSprites_Func16() {
  if ((uint8)layer3_xpos) {
    LOBYTE(layer3_xpos) = layer3_xpos - 1;
  } else if (cutscene_toad_var0BA3 >= 0xC0u) {
    Smbll_CODE_048600();
  } else if (++cutscene_toad_var0BA3 == 0xC0) {
    Smbll_DrawToadAndRelatedSprites_Func17();
  }
}

void Smbll_DrawToadAndRelatedSprites_Func18() {
  if (!cutscene_var0BA4) {
    sound_ch2 = 1;
    cutscene_var0BA4 = 1;
  }
}

void Smbll_DrawToadAndRelatedSprites_Func17() {
  *(uint16 *)&vram_buffer1[2] = -3750;
  *(uint16 *)&vram_buffer1[4] = 4864;
  *(uint16 *)&vram_buffer1[6] = 25;
  *(uint16 *)&vram_buffer1[8] = 30;
  *(uint16 *)&vram_buffer1[10] = 28;
  *(uint16 *)&vram_buffer1[12] = 17;
  strcpy((int8 *)&vram_buffer1[14], "(");
  *(uint16 *)&vram_buffer1[16] = 28;
  *(uint16 *)&vram_buffer1[18] = 29;
  *(uint16 *)&vram_buffer1[20] = 10;
  *(uint16 *)&vram_buffer1[22] = 27;
  *(uint16 *)&vram_buffer1[24] = 29;
  vram_buffer1[26] = -1;
  sound_ch3 = 21;
}

void Smbll_Dma_FillWith0x24() {
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

void Smbll_Dma_FillWith0x28() {
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

void Smbll_Dma_CODE_0480EF() {
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

void Smbll_HandleSfx() {
  uint8 v0;  // al
  uint8 v1;  // al
  uint8 v2;  // al
  uint8 v3;  // al

  v0 = sound_ch1;
  if (sound_ch1)
    goto LABEL_5;
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
  if ((ReadReg(APUI01) & 0xF) == apui01_last || (++apui01_delay, apui01_delay >= 3u)) {
    v1 = 0;
    goto LABEL_10;
  }
LABEL_11:
  v2 = music_ch1;
  if (music_ch1) {
    apui02_var160C = 4;
    WriteReg(APUI02, music_ch1);
    if (v2 < 0xF0u)
      apui02_var1606 = v2;
  } else if (ReadReg(APUI02) == apui02_var1606) {
    v3 = --apui02_var160C;
    if (!apui02_var160C) {
      ++apui02_var160C;
      WriteReg(APUI02, v3);
    }
  }
  if (!sound_ch3) {
    if ((ReadReg(APUI03) & 0x7F) == apui03_var1607 || (++apui03_delay, apui03_delay >= 3u)) {
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

void Smbll_InitializeGradientHDMA(uint8 a) {
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
    R1_ = kbyte_BA812[v1];
    v2 = kbyte_BA802[v1];
    v3 = 0;
    do {
      hdmagradient_red_channel_scanlines_and_ptrs_table[v3] = kbyte_BA970[v2];
      hdmagradient_green_channel_scanlines_and_ptrs_table[v3] = kbyte_BA9D2[v2];
      hdmagradient_blue_channel_scanlines_and_ptrs_table[v3++] = kbyte_BAA34[v2++];
    } while (v3 != R1_);
    R1_ = kbyte_BA81A[v1];
    v4 = kbyte_BA80A[v1];
    v5 = 0;
    do {
      hdmagradient_red_channel_data[v5] = kbyte_BAA96[v4];
      hdmagradient_green_channel_data[v5] = kbyte_BAAD6[v4];
      hdmagradient_blue_channel_data[v5++] = kbyte_BAB16[v4++];
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
      WriteRegWord(A1T4L, 0xA969u);
      WriteReg(A1B4, 0xBu);
      WriteReg(DAS40, 0xBu);
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

void Smbll_AdjustUnderwaterHDMAGradient() {
  uint8 v0;  // si
  uint8 v1;  // di
  uint8 v2;  // al

  if (!--underwater_hdma_gradient_timer) {
    v0 = underwater_hdma_gradient_index;
    underwater_hdma_gradient_timer = kbyte_BA92C[underwater_hdma_gradient_index];
    v1 = kbyte_BA924[underwater_hdma_gradient_index];
    v2 = kbyte_BA934[underwater_hdma_gradient_index] + hdmagradient_red_channel_scanlines_and_ptrs_table[v1];
    hdmagradient_red_channel_scanlines_and_ptrs_table[v1] = v2;
    hdmagradient_green_channel_scanlines_and_ptrs_table[v1] = v2;
    hdmagradient_blue_channel_scanlines_and_ptrs_table[v1] = v2;
    underwater_hdma_gradient_index = (v0 + 1) & 7;
  }
}

void Smbll_GiveExtraLife() {
  if (++number_of_lives >= 0x80u)
    number_of_lives = 127;
}

// nfuncs=779 queued=720 decompiled=720 lumina nreq=0 worse=0 better=0
// ALL OK, 720 function(s) have been successfully decompiled
