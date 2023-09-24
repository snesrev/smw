#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"
#include "assets/smw_assets.h"

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

#if 0
static const uint16 kOwStarPipeWarp_SrcX_048431[27] = { 0x11, 0xa, 0x9, 0xb, 0x12, 0xa, 0x7, 0x20a, 0x203, 0x410, 0x412, 0x41c, 0x414, 0x612, 0x200, 0x612, 0x10, 0x617, 0x14, 0x61c, 0x14, 0x61c, 0x617, 0x511, 0x511, 0x414, 0x106,  };
static const uint16 kOwStarPipeWarp_SrcY_048467[27] = { 0x7, 0x3, 0x10, 0xe, 0x17, 0x18, 0x12, 0x14, 0xb, 0x3, 0x1, 0x9, 0x9, 0x1d, 0xe, 0x18, 0xf, 0x16, 0x10, 0x18, 0x2, 0x1d, 0x18, 0x13, 0x11, 0x3, 0x7,  };
static const uint16 kOwStarPipeWarp_DstX_04849D[27] = { 0x4a8, 0x438, 0x908, 0x928, 0x9c8, 0x948, 0xd28, 0x118, 0xa8, 0x98, 0xb8, 0x128, 0xa8, 0x78, 0xd28, 0x408, 0xd78, 0x108, 0xdc8, 0x148, 0xdc8, 0x948, 0xb18, 0xd78, 0x268, 0xdc8, 0xd28,  };
static const uint16 kOwStarPipeWarp_DstY_0484D3[27] = { 0x148, 0xb8, 0x38, 0x18, 0x98, 0x98, 0x1d8, 0x78, 0x38, 0x108, 0xe8, 0x178, 0x188, 0x128, 0x188, 0xe8, 0x168, 0xf8, 0x188, 0x108, 0x1d8, 0x38, 0x138, 0x188, 0x78, 0x1d8, 0x1d8,  };

static const uint16 kOwLevelsForcedMusicChange_048D74[11] = { 0xb, 0x13, 0x1a, 0x1b, 0x1f, 0x20, 0x31, 0x32, 0x34, 0x35, 0x40,  };
static const uint8 kOwSubmapMusic_048D8A[7] = { 0x2, 0x3, 0x4, 0x6, 0x7, 0x9, 0x5,  };

static const uint16 kOw_KoopaKidTeleportXYPos_048E49[6] = { 0x128, 0x0, 0x188, 0x1c8, 0x0, 0x1d8,  };
static const uint8 kOwTriggerSaveTiles_048F7F[8] = { 0x58, 0x59, 0x5d, 0x63, 0x77, 0x79, 0x7e, 0x80,  };
static const uint16 kOwNoAutoMoveLevels_04906C[6] = { 0x28, 0x8, 0x14, 0x36, 0x3f, 0x45,  };

static const uint8 kOwHardcodedPathLevel_049078[10] = { 0x9, 0x15, 0x23, 0x1b, 0x43, 0x44, 0x24, 0xff, 0x30, 0x31,  };
static const uint16 kOwHardcodedPathChocolateIsland2_049082[2] = { 0x178, 0x128, };
static const uint8 kOwHardcodedPathTiles_049086[68] = { 0x10, 0x10, 0x1e, 0x19, 0x16, 0x66, 0x16, 0x19, 0x1e, 0x10, 0x10, 0x66, 0x4, 0x4, 0x4, 0x58, 0x4, 0x4, 0x4, 0x66, 0x4, 0x4, 0x4, 0x4, 0x4, 0x6a, 0x4, 0x4, 0x4, 0x4, 0x4, 0x66, 0x1e, 0x19, 0x6, 0x9, 0xf, 0x20, 0x1a, 0x21, 0x1a, 0x14, 0x19, 0x18, 0x1f, 0x17, 0x82, 0x17, 0x1f, 0x18, 0x19, 0x14, 0x1a, 0x21, 0x1a, 0x20, 0xf, 0x9, 0x6, 0x19, 0x1e, 0x66, 0x4, 0x4, 0x58, 0x4, 0x4, 0x5f,  };
static const uint8 kOwHardcodedPathDirs_0490CA[68] = { 0x2, 0x2, 0x2, 0x2, 0x6, 0x6, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x2, 0x2, 0x6, 0x6, 0x0, 0x0, 0x0, 0x4, 0x0, 0x4, 0x4, 0x0, 0x4, 0x0, 0x4, 0x6, 0x2, 0x6, 0x2, 0x6, 0x6, 0x2, 0x6, 0x2, 0x2, 0x2, 0x4, 0x4, 0x0, 0x0, 0x6, 0x6, 0x6, 0x4, 0x4, 0x4,  };
static const uint8 kOwHardcodedPathStartIndex_04910E[10] = { 0x0, 0x6, 0xc, 0x10, 0x14, 0x1a, 0x20, 0x2f, 0x3e, 0x41,  };

static const uint16 kOwExitLevelTiles_049426[5] = { 0x4344, 0x4645, 0x4847, 0x4025, 0x4d42,  };
static const uint16 kUpdateLevelName_DATA_049C91[31] = { 0x1cb, 0x0, 0x8, 0xd, 0x17, 0x23, 0x2e, 0x3a, 0x43, 0x4e, 0x59, 0x5f, 0x65, 0x75, 0x7d, 0x83, 0x87, 0x8c, 0x9a, 0xa8, 0xb2, 0xc2, 0xc9, 0xd3, 0xe5, 0xf7, 0xfe, 0x108, 0x113, 0x11a, 0x122,  };
static const uint16 kUpdateLevelName_DATA_049CCF[15] = { 0x1cb, 0x12b, 0x131, 0x138, 0x146, 0x14d, 0x154, 0x160, 0x167, 0x16c, 0x175, 0x180, 0x18a, 0x18f, 0x195,  };
static const uint16 kUpdateLevelName_DATA_049CED[13] = { 0x1cb, 0x19d, 0x19e, 0x19f, 0x1a0, 0x1a1, 0x1a2, 0x1a8, 0x1ac, 0x1b2, 0x1b7, 0x1c1, 0x1c6,  };

static const OwExits kOwExitSource_049964[] = {
  {0x0140, 0x0028, 0},
  {0x0150, 0x0058, 0},
  {0x0010, 0x0048, 1},
  {0x0010, 0x0098, 1},
  {0x00a0, 0x00d8, 0},
  {0x0140, 0x0058, 2},
  {0x0090, 0x01e8, 4},
  {0x0160, 0x00e8, 0},
  {0x00a0, 0x01c8, 0},
  {0x0160, 0x0088, 3},
  {0x0108, 0x0190, 0},
  {0x01e8, 0x0010, 3},
  {0x0110, 0x01c8, 0},
  {0x01f0, 0x0088, 3},
};

static const OwExits kOwExitDest_0499AA[] = {
  {0x0000, 0x0048, 1},
  {0x0000, 0x0098, 1},
  {0x0150, 0x0028, 0},
  {0x0160, 0x0058, 0},
  {0x0150, 0x0058, 2},
  {0x0090, 0x00d8, 0},
  {0x0150, 0x00e8, 0},
  {0x00a0, 0x01e8, 4},
  {0x0150, 0x0088, 3},
  {0x00b0, 0x01c8, 0},
  {0x01e8, 0x0000, 3},
  {0x0108, 0x01a0, 0},
  {0x0200, 0x0088, 3},
  {0x0100, 0x01c8, 0},
};

static const uint8 kOwExitExtra_0499F0[28] = { 0x0, 0x4, 0x0, 0x9, 0x14, 0x2, 0x15, 0x5, 0x14, 0x5, 0x9, 0xd, 0x15, 0xe, 0x9, 0x1e, 0x15, 0x8, 0xa, 0x1c, 0x1e, 0x0, 0x10, 0x19, 0x1f, 0x8, 0x10, 0x1c,  };
static const uint16 kOwExitLayerPosition_049A0C[12] = { 0xffef, 0xffd8, 0xffef, 0x80, 0xffef, 0x128, 0xf0, 0xffd8, 0xf0, 0x80, 0xf0, 0x128,  };

static const uint8 kOwUnknownTableA_From_04A03C[24] = { 0x7, 0x9, 0xa, 0xd, 0xe, 0x11, 0x17, 0x19, 0x1a, 0x1c, 0x1d, 0x1f, 0x28, 0x29, 0x2d, 0x2e, 0x35, 0x36, 0x37, 0x49, 0x4a, 0x4b, 0x4d, 0x51,  };
static const uint16 kOwUnknownTableA_Alpha_04A054[24] = { 0xfc08, 0x8fc, 0x8fc, 0x8fc, 0x8fc, 0x4, 0x408, 0x804, 0x804, 0x4, 0x804, 0x4, 0x8fc, 0x0, 0x8fc, 0x8fc, 0x4, 0x4, 0x0, 0xfc08, 0x408, 0x408, 0x8fc, 0xfc08,  };
static const uint16 kOwUnknownTableA_XY_04A084[48] = { 0x4, 0xfff8, 0x8, 0xfffc, 0xfff8, 0x4, 0xfff8, 0x4, 0x8, 0xfffc, 0x4, 0x4, 0x4, 0x8, 0x8, 0x4, 0xfff8, 0xfffc, 0x0, 0x0, 0x8, 0x4, 0x4, 0x4, 0xfff8, 0x4, 0x4, 0x4, 0x8, 0xfffc, 0xfff8, 0x4, 0x4, 0x4, 0x0, 0x0, 0x4, 0x4, 0x4, 0xfff8, 0x4, 0x8, 0xfffc, 0xfff8, 0xfff8, 0x4, 0xfffc, 0x8,  };
static const uint8 kOwUnknownTableA_Direction_04A0E4[24] = { 0x2, 0x2, 0x2, 0x2, 0x2, 0x0, 0x2, 0x2, 0x2, 0x0, 0x2, 0x0, 0x2, 0x0, 0x2, 0x2, 0x0, 0x0, 0x0, 0x2, 0x2, 0x2, 0x2, 0x2,  };
static const uint8 kOwDirectionAfterBeatingLevel_04D678[113] = { 0x0, 0xc0, 0xc0, 0xc0, 0x30, 0xc0, 0xc0, 0x0, 0xc0, 0x20, 0x30, 0xc0, 0xc0, 0xc0, 0xc0, 0xd0, 0x40, 0x40, 0x40, 0xd0, 0x40, 0x80, 0x80, 0x0, 0x0, 0x0, 0x0, 0x40, 0x0, 0x80, 0x20, 0x80, 0x40, 0x40, 0x80, 0x60, 0x90, 0x0, 0x0, 0xc0, 0x0, 0x0, 0x0, 0xc0, 0x40, 0x20, 0x40, 0xc0, 0xe0, 0xc0, 0x0, 0xc0, 0x0, 0x0, 0xc0, 0x20, 0x80, 0x80, 0x80, 0x80, 0x30, 0x40, 0xe0, 0x0, 0x40, 0xe0, 0xe0, 0xd0, 0x70, 0xff, 0x40, 0x90, 0x55, 0x80, 0x80, 0x80, 0x80, 0x0, 0xc0, 0xc0, 0xc0, 0xc0, 0x40, 0x0, 0x80, 0xa0, 0x30, 0xaa, 0x60, 0xd0, 0x80, 0x0, 0x55, 0x55, 0x0, 0x0, 0xaa, 0x55, 0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  };

static const uint8 kOwSubmapTileset_04DC02[7] = { 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,  };
static const uint16 kLayer2EventData_Ptrs_04E359[121] = { 0x0, 0x0, 0xd, 0xd, 0x10, 0x15, 0x18, 0x1a, 0x20, 0x23, 0x26, 0x29, 0x2c, 0x35, 0x39, 0x3a, 0x42, 0x46, 0x4a, 0x4c, 0x4d, 0x4e, 0x52, 0x59, 0x5d, 0x60, 0x67, 0x6a, 0x6c, 0x6f, 0x72, 0x75, 0x77, 0x77, 0x83, 0x83, 0x84, 0x8e, 0x90, 0x92, 0x98, 0x98, 0x98, 0xa0, 0xa5, 0xac, 0xb2, 0xbd, 0xc2, 0xc5, 0xcc, 0xd3, 0xd7, 0xe1, 0xe2, 0xe2, 0xe2, 0xe5, 0xe7, 0xe8, 0xed, 0xee, 0xf1, 0xf5, 0xfa, 0xfd, 0x100, 0x100, 0x100, 0x100, 0x100, 0x102, 0x108, 0x10f, 0x112, 0x114, 0x116, 0x117, 0x11e, 0x12b, 0x12b, 0x12b, 0x12b, 0x12f, 0x12f, 0x12f, 0x133, 0x133, 0x133, 0x137, 0x137, 0x137, 0x140, 0x140, 0x146, 0x146, 0x146, 0x147, 0x152, 0x156, 0x15c, 0x15c, 0x15f, 0x162, 0x165, 0x168, 0x16b, 0x16e, 0x171, 0x173, 0x173, 0x173, 0x173, 0x173, 0x173, 0x173, 0x173, 0x173, 0x173, 0x173, 0x173,  };

static const uint8 kOwDestruction_TileToIdx_04E5A7[5] = { 0x77, 0x79, 0x58, 0x4c, 0xa6,  };
static const uint8 kOwDestruction_TopTile_04E5AC[5] = { 0x85, 0x86, 0x0, 0x10, 0x0,  };
static const uint8 kOwDestruction_BottomTile_04E5B1[5] = { 0x85, 0x86, 0x81, 0x81, 0x81,  };
static const uint8 kOwDestruction_TriggerEvent_04E5D6[16] = { 0x6, 0xf, 0x1c, 0x21, 0x24, 0x28, 0x29, 0x37, 0x40, 0x41, 0x43, 0x4a, 0x4d, 0x2, 0x61, 0x35,  };

#endif

/////////////////////////////////////////////
// Not important for the assets file

static const uint8 kOverworldEventProcess01_DestroyTileAnimation_DATA_04ECD3[176] = { 134, 153, 134, 25, 134, 217, 134, 89, 150, 153, 150, 25, 150, 217, 150, 89, 134, 157, 134, 29, 134, 221, 134, 93, 150, 157, 150, 29, 150, 221, 150, 93, 134, 153, 134, 25, 134, 217, 134, 89, 150, 153, 150, 25, 150, 217, 150, 89, 134, 157, 134, 29, 134, 221, 134, 93, 150, 157, 150, 29, 150, 221, 150, 93, 136, 21, 152, 21, 137, 21, 153, 21, 164, 17, 180, 17, 165, 17, 181, 17, 34, 17, 144, 17, 34, 17, 145, 17, 194, 17, 210, 17, 195, 17, 211, 17, 166, 17, 182, 17, 167, 17, 183, 17, 130, 25, 146, 25, 131, 25, 147, 25, 200, 25, 248, 25, 201, 25, 249, 25, 128, 28, 144, 28, 129, 28, 144, 92, 128, 20, 144, 20, 129, 20, 144, 84, 162, 17, 178, 17, 163, 17, 179, 17, 130, 29, 146, 29, 131, 29, 147, 29, 134, 153, 134, 25, 134, 217, 134, 89, 134, 153, 134, 25, 134, 217, 134, 89, 168, 17, 184, 17, 169, 17, 185, 17,  };

static const uint16 kOverworldProcess04_PlayerIsMoving_DATA_049430[15] = { 0xc, 0xe, 0x610, 0x12, 0x418, 0x21a, 0x620, 0x642, 0x44e, 0x250, 0x658, 0x5a, 0x670, 0x90, 0x6a0,  };
static const uint8 kOverworldProcess04_PlayerIsMoving_DATA_04944E[15] = { 0x1, 0x1, 0x0, 0x1, 0x1, 0x0, 0x0, 0x0, 0x1, 0x0, 0x0, 0x1, 0x0, 0x1, 0x0,  };
static const uint16 kOw_MaxRangeForScrollWalking_049416[4] = { 0xffef, 0xffd7, 0x111, 0x131, };

static const uint16 kOwTileDistanceMovedAcross_049EA7[81] = { 0xf810, 0x10, 0xfc10, 0x10, 0xfc10, 0x10, 0xfc08, 0xf40c, 0x4fc, 0xfc04, 0x10f8, 0x1000, 0x8fc, 0x8fc, 0x10fc, 0x1000, 0x4f8, 0x10fc, 0x1000, 0x810, 0x410, 0x410, 0x408, 0xc0c, 0x404, 0x404, 0x1008, 0xf8fc, 0xf8fc, 0x1004, 0xfcf8, 0x1004, 0xf4f4, 0xf40c, 0x10, 0x1000, 0x1000, 0x10, 0x10, 0x8fc, 0x8fc, 0x1000, 0xfc10, 0xfc10, 0x4fc, 0xfc04, 0x10f8, 0x1000, 0x10fc, 0x410, 0x10, 0x1004, 0x404, 0xf8fc, 0x404, 0x810, 0xf40c, 0x1000, 0x10fc, 0x10, 0x1004, 0xf810, 0x1000, 0x1000, 0x10fc, 0x10, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0x1000, 0xfc04, 0x404, 0x404, 0x1000, 0x1000, 0x10, 0x10, 0x10fc, 0x4fc,  };
static const uint16 kOwTilePathDirection_049F49[81] = { 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x100, 0x100, 0x100, 0x100, 0x1, 0x1, 0x100, 0x1, 0x1, 0x1, 0x100, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x100, 0x100, 0x1, 0x100, 0x1, 0x100, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x100, 0x1, 0x1, 0x1, 0x1, 0x100, 0x100, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x100, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x100, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x100,  };
static const uint8 kOwTilePose_049FEB[81] = { 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x4, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x0, 0x4, 0x0, 0x0, 0x4, 0x4, 0x8, 0x8, 0x8, 0xc, 0xc, 0x8, 0x8, 0x8, 0x8, 0x8, 0xc, 0xc, 0x8, 0x8, 0x8, 0x8, 0xc, 0x8, 0x8, 0x8, 0xc, 0x8, 0xc, 0x14, 0x14, 0x14, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x8, 0 };

static const uint8 kOwStarWarpAnimationOffset[4] = { 0x20, 0x60, 0x0, 0x40,  };
static const uint16 kOwSpriteTilemap[192] = { 0x240e, 0x240f, 0x241e, 0x241f, 0x2420, 0x2421, 0x2430, 0x2431, 0x240e, 0x240f, 0x241e, 0x241f, 0x2420, 0x2421, 0x6431, 0x6430, 0x240a, 0x240b, 0x241a, 0x241b, 0x240c, 0x240d, 0x241c, 0x241d, 0x240a, 0x240b, 0x241a, 0x241b, 0x240c, 0x240d, 0x641d, 0x641c, 0x2408, 0x2409, 0x2418, 0x2419, 0x2406, 0x2407, 0x2416, 0x2417, 0x2408, 0x2409, 0x2418, 0x2419, 0x2406, 0x2407, 0x2416, 0x2417, 0x6409, 0x6408, 0x6419, 0x6418, 0x6407, 0x6406, 0x6417, 0x6416, 0x6409, 0x6408, 0x6419, 0x6418, 0x6407, 0x6406, 0x6417, 0x6416, 0x240e, 0x240f, 0x2438, 0x6438, 0x2420, 0x2421, 0x2439, 0x6439, 0x240e, 0x240f, 0x2438, 0x6438, 0x2420, 0x2421, 0x2439, 0x6439, 0x240a, 0x240b, 0x2438, 0x6438, 0x240c, 0x240d, 0x2439, 0x6439, 0x240a, 0x240b, 0x2438, 0x6438, 0x240c, 0x240d, 0x2439, 0x6439, 0x2408, 0x2409, 0x2438, 0x6438, 0x2406, 0x2407, 0x2439, 0x6439, 0x2408, 0x2409, 0x2438, 0x6438, 0x2406, 0x2407, 0x2439, 0x6439, 0x6409, 0x6408, 0x2438, 0x6438, 0x6407, 0x6406, 0x2439, 0x6439, 0x6409, 0x6408, 0x2438, 0x6438, 0x6407, 0x6406, 0x2439, 0x6439, 0x2424, 0x2425, 0x2434, 0x2435, 0x2424, 0x2425, 0x2434, 0x2435, 0x2424, 0x2425, 0x2434, 0x2435, 0x2424, 0x2425, 0x2434, 0x2435, 0x2424, 0x2425, 0x2438, 0x6438, 0x2424, 0x2425, 0x2438, 0x6438, 0x2424, 0x2425, 0x2438, 0x6438, 0x2424, 0x2425, 0x2438, 0x6438, 0x2446, 0x2447, 0x2456, 0x2457, 0x6447, 0x6446, 0x6457, 0x6456, 0x2446, 0x2447, 0x2456, 0x2457, 0x6447, 0x6446, 0x6457, 0x6456, 0x2446, 0x2447, 0x2456, 0x2457, 0x6447, 0x6446, 0x6457, 0x6456, 0x2446, 0x2447, 0x2456, 0x2457, 0x6447, 0x6446, 0x6457, 0x6456,  };
static const uint8 kOwSpriteTilemapYoshi[384] = { 0x66, 0x24, 0x67, 0x24, 0x76, 0x24, 0x77, 0x24, 0x2f, 0x62, 0x2e, 0x62, 0x3f, 0x62, 0x3e, 0x62, 0x66, 0x24, 0x67, 0x24, 0x76, 0x24, 0x77, 0x24, 0x2e, 0x22, 0x2f, 0x22, 0x3e, 0x22, 0x3f, 0x22, 0x2f, 0x62, 0x2e, 0x62, 0x3f, 0x62, 0x3e, 0x62, 0xa, 0x24, 0xb, 0x24, 0x1a, 0x24, 0x1b, 0x24, 0x2e, 0x22, 0x2f, 0x22, 0x3e, 0x22, 0x3f, 0x22, 0xa, 0x24, 0xb, 0x24, 0x1a, 0x24, 0x1b, 0x24, 0x64, 0x24, 0x65, 0x24, 0x74, 0x24, 0x75, 0x24, 0x40, 0x22, 0x41, 0x22, 0x50, 0x22, 0x51, 0x22, 0x64, 0x24, 0x65, 0x24, 0x74, 0x24, 0x75, 0x24, 0x42, 0x22, 0x43, 0x24, 0x52, 0x24, 0x53, 0x24, 0x65, 0x64, 0x64, 0x64, 0x75, 0x64, 0x74, 0x64, 0x41, 0x62, 0x40, 0x62, 0x51, 0x62, 0x50, 0x62, 0x65, 0x64, 0x64, 0x64, 0x75, 0x64, 0x74, 0x64, 0x43, 0x62, 0x42, 0x62, 0x53, 0x62, 0x52, 0x62, 0x38, 0x24, 0x38, 0x64, 0x66, 0x24, 0x67, 0x24, 0x76, 0x24, 0x77, 0x24, 0xff, 0xff, 0xff, 0xff, 0x39, 0x24, 0x39, 0x64, 0x66, 0x24, 0x67, 0x24, 0x76, 0x24, 0x77, 0x24, 0xff, 0xff, 0xff, 0xff, 0x38, 0x24, 0x38, 0x64, 0x2f, 0x62, 0x2e, 0x62, 0xa, 0x24, 0xb, 0x24, 0x1a, 0x24, 0x1b, 0x24, 0x39, 0x24, 0x39, 0x24, 0x2e, 0x22, 0x2f, 0x22, 0xa, 0x24, 0xb, 0x24, 0x1a, 0x24, 0x1b, 0x24, 0x38, 0x24, 0x38, 0x64, 0x64, 0x24, 0x65, 0x24, 0x74, 0x24, 0x75, 0x24, 0x40, 0x22, 0x41, 0x22, 0x39, 0x24, 0x39, 0x64, 0x64, 0x24, 0x65, 0x24, 0x74, 0x24, 0x75, 0x24, 0x42, 0x22, 0x42, 0x22, 0x38, 0x24, 0x38, 0x64, 0x65, 0x64, 0x64, 0x64, 0x75, 0x64, 0x74, 0x64, 0x41, 0x62, 0x40, 0x62, 0x39, 0x24, 0x39, 0x64, 0x65, 0x64, 0x64, 0x64, 0x75, 0x64, 0x74, 0x64, 0x43, 0x62, 0x42, 0x62, 0x2f, 0x62, 0x2e, 0x62, 0x3f, 0x62, 0x3e, 0x62, 0x24, 0x24, 0x25, 0x24, 0x34, 0x24, 0x35, 0x24, 0x2e, 0x22, 0x2f, 0x22, 0x3e, 0x22, 0x3f, 0x22, 0x24, 0x24, 0x25, 0x24, 0x34, 0x24, 0x35, 0x24, 0x38, 0x24, 0x38, 0x64, 0x2f, 0x62, 0x2e, 0x62, 0x24, 0x24, 0x25, 0x24, 0x34, 0x24, 0x35, 0x24, 0x39, 0x24, 0x39, 0x64, 0x2e, 0x22, 0x2f, 0x22, 0x24, 0x24, 0x25, 0x24, 0x34, 0x24, 0x35, 0x24, 0x66, 0x24, 0x67, 0x24, 0x76, 0x24, 0x77, 0x24, 0x2f, 0x62, 0x2e, 0x62, 0x3f, 0x62, 0x3e, 0x62, 0x66, 0x24, 0x67, 0x24, 0x76, 0x24, 0x77, 0x24, 0x2e, 0x22, 0x2f, 0x22, 0x3e, 0x22, 0x3f, 0x22, 0x66, 0x24, 0x67, 0x24, 0x76, 0x24, 0x77, 0x24, 0x2f, 0x62, 0x2e, 0x62, 0x3f, 0x62, 0x3e, 0x62, 0x66, 0x24, 0x67, 0x24, 0x76, 0x24, 0x77, 0x24, 0x2e, 0x22, 0x2f, 0x22, 0x3e, 0x22, 0x3f, 0x22,  };
static const uint8 kOwPlayerAndYoshiXDisp[192] = { 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x7, 0xf, 0x7, 0xf, 0x0, 0x8, 0x0, 0x8, 0x7, 0xf, 0x7, 0xf, 0x0, 0x8, 0x0, 0x8, 0xf9, 0x1, 0xf9, 0x1, 0x0, 0x8, 0x0, 0x8, 0xf9, 0x1, 0xf9, 0x1, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x7, 0xf, 0x7, 0xf, 0x0, 0x8, 0x0, 0x8, 0x7, 0xf, 0x7, 0xf, 0x0, 0x8, 0x0, 0x8, 0xf9, 0x1, 0xf9, 0x1, 0x0, 0x8, 0x0, 0x8, 0xf9, 0x1, 0xf9, 0x1, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8, 0x0, 0x8,  };
static const uint8 kOwPlayerAndYoshiYDisp[192] = { 0xfb, 0xfb, 0x3, 0x3, 0x0, 0x0, 0x8, 0x8, 0xfa, 0xfa, 0x2, 0x2, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0x8, 0x8, 0xf8, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0xf9, 0xf9, 0x1, 0x1, 0xfc, 0xfc, 0x4, 0x4, 0x0, 0x0, 0x8, 0x8, 0xfb, 0xfb, 0x3, 0x3, 0x0, 0x0, 0x8, 0x8, 0xfc, 0xfc, 0x4, 0x4, 0x0, 0x0, 0x8, 0x8, 0xfb, 0xfb, 0x3, 0x3, 0x0, 0x0, 0x8, 0x8, 0x8, 0x8, 0xfb, 0xfb, 0x3, 0x3, 0x0, 0x0, 0x8, 0x8, 0xfa, 0xfa, 0x2, 0x2, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0xf8, 0xf8, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0xf9, 0xf9, 0x1, 0x1, 0x8, 0x8, 0xfc, 0xfc, 0x4, 0x4, 0x0, 0x0, 0x8, 0x8, 0xfb, 0xfb, 0x3, 0x3, 0x0, 0x0, 0x8, 0x8, 0xfc, 0xfc, 0x4, 0x4, 0x0, 0x0, 0x8, 0x8, 0xfb, 0xfb, 0x3, 0x3, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0xf8, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0xf8, 0xf8, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0xf8, 0xf8, 0x0, 0x0, 0x8, 0x8, 0x0, 0x0, 0xf8, 0xf8, 0x0, 0x0, 0xfb, 0xfb, 0x3, 0x3, 0x0, 0x0, 0x8, 0x8, 0xfa, 0xfa, 0x2, 0x2, 0x0, 0x0, 0x8, 0x8, 0xfb, 0xfb, 0x3, 0x3, 0x0, 0x0, 0x8, 0x8, 0xfa, 0xfa, 0x2, 0x2, 0x0, 0x0, 0x8, 0x8,  };
static const uint16 kOwYoshiPalette[4] = { 0x0, 0x200, 0x400, 0x600,  };

static const uint8 kOverworldProcess04_PlayerIsMoving_OWPlayerPathSpeedOffset[2] = { 0xd, 0x8,  };

static const uint16 kOwOffsetsFreeScrolling_048211[8] = { 0x0, 0x2, 0xfffe, 0x2, 0x0, 0x2, 0xfffe, 0x2,  };
static const uint16 kOwOffsetsFreeScrollMax_048221[8] = { 0x0, 0x111, 0xffef, 0x111, 0x0, 0x132, 0xffd7, 0x132,  };

static const uint8 kOwEarthquakeFrameMask_048231[16] = { 0xf, 0xf, 0x7, 0x7, 0x7, 0x3, 0x3, 0x3, 0x1, 0x1, 0x3, 0x3, 0x3, 0x7, 0x7, 0x7,  };
static const uint8 kOwDestroyTileAnimation_X_04EB56[44] = { 0xf5, 0x11, 0xf2, 0x15, 0xf5, 0x11, 0xf3, 0x14, 0xf5, 0x11, 0xf3, 0x14, 0xf6, 0x10, 0xf4, 0x13, 0xf7, 0xf, 0xf5, 0x12, 0xf8, 0xe, 0xf7, 0x11, 0xfa, 0xd, 0xf9, 0x10, 0xfc, 0xc, 0xfb, 0xd, 0xff, 0xa, 0xfe, 0xb, 0x1, 0x7, 0x1, 0x7, 0x0, 0x8, 0x0, 0x8,  };
static const uint8 kOwDestroyTileAnimation_Y_04EB82[44] = { 0xf8, 0xf8, 0x11, 0x12, 0xf8, 0xf8, 0x10, 0x11, 0xf8, 0xf8, 0x10, 0x11, 0xf9, 0xf9, 0xf, 0x10, 0xfa, 0xfa, 0xe, 0xf, 0xfb, 0xfb, 0xc, 0xd, 0xfc, 0xfc, 0xb, 0xb, 0xfe, 0xfe, 0xa, 0xa, 0x0, 0x0, 0x8, 0x8, 0x1, 0x1, 0x7, 0x7, 0x0, 0x0, 0x8, 0x8,  };
static const uint8 kOwDestroyTileAnimation_Flags_04EBAE[44] = { 0xf6, 0xb6, 0x76, 0x36, 0xf6, 0xb6, 0x76, 0x36, 0x36, 0x76, 0xb6, 0xf6, 0x36, 0x76, 0xb6, 0xf6, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x36, 0x30, 0x70, 0xb0, 0xf0,  };
static const uint8 kOwDestroyTileAnimation_Char_04EBDA[7] = { 0x22, 0x23, 0x32, 0x33, 0x32, 0x23, 0x22,  };
static const uint8 kOwDestroyTileAnimation_Char2_04EBE1[10] = { 0x73, 0x73, 0x72, 0x72, 0x5f, 0x5f, 0x28, 0x28, 0x28, 0x28,  };

static const uint8 kDrawFlyingSwitchBlocks_XSpeed[8] = { 0x0, 0xd8, 0x28, 0xd0, 0x30, 0xd8, 0x28, 0x0,  };
static const uint8 kDrawFlyingSwitchBlocks_YSpeed[8] = { 0xd0, 0xd8, 0xd8, 0x0, 0x0, 0x28, 0x28, 0x30,  };
static const uint8 kOwPrompt02_ExpandPromptWindow_DATA_04F411[2] = { 0x4, 0xfc,  };
static const uint8 kOwPrompt02_ExpandPromptWindow_DATA_04F413[2] = { 0x68, 0x0,  };
static const uint8 kOwLifeExchangeTextTiles[81] = { 82, 73, 0, 9, 22, 40, 10, 40, 27, 40, 18, 40, 24, 40, 82, 82, 0, 9, 21, 40, 30, 40, 18, 40, 16, 40, 18, 40, 82, 11, 0, 5, 38, 40, 0, 40, 0, 40, 82, 20, 0, 5, 38, 40, 0, 40, 0, 40, 82, 15, 0, 3, 252, 56, 252, 56, 82, 47, 0, 3, 252, 56, 252, 56, 81, 201, 0, 3, 133, 41, 133, 105, 81, 210, 0, 3, 133, 41, 133, 105, 255,  };
static const uint16 kOwPrompt03_OverworldLifeExchanger_DATA_04F503[2] = { 0x387d, 0x787e,  };
static const uint16 kOwPrompt03_OverworldLifeExchanger_DATA_04F507[2] = { 0x387e, 0x787d,  };
static const uint16 kOwPrompt03_OverworldLifeExchanger_DATA_04F50B[2] = { 0xb87d, 0xf87e,  };
static const uint16 kOwPrompt03_OverworldLifeExchanger_DATA_04F50F[2] = { 0xb87e, 0xf87d,  };

static const uint8 kLoadOverworldSprites_UNK_04F672[3] = { 0x1, 0x40, 0x80,  };
static const uint8 kOverworldLightningAndRandomCloudSpawning_DATA_04F6D0[8] = { 0x70, 0x7f, 0x78, 0x7f, 0x70, 0x7f, 0x78, 0x7f,  };
static const uint16 kOverworldLightningAndRandomCloudSpawning_DATA_04F6D8[8] = { 0xfff0, 0x20, 0xc0, 0xfff0, 0xfff0, 0x80, 0xfff0, 0x0,  };
static const uint16 kOverworldLightningAndRandomCloudSpawning_DATA_04F6E8[8] = { 0x70, 0x160, 0x158, 0xb0, 0x160, 0x160, 0x70, 0x160,  };
const uint8 kOverworldLightningAndRandomCloudSpawning_DATA_04F6F8[8] = { 0x20, 0x58, 0x43, 0xcf, 0x18, 0x34, 0xa2, 0x5e,  };
const uint8 kOverworldLightningAndRandomCloudSpawning_DATA_04F700[8] = { 0x7, 0x5, 0x6, 0x7, 0x4, 0x6, 0x7, 0x5,  };
static const uint8 kCheckIfXIsAllowedOnYSubmap_DisableSpriteOnXSubmapFlags[10] = { 0x7f, 0x21, 0x7f, 0x7f, 0x7f, 0x77, 0x3f, 0xf7, 0xf7, 0x0,  };
static const uint8 kSetOverworldSpriteFrameIndex_DATA_04F833[16] = { 0x0, 0x52, 0x31, 0x19, 0x45, 0x2a, 0x3, 0x8b, 0x94, 0x3c, 0x78, 0xd, 0x36, 0x5e, 0x87, 0x1f,  };

static const uint8 kOverworldSpriteOAMIndexes[16] = { 0xf4, 0xf4, 0xf4, 0xf4, 0xf4, 0x9c, 0x3c, 0x48, 0xc8, 0xcc, 0xa0, 0xa4, 0xd8, 0xdc, 0xe0, 0xe4,  };
static const uint8 kCheckIfXIsAllowedOnYSubmap_ANDTable[7] = { 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2,  };
static const uint8 kOWSpr01_Lakitu_DATA_04F8A6[8] = { 0x1, 0x1, 0x3, 0x1, 0x1, 0x1, 0x1, 0x2,  };
static const uint8 kOWSpr01_Lakitu_DATA_04F8AE[8] = { 0xc, 0xc, 0x12, 0x12, 0x12, 0x12, 0xc, 0xc,  };
static const uint8 kOWSpr01_Lakitu_DATA_04F8B6[8] = { 0x10, 0x0, 0x8, 0x0, 0x20, 0x0, 0x20, 0x0,  };
static const uint8 kOWSpr01_Lakitu_DATA_04F8BE[8] = { 0x10, 0x0, 0x30, 0x0, 0x8, 0x0, 0x10, 0x0,  };
static const uint8 kOWSpr01_Lakitu_Acceleration[2] = { 0x1, 0xff,  };
static const uint8 kOWSpr01_Lakitu_XYSpeedCap[2] = { 0x10, 0xf0,  };
static const uint8 kOWSpr01_Lakitu_ZSpeedCap[2] = { 0x10, 0xf0,  };
static const uint8 kOWSpr02_BlueBird_DATA_04F9A8[4] = { 0x4e, 0x4f, 0x5e, 0x4f,  };
static const uint8 kOWSpr02_BlueBird_DATA_04F9AC[4] = { 0x8, 0x7, 0x4, 0x7,  };
static const uint8 kOWSpr02_BlueBird_DATA_04F9B0[4] = { 0x0, 0x1, 0x4, 0x1,  };
static const uint8 kOWSpr02_BlueBird_DATA_04F9B4[4] = { 0x1, 0x7, 0x9, 0x7,  };
static const uint8 kOWSpr06_KoopaKid_DATA_04FB85[3] = { 0x80, 0x40, 0x20,  };
static const uint8 kOWSpr06_KoopaKid_InitialXLo[3] = { 0x30, 0x10, 0xc0,  };
static const uint8 kOWSpr06_KoopaKid_InitialXHi[3] = { 0x1, 0x1, 0x1,  };
static const uint8 kOWSpr06_KoopaKid_InitialYLo[3] = { 0x7f, 0x7f, 0x8f,  };
static const uint8 kOWSpr06_KoopaKid_InitialYHi[3] = { 0x1, 0x0, 0x1,  };
static const uint8 kOWSpr06_KoopaKid_byte_4FB94[2] = { 0x8, 0x2,  };
static const uint8 kOWSpr06_KoopaKid_byte_4FB96[2] = { 0xf, 0x0,  };
static const uint8 kOWSpr07_Smoke_DATA_04FC26[16] = { 0x1, 0x2, 0x3, 0x4, 0x3, 0x2, 0x1, 0x0, 0x1, 0x2, 0x3, 0x4, 0x3, 0x2, 0x1, 0x0,  };
static const uint8 kOWSpr07_Smoke_DATA_04FC36[16] = { 0xff, 0xff, 0xfe, 0xfd, 0xfd, 0xfc, 0xfb, 0xfb, 0xfa, 0xf9, 0xf9, 0xf8, 0xf7, 0xf7, 0xf6, 0xf5,  };
static const uint8 kOWSpr09_Bowser_DATA_04FD0A[6] = { 0x7, 0x7, 0x3, 0x3, 0x5f, 0x5f,  };
static const uint8 kOWSpr09_Bowser_DATA_04FD10[10] = { 0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff, 0x1, 0xff,  };
static const uint8 kOWSpr09_Bowser_DATA_04FD1A[10] = { 0x18, 0xe8, 0xa, 0xf6, 0x8, 0xf8, 0x3, 0xfd,  0x1, 0xff,}; // todo: why 10
static const uint8 kOWSpr09_Bowser_DATA_04FD22[2] = { 0x1, 0xff,  };
static const uint8 kDrawOverworldSpriteShadow_LeftTileXDisp[16] = { 0x0, 0x0, 0x0, 0x0, 0x1, 0x2, 0x2, 0x2, 0x0, 0x0, 0x1, 0x1, 0x2, 0x2, 0x3, 0x3,  };
static const uint8 kDrawOverworldSpriteShadow_RightTileXDisp[16] = { 0x8, 0x8, 0x8, 0x8, 0x7, 0x6, 0x5, 0x5, 0x0, 0x0, 0xe, 0xe, 0xc, 0xc, 0xa, 0xa,  };

static const uint8 kSharedOverworldPathTables_DATA_049060[4] = { 0x5, 0x3, 0x1, 0x0,  };
static const uint16 kSharedOverworldPathTables_DATA_049064[4] = { 0x0, 0x2, 0x4, 0x6,  };
static const uint8 kBitTable_DATA_04E44B[8] = { 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,  };
static const uint16 kBitTable_Bank04[4] = { 0x8, 0x4, 0x2, 0x1,  };


void OwTileAnimations_ShiftWaterTiles() {  // 048086
  uint16 r3 = 0;
  uint16 r5 = 0;
  do {
    OwTileAnimations_0480B9(r5, g_ram + kOwTileAnimations_WaterTileNumbers[r3 >> 1]);
    r5 += 32;
    r3 += 2;
  } while (r3 != 6);
}

void OwTileAnimations_0480B9(uint16 k, const uint8 *p0) {  // 0480b9
  uint16 v1 = 0;
  uint16 r7 = 8;
  uint16 r9 = 8;
  if (HAS_LM_FEATURE(kLmFeature_OverworldTiles4bpp))
    r7 = 16, r9 = 0;
  do {
    *(uint16 *)&sprites_cutscene_sprite_table_0AF6[k] = WORD(p0[v1]);
    v1 += 2;
    k += 2;
  } while (--r7);
  for(; r9; r9--) {
    *(uint16 *)&sprites_cutscene_sprite_table_0AF6[k] = p0[v1++];
    k += 2;
  }
}

void OwTileAnimations() {  // 0480e0
  if ((counter_global_frames & 7) == 0) {
    for (uint8 i = 31; (i & 0x80) == 0; --i) {
      uint8 r0 = sprites_cutscene_sprite_table_0AF6[i];
      if ((i & 8) != 0) {
        bool v1 = r0 & 1;
        int8 v2 = 0;
        if (v1)
          v2 = 0x80;
        sprites_cutscene_sprite_table_0AF6[i] = (sprites_cutscene_sprite_table_0AF6[i] >> 1) + v2;
      } else {
        bool v1 = __CFSHL__(r0, 1);
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
  uint16 r13w = 96;
  uint16 r11w = 0;
  do {
    int16 v4 = 56;
    if (r11w < 0x20)
      v4 = 112;
    int16 v5 = (uint16)(counter_global_frames & v4) >> 2;
    if (v4 != 56)
      v5 = (uint16)(counter_global_frames & v4) >> 3;
    const uint8 *p0 = g_ram + kOwTileAnimations_TileNumbers[(uint16)(r11w + v5) >> 1];
    OwTileAnimations_0480B9(r13w, p0);
    r13w += 32;
    r11w += 16;
  } while (r11w != 128);
}

void OwTileAnimations_048172(uint8 k) {  // 048172
  int8 v1 = 0;
LABEL_2:;
  uint16 r0w = *(uint16 *)&sprites_cutscene_sprite_table_0AF6[(uint8)(k + 14)];
  do {
    uint16 r2w = *(uint16 *)&sprites_cutscene_sprite_table_0AF6[k];
    *(uint16 *)&sprites_cutscene_sprite_table_0AF6[k] = r0w;
    r0w = r2w;
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
      uint8 arr0[2];
      uint16 v1 = ow_scroll_camera_ypos - mirror_current_layer1_ypos;
      arr0[1] = ow_scroll_camera_ypos - mirror_current_layer1_ypos;
      if ((int16)(ow_scroll_camera_ypos - mirror_current_layer1_ypos) < 0)
        v1 = mirror_current_layer1_ypos - ow_scroll_camera_ypos;
      uint8 arr[2];
      arr[1] = v1 >> 1;
      uint16 v2 = ow_scroll_camera_xpos - mirror_current_layer1_xpos;
      arr0[0] = ow_scroll_camera_xpos - mirror_current_layer1_xpos;
      if ((int16)(ow_scroll_camera_xpos - mirror_current_layer1_xpos) < 0)
        v2 = mirror_current_layer1_xpos - ow_scroll_camera_xpos;
      v3 = v2 >> 1;
      arr[0] = v3;
      uint8 v4 = 1;
      if ((uint8)v3 < arr[1]) {
        v4 = 0;
        LOBYTE(v3) = arr[1];
      }
      if ((uint8)v3 >= 2) {
        v5 = SnesDivide(arr[v4] << 8, v3) >> 2;
        if ((arr0[v4] & 0x80) != 0)
          LOBYTE(v5) = -(int8)v5;
        arr0[v4] = v5;
        uint8 v6 = v4 ^ 1;
        uint8 v7 = 64;
        if ((arr0[v6] & 0x80) != 0)
          v7 = -64;
        arr0[v6] = v7;
        uint8 v8 = 1;
        do {
          uint16 t0 = *(&ow_layer1_sub_xpos + v8) + (uint8)(16 * arr0[v8]);
          *(&ow_layer1_sub_xpos + v8) = t0;
          uint16 t = *(&mirror_current_layer1_xpos + v8) + ((int8)arr0[v8] >> 4) + (t0 >> 8);
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
        if ((kOwEarthquakeFrameMask_048231[ow_active_earthquake_event >> 4] & counter_global_frames) == 0) {
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
  uint16 v3 = kOwOffsetsFreeScrolling_048211[v2] + *(uint16 *)((int8 *)&mirror_current_layer1_xpos + k);
  if (__CFSHL__uint16(kOwOffsetsFreeScrolling_048211[v2] ^ (v3 - kOwOffsetsFreeScrollMax_048221[v2]))) {
    *(uint16 *)((int8 *)&mirror_current_layer1_xpos + k) = v3;
    *(uint16 *)((int8 *)&mirror_current_layer2_xpos + k) = v3;
  }
}

bool HandleOverworldStarPipeWarp_GetIndex() {  // 048509
  uint16 result;
  uint16 r0w = ow_players_map[player_current_character] << 8;
  for (result = kOwStarPipeWarp_SrcX_048431_SIZE - 2; (int16)result >= 0; result -= 2) {
    int v1 = result >> 1;
    if ((uint16)(r0w ^ kOwStarPipeWarp_SrcX_048431[v1]) < 0x200) {
      PointU16 *pt = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
      if ((r0w ^ kOwStarPipeWarp_SrcX_048431[v1]) == pt->x && pt->y == kOwStarPipeWarp_SrcY_048467[v1]) {
        break;
      }
    }
  }
  if (g_lunar_magic) {
    if ((int16)result >= 0)
      ow_star_pipe_index = result >> 1;
  } else {
    ow_star_pipe_index = result;
  }
  return (int16)result >= 0;
}

void HandleOverworldStarPipeWarp_SetPlayerDestination() {  // 04853b
  uint8 v0 = player_current_characterx4;
  int v1 = g_lunar_magic ? ow_star_pipe_index : (ow_star_pipe_index >> 1);
  uint16 v5 = kOwStarPipeWarp_DstX_04849D[v1];
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  pt->x = v5 & 0x1FF;
  PointU16 *v3 = get_PointU16(ow_players_grid_aligned_pos, v0);
  v3->x = (uint16)(v5 & 0x1FF) >> 4;
  uint16 v4 = kOwStarPipeWarp_DstY_0484D3[v1];
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
  uint8 r0 = 24;
  uint8 r1 = 7;
  uint8 v0 = 0;
  uint8 v1 = 0;
  do {
    uint8 v2 = r0;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam->xpos = r0;
    r0 = v2 + 8;
    oam->ypos = r1;
    oam->charnum = 126;
    oam->flags = 54;
    sprites_oamtile_size_buffer[v0++] = 0;
    if ((v0 & 3) == 0) {
      r0 = 24;
      r1 += 8;
    }
    v1 += 4;
  } while (v0 != 16);
}

void DrawOverworldPlayer() {  // 04862e
  uint16 v7;
  uint16 v2;
  uint16 v5;
  uint8 r6, r7;

  uint16 r0w = 0;
  uint16 r4w = 0;

  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  uint16 v1 = pt->x - mirror_current_layer1_xpos;
//  r8w = v1;
  if (v1 >= 0x100 || (r0w = pt->x - mirror_current_layer1_xpos, v2 = pt->y - mirror_current_layer1_ypos, v2 >= 0x100)) {
    v2 = 240;
  }
  uint16 r2w = v2;
  //r10w = v2;
  PointU16 *v3 = get_PointU16(ow_players_pos, player_current_characterx4 ^ 4);
  uint16 v4 = v3->x - mirror_current_layer1_xpos;
  uint16 r12w = v4;
  if (v4 >= 0x100 || (r4w = v3->x - mirror_current_layer1_xpos, v5 = v3->y - mirror_current_layer1_ypos, v5 >= 0x100)) {
    v5 = 240;
  }
  uint16 r14w = v5;
  uint8 r0 = r0w - 8;
  uint8 r1 = r2w - 9;
  uint8 r2 = r4w - 8;
  uint8 r3 = v5 - 9;
  uint8 tmp8c = 3;
  uint8 tmp8a = r6 = r0;
  uint8 tmp8b = r7 = r1;
  uint8 v6 = *((uint8 *)ow_players_animation + ((uint8)player_current_characterx4 >> 1));
  if (v6 != 18 && (v6 < 7 || v6 >= 0xF)) {
    tmp8b -= 5;
    r7 = tmp8b;
  }
  v7 = swap16(player_current_characterx4);
  r4w = v7 >> 1;
  DrawOverworldPlayer_DrawHalo(0, r4w, (PointU8) { .x = tmp8a, .y = tmp8b });
  DrawOverworldPlayer_DrawCurrentPlayer(0, player_current_characterx4 >> 1, 
      (PointU8) {.x = tmp8a, .y = tmp8b}, tmp8c, r4w, r6);
  sprites_oamtile_size_buffer[39] = 0;
  sprites_oamtile_size_buffer[40] = 0;
  sprites_oamtile_size_buffer[41] = 0;
  sprites_oamtile_size_buffer[42] = 0;
  sprites_oamtile_size_buffer[43] = 0;
  sprites_oamtile_size_buffer[44] = 0;
  sprites_oamtile_size_buffer[45] = 0;
  sprites_oamtile_size_buffer[46] = 0;
  tmp8c = 3;
  uint8 v8 = ow_players_map[0];
  if (pointer_current_overworld_process == 10)
    v8 = ow_players_map[0] ^ 1;
  if (v8 == ow_players_map[1]) {
    uint8 tmp8a = r6 = r2;
    uint8 tmp8b = r7 = r3;
    uint8 v9 = *((uint8 *)ow_players_animation + (((uint8)player_current_characterx4 >> 1) ^ 2));
    if (v9 != 18 && (v9 < 7 || v9 >= 0xF)) {
      tmp8b -= 5;
      r7 = tmp8b;
    }
    if (flag_two_player_game && r12w < 0xF0 && r14w < 0xF0) {
      r4w ^= 0x200;
      DrawOverworldPlayer_DrawHalo(0x20, r4w, (PointU8) { .x = tmp8a, .y = tmp8b });
      DrawOverworldPlayer_DrawCurrentPlayer(0x20, (player_current_characterx4 >> 1) ^ 2, 
        (PointU8) {.x = tmp8a, .y = tmp8b }, tmp8c, r4w, r6);
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

void DrawOverworldPlayer_DrawHalo(uint16 k, uint16 r4, PointU8 pt) {  // 048789
  uint16 v1 = swap16(r4);
  if (*(int16 *)(&player_current_character + (v1 >> 1)) < 0) {
    OamEnt *oam = get_OamEnt(oam_buf, k);
    oam[45].xpos = pt.x;
    oam[46].xpos = pt.x + 8;
    oam[45].ypos = pt.y - 7;
    oam[46].ypos = pt.y - 7;
    oam[45].charnum = 124;
    oam[46].charnum = 124;
    oam[45].flags = 32;
    oam[46].flags = 96;
  }
}

uint8 DrawOverworldPlayer_DrawCurrentPlayer(uint8 k_in, uint8 j, PointU8 pt, uint8 tmp8c, uint16 r4w, uint8 r6) {  // 04894f
  uint16 v3;
  uint16 v5;
  uint16 k = k_in;

  int16 v2 = k;
  v3 = j >> 1;
  if (players_has_yoshi[(uint8)v3]) {
    uint16 yoshi = players_has_yoshi[(uint8)v3];
    LOBYTE(v3) = j;
    tmp8c = 7;
    uint16 r0w = 16 * ow_players_animation[v3 >> 1];
    uint16 v7 = r0w + 2 * (counter_global_frames & 8);
    if (!k && *(uint16 *)&pointer_current_overworld_process == 11)
      v7 = kOwStarWarpAnimationOffset[(uint8)(counter_global_frames & 0xC) >> 2];
    do {
      uint16 v12 = v7;
      uint16 v8 = v7 >> 1;
      OamEnt *oam = get_OamEnt(oam_buf, k);
      oam[39].xpos = pt.x + kOwPlayerAndYoshiXDisp[v8];
      oam[39].ypos = pt.y + kOwPlayerAndYoshiYDisp[v8];
      uint16 v10 = v12;
      uint16 v11 = *(uint16 *)&kOwSpriteTilemapYoshi[v12];
      if (v11 != 0xffff) {
        uint16 v13 = *(uint16 *)&kOwSpriteTilemapYoshi[v12];
        uint16 v14;
        if ((v11 & 0xF00) == 512) {
          v14 = kOwYoshiPalette[(yoshi - 4) >> 1] | v13 & 0xF0FF;
        } else {
          v14 = r4w + v13;
        }
        *(uint16 *)&oam[39].charnum = v14;
      }
      k = k + 4;
      v7 = v10 + 2;
    } while ((--tmp8c & 0x80) == 0);
  } else {
    LOBYTE(v3) = j;
    uint16 r0w = 16 * ow_players_animation[v3 >> 1];
    uint16 v4 = r0w + (counter_global_frames & 0x18);
    v5 = swap16(r4w);
    if (*(int16 *)(&player_current_character + (v5 >> 1)) >= 0) {
      if (!k && *(uint16 *)&pointer_current_overworld_process == 11)
        v4 = kOwStarWarpAnimationOffset[(uint8)(counter_global_frames & 0xC) >> 2];
    } else {
      v4 = r0w;
    }
    do {
      OamEnt *v6 = get_OamEnt(oam_buf, k);
      v6[39].xpos = pt.x;
      v6[39].ypos = pt.y;
      *(uint16 *)&v6[39].charnum = r4w + kOwSpriteTilemap[v4 >> 1];
      k = k + 4;
      v4 += 2;
      pt.x += 8;
      if ((--tmp8c & 1) != 0) {
        pt.x = r6;
        pt.y += 8;
      }
    } while ((tmp8c & 0x80) == 0);
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
      uint16 r0w = pt->x >> 4;
      uint16 r2w = pt->y >> 4;
      uint16 r4w = CalculateOverworldPlayerPosition((uint8)player_current_characterx4 >> 2, r0w, r2w);
      if ((ow_level_tile_settings[ow_level_number_of_each_tiletbl[r4w]] & 0x80) == 0) {
        uint16 v3 = 20;
        while (ow_level_number_lo != kOwLevelsForcedMusicChange_048D74[v3 >> 1]) {
          v3 -= 2;
          if ((v3 & 0x8000) != 0)
            return;
        }
      }
    }
    io_music_ch1 = kOwSubmapMusic_048D8A[ow_players_map[player_current_character]];
  }
}

void GameMode0C_LoadOverworld_048E55() {  // 048e55
  player_current_characterx4 = 4 * player_current_character;
  PointU16 *pt = get_PointU16(ow_players_grid_aligned_pos, 4 * player_current_character);
  uint16 r0w = pt->x;
  uint16 r2w = pt->y;
  uint16 r4w = CalculateOverworldPlayerPosition((uint16)(4 * player_current_character) >> 2, r0w, r2w);
  if (HAS_LM_FEATURE(kLmFeature_LevelNamesPatch)) {
    LmHook_LevelNamesPatch(ow_level_number_of_each_tiletbl[r4w]);
  } else {
    UpdateLevelName(kLevelNames[(uint16)(2 * ow_level_number_of_each_tiletbl[r4w]) >> 1]);
  }
  if (r4w <= 0x7FF)
    ow_tile_player_is_standing_on = blocks_map16_table_lo[r4w];
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
        v2->x = kOw_KoopaKidTeleportXYPos_048E49[v1];
        v2->y = kOw_KoopaKidTeleportXYPos_048E49[v1 + 3];;
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
    uint16 r0w = pt->x >> 4;
    uint16 r2w = pt->y >> 4;
    uint16 r4w = CalculateOverworldPlayerPosition((uint8)player_current_characterx4 >> 2, r0w, r2w);
    if (flag_got_midpoint && misc_exit_level_action) {
      if ((misc_exit_level_action & 0x80) == 0) {
        *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[r4w]] =
            *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[r4w]] & 0xFF3F | 0x80;
        ++*(uint16 *)&pointer_current_overworld_process;
        goto LABEL_11;
      }
      *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[r4w]] |= 0x40;
    }
    pointer_current_overworld_process = 5;
  }
LABEL_11:
  OwProcess04_PlayerIsMoving_049831();
}

void OwProcess02_HandleLevelBeaten() {  // 048f87
  uint16 r4 = UnlockOverworldPathBasedOnExit();
  uint8 v0 = 7;
  uint8 a = (uint8)ow_tile_player_is_standing_on;

  if (g_lunar_magic) {
    if (ow_level_tile_settings[ow_level_number_of_each_tiletbl[r4]] & 0x10) {
      a = 0x80;
    } else {
      if (HAS_LM_FEATURE(kLmFeature_NoDefaultSavePrompts))
        a = 0xff;
    }
  }

  while (a != kOwTriggerSaveTiles_048F7F[v0]) {
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
LABEL_10:;
  //r6w = 0;
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  uint16 r0w = pt->x >> 4;
  uint16 r2w = pt->y >> 4;
  uint16 r4w = CalculateOverworldPlayerPosition((uint8)player_current_characterx4 >> 2, r0w, r2w);
  ow_tile_player_is_standing_on = blocks_map16_table_lo[r4w];
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

static const uint16 kSharedOverworldPathTables_DATA_049058[4] = { 0xffff, 0x1, 0xffff, 0x1,  };

void OwProcess03_StandingStill() {  // 049120
  uint16 v10;
  uint8 v0 = 0x91;  // note: undefined
  uint16 j;
  uint16 v16;
  uint16 r8;

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
  uint16 r0w = pt->x >> 4;
  PointU16 *v5 = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
  v5->x = r0w;
  uint16 r2w = pt->y >> 4;
  v5->y = r2w;
  uint16 r4w = CalculateOverworldPlayerPosition(v3 >> 2, r0w, r2w);
  if (misc_exit_level_action) {
    r8 = kSharedOverworldPathTables_DATA_049060[(uint8)(misc_exit_level_action - 1)];
    for (uint16 i = 10; (i & 0x8000) == 0; i -= 2) {
      if (ow_level_number_of_each_tiletbl[r4w] == kOwNoAutoMoveLevels_04906C[i >> 1]) {
        *(uint16 *)&pointer_current_overworld_process = 5;
        UpdateSaveBuffer();
        goto LABEL_63;
      }
    }
    uint16 v7 = ow_level_direction_flags[r4w];
    int16 v8 = r8;
    if (r8) {
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
//      r6w = 0;
      v10 = ow_level_tile_settings[ow_level_number_of_each_tiletbl[r4w]] & (uint8)v10 & 0xF;
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
  ow_player_direction = j;
  uint16 v14 = 0;
  if (j < 4)
    v14 = 2;
  r8 = r4w;

  *(uint16 *)(v14 ? &r2w : &r0w) += kSharedOverworldPathTables_DATA_049058[j >> 1];
  int16 v22; 
  r4w = CalculateOverworldPlayerPosition(player_current_characterx4 >> 2, r0w, r2w);
  uint16 v15 = ow_players_map[player_current_characterx4 >> 2] ? r4w : 0;
  if ((r4w & 0x8000) == 0 && v15 < 0x800) {
    v16 = blocks_map16_table_lo[r4w];
    if (blocks_map16_table_lo[r4w]) {
      if (v16 <= 0x86) {
LABEL_53:
        ow_tile_player_is_standing_on = v16;
        r0w = v16;
        r2w = 0;
        for (uint16 k = 23; (k & 0x8000) == 0; --k) {
          if (kOwUnknownTableA_From_04A03C[k] == r0w) {
            int16 v29 = player_current_characterx4 + WORD(kOwUnknownTableA_Direction_04A0E4[k]);
            int v21 = (uint16)(4 * k) >> 1;
            r0w = kOwUnknownTableA_XY_04A084[v21];
            r2w = kOwUnknownTableA_XY_04A084[v21 + 1];
            v22 = (uint8)v29;
            goto LABEL_62;
          }
        }
        uint16 v23 = 8;
        if ((j & 2) == 0)
          v23 = -8;
        r0w = v23;
        int16 v24 = 0;
        if (j < 4)
          v24 = 2;
        v22 = player_current_characterx4 + v24;
LABEL_62:;
        uint16 v25 = get_PointU16(ow_players_pos, v22)->x + r0w;
        get_PointU16(players_overworld_xpos_is_going_to, v22)->x = v25;
        uint16 v26 = v22 ^ 2;
        uint16 v27 = get_PointU16(ow_players_pos, v26)->x + r2w;
        get_PointU16(players_overworld_xpos_is_going_to, v26)->x = v27;
        r0w = j;
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
  r0w = ow_level_number_of_each_tiletbl[r8];
  uint16 v17 = 9;
  while (kOwHardcodedPathLevel_049078[v17] != 255) {
    if (kOwHardcodedPathLevel_049078[v17] == r0w)
      goto LABEL_49;
LABEL_51:
    if ((--v17 & 0x8000) != 0)
      goto LABEL_52;
  }
  PointU16 *v18 = get_PointU16(ow_players_pos, player_current_characterx4);
  if (v18->y != kOwHardcodedPathChocolateIsland2_049082[0] || v18->x != kOwHardcodedPathChocolateIsland2_049082[1] ||
      ow_players_map[player_current_character]) {
    goto LABEL_51;
  }
LABEL_49:
  r0w = v17;
  uint16 v19 = kOwHardcodedPathStartIndex_04910E[v17];
  ow_hardcoded_path_index = v19 - 1;
  r2w = j;
  if (kOwHardcodedPathDirs_0490CA[v19] == j) {
    ow_process_hardcoded_path_flag = 1;
    v16 = kOwHardcodedPathTiles_049086[v19];
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
  uint16 r14w;
  uint16 r8;
  uint16 r0w, r2w;

  while (1) {
    if (flag_switch_players) {
      pointer_current_overworld_process = 8;
      return;
    }
    uint16 arr4[2];
    uint8 v0 = player_current_characterx4 + 2;
    for (uint16 i = 2; (i & 0x8000) == 0; i -= 2) {
      uint16 x = get_PointU16(players_overworld_xpos_is_going_to, v0)->x;
      int16 v3 = x - get_PointU16(ow_players_pos, v0)->x;
      *(uint16 *)(i ? &r2w : &r0w) = v3;
      if (v3 < 0)
        v3 = -v3;
      arr4[i >> 1] = v3;
      v0 -= 2;
    }
    uint16 v4 = -1;
    uint16 r10w = arr4[0];
    uint16 r12 = arr4[1];
    if (arr4[1] >= arr4[0]) {
      r10w = arr4[1];
      r12 = arr4[0];
      v4 = 1;
    }
    r8 = v4;
    uint8 ma = 16 * kOverworldProcess04_PlayerIsMoving_OWPlayerPathSpeedOffset[ow_player_on_climbing_tile];
    v5 = r12;
    if (v5) {
      uint16 rw = Mult8x8(ma, r12);
      v5 = SnesDivide(rw, r10w);
    }
    r14w = v5;
    r10w = 16 * kOverworldProcess04_PlayerIsMoving_OWPlayerPathSpeedOffset[ow_player_on_climbing_tile];
    for (uint16 j = 2; (j & 0x8000) == 0; j -= 2) {
      uint16 v8;
      if ((r8 & 0x8000) != 0)
        v8 = r14w;
      else
        v8 = r10w;
      if ((int16)(j ? r2w : r0w) < 0)
        v8 = -v8;
      *(uint16 *)((int8 *)&player_overworld_xspeed + j) = v8;
      r8 = -r8;
    }
    uint16 v9 = 0;
    if ((r8 & 0x8000) == 0)
      v9 = 2;
    if ((v9 ? r2w : r0w))
      break;
    if (*(uint16 *)l1_l2_scroll_spr_timer) {
      ow_process_hardcoded_path_flag = 0;
      PointU16 *pt = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
      uint16 r0w = pt->x;
      uint16 r2w = pt->y;
      uint16 r4w = CalculateOverworldPlayerPosition(player_current_characterx4 >> 2, r0w, r2w);
      if (HAS_LM_FEATURE(kLmFeature_LevelNamesPatch)) {
        LmHook_LevelNamesPatch(ow_level_number_of_each_tiletbl[r4w]);
      } else {
        UpdateLevelName(kLevelNames[(uint16)(2 * ow_level_number_of_each_tiletbl[r4w]) >> 1]);
      }
      ++*(uint16 *)&pointer_current_overworld_process;
      UpdateSaveBuffer();
      OwProcess04_PlayerIsMoving_049831();
      return;
    }
    copy_of_tile_player_is_standingd_on = ow_tile_player_is_standing_on;
    r8 = 8;
    uint16 v11 = ow_player_direction;
    uint16 r4w;
    r10w = ow_player_direction ^ 2;
    while (1) {
      PointU16 *v13 = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
      r0w = v13->x;
      r2w = v13->y;
      if (v11 < 4)
        r2w += kSharedOverworldPathTables_DATA_049058[v11 >> 1];
      else
        r0w += kSharedOverworldPathTables_DATA_049058[v11 >> 1];
      r4w = CalculateOverworldPlayerPosition(player_current_characterx4 >> 2, r0w, r2w);
      v15 = ow_process_hardcoded_path_flag;
      if (!ow_process_hardcoded_path_flag)
        break;
//      r6w = v11;
      uint16 v16 = ow_hardcoded_path_index + 1;
      if (kOwHardcodedPathDirs_0490CA[(uint16)(ow_hardcoded_path_index + 1)] == v11) {
        ++ow_hardcoded_path_index;
        v15 = kOwHardcodedPathTiles_049086[v16];
        if (v15 != 88)
          goto LABEL_34;
        break;
      }
      uint16 v12;
      do {
LABEL_24:
        v12 = r8 - 2;
        r8 = v12;
      } while (v12 == r10w);
      v11 = v12;
    }
    if ((r4w & 0x8000) != 0 || v15 >= 0x800)
      goto LABEL_24;
    v15 = blocks_map16_table_lo[r4w];
LABEL_34:
    ow_tile_player_is_standing_on = v15;
    if (v15 == 0 || v15 >= 0x87)
      goto LABEL_24;
    v42 = v15;
    int16 v41 = v11;
    r14w = kOwTilePose_049FEB[v15 - 1];
    ow_player_on_climbing_tile = (r14w == 20);
    PointU16 *v18 = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
    v18->x = r0w;
    v18->y = r2w;
    v19 = v41;
    uint8 v20 = 9;
    while ((uint8)v15 != *((uint8 *)kOwExitLevelTiles_049426 + v20)) {
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
      r4w = kOwTilePathDirection_049F49[v26];
      v24 = kOwTileDistanceMovedAcross_049EA7[v26];
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
//        r6w = 0;
        *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[r4w]] |= kBitTable_Bank04[(uint16)((uint8)v19 ^ 2) >> 1];
      }
      r14w = ow_players_animation[((player_current_characterx4 >> 1) & 2) >> 1] & 0xC;
      r4w = 1;
      r0w = (uint8)copy_of_tile_player_is_standingd_on;
      for (int16 k = 23; k >= 0; --k) {
        if (kOwUnknownTableA_From_04A03C[(uint16)k] == r0w) {
          v24 = kOwUnknownTableA_Alpha_04A054[(uint16)(2 * k) >> 1];
          goto LABEL_60;
        }
      }
      v24 = 0x800;
      if ((uint16)v19 >= 4)
        v24 = 8;
LABEL_60:
      v25 = 0;
    }
    r0w = v24;
    v27 = v25;
    uint16 v28 = 14;
    while ((uint8)v27 != LOBYTE(kOverworldProcess04_PlayerIsMoving_DATA_049430[v28])) {
      if ((--v28 & 0x8000) != 0)
        goto LABEL_68;
    }
    if ((uint8)v19 != HIBYTE(kOverworldProcess04_PlayerIsMoving_DATA_049430[v28])) {
      v29 = kOverworldProcess04_PlayerIsMoving_DATA_04944E[v28];
      goto LABEL_69;
    }
LABEL_68:
    v29 = (v19 & 2) != 0;
LABEL_69:
    if (r4w & (v29 ? 0xff00 : 0xff)) {
      BYTE(r0w) = -BYTE(r0w);
      HIBYTE(r0w) = -HIBYTE(r0w);
    }
    r4w = (uint8)r14w;
    if ((((r14w & 7) == 0) ? (r0w >> 8) : (r0w & 0xff)) < 0x80)
      r4w += 2;
    ow_players_animation[((player_current_characterx4 >> 1) & 2) >> 1] = r4w;
    int16 v30 = (uint8)r0w;
    if ((uint8)r0w >= 0x80)
      v30 = (uint8)r0w | 0xFF00;
    PointU16 *v31 = get_PointU16(ow_players_pos, player_current_characterx4);
    PointU16 *v32 = get_PointU16(players_overworld_xpos_is_going_to, player_current_characterx4);
    v32->x = (v31->x + v30) & 0xFFFC;
    int16 v33 = (int8)(r0w >> 8);
    v32->y = (v31->y + v33) & 0xFFFC;
    if ((v32->x & 0xF) != 0) {
      if ((v32->y & 0xF) == 0) {
        v19 = 0;
        if ((r0w & 0x8000) == 0)
          v19 = 2;
      }
    } else {
      v19 = 4;
      if ((r0w & 0x80) == 0)
        v19 = 6;
    }
    ow_player_direction = v19;
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
  uint16 r0w = pt->x;
  uint16 r2w = pt->y;
  if (!ow_players_map[player_current_characterx4 >> 2]) {
    uint16 v1 = 2;
    uint16 v2 = 2;
    do {
      uint16 v3 = (v1 ? r2w : r0w) - 128;
      if ((v3 & 0x8000) == 0) {
        int v5 = v2 >> 1;
        if (v3 >= kOw_MaxRangeForScrollWalking_049416[v5 + 2])
          v3 = kOw_MaxRangeForScrollWalking_049416[v5 + 2];
      } else {
        int v4 = v2 >> 1;
        if (v3 < kOw_MaxRangeForScrollWalking_049416[v4])
          v3 = kOw_MaxRangeForScrollWalking_049416[v4];
      }
      *(uint16 *)((int8 *)&mirror_current_layer1_xpos + v1) = v3;
      *(uint16 *)((int8 *)&mirror_current_layer2_xpos + v1) = v3;
      v2 -= 2;
      v1 -= 2;
    } while ((v1 & 0x8000) == 0);
  }
}

uint16 CalculateOverworldPlayerPosition(uint8 k, uint16 r0w, uint16 r2w) {  // 049885
  uint16 r4 = r0w & 0xF;
  r4 += 16 * (r0w & 0x10);
  r4 += (uint8)(16 * r2w);
  if ((r2w & 0x10) != 0)
    r4 += 512;
  if (ow_players_map[k])
    r4 += 0x400;
  return r4;
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

uint16 UnlockOverworldPathBasedOnExit() {  // 049903
  if ((int8)misc_exit_level_action <= 0)
    return 0;

  uint16 r8 = kSharedOverworldPathTables_DATA_049060[(uint8)(misc_exit_level_action - 1)];
  uint8 v0 = player_current_characterx4;
  PointU16 *pt = get_PointU16(ow_players_pos, player_current_characterx4);
  uint16 r0w = pt->x >> 4;
  PointU16 *v2 = get_PointU16(ow_players_grid_aligned_pos, player_current_characterx4);
  v2->x = r0w;
  uint16 r2w = pt->y >> 4;
  v2->y = r2w;
  uint16 r4w = CalculateOverworldPlayerPosition(v0 >> 2, r0w, r2w);
  uint16 v3 = ow_level_direction_flags[r4w];
  int16 v4 = r8;
  if (r8) {
    do {
      v3 >>= 1;
      --v4;
    } while (v4 >= 0);
  }
  *(uint16 *)&ow_level_tile_settings[ow_level_number_of_each_tiletbl[r4w]] |= kBitTable_Bank04[(uint16)(2 * (v3 & 3)) >> 1];
  return r4w;
}

void HandleOverworldPathExits() {  // 049a24
  PointU16 *pt;
  ow_currently_loaded_submap = ow_players_map[(uint8)(player_current_characterx4 >> 2)];
  uint16 r2w = 26;
  uint8 v0 = 13;
  uint8 v1 = player_current_characterx4;
  const OwExits *src = (OwExits*)kOwExitSource_049964;
  while (1) {
    pt = get_PointU16(ow_players_pos, player_current_characterx4);
    if (pt->y == src[v0].field_0 && pt->x == src[v0].field_2 &&
      src[v0].field_4 == ow_currently_loaded_submap) {
      break;
    }
    --r2w;
    --r2w;
    if ((--v0 & 0x80) != 0)
      return;
  }
  const OwExits *dst = (OwExits*)kOwExitDest_0499AA;
  pt->y = dst[v0].field_0;
  pt->x = dst[v0].field_2;
  ow_currently_loaded_submap = dst[v0].field_4;
  PointU16 *v4 = get_PointU16(ow_players_grid_aligned_pos, v1);
  v4->y = kOwExitExtra_0499F0[r2w];
  v4->x = kOwExitExtra_0499F0[r2w + 1];
}

void HandleOverworldPathExits_SetLayerPositions() {  // 049a93
  uint16 v0 = (uint8)player_current_characterx4 >> 2;
  int16 v1 = ow_currently_loaded_submap | (ow_players_map[v0 + 1] << 8);
  *(uint16 *)&ow_players_map[v0] = v1;
  if ((uint8)v1) {
    int v2 = (uint16)(4 * ((uint8)v1 - 1)) >> 1;
    mirror_current_layer1_xpos = kOwExitLayerPosition_049A0C[v2];
    mirror_current_layer2_xpos = mirror_current_layer1_xpos;
    mirror_current_layer1_ypos = kOwExitLayerPosition_049A0C[v2 + 1];
    mirror_current_layer2_ypos = mirror_current_layer1_ypos;
  } else {
    OwProcess04_PlayerIsMoving_04983F();
  }
}

void UpdateLevelName(uint16 r0w) {  // 049d07
  uint16 v0 = stripe_image_upload;
  uint16 r2w = stripe_image_upload + 38;
  stripe_image_upload += 42;
  *(uint16 *)&stripe_image_upload_data[v0 + 2] = 0x2500;
  *(uint16 *)&stripe_image_upload_data[v0] = 0x8b50;
  uint16 v1 = kUpdateLevelName_DATA_049C91[(uint16)(2 * ((r0w >> 8) & 0x7F)) >> 1];
  if ((kUpdateLevelName_LevelNameStrings[v1] & 0x80) == 0)
    v0 = UpdateLevelName_049D7F(v0, v1, r2w);
  uint16 v2 = kUpdateLevelName_DATA_049CCF[(uint16)((uint8)(r0w & 0xF0) >> 3) >> 1];
  if (kUpdateLevelName_LevelNameStrings[v2] != 0x9F)
    v0 = UpdateLevelName_049D7F(v0, v2, r2w);
  v0 = UpdateLevelName_049D7F(v0, kUpdateLevelName_DATA_049CED[(uint16)(2 * (r0w & 0xF)) >> 1], r2w);
  while (v0 < r2w)
    v0 = UpdateLevelName_049D7F(v0, 0x1CB, r2w);
  stripe_image_upload_data[v0 + 4] = -1;
}

uint16 UpdateLevelName_049D7F(uint16 k, uint16 j, uint16 r2w) {  // 049d7f
  uint8 t;
  do {
    t = kUpdateLevelName_LevelNameStrings[j];
    if (k < r2w) {
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

  uint32 addr = 0x14000;
  if (ow_players_map[(uint8)player_current_characterx4 >> 2])
    addr = 0x16000;
  SmwCopyToVram(0x3000, g_ram + addr, 0x2000);
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
  if (kOwLayer1AndEvents_SIZE) {
    int len = DecompressTo(kOwLayer1AndEvents, g_ram + 0xd000);  // 0x1000 bytes
    if (kOwLayer1AndEvents2_SIZE)
      DecompressTo(kOwLayer1AndEvents2, g_ram + 0x1c800);
  } else {
    uint8 *r13 = g_ram + 0xd000;
    uint8 *r10 = g_ram + 0xd800;
    uint8 *r4 = g_ram + 0xc800;

    uint8 r0 = 1;
    for (int16 i = 0x7ff; i >= 0; --i) {
      r10[i] = 0;
      r13[i] = 0;
    }
    for (uint16 j = 0; j != 0x800; ++j) {
      uint8 v3 = r4[j];
      if (v3 >= 0x56 && v3 < 0x81) {
        uint8 v0 = r0;
        r13[j] = r0;
        r10[j] = kOwDirectionAfterBeatingLevel_04D678[v0];
        ++r0;
      }
    }
  }

  uint8 r15 = 0;
  do {
    LoadOverworldLayer1AndEvents_04DA49(r15);
    ++r15;
  } while (r15 != 111);
}

void LoadOverworldLayer1AndEvents_04DA49(uint8 r15) {  // 04da49
  if ((kBitTable_DATA_04E44B[r15 & 7] & ow_event_flags[(uint8)(r15 & 0xF8) >> 3]) != 0) {
    uint8 *p4 = g_ram + 0xc800;
    uint16 v0 = kChangingLayer1OverworldTiles_Layer1TileLocation[r15];
    uint16 v1 = 21;
    uint8 v2 = p4[v0];
    while (v2 != kChangingLayer1OverworldTiles_TilesThatChange[v1]) {
      if ((--v1 & 0x8000) != 0)
        goto LABEL_8;
    }
    uint8 v3 = kChangingLayer1OverworldTiles_TilesToBecome[v1];
    p4[v0] = v3;
    if (!HAS_LM_FEATURE(kLmFeature_EventStuff)) {
      if (v1 == 21)
        p4[v0 + 1] = v3;
    }
LABEL_8:
    CheckIfDestroyTileEventIsActive(r15);
    pointer_overworld_event_process = 0;
    OwEventProcess07_SilentEventsAndEndOfEvent_Entry2(r15, true);
  }
}

void LoadOverworldLayer2AndEventsTilemaps() {  // 04daad
  LoadOverworldLayer2AndEventsTilemaps_Sub();
}

void BufferOverworldLayer2Tilemap(uint16 k, uint16 j, uint16 r14w, const uint8 *p0) {  // 04daba
  do {
    uint8 r3 = p0[j];
    if ((r3 & 0x80) != 0) {
      r3 &= ~0x80;
      uint8 v2 = p0[++j];
      do {
        ow_layer2_tiles[k] = v2;
        k += 2;
      } while ((--r3 & 0x80) == 0);
    } else {
      do {
        ow_layer2_tiles[k] = p0[++j];
        k += 2;
      } while ((--r3 & 0x80) == 0);
    }
    ++j;
  } while (k < r14w);
}

void OwProcess0A_SwitchBetweenSubmaps() {  // 04daef
  kOverworldProcess0A_SwitchBetweenSubmaps_Ptrs04DAF8[ow_submap_switch_process]();
}

void SubmapSwitchProcess06_EndWindowHDMA() {  // 04db18
  int16 v1;

  static const uint16 kInitializeWindowHDMA_DATA_04DB08[2] = { 0xf900, 0x700,  };
  static const uint8 kInitializeWindowHDMA_DATA_04DB0C[4] = { 0x0, 0x0, 0x0, 0x70,  };
  static const uint16 kInitializeWindowHDMA_DATA_04DB10[2] = { 0xfac0, 0x540,  };
  static const uint8 kInitializeWindowHDMA_DATA_04DB14[4] = { 0x0, 0x0, 0x0, 0x54,  };

  int v0 = ow_hdmatransition_effect_flag >> 1;
  ow_hdmatransition_effect_xpos += kInitializeWindowHDMA_DATA_04DB08[v0];
  if (((kInitializeWindowHDMA_DATA_04DB08[v0] ^
        (ow_hdmatransition_effect_xpos -
         *(uint16 *)&kInitializeWindowHDMA_DATA_04DB0C[ow_hdmatransition_effect_flag])) &
       0x8000) == 0 ||
      (ow_hdmatransition_effect_ypos += kInitializeWindowHDMA_DATA_04DB10[v0],
       ((kInitializeWindowHDMA_DATA_04DB10[v0] ^
         (ow_hdmatransition_effect_ypos -
          *(uint16 *)&kInitializeWindowHDMA_DATA_04DB14[ow_hdmatransition_effect_flag])) &
        0x8000) == 0)) {
    ow_hdmatransition_effect_xpos = *(uint16 *)&kInitializeWindowHDMA_DATA_04DB0C[ow_hdmatransition_effect_flag];
    ow_hdmatransition_effect_ypos = *(uint16 *)&kInitializeWindowHDMA_DATA_04DB14[ow_hdmatransition_effect_flag];
    ++*(uint16 *)&ow_submap_switch_process;
    ow_hdmatransition_effect_flag ^= 2;
    if (ow_hdmatransition_effect_flag)
      HandleOverworldPathExits_SetLayerPositions();
  }
  uint8 r0 = 2 * HIBYTE(ow_hdmatransition_effect_ypos);
  HIBYTE(v1) = HIBYTE(ow_hdmatransition_effect_xpos) + 0x80;
  LOBYTE(v1) = 0x80 - HIBYTE(ow_hdmatransition_effect_xpos);
  uint8 v2 = 0;
  uint8 v3 = -88;
  do {
    if (v2 >= r0)
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
  misc_level_tileset_setting = kOwSubmapTileset_04DC02[ow_players_map[(uint8)player_current_characterx4 >> 2]];
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
    io_music_ch1 = kOwSubmapMusic_048D8A[ow_players_map[v0]];
    flag_change_submap_music_on_player_switch = 0;
  }
}

void LoadOverworldLayer1AndEvents() {  // 04dc09
  misc_level_tileset_setting = kOwSubmapTileset_04DC02[ow_players_map[(uint8)player_current_characterx4 >> 2]];
  graphics_level_sprite_graphics_setting = 17;
  misc_level_mode_setting = 7;
  misc_level_layout_flags = 3;
  uint16 t = 0;
  uint8 v1 = 0;
  do
    t = LoadOverworldLayer1AndEvents_InitializedOverworldLayer1Tilemap(t, v1);
  while (t != 432);
  uint16 r0w = 0xd000;
  for (uint16 i = 0; i != 0x400; i += 2) {
    pointer_map16_tiles[i >> 1] = r0w;
    r0w += 8;
  }
  uint8 *v3 = g_ram + 0xC800;
  const uint8 *v4 = kLoadOverworldLayer1AndEvents_DATA_0CF7DF;
  MemCpy(v3, v4, 0x800);
  LoadOverworldLayer1AndEvents_04D7F2();
}

void LoadOverworldLayer2AndEventsTilemaps_Sub() {  // 04dc6a
  LoadOverworldLayer2AndEventsTilemaps_04DD40();
  BufferOverworldLayer2Tilemap(0, 0, 0x4000, kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap);
  BufferOverworldLayer2Tilemap(1, 0, 0x4000, kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap_Prop);
  uint8 r15 = 0, r15_end = g_lunar_magic ? 120 : 111;
  do {
    // lm hook moved into function
    LoadOverworldLayer2AndEventsTilemaps_04E453(r15);
    ++r15;
  } while (r15 != r15_end);
}

void SubmapSwitchProcess01_UpdateLayer1() {  // 04dcb6
  const uint8 *p0 = (const uint8 *)kMap16Data_OverworldLayer1;
  uint16 r0w = (ow_submap_switch_process - 1) << 8;
  if (ow_players_map[(uint8)(player_current_characterx4 >> 2)])
    r0w += 4 << 8;
  do {
    uint16 r2w = blocks_map16_table_lo[r0w] | blocks_map16_table_hi[r0w] << 8;
    uint16 v0 = 8 * r2w;
    r2w = (4 * (uint8)r0w) & 0x3F;
    uint16 v1 = r2w | (8 * (uint8)r0w) & 0xF80;
    *(uint16 *)&ow_byte_7EE000[v1 + 0x400] = WORD(p0[v0]);
    v0 += 2;
    *(uint16 *)&ow_byte_7EE000[v1 + 0x440] = WORD(p0[v0]);
    v0 += 2;
    *(uint16 *)&ow_byte_7EE000[v1 + 0x402] = WORD(p0[v0]);
    v0 += 2;
    *(uint16 *)&ow_byte_7EE000[v1 + 0x442] = WORD(p0[v0]);
    ++r0w;
  } while (r0w&0xff);
  ++ow_submap_switch_process;
}

void LoadOverworldLayer2AndEventsTilemaps_04DD40() {  // 04dd40
  LoadOverworldLayer2AndEventsTilemaps_04DD57(0, 0, kOverworldLayer2EventTilemap_Prop);
}

void LoadOverworldLayer2AndEventsTilemaps_04DD57(uint16 k, uint16 j, const uint8 *p2) {  // 04dd57
  do {
    const uint8 *v2 = &p2[j++];
    uint8 r5 = *v2;
    if ((r5 & 0x80) != 0) {
      r5 &= ~0x80;
      uint8 v3 = p2[j];
      do {
        ow_layer2_event_tiles[k++] = v3;
        --r5;
      } while ((r5 & 0x80) == 0);
      ++j;
    } else {
      do {
        ow_layer2_event_tiles[k++] = p2[j++];
        --r5;
      } while ((r5 & 0x80) == 0);
    }
  } while (WORD(p2[j]) != 0xFFFF);
}

void LoadOverworldLayer2AndEventsTilemaps_04E453(uint8 r15) {  // 04e453
  if ((kBitTable_DATA_04E44B[r15 & 7] & ow_event_flags[r15 >> 3]) != 0) {
    int v0 = (uint8)(2 * r15) >> 1;
    ow_starting_event_tile = kLayer2EventData_Ptrs_04E359[v0];
    for (ow_final_event_tile = kLayer2EventData_Ptrs_04E359[v0 + 1]; ow_starting_event_tile != ow_final_event_tile; ++ow_starting_event_tile) {
      BufferEventTileToLayer2Tilemap();
      if (HAS_LM_FEATURE(kLmFeature_EventStuff))
        LmHook_EventStuff(r15, false);
    }
  }
}

void BufferEventTileToLayer2Tilemap() {  // 04e496
  int v0 = (uint16)(4 * ow_starting_event_tile) >> 1;
  uint16 v1 = kLayer2EventData_TileEntries[v0];
  BufferEventTileToLayer2Tilemap_Entry2(4 * ow_starting_event_tile, v1, kLayer2EventData_TileEntries[v0 + 1]);
}

void BufferEventTileToLayer2Tilemap_Entry2(uint16 k, uint16 j, uint16 r4) {  // 04e4a9
  const uint8 *r6 = g_ram + 0x10000;
  const uint8 *r9 = kOverworldLayer2EventTilemap_Tiles;
  if (j < 0x900)
    BufferEventTileToLayer2Tilemap_Buffer6x6Tile(k, j, r4, r6, r9);
  else
    BufferEventTileToLayer2Tilemap_Buffer2x2Tile(k, j, r4, r6, r9);
}

void BufferEventTileToLayer2Tilemap_Buffer2x2Tile(uint16 k, uint16 j, uint16 r4, const uint8 *r6, const uint8 *r9) {  // 04e4d0
  uint16 r0w = 1;
  do {
    uint16 v2 = r4;
    uint8 r12 = 1;
    do {
      ow_layer2_tiles[v2++] = r9[j];
      ow_layer2_tiles[v2++] = r6[j++];
      if ((v2 & 0x3F) == 0)
        v2 = ((v2 - 1) & 0xFFC0) + 0x800;
    } while ((--r12 & 0x80) == 0);
    uint16 v4 = r4;
    r4 += 64;
    if ((r4 & 0x7C0) == 0)
      r4 = (v4 & 0xF83F) + 0x1000;
  } while ((--r0w & 0x8000) == 0);
}

void BufferEventTileToLayer2Tilemap_Buffer6x6Tile(uint16 k, uint16 j, uint16 r4, const uint8 *r6, const uint8 *r9) {  // 04e520
  uint16 r0w = 5;
  do {
    uint16 v2 = r4;
    uint8 r12 = 5;
    do {
      ow_layer2_tiles[v2++] = r9[j];
      ow_layer2_tiles[v2++] = r6[j++];
      if ((v2 & 0x3F) == 0)
        v2 = ((v2 - 1) & 0xFFC0) + 0x800;
    } while ((--r12 & 0x80) == 0);
    uint16 v4 = r4;
    r4 += 64;
    if ((r4 & 0x7C0) == 0)
      r4 = (v4 & 0xF83F) + 0x1000;
  } while ((--r0w & 0x8000) == 0);
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
      if (kOwTriggerSaveTiles_048F7F[i] == (uint8)ow_tile_player_is_standing_on) {  // merged tables
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
  uint8 v1 = kOwDestruction_TriggerEvent_04E5D6_SIZE - 1; // bug fix
  while (a != kOwDestruction_TriggerEvent_04E5D6[v1]) {
    if ((--v1 & 0x80) != 0) {
LABEL_4:
      pointer_overworld_event_process = 2;
      return 0;
    }
  }
  ow_destroy_tile_event_vramindex = v1;
  uint8 *p = blocks_map16_table_lo;
  uint16 v2 = kCheckIfDestroyTileEventIsActive_DATA_04E5B6[v1];
  uint16 v3 = 4;
  uint8 v4 = p[v2];
  while (v4 != kOwDestruction_TileToIdx_04E5A7[v3]) {
    if ((--v3 & 0x8000) != 0)
      goto LABEL_4;
  }
  ow_destroy_tile_event_tile_index = v3;
  if ((int16)(v3 - 3) >= 0) {
    p[v2] = kOwDestruction_TopTile_04E5AC[v3];
    v2 = HAS_LM_FEATURE(kLmFeature_DestroyTileAnims) ? LmHook_RemapDestroyTile(v2) : v2 + 16;
  }
  p[v2] = kOwDestruction_BottomTile_04E5B1[v3];
  return v2;
}

void OwEventProcess02_SetEventTileIndexes() {  // 04e6d3
  ++pointer_overworld_event_process;
  int v0 = (uint8)(2 * ow_current_event_number) >> 1;
  ow_starting_event_tile = kLayer2EventData_Ptrs_04E359[v0];
  ow_final_event_tile = kLayer2EventData_Ptrs_04E359[v0 + 1];
  if (ow_final_event_tile == ow_starting_event_tile) {
    pointer_overworld_event_process += 2;
  }
}

void OwEventProcess03_GetLayer2Tile() {  // 04e6f9
  uint16 v2;

  OwEventProcess03_GetLayer2Tile_04EA62();
  uint16 v0 = 4 * ow_starting_event_tile;
  int v1 = (uint16)(4 * ow_starting_event_tile) >> 1;
  *(uint16 *)&timer_destroy_tile_event_unknown = kLayer2EventData_TileEntries[v1];
  uint16 r0w = kLayer2EventData_TileEntries[v1 + 1];
  LOBYTE(v2) = (uint16)(((uint16)(r0w & 0x1FFF) >> 1) + 0x3000) >> 8;
  HIBYTE(v2) = (uint16)(r0w & 0x1FFF) >> 1;
  uint16 r2w = v2;
  ow_on_screen_ypos_of_current_event_tile = (r0w >> 3) & 0xF8;
  ow_on_screen_xpos_of_current_event_tile = 4 * (r0w & 0x3E);
  const uint8 *r12 = g_ram + 0x14000;
  if (*(uint16 *)&timer_destroy_tile_event_unknown < 0x900)
    v0 = BufferEventTileToStripeImageTable_Buffer6x6Tile(r0w, r2w, 0xefff, r12);
  else
    v0 = BufferEventTileToStripeImageTable_Buffer2x2Tile(r0w, r2w, 0xefff, r12);
  *(uint16 *)&stripe_image_upload_data[v0] = 255;
  stripe_image_upload = v0;
  BufferEventTileToLayer2Tilemap();
  io_sound_ch3 = 21;
  ++pointer_overworld_event_process;
}

uint16 BufferEventTileToStripeImageTable_Buffer2x2Tile(uint16 r0w, uint16 r2w, uint16 r10, const uint8 *r12) {  // 04e76c
  int16 v3;
  int16 v5;
  int16 v6;
  uint16 v9;
  int16 v12;
  uint16 v13;
  uint16 r8;

  uint16 n = 1;
  uint16 v0 = stripe_image_upload;
  do {
    *(uint16 *)&stripe_image_upload_data[v0] = r2w;
    uint16 v1 = v0 + 2;
    int16 v2 = 768;
    r8 = (r2w >> 8) & 0x1F;
    r8 = 32 - r8;
    if (r8 == 1) {
      LOBYTE(v3) = (uint16)(2 * r8 - 1) >> 8;
      HIBYTE(v3) = 2 * r8 - 1;
      v2 = v3;
    }
    *(uint16 *)&stripe_image_upload_data[v1] = v2;
    v0 = v1 + 2;
    uint16 r4 = 1;
    uint16 v4 = r0w;
    do {
      *(uint16 *)&stripe_image_upload_data[v0] = r10 & WORD(r12[v4]);
      v0 += 2;
      v4 += 2;
      if ((v4 & 0x3F) == 0 && r4) {
        v4 = ((v4 - 1) & 0xFFC0) + 0x800;
        LOBYTE(v5) = HIBYTE(r2w);
        HIBYTE(v5) = r2w;
        v6 = (v5 & 0x3BE0) + 0x400;
        int8 v7 = v6;
        LOBYTE(v6) = HIBYTE(v6);
        HIBYTE(v6) = v7;
        *(uint16 *)&stripe_image_upload_data[v0] = v6;
        uint16 v8 = v0 + 2;
        LOBYTE(v6) = (uint16)(2 * r8 - 1) >> 8;
        HIBYTE(v6) = 2 * r8 - 1;
        *(uint16 *)&stripe_image_upload_data[v8] = v6;
        v0 = v8 + 2;
      }
      --r4;
    } while ((r4 & 0x8000) == 0);
    LOBYTE(v9) = HIBYTE(r2w);
    HIBYTE(v9) = r2w;
    v9 += 32;
    int8 v10 = v9;
    LOBYTE(v9) = HIBYTE(v9);
    HIBYTE(v9) = v10;
    r2w = v9;
    uint16 v11 = r0w;
    r0w += 64;
    if ((r0w & 0x7C0) == 0) {
      r0w = (v11 & 0xF83F) + 0x1000;
      LOBYTE(v12) = HIBYTE(r2w);
      HIBYTE(v12) = r2w;
      v13 = ((v12 - 32) & 0x341F) + 0x800;
      int8 v14 = v13;
      LOBYTE(v13) = HIBYTE(v13);
      HIBYTE(v13) = v14;
      r2w = v13;
    }
    --n;
  } while ((n & 0x8000) == 0);
  return v0;
}

uint16 BufferEventTileToStripeImageTable_Buffer6x6Tile(uint16 r0w, uint16 r2w, uint16 r10, const uint8 *r12) {  // 04e824
  int16 v3;
  int16 v5;
  int16 v6;
  uint16 v9;
  int16 v12;
  uint16 v13;
  uint16 r8;

  uint16 n = 5;
  uint16 v0 = stripe_image_upload;
  do {
    *(uint16 *)&stripe_image_upload_data[v0] = r2w;
    uint16 v1 = v0 + 2;
    int16 v2 = 0xb00;
    r8 = (r2w >> 8) & 0x1F;
    r8 = 32 - r8;
    if (r8 < 6) {
      LOBYTE(v3) = (uint16)(2 * r8 - 1) >> 8;
      HIBYTE(v3) = 2 * r8 - 1;
      v2 = v3;
      r8 = 6 - r8;
    }
    *(uint16 *)&stripe_image_upload_data[v1] = v2;
    v0 = v1 + 2;
    uint16 r4 = 5;
    uint16 v4 = r0w;
    do {
      *(uint16 *)&stripe_image_upload_data[v0] = r10 & WORD(r12[v4]);
      v0 += 2;
      v4 += 2;
      if ((v4 & 0x3F) == 0 && r4) {
        v4 = ((v4 - 1) & 0xFFC0) + 0x800;
        LOBYTE(v5) = HIBYTE(r2w);
        HIBYTE(v5) = r2w;
        v6 = (v5 & 0x3BE0) + 0x400;
        int8 v7 = v6;
        LOBYTE(v6) = HIBYTE(v6);
        HIBYTE(v6) = v7;
        *(uint16 *)&stripe_image_upload_data[v0] = v6;
        uint16 v8 = v0 + 2;
        LOBYTE(v6) = (uint16)(2 * r8 - 1) >> 8;
        HIBYTE(v6) = 2 * r8 - 1;
        *(uint16 *)&stripe_image_upload_data[v8] = v6;
        v0 = v8 + 2;
      }
    } while ((--r4 & 0x8000) == 0);
    LOBYTE(v9) = HIBYTE(r2w);
    HIBYTE(v9) = r2w;
    v9 += 32;
    int8 v10 = v9;
    LOBYTE(v9) = HIBYTE(v9);
    HIBYTE(v9) = v10;
    r2w = v9;
    uint16 v11 = r0w;
    r0w += 64;
    if ((r0w & 0x7C0) == 0) {
      r0w = (v11 & 0xF83F) + 0x1000;
      LOBYTE(v12) = HIBYTE(r2w);
      HIBYTE(v12) = r2w;
      v13 = ((v12 - 32) & 0x341F) + 0x800;
      int8 v14 = v13;
      LOBYTE(v13) = HIBYTE(v13);
      HIBYTE(v13) = v14;
      r2w = v13;
    }
    --n;
  } while ((n & 0x8000) == 0);
  return v0;
}

void OwEventProcess07_SilentEventsAndEndOfEvent() {  // 04e9ec
  OwEventProcess07_SilentEventsAndEndOfEvent_Entry2(ow_current_event_number, false);
}

void OwEventProcess07_SilentEventsAndEndOfEvent_Entry2(uint8 a, bool from_where) {  // 04e9f1
  if (HAS_LM_FEATURE(kLmFeature_EventStuff)) {
    LmHook_EventStuff(a, from_where);
  } else {
    for (uint8 i = kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_SIZE - 1; (i & 0x80) == 0; --i) {
      if (a == kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles[i]) {
        uint8 v4 = i;
        uint8 r2 = kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileLayer[i];
        uint16 v2 = (uint8)(2 * i);
        int v3 = (uint8)v2 >> 1;
        uint16 r0w = kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileNum[v3];
        uint16 r4w = kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TilemapLocation[v3];
        if ((r2 & 1) != 0)
          BufferEventTileToLayer2Tilemap_Entry2(v2, r0w, r4w);
        else
          blocks_map16_table_lo[r4w] = r0w;
        i = v4;
      }
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
    PointU8 pt = GetXAndYDispOfCurrentEventTileSprite();
    uint16 v0 = 140;
    int16 v1 = 6;
    if (*(uint16 *)&timer_destroy_tile_event_unknown >= 0x900) {
      v0 = 12;
      v1 = 2;
    }
    uint16 r5 = v1;
    uint16 v2 = *(uint16 *)&timer_destroy_tile_event_unknown;
    do {
      uint8 r3 = r5;
      uint8 v3 = pt.x;
      do {
        uint8 r2 = v3;
        OamEnt *oam = get_OamEnt(oam_buf, v0);
        oam[84].ypos = pt.y;
        oam[84].charnum = kOverworldLayer2EventTilemap_Tiles[v2];
        oam[84].flags = ow_layer2_event_tiles[v2] & 0xC0 | ((uint8)(ow_layer2_event_tiles[v2] & 0x1C) >> 1) | 0x11;
        uint8 v5 = r2;
        oam[84].xpos = r2;
        v3 = v5 + 8;
        ++v2;
        v0 -= 4;
        --r3;
      } while (r3);
      pt.y += 8;
    } while (v0 != 0xFFFC);
    for (int8 i = 35; i >= 0; --i)
      sprites_oamtile_size_buffer[(uint8)i + 84] = 0;
    uint8 v7 = 8;
    if (ow_players_map[player_current_character] == 3)
      v7 = 1;
    uint8 tmp8a = v7;
    do {
      OwEventProcess04_FadeInLayer2Tile_00B006(timer_level_end_fade);
      --tmp8a;
    } while (tmp8a);
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
  uint8 r2, r3;
  if ((--timer_destroy_tile_event_unknown & 0x80) == 0) {
    uint8 v0 = timer_destroy_tile_event_unknown;
    uint8 v1;
    PointU8 pt;
    if (pointer_overworld_event_process == 1) {
      if (timer_destroy_tile_event_unknown == 24) {
        OwEventProcess01_DestroyTileAnimation_04EEAA();
        v0 = 24;
      }
      v1 = v0 & 0xFC;
      r2 = kOwDestroyTileAnimation_Char2_04EBE1[(v0 & 0xFC) >> 2];
      pt = GetXAndYDispOfCurrentEventTileSprite();
    } else {
      if (timer_destroy_tile_event_unknown == 16) {
        OwEventProcess01_DestroyTileAnimation_04ED83();
        v0 = 16;
      }
      r2 = kOwDestroyTileAnimation_Char_04EBDA[v0 >> 2];
      pt = GetXAndYDispOfCurrentEventTileSprite();
      v1 = 40;
    }
    r3 = 3;
    uint8 v2 = 0;
    do {
      OamEnt *oam = get_OamEnt(oam_buf, v2);
      oam[32].xpos = kOwDestroyTileAnimation_X_04EB56[v1] + pt.x;
      oam[32].ypos = kOwDestroyTileAnimation_Y_04EB82[v1] + pt.y;
      oam[32].charnum = r2;
      oam[32].flags = kOwDestroyTileAnimation_Flags_04EBAE[v1];
      v2 += 4;
      ++v1;
      --r3;
    } while ((r3 & 0x80) == 0);
    sprites_oamtile_size_buffer[32] = 0;
    sprites_oamtile_size_buffer[33] = 0;
    sprites_oamtile_size_buffer[34] = 0;
    sprites_oamtile_size_buffer[35] = 0;
  } else {
    ++pointer_overworld_event_process;
  }
}

PointU8 GetXAndYDispOfCurrentEventTileSprite() {  // 04ec67
  uint8 r0 = ow_on_screen_xpos_of_current_event_tile - mirror_current_layer2_xpos;
  uint8 r1 = ow_on_screen_ypos_of_current_event_tile - (mirror_current_layer2_ypos + 1);
  return (PointU8) { .x = r0, .y = r1 };
}

void OwEventProcess05_GetLayer1Tile() {  // 04ec78
  uint16 v0 = 21;
  uint16 tt = kChangingLayer1OverworldTiles_Layer1TileLocation[ow_current_event_number];
  uint8 v1 = g_ram[0xc800 + tt];
  while (v1 != kChangingLayer1OverworldTiles_TilesThatChange[v0]) {
    if ((--v0 & 0x8000) != 0) {
      pointer_overworld_event_process = 7;
      return;
    }
  }
  io_sound_ch3 = 1;
  ++pointer_overworld_event_process;
  ow_on_screen_xpos_of_current_event_tile = tt * 16;
  ow_on_screen_ypos_of_current_event_tile = tt & 0xf0;
  timer_destroy_tile_event_unknown = 28;
}

void OwEventProcess01_DestroyTileAnimation_04ED83() {  // 04ed83
  uint16 v0 = 21;
  uint8 v1 = g_ram[0xc800 + kChangingLayer1OverworldTiles_Layer1TileLocation[ow_current_event_number]];
  do {
    if (v1 == kChangingLayer1OverworldTiles_TilesThatChange[v0])
      break;
    --v0;
  } while (v0);
//  r14w = v0;
  int v2 = ow_current_event_number;
  uint16 r0w = kOwEventProcess01_DestroyTileAnimation_DATA_04D93D[v2];

  uint16 k = kChangingLayer1OverworldTiles_Layer1TileLocation[v2];
  blocks_map16_table_lo[k] = kChangingLayer1OverworldTiles_TilesToBecome[v0];

  const uint8 *p;
  if (HAS_LM_FEATURE(kLmFeature_DestroyTileAnims))
    p = LmHook_DestroyTileAnimation3(k);
  else
    p = kOverworldEventProcess01_DestroyTileAnimation_DATA_04ECD3 + 8 * v0;
      
  OwEventProcess01_DestroyTileAnimation_04EDE6(stripe_image_upload, r0w, p);
}

void OwEventProcess01_DestroyTileAnimation_04EDE6(uint16 k, uint16 r0w, const uint8 *p) {  // 04ede6
  uint16 v2 = r0w;
  *(uint16 *)&stripe_image_upload_data[k] = r0w;
  *(uint16 *)&stripe_image_upload_data[k + 8] = v2 + 0x2000;
  *(uint16 *)&stripe_image_upload_data[k + 2] = 768;
  *(uint16 *)&stripe_image_upload_data[k + 10] = 768;
  *(uint16 *)&stripe_image_upload_data[k + 4] = *(uint16 *)p;
  *(uint16 *)&stripe_image_upload_data[k + 12] = *(uint16 *)(p + 2);
  *(uint16 *)&stripe_image_upload_data[k + 6] = *(uint16 *)(p + 4);
  *(uint16 *)&stripe_image_upload_data[k + 14] = *(uint16 *)(p + 6);
  *(uint16 *)&stripe_image_upload_data[k + 16] = 255;
  stripe_image_upload = k + 16;
}

void OwEventProcess04_FadeInLayer2Tile_04EE30() {  // 04ee30
  uint16 v2;

  uint16 v0 = 4 * ow_starting_event_tile;
  int v1 = (uint16)(4 * ow_starting_event_tile) >> 1;
  uint16 r0w = kLayer2EventData_TileEntries[v1 + 1];
  LOBYTE(v2) = (uint16)(((uint16)(r0w & 0x1FFF) >> 1) + 0x3000) >> 8;
  HIBYTE(v2) = (uint16)(r0w & 0x1FFF) >> 1;
  uint16 r2w = v2;
  const uint8 *r12 = g_ram + 0x14000;
  if (kLayer2EventData_TileEntries[v1] < 0x900)
    v0 = BufferEventTileToStripeImageTable_Buffer6x6Tile(r0w, r2w, 0xffff, r12);
  else
    v0 = BufferEventTileToStripeImageTable_Buffer2x2Tile(r0w, r2w, 0xffff, r12);
  *(uint16 *)&stripe_image_upload_data[v0] = 255;
  stripe_image_upload = v0;
}

void OwEventProcess01_DestroyTileAnimation_04EEAA() {  // 04eeaa
  uint16 v2;
  const uint8 *p = kOverworldEventProcess01_DestroyTileAnimation_DATA_04EE7A + 8 * ow_destroy_tile_event_tile_index;
  uint16 r0w = kOwEventProcess01_DestroyTileAnimation_DATA_04E587[ow_destroy_tile_event_vramindex];
  uint16 r2 = 0;

  if (HAS_LM_FEATURE(kLmFeature_DestroyTileAnims)) {
    r2 = kCheckIfDestroyTileEventIsActive_DATA_04E5B6[ow_destroy_tile_event_vramindex];
    p = LmHook_DestroyTileAnimation3(r2);
  }

  uint16 v0 = stripe_image_upload;
  if (!sign16(ow_destroy_tile_event_tile_index - 3)) {
    v2 = r0w;
    *(uint16 *)&stripe_image_upload_data[v0] = r0w;
    v2 += 0x2000;
    *(uint16 *)&stripe_image_upload_data[v0 + 8] = v2;
    v2 = swap16(v2);
    v2 = HAS_LM_FEATURE(kLmFeature_DestroyTileAnims) ? LmHook_DestroyTileAnimation2(v2) : v2 + 32;
    v2 = swap16(v2);
    r0w = v2;
    *(uint16 *)&stripe_image_upload_data[v0 + 2] = 768;
    *(uint16 *)&stripe_image_upload_data[v0 + 10] = 768;
    *(uint16 *)&stripe_image_upload_data[v0 + 4] = *(uint16 *)(p + 0);
    *(uint16 *)&stripe_image_upload_data[v0 + 12] = *(uint16 *)(p + 2);
    *(uint16 *)&stripe_image_upload_data[v0 + 6] = *(uint16 *)(p + 4);
    *(uint16 *)&stripe_image_upload_data[v0 + 14] = *(uint16 *)(p + 6);
    v0 += 16;
    if (HAS_LM_FEATURE(kLmFeature_DestroyTileAnims))
      p = LmHook_DestroyTileAnimation3(LmHook_RemapDestroyTile(r2));
  }
  if (!HAS_LM_FEATURE(kLmFeature_DestroyTileAnims)) {
    p = kOverworldEventProcess01_DestroyTileAnimation_DATA_04EE7A + 
      (sign16(ow_destroy_tile_event_tile_index - 2) ? 8 * ow_destroy_tile_event_tile_index : 40);
  }
  OwEventProcess01_DestroyTileAnimation_04EDE6(v0, r0w, p);
}

void DrawFlyingSwitchBlocks() {  // 04f290
  int16 v8;

  if (switch_block_event_ejection_counter < 0xC) {
    if (!switch_block_event_wait_counter) {
      if (switch_block_event_ejection_counter < 8) {
        io_sound_ch3 = 28;
        uint8 r0 = 7;
        uint8 v0 = switch_block_event_blocks_thrown_ctr;
        do {
          uint8 *pt = (uint8 *)get_PointU16(ow_players_pos, player_current_characterx4);
          blocks_layer2_tiles_lo[v0 + 120] = *pt;
          blocks_layer2_tiles_lo[v0] = pt[1];
          blocks_layer2_tiles_lo[v0 + 160] = pt[2];
          blocks_layer2_tiles_lo[v0 + 40] = pt[3];
          blocks_layer2_tiles_lo[v0 + 200] = 0;
          blocks_layer2_tiles_lo[v0 + 80] = 0;
          blocks_layer2_tiles_lo[v0 + 240] = kDrawFlyingSwitchBlocks_XSpeed[r0];
          blocks_layer2_tiles_lo[v0 + 280] = kDrawFlyingSwitchBlocks_YSpeed[r0];
          blocks_layer2_tiles_lo[v0++ + 320] = -48;
          --r0;
        } while ((r0 & 0x80) == 0);
        if (v0 >= 0x28) {
          uint8 v3 = switch_block_event_oam_index + 32;
          if ((uint8)(switch_block_event_oam_index + 32) >= 0xA0)
            v3 = 0;
          switch_block_event_oam_index = v3;
          v0 = 0;
        }
        switch_block_event_blocks_thrown_ctr = v0;
      }
      switch_block_event_wait_counter = 16;
      ++switch_block_event_ejection_counter;
    }
    --switch_block_event_wait_counter;
    uint8 r15 = switch_block_event_oam_index;
    uint8 v4 = 0;
    do {
      uint16 r0w = DrawFlyingSwitchBlocks_04F39C(v4, 0);
      uint16 r2w = DrawFlyingSwitchBlocks_04F39C(v4 + 40, 2);
      DrawFlyingSwitchBlocks_04F39C(v4 + 80, 4);
      int8 v7 = blocks_layer2_tiles_lo[v4 + 320] + 1;
      if (v7 >= 64)
        v7 = 64;
      blocks_layer2_tiles_lo[v4 + 320] = v7;
      HIBYTE(v8) = blocks_layer2_tiles_lo[v4 + 80];
      LOBYTE(v8) = blocks_layer2_tiles_lo[v4 + 200];
      r2w += v8;
      if (!(HIBYTE(r0w) | HIBYTE(r2w))) {
        uint8 v9 = r15;
        OamEnt *oam = get_OamEnt(oam_buf, r15);
        oam[80].ypos = r2w;
        oam[80].xpos = r0w;
        oam[80].charnum = -26;
        oam[80].flags = (2 * (misc_color_of_palace_switch_pressed1 - 1)) | 0x30;
        sprites_oamtile_size_buffer[(v9 >> 2) + 80] = 2;
      }
      uint8 v11 = r15 + 4;
      if ((uint8)(r15 + 4) >= 0xA0)
        v11 = 0;
      r15 = v11;
      ++v4;
    } while (v4 < switch_block_event_blocks_thrown_ctr || switch_block_event_ejection_counter >= 5 && v4 < 0x28);
  } else {
    misc_color_of_palace_switch_pressed1 = 0;
  }
}

uint16 DrawFlyingSwitchBlocks_04F39C(uint8 k, uint8 j) {  // 04f39c
  uint16 sub = blocks_layer2_tiles_lo[k + 360] + (uint8)(16 * blocks_layer2_tiles_lo[k + 240]);
  blocks_layer2_tiles_lo[k + 360] = sub;
  uint16 spd = ((int8)blocks_layer2_tiles_lo[k + 240] >> 4) + (sub >> 8);
  uint16 pos = PAIR16(blocks_layer2_tiles_lo[k], blocks_layer2_tiles_lo[k + 120]) + spd;
  blocks_layer2_tiles_lo[k + 120] = pos;
  blocks_layer2_tiles_lo[k] = pos >> 8;
  return pos - *(uint16 *)((int8 *)&mirror_current_layer1_xpos + j) - 8;
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
    stripe_image_upload_data[v5--] = kOwLifeExchangeTextTiles[(uint8)v4--];
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
  SpriteSlotData *ssd = (SpriteSlotData *)kLoadOverworldSprites_SpriteSlotData;
  do {
    int8 v2 = ssd[v1 - 3].field_0;
    owspr_spriteid[v0 + 3] = v2;
    if (v2 == 1 || v2 == 2)
      owspr_zpos_lo[v0 + 3] = 64;
    owspr_xpos_lo[v0 + 3] = ssd[v1 - 3].field_1;
    owspr_xpos_hi[v0 + 3] = HIBYTE(ssd[v1 - 3].field_1);
    owspr_ypos_lo[v0 + 3] = ssd[v1 - 3].field_3;
    owspr_ypos_hi[v0 + 3] = HIBYTE(ssd[v1 - 3].field_3);
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
    uint8 r0 = v11;
    do {
      uint8 r1 = v11;
      int v12 = *(&sprites_overworld_cloud_sync_table + r0);
      uint16 r2w = owspr_ypos_hi[v12] << 8 | owspr_ypos_lo[*(&sprites_overworld_cloud_sync_table + r0)];
      uint8 v13 = r1;
      uint8 v14 = *(&sprites_starting_oamindex_for_overworld_sprites + r1);
      HIBYTE(v15) = owspr_ypos_hi[v14];
      LOBYTE(v15) = owspr_ypos_lo[v14];
      if ((int16)(v15 - r2w) < 0) {
        uint8 v18 = *(&sprites_starting_oamindex_for_overworld_sprites + r1);
        uint8 v16 = r0;
        *(&sprites_starting_oamindex_for_overworld_sprites + r1) = *(&sprites_overworld_cloud_sync_table + r0);
        *(&sprites_overworld_cloud_sync_table + v16) = v18;
      }
      v11 = v13 - 1;
    } while (v11);
    v11 = r0 - 1;
  } while (v11);
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
  uint8 r0 = a;
  if (pointer_current_overworld_process == 10 && ow_submap_switch_process != 1)
    return 1;
  uint8 result = r0 & kCheckIfXIsAllowedOnYSubmap_ANDTable[ow_players_map[(uint8)player_current_characterx4 >> 2]];
  if (result)
    return 1;
  return result;
}

void OWSpr01_Lakitu(uint8 k) {  // 04f8cc
  UpdateOverworldSpritePosition(k);
  DrawOverworldSpriteShadow(k, 0);
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  uint16 r4w = pt.y;
  uint8 v2 = SetOverworldSpriteFrameIndex(k);
  uint8 v3 = ((v2 & 0x10) != 0) ? 7 : 6;
  do {
    pt.x += kOWSpr01_Lakitu_DATA_04F8A6[v3];
    uint32 t = r4w + kOWSpr01_Lakitu_DATA_04F8AE[v3];
    pt.y = t;
    OWSpr05_Cloud_04FB7B(0x3228, t >> 16, pt);
    v3 -= 2;
  } while ((int8)v3 >= 0);
  uint8 v5 = misc_which_file_to_erase;
  pt = GetOverworldSpriteOnScreenPosition(misc_which_file_to_erase);
  OWSpr05_Cloud_04FB7A(0x3226, pt);
  if (owspr_table0e15[v5]) {
    OWSpr01_Lakitu_CalculateOverworldLakitusSpeed(v5);
  } else {
    uint8 v6 = owspr_table0e05[v5] & 1;
    uint8 v7 = kOWSpr01_Lakitu_Acceleration[v6] + owspr_zspeed[v5];
    owspr_zspeed[v5] = v7;
    if (v7 == kOWSpr01_Lakitu_ZSpeedCap[v6])
      owspr_table0e05[v5] ^= 1;
    OwHvPos pos = CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(v5);
    bool less;
    uint8 j = owspr_table0df5[v5];
    int8 v8;
    if (((pos.r0 ^ (2 * *(uint16 *)&owspr_table0df5[v5 + 15])) & 0x8000) == 0 ||
        (v8 = 64, (less = pos.r6 < *(uint16 *)&kOWSpr01_Lakitu_DATA_04F8B6[j]))) {
      int16 v9 = pos.r2 ^ *(uint16 *)&owspr_table0df5[v5 + 15];
      if (!(v9 & 0x80))
        goto label1;
      less = pos.r8 < *(uint16 *)&kOWSpr01_Lakitu_DATA_04F8BE[j];
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
  OwHvPos pos = CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(k);
  uint8 v2 = kOWSpr01_Lakitu_Acceleration[(pos.r0 & 0x8000) == 0] + owspr_xspeed[k];
  if (v2 != kOWSpr01_Lakitu_XYSpeedCap[(pos.r0 & 0x8000) == 0])
    owspr_xspeed[k] = v2;
  PointU16 *pt1 = get_PointU16(ow_players_pos, player_current_characterx4);
  owspr_ypos_lo[k] = pt1->y;
  owspr_ypos_hi[k] = HIBYTE(pt1->y);
  UpdateOverworldSpritePosition(k);
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  int8 v4 = 54;
  if ((owspr_xspeed[k] & 0x80) == 0)
    v4 = 118;
  int8 v10 = v4;
  HIBYTE(v5) = v4;
  LOBYTE(v5) = 76;
  OWSpr05_Cloud_04FB7A(v5, pt);
  HIBYTE(v7) = v10;
  uint8 v6 = (SetOverworldSpriteFrameIndex(k) >> 3) & 3;
  LOBYTE(v7) = kOWSpr02_BlueBird_DATA_04F9AC[v6];
  if ((owspr_xspeed[k] & 0x80) == 0)
    LOBYTE(v7) = kOWSpr02_BlueBird_DATA_04F9B0[v6];
  pt.x += (uint8)v7;
  pt.y += kOWSpr02_BlueBird_DATA_04F9B4[v6];
  LOBYTE(v7) = kOWSpr02_BlueBird_DATA_04F9A8[v6];
  OWSpr05_Cloud_04FB7B(v7, 0, pt);
}

static const uint8 kOWSpr03_CheepCheep_DATA_04FA2E[3] = { 0x70, 0x50, 0xb0,  };
static const uint8 kOWSpr03_CheepCheep_DATA_04FA31[3] = { 0x0, 0x1, 0x0,  };
static const uint8 kOWSpr03_CheepCheep_DATA_04FA34[3] = { 0xcf, 0x8f, 0x7f,  };
static const uint8 kOWSpr03_CheepCheep_DATA_04FA37[3] = { 0x0, 0x0, 0x1,  };
static const uint8 kOWSpr03_CheepCheep_DATA_04FA3A[4] = { 0x73, 0x72, 0x63, 0x62,  };

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
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  uint8 v1 = owspr_table0df5[k];
  uint8 v2 = 8;
  if ((owspr_zspeed[k] & 0x80) != 0) {
    v1 ^= 0xC0;
    v2 = 16;
  }
  uint8 a = (counter_global_frames & v2) != 0 ? 0x48 : 0x4a;
  uint8 j = OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v1 << 8 | a, pt);
  pt.y += owspr_zpos_lo[k];
  pt.y -= 8;
  uint8 v6 = owspr_table0e25[k];
  if (v6) {
    v6 = kOWSpr03_CheepCheep_DATA_04FA3A[v6 >> 2];
    j = OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(j, 0x36 << 8 | v6, pt);
    pt.x += 8;
    OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(j, 0x76 << 8 | v6, pt);
  }
}

uint8 OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(uint8 j, uint16 a, PointU16 pt) {  // 04faed
  return OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(j, a, 0, pt);
}

void OWSpr04_PiranhaPlant(uint8 k) {  // 04faf1
  uint16 v2;

  CheckPlayerToOverworldSpriteCollision(k);
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  int8 v1 = 42;
  if ((SetOverworldSpriteFrameIndex(k) & 8) != 0)
    v1 = 44;
  HIBYTE(v2) = 50;
  LOBYTE(v2) = v1;
  OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v2, pt);
}

uint8 OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(uint8 k, uint16 a, PointU16 pt) {  // 04fb06
  return OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(kOverworldSpriteOAMIndexes[k], a, 1, pt);
}

uint8 OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(uint8 j, uint16 a, uint8 cr, PointU16 pt) {  // 04fb0a
  OamEnt *oam = get_OamEnt(oam_buf, j);
  *(uint16 *)&oam[16].charnum = a;
  if (pt.x < 256) {
    oam[16].xpos = pt.x;
    if (pt.y < 256) {
      oam[16].ypos = pt.y;
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
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  bool v1 = (uint16)(pt.x + 32) >= 0x140;
  if ((uint16)(pt.x + 32) < 0x140)
    v1 = (uint16)(pt.y + 128) >= 0x1A0;
  if (v1)
    owspr_spriteid[k] = 0;
  OWSpr05_Cloud_04FB77(0x32, pt);
  pt.x += 16;
  OWSpr05_Cloud_04FB77(0x72, pt);
}

void OWSpr05_Cloud_04FB77(uint8 a, PointU16 pt) {  // 04fb77
  uint16 v1;

  HIBYTE(v1) = a;
  LOBYTE(v1) = 68;
  OWSpr05_Cloud_04FB7B(v1, 1, pt);
}

void OWSpr05_Cloud_04FB7A(uint16 a, PointU16 pt) {  // 04fb7a
  OWSpr05_Cloud_04FB7B(a, 1, pt);
}

void OWSpr05_Cloud_04FB7B(uint16 a, uint8 cr, PointU16 pt) {  // 04fb7b
  sprites_starting_oamindex_for_overworld_sprites =
      OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(sprites_starting_oamindex_for_overworld_sprites, a, cr, pt);
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
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
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
  OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v5, pt);
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
  owspr_ypos_lo[k] = kOWSpr07_Smoke_DATA_04FC1E[v1 + 2];
  owspr_ypos_hi[k] = HIBYTE(kOWSpr07_Smoke_DATA_04FC1E[v1 + 2]);
  if ((counter_global_frames & 0xF) == 0) {
    uint8 v2 = owspr_table0df5[k] + 1;
    if (v2 >= 0xC)
      v2 = 0;
    owspr_table0df5[k] = v2;
  }
  uint8 r4 = 3;
  uint8 r6 = counter_global_frames;
  uint8 r7 = 0;
  uint8 v3 = kOverworldSpriteOAMIndexes[k];
  uint8 v4 = owspr_table0df5[k];
  do {
    uint8 j = v3;
    PointU16 pt = GetOverworldSpriteOnScreenPosition(misc_which_file_to_erase);
    uint8 v5 = kOWSpr07_Smoke_DATA_04FC36[v4] + r7;
    pt.y += ~0xff | v5;
    pt.x += kOWSpr07_Smoke_DATA_04FC26[v4];
    uint8 t = v4 + 12;
    v4 = t & 0xF;
    if (t >= 0x10)
      r7 -= 12;
    HIBYTE(v7) = 48;
    int8 v8 = 40;
    r6 += 10;
    if ((r6 & 0x20) != 0)
      v8 = 95;
    LOBYTE(v7) = v8;
    v3 = OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(j, v7, pt);
    --r4;
  } while (r4);
}

void OWSpr08_BowserSign(uint8 k) {  // 04fce1
  uint16 v2;

  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  uint8 r4 = 4;
  uint8 r5 = 111;
  uint8 v1 = kOverworldSpriteOAMIndexes[k];
  do {
    HIBYTE(v2) = (counter_global_frames >> 1) & 6 | 0x30;
    LOBYTE(v2) = r5;
    v1 = OWSpr03_CheepCheep_GenericOverworldSpriteGFXRt_Draw8x8(v1, v2, pt);
    BYTE(pt.x) -= 8;
    --r5;
    --r4;
  } while (r4);
}

void OWSpr09_Bowser(uint8 k) {  // 04fd24
  uint16 v2;

  UpdateOverworldSpritePosition(k);
  GetOverworldSpriteOnScreenPosition(k);
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  int8 v1 = 0;
  if ((owspr_xspeed[k] & 0x80) == 0)
    v1 = 64;
  HIBYTE(v2) = v1;
  LOBYTE(v2) = 104;
  OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v2, pt);
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
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  if (ow_players_map[player_current_character]) {
    if (k == 15 && (ow_event_flags[5] & 0x12) == 0)
      HIBYTE(pt.y) = 15;
    pt.x += kLoadOverworldSprites_SubmapBooXPosOffset[k - 13];
    pt.y += kLoadOverworldSprites_SubmapBooYPosOffset[k - 13];
  }
  int8 v1 = 52;
  if ((owspr_xspeed[k] & 0x80) == 0)
    v1 = 68;
  HIBYTE(v2) = v1;
  LOBYTE(v2) = 96;

  OWSpr04_PiranhaPlant_GenericOverworldSpriteDraw(k, v2, pt);
  uint8 r0 = owspr_table0e25[k]++;
  OWSpr0A_Boo_04FDD2(k + 32, 8, r0);
  OWSpr0A_Boo_04FDD2(k + 16, 6, r0);
  OWSpr0A_Boo_04FDD2(misc_which_file_to_erase, 4, r0);
}

void OWSpr0A_Boo_04FDD2(uint8 k, uint8 a, uint8 r0) {  // 04fdd2
  uint8 v2 = owspr_table0df5[k] | a;
  if ((r0 & kOWSpr09_Bowser_DATA_04FD0A[v2 - 4]) != 0)
    owspr_table0df5[k] = v2;
  else
    OWSpr09_Bowser_04FD55(k, v2);
}

void DrawOverworldSpriteShadow(uint8 k, uint8 cr) {  // 04fe00
  uint8 r4 = cr ? 0x80 : 0;
  PointU16 pt = GetOverworldSpriteOnScreenPosition(k);
  pt.y += owspr_zpos_lo[k];
  uint8 v3 = owspr_zpos_lo[k] >> 4;
  uint8 v4 = 41;
  if ((r4 & 0x80) != 0) {
    v4 = 46;
    v3 += 8;
  }
  uint8 r5 = v4;
  pt.x += kDrawOverworldSpriteShadow_LeftTileXDisp[v3];
  uint8 j = DrawOverworldSpriteShadow_04FE45(kOverworldSpriteOAMIndexes[k], 0x32, pt, r4, r5);
  pt.x += kDrawOverworldSpriteShadow_RightTileXDisp[v3];
  DrawOverworldSpriteShadow_04FE45(j, 0x72, pt, r4, r5);
}

uint8 DrawOverworldSpriteShadow_04FE45(uint8 j, uint8 a, PointU16 pt, uint8 r4, uint8 r5) {  // 04fe45
  return OWSpr04_PiranhaPlant_GenericOverworldSpriteGFXRt_Entry2(j, r5 | a << 8, __CFSHL__(r4, 1), pt);
}

uint8 SetOverworldSpriteFrameIndex(uint8 k) {  // 04fe5b
  return kSetOverworldSpriteFrameIndex_DATA_04F833[k] + counter_global_frames;
}

PointU16 GetOverworldSpriteOnScreenPosition(uint8 k) {  // 04fe62
  uint16 r2w = GetOverworldSpriteOnScreenPosition_Y(k + 16, 2);
  r2w -= owspr_zpos_lo[misc_which_file_to_erase];
  uint16 r0w = GetOverworldSpriteOnScreenPosition_Y(misc_which_file_to_erase, 0);
  return (PointU16) { .x = r0w, .y = r2w };
}

uint16 GetOverworldSpriteOnScreenPosition_Y(uint8 k, uint8 j) {  // 04fe7d
  int16 v2;
  HIBYTE(v2) = owspr_xpos_hi[k];
  LOBYTE(v2) = owspr_xpos_lo[k];

  return v2 - *(uint16 *)((int8 *)&mirror_current_layer1_xpos + j);
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
  OwHvPos pos = CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(k);
  bool v1 = pos.r6 >= 8;
  if (pos.r6 < 8)
    v1 = pos.r8 >= 8;
  if (pos.r6 < 8 && !v1)
    ow_enter_level_flag = k;
  return v1;
}

OwHvPos CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(uint8 k) {  // 04feef
  int16 v1;
  int16 v3;

  HIBYTE(v1) = owspr_xpos_hi[k];
  LOBYTE(v1) = owspr_xpos_lo[k];
  int16 v2 = v1 + 8 - get_PointU16(ow_players_pos, player_current_characterx4)->x;
  uint16 r0w = v2;

  if (v2 < 0)
    v2 = -v2;
  HIBYTE(v3) = owspr_ypos_hi[k];
  LOBYTE(v3) = owspr_ypos_lo[k];
  int16 v4 = v3 + 8 - get_PointU16(ow_players_pos, player_current_characterx4)->y;
  uint16 r2w = v4;
  if (v4 < 0)
    v4 = -v4;
  uint16 r8w = v4;
  return (OwHvPos) { .r0 = r0w, .r2 = r2w, .r6 = v2, .r8 = r8w };
}

void OWSpr01_Lakitu_CalculateOverworldLakitusSpeed(uint8 k) {  // 04ff2e
  int16 v4;

  OwHvPos pos = CheckPlayerToOverworldSpriteColl_SubOverworldHorizAndVertPos(k);
  uint8 v1 = owspr_zpos_lo[k] >> 1;

  uint16 arr[3] = {
    pos.r6 >> 1,
    pos.r8 >> 1,
    v1,
  };

  uint8 sign_arr[3] = { pos.r0 >> 8, pos.r2 >> 8, 0 };

  uint8 v2 = 4;
  if (v1 < arr[1]) {
    v2 = 2;
    v1 = arr[1];
  }
  if (v1 < arr[0]) {
    v2 = 0;
    v1 = arr[0];
  }
  if (v1) {
    uint8 r12 = v2;
    uint8 out_arr[3];
    for (uint8 i = 4; (i & 0x80) == 0; i -= 2) {
      if (i == r12) {
        LOBYTE(v4) = 32;
      } else {
        v4 = SnesDivide(arr[i >> 1] << 8, arr[r12 >> 1]) >> 3;
      }
      if (!(sign_arr[i >> 1] & 0x80))
        LOBYTE(v4) = -(int8)v4;
      out_arr[i >> 1] = v4;
    }
    int v6 = misc_which_file_to_erase;
    owspr_xspeed[v6] = out_arr[0];
    owspr_yspeed[v6] = out_arr[1];
    owspr_zspeed[v6] = out_arr[2];
  } else {
    owspr_table0e15[k] = 0;
    owspr_xspeed[k] = 0;
    owspr_yspeed[k] = 0;
    owspr_zspeed[k] = 0;
    owspr_zpos_lo[k] = 64;
  }
}
