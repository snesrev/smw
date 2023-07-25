#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"
#include "assets/smw_assets.h"
#include "snes/ppu.h"

void LmHook_InitExanimForLevel(void) {
  if (!HAS_LM_FEATURE(kLmFeature_Exanim))
    return;

  lm_var19 = 0xff;
  lm_varA = 0;
  lm_one_shot_triggers = 0;
  ex_anim_info_0.hdr_size = 0;
  ex_anim_info_1.hdr_size = 0;
  ex_anim_info_2.hdr_size = 0;
  ex_anim_info_3.hdr_size = 0;
  ex_anim_info_4.hdr_size = 0;
  ex_anim_info_5.hdr_size = 0;
  ex_anim_info_6.hdr_size = 0;
  ex_anim_info_7.hdr_size = 0;

  WORD(lm_var3) = 0xffff;
  for (int i = 0; i < 32; i++)
    lm_exanim_frame_ctr[i] = 0xffff;

  if (lunar_magic_FE) {
    lm_varA |= kLmLevelData3FE00[lunar_magic_FE - 1];
  } else {
    lm_varA |= 0x10;
  }

  lm_ptr16.addr = 0;
  lm_ptr16.bank = 0;
  lm_varE = 0;
  lm_varA |= 0x10;

  LongPtr pp;

  if (lunar_magic_FE && lunar_magic_FE * 3 <= (int)kLmLvlExAnim_SIZE &&
      (pp = *(LongPtr *)(kLmLvlExAnim + (lunar_magic_FE - 1) * 3)).addr != 0) {

    lm_ptr0.bank = pp.bank;
    const uint8 *p = kLmExanimBlob(Load24(pp)), *p_org = p;

    lm_custom_triggers = lm_custom_triggers & WORD(p[2]) | WORD(p[4]);
    uint16 m = WORD(p[6]);
    p += 8;

    for (int i = 0; i < 16; i++, m >>= 1) {
      if (m & 1)
        lm_exanim_manual_triggers[i] = *p++;
    }
    lm_ptr0.addr = pp.addr + (p - p_org);
    if (!p_org[0])
      goto else_2;

    lm_varC = p_org[0] * 2;
    lm_ptr10.addr = 0;
  } else {
else_2:
    lm_ptr0.addr = 0;
    lm_ptr0.bank = 0;
    lm_varC = 0;
    lm_varA |= 0x20;
  }
  graphics_tile_anim_vramaddress1 = 0;
  graphics_tile_anim_vramaddress2 = 0;
  graphics_tile_anim_vramaddress3 = 0;
}

void LmHook_BeginLoadingLevelDataB(void) {
  if (!kLmLvlInfo_SIZE)
    return;
  if (lunar_magic_FE) {
    uint16 t = kLmLvlInfo[(lunar_magic_FE - 1) * 16];
    uint32 addr = LM_FEATURES->kLmLvlInfo_addr;
    lm_level_info.addr = addr + (lunar_magic_FE - 1) * 32;
    lm_level_info.bank = addr >> 16;
    lm_var9 = 0x41 + (t >> 15);
    if (lm_varB & 0x1)
      LmFunc15_DecompressSlot(1);
  } else {
    lm_var9 = 0xff;
  }
}

void LmHook_PrepareLevel(void) {
  if (lunar_magic_FE && !HAS_LM_FEATURE(kLmFeature_SkipLoadPaletteHook)) {
    LmFunc1_CustomPalettes(lunar_magic_FE - 1);
    lunar_magic_FE = 0;
  }
}

void LmFunc1_CustomPalettes(int a) {
  MemBlk pal = kLmPalettes(a);
  if (pal.size) {
    const uint16 *pp = (const uint16*)pal.ptr;
    palettes_background_color = pp[0];
    memcpy(palettes_palette_mirror, pp + 1, 512);
  }
}

void LmHook_UploadGraphicsFiles(void) {
  LmFunc_UploadGraphics_StepA();
  LmFunc_UpdateBG12NBA();

  // more things here
  if (lm_var9 == 0x42) {
    LmFunc15_DecompressSlot(0);
  } else {
    if (lunar_magic_FB)
      LmGraphicsDecompress(lunar_magic_FB - 1);
  }
  lunar_magic_FB = 0;
  lm_var9 = 0;
}

static uint16 *GetLvlInfo() {
  return &kLmLvlInfo[(lm_level_info.addr - (uint16)LM_FEATURES->kLmLvlInfo_addr) >> 1];
}

uint8 LmFunc15_DecompressSlotB(uint8 a) {
  LmGraphicsDecompress(GetLvlInfo()[a] & 0xfff);
  return 1;
}

uint8 LmFunc15_DecompressSlot(uint8 a) {
  if (lm_var9 != 0x42)
    return 0;
  return LmFunc15_DecompressSlotB(a);
}

void LmHook_OwGraphicsDecompress() {
  if (HAS_LM_FEATURE(kLmFeature_SkipOverworldDecompress))
    return;
  if (HAS_LM_FEATURE(kLmFeature_Ow4bppGfx))
    LmHook_GraphicsDecompress(0x14);
  else
    GraphicsDecompress(0x14);
}

void LmGraphicsDecompress(uint16 a) {
  if (a == 0x7f)
    return;  // skip
  if (a < 0x80) {
    GraphicsDecompress(a);  
  } else if (a < 0x100) {
    // exgfx
    MemBlk blk = kLmExgfx(a - 0x80);
    assert(blk.size != 0);
    DecompressTo(blk.ptr, g_ram + 0xad00);
  } else {
    MemBlk blk = kLmSuperExgfx(a - 0x100);
    assert(blk.size != 0);
    DecompressTo(blk.ptr, g_ram + 0xad00);
  }
}

const uint8 *LmHook_UploadGFXFile(uint8 a, uint8 index) {
  uint8 t;

  if (index < 2) {
    LmGraphicsDecompress(a);
  } else if (index < 8) {
    // bg
    if (lm_var9 == 0x42) {
      LmFunc15_DecompressSlot(index);
      lunar_magic_FC = 0;
    } else if (!(t = lunar_magic_FC)) {
      LmGraphicsDecompress(a);
    } else {
      if (index == 4)
        lunar_magic_FC = 0;
      LmGraphicsDecompress(LmFunc18_GetFF200(t, index - 4));
    }
  } else {
    // sprite
    assert(index < 12);
    if (lm_var9 == 0x42) {
      LmFunc15_DecompressSlot(index);
      lunar_magic_FD = 0;
    } else if (!(t = lunar_magic_FD)) {
      LmGraphicsDecompress(a);
    } else {
      if (index == 8)
        lunar_magic_FD = 0;
      LmGraphicsDecompress(LmFunc18_GetFF200(t, index - 4));
    }
  }
  return g_ram + 0xad00;
}

uint8 LmFunc18_GetFF200(uint8 a, uint8 k) {
  uint32 i = (a - 1) * 4 + k;
  return (i < kLmGraphicsRemapped_SIZE) ? kLmGraphicsRemapped[i] : 0;
}

uint8 LmHook_ModifyMap16IDForSpecialBlocks(uint8 a) {
  if (g_lunar_magic)
    a = LmFunc20_ModifyMap16IDForSpecialBlocks(a);
  return ModifyMap16IDForSpecialBlocks(a);
}

uint8 LmFunc20_ModifyMap16IDForSpecialBlocks(uint8 a) {
  if (misc_level_mode_setting == 9 || misc_level_mode_setting == 11 || misc_level_mode_setting == 16)
    return a;  // lm returns twice...

  uint16 t = blocks_currently_processed_map16_tile_lo | a << 8;
  do {
    t = kLmModifyMap16Ids[t];
  } while (t >= 0x200);
  blocks_currently_processed_map16_tile_lo = t;
  return t >> 8;
}

uint8 *LmHook_GraphicsDecompress(uint8 a) {
  uint8 *p = GraphicsDecompress(a);
  if (HAS_LM_FEATURE(kLmFeature_4bppgfx)) {
    uint8 *dst = p, *src = p;
    int i = 0;
    do {
      memcpy(dst, src, 16);
      dst += 16, src += 16;
      for (int j = 0; j < 8; j++) {
        dst[0] = src[0];
        dst += 1, src += 2;
      }
      i += 0x20;
    } while (i != 0x1000);
  }
  return p;
}

static const uint16 kMinOffsFromScreenToSpawn[] = {-192,   -48,  -128, -16383};
static const uint16 kMaxOffsFromScreenToSpawn[] = {432,  288,  352, 16383};

void LmHook_LoadSpritesOnLevelLoad(void) {
  min_y_offset_from_screen_to_spawn = kMinOffsFromScreenToSpawn[extra_flags_for_sprites & 3] - 0x10;
  max_y_offset_from_screen_to_spawn = kMaxOffsFromScreenToSpawn[extra_flags_for_sprites & 3] + 0x10;
  WORD(smart_spawn_horiz_collision) = 0xffff;

  lm_ptrs_to_sprites_per_screen[0] = ptr_sprite_list_data.addr;
  uint16 r4 = ptr_sprite_list_data.addr - 2;
  uint16 r8 = 0;
  uint8 r6 = 0;
  int r0 = 0;

  lm_screen_sprite_data[0] = 0;
  const uint8 *p_org = kLvlSprBlob(Load24(ptr_sprite_list_data));
  const uint8 *p = p_org + 1;
outer_loop:;
  const uint8 *r10 = p;
  uint8 a;
  uint8 r7 = r8;
read_next:
  for (;;) {
    if ((a = p[0]) != 0xff)
      break;
    if (!(extra_flags_and_horiz_level_mode & 0x20))
      goto found_end;
    p++;
    if ((a = p[0]) == 0xff)
      break;
    if (a == 0xfe)
      goto found_end;
    r6 = a * 2;
    p++;
  }

  uint8 r2_screen = ((a & 2) << 3 | (p[1] & 0xf));
  p += 2;

  if (kLmSprExtraSize_SIZE) {
    p += kLmSprExtraSize[(a & 0xc) << 6 | p[0]] - 2;
  }
  p += 1;
  r8++;
  if (r2_screen == r0)
    goto read_next;

  uint16 t0 = lm_ptrs_to_sprites_per_screen[r0];
  uint16 t1 = lm_screen_sprite_data[r0];
  do {
    r0++;
    lm_ptrs_to_sprites_per_screen[r0] = t0;
    lm_screen_sprite_data[r0] = t1;
  } while (r0 < r2_screen);

  lm_ptrs_to_sprites_per_screen[r0] = (r10 - p_org) + r4 + 1;
  lm_screen_sprite_data[r0] = r6 | r7 << 8;

  goto outer_loop;

found_end:
  t0 = lm_ptrs_to_sprites_per_screen[r0];
  t1 = lm_screen_sprite_data[r0];
  while (r0 < 0x1f) {
    r0++;
    lm_ptrs_to_sprites_per_screen[r0] = t0;
    lm_screen_sprite_data[r0] = t1;
  }
}

void Lm_ParseLevelSpriteList(uint8 k, const uint8 *p, PointU16 pt) {  // 02a82e
  uint16 xx;

  while (1) {
    if (*p == 0xFF) {
      if (!(extra_flags_and_horiz_level_mode & 0x20))
        return;
      p++;
      if (p[0] < 0x80) {
        pt.y = pt.y & ~0x1ff | p[0] * 2;
        continue;
      }
      if (p[0] != 0xff)
        return;
    }

    lm_var_0054 = p[0];
    uint8 r0 = p[1];

    uint8 screen = (8 * p[0]) & 0x10 | p[1] & 0xF;

    if (sign8(screen - HIBYTE(lm_var_0050))) {
      r0 &= ~0xf;
    } else if ((uint8)(screen - HIBYTE(lm_var_0050)) != 0) {
      if (lm_var_0045 & 0x80 || screen > HIBYTE(lm_var_004E))
        return;
      if (lm_var_0045 & 0x20)
        return;
      r0 &= ~0xf;
      goto label2;
    } else {
      r0 &= 0xf0;
      if (r0 != BYTE(lm_var_0050))
        goto label1;
      xx = r0 | screen << 8;
      if (lm_var_0045 & 0x80)
        goto found_sprite;
      if (lm_var_0045 & 0x40)
        goto label1;
      uint16 t0 = (lm_var_0054 & 1 | HIBYTE(pt.y)) << 8 | lm_var_0054 & 0xf0;
      if (sign16(t0 - lm_var_0052) || !sign16(t0 - lm_var_0046))
        goto read_next_sprite;
      goto found_sprite;
    }
  label1:
    if (lm_var_0045 & 0x82)
      goto read_next_sprite;
  label2:

    if (HIBYTE(pt.y) == HIBYTE(lm_var_0048)) {
      if ((lm_var_0054 & 0xf1) != LOBYTE(lm_var_0048) && (
          (lm_var_0054 & 0xf1) != LOBYTE(lm_var_004A) || HIBYTE(pt.y) != HIBYTE(lm_var_004A)))
        goto read_next_sprite;
    } else {
      // else_2
      if (HIBYTE(pt.y) != HIBYTE(lm_var_004A))
        goto read_next_sprite;
      if ((lm_var_0054 & 0xf1) != LOBYTE(lm_var_004A))
        goto read_next_sprite;
    }

    xx = r0 | screen << 8;
    if (sign16(xx - lm_var_004C) || !sign16(xx - lm_var_004E))
      goto read_next_sprite;

found_sprite:
    if (!sprites_load_status[k] && LoadOneSprite(p, k, (PointU16) { .x = xx, .y = pt.y }))
      return;
  read_next_sprite:
    p += 3;
    k++;
  }
}


void LmHook_BE8A(uint16 x_base) {
  int k = extra_flags_for_sprites & 3;

  lm_var_0050 = x_base;
  lm_var_0046 = mirror_current_layer1_ypos & ~0xf;
  lm_var_0052 = lm_var_0046 + kMinOffsFromScreenToSpawn[k];
  lm_var_0048 = lm_var_0052;
  lm_var_0046 += kMaxOffsFromScreenToSpawn[k];
  lm_var_004A = lm_var_0046 - 0x10;
  lm_var_004C = (mirror_current_layer1_xpos & ~0xf) - 0x30;
  lm_var_004E = lm_var_004C + 0x150;

  uint8 a = HIBYTE(lm_var_0048) & 1;
  HIBYTE(lm_var_0048) &= ~a;
  LOBYTE(lm_var_0048) |= a;

  a = HIBYTE(lm_var_004A) & 1;
  HIBYTE(lm_var_004A) &= ~a;
  LOBYTE(lm_var_004A) |= a;

  k = misc_level_layout_flags & 1;

  lm_var_0045 = 0xa0;
  (&lm_var_0045)[k * 2] = 0;

  uint8 t;
  if (extra_flags_for_sprites & 0x80) {
    t = smart_spawn_horiz_collision;
    smart_spawn_horiz_collision = BYTE(lm_var_0050);
    if (BYTE(lm_var_0050) == t)
      lm_var_0045 |= 0x40;

    t = smart_spawn_vert_collision;
    smart_spawn_vert_collision = BYTE(lm_var_0048);
    if (BYTE(lm_var_0048) == t)
      lm_var_0045 |= 0x20;

    t = lm_var_0045 & 0x60;
    if (t == 0x60)
      return;
    if (t != 0x20)
      goto else_1;

    t = HIBYTE(lm_var_0050);
    if (t & 0x80) {
      t = 0;
    } else {
      if (t >= 0x20)
        t = 0x1f;
    }
  } else {
else_1:
    t = ((k ? HIBYTE(mirror_current_layer1_ypos) : HIBYTE(mirror_current_layer1_xpos)) - 1) & 0x7f;
    if (t & 0x40)
      t = 0;
  }

  LongPtr backup = ptr_sprite_list_data;

  ptr_sprite_list_data.addr = lm_ptrs_to_sprites_per_screen[t];

  // The low byte is used to modify the sprite's Y position,
  // while the high byte indicates the number of the sprite within the level.
  uint16 tt = lm_screen_sprite_data[t];

  Lm_ParseLevelSpriteList(tt >> 8, kLvlSprBlob(Load24(ptr_sprite_list_data)) + 1, (PointU16){.x = 0, .y = tt << 8});

  ptr_sprite_list_data = backup;
}

uint16 LmFunc_InitScreenTables(int k, int a) {
  do {
    L1_Screen_Lo[k / 3].addr = a;
    L1_Screen_Hi[k / 3].addr = a;
    k += 3;
    a += lm_level_height;
  } while (a < 0x10000 && k < 0x60);
  return k;
}

void LmHook_LoadLevelInfo(void) {
  if (!HAS_LM_FEATURE(kLmFeature_LoadLevel))
    return;
  HIBYTE(mirror_current_layer1_ypos) = 0;
  HIBYTE(mirror_current_layer2_ypos) = 0;
  extra_flags_and_horiz_level_mode = 0;

  lm_level_height = 0x1b0;
  lm_level_height_minus_16 = lm_level_height - 0x10;

  LmFunc_InitScreenTables(0, 0xc800);
}

void LmHook_BufferCreditsBackgrounds(void) {
  if (!HAS_LM_FEATURE(kLmFeature_LoadLevel))
    return;

  lm_level_height = 0x1b0;
  lm_level_height_minus_16 = lm_level_height - 0x10;
  LmFunc_InitScreenTables(0, 0xc800);
  extra_flags_and_horiz_level_mode = 0;
}

static const uint16 kLmLevelHeights[32] = {
  0x1B0, 0x1C0, 0x1D0, 0x200, 0x220, 0x250, 0x260, 0x280, 0x2A0, 0x2C0, 0x2F0, 0x310, 0x340, 0x380, 0x3B0, 0x400,
  0x440, 0x4A0, 0x510, 0x590, 0x630, 0x700, 0x800, 0x950, 0xB30, 0xE00,0x12A0,0x1C00,0x3800, 0x100,  0xF0,  0xE0,
};

void LmHook_LoadLevel(uint16 j) {
  if (!HAS_LM_FEATURE(kLmFeature_LoadLevel))
    return;

  extra_flags_and_horiz_level_mode = *GetSpriteListPtr() & 0x20;

  for (int i = 0; i < 0x20; i++) {
    L1_Screen_Lo[i].bank = 0x7e;
    L1_Screen_Hi[i].bank = 0x7f;
  }

  if (misc_level_layout_flags & 1) {
    lm_level_height = 0x1b0;
    lm_level_height_minus_16 = lm_level_height - 0x10;
    LmFunc_InitScreenTables(0, 0xc800);
    lm_level_height = 0x100;
    return;
  }

  uint8 a = kLm5DE00[j] & 7;
  if (a & 4)
    a ^= 0x84;
  extra_flags_for_sprites = a;
  extra_flags_and_horiz_level_mode |= kLm10B8BC[j];
  lm_level_height = kLmLevelHeights[extra_flags_and_horiz_level_mode & 0x1f];
  lm_level_height_minus_16 = lm_level_height - 0x10;
  uint16 k = LmFunc_InitScreenTables(0, 0xc800);

  // ??
  if (extra_flags_and_horiz_level_mode & 0x80 && k < 0x60)
    LmFunc_InitScreenTables(0x30, WORD(((uint8*)L1_Screen_Lo)[(k & 1 ? k - 3 : k) >> 1]));

  for (int i = 0; i < 0x20; i++) {
    L1_Screen_8bit_Lo[i] = L1_Screen_Lo[i].addr;
    L1_Screen_8bit_Hi[i] = L1_Screen_Lo[i].addr >> 8;
  }
}

void LmHook_LoadLevelB(const uint8 *ptr_layer1_data, uint8 R2, uint16 level_number) {
  if (!HAS_LM_FEATURE(kLmFeature_LoadLevel))
    return;

  uint8 r4 = kLm6FC00[level_number];

  uint16 r6;
  if (!(misc_level_layout_flags & 1)) {
    r6 = lm_level_height - 0xf0 + (extra_flags_and_horiz_level_mode & 0x40 ? 15 : 0);
  } else {
    r6 = (uint8)(camera_last_screen_vert - 1) << 8;
  }
  mirror_current_layer2_xpos = 0;

  uint8 k = lm_var13CD;
  if (!sign8(k))
    return;

  flag_layer1_vert_scroll_level_setting = 0;
  BYTE(mirror_current_layer1_ypos) = 0;
  if (player_riding_yoshi_flag && (ptr_layer1_data[4] & 0x30) != 0x30) {
    BYTE(mirror_current_layer1_ypos) = ptr_layer1_data[4] & 0x30;
  }

  uint16 t = (R2 & 0xf) << 4;
  if (r4 & 0x40 && (t |= 0xff00) != 0xff90) {
    mirror_current_layer1_ypos = 0;
  }
  if (extra_flags_and_horiz_level_mode & 0x40)
    t--;
  t += player_ypos;
  if (sign16(t) || BYTE(mirror_current_layer1_ypos) && !(BYTE(mirror_current_layer1_ypos) == 0x20 && t == r6) && sign16(t -= 8))
    t = 0;
  mirror_current_layer1_ypos = t;

  uint16 kk = flag_layer2_vert_scroll_level_setting;

  uint8 carry = misc_level_layout_flags & 1;
  static const uint8 kShifts[] = { 0, 1, 5, 2, 3, 4, 6 };
  uint16 a;

  if (!(r4 & 0x80)) {
    k &= 0x1f;
    if (!carry) {
      k -= 0xe;
      if (extra_flags_and_horiz_level_mode & 0x40)
        k += 1;
      if (kk) {
        mirror_current_layer2_ypos = k << kShifts[kk - 1];
        a = (lm_level_height >> 4);
        if (!(extra_flags_and_horiz_level_mode & 0x40))
          a--;
      endif_8:
        a -= 0xe;
        if (a < mirror_current_layer2_ypos) {
          camera_layer2_ypos_relative_to_layer1 = ((uint16)((mirror_current_layer2_ypos - a) * 16) >> kShifts[kk - 1]);
        } else {
          camera_layer2_ypos_relative_to_layer1 = -(((uint16)((a - mirror_current_layer2_ypos) * 16) >> kShifts[kk - 1]));
        }
        mirror_current_layer2_ypos = (mirror_current_layer1_ypos >> kShifts[kk - 1]) + camera_layer2_ypos_relative_to_layer1;
      } else {
        mirror_current_layer2_ypos = k * 16;
      }
    } else {
      k -= 0xe;
      if (kk) {
        mirror_current_layer2_ypos = k << kShifts[kk - 1];
        a = camera_last_screen_vert * 16 - 2;
        goto endif_8;
      } else {
        mirror_current_layer2_ypos = k * 16;
      }
    }
  } else {
    k *= 16;
    if (k & 0x100) {
      k |= 0xff00;
      if (k == 0xff00)
        k = 0;
      else
        k += mirror_current_layer1_ypos;
    } else {
      k = (k & 0xf0) + mirror_current_layer1_ypos;
    }
    mirror_current_layer2_ypos = k;
    camera_layer2_ypos_relative_to_layer1 = -(mirror_current_layer1_ypos >> kShifts[kk - 1]) + mirror_current_layer2_ypos;
  }
}


void LmFunc_UploadOneLevelAnimation(ExAnimationInfo *anim) {
  if (anim->hdr_size) {
    const uint8 *src = (anim->src.bank == 0x7e) ? g_ram + anim->src.addr : kLmExanimBlob(Load24(anim->src));
    if (!(anim->hdr_size & 0x8000)) {
      SmwCopyToVram(anim->dst & 0x7fff, src, anim->hdr_size);
      if (anim->dst & 0x8000)
        SmwCopyToVram((anim->dst & 0x7fff) + 0x100, src + anim->hdr_size, anim->hdr_size);
    } else {
      RtlUpdatePalette((uint16 *)src, (uint8)anim->dst, (uint8)anim->hdr_size);
    }
  }
}

void LmHook_UploadLevelAnimations(void) {
  LmFunc_UploadOneLevelAnimation(&ex_anim_info_4);
  LmFunc_UploadOneLevelAnimation(&ex_anim_info_5);
  LmFunc_UploadOneLevelAnimation(&ex_anim_info_6);
  LmFunc_UploadOneLevelAnimation(&ex_anim_info_7);
  LmFunc_UploadOneLevelAnimation(&ex_anim_info_0);
  LmFunc_UploadOneLevelAnimation(&ex_anim_info_1);
  LmFunc_UploadOneLevelAnimation(&ex_anim_info_2);
  LmFunc_UploadOneLevelAnimation(&ex_anim_info_3);
  if (!sign8(lm_varA)) {
    RtlUpdatePalette(&kGlobalPalettes_Flashing[(counter_local_frames & 0x1c) >> 2], 0x64, 1);
  }
  lm_var4 = lm_var19 >> 3;
}

bool LmHook_GameMode11_LoadSublevel(void) {
  camera_last_screen_horiz = (ptr_layer1_data[0] & 0x1f) + 1;
  uint8 a = lm_var13CD;
  lm_var13CD = 0;
  if (a & 0x40) {
    player_facing_direction = 0;
  }
  lunar_magic_F9 = (a & 0x40) ? 0xc0 : 0x40;
  if (a & 0x80) {
    player_relative_position_needed_to_scroll_screen = 0x80;
    return true;
  }
  return false;
}

uint8 blocks_screen_to_place_next_object_bak;

void LmHook_PreserveLevelDataPointerInObjects(void) {
  ptr_lo_map16_data_bak = ptr_lo_map16_data;
  blocks_screen_to_place_next_object_bak = blocks_screen_to_place_next_object;
}

void LmHook_RestoreLevelDataPointerInObjects(void) {
  ptr_lo_map16_data = ptr_lo_map16_data_bak;
  blocks_screen_to_place_next_object = blocks_screen_to_place_next_object_bak;
}

uint8 LmHook_HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(void) {
  if (misc_level_layout_flags & 1) {
    ptr_lo_map16_data += 256;
  } else {
    ptr_lo_map16_data += lm_level_height;
    blocks_screen_to_place_next_object++;
  }
  return blocks_sub_scr_pos & 0xF0;
}

uint8 LmHook_HandleVerticalSubScreenCrossingForCurrentObject(void) {
  int j = blocks_sub_scr_pos + 16;
  blocks_sub_scr_pos = j;
  if (j >= 256) {
    if (misc_level_layout_flags & 1) {
      ptr_lo_map16_data += 512;
      blocks_screen_to_place_next_object++;
    } else {
      ptr_lo_map16_data += 256;
    }
    LmHook_PreserveLevelDataPointerInObjects();
  }
  return j;
}

void LmHook_UploadLevelLayer1And2Tilemaps(void) {
  if (misc_game_mode == 1) {
    lm_vram_upload_enable_0 = 0;
    lm_vram_upload_enable_6 = 0;
    lm_vram_upload_enable_12 = 0;
    lm_vram_upload_enable_16 = 0;
    return;
  }

  if (misc_game_mode >= 0x20) {
    UploadLevelLayer1And2Tilemaps();
    return;
  }

  if (lm_vram_upload_enable_0) {
    SmwCopyToVram(lm_vram_dma_dst0, g_ram + lm_vram_dma_src0, lm_vram_dma_size0);
    SmwCopyToVram(lm_vram_dma_dst1, g_ram + lm_vram_dma_src1, lm_vram_dma_size1);
    SmwCopyToVram(lm_vram_dma_dst2, g_ram + lm_vram_dma_src2, lm_vram_dma_size2);
    SmwCopyToVram(lm_vram_dma_dst3, g_ram + lm_vram_dma_src3, lm_vram_dma_size3);
    if (lm_vram_dma_size0 != 0x40) {
      SmwCopyToVram(lm_vram_dma_dst4, g_ram + lm_vram_dma_src4, lm_vram_dma_size4);
      SmwCopyToVram(lm_vram_dma_dst5, g_ram + lm_vram_dma_src5, lm_vram_dma_size5);
    }
    lm_vram_upload_enable_0 = 0;
  }

  if (lm_vram_upload_enable_6) {
    SmwCopyToVram(lm_vram_dma_dst6, g_ram + lm_vram_dma_src6, lm_vram_dma_size6);
    SmwCopyToVram(lm_vram_dma_dst7, g_ram + lm_vram_dma_src7, lm_vram_dma_size7);
    SmwCopyToVram(lm_vram_dma_dst8, g_ram + lm_vram_dma_src8, lm_vram_dma_size8);
    SmwCopyToVram(lm_vram_dma_dst9, g_ram + lm_vram_dma_src9, lm_vram_dma_size9);
    if (lm_vram_dma_size6 != 0x40) {
      SmwCopyToVram(lm_vram_dma_dst10, g_ram + lm_vram_dma_src10, lm_vram_dma_size10);
      SmwCopyToVram(lm_vram_dma_dst11, g_ram + lm_vram_dma_src11, lm_vram_dma_size11);
    }
    lm_vram_upload_enable_6 = 0;
  }

  if (lm_vram_upload_enable_12) {
    SmwCopyToVramPitch32(lm_vram_dma_dst12, g_ram + 0x10000 + lm_vram_dma_src12, lm_vram_dma_size12);
    SmwCopyToVramPitch32(lm_vram_dma_dst13, g_ram + 0x10000 + lm_vram_dma_src13, lm_vram_dma_size13);
    if (lm_vram_dma_size12 != 0x40) {
      SmwCopyToVramPitch32(lm_vram_dma_dst14, g_ram + 0x10000 + lm_vram_dma_src14, lm_vram_dma_size14);
      SmwCopyToVramPitch32(lm_vram_dma_dst15, g_ram + 0x10000 + lm_vram_dma_src15, lm_vram_dma_size15);
    }
    lm_vram_upload_enable_12 = 0;
  }

  if (lm_vram_upload_enable_16) {
    SmwCopyToVramPitch32(lm_vram_dma_dst16, g_ram + 0x10000 + lm_vram_dma_src16, lm_vram_dma_size16);
    SmwCopyToVramPitch32(lm_vram_dma_dst17, g_ram + 0x10000 + lm_vram_dma_src17, lm_vram_dma_size17);
    if (lm_vram_dma_size16 != 0x40) {
      SmwCopyToVramPitch32(lm_vram_dma_dst18, g_ram + 0x10000 + lm_vram_dma_src18, lm_vram_dma_size18);
      SmwCopyToVramPitch32(lm_vram_dma_dst19, g_ram + 0x10000 + lm_vram_dma_src19, lm_vram_dma_size19);
    }
    lm_vram_upload_enable_16 = 0;
  }
}

void LmHook_InitializeLevelLayer1And2Tilemaps(void) {
  for (int i = 0; i < 8; i++)
    lm_arr1830b[i] = -1;
  for (int i = 0; i < 4; i++)
    lm_arr1831b[i] = 2;
}

void EmptyFunc(void) {}

void Lm_SetupPipeTiles(uint16 a) {
  uint16 t = kCalculateRowOrColumnOfTilemapToUpdate_PipeMap16Ptrs[a & 3];
  for (int i = 0; i < 8; i++)
    pointer_map16_tiles[307 + i] = t + i * 8;
}

const uint16 *GetMap16RomAddr(uint8 bank, uint16 addr) {
  if (bank == 13) {
    if (addr >= 0xe300)
      return (uint16 *)((const uint8 *)kMap16Data_GhostHouse + addr - 0xe300);
    else if (addr >= 0xd400)
      return (uint16 *)((const uint8 *)kMap16Data_Underground + addr - 0xd400);
    else if (addr >= 0xc800)
      return (uint16 *)((const uint8 *)kMap16Data_Rope + addr - 0xc800);
    else if (addr >= 0xbc00)
      return (uint16 *)((const uint8 *)kMap16Data_Castle + addr - 0xbc00);
    else
      return (uint16 *)((const uint8 *)kMap16Data + addr - 0x8000);
  }
  assert(addr >= 0xd000 && addr < 0xd608);
  return (uint16 *)((const uint8 *)kMap16Data_OverworldLayer1 + addr - 0xd000);
}

const uint16 *Lm_GetMap16RomAddr(uint16 addr) {
  assert(addr < 0x8000);

  if (addr < 0x200)
    return GetMap16RomAddr(misc_level_tileset_setting < 16 ? 13 : 5, pointer_map16_tiles[addr]);
  if (addr < 0x300 && kMap16_TS_SIZE != 0) {
    // tileset specific map16
    int v2 = (4 * addr) & 0x3ff | ((misc_level_tileset_setting & 0xf) << 10);
    return kMap16_TS + v2;
  }
  int part = (4 * addr) & 0x3fff;
  switch (addr >> 12) {
  case 0: return kMap16_0 + part - 0x800;
  case 1: return kMap16_1 + part;
  case 2: return kMap16_2 + part;
  case 3: return kMap16_3 + part;
  case 4: return kMap16_4 + part;
  case 5: return kMap16_5 + part;
  case 6: return kMap16_6 + part;
  case 7: return kMap16_7 + part;
  default: assert(0); return NULL;
  }
}

void Lm_CopyTilesToL1UploadBuffer(const uint8 *plo, const uint8 *phi, uint16 j, uint16 r6) {
  uint16 *dp = &blocks_layer1_tiles_to_upload_buffer[0];
  for (int i = 0; i < 20; i++, dp += 2) {
    const uint16 *tp = Lm_GetMap16RomAddr((plo[j] | phi[j] << 8));
    dp[0] = tp[0];
    dp[64] = tp[1];
    dp[1] = tp[2];
    dp[65] = tp[3];
    if ((++j & 0xF) == 0) {
      Lm_SetupPipeTiles(++r6);
      j += lm_level_height_minus_16;
    }
  }
}

void Lm_CopyToVramBufD_6(const uint8 *plo, const uint8 *phi, uint16 j, const uint16 *ptile) {
  uint16 *dp = &blocks_layer2_tiles_to_upload_buffer[0];
  for (int i = 0; i < 32; i++, dp += 2) {
    const uint16 *tp = ptile + 4 * (plo[j] | phi[j] << 8);
    dp[0] = tp[0];
    dp[64] = tp[1];
    dp[1] = tp[2];
    dp[65] = tp[3];
    j++;
    if (i == 15)
      j += lm_var18327 - 0x10;
  }
}

void LmFunc_CopyTilemapA_12(const uint8 *plo, const uint8 *phi, uint16 j) {
  uint16 *dp = &lm_L2_colbuf[0];
  for (int i = 0; i < 16; i++, dp += 2) {
    const uint16 *tp = Lm_GetMap16RomAddr((plo[j] | phi[j] << 8));
    dp[0] = tp[0];
    dp[1] = tp[1];
    dp[32] = tp[2];
    dp[33] = tp[3];
    j = (j + 16) & 0x3fff;
  }
}

void LmFunc_108CB0(const uint8 *plo, const uint8 *phi, uint16 j, uint16 r6, uint16 r3) {
  uint16 *dp = &blocks_layer2_tiles_to_upload_buffer[0];
  for (int i = 0; i < 20; i++, dp += 2) {
    const uint16 *tp = Lm_GetMap16RomAddr((plo[j] | phi[j] << 8));
    dp[0] = r3 | tp[0];
    dp[64] = r3 | tp[1];
    dp[1] = r3 | tp[2];
    dp[65] = r3 | tp[3];
    if ((++j & 0xF) == 0) {
      Lm_SetupPipeTiles(++r6);
      j += lm_level_height_minus_16;
    }
  }
}

void LmFunc_CopyTilemapC_12(const uint8 *plo, const uint8 *phi, uint16 j, uint16 r3) {
  uint16 *dp = &lm_tilebuf3[0];
  for (int i = 0; i < 16; i++, dp += 2) {
    const uint16 *tp = Lm_GetMap16RomAddr((plo[j] | phi[j] << 8));
    dp[0] = r3 | tp[0];
    dp[1] = r3 | tp[1];
    dp[32] = r3 | tp[2];
    dp[33] = r3 | tp[3];
    j = (j + 16) & 0x3fff;
  }
}

void LmFunc_109662(const uint8 *plo, const uint8 *phi, uint16 j) {
  uint16 *dp = &blocks_layer1_tiles_to_upload_buffer[0];
  for (int i = 0; i < 32; i++, dp += 2) {
    const uint16 *tp = Lm_GetMap16RomAddr((plo[j] | phi[j] << 8));
    dp[0] = tp[0];
    dp[64] = tp[1];
    dp[1] = tp[2];
    dp[65] = tp[3];
    j++;
    if (i == 15)
      j += 256 - 16;
  }
}

void LmFunc_109C29(const uint8 *plo, const uint8 *phi, uint16 j, uint16 r3) {
  uint16 *dp = &blocks_layer2_tiles_to_upload_buffer[0];
  for (int i = 0; i < 32; i++, dp += 2) {
    const uint16 *tp = Lm_GetMap16RomAddr((plo[j] | phi[j] << 8));
    dp[0] = r3 | tp[0];
    dp[64] = r3 | tp[1];
    dp[1] = r3 | tp[2];
    dp[65] = r3 | tp[3];
    j++;
    if (i == 15)
      j += 256 - 16;
  }
}


void Lm_BufferTilemap_L1_0(void) {
  if (blocks_screen_to_place_current_object & 0x10)
    return;

  const uint16 *r10 = GetLayerLayoutPtr(0, misc_level_mode_setting);

  uint16 t0 = (mirror_current_layer1_ypos >> 4) - 1 + (blocks_screen_to_place_current_object & 0xf);
  if (sign16(t0))
    return;  // lm fix

  lm_vram_upload_enable_0 = (t0 << 6) & 0x3ff | 0x3000;

  uint16 t1;
  if (!sign16(mirror_current_layer1_xpos)) {
    t1 = (mirror_current_layer1_xpos >> 4) - 2;
    t1 = sign16(t1) ? 0 : t1;
  } else {
    t1 = 0;
  }

  Lm_SetupPipeTiles(t1 >> 4);

  const uint8 *plo = g_ram + r10[t1 >> 4];
  const uint8 *phi = g_ram + r10[t1 >> 4] + 0x10000;

  uint16 r8 = t1 & 0xf;
  lm_vram_upload_enable_0 |= (t1 & 0xf) * 2 | (t1 & 0x10 ? 0x400 : 0);

  Lm_CopyTilesToL1UploadBuffer(plo, phi, t0 * 16 | r8, t1 >> 4);
  Lm_SetupLmVramDma_0();
}

void Lm_BufferTilemap_L1_1(void) {
  if (blocks_screen_to_place_current_object & 0x10)
    return;

  const uint16 *r10 = GetLayerLayoutPtr(0, misc_level_mode_setting);
  uint16 t0 = (mirror_current_layer1_ypos >> 4) - 1 + (blocks_screen_to_place_current_object & 0xf);
  if (sign16(t0))  // lm fix
    return;

  lm_vram_upload_enable_0 = (t0 << 6) & 0x3ff | 0x3000;
  Lm_SetupPipeTiles(t0 >> 4);

  const uint8 *plo = g_ram + r10[(t0 & 0x1f0) >> 4];
  const uint8 *phi = g_ram + r10[(t0 & 0x1f0) >> 4] + 0x10000;

  LmFunc_109662(plo, phi, (t0 & 0xf) * 16);
  Lm_SetupLmVramDma_0();
}

uint16 *LmHook_CustomBgMap16(void) {
  uint16 v0 = (lm_varB & 4) != 0 ? (lm_varB & 0xF0) >> 4 : 0;
  return (uint16*)kLmCustomMap16Bg(v0).ptr;
}

void LmHook_BufferScrollingTiles_L2_Background(void) {
  if (blocks_screen_to_place_current_object & 0x10)
    return;
  const uint8 *phi = blocks_layer2_tiles_hi, *plo = blocks_layer2_tiles_lo;
  const uint16 *r10 = LmHook_CustomBgMap16();
  lm_var18327 = (lm_varB & 4) != 0 ? 0x200 : 0x1b0;
  int v0 = 32;
  uint16 v1 = (blocks_screen_to_place_current_object & 0xF) << 6;
  do {
    lm_arr_7FBC00[v1 >> 1] = WORD(blocks_layer2_tiles_lo[v1]);
    lm_arr_7FC300[v1 >> 1] = WORD(blocks_layer2_tiles_hi[v1]);
    v1 += 2;
  } while (--v0);
  uint16 r8 = (mirror_current_layer2_ypos - 16 + 16 * (blocks_screen_to_place_current_object & 0xF)) & 0x1F0;
  lm_vram_upload_enable_6 = (4 * r8) & 0x3FF | 0x3800;
  Lm_CopyToVramBufD_6(plo, phi, r8, r10);
  Lm_SetupLmVramDma_6();
}

void LmHook_BufferScrollingTiles_L2_1(void) {
  if (blocks_screen_to_place_current_object & 0x10)
    return;

  const uint16 *r10 = GetLayerLayoutPtr(1, misc_level_mode_setting);

  uint16 r3 = (misc_level_tileset_setting == 3 ? 0x1000 : 0);

  uint16 t0 = (mirror_current_layer2_ypos >> 4) - 1 + (blocks_screen_to_place_current_object & 0xf);
  if (sign16(t0))
    return;  // lm fix

  lm_vram_upload_enable_6 = (t0 << 6) & 0x3ff | 0x3800;

  uint16 t1;
  if ((mirror_current_layer2_xpos & 0x8000u) != 0 || (t1 = (mirror_current_layer2_xpos >> 4) - 2, (t1 & 0x8000u) != 0))
    t1 = 0;

  Lm_SetupPipeTiles(t1 >> 4);

  const uint8 *plo = g_ram + r10[t1 >> 4];
  const uint8 *phi = g_ram + r10[t1 >> 4] + 0x10000;

  uint16 r8 = t1 & 0xf;
  lm_vram_upload_enable_6 |= (t1 & 0xf) * 2 | (t1 & 0x10 ? 0xC00 : 0x800);

  LmFunc_108CB0(plo, phi, t0 * 16 | r8, t1 >> 4, r3);
  Lm_SetupLmVramDma_6();
}

void LmHook_BufferScrollingTiles_L2_7(void) {
  if (blocks_screen_to_place_current_object & 0x10)
    return;

  const uint16 *r10 = GetLayerLayoutPtr(1, misc_level_mode_setting);
  uint16 r3 = (misc_level_tileset_setting == 3 ? 0x1000 : 0);

  uint16 t0 = (mirror_current_layer2_ypos >> 4) - 1 + (blocks_screen_to_place_current_object & 0xf);
  lm_vram_upload_enable_6 = (t0 << 6) & 0x3ff | 0x3800;

  const uint8 *plo = g_ram + r10[(t0 & 0x1f0) >> 4];
  const uint8 *phi = g_ram + r10[(t0 & 0x1f0) >> 4] + 0x10000;

  LmFunc_109C29(plo, phi, (t0 & 0xf) * 16, r3);
  Lm_SetupLmVramDma_6();
}

static const uint16 kLm10B483[2] = {0, 14};
static const uint16 kLm10B487[2] = {0xFFFF, 0x11};

void LmFunc_UpdateTilemapA_0(void) {
  const uint16 *r10 = GetLayerLayoutPtr(0, misc_level_mode_setting);

  uint16 v2 = kLm10B487[lm_arr1831b[0] >> 1] + (mirror_current_layer1_xpos >> 4);
  lm_vram_upload_enable_12 = (2 * v2) & 0x1F | 0x3000 | (v2 & 0x10 ? 0x400 : 0);
  Lm_SetupPipeTiles(v2 >> 4);
  uint16 t1 = (v2 >> 4) & 0x1F;

  const uint8 *plo = g_ram + r10[t1];
  const uint8 *phi = g_ram + r10[t1] + 0x10000;

  uint16 r8 = mirror_current_layer1_ypos & 0x3FF0;
  lm_vram_upload_enable_12 |= (4 * r8) & 0x3C0;
  LmFunc_CopyTilemapA_12(plo, phi, r8 | v2 & 0xF);
  Lm_SetupLmVramDma_12();
}

void LmFunc_UpdateTilemapB_0(void) {
  const uint16 *r10 = GetLayerLayoutPtr(0, misc_level_mode_setting);
  uint16 v0;
  uint16 v4 = kLm10B483[lm_arr1831b[1] >> 1] + (mirror_current_layer1_ypos >> 4);
  lm_vram_upload_enable_0 = (v4 << 6) & 0x3FF | 0x3000;
  if ( (mirror_current_layer1_xpos & 0x8000) != 0 || (v0 = (mirror_current_layer1_xpos >> 4) - 2, (int16)v0 < 0) )
    v0 = 0;
  Lm_SetupPipeTiles(v0 >> 4);
  uint16 t1 = v0 >> 4;

  const uint8 *plo = g_ram + r10[t1];
  const uint8 *phi = g_ram + r10[t1] + 0x10000;

  lm_vram_upload_enable_0 |= 2 * (v0 & 0xF) | ((v0 & 0x10) == 0 ? 0 : 0x400);
  Lm_CopyTilesToL1UploadBuffer(plo, phi, v0 & 0xF | 16 * v4, v0 >> 4);
  Lm_SetupLmVramDma_0();
}

void LmFunc_UpdateTilemapB_7(void) {
  const uint16 *r10 = GetLayerLayoutPtr(0, misc_level_mode_setting);
  uint16 v0 = kLm10B483[lm_arr1831b[1] >> 1] + (mirror_current_layer1_ypos >> 4);
  lm_vram_upload_enable_0 = (v0 << 6) & 0x3FF | 0x3000;
  Lm_SetupPipeTiles(v0 >> 4);
  uint16 t1 = (v0 & 0x1f0) >> 4;
  const uint8 *plo = g_ram + r10[t1];
  const uint8 *phi = g_ram + r10[t1] + 0x10000;
  LmFunc_109662(plo, phi, (v0 & 0xF) * 16);
  Lm_SetupLmVramDma_0();
}

void LmFunc_UpdateTilemapC_0(void) {
  const uint16 *r10 = GetLayerLayoutPtr(1, misc_level_mode_setting);
  uint16 r3 = (misc_level_tileset_setting == 3 ? 0x1000 : 0);
  uint16 v2 = kLm10B487[lm_arr1831b[2] >> 1] + (mirror_current_layer2_xpos >> 4);
  lm_vram_upload_enable_16 = (2 * v2) & 0x1F | 0x3800 | (v2 & 0x10 ? 0x400 : 0);
  Lm_SetupPipeTiles(v2 >> 4);
  uint16 t1 = (v2 >> 4) & 0xF; // lm bugfix, L2 doesn't have 32 screens

  const uint8 *plo = g_ram + r10[t1];
  const uint8 *phi = g_ram + r10[t1] + 0x10000;

  uint16 r8 = mirror_current_layer2_ypos & 0x3FF0;
  lm_vram_upload_enable_16 |= (4 * r8) & 0x3C0;
  LmFunc_CopyTilemapC_12(plo, phi, r8 | v2 & 0xF, r3);
  Lm_SetupLmVramDma_16();
}

void LmFunc_UpdateTilemapD_0(void) {
  const uint8 *phi = g_ram + 0x1c300, *plo = g_ram + 0x1bc00;
  const uint16 *r10 = LmHook_CustomBgMap16();
  uint16 r8 = ((mirror_current_layer2_ypos & 0xFFF0) + 16 * kLm10B483[lm_arr1831b[3] >> 1]) & 0x1F0;
  lm_vram_upload_enable_6 = (4 * r8) & 0x3FF | 0x3800;
  Lm_CopyToVramBufD_6(plo, phi, r8, r10);
  Lm_SetupLmVramDma_6();
}

void LmFunc_UpdateTilemapD_1(void) {
  const uint16 *r10 = GetLayerLayoutPtr(1, misc_level_mode_setting);

  uint16 r3 = (misc_level_tileset_setting == 3 ? 0x1000 : 0);

  uint16 t0 = kLm10B483[lm_arr1831b[3] >> 1] + ((int16)mirror_current_layer2_ypos >> 4);
  if (sign16(t0))
    return;  // lm fix

  lm_vram_upload_enable_6 = (t0 << 6) & 0x3ff | 0x3800;

  uint16 t1;
  if ((mirror_current_layer2_xpos & 0x8000u) != 0 || (t1 = (mirror_current_layer2_xpos >> 4) - 2, (t1 & 0x8000u) != 0))
    t1 = 0;
  Lm_SetupPipeTiles(t1 >> 4);
  const uint8 *plo = g_ram + r10[t1 >> 4];
  const uint8 *phi = g_ram + r10[t1 >> 4] + 0x10000;

  lm_vram_upload_enable_6 |= (t1 & 0xf) * 2 | (t1 & 0x10 ? 0xC00 : 0x800);
  LmFunc_108CB0(plo, phi, t0 * 16 | t1 & 0xf, t1 >> 4, r3);
  Lm_SetupLmVramDma_6();
}

void LmFunc_UpdateTilemapD_2(void) {
  const uint16 *r10 = GetLayerLayoutPtr(1, misc_level_mode_setting);
  uint16 r3 = (misc_level_tileset_setting == 3 ? 0x1000 : 0);
  uint16 t0 = kLm10B483[lm_arr1831b[3] >> 1] + (mirror_current_layer2_ypos >> 4);
  lm_vram_upload_enable_6 = (t0 << 6) & 0x3ff | 0x3800;
  const uint8 *plo = g_ram + r10[(t0 & 0x1f0) >> 4];
  const uint8 *phi = g_ram + r10[(t0 & 0x1f0) >> 4] + 0x10000;
  LmFunc_109C29(plo, phi, (t0 & 0xf) * 16, r3);
  Lm_SetupLmVramDma_6();
}


static FuncV *const kLmHook_BufferTilemap_L1[32] = {
    &Lm_BufferTilemap_L1_0,
    &Lm_BufferTilemap_L1_0,
    &Lm_BufferTilemap_L1_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &Lm_BufferTilemap_L1_1,
    &Lm_BufferTilemap_L1_1,
    &EmptyFunc,
    &Lm_BufferTilemap_L1_1,
    &EmptyFunc,
    &Lm_BufferTilemap_L1_0,
    &Lm_BufferTilemap_L1_1,
    &Lm_BufferTilemap_L1_0,
    &Lm_BufferTilemap_L1_0,
    &EmptyFunc,
    &Lm_BufferTilemap_L1_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &Lm_BufferTilemap_L1_0,
    &Lm_BufferTilemap_L1_0,
};

static FuncV *const kLmHook_BufferTilemap_L2[32] = {
    &LmHook_BufferScrollingTiles_L2_Background,
    &LmHook_BufferScrollingTiles_L2_1,
    &LmHook_BufferScrollingTiles_L2_1,
    &BufferScrollingTiles_Layer2,
    &BufferScrollingTiles_Layer2,
    &BufferScrollingTiles_Layer2_VerticalLevel,
    &BufferScrollingTiles_Layer2_VerticalLevel,
    &LmHook_BufferScrollingTiles_L2_7,
    &LmHook_BufferScrollingTiles_L2_7,
    &BufferScrollingTiles_Layer2_NoScroll,
    &LmHook_BufferScrollingTiles_L2_Background,
    &BufferScrollingTiles_Layer2_NoScroll,
    &LmHook_BufferScrollingTiles_L2_Background,
    &LmHook_BufferScrollingTiles_L2_Background,
    &LmHook_BufferScrollingTiles_L2_Background,
    &LmHook_BufferScrollingTiles_L2_1,
    &BufferScrollingTiles_Layer2_NoScroll,
    &LmHook_BufferScrollingTiles_L2_Background,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &BufferScrollingTiles_Layer2_NoScroll,
    &LmHook_BufferScrollingTiles_L2_Background,
    &LmHook_BufferScrollingTiles_L2_1,
};
static FuncV *const kLmFunc_UpdateTilemapA[32] = {
    &LmFunc_UpdateTilemapA_0,
    &LmFunc_UpdateTilemapA_0,
    &LmFunc_UpdateTilemapA_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &LmFunc_UpdateTilemapA_0,
    &EmptyFunc,
    &LmFunc_UpdateTilemapA_0,
    &LmFunc_UpdateTilemapA_0,
    &EmptyFunc,
    &LmFunc_UpdateTilemapA_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &LmFunc_UpdateTilemapA_0,
    &LmFunc_UpdateTilemapA_0,
};
static FuncV *const kLmFunc_UpdateTilemapB[32] = {
    &LmFunc_UpdateTilemapB_0,
    &LmFunc_UpdateTilemapB_0,
    &LmFunc_UpdateTilemapB_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &LmFunc_UpdateTilemapB_7,
    &LmFunc_UpdateTilemapB_7,
    &EmptyFunc,
    &LmFunc_UpdateTilemapB_7,
    &EmptyFunc,
    &LmFunc_UpdateTilemapB_0,
    &LmFunc_UpdateTilemapB_7,
    &LmFunc_UpdateTilemapB_0,
    &LmFunc_UpdateTilemapB_0,
    &EmptyFunc,
    &LmFunc_UpdateTilemapB_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &LmFunc_UpdateTilemapB_0,
    &LmFunc_UpdateTilemapB_0,
};
static FuncV *const kLmFunc_UpdateTilemapC[32] = {
    &EmptyFunc,
    &LmFunc_UpdateTilemapC_0,
    &LmFunc_UpdateTilemapC_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &LmFunc_UpdateTilemapC_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &LmFunc_UpdateTilemapC_0,
};
static FuncV *const kLmFunc_UpdateTilemapD[32] = {
    &LmFunc_UpdateTilemapD_0,
    &LmFunc_UpdateTilemapD_1,
    &LmFunc_UpdateTilemapD_1,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &LmFunc_UpdateTilemapD_2,
    &LmFunc_UpdateTilemapD_2,
    &EmptyFunc,
    &LmFunc_UpdateTilemapD_0,
    &EmptyFunc,
    &LmFunc_UpdateTilemapD_0,
    &LmFunc_UpdateTilemapD_0,
    &LmFunc_UpdateTilemapD_0,
    &LmFunc_UpdateTilemapD_1,
    &EmptyFunc,
    &LmFunc_UpdateTilemapD_0,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &EmptyFunc,
    &LmFunc_UpdateTilemapD_0,
    &LmFunc_UpdateTilemapD_1,
};

void LmHook_BufferTilemap_L1(void) {
  if (misc_game_mode >= 0x20)
    BufferScrollingTiles_Layer1_Init();
  else
    kLmHook_BufferTilemap_L1[misc_level_mode_setting]();
}

void LmHook_BufferTilemap_L2(void) {
  if (misc_game_mode >= 0x20)
    BufferScrollingTiles_Layer2_Init();
  else
    kLmHook_BufferTilemap_L2[misc_level_mode_setting]();
}

void LmFunc_UpdateTilemapA() {
  kLmFunc_UpdateTilemapA[misc_level_mode_setting]();
}

void LmFunc_UpdateTilemapB() {
  kLmFunc_UpdateTilemapB[misc_level_mode_setting]();
}

void LmFunc_UpdateTilemapC() {
  kLmFunc_UpdateTilemapC[misc_level_mode_setting]();
}

void LmFunc_UpdateTilemapD() {
  kLmFunc_UpdateTilemapD[misc_level_mode_setting]();
}


void LmHook_CheckIfLevelTilemapsNeedScrollUpdate(void) {
  uint8 t = lm_arr1831b[0] >> 1;
  if ((mirror_current_layer1_xpos & 0xFFF0) != lm_arr1830b[t]) {
    lm_arr1830b[t] = mirror_current_layer1_xpos & 0xFFF0;
    lm_arr1830b[t ^ 1] = -1;
    LmFunc_UpdateTilemapA();
  }
  t = lm_arr1831b[1] >> 1;
  if ((mirror_current_layer1_ypos & 0xFFF0) != lm_arr1830b[t + 2]) {
    lm_arr1830b[t + 2] = mirror_current_layer1_ypos & 0xFFF0;
    lm_arr1830b[(t ^ 1) + 2] = -1;
    LmFunc_UpdateTilemapB();
  }
  t = lm_arr1831b[2] >> 1;
  if ((mirror_current_layer2_xpos & 0xFFF0) != lm_arr1830b[t + 4]) {
    lm_arr1830b[t + 4] = mirror_current_layer2_xpos & 0xFFF0;
    lm_arr1830b[(t ^ 1) + 4] = -1;
    LmFunc_UpdateTilemapC();
  }
  t = lm_arr1831b[3] >> 1;
  if ((mirror_current_layer2_ypos & 0xFFF0) != lm_arr1830b[t + 6]) {
    lm_arr1830b[t + 6] = mirror_current_layer2_ypos & 0xFFF0;
    lm_arr1830b[(t ^ 1) + 6] = -1;
    LmFunc_UpdateTilemapD();
  }
}

void Lm_SetupLmVramDma_0(void) {
  lm_vram_dma_dst0 = lm_vram_upload_enable_0;
  uint16 r0 = 4 * (((lm_vram_upload_enable_0 >> 1) & 0xF ^ 0xF) + 1);
  lm_vram_dma_src0 = 7142;
  lm_vram_dma_size0 = r0;
  lm_vram_dma_dst1 = (lm_vram_upload_enable_0 ^ 0x400) & 0xFFC0;
  lm_vram_dma_src1 = r0 + 0x1be6;
  lm_vram_dma_size1 = 64;
  lm_vram_dma_dst2 = lm_vram_upload_enable_0 | 0x20;
  lm_vram_dma_src2 = 7270;
  lm_vram_dma_size2 = lm_vram_dma_size0;
  lm_vram_dma_dst3 = (lm_vram_upload_enable_0 ^ 0x400) & 0xFFC0 | 0x20;
  lm_vram_dma_src3 = r0 + 0x1c66;
  lm_vram_dma_size3 = 64;
  if (lm_vram_dma_size0 != 64) {
    lm_vram_dma_dst4 = lm_vram_upload_enable_0 & 0xFFC0;
    lm_vram_dma_src4 = r0 + 0x1be6 + 0x40;
    lm_vram_dma_size4 = 64 - r0;
    lm_vram_dma_dst5 = lm_vram_upload_enable_0 & 0xFFC0 | 0x20;
    lm_vram_dma_src5 = r0 + 0x1c66 + 0x40;
    lm_vram_dma_size5 = 64 - r0;
  }
}

void Lm_SetupLmVramDma_6(void) {
  lm_vram_dma_dst6 = lm_vram_upload_enable_6;
  uint16 r0 = 4 * (((lm_vram_upload_enable_6 >> 1) & 0xF ^ 0xF) + 1);
  lm_vram_dma_src6 = 0x1CE8;
  lm_vram_dma_size6 = r0;
  lm_vram_dma_dst7 = (lm_vram_upload_enable_6 ^ 0x400) & 0xFFC0;
  lm_vram_dma_src7 = r0 + 0x1CE8;
  lm_vram_dma_size7 = 64;
  lm_vram_dma_dst8 = lm_vram_upload_enable_6 | 0x20;
  lm_vram_dma_src8 = 7528;
  lm_vram_dma_size8 = lm_vram_dma_size6;
  lm_vram_dma_dst9 = (lm_vram_upload_enable_6 ^ 0x400) & 0xFFC0 | 0x20;
  lm_vram_dma_src9 = r0 + 0x1D68;
  lm_vram_dma_size9 = 64;
  if (lm_vram_dma_size6 != 64) {
    lm_vram_dma_dst10 = lm_vram_upload_enable_6 & 0xFFC0;
    lm_vram_dma_src10 = r0 + 0x1D28;
    lm_vram_dma_size10 = 64 - r0;
    lm_vram_dma_dst11 = lm_vram_upload_enable_6 & 0xFFC0 | 0x20;
    lm_vram_dma_src11 = r0 + 0x1DA8;
    lm_vram_dma_size11 = 64 - r0;
  }
}

void Lm_SetupLmVramDma_12(void) {
  lm_vram_dma_dst12 = lm_vram_upload_enable_12;
  uint16 r0 = 4 * (((lm_vram_upload_enable_12 >> 6) & 0xF ^ 0xF) + 1);
  lm_vram_dma_src12 = 0x820B;
  lm_vram_dma_size12 = 4 * (((lm_vram_upload_enable_12 >> 6) & 0xF ^ 0xF) + 1);
  lm_vram_dma_dst13 = lm_vram_upload_enable_12 + 1;
  lm_vram_dma_src13 = 0x824B;
  lm_vram_dma_size13 = lm_vram_dma_size12;
  if (lm_vram_dma_size12 != 64) {
    lm_vram_dma_dst14 = lm_vram_upload_enable_12 & 0xFC1F;
    lm_vram_dma_src14 = r0 + 0x820B;
    lm_vram_dma_size14 = 64 - r0;
    lm_vram_dma_dst15 = (lm_vram_upload_enable_12 & 0xFC1F) + 1;
    lm_vram_dma_src15 = r0 + 0x824B;
    lm_vram_dma_size15 = 64 - r0;
  }
}

void Lm_SetupLmVramDma_16(void) {
  lm_vram_dma_dst16 = lm_vram_upload_enable_16;
  uint16 r0 = 4 * (((lm_vram_upload_enable_16 >> 6) & 0xF ^ 0xF) + 1);
  lm_vram_dma_src16 = 0x828B;
  lm_vram_dma_size16 = 4 * (((lm_vram_upload_enable_16 >> 6) & 0xF ^ 0xF) + 1);
  lm_vram_dma_dst17 = lm_vram_upload_enable_16 + 1;
  lm_vram_dma_src17 = 0x82CB;
  lm_vram_dma_size17 = lm_vram_dma_size16;
  if (lm_vram_dma_size16 != 64) {
    lm_vram_dma_dst18 = lm_vram_upload_enable_16 & 0xFC1F;
    lm_vram_dma_src18 = r0 + 0x828B;
    lm_vram_dma_size18 = 64 - r0;
    lm_vram_dma_dst19 = (lm_vram_upload_enable_16 & 0xFC1F) + 1;
    lm_vram_dma_src19 = r0 + 0x82CB;
    lm_vram_dma_size19 = 64 - r0;
  }
}


void LmHook_LevelTileAnimations(void) {
  if (!HAS_LM_FEATURE(kLmFeature_Exanim)) {
    HandleLevelTileAnimations();
    return;
  }
  if (counter_local_frames == lm_var3) {
    ex_anim_info_0.hdr_size = 0;
    ex_anim_info_1.hdr_size = 0;
    ex_anim_info_2.hdr_size = 0;
    ex_anim_info_3.hdr_size = 0;
    ex_anim_info_4.hdr_size = 0;
    ex_anim_info_5.hdr_size = 0;
    ex_anim_info_6.hdr_size = 0;
    ex_anim_info_7.hdr_size = 0;
    graphics_tile_anim_vramaddress3 = 0;
    graphics_tile_anim_vramaddress2 = 0;
    graphics_tile_anim_vramaddress1 = 0;
    return;
  }

  lm_var3 = counter_local_frames;
  uint8 v1 = lm_varA;
  if ((lm_varA & 0x40) == 0) {
    HandleLevelTileAnimations();
    v1 = lm_varA;
  }
  if ((lm_varA & 0x30) != 48) {
    ++lm_var19;
    ex_anim_info_0.hdr_size = 0;
    ex_anim_info_1.hdr_size = 0;
    ex_anim_info_2.hdr_size = 0;
    ex_anim_info_3.hdr_size = 0;
    ex_anim_info_4.hdr_size = 0;
    ex_anim_info_5.hdr_size = 0;
    ex_anim_info_6.hdr_size = 0;
    ex_anim_info_7.hdr_size = 0;
    if ((lm_varA & 0x10) == 0) {
      uint16 v3 = 2 * (counter_local_frames & 7);
      if (v3 < lm_varE) {
        LongPtr r0 = lm_ptr16;
        uint16 v0 = 4;
        do {
          uint16 v5 = *(uint16 *)(kLmExanimBlob(Load24(r0)) + v3);
          if (v5) {
            uint16 r8 = (v3 >> 1) + 0xC0A0;
            LmFunc_10C713((LongPtr){.bank = r0.bank, .addr = r0.addr + v3 + v5}, r8, 1, v0);
          }
          v3 += 16;
          ++v0;
        } while (v3 < lm_varE);
      }
    }
    if ((lm_varA & 0x20) == 0) {
      uint16 v6 = 2 * (counter_local_frames & 7);
      if (v6 < lm_varC) {
        LongPtr r0 = lm_ptr0;
        uint16 v0 = 0;
        uint16 r10 = 0;
        do {
          uint16 v8 = *(uint16 *)(kLmExanimBlob(Load24(r0)) + v6);
          if (v8) {
            uint16 r8 = (v6 >> 1) + 0xC080;
            LmFunc_10C713((LongPtr){.bank = r0.bank, .addr = r0.addr + v8}, r8, 0, v0);
          }
          v6 += 16;
          ++v0;
        } while (v6 < lm_varC);
      }
    }
  }
}

typedef void ParseTileAnimFunc(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a);

void ParseTileAnimFunc_Null(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  // empty
}

static const uint16 kParseTileAnimFunc_1_Tab[] = {0,     0x20,  0x40,  0x60,  0x80,  0xA0, 0xC0, 0xE0, 0x100, 0x180,
                                                  0x200, 0x280, 0x300, 0x380, 0x400, 0x10, 0x20, 0x40, 0x80};

int CheckExanimTrigger(ParseTileAnimCtx *ctx, uint8 a) {
  uint8 t;
  switch (a) {
  case 0: return 0;
  case 1: return timer_blue_pswitch;
  case 2: return timer_silver_pswitch;
  case 3: return flag_on_off_switch;
  case 4: return timer_star_power;
  case 5: return counter_timer_hundreds == 0;
  case 6: return (counter_timer_hundreds || *ctx->r8 == 0xff) ? -1 : (*ctx->r8 < *ctx->p) ? 0 : 1;
  case 7: return counter_yoshi_coins_collected >= 5;
  case 8: return (counter_yoshi_coins_collected < 5 || *ctx->r8 == 0xff) ? -1 : (*ctx->r8 < *ctx->p) ? 0 : 1;
  case 0xf: assert(0); return 1;
  case 0x10: case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17:
  case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1c: case 0x1d: case 0x1e: case 0x1f:
    t = lm_exanim_manual_triggers[a - 0x10];
    if (t == *ctx->r8)
      return -1;
    *ctx->r8 = t - 1;
    return 1;
  case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27:
  case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f:
    return (lm_custom_triggers >> (a - 0x20)) & 1;
  case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37:
  case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f:
  case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47:
  case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f:
    if (!(lm_one_shot_triggers & 1 << (a - 0x30)))
      return -1;
    if (*ctx->r8 < *ctx->p || *ctx->r8 == 0xff)
      return 0;
    *ctx->r8 = 0xff;
    lm_one_shot_triggers |= 1 << (a - 0x30);
    return -1;
  default: return 0;
  }
}

void ParseTileAnimFunc_1(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  int trigger = CheckExanimTrigger(ctx, a);
  if (trigger < 0)
    return;
  uint8 limit = *ctx->p;
  a = *ctx->r8;
  a = (a >= limit) ? 0xff : a;
  *ctx->r8 = ++a;
  a += trigger ? limit + 1 : 0;

  exinfo->hdr_size = kParseTileAnimFunc_1_Tab[cmd];
  uint16 dest = WORD(*++ctx->p);
  if (!sign16(dest)) {
    exinfo->dst = dest;
    exinfo->src.bank = 0x7e;
    exinfo->src.addr = WORD(ctx->p[(a + 1) * 2]);
  } else {
    exinfo->dst = dest & 0x7fff;
    exinfo->src = (&lm_ptr10)[ctx->r10];
    exinfo->src.addr += WORD(ctx->p[(a + 1) * 2]);
  }
}

void ParseTileAnimFunc_10(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  ParseTileAnimFunc_1(ctx, cmd, exinfo, a);
  exinfo->dst |= 0x8000;
}

void ParseTileAnimFunc_13(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  int trigger = CheckExanimTrigger(ctx, a);
  if (trigger < 0)
    return;
  uint8 limit = *ctx->p;
  a = *ctx->r8;
  a = (a >= limit) ? 0xff : a;
  *ctx->r8 = ++a;
  a += trigger ? limit + 1 : 0;

  uint16 x = WORD(*++ctx->p);
  exinfo->dst = x;
  int t = (a + 1) * 2;

  if (!(x & 0x7f00)) {
    exinfo->hdr_size = 0x8001;
    exinfo->src = ctx->ptr;
    exinfo->src.addr += t + (ctx->p - ctx->porg);
  } else {
    exinfo->hdr_size = (((x & 0x7f00) >> 8) + 1) | 0x8000;
    if (!sign16(x)) {
      exinfo->src.bank = 0x7e;
      exinfo->src.addr = WORD(ctx->p[t]);
    } else {
      exinfo->src = (&lm_ptr10)[ctx->r10];
      exinfo->src.addr += WORD(ctx->p[t]);
    }
  }
}

void ParseTileAnimFunc_14(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  assert(0);
}

void ParseTileAnimFunc_15(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  assert(0);
}

void ParseTileAnimFunc_16(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  assert(0);
}

void ParseTileAnimFunc_17(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  assert(0);
}

void ParseTileAnimFunc_18(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  assert(0);
}

void ParseTileAnimFunc_19(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  assert(0);
}

void ParseTileAnimFunc_1A(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  assert(0);
}

void ParseTileAnimFunc_1B(ParseTileAnimCtx *ctx, uint8 cmd, ExAnimationInfo *exinfo, uint8 a) {
  assert(0);
}

static ParseTileAnimFunc *const kkParseTileAnimsFuncs[28] = {
    &ParseTileAnimFunc_Null,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_1,
    &ParseTileAnimFunc_10,
    &ParseTileAnimFunc_10,
    &ParseTileAnimFunc_10,
    &ParseTileAnimFunc_13,
    &ParseTileAnimFunc_14,
    &ParseTileAnimFunc_15,
    &ParseTileAnimFunc_16,
    &ParseTileAnimFunc_17,
    &ParseTileAnimFunc_18,
    &ParseTileAnimFunc_19,
    &ParseTileAnimFunc_1A,
    &ParseTileAnimFunc_1B,
};

void LmFunc_10C713(LongPtr p, uint16 r8, uint8 r10, uint16 k) {
  const uint8 *pp = kLmExanimBlob(Load24(p));
  ParseTileAnimCtx ctx = {.p = pp, .porg = pp, .ptr = p, .r8 = g_ram + 0x10000 + r8, .r10 = r10};

  uint8 cmd = ctx.p[0];
  uint8 arg = ctx.p[1];
  ctx.p += 2;
  kkParseTileAnimsFuncs[cmd](&ctx, cmd, &ex_anim_info_0 + k, arg);
}

void LmHook_SetStandardPPUSettings(void) {
  WriteReg(SETINI, 0);
  WriteReg(MOSAIC, 0);
  WriteReg(BG1SC, 0x31u);
  WriteReg(BG2SC, 0x39u);
  WriteReg(BG3SC, 0x53u);
  WriteReg(BG12NBA, 0);
  WriteReg(BG34NBA, 4u);
  mirror_bg1_and2_window_mask_settings = 0;
  mirror_bg3_and4_window_mask_settings = 0;
  mirror_object_and_color_window_settings = 0;
  WriteReg(WBGLOG, 0);
  WriteReg(WOBJLOG, 0);
  WriteReg(TMW, 0);
  WriteReg(TSW, 0);
  mirror_color_math_initial_settings = 2;
  WriteReg(M7SEL, 0x80u);
}

void LmHook_HandleStandardLevelCameraScroll() {
  lm_var8325 = mirror_current_layer2_ypos;
  lm_var8323 = mirror_current_layer2_xpos;
  lm_var8321 = mirror_current_layer1_ypos;
  lm_var831f = mirror_current_layer1_xpos;
}

void LmHook_HandleStandardLevelCameraScrollB(void) {
  uint8 kShifts[] = { 0, 1, 5, 2, 3, 4, 6 };
  uint16 x = mirror_current_layer1_xpos;
  if (flag_layer2_horiz_scroll_level_setting != 0)
    mirror_current_layer2_xpos = mirror_current_layer1_xpos >> kShifts[flag_layer2_horiz_scroll_level_setting - 1];
  if (flag_layer2_vert_scroll_level_setting != 0)
    mirror_current_layer2_ypos = (mirror_current_layer1_ypos >> kShifts[flag_layer2_vert_scroll_level_setting - 1]) + camera_layer2_ypos_relative_to_layer1;
}

void LmHook_HandleStandardLevelCameraScrollC(void) {
  for (int i = 3; i >= 0; --i ) {
    uint16 v2 = (&mirror_current_layer1_xpos)[i];
    get_PointU16(misc_layer1_pos, i * 2)->x = v2;
    if ( v2 != lm_arr1831f[i] ) {
      lm_arr1831b[i] = (int16)(v2 - lm_arr1831f[i]) < 0 ? 0 : 2;
    }
  }
}

uint16 LmHook_HandleStandardLevelCameraScrollD(void) {
  uint16 a = lm_level_height + (extra_flags_and_horiz_level_mode & 0x40 ? 15 : 0) - 0xf0;
  if (sign16(a))
    a = 0;
  return a;
}

uint16 LmHook_HandleStandardLevelCameraScrollG(uint16 r2, uint16 r4) {
  if (!sign16((r2 + 6) ^ -6))
    r2 = -6;
  r2 += mirror_current_layer1_ypos;
  if (sign16(r2 - r4))
    r2 = r4;
  return r2;
}

uint16 LmHook_LoadStripeImage(uint16 r3) {
  uint16 r9, r11;

  if (misc_game_mode != 20 && misc_game_mode != 7 && misc_game_mode != 19 && misc_game_mode != 5)
    return r3; // Org code

  if ((r3 & 0x7000) != 0x2000) {
    if ((r3 & 0x7000) != 0x3000)
      return r3;
    r11 = (r3 >> 5) & 0x1F | 4 * ((r3 & 0x800) >> 8);
    r9 = ((mirror_current_layer2_ypos >> 3) - 2) & 0x3F;
    if ( ((r9 + 32) & 0x40) != 0 ) {
      if ( r11 < r9 && (uint8)((r9 + 32) & 0x3F) < r11 )
        goto LABEL_23;
    } else if ( r11 < r9 || (uint8)(r9 + 32) < r11 ) {
      goto LABEL_23;
    }
    return r3 & 0x7FF | 0x3800;
  } else {
    r11 = (r3 >> 5) & 0x1F | 4 * ((r3 & 0x800) >> 8);
    r9 = ((mirror_current_layer1_ypos >> 3) - 2) & 0x3F;
    if (((r9 + 32) & 0x40) == 0 ) {
      if ( r11 < r9 || (uint8)(r9 + 32) < r11 )
        goto LABEL_23;
      return r3 & 0x7FF | 0x3000;
    }
    if ( r11 >= r9 || ((r9 + 32) & 0x3F) >= r11 )
      return r3 & 0x7FF | 0x3000;
  }
LABEL_23:
  return 0xffff; // skip this
}

void LmHook_GameMode0C_LoadOverworld(uint16 k) {
  uint32 addr = LM_FEATURES->kLmLvlInfo_addr_other;
  if (addr == 0)
    return;
  lm_level_info.addr = addr + k * 32;
  lm_level_info.bank = addr >> 16;
  lm_var9 = 0x42;
  lm_varB = 0;
}

bool LmHook_WantEraseSprite(uint16 k, uint16 y) {
  if (!sign16(y - lm_level_height))
    return true;
  y -= mirror_current_layer1_ypos;
  if (sign16(y - max_y_offset_from_screen_to_spawn) && !sign16(y - min_y_offset_from_screen_to_spawn))
    return false;
  if (spr_property_bits167a[k] & 4 || misc_nmito_use_flag == 0x80)
    return false;
  return true;
}

uint16 LmHook_LoadLevelInfo_C(uint16 a) {
  if (misc_intro_level_flag)
    return a;

  a = ow_level_number_lo;
  if (a >= 0x25)
    a += 0x100 - 0x24;
  return a;
}

uint16 LmHook_LoadLevelInfo_A(uint16 a, uint16 k) {
  if (!g_lunar_magic)
    return a;

  uint8 f = misc_subscreen_exit_properties[k];
  if (!(f & 4)) {
    misc_level_header_entrance_settings = 0;
    return (a & 0xff) | (ow_level_number_lo >= 0x25) << 8;
  }
  flag_use_secondary_entrance = (f >> 1) & 1;
  misc_level_header_entrance_settings = (f & 8) << 3;
  return ((f & 1) | (f >> 4) << 1) << 8 | (a & 0xff);
}

void LmHook_ExpandLvlHdr(uint16 j) {
  if (!HAS_LM_FEATURE(kLmFeature_LoadLevel))
    return;

  uint8 R4_ = kLm6FC00[j];
  lm_var13CD = kLm6FE00[j];
  uint8 v2 = kLm5DE00[j];
  misc_level_header_entrance_settings |= v2 & 0xC0;
  if ((v2 & 0x20) != 0) {
    uint8 v3 = 8 * (v2 & 0x18);
    LOBYTE(player_xpos) = 2 * v3;
    HIBYTE(player_xpos) = 4 * v3;
    LOBYTE(player_xpos) = (16 * kLevelInfo_05F200[j]) & 0x70 | (2 * v3);
    LOBYTE(player_ypos) = 16 * kLevelInfo_05F000[j];
    HIBYTE(player_ypos) = R4_ & 0x3F;
  }
}


void LmStdObj22_DirectMap16(uint8 k) {
  LmHandleDirectMapObjs(0);
}

void LmStdObj23(uint8 k) {
  LmHandleDirectMapObjs(1);
}

void LmHandleDirectMapObjsInner(uint8 r0, uint8 r1, uint8 r2, uint8 r3) {
  LmHook_PreserveLevelDataPointerInObjects();

  uint8 j = blocks_sub_scr_pos;
  do {
    uint8 r2cur = r2;
    do {
      uint8 *p = ptr_lo_map16_data + j;
      p[0x0] = r0;
      p[0x10000] = r1;

      if ((++j & 0xf) == 0)
        j = LmHook_HandleHorizontalSubScreenCrossingForCurrentObject_Entry2();
    } while ((int8)--r2cur >= 0);
    LmHook_RestoreLevelDataPointerInObjects();
    j = LmHook_HandleVerticalSubScreenCrossingForCurrentObject();
  } while ((int8)--r3 >= 0);
}

void LmHandleDirectMapObjs(uint8 a) {
  uint8 r1 = a;
  uint8 r0 = *ptr_layer1_data++;
  uint8 r2 = blocks_size_or_type & 0xf;
  uint8 r3 = blocks_size_or_type >> 4;
  LmHandleDirectMapObjsInner(r0, r1, r2, r3);
}

void LmStdObj24(uint8 k) {
  lunar_magic_FD = blocks_sub_scr_pos;
  lunar_magic_FC = blocks_size_or_type;
}

void LmStdObj25(uint8 k) {
  lunar_magic_FA = blocks_sub_scr_pos;
  lunar_magic_FB = blocks_size_or_type;
}

void LmStdObj26_MusicBypass(uint8 k) {
  if (blocks_sub_scr_pos)
    misc_music_register_backup = blocks_sub_scr_pos - 1;
  if (blocks_size_or_type)
    misc_music_register_backup = blocks_size_or_type - 1;
}

void LmStdObj27(uint8 k) {
  uint8 a = *ptr_layer1_data++;
  if ((a & 0xc0) == 0) {
    LmHandleDirectMapObjs(a);
  } else {
    LmFunc_DF1C3(a, a & 0x3f);
  }
}

void LmFunc_DF1C3(uint8 k, uint8 a) {
  uint16 r0 = a << 8 | *ptr_layer1_data++;
  uint16 r4 = r0;
  uint16 r6 = r0;
  uint8 v5, v6;

  uint8 r2 = blocks_size_or_type & 0xF;
  uint8 r3 = blocks_size_or_type >> 4;
  if ((k & 0x80u) == 0) {
    v5 = blocks_size_or_type;
    v6 = blocks_size_or_type;
  } else {
    v5 = *ptr_layer1_data++;
    v6 = v5;
    if (k & 0x40) {
      r3 = *ptr_layer1_data++;
      r2 = blocks_size_or_type & 0x7F;
      if ((blocks_size_or_type & 0x80u) != 0) {
        uint8 f = *ptr_layer1_data++;

        if (lm_state_array[f >> 3 & 0xf] & (1 << (f & 7))) {
          if (f & 0x80) {
            r0 += 0x100;
            r4 += 0x100;
            r6 += 0x100;
          }
        } else {
          if (!(f & 0x80))
            return;
        }
      }
      v5 = v6;
      if (!v6) {
        LmHandleDirectMapObjsInner(r0, r0 >> 8, r2, r3);
        return;
      }
    }
  }
  uint8 r8 = v5 & 0xF;
  uint8 r10 = v5 & 0xF;
  uint8 r9 = v6 >> 4;
  blocks_object_number = v6 >> 4;
  LmHook_PreserveLevelDataPointerInObjects();
  uint8 v9 = r2;
  uint8 v10 = blocks_sub_scr_pos;

  do {
    while (1) {
      ptr_lo_map16_data[v10 + 0x10000] = r4 >> 8;
      ptr_lo_map16_data[v10] = r4;
      uint8 v11 = r4;
      if ((--v9 & 0x80u) != 0)
        break;
      uint8 v12 = v11 + 1;
      if ((--r10 & 0x80u) != 0) {
        r10 = r8;
        v12 = r6;
      }
      r4 = (r4 & 0xff00) | v12;
      if ((++v10 & 0xF) == 0)
        v10 = LmHook_HandleHorizontalSubScreenCrossingForCurrentObject_Entry2();
    }
    r10 = r8;
    uint16 v13;
    if ((--blocks_object_number & 0x80u) != 0) {
      blocks_object_number = r9;
      v13 = r0;
    } else {
      v13 = r6 + 16;
    }
    r4 = v13;
    r6 = v13;
    LmHook_RestoreLevelDataPointerInObjects();
    v10 = LmHook_HandleVerticalSubScreenCrossingForCurrentObject();
    v9 = r2;
  } while ((int8)--r3 >= 0);
}

void LmStdObj28(uint8 k) {
  if ((blocks_size_or_type & 0x80) != 0 || !counter_sublevels_entered) {
    counter_timer_ones = blocks_sub_scr_pos & 0xF;
    counter_timer_tens = blocks_sub_scr_pos >> 4;
    counter_timer_hundreds = blocks_size_or_type & 0xF;
  }
}

void LmStdObj29(uint8 k) {
  uint8 t = *ptr_layer1_data++;
  if ((t & 0xc0) == 0)
    LmHandleDirectMapObjs(t | 0x40);
  else
    LmFunc_DF1C3(t, t & 0x3f | 0x40);
}

bool LmHook_CustomTitleScreenDemo(void) {
  uint16 v0;
  uint8 v1;
  uint8 v2;

  if ( !misc_title_screen_movement_data_index ) {
    lm_title_screen_var = 0;
    misc_title_screen_movement_data_index = 1;
  }
  v0 = lm_title_screen_var;
  if ( !--timer_title_screen_input_timer ) {
    timer_title_screen_input_timer = kLmTitleScreenMoves[lm_title_screen_var + 2];
    v0 = lm_title_screen_var + 3;
    lm_title_screen_var += 3;
  }
  v1 = kLmTitleScreenMoves[v0 - 3];
  if ( v1 != 255 ) {
    io_controller_hold1 = v1;
    io_controller_press1 = v1 & 0x3F;
    v2 = kLmTitleScreenMoves[v0 - 2];
    io_controller_press1 |= (16 * v2) & 0xC0;
    io_controller_hold2 = v2 & 0xB0;
    io_controller_press2 = (2 * v2) & 0x80;
    return true;
  }
  return false;
}

void LmHook_InitializeSaveData(void) {
  if (kLmInitSaveData_SIZE)
    memcpy(ow_save_buffer, kLmInitSaveData, 96);
} 

void LmFunc13_SwitchBlock(uint8 j) {
  uint8 v1; // si
  char i; // di
  OamEnt *oam; // rbx

  misc_color_of_palace_switch_pressed1 = j + 1;
  v1 = 16 * j;
  uint16 r0 = 0;
  for ( i = 28; i >= 0; i -= 4 ) {
    oam = get_OamEnt(oam_buf, i);
    WORD(oam->charnum) = kDisplayMessage_SwitchBlockTileAndProperties[v1 >> 1];
    WORD(oam->xpos) = WORD(kDisplayMessage_SwitchBlockXAndYDisp[r0]);
    v1 += 2;
    r0 += 2;
  }
  WORD(*oam_buf_ext) = 0;
}

void LmHook_DisplayMessage(void) {
  uint16 v0; // di
  uint16 v1; // si
  uint16 v2; // di
  uint16 v3; // si
  uint16 v4; // si
  uint8 v5; // al
  uint16 v6; // [rsp+45h] [rbp-3h]
  uint8 r3 = 0; // wtf

  if ( misc_display_message == 3 ) {
    v1 = 0;
    v0 = 1;
  } else {
    v1 = ow_level_number_lo;
    if ( ow_level_number_lo == kLmDisplayMessage_Tab1[0]) {
      v0 = player_riding_yoshi_flag != 0;
    } else {
      v0 = misc_display_message - 1;
      if ( misc_display_message == 1 ) {
        if ( ow_level_number_lo == kLmDisplayMessage_Tab1[1]
          || (v0 = 1, ow_level_number_lo == kLmDisplayMessage_Tab1[2])
          || (v0 = 2, ow_level_number_lo == kLmDisplayMessage_Tab1[3])
          || (v0 = 3, ow_level_number_lo == kLmDisplayMessage_Tab1[4]) ) {
          LmFunc13_SwitchBlock(v0);
        }
        v0 = 0;
      }
    }
  }
  uint16 r0 = kLmDisplayMessage_3BE80[(2 * v1 + v0)];
  v2 = stripe_image_upload;
  v3 = 14;
  uint16 r2 = 0;
  do {
    WORD(stripe_image_upload_data[v2]) = kLmDisplayMessage_3BC7F[v3 >> 1];
    WORD(stripe_image_upload_data[v2 + 2]) = 8960;
    v6 = v3;
    r2 = 18;
    v4 = r0;
    do {
      v5 = 31;
      if ( (r3 & 0x80u) == 0 ) {
        v5 = kLmDisplayMessage_Tab0[v4++];
        if ( v5 == 0xFE ) {
          r3 = -2;
          v5 = 31;
        }
      }
      stripe_image_upload_data[v2 + 4] = v5;
      stripe_image_upload_data[v2 + 5] = 57;
      v2 += 2;
    } while ( --r2 );
    r0 = v4;
    v2 += 4;
    v3 = v6 - 2;
  } while ( (int16)v3 >= 0 );
  WORD(stripe_image_upload_data[v2]) = 255;
  stripe_image_upload = v2;
  mirror_layer3_xpos = 0;
  mirror_layer3_ypos = 0;
  flag_disable_layer3_scroll = 1;
}

void LmHook_OverworldPalette(void) {
  uint16 v2 = (misc_level_tileset_setting & 0xF) - 1;
  if ( ow_level_tile_settings[73] & 0x80 )
    v2 += 7;
  MemCpy(palettes_palette_mirror, kLmOverworldPal + v2 * 0x200, 0x200u);
}

void LmHook_LevelNamesPatch(uint16 a) {
  uint16 v1; // si
  uint16 v2; // di

  uint16 r0 = 16 * a;
  v1 = 16 * a + 3 * a;
  v2 = stripe_image_upload;
  uint16 r2 = stripe_image_upload + 38;
  stripe_image_upload += 42;
  WORD(stripe_image_upload_data[v2 + 2]) = 0x2500;
  WORD(stripe_image_upload_data[v2]) = 0x8B50;
  do
  {
    stripe_image_upload_data[v2 + 4] = kLmLevelNamesPatch[v1];
    stripe_image_upload_data[v2 + 5] = 57;
    v2 += 2;
    ++v1;
  } while ( v2 < r2);
  stripe_image_upload_data[v2 + 4] = -1;
}

int LmHook_LoadLevelInfo_E(uint16 k, uint16 lvl, uint8 r0, uint8 r1) {
  uint8 f = kLm5FE00[k];
  misc_level_header_entrance_settings |= f & 0x87;
  uint8 r15 = (f & 8) >> 3;
  uint8 r2 = kLmLevelData5DC85[k];
  uint8 r4 = r2 & 0x7F;
  uint8 g = kLmLevelData5DC8A[k];
  lm_var13CD = g & 0xC0;
  misc_level_header_entrance_settings |= 2 * (g & 0x20);
  r4 |= kLm6FC00[lvl] & 0x80;
  lm_var13CD = kLm6FE00[lvl] & 0x3F | g & 0xC0;
  if ((f & 0x40) != 0) {
    player_xpos = 8 * (f & 0x30) | (r1 >> 1) & 0x70;
    LOBYTE(player_ypos) = 16 * r0;
    HIBYTE(player_ypos) = r2 & 0x3F;
  }
  if ((r2 & 0x80) != 0) {
    misc_game_mode = 12;
    mirror_screen_display_register = 0;
    misc_mosaic_direction = 0;
    mirror_mosaic_size_and_bgenable = 0;
    if ((f & 0x10) != 0) {
      ow_star_pipe_index = r0;
      ++ow_warping_on_pipe_or_star_flag;
    }
    if ((f & 0x20) != 0) {
      ow_current_event_number = r1;
    }
    uint8 v3 = f & 7;
    if (v3 == 7)
      v3 = 0x80;
    misc_exit_level_action = v3;
    if (2 * v3) {
      ++flag_got_midpoint;
      ++counter_enemy_rollcall_screen;
    }
    return -1;
  } else {
    return r0 >> 4;
  }
}

uint16 LmHook_DestroyTileAnimation2(uint16 a) {
  return a + (((a & 0x3E0) == 0x3E0) ? 0x420 : 0x20);
}

const uint8* LmHook_DestroyTileAnimation3(uint16 k) {
  return (uint8*)Lm_GetMap16RomAddr(blocks_map16_table_hi[k] << 8 | blocks_map16_table_lo[k]);
}

uint16 LmHook_RemapDestroyTile(uint16 a) {
  a += 0x10;
  if ((uint8)a < 0x10)
    a += 0x100;
  return a;
}

void LmHook_EventStuff(uint8 a, bool from_where) {

  uint16 r6 = kLmEventStuff1[a];
  uint16 r4 = kLmEventStuff1[a + 1];

  uint16 j = r4 - r6;
  if (j == 0)
    return;
  uint16 k = r6;

  do {
    uint16 r0 = kLmEventStuff2[k >> 1];
    uint16 r4 = kLmEventStuff3[k >> 1];
    uint8 a = kLmEventStuff4[k >> 1];
    if (a & 1) {
      if (from_where)
        BufferEventTileToLayer2Tilemap_Entry2(k, r0, r4);
    } else {
      blocks_map16_table_lo[r4] = r0;
      blocks_map16_table_hi[r4] = r0 >> 8;
    }
  } while (k += 2, j -= 2);
}


#define wallkick_flags g_ram[0x61]
#define wallkick_no_back_timer g_ram[0x62]
#define wallkick_temp_y_spd g_ram[0x63]

void HackHandleWalljump() {
  uint8 v0;
  uint8 v1;
  bool v2;
  uint8 v3;
  uint8 v4;

  if ((player_blocked_flags & 4) != 0) {
    wallkick_flags = 0;
    return;
  }
  if ((wallkick_flags & 3) == 0) {
    if (wallkick_no_back_timer) {
      --wallkick_no_back_timer;
      io_controller_hold1 &= ~(wallkick_flags >> 2);
      io_controller_press1 &= ~(wallkick_flags >> 2);
    }
    if ((player_yspeed & 0x80u) == 0 &&
        !(player_riding_yoshi_flag |
          (uint8)(timer_end_level | player_carrying_something_flag1 | player_spin_jump_flag | player_cape_flying_phase |
                            player_swimming_flag | player_climbing_flag | player_ducking_flag | player_current_state)) &&
        (uint8)player_on_screen_pos_x >= 9u && (uint8)player_on_screen_pos_x < 0xE8u &&
        (player_blocked_flags & (wallkick_flags >> 2)) == 0 && (io_controller_hold1 & 3) != 3 &&
        (player_blocked_flags & io_controller_hold1) != 0) {
      wallkick_flags = player_blocked_flags & io_controller_hold1;
      wallkick_temp_y_spd = player_yspeed;
    }
    return;
  }
  if (player_riding_yoshi_flag | (uint8)(player_carrying_something_flag1 | player_swimming_flag | player_current_state) ||
      (uint8)(player_xspeed + 7) >= 0xFu || (io_controller_hold1 & 3) == 3 || (wallkick_flags & io_controller_hold1) == 0) {
    wallkick_flags = 0;
    return;
  }
  io_controller_hold1 &= ~0x40u;
  io_controller_press1 &= ~0x40u;
  player_facing_direction = wallkick_flags - 1;
  if ((io_controller_press1 & 0x80u) != 0) {
    io_sound_ch2 = 1;
  } else {
    if ((io_controller_press2 & 0x80u) == 0) {
      if ((counter_local_frames & 7) == 0) {
        v0 = player_facing_direction;
        v1 = 3;
        while (smoke_spr_spriteid[v1]) {
          if ((--v1 & 0x80u) != 0)
            goto LABEL_27;
        }
        smoke_spr_spriteid[v1] = 3;
        static const uint8 kWallKickSmokeXOffs[2] = {12, -2};
        smoke_spr_xpos_lo[v1] = kWallKickSmokeXOffs[v0] + player_xpos;
        smoke_spr_ypos_lo[v1] = player_ypos + 16;
        smoke_spr_timer[v1] = 19;
      }
LABEL_27:
      player_current_pose = 13;
      v2 = (char)(wallkick_temp_y_spd + 4) < 0;
      v3 = wallkick_temp_y_spd + 4;
      player_yspeed = wallkick_temp_y_spd + 4;
      wallkick_temp_y_spd += 4;
      if (!v2 && v3 >= 0x24u) {
        player_yspeed = 36;
        wallkick_temp_y_spd = 36;
      }
      return;
    }
    ++player_spin_jump_flag;
    io_sound_ch3 = 4;
  }
  ++camera_bounce_off_spring_flag;
  io_sound_ch1 = 1;
  player_in_air_flag = 11;
  player_yspeed = -72;
  static const uint8 kWallKickXSpeed[2] = { -32, 32 };
  player_xspeed = kWallKickXSpeed[player_facing_direction];
  io_controller_hold1 &= ~wallkick_flags;
  io_controller_press1 &= ~wallkick_flags;
  wallkick_flags *= 4;
  wallkick_no_back_timer = 16;
  v4 = 3;
  while (smoke_spr_spriteid[v4]) {
    if ((--v4 & 0x80u) != 0)
      return;
  }
  smoke_spr_spriteid[v4] = 1;
  smoke_spr_xpos_lo[v4] = player_xpos;
  smoke_spr_ypos_lo[v4] = player_ypos + 16;
  smoke_spr_timer[v4] = 16;
}

uint8 LmFunc_ReadLevelInfoByte(const uint8 *p) {
  return p[0] & 0xf0 | p[-2] >> 4;
}

static const uint16 kLmUploadGfx_Tab0[4] = { 0x140,     0, 0x100,     0};
static const uint16 kLmUploadGfx_Tab1[4] = { 0x2000, 0x1000, 0x800,     0};
static const uint16 kLmUploadGfx_Tab2[4] = { 0x50A0, 0x5000, 0x5080, 0x5800};

void LmFunc_UploadGraphics_StepA(void) {
  if (lm_var9 != 0x42 && lm_var9 != 0x41) {
    lm_word_7E145E = 0;
    lm_var1a = 0;
    lm_var1b = 0;
    lm_var1c = 0;
    return;
  }
  const uint8 *t8a = (const uint8 *)GetLvlInfo();
  lm_var1a = t8a[0x17] >> 4;
  lm_var1c = LmFunc_ReadLevelInfoByte(t8a + 0x15);
  lm_var1b = LmFunc_ReadLevelInfoByte(t8a + 7);
  lm_word_7E145E = LmFunc_ReadLevelInfoByte(t8a + 0x1f) << 8 | LmFunc_ReadLevelInfoByte(t8a + 0x1b);
  if (t8a[1] & 0x20) {
    uint16 v2 = WORD(t8a[2]);
    if ((v2 & 0xfff) != 0x7f) {
      uint16 r0 = kLmUploadGfx_Tab0[(v2 >> 14) & 3];
      uint16 v5 = kLmUploadGfx_Tab1[(v2 >> 12) & 3];
      uint16 v6 = kLmUploadGfx_Tab2[(v2 >> 14) & 3];
      if (v5 <= 0x1000) {
        LmFunc15_DecompressSlotB(1);
        SmwCopyToVram(v6, graphics_graphic_decompression_buffer + r0, v5 - r0);
      } else {
        SmwCopyToVram(0x4000, graphics_graphic_decompression_buffer + 0x1000, 0x1000);
        LmFunc15_DecompressSlotB(1);
        SmwCopyToVram(v6, graphics_graphic_decompression_buffer + r0, v5 - r0);
        SmwCopyFromVram(0x4000, graphics_graphic_decompression_buffer + 0x1000, 0x1000);
      }
    }
    lm_var1a |= 0x80;
  }
}

uint16 LmFunc_10D796(uint8 r11, uint16 *r7, uint16 *r9) {
  if (r11 == 1) {
    *r7 = 0x404;
    return 8;
  } else if (r11 == 3) {
    *r9 = 0x101;
    *r7 = 0x5959;
    return 8;
  }
  return 0;
}

void LmFunc_10D7BC(uint16 k, uint16 *r1, uint16 *r4, uint16 r7, uint16 r9) {
  uint16 v1 = 0x1e00;
  do {
    r1[v1 >> 1] = r7;
    if (r9)
      r4[v1 >> 1] = r9;
    v1 += 2;
  } while ( --k );
}

void LmFunc_10D7CF(uint16 k, uint16 *r1, uint16 *r4, uint16 r7, uint16 r9) {
  uint16 r14 = 16;
  uint16 t = 0x1c00;
  do {
    uint16 v1 = t;
    uint16 kcur = k;
    do {
      r1[v1 >> 1] = r7;
      if (r9)
        r4[v1 >> 1] = r9;
      v1 += 2;
    } while (--kcur);
    t += 0x1b0;
  } while (--r14);
}

void LmFunc_10D7FA(uint16 k, uint16 r1_value, uint16 *r1, uint16 *r4, uint16 r7, uint16 r9) {
  uint16 j = 256;
  uint16 t = 256;
  for (;;) {
    uint16 kcur = k;
    do {
      r1[j >> 1] = r7;
      if (r9)
        r4[j >> 1] = r9;
      j += 2;
    } while (--kcur);
    bool v2 = __CFADD__(lm_level_height, t);
    t += lm_level_height;
    j = t;
    if ((t + r1_value) >= 0x10000 || (t + r1_value + lm_level_height) > 0x10000)
      return;
  }
}


void LmHook_InitializeLevelLayer3_GenerateInteractiveTideWater(void) {
  static const uint16 kword_10D776[16] = {
    0,     5,     5,     5, 0x130, 0x200, 0x201, 0x202,
    0x203, 0x204, 0x205, 0x206, 0x207, 0x208, 0x209, 0x20A,
  };
  uint16 *r1, *r4;
  uint8 r11 = lm_var1b & 0xF;
  
  r1 = (uint16 *)(g_ram + 0xc800);
  r4 = (uint16 *)(g_ram + 0x1c800);

  uint16 v1 = kword_10D776[r11];
  uint16 r7 = (uint8)(v1) * 0x101;
  uint16 r9 = (uint8)(v1 >> 8) * 0x101;
  if (misc_level_layout_flags & 1) {
    misc_level_layout_flags |= 2;
    LmFunc_10D7BC(0xd00, r1, r4, r7, r9);
    uint16 v2 = LmFunc_10D796(r11, &r7, &r9);
    if (v2)
      LmFunc_10D7BC(v2, r1, r4, r7, r9);
  } else if (HAS_LM_FEATURE(kLmFeature_LoadLevel)) {
    r1 = (uint16 *)(g_ram + L2_Screen_Lo[0].addr);
    r4 = (uint16 *)(g_ram + L2_Screen_Hi[0].addr + 0x10000);
    if (lm_level_height >= 0x110) {
      LmFunc_10D7FA((lm_level_height - 0x100) >> 1, L2_Screen_Lo[0].addr, r1, r4, r7, r9);
      uint16 v2 = LmFunc_10D796(r11, &r7, &r9);
      if (v2)
        LmFunc_10D7FA(v2, L2_Screen_Lo[0].addr, r1, r4, r7, r9);
    }
  } else {
    LmFunc_10D7CF(0x58, r1, r4, r7, r9);
    uint16 v2 = LmFunc_10D796(r11, &r7, &r9);
    if (v2)
      LmFunc_10D7CF(v2, r1, r4, r7, r9);
  }
  misc_level_layout_flags |= 0x80u;
}

void LmFunc_UpdateBG12NBA(void) {  // FF9E0
  // not used
}

