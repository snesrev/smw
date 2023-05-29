#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"

void (*kHandleCurrentOverworldProcess_PtrsLong04857D[13])(void) = {
    &OwProcess00_OverworldEntryInitialization,
    &OwProcess01_ActivateEvents,
    &OwProcess02_HandleLevelBeaten,
    &OwProcess03_StandingStill,
    &OwProcess04_PlayerIsMoving,
    &OwProcess05_CheckPlayerSwitch,
    &OwProcess08_PlayerSwitchFadeIn,
    &OwProcess07_SwitchingPlayers,
    &OwProcess08_PlayerSwitchFadeIn,
    &OwProcess09_FinishedSwitchingPlayers,
    &OwProcess0A_SwitchBetweenSubmaps,
    &OwProcess0B_StarWarpAnimation,
    &OwProcess0C_IntroMarch,
};
void (*kOverworldProcess0A_SwitchBetweenSubmaps_Ptrs04DAF8[8])(void) = {
    &SubmapSwitchProcess06_EndWindowHDMA, &SubmapSwitchProcess01_UpdateLayer1,    &SubmapSwitchProcess01_UpdateLayer1,
    &SubmapSwitchProcess01_UpdateLayer1,  &SubmapSwitchProcess01_UpdateLayer1,    &SubmapSwitchProcess05_UpdatePalette,
    &SubmapSwitchProcess06_EndWindowHDMA, &SubmapSwitchProcess07_EndSubmapSwitch,
};
void (*kOverworldProcess01_ActivateEvents_Ptrs04E577[8])(void) = {
    &OwEventProcess00_CheckIfEventShouldRun, &OwEventProcess06_FadeInLayer1Tile,
    &OwEventProcess02_SetEventTileIndexes,   &OwEventProcess03_GetLayer2Tile,
    &OwEventProcess04_FadeInLayer2Tile,      &OwEventProcess05_GetLayer1Tile,
    &OwEventProcess06_FadeInLayer1Tile,      &OwEventProcess07_SilentEventsAndEndOfEvent,
};
void (*kDisplayOwPrompt_Ptrs04F3EA[8])(void) = {
    &OwPrompt01_InitializeOwPrompt, &OwPrompt02_ExpandPromptWindow,
    &OwPrompt03_OverworldLifeExchanger,    &OwPrompt02_ExpandPromptWindow,
    &OwPrompt01_InitializeOwPrompt, &OwPrompt02_ExpandPromptWindow,
    &OwPrompt07_DisplayingSavePrompt,      &OwPrompt02_ExpandPromptWindow,
};
void (*kProcessOverworldSprites_OverworldSpritePtrs[11])(uint8 k) = {
    &OverworldLightningAndRandomCloudSpawning_Return04F828,
    &OWSpr01_Lakitu,
    &OWSpr02_BlueBird,
    &OWSpr03_CheepCheep,
    &OWSpr04_PiranhaPlant,
    &OWSpr05_Cloud,
    &OWSpr06_KoopaKid,
    &OWSpr07_Smoke,
    &OWSpr08_BowserSign,
    &OWSpr09_Bowser,
    &OWSpr0A_Boo,
};

void OwTileAnimations_ShiftWaterTiles() {  // 048086
  *(uint16 *)&R3_ = 0;
  *(uint16 *)&R5_ = 0;
  do {
    R0_W = kOwTileAnimations_WaterTileNumbers[*(uint16 *)&R3_ >> 1];
    R2_ = 126;
    OwTileAnimations_0480B9(*(uint16 *)&R5_);
    *(uint16 *)&R5_ += 32;
    *(uint16 *)&R3_ += 2;
  } while (R3_ != 6);
}

void OwTileAnimations_0480B9(uint16 k) {  // 0480b9
  uint16 v1 = 0;
  *(uint16 *)&R7_ = 8;
  *(uint16 *)&R9_ = 8;
  do {
    *(uint16 *)&sprites_cutscene_sprite_table_0AF6[k] = *(uint16 *)IndirPtr(&R0_W, v1);
    v1 += 2;
    k += 2;
    --*(uint16 *)&R7_;
  } while (*(uint16 *)&R7_);
  do {
    *(uint16 *)&sprites_cutscene_sprite_table_0AF6[k] = *IndirPtr(&R0_W, v1++);
    k += 2;
    --*(uint16 *)&R9_;
  } while (*(uint16 *)&R9_);
}

void OwTileAnimations() {  // 0480e0
  if ((counter_global_frames & 7) == 0) {
    for (uint8 i = 31; (i & 0x80) == 0; --i) {
      R0_ = sprites_cutscene_sprite_table_0AF6[i];
      if ((i & 8) != 0) {
        bool v1 = R0_ & 1;
        R0_ >>= 1;
        int8 v2 = 0;
        if (v1)
          v2 = 0x80;
        sprites_cutscene_sprite_table_0AF6[i] = (sprites_cutscene_sprite_table_0AF6[i] >> 1) + v2;
      } else {
        bool v1 = __CFSHL__(R0_, 1);
        R0_ *= 2;
        sprites_cutscene_sprite_table_0AF6[i] = 2 * sprites_cutscene_sprite_table_0AF6[i] + v1;
      }
    }
  }
  if ((counter_global_frames & 7) == 0)
    OwTileAnimations_048172(0x20);
  if ((counter_global_frames & 7) == 0) {
    for (uint8 j = 31; (j & 0x80) == 0; --j)
      sprites_cutscene_sprite_sub_xpos[j + 4] =
          2 * sprites_cutscene_sprite_sub_xpos[j + 4] + __CFSHL__(sprites_cutscene_sprite_sub_xpos[j + 4], 1);
    OwTileAnimations_048172(0x40);
  }
  *(uint16 *)&R13_ = 96;
  *(uint16 *)&R11_ = 0;
  do {
    int16 v4 = 56;
    if (*(uint16 *)&R11_ < 0x20)
      v4 = 112;
    int16 v5 = (uint16)(*(uint16 *)&counter_global_frames & v4) >> 2;
    if (v4 != 56)
      v5 = (uint16)(*(uint16 *)&counter_global_frames & v4) >> 3;
    R0_W = kOwTileAnimations_TileNumbers[(uint16)(*(uint16 *)&R11_ + v5) >> 1];
    R2_ = 126;
    OwTileAnimations_0480B9(*(uint16 *)&R13_);
    *(uint16 *)&R13_ += 32;
    *(uint16 *)&R11_ += 16;
  } while (*(uint16 *)&R11_ != 128);
}

void OwTileAnimations_048172(uint8 k) {  // 048172
  int8 v1 = 0;
LABEL_2:
  R0_W = *(uint16 *)&sprites_cutscene_sprite_table_0AF6[(uint8)(k + 14)];
  do {
    R2_W = *(uint16 *)&sprites_cutscene_sprite_table_0AF6[k];
    *(uint16 *)&sprites_cutscene_sprite_table_0AF6[k] = R0_W;
    R0_W = R2_W;
    k += 2;
    if (++v1 == 8)
      goto LABEL_2;
  } while (v1 != 16);
}

void GameMode0E_ShowOverworld_Bank04() {  // 048241
  int16 v3;
  int16 v5;
  uint8 v15;

  sub_485A7();
  OwTileAnimations();
  if (misc_color_of_palace_switch_pressed1) {
    DrawFlyingSwitchBlocks();
LABEL_52:
    OverworldLightningAndRandomCloudSpawning();
    goto LABEL_53;
  }
  if (!flag_show_continue_and_end) {
    if (pointer_display_overworld_prompt && (pointer_display_overworld_prompt >= 5 || flag_two_player_game)) {
      DisplayOwPrompt(pointer_display_overworld_prompt);
      return;
    }
    if (flag_pause >> 1) {
      uint16 v1 = ow_scroll_camera_ypos - mirror_current_layer1_ypos;
      *(uint16 *)&R1_ = ow_scroll_camera_ypos - mirror_current_layer1_ypos;
      if ((int16)(ow_scroll_camera_ypos - mirror_current_layer1_ypos) < 0)
        v1 = mirror_current_layer1_ypos - ow_scroll_camera_ypos;
      R5_ = v1 >> 1;
      uint16 v2 = ow_scroll_camera_xpos - mirror_current_layer1_xpos;
      R0_W = ow_scroll_camera_xpos - mirror_current_layer1_xpos;
      if ((int16)(ow_scroll_camera_xpos - mirror_current_layer1_xpos) < 0)
        v2 = mirror_current_layer1_xpos - ow_scroll_camera_xpos;
      v3 = v2 >> 1;
      R4_ = v3;
      uint8 v4 = 1;
      if ((uint8)v3 < R5_) {
        v4 = 0;
        LOBYTE(v3) = R5_;
      }
      if ((uint8)v3 >= 2) {
        WriteReg(WRDIVL, 0);
        WriteReg(WRDIVH, *(&R4_ + v4));
        WriteReg(WRDIVB, v3);
        v5 = ReadRegWord(RDDIVL) >> 2;
        if ((*(&R1_ + v4) & 0x80) != 0)
          LOBYTE(v5) = -(int8)v5;
        *(&R1_ + v4) = v5;
        uint8 v6 = v4 ^ 1;
        uint8 v7 = 64;
        if ((*(&R1_ + v6) & 0x80) != 0)
          v7 = -64;
        *(&R1_ + v6) = v7;
        uint8 v8 = 1;
        do {
          uint16 t0 = *(&ow_layer1_sub_xpos + v8) + (uint8)(16 * *(&R1_ + v8));
          *(&ow_layer1_sub_xpos + v8) = t0;
          uint16 t = *(&mirror_current_layer1_xpos + v8) + ((int8)*(&R1_ + v8) >> 4) + (t0 >> 8);
          *(&mirror_current_layer1_xpos + v8) = t;
          *(&mirror_current_layer2_xpos + v8) = t;
        } while ((int8)--v8 >= 0);
        goto LABEL_52;
      }
      mirror_current_layer1_xpos = ow_scroll_camera_xpos;
      mirror_current_layer2_xpos = ow_scroll_camera_xpos;
      mirror_current_layer1_ypos = ow_scroll_camera_ypos;
      mirror_current_layer2_ypos = ow_scroll_camera_ypos;
      flag_pause = 0;
    } else {
      if (pointer_current_overworld_process == 3 || pointer_current_overworld_process == 4 && !flag_switch_players) {
        if (((io_controller_press2_copyp2 | io_controller_press2_copyp1) & 0x30) != 0)
          pointer_display_overworld_prompt = 1;
        if (!ow_players_map[player_current_character] && (io_controller_press1 & 0x10) != 0 && !(++flag_pause >> 1)) {
          ow_scroll_camera_xpos = mirror_current_layer1_xpos;
          ow_scroll_camera_ypos = mirror_current_layer1_ypos;
        }
      }
      if (!flag_pause) {
        if (!ow_active_earthquake_event)
          goto LABEL_51;
        if (ow_active_earthquake_event == 0xFE) {
          io_sound_ch1 = 33;
          io_music_ch1 = 8;
        }
        if ((kGameMode0E_ShowOverworld_DATA_048231[ow_active_earthquake_event >> 4] & counter_global_frames) == 0) {
          LOBYTE(mirror_current_layer1_xpos) = mirror_current_layer1_xpos ^ 1;
          LOBYTE(mirror_current_layer2_xpos) = mirror_current_layer1_xpos;
          LOBYTE(mirror_current_layer1_ypos) = mirror_current_layer1_ypos ^ 1;
          LOBYTE(mirror_current_layer2_ypos) = mirror_current_layer1_ypos;
        }
        if (ow_active_earthquake_event >= 0x80 || pointer_current_overworld_process == 2) {
          if (!--ow_active_earthquake_event)
            io_sound_ch1 = 34;
        } else {
LABEL_51:
          HandleCurrentOverworldProcess();
        }
        goto LABEL_52;
      }
      GameMode0E_ShowOverworld_UpdateMainMapFreeScrollingPosition(0, 2 * (io_controller_hold1 & 3));
      GameMode0E_ShowOverworld_UpdateMainMapFreeScrollingPosition(2, (uint8)(io_controller_hold1 & 0xC | 0x10) >> 1);
      v15 = 21;
      if ((counter_global_frames & 0x18) != 0)
        goto LABEL_41;
    }
    v15 = 24;
LABEL_41:
    graphics_stripe_image_to_upload = v15;
    goto LABEL_52;
  }
  DisplayingContinueEnd(flag_show_continue_and_end);
LABEL_53:
  DrawOverworldPlayer();
}

void GameMode0E_ShowOverworld_UpdateMainMapFreeScrollingPosition(uint8 k, uint8 a) {  // 048415
  int v2 = a >> 1;
  uint16 v3 = kGameMode0E_ShowOverworld_DATA_048211[v2] + *(uint16 *)((int8 *)&mirror_current_layer1_xpos + k);
  if (__CFSHL__uint16(kGameMode0E_ShowOverworld_DATA_048211[v2] ^ (v3 - kGameMode0E_ShowOverworld_DATA_048221[v2]))) {
    *(uint16 *)((int8 *)&mirror_current_layer1_xpos + k) = v3;
    *(uint16 *)((int8 *)&mirror_current_layer2_xpos + k) = v3;
  }
}

bool HandleOverworldStarPipeWarp_GetIndex() {  // 048509
  uint8 result;
  R1_ = ow_players_map[player_current_character];
  R0_ = 0;
  for (result = 52; (result & 0x80) == 0; result -= 2) {
    int v1 = result >> 1;
    if ((uint16)(R0_W ^ kHandleOverworldStarPipeWarp_DATA_048431[v1]) < 0x200) {
      PointU16 *pt = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
      if ((R0_W ^ kHandleOverworldStarPipeWarp_DATA_048431[v1]) == pt->x && pt->y == kHandleOverworldStarPipeWarp_DATA_048467[v1]) {
        break;
      }
    }
  }
  ow_star_pipe_index = result;
  return result != 0xff;
}

void HandleOverworldStarPipeWarp_SetPlayerDestination() {  // 04853b
  uint8 v0 = player_current_characterx4;
  int v1 = ow_star_pipe_index >> 1;
  uint16 v5 = kHandleOverworldStarPipeWarp_DATA_04849D[v1];
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  pt->x = v5 & 0x1FF;
  PointU16 *v3 = get_PointU16(ow_players_grid_aligned_pos, v0);
  v3->x = (uint16)(v5 & 0x1FF) >> 4;
  uint16 v4 = kHandleOverworldStarPipeWarp_DATA_0484D3[v1];
  pt->y = v4;
  v3->y = v4 >> 4;
  ow_currently_loaded_submap = ((uint16)(v5 >> 1) >> 8) & 0xF;
  HandleOverworldPathExits_SetLayerPositions();
}

void HandleCurrentOverworldProcess() {  // 048576
  kHandleCurrentOverworldProcess_PtrsLong04857D[pointer_current_overworld_process]();
}

void sub_485A4() {  // 0485a4
  DrawOverworldPlayer();
  sub_485A7();
}

void sub_485A7() {  // 0485a7
  player_xpos = mirror_current_layer1_xpos + 30;
  player_ypos = mirror_current_layer1_ypos + 6;
  player_xspeed = 8;
  SetPlayerPose();
  player_current_layer_priority = 3;
  PlayerDraw();
  player_number_of_tiles_to_update = 6;
  if (player_anim_timer)
    --player_anim_timer;
  if (timer_cape_flap_animation)
    --timer_cape_flap_animation;
  R0_ = 24;
  R1_ = 7;
  uint8 v0 = 0;
  uint8 v1 = 0;
  do {
    uint8 v2 = R0_;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam->xpos = R0_;
    R0_ = v2 + 8;
    oam->ypos = R1_;
    oam->charnum = 126;
    oam->flags = 54;
    sprites_oamtile_size_buffer[v0++] = 0;
    if ((v0 & 3) == 0) {
      R0_ = 24;
      R1_ += 8;
    }
    v1 += 4;
  } while (v0 != 16);
}

void DrawOverworldPlayer() {  // 04862e
  uint16 v7;
  uint16 v2;
  uint16 v5;

  R0_W = 0;
  R4_W = 0;

  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  uint16 v1 = pt->x - mirror_current_layer1_xpos;
  if (v1 >= 0x100 || (R0_W = pt->x - mirror_current_layer1_xpos, R8_W = v1, v2 = pt->y - mirror_current_layer1_ypos, v2 >= 0x100)) {
    v2 = 240;
  }
  R2_W = v2;
  R10_W = v2;
  PointU16 *v3 = get_PointU16(ow_players_pos, player_current_characterx4 ^ 4);
  uint16 v4 = v3->x - mirror_current_layer1_xpos;
  if (v4 >= 0x100 || (R4_W = v3->x - mirror_current_layer1_xpos, R12_W = v4, v5 = v3->y - mirror_current_layer1_ypos, v5 >= 0x100)) {
    v5 = 240;
  }
  R6_W = v5;
  R14_W = v5;
  R0_ -= 8;
  R1_ = R2_ - 9;
  R2_ = R4_ - 8;
  R3_ = R6_ - 9;
  temp8c = 3;
  R6_ = R0_;
  temp8a = R0_;
  R7_ = R1_;
  temp8b = R1_;
  uint8 v6 = *((uint8 *)ow_players_animation + ((uint8)player_current_characterx4 >> 1));
  if (v6 != 18 && (v6 < 7 || v6 >= 0xF)) {
    temp8b -= 5;
    R7_ = temp8b;
  }
  LOBYTE(v7) = HIBYTE(player_current_characterx4);
  HIBYTE(v7) = player_current_characterx4;
  R4_W = v7 >> 1;
  DrawOverworldPlayer_DrawHalo(0);
  DrawOverworldPlayer_DrawCurrentPlayer(0, player_current_characterx4 >> 1);
  sprites_oamtile_size_buffer[39] = 0;
  sprites_oamtile_size_buffer[40] = 0;
  sprites_oamtile_size_buffer[41] = 0;
  sprites_oamtile_size_buffer[42] = 0;
  sprites_oamtile_size_buffer[43] = 0;
  sprites_oamtile_size_buffer[44] = 0;
  sprites_oamtile_size_buffer[45] = 0;
  sprites_oamtile_size_buffer[46] = 0;
  temp8c = 3;
  uint8 v8 = ow_players_map[0];
  if (pointer_current_overworld_process == 10)
    v8 = ow_players_map[0] ^ 1;
  if (v8 == ow_players_map[1]) {
    R6_ = R2_;
    temp8a = R2_;
    R7_ = R3_;
    temp8b = R3_;
    uint8 v9 = *((uint8 *)ow_players_animation + (((uint8)player_current_characterx4 >> 1) ^ 2));
    if (v9 != 18 && (v9 < 7 || v9 >= 0xF)) {
      temp8b -= 5;
      R7_ = temp8b;
    }
    if (flag_two_player_game && R12_W < 0xF0 && R14_W < 0xF0) {
      R4_W ^= 0x200;
      DrawOverworldPlayer_DrawHalo(0x20);
      DrawOverworldPlayer_DrawCurrentPlayer(0x20, (player_current_characterx4 >> 1) ^ 2);
      sprites_oamtile_size_buffer[47] = 0;
      sprites_oamtile_size_buffer[48] = 0;
      sprites_oamtile_size_buffer[49] = 0;
      sprites_oamtile_size_buffer[50] = 0;
      sprites_oamtile_size_buffer[51] = 0;
      sprites_oamtile_size_buffer[52] = 0;
      sprites_oamtile_size_buffer[53] = 0;
      sprites_oamtile_size_buffer[54] = 0;
    }
  }
}

void DrawOverworldPlayer_DrawHalo(uint16 k) {  // 048789
  uint16 v1;

  int16 v5 = *(uint16 *)&temp8a;
  LOBYTE(v1) = HIBYTE(R4_W);
  HIBYTE(v1) = R4_W;
  if (*(int16 *)(&player_current_character + (v1 >> 1)) < 0) {
    uint8 v2 = temp8a;
    OamEnt *oam = get_OamEnt(oam_buf, k);
    oam[45].xpos = temp8a;
    oam[46].xpos = v2 + 8;
    int8 v4 = temp8b - 7;
    oam[45].ypos = temp8b - 7;
    oam[46].ypos = v4;
    oam[45].charnum = 124;
    oam[46].charnum = 124;
    oam[45].flags = 32;
    oam[46].flags = 96;
  }
  *(uint16 *)&temp8a = v5;
}

uint8 DrawOverworldPlayer_DrawCurrentPlayer(uint8 k_in, uint8 j) {  // 04894f
  uint16 v3;
  uint16 v5;
  uint16 k = k_in;

  int16 v2 = k;
  v3 = j >> 1;
  if (players_has_yoshi[(uint8)v3]) {
    R14_ = players_has_yoshi[(uint8)v3];
    R15_ = 0;
    LOBYTE(v3) = j;
    temp8c = 7;
    R0_W = 16 * ow_players_animation[v3 >> 1];
    uint16 v7 = R0_W + 2 * (counter_global_frames & 8);
    if (!k && *(uint16 *)&pointer_current_overworld_process == 11)
      v7 = kDrawOverworldPlayer_StarWarpAnimationOffset[(uint8)(counter_global_frames & 0xC) >> 2];
    do {
      uint16 v12 = v7;
      uint16 v8 = v7 >> 1;
      OamEnt *oam = get_OamEnt(oam_buf, k);
      oam[39].xpos = temp8a + kDrawOverworldPlayer_PlayerAndYoshiXDisp[v8];
      oam[39].ypos = temp8b + kDrawOverworldPlayer_PlayerAndYoshiYDisp[v8];
      uint16 v10 = v12;
      uint16 v11 = *(uint16 *)&kDrawOverworldPlayer_PlayerRidingYoshiTilesAndProp[v12];
      if (v11 != 0xffff) {
        uint16 v13 = *(uint16 *)&kDrawOverworldPlayer_PlayerRidingYoshiTilesAndProp[v12];
        uint16 v14;
        if ((v11 & 0xF00) == 512) {
          R8_W = v10;
          v14 = kDrawOverworldPlayer_YoshiPalette[(uint16)(R14_W - 4) >> 1] | v13 & 0xF0FF;
          v10 = R8_W;
        } else {
          v14 = R4_W + v13;
        }
        *(uint16 *)&oam[39].charnum = v14;
      }
      k = k + 4;
      v7 = v10 + 2;
      --temp8c;
    } while ((temp8c & 0x80) == 0);
  } else {
    LOBYTE(v3) = j;
    R0_W = 16 * ow_players_animation[v3 >> 1];
    uint16 v4 = R0_W + (counter_global_frames & 0x18);
    LOBYTE(v5) = HIBYTE(R4_W);
    HIBYTE(v5) = R4_W;
    if (*(int16 *)(&player_current_character + (v5 >> 1)) >= 0) {
      if (!k && *(uint16 *)&pointer_current_overworld_process == 11)
        v4 = kDrawOverworldPlayer_StarWarpAnimationOffset[(uint8)(counter_global_frames & 0xC) >> 2];
    } else {
      v4 = R0_W;
    }
    do {
      OamEnt *v6 = get_OamEnt(oam_buf, k);
      *(uint16 *)&v6[39].xpos = *(uint16 *)&temp8a;
      *(uint16 *)&v6[39].charnum = R4_W + kDrawOverworldPlayer_PlayerTilesAndProp[v4 >> 1];
      k = k + 4;
      v4 += 2;
      temp8a += 8;
      if ((--temp8c & 1) != 0) {
        temp8a = R6_;
        temp8b += 8;
      }
    } while ((temp8c & 0x80) == 0);
  }
  return k;
}

void GameMode0C_LoadOverworld_048D91() {  // 048d91
  flag_change_submap_music_on_player_switch = 0;
  LOBYTE(get_PointU16(l1_l2_scroll_spr_sub_pos, 0)->x) = 15;
  int8 v0 = 2;
  if (LOBYTE(ow_players_animation[0]) == 18 || (ow_players_animation[0] & 8) != 0)
    v0 = 10;
  LOBYTE(ow_players_animation[0]) = v0;
  int8 v1 = 2;
  if (LOBYTE(ow_players_animation[1]) == 18 || (ow_players_animation[1] & 8) != 0)
    v1 = 10;
  LOBYTE(ow_players_animation[1]) = v1;
  GameMode0C_LoadOverworld_048E55();
  if (!(misc_exit_level_action << 8) || (misc_exit_level_action & 0x80) != 0 || ow_level_number_lo != 24) {
    if (misc_currently_active_boss_end_cutscene) {
      *(uint16 *)&misc_currently_active_boss_end_cutscene = yoshi_current_yoshi_color << 8;
      PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
      R0_W = pt->x >> 4;
      R2_W = pt->y >> 4;
      CalculateOverworldPlayerPosition((uint8)player_current_characterx4 >> 2);
      if ((ow_level_tile_settings[ow_level_number_of_each_tiletbl[R4_W]] & 0x80) == 0) {
        uint16 v3 = 20;
        while (ow_level_number_lo != kGameMode0C_LoadOverworld_DATA_048D74[v3 >> 1]) {
          v3 -= 2;
          if ((v3 & 0x8000) != 0)
            return;
        }
      }
    }
    io_music_ch1 = kGameMode0C_LoadOverworld_DATA_048D8A[ow_players_map[player_current_character]];
  }
}

void GameMode0C_LoadOverworld_048E55() {  // 048e55
  player_current_characterx4 = 4 * player_current_character;
  PointU16 *pt = get_PointU16(ow_players_grid_aligned_pos, 4 * player_current_character);
  R0_W = pt->x;
  R2_W = pt->y;
  CalculateOverworldPlayerPosition((uint16)(4 * player_current_character) >> 2);
  R0_W = 0;
  R0_W = kLevelNames[(uint16)(2 * ow_level_number_of_each_tiletbl[R4_W]) >> 1];
  UpdateLevelName();
  if (R4_W <= 0x7FF)
    ow_tile_player_is_standing_on = blocks_map16_table_lo[R4_W];
  if (ow_enter_level_flag) {
    if ((ow_enter_level_flag & 0x80) == 0) {
      if ((misc_exit_level_action & 0x80) == 0)
        owspr_spriteid[ow_enter_level_flag] = 0;
    } else {
      owspr_table0df5[ow_enter_level_flag & 0x7F] = 0;
      if ((misc_exit_level_action & 0x80) == 0) {
        owspr06_koopa_kid_activate_flag |= kOWSpr06_KoopaKid_DATA_04FB85[owspr06_koopa_kid_tile_index];
      } else {
        int v1 = (uint8)(2 * owspr06_koopa_kid_tile_index) >> 1;
        PointU16 *v2 = get_PointU16(ow_players_pos, player_current_characterx4);
        v2->x = kGameMode0C_LoadOverworld_KoopaKidTeleportXPos[v1];
        v2->y = kGameMode0C_LoadOverworld_KoopaKidTeleportYPos[v1];
      }
    }
  }
  OwProcess04_PlayerIsMoving_049831();
  sub_485A4();
  OwTileAnimations_ShiftWaterTiles();
  OwTileAnimations();
}

void OwProcess00_OverworldEntryInitialization() {  // 048ef1
  PointU16 *v0;

  timer_keep_game_mode_active = 8;
  if (ow_players_map[0] == 1 && (v0 = get_PointU16(ow_players_pos, 0), LOBYTE(v0->x) == 104) && LOBYTE(v0->y) == 0x8E) {
    pointer_current_overworld_process = 12;
  } else {
    PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
    R0_W = pt->x >> 4;
    R2_W = pt->y >> 4;
    CalculateOverworldPlayerPosition((uint8)player_current_characterx4 >> 2);
    if (flag_got_midpoint && misc_exit_level_action) {
      if ((misc_exit_level_action & 0x80) == 0) {
        *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[R4_W]] =
            *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[R4_W]] & 0xFF3F | 0x80;
        ++*(uint16 *)&pointer_current_overworld_process;
        goto LABEL_11;
      }
      *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[R4_W]] |= 0x40;
    }
    pointer_current_overworld_process = 5;
  }
LABEL_11:
  OwProcess04_PlayerIsMoving_049831();
}

void OwProcess02_HandleLevelBeaten() {  // 048f87
  UnlockOverworldPathBasedOnExit();
  uint8 v0 = 7;
  while ((uint8)ow_tile_player_is_standing_on != kOverworldProcess02_HandleLevelBeaten_DATA_048F7F[v0]) {
    if ((--v0 & 0x80) != 0)
      goto LABEL_10;
  }
  for (uint8 i = 44; (i & 0x80) == 0; --i)
    ow_save_buffer[i + 96] = ow_event_flags[i];
  uint16 v2 = player_current_characterx4;
  uint16 v3 = player_current_characterx4 ^ 4;
  *(uint16 *)&ow_save_buffer[(player_current_characterx4 ^ 4) + 117] = *(uint16 *)&ow_save_buffer[player_current_characterx4 + 117];
  *(uint16 *)&ow_save_buffer[v3 + 119] = *(uint16 *)&ow_save_buffer[v2 + 119];
  *(uint16 *)&ow_save_buffer[v3 + 125] = *(uint16 *)&ow_save_buffer[v2 + 125];
  *(uint16 *)&ow_save_buffer[v3 + 127] = *(uint16 *)&ow_save_buffer[v2 + 127];
  v2 >>= 1;
  *(uint16 *)&ow_save_buffer[(v2 ^ 2) + 113] = *(uint16 *)&ow_save_buffer[v2 + 113];
  ow_save_buffer[(((uint8)v2 >> 1) ^ 1) + 111] = ow_save_buffer[((uint8)v2 >> 1) + 111];
  if (misc_exit_level_action == 0xE0) {
    if ((--timer_keep_game_mode_active & 0x80) == 0)
      return;
    ++flag_show_save_prompt;
    UpdateSaveBuffer();
    timer_keep_game_mode_active = 2;
    pointer_current_overworld_process = 4;
  } else {
    ++flag_show_save_prompt;
  }
LABEL_10:
  R6_W = 0;
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  R0_W = pt->x >> 4;
  R2_W = pt->y >> 4;
  CalculateOverworldPlayerPosition((uint8)player_current_characterx4 >> 2);
  ow_tile_player_is_standing_on = blocks_map16_table_lo[R4_W];
  ++pointer_current_overworld_process;
}

void UpdateSaveBuffer() {  // 049037
  if (flag_show_save_prompt) {
    for (uint8 i = 95; (i & 0x80) == 0; --i)
      ow_save_buffer[i] = ow_level_tile_settings[i];
    flag_show_save_prompt = 0;
    pointer_display_overworld_prompt = 5;
  }
}

void OwProcess03_StandingStill() {  // 049120
  uint16 v10;
  uint8 v0 = 0x91;  // note: undefined
  uint16 j;
  uint16 v16;

  flag_switch_players = 0;
  if ((ow_enter_level_flag & 0x80) == 0) {
    if ((int8)misc_exit_level_action > 0)
      goto LABEL_18;
    if ((io_controller_hold2 & 0x30) == 48 && (uint8)ow_tile_player_is_standing_on == 0x81)
      goto LABEL_15;
    if (((io_controller_press2 | io_controller_press1) & 0xC0) == 0)
      goto LABEL_18;
    flag_change_submap_music_on_player_switch = 0;
    if ((uint8)ow_tile_player_is_standing_on == 95) {
      if (HandleOverworldStarPipeWarp_GetIndex()) {
        ow_star_launch_speed = 0;
        timer_wait_before_star_launch = 0;
        io_sound_ch1 = 13;
        pointer_current_overworld_process = 11;
        OwProcess0B_StarWarpAnimation();
      }
      return;
    }
    v0 = ow_tile_player_is_standing_on;
    if ((uint8)ow_tile_player_is_standing_on == 0x82 || (uint8)ow_tile_player_is_standing_on == 91) {
      if (HandleOverworldStarPipeWarp_GetIndex()) {
        ++ow_warping_on_pipe_or_star_flag;
        misc_exit_level_action = 0;
        misc_game_mode = 11;
      }
      return;
    }
  }
  if (v0 <= 0x80) {
LABEL_15:;
    uint8 v1 = ((uint8)player_current_characterx4 >> 1) & 2;
    int8 v2 = 16;
    if ((*((uint8 *)ow_players_animation + v1) & 8) != 0)
      v2 = 18;
    *((uint8 *)ow_players_animation + v1) = v2;
    player_current_coin_count = players_coins[player_current_character];
    player_current_life_count = players_lives[player_current_character];
    player_current_power_up = players_power_up[player_current_character];
    yoshi_carry_over_levels_flag = players_has_yoshi[player_current_character];
    yoshi_current_yoshi_color = yoshi_carry_over_levels_flag;
    player_riding_yoshi_flag = yoshi_carry_over_levels_flag;
    player_current_item_box = players_item_box[player_current_character];
    timer_keep_game_mode_active = 2;
    io_music_ch1 = 0x80;
    ++misc_game_mode;
    return;
  }
LABEL_18:;
  uint8 v3 = player_current_characterx4;
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  R0_W = pt->x >> 4;
  PointU16 *v5 = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
  v5->x = R0_W;
  R2_W = pt->y >> 4;
  v5->y = R2_W;
  CalculateOverworldPlayerPosition(v3 >> 2);
  if (misc_exit_level_action) {
    R8_ = kSharedOverworldPathTables_DATA_049060[(uint8)(misc_exit_level_action - 1)];
    R9_ = 0;
    for (uint16 i = 10; (i & 0x8000) == 0; i -= 2) {
      if (ow_level_number_of_each_tiletbl[R4_W] == kSharedOverworldPathTables_NoAutoMoveLevels[i >> 1]) {
        *(uint16 *)&pointer_current_overworld_process = 5;
        UpdateSaveBuffer();
        goto LABEL_63;
      }
    }
    uint16 v7 = ow_level_direction_flags[R4_W];
    int16 v8 = R8_W;
    if (R8_W) {
      do {
        v7 >>= 1;
        --v8;
      } while (v8 >= 0);
    }
    j = kSharedOverworldPathTables_DATA_049064[(uint16)(2 * (v7 & 3)) >> 1];
  } else {
    misc_exit_level_action = 0;
    LOBYTE(v10) = io_controller_press1 & 0xF;
    if ((io_controller_press1 & 0xF) == 0) {
      PointU16 *v11 = get_PointU16(l1_l2_scroll_spr_sub_pos, 0);
      if ((int8)--LOBYTE(v11->x) < 0) {
        LOBYTE(v11->x) = 0;
        *((uint8 *)ow_players_animation + (((uint8)player_current_characterx4 >> 1) & 2)) =
            *((uint8 *)ow_players_animation + (((uint8)player_current_characterx4 >> 1) & 2)) & 8 | 2;
      }
      goto LABEL_63;
    }
    if ((uint8)ow_tile_player_is_standing_on != 0x82) {
      R6_W = 0;
      v10 = ow_level_tile_settings[ow_level_number_of_each_tiletbl[R4_W]] & (uint8)v10 & 0xF;
      if (!v10)
        goto LABEL_63;
    }
    v10 = (uint8)v10;
    for (j = 6; (j & 0x8000) == 0; j -= 2) {
      int8 v13 = v10 & 1;
      v10 >>= 1;
      if (v13)
        break;
    }
  }
  *(uint16 *)&ow_player_direction = j;
  uint16 v14 = 0;
  if (j < 4)
    v14 = 2;
  R8_W = R4_W;
  *(uint16 *)((int8 *)&R0_W + v14) += kSharedOverworldPathTables_DATA_049058[j >> 1];
  int16 v22;
  uint16 v15 = CalculateOverworldPlayerPosition(player_current_characterx4 >> 2);
  if ((R4_W & 0x8000) == 0 && v15 < 0x800) {
    v16 = blocks_map16_table_lo[R4_W];
    if (blocks_map16_table_lo[R4_W]) {
      if (v16 <= 0x86) {
LABEL_53:
        ow_tile_player_is_standing_on = v16;
        R0_W = v16;
        R2_W = 0;
        for (uint16 k = 23; (k & 0x8000) == 0; --k) {
          if (kSharedOverworldPathTables_DATA_04A03C[k] == R0_W) {
            int16 v29 = player_current_characterx4 + WORD(kSharedOverworldPathTables_DATA_04A0E4[k]);
            int v21 = (uint16)(4 * k) >> 1;
            R0_W = kSharedOverworldPathTables_DATA_04A084[v21];
            R2_W = kSharedOverworldPathTables_DATA_04A084[v21 + 1];
            v22 = (uint8)v29;
            goto LABEL_62;
          }
        }
        uint16 v23 = 8;
        if ((j & 2) == 0)
          v23 = -8;
        R0_W = v23;
        int16 v24 = 0;
        if (j < 4)
          v24 = 2;
        v22 = player_current_characterx4 + v24;
LABEL_62:;
        uint16 v25 = get_PointU16(ow_players_pos, v22)->x + R0_W;
        get_PointU16(players_overworld_xpos_is_going_to, v22)->x = v25;
        uint16 v26 = v22 ^ 2;
        uint16 v27 = get_PointU16(ow_players_pos, v26)->x + R2_W;
        get_PointU16(players_overworld_xpos_is_going_to, v26)->x = v27;
        R0_W = j;
        int v28 = (uint16)((v26 >> 1) & 2) >> 1;
        ow_players_animation[v28] = j | ow_players_animation[v28] & 8;
        get_PointU16(l1_l2_scroll_spr_sub_pos, 0)->x = 15;
        ++*(uint16 *)&pointer_current_overworld_process;
        *(uint16 *)l1_l2_scroll_spr_timer = 0;
        goto LABEL_63;
      }
    }
  }
  ow_process_hardcoded_path_flag = 0;
  ow_hardcoded_path_index = 0;
  R0_W = ow_level_number_of_each_tiletbl[R8_W];
  uint16 v17 = 9;
  while (kSharedOverworldPathTables_HardCodedOWPaths_LevelNums[v17] != 255) {
    if (kSharedOverworldPathTables_HardCodedOWPaths_LevelNums[v17] == R0_W)
      goto LABEL_49;
LABEL_51:
    if ((--v17 & 0x8000) != 0)
      goto LABEL_52;
  }
  PointU16 *v18 = get_PointU16(ow_players_pos, player_current_characterx4);
  if (v18->y != kSharedOverworldPathTables_DATA_049082 || v18->x != kSharedOverworldPathTables_DATA_049084 ||
      ow_players_map[player_current_character]) {
    goto LABEL_51;
  }
LABEL_49:
  R0_W = v17;
  uint16 v19 = kSharedOverworldPathTables_HardCodedOWPaths_Layer1AndMovementTableIndex[v17];
  ow_hardcoded_path_index = v19 - 1;
  R2_W = j;
  if (kSharedOverworldPathTables_HardCodedOWPaths_MovementDirection[v19] == j) {
    ow_process_hardcoded_path_flag = 1;
    v16 = kSharedOverworldPathTables_HardCodedOWPaths_Layer1Tiles[v19];
    goto LABEL_53;
  }
LABEL_52:
  misc_exit_level_action = 0;
LABEL_63:
  OwProcess04_PlayerIsMoving_049831();
}

void OwProcess04_PlayerIsMoving() {  // 04945d
  uint16 v5;
  int16 v19;
  uint16 v27;
  int16 v38;
  uint16 v42 = 0;
  uint16 v15;
  uint16 v24;
  uint16 v25;
  uint16 v29;

  while (1) {
    if (flag_switch_players) {
      pointer_current_overworld_process = 8;
      return;
    }
    uint8 v0 = player_current_characterx4 + 2;
    for (uint16 i = 2; (i & 0x8000) == 0; i -= 2) {
      uint16 x = get_PointU16(players_overworld_xpos_is_going_to, v0)->x;
      int16 v3 = x - get_PointU16(ow_players_pos, v0)->x;
      *(uint16 *)((int8 *)&R0_W + i) = v3;
      if (v3 < 0)
        v3 = -v3;
      *(uint16 *)((int8 *)&R4_W + i) = v3;
      v0 -= 2;
    }
    uint16 v4 = -1;
    R10_W = R4_W;
    HIBYTE(v5) = HIBYTE(R6_W);
    R12_W = R6_W;
    if (R6_W >= R4_W) {
      R10_W = R6_W;
      HIBYTE(v5) = HIBYTE(R4_W);
      R12_W = R4_W;
      v4 = 1;
    }
    R8_W = v4;
    WriteReg(WRMPYA, 16 * kOverworldProcess04_PlayerIsMoving_OWPlayerPathSpeedOffset[ow_player_on_climbing_tile]);
    LOBYTE(v5) = R12_;
    if (R12_) {
      WriteReg(WRMPYB, R12_);
      uint16 rw = ReadRegWord(RDMPYL);
      WriteRegWord(WRDIVL, rw);
      WriteReg(WRDIVB, R10_);
      v5 = ReadRegWord(RDDIVL);
    }
    R14_W = v5;
    R10_W = 16 * kOverworldProcess04_PlayerIsMoving_OWPlayerPathSpeedOffset[ow_player_on_climbing_tile];
    for (uint16 j = 2; (j & 0x8000) == 0; j -= 2) {
      uint16 v8;
      if ((R8_W & 0x8000) != 0)
        v8 = R14_W;
      else
        v8 = R10_W;
      if (*(int16 *)((int8 *)&R0_W + j) < 0)
        v8 = -v8;
      *(uint16 *)((int8 *)&player_overworld_xspeed + j) = v8;
      R8_W = -R8_W;
    }
    uint16 v9 = 0;
    if ((R8_W & 0x8000) == 0)
      v9 = 2;
    if (*(uint16 *)((int8 *)&R0_W + v9))
      break;
    if (*(uint16 *)l1_l2_scroll_spr_timer) {
      ow_process_hardcoded_path_flag = 0;
      PointU16 *pt = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
      R0_W = pt->x;
      R2_W = pt->y;
      CalculateOverworldPlayerPosition(player_current_characterx4 >> 2);
      R0_W = 0;
      R0_W = kLevelNames[(uint16)(2 * ow_level_number_of_each_tiletbl[R4_W]) >> 1];
      UpdateLevelName();
      ++*(uint16 *)&pointer_current_overworld_process;
      UpdateSaveBuffer();
      OwProcess04_PlayerIsMoving_049831();
      return;
    }
    copy_of_tile_player_is_standingd_on = ow_tile_player_is_standing_on;
    R8_W = 8;
    uint16 v11 = *(uint16 *)&ow_player_direction;
    R10_W = ow_player_direction ^ 2;
    while (1) {
      PointU16 *v13 = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
      R0_W = v13->x;
      R2_W = v13->y;
      uint16 v14 = 0;
      if (v11 < 4)
        v14 = 2;
      *(uint16 *)((int8 *)&R0_W + v14) += kSharedOverworldPathTables_DATA_049058[v11 >> 1];
      CalculateOverworldPlayerPosition(player_current_characterx4 >> 2);
      v15 = ow_process_hardcoded_path_flag;
      if (!ow_process_hardcoded_path_flag)
        break;
      R6_W = v11;
      uint16 v16 = ow_hardcoded_path_index + 1;
      if (kSharedOverworldPathTables_HardCodedOWPaths_MovementDirection[(uint16)(ow_hardcoded_path_index + 1)] == v11) {
        ++ow_hardcoded_path_index;
        v15 = kSharedOverworldPathTables_HardCodedOWPaths_Layer1Tiles[v16];
        if (v15 != 88)
          goto LABEL_34;
        break;
      }
      uint16 v12;
      do {
LABEL_24:
        v12 = R8_W - 2;
        R8_W = v12;
      } while (v12 == R10_W);
      v11 = v12;
    }
    if ((R4_W & 0x8000) != 0 || v15 >= 0x800)
      goto LABEL_24;
    v15 = blocks_map16_table_lo[R4_W];
LABEL_34:
    ow_tile_player_is_standing_on = v15;
    if (v15 == 0 || v15 >= 0x87)
      goto LABEL_24;
    v42 = v15;
    int16 v41 = v11;
    uint16 v17 = 0;
    R14_W = kSharedOverworldPathTables_DATA_049FEB[(uint16)(v15 - 1)];
    if ((uint8)R14_W == 20)
      v17 = 1;
    ow_player_on_climbing_tile = v17;
    PointU16 *v18 = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
    v18->x = R0_W;
    v18->y = R2_W;
    v19 = v41;
    uint8 v20 = 9;
    while ((uint8)v15 != *((uint8 *)kOverworldProcess04_PlayerIsMoving_DATA_049426 + v20)) {
      if ((--v20 & 0x80) != 0)
        goto LABEL_42;
    }
    HandleOverworldPathExits();
    LOBYTE(v19) = v41;
    flag_change_submap_music_on_player_switch = 1;
    OwPrompt01_InitializeOwPrompt_04F407();
    ow_hdmatransition_effect_flag = 0;
    palettes_background_color = 0;
    ow_hdmatransition_effect_xpos = 0x7000;
    ow_hdmatransition_effect_ypos = 0x5400;
    pointer_current_overworld_process = 10;
LABEL_42:
    if (v42 < 0x56) {
      v25 = 2 * (v42 - 1);
      int v26 = v25 >> 1;
      R4_W = kSharedOverworldPathTables_DATA_049F49[v26];
      v24 = kSharedOverworldPathTables_DATA_049EA7[v26];
    } else {
      if (v42 == 128 || v42 >= 0x6A && v42 < 0x6E) {
        int v21 = (uint16)((player_current_characterx4 >> 1) & 2) >> 1;
        ow_players_animation[v21] |= 8;
      } else {
        int v22 = (uint16)((player_current_characterx4 >> 1) & 2) >> 1;
        ow_players_animation[v22] = ow_players_animation[v22] & 0xF7;
      }
      *(uint16 *)l1_l2_scroll_spr_timer = 1;
      if (ow_tile_player_is_standing_on != 95 && ow_tile_player_is_standing_on != 91 && ow_tile_player_is_standing_on != 130) {
        *(uint16 *)&io_sound_ch3 = 35;
      }
      if ((uint8)ow_tile_player_is_standing_on != 130) {
        R6_W = 0;
        *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[R4_W]] |= kBitTable_Bank04[(uint16)((uint8)v19 ^ 2) >> 1];
      }
      R14_W = ow_players_animation[(uint16)((player_current_characterx4 >> 1) & 2) >> 1] & 0xC;
      R4_W = 1;
      R0_W = (uint8)copy_of_tile_player_is_standingd_on;
      for (int16 k = 23; k >= 0; --k) {
        if (kSharedOverworldPathTables_DATA_04A03C[(uint16)k] == R0_W) {
          v24 = kSharedOverworldPathTables_DATA_04A054[(uint16)(2 * k) >> 1];
          goto LABEL_60;
        }
      }
      v24 = 0x800;
      if ((uint16)v19 >= 4)
        v24 = 8;
LABEL_60:
      v25 = 0;
    }
    R0_W = v24;
    v27 = v25;
    uint16 v28 = 14;
    while ((uint8)v27 != LOBYTE(kOverworldProcess04_PlayerIsMoving_DATA_049430[v28])) {
      if ((--v28 & 0x8000) != 0)
        goto LABEL_68;
    }
    if ((uint8)v19 != HIBYTE(kOverworldProcess04_PlayerIsMoving_DATA_049430[v28])) {
      LOBYTE(v27) = (uint8)(v28 * 2) >> 1;
      LOBYTE(v27) = kOverworldProcess04_PlayerIsMoving_DATA_04944E[v27];
      v29 = v27;
      goto LABEL_69;
    }
LABEL_68:
    v29 = (v19 & 2) != 0;
LABEL_69:
    if (*(&R4_ + v29)) {
      R0_ = -R0_;
      R1_ = -R1_;
    }
    R4_W = (uint8)R14_W;
    if (*((uint8 *)&R0_W + ((R14_W & 7) == 0)) < 0x80)
      R4_W += 2;
    ow_players_animation[(uint16)((player_current_characterx4 >> 1) & 2) >> 1] = R4_W;
    int16 v30 = (uint8)R0_W;
    if ((uint8)R0_W >= 0x80)
      v30 = (uint8)R0_W | 0xFF00;
    PointU16 *v31 = get_PointU16(ow_players_pos, player_current_characterx4);
    PointU16 *v32 = get_PointU16(players_overworld_xpos_is_going_to, player_current_characterx4);
    v32->x = (v31->x + v30) & 0xFFFC;
    int16 v33 = R1_;
    if (R1_ >= 0x80)
      v33 = R1_ | 0xFF00;
    v32->y = (v31->y + v33) & 0xFFFC;
    if ((v32->x & 0xF) != 0) {
      if ((v32->y & 0xF) == 0) {
        v19 = 0;
        if ((R1_ & 0x80) == 0)
          v19 = 2;
      }
    } else {
      v19 = 4;
      if ((R0_ & 0x80) == 0)
        v19 = 6;
    }
    *(uint16 *)&ow_player_direction = v19;
    if (pointer_current_overworld_process == 10)
      goto LABEL_90;
  }
  int16 v34 = player_current_characterx4 + 2;
  for (uint16 m = 2; (m & 0x8000) == 0; m -= 2) {
    int16 v36 = *(uint16 *)((int8 *)&player_overworld_xspeed + m) + *(&flag_disable_layer3_scroll + m);
    *(uint16 *)(&flag_disable_layer3_scroll + m) = v36;
    int16 v37 = v36 & 0xFF00;
    if (v37 < 0)
      v37 |= 0xFF;
    int8 v39 = v37;
    LOBYTE(v38) = HIBYTE(v37);
    HIBYTE(v38) = v39;
    PointU16 *v40 = get_PointU16(ow_players_pos, v34);
    v40->x += v38;
    v34 -= 2;
  }
LABEL_90:
  OwProcess04_PlayerIsMoving_049831();
}

void OwProcess04_PlayerIsMoving_049831() {  // 049831
  if (pointer_current_overworld_process != 10 && !ow_active_earthquake_event)
    OwProcess04_PlayerIsMoving_04983F();
}

void OwProcess04_PlayerIsMoving_04983F() {  // 04983f
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  R0_W = pt->x;
  R2_W = pt->y;
  if (!ow_players_map[player_current_characterx4 >> 2]) {
    uint16 v1 = 2;
    uint16 v2 = 2;
    do {
      uint16 v3 = *(uint16 *)((int8 *)&R0_W + v1) - 128;
      if ((v3 & 0x8000) == 0) {
        int v5 = v2 >> 1;
        if (v3 >= kOverworldProcess04_PlayerIsMoving_MaxOverworlCameraPosition_RightAndBottom[v5])
          v3 = kOverworldProcess04_PlayerIsMoving_MaxOverworlCameraPosition_RightAndBottom[v5];
      } else {
        int v4 = v2 >> 1;
        if (v3 < kOverworldProcess04_PlayerIsMoving_MaxOverworlCameraPosition[v4])
          v3 = kOverworldProcess04_PlayerIsMoving_MaxOverworlCameraPosition[v4];
      }
      *(uint16 *)((int8 *)&mirror_current_layer1_xpos + v1) = v3;
      *(uint16 *)((int8 *)&mirror_current_layer2_xpos + v1) = v3;
      v2 -= 2;
      v1 -= 2;
    } while ((v1 & 0x8000) == 0);
  }
}

uint16 CalculateOverworldPlayerPosition(uint8 k) {  // 049885
  R4_W = R0_W & 0xF;
  R4_W += 16 * (R0_W & 0x10);
  R4_W += (uint8)(16 * R2_W);
  if ((R2_W & 0x10) != 0)
    R4_W += 512;
  uint16 result = ow_players_map[k];
  if (ow_players_map[k]) {
    result = R4_W + 0x400;
    R4_W += 0x400;
  }
  return result;
}

void OwProcess0C_IntroMarch() {  // 0498c6
  LOBYTE(ow_players_animation[0]) = 0;
  uint16 subpos = BYTE(player_overworld_sub_ypos) + 0x80;
  LOBYTE(player_overworld_sub_ypos) = subpos;

  PointU16 *pt = get_PointU16(ow_players_pos, 0);
  pt->y += -1 + (subpos >> 8);

  if (LOBYTE(pt->y) == 120) {
    pointer_current_overworld_process = 0;
    SaveGame();
  }
}

void UnlockOverworldPathBasedOnExit() {  // 049903
  if ((int8)misc_exit_level_action > 0) {
    R8_ = kSharedOverworldPathTables_DATA_049060[(uint8)(misc_exit_level_action - 1)];
    R9_ = 0;
    uint8 v0 = player_current_characterx4;
    PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
    R0_W = pt->x >> 4;
    PointU16 *v2 = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
    v2->x = R0_W;
    R2_W = pt->y >> 4;
    v2->y = R2_W;
    CalculateOverworldPlayerPosition(v0 >> 2);
    uint16 v3 = ow_level_direction_flags[R4_W];
    int16 v4 = R8_W;
    if (R8_W) {
      do {
        v3 >>= 1;
        --v4;
      } while (v4 >= 0);
    }
    *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[R4_W]] |= kBitTable_Bank04[(uint16)(2 * (v3 & 3)) >> 1];
  }
}

void HandleOverworldPathExits() {  // 049a24
  PointU16 *pt;
  ow_currently_loaded_submap = ow_players_map[(uint8)(player_current_characterx4 >> 2)];
  R2_W = 26;
  uint8 v0 = 13;
  uint8 v1 = player_current_characterx4;
  while (1) {
    pt = get_PointU16(ow_players_pos, player_current_characterx4);
    if (pt->y == kHandleOverworldPathExits_DATA_049964[v0].field_0 && pt->x == kHandleOverworldPathExits_DATA_049964[v0].field_2 &&
        kHandleOverworldPathExits_DATA_049964[v0].field_4 == ow_currently_loaded_submap) {
      break;
    }
    --R2_W;
    --R2_W;
    if ((--v0 & 0x80) != 0)
      return;
  }
  pt->y = kHandleOverworldPathExits_DATA_0499AA[v0].field_0;
  pt->x = kHandleOverworldPathExits_DATA_0499AA[v0].field_2;
  ow_currently_loaded_submap = kHandleOverworldPathExits_DATA_0499AA[v0].field_4;
  PointU16 *v4 = get_PointU16(ow_players_grid_aligned_pos, v1);
  v4->y = kHandleOverworldPathExits_DATA_0499F0[R2_];
  v4->x = kHandleOverworldPathExits_DATA_0499F0[R2_ + 1];
}

void HandleOverworldPathExits_SetLayerPositions() {  // 049a93
  uint16 v0 = (uint8)player_current_characterx4 >> 2;
  int16 v1 = ow_currently_loaded_submap | (ow_players_map[v0 + 1] << 8);
  *(uint16 *)&ow_players_map[v0] = v1;
  if ((uint8)v1) {
    int v2 = (uint16)(4 * ((uint8)v1 - 1)) >> 1;
    mirror_current_layer1_xpos = kHandleOverworldPathExits_DATA_049A0C[v2];
    mirror_current_layer2_xpos = mirror_current_layer1_xpos;
    mirror_current_layer1_ypos = kHandleOverworldPathExits_DATA_049A0C[v2 + 1];
    mirror_current_layer2_ypos = mirror_current_layer1_ypos;
  } else {
    OwProcess04_PlayerIsMoving_04983F();
  }
}

void UpdateLevelName() {  // 049d07
  uint16 v0 = stripe_image_upload;
  R2_W = stripe_image_upload + 38;
  stripe_image_upload += 42;
  *(uint16 *)&stripe_image_upload_data[v0 + 2] = 0x2500;
  *(uint16 *)&stripe_image_upload_data[v0] = 0x8b50;
  uint16 v1 = kUpdateLevelName_DATA_049C91[(uint16)(2 * (R1_ & 0x7F)) >> 1];
  if ((kUpdateLevelName_LevelNameStrings[v1] & 0x80) == 0)
    v0 = UpdateLevelName_049D7F(v0, v1);
  uint16 v2 = kUpdateLevelName_DATA_049CCF[(uint16)((uint8)(R0_W & 0xF0) >> 3) >> 1];
  if (kUpdateLevelName_LevelNameStrings[v2] != 0x9F)
    v0 = UpdateLevelName_049D7F(v0, v2);
  v0 = UpdateLevelName_049D7F(v0, kUpdateLevelName_DATA_049CED[(uint16)(2 * (R0_W & 0xF)) >> 1]);
  while (v0 < R2_W)
    v0 = UpdateLevelName_049D7F(v0, 0x1CB);
  stripe_image_upload_data[v0 + 4] = -1;
}

uint16 UpdateLevelName_049D7F(uint16 k, uint16 j) {  // 049d7f
  uint8 t;
  do {
    t = kUpdateLevelName_LevelNameStrings[j];
    if (k < R2_W) {
      stripe_image_upload_data[k + 4] = t & 0x7F;
      stripe_image_upload_data[k + 5] = 57;
      k += 2;
    }
    ++j;
  } while (!(t & 0x80));
  return k;
}

void OwProcess05_CheckPlayerSwitch() {  // 049d9a
  if (flag_two_player_game && (players_lives[player_current_character ^ 1] & 0x80) == 0 && misc_exit_level_action) {
    if ((--timer_keep_game_mode_active & 0x80) != 0) {
      timer_keep_game_mode_active = 2;
      misc_exit_level_action = 0;
      ++pointer_current_overworld_process;
    }
    OwProcess04_PlayerIsMoving_049831();
  } else {
    pointer_current_overworld_process = 3;
    misc_exit_level_action = 0;
    OwProcess04_PlayerIsMoving_049831();
  }
}

void OwProcess07_SwitchingPlayers() {  // 049dd1
  player_current_character ^= 1;
  player_current_coin_count = players_coins[player_current_character];
  player_current_life_count = players_lives[player_current_character];
  player_current_power_up = players_power_up[player_current_character];
  yoshi_carry_over_levels_flag = players_has_yoshi[player_current_character];
  yoshi_current_yoshi_color = yoshi_carry_over_levels_flag;
  player_riding_yoshi_flag = yoshi_carry_over_levels_flag;
  player_current_item_box = players_item_box[player_current_character];
  LoadOverworldLifeCounter();
  GameMode0C_LoadOverworld_048E55();
  LOBYTE(ow_currently_loaded_submap) = ow_players_map[player_current_character];
  ow_currently_loaded_submap = (uint8)ow_currently_loaded_submap;
  timer_keep_game_mode_active = 2;
  pointer_current_overworld_process = 10;
  ++flag_switch_players;
}

void OwProcess08_PlayerSwitchFadeIn() {  // 049e22
  if ((--timer_keep_game_mode_active & 0x80) != 0) {
    timer_keep_game_mode_active = 2;
    mirror_screen_display_register += kGameModeXX_FadeInOrOut_DATA_009F2F[misc_mosaic_direction];
    if (mirror_screen_display_register == kGameModeXX_FadeInOrOut_DATA_009F33[misc_mosaic_direction]) {
      ++pointer_current_overworld_process;
      misc_mosaic_direction ^= 1;
    }
  }
}

void OwProcess09_FinishedSwitchingPlayers() {  // 049e4c
  pointer_current_overworld_process = 3;
}

void OwProcess0B_StarWarpAnimation() {  // 049e52
  if (!ow_star_launch_speed) {
    if (++timer_wait_before_star_launch != 49)
      return;
    goto LABEL_5;
  }
  if ((counter_global_frames & 7) == 0) {
LABEL_5:
    if (++ow_star_launch_speed == 5)
      ow_star_launch_speed = 4;
  }
  R0_W = ow_star_launch_speed;
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  uint16 v1 = pt->y - ow_star_launch_speed;
  pt->y = v1;
  if ((int16)(v1 - mirror_current_layer1_ypos) < 0) {
    ++ow_warping_on_pipe_or_star_flag;
    misc_exit_level_action = 0;
    misc_game_mode = 11;
  }
}

void InitializeOverworldTilemaps() {  // 04d6e9
  mirror_current_layer1_ypos = 0;
  camera_xy_layer1_vramupd_left_up = -1;
  camera_xy_layer1_vramupd_right_down = -1;
  *(uint16 *)&camera_layer1_scrolling_direction = 514;
  if ((ow_players_map[(uint8)(player_current_characterx4 >> 2)] & 0xF) != 0) {
    camera_layer1_row_column_to_update_right_down = 32;
    mirror_current_layer1_ypos = 512;
  }
  do {
    BufferScrollingTiles_Layer1_Main();
    UploadLevelLayer1And2Tilemaps();
    ++camera_layer1_row_column_to_update_right_down;
    mirror_current_layer1_ypos += 16;
  } while ((mirror_current_layer1_ypos & 0x1FF) != 0);
  mirror_current_layer1_ypos = mirror_current_layer2_ypos;
  camera_layer1_row_column_to_update_right_down = 0;
  *(uint16 *)&misc_level_mode_setting = 0;
  *(uint16 *)&misc_level_layout_flags = 0;
  camera_xy_layer1_vramupd_left_up = -1;
  camera_xy_layer1_vramupd_right_down = -1;
  WriteReg(VMAIN, 0x80);
  WriteReg(VMADDL, 0);
  WriteReg(VMADDH, 0x30);
  for (uint8 i = 6; (i & 0x80) == 0; --i)
    WriteReg((SnesRegs)(i + 0x4310), kInitializeOverworldTilemaps_PARAMS_04DAB3[i]);
  if (ow_players_map[(uint8)player_current_characterx4 >> 2])
    WriteReg(A1T1H, 0x60);
  WriteReg(MDMAEN, 2);
}

uint16 LoadOverworldLayer1AndEvents_InitializedOverworldLayer1Tilemap(uint16 k, uint8 a) {  // 04d770
  blocks_map16_table_hi[k] = a;
  blocks_map16_table_hi[k + 432] = a;
  blocks_map16_table_hi[k + 864] = a;
  blocks_map16_table_hi[k + 0x510] = a;
  blocks_map16_table_hi[k + 0x6c0] = a;
  blocks_map16_table_hi[k + 0x870] = a;
  blocks_map16_table_hi[k + 0xa20] = a;
  blocks_map16_table_hi[k + 0xbd0] = a;
  blocks_map16_table_hi[k + 0xd80] = a;
  blocks_map16_table_hi[k + 0xf30] = a;
  blocks_map16_table_hi[k + 0x10e0] = a;
  blocks_map16_table_hi[k + 0x1290] = a;
  blocks_map16_table_hi[k + 0x1440] = a;
  blocks_map16_table_hi[k + 0x15f0] = a;
  blocks_map16_table_hi[k + 0x17a0] = a;
  blocks_map16_table_hi[k + 0x1950] = a;
  blocks_map16_table_hi[k + 0x1b00] = a;
  blocks_map16_table_hi[k + 0x1cb0] = a;
  blocks_map16_table_hi[k + 0x1e60] = a;
  blocks_map16_table_hi[k + 0x2010] = a;
  blocks_map16_table_hi[k + 0x21c0] = a;
  blocks_map16_table_hi[k + 0x2370] = a;
  blocks_map16_table_hi[k + 0x2520] = a;
  blocks_map16_table_hi[k + 0x26d0] = a;
  blocks_map16_table_hi[k + 0x2880] = a;
  blocks_map16_table_hi[k + 0x2a30] = a;
  blocks_map16_table_hi[k + 0x2be0] = a;
  blocks_map16_table_hi[k + 0x2d90] = a;
  blocks_map16_table_hi[k + 0x2f40] = a;
  blocks_map16_table_hi[k + 0x30f0] = a;
  blocks_map16_table_hi[k + 0x32a0] = a;
  blocks_map16_table_hi[k + 0x3450] = a;
  return k + 1;
}

void LoadOverworldLayer1AndEvents_04D7F2() {  // 04d7f2
  uint16 v0;

  HIBYTE(v0) = 0;
  R13_ = 0;
  R14_ = -48;
  R15_ = 126;
  R10_ = 0;
  R11_ = -40;
  R12_ = 126;
  R4_ = 0;
  R5_ = -56;
  R6_ = 126;
  R0_W = 1;
  for (int16 i = 0x7ff; i >= 0; --i) {
    IndirWriteByte(&R10_, i, 0);
    IndirWriteByte(&R13_, i, 0);
  }
  for (uint16 j = 0; j != 0x800; ++j) {
    uint8 v3 = *IndirPtr(&R4_, j);
    if (v3 >= 0x56 && v3 < 0x81) {
      LOBYTE(v0) = R0_;
      IndirWriteByte(&R13_, j, R0_);
      IndirWriteByte(&R10_, j, kLoadOverworldLayer1AndEvents_DATA_04D678[v0]);
      ++R0_;
    }
  }
  R15_ = 0;
  do {
    LoadOverworldLayer1AndEvents_04DA49();
    ++R15_;
  } while (R15_ != 111);
}

void LoadOverworldLayer1AndEvents_04DA49() {  // 04da49
  if ((kBitTable_DATA_04E44B[R15_ & 7] & ow_event_flags[(uint8)(R15_ & 0xF8) >> 3]) != 0) {
    R4_W = 0xc800;
    uint16 v0 = kChangingLayer1OverworldTiles_Layer1TileLocation[(uint16)(2 * R15_) >> 1];
    uint16 v1 = 21;
    R6_ = 126;
    uint8 v2 = *IndirPtr(&R4_, v0);
    while (v2 != kChangingLayer1OverworldTiles_TilesThatChange[v1]) {
      if ((--v1 & 0x8000) != 0)
        goto LABEL_8;
    }
    uint8 v3 = kChangingLayer1OverworldTiles_TilesToBecome[v1];
    IndirWriteByte(&R4_, v0, v3);
    if (v1 == 21)
      IndirWriteByte(&R4_, v0 + 1, v3);
LABEL_8:
    CheckIfDestroyTileEventIsActive(R15_);
    pointer_overworld_event_process = 0;
    OwEventProcess07_SilentEventsAndEndOfEvent_Entry2(R15_);
  }
}

void LoadOverworldLayer2AndEventsTilemaps() {  // 04daad
  LoadOverworldLayer2AndEventsTilemaps_Sub();
}

void BufferOverworldLayer2Tilemap(uint16 k, uint16 j) {  // 04daba
  do {
    R3_ = *IndirPtr(&R0_, j);
    if ((R3_ & 0x80) != 0) {
      R3_ &= ~0x80;
      uint8 v2 = *IndirPtr(&R0_, ++j);
      do {
        ow_layer2_tiles[k] = v2;
        k += 2;
        --R3_;
      } while ((R3_ & 0x80) == 0);
    } else {
      do {
        ow_layer2_tiles[k] = *IndirPtr(&R0_, ++j);
        k += 2;
        --R3_;
      } while ((R3_ & 0x80) == 0);
    }
    ++j;
  } while (k < R14_W);
}

void OwProcess0A_SwitchBetweenSubmaps() {  // 04daef
  kOverworldProcess0A_SwitchBetweenSubmaps_Ptrs04DAF8[ow_submap_switch_process]();
}

void SubmapSwitchProcess06_EndWindowHDMA() {  // 04db18
  int16 v1;

  int v0 = ow_hdmatransition_effect_flag >> 1;
  ow_hdmatransition_effect_xpos += kSubmapSwitchProcess00_InitializeWindowHDMA_DATA_04DB08[v0];
  if (((kSubmapSwitchProcess00_InitializeWindowHDMA_DATA_04DB08[v0] ^
        (ow_hdmatransition_effect_xpos -
         *(uint16 *)&kSubmapSwitchProcess00_InitializeWindowHDMA_DATA_04DB0C[ow_hdmatransition_effect_flag])) &
       0x8000) == 0 ||
      (ow_hdmatransition_effect_ypos += kSubmapSwitchProcess00_InitializeWindowHDMA_DATA_04DB10[v0],
       ((kSubmapSwitchProcess00_InitializeWindowHDMA_DATA_04DB10[v0] ^
         (ow_hdmatransition_effect_ypos -
          *(uint16 *)&kSubmapSwitchProcess00_InitializeWindowHDMA_DATA_04DB14[ow_hdmatransition_effect_flag])) &
        0x8000) == 0)) {
    ow_hdmatransition_effect_xpos = *(uint16 *)&kSubmapSwitchProcess00_InitializeWindowHDMA_DATA_04DB0C[ow_hdmatransition_effect_flag];
    ow_hdmatransition_effect_ypos = *(uint16 *)&kSubmapSwitchProcess00_InitializeWindowHDMA_DATA_04DB14[ow_hdmatransition_effect_flag];
    ++*(uint16 *)&ow_submap_switch_process;
    ow_hdmatransition_effect_flag ^= 2;
    if (ow_hdmatransition_effect_flag)
      HandleOverworldPathExits_SetLayerPositions();
  }
  R0_ = 2 * HIBYTE(ow_hdmatransition_effect_ypos);
  HIBYTE(v1) = HIBYTE(ow_hdmatransition_effect_xpos) + 0x80;
  LOBYTE(v1) = 0x80 - HIBYTE(ow_hdmatransition_effect_xpos);
  uint8 v2 = 0;
  uint8 v3 = -88;
  do {
    if (v2 >= R0_)
      v1 = 255;
    *(uint16 *)&misc_hdmawindow_effect_table[v3 + 78] = v1;
    *(uint16 *)&misc_hdmawindow_effect_table[v2 + 248] = v1;
    v2 += 2;
    v3 -= 2;
  } while (v3);
  mirror_bg1_and2_window_mask_settings = 51;
  mirror_object_and_color_window_settings = 51;
  mirror_hdmaenable = 0x80;
}

void SubmapSwitchProcess05_UpdatePalette() {  // 04db9d
  misc_level_tileset_setting = kLoadOverworldLayer1AndEvents_DATA_04DC02[ow_players_map[(uint8)player_current_characterx4 >> 2]];
  BufferPalettesRoutines_Overworld();
  palettes_palette_mirror[0] = 510;
  LOBYTE(palettes_palette_mirror[128]) = 0;
  palettes_palette_upload_table_index = 6;
  ++ow_submap_switch_process;
}

void SubmapSwitchProcess07_EndSubmapSwitch() {  // 04dbcf
  ow_submap_switch_process = 0;
  pointer_current_overworld_process = 4;
  uint8 v0 = (uint8)player_current_characterx4 >> 2;
  if (!flag_two_player_game || flag_change_submap_music_on_player_switch || ow_players_map[v0] != ow_players_map[v0 ^ 1]) {
    io_music_ch1 = kSubmapSwitchProcess07_EndSubmapSwitch_DATA_04DBC8[ow_players_map[v0]];
    flag_change_submap_music_on_player_switch = 0;
  }
}

void LoadOverworldLayer1AndEvents() {  // 04dc09
  misc_level_tileset_setting = kLoadOverworldLayer1AndEvents_DATA_04DC02[ow_players_map[(uint8)player_current_characterx4 >> 2]];
  graphics_level_sprite_graphics_setting = 17;
  misc_level_mode_setting = 7;
  misc_level_layout_flags = 3;
  uint16 t = 0;
  uint8 v1 = 0;
  do
    t = LoadOverworldLayer1AndEvents_InitializedOverworldLayer1Tilemap(t, v1);
  while (t != 432);
  R0_W = 0xd000;
  for (uint16 i = 0; i != 0x400; i += 2) {
    pointer_map16_tiles[i >> 1] = R0_W;
    R0_W += 8;
  }
  uint8 *v3 = g_ram + 0xC800;
  const uint8 *v4 = RomPtr_0C(0xF7DF);
  MemCpy(v3, v4, 0x800);
  LoadOverworldLayer1AndEvents_04D7F2();
}

void LoadOverworldLayer2AndEventsTilemaps_Sub() {  // 04dc6a
  LoadOverworldLayer2AndEventsTilemaps_04DD40();
  R0_W = 0xa533;
  R2_ = 4;
  R14_W = 0x4000;
  BufferOverworldLayer2Tilemap(0, 0);
  R0_W = 0xc02b;
  BufferOverworldLayer2Tilemap(1, 0);
  R15_ = 0;
  do {
    LoadOverworldLayer2AndEventsTilemaps_04E453();
    ++R15_;
  } while (R15_ != 111);
}

void SubmapSwitchProcess01_UpdateLayer1() {  // 04dcb6
  *(uint16 *)&temp65 = 0xd000;
  temp67 = 5;
  R0_W = 0;
  R1_ = ow_submap_switch_process - 1;
  if (ow_players_map[(uint8)(player_current_characterx4 >> 2)])
    R1_ += 4;
  do {
    R2_ = blocks_map16_table_lo[R0_W];
    *(uint16 *)&R3_ = *(uint16 *)&blocks_map16_table_hi[R0_W];
    uint16 v0 = 8 * R2_W;
    R2_W = (4 * (uint8)R0_W) & 0x3F;
    uint16 v1 = R2_W | (8 * (uint8)R0_W) & 0xF80;
    *(uint16 *)&ow_byte_7EE000[v1 + 0x400] = *(uint16 *)IndirPtr(&temp65, v0);
    v0 += 2;
    *(uint16 *)&ow_byte_7EE000[v1 + 0x440] = *(uint16 *)IndirPtr(&temp65, v0);
    v0 += 2;
    *(uint16 *)&ow_byte_7EE000[v1 + 0x402] = *(uint16 *)IndirPtr(&temp65, v0);
    *(uint16 *)&ow_byte_7EE000[v1 + 0x442] = *(uint16 *)IndirPtr(&temp65, v0 + 2);
    ++R0_;
  } while (R0_);
  ++ow_submap_switch_process;
}

void LoadOverworldLayer2AndEventsTilemaps_04DD40() {  // 04dd40
  R2_W = 0x8d00;
  R4_ = 12;
  LoadOverworldLayer2AndEventsTilemaps_04DD57(0, 0);
}

void LoadOverworldLayer2AndEventsTilemaps_04DD57(uint16 k, uint16 j) {  // 04dd57
  do {
    uint8 *v2 = IndirPtr(&R2_, j++);
    R5_ = *v2;
    if ((R5_ & 0x80) != 0) {
      R5_ &= ~0x80;
      uint8 v3 = *IndirPtr(&R2_, j);
      do {
        ow_layer2_event_tiles[k++] = v3;
        --R5_;
      } while ((R5_ & 0x80) == 0);
      ++j;
    } else {
      do {
        ow_layer2_event_tiles[k++] = *IndirPtr(&R2_, j++);
        --R5_;
      } while ((R5_ & 0x80) == 0);
    }
  } while (*(uint16 *)IndirPtr(&R2_W, j) != 0xFFFF);
}

void LoadOverworldLayer2AndEventsTilemaps_04E453() {  // 04e453
  if ((kBitTable_DATA_04E44B[R15_ & 7] & ow_event_flags[R15_ >> 3]) != 0) {
    int v0 = (uint8)(2 * R15_) >> 1;
    ow_starting_event_tile = kLayer2EventData_Ptrs[v0];
    for (ow_final_event_tile = kLayer2EventData_Ptrs[v0 + 1]; ow_starting_event_tile != ow_final_event_tile; ++ow_starting_event_tile) {
      BufferEventTileToLayer2Tilemap();
    }
  }
}

void BufferEventTileToLayer2Tilemap() {  // 04e496
  int v0 = (uint16)(4 * ow_starting_event_tile) >> 1;
  uint16 v1 = kLayer2EventData_TileEntries[v0];
  R4_W = kLayer2EventData_TileEntries[v0 + 1];
  BufferEventTileToLayer2Tilemap_Entry2(4 * ow_starting_event_tile, v1);
}

void BufferEventTileToLayer2Tilemap_Entry2(uint16 k, uint16 j) {  // 04e4a9
  R8_ = 127;
  R11_ = 12;
  R6_W = 0;
  *(uint16 *)&R9_ = 0x8000;
  if (j < 0x900)
    BufferEventTileToLayer2Tilemap_Buffer6x6Tile(k, j);
  else
    BufferEventTileToLayer2Tilemap_Buffer2x2Tile(k, j);
}

void BufferEventTileToLayer2Tilemap_Buffer2x2Tile(uint16 k, uint16 j) {  // 04e4d0
  R0_W = 1;
  do {
    uint16 v2 = R4_W;
    R12_W = 1;
    do {
      ow_layer2_tiles[v2] = *IndirPtr(&R9_, j);
      uint16 v3 = v2 + 1;
      ow_layer2_tiles[v3] = *IndirPtr(&R6_, j++);
      v2 = v3 + 1;
      if ((v2 & 0x3F) == 0)
        v2 = ((v2 - 1) & 0xFFC0) + 0x800;
      --R12_W;
    } while ((R12_W & 0x8000) == 0);
    uint16 v4 = R4_W;
    R4_W += 64;
    if ((R4_W & 0x7C0) == 0)
      R4_W = (v4 & 0xF83F) + 0x1000;
    --R0_W;
  } while ((R0_W & 0x8000) == 0);
}

void BufferEventTileToLayer2Tilemap_Buffer6x6Tile(uint16 k, uint16 j) {  // 04e520
  R0_W = 5;
  do {
    uint16 v2 = R4_W;
    R12_W = 5;
    do {
      ow_layer2_tiles[v2] = *IndirPtr(&R9_, j);
      uint16 v3 = v2 + 1;
      ow_layer2_tiles[v3] = *IndirPtr(&R6_, j++);
      v2 = v3 + 1;
      if ((v2 & 0x3F) == 0)
        v2 = ((v2 - 1) & 0xFFC0) + 0x800;
      --R12_W;
    } while ((R12_W & 0x8000) == 0);
    uint16 v4 = R4_W;
    R4_W += 64;
    if ((R4_W & 0x7C0) == 0)
      R4_W = (v4 & 0xF83F) + 0x1000;
    --R0_W;
  } while ((R0_W & 0x8000) == 0);
}

void OwProcess01_ActivateEvents() {  // 04e570
  kOverworldProcess01_ActivateEvents_Ptrs04E577[pointer_overworld_event_process]();
}

void OwEventProcess00_CheckIfEventShouldRun() {  // 04e5ee
  if (misc_exit_level_action == 2)
    ++ow_current_event_number;
  if (!counter_enemy_rollcall_screen || ow_current_event_number == 0xFF ||
      ((kBitTable_DATA_04E44B[ow_current_event_number & 7] & ow_event_flags[ow_current_event_number >> 3]) != 0)) {
    for (int8 i = 7; i >= 0; --i) {
      if (*((uint8 *)kOwEventProcess00_CheckIfEventShouldRun_DATA_04E5E6 + (uint8)i) == (uint8)ow_tile_player_is_standing_on) {
        ++pointer_current_overworld_process;
        misc_exit_level_action = -32;
        timer_keep_game_mode_active = 15;
        return;
      }
    }
    pointer_current_overworld_process = 5;
    misc_exit_level_action = 0x80;
  } else {
    ++pointer_overworld_event_process;
    uint16 t = CheckIfDestroyTileEventIsActive(ow_current_event_number);
    ow_on_screen_xpos_of_current_event_tile = 16 * t;
    ow_on_screen_ypos_of_current_event_tile = t & 0xF0;
    timer_destroy_tile_event_unknown = 40;
    if (ow_level_number_lo == 24)
      ow_active_earthquake_event = -1;
    if (pointer_overworld_event_process != 2)
      io_sound_ch3 = 22;
  }
}

uint16 CheckIfDestroyTileEventIsActive(uint8 a) {  // 04e677
  uint8 v1 = 23;
  while (a != kCheckIfDestroyTileEventIsActive_EventNums[v1]) {
    if ((--v1 & 0x80) != 0) {
LABEL_4:
      pointer_overworld_event_process = 2;
      return 0;
    }
  }
  ow_destroy_tile_event_vramindex = v1;
  R12_ = 126;
  R10_W = 0xc800;
  uint16 v2 = kCheckIfDestroyTileEventIsActive_DATA_04E5B6[v1];
  uint16 v3 = 4;
  uint8 v4 = *IndirPtr(&R10_, v2);
  while (v4 != kCheckIfDestroyTileEventIsActive_DATA_04E5A7[v3]) {
    if ((--v3 & 0x8000) != 0)
      goto LABEL_4;
  }
  ow_destroy_tile_event_tile_index = v3;
  if ((int16)(v3 - 3) >= 0) {
    IndirWriteByte(&R10_, v2, kCheckIfDestroyTileEventIsActive_DATA_04E5AC[v3]);
    v2 += 16;
  }
  IndirWriteByte(&R10_, v2, kCheckIfDestroyTileEventIsActive_DATA_04E5B1[v3]);
  return v2;
}

void OwEventProcess02_SetEventTileIndexes() {  // 04e6d3
  ++pointer_overworld_event_process;
  int v0 = (uint8)(2 * ow_current_event_number) >> 1;
  ow_starting_event_tile = kLayer2EventData_Ptrs[v0];
  ow_final_event_tile = kLayer2EventData_Ptrs[v0 + 1];
  if (ow_final_event_tile == ow_starting_event_tile) {
    ++pointer_overworld_event_process;
    ++pointer_overworld_event_process;
  }
}

void OwEventProcess03_GetLayer2Tile() {  // 04e6f9
  uint16 v2;

  OwEventProcess03_GetLayer2Tile_04EA62();
  R14_ = 127;
  uint16 v0 = 4 * ow_starting_event_tile;
  int v1 = (uint16)(4 * ow_starting_event_tile) >> 1;
  *(uint16 *)&timer_destroy_tile_event_unknown = kLayer2EventData_TileEntries[v1];
  R0_W = kLayer2EventData_TileEntries[v1 + 1];
  LOBYTE(v2) = (uint16)(((uint16)(R0_W & 0x1FFF) >> 1) + 0x3000) >> 8;
  HIBYTE(v2) = (uint16)(R0_W & 0x1FFF) >> 1;
  R2_W = v2;
  ow_on_screen_ypos_of_current_event_tile = (R0_W >> 3) & 0xF8;
  ow_on_screen_xpos_of_current_event_tile = 4 * (R0_ & 0x3E);
  R12_W = 0x4000;
  R10_W = 0xefff;
  if (*(uint16 *)&timer_destroy_tile_event_unknown < 0x900)
    v0 = BufferEventTileToStripeImageTable_Buffer6x6Tile();
  else
    v0 = BufferEventTileToStripeImageTable_Buffer2x2Tile();
  *(uint16 *)&stripe_image_upload_data[v0] = 255;
  stripe_image_upload = v0;
  BufferEventTileToLayer2Tilemap();
  io_sound_ch3 = 21;
  ++pointer_overworld_event_process;
}

uint16 BufferEventTileToStripeImageTable_Buffer2x2Tile() {  // 04e76c
  int16 v3;
  int16 v5;
  int16 v6;
  uint16 v9;
  int16 v12;
  uint16 v13;

  R6_W = 1;
  uint16 v0 = stripe_image_upload;
  do {
    *(uint16 *)&stripe_image_upload_data[v0] = R2_W;
    uint16 v1 = v0 + 2;
    int16 v2 = 768;
    R8_W = R3_ & 0x1F;
    R8_W = 32 - R8_W;
    if (R8_W == 1) {
      LOBYTE(v3) = (uint16)(2 * R8_W - 1) >> 8;
      HIBYTE(v3) = 2 * R8_W - 1;
      v2 = v3;
    }
    *(uint16 *)&stripe_image_upload_data[v1] = v2;
    v0 = v1 + 2;
    R4_W = 1;
    uint16 v4 = R0_W;
    do {
      *(uint16 *)&stripe_image_upload_data[v0] = R10_W & *(uint16 *)IndirPtr(&R12_W, v4);
      v0 += 2;
      v4 += 2;
      if ((v4 & 0x3F) == 0 && R4_W) {
        v4 = ((v4 - 1) & 0xFFC0) + 0x800;
        LOBYTE(v5) = HIBYTE(R2_W);
        HIBYTE(v5) = R2_W;
        v6 = (v5 & 0x3BE0) + 0x400;
        int8 v7 = v6;
        LOBYTE(v6) = HIBYTE(v6);
        HIBYTE(v6) = v7;
        *(uint16 *)&stripe_image_upload_data[v0] = v6;
        uint16 v8 = v0 + 2;
        LOBYTE(v6) = (uint16)(2 * R8_W - 1) >> 8;
        HIBYTE(v6) = 2 * R8_W - 1;
        *(uint16 *)&stripe_image_upload_data[v8] = v6;
        v0 = v8 + 2;
      }
      --R4_W;
    } while ((R4_W & 0x8000) == 0);
    LOBYTE(v9) = HIBYTE(R2_W);
    HIBYTE(v9) = R2_W;
    v9 += 32;
    int8 v10 = v9;
    LOBYTE(v9) = HIBYTE(v9);
    HIBYTE(v9) = v10;
    R2_W = v9;
    uint16 v11 = R0_W;
    R0_W += 64;
    if ((R0_W & 0x7C0) == 0) {
      R0_W = (v11 & 0xF83F) + 0x1000;
      LOBYTE(v12) = HIBYTE(R2_W);
      HIBYTE(v12) = R2_W;
      v13 = ((v12 - 32) & 0x341F) + 0x800;
      int8 v14 = v13;
      LOBYTE(v13) = HIBYTE(v13);
      HIBYTE(v13) = v14;
      R2_W = v13;
    }
    --R6_W;
  } while ((R6_W & 0x8000) == 0);
  return v0;
}

uint16 BufferEventTileToStripeImageTable_Buffer6x6Tile() {  // 04e824
  int16 v3;
  int16 v5;
  int16 v6;
  uint16 v9;
  int16 v12;
  uint16 v13;

  R6_W = 5;
  uint16 v0 = stripe_image_upload;
  do {
    *(uint16 *)&stripe_image_upload_data[v0] = R2_W;
    uint16 v1 = v0 + 2;
    int16 v2 = 0xb00;
    R8_W = R3_ & 0x1F;
    R8_W = 32 - R8_W;
    if (R8_W < 6) {
      LOBYTE(v3) = (uint16)(2 * R8_W - 1) >> 8;
      HIBYTE(v3) = 2 * R8_W - 1;
      v2 = v3;
      R8_W = 6 - R8_W;
    }
    *(uint16 *)&stripe_image_upload_data[v1] = v2;
    v0 = v1 + 2;
    R4_W = 5;
    uint16 v4 = R0_W;
    do {
      *(uint16 *)&stripe_image_upload_data[v0] = R10_W & *(uint16 *)IndirPtr(&R12_W, v4);
      v0 += 2;
      v4 += 2;
      if ((v4 & 0x3F) == 0 && R4_W) {
        v4 = ((v4 - 1) & 0xFFC0) + 0x800;
        LOBYTE(v5) = HIBYTE(R2_W);
        HIBYTE(v5) = R2_W;
        v6 = (v5 & 0x3BE0) + 0x400;
        int8 v7 = v6;
        LOBYTE(v6) = HIBYTE(v6);
        HIBYTE(v6) = v7;
        *(uint16 *)&stripe_image_upload_data[v0] = v6;
        uint16 v8 = v0 + 2;
        LOBYTE(v6) = (uint16)(2 * R8_W - 1) >> 8;
        HIBYTE(v6) = 2 * R8_W - 1;
        *(uint16 *)&stripe_image_upload_data[v8] = v6;
        v0 = v8 + 2;
      }
      --R4_W;
    } while ((R4_W & 0x8000) == 0);
    LOBYTE(v9) = HIBYTE(R2_W);
    HIBYTE(v9) = R2_W;
    v9 += 32;
    int8 v10 = v9;
    LOBYTE(v9) = HIBYTE(v9);
    HIBYTE(v9) = v10;
    R2_W = v9;
    uint16 v11 = R0_W;
    R0_W += 64;
    if ((R0_W & 0x7C0) == 0) {
      R0_W = (v11 & 0xF83F) + 0x1000;
      LOBYTE(v12) = HIBYTE(R2_W);
      HIBYTE(v12) = R2_W;
      v13 = ((v12 - 32) & 0x341F) + 0x800;
      int8 v14 = v13;
      LOBYTE(v13) = HIBYTE(v13);
      HIBYTE(v13) = v14;
      R2_W = v13;
    }
    --R6_W;
  } while ((R6_W & 0x8000) == 0);
  return v0;
}

void OwEventProcess07_SilentEventsAndEndOfEvent() {  // 04e9ec
  R15_ = ow_current_event_number;
  OwEventProcess07_SilentEventsAndEndOfEvent_Entry2(ow_current_event_number);
}

void OwEventProcess07_SilentEventsAndEndOfEvent_Entry2(uint8 a) {  // 04e9f1
  for (uint8 i = 43; (i & 0x80) == 0; --i) {
    if (a == kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles[i]) {
      uint8 v4 = i;
      R2_ = kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileLayer[i];
      uint16 v2 = (uint8)(2 * i);
      int v3 = (uint8)v2 >> 1;
      R0_W = kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileNum[v3];
      R4_W = kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TilemapLocation[v3];
      if ((R2_W & 1) != 0)
        BufferEventTileToLayer2Tilemap_Entry2(v2, R0_W);
      else
        blocks_map16_table_lo[R4_W] = R0_;
      i = v4;
      a = R15_;
    }
  }
  if (pointer_overworld_event_process) {
    pointer_overworld_event_process = 0;
    ++pointer_current_overworld_process;
    ow_event_flags[ow_current_event_number >> 3] |= kBitTable_DATA_04E44B[ow_current_event_number & 7];
    ++counter_events_triggered;
    counter_enemy_rollcall_screen = 0;
  }
}

void OwEventProcess03_GetLayer2Tile_04EA62() {  // 04ea62
  timer_level_end_fade = 0;
  palettes_level_end_color_fade_direction = 0;
  for (uint8 i = 111; (i & 0x80) == 0; --i) {
    *((uint8 *)&palettes_copy_of_palette_mirror[1] + i) = *((uint8 *)palettes_palette_mirror + i);
    *((uint8 *)&palettes_copy_of_palette_mirror[58] + i) = 0;
  }
  for (uint8 j = 111; (j & 0x80) == 0; j -= 16) {
    int8 v2 = 16;
    do {
      *((uint8 *)&palettes_copy_of_palette_mirror[1] + j) = *((uint8 *)&palettes_palette_mirror[64] + j);
      --j;
      --v2;
    } while (v2);
  }
  OwEventProcess03_GetLayer2Tile_04EA8B();
}

void OwEventProcess03_GetLayer2Tile_04EA8B() {  // 04ea8b
  palettes_copy_of_palette_mirror[0] = 112;
  palettes_copy_of_palette_mirror[57] = 0xc070;
  LOBYTE(palettes_copy_of_palette_mirror[114]) = 0;
  palettes_palette_upload_table_index = 3;
}

void OwEventProcess04_FadeInLayer2Tile() {  // 04eaa4
  if (timer_level_end_fade < 0x40) {
    GetXAndYDispOfCurrentEventTileSprite();
    uint16 v0 = 140;
    int16 v1 = 6;
    if (*(uint16 *)&timer_destroy_tile_event_unknown >= 0x900) {
      v0 = 12;
      v1 = 2;
    }
    *(uint16 *)&R5_ = v1;
    uint16 v2 = *(uint16 *)&timer_destroy_tile_event_unknown;
    do {
      R3_ = R5_;
      uint8 v3 = R0_;
      do {
        R2_ = v3;
        OamEnt *oam = get_OamEnt(oam_buf, v0);
        oam[84].ypos = R1_;
        oam[84].charnum = kOverworldLayer2EventTilemap_Tiles[v2];
        R4_ = ow_layer2_event_tiles[v2] & 0xC0;
        oam[84].flags = R4_ | ((uint8)(ow_layer2_event_tiles[v2] & 0x1C) >> 1) | 0x11;
        uint8 v5 = R2_;
        oam[84].xpos = R2_;
        v3 = v5 + 8;
        ++v2;
        v0 -= 4;
        --R3_;
      } while (R3_);
      R1_ += 8;
    } while (v0 != 0xFFFC);
    for (int8 i = 35; i >= 0; --i)
      sprites_oamtile_size_buffer[(uint8)i + 84] = 0;
    uint8 v7 = 8;
    if (ow_players_map[player_current_character] == 3)
      v7 = 1;
    temp8a = v7;
    do {
      OwEventProcess04_FadeInLayer2Tile_00B006(timer_level_end_fade);
      --temp8a;
    } while (temp8a);
    OwEventProcess03_GetLayer2Tile_04EA8B();
  } else {
    ++pointer_overworld_event_process;
    OwEventProcess04_FadeInLayer2Tile_04EE30();
    BufferEventTileToLayer2Tilemap();
    if (++ow_starting_event_tile < ow_final_event_tile)
      pointer_overworld_event_process = 3;
  }
}

void OwEventProcess06_FadeInLayer1Tile() {  // 04ebeb
  if ((--timer_destroy_tile_event_unknown & 0x80) == 0) {
    uint8 v0 = timer_destroy_tile_event_unknown;
    uint8 v1;
    if (pointer_overworld_event_process == 1) {
      if (timer_destroy_tile_event_unknown == 24) {
        OwEventProcess01_DestroyTileAnimation_04EEAA();
        v0 = 24;
      }
      v1 = v0 & 0xFC;
      R2_ = kOwEventProcess01_DestroyTileAnimation_DATA_04EBE1[(uint8)(v0 & 0xFC) >> 2];
      GetXAndYDispOfCurrentEventTileSprite();
    } else {
      if (timer_destroy_tile_event_unknown == 16) {
        OwEventProcess01_DestroyTileAnimation_04ED83();
        v0 = 16;
      }
      R2_ = kOwEventProcess01_DestroyTileAnimation_DATA_04EBDA[v0 >> 2];
      GetXAndYDispOfCurrentEventTileSprite();
      v1 = 40;
    }
    R3_ = 3;
    uint8 v2 = 0;
    do {
      OamEnt *oam = get_OamEnt(oam_buf, v2);
      oam[32].xpos = kOwEventProcess01_DestroyTileAnimation_DATA_04EB56[v1] + R0_;
      oam[32].ypos = kOwEventProcess01_DestroyTileAnimation_DATA_04EB82[v1] + R1_;
      oam[32].charnum = R2_;
      oam[32].flags = kOwEventProcess01_DestroyTileAnimation_DATA_04EBAE[v1];
      v2 += 4;
      ++v1;
      --R3_;
    } while ((R3_ & 0x80) == 0);
    sprites_oamtile_size_buffer[32] = 0;
    sprites_oamtile_size_buffer[33] = 0;
    sprites_oamtile_size_buffer[34] = 0;
    sprites_oamtile_size_buffer[35] = 0;
  } else {
    ++pointer_overworld_event_process;
  }
}

void GetXAndYDispOfCurrentEventTileSprite() {  // 04ec67
  R0_ = ow_on_screen_xpos_of_current_event_tile - mirror_current_layer2_xpos;
  R1_ = ow_on_screen_ypos_of_current_event_tile - (mirror_current_layer2_ypos + 1);
}

void OwEventProcess05_GetLayer1Tile() {  // 04ec78
  R15_ = 126;
  *(uint16 *)&R13_ = 0xc800;
  uint16 v0 = 21;
  uint8 v1 = *IndirPtr(&R13_, kChangingLayer1OverworldTiles_Layer1TileLocation[(uint16)(2 * ow_current_event_number) >> 1]);
  while (v1 != kChangingLayer1OverworldTiles_TilesThatChange[v0]) {
    if ((--v0 & 0x8000) != 0) {
      pointer_overworld_event_process = 7;
      return;
    }
  }
  io_sound_ch3 = 1;
  ++pointer_overworld_event_process;
  ow_on_screen_xpos_of_current_event_tile =
      16 * *((uint8 *)kChangingLayer1OverworldTiles_Layer1TileLocation + (uint8)(2 * ow_current_event_number));
  ow_on_screen_ypos_of_current_event_tile =
      *((uint8 *)kChangingLayer1OverworldTiles_Layer1TileLocation + (uint8)(2 * ow_current_event_number)) & 0xF0;
  timer_destroy_tile_event_unknown = 28;
}

void OwEventProcess01_DestroyTileAnimation_04ED83() {  // 04ed83
  R15_ = 126;
  *(uint16 *)&R13_ = 0xc800;
  uint16 v0 = 21;
  uint8 v1 = *IndirPtr(&R13_, kChangingLayer1OverworldTiles_Layer1TileLocation[(uint16)(2 * ow_current_event_number) >> 1]);
  do {
    if (v1 == kChangingLayer1OverworldTiles_TilesThatChange[v0])
      break;
    --v0;
  } while (v0);
  R14_W = v0;
  int v2 = (uint16)(2 * ow_current_event_number) >> 1;
  R0_W = kOwEventProcess01_DestroyTileAnimation_DATA_04D93D[v2];
  blocks_map16_table_lo[kChangingLayer1OverworldTiles_Layer1TileLocation[v2]] = kChangingLayer1OverworldTiles_TilesToBecome[v0];
  R12_ = 4;
  R10_W = 0xecd3;
  OwEventProcess01_DestroyTileAnimation_04EDE6(stripe_image_upload, 8 * R14_W);
}

void OwEventProcess01_DestroyTileAnimation_04EDE6(uint16 k, uint16 j) {  // 04ede6
  uint16 v2 = R0_W;
  *(uint16 *)&stripe_image_upload_data[k] = R0_W;
  *(uint16 *)&stripe_image_upload_data[k + 8] = v2 + 0x2000;
  *(uint16 *)&stripe_image_upload_data[k + 2] = 768;
  *(uint16 *)&stripe_image_upload_data[k + 10] = 768;
  *(uint16 *)&stripe_image_upload_data[k + 4] = *(uint16 *)IndirPtr(&R10_W, j);
  uint16 v3 = j + 2;
  *(uint16 *)&stripe_image_upload_data[k + 12] = *(uint16 *)IndirPtr(&R10_W, v3);
  v3 += 2;
  *(uint16 *)&stripe_image_upload_data[k + 6] = *(uint16 *)IndirPtr(&R10_W, v3);
  *(uint16 *)&stripe_image_upload_data[k + 14] = *(uint16 *)IndirPtr(&R10_W, v3 + 2);
  *(uint16 *)&stripe_image_upload_data[k + 16] = 255;
  stripe_image_upload = k + 16;
}

void OwEventProcess04_FadeInLayer2Tile_04EE30() {  // 04ee30
  uint16 v2;

  R14_ = 127;
  uint16 v0 = 4 * ow_starting_event_tile;
  int v1 = (uint16)(4 * ow_starting_event_tile) >> 1;
  R0_W = kLayer2EventData_TileEntries[v1 + 1];
  LOBYTE(v2) = (uint16)(((uint16)(R0_W & 0x1FFF) >> 1) + 0x3000) >> 8;
  HIBYTE(v2) = (uint16)(R0_W & 0x1FFF) >> 1;
  R2_W = v2;
  R12_W = 0x4000;
  R10_W = -1;
  if (kLayer2EventData_TileEntries[v1] < 0x900)
    v0 = BufferEventTileToStripeImageTable_Buffer6x6Tile();
  else
    v0 = BufferEventTileToStripeImageTable_Buffer2x2Tile();
  *(uint16 *)&stripe_image_upload_data[v0] = 255;
  stripe_image_upload = v0;
}

void OwEventProcess01_DestroyTileAnimation_04EEAA() {  // 04eeaa
  uint16 v2;

  R15_ = 126;
  R12_ = 4;
  *(uint16 *)&R13_ = 0xc800;
  R10_W = 0xee7a;
  R0_W = kOwEventProcess01_DestroyTileAnimation_DATA_04E587[(uint16)(2 * ow_destroy_tile_event_vramindex) >> 1];
  uint16 v0 = stripe_image_upload;
  if (!sign16(ow_destroy_tile_event_tile_index - 3)) {
    uint16 v1 = 8 * ow_destroy_tile_event_tile_index;
    v2 = R0_W;
    *(uint16 *)&stripe_image_upload_data[stripe_image_upload] = R0_W;
    v2 += 0x2000;
    *(uint16 *)&stripe_image_upload_data[v0 + 8] = v2;
    int8 v3 = v2;
    LOBYTE(v2) = HIBYTE(v2);
    HIBYTE(v2) = v3;
    v2 += 32;
    int8 v4 = v2;
    LOBYTE(v2) = HIBYTE(v2);
    HIBYTE(v2) = v4;
    R0_W = v2;
    *(uint16 *)&stripe_image_upload_data[v0 + 2] = 768;
    *(uint16 *)&stripe_image_upload_data[v0 + 10] = 768;
    *(uint16 *)&stripe_image_upload_data[v0 + 4] = *(uint16 *)IndirPtr(&R10_W, v1);
    v1 += 2;
    *(uint16 *)&stripe_image_upload_data[v0 + 12] = *(uint16 *)IndirPtr(&R10_W, v1);
    v1 += 2;
    *(uint16 *)&stripe_image_upload_data[v0 + 6] = *(uint16 *)IndirPtr(&R10_W, v1);
    *(uint16 *)&stripe_image_upload_data[v0 + 14] = *(uint16 *)IndirPtr(&R10_W, v1 + 2);
    v0 += 16;
  }
  uint16 v5;
  if (sign16(ow_destroy_tile_event_tile_index - 2))
    v5 = 8 * ow_destroy_tile_event_tile_index;
  else
    v5 = 40;
  OwEventProcess01_DestroyTileAnimation_04EDE6(v0, v5);
}

void DrawFlyingSwitchBlocks() {  // 04f290
  int16 v8;

  if (player_on_tilting_platform_ypos_hi < 0xC) {
    if (!player_on_tilting_platform_xpos_hi) {
      if (player_on_tilting_platform_ypos_hi < 8) {
        io_sound_ch3 = 28;
        R0_ = 7;
        uint8 v0 = temp1436;
        do {
          uint8 *pt = (uint8 *)get_PointU16(ow_players_pos, player_current_characterx4);
          blocks_layer2_tiles_lo[v0 + 120] = *pt;
          blocks_layer2_tiles_lo[v0] = pt[1];
          blocks_layer2_tiles_lo[v0 + 160] = pt[2];
          blocks_layer2_tiles_lo[v0 + 40] = pt[3];
          blocks_layer2_tiles_lo[v0 + 200] = 0;
          blocks_layer2_tiles_lo[v0 + 80] = 0;
          uint8 v2 = R0_;
          blocks_layer2_tiles_lo[v0 + 240] = kDrawFlyingSwitchBlocks_XSpeed[R0_];
          blocks_layer2_tiles_lo[v0 + 280] = kDrawFlyingSwitchBlocks_YSpeed[v2];
          blocks_layer2_tiles_lo[v0++ + 320] = -48;
          --R0_;
        } while ((R0_ & 0x80) == 0);
        if (v0 >= 0x28) {
          uint8 v3 = temp1438 + 32;
          if ((uint8)(temp1438 + 32) >= 0xA0)
            v3 = 0;
          temp1438 = v3;
          v0 = 0;
        }
        temp1436 = v0;
      }
      player_on_tilting_platform_xpos_hi = 16;
      ++player_on_tilting_platform_ypos_hi;
    }
    --player_on_tilting_platform_xpos_hi;
    R15_ = temp1438;
    uint8 v4 = 0;
    do {
      uint8 v5 = DrawFlyingSwitchBlocks_04F39C(v4, 0);
      uint8 v6 = DrawFlyingSwitchBlocks_04F39C(v4 + 40, v5);
      DrawFlyingSwitchBlocks_04F39C(v4 + 80, v6);
      int8 v7 = blocks_layer2_tiles_lo[v4 + 320] + 1;
      if (v7 >= 64)
        v7 = 64;
      blocks_layer2_tiles_lo[v4 + 320] = v7;
      HIBYTE(v8) = blocks_layer2_tiles_lo[v4 + 80];
      LOBYTE(v8) = blocks_layer2_tiles_lo[v4 + 200];
      R2_W += v8;
      if (!(R1_ | HIBYTE(R2_W))) {
        uint8 v9 = R15_;
        OamEnt *oam = get_OamEnt(oam_buf, R15_);
        oam[80].ypos = R2_W;
        oam[80].xpos = R0_;
        oam[80].charnum = -26;
        oam[80].flags = (2 * (misc_color_of_palace_switch_pressed1 - 1)) | 0x30;
        sprites_oamtile_size_buffer[(v9 >> 2) + 80] = 2;
      }
      uint8 v11 = R15_ + 4;
      if ((uint8)(R15_ + 4) >= 0xA0)
        v11 = 0;
      R15_ = v11;
      ++v4;
    } while (v4 < temp1436 || player_on_tilting_platform_ypos_hi >= 5 && v4 < 0x28);
  } else {
    misc_color_of_palace_switch_pressed1 = 0;
  }
}

uint8 DrawFlyingSwitchBlocks_04F39C(uint8 k, uint8 j) {  // 04f39c
  uint16 sub = blocks_layer2_tiles_lo[k + 360] + (uint8)(16 * blocks_layer2_tiles_lo[k + 240]);
  blocks_layer2_tiles_lo[k + 360] = sub;
  uint16 spd = ((int8)blocks_layer2_tiles_lo[k + 240] >> 4) + (sub >> 8);
  uint16 pos = PAIR16(blocks_layer2_tiles_lo[k], blocks_layer2_tiles_lo[k + 120]) + spd;
  blocks_layer2_tiles_lo[k + 120] = pos;
  blocks_layer2_tiles_lo[k] = pos >> 8;
  *(uint16 *)((int8 *)&R0_W + j) = pos - *(uint16 *)((int8 *)&mirror_current_layer1_xpos + j) - 8;
  return j + 2;
}

void DisplayOwPrompt(uint8 a) {  // 04f3e5
  kDisplayOwPrompt_Ptrs04F3EA[(uint8)(a - 1)]();
}

void OwPrompt01_InitializeOwPrompt() {  // 04f3ff
  io_sound_ch3 = 34;
  ++pointer_display_overworld_prompt;
  OwPrompt01_InitializeOwPrompt_04F407();
}

void OwPrompt01_InitializeOwPrompt_04F407() {  // 04f407
  mirror_bg1_and2_window_mask_settings = 0;
  mirror_bg3_and4_window_mask_settings = 0;
  mirror_object_and_color_window_settings = 0;
  mirror_hdmaenable = 0;
}

void OwPrompt02_ExpandPromptWindow() {  // 04f415
  int16 v0;

  flag_who_gets_lives_in_exchange_menu = (int8)(players_lives[0] - players_lives[1]) < 0;
  if (timer_wait_before_message_window_size_change ==
      kOwPrompt02_ExpandPromptWindow_DATA_04F413[flag_message_window_size_change_direction]) {
    if (++pointer_display_overworld_prompt == 7)
      graphics_stripe_image_to_upload = 30;
    if (((pointer_display_overworld_prompt - 1) & 3) == 0) {
      pointer_display_overworld_prompt = 0;
      flag_message_window_size_change_direction = 0;
      OwPrompt01_InitializeOwPrompt_04F407();
    }
  } else {
    timer_wait_before_message_window_size_change +=
        kOwPrompt02_ExpandPromptWindow_DATA_04F411[flag_message_window_size_change_direction];
    HIBYTE(v0) = timer_wait_before_message_window_size_change + 0x80;
    for (uint16 i = 366; (i & 0x8000) == 0; i -= 2) {
      misc_hdmawindow_effect_table[i + 80] = -1;
      misc_hdmawindow_effect_table[i + 81] = 0;
    }
    int8 v2 = ((uint8)(timer_wait_before_message_window_size_change + (timer_wait_before_message_window_size_change & 1) +
                       (timer_wait_before_message_window_size_change >> 1)) >>
               1) &
              0xFE;
    LOBYTE(v0) = 0x80 - timer_wait_before_message_window_size_change;
    uint8 v3 = 72;
    do {
      *(uint16 *)&misc_hdmawindow_effect_table[v3 + 168] = v0;
      *(uint16 *)&misc_hdmawindow_effect_table[(uint8)v2 + 240] = v0;
      v3 -= 2;
      v2 -= 2;
    } while (v2 >= 0);
    palettes_background_color = 0;
    mirror_bg1_and2_window_mask_settings = 34;
    mirror_object_and_color_window_settings = 32;
    mirror_hdmaenable = 0x80;
  }
}

void OwPrompt03_OverworldLifeExchanger() {  // 04f513
  if (((io_controller_press1_copyp2 | io_controller_press1_copyp1) & 0x10) != 0) {
    player_current_life_count = players_lives[player_current_character];
    CloseOwPrompt();
    return;
  }
  int8 v0 = io_controller_press1_copyp1 & 0xC0;
  if ((io_controller_press1_copyp1 & 0xC0) != 0)
    goto LABEL_6;
  if ((io_controller_press1_copyp2 & 0xC0) != 0) {
    v0 = io_controller_press1_copyp2 & 0xC0 ^ 0xC0;
LABEL_6:;
    bool v1 = __CFSHL__(v0, 1);
    if (__CFSHL__(v0, 1) != flag_who_gets_lives_in_exchange_menu)
      timer_life_exchange_blinking_arrow_frames = 24;
    flag_who_gets_lives_in_exchange_menu = __CFSHL__(v0, 1);
    bool v2 = !__CFSHL__(v0, 1);
    if ((int8)players_lives[v1] > 0 && sign8(players_lives[v2] - 98)) {
      ++players_lives[v2];
      --players_lives[v1];
      io_sound_ch3 = 35;
    }
  }
  OamEnt *oam = get_OamEnt(oam_buf, 0);
  *(uint16 *)&oam[39].xpos = 0x7848;
  *(uint16 *)&oam[40].xpos = 0x7890;
  *(uint16 *)&oam[39].charnum = 0x340a;
  *(uint16 *)&oam[40].charnum = 0x360a;
  sprites_oamtile_size_buffer[39] = 2;
  sprites_oamtile_size_buffer[40] = 2;
  LoadOverworldLifeCounter();
  int8 v4 = 80;
  LOBYTE(stripe_image_upload) = stripe_image_upload + 80;
  uint8 v5 = stripe_image_upload;
  do
    stripe_image_upload_data[v5--] = kLifeExchangeText_Mario[(uint8)v4--];
  while (v4 >= 0);
  uint8 v6 = v5 + 1;
  if ((players_lives[0] & 0x80) == 0) {
    *(uint16 *)&stripe_image_upload_data[v6 + 68] = 0x38fc;
    *(uint16 *)&stripe_image_upload_data[v6 + 70] = 0x38fc;
  }
  uint8 v7 = players_lives[1];
  if ((players_lives[1] & 0x80) == 0) {
    *(uint16 *)&stripe_image_upload_data[v6 + 76] = 0x38fc;
    *(uint16 *)&stripe_image_upload_data[v6 + 78] = 0x38fc;
  }
  if ((++timer_life_exchange_blinking_arrow_frames & 0x18) != 0) {
    v7 = 2 * flag_who_gets_lives_in_exchange_menu;
    int v8 = (uint8)(2 * flag_who_gets_lives_in_exchange_menu) >> 1;
    *(uint16 *)&stripe_image_upload_data[v6 + 52] = kOwPrompt03_OverworldLifeExchanger_DATA_04F503[v8];
    *(uint16 *)&stripe_image_upload_data[v6 + 54] = kOwPrompt03_OverworldLifeExchanger_DATA_04F507[v8];
    *(uint16 *)&stripe_image_upload_data[v6 + 60] = kOwPrompt03_OverworldLifeExchanger_DATA_04F50B[v8];
    *(uint16 *)&stripe_image_upload_data[v6 + 62] = kOwPrompt03_OverworldLifeExchanger_DATA_04F50F[v8];
  }
  OwPrompt03_OverworldLifeExchanger_04F60E(v6, v7, players_lives[0]);
  OwPrompt03_OverworldLifeExchanger_04F60E(v6 + 10, v7, players_lives[1]);
}

void OwPrompt03_OverworldLifeExchanger_04F60E(uint8 k, uint8 j, uint8 a) {  // 04f60e
  PairU16 v3 = OwPrompt03_OverworldLifeExchanger_00974C(a + 1);
  uint8 second = v3.second;
  if (!LOBYTE(v3.second))
    second = -4;
  stripe_image_upload_data[k + 36] = v3.first;
  stripe_image_upload_data[k + 34] = second;
}

void LoadOverworldSprites() {  // 04f675
  uint8 v0 = 12;
  uint8 v1 = 15;
  do {
    int8 v2 = kLoadOverworldSprites_SpriteSlotData[v1 - 3].field_0;
    owspr_spriteid[v0 + 3] = v2;
    if (v2 == 1 || v2 == 2)
      owspr_zpos_lo[v0 + 3] = 64;
    owspr_xpos_lo[v0 + 3] = kLoadOverworldSprites_SpriteSlotData[v1 - 3].field_1;
    owspr_xpos_hi[v0 + 3] = HIBYTE(kLoadOverworldSprites_SpriteSlotData[v1 - 3].field_1);
    owspr_ypos_lo[v0 + 3] = kLoadOverworldSprites_SpriteSlotData[v1 - 3].field_3;
    owspr_ypos_hi[v0 + 3] = HIBYTE(kLoadOverworldSprites_SpriteSlotData[v1 - 3].field_3);
    --v1;
    --v0;
  } while ((v0 & 0x80) == 0);
  for (uint8 i = 13; i < 0x10; ++i) {
    owspr_table0e25[i] = 0;
    owspr_zspeed[i] = kOWSpr09_Bowser_DATA_04FD22[0] - 1;
    uint8 v4 = kLoadOverworldSprites_UNK_04F672[i - 13];
    do {
      uint8 v5 = v4;
      misc_which_file_to_erase = i;
      ProcessOverworldSprites(i);
      v4 = v5 - 1;
    } while (v4 != 0);
  }
}

void OverworldLightningAndRandomCloudSpawning() {  // 04f708
  unsigned int v4;
  int16 v15;

  if (CheckIfXIsAllowedOnYSubmap_Lightning(0xF7))
    goto LABEL_9;
  uint8 v0 = palettes_lightning_flash_color_index;
  if (!palettes_lightning_flash_color_index) {
    if (!(counter_global_frames & 1))
      goto LABEL_9;
    if (--timer_wait_before_next_lightning_flash)
      goto LABEL_9;
    uint8 v1 = kOverworldLightningAndRandomCloudSpawning[counter_global_frames >> 1] & 7;
    timer_wait_before_next_lightning_flash = kOverworldLightningAndRandomCloudSpawning_DATA_04F6F8[v1];
    v0 = kOverworldLightningAndRandomCloudSpawning_DATA_04F700[v1];
    palettes_lightning_flash_color_index = v0;
    timer_lightning_frame_duration = 8;
    io_sound_ch3 = 24;
  }
  if ((--timer_lightning_frame_duration & 0x80) != 0) {
    --palettes_lightning_flash_color_index;
    timer_lightning_frame_duration = 4;
  }
  uint8 v2 = v0;
  uint8 v3 = palettes_dynamic_palette_upload_index;
  v4 = palettes_dynamic_palette_upload_index;
  *(&palettes_dynamic_palette_bytes_to_upload + palettes_dynamic_palette_upload_index) = 2;
  *(&palettes_dynamic_palette_cgramaddress + v4) = 71;
  palettes_dynamic_palette_colors[v3] = palettes_palette_mirror[v2 + 40];
  palettes_dynamic_palette_colors[v3 + 1] = HIBYTE(palettes_palette_mirror[v2 + 40]);
  palettes_dynamic_palette_colors[v3 + 2] = 0;
  palettes_dynamic_palette_upload_index = v3 + 4;
LABEL_9:
  for (uint8 i = 2; (i & 0x80) == 0; --i) {
    if (!owspr_spriteid[i]) {
      owspr_spriteid[i] = 5;
      uint8 v6 = SetOverworldSpriteFrameIndex(i);
      owspr_zpos_lo[i] = kOverworldLightningAndRandomCloudSpawning_DATA_04F6D0[v6 & 7];
      int v7 = (uint8)(2 * (v6 & 7)) >> 1;
      int16 v8 = kOverworldLightningAndRandomCloudSpawning_DATA_04F6D8[v7] + mirror_current_layer1_xpos;
      owspr_xpos_lo[i] = v8;
      owspr_xpos_hi[i] = HIBYTE(v8);
      int16 v9 = kOverworldLightningAndRandomCloudSpawning_DATA_04F6E8[v7] + mirror_current_layer1_ypos;
      owspr_ypos_lo[i] = v9;
      owspr_ypos_hi[i] = HIBYTE(v9);
    }
  }
  for (int8 j = 4; j >= 0; --j)
    *(&sprites_overworld_cloud_sync_table + (uint8)j) = j;
  uint8 v11 = 4;
  do {
    R0_ = v11;
    do {
      R1_ = v11;
      int v12 = *(&sprites_overworld_cloud_sync_table + R0_);
      R2_ = owspr_ypos_lo[*(&sprites_overworld_cloud_sync_table + R0_)];
      R3_ = owspr_ypos_hi[v12];
      uint8 v13 = R1_;
      uint8 v14 = *(&sprites_starting_oamindex_for_overworld_sprites + R1_);
      HIBYTE(v15) = owspr_ypos_hi[v14];
      LOBYTE(v15) = owspr_ypos_lo[v14];
      if ((int16)(v15 - R2_W) < 0) {
        uint8 v18 = *(&sprites_starting_oamindex_for_overworld_sprites + R1_);
        uint8 v16 = R0_;
        *(&sprites_starting_oamindex_for_overworld_sprites + R1_) = *(&sprites_overworld_cloud_sync_table + R0_);
        *(&sprites_overworld_cloud_sync_table + v16) = v18;
      }
      v11 = v13 - 1;
    } while (v11);
    v11 = R0_ - 1;
  } while (R0_ != 1);
  sprites_starting_oamindex_for_overworld_sprites = 48;
  ow_enter_level_flag = 0;
  for (uint8 k = 15; (k & 0x80) == 0; --k) {
    if (k < 0xD && owspr_table0e25[k])
      --owspr_table0e25[k];
    if (k < 5) {
      misc_which_file_to_erase = *(&sprites_overworld_cloud_sync_table + k);
      ProcessOverworldSprites(misc_which_file_to_erase);
    } else {
      misc_which_file_to_erase = k;
      ProcessOverworldSprites(k);
    }
  }
}

void OverworldLightningAndRandomCloudSpawning_Return04F828(uint8 k) {  // 04f828
  ;
}

void ProcessOverworldSprites(uint8 k) {  // 04f853
  if (!CheckIfXIsAllowedOnYSubmap_Sprites(k))
    kProcessOverworldSprites_OverworldSpritePtrs[owspr_spriteid[k]](k);
}

uint8 CheckIfXIsAllowedOnYSubmap_Sprites(uint8 k) {  // 04f87c
  return CheckIfXIsAllowedOnYSubmap_Lightning(kCheckIfXIsAllowedOnYSubmap_DisableSpriteOnXSubmapFlags[owspr_spriteid[k] - 1]);
}

uint8 CheckIfXIsAllowedOnYSubmap_Lightning(uint8 a) {  // 04f882
  R0_ = a;
  if (pointer_current_overworld_process == 10 && ow_submap_switch_process != 1)
    return 1;
  uint8 result = R0_ & kCheckIfXIsAllowedOnYSubmap_ANDTable[ow_players_map[(uint8)player_current_characterx4 >> 2]];
  if (result)
    return 1;
  return result;
}

void OWSpr01_Lakitu(uint8 k) {  // 04f8cc
  UpdateOverworldSpritePosition(k);
  DrawOverworldSpriteShadow(k, 0);
  GetOverworldSpriteOnScreenPosition(k);
  R4_W = R2_W;
  uint8 v2 = SetOverworldSpriteFrameIndex(k);
  uint8 v3 = ((v2 & 0x10) != 0) ? 7 : 6;
  do {
    R6_ = v3;
    R0_W += kOWSpr01_Lakitu_DATA_04F8A6[v3];
    uint32 t = R4_W + kOWSpr01_Lakitu_DATA_04F8AE[v3];
    R2_W = t;
    OWSpr05_Cloud_04FB7B(0x3228, t >> 16);
    v3 = R6_ - 2;
  } while ((int8)v3 >= 0);
  uint8 v5 = misc_which_file_to_erase;
  GetOverworldSpriteOnScreenPosition(misc_which_file_to_erase);
  OWSpr05_Cloud_04FB7A(0x3226);
  if (owspr_table0e15[v5]) {
    OWSpr01_Lakitu_CalculateOverworldLakitusSpeed(v5);
  } else {
    uint8 v6 = owspr_table0e05[v5] & 1;
    uint8 v7 = kOWSpr01_Lakitu_Acceleration[v6] + owspr_zspeed[v5];
    owspr_zspeed[v5] = v7;
    if (v7 == kOWSpr01_Lakitu_ZSpeedCap[v6])
      owspr_table0e05[v5] ^= 1;
    CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(v5);
    bool less;
    uint8 j = owspr_table0df5[v5];
    int8 v8;
    if (((R0_W ^ (2 * *(uint16 *)&owspr_table0df5[v5 + 15])) & 0x8000) == 0 ||
        (v8 = 64, (less = R6_W < *(uint16 *)&kOWSpr01_Lakitu_DATA_04F8B6[j]))) {
      int16 v9 = R2_W ^ *(uint16 *)&owspr_table0df5[v5 + 15];
      if (!(v9 & 0x80))
        goto label1;
      less = R8_W < *(uint16 *)&kOWSpr01_Lakitu_DATA_04F8BE[j];
      v8 = 0x80;
    }
    if (!less) {
      owspr_table0e05[v5] ^= v8;
      owspr_table0df5[v5] = SetOverworldSpriteFrameIndex(v5) & 6;
    }
label1:
    OWSpr01_Lakitu_04F993(v5 + 16, __CFSHL__(owspr_table0df5[v5 + 16], 1));
    OWSpr01_Lakitu_04F993(misc_which_file_to_erase, __CFSHL__(2 * owspr_table0e05[misc_which_file_to_erase], 1));
  }
}

void OWSpr01_Lakitu_04F993(uint8 k, uint8 cr) {  // 04f993
  bool v2 = cr >> 1 == 0;
  uint8 v3 = kOWSpr01_Lakitu_Acceleration[v2] + owspr_xspeed[k];
  if (v3 != kOWSpr01_Lakitu_XYSpeedCap[v2])
    owspr_xspeed[k] = v3;
}

void OWSpr02_BlueBird(uint8 k) {  // 04f9b8
  uint16 v5;
  uint16 v7;

  DrawOverworldSpriteShadow(k, 0);
  CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(k);
  uint8 v2 = kOWSpr01_Lakitu_Acceleration[(R1_ & 0x80) == 0] + owspr_xspeed[k];
  if (v2 != kOWSpr01_Lakitu_XYSpeedCap[(R1_ & 0x80) == 0])
    owspr_xspeed[k] = v2;
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  owspr_ypos_lo[k] = pt->y;
  owspr_ypos_hi[k] = HIBYTE(pt->y);
  UpdateOverworldSpritePosition(k);
  GetOverworldSpriteOnScreenPosition(k);
  int8 v4 = 54;
  if ((owspr_xspeed[k] & 0x80) == 0)
    v4 = 118;
  int8 v10 = v4;
  HIBYTE(v5) = v4;
  LOBYTE(v5) = 76;
  OWSpr05_Cloud_04FB7A(v5);
  HIBYTE(v7) = v10;
  uint8 v6 = (SetOverworldSpriteFrameIndex(k) >> 3) & 3;
  LOBYTE(v7) = kOWSpr02_BlueBird_DATA_04F9AC[v6];
  if ((owspr_xspeed[k] & 0x80) == 0)
    LOBYTE(v7) = kOWSpr02_BlueBird_DATA_04F9B0[v6];
  R0_W += (uint8)v7;
  R2_W += kOWSpr02_BlueBird_DATA_04F9B4[v6];
  LOBYTE(v7) = kOWSpr02_BlueBird_DATA_04F9A8[v6];
  OWSpr05_Cloud_04FB7B(v7, 0);
}

void OWSpr03_CheepCheep(uint8 k) {  // 04fa3e
  if (owspr_table0df5[k]) {
    OWSpr03_CheepCheep_04FA83(k);
  } else {
    uint8 v1 = ow_tile_player_is_standing_on - 78;
    if ((uint8)(ow_tile_player_is_standing_on - 78) < 3) {
      owspr_xpos_lo[k] = kOWSpr03_CheepCheep_DATA_04FA2E[v1];
      owspr_xpos_hi[k] = kOWSpr03_CheepCheep_DATA_04FA31[v1];
      owspr_ypos_lo[k] = kOWSpr03_CheepCheep_DATA_04FA34[v1];
      owspr_ypos_hi[k] = kOWSpr03_CheepCheep_DATA_04FA37[v1];
      uint8 v2 = SetOverworldSpriteFrameIndex(k);
      int8 v3 = v2 & 1;
      uint8 v4 = v2 >> 1;
      int8 v5 = 0;
      if (v3)
        v5 = 0x80;
      owspr_table0df5[k] = ((uint8)((v4 >> 1) + v5) >> 1) & 0x40 | 0x12;
      owspr_zspeed[k] = 36;
      io_sound_ch1 = 14;
      OWSpr03_CheepCheep_04FA7D(k);
    }
  }
}

void OWSpr03_CheepCheep_04FA7D(uint8 k) {  // 04fa7d
  owspr_table0e25[k] = 15;
}

void OWSpr03_CheepCheep_04FA83(uint8 k) {  // 04fa83
  if (--owspr_zspeed[k] == 0xE4)
    OWSpr03_CheepCheep_04FA7D(k);
  UpdateOverworldSpritePosition(k);
  if (!(owspr_table0e25[k] | owspr_zpos_lo[k]))
    owspr_table0df5[k] = 0;
  GetOverworldSpriteOnScreenPosition(k);
  uint8 v1 = owspr_table0df5[k];
  uint8 v2 = 8;
  if ((owspr_zspeed[k] & 0x80) != 0) {
    v1 ^= 0xC0;
    v2 = 16;
  }
  uint8 a = (counter_global_frames & v2) != 0 ? 0x48 : 0x4a;
  uint8 j = OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v1 << 8 | a);
  AddZPositionToTempYPos(k);
  R2_W -= 8;
  uint8 v6 = owspr_table0e25[k];
  if (v6) {
    v6 = kOWSpr03_CheepCheep_DATA_04FA3A[v6 >> 2];
    j = OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(j, 0x36 << 8 | v6);
    R0_W += 8;
    OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(j, 0x76 << 8 | v6);
  }
}

uint8 OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(uint8 j, uint16 a) {  // 04faed
  return OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(j, a, 0);
}

void OWSpr04_PiranhaPlant(uint8 k) {  // 04faf1
  uint16 v2;

  CheckPlayerToOverworldSpriteCollision(k);
  GetOverworldSpriteOnScreenPosition(k);
  int8 v1 = 42;
  if ((SetOverworldSpriteFrameIndex(k) & 8) != 0)
    v1 = 44;
  HIBYTE(v2) = 50;
  LOBYTE(v2) = v1;
  OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v2);
}

uint8 OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(uint8 k, uint16 a) {  // 04fb06
  return OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(kOverworldSpriteOAMIndexes[k], a, 1);
}

uint8 OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(uint8 j, uint16 a, uint8 cr) {  // 04fb0a
  OamEnt *oam = get_OamEnt(oam_buf, j);
  *(uint16 *)&oam[16].charnum = a;
  if (!R1_) {
    oam[16].xpos = R0_;
    if (!R3_) {
      oam[16].ypos = R2_;
      sprites_oamtile_size_buffer[(j >> 2) + 16] = cr << 1;
      j -= 4;
    }
  }
  return j;
}

void OWSpr05_Cloud(uint8 k) {  // 04fb37
  owspr_xspeed[k] = 2;
  owspr_yspeed[k] = -1;
  UpdateOverworldSpritePosition(k);
  GetOverworldSpriteOnScreenPosition(k);
  bool v1 = (uint16)(R0_W + 32) >= 0x140;
  if ((uint16)(R0_W + 32) < 0x140)
    v1 = (uint16)(R2_W + 128) >= 0x1A0;
  if (v1)
    owspr_spriteid[k] = 0;
  OWSpr05_Cloud_04FB77(0x32);
  R0_W += 16;
  OWSpr05_Cloud_04FB77(0x72);
}

void OWSpr05_Cloud_04FB77(uint8 a) {  // 04fb77
  uint16 v1;

  HIBYTE(v1) = a;
  LOBYTE(v1) = 68;
  OWSpr05_Cloud_04FB7A(v1);
}

void OWSpr05_Cloud_04FB7A(uint16 a) {  // 04fb7a
  OWSpr05_Cloud_04FB7B(a, 1);
}

void OWSpr05_Cloud_04FB7B(uint16 a, uint8 cr) {  // 04fb7b
  sprites_starting_oamindex_for_overworld_sprites =
      OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(sprites_starting_oamindex_for_overworld_sprites, a, cr);
}

void OWSpr06_KoopaKid(uint8 k) {  // 04fb98
  uint16 v5;
  uint8 v1;

  if (!owspr_table0df5[k]) {
    if ((uint8)(ow_tile_player_is_standing_on - 73) >= 3)
      return;
    uint8 v1 = ow_tile_player_is_standing_on - 73;
    owspr06_koopa_kid_tile_index = ow_tile_player_is_standing_on - 73;
    uint8 v2 = ow_tile_player_is_standing_on - 73;
    if ((kOWSpr06_KoopaKid_DATA_04FB85[(uint8)(ow_tile_player_is_standing_on - 73)] & owspr06_koopa_kid_activate_flag) != 0)
      return;
    owspr_xpos_lo[k] = kOWSpr06_KoopaKid_InitialXLo[v2];
    owspr_xpos_hi[k] = kOWSpr06_KoopaKid_InitialXHi[v2];
    owspr_ypos_lo[k] = kOWSpr06_KoopaKid_InitialYLo[v2];
    owspr_ypos_hi[k] = kOWSpr06_KoopaKid_InitialYHi[v2];
    owspr_table0df5[k] = 2;
    owspr_xspeed[k] = -16;
    owspr_table0e25[k] = 0;
  }
  GetOverworldSpriteOnScreenPosition(k);
  if (!owspr_table0e25[k]) {
    ++owspr_table0e05[k];
    UpdateOverworldSpritePosition_X(k);
    v1 = owspr_table0df5[k];
    if ((owspr_xpos_lo[k] & 0xF) == kOWSpr06_KoopaKid_byte_4FB96[v1 - 1]) {
      --owspr_table0df5[k];
      owspr_xspeed[k] = 4;
      owspr_table0e25[k] = 96;
    }
  }
  uint8 v3 = kOWSpr06_KoopaKid_byte_4FB94[owspr_table0df5[k] - 1];  // Fix OWSpr06_KoopaKid uninited Y
  int8 v4 = 34;
  if ((owspr_table0e05[k] & v3) == 0)
    v4 = 98;
  HIBYTE(v5) = v4;
  LOBYTE(v5) = 106;
  OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v5);
  uint8 v6 = CheckPlayerToOverworldSpriteCollision(k);
  int8 v7 = v6 & 1;
  int8 v8 = v6 >> 1;
  if (!v7)
    ow_enter_level_flag = v8 | 0x80;
}

void OWSpr07_Smoke(uint8 k) {  // 04fc46
  uint16 v7;

  uint8 v1 = ow_players_map[(uint8)player_current_characterx4 >> 2];
  owspr_xpos_lo[k] = kOWSpr07_Smoke_DATA_04FC1E[v1];
  owspr_xpos_hi[k] = HIBYTE(kOWSpr07_Smoke_DATA_04FC1E[v1]);
  owspr_ypos_lo[k] = kOWSpr07_Smoke_DATA_04FC22[v1];
  owspr_ypos_hi[k] = HIBYTE(kOWSpr07_Smoke_DATA_04FC22[v1]);
  if ((counter_global_frames & 0xF) == 0) {
    uint8 v2 = owspr_table0df5[k] + 1;
    if (v2 >= 0xC)
      v2 = 0;
    owspr_table0df5[k] = v2;
  }
  R4_ = 3;
  R6_ = counter_global_frames;
  R7_ = 0;
  uint8 v3 = kOverworldSpriteOAMIndexes[k];
  uint8 v4 = owspr_table0df5[k];
  do {
    uint8 j = v3;
    GetOverworldSpriteOnScreenPosition(misc_which_file_to_erase);
    uint8 v5 = kOWSpr07_Smoke_DATA_04FC36[v4] + R7_;
    R2_W += ~0xff | v5;
    R0_W += kOWSpr07_Smoke_DATA_04FC26[v4];
    uint8 t = v4 + 12;
    v4 = t & 0xF;
    if (t >= 0x10)
      R7_ -= 12;
    HIBYTE(v7) = 48;
    int8 v8 = 40;
    R6_ += 10;
    if ((R6_ & 0x20) != 0)
      v8 = 95;
    LOBYTE(v7) = v8;
    v3 = OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(j, v7);
    --R4_;
  } while (R4_);
}

void OWSpr08_BowserSign(uint8 k) {  // 04fce1
  uint16 v2;

  GetOverworldSpriteOnScreenPosition(k);
  R4_ = 4;
  R5_ = 111;
  uint8 v1 = kOverworldSpriteOAMIndexes[k];
  do {
    HIBYTE(v2) = (counter_global_frames >> 1) & 6 | 0x30;
    LOBYTE(v2) = R5_;
    v1 = OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(v1, v2);
    R0_ -= 8;
    --R5_;
    --R4_;
  } while (R4_);
}

void OWSpr09_Bowser(uint8 k) {  // 04fd24
  uint16 v2;

  UpdateOverworldSpritePosition(k);
  GetOverworldSpriteOnScreenPosition(k);
  GetOverworldSpriteOnScreenPosition(k);
  int8 v1 = 0;
  if ((owspr_xspeed[k] & 0x80) == 0)
    v1 = 64;
  HIBYTE(v2) = v1;
  LOBYTE(v2) = 104;
  OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v2);
  if (!(++owspr_table0e15[k] & 1)) {
    OWSpr09_Bowser_04FD55(k + 16, owspr_table0e05[k] | 2);
    OWSpr09_Bowser_04FD55(k, owspr_table0df5[k]);
  }
}

void OWSpr09_Bowser_04FD55(uint8 k, uint8 j) {  // 04fd55
  uint8 v2 = kOWSpr09_Bowser_DATA_04FD10[j] + owspr_xspeed[k];
  owspr_xspeed[k] = v2;
  if (v2 == kOWSpr09_Bowser_DATA_04FD1A[j])
    j ^= 1;
  owspr_table0df5[k] = j;
}

void OWSpr0A_Boo(uint8 k) {  // 04fd70
  uint16 v2;

  UpdateOverworldSpritePosition(k);
  GetOverworldSpriteOnScreenPosition(k);
  GetOverworldSpriteOnScreenPosition(k);
  if (ow_players_map[player_current_character]) {
    if (k == 15 && (ow_event_flags[5] & 0x12) == 0)
      R3_ = 15;
    R0_W += *(uint16 *)&kLoadOverworldSprites_SubmapBooXPosOffset[(uint8)(2 * k) - 26];
    R2_W += *(uint16 *)&kLoadOverworldSprites_SubmapBooYPosOffset[(uint8)(2 * k) - 26];
  }
  int8 v1 = 52;
  if ((owspr_xspeed[k] & 0x80) == 0)
    v1 = 68;
  HIBYTE(v2) = v1;
  LOBYTE(v2) = 96;
  OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v2);
  R0_ = owspr_table0e25[k]++;
  OWSpr0A_Boo_04FDD2(k + 32, 8);
  OWSpr0A_Boo_04FDD2(k + 16, 6);
  OWSpr0A_Boo_04FDD2(misc_which_file_to_erase, 4);
}

void OWSpr0A_Boo_04FDD2(uint8 k, uint8 a) {  // 04fdd2
  uint8 v2 = owspr_table0df5[k] | a;
  if ((R0_ & kOWSpr09_Bowser_DATA_04FD0A[v2 - 4]) != 0)
    owspr_table0df5[k] = v2;
  else
    OWSpr09_Bowser_04FD55(k, v2);
}

void DrawOverworldSpriteShadow(uint8 k, uint8 cr) {  // 04fe00
  int8 v2 = 0;
  if (cr)
    v2 = 0x80;
  R4_ = (R4_ >> 1) + v2;
  GetOverworldSpriteOnScreenPosition(k);
  AddZPositionToTempYPos(k);
  uint8 v3 = owspr_zpos_lo[k] >> 4;
  uint8 v4 = 41;
  if ((R4_ & 0x80) != 0) {
    v4 = 46;
    v3 += 8;
  }
  R5_ = v4;
  R6_ = v3;
  R0_W += kDrawOverworldSpriteShadow_LeftTileXDisp[v3];
  uint8 j = DrawOverworldSpriteShadow_04FE45(kOverworldSpriteOAMIndexes[k], 0x32);
  R0_W += kDrawOverworldSpriteShadow_RightTileXDisp[v3];
  DrawOverworldSpriteShadow_04FE45(j, 0x72);
}

uint8 DrawOverworldSpriteShadow_04FE45(uint8 j, uint8 a) {  // 04fe45
  return OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(j, R5_ | a << 8, __CFSHL__(R4_, 1));
}

void AddZPositionToTempYPos(uint8 k) {  // 04fe4e
  R2_W += owspr_zpos_lo[k];
}

uint8 SetOverworldSpriteFrameIndex(uint8 k) {  // 04fe5b
  return kSetOverworldSpriteFrameIndex_DATA_04F833[k] + counter_global_frames;
}

void GetOverworldSpriteOnScreenPosition(uint8 k) {  // 04fe62
  GetOverworldSpriteOnScreenPosition_Y(k + 16, 2);
  bool v1 = R2_ >= owspr_zpos_lo[misc_which_file_to_erase];
  R2_ -= owspr_zpos_lo[misc_which_file_to_erase];
  if (!v1)
    --R3_;
  GetOverworldSpriteOnScreenPosition_Y(misc_which_file_to_erase, 0);
}

void GetOverworldSpriteOnScreenPosition_Y(uint8 k, uint8 j) {  // 04fe7d
  int16 v2;

  HIBYTE(v2) = owspr_xpos_hi[k];
  LOBYTE(v2) = owspr_xpos_lo[k];
  *(uint16 *)((int8 *)&R0_W + j) = v2 - *(uint16 *)((int8 *)&mirror_current_layer1_xpos + j);
}

void UpdateOverworldSpritePosition(uint8 k) {  // 04fe90
  uint8 v1 = k + 32;
  UpdateOverworldSpritePosition_X(v1);
  if ((owspr_xpos_lo[v1] & 0x80) != 0)
    owspr_xpos_lo[v1] = 0;
  UpdateOverworldSpritePosition_X(v1 - 16);
  UpdateOverworldSpritePosition_X(misc_which_file_to_erase);
}

void UpdateOverworldSpritePosition_X(uint8 k) {  // 04feab
  uint16 t = (uint8)(16 * owspr_xspeed[k]) + owspr_sub_xpos[k];
  owspr_sub_xpos[k] = t;
  int16 spd = (int8)owspr_xspeed[k] >> 4;
  uint16 pos = PAIR16(owspr_xpos_hi[k], owspr_xpos_lo[k]) + spd + (t >> 8);
  owspr_xpos_lo[k] = pos;
  owspr_xpos_hi[k] = pos >> 8;
}

uint8 CheckPlayerToOverworldSpriteCollision(uint8 k) {  // 04fed7
  CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(k);
  bool v1 = R6_W >= 8;
  if (R6_W < 8)
    v1 = R8_W >= 8;
  if (!v1)
    ow_enter_level_flag = k;
  return v1;
}

void CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(uint8 k) {  // 04feef
  int16 v1;
  int16 v3;

  HIBYTE(v1) = owspr_xpos_hi[k];
  LOBYTE(v1) = owspr_xpos_lo[k];
  int16 v2 = v1 + 8 - get_PointU16(ow_players_pos, player_current_characterx4)->x;
  R0_W = v2;
  if (v2 < 0)
    v2 = -v2;
  R6_W = v2;
  HIBYTE(v3) = owspr_ypos_hi[k];
  LOBYTE(v3) = owspr_ypos_lo[k];
  int16 v4 = v3 + 8 - get_PointU16(ow_players_pos, player_current_characterx4)->y;
  R2_W = v4;
  if (v4 < 0)
    v4 = -v4;
  R8_W = v4;
}

void OWSpr01_Lakitu_CalculateOverworldLakitusSpeed(uint8 k) {  // 04ff2e
  int16 v4;

  CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(k);
  R6_ >>= 1;
  R8_ >>= 1;
  uint8 v1 = owspr_zpos_lo[k] >> 1;
  R10_ = v1;
  R5_ = 0;
  uint8 v2 = 4;
  if (v1 < R8_) {
    v2 = 2;
    v1 = R8_;
  }
  if (v1 < R6_) {
    v2 = 0;
    v1 = R6_;
  }
  if (v1) {
    R12_ = v2;
    for (uint8 i = 4; (i & 0x80) == 0; i -= 2) {
      if (i == R12_) {
        LOBYTE(v4) = 32;
      } else {
        WriteReg(WRDIVL, 0);
        WriteReg(WRDIVH, *(&R6_ + i));
        WriteReg(WRDIVB, *(&R6_ + v2));
        v4 = ReadRegWord(RDDIVL) >> 3;
      }
      if ((*(&R1_ + i) & 0x80) == 0)
        LOBYTE(v4) = -(int8)v4;
      *(&R0_ + i) = v4;
    }
    uint8 v5 = misc_which_file_to_erase;
    int v6 = misc_which_file_to_erase;
    owspr_xspeed[misc_which_file_to_erase] = R0_;
    owspr_yspeed[v6] = R2_;
    owspr_zspeed[v5] = R4_;
  } else {
    owspr_table0e15[k] = 0;
    owspr_xspeed[k] = 0;
    owspr_yspeed[k] = 0;
    owspr_zspeed[k] = 0;
    owspr_zpos_lo[k] = 64;
  }
}
