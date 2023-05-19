#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"
void InitializeNormalSpriteRAMTables_ClearTables(uint8 k) {  // 07f722
  spr_table164a[k] = 0;
  spr_table1632[k] = 0;
  spr_table00c2[k] = 0;
  spr_table151c[k] = 0;
  spr_table1528[k] = 0;
  spr_table1534[k] = 0;
  spr_table157c[k] = 0;
  spr_table1588[k] = 0;
  spr_table15c4[k] = 0;
  spr_table1602[k] = 0;
  spr_decrementing_table1540[k] = 0;
  spr_decrementing_table154c[k] = 0;
  spr_decrementing_table1558[k] = 0;
  spr_decrementing_table1564[k] = 0;
  spr_decrementing_table1fe2[k] = 0;
  spr_table1626[k] = 0;
  spr_table1570[k] = 0;
  spr_xspeed[k] = 0;
  spr_sub_xpos[k] = 0;
  spr_yspeed[k] = 0;
  spr_sub_ypos[k] = 0;
  spr_no_level_collision_flag[k] = 0;
  spr_table15d0[k] = 0;
  spr_decrementing_table163e[k] = 0;
  spr_property_bits1656[k] = 0;
  spr_property_bits1662[k] = 0;
  spr_property_bits166e[k] = 0;
  spr_property_bits167a[k] = 0;
  spr_property_bits1686[k] = 0;
  spr_table187b[k] = 0;
  spr_table160e[k] = 0;
  spr_table1594[k] = 0;
  spr_table1504[k] = 0;
  spr_unused_table1fd6[k] = 0;
  spr_xoffscreen_flag[k] = 1;
}

void InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(uint8 k) {  // 07f78b
  spr_table15f6[k] = kInitializeNormalSpriteRAMTables_Sprite166EVals[spr_spriteid[k]] & 0xF;
  InitializeNormalSpriteRAMTables_PropertyTables(k);
}

void InitializeNormalSpriteRAMTables_PropertyTables(uint8 k) {  // 07f7a0
  uint8 v2 = spr_spriteid[k];
  spr_property_bits1656[k] = kInitializeNormalSpriteRAMTables_Sprite1656Vals[v2];
  spr_property_bits1662[k] = kInitializeNormalSpriteRAMTables_Sprite1662Vals[v2];
  spr_property_bits166e[k] = kInitializeNormalSpriteRAMTables_Sprite166EVals[v2];
  spr_property_bits167a[k] = kInitializeNormalSpriteRAMTables_Sprite167AVals[v2];
  spr_property_bits1686[k] = kInitializeNormalSpriteRAMTables_Sprite1686Vals[v2];
  spr_property_bits190f[k] = kInitializeNormalSpriteRAMTables_Sprite190FVals[v2];
}

void InitializeNormalSpriteRAMTables(uint8 k) {  // 07f7d2
  InitializeNormalSpriteRAMTables_ClearTables(k);
  InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
}

void SpawnSpinJumpStars(uint8 k) {  // 07fc3b
  for (int8 i = 3; i >= 0; --i)
    SpawnSpinJumpStars_07FC47(i);
}

void SpawnSpinJumpStars_07FC47(uint8 k) {  // 07fc47
  uint8 v1 = 7;
  while (ext_spr_spriteid[v1]) {
    if ((--v1 & 0x80) != 0)
      return;
  }
  ext_spr_spriteid[v1] = 16;
  uint8 v2 = spr_current_slotid;
  SetHiLo(&ext_spr_ypos_hi[v1], &ext_spr_ypos_lo[v1], GetSprYPos(v2) + 4);
  SetHiLo(&ext_spr_xpos_hi[v1], &ext_spr_xpos_lo[v1], GetSprXPos(v2) + 4);
  ext_spr_xspeed[v1] = kSpawnSpinJumpStars_InitialXSpeed[k];
  ext_spr_yspeed[v1] = kSpawnSpinJumpStars_InitialYSpeed[k];
  ext_spr_decrementing_table176f[v1] = 23;
}
