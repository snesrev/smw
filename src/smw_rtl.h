#pragma once
#include "common_rtl.h"
#include "snes/snes_regs.h"

PointU16 *get_PointU16(PointU16 *pt, uint8 off);
static inline OamEnt *get_OamEnt(OamEnt *base, uint16 off) { return (OamEnt *)((uint8 *)base + off); }

void SmwVectorReset();
void SmwRunOneFrameOfGame_Internal();
void SmwVectorNMI();
void SmwVectorIRQ();
void SmwSavePlaythroughSnapshot();

void SmwCopyToVram(uint16 vram_addr, const uint8 *src, int n);
void SmwClearVram(uint16 vram_addr, uint16 value, int n);
void SmwCopyToVramPitch32(uint16 vram_addr, const uint8 *src, int n);
void SmwCopyToVramLow(uint16 vram_addr, const uint8 *src, int n);

void SmwDrawPpuFrame(void);
void SmwRunOneFrameOfGame(void);

extern bool g_did_finish_level_hook;

void AddSprXPos(uint8 k, uint16 x);
void AddSprYPos(uint8 k, uint16 y);
void AddSprXYPos(uint8 k, uint16 x, uint16 y);
uint16 GetSprXPos(uint8 k);
uint16 GetSprYPos(uint8 k);
void SetSprXPos(uint8 k, uint16 x);
void SetSprYPos(uint8 k, uint16 y);
void SetSprXYPos(uint8 k, uint16 x, uint16 y);

#pragma pack (push, 1)
typedef struct OwExits {
  uint16 field_0;
  uint16 field_2;
  uint8 field_4;
} OwExits;

typedef struct SpriteSlotData {
  uint8 field_0;
  uint16 field_1;
  uint16 field_3;
} SpriteSlotData;

typedef struct LevelTileAnimations {
  uint16 field_0;
  uint16 field_2;
  uint16 field_4;
} LevelTileAnimations;

#pragma pack (pop)

typedef struct GenTileArgs {
  uint8 r6, r7;
  uint16 r8;
  uint16 r12, r14;
  uint16 r10;
  uint8 *ptr_lo_map16_data;
} GenTileArgs;

const uint8 *GetSpriteListPtr();
uint8 GetCurrentSlope(int i);