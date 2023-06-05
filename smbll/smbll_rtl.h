#pragma once

#include "../src/common_rtl.h"

static inline OamEnt *get_OamEnt(OamEnt *base, uint16 off) { return (OamEnt *)((uint8 *)base + off); }

#pragma pack(push, 1)
typedef struct RelPosForOffs {
  uint8 player;
  uint8 enemy[10];
  uint8 fireball[2];
  uint8 block[4];
  uint8 misc[9];
  uint8 bubble[2];
} RelPosForOffs;
typedef struct RelPosStruct {
  uint8 player;
  uint8 enemy;
  uint8 fireball;
  uint8 bubble;
  uint8 block;
  uint8 unk5;
  uint8 misc;
} RelPosStruct;
#pragma pack(pop)

uint16 Smbll_SetupLayer2Bg_Callfunc(uint16 k, uint16 j);

enum RelPos {
  kRelPos_Player = 0x0,
  kRelPos_Enemy = 0x1,
  kRelPos_Fireball = 0x2,
  kRelPos_Bubble = 0x3,
  kRelPos_Block = 0x4,
  kRelPos_Unk = 0x5,
  kRelPos_Misc = 0x6,
};
