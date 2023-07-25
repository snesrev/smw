#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"
#include "assets/smw_assets.h"

static FuncV *const kInitAndMainLoop_GameModePtrs[42] = {
    &GameMode00_LoadNintendoPresents,
    &GameMode01_ShowNintendoPresents,
    &GameModeXX_FadeInOrOut,
    &GameMode11_LoadSublevel_GameMode03Entry,
    &GameMode04_PrepareTitleScreen,
    &GameModeXX_FadeInOrOut,
    &GameMode06_CircleEffect,
    &GameMode07_TitleScreenDemo,
    &GameMode08_FileSelect,
    &GameMode09_EraseFile,
    &GameMode0A_PlayerSelect,
    &GameModeXX_FadeInOrOut,
    &GameMode0C_LoadOverworld,
    &GameModeXX_FadeInOrOut,
    &GameMode0E_ShowOverworld,
    &GameModeXX_FadeInOrOut_MosaicFade,
    &GameMode10_BufferLevelLoadMessage,
    &GameMode11_LoadSublevel_0096D5,
    &GameMode12_PrepareLevel,
    &GameModeXX_FadeInOrOut_MosaicFade,
    &GameMode14_InLevel,
    &GameModeXX_FadeInOrOut,
    &GameMode16_LoadDeathMessage,
    &GameMode17_ShowDeathMessage,
    &GameModeXX_FadeInOrOut,
    &GameMode19_Cutscene,
    &GameModeXX_FadeInOrOut,
    &GameMode19_Cutscene_GameMode1BEntry,
    &GameModeXX_FadeInOrOut,
    &GameMode1D_LoadYoshisHouse,
    &GameModeXX_FadeInOrOut,
    &GameMode1D_LoadYoshisHouse_GameMode1FEntry,
    &GameModeXX_FadeInOrOut,
    &GameMode21_DelayEnemyRollcall,
    &GameModeXX_FadeInOrOut,
    &GameMode23_LoadEnemyRollcallScreen,
    &GameModeXX_FadeInOrOut,
    &GameMode25_ShowEnemyRollcallScreen,
    &GameModeXX_FadeInOrOut,
    &GameMode27_LoadTheEnd,
    &GameMode28_ShowTheEnd,
    &GameMode29_DoNothingOnTheEndScreen,
};

typedef void TileGenFunc(GenTileArgs *gta);
static TileGenFunc *const kGenerateTile_TileGenerationPtr[27] = {
    &sub_C074,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &sub_C077,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile,
    &GenericPage01Tile_SetItemMemory,
    &GenericPage01Tile_SetItemMemory,
    &EraseYoshiCoin,
    &ChangeNetDoorTiles,
    &ChangeNetDoorTiles,
    &EraseLargeSwitch,
};
static FuncV *const kGameMode14_InLevel_PlayerStatePtrs[14] = {
    &PlayerState00,
    &PlayerStateXX_PowerupAnims_PowerDownEntry,
    &PlayerStateXX_PowerupAnims_GrowAnimationEntry,
    &PlayerStateXX_PowerupAnims_GotCape,
    &PlayerStateXX_PowerupAnims_GotFlower,
    &PlayerStateXX_EnterPipe_Horizontal,
    &PlayerStateXX_EnterPipe_Vertical,
    &PlayerState07_ShootOutOfPipe,
    &PlayerState08_WarpToYoshiWingsBonus,
    &PlayerState09_Death,
    &PlayerState0A_NoYoshiCutscene,
    &PlayerState0B_RescuedPeach,
    &PlayerState0C_CastleDestructionMoves,
    &GameMode14_InLevel_Return00C592,
};

static const uint8 kCompressOAMTileSizeBuffer_DATA_008475[31] = { 0x0, 0x0, 0x8, 0x0, 0x10, 0x0, 0x18, 0x0, 0x20, 0x0, 0x28, 0x0, 0x30, 0x0, 0x38, 0x0, 0x40, 0x0, 0x48, 0x0, 0x50, 0x0, 0x58, 0x0, 0x60, 0x0, 0x68, 0x0, 0x70, 0x0, 0x78,  };
static const uint16 kManipulateMode7Image_DATA_008AB4[4] = { 0x0, 0xfe, 0x0, 0xfe,  };
static const uint16 kManipulateMode7Image_DATA_008ABC[4] = { 0x0, 0x2, 0x0, 0x2,  };
static const uint16 kManipulateMode7Image_DATA_008B57[149] = { 0x0, 0x3, 0x6, 0x9, 0xc, 0xf, 0x12, 0x15, 0x19, 0x1c, 0x1f, 0x22, 0x25, 0x28, 0x2b, 0x2e, 0x31, 0x35, 0x38, 0x3b, 0x3e, 0x41, 0x44, 0x47, 0x4a, 0x4d, 0x50, 0x53, 0x56, 0x59, 0x5c, 0x5f, 0x61, 0x64, 0x67, 0x6a, 0x6d, 0x70, 0x73, 0x75, 0x78, 0x7b, 0x7e, 0x80, 0x83, 0x86, 0x88, 0x8b, 0x8e, 0x90, 0x93, 0x95, 0x98, 0x9b, 0x9d, 0x9f, 0xa2, 0xa4, 0xa7, 0xa9, 0xab, 0xae, 0xb0, 0xb2, 0xb5, 0xb7, 0xb9, 0xbb, 0xbd, 0xbf, 0xc1, 0xc3, 0xc5, 0xc7, 0xc9, 0xcb, 0xcd, 0xcf, 0xd1, 0xd3, 0xd4, 0xd6, 0xd8, 0xd9, 0xdb, 0xdd, 0xde, 0xe0, 0xe1, 0xe3, 0xe4, 0xe6, 0xe7, 0xe8, 0xea, 0xeb, 0xec, 0xed, 0xee, 0xef, 0xf1, 0xf2, 0xf3, 0xf4, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xf9, 0xfa, 0xfb, 0xfb, 0xfc, 0xfc, 0xfd, 0xfd, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x100, 0x3cb7, 0xbcb7, 0x3cb8, 0x3cb9, 0x3cba, 0x3cbb, 0x3cba, 0xbcba, 0x3cbc, 0x3cbd, 0x3cbe, 0x3cbf, 0x3cc0, 0xbcb7, 0x3cc1, 0x3cb9, 0x3cc2, 0xbcc2, 0x3cb7, 0xfcc0,  };
static const uint8 kStatusBarTilemap_SecondRow[118] = { 0x30, 0x28, 0x31, 0x28, 0x32, 0x28, 0x33, 0x28, 0x34, 0x28, 0xfc, 0x38, 0xfc, 0x3c, 0xfc, 0x3c, 0xfc, 0x3c, 0xfc, 0x3c, 0xfc, 0x38, 0xfc, 0x38, 0x4a, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0x4a, 0x78, 0xfc, 0x38, 0x3d, 0x3c, 0x3e, 0x3c, 0x3f, 0x3c, 0xfc, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0x2e, 0x3c, 0x26, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0x0, 0x38, 0x26, 0x38, 0xfc, 0x38, 0x0, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0x64, 0x28, 0x26, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0x4a, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0x4a, 0x78, 0xfc, 0x38, 0xfe, 0x3c, 0xfe, 0x3c, 0x0, 0x3c, 0xfc, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0xfc, 0x38, 0x0, 0x38, 0x3a, 0xb8, 0x3b, 0xb8, 0x3b, 0xb8, 0x3a, 0xf8,  };
static const uint8 kUpdateStatusBarCounters_DATA_008DF5[5] = { 0x40, 0x41, 0x42, 0x43, 0x44,  };
static const uint8 kUpdateStatusBarCounters_ItemBoxItemTile[4] = { 0x24, 0x26, 0x48, 0xe,  };
static const uint8 kUpdateStatusBarCounters_StarPaletteFrames[4] = { 0x0, 0x2, 0x4, 0x2,  };
static const uint8 kUpdateStatusBarCounters_ItemBoxItemProperties[4] = { 0x8, 0xa, 0x0, 0x4,  };
static const uint8 kUpdateStatusBarCounters_BonusStarCounterNumberTiles[20] = { 0xb7, 0xc3, 0xb8, 0xb9, 0xba, 0xbb, 0xba, 0xbf, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0, 0xc3, 0xc1, 0xb9, 0xc2, 0xc4, 0xb7, 0xc5,  };
static const uint16 kUpdateStatusBarCounters_DATA_008FFA[12] = { 0x1, 0x86a0, 0x0, 0x2710, 0x0, 0x3e8, 0x0, 0x64, 0x0, 0xa, 0x0, 0x1,  };

static const uint8 kGameMode00_LoadNintendoPresents_XDisp[4] = { 0x60, 0x70, 0x80, 0x90,  };
static const uint8 kGameMode00_LoadNintendoPresents_Tiles[4] = { 0x2, 0x4, 0x6, 0x8,  };
const uint8 kGameMode19_Cutscene_SkyColorSetting[8] = { 0x2, 0x0, 0x4, 0x1, 0x0, 0x6, 0x4, 0x3,  };
static const uint8 kGameMode19_Cutscene_BGPaletteSetting[8] = { 0x6, 0x5, 0x6, 0x3, 0x3, 0x6, 0x6, 0x3,  };
static const uint8 kGameMode19_Cutscene_BGToUse[7] = { 0xff, 0xff, 0xc9, 0xf, 0xff, 0xcc, 0xc9,  };
static const uint16 kUploadMode7KoopaBossesAndLavaAnimation_VRAMAddressToUpload[12] = { 0x129e, 0x121e, 0x119e, 0x111e, 0x161e, 0x159e, 0x151e, 0x149e, 0x141e, 0x139e, 0x131e, 0x169e,  };
static const uint8 kHandleMenuCursor_DATA_009AC8[3] = { 0x1, 0xff, 0xff,  };
static const uint8 kGameMode09_EraseFile_DATA_009B17[3] = { 0x4, 0x2, 0x1,  };
// todo: oob
static const uint8 kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[70] = { 0x41, 0xf, 0xc1, 0x30, 0x0, 0x10, 0x42, 0x20, 0x41, 0x70, 0x81, 0x11, 0x0, 0x80, 0x82, 0xc, 0x0, 0x30, 0xc1, 0x30, 0x41, 0x60, 0xc1, 0x10, 0x0, 0x40, 0x1, 0x30, 0xe1, 0x1, 0x0, 0x60, 0x41, 0x4e, 0x80, 0x10, 0x0, 0x30, 0x41, 0x58, 0x0, 0x20, 0x60, 0x1, 0x0, 0x30, 0x60, 0x1, 0x0, 0x30, 0x60, 0x1, 0x0, 0x30, 0x60, 0x1, 0x0, 0x30, 0x60, 0x1, 0x0, 0x30, 0x41, 0x1a, 0xc1, 0x30, 0x0, 0x30, 0xff, 0x20 };
static const uint8 kSaveFileLocations_Hi[3] = { 0x0, 0x0, 0x1,  };
static const uint8 kSaveFileLocations_Lo[3] = { 0x0, 0x8f, 0x1e,  };
static const uint16 kHandleMenuCursor_DATA_009E6A[5] = { 0x2, 0x4, 0x2, 0x2, 0x4,  };
static const uint16 kHandleMenuCursor_DATA_009E74[5] = { 0x51cb, 0x51e8, 0x5208, 0x51c4, 0x51e5,  };
static const uint8 kHandleMenuCursor_DATA_009E7E[4] = { 0x1, 0x2, 0x4, 0x8,  };
static const uint16 kInitializeSaveData_InitialLevelFlags[8] = { 0x328, 0x14d, 0x152, 0x153, 0x85b, 0x25c, 0x457, 0x130,  };
const uint8 kGameModeXX_FadeInOrOut_DATA_009F2F[2] = { 0x1, 0xff,  };
const uint8 kGameModeXX_FadeInOrOut_DATA_009F31[2] = { 0xf0, 0x10,  };
const uint8 kGameModeXX_FadeInOrOut_DATA_009F33[2] = { 0xf, 0x0,  };
static const uint8 kInitializeLevelLayer3_DATA_009F88[48] = { 0x1, 0x2, 0xc0, 0x1, 0x80, 0x81, 0x1, 0x2, 0xc0, 0x1, 0x2, 0x81, 0x1, 0x2, 0x80, 0x1, 0x2, 0x81, 0x1, 0x2, 0x81, 0x1, 0x2, 0xc0, 0x1, 0x2, 0xc0, 0x1, 0x2, 0x81, 0x1, 0x2, 0x80, 0x1, 0x2, 0x80, 0x1, 0x2, 0x80, 0x1, 0x2, 0x81, 0x1, 0x2, 0x81, 0x1, 0x2, 0x80,  };
static const uint16 kGameMode0C_LoadOverworld_DATA_00A06B[7] = { 0x0, 0xffef, 0xffef, 0xffef, 0xf0, 0xf0, 0xf0,  };
static const uint16 kGameMode0C_LoadOverworld_DATA_00A079[7] = { 0x0, 0xffd8, 0x80, 0x128, 0xffd8, 0x80, 0x128,  };
static const uint8 kGameMode14_InLevel_GrndShakeDispYLo[4] = { 0xfe, 0x0, 0x2, 0x0,  };
static const uint8 kGameMode14_InLevel_GrndShakeDispYHi[4] = { 0xff, 0x0, 0x0, 0x0,  };
static const uint8 kUploadOverworldLayer1And2Tilemaps_DATA_00A521[4] = { 0x0, 0x4, 0x8, 0xc,  };
static const uint8 kUploadOverworldLayer1And2Tilemaps_DATA_00A525[4] = { 0x0, 0x8, 0x10, 0x18,  };
static const uint8 kInitializeLevelRAM_DATA_00A60D[4] = { 0x0, 0x1, 0x1, 0x1,  };
static const uint16 kInitializeLevelRAM_DATA_00A611[4] = { 0xd, 0xfff3, 0xfffe, 0xfffe,  };
static const uint16 kInitializeLevelRAM_DATA_00A619[4] = { 0x0, 0x0, 0xa, 0  };
static const uint8 kInitializeLevelRAM_DATA_00A621[4] = { 0x1A,0x1A, 0xA, 0xA,  };
static const uint8 kInitializeLevelRAM_DATA_00A625[16] = { 0x0, 0x80, 0x40, 0x0, 0x1, 0x2, 0x40, 0x0, 0x40, 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x0,  };
static const uint8 kUploadGraphicsFiles_SpriteGFXList[104] = {
  0x0, 0x1, 0x13, 0x2,
  0x0, 0x1, 0x12, 0x3,
  0x0, 0x1, 0x13, 0x5,
  0x0, 0x1, 0x13, 0x4,
  0x0, 0x1, 0x13, 0x6,
  0x0, 0x1, 0x13, 0x9,
  0x0, 0x1, 0x13, 0x4, 0x0, 0x1, 0x6, 0x11, 0x0, 0x1, 0x13, 0x20, 0x0, 0x1, 0x13, 0xf, 0x0, 0x1, 0x13, 0x23, 0x0, 0x1, 0xd, 0x14, 0x0, 0x1, 0x24, 0xe, 0x0, 0x1, 0xa, 0x22, 0x0, 0x1, 0x13, 0xe, 0x0, 0x1, 0x13, 0x14, 0x0, 0x0, 0x0, 0x8, 0x10, 0xf, 0x1c, 0x1d, 0x0, 0x1, 0x24, 0x22, 0x0, 0x1, 0x25, 0x22, 0x0, 0x22, 0x13, 0x2d, 0x0, 0x1, 0xf, 0x22, 0x0, 0x26, 0x2e, 0x22, 0x21, 0xb, 0x25, 0xa, 0x0, 0xd, 0x24, 0x22, 0x2c, 0x30, 0x2d, 0xe,  };
static const uint8 kUploadGraphicsFiles_FGAndBGGFXList[104] = { 0x14, 0x17, 0x19, 0x15, 0x14, 0x17, 0x1b, 0x18, 0x14, 0x17, 0x1b, 0x16, 0x14, 0x17, 0xc, 0x1a, 0x14, 0x17, 0x1b, 0x8, 0x14, 0x17, 0xc, 0x7, 0x14, 0x17, 0xc, 0x16, 0x14, 0x17, 0x1b, 0x15, 0x14, 0x17, 0x19, 0x16, 0x14, 0x17, 0xd, 0x1a, 0x14, 0x17, 0x1b, 0x8, 0x14, 0x17, 0x1b, 0x18, 0x14, 0x17, 0x19, 0x1f, 0x14, 0x17, 0xd, 0x7, 0x14, 0x17, 0x19, 0x1a, 0x14, 0x17, 0x14, 0x14, 0xe, 0xf, 0x17, 0x17, 0x1c, 0x1d, 0x8, 0x1e, 0x1c, 0x1d, 0x8, 0x1e, 0x1c, 0x1d, 0x8, 0x1e, 0x1c, 0x1d, 0x8, 0x1e, 0x1c, 0x1d, 0x8, 0x1e, 0x1c, 0x1d, 0x8, 0x1e, 0x1c, 0x1d, 0x8, 0x1e, 0x14, 0x17, 0x19, 0x2c, 0x19, 0x17, 0x1b, 0x18,  };
static const uint8 kUploadGraphicsFiles_DATA_00A9D2[4] = { 0x78, 0x70, 0x68, 0x60,  };
static const uint8 kBufferPalettesRoutines_DATA_00ABD3[12] = { 0x0, 0x18, 0x30, 0x48, 0x60, 0x78, 0x90, 0xa8, 0x0, 0x14, 0x28, 0x3c,  };
static const uint8 kBufferPalettesRoutines_DATA_00AD1E[7] = { 0x1, 0x0, 0x3, 0x4, 0x3, 0x5, 0x2,  };
static const uint8 kUpdatePaletteFromIndexedTable_DATA_00AE41[3] = { 0x0, 0x5, 0xa,  };
static const uint8 kUpdatePaletteFromIndexedTable_DATA_00AE44[3] = { 0x20, 0x40, 0x80,  };
static const uint16 kHandlePaletteFades_DATA_00AE65[3] = { 0x1f, 0x3e0, 0x7c00,  };
static const uint16 kHandlePaletteFades_DATA_00AE6B[3] = { 0xffff, 0xffe0, 0xfc00,  };
static const uint16 kHandlePaletteFades_DATA_00AE71[3] = { 0x1, 0x20, 0x400,  };
static const uint16 kHandlePaletteFades_DATA_00AE77[64] = { 0x0, 0x0, 0x1, 0x0, 0x8000, 0x8000, 0x8020, 0x400, 0x8080, 0x8080, 0x8208, 0x1040, 0x8420, 0x8420, 0x8844, 0x2210, 0x8888, 0x8888, 0x9122, 0x4488, 0x9248, 0x9248, 0xa492, 0x4924, 0xa4a4, 0xa4a4, 0xa949, 0x5294, 0xaaaa, 0x5294, 0xaaaa, 0x5554, 0xaaaa, 0xaaaa, 0xd5aa, 0xaaaa, 0xd5aa, 0xd5aa, 0xd6b5, 0xad6a, 0xdada, 0xdada, 0xdb6d, 0xb6da, 0xedb6, 0xedb6, 0xeedd, 0xbb76, 0xeeee, 0xeeee, 0xf7bb, 0xddee, 0xfbde, 0xfbde, 0xfdf7, 0xefbe, 0xfefe, 0xfefe, 0xffdf, 0xfbfe, 0xfffe, 0xfffe, 0xffff, 0xfffe,  };
static const uint16 kHandlePaletteFades_DATA_00AEF7[16] = { 0x8000, 0x4000, 0x2000, 0x1000, 0x800, 0x400, 0x200, 0x100, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,  };
static const uint16 kGlobalPalettes_BowserEnd[6] = { 0x0, 0x63fb, 0x30c, 0x20b, 0x1535, 0x1a5f,  };
static const uint16 kGlobalPalettes_B3CC[6] = { 0x0, 0x3434, 0x443a, 0x659f, 0x116, 0x27f,  };
static const uint16 kGlobalPalettes_EndingLuigi[6] = { 0x44c4, 0x320, 0x4adf, 0x200, 0x13b, 0x4e08,  };
static const uint16 kGlobalPalettes_EndingMario[6] = { 0x44c4, 0x391f, 0x4adf, 0x2874, 0x13f, 0x4e08,  };
static const uint16 kGlobalPalettes_EndingToadstool[6] = { 0x28d2, 0x551e, 0x635f, 0x7b1f, 0x1fb, 0x2de,  };
static const uint16 kSetItemMemoryBit_DATA_00BFFF[3] = { 0x0, 0x80, 0x100,  };
static const uint8 kSetItemMemoryBit_DATA_00C005[8] = { 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,  };
static const uint8 kGenericPage00Tile_Map16Page00TileLo[9] = { 0x25, 0x25, 0x25, 0x6, 0x49, 0x48, 0x2b, 0xa2, 0xc6,  };
static const uint8 kGenericPage01Tile_Map16Page01TileLo[15] = { 0x52, 0x1b, 0x23, 0x1e, 0x32, 0x13, 0x15, 0x16, 0x2b, 0x2c, 0x12, 0x68, 0x69, 0x32, 0x5e,  };
static const uint8 kGameMode14_InLevel_DATA_00C470[4] = { 0x90, 0x0, 0x90, 0x0,  };
static const uint8 kGameMode14_InLevel_DATA_00C474[4] = { 0x4, 0xfc, 0x4, 0xfc,  };
static const uint8 kGameMode14_InLevel_DATA_00C478[6] = { 0x30, 0x33, 0x33, 0x30, 0x1, 0x0,  };
static const uint8 kPlayerState0C_CastleDestructionMoves_DATA_00C5E1[9] = { 0x10, 0x30, 0x31, 0x32, 0x33, 0x34, 0xe, 0x26, 0x11};
static const uint8 kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData[247] = { 0x26, 0x11, 0x2, 0x48, 0x0, 0x60, 0x1, 0x9, 0x80, 0x8, 0x0, 0x20, 0x4, 0x60, 0x0, 0x1, 0xff, 0x1, 0x2, 0x48, 0x0, 0x60, 0x41, 0x2c, 0xc1, 0x4, 0x27, 0x4, 0x2f, 0x8, 0x25, 0x1, 0x2f, 0x4, 0x27, 0x4, 0x0, 0x8, 0x41, 0x1b, 0xc1, 0x4, 0x27, 0x4, 0x2f, 0x8, 0x25, 0x1, 0x2f, 0x4, 0x27, 0x4, 0x0, 0x4, 0x1, 0x8, 0x20, 0x1, 0x1, 0x10, 0x0, 0x8, 0x41, 0x12, 0x81, 0xa, 0x0, 0x40, 0x82, 0x10, 0x2, 0x20, 0x0, 0x30, 0x1, 0x1, 0x0, 0x50, 0x22, 0x1, 0xff, 0x1, 0x2, 0x48, 0x0, 0x60, 0x1, 0x9, 0x80, 0x8, 0x0, 0x20, 0x4, 0x60, 0x0, 0x20, 0x10, 0x20, 0x1, 0x58, 0x0, 0x2c, 0x31, 0x1, 0x3a, 0x10, 0x31, 0x1, 0x3a, 0x10, 0x31, 0x1, 0x3a, 0x20, 0x28, 0xa0, 0x28, 0x40, 0x29, 0x4, 0x28, 0x4, 0x29, 0x4, 0x28, 0x4, 0x29, 0x4, 0x28, 0x40, 0x22, 0x1, 0xff, 0x1, 0x2, 0x48, 0x0, 0x60, 0x1, 0x9, 0x80, 0x8, 0x0, 0x20, 0x4, 0x60, 0x10, 0x20, 0x31, 0x1, 0x18, 0x60, 0x31, 0x1, 0x3b, 0x80, 0x31, 0x1, 0x3c, 0x40, 0xff, 0x1, 0x2, 0x48, 0x0, 0x60, 0x2, 0x30, 0x1, 0x84, 0x0, 0x20, 0x23, 0x1, 0x1, 0x16, 0x2, 0x20, 0x20, 0x1, 0x1, 0x20, 0x2, 0x20, 0x1, 0x2, 0x0, 0x80, 0xff, 0x1, 0x2, 0x48, 0x0, 0x60, 0x2, 0x28, 0x1, 0x83, 0x0, 0x28, 0x24, 0x1, 0x2, 0x1, 0x0, 0xff, 0x0, 0x40, 0x20, 0x1, 0x0, 0x40, 0x2, 0x60, 0x0, 0x30, 0xff, 0x1, 0x2, 0x48, 0x0, 0x60, 0x1, 0x4e, 0x0, 0x40, 0x26, 0x1, 0x0, 0x1e, 0x20, 0x1, 0x0, 0x20, 0x8, 0x10, 0x20, 0x1, 0x2d, 0x18, 0x0, 0xa0, 0x20, 0x1, 0x2e, 0x1, 0xff,  };
static const uint8 kPlayerState0C_CastleDestructionMoves_DATA_00C5E9[16] = { 0x11, 0x2, 0x48, 0x0, 0x60, 0x1, 0x9, 0x80, 0x8, 0x0, 0x20, 0x4, 0x60, 0x0, 0x1, 0xff,  };
static const uint8 kPlayerState0C_CastleDestructionMoves_UNK_00C6DF[8] = { 0x1, 0x0, 0x10, 0xa0, 0x84, 0x50, 0xbc, 0xd8,  };
static const uint16 kPlayerState08_WarpToYoshiWingsBonus_DATA_00C7F9[2] = { 0xffc0, 0xa0,  };
// todo: oob read
static const uint8 kPlayerState0A_NoYoshiCutscene_DATA_00C848[41] = { 0x1, 0x5f, 0x0, 0x30, 0x8, 0x30, 0x0, 0x20, 0x40, 0x1, 0x0, 0x30, 0x1, 0x80, 0xff, 0x1, 0x3f, 0x0, 0x30, 0x20, 0x1, 0x80, 0x6, 0x0, 0x3a, 0x1, 0x38, 0x0, 0x30, 0x8, 0x30, 0x0, 0x20, 0x40, 0x1, 0x0, 0x30, 0x1, 0x80, 0xff, 0x9c };
static const uint8 kPlayerState00_FreeMovementDebugPlayerSpeed[12] = { 0x0, 0x0, 0x0, 0x0, 0x2, 0x0, 0x6, 0x0, 0xfe, 0xff, 0xfa, 0xff,  };
static const uint8 kPlayerState_OnYoshiAnimations[4] = { 0x20, 0x21, 0x27, 0x28,  };
static const uint8 kSetPlayerPose_DATA_00CE79[6] = { 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,  };
static const uint8 kSetPlayerPose_DATA_00CE7F[26] = { 0x2c, 0x2c, 0x2c, 0x2b, 0x2b, 0x2c, 0x2c, 0x2b, 0x2b, 0x2c, 0x2d, 0x2a, 0x2a, 0x2d, 0x2d, 0x2a, 0x2a, 0x2d, 0x2d, 0x2a, 0x2a, 0x2d, 0x2e, 0x2a, 0x2a, 0x2e,  };
static const uint8 kSetPlayerPose_DATA_00CE99[8] = { 0x0, 0x0, 0x25, 0x44, 0x0, 0x0, 0xf, 0x45,  };
static const uint8 kSetPlayerPose_DATA_00CEA1[8] = { 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1,  };
static const uint8 kSetPlayerPose_DATA_00CEA9[8] = { 0x2, 0x7, 0x6, 0x9, 0x2, 0x7, 0x6, 0x9,  };
static const uint16 kInitializeCapeSwingOrNetPunch_DATA_00D034[4] = { 0xc, 0xfff4, 0x8, 0xfff8,  };
static const uint16 kInitializeCapeSwingOrNetPunch_DATA_00D03C[4] = { 0x10, 0x10, 0x2, 0x2,  };
static const uint8 kPlayerStateXX_PowerupAnims_GrowingAniImgs[12] = { 0x0, 0x3d, 0x0, 0x3d, 0x0, 0x3d, 0x46, 0x3d, 0x46, 0x3d, 0x46, 0x3d,  };
static const uint8 kPlayerStateXX_EnterPipe_PipeXSpeed[2] = { 0xf8, 0x8,  };
static const uint8 kPlayerStateXX_EnterPipe_PipeYSpeed[4] = { 0x0, 0x0, 0xf0, 0x10,  };
static const uint8 kPlayerStateXX_EnterPipe_HIDEPIPESETS[4] = { 0x0, 0x63, 0x1c, 0x0,  };
static const uint8 kPlayerStateXX_EnterPipe_PipeCntrBoundryX[2] = { 0xa, 0x6,  };
static const uint8 kPlayerStateXX_EnterPipe_PipeCntringSpeed[2] = { 0xff, 0x1,  };
static const uint8 kHandlePlayerPhysics_JumpHeightTable[16] = { 0xb0, 0xb6, 0xae, 0xb4, 0xab, 0xb2, 0xa9, 0xb0, 0xa6, 0xae, 0xa4, 0xab, 0xa1, 0xa9, 0x9f, 0xa6,  };
static const uint16 kHandlePlayerPhysics_DATA_00D2CD[30] = { 0xff00, 0x100, 0xff00, 0x100, 0xff00, 0x100, 0xfe80, 0xc0, 0xff40, 0x180, 0xfe00, 0x40, 0xffc0, 0x200, 0xfe00, 0x40, 0xfe00, 0x40, 0xffc0, 0x200, 0xffc0, 0x200, 0xfc00, 0xff00, 0x100, 0x400, 0xff00, 0x100, 0xff00, 0x100,  };
static const uint16 kHandlePlayerPhysics_DATA_00D309[30] = { 0xffe0, 0x20, 0xffe0, 0x20, 0xffe0, 0x20, 0xffc0, 0x20, 0xffe0, 0x40, 0xff80, 0x20, 0xffe0, 0x80, 0xff80, 0x20, 0xff80, 0x20, 0xffe0, 0x80, 0xffe0, 0x80, 0xfe00, 0xff80, 0x80, 0x200, 0xff00, 0x100, 0xff00, 0x100,  };
static const uint16 kHandlePlayerPhysics_MarioAccel[124] = { 0xfe80, 0xfe80, 0x180, 0x180, 0xfe80, 0xfe80, 0x180, 0x180, 0xfe80, 0xfe80, 0x180, 0x180, 0xfe80, 0xfe80, 0x140, 0x140, 0xfec0, 0xfec0, 0x180, 0x180, 0xfe80, 0xfe80, 0x100, 0x100, 0xff00, 0xff00, 0x180, 0x180, 0xfe80, 0xfe80, 0x100, 0x100, 0xfe80, 0xfe80, 0x100, 0x100, 0xff00, 0xff00, 0x180, 0x180, 0xff00, 0xff00, 0x180, 0x180, 0xfc00, 0xfc00, 0xfd00, 0xfd00, 0x300, 0x300, 0x400, 0x400, 0xfc00, 0xfc00, 0x600, 0x600, 0xfa00, 0xfa00, 0x400, 0x400, 0xff80, 0x80, 0xff00, 0x100, 0xfe80, 0x180, 0xfe80, 0xfe80, 0x180, 0x180, 0xfe80, 0x280, 0xfd80, 0xfb00, 0x280, 0x500, 0xfd80, 0xfb00, 0x280, 0x500, 0xfd80, 0xfb00, 0x280, 0x500, 0xfd40, 0xfa80, 0x240, 0x480, 0xfdc0, 0xfb80, 0x2c0, 0x580, 0xfd00, 0xfa00, 0x200, 0x400, 0xfe00, 0xfc00, 0x300, 0x600, 0xfd00, 0xfa00, 0x200, 0x400, 0xfd00, 0xfa00, 0x200, 0x400, 0xfe00, 0xfc00, 0x300, 0x600, 0xfe00, 0xfc00, 0x300, 0x600, 0xfd00, 0xfa00, 0xfd00, 0xfa00, 0x300, 0x600, 0x300, 0x600,  };
static const uint16 kHandlePlayerPhysics_DATA_00D43D[124] = { 0xff80, 0xfe80, 0x80, 0x180, 0xff80, 0xfe80, 0x80, 0x180, 0xff80, 0xfe80, 0x80, 0x180, 0xfe80, 0xfe80, 0x80, 0x140, 0xff80, 0xfec0, 0x180, 0x180, 0xfe80, 0xfe80, 0x80, 0x100, 0xff80, 0xff00, 0x180, 0x180, 0xfe80, 0xfe80, 0x80, 0x100, 0xfe80, 0xfe80, 0x80, 0x100, 0xff80, 0xff00, 0x180, 0x180, 0xff80, 0xff00, 0x180, 0x180, 0xfc00, 0xfc00, 0xfe00, 0xfd00, 0x300, 0x300, 0x400, 0x400, 0xfc00, 0xfc00, 0x80, 0x80, 0xff80, 0xff80, 0x400, 0x400, 0xff80, 0x80, 0xff00, 0x100, 0xfe80, 0x180, 0xfe80, 0xfe80, 0x180, 0x180, 0xfe80, 0x280, 0xffc0, 0xfd80, 0x40, 0x280, 0xffc0, 0xfd80, 0x40, 0x280, 0xffc0, 0xfd80, 0x40, 0x280, 0xff80, 0xfd40, 0x40, 0x240, 0xffc0, 0xfdc0, 0x80, 0x2c0, 0xfd00, 0xfd00, 0x40, 0x200, 0xffc0, 0xfe00, 0x300, 0x300, 0xfd00, 0xfd00, 0x40, 0x200, 0xfd00, 0xfd00, 0x40, 0x200, 0xffc0, 0xfe00, 0x300, 0x300, 0xffc0, 0xfe00, 0x300, 0x300, 0xfd00, 0xfd00, 0xfd00, 0xfd00, 0x300, 0x300, 0x300, 0x300,  };
static const uint8 kHandlePlayerPhysics_DATA_00D535[148] = { 0xec, 0x14, 0xdc, 0x24, 0xdc, 0x24, 0xd0, 0x30, 0xec, 0x14, 0xdc, 0x24, 0xdc, 0x24, 0xd0, 0x30, 0xec, 0x14, 0xdc, 0x24, 0xdc, 0x24, 0xd0, 0x30, 0xe8, 0x12, 0xdc, 0x20, 0xdc, 0x20, 0xd0, 0x2c, 0xee, 0x18, 0xe0, 0x24, 0xe0, 0x24, 0xd4, 0x30, 0xdc, 0x10, 0xdc, 0x1c, 0xdc, 0x1c, 0xd0, 0x28, 0xf0, 0x24, 0xe4, 0x24, 0xe4, 0x24, 0xd8, 0x30, 0xdc, 0x10, 0xdc, 0x1c, 0xdc, 0x1c, 0xd0, 0x28, 0xdc, 0x10, 0xdc, 0x1c, 0xdc, 0x1c, 0xd0, 0x28, 0xf0, 0x24, 0xe4, 0x24, 0xe4, 0x24, 0xd8, 0x30, 0xf0, 0x24, 0xe4, 0x24, 0xe4, 0x24, 0xd8, 0x30, 0xdc, 0xf0, 0xdc, 0xf8, 0xdc, 0xf8, 0xd0, 0xfc, 0x10, 0x24, 0x8, 0x24, 0x8, 0x24, 0x4, 0x30, 0xd0, 0x8, 0xd0, 0x8, 0xd0, 0x8, 0xd0, 0x8, 0xf8, 0x30, 0xf8, 0x30, 0xf8, 0x30, 0xf8, 0x30, 0xf8, 0x8, 0xf0, 0x10, 0xf4, 0x4, 0xe8, 0x8, 0xf0, 0x10, 0xe0, 0x20, 0xec, 0xc, 0xd8, 0x18, 0xd8, 0x28, 0xd4, 0x2c, 0xd0, 0x30, 0xd0, 0xd0, 0x30, 0x30, 0xe0, 0x20,  };
static const uint16 kHandlePlayerPhysics_DATA_00D5C9[17] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0xf000, 0x1000, 0x0, 0x0, 0x0, 0x0, 0xe000, 0x2000, 0x0, 0x0, 0xf000, 0xf800,  };
static const uint8 kHandlePlayerPhysics_DATA_00D5EB[3] = { 0xff, 0xff, 0x2,  };
static const uint8 kHandlePlayerPhysics_DATA_00D5EE[2] = { 0x68, 0x70,  };
static const uint8 kHandlePlayerPhysics_DATA_00D5F0[2] = { 0x1c, 0xc,  };
static const uint8 kHandlePlayerPhysics_DATA_00D7A5[10] = { 0x6, 0x3, 0x4, 0x10, 0xf4, 0x1, 0x3, 0x4, 0x5, 0x6,  };
static const uint8 kHandlePlayerPhysics_DATA_00D7AF[10] = { 0x40, 0x40, 0x20, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40,  };
static const uint8 kHandlePlayerPhysics_DATA_00D7B9[15] = { 0x10, 0xc8, 0xe0, 0x2, 0x3, 0x3, 0x4, 0x3, 0x2, 0x0, 0x1, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kHandlePlayerPhysics_DATA_00D7C8[7] = { 0x1, 0x10, 0x30, 0x30, 0x38, 0x38, 0x40,  };
static const uint8 kHandlePlayerPhysics_CapeSpeed[5] = { 0xff, 0x1, 0x1, 0xff, 0xff,  };
static const uint8 kHandlePlayerPhysics_DATA_00D7D4[5] = { 0x1, 0x6, 0x3, 0x1, 0x0,  };
static const uint8 kHandlePlayerPhysics_DATA_00D7D9[11] = { 0x0, 0x0, 0x0, 0xf8, 0xf8, 0xf8, 0xf4, 0xf0, 0xc8, 0x2, 0x1,  };
static const uint8 kHandlePlayerPhysics_SwimPoses[4] = { 0x16, 0x1a, 0x1a, 0x18,  };
static const uint8 kHandlePlayerPhysics_SwimYSpeed[4] = { 0xe8, 0xf8, 0xd0, 0xd0,  };
static const uint8 kHandlePlayerPhysics_ClimbingSpeed[4] = { 0x10, 0x8, 0xf0, 0xf8,  };
static const uint8 kHandlePlayerPhysics_JumpFromVineYSpeed[2] = { 0xb0, 0xf0,  };
static const uint8 kHandlePlayerPhysics_DATA_00DABD[16] = { 0x0, 0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,  };
static const uint8 kHandlePlayerPhysics_SwingOnNetDoorPoses[14] = { 0x22, 0x15, 0x22, 0x15, 0x21, 0x1f, 0x20, 0x20, 0x20, 0x20, 0x1f, 0x21, 0x1f, 0x21,  };
static const uint8 kHandlePlayerPhysics_ClimbingPoses[2] = { 0x15, 0x22,  };
static const uint8 kHandlePlayerPhysics_NetPunchingPoses[2] = { 0x1e, 0x23,  };
static const uint8 kHandlePlayerPhysics_DATA_00DADF[18] = { 0x10, 0xf, 0xe, 0xd, 0xc, 0xb, 0xa, 0x9, 0x8, 0x7, 0x6, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5, 0x5,  };
static const uint16 kHandlePlayerPhysics_DATA_00DAF1[18] = { 0x120, 0x140, 0x12a, 0x12a, 0x130, 0x133, 0x132, 0x134, 0x136, 0x138, 0x13a, 0x13b, 0x145, 0x145, 0x145, 0x145, 0x145, 0x145,  };
static const uint8 kSetPlayerPose_AnimationSpeedTable[112] = { 0xa, 0x8, 0x6, 0x4, 0x3, 0x2, 0x1, 0x1, 0xa, 0x8, 0x6, 0x4, 0x3, 0x2, 0x1, 0x1, 0xa, 0x8, 0x6, 0x4, 0x3, 0x2, 0x1, 0x1, 0x8, 0x6, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x8, 0x6, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x5, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x5, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x5, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x5, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x5, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x5, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x4, 0x3, 0x2, 0x1, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2,  };
static const uint8 kPlayerGFXRt_PlayerXYDispIndexIndex[70] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x4, 0x4, 0x4, 0xe, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x0, 0x0, 0x0, 0x0, 0xc, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x0, 0x0,  };
static const uint8 kPlayerGFXRt_PlayerXYDispIndex[28] = { 0x0, 0x8, 0x10, 0x14, 0x18, 0x1e, 0x24, 0x24, 0x28, 0x30, 0x38, 0x3e, 0x44, 0x4a, 0x50, 0x54, 0x58, 0x58, 0x5c, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x74, 0x78, 0x7c, 0x80,  };
static const uint16 kPlayerGFXRt_XDisp[114] = { 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0xfff8, 0xfff8, 0xe, 0x6, 0xfff2, 0xfffa, 0x17, 0x7, 0xf, 0xffea, 0xfffa, 0xfffa, 0x0, 0x0, 0x0, 0x0, 0x10, 0x10, 0x0, 0x0, 0xfff8, 0xfff8, 0x0, 0xfff8, 0x8, 0x0, 0x8, 0xfff8, 0x0, 0x0, 0xfff8, 0x0, 0x0, 0x10, 0x2, 0x0, 0xfffe, 0x0, 0x0, 0x0, 0xfffc, 0x5, 0x4, 0xfffb, 0xfffb, 0x6, 0x5, 0xfffa, 0xfff9, 0x9, 0x7, 0xfff7, 0xfffd, 0xfffd, 0x3, 0x3, 0xffff, 0x7, 0x1, 0xfff9, 0xa, 0xfff6, 0x8, 0xfff8, 0x8, 0xfff8, 0x0, 0x4, 0xfffc, 0xfffe, 0x2, 0xb, 0xfff5, 0x14, 0xffec, 0xe, 0xfff3, 0x8, 0xfff8, 0xc, 0x14, 0xfffd, 0xfff4, 0xfff4, 0xb, 0xb, 0x3, 0x13, 0xfff5, 0x5, 0xfff5, 0x9, 0x1, 0x1, 0xfff7, 0x7, 0x7, 0x5, 0xd, 0xd, 0xfffb, 0xfffb, 0xfffb, 0xffff, 0xf, 0x1, 0xfff9, 0x0,  };
static const uint16 kPlayerGFXRt_YDisp[114] = { 0x1, 0x11, 0x11, 0x19, 0x1, 0x11, 0x11, 0x19, 0xc, 0x14, 0xc, 0x14, 0x18, 0x18, 0x28, 0x18, 0x18, 0x28, 0x6, 0x16, 0x1, 0x11, 0x9, 0x11, 0x1, 0x11, 0x9, 0x11, 0x1, 0x11, 0x11, 0x1, 0x11, 0x11, 0x1, 0x11, 0x11, 0x1, 0x11, 0x11, 0x1, 0x11, 0x1, 0x11, 0x11, 0x5, 0x4, 0x14, 0x4, 0x14, 0xc, 0x14, 0xc, 0x14, 0x10, 0x10, 0x10, 0x10, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0x10, 0x0, 0xb, 0xb, 0x11, 0x11, 0xffff, 0xffff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x15, 0x15, 0x25, 0x25, 0x4, 0x4, 0x4, 0x14, 0x14, 0x4, 0x14, 0x14, 0x4, 0x4, 0x14, 0x4, 0x4, 0x14, 0x0, 0x8, 0x0, 0x0, 0x8, 0x0, 0x0, 0x10, 0x18, 0x0, 0x10, 0x18, 0x0, 0x10, 0x0, 0x10, 0xfff8,  };
static const uint8 kPlayerGFXRt_PowerupTilesetIndex[4] = { 0x0, 0x46, 0x83, 0x46,  };
static const uint8 kPlayerGFXRt_Tiles[50] = { 0x0, 0x2, 0x80, 0x80, 0x0, 0x2, 0xc, 0x80, 0x0, 0x2, 0x1a, 0x1b, 0x0, 0x2, 0xd, 0x80, 0x0, 0x2, 0x22, 0x23, 0x0, 0x2, 0x32, 0x33, 0x0, 0x2, 0xa, 0xb, 0x0, 0x2, 0x30, 0x31, 0x0, 0x2, 0x20, 0x21, 0x0, 0x2, 0x7e, 0x80, 0x0, 0x2, 0x2, 0x80, 0x4, 0x7f, 0x4a, 0x5b, 0x4B, 0x5A };
static const uint8 kPlayerGFXRt_TilesIndex[192] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x28, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0xc, 0xc, 0xc, 0x0, 0x0, 0x10, 0x10, 0x14, 0x14, 0x18, 0x18, 0x0, 0x0, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0, 0x24, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0xc, 0xc, 0xc, 0x0, 0x0, 0x10, 0x10, 0x14, 0x14, 0x18, 0x18, 0x0, 0x0, 0x1c, 0x0, 0x0, 0x0, 0x0, 0x20, 0x0, 0x0, 0x0, 0x0, 0x24, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kPlayerGFXRt_TileXFlip[2] = { 0x0, 0x40,  };
static const uint8 kPlayerGFXRt_DATA_00E18E[70] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0x0, 0x10, 0x13, 0x22, 0x25, 0x28, 0x0, 0x16, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x19, 0x1c, 0x4, 0x1f, 0x10, 0x10, 0x0, 0x16, 0x10, 0x6, 0x4, 0x8, 0x2b, 0x30, 0x35, 0x3a, 0x3f, 0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x16, 0x16, 0x0, 0x0, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x4, 0x0,  };
// todo: oob
static const uint8 kPlayerGFXRt_DATA_00E1D4[72] = { 0x6, 0x0, 0x6, 0x0, 0x86, 0x2, 0x6, 0x3, 0x6, 0x1, 0x6, 0xce, 0x6, 0x6, 0x40, 0x0, 0x6, 0x2c, 0x6, 0x6, 0x44, 0xe, 0x86, 0x2c, 0x6, 0x86, 0x2c, 0xa, 0x86, 0x84, 0x8, 0x6, 0xa, 0x2, 0x6, 0xac, 0x10, 0x6, 0xcc, 0x10, 0x6, 0xae, 0x10, 0x0, 0x8c, 0x14, 0x80, 0x2e, 0x0, 0xca, 0x16, 0x91, 0x2f, 0x0, 0x8e, 0x18, 0x81, 0x30, 0x0, 0xeb, 0x1a, 0x90, 0x31, 0x4, 0xed, 0x1c, 0x82, 0x6, 0x92, 0x1e, 0x84,0x86, };
static const uint8 kPlayerGFXRt_CapeXYDispIndex[32] = { 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 0x90, 0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 0xa8, 0xaa, 0xb0, 0xb6, 0xbc, 0xc2, 0xc8, 0xce, 0xd4, 0xda, 0xde, 0xe2, 0xe2,  };
static const uint8 kPlayerGFXRt_CapeTilePointerIndex[44] = { 0xa, 0xa, 0x84, 0xa, 0x88, 0x88, 0x88, 0x88, 0x8a, 0x8a, 0x8a, 0x8a, 0x44, 0x44, 0x44, 0x44, 0x42, 0x42, 0x42, 0x42, 0x40, 0x40, 0x40, 0x40, 0x22, 0x22, 0x22, 0x22, 0xa4, 0xa4, 0xa4, 0xa4, 0xa6, 0xa6, 0xa6, 0xa6, 0x86, 0x86, 0x86, 0x86, 0x6e, 0x6e, 0x6e, 0x6e,  };
static const uint8 kPlayerGFXRt_DATA_00E266[44] = { 0x2, 0x2, 0x2, 0xc, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x12, 0x4, 0x4, 0x4, 0x12, 0x4, 0x4, 0x4, 0x12, 0x4, 0x4, 0x4, 0x12, 0x4, 0x4,  };
static const uint8 kPlayerGFXRt_DATA_00E292[16] = { 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x2, 0x4, 0x4, 0x4, 0x4, 0x8, 0x8, 0x8, 0x8,  };
static const uint16 kPlayerGFXRt_PalettePointers[8] = { 0xb2c8, 0xb2dc, 0xb2c8, 0xb2dc, 0xb2c8, 0xb2dc, 0xb2f0, 0xb304,  };
static const uint8 kPlayerGFXRt_PlayerStartingOAMIndex[4] = { 0x10, 0xd4, 0x10, 0xe8,  };
static const uint8 kPlayerGFXRt_CapeStartingOAMIndex[4] = { 0x8, 0xcc, 0x8, 0xe0,  };
static const uint8 kPlayerGFXRt_TilePriority[3] = { 0x10, 0x10, 0x30,  };
static const uint8 kSlopeDataTables_Player[33] = { 0x8, 0x8, 0x8, 0x8, 0x10, 0x10, 0x10, 0x10, 0x18, 0x18, 0x20, 0x20, 0x28, 0x30, 0x8, 0x10, 0x0, 0x0, 0x28, 0x0, 0x0, 0x0, 0x0, 0x0, 0x38, 0x50, 0x48, 0x40, 0x58, 0x58, 0x60, 0x60, 0x0,  };
static const uint8 kSlopeDataTables_Player_StationaryYSpeed[33] = { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x20, 0x20, 0x20, 0x20, 0x30, 0x30, 0x40, 0x30, 0x30, 0x30, 0x30, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x30, 0x30, 0x30, 0x40, 0x40, 0x40, 0x40, 0x0,  };
static const uint8 kSlopeDataTables_Player_TowardsPeakYSpeed[33] = { 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xec, 0xec, 0xee, 0xee, 0xda, 0xda, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xda, 0xda, 0xda, 0xda, 0x0, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kSlopeDataTables_Player_SnapToSlopeDistance[33] = { 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x9, 0x9, 0x9, 0x9, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0xb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xb, 0xb, 0xb, 0x14, 0x14, 0x14, 0x14, 0x6,  };
const uint8 kSlopeDataTables_SlopeType[33] = { 0xff, 0xff, 0xff, 0xff, 0x1, 0x1, 0x1, 0x1, 0xfe, 0xfe, 0x2, 0x2, 0xfd, 0x3, 0xfd, 0x3, 0xfd, 0x3, 0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x8, 0xf8, 0xf8, 0xfc, 0xfc, 0x4, 0x4, 0x0,  };
const uint8 kSlopeDataTables_ShapeOfSlope[512] = { 0xf, 0xf, 0xf, 0xf, 0xe, 0xe, 0xe, 0xe, 0xd, 0xd, 0xd, 0xd, 0xc, 0xc, 0xc, 0xc, 0xb, 0xb, 0xb, 0xb, 0xa, 0xa, 0xa, 0xa, 0x9, 0x9, 0x9, 0x9, 0x8, 0x8, 0x8, 0x8, 0x7, 0x7, 0x7, 0x7, 0x6, 0x6, 0x6, 0x6, 0x5, 0x5, 0x5, 0x5, 0x4, 0x4, 0x4, 0x4, 0x3, 0x3, 0x3, 0x3, 0x2, 0x2, 0x2, 0x2, 0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x1, 0x1, 0x2, 0x2, 0x2, 0x2, 0x3, 0x3, 0x3, 0x3, 0x4, 0x4, 0x4, 0x4, 0x5, 0x5, 0x5, 0x5, 0x6, 0x6, 0x6, 0x6, 0x7, 0x7, 0x7, 0x7, 0x8, 0x8, 0x8, 0x8, 0x9, 0x9, 0x9, 0x9, 0xa, 0xa, 0xa, 0xa, 0xb, 0xb, 0xb, 0xb, 0xc, 0xc, 0xc, 0xc, 0xd, 0xd, 0xd, 0xd, 0xe, 0xe, 0xe, 0xe, 0xf, 0xf, 0xf, 0xf, 0xf, 0xf, 0xe, 0xe, 0xd, 0xd, 0xc, 0xc, 0xb, 0xb, 0xa, 0xa, 0x9, 0x9, 0x8, 0x8, 0x7, 0x7, 0x6, 0x6, 0x5, 0x5, 0x4, 0x4, 0x3, 0x3, 0x2, 0x2, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2, 0x2, 0x3, 0x3, 0x4, 0x4, 0x5, 0x5, 0x6, 0x6, 0x7, 0x7, 0x8, 0x8, 0x9, 0x9, 0xa, 0xa, 0xb, 0xb, 0xc, 0xc, 0xd, 0xd, 0xe, 0xe, 0xf, 0xf, 0xf, 0xe, 0xd, 0xc, 0xb, 0xa, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0xf, 0xe, 0xd, 0xc, 0xb, 0xa, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x8, 0x6, 0x4, 0x3, 0x2, 0x2, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x1, 0x2, 0x2, 0x3, 0x4, 0x6, 0x8, 0xff, 0xfe, 0xfd, 0xfc, 0xfb, 0xfa, 0xf9, 0xf8, 0xf7, 0xf6, 0xf5, 0xf4, 0xf3, 0xf2, 0xf1, 0xf0, 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9, 0xfa, 0xfb, 0xfc, 0xfd, 0xfe, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfd, 0xfd, 0xfc, 0xfc, 0xfb, 0xfb, 0xfa, 0xfa, 0xf9, 0xf9, 0xf8, 0xf8, 0xf7, 0xf7, 0xf6, 0xf6, 0xf5, 0xf5, 0xf4, 0xf4, 0xf3, 0xf3, 0xf2, 0xf2, 0xf1, 0xf1, 0xf0, 0xf0, 0xf0, 0xf0, 0xf1, 0xf1, 0xf2, 0xf2, 0xf3, 0xf3, 0xf4, 0xf4, 0xf5, 0xf5, 0xf6, 0xf6, 0xf7, 0xf7, 0xf8, 0xf8, 0xf9, 0xf9, 0xfa, 0xfa, 0xfb, 0xfb, 0xfc, 0xfc, 0xfd, 0xfd, 0xfe, 0xfe, 0xff, 0xff, 0xf, 0xe, 0xd, 0xc, 0xb, 0xa, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0xf, 0xe, 0xd, 0xc, 0xb, 0xa, 0x9, 0x8, 0x7, 0x6, 0x5, 0x4, 0x3, 0x2, 0x1, 0x0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xe, 0xc, 0xa, 0x8, 0x6, 0x4, 0x2, 0x0, 0xe, 0xc, 0xa, 0x8, 0x6, 0x4, 0x2, 0x0, 0xfe, 0xfc, 0xfa, 0xf8, 0xf6, 0xf4, 0xf2, 0xf0, 0x0, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe, 0x0, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe,  };
static const uint16 kGetPlayerLevelCollisionMap16ID_DATA_00E832[54] = { 0x8, 0xe, 0xe, 0x8, 0x5, 0xb, 0x8, 0x2, 0x2, 0x8, 0xb, 0x5, 0x8, 0xe, 0xe, 0x8, 0x5, 0xb, 0x8, 0x2, 0x2, 0x8, 0xb, 0x5, 0x8, 0xe, 0xe, 0x8, 0x5, 0xb, 0x8, 0x2, 0x2, 0x8, 0xb, 0x5, 0x8, 0xe, 0xe, 0x8, 0x5, 0xb, 0x8, 0x2, 0x2, 0x8, 0xb, 0x5, 0x10, 0x20, 0x7, 0x0, 0xfff0, 0x8, };
// todo: buffer read overflow
static const uint16 kGetPlayerLevelCollisionMap16ID_DATA_00E89C[54] = { 0x18, 0x1a, 0x16, 0x10, 0x20, 0x20, 0x18, 0x1a, 0x16, 0x10, 0x20, 0x20, 0x12, 0x1a, 0xf, 0x8, 0x20, 0x20, 0x12, 0x1a, 0xf, 0x8, 0x20, 0x20, 0x1d, 0x28, 0x19, 0x13, 0x30, 0x30, 0x1d, 0x28, 0x19, 0x13, 0x30, 0x30, 0x1a, 0x28, 0x16, 0x10, 0x30, 0x30, 0x1a, 0x28, 0x16, 0x10, 0x30, 0x30, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,};
static const uint8 kHandlePlayerLevelColl_DATA_00E90A[3] = { 0x1, 0x2, 0x11,  };
static const uint8 kHandlePlayerLevelColl_DATA_00E90D[4] = { 0xff, 0xff, 0x1, 0x0,  };
static const uint8 kHandlePlayerLevelColl_DATA_00E911[2] = { 0x2, 0xd,  };
static const uint16 kHandlePlayerLevelColl_DATA_00E913[6] = { 0x1, 0xffff, 0x1, 0x1, 0xffff, 0xffff,  };
static const uint16 kHandlePlayerLevelColl_DATA_00E91F[6] = { 0x0, 0x0, 0xffff, 0x1, 0xffff, 0x1,  };
static const uint8 kRunPlayerBlockCode_DATA_00EAB9[2] = { 0xde, 0x23,  };
static const uint8 kRunPlayerBlockCode_DATA_00EABB[2] = { 0x20, 0xe0,  };
static const uint16 kRunPlayerBlockCode_DATA_00EABD[2] = { 0x8, 0xfff8,  };
static const uint8 kRunPlayerBlockCode_WaterSlopeMap16Numbers[26] = { 0x71, 0x72, 0x76, 0x77, 0x7b, 0x7c, 0x81, 0x86, 0x8a, 0x8b, 0x8f, 0x90, 0x94, 0x95, 0x99, 0x9a, 0x9e, 0x9f, 0xa3, 0xa4, 0xa8, 0xa9, 0xad, 0xae, 0xb2, 0xb3,  };
static const uint8 kCheckIfBlockWasHit_DATA_00F05C[36] = { 0x1, 0x5, 0x1, 0x2, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x2, 0x3, 0x3, 0x4, 0x2, 0x2, 0x2, 0x1, 0x1, 0x7, 0x11, 0x10,  };
static const uint8 kCheckIfBlockWasHit_DATA_00F080[36] = { 0x80, 0x0, 0x0, 0x1e, 0x0, 0x0, 0x5, 0x9, 0x6, 0x81, 0xe, 0xc, 0x14, 0x0, 0x5, 0x9, 0x6, 0x7, 0xe, 0xc, 0x16, 0x18, 0x1a, 0x1a, 0x0, 0x9, 0x0, 0x0, 0xff, 0xc, 0xa, 0x0, 0x0, 0x0, 0x8, 0x2,  };
static const uint8 kCheckIfBlockWasHit_DATA_00F0A4[36] = { 0xc, 0x8, 0xc, 0x8, 0xc, 0xf, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x3, 0x3, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x4, 0x8, 0x8,  };
static const uint8 kCheckIfBlockWasHit_DATA_00F0C8[36] = { 0xe, 0x13, 0xe, 0xd, 0xe, 0x10, 0xd, 0xd, 0xd, 0xd, 0xa, 0xd, 0xd, 0xc, 0xd, 0xd, 0xd, 0xd, 0xb, 0xd, 0xd, 0x16, 0xd, 0xd, 0xd, 0x11, 0x11, 0x12, 0xd, 0xd, 0xd, 0xe, 0xf, 0xc, 0xd, 0xd,  };
static const uint8 kCheckIfBlockWasHit_DATA_00F0EC[12] = { 0x8, 0x1, 0x2, 0x4, 0xed, 0xf6, 0x0, 0x7d, 0xbe, 0x0, 0x6f, 0xb7,  };
static const uint8 kCheckIfBlockWasHit_DATA_00F0F8[8] = { 0x40, 0x50, 0x0, 0x70, 0x80, 0x0, 0xa0, 0xb0,  };
static const uint8 kCheckIfBlockWasHit_DATA_00F100[32] = { 0x5, 0x9, 0x6, 0x5, 0x9, 0x6, 0x5, 0x9, 0x6, 0x5, 0x9, 0x6, 0x5, 0x9, 0x6, 0x5, 0x7, 0xa, 0x10, 0x7, 0xa, 0x10, 0x7, 0xa, 0x10, 0x7, 0xa, 0x10, 0x7, 0xa, 0x10, 0x7,  };
static const uint8 kRunPlayerBlockCode_DATA_00F3E3[2] = { 0xa, 0xff,  };
static const uint8 kRunPlayerBlockCode_PIPE_BUTTONS[4] = { 0x2, 0x1, 0x8, 0x4,  };
static const uint16 kHandleStandardLevelCameraScroll_DATA_00F69F[2] = { 0x64, 0x7c,  };
static const uint16 kHandleStandardLevelCameraScroll_DATA_00F6A3[2] = { 0x0, 0xffff,  };
static const uint16 kHandleStandardLevelCameraScroll_DATA_00F6A7[3] = { 0xfffd, 0x5, 0xfffa,  };
static const uint16 kHandleStandardLevelCameraScroll_DATA_00F6AD[3] = { 0x0, 0x0, 0xc0,  };
static const uint16 kHandleStandardLevelCameraScroll_DATA_00F6B3[6] = { 0x90, 0x60, 0x0, 0x0, 0x0, 0x0,  };
static const uint16 kHandleStandardLevelCameraScroll_DATA_00F6BF[6] = { 0x0, 0xfffe, 0x2, 0x0, -2, 2 };
static const uint16 kHandleStandardLevelCameraScroll_DATA_00F6CB[8] = { 0x0, 0x20, 0xd0, 0x0, 0x20, 0xd0,      1,     -1 };
static const uint8 kPlayerState00_DATA_00F8DF[9] = { 0xc, 0xc, 0x8, 0x0, 0x20, 0x4, 0xa, 0xd, 0xd,  };
static const uint16 kPlayerState00_DATA_00F8E8[5] = { 0x2a, 0x2a, 0x12, 0x0, 0xffed,  };
static const uint8 kSpr07B_GoalTape_DATA_00FADF[28] = { 0x74, 0x74, 0x77, 0x75, 0x76, 0xe0, 0xf0, 0x74, 0x74, 0x77, 0x75, 0x76, 0xe0, 0xf1, 0xf0, 0xf0, 0xf0, 0xf0, 0xf1, 0xe0, 0xf2, 0xe0, 0xe0, 0xe0, 0xe0, 0xf1, 0xe0, 0xe4,  };
static const uint8 kSpr07B_GoalTape_DATA_00FAFB[5] = { 0xff, 0x74, 0x75, 0x76, 0x77,  };
static const uint8 kSprStatus06_GoalCoins_SmokeTiles[4] = { 0x66, 0x64, 0x62, 0x60,  };
static const uint8 kSpawnPlayerBreathBubble_xlo[2] = { 0x2, 0xa,  };
static const uint8 kSpawnPlayerWaterSplashAndBubbles_YLo[4] = { 0x8, 0xfc, 0x10, 0x4,  };
static const uint8 kSpawnPlayerWaterSplashAndBubbles_YHi[4] = { 0x0, 0xff, 0x0, 0x0,  };
static const uint8 kSpawnPlayerWaterSplashAndBubbles_Bubble_YLo[4] = { 0x10, 0x16, 0x13, 0x1c,  };
static const uint8 kSpawnPlayerWaterSplashAndBubbles_Bubble_XLo[4] = { 0x0, 0x4, 0xa, 0x7,  };
static const uint8 kSpawnPlayerFireball_InitialXSpeed[2] = { 0xfd, 0x3,  };
static const uint8 kSpawnPlayerFireball_xlo[6] = { 0x0, 0x8, 0xf8, 0x10, 0xf8, 0x10,  };
static const uint8 kSpawnPlayerFireball_xhi[6] = { 0x0, 0x0, 0xff, 0x0, 0xff, 0x0,  };
static const uint8 kSpawnPlayerFireball_ylo[6] = { 0x8, 0x8, 0xc, 0xc, 0x14, 0x14,  };

static const uint8 kUpdateHDMAWindowBuffer_CircleHDMAData[] = {
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xfe, 0xfd, 0xfd, 0xfd, 0xfd, 0xfc, 0xfc, 0xfc, 0xfb, 0xfb, 0xfb, 0xfa, 0xfa, 0xf9, 0xf9, 0xf8, 0xf8, 0xf7, 0xf7, 0xf6, 0xf6, 0xf5, 0xf5, 0xf4, 0xf3, 0xf3, 0xf2, 0xf1, 0xf1, 0xf0, 0xef, 0xee, 0xee, 0xed, 0xec, 0xeb, 0xea, 0xe9, 0xe9, 0xe8, 0xe7, 0xe6, 0xe5, 0xe4, 0xe3, 0xe2, 0xe1, 0xdf, 0xde, 0xdd, 0xdc, 0xdb, 0xda, 0xd8, 0xd7, 0xd6, 0xd5, 0xd3, 0xd2, 0xd0, 0xcf, 0xcd, 0xcc, 0xca, 0xc9, 0xc7, 0xc6, 0xc4, 0xc2, 0xc1, 0xbf, 0xbd, 0xbb, 0xb9, 0xb7, 0xb6, 0xb4, 0xb1, 0xaf, 0xad, 0xab, 0xa9, 0xa7, 0xa4, 0xa2, 0x9f, 0x9d, 0x9a, 0x97, 0x95, 0x92, 0x8f, 0x8c, 0x89, 0x86, 0x82, 0x7f, 0x7b, 0x78, 0x74, 0x70, 0x6c, 0x67, 0x63, 0x5e, 0x59, 0x53, 0x4d, 0x46, 0x3f, 0x37, 0x2d, 0x1f, 0x00
};

static const uint8 kUpdateHDMAWindowBuffer_KeyholeHDMAData[] = {
  0x54, 0x53, 0x52, 0x52, 0x51, 0x50, 0x50, 0x4f, 0x4e, 0x4e, 0x4d, 0x4c, 0x4c, 0x4b, 0x4a, 0x4a, 0x4b, 0x48, 0x48, 0x47, 0x46, 0x46, 0x45, 0x44, 0x44, 0x43, 0x42, 0x42, 0x41, 0x40, 0x40, 0x3f, 0x3e, 0x3e, 0x3d, 0x3c, 0x3c, 0x3b, 0x3a, 0x3a, 0x39, 0x38, 0x38, 0x37, 0x36, 0x36, 0x35, 0x34, 0x34, 0x33, 0x32, 0x32, 0x31, 0x33, 0x35, 0x38, 0x3a, 0x3c, 0x3e, 0x3f, 0x41, 0x43, 0x44, 0x45, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4e, 0x4f, 0x50, 0x50, 0x51, 0x51, 0x52, 0x52, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x53, 0x52, 0x52, 0x51, 0x51, 0x50, 0x50, 0x4f, 0x4e, 0x4e, 0x4d, 0x4c, 0x4b, 0x4a, 0x49, 0x48, 0x47, 0x45, 0x44, 0x43, 0x41, 0x3f, 0x3e, 0x3c, 0x3a, 0x38, 0x35, 0x33, 0x30, 0x2d, 0x2a, 0x26, 0x23, 0x1e, 0x18, 0x11, 0x00
};



void SmwVectorReset() {
//  xWriteReg(NMITIMEN, 0);
//  xWriteReg(HDMAEN, 0);
  RtlApuWrite(APUI00, 0);
  RtlApuWrite(APUI01, 0);
  RtlApuWrite(APUI02, 0);
  RtlApuWrite(APUI03, 0);
  RtlPpuWrite(INIDISP, 0x80);
  *(uint16 *)reset_sprites_y_function_in_ram = 0xf0a9;
  uint16 v0 = 381;
  int16 v1 = 0x3fd;
  do {
    *(uint16 *)&reset_sprites_y_function_in_ram[v0 + 2] = 141;
    *(uint16 *)&reset_sprites_y_function_in_ram[v0 + 3] = v1;
    v1 -= 4;
    v0 -= 3;
  } while ((v0 & 0x8000) == 0);
  reset_sprites_y_function_in_ram[386] = 107;
  HandleSPCUploads_UploadSPCEngine();
  misc_game_mode = 0;
  misc_intro_level_flag = 0;
  InitializeFirst8KBOfRAM();
  HandleSPCUploads_UploadSamples();
  SetupHDMAWindowingEffects();
  RtlPpuWrite(OBSEL, 3);
  ++waiting_for_vblank;
}

void SmwRunOneFrameOfGame_Internal() {
  assert(waiting_for_vblank != 0);
  ++counter_global_frames;
  InitAndMainLoop_ProcessGameMode();
  waiting_for_vblank = 0;
}

void ResetSpritesFunc(int wh) {
  for (; wh < 128; wh++)
    g_ram[0x201 + wh * 4] = 0xf0;
}

void HandleSPCUploads_UploadSPCEngine() {  // 0080e8
  HandleSPCUploads_UploadDataToSPC(kSpcEngine);
}

void HandleSPCUploads_UploadDataToSPC(const uint8 *p) {  // 0080f7
  if (g_use_my_apu_code)
    RtlApuUpload(p);
}

void HandleSPCUploads_UploadSamples() {  // 0080fd
  HandleSPCUploads_StrtSPCMscUpld(kSpcSamples);
}

void HandleSPCUploads_UploadOverworldMusicBank() {  // 00810e
  HandleSPCUploads_StrtSPCMscUpld(kSpcOverworldMusicBank);
}

void HandleSPCUploads_StrtSPCMscUpld(const uint8 *p) {  // 00811d
  HandleSPCUploads_UploadDataToSPC(p);
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    RtlApuWrite((SnesRegs)(i + APUI00), 0);
    *(&io_sound_ch1 + i) = 0;
    *(&unusedram_7e1dfd + i) = 0;
  }
}

void HandleSPCUploads_008134() {  // 008134
  if (flag_active_bonus_game || misc_intro_level_flag == 0xE9 ||
      !(flag_show_player_start | (uint8)(counter_sublevels_entered | misc_intro_level_flag))) {
    HandleSPCUploads_StrtSPCMscUpld(kSpcLevelMusicBank);
  }
}

void HandleSPCUploads_UploadCreditsMusicBank() {  // 008159
  HandleSPCUploads_StrtSPCMscUpld(kSpcCreditsMusicBank);
}

void SmwVectorNMI() {
  int trigger_line = -1;
  uint8 v0 = io_music_ch1;
  if (io_music_ch1  || g_ram[kSmwRam_APUI02] == io_copy_of_music_ch1) {
    RtlApuWrite(APUI02, v0);
    io_copy_of_music_ch1 = v0;
    io_music_ch1 = 0;
  }
  RtlApuWrite(APUI00, io_sound_ch1);
  RtlApuWrite(APUI01, io_sound_ch2);
  RtlApuWrite(APUI03, io_sound_ch3);
  io_sound_ch1 = 0;
  io_sound_ch2 = 0;
  io_sound_ch3 = 0;
  RtlPpuWrite(W12SEL, mirror_bg1_and2_window_mask_settings);
  RtlPpuWrite(W34SEL, mirror_bg3_and4_window_mask_settings);
  RtlPpuWrite(WOBJSEL, mirror_object_and_color_window_settings);
  RtlPpuWrite(CGWSEL, mirror_color_math_initial_settings);
  if ((misc_nmito_use_flag & 0x80) == 0) {
    RtlPpuWrite(CGADSUB, mirror_color_math_select_and_enable & 0xFB);
    RtlPpuWrite(BGMODE, 9);
    if (waiting_for_vblank) {
      if (misc_nmito_use_flag & ~1) {
LABEL_25:
        if (misc_currently_active_boss_end_cutscene == 8) {
          RtlPpuWriteTwice(BG3HOFS, mirror_layer3_xpos);
          RtlPpuWriteTwice(BG3VOFS, mirror_layer3_ypos);
          RtlPpuWrite(BGMODE, mirror_bgmode_and_tile_size_setting);
          RtlPpuWrite(CGADSUB, mirror_color_math_select_and_enable);
          goto exit_routine;
        }
        goto LABEL_29;
      }
      goto LABEL_24;
    }
    waiting_for_vblank = 1;
    UpdatePaletteFromIndexedTable();
    if (misc_nmito_use_flag & ~1) {
      if (pointer_current_overworld_process == 10 && (uint8)(ow_submap_switch_process - 2) < 4) {
        UploadOverworldLayer1And2Tilemaps(ow_submap_switch_process - 2);
LABEL_23:
        PollJoypadInputs();
LABEL_24:
        RtlPpuWriteTwice(BG1HOFS, mirror_current_layer1_xpos);
        RtlPpuWriteTwice(BG1VOFS, shaking_layer1_disp_y + mirror_current_layer1_ypos);
        RtlPpuWriteTwice(BG2HOFS, mirror_current_layer2_xpos);
        RtlPpuWriteTwice(BG2VOFS, mirror_current_layer2_ypos);
        if (misc_nmito_use_flag)
          goto LABEL_25;
        trigger_line = 36;
        goto LABEL_28_EnableVtimeL;
      }
      UploadOverworldExAnimationData();
      UploadPlayerGFX();
    } else {
      if (!(misc_nmito_use_flag & 1))
        UploadStatusBarTilemap();
      if (misc_currently_active_boss_end_cutscene == 8) {
        if (flag_update_credits_background)
          UpdateCreditsBackground();
        goto LABEL_17;
      }
      if (g_lunar_magic)
        LmHook_UploadLevelLayer1And2Tilemaps();
      else
        UploadLevelLayer1And2Tilemaps();
      if (!flag_upload_load_screen_letters_tovram) {
        UploadLevelExAnimationData();
LABEL_17:
        RestoreSP1AfterMarioStart();
        UploadPlayerGFX();
        goto LABEL_22;
      }
      UploadLoadingLettersTiles();
    }
LABEL_22:
    LoadStripeImage();
    UploadOAMBuffer();
    goto LABEL_23;
  }
  if (!waiting_for_vblank) {
    ++waiting_for_vblank;
    if (flag_upload_load_screen_letters_tovram) {
      UploadLoadingLettersTiles();
    } else {
      RestoreSP1AfterMarioStart();
      UploadPlayerGFX();
      if ((misc_nmito_use_flag & 0x40) != 0) {
        UploadMode7KoopaBossesAndLavaAnimation();
        if (misc_nmito_use_flag & 1)
          goto LABEL_36;
      }
    }
    UploadStatusBarTilemap();
LABEL_36:
    UpdatePaletteFromIndexedTable();
    LoadStripeImage();
    UploadOAMBuffer();
    PollJoypadInputs();
  }
  RtlPpuWrite(BGMODE, 9);
  RtlPpuWriteTwice(M7X, mirror_m7_center_xpos + 0x80);
  RtlPpuWriteTwice(M7Y, mirror_m7_center_ypos + 0x80);
  RtlPpuWriteTwice(M7A, WORD(mirror_m7_matrix_alo));
  RtlPpuWriteTwice(M7B, WORD(mirror_m7_matrix_blo));
  RtlPpuWriteTwice(M7C, WORD(mirror_m7_matrix_clo));
  RtlPpuWriteTwice(M7D, WORD(mirror_m7_matrix_dlo));
  SetMode7PPUPointersAndLayer1Scroll();
  if (!(misc_nmito_use_flag & 1)) {
    trigger_line = 36;
    if ((misc_nmito_use_flag & 0x40) != 0 && kPlayerState00_DATA_00F8E8[misc_currently_active_boss] == 42) {
      trigger_line = 45;
    }
  LABEL_28_EnableVtimeL:
    flag_irqto_use = 0;
  LABEL_29:
    RtlPpuWriteTwice(BG3HOFS, 0);
    RtlPpuWriteTwice(BG3VOFS, 0);
  } else {
    RtlPpuWrite(BGMODE, 7);
    RtlPpuWriteTwice(BG1HOFS, mirror_m7_xpos);
    RtlPpuWriteTwice(BG1VOFS, mirror_m7_ypos);
  }
exit_routine:
  RtlPpuWrite(INIDISP, mirror_screen_display_register);
  RtlEnableVirq(trigger_line);
//  xWriteReg(HDMAEN, mirror_hdmaenable);
}

void SmwVectorIRQ() {
  int trigger_line = -1;
  if ((misc_nmito_use_flag & 0x80) != 0) {
    if ((misc_nmito_use_flag & 0x40) != 0) {
      if (flag_irqto_use) {
        SetMode7PPUPointersAndLayer1Scroll();
        goto LABEL_4;
      }
      flag_irqto_use = 1;
      trigger_line = (-82 - shaking_layer1_disp_y) & 0xff;
    }
    if (!timer_end_level || timer_level_end_fade < 0x40) {
      RtlPpuWrite(BGMODE, 7);
      RtlPpuWriteTwice(BG1HOFS, mirror_m7_xpos);
      RtlPpuWriteTwice(BG1VOFS, mirror_m7_ypos);
      goto out;
    }
  }
  RtlPpuWriteTwice(BG3HOFS, mirror_layer3_xpos);
  RtlPpuWriteTwice(BG3VOFS, mirror_layer3_ypos);
LABEL_4:
  RtlPpuWrite(BGMODE, mirror_bgmode_and_tile_size_setting);
  RtlPpuWrite(CGADSUB, mirror_color_math_select_and_enable);
out:
  RtlEnableVirq(trigger_line);
}

void SetMode7PPUPointersAndLayer1Scroll() {  // 008416
  RtlPpuWrite(BG1SC, 0x59);
  RtlPpuWrite(BG12NBA, 7);
  RtlPpuWriteTwice(BG1HOFS, mirror_current_layer1_xpos);
  RtlPpuWrite(BG1VOFS, shaking_layer1_disp_y + mirror_current_layer1_ypos);
  RtlPpuWrite(BG1VOFS, HIBYTE(mirror_current_layer1_ypos));
}

void CompressOamEntExt() {  // 008494
  for (uint8 i = 30; (i & 0x80) == 0; i -= 2) {
    uint8 v1 = kCompressOAMTileSizeBuffer_DATA_008475[i];
    oam_buf_ext[i] =
        sprites_oamtile_size_buffer[v1] | (4 * (sprites_oamtile_size_buffer[v1 + 1] |
                                                (4 * (sprites_oamtile_size_buffer[v1 + 2] | (4 * sprites_oamtile_size_buffer[v1 + 3])))));
    oam_buf_ext[i + 1] = sprites_oamtile_size_buffer[v1 + 4] |
                         (4 * (sprites_oamtile_size_buffer[v1 + 5] |
                               (4 * (sprites_oamtile_size_buffer[v1 + 6] | (4 * sprites_oamtile_size_buffer[v1 + 7])))));
  }
}

void LoadStripeImage() {  // 0085d2
  if (graphics_stripe_image_to_upload)
    graphics_stripe_image_to_upload += 0;
  const uint8 *p = (graphics_stripe_image_to_upload == 0) ? stripe_image_upload_data : kLoadStripeImagePtrs(graphics_stripe_image_to_upload / 3).ptr;
  LoadStripeImage_UploadToVRAM(p);
  if (!graphics_stripe_image_to_upload) {
    LOBYTE(stripe_image_upload) = graphics_stripe_image_to_upload;
    HIBYTE(stripe_image_upload) = graphics_stripe_image_to_upload;
    stripe_image_upload_data[0] = graphics_stripe_image_to_upload - 1;
  }
  graphics_stripe_image_to_upload = 0;
}

void ClearLayer3Tilemap() {  // 0085fa
  TurnOffIO();
  SmwClearVram(0x5000, 0x38fc, 0x1000);
  mirror_oamaddress_lo = 0;
  ResetSpritesFunc(0);
  UploadOAMBuffer();
}

void PollJoypadInputs() {  // 008650
  io_controller_hold2_copyp1 = ReadReg(JOY1L) & 0xF0;
  io_controller_press2_copyp1 = io_controller_hold2_copyp1 & (io_p1_ctrl_disable_hi ^ io_controller_hold2_copyp1);
  io_p1_ctrl_disable_hi = io_controller_hold2_copyp1;
  io_controller_hold1_copyp1 = ReadReg(JOY1H);
  io_controller_press1_copyp1 = io_controller_hold1_copyp1 & (io_p1_ctrl_disable_lo ^ io_controller_hold1_copyp1);
  io_p1_ctrl_disable_lo = io_controller_hold1_copyp1;
  io_controller_hold2_copyp2 = ReadReg(JOY2L) & 0xF0;
  io_controller_press2_copyp2 = io_controller_hold2_copyp2 & (io_p2_ctrl_disable_hi ^ io_controller_hold2_copyp2);
  io_p2_ctrl_disable_hi = io_controller_hold2_copyp2;
  io_controller_hold1_copyp2 = ReadReg(JOY2H);
  io_controller_press1_copyp2 = io_controller_hold1_copyp2 & (io_p2_ctrl_disable_lo ^ io_controller_hold1_copyp2);
  io_p2_ctrl_disable_lo = io_controller_hold1_copyp2;
  uint8 v0 = io_controllers_plugged_in;
  if ((io_controllers_plugged_in & 0x80) != 0)
    v0 = player_current_character;
  io_controller_hold1 = *(&io_controller_hold1_copyp1 + v0) | *(&io_controller_hold2_copyp1 + v0) & 0xC0;
  io_controller_hold2 = *(&io_controller_hold2_copyp1 + v0);
  io_controller_press1 = *(&io_controller_press1_copyp1 + v0) | *(&io_controller_press2_copyp1 + v0) & 0x40;
  io_controller_press2 = *(&io_controller_press2_copyp1 + v0);
}

void GameMode14_InLevel_0086C7() {  // 0086c7
  for (int16 i = 98; i >= 0; i -= 2)
    *(uint16 *)&sprites_oamtile_size_buffer[(uint16)i] = 514;
  ResetSpritesFunc(100);
}


void UploadLevelLayer1And2Tilemaps() {  // 0087ad
  if ((uint8)blocks_layer1_vramupload_address) {
    if ((misc_level_layout_flags & 1) != 0) {
      SmwCopyToVram(swap16(blocks_layer1_vramupload_address), g_ram + 0x1be6, 0x40);
      SmwCopyToVram(swap16(blocks_layer1_vramupload_address) + 0x400, g_ram + 0x1c26, 0x40);
      SmwCopyToVram(swap16(blocks_layer1_vramupload_address) + 0x20, g_ram + 0x1c66, 0x40);
      SmwCopyToVram(swap16(blocks_layer1_vramupload_address) + 0x420, g_ram + 0x1cA6, 0x40);
    } else {
      SmwCopyToVramPitch32(swap16(blocks_layer1_vramupload_address), g_ram + 0x1be6, 0x40);
      SmwCopyToVramPitch32(swap16(blocks_layer1_vramupload_address) + 0x800, g_ram + 0x1c26, 0x2c);
      SmwCopyToVramPitch32(swap16(blocks_layer1_vramupload_address) + 1, g_ram + 0x1c66, 0x40);
      SmwCopyToVramPitch32(swap16(blocks_layer1_vramupload_address) + 0x801, g_ram + 0x1cA6, 0x2c);
    }
  }
  LOBYTE(blocks_layer1_vramupload_address) = 0;
  if ((uint8)blocks_layer2_vramupload_address) {
    uint8 size = g_lunar_magic ? 0x40 : 0x2c;
    if ((misc_level_layout_flags & 2) != 0) {
      SmwCopyToVram(swap16(blocks_layer2_vramupload_address), g_ram + 0x1ce8, 0x40);
      SmwCopyToVram(swap16(blocks_layer2_vramupload_address) + 0x400, g_ram + 0x1d28, 0x40);
      SmwCopyToVram(swap16(blocks_layer2_vramupload_address) + 0x20, g_ram + 0x1d68, 0x40);
      SmwCopyToVram(swap16(blocks_layer2_vramupload_address) + 0x420, g_ram + 0x1da8, 0x40);
    } else {
      SmwCopyToVramPitch32(swap16(blocks_layer2_vramupload_address), g_ram + 0x1ce8, 0x40);
      SmwCopyToVramPitch32(swap16(blocks_layer2_vramupload_address) + 0x800, g_ram + 0x1d28, size);
      SmwCopyToVramPitch32(swap16(blocks_layer2_vramupload_address) + 1, g_ram + 0x1d68, 0x40);
      SmwCopyToVramPitch32(swap16(blocks_layer2_vramupload_address) + 0x801, g_ram + 0x1dA8, size);
    }
  }
  LOBYTE(blocks_layer2_vramupload_address) = 0;
}

void InitializeFirst8KBOfRAM() {  // 008a4e
  uint16 v0 = 0x1ffe;
  do {
    WORD(g_ram[v0]) = 0;
    do
      v0 -= 2;
    while ((int16)(v0 - 511) < 0 && (int16)(v0 - 256) >= 0);
  } while (v0 != 0xFFFE);
  stripe_image_upload = 0;
  *(uint16 *)&palettes_dynamic_palette_upload_index = 0;
  stripe_image_upload_data[0] = -1;
}

void SetStandardPPUSettings() {  // 008a79
  RtlPpuWrite(SETINI, 0);
  RtlPpuWrite(MOSAIC, 0);
  RtlPpuWrite(BG1SC, 0x23);
  RtlPpuWrite(BG2SC, 0x33);
  RtlPpuWrite(BG3SC, 0x53);
  RtlPpuWrite(BG12NBA, 0);
  RtlPpuWrite(BG34NBA, 4);
  mirror_bg1_and2_window_mask_settings = 0;
  mirror_bg3_and4_window_mask_settings = 0;
  mirror_object_and_color_window_settings = 0;
  RtlPpuWrite(WBGLOG, 0);
  RtlPpuWrite(WOBJLOG, 0);
  RtlPpuWrite(TMW, 0);
  RtlPpuWrite(TSW, 0);
  mirror_color_math_initial_settings = 2;
  RtlPpuWrite(M7SEL, 0x80);
}

void ManipulateMode7Image() {  // 008acd
  uint8 r0 = HIBYTE(misc_m7_angle);
  ManipulateMode7Image_008AE8(r0);
  r0 = misc_m7_angle;
  *(uint16 *)&mirror_m7_matrix_dlo = *(uint16 *)&mirror_m7_matrix_alo;
  *(uint16 *)&mirror_m7_matrix_clo = -*(uint16 *)&mirror_m7_matrix_blo;
  ManipulateMode7Image_008AE8(r0);
}

void ManipulateMode7Image_008AE8(uint8 r0) {  // 008ae8
  uint16 v0 = 2 * ((misc_m7_rotation >> 7) & 3);
  int16 v2 = kManipulateMode7Image_DATA_008ABC[v0 >> 1] + (kManipulateMode7Image_DATA_008AB4[v0 >> 1] ^ (uint8)(2 * misc_m7_rotation));
  int16 v1 = v2;
  v2 = ManipulateMode7Image_008B2B(v2, r0);
  if (v0 >= 4)
    v2 = -v2;
  *(uint16 *)&mirror_m7_matrix_blo = v2;
  int16 v3 = ((v1 ^ 0xFE) + 2) & 0x1FF;
  v3 = ManipulateMode7Image_008B2B(v3, r0);
  if ((uint16)(v0 - 2) < 4)
    v3 = -v3;
  *(uint16 *)&mirror_m7_matrix_alo = v3;
}

uint16 ManipulateMode7Image_008B2B(uint16 k, uint8 r0) {  // 008b2b
  uint8 v1 = *((uint8 *)kManipulateMode7Image_DATA_008B57 + k + 1);
  if (v1)
    v1 = r0;
  uint8 r1 = v1;
  uint16 v2 = (r1 << 8) + Mult8x8(*((uint8 *)kManipulateMode7Image_DATA_008B57 + k), r0);
  return v2 >> 5;
}

static const uint8 kStatusBarTilemap_TopRow[8] = { 0x3A,0x38,0x3B,0x38,0x3B,0x38,0x3A,0x78 };
static const uint8 kStatusBarTilemap_SomeRow[8] = { 0x3A,0xB8,0x3B,0xB8,0x3B,0xB8,0x3A,0xF8 };

void InitializeStatusBarTilemap() {  // 008cff
  SmwCopyToVram(0x502e, kStatusBarTilemap_TopRow, 8);
  SmwCopyToVram(0x5042, kStatusBarTilemap_SecondRow, 0x38);
  SmwCopyToVram(0x5063, kStatusBarTilemap_SecondRow + 0x38, 0x36);
  SmwCopyToVram(0x508e, kStatusBarTilemap_SomeRow, 8);
  int8 v4 = 54;
  uint8 v5 = 108;
  do {
    misc_status_bar_tilemap[(uint8)v4] = kStatusBarTilemap_SecondRow[v5];
    v5 -= 2;
    --v4;
  } while (v4 >= 0);
  misc_status_bar_tilemap[55] = 40;
}

void UploadStatusBarTilemap() {  // 008dac
  SmwCopyToVramLow(0x5042, g_ram + 0xef9, 0x1c);
  SmwCopyToVramLow(0x5063, g_ram + 0xf15, 0x1b);
}

void UpdateStatusBarCounters() {  // 008e1a
  if (!(flag_sprites_locked | timer_end_level) && misc_nmito_use_flag != 0xC1 && (--misc_status_bar_tilemap[55] & 0x80) != 0) {
    misc_status_bar_tilemap[55] = 40;
    if (counter_timer_ones | (uint8)(counter_timer_tens | counter_timer_hundreds)) {
      for (uint8 i = 2; (i & 0x80) == 0; --i) {
        if ((--*(&counter_timer_hundreds + i) & 0x80) == 0)
          break;
        *(&counter_timer_hundreds + i) = 9;
      }
      if (!counter_timer_hundreds && (counter_timer_ones & counter_timer_tens) == 9)
        io_sound_ch1 = -1;
      if (!(counter_timer_ones | (uint8)(counter_timer_tens | counter_timer_hundreds)))
        DamagePlayer_Kill();
    }
  }
  misc_status_bar_tilemap[44] = counter_timer_hundreds;
  misc_status_bar_tilemap[45] = counter_timer_tens;
  misc_status_bar_tilemap[46] = counter_timer_ones;
  uint8 v2 = 16;
  for (uint8 j = 0; j != 2; ++j) {
    if (*(&counter_timer_hundreds + j))
      break;
    misc_status_bar_tilemap[v2++ + 28] = -4;
  }
  for (uint8 k = 3; (k & 0x80) == 0; k -= 3) {
    uint16 r0w = *(&player_mario_score_hi + k);
    if (__PAIR32__(r0w, *(uint16 *)(&player_mario_score_lo + k)) >= 0xF423F) {
      *(&player_mario_score_hi + k) = 15;
      *(&player_mario_score_mid + k) = 66;
      *(&player_mario_score_lo + k) = 63;
    }
  }
  UpdateStatusBarCounters_Loop2(0x14, 0, player_mario_score_hi, PAIR16(player_mario_score_mid, player_mario_score_lo));
  for (uint8 m = 0; m != 6; ++m) {
    if (misc_status_bar_tilemap[m + 48])
      break;
    misc_status_bar_tilemap[m + 48] = -4;
  }
  if (player_current_character) {
    UpdateStatusBarCounters_Loop2(0x14, 0, player_luigi_score_hi, PAIR16(player_luigi_score_mid, player_luigi_score_lo));
    for (uint8 n = 0; n != 6; ++n) {
      if (misc_status_bar_tilemap[n + 48])
        break;
      misc_status_bar_tilemap[n + 48] = -4;
    }
  }
  if (counter_coin_handler) {
    --counter_coin_handler;
    if (++player_current_coin_count >= 0x64) {
      ++misc_1up_handler;
      player_current_coin_count -= 100;
    }
  }
  if ((int8)player_current_life_count >= 98)
    player_current_life_count = 98;
  PairU16 v7 = HexToDec(player_current_life_count + 1);
  uint8 second = v7.second;
  if (!LOBYTE(v7.second))
    second = -4;
  misc_status_bar_tilemap[29] = second;
  misc_status_bar_tilemap[30] = v7.first;
  if (*(&player_mario_bonus_stars + player_current_character) >= 0x64) {
    flag_active_bonus_game = -1;
    *(&player_mario_bonus_stars + player_current_character) -= 100;
  }
  PairU16 v9 = HexToDec(player_current_coin_count);
  uint8 v10 = v9.second;
  if (!LOBYTE(v9.second))
    v10 = -4;
  misc_status_bar_tilemap[27] = v9.first;
  misc_status_bar_tilemap[26] = v10;
//  r0 = 0;
//  r1 = 0;
  uint16 r2w = *(&player_mario_bonus_stars + player_current_character);
  UpdateStatusBarCounters_009051(9, 0x10, r2w);
  uint8 ii;
  for (ii = 0; ii != 1; ++ii) {
    if (misc_status_bar_tilemap[ii + 37])
      break;
    misc_status_bar_tilemap[ii + 37] = -4;
    misc_status_bar_tilemap[ii + 10] = -4;
  }
  do {
    uint8 v12 = 2 * misc_status_bar_tilemap[ii + 37];
    misc_status_bar_tilemap[ii + 10] = kUpdateStatusBarCounters_BonusStarCounterNumberTiles[v12];
    misc_status_bar_tilemap[ii++ + 37] = kUpdateStatusBarCounters_BonusStarCounterNumberTiles[v12 + 1];
  } while (ii != 2);
  UpdateStatusBarCounters_DrawItemBoxItem();
  if (player_current_character) {
    for (uint8 jj = 4; (jj & 0x80) == 0; --jj)
      misc_status_bar_tilemap[jj] = kUpdateStatusBarCounters_DATA_008DF5[jj];
  }
  uint8 v14 = counter_yoshi_coins_to_display;
  if (counter_yoshi_coins_to_display >= 5)
    v14 = 0;
  uint8 r0 = v14 - 1;
  for (uint8 kk = 0; kk != 4; ++kk) {
    uint8 v16 = -4;
    if ((r0 & 0x80) == 0)
      v16 = 46;
    misc_status_bar_tilemap[kk + 6] = v16;
    --r0;
  }
}

void UpdateStatusBarCounters_Loop2(uint8 k, uint8 j, uint16 r0w, uint16 r2w) {  // 009012
  do {
    for (misc_status_bar_tilemap[k + 28] = 0;; ++misc_status_bar_tilemap[k + 28]) {
      int v2 = j >> 1;
      bool v3 = r2w >= kUpdateStatusBarCounters_DATA_008FFA[v2 + 1];
      uint16 r6 = r2w - kUpdateStatusBarCounters_DATA_008FFA[v2 + 1];
      uint16 v4 = !v3 + kUpdateStatusBarCounters_DATA_008FFA[v2];
      uint16 r4 = r0w - v4;
      if (r0w < v4)
        break;
      r2w = r6;
      r0w = r4;
    }
    ++k;
    j += 4;
  } while (j != 24);
}

PairU16 HexToDec(uint8 a) {  // 009045
  uint8 v1 = 0;
  while (a >= 0xA) {
    a -= (a < 0xA) + 10;
    ++v1;
  }
  return MakePairU16_AX(a, v1);
}

void UpdateStatusBarCounters_009051(uint8 k, uint8 j, uint16 r2w) {  // 009051
  do {
    for (misc_status_bar_tilemap[k + 28] = 0;; ++misc_status_bar_tilemap[k + 28]) {
      int v2 = j >> 1;
      bool v3 = r2w >= kUpdateStatusBarCounters_DATA_008FFA[v2 + 1];
      uint16 r6 = r2w - kUpdateStatusBarCounters_DATA_008FFA[v2 + 1];
      if (!v3)
        break;
      r2w = r6;
    }
    ++k;
    j += 4;
  } while (j != 24);
}

void UpdateStatusBarCounters_DrawItemBoxItem() {  // 009079
  uint8 v0 = -32;
  if ((misc_nmito_use_flag & 0x40) != 0) {
    v0 = 0;
    if (misc_nmito_use_flag != 0xC1)
      get_OamEnt(oam_buf, 0)->ypos = -16;
  }
  uint8 r1 = v0;
  if (player_current_item_box) {
    uint8 r0 = kUpdateStatusBarCounters_ItemBoxItemProperties[player_current_item_box - 1];
    if (player_current_item_box == 3)
      r0 = kUpdateStatusBarCounters_StarPaletteFrames[(counter_global_frames >> 1) & 3];
    uint8 v1 = r1;
    OamEnt *oam = get_OamEnt(oam_buf, r1);
    oam->xpos = 120;
    oam->ypos = 15;
    oam->flags = r0 | 0x30;
    oam->charnum = kUpdateStatusBarCounters_ItemBoxItemTile[player_current_item_box - 1];
    sprites_oamtile_size_buffer[v1 >> 2] = 2;
  }
}

void GameMode12_PrepareLevel_00919B() {  // 00919b
  if (player_current_state == 10) {
    GameMode14_InLevel_HandlePlayerState();
  } else if (!counter_sublevels_entered) {
    counter_green_star_block = 30;
  }
}

void DrawLoadingLetters() {  // 0091b1
  BufferLoadingLetterTiles();
  uint8 v0 = 0;
  uint8 v1 = -80;
  if (flag_active_bonus_game) {
    counter_timer_hundreds = 0;
    counter_timer_tens = 0;
    counter_timer_ones = 0;
    v0 = 38;
    v1 = -92;
  }
  uint16 r0w = v1;
  uint8 v2 = 112;
  do {
    r0w = DrawLoadingLetters_Draw(v0++, v2, r0w);
    if (v0 == 8 && player_current_character)
      v0 = 14;
    v2 -= 8;
  } while (v2);
  CompressOamEntExt();
}

uint16 DrawLoadingLetters_Draw(uint8 k, uint8 j, uint16 r0w) {  // 0091e9
  OamEnt *oam = get_OamEnt(oam_buf, j);
  oam[66].flags = kDrawLoadingLetters_TileData_TopProp[k];
  oam[67].flags = kDrawLoadingLetters_TileData_BottomProp[k];
  oam[66].xpos = r0w;
  oam[67].xpos = r0w;
  r0w -= 8;
  uint8 v4 = j >> 2;
  sprites_oamtile_size_buffer[v4 + 66] = (r0w >> 8) & 1;
  sprites_oamtile_size_buffer[v4 + 67] = (r0w >> 8) & 1;
  int8 v6 = kDrawLoadingLetters_TileData[k];
  if (v6 >= 0) {
    OamEnt *v7 = get_OamEnt(oam_buf, j);
    v7[66].charnum = v6;
    v7[67].charnum = kDrawLoadingLetters_TileData_BottomTiles[k];
    v7[66].ypos = 104;
    v7[67].ypos = 112;
  }
  return r0w;
}

void UpdateEntirePalette() {  // 00922f
  palettes_palette_mirror[0] = 0;
  RtlUpdatePalette(palettes_palette_mirror, 0, 0x100);
}

void SetupHDMAWindowingEffects() {  // 009250
  RtlHdmaSetup(7, 0x41, 0x26, 0x927c, 0);
  SetupHDMAWindowingEffects_EndHDMA();
}

void SetupHDMAWindowingEffects_EndHDMA() {  // 009260
  mirror_hdmaenable = 0;
  SetupHDMAWindowingEffects_ClearWindowTable();
}

void SetupHDMAWindowingEffects_ClearWindowTable() {  // 009263
  for (uint16 i = 446; (i & 0x8000) == 0; i -= 2) {
    misc_hdmawindow_effect_table[i] = -1;
    misc_hdmawindow_effect_table[i + 1] = 0;
  }
}

void sub_9291(uint16 k) {  // 009291
  do {
    misc_hdmawindow_effect_table[k] = 0;
    misc_hdmawindow_effect_table[k + 1] = -1;
    k += 2;
  } while (k < 0x1C0);
  SetupHDMAWindowingEffects_0092A0();
}

void SetupHDMAWindowingEffects_0092A0() {  // 0092a0
  mirror_hdmaenable = 0x80;
}

void SetupHDMAWindowingEffects_0092A8() {  // 0092a8
  SetupHDMAWindowingEffects_ClearWindowTable();
  sub_9291(0x198);
}


void SetEnemyRollcallParallaxHDMA_Init() {  // 0092b2
  misc_hdmawindow_effect_table[0] = 88;
  misc_hdmawindow_effect_table[10] = 88;
  misc_hdmawindow_effect_table[20] = 88;
  misc_hdmawindow_effect_table[9] = 0;
  misc_hdmawindow_effect_table[19] = 0;
  misc_hdmawindow_effect_table[29] = 0;
  RtlHdmaSetup(5, 0x2, 0xd, 0x4a0, 0);
  RtlHdmaSetup(6, 0x2, 0xf, 0x4aa, 0);
  RtlHdmaSetup(7, 0x2, 0x11, 0x4b4, 0);
  mirror_hdmaenable = 0xE0;
  SetEnemyRollcallParallaxHDMA();
}

void SetEnemyRollcallParallaxHDMA() {  // 0092ed
  int16 v0 = 8;
  uint16 v1 = 20;
  do {
    int16 v2 = *(uint16 *)((int8 *)&mirror_current_layer1_xpos + (uint16)v0);
    *(uint16 *)&misc_hdmawindow_effect_table[v1 + 1] = v2;
    *(uint16 *)&misc_hdmawindow_effect_table[v1 + 4] = v2;
    *(uint16 *)&misc_hdmawindow_effect_table[v1 + 7] = get_PointU16(misc_layer1_pos, v0)->x;
    v1 -= 10;
    v0 -= 4;
  } while (v0 >= 0);
}

void InitAndMainLoop_ProcessGameMode() {  // 009322
  kInitAndMainLoop_GameModePtrs[misc_game_mode]();
}

void TurnOffIO() {  // 00937d
//  WriteReg(NMITIMEN, 0);
//  WriteReg(HDMAEN, 0);
  RtlPpuWrite(INIDISP, 0x80);
}

void GameMode00_LoadNintendoPresents() {  // 009391
  ClearLayer3Tilemap();
  SetStandardPPUSettings();
  UploadGraphicsFiles_Layer3();
  uint8 v0 = 12;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, v0);
    oam->xpos = kGameMode00_LoadNintendoPresents_XDisp[i];
    oam->ypos = 112;
    oam->charnum = kGameMode00_LoadNintendoPresents_Tiles[i];
    oam->flags = 48;
    v0 -= 4;
  }
  oam_buf_ext[0] = -86;
  io_sound_ch3 = 1;
  timer_title_screen_input_timer = 64;
  GameMode00_LoadNintendoPresents_0093CA();
}

void GameMode00_LoadNintendoPresents_0093CA() {  // 0093ca
  mirror_screen_display_register = 15;
  misc_mosaic_direction = 1;
  misc_sprite_palette_setting = 0;
  BufferPalettesRoutines_Levels();
  palettes_background_color = 0;
  UpdateEntirePalette();
  misc_blinking_cursor_pos = 0;
  GameMode00_LoadNintendoPresents_0093EA(0x10, 4);
}

void GameMode00_LoadNintendoPresents_0093EA(uint8 k, uint8 j) {  // 0093ea
  misc_nmito_use_flag = 1;
  SetVisibleLayers(0x20, k, j);
  ++misc_game_mode;
}

void SetVisibleLayers(uint8 a, uint8 k, uint8 j) {  // 0093fd
  RtlPpuWrite(CGADSUB, a);
  mirror_color_math_select_and_enable = a;
  RtlPpuWrite(TM, k);
  RtlPpuWrite(TS, j);
  RtlPpuWrite(TMW, 0);
  RtlPpuWrite(TSW, 0);
}

void GameMode01_ShowNintendoPresents() {  // 00940f
  if (!--timer_title_screen_input_timer) {
    GraphicsDecompressionRoutines_DecompressGFX32And33();
    ++misc_game_mode;
  }
}

void GameMode06_CircleEffect() {  // 00941b
  CheckWhichControllersArePluggedIn();
  if (GameMode07_TitleScreenDemo_009CBE()) {
    GameMode06_CircleEffect_009440(0xEC);
    ++misc_game_mode;
    GameMode07_TitleScreenDemo_InitializeFileSelect();
  } else if (!--timer_title_screen_input_timer) {
    ++timer_title_screen_input_timer;
    if ((uint8)(timer_hdmawindow_scaling_factor + 4) < 0xF0)
      GameMode06_CircleEffect_009440(timer_hdmawindow_scaling_factor + 4);
    else
      ++misc_game_mode;
  }
}

void GameMode06_CircleEffect_009440(uint8 a) {  // 009440
  timer_hdmawindow_scaling_factor = a;
  GameMode06_CircleEffect_009443();
}

void GameMode06_CircleEffect_009443() {  // 009443
  uint8 r0 = 0x80;
  uint8 r1 = 112;
  UpdateHDMAWindowBuffer_KeyholeEntry(UpdateHDMAWindowBuffer_SetCircleHDMAPointer(), r0, r1);
}

void GameMode19_Cutscene() {  // 009468
  ClearLayer3Tilemap();
  ClearOverworldAndCutsceneRAM();
  SetStandardPPUSettings();
  misc_level_tileset_setting = 24;
  graphics_level_sprite_graphics_setting = 20;
  misc_background_color_setting = kGameMode19_Cutscene_SkyColorSetting[misc_currently_active_boss_end_cutscene - 1];
  misc_bgpalette_setting = kGameMode19_Cutscene_BGPaletteSetting[misc_currently_active_boss_end_cutscene - 1];
  misc_sprite_palette_setting = 0;
  misc_fgpalette_setting = 1;
  if (misc_currently_active_boss_end_cutscene == 8) {
    UploadBigLayer3LettersToVRAM();
    graphics_stripe_image_to_upload = -46;
    LoadStripeImage();
    HandleSPCUploads_UploadCreditsMusicBank();
    BufferCreditsBackgrounds();
    SetupHDMAWindowingEffects_EndHDMA();
    ++misc_level_tileset_setting;
    ++graphics_level_sprite_graphics_setting;
  } else {
    io_music_ch1 = 21;
    graphics_stripe_image_to_upload = kGameMode19_Cutscene_BGToUse[misc_currently_active_boss_end_cutscene - 1];
    LoadStripeImage();
    graphics_stripe_image_to_upload = -49;
    LoadStripeImage();
    player_xpos = 144;
    player_ypos = 88;
    ++player_carrying_something_flag2;
  }
  UploadGraphicsFiles();
  BufferPalettesRoutines_Levels();
  UpdateEntirePalette();
  for (int8 i = 11; i >= 0; --i)
    *((uint8 *)&mirror_current_layer1_xpos + (uint8)i) = 0;
  sprites_tile_priority = 32;
  InitializeLevelRAM();
  player_facing_direction = 0;
  player_in_air_flag = 0;
  SetPlayerPose();
  GameMode23_LoadEnemyRollcallScreen_009622(0x17, 0);
  GameMode19_Cutscene_GameMode1BEntry();
}

void GameMode19_Cutscene_GameMode1BEntry() {  // 0094fd
  ResetSpritesFunc(0);
  if (misc_currently_active_boss_end_cutscene == 8) {
    GameMode1B_EndingCinema_Bank0C();
  } else {
    GameMode19_Cutscene_0CC97E();
    uint16 v1 = mirror_current_layer1_xpos;
    uint16 v0 = mirror_current_layer1_ypos;
    mirror_current_layer1_xpos = mirror_current_layer2_xpos;
    mirror_current_layer1_ypos = mirror_current_layer2_ypos;
    PlayerDraw();
    mirror_current_layer1_ypos = v0;
    mirror_current_layer1_xpos = v1;
    player_current_state = 12;
    GameMode14_InLevel_00C47E();
  }
  CompressOamEntExt();
}

void UploadBigLayer3LettersToVRAM() {  // 00955e
  const uint8 *p0 = GraphicsDecompress(0x2F);
  const uint8 *v1 = &p0[0];
  SmwCopyToVram(0x4600, v1, 512 * 2);
}

void GameMode1D_LoadYoshisHouse() {  // 009583
  ++misc_currently_active_boss_end_cutscene;
  GameMode11_LoadSublevel_0096CF(1, 0x28);
  --misc_game_mode;
  graphics_level_sprite_graphics_setting = 22;
  GameMode12_PrepareLevel();
  --misc_game_mode;
  TurnOffIO();
  ClearLayer3Tilemap();
  UploadGraphicsFiles_Layer3();
  GameMode1D_LoadYoshisHouse_InitializeYoshisHouseSceneRAM();
  GameMode23_LoadEnemyRollcallScreen_00961E();
  GameMode1D_LoadYoshisHouse_GameMode1FEntry();
}

void GameMode1D_LoadYoshisHouse_GameMode1FEntry() {  // 0095ab
  ResetSpritesFunc(0);
  GameMode1D_LoadYoshisHouse_Bank0C();
  ++counter_local_frames;
  LmHook_LevelTileAnimations();
  CompressOamEntExt();
}

void GameMode21_DelayEnemyRollcall() {  // 0095bc
  GameMode21_DelayEnemyRollcall_Bank03();
}

void GameMode23_LoadEnemyRollcallScreen() {  // 0095c1
  ClearLayer3Tilemap();
  ClearOverworldAndCutsceneRAM();
  SetStandardPPUSettings();
  GetLayer1And2PointersForEnemyRollcall();
  LoadSublevel();
  if (counter_enemy_rollcall_screen == 10) {
    graphics_level_sprite_graphics_setting = 19;
  } else if (counter_enemy_rollcall_screen == 12) {
    graphics_level_sprite_graphics_setting = 23;
  }
  UploadGraphicsFiles();
  BufferPalettesRoutines_Levels();
  InitializeLevelLayer1And2Tilemaps();
  InitializeLevelTileAnimations();
  InitializeEnemyRollcallLayerPositions();
  if (counter_enemy_rollcall_screen == 12) {
    for (uint8 i = 11; (i & 0x80) == 0; --i) {
      *((uint8 *)&palettes_palette_mirror[130] + i) = *((uint8 *)kGlobalPalettes_BowserEnd + i);
      *((uint8 *)&palettes_palette_mirror[146] + i) = *((uint8 *)kGlobalPalettes_B3CC + i);
    }
  }
  UpdateEntirePalette();
  SetEnemyRollcallParallaxHDMA_Init();
  LoadStripeImage();
  GameMode25_ShowEnemyRollcallScreen();
  GameMode23_LoadEnemyRollcallScreen_00961E();
}

void GameMode23_LoadEnemyRollcallScreen_00961E() {  // 00961e
  GameMode23_LoadEnemyRollcallScreen_009622(0x15, 2);
}

void GameMode23_LoadEnemyRollcallScreen_009622(uint8 k, uint8 j) {  // 009622
  SetKeepGameModeActiveTimer_OneFrame();
  mirror_bgmode_and_tile_size_setting = 9;
  GameMode00_LoadNintendoPresents_0093EA(k, j);
}

void GameMode25_ShowEnemyRollcallScreen() {  // 00962c
  player_number_of_tiles_to_update = 0;
  SetEnemyRollcallParallaxHDMA();
  ResetSpritesFunc(0);
  GameMode25_ShowEnemyRollcallScreen_Bank0C();
  CompressOamEntExt();
}

void GameMode27_LoadTheEnd() {  // 00963d
  ClearLayer3Tilemap();
  ClearOverworldAndCutsceneRAM();
  SetStandardPPUSettings();
  UploadBigLayer3LettersToVRAM();
  graphics_level_sprite_graphics_setting = 25;
  misc_background_color_setting = 3;
  misc_bgpalette_setting = 3;
  UploadGraphicsFiles();
  BufferPalettesRoutines_Levels();
  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    *((uint8 *)&palettes_palette_mirror[210] + i) = *((uint8 *)kGlobalPalettes_EndingLuigi + i);
    *((uint8 *)&palettes_palette_mirror[226] + i) = *((uint8 *)kGlobalPalettes_EndingMario + i);
    *((uint8 *)&palettes_palette_mirror[242] + i) = *((uint8 *)kGlobalPalettes_EndingToadstool + i);
  }
  UpdateEntirePalette();
  graphics_stripe_image_to_upload = -43;
  LoadStripeImage();
  DrawingTheEndMarioLuigiAndPeach();
  CompressOamEntExt();
  GameMode23_LoadEnemyRollcallScreen_009622(0x14, 0);
}

void GameMode29_DoNothingOnTheEndScreen() {  // 00968d
  ;
}

void GameMode10_BufferLevelLoadMessage() {  // 00968e
  ClearLayer3Tilemap();
  if (flag_active_bonus_game || !(misc_intro_level_flag | (uint8)(flag_show_player_start | counter_sublevels_entered)) &&
                                    (uint8)ow_tile_player_is_standing_on != 86) {
    DrawLoadingLetters();
  }
  GameMode00_LoadNintendoPresents_0093CA();
}

void GameMode11_LoadSublevel_GameMode03Entry() {  // 0096ae
  InitializeFirst8KBOfRAM();
  for (int8 i = 7; i >= 0; --i)
    misc_currently_loaded_sprite_graphics_files[(uint8)i] = -1;
  if (!misc_intro_level_flag) {
    HandleSPCUploads_UploadOverworldMusicBank();
    io_music_ch1 = 1;
  }
  GameMode11_LoadSublevel_0096CF(0, 0xEB);
}

void GameMode11_LoadSublevel_0096CF(uint8 j, uint8 a) {  // 0096cf
  misc_intro_level_flag = a;
  ow_players_map[0] = j;
  GameMode11_LoadSublevel_0096D5();
}

void GameMode11_LoadSublevel_0096D5() {  // 0096d5
  DamagePlayer_DisableButtons();
  if (!counter_sublevels_entered && flag_show_player_start)
    LoadOverworldLayer1AndEvents();
  flag_disable_layer3_scroll = 0;
  pointer_current_overworld_process = 0;
  timer_wait_before_score_tally = 80;
  if (LoadLevel())
    return;
  for (uint8 i = 7; (i & 0x80) == 0; --i)
    LOBYTE(get_PointU16(misc_layer1_pos, i)->x) = *((uint8 *)&mirror_current_layer1_xpos + i);
  HandleSPCUploads_008134();
  InitializeLevelRAM();
  bool skip_it = false;
  if (g_lunar_magic)
    skip_it = LmHook_GameMode11_LoadSublevel();
  else
    camera_last_screen_horiz = 32;
  if (!skip_it)
    GameMode11_LoadSublevel_00A796();
  ++flag_scroll_up_to_player;
  HandleStandardLevelCameraScroll();
  LoadSublevel();
  if (misc_intro_level_flag) {
    if (misc_intro_level_flag != 0xE9)
      goto LABEL_14;
    misc_music_register_backup = 19;
  }
  uint8 v1 = misc_music_register_backup;
  if (misc_music_register_backup < 0x40) {
    if (misc_nmito_use_flag == 0xC1)
      v1 = 22;
    io_music_ch1 = v1;
  }
  misc_music_register_backup = v1 & 0xBF;
LABEL_14:
  mirror_screen_display_register = 0;
  misc_mosaic_direction = 0;
  ++misc_game_mode;
}

PairU16 OwPrompt03_OverworldLifeExchanger_00974C(uint8 a) {  // 00974c
  PairU16 v1 = HexToDec(a);
  return MakePairU16_AX(LOBYTE(v1.first), LOBYTE(v1.second));
}

void GameMode16_LoadDeathMessage() {  // 009750
  ClearLayer3Tilemap();
  BufferLoadingLetterTiles();
  GameMode00_LoadNintendoPresents_0093CA();
}

void GameMode17_ShowDeathMessage() {  // 009759
  ResetSpritesFunc(0);
  uint8 v0 = timer_display_death_message_animation;
  if (timer_display_death_message_animation) {
    v0 = timer_display_death_message_animation - 4;
  } else if (!--timer_time_to_display_death_message) {
    if ((player_current_life_count & 0x80) != 0) {
      yoshi_carry_over_levels_flag = 0;
      if (((players_lives[1] | players_lives[0]) & 0x80) != 0) {
        for (uint8 i = 12; (i & 0x80) == 0; --i) {
          flag_collected5_yoshi_coins[i] = 0;
          g_ram[6 + i] = 0;
          flag_collected_moons[i] = 0;
        }
        ++flag_show_continue_and_end;
      }
    }
    GameMode0A_PlayerSelect_009E62();
    return;
  }
  timer_display_death_message_animation = v0;
  uint16 r0w = v0 + 0xa0;
  uint8 v2 = misc_death_message_to_display;
  uint8 v3 = 72;
  do {
    if (v3 == 40)
      r0w = 120 - timer_display_death_message_animation;
    DrawLoadingLetters_Draw(v2++, v3, r0w);
    r0w -= 8;
    v3 -= 8;
  } while (v3);
  CompressOamEntExt();
}

void GameMode12_PrepareLevel_PrepareMode7Level() {  // 0097bc
  uint8 v0;

  mirror_screen_display_register = 15;
  mirror_mosaic_size_and_bgenable = 0;
  GameModeXX_FadeInOrOut_GMMosaic();
  misc_m7_angle = 0x2020;
  LOBYTE(shaking_layer1_disp_y) = 0;
  ClearLayer3Tilemap();
  misc_level_tileset_setting = 0xff;
  GameMode12_PrepareLevel_UploadTiltingPlatformTilemap();
  if ((misc_nmito_use_flag & 0x40) == 0) {
    BufferPalettesRoutines_IggyLarryPlatform();
    SetupHDMAWindowingEffects_0092A8();
    GameMode12_PrepareLevel_009A3D(0x50);
    player_xpos = 80;
    player_ypos = -48;
    mirror_current_layer1_xpos = 0;
    PointU16 *pt = get_PointU16(misc_layer1_pos, 0);
    pt->x = 0;
    mirror_current_layer1_ypos = -112;
    pt->y = -112;
    mirror_m7_center_xpos = 128;
    mirror_m7_center_ypos = 80;
    mirror_m7_xpos = 128;
    mirror_m7_ypos = 16;
    goto LABEL_8;
  }
  GameMode12_PrepareLevel_PrepareNonIggyLarryRoom();
  if (misc_currently_active_boss < 3) {
    player_current_layer_priority = 3;
    mirror_oamaddress_lo = 0xc8;
    v0 = 18;
    goto LABEL_6;
  }
  if (misc_currently_active_boss != 3) {
LABEL_8:
    v0 = 19;
    goto LABEL_9;
  }
  v0 = 24;
LABEL_6:
  --misc_level_tileset_setting;
LABEL_9:
  graphics_level_sprite_graphics_setting = v0;
  UploadGraphicsFiles();
  RtlPpuWrite(TMW, 0x11);
  RtlPpuWrite(TS, 0);
  RtlPpuWrite(TSW, 0);
  mirror_bg1_and2_window_mask_settings = 2;
  mirror_object_and_color_window_settings = 50;
  mirror_color_math_initial_settings = 32;
  InitializeStatusBarTilemap();
  ManipulateMode7Image();
  GameMode12_PrepareLevel_009860();
}

void GameMode12_PrepareLevel_009860() {  // 009860
  PlayerDraw();
  UpdateCurrentPlayerPositionRAM();
  GameMode14_InLevel_HandlePlayerState();
  player_yspeed = 0;
  ProcessNormalSprites();
  ResetSpritesFunc(0);
}

void GameMode14_InLevel_InMode7Level() {  // 00987d
  ManipulateMode7Image();
  if ((misc_nmito_use_flag & 0x40) != 0) {
    if (misc_nmito_use_flag & 1 ||
        (HandleStandardLevelCameraScroll(), HandleScrollSpriteAndLayer3Scrolling(), misc_currently_active_boss == 4)) {
      ResetSpritesFunc(0);
    } else {
      GameMode14_InLevel_0086C7();
      GameMode14_InLevel_02827D();
    }
  } else {
    ResetSpritesFunc(0);
    GameMode14_InLevel_03C0C6();
  }
}

void UploadMode7KoopaBossesAndLavaAnimation() {  // 0098a9
  int8 v0 = misc_nmito_use_flag & 1;
  if (!(misc_nmito_use_flag & 1)) {
    uint8 v1 = (counter_local_frames >> 2) & 6;
    SmwCopyToVram(0x7800, g_ram + kLevelTileAnimations_FrameData[(v1 + 0xa0) >> 1], 0x80);    
    v0 = 0;
  }
  uint16 v2 = 4;
  uint8 v3 = 6;
  if (v0) {
    v2 = 8;
    v3 = 22;
  }
  uint16 r0w = v2;
  uint16 r2w = 0xc680;
  do {
    SmwCopyToVramLow(kUploadMode7KoopaBossesAndLavaAnimation_VRAMAddressToUpload[v3 >> 1],
        g_ram + r2w, r0w);
    r2w += r0w;
    v3 -= 2;
  } while ((v3 & 0x80) == 0);
}

void GameMode12_PrepareLevel_PrepareNonIggyLarryRoom() {  // 009925
  int16 v7;
  int16 v10;

  HIBYTE(player_ypos) = 0;
  player_xpos = 32;
  mirror_current_layer1_xpos = 0;
  PointU16 *pt = get_PointU16(misc_layer1_pos, 0);
  pt->x = 0;
  mirror_current_layer1_ypos = 0;
  pt->y = 0;
  mirror_m7_center_xpos = 128;
  mirror_m7_center_ypos = 160;
  BufferPalettesRoutines_ReznorAndMode7KoopaBosses();
  ProcessNormalSprites();
  uint8 v1 = -64;
  int8 v2 = -96;
  if (misc_nmito_use_flag & 1) {
    flag_layer1_horiz_scroll_level_setting = 0;
  } else {
    uint16 v3 = 704;
    int16 v4 = kPlayerState00_DATA_00F8E8[misc_currently_active_boss];
    if (v4 < 0)
      v3 = 0xfb80;
    if (v4 == 18)
      v3 = 800;
    uint16 r0w = v3;
    uint16 v5 = 0;
    int16 v6 = 0xc05a;
    do {
      *(uint16 *)&stripe_image_upload_data[v5] = v6;
      int8 v8 = v6;
      LOBYTE(v7) = HIBYTE(v6);
      HIBYTE(v7) = v8;
      v7 += 128;
      uint8 v9 = v7;
      LOBYTE(v7) = HIBYTE(v7);
      HIBYTE(v7) = v9;
      *(uint16 *)&stripe_image_upload_data[v5 + 132] = v7;
      v10 = __PAIR16__(v7, v9) - r0w;
      int8 v11 = v10;
      LOBYTE(v10) = HIBYTE(v10);
      HIBYTE(v10) = v11;
      *(uint16 *)&stripe_image_upload_data[v5 + 264] = v10;
      *(uint16 *)&stripe_image_upload_data[v5 + 2] = 0x7f00;
      *(uint16 *)&stripe_image_upload_data[v5 + 134] = 0x7f00;
      *(uint16 *)&stripe_image_upload_data[v5 + 266] = 0x7f00;
      int16 v12 = 16;
      do {
        *(uint16 *)&stripe_image_upload_data[v5 + 4] = 0x38a2;
        *(uint16 *)&stripe_image_upload_data[v5 + 6] = 0x38a3;
        *(uint16 *)&stripe_image_upload_data[v5 + 68] = 0x38b2;
        *(uint16 *)&stripe_image_upload_data[v5 + 70] = 0x38b3;
        *(uint16 *)&stripe_image_upload_data[v5 + 136] = 0x2c80;
        *(uint16 *)&stripe_image_upload_data[v5 + 138] = 0x2c81;
        *(uint16 *)&stripe_image_upload_data[v5 + 200] = 0x2c82;
        *(uint16 *)&stripe_image_upload_data[v5 + 202] = 0x2c83;
        *(uint16 *)&stripe_image_upload_data[v5 + 268] = 0x28a0;
        *(uint16 *)&stripe_image_upload_data[v5 + 270] = 0x28a1;
        *(uint16 *)&stripe_image_upload_data[v5 + 332] = 0x28b0;
        *(uint16 *)&stripe_image_upload_data[v5 + 334] = 0x28b1;
        v5 += 4;
        --v12;
      } while (v12);
      v5 += 332;
      v6 = 0xc05e;
    } while (v5 < 0x318);
    *(uint16 *)&stripe_image_upload_data[v5] = 255;
    LoadStripeImage();
    v1 = -80;
    v2 = -112;
  }
  LOBYTE(player_ypos) = v2;
  GameMode12_PrepareLevel_009A1F(v1);
  SetupHDMAWindowingEffects_ClearWindowTable();
  if (misc_nmito_use_flag & 1)
    SetupHDMAWindowingEffects_0092A0();
  else
    sub_9291(0x1BE);
}

void GameMode12_PrepareLevel_009A1F(uint8 k) {  // 009a1f
  int8 v1 = 16;
  do {
    blocks_map16_table_lo[k] = 50;
    blocks_map16_table_lo[k + 432] = 50;
    blocks_map16_table_hi[k] = 50;
    blocks_map16_table_hi[k++ + 432] = 50;
    --v1;
  } while (v1);
  if (k == 0xC0)
    GameMode12_PrepareLevel_009A3D(0xD0);
}

void GameMode12_PrepareLevel_009A3D(uint8 k) {  // 009a3d
  int8 v1 = 16;
  do {
    blocks_map16_table_lo[k] = 5;
    blocks_map16_table_lo[k++ + 432] = 5;
    --v1;
  } while (v1);
}

void CheckWhichControllersArePluggedIn() {  // 009a74
  uint8 v1 = ReadReg(JOYA);
  uint8 Reg = ReadReg(JOYB);
  uint8 v2 = (2 * Reg + v1) & 3;
  if (v2) {
    if (v2 == 3)
      v2 = -125;
    --v2;
  }
  io_controllers_plugged_in = v2;
}

void GameMode04_PrepareTitleScreen() {  // 009a8b
  CheckWhichControllersArePluggedIn();
  GameMode12_PrepareLevel();
  counter_timer_hundreds = 0;
  ClearLayer3Tilemap();
  graphics_stripe_image_to_upload = 3;
  LoadStripeImage();
  BufferPalettesRoutines_TitleScreen();
  UpdateEntirePalette();
  LoadOverworldSprites();
  misc_nmito_use_flag = 1;
  mirror_bg1_and2_window_mask_settings = 51;
  mirror_bg3_and4_window_mask_settings = 0;
  mirror_object_and_color_window_settings = 35;
  mirror_color_math_initial_settings = 18;
  GameMode06_CircleEffect_009443();
  timer_title_screen_input_timer = 16;
}

uint8 HandleMenuCursor_Main_ReturnsTwice(uint8 j) {  // 009ad0
  ++counter_blinking_cursor_frame;
  HandleMenuCursor_009E82(j);
  uint8 result = misc_blinking_cursor_pos;
  if ((io_controller_press1 & 0x90) != 0 || (io_controller_press2 & 0x80) != 0) {
    io_sound_ch3 = 1;
    misc_blinking_cursor_pos = 0;
    return result;
  } else {
    uint8 what = (io_controller_press1 | ((io_controller_press1 & 0x20) >> 3)) & 0xC;
    if (what != 0) {
      io_sound_ch3 = 6;
      counter_blinking_cursor_frame = 0;
      uint8 v2 = misc_blinking_cursor_pos + kHandleMenuCursor_DATA_009AC8[(what >> 2) - 1];
      if ((int8)v2 < 0)
        v2 = player_collision_var8a - 1;
      if (v2 >= player_collision_var8a)
        misc_blinking_cursor_pos = 0;
      else
        misc_blinking_cursor_pos = v2;
    }
    return 0xff;
  }
}

void GameMode09_EraseFile() {  // 009b1a
  uint8 v0;
  uint16 v3;

  FileSelectColorMath(g_lunar_magic ? palettes_background_color : 0x39C9, 0x60);
  if (((io_controller_press2 | io_controller_press1) & 0x40) != 0) {
    Gamemode_9_A_Common();
  } else {
    if ((v0 = HandleMenuCursor_Main_ReturnsTwice(8)) == 0xff)
      return;
    if (v0 == 3) {
      for (uint8 i = 2; (i & 0x80) == 0; --i) {
        int8 v2 = misc_which_file_to_erase & 1;
        misc_which_file_to_erase >>= 1;
        if (v2) {
          uint8 v6 = i;
          HIBYTE(v3) = kSaveFileLocations_Hi[i];
          LOBYTE(v3) = kSaveFileLocations_Lo[i];
          uint16 v4 = v3;
          int16 v5 = 143;
          do {
            g_sram[v4] = 0;
            g_sram[v4++ + 429] = 0;
            --v5;
          } while (v5);
          i = v6;
        }
      }
      RtlWriteSram();
      GameMode07_TitleScreenDemo_FadeOutToTitleScreen();
    } else {
      misc_blinking_cursor_pos = v0;
      misc_which_file_to_erase |= kGameMode09_EraseFile_DATA_009B17[v0];
      BufferFileSelectText_Entry3(0, misc_which_file_to_erase);
    }
  }
}

void Gamemode_9_A_Common() {  // 009b2c
  --misc_game_mode;
  --misc_game_mode;
  misc_blinking_cursor_pos = 0;
  GameMode07_TitleScreenDemo_InitializeSaveData();
}

void DisplayingContinueEnd(uint8 a) {  // 009b88
  uint8 t;

  int8 v1 = a - 1;
  if (v1) {
    if (v1 == 1) {
      if ((t = HandleMenuCursor_Main_ReturnsTwice(0)) == 0xff)
        return;
      if (t)
        GameMode07_TitleScreenDemo_FadeOutToTitleScreen();
      else
        GameMode0A_PlayerSelect_Entry2();
    } else {
      Unreachable();
    }
  } else {
    GameMode08_FileSelect_SetStripeImage(0xC);
    ++flag_show_continue_and_end;
  }
}

void OwPrompt07_DisplayingSavePrompt() {  // 009bb0
  uint8 t;
  if ((t = HandleMenuCursor_Main_ReturnsTwice(6)) == 0xff)
    return;
  if (!t) {
    io_sound_ch3 = 0;
    io_sound_ch1 = 5;
    SaveGame();
  }
  CloseOwPrompt();
}

void SaveGame() {  // 009bc9
  uint16 v0 = PAIR16(kSaveFileLocations_Hi[misc_current_save_file], kSaveFileLocations_Lo[misc_current_save_file]);
  for (int k = v0; ; k += 288) {
    uint16 j = 0;
    uint16 sum = 0;
    do {
      uint8 v3 = ow_save_buffer[j];
      g_sram[k++] = v3;
      sum += v3;
    } while (++j < 0x8D);
    WORD(g_sram[k]) = 0x5a5a - sum;
    if (k >= 0x1ad)
      break;
  }
  RtlWriteSram();
}

void CloseOwPrompt() {  // 009c13
  ++pointer_display_overworld_prompt;
  ++flag_message_window_size_change_direction;
  GameMode08_FileSelect_SetStripeImage(0x1B);
}

void GameMode07_TitleScreenDemo() {  // 009c64
  CheckWhichControllersArePluggedIn();
  if (GameMode07_TitleScreenDemo_009CBE()) {
    GameMode07_TitleScreenDemo_InitializeFileSelect();
  } else {
    DamagePlayer_DisableButtons();

    if (HAS_LM_FEATURE(kLmFeature_CustomTitleScreenDemo)) {
      if (LmHook_CustomTitleScreenDemo())
        GameMode14_InLevel();
      else
        misc_game_mode = 2;
      return;
    }

    uint8 v0 = misc_title_screen_movement_data_index;
    if (!--timer_title_screen_input_timer) {
      timer_title_screen_input_timer = kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[misc_title_screen_movement_data_index + 1];
      v0 = misc_title_screen_movement_data_index + 2;
      misc_title_screen_movement_data_index += 2;
    }
    assert(v0 != 0);
    if (kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[v0 - 2] == 0xFF) {
      GameMode07_TitleScreenDemo_FadeOutToTitleScreen();
    } else {
      uint8 v1 = kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[v0 - 2] & 0xDF;
      io_controller_hold1 = v1;
      if (v1 == kGameMode07_TitleScreenDemo_ItrCntrlrSqnc[v0 - 2])
        v1 &= 0x9F;
      io_controller_press1 = v1;
      GameMode14_InLevel();
    }
  }
}

void GameMode07_TitleScreenDemo_FadeOutToTitleScreen() {  // 009c89
  misc_game_mode = 2;
}

void GameMode07_TitleScreenDemo_InitializeFileSelect() {  // 009c9f
  ResetSpritesFunc(0);
  RtlPpuWrite(TM, 4);
  RtlPpuWrite(TS, 0x13);

  // Ensure the black thing goes away at the intro
  RtlPpuWrite(WH0, 0);
  RtlPpuWrite(WH1, 0xff);

  mirror_hdmaenable = 0;
  GameMode07_TitleScreenDemo_InitializeSaveData();
}

void GameMode07_TitleScreenDemo_InitializeSaveData() {  // 009cb0
  misc_intro_level_flag = -23;
  InitializeSaveData();
  BufferFileSelectText();
  ++misc_game_mode;
}

uint8 GameMode07_TitleScreenDemo_009CBE() {  // 009cbe
  bool v0 = (io_controller_hold2 & 0xC0) == 0;
  if ((io_controller_hold2 & 0xC0) == 0)
    v0 = (io_controller_hold1 & 0xF0) == 0;
  return !v0;
}

void GameMode08_FileSelect() {  // 009cd1
  uint8 v0;

  FileSelectColorMath(g_lunar_magic ? palettes_background_color : 0x7393, 0x20);
  CheckWhichControllersArePluggedIn();
  if ((v0 = HandleMenuCursor_Main_ReturnsTwice(2)) == 0xff)
    return;

  ++*(uint16 *)&misc_game_mode;
  if (v0 == 3) {
    misc_which_file_to_erase = 0;
    BufferFileSelectText_Entry3(0, 0);
  } else {
    misc_current_save_file = v0;
    PairU16 v1 = BufferFileSelectText_009DB5(v0);
    uint16 first = v1.first;
    uint16 second = v1.second;
    if (first != 0xffff) {
      uint16 v6 = first;
      misc_intro_level_flag = 0;
      uint8 r0 = -113;
      do {
        g_sram[second++] = g_sram[first++];
        --r0;
      } while (r0);
      uint16 v4 = v6;
      for (uint16 i = 0; i < 0x8D; ++i)
        ow_save_buffer[i] = g_sram[v4++];

      RtlWriteSram();
    }
    ++misc_game_mode;
    GameMode08_FileSelect_SetStripeImage(0x12);
  }
}

void GameMode08_FileSelect_SetStripeImage(uint8 j) {  // 009d29
  graphics_stripe_image_to_upload = j;
  HandleMenuCursor_009ED4(0);
}

void FileSelectColorMath(uint16 a, uint8 j) {  // 009d30
  palettes_background_color = a;
  mirror_color_math_select_and_enable = j;
}

void BufferFileSelectText() {  // 009d38
  BufferFileSelectText_Entry3(0xCB, 0);
}


void BufferFileSelectText_Entry3(uint8 k, uint8 r5) {  // 009d3c
  uint16 kk = k;

  int16 v1 = k;
  for (uint16 i = 0; i != 204; ++i) {
    stripe_image_upload_data[i] = kFileSelectText_EraseFile[kk];
    kk = kk + 1;
  }
  uint8 r0 = 0x84;
  uint8 v3 = 2;
  do {
    int8 v4 = r5 & 1;
    r5 >>= 1;
    if (!v4) {
      uint16 first = BufferFileSelectText_009DB5(v3).first;
      if (first != 0xffff) {
        uint8 v7, second;
        if (g_sram[first + 140] < 0x60) {
          PairU16 v8 = HexToDec(g_sram[first + 140]);
          v7 = v8.first;
          second = v8.second;
        } else {
          second = 0x87;
          v7 = 0x88;
        }
        uint8 v9 = r0;
        stripe_image_upload_data[r0 + 4] = v7;
        if (!second)
          second = 0xfc;
        stripe_image_upload_data[v9 + 2] = second;
        stripe_image_upload_data[v9 + 3] = 56;
        stripe_image_upload_data[v9 + 5] = 56;
        int8 v10 = 3;
        do {
          *(uint16 *)&stripe_image_upload_data[v9 + 6] = 0x38fc;
          v9 += 2;
          --v10;
        } while (v10);
      }
    }
    r0 -= 36;
  } while ((int8)--v3 >= 0);
}

PairU16 BufferFileSelectText_009DB5(uint8 k) {  // 009db5
  uint16 v1;

  HIBYTE(v1) = kSaveFileLocations_Hi[k];
  LOBYTE(v1) = kSaveFileLocations_Lo[k];
  uint16 v2 = v1;
  uint16 i = v1 + 429;
  for (;;) {
    uint16 v9 = v2;
    uint16 v8 = i;
    uint16 sum = WORD(g_sram[v2 + 141]);
    uint16 v4 = 141;
    do {
      sum += g_sram[v2++];
    } while (--v4);

    if (sum == 0x5A5A)
      return MakePairU16(v9, v8);
    if (v9 >= 428)
      return MakePairU16(v9 == 428 ? v9 : 0xffff, v8);
    v2 = v8;
    i = v9;
  }
}

void GameMode0A_PlayerSelect() {  // 009dfa
  uint8 t;
  if (((io_controller_press2 | io_controller_press1) & 0x40) != 0) {
    --misc_game_mode;
    Gamemode_9_A_Common();
  } else {
    CheckWhichControllersArePluggedIn();
    if ((t = HandleMenuCursor_Main_ReturnsTwice(4)) == 0xff)
      return;
    flag_two_player_game = t;
    LoadSaveBufferData();
    LoadOverworldLayer2AndEventsTilemaps();
    GameMode0A_PlayerSelect_Entry2();
  }
}

void GameMode0A_PlayerSelect_Entry2() {  // 009e17
  io_music_ch1 = 0x80;
  players_lives[1] = -1;
  uint8 v0 = flag_two_player_game;
  do
    players_lives[v0--] = 4;
  while ((v0 & 0x80) == 0);
  player_current_life_count = 4;
  player_current_coin_count = 0;
  yoshi_carry_over_levels_flag = 0;
  player_current_power_up = 0;
  flag_show_continue_and_end = 0;
  *(uint16 *)players_coins = 0;
  *(uint16 *)players_power_up = 0;
  *(uint16 *)players_has_yoshi = 0;
  *(uint16 *)&player_current_item_box = 0;
  *(uint16 *)&player_mario_bonus_stars = 0;
  *(uint16 *)&player_mario_score_lo = 0;
  *(uint16 *)&player_luigi_score_lo = 0;
  player_mario_score_hi = 0;
  player_luigi_score_hi = 0;
  misc_exit_level_action = 0;
  player_current_character = 0;
  GameMode0A_PlayerSelect_009E62();
}

void GameMode0A_PlayerSelect_009E62() {  // 009e62
  SetKeepGameModeActiveTimer_OneFrame();
  misc_game_mode = 11;
}

void HandleMenuCursor_009E82(uint8 j) {  // 009e82
  uint8 v1 = kHandleMenuCursor_DATA_009E7E[misc_blinking_cursor_pos];
  if (((counter_blinking_cursor_frame ^ 0x1F) & 0x18) == 0)
    v1 = 0;
  uint8 r0w = v1;
  uint8 v2 = stripe_image_upload;
  int v3 = j >> 1;
  *(uint16 *)&player_collision_var8a = kHandleMenuCursor_DATA_009E6A[v3];
  uint16 r2w = *(uint16 *)&player_collision_var8a;
  uint16 v4 = kHandleMenuCursor_DATA_009E74[v3];
  do {
    WORD(stripe_image_upload_data[v2]) = swap16(v4);
    uint16 v10 = v4 + 64;
    WORD(stripe_image_upload_data[v2 + 2]) = 256;
    int16 v8 = 0x38fc;
    int8 v9 = r0w & 1;
    r0w >>= 1;
    if (v9)
      v8 = 0x3d2e;
    WORD(stripe_image_upload_data[v2 + 4]) = v8;
    v4 = v10;
    v2 += 6;
    --r2w;
  } while (r2w);
  HandleMenuCursor_009ED4(v2);
}

void HandleMenuCursor_009ED4(uint8 k) {  // 009ed4
  LOBYTE(stripe_image_upload) = k;
  stripe_image_upload_data[k] = -1;
}

void InitializeSaveData() {  // 009f06
  memset(ow_save_buffer, 0, 141);
  for (uint8 i = 7; (i & 0x80) == 0; --i)
    ow_save_buffer[LOBYTE(kInitializeSaveData_InitialLevelFlags[i])] = HIBYTE(kInitializeSaveData_InitialLevelFlags[i]);
  LmHook_InitializeSaveData();
  for (uint8 j = 21; (j & 0x80) == 0; --j)
    ow_save_buffer[j + 111] = kInitializeSaveData_InitialOWPlayerPos[j];
}

void SetKeepGameModeActiveTimer_OneFrame() {  // 009f29
  SetKeepGameModeActiveTimer_VariableFrames(1);
}

void SetKeepGameModeActiveTimer_VariableFrames(uint8 a) {  // 009f2b
  timer_keep_game_mode_active = a;
}

void GameModeXX_FadeInOrOut_MosaicFade() {  // 009f37
  if ((--timer_keep_game_mode_active & 0x80) != 0) {
    SetKeepGameModeActiveTimer_OneFrame();
    mirror_mosaic_size_and_bgenable += kGameModeXX_FadeInOrOut_DATA_009F31[misc_mosaic_direction];
    sub_9F4C(misc_mosaic_direction);
  }
}

void sub_9F4C(uint8 j) {  // 009f4c
  mirror_screen_display_register += kGameModeXX_FadeInOrOut_DATA_009F2F[j];
  if (mirror_screen_display_register == kGameModeXX_FadeInOrOut_DATA_009F33[j])
    GameModeXX_FadeInOrOut_GMMosaic();
  else
    GameModeXX_FadeInOrOut_009F66();
}

void GameModeXX_FadeInOrOut_GMMosaic() {  // 009f5b
  ++misc_game_mode;
  misc_mosaic_direction ^= 1;
  GameModeXX_FadeInOrOut_009F66();
}

void GameModeXX_FadeInOrOut_009F66() {  // 009f66
  RtlPpuWrite(MOSAIC, mirror_mosaic_size_and_bgenable | 3);
}

void GameModeXX_FadeInOrOut() {  // 009f6f
  if ((--timer_keep_game_mode_active & 0x80) != 0) {
    SetKeepGameModeActiveTimer_OneFrame();
    GameModeXX_FadeInOrOut_009F77();
  }
}

void GameModeXX_FadeInOrOut_009F77() {  // 009f77
  sub_9F4C(misc_mosaic_direction);
}

void GameMode28_ShowTheEnd() {  // 009f7c
  if ((--timer_keep_game_mode_active & 0x80) != 0) {
    SetKeepGameModeActiveTimer_VariableFrames(8);
    GameModeXX_FadeInOrOut_009F77();
  }
}

const uint8 *GetLayer3ImagePtr(int i) {
  return kLayer3ImagePtrs(i).ptr;
}

void InitializeLevelLayer3() {  // 009fb8
  uint8 v4;
  uint8 r0 = 3 * misc_level_tileset_setting;
  if (misc_level_layer3_settings) {
    uint8 v0 = r0 + misc_level_layer3_settings - 1;
    int8 v1 = kInitializeLevelLayer3_DATA_009F88[v0];
    if (v1 >= 0) {
      flag_layer3_tide_level = kInitializeLevelLayer3_DATA_009F88[v0];
      InitializeLevelLayer3_GenerateInteractiveTideWater();
      mirror_layer3_ypos = (flag_layer3_tide_level & ~1) ? 64 : 112;
      ScrollSecondInteractiveLayer();
      goto LABEL_15;
    }
    int8 v3 = 2 * v1;
    if (v3 >= 0) {
      if (v3) {
        if (misc_level_tileset_setting != 1 && misc_level_tileset_setting != 3)
          goto LABEL_16;
        mirror_layer3_xpos = mirror_current_layer1_xpos >> 1;
        v4 = -64;
        goto LABEL_14;
      }
      for (uint8 i = 7; (i & 0x80) == 0; --i)
        *((uint8 *)&palettes_palette_mirror[12] + i) = *((uint8 *)kGlobalPalettes_Layer3Smasher + i);
    }
  }
  ++flag_disable_layer3_scroll;
  v4 = -48;
LABEL_14:
  mirror_layer3_ypos = v4;
LABEL_15:
  mirror_color_math_select_and_enable &= ~4;
LABEL_16:
  if (misc_level_layer3_settings) {
    uint8 v6 = r0 + misc_level_layer3_settings - 1;
    LoadStripeImage_UploadToVRAM(GetLayer3ImagePtr(v6));
  }
}

void InitializeLevelLayer3_GenerateInteractiveTideWater() {  // 00a045
  if (HAS_LM_FEATURE(kLmFeature_TideWaterTweak)) {
    LmHook_InitializeLevelLayer3_GenerateInteractiveTideWater();
    return;
  }
  for (uint16 i = 256; i < 0x1B00; i += 256) {
    int16 v1 = 88;
    do {
      *(uint16 *)&ow_byte_7EE000[i + 768] = 0;
      i += 2;
      --v1;
    } while (v1);
  }
  misc_level_layout_flags |= 0x80;
}

void GameMode0C_LoadOverworld() {  // 00a087
  TurnOffIO();
  if (ow_warping_on_pipe_or_star_flag)
    HandleOverworldStarPipeWarp_SetPlayerDestination();
  ClearOverworldAndCutsceneRAM();
  if (misc_intro_level_flag) {
    timer_title_screen_input_timer = -80;
    ow_players_map[0] = 0;
    mirror_mosaic_size_and_bgenable = -16;
    misc_game_mode = 16;
    return;
  }
  ClearLayer3Tilemap();
  HandleSPCUploads_UploadOverworldMusicBank();
  SetStandardPPUSettings();
  misc_music_register_backup = 0;
  uint8 v0 = player_current_character;
  if ((player_current_life_count & 0x80) != 0)
    ++pointer_display_overworld_prompt;
  players_lives[player_current_character] = player_current_life_count;
  players_power_up[v0] = player_current_power_up;
  players_coins[v0] = player_current_coin_count;
  uint8 v1 = yoshi_carry_over_levels_flag;
  if (yoshi_carry_over_levels_flag)
    v1 = yoshi_current_yoshi_color;
  players_has_yoshi[v0] = v1;
  players_item_box[v0] = player_current_item_box;
  mirror_color_math_initial_settings = 3;
  uint8 v2 = 48;
  uint8 v3 = 21;
  if (flag_show_continue_and_end) {
    LoadSaveBufferData();
    if (!counter_events_triggered) {
      GameMode07_TitleScreenDemo_FadeOutToTitleScreen();
      ++misc_game_mode;
      return;
    }
    LoadOverworldLayer2AndEventsTilemaps();
    palettes_background_color = 0x318c;
    mirror_object_and_color_window_settings = 48;
    mirror_color_math_initial_settings = 32;
    v2 = -77;
    v3 = 23;
  }
  SetVisibleLayers(v2, v3, 2);
  RtlPpuWrite(TMW, v3);
  RtlPpuWrite(TSW, 2);
  LoadOverworldLayer1AndEvents();
  int v4 = (uint8)(2 * ow_players_map[player_current_character]) >> 1;
  mirror_current_layer1_xpos = kGameMode0C_LoadOverworld_DATA_00A06B[v4];
  mirror_current_layer2_xpos = mirror_current_layer1_xpos;
  mirror_current_layer1_ypos = kGameMode0C_LoadOverworld_DATA_00A079[v4];
  mirror_current_layer2_ypos = mirror_current_layer1_ypos;
  if (g_lunar_magic)
    LmHook_GameMode0C_LoadOverworld(v4);
  UploadGraphicsFiles();
  LmHook_OwGraphicsDecompress();
  BufferPalettesRoutines_Overworld();
  UpdateEntirePalette();
  graphics_stripe_image_to_upload = 6;
  LoadStripeImage();
  LoadOverworldLifeCounter();
  LoadStripeImage();
  GameMode0C_LoadOverworld_048D91();
  InitializeOverworldTilemaps();
  mirror_oamaddress_lo = 0xf0;
  CompressOamEntExt();
  LoadStripeImage();
  pointer_current_overworld_process = 0;
  SetKeepGameModeActiveTimer_OneFrame();
  misc_nmito_use_flag = 2;
  for (uint16 i = 446; (i & 0x8000) == 0; i -= 2) {
    misc_hdmawindow_effect_table[i] = 0;
    misc_hdmawindow_effect_table[i + 1] = -1;
  }
  SetupHDMAWindowingEffects_0092A0();
  ++misc_game_mode;
}

void LoadSaveBufferData() {  // 00a195
  for (uint16 i = 140; (i & 0x8000) == 0; --i)
    ow_level_tile_settings[i] = ow_save_buffer[i];
}

void ClearOverworldAndCutsceneRAM() {  // 00a1a6
  for (int16 i = 189; i >= 0; --i)
    *((uint8 *)&mirror_current_layer1_xpos + (uint16)i) = 0;
  for (int16 j = 0x7ce; j >= 0; --j)
    *(&timer_prevent_pause + (uint16)j) = 0;
}

void GameMode0E_ShowOverworld() {  // 00a1be
  CheckWhichControllersArePluggedIn();
  ++counter_local_frames;
  ResetSpritesFunc(0);
  GameMode0E_ShowOverworld_Bank04();
  CompressOamEntExt();
}

void GameMode14_InLevel() {  // 00a1da
  if (misc_display_message) {
    DisplayMessage();
  } else {
    uint8 v0 = flag_active_bonus_game;
    if (flag_active_bonus_game) {
      v0 = timer_bonus_game_end;
      if (timer_bonus_game_end) {
        if (timer_bonus_game_end < 0x40) {
          DamagePlayer_DisableButtons();
          if (v0 < 0x1C) {
            PlayerState00_SetMarioPeaceImg();
            v0 = 13;
            player_current_state = 13;
          }
        }
      }
    }
    if (timer_end_level | (uint8)(player_current_state | v0)) {
      io_controller_hold1 &= ~4;
      io_controller_press1 &= ~0x40;
      io_controller_press2 &= ~0x40;
    }
    if (timer_prevent_pause) {
      --timer_prevent_pause;
    } else if ((io_controller_press1 & 0x10) != 0 && !timer_end_level && player_current_state < 9) {
      timer_prevent_pause = 60;
      uint8 v1 = 18;
      flag_pause ^= 1;
      if (flag_pause)
        v1 = 17;
      io_sound_ch1 = v1;
    }
    if (flag_pause) {
      if ((io_controller_hold1 & 0x20) != 0 && (ow_level_tile_settings[ow_level_number_lo] & 0x80) && (int8)misc_exit_level_action <= 0) {
        misc_exit_level_action = 0x80;
        ++counter_enemy_rollcall_screen;
        misc_game_mode = 11;
      }
    } else {
      if ((misc_nmito_use_flag & 0x80) == 0) {
        ResetSpritesFunc(0);
        HandleStandardLevelCameraScroll();
        HandleScrollSpriteAndLayer3Scrolling();
        CheckIfLevelTilemapsNeedScrollUpdate();
        if (HAS_HACK(kHack_Walljump))
          HackHandleWalljump();
        LmHook_LevelTileAnimations();
      } else {
        GameMode14_InLevel_InMode7Level();
      }
      uint16 v2 = mirror_current_layer1_ypos;
      shaking_layer1_disp_y = 0;
      uint8 v3 = timer_shake_layer1;
      if (timer_shake_layer1) {
        --timer_shake_layer1;
        LOBYTE(shaking_layer1_disp_y) = kGameMode14_InLevel_GrndShakeDispYLo[v3 & 3];
        HIBYTE(shaking_layer1_disp_y) = kGameMode14_InLevel_GrndShakeDispYHi[v3 & 3];
        mirror_current_layer1_ypos += shaking_layer1_disp_y;
      }
      UpdateStatusBarCounters();
      PlayerDraw();
      UpdateCurrentPlayerPositionRAM();
      GameMode14_InLevel_00C47E();
      ProcessNormalSprites();
      GameMode14_InLevel_Bank02();
      mirror_current_layer1_ypos = v2;
      CompressOamEntExt();
    }
  }
}

void UpdateCurrentPlayerPositionRAM() {  // 00a2f3
  player_current_xpos = player_xpos;
  player_current_ypos = player_ypos;
}

const uint16 *GetPlayerPalette() {
  return kPlayerPalettes + ((pointer_player_palette - 0xb2c8) >> 1);
}

void UploadPlayerGFX() {  // 00a300
  if (player_number_of_tiles_to_update) {
    RtlUpdatePalette(GetPlayerPalette(), 0x86, 10);
  }
  SmwCopyToVram(0x67f0, g_ram + (graphics_dynamic_sprite_tile7 ? graphics_dynamic_sprite_tile7 : 0x2000), 0x20);

  uint8 v0 = 0;
  do {
    uint16 t = *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[v0];
    SmwCopyToVram(0x6000 + v0 * 0x10, g_ram + (t ? t : 0x2000), 0x40);
    v0 += 2;
  } while (v0 < player_number_of_tiles_to_update);

  uint8 v1 = 0;
  do {
    uint16 t = *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[v1];
    // bugfix to make predictable behavior
    SmwCopyToVram(0x6100 + v1 * 0x10, g_ram + (t ? t : 0x2000), 0x40);
    v1 += 2;
  } while (v1 < player_number_of_tiles_to_update);
}

void UploadLevelExAnimationData() {  // 00a390
  if (graphics_tile_anim_vramaddress3)
    SmwCopyToVram(graphics_tile_anim_vramaddress3, g_ram + graphics_tile_anim_source_address3, 0x80);
  if (graphics_tile_anim_vramaddress2)
    SmwCopyToVram(graphics_tile_anim_vramaddress2, g_ram + graphics_tile_anim_source_address2, 0x80);
  uint16 v0 = graphics_tile_anim_vramaddress1;
  if (graphics_tile_anim_vramaddress1) {
    if (v0 == 0x800) {
      SmwCopyToVram(graphics_tile_anim_vramaddress1, g_ram + graphics_tile_anim_source_address1, 0x40);
      SmwCopyToVram(0x900, g_ram + graphics_tile_anim_source_address1 + 64, 0x40);
    } else {
      SmwCopyToVram(graphics_tile_anim_vramaddress1, g_ram + graphics_tile_anim_source_address1, 0x80);
    }
  }
  if (g_lunar_magic)
    LmHook_UploadLevelAnimations();
  UploadLevelAnimations_YellowFlash(0x64);
}

void UploadLevelAnimations_YellowFlash(uint8 a) {  // 00a41c
  UploadLevelAnimations_RedFlash(a, 0);
}

void UploadLevelAnimations_RedFlash(uint8 a, uint8 r0) {  // 00a41e
  RtlPpuWrite(CGADD, a);
  uint8 v1 = r0 + ((uint8)(counter_local_frames & 0x1C) >> 1);
  RtlPpuWrite(CGDATA, *((uint8 *)kGlobalPalettes_Flashing + v1));
  RtlPpuWrite(CGDATA, *((uint8 *)kGlobalPalettes_Flashing + v1 + 1));
}

void RestoreSP1AfterMarioStart() {  // 00a436
  if (flag_restoresp1_tiles_after_mario_start && !g_lunar_magic) {
    flag_restoresp1_tiles_after_mario_start = 0;
    SmwCopyToVram(0x64a0, g_ram + 0xbf6, 0xc0);
    SmwCopyToVram(0x65a0, g_ram + 0xcb6, 0xc0);
  }
}

static const uint16 kUpdatePaletteFromIndexedTable_DATA_00A47F[3] = {
  0x682, 0x0905, 0x0703
};

void UpdatePaletteFromIndexedTable() {  // 00a488
  if (palettes_palette_upload_table_index == 0xff)
    return;

  const uint8 *p = g_ram + kUpdatePaletteFromIndexedTable_DATA_00A47F[palettes_palette_upload_table_index / 3];
  int n;
  while ((n = p[0]) != 0) {
    RtlUpdatePalette((uint16 *)(p + 2), p[1], n >> 1);
    p += 2 + n;
  }
  UpdatePaletteFromIndexedTable_00AE47();
  if (!palettes_palette_upload_table_index) {
    palettes_dynamic_palette_upload_index = 0;
    palettes_dynamic_palette_bytes_to_upload = 0;
  }
  palettes_palette_upload_table_index = 0;
}

void UploadOverworldExAnimationData() {  // 00a4e3
  SmwCopyToVram(0x750, g_ram + 0xaf6, 0x160);
  if (pointer_current_overworld_process != 10) {
    UploadLevelAnimations_YellowFlash(0x6D);
    UploadLevelAnimations_RedFlash(0x7D, 16);
  }
}

void UploadOverworldLayer1And2Tilemaps(uint8 j) {  // 00a529
  uint32 ram = ow_players_map[(uint8)player_current_characterx4 >> 2] ? 0x16000 : 0x14000;
  ram += kUploadOverworldLayer1And2Tilemaps_DATA_00A525[j] << 8;
  SmwCopyToVram(
      (kUploadOverworldLayer1And2Tilemaps_DATA_00A521[j] + 48) << 8,
      g_ram + ram, 0x800);
  SmwCopyToVram((kUploadOverworldLayer1And2Tilemaps_DATA_00A521[j] + 32) << 8, g_ram + 0xe400, 0x800);
}

void GameMode12_PrepareLevel() {  // 00a59c
  ClearLayer3Tilemap();
  DamagePlayer_DisableButtons();
  flag_upload_load_screen_letters_tovram = 0;
  if (g_lunar_magic)
    LmHook_SetStandardPPUSettings();
  else
    SetStandardPPUSettings();
  InitializeStatusBarTilemap();
  InitializeLevelLayer1And2Tilemaps();
  if ((misc_nmito_use_flag & 0x80) == 0) {
    UploadGraphicsFiles();
    BufferPalettesRoutines_Levels();
    if (g_lunar_magic)
      LmHook_PrepareLevel();
    GameMode12_PrepareLevel_InitializeLayer3RAM();
    InitializeLevelLayer3();
    InitializeLevelTileAnimations();
    SetupHDMAWindowingEffects_EndHDMA();
    GameMode12_PrepareLevel_009860();
  } else {
    GameMode12_PrepareLevel_PrepareMode7Level();
  }
  UpdateEntirePalette();
  SetKeepGameModeActiveTimer_OneFrame();
  UpdateStatusBarCounters();
  uint8 *v0 = g_ram + 0x905;
  uint8 *v1 = g_ram + 0x703;
  if (HAS_LM_FEATURE(kLmFeature_Copy512colors) && misc_nmito_use_flag != 0x80)
    MemCpy(v0, v1, 0x200);
  else
    MemCpy(v0, v1, 0x1F0);
  palettes_copy_of_background_color = palettes_background_color;
  GameMode12_PrepareLevel_00919B();
  CompressOamEntExt();
  ++misc_game_mode;
}

void InitializeLevelTileAnimations() {  // 00a5f9
  counter_local_frames &= 0x18;
  do {
    LmHook_LevelTileAnimations();
    UploadLevelExAnimationData();
    ++counter_local_frames;
  } while ((counter_local_frames & 7) != 0);
}

void InitializeLevelRAM() {  // 00a635
  int8 v0 = 0;
  if (spr45_directional_coins_despawn_timer | timer_silver_pswitch | timer_blue_pswitch)
    goto LABEL_4;
  if (!timer_star_power)
    goto LABEL_6;
  v0 = misc_music_register_backup;
  if ((misc_music_register_backup & 0x80) != 0)
LABEL_4:
    v0 = misc_music_register_backup & 0x7F;
  misc_music_register_backup = v0 | 0x40;
  timer_blue_pswitch = 0;
  timer_silver_pswitch = 0;
  spr45_directional_coins_despawn_timer = 0;
  timer_star_power = 0;
LABEL_6:
  if (blocks_give_life_in_bonus_flags_row5 |
      blocks_give_life_in_bonus_flags_row4 | blocks_give_life_in_bonus_flags_row3 |
              blocks_give_life_in_bonus_flags_row2 | blocks_give_life_in_bonus_flags_row1)
    flag_prevent_coin_bonus_game_replay = blocks_give_life_in_bonus_flags_row5 | blocks_give_life_in_bonus_flags_row4 |
                                          blocks_give_life_in_bonus_flags_row3 | blocks_give_life_in_bonus_flags_row2 |
                                          blocks_give_life_in_bonus_flags_row1;
  uint8 v1 = 35;
  do
    g_ram[0x70 + v1--] = 0;
  while (v1);
  uint8 v2 = 55;
  do
    *(&pointer_current_overworld_process + v2--) = 0;
  while (v2);
  unusedram_got_invincible_star_from_goal *= 2;
  timer_display_player_kicking_pose = 0;
  timer_display_player_pick_up_pose = 0;
  timer_level_end_fade = 0;
  yoshi_in_pipe = 0;
  if (misc_level_tileset_setting < 0x10 && kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting] >> 1 &&
      !(flag_disable_no_yoshi_intro | (uint8)(counter_sublevels_entered | flag_show_player_start))) {
    if (flag_override_no_yoshi_intro_for_midway_entrance) {
      PlayerState0A_NoYoshiCutscene_00C90A();
      InitializeLevelRAM_00A6CC(1);
    } else {
      player_in_air_flag = 0;
      if (g_lunar_magic) {
        lm_var13CD = 0;
        flag_got_midpoint = 0;
        lunar_magic_FE = 0;
      }
      player_facing_direction = 1;
      player_pipe_action = 1;
      if (yoshi_carry_over_levels_flag)
        InitializeLevelRAM_00A6C7(0xA, 0xF);
      else
        InitializeLevelRAM_00A6C7(0xA, 0);
    }
  } else {
    InitializeLevelRAM_00A6CC(1);
  }
}

void InitializeLevelRAM_00A6C7(uint8 k, uint8 j) {  // 00a6c7
  player_current_state = k;
  player_timer_pipe_warping = j;
}

void InitializeLevelRAM_00A6CC(uint8 j) {  // 00a6cc
  uint8 v4;
  if ((uint8)mirror_current_layer1_ypos != 0xC0)
    ++flag_enable_vert_scroll;
  uint8 v1 = misc_level_header_entrance_settings;
  if (!misc_level_header_entrance_settings)
    goto LABEL_8;
  if (misc_level_header_entrance_settings == 5) {
    int8 v2 = 0;
    if (misc_level_header_entrance_settings >= 5)
      v2 = 0x80;
    flag_ice_level = (flag_ice_level >> 1) + v2;
LABEL_8:
    player_facing_direction = j;
    player_in_air_flag = 36;
    flag_sprites_locked = 0;
    if (timer_end_level_via_keyhole) {
      misc_music_register_backup |= 0x7F;
      LOBYTE(player_on_tilting_platform_xpos) = player_xpos | 4;
      LOBYTE(player_on_tilting_platform_ypos) = player_ypos + 16;
    }
    if (in_yoshi_wings_bonus_area) {
      player_current_state = 8;
      LOBYTE(player_ypos) = -96;
      player_yspeed = -112;
    }
    return;
  }
  if (misc_level_header_entrance_settings >= 6) {
    if (misc_level_header_entrance_settings == 6) {
      player_facing_direction = j;
      player_cape_image = j;
      yoshi_in_pipe = -1;
      LOBYTE(player_xpos) = player_xpos | 8;
      LOBYTE(player_ypos) = player_ypos | 2;
      InitializeLevelRAM_00A6C7(7, 0x20);
      return;
    }
    flag_underwater_level = j;
    if (timer_end_level_via_keyhole | flag_override_no_yoshi_intro_for_midway_entrance)
      goto LABEL_8;
    v1 = 4;
  }
  player_pipe_action = v1 + 3;
  yoshi_in_pipe = ((uint8)(v1 + 3) >> 1) - 1;
  player_facing_direction = kInitializeLevelRAM_DATA_00A60D[v1 - 1];
  uint8 v3 = 5;
  if ((uint8)(v1 + 3) < 6 ||
      (LOBYTE(player_xpos) = player_xpos | 8, v3 = 6, v4 = 30, (uint8)(v1 + 3) >= 7) && (v4 = 15, player_current_power_up)) {
    v4 = 28;
  }
  player_yspeed = v4;
  InitializeLevelRAM_00A6C7(v3, v4);
  if (player_riding_yoshi_flag) {
    player_timer_pipe_warping += kInitializeLevelRAM_DATA_00A621[player_pipe_action - 4];
    player_xpos += kInitializeLevelRAM_DATA_00A611[player_pipe_action - 4];
    player_ypos += kInitializeLevelRAM_DATA_00A619[player_pipe_action - 4];
  }
}

void GameMode11_LoadSublevel_00A796() {  // 00a796
  uint16 v0;
  if (flag_layer2_vert_scroll_level_setting) {
    if (flag_layer2_vert_scroll_level_setting == 1) {
      v0 = mirror_current_layer2_ypos - mirror_current_layer1_ypos;
    } else {
      int16 v1 = mirror_current_layer1_ypos >> 1;
      if (flag_layer2_vert_scroll_level_setting != 2)
        v1 = mirror_current_layer1_ypos >> 3;
      v0 = mirror_current_layer2_ypos - v1;
    }
    camera_layer2_ypos_relative_to_layer1 = v0;
  }
  player_relative_position_needed_to_scroll_screen = 128;
}

void UploadLoadingLettersTiles() {  // 00a7c2
  SmwCopyToVram(0x6000, g_ram + 0x1977b, 0xc0);
  SmwCopyToVram(0x6100, g_ram + 0x1983B, 0xc0);
  SmwCopyToVram(0x64a0, g_ram + 0x198fB, 0xc0);
  SmwCopyToVram(0x65a0, g_ram + 0x199bb, 0xc0);
}

void BufferLoadingLetterTiles() {  // 00a82d
  uint8 *p0 = LmHook_GraphicsDecompress(0xF);
  if (flag_active_bonus_game)
    p0 += 48;
  uint16 v0 = 0;
  do {
    int16 v1 = 8;
    do {
      *(uint16 *)&graphics_decompressed_loading_letters[v0] = WORD(*p0);
      v0 += 2;
      p0 += 2;
      --v1;
    } while (v1);
    int16 v2 = 8;
    do {
      *(uint16 *)&graphics_decompressed_loading_letters[v0] = p0[0];
      v0 += 2;
      p0 += 1;
      --v2;
    } while (v2);
  } while (v0 < 0x300);
  if (!g_lunar_magic) {
    LmHook_GraphicsDecompress(0);
    p0 = g_ram + 0xb3f0;
    uint16 v3 = 0;
    do {
      int16 v4 = 8;
      do {
        decompressed_gfx_plus_256[v3 >> 1] = WORD(p0[0]);
        v3 += 2;
        p0 += 2;
        --v4;
      } while (v4);
      int16 v5 = 8;
      do {
        decompressed_gfx_plus_256[v3 >> 1] = p0[0];
        v3 += 2;
        p0 += 1;
        --v5;
      } while (v5);
      if (v3 == 192)
        p0 = &g_ram[0xb570];
    } while (v3 < 0x180);
  }
  flag_upload_load_screen_letters_tovram = 1;
  flag_restoresp1_tiles_after_mario_start = 1;
}

void UploadGraphicsFiles_Layer3() {  // 00a993
  for(int i = 0; i < 4; i++) {
    const uint8 *p0 = GraphicsDecompress(40 + i);
    SmwCopyToVram(0x4000 + i * 0x400, p0, 0x800);
  }
  UploadGraphicsFiles_UploadGFXFile(0x6000, 0, 0);
}

void UploadGraphicsFiles() {  // 00a9da
  uint8 arr[4];

  bool lunar_magic_upload_hack = HAS_LM_FEATURE(kLmFeature_GfxUpload);

  for (int i = 0; i < 4; i++)
    arr[3 - i] = kUploadGraphicsFiles_SpriteGFXList[4 * graphics_level_sprite_graphics_setting + i];
  for(int i = 3; i >= 0; i--) {
    uint16 vmaddr = kUploadGraphicsFiles_DATA_00A9D2[i] << 8;
    if (lunar_magic_upload_hack || misc_currently_loaded_sprite_graphics_files[i] != arr[i])
      UploadGraphicsFiles_UploadGFXFile(vmaddr, arr[i], i + 8);
  }
  memcpy(misc_currently_loaded_sprite_graphics_files, arr, 4);
  if (misc_level_tileset_setting >= 0xFE) {
    if (misc_level_tileset_setting != 0xFE)
      ConvertGFX27IntoNormallFormat(RtlGetVramAddr());
    for(int i = 0; i < 4; i++)
      misc_currently_loaded_sprite_graphics_files[i + 4] = 0x80;
  } else {
    for (int i = 0; i < 4; i++)
      arr[3 - i] = kUploadGraphicsFiles_FGAndBGGFXList[4 * misc_level_tileset_setting + i];

    static const uint8 kBgVramAddrs[6] = { 0x28,0x20,0x18,0x10,   8,   0 };
    if (lunar_magic_upload_hack && lm_var9 == 0x42) {
      for(int i = 5; i >= 0; i--)
        UploadGraphicsFiles_UploadGFXFile(kBgVramAddrs[i] << 8, (i < 2) ? 0xff : arr[i - 2], i + 2);
    } else {
      for(int i = 3; i >= 0; i--) {
        if (lunar_magic_upload_hack || misc_currently_loaded_sprite_graphics_files[i + 4] != arr[i])
          UploadGraphicsFiles_UploadGFXFile(kBgVramAddrs[i + 2] << 8, arr[i], i + 4);
      }
    }
    memcpy(&misc_currently_loaded_sprite_graphics_files[4], arr, 4);
    if (lunar_magic_upload_hack)
      LmHook_UploadGraphicsFiles();
  }
}

void UploadGraphicsFiles_UploadGFXFile(uint16 dst_addr, uint8 j, uint8 index) {  // 00aa6b
  uint16 v4;
  uint16 v11;
  uint16 *dst = RtlGetVramAddr() + dst_addr;
  const uint8 *p0;

  bool lunar_magic_upload_hack = HAS_LM_FEATURE(kLmFeature_GfxUpload);

  p0 = lunar_magic_upload_hack ? LmHook_UploadGFXFile(j, index) : GraphicsDecompress(j);
  if (j == 1 && (ow_level_tile_settings[73] & 0x80) != 0) {
    p0 = GraphicsDecompress(0x31);
    j = 1;
  }

  bool lm_flag = HAS_LM_FEATURE(kLmFeature_4bppgfx);

  if (misc_level_tileset_setting >= 0x11 && j == (lm_flag ? 0x32 : 8) || j == (lm_flag ? 0x32 : 30)) {
    uint16 r10w = -256;
    for (int8 i = 127; i >= 0; --i) {
      for (int8 k = 7; k >= 0; --k) {
        v11 = WORD(*p0);
        *dst++ = v11;
        *(uint16 *)&graphics_3_bppto4_bppbuffer[(uint8)k] = WORD(p0[0]) | swap16(v11);
        p0 += 2;
      }
      for (int8 m = 7; m >= 0; --m) {
        const uint8 *v14 = p0;
        uint16 r12w = *v14;
        *dst++ = r12w | r10w & (*(uint16 *)&graphics_3_bppto4_bppbuffer[(uint8)m] | swap16(*(uint16 *)v14));
        p0 += 1;
      }
    }
  } else {
    uint16 r10w = 0;
    int16 v1 = -1;
    if (j != 1 && j != 23)
      v1 = 0;
    *(uint16 *)flag_alter3_bppto4_bppconversion = v1;
    for (int8 n = 127; n >= 0; --n) {
      if (*(uint16 *)flag_alter3_bppto4_bppconversion) {
        if ((uint8)n >= 0x7E || (uint8)n >= 0x6E && (uint8)n < 0x70)
          r10w = -256;
        else
          r10w = 0;
      }
      if (lm_flag) {
        for (int8 ii = 15; ii >= 0; --ii) {
          v4 = WORD(*p0);
          *dst++ = v4;
          p0 += 2;
        }
      } else {
        for (int8 ii = 7; ii >= 0; --ii) {
          v4 = WORD(*p0);
          *dst++ = v4;
          *(uint16 *)&graphics_3_bppto4_bppbuffer[(uint8)ii] = WORD(p0[0]) | swap16(v4);
          p0 += 2;
        }
        for (int8 jj = 7; jj >= 0; --jj) {
          uint16 r12w = p0[0];
          const uint8 *v7 = p0;
          *dst++ = r12w | r10w & (*(uint16 *)&graphics_3_bppto4_bppbuffer[(uint8)jj] | swap16(*(uint16 *)v7));
          ++p0;
        }
      }
    }
  }
}

void ConvertGFX27IntoNormallFormat(uint16 *dst) {  // 00ab42
  const uint8 *p = GraphicsDecompress(0x27);
  for (int i = 0x3ff; i >= 0; --i) {
    uint32 d = p[0] << 16 | p[1] << 8 | p[2];
    HIBYTE(*dst++) = (d >> 21) & 7;
    HIBYTE(*dst++) = (d >> 18) & 7;
    HIBYTE(*dst++) = (d >> 15) & 7;
    HIBYTE(*dst++) = (d >> 12) & 7;
    HIBYTE(*dst++) = (d >> 9) & 7;
    HIBYTE(*dst++) = (d >> 6) & 7;
    HIBYTE(*dst++) = (d >> 3) & 7;
    HIBYTE(*dst++) = (d >> 0) & 7;
    p += 3;
  }
  int v11 = 0x2000;
  do {
    HIBYTE(*dst++) = 0;
  } while (--v11);
}


void BufferPalettesRoutines_Levels() {  // 00abed
  BufferPalettesRoutines_LoadColorInVerticalStrip(2, 0x7fdd);
  BufferPalettesRoutines_LoadColorInVerticalStrip(0x102, 0x7FFF);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_Layer3, 16, 7, 1);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_Objects, 132, 5, 9);
  palettes_background_color = kGlobalPalettes_Sky[misc_background_color_setting & 0xF];
  BufferPalettesRoutines_LoadColors((kBufferPalettesRoutines_DATA_00ABD3[misc_fgpalette_setting & 0xF] >> 1) + kGlobalPalettes_Foreground, 68, 5, 1);
  BufferPalettesRoutines_LoadColors((kBufferPalettesRoutines_DATA_00ABD3[misc_sprite_palette_setting & 0xF] >> 1) + kGlobalPalettes_Sprites, 452, 5, 1);
  BufferPalettesRoutines_LoadColors((kBufferPalettesRoutines_DATA_00ABD3[misc_bgpalette_setting & 0xF] >> 1) + kGlobalPalettes_Background, 4, 5, 1);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_YoshiBerry, 82, 6, 2);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_YoshiBerry, 306, 6, 2);
}

void BufferPalettesRoutines_LoadColorInVerticalStrip(uint16 k, uint16 r4) {  // 00aced
  for (int16 i = 7; i >= 0; --i) {
    palettes_palette_mirror[k >> 1] = r4;
    k += 32;
  }
}

void BufferPalettesRoutines_LoadColors(const uint16 *r0, uint16 r4, uint16 r6, uint16 r8) {  // 00acff
  do {
    uint16 v0 = r4;
    int16 v1 = r6;
    do {
      palettes_palette_mirror[v0 >> 1] = *r0++;
      v0 += 2;
    } while (--v1 >= 0);
    r4 += 32;
  } while ((--r8 & 0x8000) == 0);
}

void BufferPalettesRoutines_Overworld() {  // 00ad25
  if (HAS_LM_FEATURE(kLmFeature_OwPalette)) {
    LmHook_OverworldPalette();
    return;
  }

  int tt = kBufferPalettesRoutines_DATA_00AD1E[(misc_level_tileset_setting & 0xF) - 1];
  const uint16 *v0 = &kGlobalPalettes_OW_Areas[tt * 28];
  if (ow_level_tile_settings[73] & 0x80)
    v0 = &kGlobalPalettes_OW_AreasPassed[tt * 28];
  BufferPalettesRoutines_LoadColors(v0, 130, 6, 3);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_OW_Objects, 82, 6, 5);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_OW_Sprites, 258, 6, 7);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_B5EC, 16, 7, 1);
}

static const uint16 kGlobalPalettes_TS_Layer3[] = {0x437F,     0,0x7F60,0x173F,0x437F,     0,0x1CFF, 0x320};
static const uint16 kGlobalPalettes_DATA_00B63C[] = {0x437F,     0, 0x320,0x7F60,0x437F,0x5BBF,0x327B, 0x8E7};

void BufferPalettesRoutines_TitleScreen() {  // 00ada6
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_DATA_00B63C, 16, 7, 0);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_TS_Layer3, 48, 7, 0);
}

static const uint16 kGlobalPalettes_IggyLarryPlatform[] = {
  0x0, 0x1ce0, 0x3de8, 0x5ef0, 0x7ff8, 0x7fff, 0x1685, 0x2f4b,
};

void BufferPalettesRoutines_IggyLarryPlatform() {  // 00add9
  BufferPalettesRoutines_Levels();
  palettes_background_color = 23;
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_Layer3, 16, 7, 1);
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_IggyLarryPlatform, 0, 7, 0);
}

void BufferPalettesRoutines_ReznorAndMode7KoopaBosses() {  // 00ae15
  misc_sprite_palette_setting = 2;
  misc_fgpalette_setting = 7;
  BufferPalettesRoutines_Levels();
  palettes_background_color = 23;
  BufferPalettesRoutines_LoadColors(kGlobalPalettes_B5EC + 4, 24, 3, 0);
}

void UpdatePaletteFromIndexedTable_00AE47() {  // 00ae47
  for (uint8 i = 2; (i & 0x80) == 0; --i) {
    uint16 v1 = palettes_background_color;
    uint8 v2 = kUpdatePaletteFromIndexedTable_DATA_00AE41[i];
    while ((--v2 & 0x80) == 0)
      v1 >>= 1;
    RtlPpuWrite(COLDATA, kUpdatePaletteFromIndexedTable_DATA_00AE44[i] | v1 & 0x1F);
  }
}

void HandlePaletteFades() {  // 00af17
  uint8 v0 = timer_end_level;
  if (counter_global_frames & 1) {
    v0 = timer_end_level - 1;
    if (timer_end_level != 1)
      --timer_end_level;
  }
  if (v0 < 0xA0) {
    mirror_color_math_select_and_enable &= ~4;
    mirror_bgmode_and_tile_size_setting = 9;
    ProcessLevelEndRoutines();
  }
  HandlePaletteFades_00AF35(false);
}

void HandlePaletteFades_00AF35(bool run_code_at_end) {  // 00af35
  if ((counter_global_frames & 3) == 0 && timer_level_end_fade < 0x40) {
    uint8 a = timer_level_end_fade;
    timer_level_end_fade = a + 2;
    uint8 r12 = (a >> 4) & 2;
    uint16 r14 = kHandlePaletteFades_DATA_00AEF7[(a & 0x1E) >> 1];
    uint16 r2w;

    palettes_copy_of_palette_mirror[0] = 510;
    if (!g_lunar_magic) {
      for (uint16 i = 0xee; (i & 0x8000) == 0; i -= 18) {
        uint16 r0w = 7;
        do {
          int v1 = i >> 1;
          r2w = palettes_copy_of_palette_mirror[v1];
          palettes_copy_of_palette_mirror[v1] = HandlePaletteFades_00AFC0(palettes_palette_mirror[v1], r2w, r12, r14);
          i -= 2;
        } while (--r0w);
      }
      for (uint16 j = 4; (j & 0x8000) == 0; j -= 2) {
        int v3 = j >> 1;
        r2w = palettes_copy_of_palette_mirror[v3 + 13];
        palettes_copy_of_palette_mirror[v3 + 13] = HandlePaletteFades_00AFC0(palettes_palette_mirror[v3 + 13], r2w, r12, r14);
      }

    } else if (HAS_LM_FEATURE(kLmFeature_WeirdPalette)) {
      for (uint16 i = 0xfe; (i & 0x8000) == 0;) {
        uint16 r0w = 0xf;
        do {
          int v1 = i >> 1;
          r2w = palettes_copy_of_palette_mirror[v1];
          palettes_copy_of_palette_mirror[v1] = HandlePaletteFades_00AFC0(palettes_palette_mirror[v1], r2w, r12, r14);
          i -= 2;
        } while (--r0w);
        i -= 2;
      }
      palettes_copy_of_palette_mirror[9] = palettes_palette_mirror[9];
      palettes_copy_of_palette_mirror[10] = palettes_palette_mirror[10];
      palettes_copy_of_palette_mirror[11] = palettes_palette_mirror[11];
      palettes_copy_of_palette_mirror[25] = palettes_palette_mirror[25];
      palettes_copy_of_palette_mirror[26] = palettes_palette_mirror[26];
      palettes_copy_of_palette_mirror[27] = palettes_palette_mirror[27];
      palettes_copy_of_palette_mirror[29] = palettes_palette_mirror[29];
      palettes_copy_of_palette_mirror[30] = palettes_palette_mirror[30];
      palettes_copy_of_palette_mirror[31] = palettes_palette_mirror[31];
    } else {
      for (uint16 i = 0xfe; (i & 0x8000) == 0; ) {
        uint16 r0w = 1;
        do {
          int v1 = i >> 1;
          r2w = palettes_copy_of_palette_mirror[v1];
          palettes_copy_of_palette_mirror[v1] = HandlePaletteFades_00AFC0(palettes_palette_mirror[v1], r2w, r12, r14);
          i -= 2;
        } while (--r0w);
        if (i == 0x3e || i == 0x1e)
          i -= 16;
      }
    }
    r2w = palettes_background_color;
    palettes_background_color = HandlePaletteFades_00AFC0(palettes_copy_of_background_color, r2w, r12, r14);
    LOBYTE(palettes_copy_of_palette_mirror[128]) = 0;
    palettes_palette_upload_table_index = 3;

    if (run_code_at_end) {
      const uint8 *p0 = (const uint8 *)GetPlayerPalette();
      for (uint16 i = 20; (i & 0x8000) == 0; i -= 2)
        palettes_copy_of_palette_mirror[(i >> 1) + 134] = WORD(p0[i]);
      palettes_copy_of_palette_mirror[128] = 0x81ee;
      for (uint16 j = 206; (j & 0x8000) == 0; j -= 18) {
        uint16 r0w = 7;
        do {
          int v2 = j >> 1;
          r2w = palettes_copy_of_palette_mirror[v2 + 144];
          palettes_copy_of_palette_mirror[v2 + 144] = HandlePaletteFades_00AFC0(palettes_palette_mirror[v2 + 144], r2w, r12, r14);
          j -= 2;
        } while (--r0w);
      }
      unused_byte_7E0AF5 = 0;
    }
  }
}

uint16 HandlePaletteFades_00AFC0(uint16 a, uint16 r2w, uint16 r12, uint16 r14) {  // 00afc0
  uint16 arr[3] = {
    4 * (a & 0x1F),
    (a & 0x3E0) >> 3,
    (a >> 8) & 0x7C
  };
  uint16 r4w = 0;
  for (uint16 i = 4; (i & 0x8000) == 0; i -= 2) {
    uint16 t = r12 | arr[i >> 1];
    uint16 v2 = r14 & kHandlePaletteFades_DATA_00AE77[t >> 1];
    if (v2) {
      int v3 = i >> 1;
      v2 = kHandlePaletteFades_DATA_00AE6B[v3];
      if (*(int8 *)&palettes_level_end_color_fade_direction < 0)
        v2 = kHandlePaletteFades_DATA_00AE71[v3];
    }
    r4w |= kHandlePaletteFades_DATA_00AE65[i >> 1] & (uint16)(r2w + v2);
  }
  return r4w;
}

void OwEventProcess04_FadeInLayer2Tile_00B006(uint8 a) {  // 00b006
  timer_level_end_fade = a + 2;
  uint8 r12 = (a >> 4) & 2;
  uint16 r14 = kHandlePaletteFades_DATA_00AEF7[(a & 0x1E) >> 1];

  for (uint16 i = 110; (i & 0x8000) == 0; i -= 16) {
    int16 v2 = 8;
    int16 v4;
    do {
      int v3 = i >> 1;
      uint16 r2w = palettes_copy_of_palette_mirror[v3 + 1];
      v4 = v2;
      uint16 r4 = HandlePaletteFades_00AFC0(palettes_palette_mirror[v3 + 64], r2w, r12, r14);
      palettes_copy_of_palette_mirror[v3 + 1] = r4;
      palettes_copy_of_palette_mirror[v3 + 58] = palettes_palette_mirror[v3 + 64] - r4;
      i -= 2;
      --v2;
    } while (v4 != 1);
  }
}

void PlayerState00_00B03E() {  // 00b03e
  HandlePaletteFades_00AF35(true);
}

void GraphicsDecompressionRoutines_DecompressGFX32And33() {  // 00b888
  if (HAS_LM_FEATURE(kLmFeature_4bppgfx)) {
    memcpy(g_ram + 0x7d00, kGfx33, kGfx33_SIZE);
    memcpy(g_ram + 0x2000, kGfx32, kGfx32_SIZE);
  } else {
    memcpy(g_ram + 0x2000, kGfx33, kGfx33_SIZE);
    uint8 *t8d = g_ram + 0xacfe;
    int16 v0 = 0x23ff;
  LABEL_2:;
    int16 v1 = 8;
    do {
      WORD(t8d[0]) = graphics_decompressedgfx32[(uint16)v0--];
      t8d -= 2;
    } while (--v1);
    int16 v2 = 8;
    while (1) {
      uint16 v3 = v0 - 1;
      WORD(t8d[0]) = *(uint16 *)&graphics_decompressedgfx32[v3];
      v0 = v3 - 1;
      if (v0 < 0)
        break;
      t8d -= 2;
      if (!--v2)
        goto LABEL_2;
    }
    memcpy(g_ram + 0x2000, kGfx32, kGfx32_SIZE);
  }
}

int DecompressTo(const uint8 *src, uint8 *pdst) {  // 00b8de
  uint8 cmd;
  uint16 v0 = 0;
  while (1) {
    uint8 tag = *src++;
    if (tag == 0xFF)
      break;
    uint8 v2 = tag & 0xE0;
    int len;
    if (v2 == 0xe0) {
      cmd = (8 * tag) & 0xE0;
      len = ((tag & 3) << 8 | *src++) + 1;
    } else {
      cmd = v2;
      len = (tag & 0x1F) + 1;
    }
    if (cmd) {
      if (cmd & 0x80) {
        uint16 v18 = src[0] << 8 | src[1];
        src += 2;
        do {
          pdst[v0++] = pdst[v18];
          ++v18;
        } while (--len);
      } else if ((cmd & 0x40) != 0) {
        if ((cmd & 0x20) != 0) {
          uint8 v4 = *src++;
          do {
            pdst[v0++] = v4++;
          } while (--len);
        } else {
          uint8 v9 = *src++;
          uint8 v10 = *src++;
          do {
            pdst[v0++] = v9;
            if (len <= 1)
              break;
            pdst[v0++] = v10;
          } while (len -= 2);
        }
      } else {
        uint8 v7 = *src++;
        do {
          pdst[v0++] = v7;
        } while (--len);
      }
    } else {
      do {
        uint8 v6 = *src++;
        pdst[v0++] = v6;
      } while (--len);
    }
  }
  return v0;
}

uint8 *GraphicsDecompress(uint8 j) {  // 00ba28
  MemBlk blk = kGraphicsPtrs(j);
  DecompressTo(blk.ptr, g_ram + 0xad00);
  return g_ram + 0xad00;
}

uint8 *GetPtrToLevelDataLayout() {
  const uint16 *rp = GetLayerLayoutPtr(misc_current_layer_being_processed, misc_level_mode_setting);
  return g_ram + rp[HIBYTE(blocks_xpos)];
}

void GenerateTile() {  // 00beb0
  if (blocks_map16_to_generate) {
    GenTileArgs gta;

    gta.r12 = blocks_xpos;
    gta.r14 = blocks_ypos;
    uint8 r9 = misc_level_layout_flags;
    if ((uint8)misc_current_layer_being_processed)
      r9 >>= 1;
    uint16 v1 = gta.r14;
    if ((r9 & 1) != 0) {
      uint8 r0 = HIBYTE(blocks_xpos);
      HIBYTE(blocks_xpos) = HIBYTE(blocks_ypos);
      HIBYTE(blocks_ypos) = r0;
      v1 = gta.r12;
    }
    if (v1 < 0x200) {
      ptr_lo_map16_data = NULL;
      gta.ptr_lo_map16_data = GetPtrToLevelDataLayout();
      // @25: Write to 0x6 = 0x25: 0xbf67: r18=0x4100: r20=0xc19e: a = 0x25, x = 0x0, y = 0xd, c = 0, r4 = 24, r5 = 40, r6 = 25, r9=1, blocks_ypos = 482/15e
      uint8 v3, v4, r4;
      if (g_lunar_magic) {
        if ((r9 & 1) != 0) {
          v3 = HIBYTE(blocks_ypos) & 1;
          v4 = HIBYTE(blocks_xpos);
        } else {
          v3 = HIBYTE(blocks_xpos) & 1;
          v4 = HIBYTE(blocks_ypos);
        }
        r4 = (4 * (2 * v4 + v3)) & 0xc | 0x20;
      } else {
        if ((r9 & 1) != 0) {
          v3 = HIBYTE(blocks_ypos) & 1;
          v4 = HIBYTE(blocks_xpos) & 1;
        } else {
          v3 = HIBYTE(blocks_xpos) & 1;
          v4 = HIBYTE(blocks_ypos);
        }
        r4 = (4 * (2 * v4 + v3)) | 0x20;
      }
      if (misc_current_layer_being_processed)
        r4 += 16;
      bool v6 = __CFSHL__(blocks_ypos & 0xF0, 1);
      uint8 r5 = 4 * (blocks_ypos & 0xF0) + v6;
      // todo: understand this
      gta.r6 = r4 | (2 * (4 * (blocks_ypos & 0xF0) + v6) + __CFSHL__(2 * (blocks_ypos & 0xF0), 1)) & 3;
      r4 = (blocks_xpos & 0xF0) >> 3;
      gta.r7 = r4 | r5 & 0xC0;
      uint16 v7, v8;
      if ((r9 & 1) != 0) {
        v7 = mirror_current_layer1_xpos;
        v8 = mirror_current_layer1_ypos - 128;
        if (misc_current_layer_being_processed) {
          v7 = mirror_current_layer2_xpos - 128;
          v8 = mirror_current_layer2_ypos;
        }
      } else {
        if (g_lunar_magic) {
          v7 = mirror_current_layer1_xpos;
          v8 = mirror_current_layer1_ypos;
          if (misc_current_layer_being_processed) {
            v7 = mirror_current_layer2_xpos;
            v8 = mirror_current_layer2_ypos;
          }
          v7 -= 0x80;
          v8 -= 0x80;
        } else {
          v7 = mirror_current_layer1_xpos - 128;
          v8 = mirror_current_layer1_ypos;
          if (misc_current_layer_being_processed) {
            v7 = mirror_current_layer2_xpos;
            v8 = mirror_current_layer2_ypos - 128;
          }
        }
      }
      gta.r8 = v7;
//      r10w = v8;
      gta.r10 = v8;
      kGenerateTile_TileGenerationPtr[blocks_map16_to_generate - 1](&gta);
    }
  }
}

void SetItemMemoryBit() {  // 00c00d
  uint16 r4 = (uint16)(blocks_xpos & 0xFF00) >> 6;
  r4 |= (uint8)(blocks_xpos & 0x80) >> 7;
  if ((blocks_ypos & 0x100) != 0)
    r4 |= 2;
  r4 += kSetItemMemoryBit_DATA_00BFFF[(uint16)(2 * (misc_item_memory_setting & 0xF)) >> 1];
  misc_item_memory_bits[r4] |= kSetItemMemoryBit_DATA_00C005[(uint8)(blocks_xpos & 0x70) >> 4];
}

void sub_C074(GenTileArgs *gta) {  // 00c074
  SetItemMemoryBit();
  sub_C077(gta);
}

void sub_C077(GenTileArgs *gta) {  // 00c077
  uint16 v0 = blocks_ypos & 0x1F0 | ((uint8)blocks_xpos >> 4);
  uint16 v1 = blocks_map16_to_generate;
  uint8 *v2 = gta->ptr_lo_map16_data + v0;
  if (g_lunar_magic)
    v2[0x10000] = 0;
  else
    v2[0x10000] &= ~1;
  uint8 v3 = kGenericPage00Tile_Map16Page00TileLo[v1];
  v2[0] = v3;
  GenericPage01Tile_00C0FB(gta, 2 * v3);
}

void GenericPage01Tile_SetItemMemory(GenTileArgs *gta) {  // 00c0c1
  SetItemMemoryBit();
  GenericPage01Tile(gta);
}

void GenericPage01Tile(GenTileArgs *gta) {  // 00c0c4
  uint16 v0 = blocks_ypos & 0x1F0 | ((uint8)blocks_xpos >> 4);
  uint16 v1 = (uint8)(blocks_map16_to_generate - 9);
  uint8 *v2 = gta->ptr_lo_map16_data + v0;
  if (g_lunar_magic)
    v2[0x10000] = 1;
  else
    v2[0x10000] |= 1;
  uint8 v3 = kGenericPage01Tile_Map16Page01TileLo[v1];
  v2[0] = v3;
  GenericPage01Tile_00C0FB(gta, 2 * (v3 | 0x100));
}

void GenericPage01Tile_00C0FB(GenTileArgs *gta, uint16 j) {  // 00c0fb
  uint16 r0w = *(uint16 *)&misc_level_layout_flags;
  if (misc_current_layer_being_processed)
    r0w >>= 1;
  if ((r0w & 1) == 0) {
    uint16 v1 = gta->r8 & 0xFFF0;
    if ((gta->r8 & 0x8000) == 0) {
      if (v1 == gta->r12)
        goto LABEL_X;
      if (v1 >= gta->r12)
        return;
    }
    uint16 v2 = v1 + 512;
    if (v2 <= gta->r12)
      return;
LABEL_X:
    if (g_lunar_magic)
      goto LABEL_11;
  } else {
LABEL_11:;
    uint16 v3 = gta->r10 & 0xFFF0;
    if ((gta->r10 & 0x8000) == 0) {
      if (v3 == gta->r14)
        goto LABEL_15;
      if (v3 >= gta->r14)
        return;
    }
    uint16 v4 = v3 + 512;
    if (v4 <= gta->r14)
      return;
  }

LABEL_15:;
  uint16 v5 = stripe_image_upload;
  uint8 v6 = gta->r6;
  stripe_image_upload_data[v5] = v6;
  stripe_image_upload_data[v5 + 8] = v6;
  uint8 v8 = gta->r7;
  stripe_image_upload_data[v5 + 1] = v8;
  stripe_image_upload_data[v5 + 9] = v8 + 32;
  stripe_image_upload_data[v5 + 2] = 0;
  stripe_image_upload_data[v5 + 10] = 0;
  stripe_image_upload_data[v5 + 3] = 3;
  stripe_image_upload_data[v5 + 11] = 3;
  stripe_image_upload_data[v5 + 16] = -1;
  const uint16 *rp = Lm_GetMap16RomAddr(j >> 1);
  *(uint16 *)&stripe_image_upload_data[v5 + 4] = rp[0];
  *(uint16 *)&stripe_image_upload_data[v5 + 12] = rp[1];
  *(uint16 *)&stripe_image_upload_data[v5 + 6] = rp[2];
  *(uint16 *)&stripe_image_upload_data[v5 + 14] = rp[3];
  stripe_image_upload = v5 + 16;
  return;
}

void EraseYoshiCoin(GenTileArgs *gta) {  // 00c1ac
  SetItemMemoryBit();
  uint16 v0 = blocks_ypos & 0x1F0 | ((uint8)blocks_xpos >> 4);
  gta->ptr_lo_map16_data[v0] = gta->ptr_lo_map16_data[v0 + 16] = 0x25;
  uint16 r0w = *(uint16 *)&misc_level_layout_flags;
  if (misc_current_layer_being_processed)
    r0w >>= 1;
  if ((r0w & 1) == 0) {
    uint16 v1 = gta->r8 & 0xFFF0;
    if ((gta->r8 & 0x8000) != 0)
      goto LABEL_7;
    if (v1 != gta->r12) {
      if (v1 >= gta->r12)
        return;
LABEL_7:
      if ((uint16)(v1 + 512) <= gta->r12)
        return;
    }
LABEL_14:;
    uint16 v4 = stripe_image_upload;
    uint8 v5 = gta->r6;
    int v6 = stripe_image_upload;
    stripe_image_upload_data[stripe_image_upload] = v5;
    stripe_image_upload_data[v6 + 12] = v5;
    uint8 v7 = gta->r7;
    stripe_image_upload_data[v4 + 1] = v7;
    stripe_image_upload_data[v4 + 13] = v7 + 1;
    stripe_image_upload_data[v4 + 2] = 0x80;
    stripe_image_upload_data[v4 + 14] = 0x80;
    stripe_image_upload_data[v4 + 3] = 7;
    stripe_image_upload_data[v4 + 15] = 7;
    stripe_image_upload_data[v4 + 24] = -1;
    g_ram[6] = 13;
    const uint16 *rp = Lm_GetMap16RomAddr(37);
    uint16 v9 = rp[0];
    *(uint16 *)&stripe_image_upload_data[v4 + 4] = v9;
    *(uint16 *)&stripe_image_upload_data[v4 + 8] = v9;
    uint16 v11 = rp[1];
    *(uint16 *)&stripe_image_upload_data[v4 + 16] = v11;
    *(uint16 *)&stripe_image_upload_data[v4 + 20] = v11;
    uint16 v13 = rp[2];
    *(uint16 *)&stripe_image_upload_data[v4 + 6] = v13;
    *(uint16 *)&stripe_image_upload_data[v4 + 10] = v13;
    uint16 v15 = rp[3];
    *(uint16 *)&stripe_image_upload_data[v4 + 18] = v15;
    *(uint16 *)&stripe_image_upload_data[v4 + 22] = v15;
    stripe_image_upload = v4 + 24;
    return;
  }
  uint16 v2 = gta->r10 & 0xFFF0;
  if ((gta->r10 & 0x8000) == 0) {
    if (v2 == gta->r14)
      goto LABEL_14;
    if (v2 >= gta->r14)
      return;
  }
  uint16 v3 = v2 + 512;
  if (v3 > gta->r14)
    goto LABEL_14;
}

static const uint16 kChangeNetDoorTiles_Open[72] = { 0x9c99, 0x1c8b, 0x1c8b, 0x1c8b, 0x1c8b, 0xdc99, 0x1c9b, 0x1cf8, 0x1cf8, 0x1cf8, 0x1cf8, 0x5c9b, 0x1c9b, 0x1cf8, 0x1cf8, 0x1cf8, 0x1cf8, 0x5c9b, 0x1c9b, 0x1cf8, 0x1cf8, 0x1cf8, 0x1cf8, 0x5c9b, 0x1c9b, 0x1cf8, 0x1cf8, 0x1cf8, 0x1cf8, 0x5c9b, 0x1c99, 0x9c8b, 0x9c8b, 0x9c8b, 0x9c8b, 0x5c99,  };
static const uint16 kChangeNetDoorTiles_Closed[72] = { 0x9cba, 0x1cab, 0x1cab, 0x1cab, 0x1cab, 0xdcba, 0x1caa, 0x1c82, 0x1c82, 0x1c82, 0x1c82, 0x5caa, 0x1caa, 0x1c82, 0x1c82, 0x1c82, 0x1c82, 0x5caa, 0x1caa, 0x1c82, 0x1c82, 0x1c82, 0x1c82, 0x5caa, 0x1caa, 0x1c82, 0x1c82, 0x1c82, 0x1c82, 0x5caa, 0x1cba, 0x9cab, 0x9cab, 0x9cab, 0x9cab, 0x5cba,  };

void ChangeNetDoorTiles(GenTileArgs *gta) {  // 00c334
  ++gta->r7;
  AddHiLo(&gta->r6, &gta->r7, 32);
  const uint8 *p2 = (uint8*)((blocks_map16_to_generate == 25) ? kChangeNetDoorTiles_Open : kChangeNetDoorTiles_Closed);
  uint16 v1 = stripe_image_upload;
  for (int16 i = 5; i >= 0; --i) {
    stripe_image_upload_data[v1] = gta->r6;
    stripe_image_upload_data[v1 + 1] = gta->r7;
    stripe_image_upload_data[v1 + 2] = 0;
    stripe_image_upload_data[v1 + 3] = 11;
    AddHiLo(&gta->r6, &gta->r7, 32);
    v1 += 16;
  }
  uint16 v3 = stripe_image_upload;
  uint16 v4 = 0;
  do {
    uint16 r0w = 5;
    do {
      *(uint16 *)&stripe_image_upload_data[v3 + 4] = WORD(p2[v4]);
      v4 += 2;
      v3 += 2;
    } while ((--r0w & 0x8000) == 0);
    v3 += 4;
  } while (v4 != 72);
  *(uint16 *)&stripe_image_upload_data[v3] = 255;
  stripe_image_upload += 96;
}

void EraseLargeSwitch(GenTileArgs *gta) {  // 00c3d1
  uint16 v0 = blocks_ypos & 0x1F0 | ((uint8)blocks_xpos >> 4);
  uint16 v1 = stripe_image_upload;
  uint8 *p = gta->ptr_lo_map16_data;
  p[v0] = 0x25;
  p[v0 + 1] = 0x25;
  p[v0 + 16] = 0x25;
  p[v0 + 17] = 0x25;
  for (int16 i = 3; i >= 0; --i) {
    stripe_image_upload_data[v1] = gta->r6;
    stripe_image_upload_data[v1 + 1] = gta->r7;
    stripe_image_upload_data[v1 + 2] = 64;
    stripe_image_upload_data[v1 + 3] = 6;
    *(uint16 *)&stripe_image_upload_data[v1 + 4] = 0x18f8;
    v1 += 6;
    AddHiLo(&gta->r6, &gta->r7, 32);
  }
  stripe_image_upload_data[v1] = -1;
  stripe_image_upload = v1;
}

void GameMode14_InLevel_00C47E() {  // 00c47e
  player_hide_player_tile_flags = 0;
  if ((unusedram_got_invincible_star_from_goal & 0x80) != 0) {
    GivePlayerStarPower();
    unusedram_got_invincible_star_from_goal = 0;
  }
  if (timer_end_level_via_keyhole) {
    player_freeze_player_flag = timer_end_level_via_keyhole;
    flag_sprites_locked = timer_end_level_via_keyhole;
    uint8 v0 = flag_keyhole_anim_phase;
    if (timer_hdmawindow_scaling_factor == kGameMode14_InLevel_DATA_00C470[flag_keyhole_anim_phase]) {
      uint8 v1 = timer_end_level_via_keyhole - 1;
      if (timer_end_level_via_keyhole == 1) {
        ++flag_keyhole_anim_phase;
        if (!(v0 & 1))
          goto LABEL_11;
        ClearOutNormalSpriteSlots();
        PlayerState00_LevelFinished(0xB, 2);
        v1 = 0;
      }
      timer_end_level_via_keyhole = v1;
    } else {
      timer_hdmawindow_scaling_factor += kGameMode14_InLevel_DATA_00C474[flag_keyhole_anim_phase];
      mirror_bg1_and2_window_mask_settings = 34;
      mirror_bg3_and4_window_mask_settings = 2;
      mirror_object_and_color_window_settings = kGameMode14_InLevel_DATA_00C478[flag_keyhole_anim_phase];
      mirror_color_math_initial_settings = 18;
      uint8 r0 = player_on_tilting_platform_xpos - mirror_current_layer1_xpos + 4;
      uint8 r1 = player_on_tilting_platform_ypos - mirror_current_layer1_ypos + 16;
      UpdateHDMAWindowBuffer_KeyholeEntry((HdmaPtrs) {.r4 = kUpdateHDMAWindowBuffer_KeyholeHDMAData, .r6 = 0}, r0, r1);
    }
  }
LABEL_11:
  if (!player_freeze_player_flag) {
    if (!flag_sprites_locked) {
      ++counter_local_frames;
      uint8 v2 = 19;
      do {
        if (*(&timer_level_end_fade + v2))
          --*(&timer_level_end_fade + v2);
      } while (--v2);
      if ((counter_local_frames & 3) == 0) {
        if (flag_active_bonus_game) {
          if (timer_bonus_game_end == 68)
            io_music_ch1 = 20;
          if (timer_bonus_game_end == 1)
            misc_game_mode = 11;
        }
        uint8 v3 = timer_blue_pswitch;
        if (timer_blue_pswitch < timer_silver_pswitch)
          v3 = timer_silver_pswitch;
        if ((misc_music_register_backup & 0x80) == 0 && v3 == 1) {
          v3 = spr45_directional_coins_despawn_timer;
          if (!spr45_directional_coins_despawn_timer)
            io_music_ch1 = misc_music_register_backup;
        }
        if (misc_music_register_backup != 0xFF && v3 == 30)
          io_sound_ch3 = 36;
        uint8 v4 = 6;
        do {
          if (*(&unusedram_7e14a8 + v4))
            --*(&unusedram_7e14a8 + v4);
        } while (--v4);
      }
    }
    GameMode14_InLevel_HandlePlayerState();
    if ((io_controller_press1 & 0x20) != 0)
      DropReservedItem();
  }
  blocks_note_block_bounce_flag = 0;
}

void GameMode14_InLevel_Return00C592() {  // 00c592
  ;
}

void GameMode14_InLevel_HandlePlayerState() {  // 00c593
  kGameMode14_InLevel_PlayerStatePtrs[player_current_state]();
}

void PlayerState0B_RescuedPeach() {  // 00c5b5
  player_override_walking_frames = 0;
  player_sliding_on_ground = 0;
  if (timer_end_level) {
    CreditsFadeOut();
    if (misc_game_mode != 20) {
      PlayerState00_00C95B();
      return;
    }
  } else {
    mirror_hdmaenable = 0;
  }
  flag_message_window_size_change_direction = 1;
  blocks_screen_to_place_current_object = 7;
  DamagePlayer_DisableButtons();
  PlayerState00_00CD24();
}

void PlayerState0C_CastleDestructionMoves() {  // 00c6e7
  int8 v0;
  uint8 v1, v2;

  DamagePlayer_DisableButtons();
  player_override_walking_frames = 0;
  UpdatePlayerSpritePosition();
  if ((player_yspeed & 0x80) == 0) {
    if ((uint8)player_ypos >= 0x58) {
      player_in_air_flag = 0;
      v0 = 88;
      goto LABEL_14;
    }
    if ((uint8)player_xpos >= 0x40) {
      if ((uint8)player_xpos < 0x60) {
        if ((uint8)player_ypos >= 0x4C) {
          io_sound_ch3 = 27;
          ++l1_l2_scroll_spr_spriteid[0];
          v0 = 76;
          v2 = -12;
          v1 = -64;
          goto LABEL_11;
        }
      } else if ((uint8)mirror_current_layer1_ypos && !sign8(mirror_current_layer1_ypos + player_ypos - 28)) {
        v0 = player_ypos;
        v1 = -48;
        if (!player_facing_direction) {
LABEL_12:
          player_yspeed = v1;
          io_sound_ch1 = 1;
LABEL_14:
          LOBYTE(player_ypos) = v0;
          goto LABEL_15;
        }
        v2 = 0;
LABEL_11:
        player_xspeed = v2;
        goto LABEL_12;
      }
    }
  }
LABEL_15:;
  uint8 v3 = *(kPlayerState0C_CastleDestructionMoves_UNK_00C6DF + misc_currently_active_boss_end_cutscene) + temp8f;
  if (!player_timer_pipe_warping) {
    temp8f += 2;
    v3 += 2;
    player_timer_pipe_warping = kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData[v3 + 1];
    if (*(kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData + v3) == 45)
      io_sound_ch1 = 30;
  }
  if (*(kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData + v3) != 0xFF) {
    uint8 v10 = *(kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData + v3);
    if ((v10 & 0x10) != 0)
      DrawQuestionMark();
    if ((v10 & 0x20) != 0) {
      uint8 v4 = v10 & 0xF;
      if ((v10 & 0xF) >= 7) {
        player_current_pose = kPlayerState0C_CastleDestructionMoves_DATA_00C5E1[v4 - 7];
        player_carrying_something_flag2 = 0;
        HandlePlayerPhysics_InAir();
        goto LABEL_40;
      }
      int8 v5 = v4 - 1;
      if (v5 >= 0) {
        if (!v5) {
          ++l1_l2_scroll_spr_timer[1];
          goto LABEL_40;
        }
        int8 v6 = v5 - 1;
        if (!v6) {
          io_sound_ch1 = 14;
          PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
          ++LOBYTE(pt->x);
          goto LABEL_40;
        }
        int8 v8 = v6 - 1;
        if (!v8) {
          l1_l2_scroll_spr_timer[1] = -120;
          goto LABEL_40;
        }
        int8 v9 = v8 - 1;
        if (!v9) {
          LOBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)->x) = 56;
          LOBYTE(player_xpos) = player_xpos & 0xF8;
          goto LABEL_40;
        }
        if (v9 != 1) {
          timer_display_player_pick_up_pose = 32;
          ++player_carrying_something_flag2;
          goto LABEL_40;
        }
        io_sound_ch3 = 9;
        player_xspeed = -40;
        ++l1_l2_scroll_spr_spriteid[0];
      } else if (timer_display_player_pick_up_pose) {
        io_sound_ch1 = 9;
      }
      ++l1_l2_scroll_spr_spriteid[0];
    } else {
      io_controller_hold1 = v10;
      io_controller_press1 = v10 & 0xBF;
      PlayerState00_00CD39();
    }
LABEL_40:
    --player_timer_pipe_warping;
  }
}

void PlayerState08_WarpToYoshiWingsBonus() {  // 00c7fd
  DamagePlayer_DisableButtons();
  player_in_air_flag = 11;
  HandlePlayerPhysics_InAir();
  if ((int8)player_yspeed >= -112)
    player_yspeed -= 13;
  int8 v0 = 2;
  if (player_xspeed) {
    if ((player_xspeed & 0x80) == 0)
      v0 = -2;
    uint8 old_speed = player_xspeed;
    player_xspeed += v0;
    if ((old_speed & 0x80) == (v0 & 0x80) && (v0 & 0x80) != (player_xspeed & 0x80))  // ovf
      player_xspeed = 0;
  }
  UpdatePlayerSpritePosition();
  if ((int16)(player_on_screen_pos_y - kPlayerState08_WarpToYoshiWingsBonus_DATA_00C7F9[in_yoshi_wings_bonus_area >> 1]) < 0) {
    player_current_state = 0;
    if (!in_yoshi_wings_bonus_area) {
      in_yoshi_wings_bonus_area = 2;
      IncrementSublevelsEnteredAndPrepareToLoadSublevel();
    }
  }
  PlayerState08_WarpToYoshiWingsBonus_00C845();
}

void PlayerState08_WarpToYoshiWingsBonus_00C845() {  // 00c845
  PlayerState00_00CD8F();
}

void PlayerState0A_NoYoshiCutscene() {  // 00c870
  player_spinjump_fireball_timer = 0;
  int8 v0 = kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting];
  if (v0 < 0) {
    DrawBigCastleGate();
  } else if ((v0 & 0x40) != 0) {
    DrawNoYoshiSign();
  } else {
    DrawGhostHouseEntranceDoor();
  }
  uint8 v1 = player_timer_pipe_warping;
  int8 v2 = io_controller_press2 | io_controller_press1;
  DamagePlayer_DisableButtons();
  if (v2 < 0)
    goto LABEL_23;
  player_override_walking_frames = 0;
  if (!--player_pipe_action) {
    v1 += 2;
    player_timer_pipe_warping = v1;
    player_pipe_action = kPlayerState0A_NoYoshiCutscene_DATA_00C848[v1 - 1];
  }
  if (kPlayerState0A_NoYoshiCutscene_DATA_00C848[v1 - 2] == 0xFF) {
LABEL_23:
    ++flag_show_player_start;
    misc_game_mode = 15;
    if (v1 >= 0x11)
      ++yoshi_carry_over_levels_flag;
    PlayerState0A_NoYoshiCutscene_00C90A();
  } else {
    uint8 v3 = kPlayerState0A_NoYoshiCutscene_DATA_00C848[v1 - 2] & 0xDF;
    io_controller_hold1 = v3;
    if (v3 != kPlayerState0A_NoYoshiCutscene_DATA_00C848[v1 - 2])
      io_controller_press2 = 0x80;
    if ((v3 & 0x40) != 0) {
      DamagePlayer_DisableButtons();
      uint8 v4 = -80;
      if ((kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting] & 0x80) == 0)
        v4 = 127;
      timer_no_yoshi_intro_door_timer = v4;
    }
    UpdatePlayerSpritePosition();
    player_in_air_flag = 36;
    uint8 v5 = player_riding_yoshi_flag ? 95 : 111;
    if ((kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting] & 0x40) != 0)
      v5 -= 16;
    if (v5 < (uint8)player_ypos) {
      LOBYTE(player_ypos) = v5 + 1;
      player_in_air_flag = 0;
      player_spin_jump_flag = 0;
    }
    PlayerState00_00CD82();
  }
}

void PlayerState0A_NoYoshiCutscene_00C90A() {  // 00c90a
  flag_prevent_yoshi_carry_over = 1;
  io_sound_ch2 = 3;
}

void PlayerState00_HandleEndOfLevel() {  // 00c915
  DamagePlayer_DisableButtons();
  flag_player_in_lakitus_cloud = 0;
  player_override_walking_frames = 0;
  player_sliding_on_ground = 0;
  if (!(misc_level_layout_flags & 1)) {
    if (!(misc_color_of_palace_switch_pressed1 | misc_currently_active_boss_end_cutscene)) {
      PlayerState00_00C96B();
      return;
    }
    if (player_in_air_flag)
      PlayerState00_00CCE0();
    if (misc_color_of_palace_switch_pressed1)
      goto LABEL_9;
    PlayerState00_00B03E();
    if (timer_level_end_fade < 0x40)
      return;
  }
  ProcessLevelEndRoutines();
LABEL_9:
  flag_sprites_locked = 1;
  if ((counter_global_frames & 1) && !--timer_end_level) {
    if (misc_color_of_palace_switch_pressed1)
      PlayerState00_00C962();
    else
      PlayerState00_00C95B();
  }
}

void PlayerState00_00C95B() {  // 00c95b
  PlayerState00_LevelFinished(0xB, 1);
}

void PlayerState00_00C962() {  // 00c962
  timer_title_screen_input_timer = -96;
  ++misc_display_message;
}

void PlayerState00_00C96B() {  // 00c96b
  HandlePaletteFades();
  if (flag_show_victory_pose_during_level_end) {
    PlayerState00_SetMarioPeaceImg();
    if (timer_show_victory_pose) {
      if (!--timer_show_victory_pose)
        io_music_ch1 = 17;
    } else {
      PlayerState00_00CA44();
      io_controller_hold1 = 1;
      PlayerState00_00CD24();
      if (!timer_hdmawindow_scaling_factor) {
        uint8 v0 = flag_secret_goal_sprite + 1;
        if (flag_secret_goal_sprite == 2 && !g_lunar_magic) {
          ow_players_map[0] = 1;
          v0 = 0;
        }
        uint8 v1 = 12;
        if (flag_active_bonus_game) {
          flag_active_bonus_game = -1;
          mirror_mosaic_size_and_bgenable = -16;
          timer_end_level = 0;
          misc_music_register_backup = 0;
          v1 = 16;
        }
        mirror_screen_display_register = 0;
        misc_mosaic_direction = 0;
        PlayerState00_LevelFinished(v1, v0);
      }
    }
  } else {
    if (timer_end_level >= (g_lunar_magic ? 0x38 : 0x28)) {
      player_facing_direction = 1;
      io_controller_hold1 = 1;
      player_xspeed = 5;
    }
    if (player_in_air_flag)
      HandlePlayerPhysics_00D76B();
    if (!player_xspeed) {
      flag_layer1_horiz_scroll_level_setting = 0;
      PlayerState00_00CA3E();
      ++flag_show_victory_pose_during_level_end;
      timer_show_victory_pose = 64;
      palettes_level_end_color_fade_direction = 0x80;
      timer_level_end_fade = 0;
    }
    PlayerState00_00CD24();
  }
}

void PlayerState00_LevelFinished(uint8 j, uint8 a) {  // 00c9fe
  g_did_finish_level_hook = true;
  misc_exit_level_action = a;
  if (misc_currently_active_boss_end_cutscene) {
    uint8 v2 = 8;
    if (ow_level_number_lo == kLevelsThatTriggerCutscenes[8])
      ++misc_exit_level_action;
    if (ow_level_number_lo != kLevelsThatTriggerCutscenes[9]) {
      while (ow_level_number_lo != kLevelsThatTriggerCutscenes[v2 - 1]) {
        if (!--v2)
          goto LABEL_9;
      }
    }
    misc_currently_active_boss_end_cutscene = v2;
    j = 24;
  }
LABEL_9:
  misc_game_mode = j;
  ++counter_enemy_rollcall_screen;
  PlayerState00_SetMidpointFlag();
}

void PlayerState00_SetMidpointFlag() {  // 00ca2b
  flag_got_midpoint = 1;
}

void PlayerState00_SetMarioPeaceImg() {  // 00ca31
  player_current_pose = player_riding_yoshi_flag ? 20 : 38;
}

void PlayerState00_00CA3E() {  // 00ca3e
  timer_hdmawindow_scaling_factor = -16;
}

void PlayerState00_00CA44() {  // 00ca44
  if (timer_hdmawindow_scaling_factor) {
    UpdateHDMAWindowBuffer_IrisInOnPlayerEntry(0xFC, UpdateHDMAWindowBuffer_SetCircleHDMAPointer());
    mirror_bg1_and2_window_mask_settings = 51;
    mirror_object_and_color_window_settings = 51;
    mirror_bg3_and4_window_mask_settings = 3;
    mirror_color_math_initial_settings = 34;
  }
}

HdmaPtrs UpdateHDMAWindowBuffer_SetCircleHDMAPointer() {  // 00ca61
  return (HdmaPtrs) { .r4 = kUpdateHDMAWindowBuffer_CircleHDMAData, .r6 = kUpdateHDMAWindowBuffer_CircleHDMAData };
}

void UpdateHDMAWindowBuffer_IrisInOnPlayerEntry(uint8 a, HdmaPtrs hptr) {  // 00ca6d
  timer_hdmawindow_scaling_factor += a;
  uint8 r0 = player_on_screen_pos_x + 8;
  uint8 v1 = player_current_power_up ? 16 : 24;
  uint8 r1 = player_on_screen_pos_y + v1;
  if (r1 == 255 || r1 == 0)
    r1 = 1;
  UpdateHDMAWindowBuffer_KeyholeEntry(hptr, r0, r1);
}

void UpdateHDMAWindowBuffer_KeyholeEntry(HdmaPtrs hptr, uint8 r0, uint8 r1) {  // 00ca88
  uint16 v1 = 2 * (2 * r1 - 1);
  uint16 v2 = 0;
  while (r1 >= timer_hdmawindow_scaling_factor) {
    if (v2 < 0x1E0) {
      misc_hdmawindow_effect_table[v2] = 255;
      misc_hdmawindow_effect_table[v2 + 1] = 0;
    }
    if (v1 < 0x1C0) {
      misc_hdmawindow_effect_table[v1] = 255;
      misc_hdmawindow_effect_table[v1 + 1] = 0;
    }
    v2 += 2;
    v1 -= 2;
    if (!r1)
      goto LABEL_21;
    --r1;
  }
  do {
    PairU8 pair = UpdateHDMAWindowBuffer_00CC14(v1, hptr, r1);
    if (v2 < 0x1e0) {
      misc_hdmawindow_effect_table[v2 + 1] = r0 + pair.first < 255 ? r0 + pair.first : 255;
      misc_hdmawindow_effect_table[v2] = r0 >= pair.first ? r0 - pair.first : 0;
    }
    if (v1 < 0x1E0) {
      if (hptr.r6) {
        misc_hdmawindow_effect_table[v1 + 1] = r0 + pair.second < 255 ? r0 + pair.second : 255;
        misc_hdmawindow_effect_table[v1] = r0 >= pair.second ? r0 - pair.second : 0;
      } else {
        misc_hdmawindow_effect_table[v1 + 1] = 0;
        misc_hdmawindow_effect_table[v1] = 255;
      }
    }
    v2 += 2;
    v1 -= 2;
    if (!r1)
      break;
  } while (--r1);
LABEL_21:
  mirror_hdmaenable = 0x80;
}

PairU8 UpdateHDMAWindowBuffer_00CC14(uint16 j, HdmaPtrs hptr, uint8 r1) {  // 00cc14
  uint16 v1 = SnesDivide(r1 << 8, timer_hdmawindow_scaling_factor) >> 1;
  uint8 t = hptr.r6 ? hptr.r6[v1] : 0;
  uint8 r3 = (t * timer_hdmawindow_scaling_factor) >> 8;
  const uint8 *v3 = hptr.r4;
  uint8 result = (v3[v1] * timer_hdmawindow_scaling_factor) >> 8;
  uint8 r2 = result;
  return (PairU8) { .first = r2, .second = r3 };
}

void PlayerState00() {  // 00cc68
  if ((io_controller_hold2 & 0x20) != 0 && io_controller_press2 == 0x80 && ++debug_free_movement >= 3)
    debug_free_movement = 0;
  if (timer_end_level) {
    PlayerState00_HandleEndOfLevel();
  } else {
    PlayerState00_HandleLRScrolling();
    if (!flag_sprites_locked) {
      flag_cape_to_sprite_interaction = 0;
      player_override_walking_frames = 0;
      if (timer_stun_player) {
        --timer_stun_player;
        player_xspeed = 0;
        player_current_pose = 15;
      } else {
        PlayerState00_00CCE0();
      }
    }
  }
}

void PlayerState00_00CCE0() {  // 00cce0
  if ((misc_nmito_use_flag & 0x80) == 0 || misc_nmito_use_flag & 1) {
    PlayerState00_00CD24();
  } else {
    if ((misc_nmito_use_flag & 0x40) != 0 || player_in_air_flag) {
      UpdatePlayerSpritePosition();
    } else {
      player_xpos = player_on_tilting_platform_xpos;
      player_ypos = player_on_tilting_platform_ypos;
      UpdatePlayerSpritePosition();
      player_on_tilting_platform_xpos = player_xpos;
      player_on_tilting_platform_ypos = player_ypos & 0xFFF0;
      PlayerState00_00F9C9(player_on_tilting_platform_xpos, player_on_tilting_platform_ypos, (PointU16) {.x = 0, .y = 0});
    }
    PlayerState00_00F8F2();
    PlayerState00_00CD36();
  }
}

void PlayerState00_00CD24() {  // 00cd24
  if ((player_yspeed & 0x80) != 0 && (player_blocked_flags & 8) != 0)
    player_yspeed = 0;
  UpdatePlayerSpritePosition();
  HandlePlayerLevelCollision();
  PlayerState00_00CD36();
}

void PlayerState00_00CD36() {  // 00cd36
  PlayerState00_CheckPlayerPitFall();
  PlayerState00_00CD39();
}

void PlayerState00_00CD39() {  // 00cd39
  player_turning_around_flag = 0;
  if (timer_inflate_from_pballoon) {
    PlayerState00_00CD95(timer_inflate_from_pballoon);
  } else {
    if (flag_player_climb_on_air)
      player_collision_var8b = 31;
    if (player_climbing_flag || !(player_riding_yoshi_flag | player_carrying_something_flag2) && (player_collision_var8b & 0x1B) == 27 &&
                                    (io_controller_hold1 & 0xC) != 0 &&
                                    (player_in_air_flag || (io_controller_hold1 & 8) != 0 || (player_collision_var8b & 4) != 0)) {
      player_climbing_flag = player_collision_var8b;
      HandlePlayerPhysics_Climbing();
    } else if (player_swimming_flag) {
      HandlePlayerPhysics_Swimming();
      PlayerState00_00CD8F();
    } else {
      PlayerState00_00CD82();
    }
  }
}

void PlayerState00_00CD82() {  // 00cd82
  HandlePlayerPhysics();
  CheckPowerUpSpecificPlayerAttacks();
  HandlePlayerPhysics_InAir();
  PlayerState00_00CD8B();
}

void PlayerState00_00CD8B() {  // 00cd8b
  SetPlayerPose();
  PlayerState00_00CD8F();
}

void PlayerState00_00CD8F() {  // 00cd8f
  uint8 v0 = player_riding_yoshi_flag;
  if (player_riding_yoshi_flag) {
    if (timer_yoshi_tongue_is_out) {
      v0 = 3;
      if (timer_yoshi_tongue_is_out < 0xC)
        v0 = 4;
    }
    uint8 v1 = kPlayerState_OnYoshiAnimations[v0 - 1];
    if (v0 == 1 && player_ducking_flag)
      v1 = 29;
    player_current_pose = v1;
    if (yoshi_yoshi_has_wings == 1 && (io_controller_press1 & 0x40) != 0) {
      unusedram_7e18db = 8;
      SpawnPlayerFireball();
    }
  }
}

void PlayerState00_00CD95(uint8 j) {  // 00cd95
  uint8 v1 = player_current_power_up ? 67 : 66;
  uint8 v2 = j - 1;
  if (v2) {
    timer_inflate_from_pballoon = v2;
    v1 = 15;
  }
  player_current_pose = v1;
}

void PlayerState00_HandleLRScrolling() {  // 00cddd
  uint8 v4;

  if (flag_layer1_horiz_scroll_level_setting) {
    uint8 v0 = misc_lrscroll_direction;
    flag_sprites_locked = flag_lrscroll_flag;
    if (flag_lrscroll_flag)
      goto LABEL_17;
    uint8 v1 = camera_lrscroll_move_flag;
    if (camera_lrscroll_move_flag) {
      misc_lrscroll_direction = 0;
    } else {
      if (io_controller_hold1 | io_controller_hold2 & 0xCF)
        goto LABEL_16;
      uint8 v2 = io_controller_hold2 & 0x30;
      if ((io_controller_hold2 & 0x30) == 0 || v2 == 48)
        goto LABEL_16;
      uint8 v3 = v2 >> 3;
      if (++timer_time_before_lrscroll < 0x10 ||
          (v4 = v3, player_relative_position_needed_to_scroll_screen == kHandleStandardLevelCameraScroll_DATA_00F6CB[v3 >> 1])) {
LABEL_17:
        player_facing_directionx2 = 2 * player_facing_direction;
        uint16 v8 = player_relative_position_needed_to_scroll_screen;
        int v9 = v0 >> 1;
        if (player_relative_position_needed_to_scroll_screen != kHandleStandardLevelCameraScroll_DATA_00F6CB[v9]) {
          v8 = kHandleStandardLevelCameraScroll_DATA_00F6BF[v9] + player_relative_position_needed_to_scroll_screen;
          if (v8 != kHandleStandardLevelCameraScroll_DATA_00F6B3[player_facing_directionx2 >> 1]) {
LABEL_21:
            player_relative_position_needed_to_scroll_screen = v8;
            camera_lrscroll_move_flag = 0;
            return;
          }
          misc_lrscroll_direction = 0;
        }
        flag_lrscroll_flag = 0;
        goto LABEL_21;
      }
      player_relative_position_needed_to_scroll_screen &= ~1;
      ++flag_lrscroll_flag;
      uint8 v5 = (v4 == 2) ? camera_last_screen_horiz - 1 : 0;
      if ((v5 << 8) != mirror_current_layer1_xpos)
        io_sound_ch3 = 14;
      v1 = v4;
      misc_lrscroll_direction = v4;
    }
    v0 = v1;
LABEL_16:
    timer_time_before_lrscroll = 0;
    goto LABEL_17;
  }
}

void SetPlayerPose() {  // 00ceb1
  if (timer_cape_flap_animation)
    goto LABEL_26;
  uint8 v0 = player_cape_image;
  uint8 v1;
  if (player_in_air_flag) {
    v1 = 4;
    if ((player_yspeed & 0x80) == 0) {
      v0 = player_cape_image + 1;
      if ((uint8)(player_cape_image + 1) >= 5) {
        if (v0 >= 0xB)
          v0 = 7;
      } else {
        v0 = 5;
      }
      goto LABEL_23;
    }
    if (player_in_air_flag != 12 && !player_swimming_flag)
      goto LABEL_13;
LABEL_19:
    v0 = player_cape_image + 1;
    if ((uint8)(player_cape_image + 1) < 3)
      v0 = 5;
    if (v0 >= 7)
      v0 = 3;
    goto LABEL_23;
  }
  uint8 v2 = player_xspeed;
  if (player_xspeed) {
    if ((player_xspeed & 0x80) != 0)
      v2 = -player_xspeed;
    v1 = kSetPlayerPose_AnimationSpeedTable[v2 >> 3];
    goto LABEL_19;
  }
  v1 = 8;
LABEL_13:
  if (player_cape_image) {
    v0 = player_cape_image - 1;
    if ((uint8)(player_cape_image - 1) >= 3)
      v0 = 2;
  }
LABEL_23:
  player_cape_image = v0;
  uint8 v3 = v1;
  if (player_swimming_flag)
    v3 = 2 * v1;
  timer_cape_flap_animation = v3;
LABEL_26:
  if (!(timer_active_cape_spin | player_spin_jump_flag)) {
    uint8 v7 = player_sliding_on_ground;
    if (player_sliding_on_ground) {
      if ((player_sliding_on_ground & 0x80) != 0)
        v7 = kSetPlayerPose_DATA_00CE7F[player_facing_direction | (player_slope_player_is_on1 >> 2)];
      goto LABEL_57;
    }
    v7 = 60;
    if (player_carrying_something_flag2)
      v7 = 29;
    if (player_ducking_flag)
      goto LABEL_57;
    if (timer_display_player_shoot_fireball_pose) {
      v7 = 63;
      if (player_in_air_flag)
        v7 = 22;
      goto LABEL_57;
    }
    v7 = 14;
    if (!timer_display_player_kicking_pose) {
      v7 = 29;
      if (!timer_display_player_pick_up_pose) {
        v7 = 15;
        if (!timer_display_player_face_screen_pose) {
          if (flag_player_in_lakitus_cloud) {
            SetPlayerPose_Entry3(0);
            return;
          }
          v7 = player_in_air_flag;
          if (player_in_air_flag) {
            if (!timer_show_running_frames_before_take_off) {
              if (player_cape_flying_phase)
                v7 = kSetPlayerPose_DATA_00CE79[player_cape_flying_phase - 1];
              if (player_carrying_something_flag2) {
                SetPlayerPose_Entry4(9);
                return;
              }
              goto LABEL_57;
            }
LABEL_58:
            SetPlayerPose_Entry2();
            return;
          }
          v7 = player_turning_around_flag;
          if (!player_turning_around_flag)
            goto LABEL_58;
        }
      }
    }
LABEL_57:
    SetPlayerPose_Entry4(v7);
    return;
  }
  player_ducking_flag = 0;
  uint8 v4 = counter_local_frames & 6;
  uint8 v5 = counter_local_frames & 6;
  if (player_in_air_flag && (player_yspeed & 0x80) == 0)
    ++v5;
  player_cape_image = kSetPlayerPose_DATA_00CEA9[v5];
  if (player_current_power_up)
    ++v4;
  uint8 v6 = kSetPlayerPose_DATA_00CEA1[v4];
  player_facing_direction = v6;
  if (player_current_power_up == 2)
    InitializeCapeSwingOrNetPunch(v6);
  SetPlayerPose_Entry4(kSetPlayerPose_DATA_00CE99[v4]);
}

void SetPlayerPose_Entry2() {  // 00cfbc
  if ((player_xspeed & 0x80) != 0)
    SetPlayerPose_Entry3(-player_xspeed);
  else
    SetPlayerPose_Entry3(player_xspeed);
}

void SetPlayerPose_Entry3(uint8 a) {  // 00cfc3
  uint8 v2, v3;
  if (!a) {
    v2 = 0;
    if ((io_controller_hold1 & 8) != 0)
      player_override_walking_frames = 3;
LABEL_11:
    v3 = v2;
    goto LABEL_12;
  }
  if (flag_ice_level) {
    v3 = io_controller_hold1 & 3;
    if ((io_controller_hold1 & 3) == 0)
      goto LABEL_12;
    player_anim_speed_index = 104;
  }
  v3 = player_walking_frame;
  if (!player_anim_timer) {
    uint8 v4 = player_walking_frame - 1;
    if ((int8)v4 < 0)
      v4 = kSetPlayerPose_WalkingPoseCount[player_current_power_up];
    v2 = v4;
    player_anim_timer = kSetPlayerPose_AnimationSpeedTable[player_anim_speed_index | (a >> 3)];
    goto LABEL_11;
  }
LABEL_12:
  player_walking_frame = v3;
  uint8 v5 = player_override_walking_frames + v3;
  if (player_carrying_something_flag2) {
    SetPlayerPose_Entry4(v5 + 7);
  } else if (a >= 0x2F) {
    SetPlayerPose_Entry4((a >= 0x2F) + v5 + 3);
  } else {
    SetPlayerPose_Entry4(v5);
  }
}

void SetPlayerPose_Entry4(uint8 a) {  // 00d01a
  if (player_wall_walk_status) {
    player_facing_direction = player_wall_walk_status & 1;
    a = 16;
    if (player_wall_walk_status >= 6)
      a = player_walking_frame + 17;
  }
  player_current_pose = a;
}

void InitializeCapeSwingOrNetPunch(uint8 a) {  // 00d044
  flag_cape_to_sprite_interaction = 1;
  int v1 = (uint8)(2 * a) >> 1;
  player_cape_hitbox_x = kInitializeCapeSwingOrNetPunch_DATA_00D034[v1] + player_xpos;
  player_cape_hitbox_y = kInitializeCapeSwingOrNetPunch_DATA_00D03C[v1] + player_ypos;
}

void CheckPowerUpSpecificPlayerAttacks() {  // 00d062
  if (player_current_power_up == 2) {
    if ((io_controller_press1 & 0x40) != 0 && !(player_spin_jump_flag | (uint8)(player_riding_yoshi_flag | player_ducking_flag))) {
      timer_active_cape_spin = 18;
      io_sound_ch3 = 4;
    }
  } else if (player_current_power_up == 3 && !(player_riding_yoshi_flag | player_ducking_flag)) {
    if ((io_controller_press1 & 0x40) == 0) {
      if (!player_spin_jump_flag || (++player_spinjump_fireball_timer & 0xF) != 0)
        return;
      player_facing_direction = (player_spinjump_fireball_timer & 0x10) != 0;
    }
    SpawnPlayerFireball();
  }
}

void PlayerState09_Death() {  // 00d0b6
  player_current_power_up = 0;
  player_current_pose = 62;
  if ((counter_global_frames & 3) == 0)
    --player_anim_timer;
  if (!player_anim_timer) {
    misc_exit_level_action = 0x80;
    if (!flag_prevent_yoshi_carry_over)
      yoshi_carry_over_levels_flag = 0;
    if ((--player_current_life_count & 0x80) == 0) {
      if (counter_timer_ones | counter_timer_tens | counter_timer_hundreds) {
        misc_game_mode = 11;
        return;
      }
      misc_death_message_to_display = 29;
    } else {
      io_music_ch1 = 10;
      misc_death_message_to_display = 20;
    }
    timer_display_death_message_animation = -64;
    timer_time_to_display_death_message = -1;
    misc_game_mode = 21;
    return;
  }
  if (player_anim_timer < 0x26) {
    player_xspeed = 0;
    UpdatePlayerSpritePosition();
    HandlePlayerPhysics_D930(0);
    player_facing_direction = (counter_global_frames & 4) != 0;
  }
}

void PlayerStateXX_PowerupAnims_PowerDownEntry() {  // 00d129
  if (player_anim_timer) {
    player_current_pose = kPlayerStateXX_PowerupAnims_GrowingAniImgs[player_anim_timer >> 2];
    if (player_anim_timer)
      --player_anim_timer;
  } else {
    timer_player_hurt = 127;
    PlayerStateXX_PowerupAnims_Done();
  }
}

void PlayerStateXX_PowerupAnims_GrowAnimationEntry() {  // 00d147
  if (player_anim_timer) {
    player_current_pose = kPlayerStateXX_PowerupAnims_GrowingAniImgs[11 - (player_anim_timer >> 2)];
    if (player_anim_timer)
      --player_anim_timer;
  } else {
    ++player_current_power_up;
    PlayerStateXX_PowerupAnims_Done();
  }
}

void PlayerStateXX_PowerupAnims_Done() {  // 00d158
  player_current_state = 0;
  flag_sprites_locked = 0;
}

void PlayerStateXX_PowerupAnims_GotCape() {  // 00d15f
  player_hide_player_tile_flags = 127;
  if (!--player_anim_timer) {
    if (!(player_current_power_up >> 1))
      timer_player_hurt = 127;
    PlayerStateXX_PowerupAnims_Done();
  }
}

void PlayerStateXX_PowerupAnims_GotFlower() {  // 00d16f
  if (player_cape_flying_phase | player_sliding_on_ground & 0x80) {
    player_cape_flying_phase = 0;
    player_sliding_on_ground &= ~0x80;
    player_current_pose = 0;
  }
  if (!--timer_player_palette_cycle)
    PlayerStateXX_PowerupAnims_Done();
}

void PlayerStateXX_EnterPipe_Horizontal() {  // 00d197
  DamagePlayer_DisableButtons();
  player_override_walking_frames = 0;
  SetPlayerPose();
  SetPlayerPose_Entry2();
  PlayerStateXX_EnterPipe_00D1F4();
  if (player_riding_yoshi_flag)
    player_current_pose = 41;
  player_ypos = (player_ypos - 8) & 0xFFF0 | 0xE;
  uint8 v0 = (player_pipe_action >> 1) + 1;
  uint8 v1 = kPlayerStateXX_EnterPipe_HIDEPIPESETS[v0 - 1];
  if (player_carrying_something_flag2) {
    v1 ^= 0x1C;
    --timer_display_player_face_screen_pose;
    timer_display_player_face_screen_pose += (timer_display_player_face_screen_pose & 0x80) != 0;
  }
  if (player_timer_pipe_warping < 0x1D) {
    if (v0 >= 3) {
      ++player_ypos;
      ++player_ypos;
    }
    v1 = kPlayerStateXX_EnterPipe_HIDEPIPESETS[v0];
  }
  player_hide_player_tile_flags = v1;
  PlayerStateXX_EnterPipe_00D22D();
}

void PlayerStateXX_EnterPipe_00D1F4() {  // 00d1f4
  if (timer_cape_flap_animation)
    --timer_cape_flap_animation;
  if (player_anim_timer)
    --player_anim_timer;
}

void PlayerStateXX_EnterPipe_Vertical() {  // 00d203
  DamagePlayer_DisableButtons();
  player_cape_image = 0;
  uint8 pose = 15;
  if (player_riding_yoshi_flag) {
    uint8 v1 = 0;
    if ((player_xpos & 0xF) != kPlayerStateXX_EnterPipe_PipeCntrBoundryX[player_facing_direction]) {
      if ((int8)((player_xpos & 0xF) - kPlayerStateXX_EnterPipe_PipeCntrBoundryX[player_facing_direction]) < 0)
        v1 = 1;
      LOBYTE(player_xpos) = kPlayerStateXX_EnterPipe_PipeCntringSpeed[v1] + player_xpos;
    }
    pose = 33;
  }
  player_current_pose = pose;
  PlayerStateXX_EnterPipe_00D22D();
}

void PlayerStateXX_EnterPipe_00D22D() {  // 00d22d
  io_controller_hold1 = 64;
  player_current_layer_priority = 2;
  if (player_timer_pipe_warping) {
    uint8 v0 = player_pipe_action & 3;
    if (!--player_timer_pipe_warping && player_pipe_action < 4) {
      player_hide_player_tile_flags = 127;
      ++flag_about_to_warp_in_pipe;
    }
    if (!(player_yspeed | player_xspeed))
      io_sound_ch1 = 4;
    player_xspeed = kPlayerStateXX_EnterPipe_PipeXSpeed[v0];
    player_yspeed = kPlayerStateXX_EnterPipe_PipeYSpeed[v0];
    player_in_air_flag = 0;
    UpdatePlayerSpritePosition();
  } else {
    if (player_pipe_action < 4)
      IncrementSublevelsEnteredAndPrepareToLoadSublevel();
    else
      PlayerStateXX_EnterPipe_00D26A();
  }
}

void PlayerStateXX_EnterPipe_00D26A() {  // 00d26a
  player_current_layer_priority = 0;
  yoshi_in_pipe = 0;
  PlayerStateXX_PowerupAnims_Done();
}

void IncrementSublevelsEnteredAndPrepareToLoadSublevel() {  // 00d273
  ++counter_sublevels_entered;
  misc_game_mode = 15;
}

void UnusedAddToWarpPipeTimerRoutine() {  // 00d27c
  player_timer_pipe_warping += player_ypos - player_current_ypos;
}

void PlayerState07_ShootOutOfPipe() {  // 00d287
  DamagePlayer_DisableButtons();
  player_current_layer_priority = 2;
  player_in_air_flag = 12;
  PlayerState00_00CD8B();
  if (!--player_timer_pipe_warping) {
    PlayerStateXX_EnterPipe_00D26A();
    return;
  }
  if (player_timer_pipe_warping < 0x18)
    goto LABEL_6;
  if (player_timer_pipe_warping == 24) {
    io_sound_ch3 = 9;
LABEL_6:
    player_current_layer_priority = 0;
    yoshi_in_pipe = 0;
    flag_sprites_locked = 0;
  }
  player_xspeed = 64;
  player_yspeed = -64;
  UpdatePlayerSpritePosition();
}

void HandlePlayerPhysics() {  // 00d5f2
  uint8 v4;
  uint8 r1 = 0;
  if (!player_in_air_flag) {
    player_ducking_flag = 0;
    if (!player_sliding_on_ground && (io_controller_hold1 & 4) != 0) {
      player_ducking_flag = io_controller_hold1 & 4;
      flag_cape_to_sprite_interaction = 0;
    }
    if (misc_player_on_solid_sprite == 2 || (player_blocked_flags & 8) != 0 ||
        ((io_controller_press2 | io_controller_press1) & 0x80) == 0) {
      if (player_ducking_flag) {
        if (player_xspeed) {
          if (!flag_ice_level)
            SpawnPlayerTurnAroundSmoke();
        }
        goto LABEL_12;
      }
    } else {
      uint8 v0 = player_xspeed;
      if ((player_xspeed & 0x80) != 0)
        v0 = -player_xspeed;
      uint8 v1 = (v0 >> 2) & 0xFE;
      if ((io_controller_press2 & 0x80) == 0 || player_carrying_something_flag2) {
        io_sound_ch2 = 1;
      } else {
        player_spin_jump_flag = player_carrying_something_flag2 + 1;
        io_sound_ch3 = 4;
        player_spinjump_fireball_timer = kHandlePlayerPhysics_DATA_00D5F0[player_facing_direction];
        if (player_riding_yoshi_flag)
          goto LABEL_25;
        ++v1;
      }
      player_yspeed = kHandlePlayerPhysics_JumpHeightTable[v1];
      uint8 v2 = 11;
      if (player_pmeter >= 0x70) {
        if (!timer_wait_before_cape_flight_begins)
          timer_wait_before_cape_flight_begins = 80;
        v2 = 12;
      }
      player_in_air_flag = v2;
      player_sliding_on_ground = 0;
    }
  }
LABEL_25:
  if ((player_sliding_on_ground & 0x80) != 0) {
LABEL_28:
    SpawnPlayerTurnAroundSmoke();
    if (player_slope_player_is_on2) {
      HandlePlayerPhysics_UpdatePMeter();
      HandlePlayerPhysics_00D742(((player_slope_player_is_on1 & 2) != 0) + (player_slope_player_is_on1 >> 2) + 118,
                                      ((player_slope_player_is_on1 & 4) != 0) + (player_slope_player_is_on1 >> 3) - 121);
      return;
    }
LABEL_12:
    HandlePlayerPhysics_00D764();
    return;
  }
  if ((io_controller_hold1 & 3) == 0) {
LABEL_27:
    if (!player_sliding_on_ground)
      goto LABEL_12;
    goto LABEL_28;
  }
  player_sliding_on_ground = 0;
  int8 v3 = io_controller_hold1 & 1;
  if (!player_cape_flying_phase) {
    if (v3 != player_facing_direction) {
      if (!player_carrying_something_flag2) {
LABEL_39:
        player_facing_direction = io_controller_hold1 & 1;
        goto LABEL_40;
      }
      if (!timer_display_player_face_screen_pose) {
        timer_display_player_face_screen_pose = 8;
        goto LABEL_39;
      }
    }
LABEL_40:
    r1 = io_controller_hold1 & 1;
    v4 = player_slope_player_is_on1 | (4 * v3);
    if (player_xspeed && ((*((uint8 *)kHandlePlayerPhysics_MarioAccel + v4 + 1) ^ player_xspeed) & 0x80) != 0 &&
        !timer_player_slides_when_turing) {
      if (!flag_ice_level) {
        player_turning_around_flag = 13;
        SpawnPlayerTurnAroundSmoke();
      }
      v4 -= 112;
    }
    goto LABEL_46;
  }
  if (v3 != player_facing_direction && (io_controller_press1 & 0x80) == 0)
    goto LABEL_27;
  player_slope_player_is_on1 = kHandlePlayerPhysics_DATA_00D5EE[player_facing_direction];
  r1 = io_controller_hold1 & 1;
  v4 = player_slope_player_is_on1 | (4 * v3);
LABEL_46:;
  uint8 v5 = 0;
  if ((io_controller_hold1 & 0x40) == 0)
    goto LABEL_54;
  v4 += 2;
  v5 = 1;
  uint8 v6 = player_xspeed;
  if ((player_xspeed & 0x80) != 0)
    v6 = -player_xspeed;
  if (sign8(v6 - 35))
    goto LABEL_54;
  if (!player_in_air_flag) {
    timer_show_running_frames_before_take_off = 16;
LABEL_53:
    v5 = 2;
    goto LABEL_54;
  }
  if (player_in_air_flag == 12)
    goto LABEL_53;
LABEL_54:
  v5 = HandlePlayerPhysics_UpdatePMeterEx(v5);
  HandlePlayerPhysics_00D742(v4, r1 | player_slope_player_is_on1 | (2 * v5));
}

void HandlePlayerPhysics_00D742(uint8 k, uint8 j) {  // 00d742
  if (player_xspeed == kHandlePlayerPhysics_DATA_00D535[j] ||
      ((kHandlePlayerPhysics_DATA_00D535[j] ^ (player_xspeed - kHandlePlayerPhysics_DATA_00D535[j])) & 0x80) == 0) {
    HandlePlayerPhysics_00D76B();
  } else {
    int v2 = k >> 1;
    uint16 v3 = kHandlePlayerPhysics_MarioAccel[v2];
    if (flag_ice_level) {
      if (!player_in_air_flag)
        v3 = kHandlePlayerPhysics_DATA_00D43D[v2];
    }
    *(uint16 *)&player_sub_xspeed = *(uint16 *)&player_sub_xspeed + v3;
  }
}

void HandlePlayerPhysics_00D764() {  // 00d764
  HandlePlayerPhysics_UpdatePMeter();
  if (!player_in_air_flag)
    HandlePlayerPhysics_00D76B();
}

void HandlePlayerPhysics_00D76B() {  // 00d76b
  HandlePlayerPhysics_00D772(player_slope_player_is_on1 >> 2, player_slope_player_is_on1 >> 1);
}

void HandlePlayerPhysics_00D772(uint8 k, uint8 j) {  // 00d772
  uint16 v2;
  if ((int8)(player_xspeed - *((uint8 *)kHandlePlayerPhysics_DATA_00D5C9 + k + 1)) < 0)
    j += 2;
  if (player_in_air_flag | timer_end_level || (v2 = kHandlePlayerPhysics_DATA_00D309[j >> 1], *(int16 *)&flag_underwater_level >= 0)) {
    v2 = kHandlePlayerPhysics_DATA_00D2CD[j >> 1];
  }
  *(uint16 *)&player_sub_xspeed += v2;
  int v3 = k >> 1;
  if (((kHandlePlayerPhysics_DATA_00D2CD[j >> 1] ^ (*(uint16 *)&player_sub_xspeed - kHandlePlayerPhysics_DATA_00D5C9[v3])) & 0x8000) == 0)
    *(uint16 *)&player_sub_xspeed = kHandlePlayerPhysics_DATA_00D5C9[v3];
}

void HandlePlayerPhysics_InAir() {  // 00d7e4
  uint8 v0, v6;
  if (!player_cape_flying_phase) {
    if (!player_in_air_flag || player_spin_jump_flag | (uint8)(player_riding_yoshi_flag | player_carrying_something_flag2) ||
        (int8)player_sliding_on_ground > 0 || (player_sliding_on_ground = 0, player_current_power_up != 2) ||
        (player_yspeed & 0x80) != 0 || !timer_wait_before_cape_flight_begins) {
LABEL_43:
      if (player_in_air_flag) {
        uint8 v5 = 0;
        if (player_riding_yoshi_flag && yoshi_yoshi_has_wings >> 1) {
          v6 = 2;
          if (player_current_power_up != 2)
            v5 = 1;
          goto LABEL_54;
        }
        if (player_current_power_up == 2) {
          if (player_in_air_flag == 12) {
            v6 = 1;
            if (timer_wait_before_cape_flight_begins > 1)
              goto LABEL_54;
            ++timer_wait_before_cape_flight_begins;
          }
          v6 = 0;
LABEL_54:
          if (!timer_time_to_float_after_cape_flight) {
            if ((*(&io_controller_hold1 + v5) & 0x80) == 0) {
LABEL_60:
              if (v6 == 2) {
                HandlePlayerPhysics_D930(2);
                return;
              }
              goto LABEL_62;
            }
            timer_time_to_float_after_cape_flight = 16;
          }
          if (((player_yspeed & 0x80) == 0 ||
               (kHandlePlayerPhysics_DATA_00D7B9[v6] & 0x80) != 0 && player_yspeed >= kHandlePlayerPhysics_DATA_00D7B9[v6]) &&
              (int8)(kHandlePlayerPhysics_DATA_00D7B9[v6] - player_yspeed) <= 0) {
            player_yspeed = kHandlePlayerPhysics_DATA_00D7B9[v6];
            return;
          }
          goto LABEL_60;
        }
      }
LABEL_62:
      if ((io_controller_hold1 & 0x80) == 0)
        HandlePlayerPhysics_D930(0);
      else
        HandlePlayerPhysics_D930(1);
      return;
    }
    player_ducking_flag = 0;
    player_in_air_flag = 11;
    player_furthest_cape_dive_stage = 0;
    HandlePlayerPhysics_00D94F();
    v0 = 2;
    goto LABEL_21;
  }
  if (player_cape_flying_phase >= 2)
    HandlePlayerPhysics_00D94F();
  v0 = player_cape_glide_index;
  if (player_cape_glide_index == 4)
    goto LABEL_20;
  v0 = 3;
  if ((player_yspeed & 0x80) != 0)
    goto LABEL_20;
  if ((io_controller_hold1 & 3) == 0) {
    if (player_cape_flying_phase < 4)
      v0 = 2;
    goto LABEL_20;
  }
  uint8 v1 = (uint8)(io_controller_hold1 & 3) >> 1;
  if (player_facing_direction)
    v1 ^= 1;
  v0 = v1;
  if (v1 == player_cape_glide_index) {
LABEL_20:
    if (timer_change_diving_state)
      goto LABEL_27;
  }
LABEL_21:
  if ((io_controller_hold1 & 0x40) == 0)
    v0 = 4;
  if (player_cape_flying_phase != kHandlePlayerPhysics_DATA_00D7D4[v0]) {
    player_cape_flying_phase += kHandlePlayerPhysics_CapeSpeed[v0];
    uint8 v2 = 8;
    if (player_furthest_cape_dive_stage == 0xC8)
      v2 = 2;
    timer_change_diving_state = v2;
  }
LABEL_27:
  player_cape_glide_index = v0;
  uint8 v3 = player_cape_flying_phase;
  if (!player_cape_flying_phase)
    goto LABEL_43;
  uint8 v4 = player_yspeed;
  if ((player_yspeed & 0x80) == 0) {
    if (player_yspeed >= kHandlePlayerPhysics_DATA_00D7C8[player_cape_flying_phase])
      v4 = kHandlePlayerPhysics_DATA_00D7C8[player_cape_flying_phase];
  } else if (player_yspeed < 0xC8) {
    v4 = -56;
  }
  if (player_cape_flying_phase == 1) {
    if (!player_furthest_cape_dive_stage)
      goto LABEL_41;
    if ((player_yspeed & 0x80) != 0) {
      if (player_yspeed < player_furthest_cape_dive_stage) {
        player_yspeed = player_furthest_cape_dive_stage;
        player_furthest_cape_dive_stage = 0;
      }
    } else {
      io_sound_ch1 = 9;
    }
    if (!player_xspeed || ((kHandlePlayerPhysics_DATA_00D535[player_facing_direction] ^ player_xspeed) & 0x80) != 0)
LABEL_41:
      v3 = 2;
  }
  player_yspeed = kHandlePlayerPhysics_DATA_00D7A5[v3 + 3] + v4;
}

void HandlePlayerPhysics_D930(uint8 j) {  // 00d930
  uint8 v1 = player_yspeed;
  if ((player_yspeed & 0x80) == 0) {
    if (player_yspeed >= kHandlePlayerPhysics_DATA_00D7AF[j])
      v1 = kHandlePlayerPhysics_DATA_00D7AF[j];
    if (player_in_air_flag && player_in_air_flag == 11)
      player_in_air_flag = 36;
  }
  player_yspeed = kHandlePlayerPhysics_DATA_00D7A5[j] + v1;
}

void HandlePlayerPhysics_00D94F() {  // 00d94f
  unusedram_7e140a = 0;
  uint8 v0 = player_yspeed;
  if ((player_yspeed & 0x80) != 0)
    v0 = 0;
  if ((int8)(kHandlePlayerPhysics_DATA_00D7D9[v0 >> 3] - player_furthest_cape_dive_stage) < 0)
    player_furthest_cape_dive_stage = kHandlePlayerPhysics_DATA_00D7D9[v0 >> 3];
}

void HandlePlayerPhysics_UpdatePMeter() {  // 00d968
  HandlePlayerPhysics_UpdatePMeterEx(0);
}

uint8 HandlePlayerPhysics_UpdatePMeterEx(uint8 j) {  // 00d96a
  int8 v1 = kHandlePlayerPhysics_DATA_00D5EB[j] + player_pmeter;
  if (v1 < 0)
    v1 = 0;
  if ((uint8)v1 >= 0x70) {
    j += 1;
    v1 = 112;
  }
  player_pmeter = v1;
  return j;
}

void HandlePlayerPhysics_Swimming() {  // 00d988
  int8 v4;
  player_sliding_on_ground = 0;
  player_ducking_flag = 0;
  player_cape_flying_phase = 0;
  player_spin_jump_flag = 0;
  uint8 v0 = player_yspeed;
  if (player_carrying_something_flag2) {
    if (player_in_air_flag || ((io_controller_press2 | io_controller_press1) & 0x80) == 0) {
      if ((io_controller_hold1 & 4) == 0)
        goto LABEL_7;
    } else {
      player_in_air_flag = 11;
      player_sliding_on_ground = 0;
      v0 = -16;
    }
    HandlePlayerPhysics_00DAA9();
    v0 += 8;
LABEL_7:;
    int8 v1 = v0 + 1;
    if (!player_can_jump_out_of_water) {
      --v1;
      if ((counter_local_frames & 3) == 0)
        v1 -= 2;
    }
    uint8 v2 = v1;
    if ((int8)v1 < 0) {
      if ((uint8)v1 < 0xF0)
        v2 = -16;
    } else if ((uint8)v1 >= 0x10) {
      v2 = 16;
    }
    player_yspeed = v2;
    uint8 v3 = 0x80;
    v4 = io_controller_hold1 & 3;
    if ((io_controller_hold1 & 3) != 0)
      goto LABEL_34;
    v4 = player_facing_direction;
LABEL_33:
    v3 = 120;
LABEL_34:
    player_facing_direction = v4 & 1;
    uint8 v7 = 4 * (v4 & 1);
    uint8 v8 = v3 | v4 & 1;
    if (flag_layer3_tide_level)
      v8 += 4;
    uint8 v9 = v8;
    if (player_in_air_flag)
      v9 = v8 + 2;
    HandlePlayerPhysics_00D742(v7, v9);
    goto LABEL_43;
  }
  if (((io_controller_press2 | io_controller_press1) & 0x80) != 0 && !player_can_jump_out_of_water) {
    HandlePlayerPhysics_00DAA9();
    if (!player_in_air_flag) {
      player_in_air_flag = 11;
      player_sliding_on_ground = 0;
      v0 = -16;
    }
    v0 -= 32;
  }
  if ((counter_local_frames & 3) == 0)
    v0 += 2;
  uint8 v5 = (uint8)(io_controller_hold1 & 0xC) >> 2;
  uint8 v6 = v0;
  if ((v0 & 0x80) != 0) {
    if (v0 < kHandlePlayerPhysics_SwimYSpeed[v5])
      v6 = kHandlePlayerPhysics_SwimYSpeed[v5];
  } else if (v0 >= 0x40) {
    v6 = 64;
  }
  player_yspeed = v6;
  if (player_in_air_flag || (io_controller_hold1 & 4) == 0) {
    v4 = io_controller_hold1 & 3;
    if ((io_controller_hold1 & 3) != 0)
      goto LABEL_33;
  } else {
    flag_cape_to_sprite_interaction = 0;
    ++player_ducking_flag;
  }
  uint8 v10 = 0;
  if (flag_layer3_tide_level) {
    v10 = 30;
    if (!player_in_air_flag)
      v10 = 32;
  }
  HandlePlayerPhysics_00D772(v10, 0);
LABEL_43:
  CheckPowerUpSpecificPlayerAttacks();
  SetPlayerPose();
  if (!timer_active_cape_spin && player_in_air_flag) {
    uint8 v11 = 24;
    if (!timer_display_player_shoot_fireball_pose)
      v11 = kHandlePlayerPhysics_SwimPoses[(player_anim_timer >> 2) & 3];
    if (player_carrying_something_flag2)
      ++v11;
    player_current_pose = v11;
  }
}

void HandlePlayerPhysics_00DAA9() {  // 00daa9
  io_sound_ch1 = 14;
  player_anim_timer |= 0x10;
}

void HandlePlayerPhysics_Climbing() {  // 00db17
  uint8 v7;
  player_in_air_flag = 0;
  player_yspeed = 0;
  player_cape_image = 0;
  player_spin_jump_flag = 0;
  uint8 j = timer_on_swinging_climbing_net_door;
  if (j) {
    uint8 v1 = sprites_player_xspeed_on_swinging_net_door;
    if ((v1 & 0x80) != 0)
      v1 = -v1;
    uint8 k = v1;
    if (j >= 0x1E) {
      uint8 v3 = kHandlePlayerPhysics_DATA_00DADF[v1];
      if ((sprites_player_xspeed_on_swinging_net_door & 0x80) != 0)
        v3 = -v3;
      player_xspeed = v3;
      player_sub_xspeed = 0;
      player_sub_xpos = 0;
    }
    uint8 t = sprites_player_xspeed_on_swinging_net_door ^ (j < 8 ? 0x80 : 0);
    uint16 v4 = kHandlePlayerPhysics_DATA_00DAF1[k];
    if (!(t & 0x80))
      v4 = -v4;
    *(uint16 *)&player_sub_xspeed += v4;
    uint8 v5 = player_facing_direction_on_net_door | (j >> 1) & 0xE;
    uint8 v6 = kHandlePlayerPhysics_DATA_00DABD[v5];
    if ((sprites_player_xspeed_on_swinging_net_door & 0x80) == 0)
      v6 ^= 1;
    player_facing_direction = v6;
    v7 = kHandlePlayerPhysics_SwingOnNetDoorPoses[v5];
    goto LABEL_15;
  }
  player_xspeed = 0;
  player_sub_xspeed = 0;
  uint8 v8 = player_current_layer_priority;
  if (timer_display_player_net_punch_pose) {
    InitializeCapeSwingOrNetPunch(player_current_layer_priority + 2);
    v7 = kHandlePlayerPhysics_NetPunchingPoses[v8];
LABEL_15:
    player_current_pose = v7;
    return;
  }
  uint8 v9 = player_swimming_flag;
  if ((io_controller_press1 & 0x80) != 0) {
    player_in_air_flag = 11;
    player_yspeed = kHandlePlayerPhysics_JumpFromVineYSpeed[player_swimming_flag];
    io_sound_ch2 = 1;
LABEL_29:
    player_climbing_flag = 0;
    return;
  }
  if ((io_controller_press1 & 0x40) && (player_climbing_flag & 0x80) != 0) {
    io_sound_ch1 = 1;
    player_facing_direction_on_net_door = v8;
    player_facing_direction = ((uint8)(player_xpos & 8) >> 3) ^ 1;
    timer_display_player_net_punch_pose = 8;
  }
  player_current_pose = kHandlePlayerPhysics_ClimbingPoses[v8];
  if ((io_controller_hold1 & 3) != 0) {
    int8 v10 = (uint8)(io_controller_hold1 & 3) >> 1;
    if ((player_collision_var8b & 0x18) == 24)
      goto LABEL_25;
    if ((player_climbing_flag & 0x80) == 0)
      goto LABEL_29;
    if (v10 != player_collision_var8c)
LABEL_25:
      player_xspeed = kHandlePlayerPhysics_ClimbingSpeed[(uint8)(player_swimming_flag | (2 * v10))];
  }
  uint8 v11 = io_controller_hold1 & 0xC;
  if ((io_controller_hold1 & 0xC) != 0) {
    if ((io_controller_hold1 & 8) == 0) {
      int8 v12 = player_collision_var8b & 1;
      player_collision_var8b >>= 1;
      if (!v12)
        goto LABEL_29;
      goto LABEL_31;
    }
    v9 += 2;
    v11 = player_collision_var8b & 2;
    if ((player_collision_var8b & 2) != 0) {
LABEL_31:
      if ((player_climbing_flag & 0x80) == 0)
        player_xspeed = 0;
      v11 = kHandlePlayerPhysics_ClimbingSpeed[v9];
      player_yspeed = v11;
    }
  }
  if (player_xspeed | v11) {
    player_anim_timer |= 8;
    if ((player_anim_timer & 7) == 0)
      player_facing_direction ^= 1;
  }
}

void UpdatePlayerSpritePosition() {  // 00dc2d
  uint8 tmp8a = player_yspeed;
  if (player_wall_walk_status) {
    uint8 v0 = player_xspeed;
    player_yspeed = (player_wall_walk_status & 1) ? -v0 : v0;
  }
  uint16 tx = player_sub_xpos + (uint8)(player_xspeed * 16);
  player_sub_xpos = tx;
  player_xpos += ((int8)player_xspeed >> 4) + (tx >> 8);

  uint16 ty = player_sub_ypos + (uint8)(player_yspeed * 16);
  player_sub_ypos = ty;
  player_ypos += ((int8)player_yspeed >> 4) + (ty >> 8);
  player_yspeed = tmp8a;
}

void PlayerDraw() {  // 00e2bd
  int8 v4;
  if (player_hide_player_tile_flags != 0xFF)
    PlayerGFXRt_01EA70();
  if (timer_player_palette_cycle)
    goto LABEL_14;
  uint8 star = timer_star_power;
  if (timer_star_power) {
    if (player_hide_player_tile_flags != 0xFF && (counter_local_frames & 3) == 0)
      --timer_star_power;
    if (star >= 0x1E) {
      if (star != 30) {
        v4 = (counter_global_frames & 3) + 4;
        goto LABEL_18;
      } else {
        if (misc_music_register_backup != 0xFF) {
          misc_music_register_backup &= ~0x80;
          uint8 t = misc_music_register_backup;
          if (spr45_directional_coins_despawn_timer | timer_silver_pswitch | timer_blue_pswitch)
            t = 14;
          io_music_ch1 = t;
        }
      }
    }
LABEL_14:
    v4 = (counter_global_frames >> 2 & 3) + 4;
  } else {
    v4 = player_current_character | (2 * player_current_power_up);
  }
LABEL_18:
  pointer_player_palette = kPlayerGFXRt_PalettePointers[v4];
  uint8 v5 = player_current_pose;
  int8 v6 = player_wall_walk_status <= 5;
  if (player_wall_walk_status > 5) {
    int8 v7 = player_wall_walk_status;
    if (!player_current_power_up || player_current_pose == 19)
      v7 = player_wall_walk_status ^ 1;
    v6 = v7 & 1;
  }
  player_on_screen_pos_x = player_xpos - (!v6 + mirror_current_layer1_xpos);
  int16 v8 = player_ypos + player_relative_yposition_during_screen_shake;
  uint8 v9 = 1;
  if (player_current_power_up < 1) {
    --v8;
    v9 = 0;
  }
  bool v10 = v5 >= 0xA;
  if (v5 < 0xA)
    v10 = v9 >= player_walking_frame;
  uint16 v11 = v8 - (!v10 + mirror_current_layer1_ypos);
  if (v5 == 28)
    v11 += 2;
  player_on_screen_pos_y = v11;
  if (!timer_player_hurt ||
      player_freeze_player_flag | (uint8)(flag_sprites_locked | timer_player_hurt & kPlayerGFXRt_DATA_00E292[timer_player_hurt >> 3])) {
    uint8 v12 = -56;
    if (v5 == 67)
      v12 = -24;
    uint8 r4 = v12;
    if (v5 == 41 && !player_current_power_up)
      v5 = 32;
    uint8 r5 = kPlayerGFXRt_PlayerXYDispIndex[player_facing_direction | kPlayerGFXRt_PlayerXYDispIndexIndex[v5]];
    uint8 v13 = player_current_pose;
    if (player_current_pose < 0x3D)
      v13 = kPlayerGFXRt_PowerupTilesetIndex[player_current_power_up] + player_current_pose;
    uint8 r6 = kPlayerGFXRt_TilesIndex[v13];
    uint8 r10 = kPlayerGFXRt_HeadTilePointerIndex[v13];
    uint8 r11 = kPlayerGFXRt_BodyTilePointerIndex[v13];
    uint8 v14 = sprites_tile_priority;
    if (player_current_layer_priority)
      v14 = kPlayerGFXRt_TilePriority[player_current_layer_priority - 1];
    uint8 v15 = kPlayerGFXRt_PlayerStartingOAMIndex[player_current_layer_priority];
    int8 v16 = kPlayerGFXRt_TileXFlip[player_facing_direction] | v14;
    OamEnt *oam = get_OamEnt(oam_buf, v15);
    oam[64].flags = v16;
    oam[65].flags = v16;
    oam[67].flags = v16;
    oam[68].flags = v16;
    oam[62].flags = v16;
    oam[63].flags = v16;
    if (r4 == 0xE8)
      v16 ^= 0x40;
    oam[66].flags = v16;
    uint8 v18 = PlayerGFXRt_00E45D(v15, r4 & 0x80, r5 + 0, r6 + 0);
    uint8 v19 = PlayerGFXRt_00E45D(v18, r4 & 0x40, r5 + 2, r6 + 1);
    uint8 v20 = PlayerGFXRt_00E45D(v19, r4 & 0x20, r5 + 4, r6 + 2);
    uint8 v21 = PlayerGFXRt_00E45D(v20, r4 & 0x10, r5 + 6, r6 + 3);
    
    uint8 r12 = 0, r13 = 0;
    if (player_current_power_up == 2) {
      uint8 j = v21;
      uint8 v22 = kPlayerGFXRt_DATA_00E18E[player_current_pose];
      r13 = kPlayerGFXRt_DATA_00E1D4[v22 + 3];
      uint8 r14 = kPlayerGFXRt_DATA_00E1D4[v22 + 4];
      r12 = kPlayerGFXRt_DATA_00E1D4[v22 + 1];
      uint8 v24;
      if (r12 >= 4) {
        v24 = kPlayerGFXRt_DATA_00E1D4[v22 + 2];
      } else {
        uint8 v23 = r12 | (4 * player_cape_image);
        r12 = kPlayerGFXRt_CapeTilePointerIndex[v23];
        v24 = kPlayerGFXRt_DATA_00E266[v23];
      }
      r5 = kPlayerGFXRt_CapeXYDispIndex[player_facing_direction | v24];
      player_hide_player_tile_flags |= kPlayerGFXRt_DATA_00E1D4[v22];
      uint8 r6 = 44;
      if (!(kPlayerGFXRt_DATA_00E1D4[v22] & 0x80))
        PlayerGFXRt_00E45D(j, r4 & 0x08, r5, r6++), r5 += 2, r4 <<= 1;
      uint8 v25 = PlayerGFXRt_00E45D(kPlayerGFXRt_CapeStartingOAMIndex[player_current_layer_priority], r4 & 0x08, r5, r6++);
      PlayerGFXRt_00E45D(v25, r4 & 0x04, r5 + 2, r14);
    }
    PlayerGFXRt_00F636(r10, r11, r12, r13);
  }
}

uint8 PlayerGFXRt_00E45D(uint8 j, uint8 r4, uint8 r5, uint8 r6) {  // 00e45d
  bool xflag = true;

  bool v1 = player_hide_player_tile_flags & 1;
  player_hide_player_tile_flags >>= 1;
  if (!v1) {
    int8 v2 = kPlayerGFXRt_Tiles[r6];
    if (v2 >= 0) {
      OamEnt *oam = get_OamEnt(oam_buf, j);
      oam[64].charnum = v2;
      int v4 = r5 >> 1;
      uint16 v5 = kPlayerGFXRt_YDisp[v4] + player_on_screen_pos_y;
      if ((uint16)(v5 + 0x10) < 0x100) {
        oam[64].ypos = v5;
        uint16 v6 = kPlayerGFXRt_XDisp[v4] + player_on_screen_pos_x;
        if ((uint16)(v5 + 0x80) < 0x200) {
          oam[64].xpos = v6;
          xflag = (v6 >> 8) & 1;
        }
      }
    } else {
      xflag = false;
    }
  }
  sprites_oamtile_size_buffer[(j >> 2) + 64] = (2 * (r4 != 0) + xflag) & 3;
  return j + 4;
}

void HandlePlayerLevelCollision() {  // 00e92b
  ResetPlayerLevelCollisionRAM();
  if (player_disable_object_interaction_flag) {
    RunPlayerBlockCode_00EE1D();
    HandlePlayerLevelColl_00E98C();
  } else {
    temp8d = player_on_ground_flag;
    player_on_ground_flag = 0;
    temp8f = player_in_air_flag;
    if ((misc_level_layout_flags & 0x80) != 0) {
      temp8e = misc_level_layout_flags & 0x82;
      LOBYTE(misc_current_layer_being_processed) = 1;
      player_xpos += misc_second_level_layer_xpos;
      player_ypos += misc_second_level_layer_ypos;
      RunPlayerBlockCode();
      player_xpos -= misc_second_level_layer_xpos;
      player_ypos -= misc_second_level_layer_ypos;
    }
    player_on_ground_flag *= 2;
    temp8e = misc_level_layout_flags & 0x41;
    if ((misc_level_layout_flags & 0x40) == 0) {
      LOBYTE(misc_current_layer_being_processed) = 0;
      temp8d *= 2;
      RunPlayerBlockCode();
    }
    HandlePlayerLevelColl_00E98C();
  }
}

void HandlePlayerLevelColl_00E98C() {  // 00e98c
  if (flag_side_exits) {
    if (player_on_screen_pos_x < 0xFA) {
LABEL_3:
      HandlePlayerLevelColl_00E9FB();
      return;
    }
    DisplayMessage_ExitToOverworldNoEvent();
  } else if ((uint8)player_on_screen_pos_x < 0xF0) {
    if ((player_blocked_flags & 3) != 0)
      goto LABEL_3;
    if ((int16)(misc_layer1_pos[0].x + 232 - player_xpos) > 0)
      HandlePlayerLevelColl_00E9C8(1, (int16)(player_xpos - 8 - misc_layer1_pos[0].x) < 0);
    else
      HandlePlayerLevelColl_00E9C8(0, (int16)(misc_layer1_pos[0].x + 232 - player_xpos) < 0);
  } else {
    HandlePlayerLevelColl_00EA08();
  }
}

void HandlePlayerLevelColl_00E9C8(uint8 j, uint8 sign) {  // 00e9c8
  if (sign) {
    if (!flag_layer1_horiz_scroll_level_setting) {
      player_blocked_flags |= 0x80;
      uint8 r0 = get_PointU16(l1_l2_scroll_spr_speed, 0)->x >> 4;
      if (((kHandlePlayerLevelColl_DATA_00E90D[j + 1] ^ (r0 - player_xspeed)) & 0x80) == 0) {
        player_xspeed = r0;
        player_sub_xpos = get_PointU16(l1_l2_scroll_spr_sub_pos, 0)->x;
      }
    }
    player_blocked_flags |= kHandlePlayerLevelColl_DATA_00E90A[j];
  }
  HandlePlayerLevelColl_00E9FB();
}

void HandlePlayerLevelColl_00E9FB() {  // 00e9fb
  if ((player_blocked_flags & 0x1C) != 28 || misc_player_on_solid_sprite)
    HandlePlayerLevelColl_00EA0D();
  else
    HandlePlayerLevelColl_00EA08();
}

void HandlePlayerLevelColl_00EA08() {  // 00ea08
  DamagePlayer_KillAndDisableButtons();
  player_xspeed = 0;
  HandlePlayerLevelColl_00EA34();
}

void HandlePlayerLevelColl_00EA0D() {  // 00ea0d
  if ((player_blocked_flags & 3) != 0 &&
      (player_xpos += *(uint16 *)&kHandlePlayerLevelColl_DATA_00E90D[player_blocked_flags & 2], (player_blocked_flags & 0x80) == 0) &&
      (player_anim_speed_index = 3,
       ((kHandlePlayerLevelColl_DATA_00E90D[player_blocked_flags & 2] ^ player_xspeed) & 0x80) != 0)) {
    player_xspeed = 0;
  }
  HandlePlayerLevelColl_00EA34();
}

void HandlePlayerLevelColl_00EA34() {  // 00ea34
  if (player_current_layer_priority == 1 && !player_collision_var8b)
    player_current_layer_priority = 0;
  player_can_jump_out_of_water = 0;
  if (flag_underwater_level) {
    player_swimming_flag = 1;
    SpawnPlayerBreathBubble();
    return;
  }
  int8 v0 = player_collision_var8a & 1;
  player_collision_var8a >>= 1;
  if (!v0) {
    player_swimming_flag = 0;
    return;
  }
  if (!player_swimming_flag && (player_yspeed & 0x80) == 0) {
    v0 = player_collision_var8a & 1;
    player_collision_var8a >>= 1;
    if (!v0)
      return;
    SpawnPlayerWaterSplashAndBubbles();
    player_yspeed = 0;
    player_swimming_flag = 1;
    SpawnPlayerBreathBubble();
    return;
  }
  v0 = player_collision_var8a & 1;
  player_collision_var8a >>= 1;
  if (v0) {
    player_swimming_flag = 1;
    SpawnPlayerBreathBubble();
    return;
  }
  if (!player_swimming_flag)
    return;
  if (!sign8(-4 - player_yspeed))
    player_yspeed = -4;
  ++player_can_jump_out_of_water;
  if ((io_controller_hold1 & 0x88) != 0x88) {
    SpawnPlayerBreathBubble();
    return;
  }
  if ((io_controller_hold2 & 0x80) != 0 && !player_carrying_something_flag2) {
    player_spin_jump_flag = player_carrying_something_flag2 + 1;
    io_sound_ch3 = 4;
  }
  if ((player_blocked_flags & 8) != 0) {
    SpawnPlayerBreathBubble();
    return;
  }
  SpawnPlayerWaterSplashAndBubbles();
  player_in_air_flag = 11;
  player_yspeed = -86;
  player_swimming_flag = 0;
}

void ResetPlayerLevelCollisionRAM() {  // 00eaa6
  player_anim_speed_index = 0;
  player_blocked_flags = 0;
  player_slope_player_is_on1 = 0;
  player_slope_player_is_on2 = 0;
  player_collision_var8a = 0;
  player_collision_var8b = 0;
  sprites_layer2_is_touched_flag = 0;
}

void RunPlayerBlockCode() {  // 00eadb
  player_ypos_in_block = player_ypos & 0xF;
  if (!player_wall_walk_status) {
    RunPlayerBlockCode_EB77();
    return;
  }
  uint8 v0 = player_wall_walk_status & 1;
  if (((kRunPlayerBlockCode_DATA_00EAB9[v0] ^ (player_xspeed - kRunPlayerBlockCode_DATA_00EAB9[v0])) & 0x80) != 0 ||
      player_riding_yoshi_flag | (uint8)(player_ducking_flag | player_carrying_something_flag2 | player_in_air_flag)) {
    RunPlayerBlockCode_00EB48(v0);
    return;
  }
  if (player_wall_walk_status < 6) {
    if (player_ypos_in_block < 8)
      return;
    if (player_wall_walk_status >= 4) {
      RunPlayerBlockCode_00EB73();
      return;
    }
    player_wall_walk_status |= 4;
    goto LABEL_11;
  }
  uint8 v1 = 96;
  if (v0)
    v1 = 102;
  v1 += 2;
  if (RunPlayerBlockCode_00EFE8_ReturnsTwice(v1))
    return;
  v1 += 2;
  if (player_current_power_up && RunPlayerBlockCode_00EFE8_ReturnsTwice(v1))
    return;
  if ((uint8)GetPlayerLevelCollisionMap16ID_WallRun(v1 += 2).first) {
LABEL_11:
    LOBYTE(player_xpos) = player_xpos & 0xF0 | 8;
    return;
  }
  player_wall_walk_status &= ~2;
}

void RunPlayerBlockCode_00EB48(uint8 j) {  // 00eb48
  player_xspeed = kRunPlayerBlockCode_DATA_00EABB[j];
  player_xpos += kRunPlayerBlockCode_DATA_00EABD[j];
  player_ypos += (player_current_power_up) ? 16 : 8;
  player_in_air_flag = 36;
  player_yspeed = -32;
  RunPlayerBlockCode_00EB73();
}

void RunPlayerBlockCode_00EB73() {  // 00eb73
  player_wall_walk_status = 0;
}

static const uint8 kSlopeSteepness_e55e[106] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 14, 15, 16, 17, 3, 3, 4, 4, 9, 9, 10, 10, 12, 12, 13, 13, 18, 19, 20, 21, 22, 23, 28, 29, 30, 31, 24, 25, 26, 27, 8, 9, 10, 11, 12, 13,  };
static const uint8 kSlopeSteepness_e5c8[106] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 14, 15, 16, 17, 3, 3, 4, 4, 9, 9, 10, 10, 12, 12, 13, 13, 12, 13, 13, 12, 22, 23, 28, 29, 30, 31, 24, 25, 26, 27, 8, 9, 10, 11, 12, 13,  };

const uint8 *GetSlopeSteepness() {
  switch (ptr_slope_steepness.addr) {
  case 0xe55e: return kSlopeSteepness_e55e;
  case 0xe5c8: return kSlopeSteepness_e5c8;
  }
  return Unreachable(), NULL;
}

void RunPlayerBlockCode_EB77() {  // 00eb77
  unsigned int v3;
  unsigned int v10;
  uint16 v13;
  int8 v14;
  uint8 v4;

  uint8 v0 = 0;
  if (player_current_power_up && !player_ducking_flag)
    v0 = 24;
  if (player_riding_yoshi_flag)
    v0 += 48;
  player_xpos_in_block = ((player_xpos & 0xF) + 8) & 0xF;
  player_hdir_block_touched = 0;
  if ((player_xpos & 0xF) >= 8) {
    v0 += 12;
    ++player_hdir_block_touched;
  }
  player_vdir_push_out_of_block = (*((uint8 *)kGetPlayerLevelCollisionMap16ID_DATA_00E89C + v0 + 6) + player_ypos_in_block) & 0xF;
  PairU16 wr = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
  int8 v2 = wr.first;
  v3 = wr.second;
  if (!v2) {
    if ((uint8)v3 == 0x9C && misc_level_tileset_setting == 1) {
LABEL_26:
      if (!temp8f && (io_controller_press1 & 8) != 0) {
        io_sound_ch3 = 15;
        IncrementSublevelsEnteredAndPrepareToLoadSublevel();
        player_current_state = 13;
        DamagePlayer_DisableButtons();
      }
      goto LABEL_30;
    }
    if ((uint8)v3 != 32) {
      if ((uint8)v3 != 31) {
        if (!timer_blue_pswitch)
          goto LABEL_29;
        if ((uint8)v3 == 40)
          goto LABEL_25;
        if ((uint8)v3 != 39) {
LABEL_29:
          RunPlayerBlockCode_00F28C(v3);
          goto LABEL_30;
        }
      }
      if (player_current_power_up)
        goto LABEL_30;
    }
LABEL_25:
    if (RunPlayerBlockCode_00F443() & 1)
      goto LABEL_30;
    goto LABEL_26;
  }
  if ((uint8)v3 >= 0x11) {
    if ((uint8)v3 < 0x6E) {
      v0 += 4;
      v4 = 0;
      if ((uint8)v3 != 30 && (uint8)v3 != 82)
        v4 = 2;
      goto LABEL_42;
    }
    if (CheckWaterSlope(v3) & 1)
      player_collision_var8a |= 1;
  }
LABEL_30:;
  PairU16 v5 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
  uint8 second = v5.second;
  if (!LOBYTE(v5.first)) {
    RunPlayerBlockCode_00F2C9(v5.second, 0x10);
    goto LABEL_35;
  }
  if (LOBYTE(v5.second) < 0x11 || LOBYTE(v5.second) >= 0x6E) {
LABEL_35:;
    PairU16 v7 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
    second = v7.second;
    if (!LOBYTE(v7.first)) {
      RunPlayerBlockCode_00F2C9(v7.second, 8);
      goto LABEL_45;
    }
    if (LOBYTE(v7.second) < 0x11 || LOBYTE(v7.second) >= 0x6E)
      goto LABEL_45;
    goto LABEL_39;
  }
  v0 += 2;
LABEL_39:
  if (player_facing_direction != player_hdir_block_touched) {
    RunPlayerBlockCode_CheckIfEnteringHorizontalPipe(v0, second, player_facing_direction);
    RunPlayerBlockCode_CheckIfGrabbingThrowBlock(second);
  }
  player_anim_speed_index = 3;
  v4 = player_hdir_block_touched;
  if ((player_xpos & 0xF) != kHandlePlayerLevelColl_DATA_00E911[player_hdir_block_touched]) {
LABEL_42:
    if (!blocks_note_block_bounce_flag || blocks_currently_processed_map16_tile_lo != 82) {
      uint8 t = kHandlePlayerLevelColl_DATA_00E90A[v4];
      player_blocked_flags |= t;
      RunPlayerBlockCode_CheckIfPlayerTouchingHurtBlock(blocks_currently_processed_map16_tile_lo, t & 3, true);
    }
  }
LABEL_45:;
  PairU16 v8 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
  int8 v9 = v8.first;
  v10 = v8.second;
  int8 v11 = v10;
  if (!v9) {
    RunPlayerBlockCode_00F2C2(v10, 2);
    if ((player_yspeed & 0x80) == 0 || blocks_currently_processed_map16_tile_lo < 0x21 ||
        blocks_currently_processed_map16_tile_lo >= 0x25) {
      goto LABEL_73;
    }
    CheckIfBlockWasHit_Entry3(blocks_currently_processed_map16_tile_lo - 4, 0);
    goto LABEL_61;
  }
  if ((uint8)v10 < 0x11)
    goto LABEL_73;
  if ((uint8)v10 >= 0x6E) {
    if ((uint8)v10 >= 0xD8) {
      blocks_ypos += 16;
      PairU16 pair = GetPlayerLevelCollisionMap16ID_Entry2(v0);
      v11 = pair.second;
      if (!LOBYTE(pair.first) || LOBYTE(pair.second) < 0x6E ||
          LOBYTE(pair.second) >= 0xD8) {
        goto LABEL_73;
      }
      player_vdir_push_out_of_block -= (LOBYTE(pair.second) < 0xD8) + 15;
    }
    const uint8 *slope_steepness = GetSlopeSteepness();
    v13 = 16 * slope_steepness[(uint8)(v11 - 110)];
    LOBYTE(v13) = player_xpos_in_block | v13;
    v14 = kSlopeDataTables_ShapeOfSlope[v13];
    if (v14 >= 0)
      goto LABEL_73;
    goto LABEL_62;
  }
  v10 = RunPlayerBlockCode_00F3E9(2, v10);
  RunPlayerBlockCode_CheckIfPlayerTouchingHurtBlock(v10, 0, true);
  if (blocks_currently_processed_map16_tile_lo != 30) {
LABEL_61:
    v14 = -16;
LABEL_62:;
    int8 v15 = player_vdir_push_out_of_block + v14;
    if (v15 >= 0)
      goto LABEL_73;
    if ((uint8)v15 >= 0xF9 || player_in_air_flag) {
      if (player_in_air_flag) {
        player_ypos += (uint8)~v15;
      }
      player_blocked_flags |= 8;
    } else {
      player_blocked_flags = player_blocked_flags & 0xF4 | 9;
      player_xspeed = 0;
    }
  }
  if ((player_yspeed & 0x80) != 0) {
    player_yspeed = 0;
    if (!io_sound_ch1)
      io_sound_ch1 = 1;
  }
LABEL_73:;
  PairU16 v18 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
  uint8 v19 = v18.second;
  if (!LOBYTE(v18.first)) {
    if (LOBYTE(v18.second) == 5)
      DamagePlayer_KillAndDisableButtons();
    else
      RunPlayerBlockCode_00F2C2(v18.second, 4);
    goto LABEL_95;
  }
  if (LOBYTE(v18.second) < 0x6E) {
    RunPlayerBlockCode_00F3E9(3, v18.second);
    goto LABEL_99;
  }
  if (LOBYTE(v18.second) >= 0xD8) {
    if (LOBYTE(v18.second) >= 0xFB) {
      DamagePlayer_KillAndDisableButtons();
      return;
    }
    blocks_ypos -= 16;
    PairU16 v20 = GetPlayerLevelCollisionMap16ID_Entry2(v0);
    v19 = v20.second;
    if (!LOBYTE(v20.first) || LOBYTE(v20.second) < 0x6E || LOBYTE(v20.second) >= 0xD8) {
LABEL_95:;
      PairU16 v23 = GetPlayerLevelCollisionMap16ID_WallRun(v0 += 2);
      if (!LOBYTE(v23.first)) {
        RunPlayerBlockCode_00F309(v23.second);
        RunPlayerBlockCode_00EE1D();
        return;
      }
      if (LOBYTE(v23.second) >= 0x6E) {
LABEL_106:
        RunPlayerBlockCode_00EE1D();
        return;
      }
LABEL_99:
      if ((player_yspeed & 0x80) != 0)
        return;
      if (misc_level_tileset_setting != 3 && misc_level_tileset_setting != 14 || blocks_currently_processed_map16_tile_lo < 0x59 ||
          blocks_currently_processed_map16_tile_lo >= 0x5C) {
        uint8 v24 = player_ypos_in_block & 0xF;
        player_ypos_in_block = 0;
        player_vdir_push_out_of_block = v24;
        if (v24 < 8) {
          RunPlayerBlockCode_00EE3A();
          return;
        }
      }
      goto LABEL_106;
    }
    player_ypos_in_block += (LOBYTE(v20.second) >= 0xD8) + 16;
  }
  if ((misc_level_tileset_setting == 3 || misc_level_tileset_setting == 14) && v19 >= 0xD2)
    goto LABEL_95;
  const uint8 *slope_steepness = GetSlopeSteepness();
  uint8 k = slope_steepness[(uint8)(v19 - 110)];
  uint8 v22 = player_ypos_in_block - kSlopeDataTables_ShapeOfSlope[player_xpos_in_block | 16 * k];
  if ((v22 & 0x80) != 0)
    ++player_on_ground_flag;
  if (v22 >= kSlopeDataTables_Player_SnapToSlopeDistance[k])
    goto LABEL_95;
  player_vdir_push_out_of_block = v22;
  player_ypos_in_block = 0;
  if (RunPlayerBlockCode_00F005_ReturnsTwice(k))
    return;
  if (k < 0x1C) {
    RunPlayerBlockCode_00EFBC();
    RunPlayerBlockCode_00EE85(k);
  } else {
    timer_player_slides_when_turing = 8;
    RunPlayerBlockCode_00EED1(k);
  }
}

void RunPlayerBlockCode_00EE1D() {  // 00ee1d
  if (misc_player_on_solid_sprite && (player_yspeed & 0x80) == 0) {
    temp8e = 0;
    RunPlayerBlockCode_00EEE1(0x20);
  } else if (!(player_in_air_flag | player_blocked_flags & 4)) {
    player_in_air_flag = 36;
  }
}

void RunPlayerBlockCode_00EE3A() {  // 00ee3a
  if ((misc_level_tileset_setting == 2 || misc_level_tileset_setting == 8) && (uint8)(blocks_currently_processed_map16_tile_lo - 12) < 2) {
    RunPlayerBlockCode_00EFCD(2 * (blocks_currently_processed_map16_tile_lo - 12));
  } else {
    RunPlayerBlockCode_CheckIfGrabbingThrowBlock(blocks_currently_processed_map16_tile_lo);
    if (blocks_currently_processed_map16_tile_lo == 30) {
      if (temp8f && player_current_power_up && player_spin_jump_flag) {
        CheckIfBlockWasHit_Entry3(0x21, 3);
        RunPlayerBlockCode_00EE1D();
        return;
      }
    } else {
      if (blocks_currently_processed_map16_tile_lo == 50)
        flag_active_create_eat_block = 0;
      RunPlayerBlockCode_CheckIfPlayerTouchingHurtBlock(blocks_currently_processed_map16_tile_lo, 3, false);
    }
  }
  RunPlayerBlockCode_00EE85(0x20);
}

void RunPlayerBlockCode_00EE85(uint8 j) {  // 00ee85
  if ((player_yspeed & 0x80) == 0 || temp8d >= 2) {
    if (!misc_color_of_palace_switch_pressed2) {
LABEL_10:
      RunPlayerBlockCode_00EED1(j);
      return;
    }
    if (((misc_color_of_palace_switch_pressed2 - 1) & 3) != 0) {
      if (((misc_color_of_palace_switch_pressed2 - 1) & 3) >= 2)
        goto LABEL_10;
      blocks_xpos -= 16;
    }
    uint8 v1 = (uint8)(misc_color_of_palace_switch_pressed2 - 1) >> 2;
    if (!flag_activated_switches[v1]) {
      flag_activated_switches[v1] = 1;
      misc_color_of_palace_switch_pressed1 = 1;
      sprites_color_of_flat_palace_switch_to_spawn = v1;
      RunPlayerBlockCode_SpawnFlatPalaceSwitch();
      io_music_ch1 = 12;
      misc_music_register_backup = -1;
      timer_end_level = 8;
    }
    goto LABEL_10;
  }
}

void RunPlayerBlockCode_00EED1(uint8 j) {  // 00eed1
  ++player_on_ground_flag;
  player_ypos -= player_vdir_push_out_of_block;
  RunPlayerBlockCode_00EEE1(j);
}

void RunPlayerBlockCode_00EEE1(uint8 j) {  // 00eee1
  int8 v5;

  if (kSlopeDataTables_SlopeType[j])
    goto LABEL_4;
  if (player_sliding_on_ground) {
    uint8 v1 = player_xspeed;
    if (!player_xspeed) {
LABEL_7:
      player_sliding_on_ground = v1;
      goto LABEL_8;
    }
LABEL_4:
    player_slope_player_is_on2 = kSlopeDataTables_SlopeType[j];
    if ((io_controller_hold1 & 4) == 0 || player_sliding_on_ground | player_carrying_something_flag2)
      goto LABEL_8;
    v1 = 28;
    goto LABEL_7;
  }
LABEL_8:;
  uint8 v2 = kSlopeDataTables_Player[j];
  player_slope_player_is_on1 = v2;
  if (j >= 0x1C)
    goto LABEL_18;
  if (player_xspeed) {
    uint8 v3 = kSlopeDataTables_SlopeType[j];
    if (v3) {
      if (((player_xspeed ^ v3) & 0x80) != 0) {
        player_anim_speed_index = v2;
        uint8 v4 = player_xspeed;
        if ((player_xspeed & 0x80) != 0)
          v4 = -player_xspeed;
        if (v4 >= 0x28) {
          v5 = kSlopeDataTables_Player_TowardsPeakYSpeed[j];
          goto LABEL_23;
        }
        j = 32;
      }
    }
  }
  v5 = player_yspeed;
  if (player_yspeed >= kSlopeDataTables_Player_StationaryYSpeed[j])
LABEL_18:
    v5 = kSlopeDataTables_Player_StationaryYSpeed[j];
  if ((temp8e & 0x80) != 0) {
    ++sprites_layer2_is_touched_flag;
    player_xpos -= (int8)misc_layer2_xdisp;
    v5 += 40;
  }
LABEL_23:
  player_yspeed = v5;
  if (v5 < 0)
    ++player_on_ground_flag;
  flag_standing_on_beta_cage = 0;
  player_in_air_flag = 0;
  player_climbing_flag = 0;
  camera_bounce_off_spring_flag = 0;
  player_spin_jump_flag = 0;
  player_blocked_flags |= 4;
  uint8 v9 = player_cape_flying_phase;
  if (player_cape_flying_phase) {
    counter_consecutive_enemies_stomped = 0;
    player_cape_flying_phase = 0;
    if (v9 >= 5) {
      if (temp8f) {
        RunPlayerBlockCode_TriggerCapeDiveGroundPound();
        io_sound_ch3 = 9;
      }
    } else if (player_current_power_up == 2) {
      player_sliding_on_ground = (player_sliding_on_ground >> 1) + 0x80;
    }
  } else {
    if (player_riding_yoshi_flag && temp8f) {
      if (yoshi_stomp_ground_flag) {
        YoshiStompRoutine();
        io_sound_ch3 = 37;
      }
    }
    counter_consecutive_enemies_stomped = 0;
  }
}

void RunPlayerBlockCode_00EFBC() {  // 00efbc
  if (blocks_currently_processed_map16_tile_lo >= 0xCE && blocks_currently_processed_map16_tile_lo < 0xD2)
    RunPlayerBlockCode_00EFCD(2 * (blocks_currently_processed_map16_tile_lo + 52));
}

void RunPlayerBlockCode_00EFCD(uint8 k) {  // 00efcd
  if ((counter_global_frames & 3) == 0) {
    int v1 = k >> 1;
    player_xpos += kHandlePlayerLevelColl_DATA_00E913[v1];
    player_ypos += kHandlePlayerLevelColl_DATA_00E91F[v1];
  }
}

bool RunPlayerBlockCode_00EFE8_ReturnsTwice(uint8 k) {  // 00efe8
  unsigned int v3;
  bool ret = false;

  PairU16 pair = GetPlayerLevelCollisionMap16ID_WallRun(k);
  int8 v2 = pair.first;
  v3 = HIWORD(pair.second);
  if (v2) {
    if ((uint8)v3 >= 0x11 && (uint8)v3 < 0x6E) {
      CheckIfBlockWasHit(v3, 0);
      ret = true;
      RunPlayerBlockCode_00EB48(player_wall_walk_status & 1);
    }
  } else {
    RunPlayerBlockCode_00F309(v3);
  }
  return ret;
}

bool RunPlayerBlockCode_00F005_ReturnsTwice(uint8 j) {  // 00f005
  if ((uint8)(j - 14) < 2 && ((uint8)(j - 14) ^ 1) == player_facing_direction) {
    uint8 v1 = (j - 14) ^ 1;
    uint8 v2 = player_xpos_in_block;
    if (v1 & 1)
      v2 ^= 0xF;
    if (v2 < 8) {
      if (player_riding_yoshi_flag) {
        io_sound_ch3 = 8;
        player_yspeed = 0x80;
        camera_bounce_off_spring_flag = 0x80;
        player_in_air_flag = 36;
        return true;
      } else if (((kRunPlayerBlockCode_DATA_00EAB9[v1] ^ (player_xspeed - kRunPlayerBlockCode_DATA_00EAB9[v1])) & 0x80) == 0 &&
                 !(player_ducking_flag | player_carrying_something_flag2)) {
        player_wall_walk_status = v1 + 2;
      }
    }
  }
  return false;
}

uint8 CheckWaterSlope(uint8 a) {  // 00f04d
  uint8 v1 = 25;
  while (1) {
    if (a == kRunPlayerBlockCode_WaterSlopeMap16Numbers[v1])
      return 1;
    if ((--v1 & 0x80) != 0)
      return 0;
  }
}

void RunPlayerBlockCode_CheckIfPlayerTouchingHurtBlock(uint8 a, uint8 j, bool ignore_yoshi) {  // 00f120
  if (ignore_yoshi || !player_riding_yoshi_flag) {
    if (a == 47 ||
      a >= 0x59 && a < 0x5C && (misc_level_tileset_setting == 5 || misc_level_tileset_setting == 13) ||
      (a >= 0x59 && a < 0x5d || a >= 0x66 && a < 0x6A) && misc_level_tileset_setting == 1) {
      DamagePlayer_Hurt();
      return;
    }
  }
  CheckIfBlockWasHit(a, j);
}

void CheckIfBlockWasHit(uint8 a, uint8 j) {  // 00f160
  a = a - 17;
  if (a >= 0x1D) {
    if ((kInitializeLevelRAM_DATA_00A625[misc_level_tileset_setting] & 3) == 0 && (uint8)(a - 89) < 2)
      CheckIfBlockWasHit_Entry3(a - 89 + 34, j);
  } else {
    CheckIfBlockWasHit_Entry3(a, j);
  }
}

void CheckIfBlockWasHit_Entry3(uint8 a, uint8 j) {  // 00f17f
  uint8 r4, r5;
  uint8 v3;
  int8 v5;

  if ((kCheckIfBlockWasHit_DATA_00F0A4[a] & kCheckIfBlockWasHit_DATA_00F0EC[j]) == 0)
    return;
  uint8 r6 = j;
  uint8 r7 = kCheckIfBlockWasHit_DATA_00F0C8[a];
  r4 = kCheckIfBlockWasHit_DATA_00F05C[a];
  int8 v2 = kCheckIfBlockWasHit_DATA_00F080[a];
  if (v2 >= 0)
    goto LABEL_9;
  if (v2 != -1) {
    uint8 v4 = (v2 & 1) ? 0x80 : 0;
    v2 = kCheckIfBlockWasHit_DATA_00F100[(uint8)(((uint8)blocks_xpos >> 1) + v4) >> 3];
LABEL_9:
    v5 = v2 & 1;
    v3 = (uint8)v2 >> 1;
    if (v5) {
      if (v3 != 3) {
        if (!player_current_power_up)
          v3 = 1;
        goto LABEL_15;
      }
      if (!timer_star_power)
        goto LABEL_14;
    }
    goto LABEL_15;
  }
  v3 = 5;
  if (counter_green_star_block)
LABEL_14:
    v3 = 6;
LABEL_15:
  r5 = v3;
  if (v3 == 5) {
    v3 = 22;
    r7 = 22;
  }
  blocks_xpos &= ~0xf;
  blocks_ypos &= ~0xf;
  if (v3 != 6 || misc_level_tileset_setting != 4)
    goto LABEL_19;
  uint8 v6 = (blocks_ypos >> 6) & 7;
  uint8 v7 = kCheckIfBlockWasHit_DATA_00F0EC[(uint8)blocks_xpos >> 4] | *(&timer_inflate_from_pballoon + v6);
  int8 v8 = *(&timer_inflate_from_pballoon + v6);
  *(&timer_inflate_from_pballoon + v6) = v7;
  if (v7 == 0xFF) {
    r5 = 5;
LABEL_23:
    r7 = 23;
LABEL_19:
    SpawnBounceSprite(r4, r5, r6, r7);
    goto LABEL_20;
  }
  if (!flag_prevent_coin_bonus_game_replay) {
    uint8 v9 = v8 ? 2 : 0;
    if ((counter_global_frames & (v9 ^ 3)) != 0)
      goto LABEL_23;
  }
  io_sound_ch3 = 42;
  r5 = 0;
  SpawnBounceSprite(r4, r5, r6, r7);
  int8 v10 = 7;
  uint8 v11 = *(&timer_inflate_from_pballoon + v6);
  do {
    v5 = v11 & 1;
    v11 >>= 1;
    if (!v5) {
      uint8 v12 = v11;
      blocks_map16_to_generate = 13;
      LOBYTE(blocks_xpos) = kCheckIfBlockWasHit_DATA_00F0F8[(uint8)v10];
      GenerateTile();
      v11 = v12;
    }
  } while (--v10 >= 0);
LABEL_20:;
}

void RunPlayerBlockCode_CheckIfGrabbingThrowBlock(uint8 j) {  // 00f267
  if (j == 46 && (io_controller_press1 & 0x40) != 0 && !(player_riding_yoshi_flag | player_carrying_something_flag2) &&
      (GrabThrowBlockBlock() & 0x80) == 0) {
    blocks_map16_to_generate = 2;
    GenerateTile();
  }
}

void RunPlayerBlockCode_00F28C(uint8 j) {  // 00f28c
  int8 v1 = j - 111;
  if ((uint8)(j - 111) >= 4) {
    RunPlayerBlockCode_00F2C2(j, 1);
    return;
  }
  if (v1 == counter_1up_check_points_collected)
    goto LABEL_6;
  if (v1 + 1 != counter_1up_check_points_collected && counter_1up_check_points_collected < 4) {
    v1 = -1;
LABEL_6:
    counter_1up_check_points_collected = v1 + 1;
    if (v1 == 3) {
      TriggerHidden1up();
      flag_collected1up_checkpoints[ow_level_number_lo >> 3] |= kBitTable_Bank05[ow_level_number_lo & 7];
    }
  }
}

void RunPlayerBlockCode_00F2C2(uint8 j, uint8 a) {  // 00f2c2
  if (j < 6)
    player_collision_var8a |= a;
  else
    RunPlayerBlockCode_00F2C9(j, a);
}

void RunPlayerBlockCode_00F2C9(uint8 j, uint8 a) {  // 00f2c9
  if (j == 56) {
    blocks_map16_to_generate = 2;
    GenerateTile();
    SpawnGlitterEffectForCoin();
    if (g_lunar_magic || lm_var13CD)
      PlayerState00_SetMidpointFlag();
    if (!player_current_power_up)
      player_current_power_up = 1;
    io_sound_ch1 = 5;
  } else {
    if (j != 6) {
      if (j < 7 || j >= 0x1D) {
        RunPlayerBlockCode_00F309(j);
        return;
      }
      a |= 0x80;
    }
    if (a == 1)
      a = 25;
    player_collision_var8b |= a;
    player_collision_var8c = player_hdir_block_touched;
  }
}

void RunPlayerBlockCode_00F309(uint8 j) {  // 00f309
  if (j >= 0x2F || j < 0x2A) {
    if (j != 110)
      return;
    SpawnScoreSpriteAtPlayerPosition(0xF);
    ++unusedram_3up_moons_counter;
    flag_collected_moons[ow_level_number_lo >> 3] |= kBitTable_Bank05[ow_level_number_lo & 7];
    blocks_map16_to_generate = 1;
    goto LABEL_15;
  }
  if (j != 42 || timer_blue_pswitch) {
    if (j != 45) {
      if (j < 0x2D) {
        GiveCoins_OneCoin();
        blocks_map16_to_generate = 1;
LABEL_15:
        GenerateTile();
        SpawnGlitterEffectForCoin();
        return;
      }
      LOBYTE(blocks_ypos) = blocks_ypos - 16;
    }
    RunPlayerBlockCode_00F377();
    if (++counter_yoshi_coins_to_display >= 5)
      flag_collected5_yoshi_coins[ow_level_number_lo >> 3] |= kBitTable_Bank05[ow_level_number_lo & 7];
    io_sound_ch1 = 28;
    GiveCoins_MultipleCoins_NoCoinSound(1);
    blocks_map16_to_generate = 24;
    goto LABEL_15;
  }
}

void RunPlayerBlockCode_00F377() {  // 00f377
  uint8 v1 = 9 + counter_yoshi_coins_collected++;
  SpawnScoreSpriteAtPlayerPosition(v1 < 13 ? v1 : 13);
}

void SpawnScoreSpriteAtPlayerPosition_LakituEntry() {  // 00f388
  SpawnScoreSpriteAtPlayerPosition(0xD);
}

void SpawnScoreSpriteAtPlayerPosition(uint8 a) {  // 00f38a
  uint8 v1 = CheckAvailableScoreSpriteSlot();
  score_spr_spriteid[v1] = a;
  SetHiLo(&score_spr_xpos_hi[v1], &score_spr_xpos_lo[v1], player_xpos);
  SetHiLo(&score_spr_ypos_hi[v1], &score_spr_ypos_lo[v1], player_ypos);
  score_spr_yspeed[v1] = 48;
  score_spr_layer_index[v1] = 0;
}

void RunPlayerBlockCode_CheckIfEnteringHorizontalPipe(uint8 k, uint8 j, uint8 a) {  // 00f3c4
  if (j == 63) {
    if (temp8f) {
      RunPlayerBlockCode_00F43F();
    } else {
      int8 v4 = player_xpos;
      if (a)
        v4 = -player_xpos;
      sub_F40A(a, 5, 2 * (v4 & 0xF) + 32);
    }
  }
}

uint8 RunPlayerBlockCode_00F3E9(uint8 a, uint8 j) {  // 00f3e9
  if ((uint8)(j - 55) >= 2)
    return j;
  j -= 55;
  if ((uint8)(player_xpos_in_block - (1 + kRunPlayerBlockCode_DATA_00F3E3[j])) < 5) {
    uint8 v3 = player_riding_yoshi_flag ? 48 : 32;
    return sub_F40A(a, 6, v3);
  } else {
    return blocks_currently_processed_map16_tile_lo;
  }
}

uint8 sub_F40A(uint8 k, uint8 j, uint8 a) {  // 00f40a
  player_timer_pipe_warping = a;
  int8 v3 = kRunPlayerBlockCode_PIPE_BUTTONS[k] & io_controller_hold1;
  if (v3) {
    flag_sprites_locked = kRunPlayerBlockCode_PIPE_BUTTONS[k] & io_controller_hold1;
    player_facing_direction = v3 & 1;
    player_pipe_action = k;
    int8 v4 = k >> 1;
    if (!v4 && player_carrying_something_flag2) {
      player_facing_direction ^= 1;
      timer_display_player_face_screen_pose = 8;
    }
    yoshi_in_pipe = v4 + 1;
    player_current_state = j;
    DamagePlayer_DisableButtons();
    io_sound_ch1 = 4;
  }
  return blocks_currently_processed_map16_tile_lo;
}

uint8 RunPlayerBlockCode_00F43F() {  // 00f43f
  return blocks_currently_processed_map16_tile_lo;
}

uint8 RunPlayerBlockCode_00F443() {  // 00f443
  return (((uint8)player_xpos + 4) & 0xF) >= 8;
}

PairU16 GetPlayerLevelCollisionMap16ID_WallRun(uint8 k) {  // 00f44d
  uint8 v1 = k;  // moved incr to outside
  blocks_xpos = kGetPlayerLevelCollisionMap16ID_DATA_00E832[(v1 >> 1) - 1] + player_xpos;
  blocks_ypos = kGetPlayerLevelCollisionMap16ID_DATA_00E89C[(v1 >> 1) - 1] + player_ypos;
  PairU16 p = GetPlayerLevelCollisionMap16ID_Entry2(v1);
  return p;
}

static const uint8 kLevelDataLayoutTables_EightBitLo_Horizontal[32] = { 0x0, 0xb0, 0x60, 0x10, 0xc0, 0x70, 0x20, 0xd0, 0x80, 0x30, 0xe0, 0x90, 0x40, 0xf0, 0xa0, 0x50, 
0x0, 0xb0, 0x60, 0x10, 0xc0, 0x70, 0x20, 0xd0, 0x80, 0x30, 0xe0, 0x90, 0x40, 0xf0, 0xa0, 0x50,};

static const uint8 kLevelDataLayoutTables_EightBitLo_Vertical[28] = { 
  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
  0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
};
static const uint8 kLevelDataLayoutTables_EightBitHi_Horizontal[32] = { 0xc8, 0xc9, 0xcb, 0xcd, 0xce, 0xd0, 0xd2, 0xd3, 0xd5, 0xd7, 0xd8, 0xda, 0xdc, 0xdd, 0xdf, 0xe1, 
0xe3, 0xe4, 0xe6, 0xe8, 0xe9, 0xeb, 0xed, 0xee, 0xf0, 0xf2, 0xf3, 0xf5, 0xf7, 0xf8, 0xfa, 0xfc,};

static const uint8 kLevelDataLayoutTables_EightBitHi_Vertical[28] = { 0xc8, 0xca, 0xcc, 0xce, 0xd0, 0xd2, 0xd4, 0xd6, 0xd8, 0xda, 0xdc, 0xde, 0xe0, 0xe2,
0xe4, 0xe6, 0xe8, 0xea, 0xec, 0xee, 0xf0, 0xf2, 0xf4, 0xf6, 0xf8, 0xfa, 0xfc, 0xfe,};


uint16 GetLevelLayoutPtr_Vertical(int i) {
  assert(i < 28);
  return PAIR16(kLevelDataLayoutTables_EightBitHi_Vertical[i], kLevelDataLayoutTables_EightBitLo_Vertical[i]);
}

uint16 GetLevelLayoutPtr_Horizontal(int i) {
  if (i >= 32)
    printf("WARNING: GetLevelLayoutPtr_Horizontal: Reading invalid slot %d\n", i);
  if (HAS_LM_FEATURE(kLmFeature_LoadLevel))
    return PAIR16(L1_Screen_8bit_Hi[i], L1_Screen_8bit_Lo[i]);
  else
    return PAIR16(kLevelDataLayoutTables_EightBitHi_Horizontal[i], kLevelDataLayoutTables_EightBitLo_Horizontal[i]);
}

PairU16 GetPlayerLevelCollisionMap16ID_Entry2(uint8 k) {  // 00f465
  uint16 r0w;
  uint16 level_height = g_lunar_magic ? lm_level_height : 0x1b0;

  misc_color_of_palace_switch_pressed2 = 0;
  if ((temp8e & 0x80) != 0) {
    if (temp8e & 0x7f) {
      if (HIBYTE(blocks_xpos) >= 2 || HIBYTE(blocks_ypos) >= 0xE)
        goto default_return;
      r0w = GetLevelLayoutPtr_Vertical(HIBYTE(blocks_ypos) + 14) + (blocks_ypos & 0xF0 | ((uint8)blocks_xpos >> 4) | HIBYTE(blocks_xpos) << 8);
    } else if (blocks_ypos < level_height) {
      if (HIBYTE(blocks_xpos) >= 0x10)
        goto default_return;
      r0w = GetLevelLayoutPtr_Horizontal(HIBYTE(blocks_xpos) + 16) + (blocks_ypos & 0xF0 | ((uint8)blocks_xpos >> 4) | HIBYTE(blocks_ypos) << 8);
    } else {
      goto default_return;
    }
  } else {
    if (temp8e) {
      if (HIBYTE(blocks_xpos) >= 2 || HIBYTE(blocks_ypos) >= misc_screens_in_lvl)
        goto default_return;
      r0w = GetLevelLayoutPtr_Vertical(HIBYTE(blocks_ypos)) + (blocks_ypos & 0xF0 | ((uint8)blocks_xpos >> 4) | HIBYTE(blocks_xpos) << 8);
    } else {
      if (blocks_ypos >= level_height || HIBYTE(blocks_xpos) >= misc_screens_in_lvl)
        goto default_return;
      r0w = GetLevelLayoutPtr_Horizontal(HIBYTE(blocks_xpos)) + (blocks_ypos & 0xF0 | ((uint8)blocks_xpos >> 4) | HIBYTE(blocks_ypos) << 8);
    }
  }
  blocks_currently_processed_map16_tile_lo = g_ram[r0w];
  uint8 v7 = LmHook_ModifyMap16IDForSpecialBlocks(g_ram[0x10000 + r0w]);
  return MakePairU16_AY(v7, blocks_currently_processed_map16_tile_lo);

default_return:
  if (g_lunar_magic)
    blocks_currently_processed_map16_tile_lo = 0x25;
  return MakePairU16_AY(0, 0x25);
}

uint8 ModifyMap16IDForSpecialBlocks(uint8 a) {  // 00f545
  if (!a) {
    if (blocks_currently_processed_map16_tile_lo == 41) {
      if (timer_blue_pswitch)
        return blocks_currently_processed_map16_tile_lo = 36;
    } else if (blocks_currently_processed_map16_tile_lo == 43) {
      if (timer_blue_pswitch)
        return blocks_currently_processed_map16_tile_lo = 50;
    } else if ((uint8)(blocks_currently_processed_map16_tile_lo + 20) < 0x10) {
      misc_color_of_palace_switch_pressed2 = blocks_currently_processed_map16_tile_lo + 21;
      return blocks_currently_processed_map16_tile_lo = 50;
    }
    return 0;
  }
  if (blocks_currently_processed_map16_tile_lo == 50) {
    if (!timer_blue_pswitch)
      return a;
    blocks_currently_processed_map16_tile_lo = 43;
    return 0;
  }
  if (blocks_currently_processed_map16_tile_lo == 47 && timer_silver_pswitch) {
    blocks_currently_processed_map16_tile_lo = 43;
    return 0;
  }
  return a;
}

void PlayerState00_CheckPlayerPitFall() {  // 00f595
  if (!sign16(mirror_current_layer1_ypos - 128 - player_ypos))
    player_ypos = mirror_current_layer1_ypos - 128;
  if ((int8)(HIBYTE(player_on_screen_pos_y) - 1) >= 0) {
    if (in_yoshi_wings_bonus_area)
      PlayerState00_00C95B();
    else
      DamagePlayer_PitFall();
  }
}

void DamagePlayer_Hurt() {  // 00f5b7
  if (!player_current_state && !(timer_end_level | (uint8)(timer_star_power | timer_player_hurt))) {
    counter_pink_berry_cloud_coins = 0;
    if (player_wall_walk_status)
      RunPlayerBlockCode_00EB48(player_wall_walk_status & 1);
    if (player_current_power_up) {
      if (player_current_power_up == 2 && player_cape_flying_phase) {
        io_sound_ch1 = 15;
        player_spin_jump_flag = 1;
        timer_player_hurt = 48;
        DamagePlayer_00F622();
      } else {
        io_sound_ch1 = 4;
        DropReservedItem();
        player_current_state = 1;
        player_current_power_up = 0;
        DamagePlayer_SetHurtAnimationTimer(0x2F);
      }
    } else {
      DamagePlayer_Kill();
    }
  }
}

void DamagePlayer_Kill() {  // 00f606
  player_yspeed = -112;
  DamagePlayer_PitFall();
}

void DamagePlayer_PitFall() {  // 00f60a
  io_music_ch1 = 9;
  misc_music_register_backup = -1;
  player_current_state = 9;
  player_spin_jump_flag = 0;
  DamagePlayer_SetHurtAnimationTimer(0x30);
}

void DamagePlayer_SetHurtAnimationTimer(uint8 a) {  // 00f61d
  player_anim_timer = a;
  flag_sprites_locked = a;
  DamagePlayer_00F622();
}

void DamagePlayer_00F622() {  // 00f622
  player_cape_flying_phase = 0;
  unusedram_7e188a = 0;
}

void DamagePlayer_KillAndDisableButtons() {  // 00f629
  DamagePlayer_Kill();
  DamagePlayer_DisableButtons();
}

void DamagePlayer_DisableButtons() {  // 00f62d
  io_controller_hold1 = 0;
  io_controller_press1 = 0;
  io_controller_hold2 = 0;
  io_controller_press2 = 0;
}

void PlayerGFXRt_00F636(uint8 r10, uint8 r11, uint8 r12, uint8 r13) {  // 00f636
  uint16 t = (r10 & 0xf7) << 6 | ((r10 & 0x8) ? 0x4000 : 0);
  *(uint16 *)graphics_dynamic_sprite_pointers_top_lo = t + 0x2000;
  *(uint16 *)graphics_dynamic_sprite_pointers_bottom_lo = t + 0x2200;

  t = (r11 & 0xf7) << 6 | ((r11 & 0x8) ? 0x4000 : 0);
  *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[2] = t + 0x2000;
  *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[2] = t + 0x2200;

  t = 32 * r12;
  *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[4] = t + 0x2000;
  *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[4] = t + 0x2200;

  graphics_dynamic_sprite_tile7 = 32 * r13 + 0x2000;
  player_number_of_tiles_to_update = 10;
}

void HandleStandardLevelCameraScroll() {  // 00f6db
  if (g_lunar_magic)
    LmHook_HandleStandardLevelCameraScroll();

  camera_pos_for_scroll[0] = player_relative_position_needed_to_scroll_screen - 12;
  camera_pos_for_scroll[1] = player_relative_position_needed_to_scroll_screen - 12 + 24;
  PointU16 *pt = get_PointU16(misc_layer1_pos, 0);
  mirror_current_layer1_xpos = pt->x;
  mirror_current_layer1_ypos = pt->y;
  mirror_current_layer2_xpos = pt[1].x;
  mirror_current_layer2_ypos = pt[1].y;
  if (misc_level_layout_flags & 1) {
    HandleStandardLevelCameraScroll_00F7F4((camera_last_screen_vert - 1) << 8);
    if (flag_layer1_horiz_scroll_level_setting) {
      uint8 v7 = 0;
      uint16 r0w = player_xpos - mirror_current_layer1_xpos;
      if ((int16)(r0w - player_relative_position_needed_to_scroll_screen) >= 0)
        v7 = 2;
      uint16 r2w = r0w - camera_pos_for_scroll[v7 >> 1];
      if ((r2w != 0 || !g_lunar_magic) && ((kHandleStandardLevelCameraScroll_DATA_00F6A3[v7 >> 1] ^ r2w) & 0x8000) != 0) {
        r2w = HandleStandardLevelCameraScroll_00F8AB(r2w);
        uint16 v8 = mirror_current_layer1_xpos + r2w;
        if ((int16)v8 < 0)
          v8 = 0;
        if (!sign16(v8 - 257))
          v8 = 256;
        mirror_current_layer1_xpos = v8;
      }
    }
  } else {
    HandleStandardLevelCameraScroll_00F7F4(g_lunar_magic ? LmHook_HandleStandardLevelCameraScrollD() : 0xc0);
    if (flag_layer1_horiz_scroll_level_setting) {
      uint16 r0w = player_xpos - mirror_current_layer1_xpos;
      uint8 v1 = ((int16)(r0w - player_relative_position_needed_to_scroll_screen) < 0) ? 0 : 2;
      camera_layer1_scrolling_direction = v1;
      camera_layer2_scrolling_direction = v1;
      int16 v2 = r0w - camera_pos_for_scroll[v1 >> 1];
      if (v2) {
        uint16 r2w = player_xpos - mirror_current_layer1_xpos - camera_pos_for_scroll[v1 >> 1];
        if (((kHandleStandardLevelCameraScroll_DATA_00F6A3[v1 >> 1] ^ v2) & 0x8000) != 0) {
          r2w = HandleStandardLevelCameraScroll_00F8AB(r2w);
          uint16 v3 = mirror_current_layer1_xpos + r2w;
          if ((int16)(mirror_current_layer1_xpos + r2w) < 0)
            v3 = 0;
          mirror_current_layer1_xpos = v3;
          int16 v5 = (camera_last_screen_horiz - 1) << 8;
          if (v5 < 0)
            v5 = 128;
          if (sign16(v5 - mirror_current_layer1_xpos))
            mirror_current_layer1_xpos = v5;
        }
      }
    }
  }
  if (g_lunar_magic) {
    LmHook_HandleStandardLevelCameraScrollB();
  } else {
    if (flag_layer2_horiz_scroll_level_setting) {
      uint16 v9 = mirror_current_layer1_xpos;
      if (flag_layer2_horiz_scroll_level_setting != 1)
        v9 >>= 1;
      mirror_current_layer2_xpos = v9;
    }
    if (flag_layer2_vert_scroll_level_setting) {
      uint16 v10 = mirror_current_layer1_ypos;
      if (flag_layer2_vert_scroll_level_setting != 1)
        v10 = (flag_layer2_vert_scroll_level_setting != 2) ? v10 >> 5 : v10 >> 1;
      mirror_current_layer2_ypos = camera_layer2_ypos_relative_to_layer1 + v10;
    }
  }
  misc_layer1_xdisp = mirror_current_layer1_xpos - LOBYTE(pt->x);
  misc_layer1_ydisp = mirror_current_layer1_ypos - LOBYTE(pt->y);
  misc_layer2_xdisp = mirror_current_layer2_xpos - LOBYTE(pt[1].x);
  misc_layer2_ydisp = mirror_current_layer2_ypos - LOBYTE(pt[1].y);
  if (g_lunar_magic) {
    LmHook_HandleStandardLevelCameraScrollC();
  } else {
    for (uint8 i = 7; (i & 0x80) == 0; --i)
      LOBYTE(get_PointU16(misc_layer1_pos, i)->x) = *((uint8 *)&mirror_current_layer1_xpos + i);
  }
}

void HandleStandardLevelCameraScroll_00F7F4(uint16 a) {  // 00f7f4
  uint16 v7;

  if (flag_layer1_vert_scroll_level_setting) {
    uint16 r4w = a;
    uint8 v1 = 0;
    uint16 r0w = player_ypos - mirror_current_layer1_ypos;
    if (!sign16(player_ypos - mirror_current_layer1_ypos - 112))
      v1 = 2;
    camera_layer1_scrolling_direction = v1;
    camera_layer2_scrolling_direction = v1;
    int v2 = v1 >> 1;
    uint16 r2w = player_ypos - mirror_current_layer1_ypos - kHandleStandardLevelCameraScroll_DATA_00F69F[v2];
    if (((kHandleStandardLevelCameraScroll_DATA_00F6A3[v2] ^ r2w) & 0x8000) == 0) {
      v1 = 2;
      r2w = 0;
    }
    if ((r2w & 0x8000) != 0) {
      uint8 v3 = player_wall_walk_status;
      if (player_wall_walk_status < 6)
        v3 = camera_bounce_off_spring_flag | flag_player_in_lakitus_cloud | timer_inflate_from_pballoon | player_climbing_flag |
             timer_wait_before_cape_flight_begins | (flag_display_yoshis_wings >> 1);
      uint8 v4 = v3;
      if (v3 || player_riding_yoshi_flag && (v4 = yoshi_yoshi_has_wings, yoshi_yoshi_has_wings >= 2) ||
          player_swimming_flag && (v4 = player_in_air_flag) != 0 ||
          flag_layer1_vert_scroll_level_setting != 1 && (v4 = flag_enable_vert_scroll) == 0) {
        flag_enable_vert_scroll = v4;
        if (!v4) {
          if (g_lunar_magic) {
            v7 = LmHook_HandleStandardLevelCameraScrollG(r2w, r4w);
            goto get_out;
          }
          v1 = 4;
        }
      } else if (!flag_scroll_up_to_player) {
        if (player_in_air_flag)
          return;
        ++*(uint16 *)&flag_scroll_up_to_player;
      }
    } else {
      flag_scroll_up_to_player = 0;
    }
    int v5 = v1 >> 1;
    uint16 v6 = r2w;
    uint16 t = (v6 - kHandleStandardLevelCameraScroll_DATA_00F6A7[v5]) ^ kHandleStandardLevelCameraScroll_DATA_00F6A7[v5];
    if (!sign16(t))
      v6 = kHandleStandardLevelCameraScroll_DATA_00F6A7[v5];
    v7 = mirror_current_layer1_ypos + v6;
    if ((int16)(v7 - kHandleStandardLevelCameraScroll_DATA_00F6AD[v5]) < 0)
      v7 = kHandleStandardLevelCameraScroll_DATA_00F6AD[v5];

get_out:
    mirror_current_layer1_ypos = v7;
    if (sign16(r4w - v7)) {
      mirror_current_layer1_ypos = r4w;
      *(uint16 *)&flag_enable_vert_scroll = 0;
    }
  }
}

uint16 HandleStandardLevelCameraScroll_00F8AB(uint16 r2w) {  // 00f8ab
  if (!flag_lrscroll_flag) {
    uint8 v0 = 8;
    int v1 = player_facing_directionx2 >> 1;
    if ((int16)(player_relative_position_needed_to_scroll_screen - kHandleStandardLevelCameraScroll_DATA_00F6B3[v1]) < 0)
      v0 = 10;
    int v2 = v0 >> 1;
    if (((r2w ^ kHandleStandardLevelCameraScroll_DATA_00F6BF[v2]) & 0x8000) != 0 &&
        ((r2w ^ kHandleStandardLevelCameraScroll_DATA_00F6BF[v1]) & 0x8000) != 0) {
      if ((uint16)(kHandleStandardLevelCameraScroll_DATA_00F6CB[v2 + 2] + r2w)) {
        r2w += kHandleStandardLevelCameraScroll_DATA_00F6CB[v2 + 2];
        camera_lrscroll_move_flag = v0;
      }
    }
  }
  return r2w;
}

void PlayerState00_00F8F2() {  // 00f8f2
  ResetPlayerLevelCollisionRAM();
  if ((misc_nmito_use_flag & 0x40) != 0) {
    HandlePlayerLevelCollision();
    uint8 v0 = misc_currently_active_boss;
    if ((player_yspeed & 0x80) != 0 && (int16)(player_ypos - kPlayerState00_DATA_00F8E8[v0]) < 0) {
      player_ypos = kPlayerState00_DATA_00F8E8[v0];
      player_yspeed = 0;
      io_sound_ch1 = 1;
    }
    if (kPlayerState00_DATA_00F8E8[misc_currently_active_boss] == 42) {
      uint8 v1 = 0;
      int16 t = spr_table160e[9] + 1 - player_xpos;
      if (t > 0) {
        t = player_xpos + 15 - spr_table1534[9];
        v1 = 1;
      }
      HandlePlayerLevelColl_00E9C8(v1, t < 0);
    }
  } else {
    if (!(player_yspeed & 0x80)) {
      CheckPlatformCollRet cpcr = CheckTiltingPlatformCollision(player_xpos + 8, player_ypos + 32);
      if (cpcr.retval) {
        if (player_in_air_flag) {
          player_on_tilting_platform_xpos = cpcr.pt.x & 0xff;
          player_on_tilting_platform_ypos = cpcr.pt.y & 0xf0;
          PlayerState00_00F9C9(player_on_tilting_platform_xpos, player_on_tilting_platform_ypos, cpcr.pt);
        }
        uint8 v2 = kPlayerState00_DATA_00F8DF[(uint8)(misc_m7_rotation + 72) >> 4];
        temp8e = 0x80;
        RunPlayerBlockCode_00EEE1(v2);
      } else {
        RunPlayerBlockCode_00EE1D();
      }
    }
    if ((int16)(player_on_screen_pos_y - 174) >= 0)
      DamagePlayer_KillAndDisableButtons();
    HandlePlayerLevelColl_00E98C();
  }
}

void PlayerState00_00F9C9(uint16 temp14b4, uint16 temp14b6, PointU16 pt) {  // 00f9c9
  uint16 v0 = misc_m7_rotation;
  misc_m7_rotation = -misc_m7_rotation;
  CheckPlatformCollRet ret = CheckTiltingPlatformCollision(temp14b4, temp14b6);
  if (ret.out_of_bounds)
    ret.pt = pt;
  misc_m7_rotation = v0;
  player_xpos = (uint8)ret.pt.x - 8;
  player_ypos = (uint8)ret.pt.y - 32;
}

uint8 CheckWhatSlopeSpriteIsOn(uint8 a, uint8 r10, uint8 r12, uint8 *slope_type) {  // 00fa19
  R5_slopeptr.addr = 0xe632;
  const uint8 *slope_steepness = GetSlopeSteepness();
  uint8 r8 = slope_steepness[(uint8)(a - 110)];
  *slope_type = r8;
  uint8 r1 = 16 * r8;
  if (__CFSHL__(8 * r8, 1))
    R5_slopeptr.addr = 0xe732;
  return r1 | r10 & 0xF;
}

void RunPlayerBlockCode_SpawnFlatPalaceSwitch() {  // 00fa45
  timer_shake_layer1 = 32;
  spr_spriteid[2] = 96;
  spr_current_status[2] = 8;
  SetSprXPos(2, blocks_xpos & ~0xf);
  SetSprYPos(2, (blocks_ypos & ~0xf) + 16);
  InitializeNormalSpriteRAMTables(2);
  spr_decrementing_table1540[2] = 95;
}

void Spr07B_GoalTape_TriggerGoalTape() {  // 00fa80
  timer_inflate_from_pballoon = 0;
  timer_player_has_pballoon = 0;
  timer_respawn_sprite = 0;
  gen_spr_spriteid = 0;
  counter_current_silver_coins = 0;
  for (uint8 i = 11; (i & 0x80) == 0; --i) {
    if (spr_current_status[i] >= 8) {
      if (spr_current_status[i] == 11) {
        Spr07B_GoalTape_LvlEndPowerUp(i);
      } else if (spr_spriteid[i] != 123 && spr_yoffscreen_flag[i] | spr_xoffscreen_flag[i] || (spr_property_bits1686[i] & 0x20) != 0) {
        if ((spr_property_bits190f[i] & 2) == 0)
          spr_current_status[i] = 0;
      } else {
        spr_decrementing_table1540[i] = 16;
        spr_current_status[i] = 6;
      }
    }
  }
  for (int8 j = 7; j >= 0; --j)
    ext_spr_spriteid[(uint8)j] = 0;
}

void Spr07B_GoalTape_LvlEndPowerUp(uint8 j) {  // 00fb00
  uint8 v1 = player_current_power_up;
  if (timer_star_power)
    v1 = 4;
  if (player_riding_yoshi_flag)
    v1 = 5;
  uint8 v2 = spr_spriteid[j];
  switch (v2) {
  case 0x2F:
  case 0x3E: goto LABEL_11;
  case 0x80:
LABEL_10:
    v1 += 7;
LABEL_11:
    v1 += 7;
    break;
  case 0x2D: v1 += 7; goto LABEL_10;
  }
  uint8 v3 = kSpr07B_GoalTape_DATA_00FADF[v1];
  if (v3 == kSpr07B_GoalTape_DATA_00FAFB[player_current_item_box])
    v3 = 120;
  uint8 r15 = 0;
  if (v3 >= 0xE0) {
    r15 = v3 & 0xF;
    v3 = 120;
  }
  spr_spriteid[j] = v3;
  if (v3 == 118)
    ++unusedram_got_invincible_star_from_goal;
  InitializeNormalSpriteRAMTables(j);
  spr_table1594[j] = r15;
  spr_current_status[j] = 12;
  spr_yspeed[j] = -48;
  spr_xspeed[j] = 5;
  spr_decrementing_table154c[j] = 32;
  io_sound_ch1 = 12;
  uint8 v4 = 3;
  while (smoke_spr_spriteid[v4]) {
    if ((--v4 & 0x80) != 0)
      return;
  }
  smoke_spr_spriteid[v4] = 1;
  smoke_spr_ypos_lo[v4] = spr_ypos_lo[j];
  smoke_spr_xpos_lo[v4] = spr_xpos_lo[j];
  smoke_spr_timer[v4] = 27;
}

void SprStatus06_GoalCoins(uint8 k) {  // 00fbb4
  AddSprXPos(k, (int8)misc_layer1_xdisp);
  uint8 v3 = spr_decrementing_table1540[k];
  if (v3) {
    if (v3 == 1)
      spr_yspeed[k] = -48;
    spr_table15f6[k] = 4;
    GenericGFXRtDraw1Tile16x16(k);
    get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = kSprStatus06_GoalCoins_SmokeTiles[spr_decrementing_table1540[k] >> 2];
  } else {
    ++spr_table1570[k];
    UpdateNormalSpritePosition_Y(k);
    spr_yspeed[k] += 2;
    if (!sign8(spr_yspeed[k] - 32)) {
      GiveCoins_OneCoin();
      uint8 v4 = counter_current_silver_coins;
      if (counter_current_silver_coins >= 0xD)
        v4 = 13;
      GivePoints(k, v4);
      counter_current_silver_coins += 2;
      spr_current_status[k] = 0;
    }
    PowerUpAndItemGFXRt_DrawCoinSprite(k);
  }
}

void UnusedYoshiRelatedRoutine() {  // 00fc23
  uint8 j = 11;
  while (spr_current_status[j] != 8 || spr_spriteid[j] != 53) {
    if ((--j & 0x80) != 0) {
      yoshi_carry_over_levels_flag = 0;
      return;
    }
  }
  yoshi_carry_over_levels_flag = 1;
  yoshi_yoshi_has_wings = 0;
  spr_table15f6[j] = spr_table15f6[j] & 0xF1 | 0xA;
  if (!player_riding_yoshi_flag) {
    SetSprXPos(j, mirror_current_layer1_xpos - 16);
    SetSprYPos(j, player_ypos);
    spr_table00c2[j] = 3;
    spr_table157c[j] = 0;
    spr_xspeed[j] = 16;
  }
}

void SpawnMountedYoshiOnLevelLoad() {  // 00fc7a
  io_sound_ch2 = 2;
  uint8 j = 0;
  if (!flag_disable_bonus_game_sprite) {
    j = 5;
    if (sprites_sprite_memory_setting != 10) {
      j = FindFreeNormalSpriteSlot_HighPriority();
      if ((j & 0x80) != 0)
        j = 3;
    }
  }
  spr_current_status[j] = 8;
  spr_spriteid[j] = 53;
  SetSprXPos(j, player_xpos);
  player_ypos -= 16;
  SetSprYPos(j, player_ypos);
  InitializeNormalSpriteRAMTables(j);
  spr_decrementing_table1fe2[j] = 4;
  spr_table15f6[j] = yoshi_current_yoshi_color;
  if (in_yoshi_wings_bonus_area)
    spr_table15f6[j] = 6;
  ++player_riding_yoshi_flag;
  ++spr_table00c2[j];
  spr_table157c[j] = player_facing_direction ^ 1;
  --spr_table160e[j];
  sprites_yoshi_slot_index = j + 1;
  yoshi_stray_yoshi_flag = j + 1;
}

void ClearOutNormalSpriteSlots() {  // 00fcec
  for (int8 i = 11; i >= 0; --i)
    spr_current_status[(uint8)i] = 0;
}

void Spr029_KoopaKids_Init_SetPosition(uint8 k) {  // 00fcf5
  SetSprXPos(k, 160);
  SetSprYPos(k, 0);
}

void SpawnPlayerBreathBubble() {  // 00fd08
  uint8 v3;
  uint8 v0 = 63;
  if ((io_controller_hold1 & 0x83) == 0)
    v0 = 127;
  if (!(flag_sprites_locked | (uint8)(counter_local_frames & v0))) {
    uint8 v1 = 7;
    while (ext_spr_spriteid[v1]) {
      if ((--v1 & 0x80) != 0)
        return;
    }
    ext_spr_spriteid[v1] = 18;
    SetHiLo(&ext_spr_xpos_hi[v1], &ext_spr_xpos_lo[v1],
        player_xpos + kSpawnPlayerBreathBubble_xlo[player_facing_direction]);
    if (!player_current_power_up || (v3 = 4, player_ducking_flag))
      v3 = 12;
    SetHiLo(&ext_spr_ypos_hi[v1], &ext_spr_ypos_lo[v1], player_ypos + v3);
    ext_spr_decrementing_table176f[v1] = 0;
  }
}

void SpawnGlitterEffectForCoin() {  // 00fd5a
  if (!(HIBYTE(player_on_screen_pos_y) | HIBYTE(player_on_screen_pos_x))) {
    uint8 v0 = 3;
    while (smoke_spr_spriteid[v0]) {
      if ((--v0 & 0x80) != 0)
        return;
    }
    smoke_spr_spriteid[v0] = 5;
    smoke_spr_xpos_lo[v0] = blocks_xpos & 0xF0;
    smoke_spr_ypos_lo[v0] = blocks_ypos & 0xF0;
    if ((uint8)misc_current_layer_being_processed) {
      smoke_spr_xpos_lo[v0] = (blocks_xpos - misc_second_level_layer_xpos) & 0xF0;
      smoke_spr_ypos_lo[v0] = (blocks_ypos - misc_second_level_layer_ypos) & 0xF0;
    }
    smoke_spr_timer[v0] = 16;
  }
}

void SpawnPlayerWaterSplashAndBubbles() {  // 00fda5
  uint8 j = 0;
  if (player_in_air_flag) {
    j = 11;
    while (mextspr_spriteid[j]) {
      if ((--j & 0x80) != 0)
        goto LABEL_5;
    }
  } else {
LABEL_5:
    j++;
  }
  uint8 v1 = player_current_power_up != 0;
  if (player_riding_yoshi_flag)
    v1 += 2;
  uint16 ypos = player_ypos + PAIR16(kSpawnPlayerWaterSplashAndBubbles_YHi[v1], kSpawnPlayerWaterSplashAndBubbles_YLo[v1]);
  SetHiLo(&mextspr_ypos_hi[j], &mextspr_ypos_lo[j], (ypos & ~0xf) + 3);
  SetHiLo(&mextspr_xpos_hi[j], &mextspr_xpos_lo[j], player_xpos);
  mextspr_spriteid[j] = 7;
  mextspr_timer[j] = 0;
  if ((player_yspeed & 0x80) == 0) {
    player_yspeed = 0;
    if (player_in_air_flag)
      player_xspeed = 0;
    uint8 v5 = player_current_power_up ? 3 : 2;
    do {
      if (!ext_spr_spriteid[v5]) {
        ext_spr_spriteid[v5] = 18;
        ext_spr_table1765[v5] = 8 * v5 + 0xf7;
        SetHiLo(&ext_spr_ypos_hi[v5], &ext_spr_ypos_lo[v5], player_ypos + kSpawnPlayerWaterSplashAndBubbles_Bubble_YLo[v5]);
        SetHiLo(&ext_spr_xpos_hi[v5], &ext_spr_xpos_lo[v5], player_xpos + kSpawnPlayerWaterSplashAndBubbles_Bubble_XLo[v5]);
        ext_spr_decrementing_table176f[v5] = 0;
      }
    } while ((--v5 & 0x80) == 0);
  }
}

void SpawnPlayerTurnAroundSmoke() {  // 00fe4a
  if (!(flag_sprites_locked | HIBYTE(player_on_screen_pos_y) | HIBYTE(player_on_screen_pos_x) | player_in_air_flag |
        counter_global_frames & 3) &&
      ((io_controller_hold1 & 4) == 0 || (uint8)(player_xspeed + 8) >= 0x10)) {
    uint8 v0 = 3;
    while (smoke_spr_spriteid[v0]) {
      if (!--v0)
        return;
    }
    SpawnPlayerTurnAroundSmoke_00FE72(v0);
  }
}

void SpawnPlayerTurnAroundSmoke_00FE72(uint8 j) {  // 00fe72
  smoke_spr_spriteid[j] = 3;
  smoke_spr_xpos_lo[j] = player_xpos + 4;
  smoke_spr_ypos_lo[j] = player_ypos + 26 + (player_riding_yoshi_flag ? 16 : 0);
  smoke_spr_timer[j] = 19;
}

void SpawnPlayerFireball() {  // 00fea8
  uint8 v0 = 9;
  while (ext_spr_spriteid[v0]) {
    if (--v0 == 7)
      return;
  }
  io_sound_ch3 = 6;
  timer_display_player_shoot_fireball_pose = 10;
  ext_spr_spriteid[v0] = 5;
  ext_spr_yspeed[v0] = 48;
  uint8 dir = player_facing_direction;
  ext_spr_xspeed[v0] = kSpawnPlayerFireball_InitialXSpeed[dir];
  if (player_riding_yoshi_flag)
    dir += yoshi_ducking_flag ? 4 : 2;
  SetHiLo(&ext_spr_xpos_hi[v0], &ext_spr_xpos_lo[v0], player_xpos + PAIR16(kSpawnPlayerFireball_xhi[dir], kSpawnPlayerFireball_xlo[dir]));
  SetHiLo(&ext_spr_ypos_hi[v0], &ext_spr_ypos_lo[v0], player_ypos + kSpawnPlayerFireball_ylo[dir]);
  ext_spr_table1779[v0] = player_current_layer_priority;
}

void Spr088_WingedCage_SyncPlayerPosToLayer1() {  // 00ff07
  player_xpos += (int8)misc_layer1_xdisp;
  player_ypos -= (int8)misc_layer1_ydisp;
}

void Spr088_WingedCage_SyncLayer3ScrollToLayer1(uint8 k) {  // 00ff32
  uint16 v1 = GetSprXPos(k);
  mirror_layer3_xpos = 48 - (v1 - mirror_current_layer1_xpos);
  v1 = GetSprYPos(k);
  mirror_layer3_ypos = 256 - (v1 - mirror_current_layer1_ypos);
}

void Spr089_Layer3Smasher_UpdatePos(uint8 k) {  // 00ff61
  uint16 v1 = GetSprXPos(k);
  if (sign16(v1 + 256) || !sign16(v1 - 256))
    v1 = 256;
  mirror_layer3_xpos = v1;
  uint16 v2 = GetSprYPos(k);
  mirror_layer3_ypos = shaking_layer1_disp_y + 160 - v2;
}


