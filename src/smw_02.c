#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"

void (*kProcessMinorExtendedSprites_MinorExtendedSpritesPtrs[12])(uint8 k) = {
    &ProcessMinorExtendedSprites_Return, &MExtSpr01_BrickPiece,  &MExtSpr02_SmallStar,   &MExtSpr03_EggShell,
    &MExtSpr04_PodobooFire,         &MExtSpr02_SmallStar,   &MExtSpr06_RipVanFishZ, &MExtSpr07_WaterSplash,
    &MExtSpr06_RipVanFishZ,         &MExtSpr06_RipVanFishZ, &MExtSpr0A_BooStream,   &MExtSpr0B_UnusedYoshiSmoke,
};
void (*kProcessBounceAndSmokeSprites_BounceSpritePtrs[8])(uint8 k) = {
    &ProcessBounceAndSmokeSprites_Return02904C,
    &BounceSpr01_TurnBlock,
    &BounceSpr01_TurnBlock,
    &BounceSpr01_TurnBlock,
    &BounceSpr01_TurnBlock,
    &BounceSpr01_TurnBlock,
    &BounceSpr01_TurnBlock,
    &BounceSpr07_SpinningTurnBlock,
};
void (*kUnk_296cb[6])(uint8 k) = {
    &ProcessBounceAndSmokeSprites_Return0296D7,
    &SmokeSpr01_PuffOfSmoke,
    &SmokeSpr02_ContactEffect,
    &SmokeSpr03_TurnAroundSmoke,
    &ProcessBounceAndSmokeSprites_Return0296D7,
    &SmokeSpr05_Glitter,
};
void (*kProcessExtendedSprites_ExtendedSpritePtrs[19])(uint8 k) = {
    &ProcessExtendedSprites_Return029B15,
    &ExtSpr01_SmokePuff,
    &ExtSpr02_ReznorFireball,
    &ExtSpr03_FlameRemnant,
    &ExtSpr04_Hammer,
    &ExtSpr05_MarioFireball,
    &ExtSpr0D_Baseball,
    &ExtSpr07_LavaSplash,
    &ExtSpr08_LauncherArm,
    &ExtSpr09_Unused,
    &ExtSpr0A_CloudCoin,
    &ExtSpr04_Hammer,
    &ExtSpr0C_VolcanoLotusFire,
    &ExtSpr0D_Baseball,
    &ExtSpr0A_CloudCoin,
    &ExtSpr0F_SmokeTrail,
    &ExtSpr10_SpinJumpStars,
    &ExtSpr11_YoshiFireball,
    &ExtSpr12_BreathBubble,
};
void (*kUnk_2b00c[15])(void) = {
    &GenSpr01_GenerateEerie,          &GenSpr02_GenParachuteEnemy,
    &GenSpr02_GenParachuteEnemy,      &GenSpr02_GenParachuteEnemy,
    &GenSprXX_GenerateDolphins,       &GenSprXX_GenerateDolphins,
    &GenSpr07_GenerateFish,           &GenSpr08_TurnOffRespawningSprite,
    &GenSpr09_GenerateSuperKoopa,     &GenSpr0A_GenerateBubbles,
    &GenSpr0B_GenerateBullet,         &GenSpr0D_GenerateDiagnalBullets,
    &GenSpr0D_GenerateDiagnalBullets, &GenSpr0E_GenerateFire,
    &GenSpr0F_TurnOffGenerator,
};
void (*kProcessShooterSprites_ShooterSprPtrs[3])(uint8 k) = {
    &ShooterSpr01_BulletBillShooter,
    &ShooterSpr02_TorpedoShooter,
    &ProcessShooterSprites_Return02B3AA,
};
void (*kSpr091_CharginChuck_ChuckPtrs[13])(uint8 k) = {
    &Spr091_CharginChuck_State00_LookingSideToSide, &Spr091_CharginChuck_State01_Charging,
    &Spr091_CharginChuck_State02_PrepareToCharge,   &Spr091_CharginChuck_State03_Hurt,
    &Spr091_CharginChuck_State04_Digging,           &Spr091_CharginChuck_State05_PrepareToJumpOrSplit,
    &Spr091_CharginChuck_State06_Jumping,           &Spr091_CharginChuck_State07_LandFromJump,
    &Spr091_CharginChuck_State08_Clappin,           &Spr091_CharginChuck_State09_Puntin,
    &Spr091_CharginChuck_State0A_Pitchin,           &Spr091_CharginChuck_State0B_WaitToWhistle,
    &Spr091_CharginChuck_State0C_Whistlin,
};
void (*kUnk_2cdf8[3])(uint8 k) = {
    &SprXXX_WallSpringboard_Return02CDFE,
    &SprXXX_WallSpringboard_State01_PlayerIsOnTop,
    &SprXXX_WallSpringboard_State02_Rebound,
};
void (*kUnk_2e747[2])(uint8 k) = {
    &Spr047_SwimmingAndJumpingCheepCheep_Swimming,
    &Spr047_SwimmingAndJumpingCheepCheep_Jumping,
};
void (*kSprXXX_SuperKoopas_SuperKoopaPtrs[3])(uint8 k) = {
    &SprXXX_SuperKoopas_GroundedSuperKoopaState00_Running,
    &SprXXX_SuperKoopas_GroundedSuperKoopaState01_Jumping,
    &SprXXX_SuperKoopas_GroundedSuperKoopaState02_Flying,
};
void (*kProcessClusterSprites_ClusterSpritePtrs[9])(uint8 k) = {
    &ProcessClusterSprites_Return02F820,
    &ClusterSpr01_1up,
    NULL,
    &ClusterSpr03_BooCeiling,
    &ClusterSpr04_BooRing,
    &ClusterSpr05_CandleFlame,
    &ClusterSpr06_SumoBroFlame,
    &ClusterSpr07_ReappearingBoo,
    &ClusterSpr03_BooCeiling,

};

void DropReservedItem() {  // 028008
  uint8 v0 = player_current_item_box;
  if (player_current_item_box) {
    player_current_item_box = 0;
    io_sound_ch3 = 12;
    uint8 k = 11;
    while (spr_current_status[k]) {
      if ((--k & 0x80) != 0) {
        if ((--spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
          spr_slot_to_overwrite_when_slots_full = 1;
        k = spr_slot_to_overwrite_when_slots_full + 10;
        if (spr_spriteid[(uint8)(spr_slot_to_overwrite_when_slots_full + 10)] == 125 && spr_current_status[k] == 11) {
          timer_inflate_from_pballoon = 0;
        }
        break;
      }
    }
    spr_current_status[k] = 8;
    spr_spriteid[k] = v0 + 115;
    InitializeNormalSpriteRAMTables(k);
    SetSprXPos(k, mirror_current_layer1_xpos + 120);
    SetSprYPos(k, mirror_current_layer1_ypos + 32);
    ++spr_table1534[k];
  }
}

void BobOmbExplosion(uint8 k) {  // 02808a
  spr_property_bits1656[k] = 0;
  spr_property_bits1662[k] = 17;
  if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
    return;
  if (!flag_sprites_locked)
    ++spr_table1570[k];
  if (spr_decrementing_table1540[k]) {
    if (((spr_decrementing_table1540[k] >> 1) & 3) == 3) {
      BobOmbExplosion_ExplodeSprites(k);
      if ((uint8)(spr_decrementing_table1540[k] - 16) < 0x20)
        CheckPlayerToNormalSpriteCollision(k);
    }
    R15_ = 4;
    do {
      int8 v4 = spr_decrementing_table1540[k] >> 1;
      R2_ = v4 & 3;
      R0_ = spr_xpos_lo[k] - mirror_current_layer1_xpos + 4;
      R1_ = spr_ypos_lo[k] - mirror_current_layer1_ypos + 4;
      uint8 v1 = R15_;
      if ((v4 & 4) != 0)
        v1 = R15_ + 5;
      do {
        R0_ += kBobOmbExplosion_BombExplosionX[v1];
        R1_ += kBobOmbExplosion_BombExplosionY[v1];
        --R2_;
      } while ((R2_ & 0x80) == 0);
      uint8 v2 = spr_oamindex[k] + 4 * R15_;
      OamEnt *oam = get_OamEnt(oam_buf, v2);
      oam[64].xpos = R0_;
      oam[64].ypos = R1_;
      oam[64].charnum = -68;
      oam[64].flags = sprites_tile_priority | (2 * ((counter_global_frames >> 2) & 3) + 1);
      sprites_oamtile_size_buffer[(v2 >> 2) + 64] = 0;
    } while ((--R15_ & 0x80) == 0);
    Spr070_Pokey_Bank02SpriteEntry(k, 0, 4);
  } else {
    spr_current_status[k] = 0;
  }
}

void BobOmbExplosion_ExplodeSprites(uint8 k) {  // 028139
  for (uint8 i = 9; (i & 0x80) == 0; --i) {
    if (i != spr_current_slotid && spr_current_status[i] >= 8)
      BobOmbExplosion_ExplodeKillSpr(k, i);
  }
}

void BobOmbExplosion_ExplodeKillSpr(uint8 k, uint8 j) {  // 028150
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(j);
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
  if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
    if ((spr_property_bits167a[j] & 2) == 0) {
      spr_current_status[j] = 2;
      spr_yspeed[j] = -64;
      spr_xspeed[j] = 0;
    }
  }
}

void GameMode14_InLevel_02827D() {  // 02827d
  misc_morton_roy_ludwig_background_xoffset = mirror_current_layer1_xpos;
  R5_ = -(int8)mirror_current_layer1_xpos;
  int8 v0 = 0;
  if (mirror_current_layer1_xpos & 0x100)
    v0 = 0x80;
  misc_morton_roy_ludwig_background_xoffset = (misc_morton_roy_ludwig_background_xoffset >> 1) + v0;
  R6_ = -misc_morton_roy_ludwig_background_xoffset;
  int8 v1 = 0;
  if ((mirror_current_layer1_xpos & 0x200) != 0)
    v1 = 0x80;
  misc_morton_roy_ludwig_background_xoffset = -(int8)((misc_morton_roy_ludwig_background_xoffset >> 1) + v1);
  uint16 v2 = 356;
  *(uint16 *)&R3_ = 356;
  do {
    get_OamEnt(oam_buf, v2)[3].ypos = -16;
    v2 += 4;
  } while (v2 < 0x18C);
  R12_W = 0;
  uint16 v3 = 56;
  uint16 v4 = 224;
  if (spr_table187b[9] == 1) {
    R12_W = 57;
    v3 = 29;
    v4 = 252;
  }
  do {
    R0_W = v3;
    R10_W = R12_W + v3;
    uint16 v5 = R12_W + v3;
    uint8 v6 = kGameMode14_InLevel_DATA_028178[v5] + R6_;
    OamEnt *oam = get_OamEnt(oam_buf, v4);
    oam[3].xpos = v6;
    R2_ = v6;
    R7_ = shaking_layer1_disp_y;
    int8 v8 = 0;
    if (__CFSHL__(shaking_layer1_disp_y, 1))
      v8 = 0x80;
    R7_ = (R7_ >> 1) + v8;
    oam[3].ypos = kGameMode14_InLevel_DATA_0281CF[v5] - 1 - R7_;
    if (!flag_update_background_sprites_in_koopa_kid_rooms) {
      oam[3].charnum = kGameMode14_InLevel_DATA_028226[R10_W];
      oam[3].flags = 13;
    }
    sprites_oamtile_size_buffer[(v4 >> 2) + 3] = 2;
    if (R2_ >= 0xF0 && spr_table187b[9] != 1) {
      uint16 v9 = *(uint16 *)&R3_;
      OamEnt *v10 = get_OamEnt(oam_buf, v4);
      get_OamEnt(oam_buf, *(uint16 *)&R3_)[3] = v10[3];
      sprites_oamtile_size_buffer[(v9 >> 2) + 3] = 3;
      R3_W += 4;
    }
    v4 -= 4;
    v3 = R0_W - 1;
  } while ((int16)(R0_W - 1) >= 0);
  flag_update_background_sprites_in_koopa_kid_rooms = 1;
  if (spr_table187b[9] == 1) {
    OamEnt *v12 = get_OamEnt(oam_buf, 0);
    v12[47].flags = -51;
    v12[48].flags = -51;
    v12[49].flags = -51;
    v12[50].flags = -51;
    v12[51].flags = -51;
    v12[52].flags = -51;
  } else if ((counter_local_frames & 3) == 0) {
    R0_ = 0;
    do {
      uint8 v13 = kGameMode14_InLevel_DATA_0283C8[R0_];
      if ((GetRand() & 1) == 0) {
        OamEnt *v14 = get_OamEnt(oam_buf, v13);
        v14[3].charnum ^= 2;
      }
      get_OamEnt(oam_buf, v13)[3].flags = 9;
      ++R0_;
    } while (R0_ != 4);
  }
  GameMode14_InLevel_0283CE();
}

void GameMode14_InLevel_0283CE() {  // 0283ce
  R12_ = spr_table1534[9] - 30;
  R13_ = spr_table160e[9] + 16;
  for (uint8 i = 1; (i & 0x80) == 0; --i) {
    R15_ = i;
    int8 v1 = *(&sprites_morton_and_roy_left_pillar_status + i);
    if (v1) {
      if (v1 >= 0) {
        player_freeze_player_flag = *(&sprites_morton_and_roy_left_pillar_status + i);
        flag_sprites_locked = v1;
        GameMode14_InLevel_0283F8(i);
      }
      GameMode14_InLevel_028439(i);
    }
  }
}

void GameMode14_InLevel_0283F8(uint8 k) {  // 0283f8
  uint8 v1 = *(&sprites_morton_and_roy_left_pillar_yposition + k) + (*(&sprites_morton_and_roy_left_pillar_yposition + k) >> 5) + 1;
  if (v1 >= 0xB0) {
    *(&sprites_morton_and_roy_left_pillar_status + k) *= 2;
    *(&sprites_morton_and_roy_left_pillar_status + k) = (*(&sprites_morton_and_roy_left_pillar_status + k) >> 1) + 0x80;
    timer_shake_layer1 = 48;
    io_sound_ch3 = 9;
    if (k || sprites_morton_and_roy_right_pillar_status) {
      if (k == 1) {
        flag_sprites_locked = 0;
        player_freeze_player_flag = 0;
      }
    } else {
      ++sprites_morton_and_roy_right_pillar_status;
      sprites_morton_and_roy_right_pillar_yposition = 0;
    }
    v1 = -80;
  }
  *(&sprites_morton_and_roy_left_pillar_yposition + k) = v1;
}

void GameMode14_InLevel_028439(uint8 k) {  // 028439
  uint8 v1 = kGameMode14_InLevel_DATA_0283CC[k];
  R0_ = 0;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam->ypos = -16;
    int8 v3 = *(&sprites_morton_and_roy_left_pillar_yposition + k) - mirror_current_layer1_ypos - shaking_layer1_disp_y - R0_;
    if ((uint8)v3 < 0x20)
      break;
    if ((uint8)v3 < 0xA4)
      oam->ypos = v3;
    oam->xpos = *(&R12_ + k);
    int8 v4 = -26;
    if (R0_)
      v4 = 8;
    oam->charnum = v4;
    oam->flags = 13;
    sprites_oamtile_size_buffer[v1 >> 2] = 2;
    k = R15_;
    v1 += 4;
    R0_ += 16;
  } while (R0_ < 0x90);
}

void sub_284A6(uint8 k, uint8 a) {  // 0284a6
  R3_ = a;
  R1_ = 2;
  do {
    SpawnWaterSplash_0284D8(k);
    R2_ += R3_;
  } while ((--R1_ & 0x80) == 0);
}

void SpawnWaterSplash_VerticalCheepCheepEntry(uint8 k) {  // 0284bc
  SpawnWaterSplash_0284C2(k, 0x12);
}

void SpawnWaterSplash(uint8 k) {  // 0284c0
  SpawnWaterSplash_0284C2(k, 0);
}

void SpawnWaterSplash_0284C2(uint8 k, uint8 a) {  // 0284c2
  R0_ = a;
  R2_ = 0;
  if (spr_spriteid[k] == 65 || spr_spriteid[k] == 66) {
    if ((spr_yspeed[k] & 0x80) != 0)
      sub_284A6(k, 0xA);
  } else {
    SpawnWaterSplash_0284D8(k);
  }
}

void SpawnWaterSplash_0284D8(uint8 k) {  // 0284d8
  if (!CheckIfNormalSpriteOffScreen(k)) {
    uint8 j = 11;
    while (mextspr_spriteid[j]) {
      if ((--j & 0x80) != 0)
        return;
    }
    mextspr_ypos_lo[j] = (spr_ypos_lo[k] & 0xF0) + 3;
    SetHiLo(&mextspr_xpos_hi[j], &mextspr_xpos_lo[j], GetSprXPos(k) + R2_);
    mextspr_spriteid[j] = 7;
    mextspr_timer[j] = R0_;
  }
}

void SpawnLavaSplash(uint8 k) {  // 028528
  CheckIfNormalSpriteOffScreen(k);
  if (!spr_yoffscreen_flag[k]) {
    R0_ = 4;
    uint8 j = 7;
    do {
      while (ext_spr_spriteid[j]) {
        if ((--j & 0x80) != 0)
          return;
      }
      ext_spr_spriteid[j] = 7;
      SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], GetSprYPos(k));
      SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], GetSprXPos(k) + 4);
      ext_spr_xspeed[j] = kSpawnLavaSplash_InitialXSpeed[GetRand() & 7];
      ext_spr_yspeed[j] = kSpawnLavaSplash_InitialYSpeed[misc_random_byte2 & 7];
      ext_spr_decrementing_table176f[j] = kSpawnLavaSplash_InitialAnimationFrameCounter[GetRand() & 7];
      --R0_;
    } while ((R0_ & 0x80) == 0);
  }
}

void SpawnSparkles_PlayerEntry() {  // 02858f
  int8 v0 = 31;
  uint8 v1 = 0;
  if (!player_current_power_up) {
    v0 = 15;
    v1 = 16;
  }
  R1_ = v1;
  GetRand();
  R0_ = player_ypos + R1_ + (misc_random_byte1 & v0);
  R2_ = player_xpos + (misc_random_byte2 & 0xF) - 2;
  SpawnSparkles();
}

void SpawnSparkles() {  // 0285ba
  uint8 v0 = 11;
  while (mextspr_spriteid[v0]) {
    if ((--v0 & 0x80) != 0)
      return;
  }
  mextspr_spriteid[v0] = 5;
  mextspr_yspeed[v0] = 0;
  mextspr_ypos_lo[v0] = R0_;
  mextspr_xpos_lo[v0] = R2_;
  mextspr_timer[v0] = 23;
}

void Spr033_Podoboo_SpawnPodobooFire(uint8 k) {  // 0285df
  if (!CheckIfNormalSpriteOffScreen(k)) {
    uint8 j = 11;
    while (mextspr_spriteid[j]) {
      if ((--j & 0x80) != 0)
        return;
    }
    GetRand();
    mextspr_spriteid[j] = 4;
    mextspr_yspeed[j] = 0;
    SetHiLo(&mextspr_xpos_hi[j], &mextspr_xpos_lo[j], GetSprXPos(k) + (uint8)((misc_random_byte1 & 0xF) - 3));
    SetHiLo(&mextspr_ypos_hi[j], &mextspr_ypos_lo[j], GetSprYPos(k) + (uint8)((misc_random_byte2 & 7) + 7));
    mextspr_timer[j] = 23;
  }
}

uint8 GrabThrowBlockBlock() {  // 02862f
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) != 0)
    return j;
  spr_current_status[j] = 11;
  SetSprYPos(j, player_ypos);
  spr_xpos_lo[j] = player_xpos;
  spr_xpos_hi[j] = *((uint8 *)&player_xpos + j + 1); // wtf?
  spr_spriteid[j] = 83;
  InitializeNormalSpriteRAMTables(j);
  spr_decrementing_table1540[j] = -1;
  timer_display_player_pick_up_pose = 8;
  player_carrying_something_flag2 = 8;
  return 0;
}

void SpawnBrickPieces(uint8 a) {  // 028663
  R0_ = a;
  uint8 v1 = 3;
  uint8 j = 11;
LABEL_2:
  if (!mextspr_spriteid[j])
    goto LABEL_7;
  do {
    if ((--j & 0x80) == 0)
      goto LABEL_2;
    if ((--mextspr_slot_to_overwrite_when_slots_full & 0x80) != 0)
      mextspr_slot_to_overwrite_when_slots_full = 11;
    j = mextspr_slot_to_overwrite_when_slots_full;
LABEL_7:
    io_sound_ch3 = 7;
    mextspr_spriteid[j] = 1;
    SetHiLo(&mextspr_xpos_hi[j], &mextspr_xpos_lo[j], blocks_xpos + kSpawnBrickPieces_xlo[v1]);
    SetHiLo(&mextspr_ypos_hi[j], &mextspr_ypos_lo[j], blocks_ypos + kSpawnBrickPieces_ylo[v1]);
    mextspr_yspeed[j] = kSpawnBrickPieces_InitialYSpeed[v1];
    mextspr_xspeed[j] = kSpawnBrickPieces_InitialXSpeed[v1];
    mextspr_timer[j] = R0_;
    --v1;
  } while ((v1 & 0x80) == 0);
}

void YoshiStompRoutine() {  // 0286bf
  if (!counter_consecutive_enemies_stomped) {
    uint8 j = InitializeBlockPunchAttack();
    bounce_spr_type[j] = 2;
    SetHiLo(&bounce_spr_hitbox_y_hi[j], &bounce_spr_hitbox_x_lo[j], player_xpos);  // snes bug
    SetHiLo(&bounce_spr_hitbox_y_hi[j], &bounce_spr_hitbox_y_lo[j], player_ypos + 32);
    SpawnYoshiStompSmoke();
  }
}

uint8 InitializeBlockPunchAttack() {  // 0286ed
  uint8 j = 3;
  while (bounce_spr_type[j]) {
    if ((--j & 0x80) != 0) {
      ++j;
      break;
    }
  }
  SetHiLo(&bounce_spr_hitbox_x_hi[j], &bounce_spr_hitbox_x_lo[j], blocks_xpos);
  SetHiLo(&bounce_spr_hitbox_y_hi[j], &bounce_spr_hitbox_y_lo[j], blocks_ypos);
  if ((uint8)misc_current_layer_being_processed) {
    SetHiLo(&bounce_spr_hitbox_x_hi[j], &bounce_spr_hitbox_x_lo[j], blocks_xpos - misc_second_level_layer_xpos);
    SetHiLo(&bounce_spr_hitbox_y_hi[j], &bounce_spr_hitbox_y_lo[j], blocks_ypos - misc_second_level_layer_ypos);
  }
  bounce_spr_type[j] = 1;
  bounce_spr_interact_timer[j] = 6;
  return j;
}

void SpawnBounceSprite() {  // 028752
  if (R4_ == 7) {
    uint8 v0 = player_current_character + __CFSHL__(player_current_character, 1) + 2 * player_current_character;
    uint8 v1 = *(&player_mario_score_lo + v0);
    *(&player_mario_score_lo + v0) = v1 + 5;
    if (v1 >= 0xFB && (*(&player_mario_score_mid + v0))++ == 0xFF)
      ++*(&player_mario_score_hi + v0);
    player_yspeed = -48;
    SpawnBrickPieces(0);
    InitializeBlockPunchAttack();
    blocks_map16_to_generate = 2;
    GenerateTile();
  } else {
    uint8 v3 = 3;
    while (bounce_spr_spriteid[v3]) {
      if ((--v3 & 0x80) != 0) {
        if ((--bounce_spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
          bounce_spr_slot_to_overwrite_when_slots_full = 3;
        uint8 j = bounce_spr_slot_to_overwrite_when_slots_full;
        if (bounce_spr_spriteid[j] == 7) {
          uint16 v4 = blocks_xpos;
          uint16 v5 = blocks_ypos;
          blocks_xpos = PAIR16(bounce_spr_xpos_hi[j], bounce_spr_xpos_lo[j]);
          uint16 t = PAIR16(bounce_spr_ypos_hi[j], bounce_spr_ypos_lo[j]) + 12;
          blocks_ypos = t & ~0xF;
          blocks_map16_to_generate = bounce_spr_map16_tile_to_spawn[j];
          uint8 v12 = R4_;
          uint8 v11 = R5_;
          uint8 v10 = R6_;
          uint8 v9 = R7_;
          GenerateTile();
          R7_ = v9;
          R6_ = v10;
          R5_ = v11;
          R4_ = v12;
          blocks_ypos = v5;
          blocks_xpos = v4;
        }
        v3 = bounce_spr_slot_to_overwrite_when_slots_full;
        break;
      }
    }
    uint8 v6 = R4_;
    if (R4_ < 0x10) {
      if (R4_ == 5)
        io_sound_ch1 = 11;
      bounce_spr_yxppccct[v3] = kSpawnBounceSprite_BlockBounce[R4_];
    } else {
      R4_ = 0;
      bounce_spr_yxppccct[v3] = kSpawnBounceSprite_BlockBounce[v6 - 9];
    }
    bounce_spr_spriteid[v3] = R4_ + 1;
    bounce_spr_current_status[v3] = 0;
    bounce_spr_xpos_lo[v3] = blocks_xpos;
    bounce_spr_xpos_hi[v3] = HIBYTE(blocks_xpos);
    bounce_spr_ypos_lo[v3] = blocks_ypos;
    bounce_spr_ypos_hi[v3] = HIBYTE(blocks_ypos);
    int8 v7 = 0;
    if (misc_current_layer_being_processed & 1)
      v7 = 0x80;
    R8_ = ((uint8)misc_current_layer_being_processed >> 2) + v7;
    uint8 v8 = R6_;
    bounce_spr_yspeed[v3] = kSpawnBounceSprite_BlockBounceYSpeed[R6_];
    bounce_spr_xspeed[v3] = kSpawnBounceSprite_BlockBounceXSpeed[v8];
    bounce_spr_properties[v3] = R8_ | v8;
    bounce_spr_map16_tile_to_spawn[v3] = R7_;
    bounce_spr_timer[v3] = 8;
    if (bounce_spr_spriteid[v3] == 7)
      bounce_spr07_spinning_turn_block_despawn_timer[v3] = -1;
    InitializeBlockPunchAttack();
    SpawnBounceSprite_02887D();
  }
}

void SpawnBounceSprite_02887D() {  // 02887d
  uint8 j;

  if (!R5_)
    return;
  if (R5_ < 8 && R5_ >= 6) {
    if (R5_ == 7 && !blocks_multi_coin_block_timer)
      blocks_multi_coin_block_timer = -1;
    goto LABEL_7;
  }
  if (R5_ != 11 || (blocks_xpos & 0x30) != 32) {
    switch (R5_) {
    case 0x10: goto LABEL_16;
    case 8:
      if (sprites_sprite_memory_setting) {
LABEL_16:
        j = FindFreeNormalSpriteSlot_HighPriority();
        if ((j & 0x80) != 0)
          return;
        goto LABEL_24;
      }
      break;
    case 0xC: goto LABEL_16;
    }
  }
  j = 11;
  while (spr_current_status[j]) {
    if (--j == 0xFF) {
      if ((--spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
        spr_slot_to_overwrite_when_slots_full = 1;
      j = spr_slot_to_overwrite_when_slots_full + 10;
      break;
    }
  }
LABEL_24:
  misc_scratch7e185e = j;
  uint8 v1 = R5_;
  spr_current_status[j] = kSpawnBounceSprite_StatusOfSprInBlk[R5_];
  if (yoshi_stray_yoshi_flag)
    v1 += 17;
  sprites_second_tracked_sprite_index = v1;
  uint8 v2 = kSpawnBounceSprite_SpriteInBlock[v1];
  spr_spriteid[j] = v2;
  R14_ = v2;
  uint8 v3 = 2;
  if (v2 < 0x81 && v2 >= 0x79)
    v3 = 3;
  io_sound_ch3 = v3;
  InitializeNormalSpriteRAMTables(j);
  ++spr_xoffscreen_flag[j];
  if (spr_spriteid[j] == 69) {
    if (spr45_directional_coins_no_respawn_flag) {
      spr_current_status[j] = 0;
LABEL_7:
      SpawnBounceSprite_SpawnSpinningCoins();
      return;
    }
    io_music_ch1 = 14;
    ++spr45_directional_coins_no_respawn_flag;
    spr45_directional_coins_despawn_timer = 0;
  }
  SetSprXYPos(j, blocks_xpos, blocks_ypos);
  if ((uint8)misc_current_layer_being_processed) {
    SetSprXYPos(j, blocks_xpos - misc_second_level_layer_xpos, blocks_ypos - misc_second_level_layer_ypos);
  }
  uint8 v5 = spr_spriteid[j];
  switch (v5) {
  case 0x7D:;
    uint8 v6 = (uint8)(spr_xpos_lo[j] & 0x30) >> 4;
    spr_current_status[j] = kSpawnBounceSprite_DATA_0288D9[v6];
    uint8 v7 = kSpawnBounceSprite_DATA_0288D6[v6];
    spr_spriteid[j] = v7;
    uint8 v11 = v7;
    InitializeNormalSpriteRAMTables(j);
    if (v11 == 125) {
      ++spr_table157c[j];
      return;
    }
    if (v11 == 126) {
      spr_table00c2[j] += 2;
      return;
    }
    break;
  case 4: spr_decrementing_table1540[j] = -1; break;
  case 0x3E: {
    bool v10 = (spr_xpos_lo[j] & 0x10) != 0;
    spr_table151c[j] = v10;
    spr_table15f6[j] = kSpawnBounceSprite_DATA_028A42[v10];
    SpawnSmokePuff();
    break;
  }
  case 0x2C: {
    for (uint8 i = 11; (i & 0x80) == 0; --i) {
      if (spr_current_status[i] >= 8 && spr_spriteid[i] == 45)
        goto LABEL_46;
    }
    uint8 v9 = yoshi_stray_yoshi_flag;
    if (yoshi_stray_yoshi_flag)
LABEL_46:
      v9 = 1;
    spr_table151c[j] = kSpawnBounceSprite_DATA_0288A1[v9];
    break;
  }
  default: spr_decrementing_table1540[j] = 62; break;
  }
  spr_yspeed[j] = -48;
  spr_decrementing_table154c[j] = 44;
  if ((spr_property_bits190f[j] & 0x80) != 0)
    spr_decrementing_table15ac[j] = 16;
}

void SpawnSmokePuff() {  // 028a44
  uint8 v0 = 3;
  while (smoke_spr_spriteid[v0]) {
    if ((--v0 & 0x80) != 0) {
      ++v0;
      break;
    }
  }
  smoke_spr_spriteid[v0] = 1;
  smoke_spr_ypos_lo[v0] = blocks_ypos;
  smoke_spr_xpos_lo[v0] = blocks_xpos;
  smoke_spr_timer[v0] = 27;
}

void SpawnBounceSprite_SpawnSpinningCoins() {  // 028a66
  uint8 v0 = 3;
  while (block_coin_spr_slotid[v0]) {
    if ((--v0 & 0x80) != 0) {
      if ((--block_coin_spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
        block_coin_spr_slot_to_overwrite_when_slots_full = 3;
      v0 = block_coin_spr_slot_to_overwrite_when_slots_full;
      break;
    }
  }
  GiveCoins_OneCoin();
  ++block_coin_spr_slotid[v0];
  SetHiLo(&block_coin_spr_xpos_hi[v0], &block_coin_spr_xpos_lo[v0], blocks_xpos);
  SetHiLo(&block_coin_spr_ypos_hi[v0], &block_coin_spr_ypos_lo[v0], blocks_ypos - 16);
  block_coin_spr_layer_index[v0] = misc_current_layer_being_processed;
  block_coin_spr_yspeed[v0] = -48;
}

void GameMode14_InLevel_Bank02() {  // 028ab1
  int8 v0;

  if (misc_1up_handler) {
    if (timer_give1up) {
      --timer_give1up;
    } else {
      if (--misc_1up_handler)
        timer_give1up = 35;
      io_sound_ch3 = 5;
      ++player_current_life_count;
    }
  }
  if (timer_star_power < 8) {
    uint8 v1 = timer_unused_player_sparkle;
    if (!timer_unused_player_sparkle)
      goto LABEL_14;
    --timer_unused_player_sparkle;
    v0 = v1 & 1;
  } else {
    v0 = kGameMode14_InLevel_DATA_028AA9[timer_star_power >> 5] & counter_global_frames;
  }
  if (!(HIBYTE(player_on_screen_pos_y) | (uint8)(HIBYTE(player_on_screen_pos_x) | v0)) && (uint8)player_on_screen_pos_y < 0xD0) {
    SpawnSparkles_PlayerEntry();
  }
LABEL_14:
  ProcessMinorExtendedSprites();
  ProcessBounceAndSmokeSprites();
  ProcessScoreSprites();
  ProcessExtendedSprites();
  ProcessSpinningCoinSprites();
  ProcessShooterSprites();
  ProcessGeneratorSprite();
  HandleCapeInteraction();
  ParseLevelSpriteList();
  if (timer_respawn_sprite) {
    if (!(timer_disappearing_sprite | flag_sprites_locked | counter_global_frames & 1) && !--timer_respawn_sprite) {
      uint8 j = FindFreeNormalSpriteSlot_HighPriority();
      if ((j & 0x80) == 0) {
        spr_current_status[j] = 1;
        spr_spriteid[j] = sprites_sprite_to_respawn;
        SetSprXYPos(j, (mirror_current_layer1_xpos - 32) & ~0x10, sprites_ypos_of_respawning_sprite);
        InitializeNormalSpriteRAMTables(j);
      }
    }
  }
}

void ProcessMinorExtendedSprites() {  // 028b67
  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    uint8 v1 = mextspr_spriteid[i];
    if (v1) {
      sprites_currently_processed_misc_sprite = i;
      ProcessMinorExtendedSprites_028B94(i, v1);
    }
  }
}

void ProcessMinorExtendedSprites_Return(uint8 k) {  // 028b77
  ;
}

void ProcessMinorExtendedSprites_028B94(uint8 k, uint8 a) {  // 028b94
  kProcessMinorExtendedSprites_MinorExtendedSpritesPtrs[a](k);
}

void Spr035_Yoshi_SpawnUnusedYoshiSmoke(uint8 k) {  // 028bb0
  Spr035_Yoshi_SpawnUnusedYoshiSmoke_Return(k);
}

void Spr035_Yoshi_SpawnUnusedYoshiSmoke_Return(uint8 k) {  // 028bb8
  ;
}

void Spr035_Yoshi_Sub(uint8 k) {  // 028bb9
  R0_ = 0;
  Spr035_Yoshi_028BC0(k);
  ++R0_;
  Spr035_Yoshi_028BC0(k);
}

void Spr035_Yoshi_028BC0(uint8 k) {  // 028bc0
  uint8 j = 11;
  while (mextspr_spriteid[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  mextspr_spriteid[j] = 11;
  mextspr_timer[j] = 0;
  SetHiLo(&mextspr_ypos_hi[j], &mextspr_ypos_lo[j], GetSprYPos(k) + 28);
  mextspr_xspeed[j] = kSpr035_Yoshi_DATA_028C09[R0_];
  SetHiLo(&mextspr_xpos_hi[j], &mextspr_xpos_lo[j], player_xpos + PAIR16(kSpr035_Yoshi_DATA_028C0D[R0_], kSpr035_Yoshi_DATA_028C0B[R0_]));
}

void MExtSpr0B_UnusedYoshiSmoke(uint8 k) {  // 028c0f
  if (mextspr_timer[k]) {
    if (mextspr_timer[k]-- != 1) {
      uint8 v5 = kMinorExtendedSpriteOAMIndexes[k];
      uint8 v6 = mextspr_xpos_lo[k];
      R0_ = v6 - mirror_current_layer1_xpos;
      if (mextspr_xpos_hi[k] == (uint8)((v6 < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos))) {
        uint8 v7 = mextspr_ypos_lo[k];
        R1_ = v7 - mirror_current_layer1_ypos;
        if (mextspr_ypos_hi[k] == (uint8)((v7 < (uint8)mirror_current_layer1_ypos) + HIBYTE(mirror_current_layer1_ypos))) {
          OamEnt *oam = get_OamEnt(oam_buf, v5);
          oam->xpos = R0_;
          oam->ypos = R1_;
          oam->charnum = kMExtSpr0B_UnusedYoshiSmoke_Tiles[mextspr_timer[k] >> 2];
          oam->flags = sprites_tile_priority | 8;
          sprites_oamtile_size_buffer[v5 >> 2] = 0;
          return;
        }
      }
    }
LABEL_14:
    mextspr_spriteid[k] = 0;
    return;
  }
  int8 v1 = mextspr_xspeed[k];
  if (!v1)
    goto LABEL_14;
  uint8 v2;
  if (v1 >= 0)
    v2 = v1 - 8;
  else
    v2 = v1 + 8;
  mextspr_xspeed[k] = v2;
  UpdateMinorExtendedSpritePosition_X(k);
  if (((counter_global_frames ^ k) & 3) == 0) {
    uint8 v3 = 11;
    while (mextspr_spriteid[v3]) {
      if ((--v3 & 0x80) != 0)
        return;
    }
    mextspr_spriteid[v3] = 11;
    mextspr_yspeed[v3] = 11;
    mextspr_xpos_lo[v3] = mextspr_xpos_lo[k];
    mextspr_xpos_hi[v3] = mextspr_xpos_hi[k];
    mextspr_ypos_lo[v3] = mextspr_ypos_lo[k];
    mextspr_ypos_hi[v3] = mextspr_ypos_hi[k];
    mextspr_timer[v3] = 16;
  }
}

void MExtSpr0A_BooStream(uint8 k) {  // 028cc4
  if (!flag_sprites_locked) {
    SetHiLo(&R10_, &R4_, PAIR16(mextspr_xpos_hi[k], mextspr_xpos_lo[k]) + 4);
    SetHiLo(&R11_, &R5_, PAIR16(mextspr_ypos_hi[k], mextspr_ypos_lo[k]) + 4);
    R6_ = 8;
    R7_ = 8;
    StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
    if (StandardSpriteToSpriteCollisionChecks_CheckContact())
      DamagePlayer_Hurt();
    if (mextspr_timer[k]-- == 1)
      goto LABEL_9;
  }
  uint8 v4 = kMinorExtendedSpriteOAMIndexes[k];
  uint8 v5 = mextspr_xpos_lo[k];
  R0_ = v5 - mirror_current_layer1_xpos;
  if (mextspr_xpos_hi[k] != (uint8)((v5 < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)))
    return;
  OamEnt *oam = get_OamEnt(oam_buf, v4);
  oam->xpos = R0_;
  if ((uint8)(mextspr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xF0) {
LABEL_9:
    mextspr_spriteid[k] = 0;
    return;
  }
  oam->ypos = mextspr_ypos_lo[k] - mirror_current_layer1_ypos;
  oam->charnum = kMExtSpr0A_BooStream_Tiles[k];
  oam->flags = sprites_tile_priority | (mextspr_xspeed[k] >> 1) & 0x40 ^ 0x40 | 0xF;
  sprites_oamtile_size_buffer[v4 >> 2] = 2;
}

void MExtSpr07_WaterSplash(uint8 k) {  // 028d4f
  OamEnt *oam;

  if (mextspr_xpos_hi[k] != (uint8)((mextspr_xpos_lo[k] < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)))
    goto LABEL_3;
  uint8 v1 = mextspr_timer[k];
  if (v1 == 32)
    goto LABEL_3;
  R0_ = 0;
  if (v1 >= 0x10) {
    if (!(flag_sprites_locked | v1 & 1))
      ++mextspr_ypos_lo[k];
    R2_ = (uint8)(mextspr_timer[k] - 16) >> 2;
    R0_ = (counter_global_frames & 1) ? -R2_ : R2_;
  }
  uint8 v3 = kMinorExtendedSpriteOAMIndexes[k];
  if ((uint8)(R0_ + mextspr_xpos_lo[k] - mirror_current_layer1_xpos) >= 0xF0 ||
      (oam = get_OamEnt(oam_buf, v3), oam->xpos = R0_ + mextspr_xpos_lo[k] - mirror_current_layer1_xpos,
       (uint8)(mextspr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xE8)) {
LABEL_3:
    mextspr_spriteid[k] = 0;
  } else {
    oam->ypos = mextspr_ypos_lo[k] - mirror_current_layer1_ypos;
    uint8 v5 = mextspr_timer[k] >> 1;
    oam->charnum = kMExtSpr07_WaterSplash_Tiles[(v5 >= 12) ? 12 : v5];
    oam->flags = sprites_tile_priority | 2;
    sprites_oamtile_size_buffer[v3 >> 2] = 2;
    if (!flag_sprites_locked)
      ++mextspr_timer[k];
  }
}

void MExtSpr06_RipVanFishZ(uint8 k) {  // 028ddb
  OamEnt *oam;

  if (!flag_sprites_locked) {
    if (mextspr_timer[k])
      --mextspr_timer[k];
    uint8 v1 = mextspr_timer[k];
    ++mextspr_xspeed[k];
    if ((v1 & 0x10) == 0) {
      --mextspr_xspeed[k];
      --mextspr_xspeed[k];
    }
    uint8 v6 = mextspr_xspeed[k];
    if (mextspr_spriteid[k] == 9)
      mextspr_xspeed[k] = -mextspr_xspeed[k];
    UpdateMinorExtendedSpritePosition_X(k);
    mextspr_xspeed[k] = v6;
    if ((mextspr_timer[k] & 3) == 0)
      --mextspr_ypos_lo[k];
  }
  uint8 v2 = kMinorExtendedSpriteOAMIndexes[k];
  int8 v3 = mextspr_xpos_lo[k] - mirror_current_layer1_xpos;
  if ((uint8)v3 < 8 || (uint8)v3 >= 0xFC ||
      (oam = get_OamEnt(oam_buf, v2), oam->xpos = v3, (uint8)(mextspr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xF0) ||
      (oam->ypos = mextspr_ypos_lo[k] - mirror_current_layer1_ypos, oam->flags = sprites_tile_priority | 3, mextspr_timer[k] == 20)) {
    mextspr_spriteid[k] = 0;
  } else {
    uint8 v5 = 127;
    if (mextspr_spriteid[k] < 8)
      v5 = kMExtSpr06_RipVanFishZ_Tiles[(mextspr_timer[k] >> 5) & 3];
    oam->charnum = v5;
    sprites_oamtile_size_buffer[v2 >> 2] = 0;
  }
}

void MExtSpr03_EggShell(uint8 k) {  // 028e7e
  OamEnt *oam;
  uint8 v1;
  if ((--mextspr_timer[k] & 0x3F) != 0 &&
      (UpdateMinorExtendedSpritePosition_X(k), UpdateMinorExtendedSpritePosition_Y(k), ++mextspr_yspeed[k], ++mextspr_yspeed[k],
       v1 = kMinorExtendedSpriteOAMIndexes[k], (uint8)(mextspr_ypos_lo[k] - mirror_current_layer1_ypos) < 0xF0) &&
      (oam = get_OamEnt(oam_buf, v1), oam->ypos = mextspr_ypos_lo[k] - mirror_current_layer1_ypos,
       (uint8)(mextspr_xpos_lo[k] - mirror_current_layer1_xpos) < 0xF8)) {
    oam->xpos = mextspr_xpos_lo[k] - mirror_current_layer1_xpos;
    oam->charnum = 111;
    oam->flags = sprites_tile_priority | mextspr_timer[k] & 0xC0 | 3;
    sprites_oamtile_size_buffer[v1 >> 2] = 0;
  } else {
    MExtSpr_Delete(k);
  }
}

void MExtSpr02_SmallStar(uint8 k) {  // 028ed2
  OamEnt *oam;

  if (!mextspr_timer[k])
    goto LABEL_2;
  if (!flag_sprites_locked)
    --mextspr_timer[k];
  uint8 v1 = kMinorExtendedSpriteOAMIndexes[k];
  if ((uint8)(mextspr_xpos_lo[k] - mirror_current_layer1_xpos) < 0xF0 &&
      (oam = get_OamEnt(oam_buf, v1), oam->xpos = mextspr_xpos_lo[k] - mirror_current_layer1_xpos,
       (uint8)(mextspr_ypos_lo[k] - mirror_current_layer1_ypos) < 0xF0)) {
    oam->ypos = mextspr_ypos_lo[k] - mirror_current_layer1_ypos;
    uint8 v4 = mextspr_spriteid[k];
    uint8 v3 = mextspr_timer[k] >> 3;
    if (v4 == 5)
      v3 += 3;
    oam->charnum = kMExtSpr02_SmallStar_Tiles[v3];
    oam->flags = sprites_tile_priority | 6;
    sprites_oamtile_size_buffer[v1 >> 2] = 0;
  } else {
LABEL_2:
    MExtSpr_Delete(k);
  }
}

void MExtSpr04_PodobooFire(uint8 k) {  // 028f2f
  if (mextspr_xpos_hi[k] != (uint8)((mextspr_xpos_lo[k] < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)) ||
      !mextspr_timer[k]) {
    goto LABEL_7;
  }
  if (!flag_sprites_locked) {
    --mextspr_timer[k];
    UpdateMinorExtendedSpritePosition_Y(k);
    ++mextspr_yspeed[k];
  }
  uint8 v1 = kMinorExtendedSpriteOAMIndexes[k];
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam->xpos = mextspr_xpos_lo[k] - mirror_current_layer1_xpos;
  if (mextspr_ypos_lo[k] < 0xF0) {
    oam->ypos = mextspr_ypos_lo[k] - mirror_current_layer1_ypos;
    oam->charnum = kMExtSpr04_PodobooFire_Tiles[mextspr_timer[k] >> 3];
    oam->flags = sprites_tile_priority | 5;
    sprites_oamtile_size_buffer[v1 >> 2] = 0;
  } else {
LABEL_7:
    MExtSpr_Delete(k);
  }
}

void MExtSpr_Delete(uint8 k) {  // 028f87
  mextspr_spriteid[k] = 0;
}

void MExtSpr01_BrickPiece(uint8 k) {  // 028f8b
  OamEnt *oam;

  if (!flag_sprites_locked) {
    if ((counter_global_frames & 3) != 0)
      AddHiLo(&mextspr_xpos_hi[k], &mextspr_xpos_lo[k], (int8)mextspr_xspeed[k]);
    AddHiLo(&mextspr_ypos_hi[k], &mextspr_ypos_lo[k], (int8)mextspr_yspeed[k]);
    if ((counter_global_frames & 3) == 0)
      ++mextspr_yspeed[k];
  }
  uint16 t = PAIR16(mextspr_ypos_hi[k], mextspr_ypos_lo[k]) - mirror_current_layer1_ypos;
  R0_ = t;
  if ((t >> 8)) {
    if ((int8)(t >> 8) < 0)
      return;
    goto LABEL_15;
  }
  uint8 v8 = kMinorExtendedSpriteOAMIndexes[k];

  uint16 tx = PAIR16(mextspr_xpos_hi[k], mextspr_xpos_lo[k]) - mirror_current_layer1_xpos;
  R1_ = tx;
  if ((tx >> 8) || (oam = get_OamEnt(oam_buf, v8), oam->xpos = tx, R0_ >= 0xF0)) {
LABEL_15:
    MExtSpr_Delete(k);
    return;
  }
  oam->ypos = R0_;
  uint8 v13 = mextspr_timer[k];
  uint8 v11 = (sprites_currently_processed_misc_sprite + (counter_local_frames >> 1)) & 7;
  oam->charnum = kMExtSpr01_BrickPiece_Tiles[v11];
  uint8 v12 = v13;
  if (v13)
    v12 = counter_global_frames & 0xE;
  oam->flags = sprites_tile_priority | kMExtSpr01_BrickPiece_Flip[v11] ^ v12;
  sprites_oamtile_size_buffer[v8 >> 2] = 0;
}

void ProcessBounceAndSmokeSprites() {  // 02902d
  if (blocks_multi_coin_block_timer >= 2 && !flag_sprites_locked)
    --blocks_multi_coin_block_timer;
  for (int8 i = 3; i >= 0; --i) {
    sprites_currently_processed_misc_sprite = i;
    ProcessBounceAndSmokeSprites_BounceSprites(i);
    CheckPlayerAttackToNormalSpriteCollision(i);
    ProcessBounceAndSmokeSprites_SmokeSprites(i);
  }
}

void ProcessBounceAndSmokeSprites_Return02904C(uint8 k) {  // 02904c
  ;
}

void ProcessBounceAndSmokeSprites_BounceSprites(uint8 k) {  // 02904d
  uint8 v1 = bounce_spr_spriteid[k];
  if (v1) {
    if (!flag_sprites_locked) {
      if (bounce_spr_timer[k])
        --bounce_spr_timer[k];
    }
    kProcessBounceAndSmokeSprites_BounceSpritePtrs[v1](k);
  }
}

void BounceSpr07_SpinningTurnBlock(uint8 k) {  // 029076
  if (!flag_sprites_locked) {
    if (!bounce_spr_current_status[k]) {
      ++bounce_spr_current_status[k];
      SpawnMap16TileFromBounceSprite_InvisibleSolidBlock(k);
    }
    uint8 v1 = bounce_spr_timer[k];
    if (v1) {
      if (v1 == 1) {
        uint16 t = (PAIR16(bounce_spr_ypos_hi[k], bounce_spr_ypos_lo[k]) + 8) & ~0xf;
        bounce_spr_ypos_lo[k] = t;
        bounce_spr_ypos_hi[k] = t >> 8;
        SpawnMap16TileFromBounceSprite(k, 5);
      } else {
        UpdateBounceSpritePosition_Y(k);
        bounce_spr_yspeed[k] += kBounceSpr07_SpinningTurnBlock_YAcceleration[bounce_spr_properties[k]];
        BounceSpriteDraw(k);
      }
    }
    if (bounce_spr07_spinning_turn_block_despawn_timer[k]) {
      --bounce_spr07_spinning_turn_block_despawn_timer[k];
    } else {
      SpawnMap16TileFromBounceSprite(k, bounce_spr_map16_tile_to_spawn[k]);
      bounce_spr_spriteid[k] = 0;
    }
  }
}

void BounceSpr01_TurnBlock(uint8 k) {  // 0290de
  BounceSpriteDraw(k);
  if (!flag_sprites_locked) {
    if (!bounce_spr_current_status[k]) {
      ++bounce_spr_current_status[k];
      GetBounceSpriteLevelCollisionMap16ID(k);
      SpawnMap16TileFromBounceSprite_InvisibleSolidBlock(k);
      uint8 v1 = bounce_spr_properties[k] & 3;
      if (kBounceSpr01_TurnBlock_DATA_0290D6[v1] != 0x80)
        player_yspeed = kBounceSpr01_TurnBlock_DATA_0290D6[v1];
      if (kBounceSpr01_TurnBlock_DATA_0290DA[v1] != 0x80)
        player_xspeed = kBounceSpr01_TurnBlock_DATA_0290DA[v1];
    }
    UpdateBounceSpritePosition_Y(k);
    UpdateBounceSpritePosition_X(k);
    uint8 v2 = bounce_spr_properties[k] & 3;
    bounce_spr_yspeed[k] += kBounceSpr01_TurnBlock_YAcceleration[v2];
    bounce_spr_xspeed[k] += kBounceSpr01_TurnBlock_XAcceleration[v2];
    if ((bounce_spr_properties[k] & 3) == 3 && !player_current_state) {
      uint8 v3 = 32;
      if (player_riding_yoshi_flag)
        v3 = 48;
      R0_ = v3;
      uint8 v4 = bounce_spr_ypos_lo[k];
      LOBYTE(player_ypos) = v4 - R0_;
      HIBYTE(player_ypos) = bounce_spr_ypos_hi[k] - (v4 < R0_);
      misc_player_on_solid_sprite = 1;
      blocks_note_block_bounce_flag = 1;
      player_yspeed = 0;
    }
    if (!bounce_spr_timer[k]) {
      if ((bounce_spr_properties[k] & 3) == 3) {
        player_yspeed = -96;
        bool v5 = (uint8)player_ypos >= 2;
        LOBYTE(player_ypos) = player_ypos - 2;
        HIBYTE(player_ypos) -= !v5;
        io_sound_ch3 = 8;
      }
      SpawnMap16TileFromBounceSprite_MultiCoinBlock(k);
      if (bounce_spr_spriteid[k] >= 6) {
        io_sound_ch1 = 11;
        flag_on_off_switch ^= 1;
      }
      bounce_spr_spriteid[k] = 0;
    }
  }
}

void SpawnMap16TileFromBounceSprite_MultiCoinBlock(uint8 k) {  // 02919f
  uint8 v1 = bounce_spr_map16_tile_to_spawn[k];
  if ((v1 == 10 || v1 == 11) && blocks_multi_coin_block_timer == 1) {
    blocks_multi_coin_block_timer = 0;
    v1 = 13;
  }
  SpawnMap16TileFromBounceSprite(k, v1);
}

void SpawnMap16TileFromBounceSprite_InvisibleSolidBlock(uint8 k) {  // 0291b8
  SpawnMap16TileFromBounceSprite(k, 9);
}

void SpawnMap16TileFromBounceSprite(uint8 k, uint8 a) {  // 0291ba
  blocks_map16_to_generate = a;
  blocks_xpos = (PAIR16(bounce_spr_xpos_hi[k], bounce_spr_xpos_lo[k]) + 8) & ~0xf;
  blocks_ypos = (PAIR16(bounce_spr_ypos_hi[k], bounce_spr_ypos_lo[k]) + 8) & ~0xf;
  LOBYTE(misc_current_layer_being_processed) = (bounce_spr_properties[k] & 0x80) != 0;
  GenerateTile();
}

void BounceSpriteDraw(uint8 k) {  // 0291f8
  uint8 v1 = 0;
  if ((bounce_spr_properties[k] & 0x80) != 0)
    v1 = 4;
  R2_ = *((uint8 *)&mirror_current_layer1_ypos + v1);
  R3_ = *((uint8 *)&mirror_current_layer1_xpos + v1);
  R4_ = *((uint8 *)&mirror_current_layer1_ypos + v1 + 1);
  R5_ = *((uint8 *)&mirror_current_layer1_xpos + v1 + 1);
  if (bounce_spr_ypos_hi[k] == (uint8)((bounce_spr_ypos_lo[k] < R2_) + R4_) &&
      bounce_spr_xpos_hi[k] == (uint8)((bounce_spr_xpos_lo[k] < R3_) + R5_)) {
    uint8 v2 = kBounceSpriteGFXRt_OAMIndex[k];
    R1_ = bounce_spr_ypos_lo[k] - R2_;
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam->ypos = R1_;
    R0_ = bounce_spr_xpos_lo[k] - R3_;
    oam->xpos = R0_;
    oam->flags = sprites_tile_priority | bounce_spr_yxppccct[k];
    oam->charnum = kBounceSpriteGFXRt_Tiles[bounce_spr_spriteid[k] - 1];
    sprites_oamtile_size_buffer[v2 >> 2] = 2;
  }
}

void GetBounceSpriteLevelCollisionMap16ID(uint8 k) {  // 029265
  int8 v1 = 1;
  R15_ = bounce_spr_properties[k];
  if ((R15_ & 0x80) != 0)
    v1 = 2;
  if ((misc_level_layout_flags & (uint8)v1) != 0) {
    uint16 t = PAIR16(bounce_spr_ypos_hi[k], bounce_spr_ypos_lo[k]) - 3;
    R0_ = t & ~0xf;
    uint8 v2 = (t >> 8);
    if (v2 >= misc_screens_in_lvl)
      return;
    R3_ = v2;
    R8_ = v2 & 0x10;
    R1_ = bounce_spr_xpos_lo[k];
    if (bounce_spr_xpos_hi[k] >= 2)
      return;
    R2_ = bounce_spr_xpos_hi[k];
    R0_ |= R1_ >> 4;
    uint8 v3 = kLevelDataLayoutTables_EightBitLo_Vertical[R3_];
    uint8 v4 = kLevelDataLayoutTables_EightBitHi_Vertical[R3_];
    if (R15_) {
      v3 = kLevelDataLayoutTables_EightBitLo_Vertical_L2[R3_];
      v4 = kLevelDataLayoutTables_EightBitHi_Vertical_L2[R3_];
    }
    *(uint16 *)&R5_ = PAIR16(R2_, R0_) + PAIR16(v4, v3);
  } else {
    uint16 t = PAIR16(bounce_spr_ypos_hi[k], bounce_spr_ypos_lo[k]) - 3;
    R0_ = t & ~0xf;
    uint8 t2 = t >> 8;
    if (t2 >= 2)
      return;
    R2_ = t2;
    R1_ = bounce_spr_xpos_lo[k];
    uint8 v5 = bounce_spr_xpos_hi[k];
    if (v5 >= misc_screens_in_lvl)
      return;
    R3_ = bounce_spr_xpos_hi[k];
    R0_ |= R1_ >> 4;
    uint8 v6 = v5;
    uint8 v7 = kLevelDataLayoutTables_EightBitLo[v5];
    uint8 v8 = kLevelDataLayoutTables_EightBitHi[v6];
    if (R15_) {
      v7 = kLevelDataLayoutTables_EightBitLo_Horizontal_L2[v6];
      v8 = kLevelDataLayoutTables_EightBitHi_Horizontal_L2[v6];
    }
    *(uint16 *)&R5_ = PAIR16(R2_, R0_) + PAIR16(v8, v7);
  }
  R7_ = 126;
  uint8 v9 = sprites_currently_processed_misc_sprite;
  blocks_currently_processed_map16_tile_lo = *IndirPtr(&R5_, 0);
  ++R7_;
  if (!*IndirPtr(&R5_, 0) && blocks_currently_processed_map16_tile_lo == 43) {
    uint8 v11 = bounce_spr_ypos_lo[v9];
    bounce_spr_ypos_lo[v9] = (v11 - ((blocks_currently_processed_map16_tile_lo < 0x2B) + 3)) & 0xF0;
    uint8 v10 = bounce_spr_ypos_hi[v9];
    bounce_spr_ypos_hi[v9] = v10 - 1;
    SpawnMap16TileFromBounceSprite_InvisibleSolidBlock(v9);
    GetBounceSpriteLevelCollisionMap16ID_029356(v9);
    bounce_spr_ypos_hi[v9] = v10;
    bounce_spr_ypos_lo[v9] = v11;
  }
}

void GetBounceSpriteLevelCollisionMap16ID_029356(uint8 k) {  // 029356
  uint8 v1 = 3;
  while (block_coin_spr_slotid[v1]) {
    if ((--v1 & 0x80) != 0) {
      ++v1;
      break;
    }
  }
  block_coin_spr_slotid[v1] = 1;
  GiveCoins_OneCoin();
  block_coin_spr_xpos_lo[v1] = bounce_spr_xpos_lo[k];
  block_coin_spr_xpos_hi[v1] = bounce_spr_xpos_hi[k];
  block_coin_spr_ypos_lo[v1] = bounce_spr_ypos_lo[k];
  block_coin_spr_ypos_hi[v1] = bounce_spr_ypos_hi[k];
  block_coin_spr_layer_index[v1] = (4 * bounce_spr_properties[k] + __CFSHL__(bounce_spr_properties[k], 1)) & 1;
  block_coin_spr_yspeed[v1] = -48;
}

void CheckPlayerAttackToNormalSpriteCollision(uint8 k) {  // 029398
  if (bounce_spr_type[k]) {
    if (bounce_spr_interact_timer[k]-- == 1) {
      bounce_spr_type[k] = 0;
    } else if (bounce_spr_interact_timer[k] < 3) {
      R14_ = 0;
      CheckPlayerAttackToNormalSpriteColl_CapeSwingEntry();
    }
  }
}

void CheckPlayerAttackToNormalSpriteColl_CapeSwingEntry() {  // 0293ae
  uint8 j = sprites_currently_processed_misc_sprite;

  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    spr_current_slotid = i;
    if (spr_current_status[i] != 11 && spr_current_status[i] >= 8 &&
        !(spr_decrementing_table1fe2[i] | spr_decrementing_table154c[i] | spr_table15d0[i] | spr_property_bits166e[i] & 0x20)) {
      uint8 v2 = spr_table1632[i];
      if (player_climbing_flag)
        v2 ^= 1;
      if (player_current_layer_priority == v2) {
        StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(i);
        if (R14_)
          CheckPlayerAttackToNormalSpriteColl_GetCapeSwingOrNetPunchClipping();
        else
          CheckPlayerAttackToNormalSpriteColl_GetBounceSpriteClipping(j);
        if (StandardSpriteToSpriteCollisionChecks_CheckContact())
          CheckPlayerAttackToNormalSpriteColl_029404(i);
      }
    }
  }
}

void CheckPlayerAttackToNormalSpriteColl_029404(uint8 k) {  // 029404
  spr_decrementing_table154c[k] = 8;
  if (spr_spriteid[k] == 0x81) {
    if (spr_table00c2[k]) {
      spr_table00c2[k] = 0;
      spr_yspeed[k] = -64;
      spr_decrementing_table1540[k] = 16;
      spr_table157c[k] = 0;
      spr_decrementing_table1558[k] = 32;
    }
    return;
  }
  if (spr_spriteid[k] == 45)
    goto LABEL_11;
  if ((spr_property_bits167a[k] & 2) == 0) {
    if (spr_current_status[k] == 8 || spr_spriteid[k] != 13 && spr_table00c2[k])
      spr_decrementing_table1540[k] = -1;
LABEL_11:
    spr_decrementing_table1558[k] = 0;
    if (R14_ != 53)
      SpawnContactEffectFromSide(k);
    GivePoints(k, 0);
    spr_current_status[k] = 2;
    if (spr_spriteid[k] == 30)
      spr_decrementing_table1540[9] = 31;
    if ((spr_property_bits1662[k] & 0x80) == 0 && (spr_property_bits1656[k] & 0x10) != 0 && (spr_property_bits1656[k] & 0x20) == 0) {
      spr_current_status[k] = 9;
      spr_table15f6[k] *= 2;
      spr_table15f6[k] = (spr_table15f6[k] >> 1) + 0x80;
      if ((spr_property_bits1686[k] & 0x40) != 0) {
        spr_spriteid[k] = kGenericSpriteToSpawnTable[spr_spriteid[k]];
        InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
      }
    }
  }
  uint8 v1 = -64;
  if (R14_) {
    v1 = -80;
    if (R14_ == 2)
      v1 = -64;
  }
  spr_yspeed[k] = v1;
  uint8 v2 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
  spr_xspeed[k] = kCheckPlayerAttackToNormalSpriteColl_DATA_029392[v2];
  spr_table157c[k] = v2 ^ 1;
}

void RunPlayerBlockCode_TriggerCapeDiveGroundPound() {  // 0294c1
  timer_shake_layer1 = 48;
  unusedram_7e14a9 = 0;
  for (uint8 i = 9; (i & 0x80) == 0; --i) {
    if (spr_current_status[i] >= 8 && (spr_table1588[i] & 4) != 0 &&
        !(spr_decrementing_table154c[i] | spr_table15d0[i] | spr_property_bits166e[i] & 0x20)) {
      R14_ = 53;
      CheckPlayerAttackToNormalSpriteColl_029404(i);
    }
  }
}

void HandleCapeInteraction() {  // 0294f5
  if (flag_cape_to_sprite_interaction) {
    R14_ = flag_cape_to_sprite_interaction;
    if (counter_global_frames & 1) {
      CheckPlayerAttackToNormalSpriteColl_CapeSwingEntry();
      HandleCapeToExtendedSpriteCollision();
    }
    HandleCapeLevelCollision();
  }
}

void HandleCapeLevelCollision() {  // 02950b
  R15_ = 0;
  HandleCapeLevelColl_029540();
  if ((misc_level_layout_flags & 0x80) != 0) {
    ++R15_;
    player_cape_hitbox_x += misc_second_level_layer_xpos;
    player_cape_hitbox_y += misc_second_level_layer_ypos;
    HandleCapeLevelColl_029540();
  }
}

void HandleCapeLevelColl_029540() {  // 029540
  uint8 v0 = counter_global_frames & 1;
  if ((misc_level_layout_flags & (uint8)(R15_ + 1)) != 0) {
    uint16 posy = player_cape_hitbox_y + kHandleCapeLevelColl_DATA_02953C[v0];
    LOBYTE(blocks_ypos) = R0_ = posy & 0xF0;
    if ((posy >> 8) < misc_screens_in_lvl) {
      HIBYTE(blocks_ypos) = R3_ = (posy >> 8);
      uint16 posx = player_cape_hitbox_x + kHandleCapeLevelColl_DATA_02953E[v0];
      LOBYTE(blocks_xpos) = R1_ = posx;
      if ((uint8)(posx >> 8) < 2) {
        HIBYTE(blocks_xpos) = R2_ = (posx >> 8);
        R0_ |= R1_ >> 4;
        uint8 v2 = kLevelDataLayoutTables_EightBitLo_Vertical[R3_];
        uint8 v3 = kLevelDataLayoutTables_EightBitHi_Vertical[R3_];
        if (R15_) {
          v2 = kLevelDataLayoutTables_EightBitLo_Vertical_L2[R3_];
          v3 = kLevelDataLayoutTables_EightBitHi_Vertical_L2[R3_];
        }
        R5_W = PAIR16(R2_, R0_) + PAIR16(v3, v2);
LABEL_17:
        R7_ = 126;
        blocks_currently_processed_map16_tile_lo = *IndirPtr(&R5_, 0);
        ++R7_;
        uint8 *v8 = IndirPtr(&R5_, 0);
        if (ModifyMap16IDForSpecialBlocks(*v8)) {
          LOBYTE(misc_current_layer_being_processed) = R15_;
          CheckIfBlockWasHit(blocks_currently_processed_map16_tile_lo, 0);
        }
      }
    }
  } else {
    uint16 posy = player_cape_hitbox_y + kHandleCapeLevelColl_DATA_02953C[v0];
    LOBYTE(blocks_ypos) = R0_ = posy & ~0xF;
    if ((posy >> 8) < 2) {
      HIBYTE(blocks_ypos) = R2_ = (posy >> 8);
      uint16 posx = player_cape_hitbox_x + kHandleCapeLevelColl_DATA_02953E[v0];
      LOBYTE(blocks_xpos) = R1_ = posx;
      if ((uint8)(posx >> 8) < misc_screens_in_lvl) {
        HIBYTE(blocks_xpos) = R3_ = posx >> 8;
        R0_ |= R1_ >> 4;
        uint8 v6 = kLevelDataLayoutTables_EightBitLo[R3_];
        uint8 v7 = kLevelDataLayoutTables_EightBitHi[R3_];
        if (R15_) {
          v6 = kLevelDataLayoutTables_EightBitLo_Horizontal_L2[R3_];
          v7 = kLevelDataLayoutTables_EightBitHi_Horizontal_L2[R3_];
        }
        R5_W = PAIR16(R2_, R0_) + PAIR16(v7, v6);
        goto LABEL_17;
      }
    }
  }
}

void HandleCapeToExtendedSpriteCollision() {  // 029631
  for (uint8 i = 7; (i & 0x80) == 0; --i) {
    spr_current_slotid = i;
    if (ext_spr_spriteid[i] >= 2) {
      GetExtendedSpriteClipping(i);
      CheckPlayerAttackToNormalSpriteColl_GetCapeSwingOrNetPunchClipping();
      if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
        if (ext_spr_spriteid[i] != 18)
          CheckMarioToExtendedSpriteColl_02A4DE(i);
      }
    }
  }
}

void CheckPlayerAttackToNormalSpriteColl_GetBounceSpriteClipping(uint8 j) {  // 029663
  uint8 v1 = bounce_spr_type[j];
  SetHiLo(&R8_, &R0_, PAIR16(kCheckPlayerAttackToNormalSpriteColl_DATA_029658[v1 - 1], kCheckPlayerAttackToNormalSpriteColl_DATA_029657[v1 - 1]) +
      PAIR16(bounce_spr_hitbox_x_hi[j], bounce_spr_hitbox_x_lo[j]));
  R2_ = kCheckPlayerAttackToNormalSpriteColl_DATA_02965A[v1 - 1];
  SetHiLo(&R9_, &R1_, PAIR16(kCheckPlayerAttackToNormalSpriteColl_DATA_02965E[v1 - 1], kCheckPlayerAttackToNormalSpriteColl_DATA_02965C[v1 - 1]) +
      PAIR16(bounce_spr_hitbox_y_hi[j], bounce_spr_hitbox_y_lo[j]));
  R3_ = kCheckPlayerAttackToNormalSpriteColl_DATA_029660[v1 - 1];
}

void CheckPlayerAttackToNormalSpriteColl_GetCapeSwingOrNetPunchClipping() {  // 029696
  SetHiLo(&R8_, &R0_, player_cape_hitbox_x - 2);
  R2_ = 20;
  SetHiLo(&R9_, &R1_, player_cape_hitbox_y);
  R3_ = 16;
}

void ProcessBounceAndSmokeSprites_SmokeSprites(uint8 k) {  // 0296c0
  uint8 v1 = smoke_spr_spriteid[k];
  if (v1)
    kUnk_296cb[v1 & 0x7F](k);
}

void ProcessBounceAndSmokeSprites_Return0296D7(uint8 k) {  // 0296d7
  ;
}

void EraseSmokeSprite(uint8 k) {  // 0296df
  smoke_spr_spriteid[k] = 0;
}

void SmokeSpr01_PuffOfSmoke(uint8 k) {  // 0296e3
  OamEnt *v2;
  OamEnt *oam;

  if (!smoke_spr_timer[k])
    goto LABEL_10;
  if ((smoke_spr_spriteid[k] & 0x80) != 0 || !flag_sprites_locked)
    --smoke_spr_timer[k];
  if (spr_spriteid[7] == 0xA9 || (misc_nmito_use_flag & 0x40) == 0) {
    uint8 v3 = kSmokeSpriteOAMIndexes_One[k];
    if ((uint8)(smoke_spr_xpos_lo[k] - mirror_current_layer1_xpos) >= 0xF4 ||
        (oam = get_OamEnt(oam_buf, v3), oam->xpos = smoke_spr_xpos_lo[k] - mirror_current_layer1_xpos,
         (uint8)(smoke_spr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xE0)) {
      EraseSmokeSprite(k);
    } else {
      oam->ypos = smoke_spr_ypos_lo[k] - mirror_current_layer1_ypos;
      oam->flags = sprites_tile_priority;
      get_OamEnt(oam_buf, v3)->charnum = kSmokeSpr01_PuffOfSmoke_Tiles[smoke_spr_timer[k] >> 2];
      sprites_oamtile_size_buffer[v3 >> 2] = 2;
    }
  } else {
    uint8 v1 = kSmokeSpriteOAMIndexes_Two[k];
    if ((uint8)(smoke_spr_xpos_lo[k] - mirror_current_layer1_xpos) >= 0xF4 ||
        (v2 = get_OamEnt(oam_buf, v1), v2[64].xpos = smoke_spr_xpos_lo[k] - mirror_current_layer1_xpos,
         (uint8)(smoke_spr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xE0)) {
LABEL_10:
      EraseSmokeSprite(k);
      return;
    }
    v2[64].ypos = smoke_spr_ypos_lo[k] - mirror_current_layer1_ypos;
    v2[64].flags = sprites_tile_priority;
    get_OamEnt(oam_buf, v1)[64].charnum = kSmokeSpr01_PuffOfSmoke_Tiles[smoke_spr_timer[k] >> 2];
    sprites_oamtile_size_buffer[(v1 >> 2) + 64] = 2;
  }
}

void SmokeSpr02_ContactEffect(uint8 k) {  // 029797
  if (!smoke_spr_timer[k])
    goto LABEL_2;
  if (!flag_sprites_locked)
    --smoke_spr_timer[k];
  if ((misc_nmito_use_flag & 0x40) != 0 && misc_nmito_use_flag != 0xC1) {
    int8 v6 = smoke_spr_xpos_lo[k] - mirror_current_layer1_xpos;
    if ((uint8)v6 < 0xF0) {
      OamEnt *oam = get_OamEnt(oam_buf, 0x90);
      oam[64].xpos = v6;
      oam[66].xpos = v6;
      int8 v8 = v6 + 8;
      oam[65].xpos = v8;
      oam[67].xpos = v8;
      int8 v9 = smoke_spr_ypos_lo[k] - mirror_current_layer1_ypos;
      oam[64].ypos = v9;
      oam[65].ypos = v9;
      v9 += 8;
      oam[66].ypos = v9;
      oam[67].ypos = v9;
      int8 v10 = sprites_tile_priority | (32 * smoke_spr_timer[k]) & 0x40;
      oam[64].flags = v10;
      oam[65].flags = v10;
      v10 ^= 0xC0;
      oam[66].flags = v10;
      oam[67].flags = v10;
      if ((smoke_spr_timer[k] & 2) != 0) {
        oam[64].charnum = 125;
        oam[67].charnum = 125;
        oam[65].charnum = 124;
        oam[66].charnum = 124;
      } else {
        oam[64].charnum = 124;
        oam[67].charnum = 124;
        oam[65].charnum = 125;
        oam[66].charnum = 125;
      }
      sprites_oamtile_size_buffer[100] = 0;
      sprites_oamtile_size_buffer[101] = 0;
      sprites_oamtile_size_buffer[102] = 0;
      sprites_oamtile_size_buffer[103] = 0;
    } else {
      EraseSmokeSprite(k);
    }
  } else {
    int8 v1 = smoke_spr_xpos_lo[k] - mirror_current_layer1_xpos;
    if ((uint8)v1 >= 0xF0) {
LABEL_2:
      EraseSmokeSprite(k);
      return;
    }
    OamEnt *v2 = get_OamEnt(oam_buf, 0xF0);
    v2->xpos = v1;
    v2[2].xpos = v1;
    int8 v3 = v1 + 8;
    v2[1].xpos = v3;
    v2[3].xpos = v3;
    int8 v4 = smoke_spr_ypos_lo[k] - mirror_current_layer1_ypos;
    v2->ypos = v4;
    v2[1].ypos = v4;
    v4 += 8;
    v2[2].ypos = v4;
    v2[3].ypos = v4;
    int8 v5 = sprites_tile_priority | (32 * smoke_spr_timer[k]) & 0x40;
    v2->flags = v5;
    v2[1].flags = v5;
    v5 ^= 0xC0;
    v2[2].flags = v5;
    v2[3].flags = v5;
    if ((smoke_spr_timer[k] & 2) != 0) {
      v2->charnum = 125;
      v2[3].charnum = 125;
      v2[1].charnum = 124;
      v2[2].charnum = 124;
    } else {
      v2->charnum = 124;
      v2[3].charnum = 124;
      v2[1].charnum = 125;
      v2[2].charnum = 125;
    }
    sprites_oamtile_size_buffer[60] = 0;
    sprites_oamtile_size_buffer[61] = 0;
    sprites_oamtile_size_buffer[62] = 0;
    sprites_oamtile_size_buffer[63] = 0;
  }
}

void SmokeSpr05_Glitter(uint8 k) {  // 0298ca
  uint8 v1 = smoke_spr_timer[k];
  if (v1) {
    if (!flag_sprites_locked) {
      --smoke_spr_timer[k];
      if ((v1 & 3) == 0) {
        uint8 v2 = 11;
        while (mextspr_spriteid[v2]) {
          if ((--v2 & 0x80) != 0) {
            if ((--mextspr_slot_to_overwrite_when_slots_full & 0x80) != 0)
              mextspr_slot_to_overwrite_when_slots_full = 11;
            v2 = mextspr_slot_to_overwrite_when_slots_full;
            break;
          }
        }
        mextspr_spriteid[v2] = 2;
        R1_ = smoke_spr_ypos_lo[k];
        R0_ = smoke_spr_xpos_lo[k];
        uint8 v3 = (smoke_spr_timer[k] >> 2) & 3;
        mextspr_xpos_lo[v2] = R0_ + kSmokeSpr05_Glitter_DATA_0298C2[v3];
        mextspr_ypos_lo[v2] = R1_ + kSmokeSpr05_Glitter_DATA_0298C6[v3];
        mextspr_timer[v2] = 23;
      }
    }
  } else {
    EraseSmokeSprite(k);
  }
}

void SmokeSpr03_TurnAroundSmoke(uint8 k) {  // 029927
  uint8 v1 = smoke_spr_timer[k];
  if (v1) {
    if (!flag_sprites_locked) {
      --smoke_spr_timer[k];
      if ((v1 & 7) == 0)
        --smoke_spr_ypos_lo[k];
    }
    uint8 v2;
    if (spr_spriteid[7] == 0xA9 || flag_reznor_room_oamindex_timer || (misc_nmito_use_flag & 0x80) == 0) {
      v2 = kSmokeSpriteOAMIndexes_One[k];
    } else {
      if (misc_nmito_use_flag != 0xC1 && (misc_nmito_use_flag & 0x40) != 0) {
        uint8 v4 = kSmokeSpriteOAMIndexes_Two[k];
        OamEnt *oam = get_OamEnt(oam_buf, v4);
        oam[64].xpos = smoke_spr_xpos_lo[k] - mirror_current_layer1_xpos;
        oam[64].ypos = smoke_spr_ypos_lo[k] - mirror_current_layer1_ypos;
        oam[64].flags = sprites_tile_priority;
        oam[64].charnum = kSmokeSpr03_TurnAroundSmoke_Tiles[smoke_spr_timer[k] >> 2];
        sprites_oamtile_size_buffer[(v4 >> 2) + 64] = 0;
        return;
      }
      v2 = kSmokeSpriteOAMIndexes_Two[k];
    }
    OamEnt *v3 = get_OamEnt(oam_buf, v2);
    v3->xpos = smoke_spr_xpos_lo[k] - mirror_current_layer1_xpos;
    v3->ypos = smoke_spr_ypos_lo[k] - mirror_current_layer1_ypos;
    v3->flags = sprites_tile_priority;
    v3->charnum = kSmokeSpr03_TurnAroundSmoke_Tiles[smoke_spr_timer[k] >> 2];
    sprites_oamtile_size_buffer[v2 >> 2] = 0;
    return;
  }
  if ((misc_nmito_use_flag & 0x40) != 0 && !flag_reznor_room_oamindex_timer)
    get_OamEnt(oam_buf, kSmokeSpriteOAMIndexes_Two[k])[64].ypos = -16;
  EraseSmokeSprite(k);
}

void ProcessSpinningCoinSprites() {  // 0299d2
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    spr_current_slotid = i;
    if (block_coin_spr_slotid[i])
      ProcessSpinningCoinSprites_Sub(i);
  }
}

void ProcessSpinningCoinSprites_Sub(uint8 k) {  // 0299f1
  if (!flag_sprites_locked) {
    ProcessSpinningCoinSprites_UpdateSpinningCoinSpriteYPosition(k);
    uint8 v1 = block_coin_spr_yspeed[k] + 3;
    block_coin_spr_yspeed[k] = v1;
    if (!sign8(v1 - 32)) {
      uint8 v10 = CheckAvailableScoreSpriteSlot();
      score_spr_spriteid[v10] = 1;
      score_spr_ypos_lo[v10] = block_coin_spr_ypos_lo[k];
      score_spr_ypos_hi[v10] = block_coin_spr_ypos_hi[k];
      score_spr_xpos_lo[v10] = block_coin_spr_xpos_lo[k];
      score_spr_xpos_hi[v10] = block_coin_spr_xpos_hi[k];
      score_spr_yspeed[v10] = 48;
      score_spr_layer_index[v10] = block_coin_spr_layer_index[k];
      ProcessSpinningCoinSprites_029ADA(k);
      goto LABEL_9;
    }
  }
  uint8 v2 = 4 * block_coin_spr_layer_index[k];
  R2_ = *((uint8 *)&mirror_current_layer1_ypos + v2);
  R3_ = *((uint8 *)&mirror_current_layer1_xpos + v2);
  R4_ = *((uint8 *)&mirror_current_layer1_ypos + v2 + 1);
  if (block_coin_spr_ypos_hi[k] != (uint8)((block_coin_spr_ypos_lo[k] < R2_) + R4_))
    return;
  if ((uint8)(block_coin_spr_xpos_lo[k] - R3_) >= 0xF8) {
LABEL_9:
    block_coin_spr_slotid[k] = 0;
    return;
  }
  R0_ = block_coin_spr_xpos_lo[k] - R3_;
  R1_ = block_coin_spr_ypos_lo[k] - R2_;
  R15_ = kProcessSpinningCoinSprites_DATA_0299E9[k];
  uint8 v3 = R15_;
  OamEnt *oam = get_OamEnt(oam_buf, R15_);
  oam->xpos = R0_;
  oam->ypos = R1_;
  oam->charnum = -24;
  oam->flags = sprites_tile_priority | 4;
  sprites_oamtile_size_buffer[v3 >> 2] = 2;
  if ((((uint8)(counter_local_frames + k) >> 2) & 3) != 0) {
    uint8 v5 = R15_;
    uint8 v6 = ((uint8)(counter_local_frames + k) >> 2) & 3;
    int8 v7 = R0_ + 4;
    OamEnt *v8 = get_OamEnt(oam_buf, R15_);
    v8->xpos = R0_ + 4;
    v8[1].xpos = v7;
    v8[1].ypos = R1_ + 8;
    uint8 v9 = kProcessSpinningCoinSprites_RollingCoinTiles[v6 - 1];
    v8->charnum = v9;
    v8[1].charnum = v9;
    v8[1].flags = v8->flags | 0x80;
    v5 >>= 2;
    sprites_oamtile_size_buffer[v5] = 0;
    sprites_oamtile_size_buffer[v5 + 1] = 0;
  }
}

void ProcessSpinningCoinSprites_029ADA(uint8 k) {  // 029ada
  uint8 v1 = 3;
  while (smoke_spr_spriteid[v1]) {
    if ((--v1 & 0x80) != 0)
      return;
  }
  smoke_spr_spriteid[v1] = 5;
  uint8 t = block_coin_spr_layer_index[k];
  uint8 v2 = block_coin_spr_xpos_lo[k];
  if (t & 1)
    v2 -= misc_second_level_layer_xpos + 1;
  smoke_spr_xpos_lo[v1] = v2;
  uint8 v3 = block_coin_spr_ypos_lo[k];
  if (t & 1)
    v3 -= misc_second_level_layer_ypos + 1;
  smoke_spr_ypos_lo[v1] = v3;
  smoke_spr_timer[v1] = 16;
}

void ProcessExtendedSprites() {  // 029b0a
  for (int8 i = 9; i >= 0; --i) {
    spr_current_slotid = i;
    ProcessExtendedSprites_029B16(i);
  }
}

void ProcessExtendedSprites_Return029B15(uint8 k) {  // 029b15
  ;
}

void ProcessExtendedSprites_029B16(uint8 k) {  // 029b16
  uint8 v1 = ext_spr_spriteid[k];
  if (v1) {
    if (!flag_sprites_locked) {
      if (ext_spr_decrementing_table176f[k])
        --ext_spr_decrementing_table176f[k];
    }
    kProcessExtendedSprites_ExtendedSpritePtrs[v1](k);
  }
}

void ExtSpr0C_VolcanoLotusFire(uint8 k) {  // 029b51
  uint8 v1 = kExtendedSpriteOAMIndexes[k];
  uint8 v2 = ext_spr_xpos_lo[k];
  R0_ = v2 - mirror_current_layer1_xpos;
  if (ext_spr_xpos_hi[k] != (uint8)((v2 < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)))
    goto LABEL_18;
  uint8 v3 = ext_spr_ypos_lo[k];
  R1_ = v3 - mirror_current_layer1_ypos;
  int8 v4 = ext_spr_ypos_hi[k] - ((v3 < (uint8)mirror_current_layer1_ypos) + HIBYTE(mirror_current_layer1_ypos));
  if (v4) {
    if (v4 >= 0) {
LABEL_18:
      ext_spr_spriteid[k] = 0;
      return;
    }
  } else {
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam->xpos = R0_;
    if (R1_ < 0xF0) {
      oam->ypos = R1_;
      oam->flags = sprites_tile_priority | 9;
      int8 v6 = -90;
      if (((spr_current_slotid ^ (counter_local_frames >> 1)) & 2) != 0)
        v6 = -74;
      oam->charnum = v6;
      sprites_oamtile_size_buffer[v1 >> 2] = 0;
    }
  }
  if (!flag_sprites_locked) {
    CheckMarioToExtendedSpriteCollision(k);
    UpdateExtendedSpritePosition_X(k);
    UpdateExtendedSpritePosition_Y(k);
    if ((counter_global_frames & 3) == 0 && sign8(ext_spr_yspeed[k] - 24))
      ++ext_spr_yspeed[k];
    if ((ext_spr_yspeed[k] & 0x80) == 0) {
      uint8 v7 = 8;
      if (((counter_global_frames + __CFSHL__(4 * k, 1) + 8 * k) & 8) == 0)
        v7 = -8;
      ext_spr_xspeed[k] = v7;
    }
  }
}

void SpawnYoshiStompSmoke() {  // 029be4
  timer_shake_layer1 = 5;
  io_sound_ch3 = 9;
  R0_ = 0;
  SpawnYoshiStompSmoke_SpawnFirstSmoke();
  R0_ = 1;
  SpawnYoshiStompSmoke_SpawnFirstSmoke();
}

void SpawnYoshiStompSmoke_SpawnFirstSmoke() {  // 029bf5
  uint8 j = 7;
  while (ext_spr_spriteid[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  ext_spr_spriteid[j] = 15;
  SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], player_ypos + 40);
  SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], player_xpos + PAIR16(kSpawnYoshiStompSmoke_InitialXHi[R0_], kSpawnYoshiStompSmoke_InitialXLo[R0_]));
  ext_spr_xspeed[j] = kSpawnYoshiStompSmoke_InitialXSpeed[R0_];
  ext_spr_decrementing_table176f[j] = 21;
}

void ExtSpr0F_SmokeTrail(uint8 k) {  // 029c3e
  GenericExtendedSpriteDraw(k);
  uint8 v1 = kExtendedSpriteOAMIndexes[k];
  uint8 v2 = ext_spr_decrementing_table176f[k] >> 1;
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam->flags = (16 * counter_local_frames) & 0xC0 | 0x32;
  oam->charnum = kExtSpr0F_SmokeTrail_Tiles[v2];
  sprites_oamtile_size_buffer[v1 >> 2] = 2;
  if (!flag_sprites_locked) {
    uint8 v4 = ext_spr_decrementing_table176f[k];
    if (v4) {
      if (v4 == 6) {
        int8 v5 = 0;
        if (__CFSHL__(ext_spr_xspeed[k], 1))
          v5 = 0x80;
        ext_spr_xspeed[k] = (ext_spr_xspeed[k] >> 1) + v5;
      }
      UpdateExtendedSpritePosition_X(k);
    } else {
      EraseExtSprite(k);
    }
  }
}

void ExtSpr10_SpinJumpStars(uint8 k) {  // 029c83
  if (ext_spr_decrementing_table176f[k]) {
    GenericExtendedSpriteDraw(k);
    OamEnt *oam = get_OamEnt(oam_buf, kExtendedSpriteOAMIndexes[k]);
    oam->flags = 52;
    oam->charnum = -17;
    if (!flag_sprites_locked &&
        (kExtSpr10_SpinJumpStars_DATA_029CB0[ext_spr_decrementing_table176f[k] >> 2] & counter_global_frames) == 0) {
      UpdateExtendedSpritePosition_X(k);
      UpdateExtendedSpritePosition_Y(k);
    }
  } else {
    EraseExtSprite(k);
  }
}

void ExtSpr0A_CloudCoin(uint8 k) {  // 029cb5
  if (!flag_sprites_locked) {
    UpdateExtendedSpritePosition_Y(k);
    if (sign8(ext_spr_yspeed[k] - 48))
      ext_spr_yspeed[k] += 2;
    if (ext_spr_spriteid[k] == 14) {
      uint8 v1 = 8;
      if ((counter_local_frames & 8) != 0)
        v1 = -8;
      ext_spr_xspeed[k] = v1;
      UpdateExtendedSpritePosition_X(k);
    } else {
      if (!ext_spr_table1765[k] && HandleExtendedSpriteLevelCollision(k) & 1) {
        ext_spr_yspeed[k] = -48;
        ++ext_spr_table1765[k];
      }
      CheckMarioToExtendedSpriteCollision(k);
    }
  }
  if ((uint8)(ext_spr_ypos_lo[k] - mirror_current_layer1_ypos) < 0xF0) {
    R1_ = ext_spr_ypos_lo[k] - mirror_current_layer1_ypos;
    if (ext_spr_xpos_hi[k] == (uint8)((ext_spr_xpos_lo[k] < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos))) {
      uint8 v2 = kExtendedSpriteOAMIndexes[k];
      R15_ = v2;
      R0_ = ext_spr_xpos_lo[k] - mirror_current_layer1_xpos;
      OamEnt *oam = get_OamEnt(oam_buf, v2);
      oam->xpos = R0_;
      if (ext_spr_spriteid[k] == 14) {
        oam->ypos = R1_ - 5;
        oam->charnum = -104;
        ExtSpr0A_CloudCoin_029D36(v2, 0xB);
      } else {
        ExtSpr0A_CloudCoin_029D45(v2);
      }
    }
  } else {
    EraseExtSprite(k);
  }
}

void ExtSpr0A_CloudCoin_029D36(uint8 j, uint8 a) {  // 029d36
  get_OamEnt(oam_buf, j)->flags = sprites_tile_priority | a;
  sprites_oamtile_size_buffer[j >> 2] = 0;
}

void ExtSpr0A_CloudCoin_029D45(uint8 j) {  // 029d45
  OamEnt *oam = get_OamEnt(oam_buf, j);
  oam->ypos = R1_;
  oam->charnum = -62;
  ExtSpr0A_CloudCoin_029D36(j, 4);
  sprites_oamtile_size_buffer[j >> 2] = 2;
}

void ExtSpr09_Unused(uint8 k) {  // 029d9d
  uint8 v1;
  OamEnt *oam;

  CheckMarioToExtendedSpriteCollision(k);
  if (spr_current_status[ext_spr_xspeed[k]] == 8 && (v1 = ext_spr_decrementing_table176f[k]) != 0) {
    R15_ = kExtSpr09_Unused_DATA_029D5E[v1 >> 2];
    R2_ = R15_ + __CFSHL__(R15_, 1) + 2 * R15_;
    R3_ = R2_ + ext_spr_table1765[k];
    R0_ = kExtSpr09_Unused_XDisp[R3_] + ext_spr_xpos_lo[k] - mirror_current_layer1_xpos;
    uint8 v2 = kExtSpr09_Unused_YDisp[R3_] + ext_spr_ypos_lo[k] - mirror_current_layer1_ypos;
    R1_ = v2;
    uint8 v3 = kExtendedSpriteOAMIndexes[k];
    if (v2 < 0xF0 && (oam = get_OamEnt(oam_buf, v3), oam->ypos = v2, R0_ >= 0x10) && R0_ < 0xF0) {
      oam->xpos = R0_;
      oam->flags = kExtSpr09_Unused_Prop[ext_spr_table1765[k]];
      oam->charnum = kExtSpr09_Unused_Tiles[R3_];
      sprites_oamtile_size_buffer[v3 >> 2] = kExtSpr09_Unused_TileSize[R15_];
      if ((uint8)(R0_ - player_on_screen_pos_x + 4) < 8 && (uint8)(R1_ - player_on_screen_pos_y) < 0x10) {
        CheckMarioToExtendedSpriteColl_02A469(spr_current_slotid);
      }
    } else {
      EraseExtSprite(k);
    }
  } else {
    EraseExtSprite(k);
  }
}

void EraseExtSprite(uint8 k) {  // 029e39
  ext_spr_spriteid[k] = 0;
}

void ExtSpr08_LauncherArm(uint8 k) {  // 029e3d
  uint8 v1 = 0;
  uint8 v2 = ext_spr_decrementing_table176f[k];
  if (v2) {
    if (v2 < 0x60) {
      v1 = 1;
      if (v2 < 0x30)
        v1 = 2;
    }
    uint8 v6 = v1;
    if (!flag_sprites_locked) {
      ext_spr_yspeed[k] = kExtSpr08_LauncherArm_YSpeed[v1];
      UpdateExtendedSpritePosition_Y(k);
    }
    GenericExtendedSpriteDraw(k);
    uint8 v3 = kExtendedSpriteOAMIndexes[k];
    int8 v4 = -124;
    if (v6)
      v4 = -92;
    OamEnt *oam = get_OamEnt(oam_buf, v3);
    oam->charnum = v4;
    oam->flags = 19;
    sprites_oamtile_size_buffer[v3 >> 2] = 2;
  } else {
    EraseExtSprite(k);
  }
}

void ExtSpr07_LavaSplash(uint8 k) {  // 029e86
  OamEnt *oam;

  if (!flag_sprites_locked) {
    UpdateExtendedSpritePosition_X(k);
    UpdateExtendedSpritePosition_Y(k);
    uint8 v1 = ext_spr_yspeed[k] + 2;
    ext_spr_yspeed[k] = v1;
    if (!sign8(v1 - 48))
      goto LABEL_6;
  }
  uint8 v2 = kExtendedSpriteOAMIndexes[k];
  uint8 v3 = ext_spr_xpos_lo[k];
  R0_ = v3 - mirror_current_layer1_xpos;
  if (ext_spr_xpos_hi[k] == (uint8)((v3 < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)) &&
      (oam = get_OamEnt(oam_buf, v2), oam->xpos = R0_, (uint8)(ext_spr_ypos_lo[k] - mirror_current_layer1_ypos) < 0xF0)) {
    oam->ypos = ext_spr_ypos_lo[k] - mirror_current_layer1_ypos;
    oam->charnum = kExtSpr07_LavaSplash_Tiles[(ext_spr_decrementing_table176f[k] >> 3) & 3];
    oam->flags = sprites_tile_priority | 5;
    sprites_oamtile_size_buffer[v2 >> 2] = 0;
  } else {
LABEL_6:
    ext_spr_spriteid[k] = 0;
  }
}

void ExtSpr12_BreathBubble(uint8 k) {  // 029eee
  if (!flag_sprites_locked) {
    if ((++ext_spr_table1765[k] & 0x30) != 0)
      AddHiLo(&ext_spr_ypos_hi[k], &ext_spr_ypos_lo[k], -1);
    if (!((counter_global_frames ^ k) & 1) &&
        (HandleExtendedSpriteLevelCollision(k) || !flag_underwater_level && R12_ >= 6 && (!R15_ || R13_ >= 6))) {
      goto LABEL_11;
    }
  }
  if (ext_spr_ypos_hi[k] == (uint8)((ext_spr_ypos_lo[k] < (uint8)mirror_current_layer1_ypos) + HIBYTE(mirror_current_layer1_ypos))) {
    GenericExtendedSpriteDraw(k);
    R0_ = kExtSpr12_BreathBubble_XDisp[(uint8)(ext_spr_table1765[k] & 0xC) >> 2];
    OamEnt *oam = get_OamEnt(oam_buf, kExtendedSpriteOAMIndexes[k]);
    oam->xpos += R0_;
    oam->ypos += 5;
    oam->charnum = 28;
  } else {
LABEL_11:
    EraseExtSprite(k);
  }
}

void ExtSpr11_YoshiFireball(uint8 k) {  // 029f61
  if (!flag_sprites_locked) {
    UpdateExtendedSpritePosition_X(k);
    UpdateExtendedSpritePosition_Y(k);
    CheckPlayerFireballToNormalSpriteCollision(k);
  }
  GenericExtendedSpriteDraw(k);
  uint8 v1 = kExtendedSpriteOAMIndexes[k];
  int8 v2 = 4;
  if (counter_local_frames & 0x4)
    v2 = 43;
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam->charnum = v2;
  oam->flags = ((uint8)(ext_spr_xspeed[k] & 0x80 ^ 0x80) >> 1) | 0x35;
  sprites_oamtile_size_buffer[v1 >> 2] = 2;
}

void ExtSpr05_MarioFireball(uint8 k) {  // 029faf
  if (flag_sprites_locked) {
    ExtSpr05_MarioFireball_02A02C(k);
    return;
  }
  if (ext_spr_ypos_hi[k] != (uint8)((ext_spr_ypos_lo[k] < (uint8)mirror_current_layer1_ypos) + HIBYTE(mirror_current_layer1_ypos))) {
    EraseExtSprite(k);
    return;
  }
  ++ext_spr_table1765[k];
  CheckPlayerFireballToNormalSpriteCollision(k);
  if (sign8(ext_spr_yspeed[k] - 48))
    ext_spr_yspeed[k] += 4;
  if (HandleExtendedSpriteLevelCollision(k)) {
    if (++ext_spr_sub_xpos[k] >= 2) {
      ExtSpr05_MarioFireball_02A02C(k);
      ExtSpr05_MarioFireball_02A045(k);
      return;
    }
    if ((ext_spr_xspeed[k] & 0x80) != 0)
      R11_ = -R11_;
    uint8 v1 = R11_ + 4;
    ext_spr_yspeed[k] = kExtSpr05_MarioFireball_DATA_029F99[v1];
    SetHiLo(&ext_spr_ypos_hi[k], &ext_spr_ypos_lo[k], PAIR16(ext_spr_ypos_hi[k], ext_spr_ypos_lo[k]) - kExtSpr05_MarioFireball_DATA_029FA2[v1]);
  } else {
    ext_spr_sub_xpos[k] = 0;
  }
  SetHiLo(&ext_spr_xpos_hi[k], &ext_spr_xpos_lo[k], PAIR16(ext_spr_xpos_hi[k], ext_spr_xpos_lo[k]) + (int8)ext_spr_xspeed[k]);
  UpdateExtendedSpritePosition_Y(k);
  ExtSpr05_MarioFireball_02A02C(k);
}

void ExtSpr05_MarioFireball_02A02C(uint8 k) {  // 02a02c
  if (spr_spriteid[7] == 0xA9 || (misc_nmito_use_flag & 0x80) == 0 || (misc_nmito_use_flag & 0x40) == 0)
    GenericExtendedSpriteGFXRt_FireballEntry(k, kExtSpr05_MarioFireball_DATA_029FA2[k + 1]);
  else
    ExtSpr05_MarioFireball_02A04F(k);
}

void ExtSpr05_MarioFireball_02A045(uint8 k) {  // 02a045
  io_sound_ch1 = 1;
  ext_spr_decrementing_table176f[k] = 15;
  ext_spr_spriteid[k] = 1;
}

void ExtSpr05_MarioFireball_02A04F(uint8 k) {  // 02a04f
  OamEnt *oam;

  uint8 v1 = kExtSpr05_MarioFireball_DATA_029FA2[k + 3];
  R0_ = (uint8)(ext_spr_xspeed[k] & 0x80) >> 1;
  if ((uint8)(ext_spr_xpos_lo[k] - mirror_current_layer1_xpos) >= 0xF8 ||
      (oam = get_OamEnt(oam_buf, v1), oam[64].xpos = ext_spr_xpos_lo[k] - mirror_current_layer1_xpos,
       (uint8)(ext_spr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xF0)) {
    EraseExtSprite(k);
  } else {
    oam[64].ypos = ext_spr_ypos_lo[k] - mirror_current_layer1_ypos;
    R1_ = ext_spr_table1779[k];
    uint8 v3 = (ext_spr_table1765[k] >> 2) & 3;
    oam[64].charnum = kGenericExtendedSpriteGFXRt_FireballTiles[v3];
    int8 v4 = sprites_tile_priority | R0_ ^ kGenericExtendedSpriteGFXRt_DATA_02A15F[v3];
    oam[64].flags = v4;
    if (R1_)
      oam[64].flags = v4 & 0xCF | 0x10;
    sprites_oamtile_size_buffer[(v1 >> 2) + 64] = 0;
  }
}

void CheckPlayerFireballToNormalSpriteCollision(uint8 k) {  // 02a0ac
  if (((counter_global_frames ^ k) & 3) == 0) {
    uint8 v1 = k;
    misc_scratch7e185e = k;
    for (uint8 i = 9; (i & 0x80) == 0; --i) {
      spr_current_slotid = i;
      if (spr_current_status[i] >= 8 && ext_spr_table1779[v1] == (spr_table1632[i] | spr_table15d0[i] | spr_property_bits167a[i] & 2)) {
        StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(i);
        CheckPlayerFireballToNormalSpriteColl_GetPlayerFireballClipping(v1);
        if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
          if (ext_spr_spriteid[v1] != 17)
            ExtSpr05_MarioFireball_02A045(v1);
          if ((spr_property_bits166e[i] & 0x10) == 0) {
            if ((spr_property_bits190f[i] & 8) != 0) {
              if (++spr_table1528[i] >= 5) {
                io_sound_ch1 = 2;
                spr_current_status[i] = 2;
                spr_yspeed[i] = -48;
                spr_xspeed[i] =
                    kCheckPlayerFireballToNormalSpriteColl_FireKillXSpeed[CheckPlayerPositionRelativeToSprite_Bank23_X(i)];
                GivePoints(i, 4);
              }
            } else {
              io_sound_ch1 = 3;
              spr_spriteid[i] = 33;
              spr_current_status[i] = 8;
              InitializeNormalSpriteRAMTables(i);
              spr_yspeed[i] = -48;
              spr_table157c[i] = CheckPlayerPositionRelativeToSprite_Bank23_X(i) ^ 1;
            }
          }
        }
      }
      v1 = misc_scratch7e185e;
    }
    spr_current_slotid = k;
  }
}

void ExtSpr02_ReznorFireball(uint8 k) {  // 02a16b
  if (!flag_sprites_locked) {
    UpdateExtendedSpritePosition_X(k);
    UpdateExtendedSpritePosition_Y(k);
    CheckMarioToExtendedSpriteCollision(k);
  }
  ExtSpr02_ReznorFireball_PiranhaFireballEntry(k);
}

void ExtSpr02_ReznorFireball_PiranhaFireballEntry(uint8 k) {  // 02a178
  if ((misc_nmito_use_flag & 0x80) != 0) {
    GenericExtendedSpriteDraw(k);
    uint8 v1 = kExtendedSpriteOAMIndexes[k];
    uint8 v2 = (counter_local_frames >> 2) & 3;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam->charnum = kExtSpr02_ReznorFireball_Tiles[v2];
    oam->flags = R0_ ^ kExtSpr02_ReznorFireball_Prop[v2];
    sprites_oamtile_size_buffer[v1 >> 2] = 2;
  } else {
    GenericExtendedSpriteDraw(k);
  }
}

void GenericExtendedSpriteDraw(uint8 k) {  // 02a1a4
  GenericExtendedSpriteGFXRt_FireballEntry(k, kExtendedSpriteOAMIndexes[k]);
}

void GenericExtendedSpriteGFXRt_FireballEntry(uint8 k, uint8 j) {  // 02a1a7
  uint8 v3;

  R0_ = (uint8)(ext_spr_xspeed[k] & 0x80 ^ 0x80) >> 1;
  uint8 v2 = ext_spr_xpos_lo[k];
  R1_ = v2 - mirror_current_layer1_xpos;
  if (ext_spr_xpos_hi[k] == (uint8)((v2 < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)) &&
      (v3 = ext_spr_ypos_lo[k], R2_ = v3 - mirror_current_layer1_ypos,
       ext_spr_ypos_hi[k] == (uint8)((v3 < (uint8)mirror_current_layer1_ypos) + HIBYTE(mirror_current_layer1_ypos))) &&
      R2_ < 0xF0) {
    OamEnt *oam = get_OamEnt(oam_buf, j);
    oam->ypos = R2_;
    oam->xpos = R1_;
    R1_ = ext_spr_table1779[k];
    uint8 v5 = (counter_local_frames >> 2) & 3;
    oam->charnum = kGenericExtendedSpriteGFXRt_FireballTiles[v5];
    int8 v6 = sprites_tile_priority | R0_ ^ kGenericExtendedSpriteGFXRt_DATA_02A15F[v5];
    oam->flags = v6;
    if (R1_)
      oam->flags = v6 & 0xCF | 0x10;
    sprites_oamtile_size_buffer[j >> 2] = 0;
  } else {
    EraseExtSprite(k);
  }
}

void ExtSpr03_FlameRemnant(uint8 k) {  // 02a219
  if (flag_sprites_locked)
    goto LABEL_7;
  ++ext_spr_table1765[k];
  uint8 v1 = ext_spr_decrementing_table176f[k];
  if (!v1) {
    EraseExtSprite(k);
    return;
  }
  if (v1 >= 0x50) {
LABEL_7:
    CheckMarioToExtendedSpriteCollision(k);
  } else if ((v1 & 1) != 0) {
    return;
  }
  GenericExtendedSpriteDraw(k);
  OamEnt *oam = get_OamEnt(oam_buf, kExtendedSpriteOAMIndexes[k]);
  oam->charnum = kExtSpr03_FlameRemnant_Tiles[(ext_spr_table1765[k] & 4) != 0];
  oam->flags = oam->flags & 0x3A | 5;
}

void ExtSpr0D_Baseball(uint8 k) {  // 02a254
  if (!flag_sprites_locked) {
    UpdateExtendedSpritePosition_X(k);
    ++ext_spr_table1765[k];
    if ((counter_global_frames & 1) == 0)
      ++ext_spr_table1765[k];
    CheckMarioToExtendedSpriteCollision(k);
  }
  if (ext_spr_spriteid[k] == 13) {
    uint8 v1 = ext_spr_xpos_lo[k];
    R0_ = v1 - mirror_current_layer1_xpos;
    int8 v2 = ext_spr_xpos_hi[k] - ((v1 < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos));
    if (v2) {
      if (((ext_spr_xspeed[k] ^ v2) & 0x80) != 0)
        return;
LABEL_12:
      ext_spr_spriteid[k] = 0;
      return;
    }
    uint8 v3 = kExtendedSpriteOAMIndexes[k];
    OamEnt *oam = get_OamEnt(oam_buf, v3);
    oam->xpos = R0_;
    uint8 v5 = ext_spr_ypos_lo[k];
    R1_ = v5 - mirror_current_layer1_ypos;
    if (ext_spr_ypos_hi[k] != (uint8)((v5 < (uint8)mirror_current_layer1_ypos) + HIBYTE(mirror_current_layer1_ypos)))
      goto LABEL_12;
    oam->ypos = R1_;
    oam->charnum = -83;
    oam->flags = (16 * counter_local_frames) & 0xC0 | 0x39;
    sprites_oamtile_size_buffer[v3 >> 2] = 0;
  } else {
    uint8 v6 = ExtSpr04_Hammer_ThrownBoneEntry(k);
    OamEnt *v7 = get_OamEnt(oam_buf, v6);
    int8 v8 = 0x80;
    if (v7->charnum < 0x26)
      v8 = -126;
    v7->charnum = v8;
    v7->flags = v7->flags & 0xF1 | 2;
  }
}

void ExtSpr04_Hammer(uint8 k) {  // 02a2ef
  if (!flag_sprites_locked) {
    UpdateExtendedSpritePosition_X(k);
    UpdateExtendedSpritePosition_Y(k);
    if (sign8(ext_spr_yspeed[k] - 64)) {
      ++ext_spr_yspeed[k];
      ++ext_spr_yspeed[k];
    }
    CheckMarioToExtendedSpriteCollision(k);
    ++ext_spr_table1765[k];
  }
  if (ext_spr_spriteid[k] == 11)
    ExtSpr02_ReznorFireball_PiranhaFireballEntry(k);
  else
    ExtSpr04_Hammer_ThrownBoneEntry(k);
}

uint8 ExtSpr04_Hammer_ThrownBoneEntry(uint8 k) {  // 02a317
  GenericExtendedSpriteDraw(k);
  uint8 result = kExtendedSpriteOAMIndexes[k];
  uint8 v2 = (ext_spr_table1765[k] >> 3) & 7;
  OamEnt *oam = get_OamEnt(oam_buf, result);
  oam->charnum = kExtSpr04_Hammer_Tiles[v2];
  oam->flags = sprites_tile_priority | R0_ ^ kExtSpr04_Hammer_Prop[v2] ^ 0x40;
  sprites_oamtile_size_buffer[result >> 2] = 2;
  return result;
}

void ExtSpr01_SmokePuff(uint8 k) {  // 02a34f
  if (ext_spr_decrementing_table176f[k]) {
    if (!flag_reznor_room_oamindex_timer && (misc_nmito_use_flag & 0x80) != 0 && (misc_nmito_use_flag & 0x40) != 0) {
      uint8 v3 = kExtSpr05_MarioFireball_DATA_029FA2[k + 3];
      if ((uint8)(ext_spr_xpos_lo[k] - mirror_current_layer1_xpos) < 0xF8) {
        OamEnt *oam = get_OamEnt(oam_buf, v3);
        oam[64].xpos = ext_spr_xpos_lo[k] - mirror_current_layer1_xpos;
        if ((uint8)(ext_spr_ypos_lo[k] - mirror_current_layer1_ypos) < 0xF0) {
          oam[64].ypos = ext_spr_ypos_lo[k] - mirror_current_layer1_ypos;
          oam[64].charnum = kExtSpr01_SmokePuff_Tiles[ext_spr_decrementing_table176f[k] >> 2];
          oam[64].flags = sprites_tile_priority | kExtSpr01_SmokePuff_Prop[(counter_local_frames >> 2) & 3];
          sprites_oamtile_size_buffer[(v3 >> 2) + 64] = 2;
          return;
        }
      }
    } else {
      uint8 v1 = kExtendedSpriteOAMIndexes[k];
      if (k >= 8)
        v1 = kExtSpr05_MarioFireball_DATA_029FA2[k + 1];
      if ((uint8)(ext_spr_xpos_lo[k] - mirror_current_layer1_xpos) < 0xF8) {
        OamEnt *v2 = get_OamEnt(oam_buf, v1);
        v2->xpos = ext_spr_xpos_lo[k] - mirror_current_layer1_xpos;
        if ((uint8)(ext_spr_ypos_lo[k] - mirror_current_layer1_ypos) < 0xF0) {
          v2->ypos = ext_spr_ypos_lo[k] - mirror_current_layer1_ypos;
          v2->charnum = kExtSpr01_SmokePuff_Tiles[ext_spr_decrementing_table176f[k] >> 2];
          v2->flags = sprites_tile_priority | kExtSpr01_SmokePuff_Prop[(counter_local_frames >> 2) & 3];
          sprites_oamtile_size_buffer[v1 >> 2] = 2;
          return;
        }
      }
    }
  }
  EraseExtSprite(k);
}

void CheckMarioToExtendedSpriteCollision(uint8 k) {  // 02a3f6
  if (ext_spr_table1779[k] == player_current_layer_priority) {
    StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
    GetExtendedSpriteClipping(k);
    if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
      if (ext_spr_spriteid[k] == 10) {
        GiveCoins_OneCoin();
        ++counter_pink_berry_cloud_coins;
        ext_spr_spriteid[k] = 0;
        uint8 v1 = 3;
        while (smoke_spr_spriteid[v1]) {
          if ((--v1 & 0x80) != 0) {
            ++v1;
            break;
          }
        }
        smoke_spr_spriteid[v1] = 5;
        smoke_spr_xpos_lo[v1] = ext_spr_xpos_lo[k];
        smoke_spr_ypos_lo[v1] = ext_spr_ypos_lo[k];
        smoke_spr_timer[v1] = 10;
        uint8 v2 = CheckAvailableScoreSpriteSlot();
        score_spr_spriteid[v2] = 5;
        score_spr_ypos_lo[v2] = ext_spr_ypos_lo[k];
        score_spr_ypos_hi[v2] = ext_spr_ypos_hi[k];
        score_spr_xpos_lo[v2] = ext_spr_xpos_lo[k];
        score_spr_xpos_hi[v2] = ext_spr_xpos_hi[k];
        score_spr_yspeed[v2] = 48;
        score_spr_layer_index[v2] = 0;
      } else {
        CheckMarioToExtendedSpriteColl_02A469(k);
      }
    }
  }
}

void CheckMarioToExtendedSpriteColl_02A469(uint8 k) {  // 02a469
  if (timer_star_power) {
    if (ext_spr_spriteid[k] != 4) {
      uint8 v1 = ext_spr_xpos_lo[k];
      ext_spr_xpos_lo[k] = v1 - 4;
      ext_spr_xpos_hi[k] -= v1 < 4;
      uint8 v2 = ext_spr_ypos_lo[k];
      ext_spr_ypos_lo[k] = v2 - 4;
      ext_spr_ypos_hi[k] -= v2 < 4;
    }
    CheckMarioToExtendedSpriteColl_02A4DE(k);
  } else if (player_riding_yoshi_flag) {
    CheckMarioToExtendedSpriteColl_LoseYoshi();
  } else {
    DamagePlayer_Hurt();
  }
}

void CheckMarioToExtendedSpriteColl_LoseYoshi() {  // 02a473
  uint8 v0 = sprites_yoshi_slot_index;
  int v1 = sprites_yoshi_slot_index;
  spr_table1632[sprites_yoshi_slot_index + 11] = 16;
  io_sound_ch2 = 3;
  io_sound_ch3 = 19;
  spr_xspeed[v1 + 11] = 2;
  player_riding_yoshi_flag = 0;
  yoshi_carry_over_levels_flag = 0;
  player_yspeed = -64;
  player_xspeed = 0;
  spr_yspeed[v0 + 11] = kCheckMarioToExtendedSpriteColl_YoshiXSpeed[spr_table1570[v0 + 11]];
  spr_table1588[v0 + 11] = 0;
  spr_table1510[v0 + 11] = 0;
  timer_yoshi_tongue_init = 0;
  timer_player_hurt = 48;
}

void CheckMarioToExtendedSpriteColl_02A4DE(uint8 k) {  // 02a4de
  ext_spr_decrementing_table176f[k] = 7;
  ext_spr_spriteid[k] = 1;
}

void GetExtendedSpriteClipping(uint8 k) {  // 02a519
  uint8 v1 = ext_spr_spriteid[k];
  SetHiLo(&R10_, &R4_, PAIR16(ext_spr_xpos_hi[k], ext_spr_xpos_lo[k]) + kGetExtendedSpriteClipping_DATA_02A4E9[v1 - 2]);
  R6_ = kGetExtendedSpriteClipping_DATA_02A501[v1 - 2];
  SetHiLo(&R11_, &R5_, PAIR16(ext_spr_ypos_hi[k], ext_spr_ypos_lo[k]) + kGetExtendedSpriteClipping_DATA_02A4F5[v1 - 2]);
  R7_ = kGetExtendedSpriteClipping_DATA_02A50D[v1 - 2];
}

void CheckPlayerFireballToNormalSpriteColl_GetPlayerFireballClipping(uint8 j) {  // 02a547
  SetHiLo(&R8_, &R0_, PAIR16(ext_spr_xpos_hi[j], ext_spr_xpos_lo[j]) - 2);
  R2_ = 12;
  SetHiLo(&R9_, &R1_, PAIR16(ext_spr_ypos_hi[j], ext_spr_ypos_lo[j]) - 4);
  R3_ = 19;
}

uint8 HandleExtendedSpriteLevelCollision(uint8 k) {  // 02a56e
  R15_ = 0;
  R14_ = 0;
  R11_ = 0;
  sprites_distance_to_snap_down_to_nearest_tile = 0;
  if (!flag_reznor_room_oamindex_timer && (misc_nmito_use_flag & 0x80) != 0) {
    if ((misc_nmito_use_flag & 0x40) == 0) {
      WORD(temp14b4) = PAIR16(ext_spr_xpos_hi[k], ext_spr_xpos_lo[k]) + 4;
      WORD(temp14b6) = PAIR16(ext_spr_ypos_hi[k], ext_spr_ypos_lo[k]) + 8;
      return CheckTiltingPlatformCollision();
    }
    if (misc_nmito_use_flag != 0xC1)
      return ext_spr_ypos_lo[k] >= 0xA8;
  }
  R14_ = 2 * R14_ + (HandleExtendedSpriteLevelColl_02A611(k));
  R12_ = blocks_currently_processed_map16_tile_lo;
  if ((misc_level_layout_flags & 0x80) != 0) {
    ++R15_;
    uint16 old_x = PAIR16(ext_spr_xpos_hi[k], ext_spr_xpos_lo[k]);
    uint16 old_y = PAIR16(ext_spr_ypos_hi[k], ext_spr_ypos_lo[k]);
    AddHiLo(&ext_spr_xpos_hi[k], &ext_spr_xpos_lo[k], misc_second_level_layer_xpos);
    AddHiLo(&ext_spr_ypos_hi[k], &ext_spr_ypos_lo[k], misc_second_level_layer_ypos);
    R14_ = 2 * R14_ + (HandleExtendedSpriteLevelColl_02A611(k));
    R13_ = blocks_currently_processed_map16_tile_lo;
    SetHiLo(&ext_spr_xpos_hi[k], &ext_spr_xpos_lo[k], old_x);
    SetHiLo(&ext_spr_ypos_hi[k], &ext_spr_ypos_lo[k], old_y);
  }
  return R14_ != 0;
}

uint8 HandleExtendedSpriteLevelColl_02A611(uint8 k) {  // 02a611
  while (1) {
    if ((misc_level_layout_flags & (uint8)(R15_ + 1)) != 0) {
      uint16 t = PAIR16(ext_spr_ypos_hi[k], ext_spr_ypos_lo[k]) + 8;
      LOBYTE(blocks_ypos) = t;
      R0_ = t & ~0xF;
      if ((t >> 8) >= misc_screens_in_lvl)
        return 0;
      R3_ = (t >> 8);
      HIBYTE(blocks_ypos) = (t >> 8);
      t = PAIR16(ext_spr_xpos_hi[k], ext_spr_xpos_lo[k]) + 4;
      R1_ = t;
      LOBYTE(blocks_xpos) = t;
      if ((t >> 8) >= 2)
        return 0;
      HIBYTE(blocks_xpos) = R2_ = (t >> 8);
      R0_ |= R1_ >> 4;
      uint8 v4 = kLevelDataLayoutTables_EightBitLo_Vertical[R3_];
      uint8 v5 = kLevelDataLayoutTables_EightBitHi_Vertical[R3_];
      if (R15_) {
        v4 = kLevelDataLayoutTables_EightBitLo_Vertical_L2[R3_];
        v5 = kLevelDataLayoutTables_EightBitHi_Vertical_L2[R3_];
      }
      *(uint16 *)&R5_ = PAIR16(R2_, R0_) + PAIR16(v5, v4);
    } else {
      uint16 t = PAIR16(ext_spr_ypos_hi[k], ext_spr_ypos_lo[k]) + 8;
      blocks_ypos = t;
      R0_ = t & 0xf0;
      R2_ = t >> 8;
      if ((uint8)(R0_ - mirror_current_layer1_ypos) >= 0xF0)
        return 0;
      uint16 xpos = PAIR16(ext_spr_xpos_hi[k], ext_spr_xpos_lo[k]) + 4;
      
      LOBYTE(blocks_xpos) = R1_ = xpos;
      if ((xpos >> 8) >= misc_screens_in_lvl)
        return 0;
      R3_ = (xpos >> 8);
      HIBYTE(blocks_xpos) = (xpos >> 8);
      R0_ |= R1_ >> 4;
      uint8 v10 = kLevelDataLayoutTables_EightBitLo[R3_];
      uint8 v11 = kLevelDataLayoutTables_EightBitHi[R3_];
      if (R15_) {
        v10 = kLevelDataLayoutTables_EightBitLo_Horizontal_L2[R3_];
        v11 = kLevelDataLayoutTables_EightBitHi_Horizontal_L2[R3_];
      }
      *(uint16 *)&R5_ = PAIR16(R2_, R0_) + PAIR16(v11, v10);
    }
    R7_ = 126;
    k = spr_current_slotid;
    blocks_currently_processed_map16_tile_lo = *IndirPtr(&R5_, 0);
    ++R7_;
    uint8 *v12 = IndirPtr(&R5_, 0);
    if (!ModifyMap16IDForSpecialBlocks(*v12))
      return 0;
    if (blocks_currently_processed_map16_tile_lo < 0x11)
      return (blocks_ypos & 0xF) < 6;
    if (blocks_currently_processed_map16_tile_lo < 0x6E)
      return 1;
    if (blocks_currently_processed_map16_tile_lo < 0xD8)
      break;
    if ((blocks_ypos & 0xF) >= 6)
      return 0;
    AddHiLo(&ext_spr_ypos_hi[k], &ext_spr_ypos_lo[k], -2);
  }
  R10_ = blocks_xpos;
  R12_ = blocks_ypos;
  uint8 v13 = CheckWhatSlopeSpriteIsOn(blocks_currently_processed_map16_tile_lo);
  uint8 v14 = R0_;
  if (R0_ < 0xC && v14 < *IndirPtr(&R5_, v13))
    return 0;
  sprites_distance_to_snap_down_to_nearest_tile = *IndirPtr(&R5_, v13);
  R11_ = kSlopeDataTables_SlopeType[R8_];
  return 1;
}

void LoadSublevel_02A751() {  // 02a751
  InitializeAllSpritesOnLevelLoad();
  LoadSpritesOnLevelLoad();
  if ((misc_nmito_use_flag & 0x80) == 0)
    ProcessNormalSprites();
  if (yoshi_carry_over_levels_flag) {
    if (!flag_prevent_yoshi_carry_over)
      SpawnMountedYoshiOnLevelLoad();
  }
}

void ParseLevelSpriteList() {  // 02a7fc
  if ((counter_global_frames & 1) == 0)
    ParseLevelSpriteList_Entry2();
}

void ParseLevelSpriteList_Entry2() {  // 02a802
  int8 v0;
  if (misc_level_layout_flags & 1) {
    uint16 t = kParseLevelSpriteList_DATA_02A7F6[camera_layer1_scrolling_direction] + (uint8)mirror_current_layer1_ypos;
    R0_ = t & 0xF0;
    v0 = HIBYTE(mirror_current_layer1_ypos) + (t >> 8);
  } else {
    uint16 t = kParseLevelSpriteList_DATA_02A7F6[camera_layer1_scrolling_direction] + (uint8)mirror_current_layer1_xpos;
    R0_ = t & 0xF0;
    v0 = HIBYTE(mirror_current_layer1_xpos) + (t >> 8);
  }
  int8 v1 = kParseLevelSpriteList_DATA_02A7F9[camera_layer1_scrolling_direction] + v0;
  if (v1 >= 0) {
    R1_ = v1;
    ParseLevelSpriteList_LoadSpriteLoopStrt(0, 1);
  }
}

void ParseLevelSpriteList_LoadSpriteLoopStrt(uint8 k, uint8 j) {  // 02a82e
  while (1) {
    uint8 *v2 = IndirPtr(&ptr_sprite_list_data, j);
    if (*v2 == 0xFF)
      break;
    R2_ = (8 * *v2) & 0x10;
    uint8 v3 = j + 1;
    uint8 v4 = R2_ | *IndirPtr(&ptr_sprite_list_data, v3) & 0xF;
    bool v5 = v4 < R1_;
    int8 v6 = v4 - R1_;
    if (v5)
      goto LABEL_3;
    if (v6)
      return;
    if ((*IndirPtr(&ptr_sprite_list_data, v3) & 0xF0) != R0_ || sprites_load_status[k]) {
LABEL_3:
      j = v3 + 2;
      ++k;
    } else {
      R2_ = k;
      ++sprites_load_status[k];
      uint8 v7 = v3 + 1;
      uint8 v8 = *IndirPtr(&ptr_sprite_list_data, v7);
      uint8 v9;
      R5_ = v8;
      v3 = v7 - 1;
      if (v8 >= 0xE7) {
        if (!*(uint16 *)l1_l2_scroll_spr_spriteid) {
          l1_l2_scroll_spr_spriteid[0] = R5_ + 25;
          l1_l2_scroll_spr_scroll_type_index[0] = *IndirPtr(&ptr_sprite_list_data, (uint8)(v3 - 1)) >> 2;
          InitializeScrollSprites();
        }
        goto LABEL_3;
      }
      if (v8 == 0xDE) {
        R3_ = v3 - 1;
        Spr0DE_Load5Eeries(k);
        goto LABEL_3;
      }
      if (v8 == 0xE0) {
        R3_ = v3 - 1;
        Spr0E0_Load3Platforms();
        goto LABEL_3;
      }
      if (v8 < 0xCB) {
        if (v8 >= 0xC9) {
          SprXXX_LoadShooter(k, v3, v8);
          goto LABEL_3;
        }
        v9 = 1;
      } else {
        if (v8 < 0xDA) {
          gen_spr_spriteid = v8 + 54;
          sprites_load_status[k] = 0;
          goto LABEL_3;
        }
        if (v8 >= 0xE1) {
          R3_ = v3 - 1;
          Spr0E1_LoadBooCeiling(k, v8);
          goto LABEL_3;
        }
        v9 = 9;
      }
      R4_ = v9;
      R3_ = v3 - 1;
      uint8 v10 = kParseLevelSpriteList_SpriteSlotMax[sprites_sprite_memory_setting];
      R6_ = kParseLevelSpriteList_SpriteSlotStart[sprites_sprite_memory_setting];
      if (R5_ == kParseLevelSpriteList_ReservedSprite1[sprites_sprite_memory_setting]) {
        v10 = kParseLevelSpriteList_SpriteSlotMax1[sprites_sprite_memory_setting];
        R6_ = kParseLevelSpriteList_SpriteSlotStart1[sprites_sprite_memory_setting];
      }
      if (R5_ == kParseLevelSpriteList_ReservedSprite2[sprites_sprite_memory_setting] && (R5_ != 100 || (R0_ & 0x10) != 0)) {
        v10 = kParseLevelSpriteList_SpriteSlotMax2[sprites_sprite_memory_setting];
        R6_ = -1;
      }
      R15_ = v10;
      while (spr_current_status[v10]) {
        if (--v10 == R6_) {
          if (R5_ != 123) {
LABEL_38:
            sprites_load_status[R2_] = 0;
            return;
          }
          v10 = R15_;
          while ((spr_property_bits167a[v10] & 2) != 0) {
            if (--v10 == R6_)
              goto LABEL_38;
          }
          break;
        }
      }
      uint8 v11 = R3_;
      uint8 *v12 = IndirPtr(&ptr_sprite_list_data, R3_);
      if (misc_level_layout_flags & 1) {
        SetSprXYPos(v10, *v12 & 0xF0 | (*v12 & 0xD) << 8, R0_W);
      } else {
        SetSprXYPos(v10, R0_W, *v12 & 0xF0 | (*v12 & 0xD) << 8);
      }
      uint8 v14 = v11 + 2;
      spr_current_status[v10] = R4_;
      uint8 v15 = *IndirPtr(&ptr_sprite_list_data, v14);
      if (R4_ >= 9)
        v15 += 42;
      if ((ow_level_tile_settings[73] & 0x80) != 0) {
        if (v15 == 4)
          v15 = 7;
        if (v15 == 5)
          v15 = 6;
      }
      spr_spriteid[v10] = v15;
      spr_load_status_table_index[v10] = R2_;
      if (!timer_silver_pswitch || (kInitializeNormalSpriteRAMTables_Sprite190FVals[spr_spriteid[v10]] & 0x40) != 0) {
        InitializeNormalSpriteRAMTables(v10);
      } else {
        spr_spriteid[v10] = 33;
        spr_current_status[v10] = 8;
        InitializeNormalSpriteRAMTables(v10);
        spr_table15f6[v10] = spr_table15f6[v10] & 0xF1 | 2;
      }
      spr_xoffscreen_flag[v10] = 1;
      spr_decrementing_table1fe2[v10] = 4;
      j = v14 + 1;
      k = R2_ + 1;
    }
  }
}

uint8 FindFreeNormalSpriteSlot_LowPriority() {  // 02a9de
  R14_ = 2;
  return FindFreeNormalSpriteSlot_02A9E6();
}

uint8 FindFreeNormalSpriteSlot_HighPriority() {  // 02a9e4
  R14_ = 0;
  return FindFreeNormalSpriteSlot_02A9E6();
}

uint8 FindFreeNormalSpriteSlot_02A9E6() {  // 02a9ef
  R15_ = kParseLevelSpriteList_SpriteSlotStart[sprites_sprite_memory_setting];
  uint8 result = kParseLevelSpriteList_SpriteSlotMax[sprites_sprite_memory_setting] - R14_;
  while (spr_current_status[result]) {
    if (--result == R15_)
      return -1;
  }
  return result;
}

void Spr0E1_LoadBooCeiling(uint8 k, uint8 a) {  // 02aac0
  flag_run_cluster_sprites = 1;
  switch (a) {
  case 0xE4:
    for (uint8 i = 14; (i & 0x80) == 0; --i) {
      cluster_spr_table1e66[i] = 0;
      cluster_spr_table0f86[i] = 0;
      cluster_spr_spriteid[i] = 8;
      uint8 r = GetRand();
      SetHiLo(&cluster_spr_xpos_hi[i], &cluster_spr_xpos_lo[i], mirror_current_layer1_xpos + r);
      cluster_spr_table0f4a[i] = cluster_spr_xpos_lo[i];
      uint8 *v14 = IndirPtr(&ptr_sprite_list_data, R3_);
      cluster_spr_ypos_lo[i] = *v14 & 0xF0;
      cluster_spr_ypos_hi[i] = *v14 & 1;
    }
    break;
  case 0xE6:
    spr_current_status[3] = 7;
    for (uint8 j = 3; (j & 0x80) == 0; --j) {
      cluster_spr_spriteid[j] = 5;
      cluster_spr_xpos_lo[j] = kSpr0E6_LoadCandleFlames_xlo[j];
      cluster_spr_ypos_lo[j] = -16;
      cluster_spr_table0f4a[j] = 4 * j;
    }
    break;
  case 0xE5:
    sprites_disappearing_boo_frame_counter = 0;
    for (uint8 m = 19; (m & 0x80) == 0; --m) {
      cluster_spr_spriteid[m] = 7;
      uint8 v20 = kSpr0E5_LoadReappearingBoo_DATA_02AA0B[m];
      cluster_spr_table1e66[m] = v20 & 0xF0;
      cluster_spr_table1e52[m] = 16 * v20;
      uint8 v21 = kSpr0E5_LoadReappearingBoo_DATA_02AA1F[m];
      cluster_spr_table1e8e[m] = v21 & 0xF0;
      cluster_spr_table1e7a[m] = 16 * v21;
    }
    break;
  default:
    if (a >= 0xE2) {
      if (cluster_spr04_boo_ring_index < 2) {
        uint8 v7 = 1;
        if (a != 0xE2)
          v7 = -1;
        R15_ = v7;
        R14_ = 9;
        for (uint8 n = 19; (n & 0x80) == 0; --n) {
          if (!cluster_spr_spriteid[n]) {
            cluster_spr_spriteid[n] = 4;
            cluster_spr_table0f86[n] = cluster_spr04_boo_ring_index;
            cluster_spr_table0f72[n] = R14_;
            uint8 v9 = R15_;
            cluster_spr_table0f4a[n] = R15_;
            R15_ = 0;
            if (v9) {
              uint8 *v10 = IndirPtr(&ptr_sprite_list_data, R3_);
              uint8 v11 = cluster_spr04_boo_ring_index;
              uint8 v18 = *v10;
              *(&cluster_spr04_boo_ring1_center_ypos_lo + cluster_spr04_boo_ring_index) = v18 & 0xF0;
              *(&cluster_spr04_boo_ring1_center_ypos_hi + cluster_spr04_boo_ring_index) = v18 & 1;
              *(&cluster_spr04_boo_ring1_center_xpos_lo + v11) = R0_;
              *(&cluster_spr04_boo_ring1_center_xpos_hi + v11) = R1_;
              *(&cluster_spr04_boo_ring1_offscreen_flag + v11) = 0;
              *(&cluster_spr04_boo_ring_unused_ring1_level_list_index + v11) = R2_;
            }
            if ((--R14_ & 0x80) != 0)
              break;
          }
        }
        ++cluster_spr04_boo_ring_index;
      }
    } else {
      for (uint8 ii = 19; (ii & 0x80) == 0; --ii) {
        cluster_spr_table1e66[ii] = 0;
        cluster_spr_table0f86[ii] = 0;
        cluster_spr_spriteid[ii] = 3;
        uint8 r = GetRand();
        SetHiLo(&cluster_spr_xpos_hi[ii], &cluster_spr_xpos_lo[ii], mirror_current_layer1_xpos + r);
        cluster_spr_table0f4a[ii] = cluster_spr_xpos_lo[ii];
        uint8 v6 = (misc_random_byte2 & 0x3F) + 8;
        SetHiLo(&cluster_spr_ypos_hi[ii], &cluster_spr_ypos_lo[ii], mirror_current_layer1_ypos + v6);
      }
      ++cluster_spr04_boo_ring_index;
    }
    break;
  }
}

void SprXXX_LoadShooter(uint8 k, uint8 j, uint8 a) {  // 02ab78
  R2_ = k;
  R3_ = j - 1;
  R4_ = a;
  uint8 v3 = 7;
  while (shooter_spr_spriteid[v3]) {
    if ((--v3 & 0x80) != 0) {
      if ((--shooter_spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
        shooter_spr_slot_to_overwrite_when_slots_full = 7;
      v3 = shooter_spr_slot_to_overwrite_when_slots_full;
      sprites_load_status[shooter_spr_unused_level_list_index[shooter_spr_slot_to_overwrite_when_slots_full]] = 0;
      break;
    }
  }
  uint8 v4 = R3_;
  shooter_spr_spriteid[v3] = R4_ + 56;
  if (misc_level_layout_flags & 1) {
    uint8 *v5 = IndirPtr(&ptr_sprite_list_data, v4);
    uint8 v7 = *v5;
    shooter_spr_xpos_lo[v3] = *v5 & 0xF0;
    shooter_spr_xpos_hi[v3] = v7 & 1;
    shooter_spr_ypos_lo[v3] = R0_;
    shooter_spr_ypos_hi[v3] = R1_;
  } else {
    uint8 *v6 = IndirPtr(&ptr_sprite_list_data, v4);
    uint8 v8 = *v6;
    shooter_spr_ypos_lo[v3] = *v6 & 0xF0;
    shooter_spr_ypos_hi[v3] = v8 & 1;
    shooter_spr_xpos_lo[v3] = R0_;
    shooter_spr_xpos_hi[v3] = R1_;
  }
  shooter_spr_unused_level_list_index[v3] = R2_;
  shooter_spr_shoot_timer[v3] = 16;
  ParseLevelSpriteList_LoadSpriteLoopStrt(R2_ + 1, v4 + 3);
}

void InitializeAllSpritesOnLevelLoad() {  // 02abf2
  for (int8 i = 63; i >= 0; --i)
    sprites_load_status[(uint8)i] = 0;
  R0_ = -1;
  for (uint8 j = 11; (j & 0x80) == 0; --j) {
    spr_load_status_table_index[j] = -1;
    if (spr_current_status[j] == 11)
      R0_ = j;
    else
      spr_current_status[j] = 0;
  }
  uint8 v2 = R0_;
  if ((R0_ & 0x80) == 0) {
    spr_current_status[R0_] = 0;
    spr_current_status[0] = 11;
    spr_spriteid[0] = spr_spriteid[v2];
    SetSprXPos(0, GetSprXPos(v2));
    SetSprYPos(0, GetSprYPos(v2));
    uint8 v4 = spr_table15f6[v2];
    InitializeNormalSpriteRAMTables(0);
    spr_table15f6[0] = v4;
  }
  for (int16 k = 634; k >= 0; --k)
    *(&blocks_currently_processed_map16_tile_lo + (uint16)k) = 0;
  l1_l2_scroll_spr_spriteid[0] = 0;
  l1_l2_scroll_spr_spriteid[1] = 0;
}

void LoadSpritesOnLevelLoad() {  // 02ac5c
  if (misc_level_layout_flags & 1) {
    uint8 v5 = camera_layer1_scrolling_direction;
    camera_layer1_scrolling_direction = 1;
    uint16 old_y = mirror_current_layer1_ypos;
    mirror_current_layer1_ypos -= 96;
    misc_scratch7e18b6 = 0;
    do {
      ParseLevelSpriteList_Entry2();
      ParseLevelSpriteList_Entry2();
      mirror_current_layer1_ypos += 16;
    } while (++misc_scratch7e18b6 < 0x20);
    mirror_current_layer1_ypos = old_y;
    camera_layer1_scrolling_direction = v5;
  } else {
    uint8 v6 = camera_layer1_scrolling_direction;
    camera_layer1_scrolling_direction = 1;
    uint16 old_x = mirror_current_layer1_xpos;
    mirror_current_layer1_xpos -= 96;
    misc_scratch7e18b6 = 0;
    do {
      ParseLevelSpriteList_Entry2();
      ParseLevelSpriteList_Entry2();
      mirror_current_layer1_xpos += 16;
    } while (++misc_scratch7e18b6 < 0x20);
    mirror_current_layer1_xpos = old_x;
    camera_layer1_scrolling_direction = v6;
  }
}

void GivePoints_Entry2(uint8 j, uint8 a) {  // 02ace1
  GivePoints_02ACEF(j, a + 5);
}

void GivePoints(uint8 k, uint8 a) {  // 02ace5
  GivePoints_02ACEF(k, a + 5);
}

void GivePoints_02ACEF(uint8 k, uint8 a) {  // 02acef
  uint8 v2 = CheckAvailableScoreSpriteSlot();
  score_spr_spriteid[v2] = a;
  uint16 ypos = GetSprYPos(k) - 8;
  SetHiLo(&score_spr_ypos_hi[v2], &score_spr_ypos_lo[v2], ypos);
  if ((uint8)(ypos - mirror_current_layer1_ypos) >= 0xF0)
    SetHiLo(&score_spr_ypos_hi[v2], &score_spr_ypos_lo[v2], PAIR16(score_spr_ypos_hi[v2], score_spr_ypos_lo[v2]) + 16);
  SetHiLo(&score_spr_xpos_hi[v2], &score_spr_xpos_lo[v2], GetSprXPos(k));
  score_spr_yspeed[v2] = 48;
}

uint8 CheckAvailableScoreSpriteSlot() {  // 02ad34
  uint8 result = 5;
  while (score_spr_spriteid[result]) {
    if ((--result & 0x80) != 0) {
      if ((--score_spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
        score_spr_slot_to_overwrite_when_slots_full = 5;
      return score_spr_slot_to_overwrite_when_slots_full;
    }
  }
  return result;
}

void ProcessScoreSprites() {  // 02ada4
  if ((misc_nmito_use_flag & 0x40) != 0) {
    if (misc_nmito_use_flag == 0xC1)
      return;
    OamEnt *oam = get_OamEnt(oam_buf, 0);
    oam[1].ypos = -16;
    oam[2].ypos = -16;
  }
  for (uint8 i = 5; (i & 0x80) == 0; --i) {
    spr_current_slotid = i;
    if (score_spr_spriteid[i])
      ProcessScoreSprites_Sub(i);
  }
}

void ProcessScoreSprites_Sub(uint8 k) {  // 02adc9
  if (!flag_sprites_locked) {
    uint8 v1 = score_spr_yspeed[k];
    if (!v1) {
      score_spr_spriteid[k] = 0;
      return;
    }
    --score_spr_yspeed[k];
    if (v1 != 42)
      goto LABEL_11;
    uint8 v2 = score_spr_spriteid[k];
    if (v2 >= 0xD) {
      if (v2 < 0x11) {
        misc_1up_handler += kProcessScoreSprites_CoinsToGive[v2 - 17];
        timer_give1up = 0;
LABEL_10:
LABEL_11:
        if ((kProcessScoreSprites_UpdateSpeedFrameIndex[score_spr_yspeed[k] >> 4] & counter_global_frames) == 0) {
          uint8 v9 = score_spr_ypos_lo[k];
          if ((uint8)(v9 - mirror_current_layer1_ypos) >= 4) {
            --score_spr_ypos_lo[k];
            if (!v9)
              --score_spr_ypos_hi[k];
          }
        }
        goto LABEL_15;
      }
      GiveCoins_MultipleCoins(kProcessScoreSprites_CoinsToGive[v2 - 17]);
    }
    uint8 v3 = 3 * player_current_character;
    uint32 t = *(&player_mario_score_hi + v3) << 16 | *(&player_mario_score_mid + v3) << 8 | *(&player_mario_score_lo + v3);
    t += PAIR16(kProcessScoreSprites_PointMultiplierHi[v2], kProcessScoreSprites_PointMultiplierLo[v2]);
    *(&player_mario_score_hi + v3) = t >> 16;
    *(&player_mario_score_mid + v3) = t >> 8;
    *(&player_mario_score_lo + v3) = t;
    goto LABEL_10;
  }
LABEL_15:;
  uint8 v10 = 4 * score_spr_layer_index[k];
  R2_W = *(uint16 *)((char *)&mirror_current_layer1_ypos + v10);
  R4_W = *(uint16 *)((char *)&mirror_current_layer1_xpos + v10);
  uint16 xpos = PAIR16(score_spr_xpos_hi[k], score_spr_xpos_lo[k]) - R4_W;
  uint16 ypos = PAIR16(score_spr_ypos_hi[k], score_spr_ypos_lo[k]) - R2_W;
  if (!((uint16)(xpos + 12) >> 8) && !(xpos >> 8) && !(ypos >> 8)) {
    uint8 v11 = kProcessScoreSprites_OAMIndex[k];
    if ((misc_nmito_use_flag & 0x40) != 0)
      v11 = 4;
    int8 v12 = score_spr_ypos_lo[k] - R2_;
    OamEnt *oam = get_OamEnt(oam_buf, v11);
    oam->ypos = v12;
    oam[1].ypos = v12;
    int8 v14 = score_spr_xpos_lo[k] - R4_;
    oam->xpos = v14;
    oam[1].xpos = v14 + 8;
    uint8 v23 = k;
    uint8 v15 = score_spr_spriteid[k];
    oam->charnum = kProcessScoreSprites_LeftTiles[v15];
    oam[1].charnum = kProcessScoreSprites_RightTiles[v15];
    uint8 v16 = v23;
    uint8 v24 = v11;
    uint8 v17 = score_spr_spriteid[v16];
    uint8 v18 = 8;
    if (v17 >= 0xE)
      v18 = kProcessScoreSprites_TwoUp3UpProp[v17 - 14];
    int8 v19 = v18 | 0x30;
    OamEnt *v20 = get_OamEnt(oam_buf, v24);
    v20->flags = v19;
    v20[1].flags = v19;
    uint8 v21 = v24 >> 2;
    sprites_oamtile_size_buffer[v21] = 0;
    sprites_oamtile_size_buffer[v21 + 1] = 0;
    if (score_spr_spriteid[v16] >= 0x11) {
      OamEnt *v22 = get_OamEnt(oam_buf, 0x4C);
      v22->xpos = score_spr_xpos_lo[v16] - R4_ - 8;
      v22->ypos = score_spr_ypos_lo[v16] - R2_;
      v22->charnum = 95;
      v22->flags = 52;
      sprites_oamtile_size_buffer[19] = 0;
    }
  }
}

void Spr0E0_Load3Platforms() {  // 02af33
  uint8 v3 = *IndirPtr(&ptr_sprite_list_data, R3_);
  R8_ = v3 & 0xF0;
  R9_ = v3 & 1;
  R4_ = 2;
  do {
    uint8 j = FindFreeNormalSpriteSlot_HighPriority();
    if ((j & 0x80) != 0)
      break;
    uint8 v1 = j;
    spr_current_status[j] = 1;
    spr_spriteid[j] = -93;
    InitializeNormalSpriteRAMTables(j);
    SetSprXYPos(j, R0_W, R8_W);
    uint8 v2 = R4_;
    spr_table1602[v1] = kSpr0E0_Load3Platforms_InitialAngleLo[R4_];
    spr_table151c[v1] = kSpr0E0_Load3Platforms_InitialAngleHi[v2];
    if (v2 == 2)
      spr_load_status_table_index[v1] = R2_;
  } while ((--R4_ & 0x80) == 0);
}

void Spr0DE_Load5Eeries(uint8 k) {  // 02af9d
  uint8 v5 = *IndirPtr(&ptr_sprite_list_data, R3_);
  R8_ = v5 & 0xF0;
  R9_ = v5 & 1;
  R4_ = 4;
  do {
    uint8 j = FindFreeNormalSpriteSlot_HighPriority();
    if ((j & 0x80) != 0)
      break;
    uint8 v3 = R4_;
    spr_current_status[j] = 8;
    spr_spriteid[j] = 57;
    InitializeNormalSpriteRAMTables(j);
    SetSprXYPos(j, PAIR16(kSpr0DE_Load5Eeries_xhi[v3], kSpr0DE_Load5Eeries_xlo[v3]) + R0_W, R8_W);
    spr_yspeed[j] = kSpr0DE_Load5Eeries_InitialYSpeed[v3];
    spr_table00c2[j] = kSpr0DE_Load5Eeries_InitialVerticalDirection[v3];
    if (v3 == 4)
      spr_load_status_table_index[j] = R2_;
    spr_xspeed[j] = kSpr0DE_Load5Eeries_InitialXSpeed[CheckPlayerPositionRelativeToSprite_Bank23_X(j)];
  } while ((--R4_ & 0x80) == 0);
}

void ProcessGeneratorSprite() {  // 02affe
  if (gen_spr_spriteid) {
    if (!flag_sprites_locked)
      kUnk_2b00c[(uint8)(gen_spr_spriteid - 1)]();
  }
}

void GenSpr08_TurnOffRespawningSprite() {  // 02b02b
  ++timer_disappearing_sprite;
  timer_respawn_sprite = 0;
}

void GenSpr0F_TurnOffGenerator() {  // 02b032
  gen_spr_spriteid = 0;
}

void GenSpr0E_GenerateFire() {  // 02b036
  if ((counter_local_frames & 0x7F) == 0) {
    uint8 j = FindFreeNormalSpriteSlot_LowPriority();
    if ((j & 0x80) == 0) {
      io_sound_ch3 = 23;
      spr_current_status[j] = 8;
      spr_spriteid[j] = -77;
      InitializeNormalSpriteRAMTables(j);
      uint8 r = GetRand();
      SetSprYPos(j, (mirror_current_layer1_ypos + (r & 0x7F) + 32) & ~0xf);
      SetSprXPos(j, mirror_current_layer1_xpos + 255);
      ++spr_table157c[j];
    }
  }
}

void GenSpr0B_GenerateBullet() {  // 02b07c
  if ((counter_local_frames & 0x7F) == 0) {
    uint8 j = FindFreeNormalSpriteSlot_LowPriority();
    if ((j & 0x80) == 0) {
      io_sound_ch3 = 9;
      spr_current_status[j] = 8;
      spr_spriteid[j] = 28;
      InitializeNormalSpriteRAMTables(j);
      uint8 r = GetRand();
      SetSprYPos(j, (mirror_current_layer1_ypos + (r & 0x7F) + 32) & ~0xf);
      SetSprXPos(j, mirror_current_layer1_xpos + PAIR16(kGenSpr09_GenerateSuperKoopa_InitialXHi[r & 1], kGenSpr09_GenerateSuperKoopa_InitialXLo[r & 1]));
      spr_table00c2[j] = r & 1;
    }
  }
}

void GenSpr0D_GenerateDiagnalBullets() {  // 02b0cd
  if (!(counter_local_frames & 1)) {
    uint8 v0 = sprites_special_bullet_generator_timer++;
    if (v0 == 0xA0) {
      sprites_special_bullet_generator_timer = 0;
      io_sound_ch3 = 9;
      int8 v1 = kGenSpr0C_GenerateSurroundingBullets_DATA_02B0CB[gen_spr_spriteid - 12];
      R13_ = kGenSpr0C_GenerateSurroundingBullets_DATA_02B0C9[gen_spr_spriteid - 12];
      do {
        GenSpr0C_GenerateSurroundingBullets();
        --R13_;
        --v1;
      } while (v1 >= 0);
    }
  }
}

void GenSpr0C_GenerateSurroundingBullets() {  // 02b115
  uint8 j = FindFreeNormalSpriteSlot_LowPriority();
  if ((j & 0x80) == 0) {
    spr_spriteid[j] = 28;
    spr_current_status[j] = 8;
    InitializeNormalSpriteRAMTables(j);
    SetSprXPos(j, mirror_current_layer1_xpos + kGenSpr0C_GenerateSurroundingBullets_InitialXLo[R13_]);
    SetSprYPos(j, mirror_current_layer1_ypos + kGenSpr0C_GenerateSurroundingBullets_InitialYLo[R13_]);
    spr_table00c2[j] = kGenSpr0C_GenerateSurroundingBullets_InitialFiringDirection[R13_];
  }
}

void GenSpr07_GenerateFish() {  // 02b15b
  if ((counter_local_frames & 0x1F) == 0) {
    uint8 j = FindFreeNormalSpriteSlot_LowPriority();
    if ((j & 0x80) == 0) {
      spr_current_status[j] = 8;
      spr_spriteid[j] = 23;
      InitializeNormalSpriteRAMTables(j);
      SetSprYPos(j, mirror_current_layer1_ypos + 192);
      uint8 t = GetRand();
      uint8 v2 = kGenSpr07_GenerateFish_DATA_02B153[t & 3];
      if (t & 0x80)
        v2 = ~v2;
      SetSprXPos(j, mirror_current_layer1_xpos + v2);
      uint8 v3 = kGenSpr07_GenerateFish_DATA_02B157[misc_random_byte2 & 3];
      if (t & 0x80)
        v3 = -v3;
      spr_xspeed[j] = v3;
      spr_yspeed[j] = -72;
    }
  }
}

void GenSpr09_GenerateSuperKoopa() {  // 02b1bc
  if ((counter_local_frames & 0x3F) == 0) {
    uint8 j = FindFreeNormalSpriteSlot_LowPriority();
    if ((j & 0x80) == 0) {
      spr_current_status[j] = 8;
      spr_spriteid[j] = 113;
      InitializeNormalSpriteRAMTables(j);
      uint8 r = GetRand();
      uint8 v1 = (r & 0x3F) + 32;
      SetSprYPos(j, mirror_current_layer1_ypos + v1);
      spr_yspeed[j] = 40;
      SetSprXPos(j, mirror_current_layer1_xpos + PAIR16(kGenSpr09_GenerateSuperKoopa_InitialXHi[r & 1], kGenSpr09_GenerateSuperKoopa_InitialXLo[r & 1]));
      spr_table157c[j] = r & 1;
    }
  }
}

void GenSpr0A_GenerateBubbles() {  // 02b207
  if ((counter_local_frames & 0x7F) == 0) {
    uint8 j = FindFreeNormalSpriteSlot_LowPriority();
    if ((j & 0x80) == 0) {
      spr_current_status[j] = 8;
      spr_spriteid[j] = -99;
      InitializeNormalSpriteRAMTables(j);
      uint8 r = GetRand();
      uint8 v1 = (r & 0x3F) + 32;
      SetSprYPos(j, mirror_current_layer1_ypos + v1);
      SetSprXPos(j, mirror_current_layer1_xpos + PAIR16(kGenSpr09_GenerateSuperKoopa_InitialXHi[r & 1], kGenSpr09_GenerateSuperKoopa_InitialXLo[r & 1]));
      spr_table157c[j] = r & 1;
      spr_table00c2[j] = kGenSpr0A_GenerateBubbles_DATA_02B25A[GetRand() & 3];
    }
  }
}

void GenSprXX_GenerateDolphins() {  // 02b26c
  if ((counter_local_frames & 0x1F) == 0) {
    uint8 v5 = gen_spr_spriteid;
    uint8 j = kGenSprXX_GenerateDolphins_InitialYSpeed[v5 - 1];
    R0_ = kGenSprXX_GenerateDolphins_InitialYSpeed[v5 + 1];
    while (spr_current_status[j]) {
      if (--j == R0_)
        return;
    }
    spr_current_status[j] = 8;
    spr_spriteid[j] = 65;
    InitializeNormalSpriteRAMTables(j);
    uint8 v1 = (GetRand() & 0x7F) + 64;
    SetSprYPos(j, mirror_current_layer1_ypos + v1);
    spr_yspeed[j] = kGenSprXX_GenerateDolphins_InitialYSpeed[GetRand() & 3];
    SetSprXPos(j, mirror_current_layer1_xpos + PAIR16(kGenSpr0A_GenerateBubbles_DATA_02B25A[v5 + 1], kGenSpr0A_GenerateBubbles_DATA_02B25A[v5 - 1]));
    spr_xspeed[j] = kGenSprXX_GenerateDolphins_InitialXLo[v5 - 1];
    ++spr_table151c[j];
  }
}

void GenSpr01_GenerateEerie() {  // 02b2d6
  if ((counter_local_frames & 0x3F) == 0) {
    uint8 j = FindFreeNormalSpriteSlot_LowPriority();
    if ((j & 0x80) == 0) {
      spr_current_status[j] = 8;
      spr_spriteid[j] = 56;
      InitializeNormalSpriteRAMTables(j);
      uint8 v1 = (GetRand() & 0x7F) + 64;
      SetSprYPos(j, mirror_current_layer1_ypos + v1);
      uint8 v6 = misc_random_byte2 & 1;
      SetSprXPos(j, mirror_current_layer1_xpos + PAIR16(kGenSpr01_GenerateEerie_InitialXHi[v6], kGenSpr01_GenerateEerie_InitialXLo[v6]));
      spr_xspeed[j] = kGenSpr01_GenerateEerie_InitialXSpeed[v6];
    }
  }
}

void GenSpr02_GenParachuteEnemy() {  // 02b329
  if ((counter_local_frames & 0x7F) == 0) {
    uint8 j = FindFreeNormalSpriteSlot_LowPriority();
    if ((j & 0x80) == 0) {
      spr_current_status[j] = 8;
      uint8 r = GetRand();
      uint8 v3 = gen_spr_spriteid;
      if (r & 1)
        v3 += 3;
      spr_spriteid[j] = kGenSprXX_GenerateParachuteEnemies_SpriteToSpawn[v3 - 2];
      InitializeNormalSpriteRAMTables(j);
      SetSprYPos(j, mirror_current_layer1_ypos - 32);
      SetSprXPos(j, mirror_current_layer1_xpos + misc_random_byte1 + 48);
      uint8 t = spr_xpos_lo[j];
      spr_table1570[j] = t & 0xe;
      spr_xspeed[j] = kGenSprXX_GenerateParachuteEnemies_InitialXSpeed[(t >> 1) & 3];
    }
  }
}

void ProcessShooterSprites() {  // 02b387
  if (!flag_sprites_locked) {
    for (uint8 i = 7; (i & 0x80) == 0; --i) {
      spr_current_slotid = i;
      uint8 v1 = shooter_spr_spriteid[i];
      if (v1) {
        if (shooter_spr_shoot_timer[i]) {
          uint8 a = shooter_spr_spriteid[i];
          if (counter_global_frames & 1)
            --shooter_spr_shoot_timer[i];
          v1 = a;
        }
        ProcessShooterSprites_02B3AB(i, v1);
      }
    }
  }
}

void ProcessShooterSprites_Return02B3AA(uint8 k) {  // 02b3aa
  ;
}

void ProcessShooterSprites_02B3AB(uint8 k, uint8 a) {  // 02b3ab
  kProcessShooterSprites_ShooterSprPtrs[(uint8)(a - 1)](k);
}

void ShooterSpr02_TorpedoShooter(uint8 k) {  // 02b3b6
  if (!shooter_spr_shoot_timer[k]) {
    shooter_spr_shoot_timer[k] = 80;
    if (shooter_spr_ypos_hi[k] ==
            (uint8)((shooter_spr_ypos_lo[k] < (uint8)mirror_current_layer1_ypos) + HIBYTE(mirror_current_layer1_ypos)) &&
        shooter_spr_xpos_hi[k] ==
            (uint8)((shooter_spr_xpos_lo[k] < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)) &&
        (uint8)(shooter_spr_xpos_lo[k] - mirror_current_layer1_xpos + 16) >= 0x20) {
      uint8 j = FindFreeNormalSpriteSlot_LowPriority();
      if ((j & 0x80) == 0) {
        spr_current_status[j] = 8;
        spr_spriteid[j] = 68;
        SetSprXPos(j, PAIR16(shooter_spr_xpos_hi[k], shooter_spr_xpos_lo[k]));
        SetSprYPos(j, PAIR16(shooter_spr_ypos_hi[k], shooter_spr_ypos_lo[k]));
        uint8 v2 = j;
        InitializeNormalSpriteRAMTables(j);
        uint8 v3 = CheckPlayerPositionRelativeToSprite_Bank23_X(j);
        spr_table157c[v2] = v3;
        R0_ = v3;
        spr_decrementing_table1540[v2] = 48;
        uint8 v4 = 7;
        while (ext_spr_spriteid[v4]) {
          if ((--v4 & 0x80) != 0)
            return;
        }
        ext_spr_spriteid[v4] = 8;
        SetHiLo(&ext_spr_xpos_hi[v4], &ext_spr_xpos_lo[v4], PAIR16(shooter_spr_xpos_hi[k], shooter_spr_xpos_lo[k]) + 8);
        SetHiLo(&ext_spr_ypos_hi[v4], &ext_spr_ypos_lo[v4], PAIR16(shooter_spr_ypos_hi[k], shooter_spr_ypos_lo[k]) - 9);
        ext_spr_decrementing_table176f[v4] = -112;
        ext_spr_xspeed[v4] = kShooterSpr02_TorpedoShooter_InitialXSpeed[R0_];
      }
    }
  }
}

void ShooterSpr01_BulletBillShooter(uint8 k) {  // 02b466
  if (!shooter_spr_shoot_timer[k]) {
    shooter_spr_shoot_timer[k] = 96;
    if (shooter_spr_ypos_hi[k] ==
            (uint8)((shooter_spr_ypos_lo[k] < (uint8)mirror_current_layer1_ypos) + HIBYTE(mirror_current_layer1_ypos)) &&
        shooter_spr_xpos_hi[k] ==
            (uint8)((shooter_spr_xpos_lo[k] < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)) &&
        (uint8)(shooter_spr_xpos_lo[k] - mirror_current_layer1_xpos + 0x10) >= 0x10 &&
        (uint8)(player_xpos - shooter_spr_xpos_lo[k] + 0x11) >= 0x22) {
      uint8 j = FindFreeNormalSpriteSlot_LowPriority();
      if ((j & 0x80) == 0) {
        io_sound_ch3 = 9;
        spr_current_status[j] = 1;
        spr_spriteid[j] = 28;
        SetSprXPos(j, PAIR16(shooter_spr_xpos_hi[k], shooter_spr_xpos_lo[k]));
        SetSprYPos(j, PAIR16(shooter_spr_ypos_hi[k], shooter_spr_ypos_lo[k]) - 1);
        InitializeNormalSpriteRAMTables(j);
        ShooterSpr01_BulletBillShooter_ShowShooterSmoke(k);
      }
    }
  }
}

void ShooterSpr01_BulletBillShooter_ShowShooterSmoke(uint8 k) {  // 02b4de
  uint8 v1 = 3;
  while (smoke_spr_spriteid[v1]) {
    if ((--v1 & 0x80) != 0)
      return;
  }
  smoke_spr_spriteid[v1] = 1;
  smoke_spr_ypos_lo[v1] = shooter_spr_ypos_lo[k];
  smoke_spr_timer[v1] = 27;
  smoke_spr_xpos_lo[v1] =
      kShooterSpr01_BulletBillShooter_ShooterSmokeDispX[HIBYTE(player_xpos) >= ((uint8)player_xpos < shooter_spr_xpos_lo[k]) + shooter_spr_xpos_hi[k]] +
      shooter_spr_xpos_lo[k];
}

void UpdateBounceSpritePosition_X(uint8 k) {  // 02b51a
  UpdateBounceSpritePosition_Y(k + 4);
}

void UpdateBounceSpritePosition_Y(uint8 k) {  // 02b526
  uint16 t = bounce_spr_sub_ypos[k] + (uint8)(16 * bounce_spr_yspeed[k]);
  bounce_spr_sub_ypos[k] = t;
  AddHiLo(&bounce_spr_ypos_hi[k], &bounce_spr_ypos_lo[k], ((int8)bounce_spr_yspeed[k] >> 4) + (t >> 8));
}

void UpdateExtendedSpritePosition_X(uint8 k) {  // 02b554
  UpdateExtendedSpritePosition_Y(k + 10);
}

void UpdateExtendedSpritePosition_Y(uint8 k) {  // 02b560
  uint16 t = ext_spr_sub_ypos[k] + (uint8)(16 * ext_spr_yspeed[k]);
  ext_spr_sub_ypos[k] = t;
  AddHiLo(&ext_spr_ypos_hi[k], &ext_spr_ypos_lo[k], ((int8)ext_spr_yspeed[k] >> 4) + (t >> 8));
}

void ProcessSpinningCoinSprites_UpdateSpinningCoinSpriteYPosition(uint8 k) {  // 02b58e
  uint16 t = block_coin_spr_sub_ypos[k] + (uint8)(16 * block_coin_spr_yspeed[k]);
  block_coin_spr_sub_ypos[k] = t;
  AddHiLo(&block_coin_spr_ypos_hi[k], &block_coin_spr_ypos_lo[k], ((int8)block_coin_spr_yspeed[k] >> 4) + (t >> 8));
}

void UpdateMinorExtendedSpritePosition_X(uint8 k) {  // 02b5bc
  UpdateMinorExtendedSpritePosition_Y(k + 12);
}

void UpdateMinorExtendedSpritePosition_Y(uint8 k) {  // 02b5c8
  uint16 t = mextspr_sub_ypos[k] + (uint8)(16 * mextspr_yspeed[k]);
  mextspr_sub_ypos[k] = t;
  mextspr_ypos_lo[k] += ((int8)mextspr_yspeed[k] >> 4) + (t >> 8);
}

void Spr070_Pokey(uint8 k) {  // 02b636
  Spr070_Pokey_Sub(k);
  uint8 v1 = spr_table00c2[k];
  int8 v2 = 4;
  uint8 v3 = 0;
  do {
    int8 v4 = v1 & 1;
    v1 >>= 1;
    if (v4)
      ++v3;
    --v2;
  } while (v2 >= 0);
  spr_property_bits1662[k] = kSpr070_Pokey_PokeyClipIndex[v3];
}

void Spr070_Pokey_Sub(uint8 k) {  // 02b672
  if (spr_table1534[k]) {
    GenericGFXRtDraw1Tile16x16(k);
    int8 v1 = -118;
    if (spr_table00c2[k])
      v1 = -24;
    get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = v1;
    if (spr_current_status[k] == 8) {
      UpdateNormalSpritePosition_Y(k);
      spr_yspeed[k] += 2;
      SubOffscreen_Bank02_Entry1(k);
    }
  } else {
    if (spr_current_status[k] == 8) {
      uint8 v2 = spr_table00c2[k];
      if (!v2 || v2 >= 0x20) {
        spr_current_status[k] = 0;
        return;
      }
      if (!flag_sprites_locked) {
        SubOffscreen_Bank02_Entry1(k);
        CheckPlayerToNormalSpriteCollision(k);
        if ((++spr_table1570[k] & 0x7F) == 0)
          spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
        spr_xspeed[k] = kSpr070_Pokey_XSpeed[spr_table157c[k]];
        UpdateNormalSpritePosition_X(k);
        UpdateNormalSpritePosition_Y(k);
        if (sign8(spr_yspeed[k] - 64))
          spr_yspeed[k] += 2;
        HandleNormalSpriteLevelCollision(k);
        if ((spr_table1588[k] & 4) != 0)
          spr_yspeed[k] = 0;
        if ((spr_table1588[k] & 3) != 0)
          spr_table157c[k] ^= 1;
        Spr070_Pokey_02B7AC(k);
        for (uint8 i = 0; i != 4; ++i) {
          if ((kSpr070_Pokey_DATA_02B653[i] & spr_table00c2[k]) == 0) {
            uint8 kb = spr_table00c2[k];
            R0_ = kSpr070_Pokey_DATA_02B657[i] & kb;
            spr_table00c2[k] = R0_ | kSpr070_Pokey_DATA_02B65B[i] & (kb >> 1);
          }
        }
      }
    }
    if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
      return;
    R1_ += 64;
    R2_ = spr_table00c2[k];
    R7_ = R2_;
    R4_ = spr_table151c[k];
    R3_ = kSpr070_Pokey_DATA_02B665[spr_decrementing_table1540[k]];
    R5_ = 0;
    uint8 v4 = spr_oamindex[k];
    for (int8 j = 4; j >= 0; j--) {
      R6_ = j;
      uint8 v6 = (j + (counter_local_frames >> 3)) & 3;
      if (R7_ == 1)
        v6 = 0;
      OamEnt *oam = get_OamEnt(oam_buf, v4);
      oam[64].xpos = kSpr070_Pokey_XDisp[v6] + R0_;
      uint8 v8 = R6_;
      int8 v9 = R2_ & 1;
      R2_ >>= 1;
      if (v9) {
        v9 = R4_ & 1;
        R4_ >>= 1;
        if (!v9)
          R5_ = R3_;
        oam[64].ypos = R1_ - R5_;
      }
      R1_ -= 16;
      int8 v10 = -24;
      if (!(R2_ & 1))
        v10 = -118;
      oam[64].charnum = v10;
      oam[64].flags = sprites_tile_priority | 5;
      v4 += 4;
    }
    Spr070_Pokey_Bank02SpriteEntry(k, 2, 4);
  }
}

void Spr070_Pokey_Bank02SpriteEntry(uint8 k, uint8 j, uint8 a) {  // 02b7a7
  FinishOAMWrite(k, j, a);
}

void Spr070_Pokey_02B7AC(uint8 k) {  // 02b7ac
  uint8 v1 = 9;
  while (1) {
    if (!((counter_global_frames ^ v1) & 1) && spr_current_status[v1] == 10) {
      StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(v1);
      StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
      if (StandardSpriteToSpriteCollisionChecks_CheckContact())
        break;
    }
    if ((--v1 & 0x80) != 0)
      return;
  }
  if (!spr_decrementing_table1558[k]) {
    uint8 v2 = spr_ypos_lo[v1] - spr_ypos_lo[k];
    sprites_second_tracked_sprite_index = v1;
    Spr070_Pokey_RemovePokeySgmntRt(k, v2);
    Spr070_Pokey_02B82E(k);
  }
}

void Spr070_Pokey_RemovePokeySgmntRt(uint8 k, uint8 a) {  // 02b7ed
  uint8 v2 = 0;
  if (!sign8(a - 9)) {
    v2 = 1;
    if (!sign8(a - 25)) {
      v2 = 2;
      if (!sign8(a - 41)) {
        v2 = 3;
        if (!sign8(a - 57))
          v2 = 4;
      }
    }
  }
  uint8 v3 = kSpr070_Pokey_PokeyUnsetBit[v2] & spr_table00c2[k];
  spr_table00c2[k] = v3;
  spr_table151c[k] = v3;
  R13_ = kSpr070_Pokey_DATA_02B829[v2];
  spr_decrementing_table1540[k] = 12;
  spr_decrementing_table1558[k] = 24;
}

void Spr070_Pokey_RemovePokeySegment(uint8 k, uint8 a) {  // 02b81c
  Spr070_Pokey_RemovePokeySgmntRt(k, a);
}

void Spr070_Pokey_02B82E(uint8 k) {  // 02b82e
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) == 0) {
    spr_current_status[j] = 2;
    spr_spriteid[j] = 112;
    SetSprXPos(j, GetSprXPos(k));
    InitializeNormalSpriteRAMTables(j);
    uint8 v2 = sprites_second_tracked_sprite_index;
    SetSprYPos(j, GetSprYPos(v2));
    spr_xspeed[j] = (int8)spr_xspeed[v2] >> 1;
    spr_yspeed[j] = -32;
    spr_table00c2[j] = R13_ & spr_table00c2[k];
    spr_table1534[j] = 1;
    GivePoints_Entry2(j, 1);
  }
}

void Spr044_TorpedoTed(uint8 k) {  // 02b88a
  uint8 v3 = sprites_tile_priority;
  if (spr_decrementing_table1540[k])
    sprites_tile_priority = 16;
  Spr044_TorpedoTed_Draw(k);
  sprites_tile_priority = v3;
  if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    if (spr_decrementing_table1540[k]) {
      spr_yspeed[k] = 8;
      UpdateNormalSpritePosition_Y(k);
      spr_yspeed[k] = 16;
    } else {
      if ((counter_global_frames & 3) == 0) {
        uint8 v1 = spr_table157c[k];
        uint8 v2 = spr_xspeed[k];
        if (v2 != kSpr044_TorpedoTed_MaxSpeed[v1])
          spr_xspeed[k] = kSpr044_TorpedoTed_Acceleration[v1] + v2;
      }
      UpdateNormalSpritePosition_X(k);
      UpdateNormalSpritePosition_Y(k);
      if (spr_yspeed[k] && (counter_global_frames & 1) == 0)
        --spr_yspeed[k];
      if (((counter_local_frames + k) & 7) == 0)
        Spr044_TorpedoTed_SpawnSmokePuffTrail(k);
    }
  }
}

void Spr044_TorpedoTed_Draw(uint8 k) {  // 02b8f7
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  uint8 v2 = R1_;
  OamEnt *oam = get_OamEnt(oam_buf, drt);
  oam[64].ypos = R1_;
  oam[65].ypos = v2;
  R2_ = sprites_tile_priority | spr_table15f6[k];
  uint8 v4 = spr_table157c[k];
  oam[64].xpos = kSpr044_TorpedoTed_XDisp[v4] + R0_;
  oam[65].xpos = kSpr044_TorpedoTed_XDisp[v4 + 1] + R0_;
  int8 v5 = R2_ | kSpr044_TorpedoTed_Prop[v4];
  oam[64].flags = v5;
  oam[65].flags = v5;
  oam[64].charnum = 0x80;
  int8 v6 = -126;
  if (!spr_decrementing_table1540[k]) {
    v6 = -96;
    if ((counter_local_frames & 2) != 0)
      v6 = -126;
  }
  oam[65].charnum = v6;
  Spr070_Pokey_Bank02SpriteEntry(k, 2, 1);
}

void Spr044_TorpedoTed_SpawnSmokePuffTrail(uint8 k) {  // 02b952
  uint8 j = 3;
  while (smoke_spr_spriteid[j]) {
    if ((--j & 0x80) != 0) {
      if ((--smoke_spr_copy_of_slot_to_overwrite_when_slots_full & 0x80) != 0)
        smoke_spr_copy_of_slot_to_overwrite_when_slots_full = 3;
      j = smoke_spr_copy_of_slot_to_overwrite_when_slots_full;
      break;
    }
  }

  uint8 v2 = spr_table157c[k];
  uint16 t1 = GetSprXPos(k) + PAIR16(kSpr044_TorpedoTed_DATA_02B950[v2], kSpr044_TorpedoTed_DATA_02B94E[v2]);
  uint16 t = t1 - mirror_current_layer1_xpos;
  if (t < 256) {
    smoke_spr_spriteid[j] = 1;
    smoke_spr_xpos_lo[j] = t1;
    smoke_spr_ypos_lo[j] = spr_ypos_lo[k];
    smoke_spr_timer[j] = 15;
  }
}

void UnusedGenTileFromSpr(uint8 k, uint8 a) {  // 02b9a4
  blocks_map16_to_generate = a;
  blocks_xpos = GetSprXPos(k);
  blocks_ypos = GetSprYPos(k);
  GenerateTile();
}

void CheckPlayerToNormalSpriteColl_TurnSpritesIntoSilverCoins() {  // 02b9bd
  counter_current_silver_coins = 2;
  for (uint8 i = 9; (i & 0x80) == 0; --i) {
    if (spr_current_status[i] >= 8 && (spr_property_bits190f[i] & 0x40) == 0)
      CheckPlayerToNormalSpriteColl_02B9D9(i);
  }
}

void CheckPlayerToNormalSpriteColl_02B9D9(uint8 j) {  // 02b9d9
  spr_spriteid[j] = 33;
  spr_current_status[j] = 8;
  InitializeNormalSpriteRAMTables(j);
  spr_table15f6[j] = spr_table15f6[j] & 0xF1 | 2;
  spr_yspeed[j] = -40;
}

void CheckBerryTileCollisionWithYoshiTongue() {  // 02b9fa
  R15_ = 0;
  R4_ = R1_ & 0xF0;
  if (R9_ < 2) {
    R13_ = R9_;
    HIBYTE(yoshi_ypos) = R9_;
    R6_ = R0_;
    if (R8_ < misc_screens_in_lvl) {
      R7_ = R8_;
      R4_ |= R6_ >> 4;
      uint16 vv = PAIR16(kLevelDataLayoutTables_EightBitHi[R8_], kLevelDataLayoutTables_EightBitLo[R8_]);
      if (R15_)
        vv = PAIR16(kLevelDataLayoutTables_EightBitHi_Horizontal_L2[R8_], kLevelDataLayoutTables_EightBitLo_Horizontal_L2[R8_]);
      R5_W = PAIR16(R13_, R4_) + vv;
      R7_ = 126;
      blocks_currently_processed_map16_tile_lo = *IndirPtr(&R5_, 0);
      ++R7_;
      if (!*IndirPtr(&R5_, 0) && blocks_currently_processed_map16_tile_lo >= 0x45 && blocks_currently_processed_map16_tile_lo < 0x48) {
        yoshi_berry_being_eaten = blocks_currently_processed_map16_tile_lo - 68;
        uint8 j = 11;
        while (spr_current_status[j]) {
          if ((--j & 0x80) != 0)
            return;
        }
        spr_current_status[j] = 8;
        spr_spriteid[j] = 116;
        blocks_xpos = PAIR16(R8_, R0_);
        SetSprXPos(j, blocks_xpos);
        blocks_ypos = PAIR16(R9_, R1_);
        SetSprYPos(j, blocks_ypos);
        InitializeNormalSpriteRAMTables(j);
        ++spr_table160e[j];
        spr_property_bits1662[j] = spr_property_bits1662[j] & 0xF0 | 0xC;
        spr_property_bits167a[j] &= ~0x40;
        blocks_map16_to_generate = 4;
        GenerateTile();
      }
    }
  }
}

void Spr035_Yoshi_DrawYoshisWings(uint8 k, uint8 a) {  // 02bb23
  R2_ = a;
  if (!CheckIfNormalSpriteOffScreen(k)) {
    OamEnt *oam = get_OamEnt(oam_buf, 0xF8);
    SetHiLo(&R4_, &R0_, GetSprXPos(k));
    R1_ = spr_ypos_lo[k];
    uint8 v2 = R2_ + 2 * spr_table157c[k];
    uint16 t = PAIR16(R4_, R0_) + PAIR16(kSpr035_Yoshi_DATA_02BB0F[v2], kSpr035_Yoshi_DATA_02BB0B[v2]) - mirror_current_layer1_xpos;
    oam->xpos = t;
    if (t < 256) {
      oam->ypos = kSpr035_Yoshi_DATA_02BB13[v2] + R1_ - mirror_current_layer1_ypos;
      oam->charnum = kSpr035_Yoshi_Tiles[v2];
      oam->flags = kSpr035_Yoshi_Prop[v2] | sprites_tile_priority;
      sprites_oamtile_size_buffer[0xF8 >> 2] = kSpr035_Yoshi_TileSize[v2];
    }
  }
}

void SprXXX_Dolphins(uint8 k) {  // 02bb94
  SprXXX_Dolphins_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry2(k);
    UpdateNormalSpritePosition_Y(k);
    spr_table1528[k] = UpdateNormalSpritePosition_X(k);
    if ((int8)spr_yspeed[k] <= 62)
      ++spr_yspeed[k];
    if ((counter_global_frames ^ k) & 1)
      HandleNormalSpriteLevelCollision(k);
    if ((spr_yspeed[k] & 0x80) != 0 || !spr_table164a[k])
      goto LABEL_15;
    uint8 v1 = spr_yspeed[k];
    if (v1) {
      int8 v2 = v1 - 8;
      spr_yspeed[k] = v2;
      if (v2 < 0)
        spr_yspeed[k] = 0;
    }
    if (!spr_table151c[k]) {
      uint8 v4 = 2 * (spr_spriteid[k] - 65) + (spr_table00c2[k] & 1);
      uint8 v5 = kSprXXX_Dolphins_XAcceleration[v4] + spr_xspeed[k];
      spr_xspeed[k] = v5;
      if (v5 != kSprXXX_Dolphins_MaxXSpeed[v4]) {
LABEL_15:
        SolidSpriteBlock(k);
        return;
      }
      ++spr_table00c2[k];
    }
    spr_yspeed[k] = -64;
    goto LABEL_15;
  }
}

void SprXXX_Dolphins_Draw(uint8 k) {  // 02bc14
  uint8 drt;

  if (spr_spriteid[k] == 67) {
    spr_table157c[k] = (uint8)(counter_local_frames & 4) >> 2;
    GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
  } else {
    if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
      return;
    R2_ = spr_xspeed[k];
    uint8 v2 = R0_;
    bool v3 = __CFSHL__(R2_, 1);
    R2_ *= 2;
    if (v3) {
      OamEnt *oam = get_OamEnt(oam_buf, drt);
      oam[64].xpos = R0_;
      int8 v5 = v2 + 16;
      oam[65].xpos = v5;
      oam[66].xpos = v5 + 8;
    } else {
      int8 v6 = R0_ + 24;
      OamEnt *v7 = get_OamEnt(oam_buf, drt);
      v7[64].xpos = R0_ + 24;
      v6 -= 16;
      v7[65].xpos = v6;
      v7[66].xpos = v6 - 8;
    }
    uint8 v8 = R1_;
    OamEnt *v9 = get_OamEnt(oam_buf, drt);
    v9[64].ypos = R1_;
    v9[65].ypos = v8;
    v9[66].ypos = v8;
    uint8 v10 = (uint8)(counter_local_frames & 8) >> 3;
    v9[64].charnum = kSprXXX_Dolphins_Tiles1[v10];
    v9[65].charnum = kSprXXX_Dolphins_Tiles2[v10];
    v9[66].charnum = kSprXXX_Dolphins_Tiles3[v10];
    int8 v11 = sprites_tile_priority | spr_table15f6[k];
    if (!v3)
      v11 |= 0x40;
    v9[64].flags = v11;
    v9[65].flags = v11;
    v9[66].flags = v11;
    Spr070_Pokey_Bank02SpriteEntry(k, 2, 2);
  }
}

void Spr0A5_Sparky(uint8 k) {  // 02bcdb
  CheckNormalSpriteToNormalSpriteCollision(k);
  if (!(flag_sprites_locked | GetRand()))
    spr_decrementing_table1558[k] = 12;
  if (spr_spriteid[k] == 46) {
    uint8 v1 = spr_table00c2[k];
    bool v2;
    if (spr_decrementing_table1564[k]) {
      v1 += 8;
      v2 = 0;
    } else {
      v2 = (counter_local_frames & 8) != 0;
    }
    spr_table1602[k] = kSprXXX_WallFollowers_SpikeTopAnimationFramesOffset[v1] + v2;
    spr_table15f6[k] = kSprXXX_WallFollowers_SpikeTopDirection[v1] | spr_table15f6[k] & 0x3F;
    GenericGFXRtDraw1Tile16x16(k);
  } else if (spr_spriteid[k] < 0xA5) {
    SprXXX_WallFollowers_UrchinDraw(k);
  } else {
    SprXXX_WallFollowers_SparkyDraw(k);
  }
  if (spr_current_status[k] != 8) {
    spr_table1528[k] = 0;
    spr_decrementing_table1558[k] = -1;
    return;
  }
  if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry4(k);
    CheckPlayerToNormalSpriteCollision(k);
    uint8 v3 = spr_spriteid[k];
    if (v3 == 46) {
      if ((uint8)(spr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xE0)
        spr_current_status[k] = 0;
    } else if (v3 != 60 && v3 != 0xA5 && v3 != 0xA6) {
      if ((spr_table00c2[k] & 1) != 0) {
        if (spr_spriteid[k] != 59 && !spr_decrementing_table1540[k] ||
            (UpdateNormalSpritePosition_X(k), UpdateNormalSpritePosition_Y(k), HandleNormalSpriteLevelCollision(k),
             (spr_table1588[k] & 0xF) != 0)) {
          spr_xspeed[k] = -spr_xspeed[k];
          spr_yspeed[k] = -spr_yspeed[k];
          spr_decrementing_table1540[k] = 64;
          ++spr_table00c2[k];
        }
      } else if (!spr_decrementing_table1540[k]) {
        spr_decrementing_table1540[k] = 0x80;
        ++spr_table00c2[k];
      }
      return;
    }
    if (!spr_decrementing_table1540[k]) {
      uint8 v4 = spr_table00c2[k];
      spr_yspeed[k] = kSprXXX_WallFollowers_DATA_02BCA7[v4];
      spr_xspeed[k] = kSprXXX_WallFollowers_DATA_02BC9F[v4];
      HandleNormalSpriteLevelCollision(k);
      if ((spr_table1588[k] & 0xF) == 0) {
        spr_decrementing_table1564[k] = 8;
        uint8 v5 = 56;
        uint8 v6 = spr_spriteid[k];
        if (v6 != 60) {
          v5 = 26;
          if (v6 == 0xA5)
            v5 = 13;
        }
        spr_decrementing_table1540[k] = v5;
      }
    }
    int8 v7 = 32;
    uint8 v8 = spr_spriteid[k];
    if (v8 != 60) {
      v7 = 16;
      if (v8 == 0xA5)
        v7 = 8;
    }
    if (v7 == spr_decrementing_table1540[k]) {
      uint8 v9 = ++spr_table00c2[k];
      if (v9 == 4)
        spr_table00c2[k] = 0;
      if (v9 == 8)
        spr_table00c2[k] = 4;
    }
    if ((kSprXXX_WallFollowers_DATA_02BCAF[spr_table00c2[k]] & spr_table1588[k]) == 0)
      goto LABEL_49;
    spr_decrementing_table1564[k] = 8;
    int8 v10 = --spr_table00c2[k];
    uint8 v11;
    if (v10 >= 0) {
      if (v10 != 3) {
LABEL_49:;
        uint8 v12 = spr_table00c2[k];
        spr_yspeed[k] = kSprXXX_WallFollowers_YSpeed[v12];
        spr_xspeed[k] = kSprXXX_WallFollowers_XSpeed[v12];
        if (spr_spriteid[k] == 0xA5) {
          spr_xspeed[k] *= 2;
          spr_yspeed[k] *= 2;
        }
        UpdateNormalSpritePosition_X(k);
        UpdateNormalSpritePosition_Y(k);
        return;
      }
      v11 = 7;
    } else {
      v11 = 3;
    }
    spr_table00c2[k] = v11;
    goto LABEL_49;
  }
}

void SprXXX_WallFollowers_SparkyDraw(uint8 k) {  // 02be4e
  uint8 drt;

  if (spr_spriteid[k] == 0xA5) {
    GenericGFXRtDraw1Tile16x16(k);
    uint8 v1 = spr_oamindex[k];
    if (graphics_level_sprite_graphics_setting == 2) {
      bool v2 = (counter_local_frames & 4) != 0;
      OamEnt *oam = get_OamEnt(oam_buf, v1);
      oam[64].charnum = -56;
      oam[64].flags = sprites_tile_priority | kSprXXX_WallFollowers_FuzzyProp[v2];
    } else {
      OamEnt *v4 = get_OamEnt(oam_buf, v1);
      v4[64].charnum = 10;
      v4[64].flags ^= 16 * (counter_local_frames & 0xC);
    }
  } else {
    if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
      return;
    spr_oamindex[k] = drt + 4;
    uint8 v6 = drt + 4;
    R3_ = counter_local_frames & 4;
    uint8 v7 = 3;
    do {
      OamEnt *v8 = get_OamEnt(oam_buf, v6);
      v8[64].xpos = kSprXXX_WallFollowers_HotheadXDisp[v7] + R0_;
      v8[64].ypos = kSprXXX_WallFollowers_HotheadYDisp[v7] + R1_;
      uint8 v15 = v7;
      uint8 v9 = R3_ | v7;
      v8[64].charnum = kSprXXX_WallFollowers_HotheadTiles[v9];
      v8[64].flags = sprites_tile_priority | kSprXXX_WallFollowers_HotheadProp[v9];
      v6 += 4;
      v7 = v15 - 1;
    } while ((int8)v7 >= 0);
    uint8 v10 = k;
    uint8 kb = R0_;
    uint8 v16 = R1_;
    Spr070_Pokey_Bank02SpriteEntry(v10, 2, 3);
    R1_ = v16;
    R0_ = kb;
    uint8 v11 = 9;
    if (spr_decrementing_table1558[v10])
      v11 = 25;
    R2_ = v11;
    uint8 v12 = spr_oamindex[v10] - 4;
    spr_oamindex[v10] = v12;
    uint8 kc = v10;
    uint8 v13 = spr_table00c2[v10];
    OamEnt *v14 = get_OamEnt(oam_buf, v12);
    v14[64].xpos = kSprXXX_WallFollowers_HotheadEyesXDisp[v13] + R0_;
    v14[64].ypos = kSprXXX_WallFollowers_HotheadEyesYDisp[v13] + R1_;
    v14[64].charnum = R2_;
    v14[64].flags = sprites_tile_priority | 5;
    Spr070_Pokey_Bank02SpriteEntry(kc, 0, 0);
  }
}

void SprXXX_WallFollowers_UrchinDraw(uint8 k) {  // 02bf5c
  uint8 drt;

  if (!spr_decrementing_table163e[k]) {
    ++spr_table1528[k];
    spr_decrementing_table163e[k] = 12;
  }
  spr_table1602[k] = kSprXXX_WallFollowers_UrchinAnimationFrames[spr_table1528[k] & 3];
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  R5_ = 0;
  R2_ = spr_table1602[k];
  R3_ = spr_decrementing_table1558[k];
  do {
    uint8 v2 = R5_;
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSprXXX_WallFollowers_UrchinXDisp[R5_] + R0_;
    oam[64].ypos = kSprXXX_WallFollowers_UrchinYDisp[v2] + R1_;
    oam[64].flags = kSprXXX_WallFollowers_UrchinProp[v2];
    uint8 v4;
    if (v2) {
      v4 = kSprXXX_WallFollowers_UrchinTiles[R2_];
    } else {
      v4 = -54;
      if (R3_)
        v4 = -52;
    }
    oam[64].charnum = v4;
    drt += 4;
    ++R5_;
  } while (R5_ != 5);
  Spr070_Pokey_Bank02SpriteEntry(spr_current_slotid, 2, 4);
}

void Spr03D_RipVanFish(uint8 k) {  // 02bfcd
  bool v4;

  GenericGFXRtDraw1Tile16x16(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    uint8 v10 = spr_xspeed[k];
    uint8 v9 = spr_yspeed[k];
    if (timer_star_power) {
      spr_yspeed[k] = -spr_yspeed[k];
      spr_xspeed[k] = -spr_xspeed[k];
    }
    Spr03D_RipVanFish_SetFacingDirectionBasedOnSpeed(k);
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
    HandleNormalSpriteLevelCollision(k);
    spr_yspeed[k] = v9;
    spr_xspeed[k] = v10;
    ++spr_table1570[k];
    if ((spr_table1588[k] & 3) != 0)
      spr_xspeed[k] = 0;
    if ((spr_table1588[k] & 0xC) != 0)
      spr_yspeed[k] = 0;
    if (!spr_table164a[k])
      spr_yspeed[k] = 16;
    uint8 v1 = spr_table00c2[k];
    if (!v1)
      goto LABEL_13;
    if (v1 == 1) {
      while (1) {
        if ((counter_global_frames & 1) != 0 || (v4 = spr_table151c[k] == 1, --spr_table151c[k], !v4)) {
          if ((counter_global_frames & 7) == 0) {
            uint8 v5 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
            uint8 v6 = spr_xspeed[k];
            if (v6 != kSpr03D_RipVanFish_MaxSpeed[v5])
              spr_xspeed[k] = kSpr03D_RipVanFish_Acceleration[v5] + v6;
            uint8 v7 = CheckPlayerPositionRelativeToSprite_Bank23_Y(k);
            uint8 v8 = spr_yspeed[k];
            if (v8 != kSpr03D_RipVanFish_MaxSpeed[v7])
              spr_yspeed[k] = kSpr03D_RipVanFish_Acceleration[v7] + v8;
          }
          spr_table1602[k] = (spr_table1570[k] & 4) != 0;
          return;
        }
        spr_table00c2[k] = 0;
LABEL_13:
        spr_yspeed[k] = 2;
        if ((counter_global_frames & 3) == 0) {
          int8 v2 = spr_xspeed[k];
          if (v2) {
            if (v2 >= 0)
              --spr_xspeed[k];
            else
              ++spr_xspeed[k];
          }
        }
        if ((spr_table1588[k] & 4) != 0) {
          spr_yspeed[k] = 0;
          spr_ypos_lo[k] &= 0xF0;
        }
        SpawnMusicNoteOrZ_Z(k);
        if (!flag_wake_up_rip_van_fish) {
          CheckPlayerPositionRelativeToSprite_Bank23_X(k);
          if ((uint8)(R15_ + 48) >= 0x60)
            break;
          CheckPlayerPositionRelativeToSprite_Bank23_Y(k);
          if ((uint8)(R14_ + 48) >= 0x60)
            break;
        }
        ++spr_table00c2[k];
        spr_table151c[k] = -1;
      }
      uint8 v3 = 2;
      if ((spr_table1570[k] & 0x30) == 0)
        v3 = 3;
      spr_table1602[k] = v3;
    } else {
      Unreachable();
    }
  }
}

void SpawnMusicNoteOrZ_MusicNote(uint8 k) {  // 02c0cf
  uint8 v1 = 8;
  if (spr_table157c[k])
    v1 = 9;
  SpawnMusicNoteOrZ_02C0DB(k, v1);
}

void SpawnMusicNoteOrZ_Z(uint8 k) {  // 02c0d9
  SpawnMusicNoteOrZ_02C0DB(k, 6);
}

void SpawnMusicNoteOrZ_02C0DB(uint8 k, uint8 a) {  // 02c0db
  if (!(spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k]) && (--spr_table1528[k] & 0x80) != 0) {
    spr_table1528[k] = 40;
    uint8 v3 = 11;
    while (mextspr_spriteid[v3]) {
      if ((--v3 & 0x80) != 0) {
        if ((--mextspr_slot_to_overwrite_when_slots_full & 0x80) != 0)
          mextspr_slot_to_overwrite_when_slots_full = 11;
        v3 = mextspr_slot_to_overwrite_when_slots_full;
        break;
      }
    }
    mextspr_spriteid[v3] = a;
    mextspr_xpos_lo[v3] = spr_xpos_lo[k] + 6;
    mextspr_ypos_lo[v3] = spr_ypos_lo[k];
    mextspr_timer[v3] = 127;
    mextspr_xspeed[v3] = -6;
  }
}

void Spr03D_RipVanFish_SetFacingDirectionBasedOnSpeed(uint8 k) {  // 02c126
  spr_table157c[k] = (spr_xspeed[k] & 0x80) != 0;
}

void Spr091_CharginChuck_State04_Digging(uint8 k) {  // 02c13a
  uint8 v1 = spr_decrementing_table1558[k];
  if (v1) {
    if (v1 == 1) {
      spr_decrementing_table1540[k] = 48;
      spr_table1534[k] = 4;
      spr_table1570[k] = 0;
    }
    spr_table151c[k] = 2;
  } else {
    if (!spr_decrementing_table1540[k]) {
      uint8 v2 = ++spr_table1534[k] & 3;
      spr_table1570[k] = v2;
      spr_decrementing_table1540[k] = kSpr091_CharginChuck_DATA_02C132[v2];
      if (v2 == 1) {
        if ((spr_table1534[k] & 0xC) == 0) {
          spr_decrementing_table1558[k] = 64;
          return;
        }
        Spr091_CharginChuck_02C19A(k);
      }
    }
    spr_table1602[k] = kSpr091_CharginChuck_DATA_02C136[spr_table1570[k]];
    spr_table151c[k] = kSpr091_CharginChuck_DATA_02C1F3[spr_table157c[k]];
  }
}

void Spr091_CharginChuck_02C19A(uint8 k) {  // 02c19a
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) == 0) {
    spr_current_status[j] = 8;
    spr_spriteid[j] = 72;
    R2_ = spr_table157c[k];
    R0_W = GetSprXPos(k);
    InitializeNormalSpriteRAMTables(j);
    uint8 v2 = R2_;
    SetSprXPos(j, PAIR16(kSpr091_CharginChuck_DigginChuckRockInitialXPosHi[v2], kSpr091_CharginChuck_DigginChuckRockInitialXPosLo[v2]) + R0_W);
    spr_xspeed[j] = kSpr091_CharginChuck_DigginChuckRockInitialXSpeed[v2];
    SetSprYPos(j, GetSprYPos(k) + 10);
    spr_yspeed[j] = -64;
    spr_decrementing_table1540[j] = 44;
  }
}

void Spr046_DigginChuck(uint8 k) {  // 02c1f5
  uint8 v1 = spr_table187b[k];
  Spr091_CharginChuck_02C22C(k);
  if (!v1 && spr_table187b[k] && !spr_decrementing_table163e[k])
    spr_decrementing_table163e[k] = 40;
}

void Spr091_CharginChuck_02C22C(uint8 k) {  // 02c22c
  if (spr_current_status[k] != 8) {
    spr_table151c[k] = kSpr091_CharginChuck_DATA_02C213[(counter_local_frames >> 2) & 3];
    Spr091_CharginChuck_Draw(k);
    return;
  }
  if (spr_decrementing_table15ac[k])
    spr_table1602[k] = 5;
  if ((spr_table1588[k] & 4) == 0 && (spr_yspeed[k] & 0x80) != 0 && spr_table00c2[k] < 5)
    spr_table1602[k] = 6;
  Spr091_CharginChuck_Draw(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry1(k);
    Spr091_CharginChuck_ProcessPlayerInteraction(k);
    CheckNormalSpriteToNormalSpriteCollision(k);
    HandleNormalSpriteLevelCollision(k);
    if ((spr_table1588[k] & 8) != 0)
      spr_yspeed[k] = 16;
    if ((spr_table1588[k] & 3) != 0) {
      if (spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k] || !spr_table187b[k] ||
          (uint8)(spr_xpos_lo[k] - mirror_current_layer1_xpos + 20) < 0x1C || (spr_table1588[k] & 0x40) != 0 ||
          blocks_copy_of_currently_processed_map16_tile_lo2 != 46 && blocks_copy_of_currently_processed_map16_tile_lo2 != 30) {
        if ((spr_table1588[k] & 4) != 0) {
          spr_yspeed[k] = -64;
          UpdateNormalSpritePosition_Y(k);
LABEL_25:
          UpdateNormalSpritePosition_Y(k);
          uint8 v1 = 0;
          uint8 v2 = spr_yspeed[k];
          if (spr_table164a[k]) {
            v1 = 1;
            if (sign8(v2)) {
              if (v2 < 0xE0)
                v2 = -32;
            }
          }
          int8 v3 = kSpr091_CharginChuck_YAcceleration[v1] + v2;
          if (v3 >= 0 && (uint8)v3 >= kSpr091_CharginChuck_MaxYSpeed[v1])
            v3 = kSpr091_CharginChuck_MaxYSpeed[v1];
          if (v3 >= 0 && spr_table00c2[k] == 7)
            v3 += 3;
          spr_yspeed[k] = v3;
          kSpr091_CharginChuck_ChuckPtrs[spr_table00c2[k]](k);
          return;
        }
LABEL_23:
        if ((spr_table1588[k] & 4) != 0)
          Spr091_CharginChuck_02C579(k);
        goto LABEL_25;
      }
      if ((spr_table1588[k] & 4) == 0)
        goto LABEL_23;
      uint16 v5 = blocks_xpos;
      uint16 v4 = blocks_ypos;
      SpawnBrickPieces(blocks_ypos);
      blocks_map16_to_generate = 2;
      GenerateTile();
      LOBYTE(blocks_ypos) = v4 - 16;
      HIBYTE(blocks_ypos) = HIBYTE(v4) - ((uint8)v4 < 0x10);
      blocks_xpos = v5;
      SpawnBrickPieces(HIBYTE(v5));
      blocks_map16_to_generate = 2;
      GenerateTile();
    }
    UpdateNormalSpritePosition_X(k);
    goto LABEL_23;
  }
}

void Spr091_CharginChuck_State0B_WaitToWhistle(uint8 k) {  // 02c356
  spr_table1602[k] = 3;
  if (spr_table164a[k]) {
    CheckPlayerPositionRelativeToSprite_Bank23_X(k);
    if ((uint8)(R15_ + 48) < 0x60)
      spr_table00c2[k] = 12;
  }
  Spr091_CharginChuck_02C556(k);
}

void Spr091_CharginChuck_State0C_Whistlin(uint8 k) {  // 02c37b
  if ((counter_local_frames & 0x3F) == 0)
    io_sound_ch3 = 30;
  uint8 v1 = 3;
  if ((counter_local_frames & 0x30) != 0)
    v1 = 6;
  spr_table1602[k] = v1;
  spr_table151c[k] = kSpr091_CharginChuck_DATA_02C373[(counter_local_frames >> 2) & 7];
  if ((spr_xpos_lo[k] & 0x10) != 0)
    gen_spr_spriteid = 9;
  flag_wake_up_rip_van_fish = 9;
}

void Spr091_CharginChuck_State0A_Pitchin(uint8 k) {  // 02c3cb
  if (spr_table1534[k]) {
    uint8 v1 = spr_decrementing_table1540[k];
    if (v1) {
      uint8 v2 = spr_decrementing_table1540[k];
      if (v1 >= 0x20 && v1 < 0x30)
        spr_yspeed[k] = 0;
      spr_table1602[k] = kSpr091_CharginChuck_DATA_02C3BB[v1 >> 2];
      if (v2 == 38)
        Spr091_CharginChuck_02C466(k);
    } else {
      spr_table1534[k] = 0;
    }
  } else {
    CheckPlayerPositionRelativeToSprite_Bank23_Y(k);
    if ((int8)R14_ <= -49) {
      spr_yspeed[k] = -56;
      spr_decrementing_table1540[k] = 62;
      ++spr_table1534[k];
    }
    if ((counter_global_frames & 7) == 0 && spr_decrementing_table1540[k])
      ++spr_decrementing_table1540[k];
    if ((counter_local_frames & 0x3F) == 0)
      Spr091_CharginChuck_02C556(k);
    if (!spr_decrementing_table1540[k])
      spr_decrementing_table1540[k] = kSpr091_CharginChuck_DATA_02C3B3[spr_table187b[k]];
    if (spr_decrementing_table1540[k] >= 0x40) {
      spr_table1602[k] = kSpr091_CharginChuck_DATA_02C3B7[((uint8)(spr_decrementing_table1540[k] - 64) >> 3) & 3];
      if ((spr_decrementing_table1540[k] & 0x1F) == 6) {
        Spr091_CharginChuck_02C466(k);
        spr_decrementing_table1558[k] = 8;
      }
    } else {
      spr_table1602[k] = 0;
    }
  }
}

void Spr091_CharginChuck_02C466(uint8 k) {  // 02c466
  if (!(spr_yoffscreen_flag[k] | spr_decrementing_table1558[k])) {
    uint8 j = 7;
    while (ext_spr_spriteid[j]) {
      if ((--j & 0x80) != 0)
        return;
    }
    ext_spr_spriteid[j] = 13;
    R0_W = GetSprXPos(k);
    SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], GetSprYPos(k));
    uint8 v2 = spr_table157c[k];
    SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j],
        PAIR16(kSpr091_CharginChuck_BaseballInitialXPosHi[v2], kSpr091_CharginChuck_BaseballInitialXPosLo[v2]) + R0_W);
    ext_spr_xspeed[j] = kSpr091_CharginChuck_BaseballInitialXSpeed[v2];
  }
}

void Spr091_CharginChuck_State09_Puntin(uint8 k) {  // 02c4bd
  spr_table1602[k] = 0;
  uint8 v1 = (counter_global_frames + 8 * k) & 0x7F;
  if (!v1) {
    Spr091_CharginChuck_02C556(k);
    SpawnFootball(k);
  }
  if (v1 < 0x20)
    spr_table1602[k] = kSpr091_CharginChuck_DATA_02C4B5[v1 >> 2];
}

void Spr091_CharginChuck_State08_Clappin(uint8 k) {  // 02c4e3
  Spr091_CharginChuck_02C556(k);
  uint8 v1 = 6;
  if ((int8)(spr_yspeed[k] + 16) >= 0 && spr_table160e[k]) {
    if (!spr_decrementing_table1fe2[k]) {
      io_sound_ch3 = 25;
      spr_decrementing_table1fe2[k] = 32;
    }
    v1 = 7;
  }
  spr_table1602[k] = v1;
  if ((spr_table1588[k] & 4) != 0) {
    spr_table160e[k] = 0;
    spr_table1602[k] = 4;
    if (!spr_decrementing_table1540[k]) {
      spr_decrementing_table1540[k] = 32;
      spr_yspeed[k] = -16;
      CheckPlayerPositionRelativeToSprite_Bank23_Y(k);
      if ((int8)R14_ <= -49) {
        spr_yspeed[k] = -64;
        ++spr_table160e[k];
        io_sound_ch3 = 8;
      }
    }
  }
}

void Spr091_CharginChuck_State06_Jumping(uint8 k) {  // 02c53c
  spr_table1602[k] = 6;
  if ((spr_table1588[k] & 4) != 0) {
    Spr091_CharginChuck_02C579(k);
    Spr091_CharginChuck_02C556(k);
    spr_decrementing_table1540[k] = 8;
    ++spr_table00c2[k];
  }
}

void Spr091_CharginChuck_02C556(uint8 k) {  // 02c556
  uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
  spr_table157c[k] = v1;
  spr_table151c[k] = kSpr091_CharginChuck_DATA_02C639[v1];
}

void Spr091_CharginChuck_State07_LandFromJump(uint8 k) {  // 02c564
  spr_table1602[k] = 3;
  if (spr_decrementing_table1540[k]) {
    Spr091_CharginChuck_02C579(k);
  } else if ((spr_table1588[k] & 4) != 0) {
    spr_table00c2[k] = 5;
    Spr091_CharginChuck_02C579(k);
  }
}

void Spr091_CharginChuck_02C579(uint8 k) {  // 02c579
  spr_xspeed[k] = 0;
  spr_yspeed[k] = 0;
}

void Spr091_CharginChuck_State05_PrepareToJumpOrSplit(uint8 k) {  // 02c582
  Spr091_CharginChuck_02C556(k);
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 == 1) {
      if (spr_spriteid[k] == 0x93) {
        spr_xspeed[k] = kSpr091_CharginChuck_JumpingInitialXSpeed[CheckPlayerPositionRelativeToSprite_Bank23_X(k)];
        spr_yspeed[k] = -80;
        spr_table00c2[k] = 6;
        io_sound_ch3 = 8;
      } else {
        spr_table00c2[k] = 0;
        spr_decrementing_table1540[k] = 80;
        io_sound_ch1 = 16;
        misc_scratch7e185e = 0;
        Spr091_CharginChuck_02C5BC(k);
        ++misc_scratch7e185e;
        Spr091_CharginChuck_02C5BC(k);
      }
    } else {
      spr_table1602[k] = 9;
    }
  } else {
    Spr091_CharginChuck_02C602(k);
  }
}

void Spr091_CharginChuck_02C5BC(uint8 k) {  // 02c5bc
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) == 0) {
    spr_current_status[j] = 8;
    spr_spriteid[j] = -111;
    SetSprXPos(j, GetSprXPos(k));
    SetSprYPos(j, GetSprYPos(k));
    InitializeNormalSpriteRAMTables(j);
    spr_xspeed[j] = kSpr091_CharginChuck_SplittingInitialXSpeed[misc_scratch7e185e];
    spr_yspeed[j] = -56;
    spr_decrementing_table1540[j] = 80;
  }
  spr_table1602[k] = 9;
}

void Spr091_CharginChuck_02C602(uint8 k) {  // 02c602
  spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
  if ((uint8)(R15_ + 80) >= 0xA0) {
    spr_table1602[k] = 3;
    if ((counter_global_frames & 0x3F) == 0)
      spr_yspeed[k] = -32;
  } else {
    spr_decrementing_table1540[k] = 64;
  }
}

void Spr091_CharginChuck_02C628(uint8 k) {  // 02c628
  spr_decrementing_table15ac[k] = 8;
}

void Spr091_CharginChuck_State00_LookingSideToSide(uint8 k) {  // 02c63b
  spr_table1602[k] = 3;
  spr_table187b[k] = 0;
  if ((spr_decrementing_table1540[k] & 0xF) == 0) {
    CheckPlayerPositionRelativeToSprite_Bank23_Y(k);
    if ((uint8)(R14_ + 40) < 0x50) {
      Spr091_CharginChuck_02C556(k);
      ++spr_table187b[k];
LABEL_4:
      spr_table00c2[k] = 2;
      spr_decrementing_table1540[k] = 24;
      return;
    }
  }
  if (!spr_decrementing_table1540[k]) {
    spr_table157c[k] ^= 1;
    goto LABEL_4;
  }
  if ((counter_local_frames & 3) != 0)
    goto LABEL_10;
  uint8 v1 = spr_table1534[k] & 1;
  if ((uint8)(kSpr091_CharginChuck_DATA_02C666[v1] + spr_table1594[k]) < 0xB) {
    spr_table1594[k] += kSpr091_CharginChuck_DATA_02C666[v1];
LABEL_10:
    spr_table151c[k] = kSpr091_CharginChuck_DATA_02C62E[spr_table1594[k]];
    return;
  }
  ++spr_table1534[k];
}

void Spr091_CharginChuck_State01_Charging(uint8 k) {  // 02c6a7
  CheckPlayerPositionRelativeToSprite_Bank23_Y(k);
  if ((uint8)(R14_ + 48) < 0x60 && CheckPlayerPositionRelativeToSprite_Bank23_X(k) == spr_table157c[k]) {
    spr_decrementing_table1540[k] = 32;
    spr_table187b[k] = 32;
  }
  if (!spr_decrementing_table1540[k]) {
    spr_table00c2[k] = 0;
    Spr091_CharginChuck_02C628(k);
    spr_decrementing_table1540[k] = GetRand() & 0x3F | 0x40;
  }
  uint8 v1 = spr_table157c[k];
  spr_table151c[k] = kSpr091_CharginChuck_DATA_02C639[v1];
  if ((spr_table1588[k] & 4) != 0) {
    if (spr_table187b[k]) {
      if ((counter_local_frames & 7) == 0)
        io_sound_ch1 = 1;
      v1 += 2;
    }
    spr_xspeed[k] = kSpr091_CharginChuck_ChargingXSpeed[v1];
  }
  uint8 v2 = counter_global_frames;
  if (!spr_table187b[k])
    v2 = counter_global_frames >> 1;
  spr_table1602[k] = kSpr091_CharginChuck_DATA_02C6A3[(v2 >> 1) & 3];
}

void Spr091_CharginChuck_State02_PrepareToCharge(uint8 k) {  // 02c726
  spr_table1602[k] = 3;
  if (!spr_decrementing_table1540[k]) {
    Spr091_CharginChuck_02C628(k);
    spr_table00c2[k] = 1;
    spr_decrementing_table1540[k] = 64;
  }
}

void Spr091_CharginChuck_State03_Hurt(uint8 k) {  // 02c74a
  uint8 v1 = spr_table1570[k];
  if (spr_decrementing_table1540[k]) {
LABEL_4:
    spr_table1602[k] = kSpr091_CharginChuck_DATA_02C73D[v1];
    uint8 v2 = 2;
    if (v1 == 5)
      v2 = ((counter_local_frames >> 1) & 2) + 1;
    spr_table151c[k] = v2;
    return;
  }
  ++spr_table1570[k];
  if (++v1 != 7) {
    spr_decrementing_table1540[k] = kSpr091_CharginChuck_HurtAnimationFrameCounter[v1];
    goto LABEL_4;
  }
  if (spr_spriteid[k] == 0x94) {
    spr_table00c2[k] = 12;
  } else {
    if (spr_spriteid[k] == 70)
      spr_spriteid[k] = -111;
    spr_decrementing_table1540[k] = 48;
    spr_table00c2[k] = 2;
    ++spr_table187b[k];
    Spr091_CharginChuck_02C556(k);
  }
}

void Spr091_CharginChuck_ProcessPlayerInteraction(uint8 k) {  // 02c79d
  if (!spr_decrementing_table1564[k] && CheckPlayerToNormalSpriteCollision(k) & 1) {
    if (timer_star_power) {
      spr_yspeed[k] = -48;
LABEL_5:
      spr_xspeed[k] = 0;
      spr_current_status[k] = 2;
      io_sound_ch1 = 3;
      GivePoints(k, 3);
      return;
    }
    CheckPlayerPositionRelativeToSprite_Bank23_Y(k);
    if (sign8(R14_ + 20)) {
      spr_decrementing_table1564[k] = 5;
      io_sound_ch1 = 2;
      SpawnContactEffectFromAbove(k);
      BoostMarioSpeed();
      spr_decrementing_table163e[k] = 0;
      if (spr_table00c2[k] != 3) {
        if (++spr_table1528[k] >= 3) {
          spr_yspeed[k] = 0;
          goto LABEL_5;
        }
        io_sound_ch3 = 40;
        spr_table00c2[k] = 3;
        spr_decrementing_table1540[k] = 3;
        spr_table1570[k] = 0;
        player_xspeed = kSpr091_CharginChuck_StompKnockbackXSpeed[CheckPlayerPositionRelativeToSprite_Bank23_X(k)];
      }
    } else if (!player_riding_yoshi_flag) {
      DamagePlayer_Hurt();
    }
  }
}

void Spr091_CharginChuck_Draw(uint8 k) {  // 02c81a
  if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
    return;
  Spr091_CharginChuck_DrawHead(k);
  Spr091_CharginChuck_DrawBody();
  Spr091_CharginChuck_DrawExtraTiles(k);
  Spr091_CharginChuck_DrawDigginChuckExtraTiles(k);
  Spr070_Pokey_Bank02SpriteEntry(k, 0xFF, 4);
}

void Spr091_CharginChuck_DrawHead(uint8 k) {  // 02c88c
  R7_ = 0;
  uint8 v1 = spr_table1602[k];
  R4_ = v1;
  bool v2 = 0;
  if (v1 == 9) {
    uint8 v3 = spr_decrementing_table1540[k];
    v2 = v3 < 0x20;
    uint8 v4 = v3 - 32;
    v2 = !v2;
    if (v2) {
      R7_ = v4 >> 5;
      v2 = (v4 & 2) != 0;
    }
  }
  R0_ += v2;
  R2_ = spr_table151c[k];
  R3_ = spr_table157c[k];
  R8_ = sprites_tile_priority | spr_table15f6[k];
  R5_ = spr_oamindex[k];
  uint8 v5 = kSpr091_CharginChuck_HeadOAMIndexOffset[v1] + R5_;
  uint8 v6 = kSpr091_CharginChuck_HeadXDisp[R4_];
  if (!R3_)
    v6 = -v6;
  OamEnt *oam = get_OamEnt(oam_buf, v5);
  oam[64].xpos = R0_ + v6;
  oam[64].ypos = kSpr091_CharginChuck_HeadYDisp[R4_] + R1_ - R7_;
  int v8 = R2_;
  oam[64].flags = R8_ | kSpr091_CharginChuck_HeadProp[R2_];
  oam[64].charnum = kSpr091_CharginChuck_HeadTiles[v8];
  sprites_oamtile_size_buffer[(v5 >> 2) + 64] = 2;
}

void Spr091_CharginChuck_DrawBody() {  // 02ca27
  R6_ = 0;
  uint8 v0 = R4_;
  if (!R3_) {
    v0 = R4_ + 26;
    R6_ = 64;
  }
  uint8 v1 = R5_ + kSpr091_CharginChuck_BodyOAMIndexOffset[R4_];
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[64].xpos = kSpr091_CharginChuck_BodyXDisp1[v0] + R0_;
  oam[65].xpos = kSpr091_CharginChuck_BodyXDisp2[v0] + R0_;
  uint8 v3 = R4_;
  int v4 = R4_;
  oam[64].ypos = kSpr091_CharginChuck_BodyYDisp1[R4_] + R1_;
  oam[65].ypos = R1_;
  oam[64].charnum = kSpr091_CharginChuck_BodyTiles1[v4];
  oam[65].charnum = kSpr091_CharginChuck_BodyTiles2[v3];
  int8 v5 = R6_ | R8_;
  oam[64].flags = kSpr091_CharginChuck_BodyProp1[v3] ^ (R6_ | R8_);
  oam[65].flags = kSpr091_CharginChuck_BodyProp2[v3] ^ v5;
  v1 >>= 2;
  sprites_oamtile_size_buffer[v1 + 64] = kSpr091_CharginChuck_BodyTileSize1[v3];
  sprites_oamtile_size_buffer[v1 + 65] = 2;
}

void Spr091_CharginChuck_DrawExtraTiles(uint8 k) {  // 02ca9d
  uint8 v1 = R4_;
  if (R4_ >= 0x14) {
    R2_ = R4_;
    if (!spr_table157c[k])
      v1 = R4_ + 6;
    uint8 v16 = R5_ + 8;
    OamEnt *oam = get_OamEnt(oam_buf, (uint8)(R5_ + 8));
    oam[64].xpos = kSpr091_CharginChuck_BaseballXDisp[v1 - 20] + R0_;
    uint8 v18 = kSpr091_CharginChuck_BaseballYDisp[R2_ - 20];
    if (v18) {
      oam[64].ypos = R1_ + v18;
      oam[64].charnum = -83;
      oam[64].flags = sprites_tile_priority | 9;
      sprites_oamtile_size_buffer[(v16 >> 2) + 64] = 0;
    }
  } else if (R4_ == 18 || R4_ == 19) {
    uint8 v10 = R5_;
    uint8 v11 = spr_table157c[k];
    OamEnt *v12 = get_OamEnt(oam_buf, R5_);
    v12[64].xpos = R0_ + ((8 * v11) ^ 8);
    v12[65].xpos = R0_ + 8 * v11;
    v12[64].charnum = 28;
    v12[65].charnum = 29;
    int8 v13 = R1_ - 8;
    v12[64].ypos = R1_ - 8;
    v12[65].ypos = v13;
    int8 v14 = sprites_tile_priority | kSpr091_CharginChuck_CharginShoulderProp[v11];
    v12[64].flags = v14;
    v12[65].flags = v14;
    uint8 v15 = v10 >> 2;
    sprites_oamtile_size_buffer[v15 + 64] = 0;
    sprites_oamtile_size_buffer[v15 + 65] = 0;
  } else {
    uint8 v2 = R4_ - 6;
    if ((uint8)(R4_ - 6) < 2) {
      uint8 v3 = R4_ - 6;
      uint8 v4 = R5_;
      OamEnt *v5 = get_OamEnt(oam_buf, R5_);
      v5[64].xpos = kSpr091_CharginChuck_JumpinChuckLeftHandXDisp[v2] + R0_;
      v5[65].xpos = kSpr091_CharginChuck_JumpinChuckRightHandXDisp[v2] + R0_;
      int8 v6 = kSpr091_CharginChuck_JumpinChuckHandsYDisp[v2] + R1_;
      v5[64].ypos = v6;
      v5[65].ypos = v6;
      uint8 v7 = kSpr091_CharginChuck_JumpinChuckHandTiles[v3];
      v5[64].charnum = v7;
      v5[65].charnum = v7;
      uint8 v8 = R8_;
      v5[64].flags = R8_;
      v5[65].flags = v8 | 0x40;
      v4 >>= 2;
      uint8 v9 = kSpr091_CharginChuck_JumpinChuckHandTileSize[v3];
      sprites_oamtile_size_buffer[v4 + 64] = v9;
      sprites_oamtile_size_buffer[v4 + 65] = v9;
    }
  }
}

void Spr091_CharginChuck_DrawDigginChuckExtraTiles(uint8 k) {  // 02cba1
  if (spr_spriteid[k] == 70) {
    uint8 v1 = spr_table1602[k];
    uint8 v2;
    if (v1 == 5) {
      v2 = 1;
    } else {
      if (v1 < 0xE)
        return;
      v2 = v1 - 14;
    }
    R2_ = v2;
    uint8 v3 = spr_oamindex[k] + 12;
    uint8 v4 = spr_table157c[k] | (2 * v2);
    OamEnt *oam = get_OamEnt(oam_buf, v3);
    oam[64].xpos = kSpr091_CharginChuck_DigginChuckXDisp[v4] + R0_;
    oam[64].flags = sprites_tile_priority | kSpr091_CharginChuck_DigginChuckProp[v4 & 1];
    uint8 v6 = R2_;
    int v7 = R2_;
    oam[64].ypos = kSpr091_CharginChuck_DigginChuckYDisp[R2_] + R1_;
    oam[64].charnum = kSpr091_CharginChuck_DigginChuckTiles[v7];
    sprites_oamtile_size_buffer[(v3 >> 2) + 64] = kSpr091_CharginChuck_DigginChuckTileSize[v6];
  }
}

void Spr091_CharginChuck_Return02CBFC() {  // 02cbfc
  ;
}

void Spr088_WingedCage_Init(uint8 k) {  // 02cbfd
  ;
}

void Spr088_WingedCage(uint8 k) {  // 02cbfe
  if (!flag_sprites_locked)
    ++spr_table1570[k];
  Spr088_WingedCage_Draw(k);
  Spr088_WingedCage_SyncLayer3ScrollToLayer1(k);
  AddSprXPos(k, misc_layer1_xdisp);
  if (!player_current_state) {
    if (flag_standing_on_beta_cage)
      Spr088_WingedCage_SyncPlayerPosToLayer1();
    AddSprYPos(k, (int8)misc_layer1_ydisp);
    R0_W = GetSprXPos(k);
    R2_W = GetSprYPos(k);
    if ((int8)(player_xspeed - 1) >= 0) {
      if ((uint16)(R0_W + 144) < player_xpos) {
        player_xpos = R0_W + 145;
        player_xspeed = 0;
      }
    } else if (R0_W >= player_xpos) {
      player_xpos = R0_W;
      player_xspeed = 0;
    }
    if ((player_yspeed & 0x80) == 0) {
      if ((uint16)(R2_W + 96) < player_ypos) {
        player_ypos = R2_W + 97;
        player_yspeed = 0;
        misc_player_on_solid_sprite = 1;
        flag_standing_on_beta_cage = 1;
      }
    } else if ((uint16)(R2_W + 32) >= player_ypos) {
      player_yspeed = 0;
    }
  }
}

void Spr088_WingedCage_Draw(uint8 k) {  // 02ccb9
  R8_ = 3;
  R0_ = spr_xpos_lo[k] - mirror_current_layer1_xpos;
  R1_ = spr_ypos_lo[k] - mirror_current_layer1_ypos;
  R2_ = spr_oamindex[k];
  do {
    int8 v3 = kSpr088_WingedCage_XDisp[R8_] + R0_;
    OamEnt *oam = get_OamEnt(oam_buf, R2_);
    oam[64].xpos = v3;
    oam[65].xpos = v3;
    int8 v5 = kSpr088_WingedCage_YDisp[R8_] + R1_;
    oam[64].ypos = v5;
    oam[65].ypos = v5 + 8;
    uint8 t = (R8_ ^ (spr_table1570[spr_current_slotid] >> 3)) & 1;
    oam[64].charnum = t ? 0x81 : 0xc6;
    oam[65].charnum = t ? 0xd7 : 0xd6;
    oam[64].flags = 112;
    oam[65].flags = 112;
    uint8 v8 = R2_ >> 2;
    sprites_oamtile_size_buffer[v8 + 64] = 0;
    sprites_oamtile_size_buffer[v8 + 65] = 0;
    R2_ += 8;
  } while ((--R8_ & 0x80) == 0);
}

void Spr060_FlatPalaceSwitch_Sub(uint8 k) {  // 02cd59
  uint8 drt;

  if (spr_decrementing_table1540[k] == 94) {
    blocks_map16_to_generate = 27;
    blocks_xpos = GetSprXPos(k);
    blocks_ypos = GetSprYPos(k) - 16;
    GenerateTile();
  }
  SolidSpriteBlock(k);
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  R2_ = kSpr060_FlatPalaceSwitch_Palette[sprites_color_of_flat_palace_switch_to_spawn];
  for (uint8 i = 7; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSpr060_FlatPalaceSwitch_XDisp[i] + R0_;
    oam[64].ypos = kSpr060_FlatPalaceSwitch_YDisp[i] + R1_;
    oam[64].charnum = kSpr060_FlatPalaceSwitch_Tile[i];
    uint8 v5 = kSpr060_FlatPalaceSwitch_Prop[i];
    if (i < 4)
      v5 |= R2_;
    oam[64].flags = v5;
    drt += 4;
  }
  Spr070_Pokey_Bank02SpriteEntry(k, 0, 7);
}

void SprXXX_WallSpringboard(uint8 k) {  // 02cdcb
  SubOffscreen_Bank02_Entry1(k);
  SprXXX_WallSpringboard_Draw(k);
  if (!flag_sprites_locked) {
    if (spr_table1534[k]) {
      --spr_table1534[k];
      if ((io_controller_hold1 & 0x80) != 0) {
        spr_table1534[k] = 0;
        player_yspeed = kSprXXX_WallSpringboard_HighBouncePlayerYSpeed[spr_table151c[k]];
        io_sound_ch3 = 8;
      }
    }
    kUnk_2cdf8[spr_table1528[k]](k);
  }
}

void SprXXX_WallSpringboard_Return02CDFE(uint8 k) {  // 02cdfe
  ;
}

void SprXXX_WallSpringboard_State01_PlayerIsOnTop(uint8 k) {  // 02ce0f
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 == 1) {
      ++spr_table1528[k];
      spr_table157c[k] = 1;
    }
  } else {
    int8 v2 = spr_table00c2[k];
    if (v2 >= 0 && (uint8)v2 >= spr_table151c[k]) {
      spr_table00c2[k] = spr_table151c[k];
      spr_decrementing_table1540[k] = 8;
    } else {
      spr_table00c2[k] = v2 + 1;
    }
  }
}

void SprXXX_WallSpringboard_State02_Rebound(uint8 k) {  // 02ce3a
  bool v1;

  if ((++spr_table1570[k] & 3) == 0 && (v1 = spr_table151c[k] == 1, --spr_table151c[k], v1)) {
    spr_table00c2[k] = 0;
    spr_table1528[k] = 0;
  } else {
    R0_ = -spr_table151c[k];
    if ((spr_table157c[k] & 1) != 0) {
      uint8 v5 = spr_table00c2[k] - 4;
      spr_table00c2[k] = v5;
      if ((v5 & 0x80) != 0 && v5 < R0_) {
        spr_table00c2[k] = R0_;
        ++spr_table157c[k];
      }
    } else {
      uint8 v2 = spr_table00c2[k];
      bool v3 = (int8)(v2 + 4) < 0;
      uint8 v4 = v2 + 4;
      spr_table00c2[k] = v4;
      if (!v3 && v4 >= spr_table151c[k]) {
        spr_table00c2[k] = spr_table151c[k];
        ++spr_table157c[k];
      }
    }
  }
}

void SprXXX_WallSpringboard_Draw(uint8 k) {  // 02cee0
  if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
    return;
  R2_ = 4;
  R5_ = spr_spriteid[k] - 107;
  int8 v1 = spr_table00c2[k];
  R3_ = v1;
  if (v1 < 0)
    v1 = -v1;
  R4_ = v1;
  uint8 v2 = spr_oamindex[k];
  do {
    uint8 v3 = R2_ + R4_ * 5;
    uint8 v4 = kSprXXX_WallSpringboard_XDisp[v3];
    if (R5_ & 1)
      v4 = -v4;
    R8_ = v4;
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam[64].xpos = R0_ + v4;
    uint8 v6 = kSprXXX_WallSpringboard_YDisp[v3];
    if (__CFSHL__(R3_, 1))
      v6 = -v6;
    R9_ = v6;
    oam[64].ypos = R1_ + v6;
    oam[64].charnum = 61;
    oam[64].flags = sprites_tile_priority | 0xA;
    SprXXX_WallSpringboard_HandlePlayerCollision(k, v2);
    v2 += 4;
    --R2_;
  } while ((R2_ & 0x80) == 0);
  Spr070_Pokey_Bank02SpriteEntry(k, 0, 4);
}

void SprXXX_WallSpringboard_HandlePlayerCollision(uint8 k, uint8 j) {  // 02cf52
  if (!player_current_state &&
      !(spr_yoffscreen_flag[k] | (uint8)(spr_xoffscreen_flag[k] | HIBYTE(player_on_screen_pos_x) | HIBYTE(player_on_screen_pos_y)))) {
    R10_ = player_on_screen_pos_x + 2;
    R11_ = player_on_screen_pos_y + (player_riding_yoshi_flag ? 32 : 16);
    OamEnt *oam = get_OamEnt(oam_buf, j);
    if ((uint8)(oam[64].xpos - R10_ + 8) < 0x14) {
      R15_ = player_current_power_up ? 26 : 28;
      if ((uint8)(oam[64].ypos - R11_ + 8) < R15_ && (player_yspeed & 0x80) == 0) {
        R15_ = player_riding_yoshi_flag ? 47 : 31;
        player_ypos = oam[64].ypos - R15_ + mirror_current_layer1_ypos;
        player_in_air_flag = 0;
        misc_player_on_solid_sprite = 2;
        uint8 v7 = spr_table1528[k];
        if (!v7 || v7 == 2) {
          player_xspeed = 0;
          spr_table151c[k] = kSprXXX_WallSpringboard_MaxAngle[R2_];
          spr_table1528[k] = 1;
          spr_table1570[k] = 0;
        } else if (spr_decrementing_table1540[k] == 1) {
          spr_table1534[k] = 8;
          player_yspeed = kSprXXX_WallSpringboard_AutoBouncePlayerYSpeed[spr_table00c2[k]];
        }
      }
    }
  }
}

void SubOffscreen_Bank02_Entry4(uint8 k) {  // 02d017
  R3_ = 6;
  SubOffscreen_Bank02_02D027(k);
}

void SubOffscreen_Bank02_Entry3(uint8 k) {  // 02d01b
  R3_ = 4;
  SubOffscreen_Bank02_02D027(k);
}

void SubOffscreen_Bank02_Entry2(uint8 k) {  // 02d01f
  R3_ = 2;
  SubOffscreen_Bank02_02D027(k);
}

void SubOffscreen_Bank02_Entry1(uint8 k) {  // 02d025
  R3_ = 0;
  SubOffscreen_Bank02_02D027(k);
}

void SubOffscreen_Bank02_02D027(uint8 k) {  // 02d027
  if (CheckIfNormalSpriteOffScreen(k)) {
    if ((misc_level_layout_flags & 1) != 0) {
      sub_2D091(k);
      return;
    }
    if (R3_ != 4) {
      uint16 ypos = GetSprYPos(k) + 0x50;
      if (!sign8((ypos >> 8) - 2)) {
LABEL_10:
        SubOffscreen_Bank02_EraseSprite(k);
        return;
      }
      if ((spr_property_bits167a[k] & 4) != 0)
        return;
    }
    R1_ = R3_ | counter_global_frames & 1;
    uint16 xpos = PAIR16(kSubOffscreen_Bank02_DATA_02D00F[R1_], kSubOffscreen_Bank02_DATA_02D007[R1_]) +
        mirror_current_layer1_xpos - GetSprXPos(k);
    uint8 v3 = (xpos >> 8);
    if (R1_ & 1)
      v3 ^= 0x80;
    if ((v3 & 0x80) != 0)
      goto LABEL_10;
  }
}

void SubOffscreen_Bank02_EraseSprite(uint8 k) {  // 02d07a
  if (spr_current_status[k] >= 8) {
    uint8 v1 = spr_load_status_table_index[k];
    if (v1 != 0xFF)
      sprites_load_status[v1] = 0;
  }
  spr_current_status[k] = 0;
}

void sub_2D091(uint8 k) {  // 02d091
  if ((spr_property_bits167a[k] & 4) == 0 && !(counter_global_frames & 1)) {
    bool v1 = (counter_global_frames & 2) != 0;
    R1_ = v1;
    uint16 ypos = mirror_current_layer1_ypos + PAIR16(kSubOffscreen_Bank02_DATA_02D005[v1], kSubOffscreen_Bank02[v1]) - GetSprYPos(k);
    uint8 r0 = ypos >> 8;
    if ((counter_global_frames & 2) != 0)
      r0 ^= 0x80;
    if ((r0 & 0x80) != 0)
      SubOffscreen_Bank02_EraseSprite(k);
  }
}

void Spr035_Yoshi_CheckBerryTileCollisionWithAdultYoshiMouth(uint8 k) {  // 02d0d4
  if (!spr_decrementing_table1564[k] && (spr_table160e[k] & 0x80) != 0)
    Spr035_Yoshi_02D0E6(k);
}

void Spr035_Yoshi_02D0E6(uint8 k) {  // 02d0e6
  R15_ = 0;
  uint16 t = GetSprYPos(k) + 8;
  LOBYTE(yoshi_ypos) = t;
  R0_ = t & 0xF0;
  if (t < 0x200) {
    R2_ = t >> 8;
    HIBYTE(yoshi_ypos) = t >> 8;
    uint8 v2 = spr_table157c[k];
    uint16 xpos = GetSprXPos(k) + PAIR16(kSpr035_Yoshi_DATA_02D0D2[v2], kSpr035_Yoshi_DATA_02D0D0[v2]);
    R1_ = xpos;
    LOBYTE(yoshi_xpos) = xpos;
    if ((xpos >> 8) < misc_screens_in_lvl) {
      HIBYTE(yoshi_xpos) = (xpos >> 8);
      R3_ = (xpos >> 8);
      R0_ |= R1_ >> 4;
      uint8 v6 = (xpos >> 8);
      uint16 v8 = PAIR16(kLevelDataLayoutTables_EightBitHi[v6], kLevelDataLayoutTables_EightBitLo[v6]);
      if (R15_)
        v8 = PAIR16(kLevelDataLayoutTables_EightBitHi_Horizontal_L2[v6], kLevelDataLayoutTables_EightBitLo_Horizontal_L2[v6]);
      *(uint16 *)&R5_ = PAIR16(R2_, R0_) + v8;
      R7_ = 126;
      uint8 v9 = spr_current_slotid;
      blocks_currently_processed_map16_tile_lo = *IndirPtr(&R5_, 0);
      ++R7_;
      if (!*IndirPtr(&R5_, 0) && blocks_currently_processed_map16_tile_lo >= 0x45 && blocks_currently_processed_map16_tile_lo < 0x48) {
        yoshi_berry_being_eaten = blocks_currently_processed_map16_tile_lo - 68;
        timer_yoshi_tongue_is_out = 0;
        spr_table1602[v9] = kSpr035_Yoshi_DATA_02D1F1[yoshi_ducking_flag];
        spr_decrementing_table1564[v9] = 34;
        player_ypos = (player_ypos + 8) & ~0xf;
      }
    }
  }
}

void Spr035_Yoshi_ChangeBerryIntoBushTile() {  // 02d1f3
  blocks_xpos = yoshi_xpos;
  blocks_ypos = yoshi_ypos;
  blocks_map16_to_generate = 4;
  GenerateTile();
}

void HandleHeldPBalloonAndInLakituCloudMovement(uint8 k) {  // 02d214
  if ((io_controller_hold1 & 3) != 0) {
    uint8 v2 = io_controller_hold1 & 3;
    uint8 v3;
    if ((io_controller_hold1 & 3) == 1) {
      v3 = spr_xspeed[k];
      if (v3 == kHandleHeldPBalloonAndInLakituCloudMovement_MaxXSpeed[0])
        goto LABEL_14;
      if ((int8)(v3 - kHandleHeldPBalloonAndInLakituCloudMovement_MaxXSpeed[v2 - 1]) >= 0)
        goto LABEL_2;
    } else {
      v3 = spr_xspeed[k];
      if (v3 == kHandleHeldPBalloonAndInLakituCloudMovement_MaxXSpeed[v2 - 1])
        goto LABEL_14;
      if ((int8)(v3 - kHandleHeldPBalloonAndInLakituCloudMovement_MaxXSpeed[v2 - 1]) < 0)
        goto LABEL_2;
    }
    spr_xspeed[k] = kHandleHeldPBalloonAndInLakituCloudMovement_XAcceleration[v2 - 1] + v3;
    goto LABEL_14;
  }
LABEL_2:;
  int8 v1 = spr_xspeed[k];
  if (v1) {
    if (v1 < 0) {
      ++spr_xspeed[k];
      ++spr_xspeed[k];
    }
    --spr_xspeed[k];
  }
LABEL_14:;
  uint8 v4 = 0;
  if (spr_spriteid[k] == 0x87) {
    if ((io_controller_hold1 & 0xC) != 0) {
      v4 = 16;
      if ((io_controller_hold1 & 8) != 0)
        v4 = -16;
    }
  } else {
    v4 = -8;
    if ((io_controller_hold1 & 0xC) != 0) {
      v4 = -16;
      if ((io_controller_hold1 & 8) == 0)
        v4 = 8;
    }
  }
  R0_ = v4;
  int8 v5 = spr_yspeed[k] - v4;
  if (v5)
    spr_yspeed[k] += (v5 < 0) ? 1 : -1;
  player_xspeed = spr_xspeed[k];
  player_yspeed = spr_yspeed[k];
}

uint8 UpdateNormalSpritePosition_X(uint8 k) {  // 02d288
  return UpdateNormalSpritePosition_Y(k + 12);
}

uint8 UpdateNormalSpritePosition_Y(uint8 k) {  // 02d294
  uint16 t = spr_sub_ypos[k] + (uint8)(16 * spr_yspeed[k]);
  spr_sub_ypos[k] = t;
  uint16 disp = ((int8)spr_yspeed[k] >> 4) + (t >> 8);
  AddSprYPos(k, disp);
  sprites_position_disp = disp;
  return disp;
}

void AimTowardsPlayer_Bank23(uint8 k, uint8 a) {  // 02d2fb
  R1_ = a;
  R2_ = CheckPlayerPositionRelativeToSprite_Bank23_Y(k);
  uint8 v2 = R14_;
  if ((R14_ & 0x80) != 0)
    v2 = -R14_;
  R12_ = v2;
  R3_ = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
  uint8 v3 = R15_;
  if ((R15_ & 0x80) != 0)
    v3 = -R15_;
  R13_ = v3;
  int8 v4 = 0;
  uint8 v5 = R13_;
  if (R13_ < R12_) {
    v4 = 1;
    R13_ = R12_;
    R12_ = v5;
  }
  R11_ = 0;
  R0_ = 0;
  uint8 v6 = R1_;
  do {
    uint8 v7 = R12_ + R11_;
    if ((uint8)(R12_ + R11_) >= R13_) {
      v7 -= ((uint8)(R12_ + R11_) < R13_) + R13_;
      ++R0_;
    }
    R11_ = v7;
    --v6;
  } while (v6);
  if (v4) {
    uint8 v8 = R0_;
    R0_ = R1_;
    R1_ = v8;
  }
  if (R2_)
    R0_ = -R0_;
  if (R3_)
    R1_ = -R1_;
}

uint8 GetDrawInfo_Bank23_ReturnsTwice(uint8 k) {  // 02d378
  spr_yoffscreen_flag[k] = 0;
  spr_xoffscreen_flag[k] = (uint16)(GetSprXPos(k) - mirror_current_layer1_xpos) >= 256;
  bool carry = (uint16)(GetSprXPos(k) - mirror_current_layer1_xpos + 0x40) >= 0x180;
  spr_table15c4[k] = carry;
  if (carry) {
    return 0xff;
  } else {
    uint8 v3 = (spr_property_bits1662[k] & 0x20) != 0;
    do {
      uint16 ypos = GetSprYPos(k) + kGetDrawInfo_DATA_02D374[v3] - mirror_current_layer1_ypos;
      if ((ypos >> 8) != 0)
        spr_yoffscreen_flag[k] |= kGetDrawInfo_DATA_02D376[v3];
    } while ((--v3 & 0x80) == 0);
    R0_ = spr_xpos_lo[k] - mirror_current_layer1_xpos;
    R1_ = spr_ypos_lo[k] - mirror_current_layer1_ypos;
    return spr_oamindex[k];
  }
}

void Spr089_Layer3Smasher(uint8 k) {  // 02d3ea
  Spr089_Layer3Smasher_UpdatePos(k);
  if (!flag_sprites_locked) {
    Spr089_Layer3Smasher_02D49C(k);
    AddSprXPos(k, (int8)misc_layer1_xdisp);
    uint8 v3 = spr_table00c2[k];
    if (v3) {
      switch (v3) {
      case 1:
        if (spr_decrementing_table1540[k]) {
          spr_yspeed[k] = 4;
          UpdateNormalSpritePosition_Y(k);
        } else {
          ++spr_table00c2[k];
        }
        break;
      case 2:
        UpdateNormalSpritePosition_Y(k);
        int8 v4 = spr_yspeed[k];
        if (v4 <= 63)
          spr_yspeed[k] = v4 + 7;
        if (spr_ypos_lo[k] >= 0xA0) {
          spr_ypos_lo[k] &= 0xF0;
          timer_shake_layer1 = 80;
          io_sound_ch3 = 9;
          spr_decrementing_table1540[k] = 48;
          ++spr_table00c2[k];
        }
        break;
      case 3:
        if (!spr_decrementing_table1540[k])
          ++spr_table00c2[k];
        break;
      case 4:
        spr_yspeed[k] = -32;
        UpdateNormalSpritePosition_Y(k);
        if (!spr_ypos_lo[k]) {
          spr_table00c2[k] = 0;
          spr_decrementing_table1540[k] = -96;
        }
        break;
      default: Unreachable(); break;
      }
    } else if (timer_disappearing_sprite) {
      SubOffscreen_Bank02_EraseSprite(k);
    } else if (!spr_decrementing_table1540[k]) {
      ++spr_table00c2[k];
      spr_decrementing_table1540[k] = 0x80;
      SetSprXPos(k, (int8)(GetRand() & 0x3F | 0x80));
      SetSprYPos(k, 0);
      spr_yspeed[k] = 0;
    }
  }
}

void Spr089_Layer3Smasher_02D49C(uint8 k) {  // 02d49c
  uint8 v1 = (player_current_power_up && !player_ducking_flag) ? 16 : 0;
  if ((uint8)(spr_ypos_lo[k] + v1) >= (uint8)player_on_screen_pos_y) {
    R0_W = GetSprXPos(k);
    uint16 t = R0_W + player_on_screen_pos_x - 48;
    if (t < 0x90) {
      if ((uint16)(t - 8) >= 0x80) {
        player_xspeed = sign16(t - 8 - 0x80) ? -8 : 8;
      } else if (player_in_air_flag) {
        player_yspeed = ((spr_yspeed[k] & 0x80) == 0) ? spr_yspeed[k] : 0;
      } else {
        DamagePlayer_Hurt();
      }
    }
  }
}

uint8 CheckPlayerPositionRelativeToSprite_Bank23_X(uint8 k) {  // 02d4fa
  int t = player_xpos - GetSprXPos(k);
  R15_ = t;
  return sign16(t) != 0;
}

uint8 CheckPlayerPositionRelativeToSprite_Bank23_Y(uint8 k) {  // 02d50c
  int t = player_ypos - GetSprYPos(k);
  R14_ = t;
  return sign16(t) != 0;
}

void Spr09F_BanzaiBill_Sub(uint8 k) {  // 02d587
  Spr09F_BanzaiBill_Draw(k);
  if (spr_current_status[k] != 2 && !flag_sprites_locked) {
    SubOffscreen_Bank02_Entry1(k);
    spr_xspeed[k] = -24;
    UpdateNormalSpritePosition_X(k);
    CheckPlayerToNormalSpriteCollision(k);
  }
}

void Spr09F_BanzaiBill_Draw(uint8 k) {  // 02d5e4
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  for (uint8 i = 15; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSpr09F_BanzaiBill_XDisp[i] + R0_;
    oam[64].ypos = kSpr09F_BanzaiBill_YDisp[i] + R1_;
    oam[64].charnum = kSpr09F_BanzaiBill_Tiles[i];
    oam[64].flags = kSpr09F_BanzaiBill_Prop[i];
    drt += 4;
  }
  Spr070_Pokey_Bank02SpriteEntry(k, 2, 0xF);
}

void Spr09E_BallNChain(uint8 k) {  // 02d617
  if (spr_spriteid[k] == 0x9F)
    Spr09F_BanzaiBill_Sub(k);
  else
    Spr09E_BallNChain_Sub(k);
}

void Spr09E_BallNChain_Sub(uint8 k) {  // 02d62a
  bool v4;

  SubOffscreen_Bank02_Entry4(k);
  if (!flag_sprites_locked) {
    int8 v1 = ((spr_xpos_lo[k] & 0x10) == 0) ? -2 : 2;
    SetHiLo(&spr_table151c[k], &spr_table1602[k], PAIR16(spr_table151c[k], spr_table1602[k]) + (int8)v1 & 0x1ff);
  }
  R1_ = spr_table151c[k];
  R0_ = spr_table1602[k];
  R2_W = (R0_W + 128) & 0x1FF;
  R4_W = kCircleCoordinates[(uint16)(2 * (uint8)R0_W) >> 1];
  R6_W = kCircleCoordinates[(uint16)(2 * (uint8)(R0_W + 0x80)) >> 1];
  uint8 v5 = spr_current_slotid;
  WriteReg(WRMPYA, R4_);
  uint8 v6 = spr_table187b[v5];
  if (!R5_) {
    WriteReg(WRMPYB, v6);
    uint8 t = ReadReg(RDMPYL);
    v6 = ReadReg(RDMPYH) + (t >> 7);
  }
  v4 = R1_ & 1;
  R1_ >>= 1;
  if (v4)
    v6 = -v6;
  R4_ = v6;
  WriteReg(WRMPYA, R6_);
  uint8 v8 = spr_table187b[v5];
  if (!R7_) {
    WriteReg(WRMPYB, v8);
    uint8 t = ReadReg(RDMPYL);
    v8 = ReadReg(RDMPYH) + (t >> 7);
  }
  v4 = R3_ & 1;
  R3_ >>= 1;
  if (v4)
    v8 = -v8;
  R6_ = v8;
  uint16 old_x = GetSprXPos(v5);
  uint16 old_y = GetSprYPos(v5);
  AddSprXPos(v5, (int8)R4_);
  spr_table1528[v5] = spr_xpos_lo[v5] - spr_table1534[v5];
  spr_table1534[v5] = spr_xpos_lo[v5];
  AddSprYPos(v5, (int8)R6_);
  if (spr_spriteid[v5] == 0x9E) {
    CheckPlayerToNormalSpriteCollision(v5);
    Spr0A3_GreyChainedPlatform_02D813(v5);
  } else {
    if (SolidSpriteBlock(v5) & 1) {
      spr_table160e[v5] = 3;
      misc_player_on_solid_sprite = 3;
      if (!player_riding_yoshi_flag) {
        PlayerDraw();
        player_hide_player_tile_flags = -1;
      }
    } else if (spr_table160e[v5]) {
      spr_table160e[v5] = 0;
      PlayerDraw();
    }
    Spr0A3_GreyChainedPlatform_02D848(v5);
  }
  SetSprXPos(v5, old_x);
  SetSprYPos(v5, old_y);
  R0_ = spr_xpos_lo[v5] + Spr0A3_GreyChainedPlatform_02D870(v5, mirror_current_layer1_xpos + R0_ - spr_xpos_lo[v5]) -
        mirror_current_layer1_xpos;
  R1_ = spr_ypos_lo[v5] + Spr0A3_GreyChainedPlatform_02D870(v5, mirror_current_layer1_ypos + R1_ - spr_ypos_lo[v5]) -
        mirror_current_layer1_ypos;
  if (!spr_table15c4[v5]) {
    uint8 v11 = spr_oamindex[v5] + 16;
    uint8 v21 = v5;
    R10_ = spr_xpos_lo[v5];
    R11_ = spr_ypos_lo[v5];
    R8_ = (spr_spriteid[v5] != 0x9E) ? -94 : -24;
    for (int8 i = 1; i >= 0; --i) {
      OamEnt *oam = get_OamEnt(oam_buf, v11);
      oam[64].xpos = R0_;
      oam[64].ypos = R1_;
      oam[64].charnum = R8_;
      oam[64].flags = 51;
      R0_ = mirror_current_layer1_xpos + R0_ - R10_;
      int8 v15 = __CFSHL__(R0_, 1) ? 0x80 : 0;
      R0_ = (R0_ >> 1) + v15;
      R0_ = R10_ + R0_ - mirror_current_layer1_xpos;
      R1_ = mirror_current_layer1_ypos + R1_ - R11_;
      int8 v16 = (__CFSHL__(R1_, 1)) ? 0x80 : 0;
      R1_ = R11_ + (R1_ >> 1) + v16 - mirror_current_layer1_ypos;
      v11 += 4;
    }
    Spr070_Pokey_Bank02SpriteEntry(v21, 2, 5);
  }
}

void Spr0A3_GreyChainedPlatform_02D813(uint8 k) {  // 02d813
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSpr0A3_GreyChainedPlatform_DATA_02D807[i] + R0_;
    oam[64].ypos = kSpr0A3_GreyChainedPlatform_DATA_02D80B[i] + R1_;
    oam[64].charnum = kSpr0A3_GreyChainedPlatform_DoNothing6Times[i];
    oam[64].flags = kSpr0A3_GreyChainedPlatform_DATA_02D80F[i];
    drt += 4;
  }
}

void Spr0A3_GreyChainedPlatform_02D848(uint8 k) {  // 02d848
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSpr0A3_GreyChainedPlatform_DATA_02D840[i] + R0_;
    oam[64].ypos = R1_;
    oam[64].charnum = kSpr0A3_GreyChainedPlatform_WoodPlatformTiles[i];
    oam[64].flags = 51;
    drt += 4;
  }
}

uint8 Spr0A3_GreyChainedPlatform_02D870(uint8 k, uint8 a) {  // 02d870
  uint8 org_a = a;

  if ((a & 0x80) != 0)
    a = -a;
  WriteReg(WRDIVH, a);
  WriteReg(WRDIVL, 0);
  WriteReg(WRDIVB, spr_table187b[k] >> 1);
  R14_ = ReadReg(RDDIVL);
  uint8 Reg = ReadReg(RDDIVH);
  bool v3 = __CFSHL__(R14_, 1);
  R14_ *= 2;
  int8 v4 = 2 * Reg + v3;
  v3 = __CFSHL__(R14_, 1);
  R14_ *= 2;
  int8 v5 = 2 * v4 + v3;
  v3 = __CFSHL__(R14_, 1);
  R14_ *= 2;
  int8 v6 = 2 * v5 + v3;
  v3 = __CFSHL__(R14_, 1);
  R14_ *= 2;
  uint8 result = 2 * v6 + v3;
  return ((org_a & 0x80) != 0) ? -result : result;
}

void Spr09D_BubbleWithSprite(uint8 k) {  // 02d8bb
  spr_oamindex[k] += 20;
  GenericGFXRtDraw1Tile16x16(k);
  uint8 v1 = spr_oamindex[k];
  uint8 v2 = spr_table00c2[k];
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[64].flags = sprites_tile_priority | kSpr09D_BubbleWithSprite_BubbleSprGfxProp1[v2];
  uint8 v4 = kSpr09D_BubbleWithSprite_BubbleSprTiles1[v2];
  if (__CFSHL__(4 * counter_local_frames, 1))
    v4 = kSpr09D_BubbleWithSprite_BubbleSprTiles2[v2];
  oam[64].charnum = v4;
  uint8 v5 = k;
  if (spr_table1534[k] >= 0x60 || (spr_table1534[k] & 2) != 0)
    Spr09D_BubbleWithSprite_Draw(k);
  if (spr_current_status[k] == 2) {
    spr_current_status[k] = 8;
LABEL_20:
    if (spr_table1534[k] >= 7)
      spr_table1534[k] = 6;
    return;
  }
  if (flag_sprites_locked)
    return;
  if ((counter_global_frames & 1) == 0 && --spr_table1534[k] == 4)
    io_sound_ch3 = 25;
  if (spr_table1534[k] != 1) {
    if ((uint8)(spr_table1534[k] - 1) < 7)
      return;
    SubOffscreen_Bank02_Entry1(k);
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
    HandleNormalSpriteLevelCollision(k);
    spr_xspeed[k] = kSpr09D_BubbleWithSprite_BubbleSprGfxProp2[spr_table157c[k]];
    if ((counter_global_frames & 1) == 0) {
      uint8 v6 = spr_table151c[k] & 1;
      uint8 v7 = kSpr09D_BubbleWithSprite_BubbleSprGfxProp3[v6] + spr_yspeed[k];
      spr_yspeed[k] = v7;
      if (v7 == kSpr09D_BubbleWithSprite_BubbleSprGfxProp4[v6])
        ++spr_table151c[k];
    }
    if (!spr_table1588[k]) {
      CheckNormalSpriteToNormalSpriteCollision(k);
      if (!(CheckPlayerToNormalSpriteCollision(k) & 1))
        return;
      player_yspeed = 0;
      player_xspeed = 0;
    }
    goto LABEL_20;
  }
  uint8 v8 = kSpr09D_BubbleWithSprite_BubbleSprites[spr_table00c2[k]];
  spr_spriteid[k] = v8;
  uint8 kb = v8;
  InitializeNormalSpriteRAMTables(v5);
  uint8 v9 = 32;
  if (kb == 116)
    v9 = 4;
  spr_decrementing_table154c[v5] = v9;
  if (spr_spriteid[v5] == 13)
    --spr_decrementing_table1540[v5];
  spr_table157c[v5] = CheckPlayerPositionRelativeToSprite_Bank23_X(v5);
}

void Spr09D_BubbleWithSprite_Draw(uint8 k) {  // 02d9d6
  if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
    return;
  R2_ = kSpr09D_BubbleWithSprite_DATA_02D9D2[(counter_local_frames >> 3) & 3];
  uint8 v1 = spr_oamindex[k] - 20;
  spr_oamindex[k] = v1;
  uint8 v2 = v1;
  R3_ = spr_table1534[k];
  int8 v3 = 4;
  do {
    uint8 v7 = v3;
    uint8 v4 = R2_ + v3;
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam[64].xpos = kSpr09D_BubbleWithSprite_XDisp[v4] + R0_;
    oam[64].ypos = kSpr09D_BubbleWithSprite_YDisp[v4] + R1_;
    oam[64].charnum = kSpr09D_BubbleWithSprite_Tiles[v7];
    oam[64].flags = sprites_tile_priority | kSpr09D_BubbleWithSprite_Prop[v7];
    if (R3_ < 6) {
      oam[64].flags = sprites_tile_priority | 2;
      oam[64].charnum = R3_ < 3 ? 0x66 : 0x64;
    }
    sprites_oamtile_size_buffer[(v2 >> 2) + 64] = kSpr09D_BubbleWithSprite_TileSize[v7];
    v2 += 4;
    v3 = v7 - 1;
  } while (v3 >= 0);
  Spr070_Pokey_Bank02SpriteEntry(k, 0xFF, 4);
}

void Spr09B_HammerBro_Init(uint8 k) {  // 02da59
  ;
}

void Spr09B_HammerBro(uint8 k) {  // 02da5a
  spr_table157c[k] = 0;
  if (spr_current_status[k] == 2) {
    Spr09B_HammerBro_Draw(k);
  } else if (!flag_sprites_locked) {
    CheckPlayerAndNormalSpriteCollisions(k);
    SubOffscreen_Bank02_Entry2(k);
    uint8 v1 = ow_players_map[player_current_character];
    if ((counter_global_frames & 3) != 0)
      ++spr_table1570[k];
    int8 v2 = 2 * spr_table1570[k];
    if (v1)
      v2 = 4 * spr_table1570[k];
    spr_table157c[k] = v2 & 0x40;
    if (!(spr_decrementing_table1540[k] |
          (uint8)(spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k] | kSpr09B_HammerBro_HammerFreq[v1] & spr_table1570[k]))) {
      spr_decrementing_table1540[k] = 3;
      R0_ = spr_table157c[k] ? 16 : -16;
      uint8 j = 7;
      while (ext_spr_spriteid[j]) {
        if ((--j & 0x80) != 0)
          return;
      }
      ext_spr_spriteid[j] = 4;
      SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], GetSprXPos(k));
      SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], GetSprYPos(k));
      ext_spr_yspeed[j] = -48;
      ext_spr_xspeed[j] = R0_;
    }
  }
}

void Spr09B_HammerBro_Draw(uint8 k) {  // 02dafd
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  R2_ = spr_table157c[k];
  uint8 v2 = 3;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSpr09B_HammerBro_XDisp[v2] + R0_;
    oam[64].ypos = kSpr09B_HammerBro_YDisp[v2] + R1_;
    uint8 v5 = v2;
    uint8 v4 = R2_;
    oam[64].flags = R2_ | 0x37;
    if (v4)
      v2 += 4;
    oam[64].charnum = kSpr09B_HammerBro_Tiles[v2];
    sprites_oamtile_size_buffer[(drt >> 2) + 64] = kSpr09B_HammerBro_TileSize[v5];
    drt += 4;
    v2 = v5 - 1;
  } while ((int8)v2 >= 0);
  Spr070_Pokey_Bank02SpriteEntry(k, 0xFF, 3);
}

void Spr09C_HammerBroPlatform(uint8 k) {  // 02db5c
  Spr09C_HammerBroPlatform_Draw(k);
  spr_table1594[k] = -1;
  uint8 j = 9;
  while (spr_current_status[j] != 8 || spr_spriteid[j] != 0x9B) {
    if ((--j & 0x80) != 0)
      goto LABEL_7;
  }
  spr_table1594[k] = j;
  SetSprXYPos(j, GetSprXPos(k), GetSprYPos(k) - 16);
  Spr09B_HammerBro_Draw(j);
LABEL_7:
  if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry2(k);
    if ((counter_global_frames & 1) == 0) {
      uint8 v3 = spr_table1534[k] & 1;
      uint8 v4 = kSpr09C_HammerBroPlatform_XAcceleration[v3] + spr_xspeed[k];
      spr_xspeed[k] = v4;
      if (v4 == kSpr09C_HammerBroPlatform_MaxXSpeed[v3])
        ++spr_table1534[k];
      uint8 v5 = spr_table151c[k] & 1;
      uint8 v6 = kSpr09C_HammerBroPlatform_YAcceleration[v5] + spr_yspeed[k];
      spr_yspeed[k] = v6;
      if (v6 == kSpr09C_HammerBroPlatform_MaxYSpeed[v5])
        ++spr_table151c[k];
    }
    UpdateNormalSpritePosition_Y(k);
    spr_table1528[k] = UpdateNormalSpritePosition_X(k);
    SolidSpriteBlock(k);
    if (spr_decrementing_table1558[k]) {
      spr_table00c2[k] = 1;
      CheckPlayerPositionRelativeToSprite_Bank23_X(k);
      if (!sign8(R15_ - 8))
        ++spr_table00c2[k];
      uint8 v7 = spr_table1594[k];
      if ((v7 & 0x80) == 0) {
        spr_current_status[v7] = 2;
        spr_yspeed[v7] = -64;
        SpawnContactEffectFromSide(v7);
      }
    }
  }
}

void Spr09C_HammerBroPlatform_Draw(uint8 k) {  // 02dc3f
  if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
    return;
  R7_ = spr_table00c2[k];
  R5_ = kSpr09C_HammerBroPlatform_BounceYDisp[spr_decrementing_table1558[k] >> 1];
  uint8 v1 = spr_oamindex[k];
  R2_ = (counter_local_frames >> 1) & 4;
  uint8 v2 = 3;
  do {
    R6_ = v2;
    uint8 v3 = R2_ | v2;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].xpos = kSpr09C_HammerBroPlatform_XDisp[v3] + R0_;
    oam[64].ypos = kSpr09C_HammerBroPlatform_YDisp[v3] + R1_;
    if (R6_ < 2 && R6_ + 1 == R7_)
      oam[64].ypos -= R5_;
    oam[64].charnum = kSpr09C_HammerBroPlatform_Tiles[v3];
    oam[64].flags = kSpr09C_HammerBroPlatform_Prop[v3];
    sprites_oamtile_size_buffer[(v1 >> 2) + 64] = kSpr09C_HammerBroPlatform_TileSize[v3];
    v1 += 4;
    v2 = R6_ - 1;
  } while ((int8)(R6_ - 1) >= 0);
  Spr070_Pokey_Bank02SpriteEntry(k, 0xFF, 3);
}

void Spr09A_SumoBro(uint8 k) {  // 02dcb7
  Spr09A_SumoBro_Draw(k);
  if (!flag_sprites_locked && spr_current_status[k] == 8) {
    SubOffscreen_Bank02_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    HandleNormalSpriteGravity(k);
    if ((spr_table1588[k] & 4) != 0) {
      spr_yspeed[k] = 0;
      spr_xspeed[k] = 0;
    }
    uint8 v1 = spr_table00c2[k];
    if (v1) {
      switch (v1) {
      case 1:
        if (!spr_decrementing_table1540[k]) {
          ++spr_table1602[k];
          Spr09A_SumoBro_02DCF9(k, 3);
        }
        break;
      case 2:
        if (spr_decrementing_table1558[k]) {
          spr_table1602[k] = 1;
        } else {
          spr_xspeed[k] = kSpr09A_SumoBro_XSpeed[spr_table157c[k]];
          if (!spr_decrementing_table1540[k]) {
            if ((++spr_table1570[k] & 1) == 0)
              spr_decrementing_table1558[k] = 32;
            if (spr_table1570[k] == 3) {
              spr_table1570[k] = 0;
              Spr09A_SumoBro_02DCF9(k, 0x70);
            } else {
              Spr09A_SumoBro_02DD3F(k, 3);
            }
          }
        }
        break;
      case 3: {
        uint8 v2 = 3;
        uint8 v3 = spr_decrementing_table1540[k];
        if (v3) {
          if (v3 == 46) {
            if (!(spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k])) {
              timer_shake_layer1 = 48;
              io_sound_ch3 = 9;
              Spr09A_SumoBro_GenSumoLightning(k);
            }
            v2 = 3;
          }
          if (v3 >= 0x30 && v3 < 0x50) {
            v2 = 4;
            if (v3 < 0x44)
              v2 = 5;
          }
          spr_table1602[k] = v2;
        } else {
          spr_table157c[k] ^= 1;
          Spr09A_SumoBro_02DD3F(k, 0x40);
        }
        break;
      }
      default: Unreachable(); break;
      }
    } else {
      spr_table1602[k] = 1;
      if (!spr_decrementing_table1540[k]) {
        spr_table1602[k] = 0;
        Spr09A_SumoBro_02DCF9(k, 3);
      }
    }
  }
}

void Spr09A_SumoBro_02DCF9(uint8 k, uint8 a) {  // 02dcf9
  spr_decrementing_table1540[k] = a;
  ++spr_table00c2[k];
}

void Spr09A_SumoBro_02DD3F(uint8 k, uint8 a) {  // 02dd3f
  Spr09A_SumoBro_02DCF9(k, a);
  spr_table00c2[k] = 0;
}

void Spr09A_SumoBro_GenSumoLightning(uint8 k) {  // 02dd8f
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) == 0) {
    spr_spriteid[j] = 43;
    spr_current_status[j] = 8;
    SetSprXPos(j, GetSprXPos(k) + 4);
    SetSprYPos(j, GetSprYPos(k));
    InitializeNormalSpriteRAMTables(j);
    spr_decrementing_table1fe2[j] = 16;
  }
}

void Spr09A_SumoBro_Draw(uint8 k) {  // 02de3e
  if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
    return;
  uint8 v1 = spr_table157c[k];
  int8 v2 = v1 & 1;
  uint8 v3 = v1 >> 1;
  int8 v4 = 0;
  if (v2)
    v4 = 0x80;
  v2 = v3 & 1;
  uint8 v5 = (v3 >> 1) + v4;
  int8 v6 = 0;
  if (v2)
    v6 = 0x80;
  R2_ = ((v5 >> 1) + v6) & 0x40 ^ 0x40;
  uint8 v7 = spr_oamindex[k];
  uint8 v8 = 4 * spr_table1602[k];
  R5_ = 3;
  do {
    uint8 v11 = v8;
    if (R2_)
      v8 += 24;
    OamEnt *oam = get_OamEnt(oam_buf, v7);
    oam[64].xpos = kSpr09A_SumoBro_XDisp[v8] + R0_;
    oam[64].ypos = kSpr09A_SumoBro_YDisp[v11] + R1_;
    uint8 v10 = kSpr09A_SumoBro_Tiles[v11];
    oam[64].charnum = v10;
    oam[64].flags = R2_ + (v10 != 102) + 52;
    sprites_oamtile_size_buffer[(v7 >> 2) + 64] = kSpr09A_SumoBro_TileSize[v11];
    v7 += 4;
    v8 = v11 + 1;
    --R5_;
  } while ((R5_ & 0x80) == 0);
  Spr070_Pokey_Bank02SpriteEntry(k, 0xFF, 3);
}

void Spr02B_SumoLightning(uint8 k) {  // 02deb0
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    R2_ = spr_decrementing_table1540[k];
    if (v1 == 1)
      spr_current_status[k] = 0;
    if ((v1 & 0xF) == 1) {
      flag_run_cluster_sprites = 1;
      Spr02B_SumoLightning_02DF2C(k);
      if (++spr_table1570[k] != 1) {
        Spr02B_SumoLightning_02DF2C(k);
        ++spr_table1570[k];
      }
    }
  } else {
    spr_yspeed[k] = 48;
    UpdateNormalSpritePosition_Y(k);
    if (!spr_decrementing_table1fe2[k]) {
      HandleNormalSpriteLevelCollision(k);
      if ((spr_table1588[k] & 4) != 0) {
        io_sound_ch3 = 23;
        spr_decrementing_table1540[k] = 34;
        if (!(spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k])) {
          LOBYTE(blocks_xpos) = GetSprXPos(k);
          LOBYTE(blocks_ypos) = GetSprYPos(k);
          SpawnSmokePuff();
        }
      }
    }
    GenericGFXRtDraw4Tiles8x8Square(k, 0);
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    oam[65].flags ^= 0xC0;
  }
}

void Spr02B_SumoLightning_02DF2C(uint8 k) {  // 02df2c
  R0_W = GetSprXPos(k);
  uint8 j = 9;
  while (cluster_spr_spriteid[j]) {
    if ((--j & 0x80) != 0) {
      if ((--cluster_spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
        cluster_spr_slot_to_overwrite_when_slots_full = 9;
      j = cluster_spr_slot_to_overwrite_when_slots_full;
      break;
    }
  }
  uint8 v2 = spr_table1570[k];
  SetHiLo(&cluster_spr_xpos_hi[j], &cluster_spr_xpos_lo[j],
      PAIR16(kSpr02B_SumoLightning_FireInitialXPosHi[v2], kSpr02B_SumoLightning_FireInitialXPosLo[v2]) + R0_W);
  cluster_spr_ypos_lo[j] = spr_ypos_lo[k] - 16;
  cluster_spr_ypos_hi[j] = spr_ypos_hi[k];  // bug wtf?
  cluster_spr_table0f4a[j] = 127;
  if (cluster_spr_xpos_hi[j] ==
        ((cluster_spr_xpos_lo[j] < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)))
    cluster_spr_spriteid[j] = 6;
}

void Spr099_VolcanoLotus(uint8 k) {  // 02df93
  Spr099_VolcanoLotus_Draw(k);
  if (flag_sprites_locked)
    return;
  spr_table151c[k] = 0;
  CheckPlayerAndNormalSpriteCollisions(k);
  SubOffscreen_Bank02_Entry1(k);
  UpdateNormalSpritePosition_Y(k);
  if (sign8(spr_yspeed[k] - 64))
    ++spr_yspeed[k];
  HandleNormalSpriteLevelCollision(k);
  if ((spr_table1588[k] & 4) != 0)
    spr_yspeed[k] = 0;
  uint8 v1 = spr_table00c2[k];
  switch (v1) {
  case 0:;
    uint8 v2 = spr_decrementing_table1540[k];
    if (v2) {
      spr_table1602[k] = (v2 & 8) != 0;
      return;
    }
    goto LABEL_12;
  case 1: {
    uint8 v3 = spr_decrementing_table1540[k];
    if (v3) {
      spr_table151c[k] = (v3 & 2) != 0;
      return;
    }
LABEL_12:
    sub_2DFD0(k, 0x40);
    return;
  }
  case 2: {
    uint8 v4 = spr_decrementing_table1540[k];
    if (!v4) {
      sub_2DFD0(k, 0x80);
      spr_table00c2[k] = 0;
    }
    if (v4 == 56)
      Spr099_VolcanoLotus_02E079(k);
    spr_table1602[k] = 2;
    break;
  }
  default: Unreachable(); break;
  }
}

void sub_2DFD0(uint8 k, uint8 a) {  // 02dfd0
  spr_decrementing_table1540[k] = a;
  ++spr_table00c2[k];
}

void Spr099_VolcanoLotus_Draw(uint8 k) {  // 02e00b
  Spr08F_ScalePlatform_Draw(k);
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].charnum = -50;
  oam[65].charnum = -50;
  int8 v2 = oam[64].flags & 0x30 | 0xB;
  oam[64].flags = v2;
  oam[65].flags = v2 | 0x40;
  int8 v3 = oam[64].xpos + 8;
  oam[66].xpos = v3;
  oam[67].xpos = v3 + 8;
  int8 ypos = oam[64].ypos;
  oam[66].ypos = ypos;
  oam[67].ypos = ypos;
  uint8 v5 = kSpr099_VolcanoLotus_Tiles[spr_table1602[k]];
  oam[66].charnum = v5;
  oam[67].charnum = v5 + 1;
  int8 v6 = 57;
  if (spr_table151c[k])
    v6 = 53;
  oam[66].flags = v6;
  oam[67].flags = v6;
  spr_oamindex[k] += 8;
  Spr070_Pokey_Bank02SpriteEntry(k, 0, 1);
}

void Spr099_VolcanoLotus_02E079(uint8 k) {  // 02e079
  if (!(spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k])) {
    R0_ = 3;
    do {
      uint8 j = 7;
      while (ext_spr_spriteid[j]) {
        if ((--j & 0x80) != 0)
          return;
      }
      ext_spr_spriteid[j] = 12;
      SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], GetSprXPos(k) + 4);
      SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], GetSprYPos(k));
      ext_spr_xspeed[j] = kSpr099_VolcanoLotus_FireInitialXSpeed[R0_];
      ext_spr_yspeed[j] = kSpr099_VolcanoLotus_FireInitialYSpeed[R0_];
    } while ((--R0_ & 0x80) == 0);
  }
}

void Spr04F_JumpingPiranhaPlant(uint8 k) {  // 02e0cd
  InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
  uint8 v6 = sprites_tile_priority;
  sprites_tile_priority = 16;
  spr_table1602[k] = ((uint8)(spr_table1570[k] & 8) >> 2) ^ 2;
  GenericGFXRtDraw1Tile16x16(k);
  spr_oamindex[k] += 4;
  spr_table1602[k] = ((uint8)(spr_table151c[k] & 4) >> 2) + 1;
  uint16 old_y = GetSprYPos(k);
  AddSprYPos(k, 8);
  spr_table15f6[k] = 10;
  GenericGFXRtDraw4Tiles8x8Square(k, 1);
  SetSprYPos(k, old_y);
  sprites_tile_priority = v6;
  if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    UpdateNormalSpritePosition_Y(k);
    uint8 v1 = spr_table00c2[k];
    if (v1) {
      if (v1 == 1) {
        int8 v2 = spr_yspeed[k];
        if (v2 <= 63)
          spr_yspeed[k] = v2 + 2;
        ++spr_table1570[k];
        if (!sign8(spr_yspeed[k] + 16)) {
          spr_decrementing_table1540[k] = 80;
          ++spr_table00c2[k];
        }
      } else if (v1 == 2) {
        ++spr_table151c[k];
        uint8 v3 = spr_decrementing_table1540[k];
        if (v3 && spr_spriteid[k] == 80 && (spr_table1570[k] = 0, v3 == 64) && !(spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k])) {
          SprXXX_JumpingPiranhaPlant_02E1C0(k, 0x10);
          SprXXX_JumpingPiranhaPlant_02E1C0(k, 0xF0);
        } else {
          SprXXX_JumpingPiranhaPlant_02E17F(k);
        }
      } else {
        Unreachable();
      }
    } else {
      spr_yspeed[k] = 0;
      if (!spr_decrementing_table1540[k]) {
        CheckPlayerPositionRelativeToSprite_Bank23_X(k);
        if ((uint8)(R15_ + 27) >= 0x37) {
          spr_yspeed[k] = -64;
          ++spr_table00c2[k];
          spr_table1602[k] = 0;
        }
      }
    }
  }
}

void SprXXX_JumpingPiranhaPlant_02E17F(uint8 k) {  // 02e17f
  ++spr_table1570[k];
  if ((counter_local_frames & 3) == 0 && sign8(spr_yspeed[k] - 8))
    ++spr_yspeed[k];
  HandleNormalSpriteLevelCollision(k);
  if ((spr_table1588[k] & 4) != 0) {
    spr_table00c2[k] = 0;
    spr_decrementing_table1540[k] = 64;
  }
}

void SprXXX_JumpingPiranhaPlant_02E1C0(uint8 k, uint8 a) {  // 02e1c0
  R0_ = a;
  uint8 j = 7;
  while (ext_spr_spriteid[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  ext_spr_spriteid[j] = 11;
  SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], GetSprXPos(k) + 4);
  SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], GetSprYPos(k));
  ext_spr_yspeed[j] = -48;
  ext_spr_xspeed[j] = R0_;
  SprXXX_JumpingPiranhaPlant_02E17F(k);
}

void Spr045_DirectionalCoins(uint8 k) {  // 02e21d
  uint8 v7 = sprites_tile_priority;
  if (spr_decrementing_table1540[k] >= 0x30)
    sprites_tile_priority = 16;
  uint16 old_ypos = mirror_current_layer1_ypos;
  mirror_current_layer1_ypos += 1;
  if (timer_blue_pswitch) {
    GenericGFXRtDraw1Tile16x16(k);
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    oam[64].charnum = 46;
    oam[64].flags &= 0x3F;
  } else {
    PowerUpAndItemGFXRt_DrawCoinSprite(k);
  }
  mirror_current_layer1_ypos = old_ypos;
  sprites_tile_priority = v7;
  if (!flag_sprites_locked) {
    if ((counter_global_frames & 3) == 0 && !--spr45_directional_coins_despawn_timer)
      goto LABEL_20;
    uint8 v3 = spr_table00c2[k];
    spr_xspeed[k] = kSpr045_DirectionalCoins_XSpeed[v3];
    spr_yspeed[k] = kSpr045_DirectionalCoins_YSpeed[v3];
    UpdateNormalSpritePosition_Y(k);
    UpdateNormalSpritePosition_X(k);
    if ((io_controller_hold1 & 0xF) != 0) {
      uint8 v4 = kSpr045_DirectionalCoins_DATA_02E201[io_controller_hold1 & 0xF];
      if (kSpr045_DirectionalCoins_DATA_02E211[v4] != spr_table00c2[k])
        spr_table151c[k] = v4;
    }
    R0_ = spr_ypos_lo[k] & 0xF;
    if (!(R0_ | spr_xpos_lo[k] & 0xF)) {
      spr_table00c2[k] = spr_table151c[k];
      blocks_xpos = GetSprXPos(k);
      blocks_ypos = GetSprYPos(k);
      blocks_map16_to_generate = 6;
      GenerateTile();
      return;
    }
  }
  HandleNormalSpriteLevelCollision(k);
  if (!spr_xspeed[k]) {
    if (!sprites_map16_tile_being_touched_vertically_hi && sprites_map16_tile_touched_vert_lo == 37)
      return;
LABEL_20:
    Spr045_DirectionalCoins_02E271(k);
    return;
  }
  if (sprites_map16_tile_touched_horiz_hi || sprites_map16_tile_touched_horiz_lo != 37)
    goto LABEL_20;
}

void Spr045_DirectionalCoins_02E271(uint8 k) {  // 02e271
  spr45_directional_coins_despawn_timer = 0;
  spr_current_status[k] = 0;
  if (!__PAIR16__(timer_silver_pswitch, timer_blue_pswitch) && (misc_music_register_backup & 0x80) == 0)
    io_music_ch1 = misc_music_register_backup;
}

void Spr090_GreenGasBubble(uint8 k) {  // 02e311
  Spr090_GreenGasBubble_Draw(k);
  if (!flag_sprites_locked && spr_current_status[k] == 8) {
    spr_xspeed[k] = kSpr090_GreenGasBubble_XSpeed[spr_table157c[k]];
    UpdateNormalSpritePosition_X(k);
    if ((counter_global_frames & 3) == 0) {
      uint8 v1 = spr_table00c2[k] & 1;
      uint8 v2 = kSpr090_GreenGasBubble_Acceleration[v1] + spr_yspeed[k];
      spr_yspeed[k] = v2;
      if (v2 == kSpr090_GreenGasBubble_MaxYSpeed[v1])
        ++spr_table00c2[k];
    }
    UpdateNormalSpritePosition_Y(k);
    ++spr_table1570[k];
    SubOffscreen_Bank02_Entry1(k);
    CheckPlayerToNormalSpriteCollision(k);
  }
}

void Spr090_GreenGasBubble_Draw(uint8 k) {  // 02e3aa
  if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
    return;
  uint8 v1 = (spr_table1570[k] >> 3) & 3;
  R2_ = kSpr090_GreenGasBubble_DATA_02E3A2[v1];
  R3_ = kSpr090_GreenGasBubble_DATA_02E3A6[v1];
  uint8 v2 = spr_oamindex[k];
  for (uint8 i = 15; (i & 0x80) == 0; --i) {
    int8 v7 = kSpr090_GreenGasBubble_DATA_02E352[i] + R0_;
    int8 v4;
    if ((kSpr090_GreenGasBubble_DATA_02E392[i] & 2) != 0)
      v4 = v7 - R2_;
    else
      v4 = R2_ + v7;
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam[64].xpos = v4;
    int8 v8 = kSpr090_GreenGasBubble_DATA_02E362[i] + R1_;
    int8 v6;
    if ((kSpr090_GreenGasBubble_DATA_02E392[i] & 1) != 0)
      v6 = v8 - R3_;
    else
      v6 = R3_ + v8;
    oam[64].ypos = v6;
    oam[64].charnum = kSpr090_GreenGasBubble_Tiles[i];
    oam[64].flags = kSpr090_GreenGasBubble_Prop[i];
    v2 += 4;
  }
  Spr070_Pokey_Bank02SpriteEntry(k, 2, 0xF);
}

void Spr04C_ExplodingBlock(uint8 k) {  // 02e41f
  GenericGFXRtDraw1Tile16x16(k);
  if (!flag_sprites_locked) {
    uint8 v1 = 0;
    if ((++spr_table1570[k] & 0x40) != 0) {
      v1 = 4;
      if ((spr_table1570[k] & 4) != 0)
        v1 = -4;
    }
    spr_xspeed[k] = v1;
    UpdateNormalSpritePosition_X(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    CheckPlayerPositionRelativeToSprite_Bank23_X(k);
    if ((uint8)(R15_ + 96) < 0xC0 && !spr_xoffscreen_flag[k])
      ShatterExplodingBlock(k);
  }
}

void ShatterExplodingBlock(uint8 k) {  // 02e463
  spr_spriteid[k] = spr_table00c2[k];
  InitializeNormalSpriteRAMTables(k);
  spr_yspeed[k] = -48;
  spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
  blocks_xpos = GetSprXPos(k);
  blocks_ypos = GetSprYPos(k);
  SpawnBrickPieces(0);
}

void Spr08F_ScalePlatform(uint8 k) {  // 02e495
  uint8 v1 = spr_oamindex[k];
  Spr08F_ScalePlatform_Sub(k);
  spr_oamindex[k] = v1;
}

void Spr08F_ScalePlatform_Sub(uint8 k) {  // 02e4a5
  SubOffscreen_Bank02_Entry3(k);
  misc_scratch7e185e = 0;
  uint16 old_x = GetSprXPos(k), old_y = GetSprYPos(k);
  SetSprYPos(k, PAIR16(spr_table151c[k], spr_table1534[k]));
  SetSprXPos(k, PAIR16(spr_table1602[k], spr_table00c2[k]));
  uint8 ret = Spr08F_ScalePlatform_02E524(k, 2);
  SetSprXPos(k, old_x);
  SetSprYPos(k, old_y);
  if (ret) {
    ++misc_scratch7e185e;
    Spr08F_ScalePlatform_02E559(k, 0xF8);
  }
  spr_oamindex[k] += 8;
  if (Spr08F_ScalePlatform_02E524(k, 0)) {
    ++misc_scratch7e185e;
    Spr08F_ScalePlatform_02E559(k, 8);
  }
  if (!misc_scratch7e185e) {
    uint8 v1 = 2;
    uint8 v2 = spr_ypos_lo[k];
    if (v2 != spr_table1534[k]) {
      if ((int8)(spr_ypos_hi[k] - ((v2 < spr_table1534[k]) + spr_table151c[k])) >= 0)
        v1 = -2;
      Spr08F_ScalePlatform_02E559(k, v1);
    }
  }
}

uint8 Spr08F_ScalePlatform_02E524(uint8 k, uint8 j) {  // 02e524
  if ((spr_ypos_lo[k] & 0xF) == 0 && spr_yspeed[k]) {
    if ((spr_yspeed[k] & 0x80) != 0)
      ++j;
    blocks_map16_to_generate = kSpr08F_ScalePlatform_MushrmScaleTiles[j];
    blocks_xpos = GetSprXPos(k);
    blocks_ypos = GetSprYPos(k);
    GenerateTile();
  }
  Spr08F_ScalePlatform_Draw(k);
  spr_table1528[k] = 0;
  return SolidSpriteBlock(k);
}

void Spr08F_ScalePlatform_02E559(uint8 k, uint8 a) {  // 02e559
  if (!flag_sprites_locked) {
    UpdateNormalSpritePosition_Y(k);
    spr_yspeed[k] = a;
    AddHiLo(&spr_table151c[k], &spr_table1534[k], -(int8)sprites_position_disp);
  }
}

void Spr08F_ScalePlatform_Draw(uint8 k) {  // 02e57e
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  int8 v2 = R0_ - 8;
  OamEnt *oam = get_OamEnt(oam_buf, drt);
  oam[64].xpos = R0_ - 8;
  oam[65].xpos = v2 + 16;
  int8 v4 = R1_ - 1;
  oam[64].ypos = R1_ - 1;
  oam[65].ypos = v4;
  oam[64].charnum = 0x80;
  oam[65].charnum = 0x80;
  int8 v5 = sprites_tile_priority | spr_table15f6[k];
  oam[64].flags = v5;
  oam[65].flags = v5 | 0x40;
  Spr070_Pokey_Bank02SpriteEntry(k, 2, 1);
}

void Spr052_MovingLedgeHole(uint8 k) {  // 02e5bc
  SubOffscreen_Bank02_Entry1(k);
  if (!flag_sprites_locked) {
    ++spr_table1570[k];
    spr_xspeed[k] = ((spr_table1570[k] & 0x80) == 0) ? -16 : 16;
    UpdateNormalSpritePosition_X(k);
  }
  Spr052_MovingLedgeHole_Draw(k);
  Spr052_MovingLedgeHole_02E5F7(k);
  if (!player_disable_object_interaction_flag || player_disable_object_interaction_flag - 1 == k) {
    uint8 v2 = CheckPlayerToNormalSpriteCollision(k);
    player_disable_object_interaction_flag = (v2 & 1) ? k + 1 : 0;
  }
}

void Spr052_MovingLedgeHole_02E5F7(uint8 k) {  // 02e5f7
  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    if (i != k && ((counter_global_frames ^ i) & 3) == 0 && spr_current_status[i] >= 8) {
      uint8 v2 = spr_no_level_collision_flag[i];
      if (!v2 || v2 - 1 == k) {
        StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(i);
        StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
        uint8 v4 = StandardSpriteToSpriteCollisionChecks_CheckContact();
        spr_no_level_collision_flag[i] = (v4 & 1) ? k + 1 : 0;
      }
    }
  }
}

void Spr052_MovingLedgeHole_Draw(uint8 k) {  // 02e637
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSpr052_MovingLedgeHole_XDisp[i] + R0_;
    oam[64].ypos = R1_;
    oam[64].charnum = kSpr052_MovingLedgeHole_Tiles[i];
    oam[64].flags = kSpr052_MovingLedgeHole_Prop[i];
    drt += 4;
  }
  Spr070_Pokey_Bank02SpriteEntry(k, 2, 3);
}

void Spr01E_Lakitu_LakituFishingLineDraw(uint8 k) {  // 02e67a
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  spr_oamindex[k] = drt + 8;
  int8 v2 = R0_ - 13;
  OamEnt *oam = get_OamEnt(oam_buf, (uint8)(drt + 8));
  oam[64].xpos = R0_ - 13;
  misc_scratch7e185e = v2 - 8;
  oam[65].xpos = v2 - 8;
  uint8 v4 = R1_ + 2;
  oam[64].ypos = R1_ + 2;
  misc_scratch7e18b6 = v4;
  oam[65].ypos = v4 + 64;
  oam[64].charnum = -86;
  oam[65].charnum = 36;
  oam[64].flags = 53;
  oam[65].flags = 58;
  Spr070_Pokey_Bank02SpriteEntry(k, 2, 1);
  if (!spr_xoffscreen_flag[k]) {
    OamEnt *v5 = get_OamEnt(oam_buf, spr_oamindex[k]);
    if ((uint8)(player_on_screen_pos_x - v5[65].xpos + 12) < 0x18 && (uint8)(player_on_screen_pos_y - v5[65].ypos + 12) < 0x18) {
      spr_table151c[k] = 0;
      SpawnScoreSpriteAtPlayerPosition_LakituEntry();
    }
  }
  spr_oamindex[k] = 56;
  uint8 v6 = 56;
  for (int8 i = 7; i >= 0; --i) {
    OamEnt *v8 = get_OamEnt(oam_buf, v6);
    v8[64].xpos = misc_scratch7e185e;
    uint8 v9 = misc_scratch7e18b6;
    v8[64].ypos = misc_scratch7e18b6;
    misc_scratch7e18b6 = v9 + 8;
    v8[64].charnum = -119;
    v8[64].flags = 53;
    v6 += 4;
  }
  Spr070_Pokey_Bank02SpriteEntry(k, 0, 7);
}

void Spr047_SwimmingAndJumpingCheepCheep(uint8 k) {  // 02e727
  GenericGFXRtDraw1Tile16x16(k);
  if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    HandleNormalSpriteLevelCollision(k);
    SprXXX_SuperKoopas_02EB3D(k, 0);
    kUnk_2e747[spr_table00c2[k] & 1](k);
  }
}

void Spr047_SwimmingAndJumpingCheepCheep_Swimming(uint8 k) {  // 02e74e
  spr_xspeed[k] = kSpr047_SwimmingAndJumpingCheepCheep_XSpeed[spr_table157c[k]];
  UpdateNormalSpritePosition_X(k);
  if (!spr_decrementing_table1540[k]) {
    uint8 v1 = ++spr_table1570[k];
    if (v1 == 4) {
      ++spr_table00c2[k];
      spr_decrementing_table1540[k] = 0x80;
      spr_yspeed[k] = -96;
    } else {
      spr_table157c[k] ^= 1;
      spr_decrementing_table1540[k] = (v1 != 3) ? 64 : 32;
    }
  }
}

void Spr047_SwimmingAndJumpingCheepCheep_Jumping(uint8 k) {  // 02e788
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 < 0x70) {
      spr_xspeed[k] = 0;
      UpdateNormalSpritePosition_Y(k);
      int8 v2 = spr_yspeed[k];
      if (v2 <= 47)
        spr_yspeed[k] = v2 + 2;
    }
  } else {
    spr_ypos_lo[k] &= 0xF0;
    ++spr_table00c2[k];
    spr_table1570[k] = 0;
    spr_decrementing_table1540[k] = 32;
  }
}

void Spr048_DigginChuckRock(uint8 k) {  // 02e7bd
  uint8 v4 = sprites_tile_priority;
  if (spr_decrementing_table1540[k])
    sprites_tile_priority = 16;
  GenericGFXRtDraw1Tile16x16(k);
  sprites_tile_priority = v4;
  if (!flag_sprites_locked && spr_decrementing_table1540[k] < 8) {
    SprXXX_SuperKoopas_02EB3D(k, 0);
    SubOffscreen_Bank02_Entry1(k);
    HandleNormalSpriteGravity(k);
    if (!spr_decrementing_table1540[k]) {
      if ((spr_table1588[k] & 3) != 0)
        spr_xspeed[k] = -spr_xspeed[k];
      if ((spr_table1588[k] & 8) != 0)
        spr_yspeed[k] = 16;
      if ((spr_table1588[k] & 4) != 0) {
        uint8 v1 = -32;
        if (spr_yspeed[k] >= 0x38)
          v1 = -48;
        spr_yspeed[k] = v1;
        uint8 v2 = 8;
        int8 v3 = spr_slope_surface_its_on[k];
        if (v3) {
          if (v3 < 0)
            v2 = -8;
          spr_xspeed[k] = v2;
        }
      }
    }
    CheckPlayerAndNormalSpriteCollisions(k);
  }
}

void Spr049_ShiftingPipe(uint8 k) {  // 02e845
  if ((spr_table1534[k] & 0x80) != 0) {
    Spr049_ShiftingPipe_Draw(k);
    SubOffscreen_Bank02_Entry1(k);
    if (!(spr_xoffscreen_flag[k] | flag_sprites_locked)) {
      CheckPlayerPositionRelativeToSprite_Bank23_X(k);
      if ((uint8)(R15_ + 80) < 0xA0) {
        uint8 v2 = spr_table00c2[k] & 3;
        if (++spr_table1570[k] == kSpr049_ShiftingPipe_DATA_02E839[v2]) {
          spr_table1570[k] = 0;
          ++spr_table00c2[k];
        } else {
          uint8 v3 = kSpr049_ShiftingPipe_YSpeed[v2];
          spr_yspeed[k] = v3;
          if (v3) {
            if ((spr_ypos_lo[k] & 0xF) == 0)
              Spr049_ShiftingPipe_GrowingPipeGfx(k, v2);
          }
          UpdateNormalSpritePosition_Y(k);
        }
      }
    }
    SolidSpriteBlock(k);
  } else {
    uint16 old_y = GetSprYPos(k);
    SetSprYPos(k, old_y - spr_table1534[k]);
    Spr049_ShiftingPipe_GrowingPipeGfx(k, 3);
    SetSprYPos(k, old_y);
    spr_table1534[k] -= 16;
  }
}

void Spr049_ShiftingPipe_GrowingPipeGfx(uint8 k, uint8 j) {  // 02e8ba
  misc_scratch7e185e = kSpr049_ShiftingPipe_LeftTileToSpawn[j];
  misc_scratch7e18b6 = kSpr049_ShiftingPipe_RightTileToSpawn[j];
  blocks_map16_to_generate = misc_scratch7e185e;
  blocks_xpos = GetSprXPos(k);
  blocks_ypos = GetSprYPos(k);
  GenerateTile();
  blocks_map16_to_generate = misc_scratch7e18b6;
  blocks_xpos = GetSprXPos(k) + 16;
  blocks_ypos = GetSprYPos(k);
  GenerateTile();
}

void Spr049_ShiftingPipe_Draw(uint8 k) {  // 02e902
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  uint8 v2 = R0_;
  OamEnt *oam = get_OamEnt(oam_buf, drt);
  oam[64].xpos = R0_;
  oam[65].xpos = v2 + 16;
  int8 v4 = R1_ - 1;
  oam[64].ypos = R1_ - 1;
  oam[65].ypos = v4;
  oam[64].charnum = -92;
  oam[65].charnum = -90;
  int8 v5 = sprites_tile_priority | spr_table15f6[k];
  oam[64].flags = v5;
  oam[65].flags = v5;
  Spr070_Pokey_Bank02SpriteEntry(k, 2, 1);
}

void Spr04B_PipeLakitu(uint8 k) {  // 02e93d
  uint8 v3;

  if (spr_current_status[k] == 2) {
    spr_table1602[k] = 2;
    Spr04B_PipeLakitu_Draw(k);
    return;
  }
  Spr04B_PipeLakitu_Draw(k);
  if (flag_sprites_locked)
    return;
  spr_table1602[k] = 0;
  SubOffscreen_Bank02_Entry1(k);
  CheckPlayerAndNormalSpriteCollisions(k);
  uint8 v1 = spr_table00c2[k];
  switch (v1) {
  case 0:
    if (!spr_decrementing_table1540[k]) {
      CheckPlayerPositionRelativeToSprite_Bank23_X(k);
      if ((uint8)(R15_ + 19) >= 0x36)
        sub_2E980(k, 0x90);
    }
    return;
  case 1: {
    uint8 v2 = spr_decrementing_table1540[k];
    if (!v2) {
      spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
      sub_2E980(k, 0xC);
      return;
    }
    if (v2 < 0x7C) {
      if (v2 < 0x50)
        spr_table157c[k] = (counter_global_frames & 0x20) != 0;
      return;
    }
LABEL_16:
    v3 = -8;
    goto LABEL_17;
  }
  case 2:
    if (!spr_decrementing_table1540[k]) {
      sub_2E980(k, 0x80);
      return;
    }
    goto LABEL_16;
  }
  if (v1 != 3) {
    if (v1 != 4) {
      Unreachable();
      return;
    }
    if (!spr_decrementing_table1540[k]) {
      sub_2E980(k, 0x50);
      spr_table00c2[k] = 0;
      return;
    }
    v3 = 8;
LABEL_17:
    spr_yspeed[k] = v3;
    UpdateNormalSpritePosition_Y(k);
    return;
  }
  uint8 v4 = spr_decrementing_table1540[k];
  if (v4) {
    if (v4 == 64) {
      MakeLakituThrowSpiny(k);
    } else if (v4 < 0x40) {
      ++spr_table1602[k];
    }
  } else {
    sub_2E980(k, 0x20);
  }
}

void sub_2E980(uint8 k, uint8 a) {  // 02e980
  spr_decrementing_table1540[k] = a;
  ++spr_table00c2[k];
}

void Spr04B_PipeLakitu_Draw(uint8 k) {  // 02e9ec
  uint8 drt;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  uint8 v2 = R0_;
  OamEnt *oam = get_OamEnt(oam_buf, drt);
  oam[64].xpos = R0_;
  oam[65].xpos = v2;
  uint8 v4 = R1_;
  oam[64].ypos = R1_;
  oam[65].ypos = v4 + 16;
  uint8 v5 = spr_table1602[k];
  oam[64].charnum = kSpr04B_PipeLakitu_HeadTiles[v5];
  oam[65].charnum = kSpr04B_PipeLakitu_BodyTiles[v5];
  uint8 v6 = spr_table157c[k];
  int8 v7 = v6 & 1;
  uint8 v8 = v6 >> 1;
  int8 v9 = 0;
  if (v7)
    v9 = 0x80;
  int8 v10 = ((uint8)((v8 >> 1) + v9) >> 1) ^ 0x5B;
  oam[64].flags = v10;
  oam[65].flags = v10;
  Spr070_Pokey_Bank02SpriteEntry(k, 2, 1);
}

void SetBabyYoshiDynamicGraphicsPointer(uint8 k) {  // 02ea25
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  R0_ = oam[64].charnum;
  R1_ = 0;
  oam[64].charnum = 6;
  *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[6] = 32 * R0_W + 0x8500;
  *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[6] = *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[6] + 512;
}

void CheckIfBabyYoshiCanEatNormalSprite2(uint8 k) {  // 02ea4e
  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    if (i != spr_table160e[k] && !((counter_global_frames ^ i) & 1) && i != spr_current_slotid) {
      sprites_second_tracked_sprite_index = i;
      if (spr_current_status[i] >= 8) {
        uint8 v2 = spr_spriteid[i];
        if (v2 != 112 && v2 != 14 && (v2 < 0x1D || !(growing_yoshi_timer | spr_property_bits1686[i] & 3)))
          CheckIfBabyYoshiCanEatNormalSprite_02EA8A(k, i);
      }
    }
  }
}

void CheckIfBabyYoshiCanEatNormalSprite_02EA8A(uint8 k, uint8 j) {  // 02ea8a
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(j);
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
  if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
    if (spr_decrementing_table163e[k] && (CheckIfBabyYoshiCanEatNormalSprite1(k), growing_yoshi_timer)) {
      spr_decrementing_table163e[k] = 0;
    } else {
      spr_decrementing_table163e[k] = 55;
      uint8 v2 = sprites_second_tracked_sprite_index;
      spr_table1632[v2] = 55;
      spr_table160e[k] = v2;
      spr_table157c[k] = GetSprXPos(k) >= GetSprXPos(v2);
    }
  }
}

void Spr08E_WarpHole(uint8 k) {  // 02eada
  if (CheckPlayerToNormalSpriteCollision(k)) {
    player_xspeed = 0;
    player_xpos = GetSprXPos(k) + 10;
  }
}

void Spr08E_WarpHole_Return02EAF1() {  // 02eaf1
  ;
}

void CheckPlayerToNormalSpriteColl_SpawnFeatherFromSuperKoopa(uint8 k) {  // 02eaf2
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) == 0) {
    spr_current_status[j] = 8;
    spr_spriteid[j] = 119;
    SetSprXPos(j, GetSprXPos(k));
    SetSprYPos(j, GetSprYPos(k));
    InitializeNormalSpriteRAMTables(j);
    spr_decrementing_table154c[j] = 48;
    spr_yspeed[j] = -48;
  }
}

void SprXXX_SuperKoopas(uint8 k) {  // 02eb31
  SprXXX_SuperKoopas_Draw(k);
  if (spr_current_status[k] == 2) {
    SprXXX_SuperKoopas_02EB3D(k, 4);
  } else if (!flag_sprites_locked) {
    SubOffscreen_Bank02_Entry1(k);
    CheckPlayerAndNormalSpriteCollisions(k);
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
    if (spr_spriteid[k] == 115) {
      kSprXXX_SuperKoopas_SuperKoopaPtrs[spr_table00c2[k]](k);
    } else {
      spr_xspeed[k] = kSprXXX_SuperKoopas_NonGroundedKoopaXSpeed[spr_table157c[k]];
      SprXXX_SuperKoopas_02EBF8(k);
      if ((counter_global_frames & 1) == 0 && !sign8(spr_yspeed[k] + 16))
        --spr_yspeed[k];
    }
  }
}

void SprXXX_SuperKoopas_02EB3D(uint8 k, uint8 j) {  // 02eb3d
  if ((counter_local_frames & 4) != 0)
    ++j;
  spr_table1602[k] = j;
}

void SprXXX_SuperKoopas_GroundedSuperKoopaState00_Running(uint8 k) {  // 02eb8d
  R1_ = 0;
  R0_ = 0;
  uint8 v1 = spr_table157c[k];
  uint8 v2 = spr_xspeed[k];
  if (v2 != kSprXXX_SuperKoopas_MaxXSpeed[v1]) {
    uint8 v3 = kSprXXX_SuperKoopas_XAcceleration[v1] + v2;
    if (!R1_)
      spr_xspeed[k] = v3;
    ++R0_;
  }
  if (++spr_table151c[k] == 48)
    SprXXX_SuperKoopas_02EBCA(k);
  else
    SprXXX_SuperKoopas_02EBB5(k);
}

void SprXXX_SuperKoopas_02EBB5(uint8 k) {  // 02ebb5
  uint8 v1 = (counter_global_frames & 4) != 0;
  if (!R0_)
    v1 += 6;
  spr_table1602[k] = v1;
}

void SprXXX_SuperKoopas_02EBCA(uint8 k) {  // 02ebca
  ++spr_table00c2[k];
  spr_yspeed[k] = -48;
}

void SprXXX_SuperKoopas_GroundedSuperKoopaState01_Jumping(uint8 k) {  // 02ebd1
  uint8 v1 = spr_yspeed[k] + 2;
  spr_yspeed[k] = v1;
  if (!sign8(v1 - 20))
    ++spr_table00c2[k];
  R0_ = 0;
  SprXXX_SuperKoopas_02EBB5(k);
  ++spr_table1602[k];
}

void SprXXX_SuperKoopas_GroundedSuperKoopaState02_Flying(uint8 k) {  // 02ebe7
  spr_xspeed[k] = kSprXXX_SuperKoopas_MaxXSpeed[spr_table157c[k]];
  if (spr_yspeed[k])
    spr_yspeed[k]--;
  SprXXX_SuperKoopas_02EBF8(k);
}

void SprXXX_SuperKoopas_02EBF8(uint8 k) {  // 02ebf8
  spr_table1602[k] = ((counter_global_frames & 4) != 0) ? 3 : 2;
}

void SprXXX_SuperKoopas_Draw(uint8 k) {  // 02ecde
  uint8 drt;
  uint8 v4;
  int8 v5;

  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  R2_ = spr_table157c[k];
  R5_ = spr_table15f6[k] & 0xE;
  R3_ = 4 * spr_table1602[k];
  R4_ = 0;
  do {
    uint8 v2 = R4_ + R3_;
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].ypos = kSprXXX_SuperKoopas_YDisp[(uint8)(R4_ + R3_)] + R1_;
    oam[64].charnum = kSprXXX_SuperKoopas_Tiles[v2];
    sprites_oamtile_size_buffer[(drt >> 2) + 64] = kSprXXX_SuperKoopas_TileSize[v2];
    if ((kSprXXX_SuperKoopas_Prop[v2] & 2) != 0) {
      if (spr_table1534[spr_current_slotid]) {
        v4 = kSprXXX_SuperKoopas_DATA_02ED39[(counter_local_frames & 2) != 0];
      } else {
        v4 = 8;
        if (spr_spriteid[spr_current_slotid] >= 0x72)
          v4 = 4;
      }
      v5 = (kSprXXX_SuperKoopas_Prop[v2] | v4) & ~2;
    } else {
      v5 = R5_ | kSprXXX_SuperKoopas_Prop[v2];
    }
    if (!(R2_ & 1)) {
      v2 += 36;
      v5 |= 0x40;
    }
    oam[64].flags = sprites_tile_priority | v5;
    oam[64].xpos = kSprXXX_SuperKoopas_XDisp[v2] + R0_;
    drt += 4;
  } while (++R4_ != 4);
  Spr070_Pokey_Bank02SpriteEntry(k, 0xFF, 3);
}

void Spr061_SkullRaft_Init(uint8 k) {  // 02ed8a
  sprites_floating_skull_speed = 0;
  ++spr_table00c2[k];
  R0_ = 2;
  do {
    uint8 j = FindFreeNormalSpriteSlot_HighPriority();
    if ((j & 0x80) == 0) {
      spr_current_status[j] = 8;
      spr_spriteid[j] = 97;
      SetSprYPos(j, GetSprYPos(k));
      SetSprXPos(j, GetSprXPos(k) + kSpr061_SkullRaft_Init_XPosOffset[R0_]);
      InitializeNormalSpriteRAMTables(j);
    }
  } while ((--R0_ & 0x80) == 0);
}

void Spr061_SkullRaft(uint8 k) {  // 02edd8
  if (!spr_table00c2[k] || (SubOffscreen_Bank02_Entry1(k), spr_current_status[k])) {
    GenericGFXRtDraw1Tile16x16(k);
    int8 v2 = ((counter_local_frames & 8) != 0) ? -30 : -32;
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    oam[64].charnum = v2;
    if (oam[64].ypos < 0xF0)
      oam[64].ypos += 3;
    if (!flag_sprites_locked) {
      R0_ = 0;
      for (uint8 i = 9; (i & 0x80) == 0; --i) {
        if (spr_current_status[i] && spr_spriteid[i] == 97 && (spr_table1588[i] & 0xF) != 0)
          R0_ = spr_table1588[i] & 0xF;
      }
      spr_xspeed[k] = sprites_floating_skull_speed;
      if (!sign8(spr_yspeed[k] - 32))
        spr_yspeed[k] = 32;
      HandleNormalSpriteGravity(k);
      if ((spr_table1588[k] & 4) != 0)
        spr_yspeed[k] = 16;
      if (CheckPlayerToNormalSpriteCollision(k) && (player_yspeed & 0x80) == 0) {
        sprites_floating_skull_speed = 12;
        OamEnt *v5 = get_OamEnt(oam_buf, spr_oamindex[k]);
        ++v5[64].ypos;
        misc_player_on_solid_sprite = 1;
        player_in_air_flag = 0;
        R1_ = player_riding_yoshi_flag ? 44 : 28;
        player_ypos = GetSprYPos(k) - R1_;
        if ((player_blocked_flags & 1) == 0)
          player_xpos += (int8)sprites_position_disp;
      }
    }
  } else {
    for (uint8 j = 9; (j & 0x80) == 0; --j) {
      if (spr_spriteid[j] == 97)
        spr_current_status[j] = 0;
    }
  }
}

void Spr06A_CoinGameCloud(uint8 k) {  // 02eeb5
  if (!spr_table00c2[k]) {
    ++spr_table00c2[k];
    counter_pink_berry_cloud_coins = 0;
  }
  if (!flag_sprites_locked) {
    if ((counter_local_frames & 0x7F) == 0 && spr_table1570[k] < 0xB) {
      ++spr_table1570[k];
      Spr06A_CoinGameCloud_02EF67(k);
    }
    if ((counter_local_frames & 1) == 0) {
      R0_W = GetSprYPos(k);
      R2_W = 0x110;
      bool v1 = R0_W >= R2_W;
      if (spr_table1570[k] >= 0xB) {
        SubOffscreen_Bank02_Entry1(k);
        v1 = 1;
      }
      uint8 v2 = spr_yspeed[k];
      if (v2 != kSpr06A_CoinGameCloud_MaxYSpeed[v1])
        spr_yspeed[k] = kSpr06A_CoinGameCloud_Acceleration[v1] + v2;
    }
    UpdateNormalSpritePosition_Y(k);
    spr_xspeed[k] = 8;
    UpdateNormalSpritePosition_X(k);
  }
  uint8 v4 = spr_oamindex[k];
  spr_oamindex[k] = v4 + 4;
  GenericGFXRtDraw1Tile16x16(k);
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].charnum = 96;
  oam[64].flags = (8 * counter_local_frames) & 0xC0 | 0x30;
  spr_oamindex[k] = v4;
  if (GetDrawInfo_Bank23_ReturnsTwice(k) == 0xff)
    return;
  oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].xpos = R0_ + 4;
  oam[64].ypos = R1_ + 4;
  oam[64].charnum = 77;
  oam[64].flags = 57;
  Spr070_Pokey_Bank02SpriteEntry(k, 0, 0);
}

void Spr06A_CoinGameCloud_02EF67(uint8 k) {  // 02ef67
  if (counter_pink_berry_cloud_coins < 0xA) {
    if (spr_table1570[k] < 0xB) {
      uint8 v2 = 7;
      while (ext_spr_spriteid[v2]) {
        if ((--v2 & 0x80) != 0)
          return;
      }
      ext_spr_spriteid[v2] = 10;
      SetHiLo(&ext_spr_xpos_hi[v2], &ext_spr_xpos_lo[v2], GetSprXPos(k) + 4);
      SetHiLo(&ext_spr_ypos_hi[v2], &ext_spr_ypos_lo[v2], GetSprYPos(k));
      ext_spr_yspeed[v2] = -48;
      ext_spr_xspeed[v2] = 0;
      ext_spr_table1765[v2] = 0;
    }
  } else {
    uint8 v1 = 11;
    while (spr_current_status[v1]) {
      if (--v1 == 9)
        return;
    }
    spr_current_status[v1] = 8;
    spr_spriteid[v1] = 120;
    SetSprXPos(v1, GetSprXPos(k));
    SetSprYPos(v1, GetSprYPos(k));
    InitializeNormalSpriteRAMTables(v1);
    spr_yspeed[v1] = -32;
    ++spr_table157c[v1];
  }
}

void Spr086_Wiggler_Init(uint8 k) {  // 02eff2
  Spr086_Wiggler_Init_GetWigglerSegmentPosIndex(k);
  for (int i = 126; i >= 0; i -= 2) {
    IndirWriteByte(&spr86_wiggler_segment_pos_ptr, i, spr_xpos_lo[k]);
    IndirWriteByte(&spr86_wiggler_segment_pos_ptr, i + 1, spr_ypos_lo[k]);
  }
  spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
}

void Spr086_Wiggler_Init_GetWigglerSegmentPosIndex(uint8 k) {  // 02f011
  spr86_wiggler_segment_pos_ptr = PAIR16(kSpr086_Wiggler_Init_WigglerSegmentTablePointerHi[k & 3], kSpr086_Wiggler_Init_WigglerSegmentTablePointerLo[k & 3]) + 0x9a7b;
  spr86_wiggler_segment_pos_ptr_bank = 127;
}

void Spr086_Wiggler(uint8 k) {  // 02f035
  uint8 drt;

  Spr086_Wiggler_Init_GetWigglerSegmentPosIndex(k);
  if (!flag_sprites_locked) {
    CheckNormalSpriteToNormalSpriteCollision(k);
    uint8 v1 = spr_decrementing_table1540[k];
    if (v1) {
      uint8 v2;
      if (v1 == 1)
        v2 = 8;
      else
        v2 = v1 & 0xE;
      R0_ = v2;
      spr_table15f6[k] = v2 | spr_table15f6[k] & 0xF1;
    } else {
      UpdateNormalSpritePosition_X(k);
      UpdateNormalSpritePosition_Y(k);
      SubOffscreen_Bank02_Entry1(k);
      ++spr_table1570[k];
      if (spr_table151c[k]) {
        ++spr_table1570[k];
        if ((++spr_table1534[k] & 0x3F) == 0)
          spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank23_X(k);
      }
      uint8 v3 = spr_table157c[k];
      if (spr_table151c[k])
        v3 += 2;
      spr_xspeed[k] = kSpr086_Wiggler_XSpeed[v3];
      ++spr_yspeed[k];
      HandleNormalSpriteLevelCollision(k);
      if ((spr_table1588[k] & 3) != 0 || (spr_table1588[k] & 4) == 0) {
        if (!spr_decrementing_table15ac[k]) {
          spr_table157c[k] ^= 1;
          spr_table1602[k] = 0;
          spr_decrementing_table15ac[k] = 8;
        }
      } else {
        SetNormalSpriteYSpeedBasedOnSlope(k);
      }
      Spr086_Wiggler_02F0DB(k);
      uint8 v4 = spr_table1602[k];
      spr_table1602[k] = v4 + 1;
      if ((v4 & 7) == 0)
        spr_table00c2[k] = spr_table157c[k] | (2 * spr_table00c2[k]);
    }
  }
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(k)) == 0xff)
    return;
  R3_ = spr_table1570[k];
  R7_ = spr_table15f6[k];
  R8_ = spr_table151c[k];
  R2_ = spr_table00c2[k];
  uint8 v6 = drt + 4;
  uint8 v7 = 0;
  uint8 ka;
  do {
    ka = v7;
    R5_ = v7;
    R6_ = (v7 + (R3_ >> 3)) & 3;
    uint8 v24 = v6;
    uint8 v8 = kSpr086_Wiggler_DATA_02F103[v7];
    if (R8_)
      v8 = (v8 >> 1) & 0xFE;
    R9_ = v8;
    uint8 *v9 = IndirPtr(&spr86_wiggler_segment_pos_ptr, v8);
    get_OamEnt(oam_buf, v24)[64].xpos = *v9 - mirror_current_layer1_xpos;
    int8 v10 = *IndirPtr(&spr86_wiggler_segment_pos_ptr, (uint8)(R9_ + 1)) - mirror_current_layer1_ypos -
               kSpr086_Wiggler_WigglerYDisp[R6_];
    OamEnt *oam = get_OamEnt(oam_buf, v24);
    oam[64].ypos = v10;
    uint8 v12 = -116;
    if (v7)
      v12 = kSpr086_Wiggler_WigglerTiles[R6_];
    oam[64].charnum = v12;
    int8 v13 = sprites_tile_priority | R7_;
    int8 v14 = R2_ & 1;
    R2_ >>= 1;
    if (!v14)
      v13 |= 0x40;
    oam[64].flags = v13;
    sprites_oamtile_size_buffer[(v24 >> 2) + 64] = 2;
    v6 = v24 + 4;
    ++v7;
  } while (ka != 4);
  uint8 v15 = spr_oamindex[spr_current_slotid];
  OamEnt *v16 = get_OamEnt(oam_buf, v15);
  uint8 v17 = spr_current_slotid;
  uint8 flags;
  if (R8_) {
    v16[64].xpos = kSpr086_Wiggler_EyeXDisp[spr_table157c[spr_current_slotid]] + v16[65].xpos;
    v16[64].ypos = v16[65].ypos;
    v16[64].charnum = -120;
    flags = v16[65].flags;
  } else {
    v16[64].xpos = kSpr086_Wiggler_FlowerXDisp[spr_table157c[spr_current_slotid]] + v16[65].xpos;
    v16[64].ypos = v16[65].ypos - 8;
    v16[64].charnum = -104;
    flags = v16[65].flags & 0xF1 | 0xA;
  }
  get_OamEnt(oam_buf, v15)[64].flags = flags;
  sprites_oamtile_size_buffer[(v15 >> 2) + 64] = 0;
  Spr070_Pokey_Bank02SpriteEntry(v17, 0xFF, 5);
  R0_W = GetSprXPos(v17);
  if ((uint16)(R0_W - player_xpos + 80) < 0xA0 && spr_current_status[v17] == 8) {
    R0_ = 4;
    uint8 v19 = spr_oamindex[v17];
    do {
      OamEnt *v20 = get_OamEnt(oam_buf, v19);
      if ((uint8)(v20[65].xpos - player_on_screen_pos_x + 12) < 0x18) {
        uint8 v21 = v20[65].ypos - player_on_screen_pos_y - 16;
        if (player_riding_yoshi_flag)
          v21 -= 16;
        if ((uint8)(v21 + 12) < 0x18) {
          if (timer_star_power) {
            spr_current_status[v17] = 2;
            spr_yspeed[v17] = -48;
            uint8 v23 = ++player_star_kill_count;
            if (player_star_kill_count >= 9) {
              v23 = 9;
              player_star_kill_count = 9;
            }
            GivePoints(v17, v23);
            if (player_star_kill_count < 8)
              io_sound_ch1 = kSpr086_Wiggler_StompSounds[player_star_kill_count - 1];
            return;
          }
          if (!(HIBYTE(player_on_screen_pos_y) | spr_decrementing_table154c[v17])) {
            spr_decrementing_table154c[v17] = 8;
            if (!counter_consecutive_enemies_stomped && sign8(player_yspeed - 8)) {
              DamagePlayer_Hurt();
            } else {
              io_sound_ch1 = 3;
              BoostMarioSpeed();
              if (!(spr_table15d0[v17] | spr_table151c[v17])) {
                SpawnContactEffectFromAbove(v17);
                uint8 v22 = counter_consecutive_enemies_stomped++;
                GivePoints(v17, v22);
                spr_decrementing_table1540[v17] = 64;
                ++spr_table151c[v17];
                Spr086_Wiggler_02F2D7(v17);
              }
            }
            return;
          }
        }
      }
      v19 += 4;
      --R0_;
    } while ((R0_ & 0x80) == 0);
  }
}

void Spr086_Wiggler_02F0DB(uint8 k) {  // 02f0db
  uint8 *v2 = g_ram + 0x10000 + spr86_wiggler_segment_pos_ptr;
  memmove(v2 + 2, v2, 0x7E);
  IndirWriteByte(&spr86_wiggler_segment_pos_ptr, 0, spr_xpos_lo[k]);
  IndirWriteByte(&spr86_wiggler_segment_pos_ptr, 1, spr_ypos_lo[k]);
}

void Spr086_Wiggler_02F2D7(uint8 k) {  // 02f2d7
  uint8 j = 7;
  while (ext_spr_spriteid[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  ext_spr_spriteid[j] = 14;
  ext_spr_table1765[j] = 1;
  SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], GetSprXPos(k));
  SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], GetSprYPos(k));
  ext_spr_yspeed[j] = -48;
  ext_spr_xspeed[j] = -spr_xspeed[k];
}

void Spr08A_Bird(uint8 k) {  // 02f317
  if (spr_decrementing_table15ac[k])
    spr_table1602[k] = 4;
  Spr08A_Bird_Draw(k);
  UpdateNormalSpritePosition_X(k);
  UpdateNormalSpritePosition_Y(k);
  spr_yspeed[k] += 3;
  uint8 v1 = spr_table00c2[k];
  if (v1) {
    if (v1 == 1) {
      spr_yspeed[k] = 0;
      spr_xspeed[k] = 0;
      spr_table1602[k] = 0;
      uint8 v2 = spr_decrementing_table1540[k];
      if (v2) {
        if (v2 < 8)
          ++spr_table1602[k];
      } else if (spr_table1570[k]) {
        --spr_table1570[k];
        spr_decrementing_table1540[k] = GetRand() & 0x15 | 0xA;
      } else {
        spr_table00c2[k] = 0;
        if ((GetRand() & 1) != 0)
          spr_table1570[k] = (GetRand() & 3) + 2;
        else
          Spr08A_Bird_02F3C1(k);
      }
    } else {
      Unreachable();
    }
  } else {
    spr_xspeed[k] = kSpr08A_Bird_XSpeed[spr_table157c[k]];
    spr_table1602[k] = 0;
    if ((spr_yspeed[k] & 0x80) == 0 && spr_ypos_lo[k] >= 0xE8) {
      spr_ypos_lo[k] &= 0xF8;
      spr_yspeed[k] = -16;
      if ((uint8)(spr_xpos_lo[k] + 48) < 0x60) {
        if (!spr_decrementing_table154c[k]) {
          Spr08A_Bird_02F3C1(k);
          spr_decrementing_table154c[k] = 16;
        }
      } else if (spr_table1570[k]) {
        --spr_table1570[k];
      } else {
        ++spr_table00c2[k];
        spr_table1570[k] = kSpr08A_Bird_DATA_02F33C[GetRand() & 3];
      }
    }
  }
}

void Spr08A_Bird_02F3C1(uint8 k) {  // 02f3c1
  spr_table157c[k] ^= 1;
  spr_decrementing_table15ac[k] = 10;
  spr_table1570[k] = (GetRand() & 3) + 2;
}

void Spr08A_Bird_Draw(uint8 k) {  // 02f3ea
  R2_ = kSpr08A_Bird_Direction[spr_table157c[k]] | kSpr08A_Bird_Palette[k & 3];
  uint8 v1 = kSpr08A_Bird_BirdOAMIndex[k & 3];
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam->xpos = spr_xpos_lo[k] - mirror_current_layer1_xpos;
  oam->ypos = spr_ypos_lo[k] - mirror_current_layer1_ypos;
  oam->charnum = kSpr08A_Bird_Tiles[spr_table1602[k]];
  oam->flags = R2_;
  sprites_oamtile_size_buffer[v1 >> 2] = 0;
}

void Spr08B_FireplaceSmoke(uint8 k) {  // 02f434
  ++spr_table1570[k];
  uint8 v1 = 4;
  if ((spr_table1570[k] & 0x40) != 0)
    v1 = -2;
  spr_xspeed[k] = v1;
  spr_yspeed[k] = -4;
  UpdateNormalSpritePosition_Y(k);
  if (!spr_decrementing_table1540[k])
    UpdateNormalSpritePosition_X(k);
  Spr08B_FireplaceSmoke_Draw(k);
  if ((uint8)(spr_ypos_lo[k] - mirror_current_layer1_ypos) == 0xF0)
    spr_current_status[k] = 0;
}

void Spr08B_FireplaceSmoke_Draw(uint8 k) {  // 02f47c
  if ((counter_local_frames & 0xF) == 0)
    ++spr_table151c[k];
  R0_ = kSpr08B_FireplaceSmoke_DATA_02F463[spr_table151c[k]];
  uint8 v1 = spr_oamindex[k];
  int8 v4 = spr_xpos_lo[k] - mirror_current_layer1_xpos;
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[64].xpos = v4 - R0_;
  oam[65].xpos = R0_ + v4;
  int8 v3 = spr_ypos_lo[k] - mirror_current_layer1_ypos;
  oam[64].ypos = v3;
  oam[65].ypos = v3;
  oam[64].charnum = -59;
  oam[65].charnum = -59;
  oam[64].flags = 5;
  oam[65].flags = 69;
  v1 >>= 2;
  sprites_oamtile_size_buffer[v1 + 64] = 2;
  sprites_oamtile_size_buffer[v1 + 65] = 2;
}

void Spr08C_SideExitAndFireplace(uint8 k) {  // 02f4d5
  flag_side_exits = 1;
  if ((spr_xpos_lo[k] & 0x10) == 0) {
    Spr08C_SideExitAndFireplace_Draw(k);
    Spr08C_SideExitAndFireplace_SmokeSpawn();
  }
}

void Spr08C_SideExitAndFireplace_Draw(uint8 k) {  // 02f4eb
  uint8 v1 = spr_oamindex[k] + 8;
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[64].xpos = -72;
  oam[65].xpos = -72;
  oam[64].ypos = -80;
  oam[65].ypos = -72;
  if ((counter_global_frames & 3) == 0 && (GetRand() & 3) == 0)
    ++spr_table00c2[k];
  uint8 v3 = spr_table00c2[k] & 1;
  OamEnt *v4 = get_OamEnt(oam_buf, v1);
  v4[64].charnum = kSpr08C_SideExitAndFireplace_TopTile[v3];
  v4[65].charnum = kSpr08C_SideExitAndFireplace_BottomTile[v3];
  v4[64].flags = 53;
  v4[65].flags = 53;
  uint8 v5 = v1 >> 2;
  sprites_oamtile_size_buffer[v5 + 64] = 0;
  sprites_oamtile_size_buffer[v5 + 65] = 0;
}

void Spr08C_SideExitAndFireplace_SmokeSpawn() {  // 02f53e
  if ((counter_local_frames & 0x3F) == 0)
    Spr08C_SideExitAndFireplace_SmokeSpawn_CheckEmptySlot();
}

void Spr08C_SideExitAndFireplace_SmokeSpawn_CheckEmptySlot() {  // 02f548
  uint8 j = 9;
  while (spr_current_status[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  spr_spriteid[j] = -117;
  spr_current_status[j] = 8;
  InitializeNormalSpriteRAMTables(j);
  SetSprXYPos(j, 0xbb, 0xe0);
  spr_decrementing_table1540[j] = 32;
}

void Spr08D_GhostHouseDoor(uint8 k) {  // 02f5d0
  if ((uint8)mirror_current_layer1_xpos < 0x46) {
    uint8 v0 = 9;
    uint8 v1 = -96;
    do {
      R2_ = 0;
      uint8 v2 = kSpr08D_GhostHouseDoor_DATA_02F59E[v0];
      R0_ = v2 - mirror_current_layer1_xpos;
      if (kSpr08D_GhostHouseDoor_DATA_02F5A8[v0] !=
          (uint8)((v2 < (uint8)mirror_current_layer1_xpos) + HIBYTE(mirror_current_layer1_xpos)))
        ++R2_;
      OamEnt *oam = get_OamEnt(oam_buf, v1);
      oam[64].xpos = R0_;
      oam[64].ypos = kSpr08D_GhostHouseDoor_YDisp[v0];
      oam[64].charnum = kSpr08D_GhostHouseDoor_Tile[v0];
      oam[64].flags = kSpr08D_GhostHouseDoor_Prop[v0];
      sprites_oamtile_size_buffer[(v1 >> 2) + 64] = R2_ | 2;
      v1 += 4;
      --v0;
    } while ((v0 & 0x80) == 0);
  }
}

void DrawNoYoshiSign() {  // 02f639
  uint8 v0 = 7;
  uint8 v1 = -80;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].xpos = kDrawNoYoshiSign_XDisp[v0] - 64;
    oam[64].ypos = kDrawNoYoshiSign_YDisp[v0] + 112;
    oam[64].charnum = kDrawNoYoshiSign_Tiles[v0];
    oam[64].flags = kDrawNoYoshiSign_Prop[v0];
    sprites_oamtile_size_buffer[(v1 >> 2) + 64] = 2;
    v1 += 4;
    --v0;
  } while ((v0 & 0x80) == 0);
}

void DrawBigCastleGate() {  // 02f66e
  uint8 v0 = timer_no_yoshi_intro_door_timer;
  if (timer_no_yoshi_intro_door_timer)
    --timer_no_yoshi_intro_door_timer;
  if (v0 == 0xB0)
    io_sound_ch3 = 15;
  if (v0 == 1)
    io_sound_ch3 = 16;
  if (v0 >= 0x30) {
    if (v0 < 0x81)
      v0 = 48;
    else
      v0 = -(int8)(v0 + 79);
  }
  R0_ = v0;
  DrawBigCastleGate_DrawBigCastleGate();
}

void DrawBigCastleGate_DrawBigCastleGate() {  // 02f6b8
  uint8 v0 = 11;
  uint8 v1 = -80;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam->xpos = kDrawBigCastleGate_XDisp[v0] - 72;
    oam->ypos = kDrawBigCastleGate_YDisp[v0] + 80 - mirror_current_layer1_ypos - R0_;
    oam->charnum = -91;
    oam->flags = 33;
    sprites_oamtile_size_buffer[v1 >> 2] = 2;
    v1 += 4;
    --v0;
  } while ((v0 & 0x80) == 0);
}

void DrawGhostHouseEntranceDoor() {  // 02f759
  uint8 v0 = timer_no_yoshi_intro_door_timer;
  if (timer_no_yoshi_intro_door_timer)
    --timer_no_yoshi_intro_door_timer;
  if (v0 == 118)
    io_sound_ch3 = 15;
  if (v0 == 8)
    io_sound_ch3 = 16;
  R3_ = kDrawGhostHouseEntranceDoor_AnimationFrame[v0 >> 3];
  uint8 v1 = 7;
  R0_ = -72 - mirror_current_layer1_xpos;
  R1_ = 96 - mirror_current_layer1_ypos;
  do {
    R2_ = v1;
    uint8 v2 = kDrawGhostHouseEntranceDoor_OAMIndexes[v1];
    uint8 v3 = v1 + 8 * R3_;
    uint8 v5;
    if ((v2 & 0x80) != 0) {
      OamEnt *oam = get_OamEnt(oam_buf, v2);
      oam->xpos = kDrawGhostHouseEntranceDoor_XDisp[v3] + R0_;
      oam->charnum = kDrawGhostHouseEntranceDoor_Tiles[v3];
      v5 = R2_;
      int v9 = R2_;
      oam->ypos = kDrawGhostHouseEntranceDoor_YDisp[R2_] + R1_;
      uint8 v10 = kDrawGhostHouseEntranceDoor_Prop[v9];
      if (R3_ >= 3)
        v10 ^= 0x40;
      oam->flags = v10;
      sprites_oamtile_size_buffer[v2 >> 2] = 2;
    } else {
      OamEnt *v4 = get_OamEnt(oam_buf, v2);
      v4[64].xpos = kDrawGhostHouseEntranceDoor_XDisp[v3] + R0_;
      v4[64].charnum = kDrawGhostHouseEntranceDoor_Tiles[v3];
      v5 = R2_;
      int v6 = R2_;
      v4[64].ypos = kDrawGhostHouseEntranceDoor_YDisp[R2_] + R1_;
      uint8 v7 = kDrawGhostHouseEntranceDoor_Prop[v6];
      if (R3_ >= 3)
        v7 ^= 0x40;
      v4[64].flags = v7;
      sprites_oamtile_size_buffer[(v2 >> 2) + 64] = 2;
    }
    v1 = v5 - 1;
  } while ((v1 & 0x80) == 0);
}

void ProcessClusterSprites() {  // 02f810
  for (uint8 i = 19; (i & 0x80) == 0; --i) {
    spr_current_slotid = i;
    uint8 v2 = cluster_spr_spriteid[i];
    if (v2)
      ProcessClusterSprites_02F821(i, v2);
  }
}

void ProcessClusterSprites_Return02F820(uint8 k) {  // 02f820
  ;
}

void ProcessClusterSprites_02F821(uint8 k, uint8 a) {  // 02f821
  kProcessClusterSprites_ClusterSpritePtrs[a](k);
}

void ClusterSpr07_ReappearingBoo(uint8 k) {  // 02f83d
  uint8 v6;

  uint8 v1 = sprites_disappearing_boo_frame_counter;
  misc_scratch7e185e = sprites_disappearing_boo_frame_counter;
  if (!k) {
    --sprites_disappearing_boo_frame_counter;
    if (!v1) {
      ++cluster_spr04_boo_ring_index;
      sprites_disappearing_boo_frame_counter = -1;
    }
  }
  if (!v1) {
    if (timer_disappearing_sprite) {
      cluster_spr_spriteid[k] = 0;
      cluster_spr04_boo_ring_index = 0;
      return;
    }
    R0_ = cluster_spr_table1e66[k];
    R1_ = cluster_spr_table1e52[k];
    if ((cluster_spr04_boo_ring_index & 1) == 0) {
      R0_ = cluster_spr_table1e8e[k];
      R1_ = cluster_spr_table1e7a[k];
    }
    SetHiLo(&cluster_spr_xpos_hi[k], &cluster_spr_xpos_lo[k], mirror_current_layer1_xpos + R0_);
    SetHiLo(&cluster_spr_ypos_hi[k], &cluster_spr_ypos_lo[k], mirror_current_layer1_ypos + R1_);
  }
  R0_ = counter_local_frames + 4 * k;
  if (!(flag_sprites_locked | R0_ & 7)) {
    uint8 v3 = (uint8)(R0_ & 0x20) >> 5;
    SetHiLo(&cluster_spr_ypos_hi[k], &cluster_spr_ypos_lo[k], 
      PAIR16(cluster_spr_ypos_hi[k], cluster_spr_ypos_lo[k]) + 
      PAIR16(kClusterSpr07_ReappearingBoo_DATA_02F839[v3], kClusterSpr07_ReappearingBoo_DATA_02F837[v3]));
  }
  if (misc_scratch7e185e >= 0x20) {
    uint8 v5;
    if (misc_scratch7e185e >= 0x40) {
      if (misc_scratch7e185e < 0xE0) {
        ClusterSpr04_BooRing_02FBB0(k);
        v6 = 8;
        goto LABEL_19;
      }
      v5 = ((misc_scratch7e185e - ((misc_scratch7e185e < 0xE0) - 32)) ^ 0x1F) + 1;
    } else {
      v5 = misc_scratch7e185e - ((misc_scratch7e185e < 0x40) + 31);
    }
    v6 = v5 >> 2;
LABEL_19:
    sprites_big_boo_boss_palette_index = v6;
    if (!k)
      FadingBooPaletteAnimation();
    ClusterSpr03_BooCeiling_DrawClusterSpriteBoo(k, 0xF);
  }
}

void ClusterSpr06_SumoBroFlame(uint8 k) {  // 02f91c
  uint8 v1 = cluster_spr_table0f4a[k];
  if (v1) {
    if (!flag_sprites_locked)
      --cluster_spr_table0f4a[k];
    misc_scratch7e185e = 2 * kClusterSpr06_SumoBroFlame_DATA_02F90C[v1 >> 3];
    ClusterSpr06_SumoBroFlame_CheckPlayerContact(k);
    ClusterSpr06_SumoBroFlame_02F940(k);
  } else {
    cluster_spr_spriteid[k] = 0;
  }
}

void ClusterSpr06_SumoBroFlame_02F940(uint8 k) {  // 02f940
  spr_oamindex[0] = kClusterSpriteOAMIndexes[(uint8)(2 * k)];
  SetSprXPos(0, PAIR16(cluster_spr_xpos_hi[k], cluster_spr_xpos_lo[k]));
  SetSprYPos(0, PAIR16(cluster_spr_ypos_hi[k], cluster_spr_ypos_lo[k]));
  uint8 drt;
  
  if ((drt = GetDrawInfo_Bank23_ReturnsTwice(0)) == 0xff)
    return;
  int8 v2 = 1;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = R0_;
    uint8 v4 = misc_scratch7e185e | v2;
    int8 v5 = kClusterSpr06_SumoBroFlame_DATA_02F8FC[v4];
    if (v5 >= 0) {
      oam[64].ypos = R1_ + v5;
      oam[64].charnum = kClusterSpr06_SumoBroFlame_Tiles[v4];
      oam[64].flags = sprites_tile_priority | (16 * (counter_local_frames & 4)) | 5;
    }
    drt += 4;
  } while ((int8)--v2 >= 0);
  FinishOAMWrite(0, 2, 1);
}

void ClusterSpr06_SumoBroFlame_02F9A6(uint8 k) {  // 02f9a6
  cluster_spr_spriteid[k] = 0;
}

void ClusterSpr06_SumoBroFlame_CheckPlayerContact(uint8 k) {  // 02f9ae
  if (((counter_global_frames ^ k) & 3) == 0 && cluster_spr_table0f4a[k] >= 0x10) {
    SetHiLo(&R10_, &R4_, PAIR16(cluster_spr_xpos_hi[k], cluster_spr_xpos_lo[k]) + 2);
    R6_ = 12;
    SetHiLo(&R11_, &R5_, PAIR16(cluster_spr_ypos_hi[k], cluster_spr_ypos_lo[k]) + kClusterSpr06_SumoBroFlame_DATA_02F9AA[misc_scratch7e185e]);
    R7_ = 20;
    StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
    if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
      if (timer_star_power)
        ClusterSpr06_SumoBroFlame_02F9A6(k);
      else
        ClusterSpr06_SumoBroFlame_02F9F5();
    }
  }
}

void ClusterSpr06_SumoBroFlame_02F9F5() {  // 02f9f5
  if (player_riding_yoshi_flag)
    CheckMarioToExtendedSpriteColl_LoseYoshi();
  else
    DamagePlayer_Hurt();
}

void ClusterSpr05_CandleFlame(uint8 k) {  // 02fa16
  if (!flag_sprites_locked && (kClusterSpr05_CandleFlame_DATA_02FA02[GetRand() & 7] & counter_global_frames) == 0)
    ++cluster_spr_table0f4a[k];
  uint8 v1 = kClusterSpr05_CandleFlame_OAMIndex[k];
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[64].xpos = cluster_spr_xpos_lo[k] - mirror_current_layer2_xpos;
  oam[64].ypos = cluster_spr_ypos_lo[k] - mirror_current_layer2_ypos;
  uint8 v3 = cluster_spr_table0f4a[k] & 3;
  oam[64].charnum = kClusterSpr05_CandleFlame_Tiles[v3];
  oam[64].flags = kClusterSpr05_CandleFlame_Prop[v3];
  sprites_oamtile_size_buffer[(v1 >> 2) + 64] = 2;
  if (oam[64].xpos >= 0xF0) {
    get_OamEnt(oam_buf, 0)[123] = oam[64];
    sprites_oamtile_size_buffer[123] = 3;
  }
}

void ClusterSpr04_BooRing(uint8 k) {  // 02fa98
  uint8 v1 = cluster_spr_table0f86[k];
  if (*(&cluster_spr04_boo_ring1_offscreen_flag + v1)) {
    cluster_spr_spriteid[k] = 0;
  } else {
    if (!flag_sprites_locked) {
      int8 v2 = cluster_spr_table0f4a[k];
      if (v2) {
        SetHiLo((&cluster_spr04_boo_ring1_angle_hi + v1), (&cluster_spr04_boo_ring1_angle_lo + v1),
          PAIR16(*(&cluster_spr04_boo_ring1_angle_hi + v1), *(&cluster_spr04_boo_ring1_angle_lo + v1)) + (int8)v2 & 0x1ff);
        R0_W = PAIR16(*(&cluster_spr04_boo_ring1_center_xpos_hi + v1), *(&cluster_spr04_boo_ring1_center_xpos_lo + v1));
        if ((uint16)(R0_W - mirror_current_layer1_xpos + 128) >= 0x200) {
          *(&cluster_spr04_boo_ring1_offscreen_flag + v1) = 1;
          sprites_load_status[*(&cluster_spr04_boo_ring_unused_ring1_level_list_index + v1)] = 0;
          --cluster_spr04_boo_ring_index;
        }
      }
    }
    R0_W = PAIR16(*(&cluster_spr04_boo_ring1_angle_hi + v1), *(&cluster_spr04_boo_ring1_angle_lo + v1)) +
        kClusterSpr04_BooRing_DATA_02FA84[cluster_spr_table0f72[k]] & 0x1ff;
    R2_W = (R0_W + 128) & 0x1FF;
    R4_W = kCircleCoordinates[(uint8)R0_W];
    R6_W = kCircleCoordinates[(uint8)(R0_W + 0x80)];
    WriteReg(WRMPYA, R4_);
    uint8 v6 = 80;
    if (!R5_) {
      WriteReg(WRMPYB, 0x50);
      uint8 t = ReadReg(RDMPYL);
      v6 = ReadReg(RDMPYH) + (t >> 7);
    }
    R4_ = (R1_ & 1) ? -v6 : v6;
    WriteReg(WRMPYA, R6_);
    uint8 v8 = 80;
    if (!R7_) {
      WriteReg(WRMPYB, 0x50);
      uint8 t = ReadReg(RDMPYL);
      v8 = ReadReg(RDMPYH) + (t >> 7);
    }
    R6_ = (R3_ & 1) ? -v8 : v8;
    uint8 v11 = cluster_spr_table0f86[k];
    SetHiLo(&cluster_spr_xpos_hi[k], &cluster_spr_xpos_lo[k],
        PAIR16(*(&cluster_spr04_boo_ring1_center_xpos_hi + v11), *(&cluster_spr04_boo_ring1_center_xpos_lo + v11)) + (int8)R4_);
    SetHiLo(&cluster_spr_ypos_hi[k], &cluster_spr_ypos_lo[k],
        PAIR16(*(&cluster_spr04_boo_ring1_center_ypos_hi + v11), *(&cluster_spr04_boo_ring1_center_ypos_lo + v11)) + (int8)R6_);
    ClusterSpr03_BooCeiling_02FC8D(k);
    ClusterSpr04_BooRing_02FBB0(k);
  }
}

void ClusterSpr04_BooRing_02FBB0(uint8 k) {  // 02fbb0
  if (((counter_global_frames ^ k) & 3) == 0)
    CheckPlayerToEnemyClusterSpriteCollision(k);
}

void ClusterSpr03_BooCeiling(uint8 k) {  // 02fbc7
  if (!k) {
    if (!(flag_sprites_locked | counter_global_frames & 7)) {
      uint8 v1 = GetRand() & 0x1F;
      if (v1 >= 0x14)
        v1 -= (v1 < 0x14) + 20;
      uint8 v2 = v1;
      if (!cluster_spr_table0f86[v1]) {
        ++cluster_spr_table0f86[v1];
        cluster_spr_table0f9a[v1] = 32;
        uint16 xpos = (uint8)(cluster_spr_xpos_lo[v2] - mirror_current_layer1_xpos) + mirror_current_layer1_xpos;
        SetHiLo(&cluster_spr_xpos_hi[v2], &cluster_spr_xpos_lo[v2], xpos);
        SetSprXPos(0, xpos);
        uint16 ypos = (uint8)(cluster_spr_ypos_lo[v2] - mirror_current_layer1_ypos) + mirror_current_layer1_ypos;
        SetHiLo(&cluster_spr_ypos_hi[v2], &cluster_spr_ypos_lo[v2], ypos);
        SetSprYPos(0, ypos);
        cluster_spr_table0f72[v2] = ypos & ~3;
        AimTowardsPlayer_Bank23(0, 0x10);
        cluster_spr_table1e52[v2] = R0_ + 9;
        cluster_spr_table1e66[v2] = R1_;
      }
    }
    k = spr_current_slotid;
  }
  if (!flag_sprites_locked && cluster_spr_table0f9a[k])
    --cluster_spr_table0f9a[k];
  if (cluster_spr_table0f86[k]) {
    if (!flag_sprites_locked) {
      if (!cluster_spr_table0f9a[k]) {
        UpdateClusterSpritePosition_X(k);
        UpdateClusterSpritePosition_Y(k);
        if (((counter_global_frames ^ k) & 3) == 0) {
          CheckPlayerToEnemyClusterSpriteCollision(k);
          if (!sign8(cluster_spr_table1e52[k] + 31))
            --cluster_spr_table1e52[k];
        }
      }
      if ((cluster_spr_ypos_lo[k] & 0xFC) == cluster_spr_table0f72[k] && (cluster_spr_table1e52[k] & 0x80) != 0) {
        cluster_spr_table0f86[k] = 0;
        cluster_spr_table1e66[k] = 0;
      }
    }
    ClusterSpr03_BooCeiling_02FC8D(k);
  } else {
    ClusterSpr03_BooCeiling_02FCE2(k);
  }
}

void ClusterSpr03_BooCeiling_02FC8D(uint8 k) {  // 02fc8d
  R0_W = PAIR16(cluster_spr_xpos_hi[k], cluster_spr_xpos_lo[k]);
  if ((uint16)(R0_W - mirror_current_layer1_xpos + 64) < 0x180) {
    ClusterSpr03_BooCeiling_DrawClusterSpriteBoo(k, 2);
    uint16 ypos = PAIR16(cluster_spr_ypos_hi[k], cluster_spr_ypos_lo[k]);
    uint16 xpos = PAIR16(cluster_spr_xpos_hi[k], cluster_spr_xpos_lo[k]);
    if ((uint16)(ypos + 16 - mirror_current_layer1_ypos) >> 8) {
      get_OamEnt(oam_buf, kClusterSpriteOAMIndexes[k])[64].ypos = 0xf0;
    } else if ((uint16)(xpos - mirror_current_layer1_xpos) >> 8) {
      sprites_oamtile_size_buffer[(kClusterSpriteOAMIndexes[k] >> 2) + 64] = 3;
    }
  }
}

void ClusterSpr03_BooCeiling_02FCE2(uint8 k) {  // 02fce2
  if (!flag_sprites_locked && cluster_spr_spriteid[k] != 8) {
    if (!cluster_spr_table0f9a[k] && (counter_global_frames & 1) == 0) {
      uint8 v1 = cluster_spr_table0f4a[k] & 1;
      uint8 v2 = kClusterSpr03_BooCeiling_DATA_02FBBB[v1] + cluster_spr_table1e66[k];
      cluster_spr_table1e66[k] = v2;
      if (v2 == kClusterSpr03_BooCeiling_DATA_02FBBD[v1]) {
        ++cluster_spr_table0f4a[k];
        cluster_spr_table0f9a[k] = misc_random_byte1 | 0x3F;
      }
    }
    UpdateClusterSpritePosition_X(k);
    if (((counter_global_frames ^ k) & 3) == 0) {
      int8 v3 = (((counter_global_frames + 8 * k) & 0x40) != 0) ? -1 : 1;
      AddHiLo(&cluster_spr_ypos_hi[k], &cluster_spr_ypos_lo[k], v3);
    }
  }
  ClusterSpr03_BooCeiling_DrawClusterSpriteBoo(k, 0xE);
}

void ClusterSpr03_BooCeiling_DrawClusterSpriteBoo(uint8 k, uint8 a) {  // 02fd48
  R2_ = a;
  uint8 v2 = kClusterSpriteOAMIndexes[k];
  OamEnt *oam = get_OamEnt(oam_buf, v2);
  oam[64].xpos = cluster_spr_xpos_lo[k] - mirror_current_layer1_xpos;
  oam[64].ypos = cluster_spr_ypos_lo[k] - mirror_current_layer1_ypos;
  R0_ = (counter_local_frames & 8) != 0;
  oam[64].charnum = kClusterSpr03_BooCeiling_BooCeilingTiles[R0_ + 2 * (k & 3)];
  int8 v4 = (!__CFSHL__(cluster_spr_table1e66[k], 1)) ? 0x40 : 0;
  oam[64].flags = R2_ | v4 | 0x31;
  sprites_oamtile_size_buffer[(v2 >> 2) + 64] = 2;
  if (cluster_spr_spriteid[k] == 8) {
    uint8 v5 = kClusterSpriteOAMIndexes[k];
    R0_ = (counter_local_frames & 4) != 0;
    OamEnt *v6 = get_OamEnt(oam_buf, v5);
    v6[64].charnum = kClusterSpr03_BooCeiling_BatCeilingTiles[(uint8)(R0_ | (2 * cluster_spr_table0f86[k]))];
    v6[64].flags = 55;
  }
}

void ClusterSpr01_1up(uint8 k) {  // 02fdbc
  UpdateClusterSpritePosition_Y(k);
  if (sign8(cluster_spr_table1e52[k] - 64))
    cluster_spr_table1e52[k] += 3;
  if (cluster_spr_ypos_hi[k] && cluster_spr_ypos_lo[k] >= 0x80) {
    cluster_spr_ypos_lo[k] &= 0xF0;
    cluster_spr_table1e52[k] = 0;
  }
  if ((counter_global_frames ^ k) & 1) {
    if (!cluster_spr_table1e52[k]) {
      cluster_spr_xpos_lo[k] += cluster_spr_table1e66[k];
      if (((cluster_spr_table1e66[k] ^ cluster_spr_xpos_lo[k]) & 0x80) != 0 && (uint8)(cluster_spr_xpos_lo[k] + 32) < 0x30) {
        cluster_spr_table1e66[k] = -cluster_spr_table1e66[k];
      }
    }
    if ((uint8)(player_xpos - cluster_spr_xpos_lo[k] + 12) < 0x1E) {
      uint8 v1 = 32;
      if (!player_ducking_flag && player_current_power_up)
        v1 = 48;
      if ((uint8)(player_ypos - cluster_spr_ypos_lo[k] + 32) < v1) {
        cluster_spr_spriteid[k] = 0;
        ClusterSpr01_1up_SpawnScoreSprite(k);
        if (!--counter_remaining_bonus_game1ups)
          timer_bonus_game_end = 88;
      }
    }
  }
  uint8 v2 = kClusterSpr01_1up_OAMIndex[k];
  OamEnt *oam = get_OamEnt(oam_buf, v2);
  oam->xpos = cluster_spr_xpos_lo[k] - mirror_current_layer1_xpos;
  oam->ypos = cluster_spr_ypos_lo[k] - mirror_current_layer1_ypos;
  oam->charnum = 36;
  oam->flags = 58;
  sprites_oamtile_size_buffer[v2 >> 2] = 2;
}

void CheckPlayerToEnemyClusterSpriteCollision(uint8 k) {  // 02fe71
  R2_ = 20;
  R3_ = 0;
  R0_W = PAIR16(cluster_spr_xpos_hi[k], cluster_spr_xpos_lo[k]);
  if ((uint16)(player_xpos - R0_W + 10) < R2_W) {
    R2_W = PAIR16(cluster_spr_ypos_hi[k], cluster_spr_ypos_lo[k]) + 3;
    R4_W = player_current_power_up ? 32 : 20;
    if ((uint16)(player_ypos - R2_W + 28) < R4_W)
      ClusterSpr06_SumoBroFlame_02F9F5();
  }
}

void ClusterSpr01_1up_SpawnScoreSprite(uint8 k) {  // 02ff6c
  uint8 v1 = CheckAvailableScoreSpriteSlot();
  score_spr_spriteid[v1] = 13;
  SetHiLo(&score_spr_ypos_hi[v1], &score_spr_ypos_lo[v1], PAIR16(cluster_spr_ypos_hi[k], cluster_spr_ypos_lo[k]) - 8);
  SetHiLo(&score_spr_xpos_hi[v1], &score_spr_xpos_lo[v1], PAIR16(cluster_spr_xpos_hi[k], cluster_spr_xpos_lo[k]));
  score_spr_yspeed[v1] = 48;
}

void UpdateClusterSpritePosition_X(uint8 k) {  // 02ff98
  UpdateClusterSpritePosition_Y(k + 20);
}

void UpdateClusterSpritePosition_Y(uint8 k) {  // 02ffa3
  uint16 t = (uint8)(16 * cluster_spr_table1e52[k]) + cluster_spr_table1e7a[k];
  cluster_spr_table1e7a[k] = t;
  AddHiLo(&cluster_spr_ypos_hi[k], &cluster_spr_ypos_lo[k], (t >> 8) + ((int8)cluster_spr_table1e52[k] >> 4));
}

