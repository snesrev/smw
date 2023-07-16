#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"
#include "assets/smw_assets.h"

void (*kUnk_ca1de[5])(void) = {
    &sub_CA1ED,
    &YoshisWatchInExcitementDuringEnding,
    &HatchYoshiEggsDuringEnding,
    &SlideInThankYouDuringEnding,
    &EveryoneCheeringDuringEnding,
};
void (*kGameMode19_Cutscene_Ptrs0CC9A5[7])(void) = {
    &GameMode19_Cutscene_IggyCutscene,   &GameMode19_Cutscene_MortonCutscene, &GameMode19_Cutscene_LemmyCutscene,
    &GameMode19_Cutscene_LudwigCutscene, &GameMode19_Cutscene_RoyCutscene,    &GameMode19_Cutscene_WendyCutscene,
    &GameMode19_Cutscene_LarryCutscene,
};
void (*kGameMode19_Cutscene_Ptrs0CC9C0[6])(void) = {
    &HandleTNTFuse,
    &InitializeTNTExplosion,
    &HandleTNTExplosion,
    &InitializeCastleCrumblingDown,
    &HandleCastleCrumblingDown,
    &CheckIfPlayerCanEndCastleDestructionCutscene,
};
void (*kGameMode19_Cutscene_Ptrs0CC9D6[5])(void) = {
    &PlayerDropkicksAndStompsCastle,
    &InitializeCastleCrumblingDown,
    &HandleCastleCrumblingDown,
    &DrawPlayerCough_MortonCutscene,
    &CheckIfPlayerCanEndCastleDestructionCutscene,
};
void (*kGameMode19_Cutscene_Ptrs0CC9F0[10])(void) = {
    &HandleTNTFuse,
    &InitializeDudTNTExplosion,
    &HandleDudTNTExplosion,
    &DelayTNTExplosionUntilPlayerComesBy,
    &InitializeTNTExplosion,
    &HandleTNTExplosion,
    &InitializeCastleCrumblingDown,
    &HandleCastleCrumblingDown,
    &WaitForCastleDestructionTextToFinishInRoyCutscene,
    &CheckIfPlayerCanEndCastleDestructionCutscene,
};
void (*kGameMode19_Cutscene_Ptrs0CCA1F[8])(void) = {
    &HandleTNTFuse,
    &InitializeTNTExplosion,
    &HandleTNTExplosion,
    &InitializeCastleLiftoff,
    &HandleCastleLiftoff,
    &InitializeFarawayCastleRocket,
    &HandleFarawayCastleRocket,
    &CheckIfPlayerCanEndCastleDestructionCutscene,
};
void (*kGameMode19_Cutscene_Ptrs0CCA49[4])(void) = {
    &WaitBeforeMakingHammeredCastleCrumble,
    &InitializeCastleCrumblingDown,
    &HandleCastleCrumblingDown,
    &CheckIfPlayerCanEndCastleDestructionCutscene,
};
void (*kGameMode19_Cutscene_Ptrs0CCA6E[2])(void) = {
    &WaitForWendysCastleToBeFullyMopped,
    &CheckIfPlayerCanEndCastleDestructionCutscene,
};
void (*kGameMode19_Cutscene_Ptrs0CCA79[5])(void) = {
    &UprootCastleFromGround,
    &KickCastleAway,
    &KickedCastleCreatesQuake,
    &WaitForPlayerVictoryPoseAfterCastleQuake,
    &CheckIfPlayerCanEndCastleDestructionCutscene,
};

static const uint16 kBufferCreditsBackgrounds_TilePageModifier[7] = { 0xffff, 0xfeff, 0xfeff, 0xfeff, 0xffff, 0xfeff, 0xfeff,  };
static const uint8 kUpdateCreditsBackground_PARAMS_0C9559[7] = { 0x1, 0x18, 0x0, 0x40, 0x7f, 0x0, 0x4,  };
static const uint8 kUpdateCreditsBackground_PARAMS_0C9560[7] = { 0x1, 0x18, 0x0, 0x44, 0x7f, 0x0, 0x4,  };
static const uint8 kGameMode1B_EndingCinema_DATA_0C9EAC[5] = { 0x40, 0x3e, 0xfc, 0x0, 0xff,  };
static const uint16 kGameMode1B_EndingCinema_BackgroundChangeHeight[7] = { 0xc0, 0x180, 0x240, 0x300, 0x3c0, 0x480, 0x559,  };
static const uint8 kGameMode1B_EndingCinema_PeachOnYoshiOffset[3] = { 0x0, 0xff, 0x0,  };
static const uint8 kInitializeCreditsEggPositions_InitialXPos[7] = { 0x63, 0x73, 0x83, 0x93, 0xa3, 0xb3, 0xc3,  };
static const uint8 kInitializeCreditsEggPositions_InitialYPos[7] = { 0xa0, 0x9c, 0xa0, 0x9c, 0xa0, 0x9c, 0xa0,  };
static const uint8 kGameMode1D_LoadYoshisHouse_Tiles[42] = { 0xff, 0x2, 0x4, 0x6, 0x8, 0x6, 0x8, 0x6, 0x8, 0x6, 0x8, 0x4, 0x2, 0xff, 0x20, 0x22, 0x24, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x24, 0x22, 0x20, 0x40, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x42, 0x40,  };
static const uint8 kGameMode1D_LoadYoshisHouse_Prop[42] = { 0xff, 0x37, 0x37, 0x35, 0x35, 0x37, 0x37, 0x39, 0x39, 0x3b, 0x3b, 0x77, 0x77, 0xff, 0x37, 0x37, 0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0x77, 0x77, 0x37, 0x37, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x77, 0x77,  };
static const uint8 kDrawEndingThankYou_Tiles[16] = { 0x26, 0x28, 0x2a, 0x2c, 0x46, 0x48, 0x4a, 0x4c, 0x60, 0x62, 0x64, 0x66, 0x6a, 0x6c, 0x6e, 0xa,  };
static const uint8 kProcessCheeringYoshis_DATA_0CA30D[4] = { 0x0, 0x1, 0x2, 0x1,  };
static const uint8 kProcessCheeringYoshis_DATA_0CA311[4] = { 0x0, 0x1, 0x1, 0x1,  };
static const uint8 kGameMode1D_LoadYoshisHouse_EggInitialXPos[7] = { 0x40, 0x50, 0x60, 0x70, 0x80, 0x90, 0xa0,  };
static const uint8 kGameMode1D_LoadYoshisHouse_EggInitialYPos[7] = { 0xaf, 0xab, 0xaf, 0xab, 0xaf, 0xab, 0xaf,  };
static const uint8 kGameMode1D_LoadYoshisHouse_EggYSpeed[7] = { 0xf6, 0x0, 0xf6, 0x0, 0xf6, 0x0, 0xf6,  };
static const uint8 kYoshisWatchInExcitementDuringEnding_DATA_0CA439[3] = { 0x0, 0x2, 0x2,  };
static const uint8 kHatchYoshiEggsDuringEnding_DATA_0CA524[7] = { 0x20, 0x1, 0x10, 0x40, 0x8, 0x2, 0x4,  };
static const uint8 kHatchYoshiEggsDuringEnding_DATA_0CA52B[7] = { 0x10, 0x60, 0x20, 0x0, 0x30, 0x50, 0x40,  };
static const uint8 kHatchYoshiEggsDuringEnding_DATA_0CA5D2[4] = { 0xc8, 0xc8, 0xd8, 0xd8,  };
static const uint8 kHatchYoshiEggsDuringEnding_DATA_0CA5D6[4] = { 0x26, 0x66, 0x26, 0x66,  };
static const uint8 kHatchYoshiEggsDuringEnding_DATA_0CA5DA[4] = { 0xe8, 0x18, 0xf4, 0xc,  };
static const uint16 kDrawCreditsPeachRedAndYellowYoshi_DATA_0CA7B9[26] = { 0x6463, 0x6968, 0x6463, 0x6968, 0x4c4b, 0x6c6b, 0x8b8a, 0x68aa, 0x8e8d, 0xaead, 0x8a, 0x44aa, 0xe8a, 0x2eaa, 0x8081, 0xa0a1, 0x8384, 0xa3a4, 0x8687, 0xa6a7, 0x8180, 0xa1a0, 0x8483, 0xa4a3, 0x8786, 0xa7a6,  };
static const uint16 kDrawCreditsPeachRedAndYellowYoshi_DATA_0CA7ED[26] = { 0x2121, 0x2121, 0x2121, 0x2121, 0x2121, 0x2121, 0x2121, 0x2121, 0x2020, 0x2020, 0x2121, 0x2121, 0x2121, 0x2121, 0x7878, 0x7878, 0x7878, 0x7878, 0x7878, 0x7878, 0x3434, 0x3434, 0x3434, 0x3434, 0x3434, 0x3434,  };
static const uint8 kDrawEndingBabyYoshis_BabyYoshiProp[7] = { 0x68, 0x26, 0x24, 0x6a, 0x28, 0x64, 0x26,  };
static const uint16 kDrawLeaningEndingYoshis_DATA_0CA93A[12] = { 0xb9bb, 0xdbdc, 0xd9da, 0x898b, 0xabac, 0xa9aa, 0xbbb9, 0xdad9, 0xdcdb, 0x8b89, 0xaaa9, 0xacab,  };
static const uint16 kDrawLeaningEndingYoshis_DATA_0CA952[12] = { 0x7878, 0x7878, 0x7878, 0x7878, 0x7878, 0x7878, 0x3434, 0x3434, 0x3434, 0x3434, 0x3434, 0x3434,  };
static const uint16 kDrawLeaningEndingYoshis_DATA_0CA96A[12] = { 0x1000, 0x800, 0x1810, 0x1000, 0x800, 0x1810, 0x1000, 0x800, 0x1810, 0x1000, 0x800, 0x1810,  };
static const uint16 kDrawLeaningEndingYoshis_DATA_0CA982[12] = { 0x0, 0x1010, 0x1010, 0x0, 0x1010, 0x1010, 0x0, 0x1010, 0x1010, 0x0, 0x1010, 0x1010,  };
static const uint8 kDrawLeaningEndingYoshis_DATA_0CA99A[4] = { 0x0, 0x6, 0xc, 0x12,  };
static const uint8 kDrawCameraFacingEndingYoshis_Tiles[6] = { 0xc4, 0xe4, 0xe6, 0xe8, 0xce, 0xee,  };
static const uint8 kDrawCameraFacingEndingYoshis_Prop[4] = { 0x36, 0x36, 0x3a, 0x3a,  };
static const uint8 kDrawingTheEndMarioLuigiAndPeach_TileData[140] = { 0x53, 0x6a, 0x80, 0x3c, 0x63, 0x6a, 0x82, 0x3c, 0x53, 0x7a, 0xa0, 0x3c, 0x63, 0x7a, 0xa2, 0x3c, 0x53, 0x8a, 0x84, 0x3c, 0x63, 0x8a, 0x86, 0x3c, 0x53, 0x9a, 0xa4, 0x3c, 0x63, 0x9a, 0xa6, 0x3c, 0x53, 0xaa, 0x88, 0x3c, 0x63, 0xaa, 0x8a, 0x3c, 0x8d, 0x5a, 0xa8, 0x3a, 0x9d, 0x5a, 0xaa, 0x3a, 0x8d, 0x6a, 0x8c, 0x3a, 0x9d, 0x6a, 0x8e, 0x3a, 0x8d, 0x7a, 0xac, 0x3a, 0x9d, 0x7a, 0xae, 0x3a, 0x8d, 0x8a, 0x63, 0x3a, 0x9d, 0x8a, 0x65, 0x3a, 0x8d, 0x9a, 0x48, 0x3a, 0x9d, 0x9a, 0x68, 0x3a, 0x8d, 0xaa, 0x6b, 0x3a, 0x9d, 0xaa, 0x6d, 0x3a, 0x78, 0x58, 0x4d, 0x3e, 0x70, 0x68, 0xe0, 0x3f, 0x80, 0x68, 0xc4, 0x3f, 0x70, 0x78, 0x4a, 0x3f, 0x80, 0x78, 0x4c, 0x3f, 0x70, 0x88, 0x6a, 0x3f, 0x80, 0x88, 0x6c, 0x3f, 0x68, 0x98, 0xab, 0x3f, 0x78, 0x98, 0xc8, 0x3f, 0x88, 0x98, 0xe6, 0x3f, 0x68, 0xa8, 0xe8, 0x3f, 0x78, 0xa8, 0xea, 0x3f, 0x88, 0xa8, 0xec, 0x3f,  };
static const uint8 kCreditsFadeOut_DATA_0CAB1B[2] = { 0xfe, 0x2,  };
static const uint8 kCreditsFadeOut_DATA_0CAB1D[2] = { 0x0, 0xe0,  };
static const uint8 kCreditsFadeOut_BGPaletteIndex[8] = { 0x0, 0x18, 0x30, 0x48, 0x60, 0x78, 0x90, 0xa8,  };
static const uint8 kCreditsFadeOut_SkyColorSetting[7] = { 0x6, 0x0, 0x0, 0x2, 0x5, 0x6, 0x0,  };
static const uint8 kCreditsFadeOut_BGPaletteSetting[7] = { 0x3, 0x3, 0x7, 0x0, 0x1, 0x2, 0x0,  };
static const uint8 kInitializeEnemyRollcallLayerPositions_DATA_0CADB5[13] = { 0x28, 0x28, 0x44, 0x28, 0x38, 0x20, 0x28, 0x20, 0x8, 0x28, 0x7c, 0x68, 0x28,  };
static const uint16 kInitializeEnemyRollcallLayerPositions_InitialLayer2YPos[13] = { 0x0, 0x88, 0xe0, 0xc0, 0xe8, 0x0, 0xa0, 0x50, 0xb0, 0xe0, 0x18, 0xe0, 0x0,  };
static const uint16 kGameMode25_ShowEnemyRollcallScreen_EnemyRollcallSpriteDataPtrs[13] = { 0x2fc, 0x11c, 0x1c1, 0x222, 0x0, 0x45, 0x28b, 0x395, 0x9e, 0x42a, 0x493, 0xe7, 0x4fc,  };
static const uint8 kDrawThankYouSpeechBubble_TileData[12] = { 0x20, 0x48, 0xa6, 0x18, 0x30, 0x48, 0xa8, 0x18, 0x28, 0x58, 0x8d, 0x8,  };
static const uint8 kDrawCastleDestructionCastleDoor_Tiles[4] = { 0x86, 0x87, 0x96, 0x97,  };
static const uint8 kHandleTNTExplosion_DATA_0CCC49[4] = { 0x3, 0x1, 0x3, 0x1,  };
static const uint16 kHandleTNTExplosion_DATA_0CCC4D[2] = { 0x7393, 0x7fff,  };
static const uint8 kHandleTNTExplosion_DATA_0CCC9F[18] = { 0xa0, 0xa4, 0x0, 0xc0, 0xc4, 0x0, 0xa0, 0xa2, 0xa4, 0xc0, 0xc2, 0xc4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,  };
static const uint8 kHandleTNTExplosion_DATA_0CCCB1[5] = { 0x0, 0x6, 0xc, 0x6, 0xc,  };
static const uint8 kHandleCastleLiftoff_CastleDustTiles[8] = { 0x80, 0x81, 0x82, 0x83, 0x83, 0x82, 0x81, 0x80,  };
static const uint8 kHandleCastleLiftoff_RocketFlameTiles[4] = { 0xc6, 0xc8, 0xc6, 0xc8,  };
static const uint8 kHandleCastleLiftoff_RocketFlameProp[4] = { 0x25, 0x25, 0x65, 0x65,  };
static const uint8 kHandleFarawayCastleRocket_DATA_0CCED4[7] = { 0x2, 0xff, 0x2, 0x3, 0x4, 0x5, 0x6,  };
static const uint8 kHandleFarawayCastleRocket_DATA_0CCEDB[7] = { 0x3, 0x1, 0x7, 0x7, 0x7, 0x7, 0x7,  };
static const uint8 kHandleFarawayCastleRocket_Tiles[7] = { 0xb7, 0xb8, 0x89, 0x99, 0xa9, 0xb9, 0xe8,  };
static const uint8 kHandleFarawayCastleRocket_Prop[7] = { 0x25, 0x25, 0x23, 0x23, 0x23, 0x23, 0x23,  };
static const uint8 kHandleDudTNTExplosion_TilesAndProp[4] = { 0x60, 0x62, 0x64, 0x66,  };
static const uint8 kDrawCutsceneContactEffect_Tiles[4] = { 0x7c, 0x7d, 0x7d, 0x7c,  };
static const uint8 kDrawCutsceneContactEffect_Prop[4] = { 0x30, 0x30, 0xf0, 0xf0,  };
static const uint8 kHandleCastleCrumblingDown_RubbleTiles[41] = { 0x20, 0xb3, 0x0, 0xf, 0xc0, 0x1, 0xc1, 0x1, 0xc2, 0x1, 0xc3, 0x1, 0xc4, 0x1, 0xc5, 0x1, 0xc1, 0x41, 0xc0, 0x41, 0x20, 0xd3, 0x0, 0xf, 0xd0, 0x1, 0xd1, 0x1, 0xd2, 0x1, 0xd3, 0x1, 0xd4, 0x1, 0xd5, 0x1, 0xd1, 0x41, 0xd0, 0x41, 0xff,  };
static const uint8 kProcessMop_DATA_0CD1F0[13] = { 0x20, 0xf4, 0x40, 0x2, 0xf8, 0x0, 0x21, 0x14, 0x40, 0x2, 0xf8, 0x0, 0xff,  };
static const uint16 kProcessMop_DATA_0CD1FD[24] = { 0xf420, 0x1421, 0x3421, 0x5421, 0x7421, 0x9421, 0xb421, 0xd421, 0xf620, 0x1621, 0x3621, 0x5621, 0x7621, 0x9621, 0xb621, 0xd621, 0xf820, 0x1821, 0x3821, 0x5821, 0x7821, 0x9821, 0xb821, 0xd821,  };
static const uint8 kSpawnHammerDebris_YSpeed[16] = { 0xc8, 0xc0, 0xc4, 0xc8, 0xc0, 0xb4, 0xc8, 0xb8, 0xc6, 0xb7, 0xc4, 0xb0, 0xc8, 0xc0, 0xc8, 0xc4,  };
static const uint8 kSpawnHammerDebris_XSpeed[16] = { 0x18, 0xf8, 0xa, 0x20, 0xe8, 0x1a, 0xea, 0x8, 0xf0, 0x18, 0xe0, 0x2a, 0xf8, 0x20, 0xfa, 0x18,  };
static const uint8 kProcessHammerDebris_DATA_0CD423[2] = { 0x3c, 0x3d,  };
static const uint8 kDrawQuestionMark_YDisp[32] = { 0xf8, 0x80, 0x80, 0x80, 0xfa, 0x80, 0x80, 0x80, 0xfa, 0xfc, 0x80, 0x80, 0xfa, 0xfc, 0x4, 0x80, 0xf8, 0x80, 0x80, 0x80, 0xf9, 0x80, 0x80, 0x80, 0xfa, 0x80, 0x80, 0x80, 0xfa, 0x80, 0x80, 0x80,  };
static const uint8 kDrawQuestionMark_XDisp[32] = { 0x8, 0x80, 0x80, 0x80, 0x9, 0x80, 0x80, 0x80, 0x9, 0xff, 0x80, 0x80, 0x9, 0xff, 0xf6, 0x80, 0x4, 0x80, 0x80, 0x80, 0x0, 0x80, 0x80, 0x80, 0xff, 0x80, 0x80, 0x80, 0x0, 0x80, 0x80, 0x80,  };
static const uint8 kDrawPlayerCough_Tiles[4] = { 0x89, 0x99, 0xa9, 0xb9,  };
static const uint8 kDrawWoodHammer_HammerSwingPlayerPoses[16] = { 0x35, 0x36, 0x36, 0x36, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x37, 0x36, 0x36, 0x35, 0x35, 0x35,  };
static const uint8 kDrawWoodHammer_Tiles[19] = { 0x8b, 0x8b, 0x8b, 0xaa, 0x8a, 0xce, 0xce, 0x8a, 0x8a, 0xaa, 0xaa, 0x8a, 0xaa, 0x8a, 0xce, 0x8a, 0xaa, 0x8a, 0x8a,  };
static const uint8 kDrawWoodHammer_Prop[19] = { 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x61, 0x21, 0x21, 0x21, 0x21, 0xa1, 0x21, 0x21, 0x61, 0x61, 0x61, 0xe1, 0xe1,  };
static const uint8 kDrawWoodHammer_XDisp[38] = { 0xfa, 0xfa, 0xf9, 0xfb, 0xf9, 0xfa, 0xf0, 0xf0, 0xf4, 0xf4, 0xfd, 0xff, 0xfd, 0xff, 0xa, 0xd, 0xa, 0xd, 0xe, 0x10, 0xe, 0x10, 0xd, 0xe, 0xe, 0x10, 0xa, 0xd, 0xfd, 0xff, 0xf4, 0xf4, 0xf0, 0xf0, 0xf3, 0xf0, 0xf3, 0xf0,  };
static const uint8 kDrawWoodHammer_YDisp[38] = { 0x6, 0x3, 0x7, 0x0, 0x7, 0x1, 0xd, 0x8, 0x2, 0xfb, 0xff, 0xf6, 0xff, 0xf6, 0x3, 0xfd, 0x3, 0xfd, 0xa, 0x6, 0xa, 0x6, 0x12, 0xf, 0xa, 0x6, 0x3, 0xfd, 0xff, 0xf6, 0x2, 0xfb, 0xd, 0x8, 0x15, 0x10, 0x15, 0x10,  };
static const uint8 kProcessMop_DATA_0CD6C4[6] = { 0xe7, 0xe6, 0xe6, 0xea, 0xe6, 0xe7,  };
static const uint8 kProcessMop_DATA_0CD6CA[6] = { 0xf6, 0xf1, 0xf3, 0xf3, 0xf3, 0xf4,  };
static const uint8 kProcessMop_DATA_0CD6D0[3] = { 0x1b, 0xe, 0x0,  };
static const uint8 kProcessMop_DATA_0CD6D3[3] = { 0x15, 0x8, 0x0,  };
static const uint8 kProcessMop_Tiles[3] = { 0x8e, 0x8e, 0x8c,  };
static const uint8 kProcessMop_DATA_0CD6D9[7] = { 0xfc, 0x4, 0xfc, 0x4, 0xfc, 0x4, 0xfc,  };
// todo: oob
static const uint8 kProcessMop_DATA_0CD6E0[7] = { 0x34, 0x68, 0x34, 0x68, 0x34,0x68, 0x34,  };
static const uint8 kProcessMop_DATA_0CD6E5[7] = { 0x68, 0x34, 0xb0, 0x0, 0xc0, 0x0, 0xc0,  };
static const uint8 kCarryEggAwayFromCastle_DATA_0CD7EB[2] = { 0xf7, 0xf6,  };
static const uint8 kCarryEggAwayFromCastle_DATA_0CD7ED[6] = { 0x63, 0x5f, 0x62, 0x5f, 0x62, 0x5e,  };
static const uint8 kCarryEggAwayFromCastle_YDisp[16] = { 0x67, 0x66, 0x65, 0x65, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x64, 0x65, 0x65, 0x66, 0x67,  };

void GameMode1B_EndingCinema_Bank0C() {  // 0c938d
  GameMode1B_EndingCinema_Sub();
  CreditsFadeOut();
}

void GameMode1D_LoadYoshisHouse_Bank0C() {  // 0c939a
  GameMode1D_LoadYoshisHouse_DrawEndingYoshisHouseDecorations();
  GameMode1D_LoadYoshisHouse_0CA1D4();
}

void GameMode25_ShowEnemyRollcallScreen_Bank0C() {  // 0c93a5
  GameMode25_ShowEnemyRollcallScreen_Sub();
}

void GameMode21_DelayEnemyRollcall_Bank03() {  // 0c93ad
  if (!--HIBYTE(misc_layer3_yspeed)) {
    misc_game_mode = 35;
    counter_enemy_rollcall_screen = -1;
  }
}

void BufferCreditsBackgrounds() {  // 0c93dd
  *(uint16 *)&blocks_screen_to_place_current_object = 0;
  do {
    int v0 = blocks_screen_to_place_current_object;
    const uint8 *ptr_layer2_data_addr = kBufferCreditsBackgrounds_Layer2(v0).ptr;
    uint8 isbg = kBufferCreditsBackgrounds_Layer2_IsBg[v0];
    uint8 upper = isbg >> 4;
    for (uint16 i = 0; i != 512; ++i) {
      blocks_layer2_tiles_hi[i] = upper;
      blocks_layer2_tiles_hi[i + 512] = upper;
    }
    BufferCreditsBackgrounds_0C944C(0xb900, ptr_layer2_data_addr);

    uint16 modifier = kBufferCreditsBackgrounds_TilePageModifier[v0];
    BufferCreditsBackgrounds_0C94C0(modifier);
    ++*(uint16 *)&blocks_screen_to_place_current_object;
  } while (*(uint16 *)&blocks_screen_to_place_current_object != 7);
  credits_var65 = 0x5840;
  credits_index = 0;
  blocks_screen_to_place_current_object = 0;
  UpdateCreditsBackground();
  InitializeCreditsEggPositions();
  io_music_ch1 = 9;
}

void BufferCreditsBackgrounds_0C944C(uint16 r13w, const uint8 *src) {  // 0c944c
  uint16 R3 = 0;
  uint16 R5 = 0;
  uint8 *wp = g_ram + r13w;
  do {
    int16 v0 = R3;
    uint8 r7 = src[R3];
    uint16 v1 = v0 + 1;
    R3 = v1;
    if ((r7 & 0x80) == 0) {
      do {
        int16 v4 = R3;
        uint8 v5 = src[R3];
        R3 = v4 + 1;
        int16 v6 = R5;
        wp[R5] = v5;
        R5 = v6 + 1;
      } while ((--r7 & 0x80) == 0);
    } else {
      r7 &= ~0x80;
      uint8 v2 = src[v1];
      R3 = v1 + 1;
      uint16 v3 = R5;
      do {
        wp[v3++] = v2;
      } while ((--r7 & 0x80) == 0);
      R5 = v3;
    }
  } while (src[R3] != 0xFF || src[R3 + 1] != 0xFF);
  uint16 r0w = 0x9100;  // kMap16Data_Backgrounds
  for (uint16 i = 0; i != 0x400; i += 2) {
    pointer_map16_tiles[i >> 1] = r0w;
    r0w += 8;
  }
}

void BufferCreditsBackgrounds_0C94C0(uint16 mask) {  // 0c94c0
  const uint8 *p_lo = g_ram + 0xb900;
  const uint8 *p_hi = g_ram + 0xbd00;

  uint16 r4w = 240;
  uint16 r0w = blocks_screen_to_place_current_object << 8;
  uint16 r8w = 127;
  while (1) {
    do {
      uint16 r2w = p_lo[r4w] | p_hi[r4w] << 8;
      const uint16 *rp = GetMap16RomAddr(13, pointer_map16_tiles[r2w]);
      uint16 v2 = (4 * r0w) & 0x3F | (2 * ((4 * r0w) & 0xFFC0));
      *(uint16 *)&ow_layer2_tiles[v2] = mask & rp[0];
      *(uint16 *)&ow_layer2_tiles[v2 + 64] = mask & rp[1];
      *(uint16 *)&ow_layer2_tiles[v2 + 2] = mask & rp[2];
      *(uint16 *)&ow_layer2_tiles[v2 + 66] = mask & rp[3];
      ++r0w;
      ++r4w;
      --r8w;
    } while ((r8w & 0x8000) == 0);
    r8w = 127;
    if (r4w != 368)
      break;
    r4w = 672;
  }
}

void UpdateCreditsBackground() {  // 0c9567
  SmwCopyToVram(0x30c0, g_ram + (0x14000 | blocks_screen_to_place_current_object << 11), 0x400);
  SmwCopyToVram(0x34c0, g_ram + (0x14400 | blocks_screen_to_place_current_object << 11), 0x400);
  flag_update_credits_background = 0;
}

void GameMode1B_EndingCinema_BufferNextRowOfCredits() {  // 0c9eb1
  uint16 v0 = stripe_image_upload;
  uint16 v1 = 0;
  int v2 = stripe_image_upload;
  WORD(stripe_image_upload_data[v2 + 0]) = swap16(credits_var65);
  uint16 v3 = v0 + 2;
  do
    stripe_image_upload_data[v3++] = kGameMode1B_EndingCinema_DATA_0C9EAC[v1++];
  while (v1 != 5);
  uint16 v4 = v3 - 1;
  stripe_image_upload = v4;
  uint16 v5 = kGameMode1B_EndingCinema_RowPointers[credits_index++];
  if (kGameMode1B_EndingCinema_Tilemaps[v5] != 0xFF) {
    uint8 r2 = kGameMode1B_EndingCinema_Tilemaps[v5];
    uint16 r0w = kGameMode1B_EndingCinema_Tilemaps[v5 + 1];
    uint16 v6 = v5 + 2;
    WORD(stripe_image_upload_data[v4]) = swap16(credits_var65) + (r2 << 8);
    uint16 v7 = v4 + 2;
    WORD(stripe_image_upload_data[v7]) = swap16(r0w);
    uint16 v8 = v7 + 2;
    do {
      *(uint16 *)&stripe_image_upload_data[v8] = *(uint16 *)&kGameMode1B_EndingCinema_Tilemaps[v6];
      v8 += 2;
      v6 += 2;
      r0w -= 2;
    } while ((r0w & 0x8000) == 0);
    *(uint16 *)&stripe_image_upload_data[v8] = 255;
    stripe_image_upload = v8;
  }
  credits_var65 += 32;
  if ((credits_var65 & 0x3FF) == 0)
    credits_var65 ^= 0xC00;
}

void GameMode1B_EndingCinema_Sub() {  // 0c9f6a
  get_PointU16(l1_l2_scroll_spr_speed, 0)->x = -128;
  uint16 r0w = mirror_current_layer2_xpos;
  r0w += GameMode1B_EndingCinema_0C9FCB(0);
  mirror_current_layer2_xpos = r0w;
  if (mirror_layer3_ypos < 0x559) {
    get_PointU16(l1_l2_scroll_spr_speed, 2)->x = 64;
    uint16 r1w = mirror_layer3_ypos;
    uint16 r4w = mirror_layer3_ypos;
    r4w += GameMode1B_EndingCinema_0C9FCB(2);
    uint16 v1 = r1w;
    if (v1 != r4w) {
      mirror_layer3_ypos = r4w;
      if ((r4w & 7) == 1)
        GameMode1B_EndingCinema_BufferNextRowOfCredits();
    }
  }
  uint8 v2 = 12;
  while (mirror_layer3_ypos != kGameMode1B_EndingCinema_BackgroundChangeHeight[v2 >> 1]) {
    v2 -= 2;
    if ((v2 & 0x80) != 0)
      goto LABEL_11;
  }
  if (!flag_message_window_size_change_direction)
    ++*(uint16 *)&flag_message_window_size_change_direction;
LABEL_11:
  player_xpos = 56;
  player_ypos = 143;
  player_current_power_up = 1;
  player_xspeed = 8;
  HandlePlayerPoseAndAnimationTimersDuringEnding();
  SetSprXYPos(0, 82, 143);
  spr_oamindex[0] = -96;
  SpawnEndingYoshiSpriteAndDrawPlayer();
  uint8 r0 = 81;
  uint8 r2 = kGameMode1B_EndingCinema_PeachOnYoshiOffset[spr_table1602[0]] - 123;
  DrawCreditsPeachRedAndYellowYoshi_Peach(0, 4 * spr_table1602[0], r0, r2);
  MakeCreditsEggsBounce(-96);
  r2 = 16;
  DrawEndingBabyYoshis(r2);
}

uint16 GameMode1B_EndingCinema_0C9FCB(uint8 k) {  // 0c9fcb
  uint16 v4;

  PointU16 *pt = get_PointU16(l1_l2_scroll_spr_sub_pos, k);
  uint16 v2 = get_PointU16(l1_l2_scroll_spr_speed, k)->x + LOBYTE(pt->x);
  pt->x = v2;
  int16 v3 = v2 & 0xFF00;
  if (v3 < 0)
    v3 |= 0xFF;
  uint8 v5 = v3;
  LOBYTE(v4) = HIBYTE(v3);
  HIBYTE(v4) = v5;
  return v4;
}

void InitializeCreditsEggPositions() {  // 0ca051
  for (uint8 i = 14; (i & 0x80) == 0; --i) {
    sprites_cutscene_sprite_sub_ypos[i] = 0;
    sprites_cutscene_sprite_sub_xpos[i] = 0;
  }
  uint8 v1 = 13;
  uint8 v2 = 6;
  do {
    sprites_cutscene_sprite_ypos_lo[v1] = kInitializeCreditsEggPositions_InitialYPos[v2];
    sprites_cutscene_sprite_ypos_hi[v1] = 0;
    sprites_cutscene_sprite_xpos_lo[v1] = kInitializeCreditsEggPositions_InitialXPos[v2];
    sprites_cutscene_sprite_xpos_hi[v1] = 0;
    sprites_cutscene_sprite_yspeed[v1] = kGameMode1D_LoadYoshisHouse_EggYSpeed[v2];
    sprites_cutscene_sprite_table_0AF6[v1] = 1;
    --v2;
    --v1;
  } while (v1 != 6);
  player_facing_direction = 0;
  timer_wait_before_message_window_size_change = -30;
}

void GameMode1D_LoadYoshisHouse_DrawEndingYoshisHouseDecorations() {  // 0ca0e3
  uint8 r0 = 16;
  uint8 r2 = 16;
  uint8 r1 = 47;
  uint8 v0 = -112;
  for (uint8 i = 0; i != 42; ++i) {
    if (kGameMode1D_LoadYoshisHouse_Tiles[i] != 0xFF) {
      OamEnt *oam = get_OamEnt(oam_buf, v0);
      oam[64].charnum = kGameMode1D_LoadYoshisHouse_Tiles[i];
      oam[64].flags = kGameMode1D_LoadYoshisHouse_Prop[i];
      oam[64].xpos = r0;
      oam[64].ypos = r1;
      sprites_oamtile_size_buffer[(v0 >> 2) + 64] = 2;
      v0 += 4;
    }
    r0 += 16;
    if (r0 == 0xF0) {
      r0 = r2;
      r1 += 16;
    }
  }
}

void DrawEndingThankYou() {  // 0ca146
  DrawEndingThankYou_Entry2(0x50, 0, 0, 0, 63);
}

void DrawEndingThankYou_Entry2(uint8 k, uint8 j, uint16 r0w, uint16 r4, uint16 r8) {  // 0ca159
  r0w += 128;
  uint16 r2w = r0w;
  k = DrawEndingThankYou_0CA183(k, j, r8, r0w, r2w);
  r0w = 128 - r4 - 64;
  r2w = 128 - r4 - 64;
  DrawEndingThankYou_0CA183(k, j+8, 63, r0w, r2w);
}

uint8 DrawEndingThankYou_0CA183(uint8 k, uint8 j, uint16 r8, uint16 r0w, uint16 r2) {  // 0ca183
  do {
    if (r0w < 256) {
      OamEnt *oam = get_OamEnt(oam_buf, k);
      oam[64].charnum = kDrawEndingThankYou_Tiles[j];
      oam[64].flags = 53;
      oam[64].xpos = r0w;
      oam[64].ypos = r8;
      sprites_oamtile_size_buffer[(k >> 2) + 64] = 2;
      k += 4;
    }
    r0w += 16;
    if ((j & 7) == 3) {
      r0w = r2;
      r8 += 16;
    }
    ++j;
  } while ((j & 7) != 0);
  return k;
}

void GameMode1D_LoadYoshisHouse_0CA1D4() {  // 0ca1d4
  CreditsFadeOut();
  kUnk_ca1de[l1_l2_scroll_spr_current_state[0]]();
}

void sub_CA1ED() {  // 0ca1ed
  ProcessCheeringYoshis();
  if (!timer_wait_before_message_window_size_change)
    WalkingIntoYoshisHouseDuringEnding_0CA1F6();
}

void WalkingIntoYoshisHouseDuringEnding_0CA1F6() {  // 0ca1f6
  uint8 r2;
  player_ypos = 352;
  if (sprites_cutscene_sprite_xpos_lo[0] == 112) {
    yoshi_stray_yoshi_flag = 0;
    player_current_pose = 15;
    HandlePlayerPoseAndAnimationTimersDuringEnding_0CA764();
    SpawnEndingYoshiSpriteAndDrawPlayer_0CA7B4();
    if (!l1_l2_scroll_spr_current_state[0]) {
      uint8 r0 = spr_xpos_lo[0];
      r2 = -97;
      DrawCameraFacingEndingYoshis_BlueYoshi(0xB4, 0, 1, r0, r2);
    }
    uint16 r0w = PAIR16(sprites_cutscene_sprite_xpos_hi[0], sprites_cutscene_sprite_xpos_lo[0]) + 16;
    r2 = -97;
    DrawCreditsPeachRedAndYellowYoshi_Peach(0xA4, 0xC, r0w, r2);
  } else {
    sprites_cutscene_sprite_xspeed[0] = -8;
    UpdateCutsceneSpritePosition_X(0);
    player_xpos = PAIR16(sprites_cutscene_sprite_xpos_hi[0], sprites_cutscene_sprite_xpos_lo[0]);
    player_current_power_up = 1;
    player_xspeed = 8;
    HandlePlayerPoseAndAnimationTimersDuringEnding();
    SetSprXPos(0, PAIR16(sprites_cutscene_sprite_xpos_hi[0], sprites_cutscene_sprite_xpos_lo[0]) + 48);
    SetSprYPos(0, 0x160);
    spr_oamindex[0] = 48;
    SpawnEndingYoshiSpriteAndDrawPlayer();
    uint16 r0w = PAIR16(sprites_cutscene_sprite_xpos_hi[0], sprites_cutscene_sprite_xpos_lo[0]) + 16;
    r2 = -97;
    PointU16 *pt = get_PointU16(l1_l2_scroll_spr_sub_pos, 0);
    if ((int8)--LOBYTE(pt->x) < 0) {
      LOBYTE(pt->x) = 6;
      HIBYTE(pt->x) ^= 1;
    }
    DrawCreditsPeachRedAndYellowYoshi_Peach(0xA4, 4 * (HIBYTE(pt->x) + 3), r0w, r2);
  }
  uint16 r0w = sprites_cutscene_sprite_xpos_lo[7] | sprites_cutscene_sprite_xpos_hi[7] << 8;
  if (r0w == 48) {
    if (!*(uint16 *)l1_l2_scroll_spr_current_state)
      ++*(uint16 *)l1_l2_scroll_spr_current_state;
  } else {
    for (uint8 i = 13; i != 6; --i) {
      if (i < 0xB || sprites_cutscene_sprite_xpos_lo[11] != 0x98) {
        sprites_cutscene_sprite_xspeed[i] = -8;
        UpdateCutsceneSpritePosition_X(i);
      }
    }
  }
  WalkingIntoYoshisHouseDuringEnding_0CA2FC();
}

void WalkingIntoYoshisHouseDuringEnding_0CA2FC() {  // 0ca2fc
  uint8 r2;
  MakeCreditsEggsBounce(-81);
  r2 = -120;
  DrawEndingBabyYoshis(r2);
}

void ProcessCheeringYoshis() {  // 0ca315
  ++sprites_cutscene_sprite_yspeed[1];
  UpdateCutsceneSpritePosition_Y(1);
  if (sprites_cutscene_sprite_ypos_lo[1] >= 0x9F) {
    sprites_cutscene_sprite_yspeed[1] = -16;
    sprites_cutscene_sprite_ypos_lo[1] = -97;
  }
  int8 v0 = 0;
  if ((sprites_cutscene_sprite_yspeed[1] & 0x80) != 0) {
    if (sprites_cutscene_sprite_yspeed[1] < 0xF4)
      goto LABEL_10;
    v0 = 1;
    if (sprites_cutscene_sprite_yspeed[1] < 0xF8)
      goto LABEL_10;
    v0 = 2;
  }
  if (sprites_cutscene_sprite_yspeed[1] < 0xC) {
    v0 = 1;
    if (sprites_cutscene_sprite_yspeed[1] < 8)
      v0 = 2;
  }
LABEL_10:
  LOBYTE(misc_layer3_xspeed) = v0;
  if (sprites_draw_ending_yoshis == 1) {
    uint8 r0 = 24;
    uint8 r2 = sprites_cutscene_sprite_ypos_lo[1];
    DrawCreditsPeachRedAndYellowYoshi_Peach(0xD0, 4 * (kProcessCheeringYoshis_DATA_0CA30D[(uint8)misc_layer3_xspeed] + 7), r0, r2);
    r0 = -44;
    r2 = sprites_cutscene_sprite_ypos_lo[1];
    DrawCreditsPeachRedAndYellowYoshi_Peach(0xF0, 4 * (kProcessCheeringYoshis_DATA_0CA30D[(uint8)misc_layer3_xspeed] + 10), r0, r2);
    uint8 v1 = 2 * kProcessCheeringYoshis_DATA_0CA311[(uint8)misc_layer3_xspeed];
    r0 = 80;
    r2 = sprites_cutscene_sprite_ypos_lo[1];
    DrawCameraFacingEndingYoshis_BlueYoshi(0xF0, v1, 0, r0, r2);
  }
}

void GameMode1D_LoadYoshisHouse_InitializeYoshisHouseSceneRAM() {  // 0ca3c9
  sprites_draw_ending_yoshis = 1;
  player_facing_direction = 0;
  l1_l2_scroll_spr_current_state[0] = 0;
  sprites_cutscene_sprite_xpos_lo[0] = 0;
  sprites_cutscene_sprite_xpos_hi[0] = 1;
  sprites_cutscene_sprite_sub_xpos[0] = 0;
  sprites_cutscene_sprite_sub_xpos[1] = 0;
  sprites_cutscene_sprite_sub_xpos[7] = 0;
  PointU16 *pt = get_PointU16(l1_l2_scroll_spr_sub_pos, 0);
  LOBYTE(pt->x) = 6;
  HIBYTE(pt->x) = 0;
  misc_layer3_xspeed = 0x600;
  sprites_cutscene_sprite_yspeed[1] = -16;
  sprites_cutscene_sprite_ypos_lo[1] = -97;
  timer_wait_before_message_window_size_change = -30;
  blocks_screen_to_place_current_object = -30;
  io_music_ch1 = 10;
  uint8 v1 = 13;
  uint8 v2 = 6;
  do {
    sprites_cutscene_sprite_ypos_lo[v1] = kGameMode1D_LoadYoshisHouse_EggInitialYPos[v2];
    sprites_cutscene_sprite_ypos_hi[v1] = 0;
    sprites_cutscene_sprite_xpos_lo[v1] = kGameMode1D_LoadYoshisHouse_EggInitialXPos[v2];
    sprites_cutscene_sprite_yspeed[v1] = kGameMode1D_LoadYoshisHouse_EggYSpeed[v2];
    sprites_cutscene_sprite_table_0AF6[v1] = 1;
    sprites_cutscene_sprite_xpos_hi[v1] = 1;
    --v2;
    --v1;
  } while (v1 != 6);
}

void YoshisWatchInExcitementDuringEnding() {  // 0ca43c
  if ((uint8)misc_layer3_xspeed >= 8) {
    --HIBYTE(misc_layer3_xspeed);
    if ((misc_layer3_xspeed & 0x8000) != 0) {
      HIBYTE(misc_layer3_xspeed) = 6;
      LOBYTE(misc_layer3_xspeed) = misc_layer3_xspeed + 1;
      if ((uint8)misc_layer3_xspeed == 11) {
        LOBYTE(misc_layer3_xspeed) = 10;
        ++l1_l2_scroll_spr_current_state[0];
      }
    }
    YoshisWatchInExcitementDuringEnding_0CA478();
  } else {
    ProcessCheeringYoshis();
    if (!(uint8)misc_layer3_xspeed && sprites_cutscene_sprite_ypos_lo[1] == 0x9F)
      LOBYTE(misc_layer3_xspeed) = 8;
    YoshisWatchInExcitementDuringEnding_0CA510(0);
  }
}

void YoshisWatchInExcitementDuringEnding_0CA478() {  // 0ca478
  if ((misc_layer3_xspeed & 3) != 0) {
    YoshisWatchInExcitementDuringEnding_0CA4B6();
  } else {
    uint8 r2;
    uint8 r0 = 24;
    r2 = -97;
    DrawCreditsPeachRedAndYellowYoshi_Peach(0xD0, 4 * ((misc_layer3_xspeed & 3) + 7), r0, r2);
    r0 = -44;
    r2 = -97;
    DrawCreditsPeachRedAndYellowYoshi_Peach(0xF0, 4 * ((misc_layer3_xspeed & 3) + 10), r0, r2);
    YoshisWatchInExcitementDuringEnding_0CA4E9();
  }
}

void YoshisWatchInExcitementDuringEnding_0CA4B6() {  // 0ca4b6
  uint8 r2;
  uint8 r0 = 24;
  r2 = -89;
  DrawLeaningEndingYoshis(0xC0, 4 * ((misc_layer3_xspeed & 3) - 1), r0, r2);
  r0 = -52;
  r2 = -89;
  DrawLeaningEndingYoshis(0xD8, 4 * ((misc_layer3_xspeed & 3) - 1 + 2), r0, r2);
  YoshisWatchInExcitementDuringEnding_0CA4E9();
}

void YoshisWatchInExcitementDuringEnding_0CA4E9() {  // 0ca4e9
  uint8 v0 = 2 * kYoshisWatchInExcitementDuringEnding_DATA_0CA439[misc_layer3_xspeed & 3];
  uint8 r0 = 80;
  uint8 r2 = -97;
  DrawCameraFacingEndingYoshis_BlueYoshi(0xF0, v0, 0, r0, r2);
  YoshisWatchInExcitementDuringEnding_0CA510(v0);
}

void YoshisWatchInExcitementDuringEnding_0CA510(uint8 j) {  // 0ca510
  uint8 r0 = spr_xpos_lo[0];
  uint8 r2 = -97;
  DrawCameraFacingEndingYoshis_BlueYoshi(0xB4, j, 1, r0, r2);
  WalkingIntoYoshisHouseDuringEnding_0CA1F6();
}

void HatchYoshiEggsDuringEnding() {  // 0ca532
  if ((uint8)misc_layer3_tide_sub_ypos)
    goto LABEL_5;
  sprites_cutscene_sprite_yspeed[3] = -104;
  sprites_cutscene_sprite_yspeed[4] = -104;
  sprites_cutscene_sprite_yspeed[5] = -44;
  sprites_cutscene_sprite_yspeed[6] = -44;
  uint8 v0 = HIBYTE(misc_layer3_yspeed);
  uint8 v1 = kHatchYoshiEggsDuringEnding_DATA_0CA52B[HIBYTE(misc_layer3_yspeed)] >> 4;
  LOBYTE(misc_layer3_tide_sub_ypos) = v1 + 1;
  sprites_cutscene_sprite_yspeed[v1 + 7] = -64;
  sprites_cutscene_sprite_table_0AF6[v1 + 7] = 4;
  sprites_cutscene_sprite_ypos_lo[3] = sprites_cutscene_sprite_ypos_lo[v1 + 7];
  sprites_cutscene_sprite_ypos_lo[4] = sprites_cutscene_sprite_ypos_lo[3];
  sprites_cutscene_sprite_ypos_lo[5] = sprites_cutscene_sprite_ypos_lo[3] + 8;
  sprites_cutscene_sprite_ypos_lo[6] = sprites_cutscene_sprite_ypos_lo[3] + 8;
  sprites_cutscene_sprite_ypos_hi[3] = 0;
  sprites_cutscene_sprite_ypos_hi[4] = 0;
  sprites_cutscene_sprite_ypos_hi[5] = 0;
  sprites_cutscene_sprite_ypos_hi[6] = 0;
  sprites_cutscene_sprite_xpos_lo[3] = sprites_cutscene_sprite_xpos_lo[v1 + 7];
  sprites_cutscene_sprite_xpos_lo[5] = sprites_cutscene_sprite_xpos_lo[3];
  sprites_cutscene_sprite_xpos_lo[4] = sprites_cutscene_sprite_xpos_lo[3] + 8;
  sprites_cutscene_sprite_xpos_lo[6] = sprites_cutscene_sprite_xpos_lo[3] + 8;
  sprites_cutscene_sprite_xpos_hi[3] = 0;
  sprites_cutscene_sprite_xpos_hi[4] = 0;
  sprites_cutscene_sprite_xpos_hi[5] = 0;
  sprites_cutscene_sprite_xpos_hi[6] = 0;
  LOBYTE(misc_layer3_yspeed) = kHatchYoshiEggsDuringEnding_DATA_0CA524[v0] | misc_layer3_yspeed;
  if (++HIBYTE(misc_layer3_yspeed) != 7) {
    io_sound_ch3 = 10;
LABEL_5:
    HatchYoshiEggsDuringEnding_0CA5DE();
    goto LABEL_6;
  }
  sprites_cutscene_sprite_xpos_hi[2] = 0;
  sprites_cutscene_sprite_xpos_lo[2] = 0x80;
  sprites_cutscene_sprite_xspeed[2] = 0;
  io_music_ch1 = 11;
  ++l1_l2_scroll_spr_current_state[0];
LABEL_6:
  YoshisWatchInExcitementDuringEnding_0CA4B6();
}

void HatchYoshiEggsDuringEnding_0CA5DE() {  // 0ca5de
  if ((uint8)misc_layer3_tide_sub_ypos) {
    for (uint8 i = 6; i != 2; --i) {
      if (sprites_cutscene_sprite_yspeed[i] != 106)
        sprites_cutscene_sprite_yspeed[i] += 6;
      sprites_cutscene_sprite_xspeed[i] = kHatchYoshiEggsDuringEnding_DATA_0CA5DA[(uint8)(i - 3)];
      UpdateCutsceneSpritePosition_Y(i);
      UpdateCutsceneSpritePosition_X(i);
    }
    if ((sprites_cutscene_sprite_ypos_lo[3] & 0xF0) == 0xF0)
      LOBYTE(misc_layer3_tide_sub_ypos) = 0;
    uint8 v1 = 0;
    for (uint8 j = 6; j != 2; --j) {
      if (!sprites_cutscene_sprite_xpos_hi[j] && !sprites_cutscene_sprite_ypos_hi[j] && sprites_cutscene_sprite_ypos_lo[j] < 0xF0) {
        OamEnt *oam = get_OamEnt(oam_buf, v1);
        oam->xpos = sprites_cutscene_sprite_xpos_lo[j];
        oam->ypos = sprites_cutscene_sprite_ypos_lo[j];
        uint8 v5 = j;
        uint8 v4 = j - 3;
        oam->charnum = kHatchYoshiEggsDuringEnding_DATA_0CA5D2[v4];
        oam->flags = kHatchYoshiEggsDuringEnding_DATA_0CA5D6[v4];
        j = v5;
        sprites_oamtile_size_buffer[v1 >> 2] = 0;
        v1 += 4;
      }
    }
  }
}

void SlideInThankYouDuringEnding() {  // 0ca65b
  sprites_cutscene_sprite_xspeed[2] -= 4;
  UpdateCutsceneSpritePosition_X(2);
  uint8 v0 = sprites_cutscene_sprite_xpos_lo[2];
  if (v0 >= 0xF8) {
    ++l1_l2_scroll_spr_current_state[0];
    HIBYTE(misc_layer3_tide_sub_ypos) = -16;
    v0 = 0;
  }
  DrawEndingThankYou_Entry2(0x50, 0, v0, v0, 63);
  --HIBYTE(misc_layer3_xspeed);
  if ((misc_layer3_xspeed & 0x8000) != 0) {
    HIBYTE(misc_layer3_xspeed) = 6;
    LOBYTE(misc_layer3_xspeed) = misc_layer3_xspeed - 1;
    if ((uint8)misc_layer3_xspeed == 7)
      LOBYTE(misc_layer3_xspeed) = 8;
  }
  YoshisWatchInExcitementDuringEnding_0CA478();
}

void EveryoneCheeringDuringEnding() {  // 0ca6b0
  uint8 r2;
  DrawEndingThankYou();
  ProcessCheeringYoshis();
  WalkingIntoYoshisHouseDuringEnding_0CA2FC();
  player_ypos = 352;
  yoshi_stray_yoshi_flag = 0;
  player_current_pose = 38;
  HandlePlayerPoseAndAnimationTimersDuringEnding_0CA764();
  SpawnEndingYoshiSpriteAndDrawPlayer_0CA7B4();
  uint8 v0 = 2 * kProcessCheeringYoshis_DATA_0CA311[(uint8)misc_layer3_xspeed];
  uint8 r0 = spr_xpos_lo[0];
  r2 = sprites_cutscene_sprite_ypos_lo[1];
  DrawCameraFacingEndingYoshis_BlueYoshi(0xB4, v0, 1, r0, r2);
  uint16 r0w = PAIR16(sprites_cutscene_sprite_xpos_hi[0], sprites_cutscene_sprite_xpos_lo[0]) + 16;
  r2 = -97;
  DrawCreditsPeachRedAndYellowYoshi_Peach(0xA4, 4 * (((uint8)(counter_global_frames & 8) >> 3) + 5), r0w, r2);
  if (!--HIBYTE(misc_layer3_tide_sub_ypos)) {
    ++misc_game_mode;
    HIBYTE(misc_layer3_yspeed) = 64;
  }
}

void UpdateCutsceneSpritePosition_Y(uint8 k) {  // 0ca721
  uint16 sub = sprites_cutscene_sprite_sub_ypos[k] + (uint8)(16 * sprites_cutscene_sprite_yspeed[k]);
  sprites_cutscene_sprite_sub_ypos[k] = sub;
  uint16 pos = PAIR16(sprites_cutscene_sprite_ypos_hi[k], sprites_cutscene_sprite_ypos_lo[k]) +
               ((int8)sprites_cutscene_sprite_yspeed[k] >> 4) + (sub >> 8);
  sprites_cutscene_sprite_ypos_lo[k] = pos;
  sprites_cutscene_sprite_ypos_hi[k] = pos >> 8;
}

void UpdateCutsceneSpritePosition_X(uint8 k) {  // 0ca74f
  UpdateCutsceneSpritePosition_Y(k + 15);
}

void HandlePlayerPoseAndAnimationTimersDuringEnding() {  // 0ca75a
  SetPlayerPose();
  HandlePlayerPoseAndAnimationTimersDuringEnding_0CA764();
}

void HandlePlayerPoseAndAnimationTimersDuringEnding_0CA764() {  // 0ca764
  player_current_layer_priority = 0;
  if (player_anim_timer)
    --player_anim_timer;
  if (timer_cape_flap_animation)
    --timer_cape_flap_animation;
}

void SpawnEndingYoshiSpriteAndDrawPlayer() {  // 0ca778
  spr_current_slotid = 0;
  spr_spriteid[0] = 53;
  uint8 v1 = spr_table1602[0];
  InitializeNormalSpriteRAMTables(0);
  spr_table1602[0] = v1;
  spr_table00c2[0] = 2;
  spr_table157c[0] = 1;
  uint16 t = scroll_spr_layer_index + 56;
  scroll_spr_layer_index = t;
  if (t >= 256 && ++spr_table1602[0] >= 3)
    spr_table1602[0] = 0;
  yoshi_stray_yoshi_flag = 1;
  SpawnEndingYoshiSpriteAndDrawPlayer_0CA7B4();
}

void SpawnEndingYoshiSpriteAndDrawPlayer_0CA7B4() {  // 0ca7b4
  PlayerDraw();
}

void DrawCreditsPeachRedAndYellowYoshi_Peach(uint8 k_in, uint8 j_in, uint16 r0w, uint8 r2) {  // 0ca821
  uint16 j = j_in;
  uint16 k = k_in;

  int16 v2 = k;
  if (j >= 0x28)
    k = k | 0x100;
  uint8 r4 = 1;
  do {
    if (r0w >= 256)
      break;
    uint8 r10 = 2;
    uint8 v3 = r0w;
    OamEnt *oam = get_OamEnt(oam_buf, k);
    oam[1].xpos = r0w;
    oam->xpos = v3 + 8;
    if (v3 >= 0xF8)
      r10 = 1;
    uint8 v5 = r2;
    oam->ypos = r2;
    oam[1].ypos = v5;
    oam[1].charnum = *((uint8 *)kDrawCreditsPeachRedAndYellowYoshi_DATA_0CA7B9 + j);
    oam->charnum = *((uint8 *)kDrawCreditsPeachRedAndYellowYoshi_DATA_0CA7B9 + j + 1);
    oam[1].flags = *((uint8 *)kDrawCreditsPeachRedAndYellowYoshi_DATA_0CA7ED + j);
    oam->flags = *((uint8 *)kDrawCreditsPeachRedAndYellowYoshi_DATA_0CA7ED + j + 1);
    r2 += 16;
    sprites_oamtile_size_buffer[(k >> 2) + 1] = 2;
    sprites_oamtile_size_buffer[k >> 2] = r10;
    k = k + 8;
    j = j + 2;
    --r4;
  } while ((r4 & 0x80) == 0);
}

void MakeCreditsEggsBounce(uint8 r14) {  // 0ca8a3
  for (uint8 i = 13; i != 6; --i) {
    sprites_cutscene_sprite_yspeed[i] += sprites_cutscene_sprite_table_0AF6[i];
    UpdateCutsceneSpritePosition_Y(i);
    if (sprites_cutscene_sprite_ypos_lo[i] >= r14) {
      sprites_cutscene_sprite_sub_ypos[i] = 0;
      sprites_cutscene_sprite_yspeed[i] = -10;
      sprites_cutscene_sprite_table_0AF6[i] = 1;
      sprites_cutscene_sprite_ypos_lo[i] = r14;
    }
  }
}

void DrawEndingBabyYoshis(uint8 r2) {  // 0ca8df
  uint8 r14 = misc_layer3_yspeed;
  for (uint8 i = 13; i != 6; --i) {
    if (!sprites_cutscene_sprite_xpos_hi[i]) {
      uint8 r0 = sprites_cutscene_sprite_xpos_lo[i];
      uint8 r1 = sprites_cutscene_sprite_ypos_lo[i];
      uint8 v1 = r2;
      OamEnt *oam = get_OamEnt(oam_buf, r2);
      oam->xpos = r0;
      oam->ypos = r1;
      int8 v3 = r14 & 1;
      r14 >>= 1;
      if (v3) {
        oam->charnum = -22;
        oam->flags = kDrawEndingBabyYoshis_BabyYoshiProp[(uint8)(i - 7)];
      } else {
        oam->charnum = -122;
        oam->flags = 33;
      }
      sprites_oamtile_size_buffer[v1 >> 2] = 2;
      r2 += 4;
    }
  }
}

void DrawLeaningEndingYoshis(uint8 k, uint8 j, uint8 r0, uint8 r2) {  // 0ca99e
  uint8 v2 = kDrawLeaningEndingYoshis_DATA_0CA99A[j >> 2];
  uint8 r4 = 2;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, k);
    oam->xpos = r0 + *((uint8 *)kDrawLeaningEndingYoshis_DATA_0CA96A + v2);
    oam[1].xpos = r0 + *((uint8 *)kDrawLeaningEndingYoshis_DATA_0CA96A + v2 + 1);
    oam->ypos = r2 + *((uint8 *)kDrawLeaningEndingYoshis_DATA_0CA982 + v2);
    oam[1].ypos = r2 + *((uint8 *)kDrawLeaningEndingYoshis_DATA_0CA982 + v2 + 1);
    oam->charnum = *((uint8 *)kDrawLeaningEndingYoshis_DATA_0CA93A + v2);
    oam[1].charnum = *((uint8 *)kDrawLeaningEndingYoshis_DATA_0CA93A + v2 + 1);
    oam->flags = *((uint8 *)kDrawLeaningEndingYoshis_DATA_0CA952 + v2);
    oam[1].flags = *((uint8 *)kDrawLeaningEndingYoshis_DATA_0CA952 + v2 + 1);
    uint8 v7 = v2;
    uint8 v6 = k;
    uint8 v4 = k >> 2;
    uint8 v5 = 2;
    if ((r4 & 2) == 0)
      v5 = 0;
    sprites_oamtile_size_buffer[v4] = v5;
    sprites_oamtile_size_buffer[v4 + 1] = v5;
    k = v6 + 8;
    v2 = v7 + 2;
  } while ((--r4 & 0x80) == 0);
}

void DrawCameraFacingEndingYoshis_BlueYoshi(uint8 k, uint8 j, uint8 r14, uint8 r0, uint8 r2) {  // 0caa15
  uint8 v2 = r14;
  OamEnt *oam = get_OamEnt(oam_buf, k);
  oam->flags = kDrawCameraFacingEndingYoshis_Prop[v2 * 2 + 0];
  oam[1].flags = kDrawCameraFacingEndingYoshis_Prop[v2 * 2 + 1];
  uint8 v4 = r0;
  oam->xpos = r0;
  oam[1].xpos = v4;
  uint8 v5 = r2;
  oam->ypos = r2;
  oam[1].ypos = v5 + 16;
  oam->charnum = *(kDrawCameraFacingEndingYoshis_Tiles + j);
  oam[1].charnum = *(kDrawCameraFacingEndingYoshis_Tiles + j + 1);
  uint8 v6 = k >> 2;
  sprites_oamtile_size_buffer[v6] = 2;
  sprites_oamtile_size_buffer[v6 + 1] = 2;
}

void DrawingTheEndMarioLuigiAndPeach() {  // 0caadf
  uint8 v0 = 0;
  uint8 v1 = 0;
  uint8 v3;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, v0);
    oam->xpos = kDrawingTheEndMarioLuigiAndPeach_TileData[v1];
    oam->ypos = kDrawingTheEndMarioLuigiAndPeach_TileData[v1 + 1];
    oam->charnum = kDrawingTheEndMarioLuigiAndPeach_TileData[v1 + 2];
    oam->flags = kDrawingTheEndMarioLuigiAndPeach_TileData[v1 + 3];
    v3 = v0;
    sprites_oamtile_size_buffer[v0 >> 2] = 2;
    v0 += 4;
    v1 = v0;
  } while (v3 != 0x88);
}

void CreditsFadeOut() {  // 0cab1f
  uint8 v0 = flag_message_window_size_change_direction;
  uint8 v1 = 51;
  mirror_bg1_and2_window_mask_settings = 51;
  if ((blocks_screen_to_place_current_object || flag_message_window_size_change_direction) &&
      (blocks_screen_to_place_current_object < 6 ||
       blocks_screen_to_place_current_object == 6 && !flag_message_window_size_change_direction)) {
    v1 = 48;
  }
  mirror_object_and_color_window_settings = v1;
  uint8 v2 = timer_wait_before_message_window_size_change;
  if (timer_wait_before_message_window_size_change != kCreditsFadeOut_DATA_0CAB1D[flag_message_window_size_change_direction])
    goto LABEL_12;
  if (flag_message_window_size_change_direction) {
    flag_message_window_size_change_direction = 0;
    if (blocks_screen_to_place_current_object >= 6) {
      ++misc_game_mode;
      goto LABEL_13;
    }
    uint8 v6 = timer_wait_before_message_window_size_change;
    ++flag_update_credits_background;
    ++blocks_screen_to_place_current_object;
    CreditsFadeOut_0CABB2();
    v0 = 0;
    v2 = v6;
LABEL_12:
    timer_wait_before_message_window_size_change = kCreditsFadeOut_DATA_0CAB1B[v0] + v2;
  }
LABEL_13:;
  uint8 v3 = 0;
  uint8 v4 = -32;
  int16 v5 = 255;
  do {
    if (v3 >= timer_wait_before_message_window_size_change)
      v5 = -256;
    *(uint16 *)&misc_hdmawindow_effect_table[v3] = v5;
    *(uint16 *)&misc_hdmawindow_effect_table[v4 + 222] = v5;
    v3 += 2;
    v4 -= 2;
  } while (v4);
  RtlPpuWrite(TMW, 0x13);
  RtlPpuWrite(TSW, 0x13);
  mirror_color_math_initial_settings = 34;
  mirror_hdmaenable = 0x80;
}

void CreditsFadeOut_0CABB2() {  // 0cabb2
  palettes_dynamic_palette_bytes_to_upload = 12;
  palettes_dynamic_palette_colors[12] = 12;
  palettes_dynamic_palette_cgramaddress = 2;
  palettes_dynamic_palette_colors[13] = 18;
  palettes_background_color = kGlobalPalettes_Sky[kCreditsFadeOut_SkyColorSetting[blocks_screen_to_place_current_object] & 0xF];
  const uint8 *p0 = (uint8*)(kGlobalPalettes_Background + (kCreditsFadeOut_BGPaletteSetting[blocks_screen_to_place_current_object] & 0xF) * 12);
  uint16 r4w = 0;
  uint16 n = 1;
  uint16 v0;
  do {
    v0 = r4w;
    for (int16 i = 5; i >= 0; --i) {
      *(uint16 *)&palettes_dynamic_palette_colors[v0] = WORD(p0[0]);
      p0 += 2;
      v0 += 2;
    }
    r4w += 14;
    --n;
  } while ((n & 0x8000) == 0);
  *(uint16 *)&palettes_dynamic_palette_colors[v0] = 0;
}

void GetLayer1And2PointersForEnemyRollcall() {  // 0cad8c
  int v1 = ++counter_enemy_rollcall_screen;

  ptr_layer1_data = kRollCallData_Layer1(v1).ptr;
  ptr_layer2_data = kRollCallData_Layer2(v1).ptr;
  ptr_layer2_is_bg = kRollCallData_Layer2_IsBg[v1];
}


static const uint16 kCreditsEnemyNames_SpecialWorld[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Pumpkin[] = {0xc152, 0x0d00, 0x3819, 0x381e, 0x3816, 0x3819, 0x3814, 0x3812, 0x3817, 0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Pidget[] = {0x2d53, 0x0b00, 0x3819, 0x3812, 0x380d, 0x3810, 0x3812, 0x381d, 0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused2[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_MaskKoopa[] = {0x2e53, 0x1500, 0x3816, 0x380a, 0x381c, 0x3814, 0x00fc, 0x3814, 0x3818, 0x3818, 0x3819, 0x380a, 0x381c, 0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused3[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused4[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused5[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused6[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused7[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused8[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused9[] = {0xffff};
static const uint16 kCreditsEnemyNames_SpecialWorld_Unused10[] = {0xffff};

static const uint16 * const kInitializeEnemyRollcallLayerPositions_SpecialWorldEnemyNamePtrs[13] = {
  kCreditsEnemyNames_SpecialWorld,
  kCreditsEnemyNames_SpecialWorld_Pumpkin,
  kCreditsEnemyNames_SpecialWorld_Pidget,
  kCreditsEnemyNames_SpecialWorld_Unused2,
  kCreditsEnemyNames_SpecialWorld_MaskKoopa,
  kCreditsEnemyNames_SpecialWorld_Unused3,
  kCreditsEnemyNames_SpecialWorld_Unused4,
  kCreditsEnemyNames_SpecialWorld_Unused5,
  kCreditsEnemyNames_SpecialWorld_Unused6,
  kCreditsEnemyNames_SpecialWorld_Unused7,
  kCreditsEnemyNames_SpecialWorld_Unused8,
  kCreditsEnemyNames_SpecialWorld_Unused9,
  kCreditsEnemyNames_SpecialWorld_Unused10,
};

void InitializeEnemyRollcallLayerPositions() {  // 0cadf6
  graphics_stripe_image_to_upload = 3 * counter_enemy_rollcall_screen - 40;
  uint8 v7 = counter_enemy_rollcall_screen;
  uint8 v6 = 2 * counter_enemy_rollcall_screen;
  LoadStripeImage();
  if ((ow_level_tile_settings[73] & 0x80) != 0) {
    const uint16 *r0w = kInitializeEnemyRollcallLayerPositions_SpecialWorldEnemyNamePtrs[counter_enemy_rollcall_screen];
    uint8 v0 = 0;
    uint8 v1 = stripe_image_upload;
    uint16 v3;
    do {
      const uint8 *v2 = (const uint8 *)&r0w[v0 >> 1];
      v3 = *(uint16 *)v2;
      *(uint16 *)&stripe_image_upload_data[v1] = v3;
      v0 += 2;
      v1 += 2;
    } while (v3 != 0xffff);
    stripe_image_upload = v1;
  }
  misc_hdmawindow_effect_table[3] = kInitializeEnemyRollcallLayerPositions_DATA_0CADB5[v7];
  misc_hdmawindow_effect_table[13] = misc_hdmawindow_effect_table[3];
  misc_hdmawindow_effect_table[23] = misc_hdmawindow_effect_table[3];
  misc_hdmawindow_effect_table[6] = -120 - kInitializeEnemyRollcallLayerPositions_DATA_0CADB5[v7];
  misc_hdmawindow_effect_table[16] = misc_hdmawindow_effect_table[6];
  misc_hdmawindow_effect_table[26] = misc_hdmawindow_effect_table[6];
  mirror_current_layer2_ypos = kInitializeEnemyRollcallLayerPositions_InitialLayer2YPos[v6 >> 1];
  if (counter_enemy_rollcall_screen == 12) {
    mirror_current_layer1_xpos = 0;
    mirror_current_layer2_xpos = 0;
    mirror_layer3_xpos = 0;
    PointU16 *pt = get_PointU16(misc_layer1_pos, 0);
    pt->x = 0;
    pt[1].x = 0;
    misc_layer3_xdisp = 0;
  } else {
    mirror_current_layer1_xpos = -256;
    mirror_layer3_xpos = -256;
    PointU16 *v5 = get_PointU16(misc_layer1_pos, 0);
    v5->x = 256;
    misc_layer3_xdisp = 256;
    mirror_current_layer2_xpos = -128;
    v5[1].x = 128;
  }
  *(uint16 *)((int8 *)&misc_layer3_yspeed + 1) = 255;
}

void GameMode25_ShowEnemyRollcallScreen_Sub() {  // 0caead
  uint16 v2;

  if (counter_enemy_rollcall_screen == 12) {
    --HIBYTE(misc_layer3_yspeed);
LABEL_7:
    if (!HIBYTE(misc_layer3_yspeed)) {
      ++misc_game_mode;
      if (counter_enemy_rollcall_screen != 12)
        misc_game_mode = 34;
    }
    goto LABEL_10;
  }
  PointU16 *pt = get_PointU16(misc_layer1_pos, 0);
  if (mirror_current_layer1_xpos == pt->x && *(uint16 *)((int8 *)&misc_layer3_yspeed + 1)) {
    --*(uint16 *)((int8 *)&misc_layer3_yspeed + 1);
    goto LABEL_10;
  }
  mirror_current_layer1_xpos += 2;
  mirror_layer3_xpos = mirror_current_layer1_xpos;
  uint16 v1 = pt->x - 2;
  pt->x = v1;
  misc_layer3_xdisp = v1;
  ++mirror_current_layer2_xpos;
  --pt[1].x;
  if ((pt->x & (uint8)mirror_current_layer1_xpos) == 0)
    goto LABEL_7;
LABEL_10:;
  uint8 v3 = 32;
  if (counter_enemy_rollcall_screen == 5)
    v3 = 48;
  uint8 r0 = v3;
  v2 = 2 * counter_enemy_rollcall_screen;
  uint16 v4 = kGameMode25_ShowEnemyRollcallScreen_EnemyRollcallSpriteDataPtrs[v2 >> 1];
  uint16 r1w = 127;
  int16 v5 = 508;
  while (1) {
    uint16 v9 = v5;
    uint16 x = mirror_current_layer1_xpos;
    if ((kGameMode25_ShowEnemyRollcallScreen_TileData[v4 + 3] & 0x20) != 0)
      x = get_PointU16(misc_layer1_pos, 0)->x;
    uint8 r4 = x >> 8;
    if (kGameMode25_ShowEnemyRollcallScreen_TileData[v4] == 0xFF)
      break;
    OamEnt *oam = get_OamEnt(oam_buf, v9);
    int t = kGameMode25_ShowEnemyRollcallScreen_TileData[v4] - (x & 0xff);
    oam->xpos = t;
    r4 = (0 - r4 - (t < 0)) & 1;
    sprites_oamtile_size_buffer[r1w] = r4 | ((uint8)(kGameMode25_ShowEnemyRollcallScreen_TileData[v4 + 3] & 0x10) >> 3);

    oam->ypos = kGameMode25_ShowEnemyRollcallScreen_TileData[v4 + 1];
    oam->charnum = kGameMode25_ShowEnemyRollcallScreen_TileData[v4 + 2];
    oam->flags = r0 | kGameMode25_ShowEnemyRollcallScreen_TileData[v4 + 3] & 0xCF;
    v5 = v9 - 4;
    v4 += 4;
    --BYTE(r1w);
  }
}

void DisplayCastleDestructionText() {  // 0cc94e
  if (l1_l2_scroll_spr_current_state[1]) {
    if ((--l1_l2_scroll_spr_current_state[1] & 0x1F) == 0) {
      uint8 r0;
      r0 = 8 * (misc_currently_active_boss_end_cutscene - 1);
      r0 |= (uint8)(l1_l2_scroll_spr_current_state[1] & 0xE0) >> 5;
      graphics_stripe_image_to_upload = 3 * r0 + 33;
    }
  }
}

void GameMode19_Cutscene_0CC97E() {  // 0cc97e
  DisplayCastleDestructionText();
  DrawThankYouSpeechBubble();
  GameMode19_Cutscene_ProcessCutscene();
}

void GameMode19_Cutscene_ProcessCutscene() {  // 0cc98c
  if ((counter_global_frames & 3) == 0) {
    PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
    if (HIBYTE(pt[1].y))
      --HIBYTE(pt[1].y);
  }
  CarryEggAwayFromCastle();
  kGameMode19_Cutscene_Ptrs0CC9A5[(uint8)(misc_currently_active_boss_end_cutscene - 1)]();
}

void GameMode19_Cutscene_IggyCutscene() {  // 0cc9b3
  DrawTNTFuseBox();
  RaiseFlagUpFromRubble();
  kGameMode19_Cutscene_Ptrs0CC9C0[l1_l2_scroll_spr_current_state[0]]();
}

void GameMode19_Cutscene_MortonCutscene() {  // 0cc9cc
  RaiseFlagUpFromRubble();
  kGameMode19_Cutscene_Ptrs0CC9D6[l1_l2_scroll_spr_current_state[0]]();
}

void GameMode19_Cutscene_RoyCutscene() {  // 0cc9e0
  DrawTNTFuseBox();
  RaiseFlagUpFromRubble();
  DrawPlayerCough_RoyCutscene();
  kGameMode19_Cutscene_Ptrs0CC9F0[l1_l2_scroll_spr_current_state[0]]();
}

void GameMode19_Cutscene_LudwigCutscene() {  // 0cca04
  DrawTNTFuseBox();
  if (!l1_l2_scroll_spr_current_state[0])
    l1_l2_scroll_spr_timer[1] = 4;
  if (l1_l2_scroll_spr_current_state[0] == 7)
    HandleFarawayCastleRocket_DrawSprite();
  kGameMode19_Cutscene_Ptrs0CCA1F[l1_l2_scroll_spr_current_state[0]]();
}

void GameMode19_Cutscene_LemmyCutscene() {  // 0cca2f
  DrawWoodHammer();
  RaiseFlagUpFromRubble();
  if (l1_l2_scroll_spr_current_state[0] != 3)
    SpawnHammerDebris();
  ProcessHammerDebris();
  kGameMode19_Cutscene_Ptrs0CCA49[l1_l2_scroll_spr_current_state[0]]();
}

void GameMode19_Cutscene_WendyCutscene() {  // 0cca51
  ProcessMop();
  if (l1_l2_scroll_spr_timer[0]) {
    uint8 r0 = -80;
    sprites_cutscene_sprite_xpos_lo[1] = 104;
    DrawWhiteFlag(0x30, r0);
  }
  kGameMode19_Cutscene_Ptrs0CCA6E[l1_l2_scroll_spr_current_state[0]]();
}

void GameMode19_Cutscene_LarryCutscene() {  // 0cca72
  kGameMode19_Cutscene_Ptrs0CCA79[l1_l2_scroll_spr_current_state[0]]();
}

void DrawThankYouSpeechBubble() {  // 0cca8f
  if (LOBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)[1].x)) {
    uint8 v0 = 0;
    uint8 v1 = 0;
    uint8 v3;
    do {
      OamEnt *oam = get_OamEnt(oam_buf, v1);
      oam[120].xpos = kDrawThankYouSpeechBubble_TileData[v0];
      oam[120].ypos = kDrawThankYouSpeechBubble_TileData[v0 + 1];
      oam[120].charnum = kDrawThankYouSpeechBubble_TileData[v0 + 2];
      oam[120].flags = kDrawThankYouSpeechBubble_TileData[v0 + 3] & 0xCF | 0x20;
      v3 = v1;
      sprites_oamtile_size_buffer[(v1 >> 2) + 120] = (uint8)(kDrawThankYouSpeechBubble_TileData[v0 + 3] & 0x10) >> 3;
      v1 += 4;
      v0 = v1;
    } while (v3 != 8);
  }
}

void RaiseFlagUpFromRubble() {  // 0ccace
  if (l1_l2_scroll_spr_current_state[0]) {
    if (l1_l2_scroll_spr_timer[0]) {
      if (sprites_cutscene_sprite_xpos_lo[1] >= 0x5C) {
        sprites_cutscene_sprite_xspeed[1] = -16;
        CopyOfUpdateCutsceneSpritePosition_X(1);
      }
      uint8 r0 = -85;
      DrawWhiteFlag(0x30, r0);
    }
  } else {
    l1_l2_scroll_spr_timer[0] = 0;
    sprites_cutscene_sprite_xpos_lo[1] = -104;
  }
}

void DrawWhiteFlag(uint8 k, uint8 r0) {  // 0ccafd
  OamEnt *oam = get_OamEnt(oam_buf, k);
  oam[96].xpos = r0;
  oam[96].ypos = sprites_cutscene_sprite_xpos_lo[1];
  oam[96].charnum = -26;
  oam[96].flags = 33;
  sprites_oamtile_size_buffer[(k >> 2) + 96] = 2;
}

void HandleTNTFuse() {  // 0ccb1c
  if (l1_l2_scroll_spr_spriteid[0]) {
    uint8 v0 = 48;
    if (misc_currently_active_boss_end_cutscene == 1)
      v0 = 24;
    sprites_cutscene_sprite_xspeed[0] = v0;
    CopyOfUpdateCutsceneSpritePosition_X(0);
    if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0) {
      l1_l2_scroll_spr_spriteid[1] = 1;
      l1_l2_scroll_spr_scroll_type_index[0] ^= 1;
    }
  } else {
    sprites_cutscene_sprite_xpos_lo[0] = 96;
    l1_l2_scroll_spr_spriteid[1] = 1;
    l1_l2_scroll_spr_scroll_type_index[0] = 0;
  }
  DrawCastleDestructionCastleDoor();
  HandleTNTFuse_TNTFuseAndLineDraw();
}

void DrawTNTFuseBox() {  // 0ccb5b
  int8 v0 = -32;
  if (l1_l2_scroll_spr_spriteid[0])
    v0 = -30;
  OamEnt *oam = get_OamEnt(oam_buf, 0);
  oam->charnum = v0;
  oam->flags = 57;
  oam->xpos = 80;
  oam->ypos = 103;
  sprites_oamtile_size_buffer[0] = 2;
}

void HandleTNTFuse_TNTFuseAndLineDraw() {  // 0ccb80
  uint8 v0 = 96;
  if (l1_l2_scroll_spr_spriteid[0])
    v0 = sprites_cutscene_sprite_xpos_lo[0];
  uint8 r0 = v0;
  uint8 r1 = 103;
  for (uint8 i = 20; i != 40; i += 4) {
    if (r0 < 0xB0) {
      OamEnt *oam = get_OamEnt(oam_buf, i);
      oam[96].xpos = r0;
      oam[96].ypos = r1;
      oam[96].charnum = -28;
      oam[96].flags = 63;
      sprites_oamtile_size_buffer[(i >> 2) + 96] = 2;
    }
    r0 += 16;
  }
  if (l1_l2_scroll_spr_spriteid[0]) {
    if ((uint8)(sprites_cutscene_sprite_xpos_lo[0] - 8) < 0xB0) {
      OamEnt *v3 = get_OamEnt(oam_buf, 0x28);
      v3[96].xpos = sprites_cutscene_sprite_xpos_lo[0] - 8;
      v3[96].ypos = 111;
      int8 v4 = -123;
      if (l1_l2_scroll_spr_scroll_type_index[0])
        v4 = -107;
      v3[96].charnum = v4;
      v3[96].flags = 53;
      sprites_oamtile_size_buffer[106] = 0;
    } else {
      ++l1_l2_scroll_spr_current_state[0];
    }
  }
}

void DrawCastleDestructionCastleDoor() {  // 0ccbfa
  sub_CCBFC(4);
}

void sub_CCBFC(uint8 k) {  // 0ccbfc
  uint8 r0 = -88;
  uint8 r2 = -88;
  uint8 r1 = 95;
  DrawCastleDestructionCastleDoor_Entry3(k, r0, r1, r2);
}

void DrawCastleDestructionCastleDoor_Entry3(uint8 k, uint8 r0, uint8 r1, uint8 r2) {  // 0ccc06
  uint8 v1 = 0;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, k);
    oam[96].xpos = r0;
    oam[96].ypos = r1;
    oam[96].charnum = kDrawCastleDestructionCastleDoor_Tiles[v1];
    oam[96].flags = 45;
    sprites_oamtile_size_buffer[(k >> 2) + 96] = 2;
    ++v1;
    r0 += 8;
    if ((v1 & 1) == 0) {
      r0 = r2;
      r1 += 8;
    }
    k += 4;
  } while (v1 != 4);
}

void HandleTNTExplosion() {  // 0ccc51
  palettes_background_color = kHandleTNTExplosion_DATA_0CCC4D[(uint8)(counter_global_frames & 2) >> 1];
  if ((--l1_l2_scroll_spr_scroll_type_index[1] & 0x80) == 0) {
    if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0) {
      l1_l2_scroll_spr_scroll_type_index[0] = (l1_l2_scroll_spr_scroll_type_index[0] + 1) & 3;
      l1_l2_scroll_spr_spriteid[1] = kHandleTNTExplosion_DATA_0CCC49[l1_l2_scroll_spr_scroll_type_index[0]];
    }
    HandleTNTExplosion_TNTExplosionDraw();
  } else {
    ClearCutsceneSpritesSubpixelPosition();
    palettes_background_color = kGlobalPalettes_Sky[kGameMode19_Cutscene_SkyColorSetting[misc_currently_active_boss_end_cutscene - 1]];
    ++l1_l2_scroll_spr_current_state[0];
  }
  sub_CCBFC(0x1C);
}

void HandleTNTExplosion_TNTExplosionDraw() {  // 0cccb6
  uint8 r8 = kHandleTNTExplosion_DATA_0CCCB1[(uint8)(l1_l2_scroll_spr_scroll_type_index[0] + 1)];
  uint8 v0 = -96;
  if (l1_l2_scroll_spr_scroll_type_index[0] == 0xFF)
    v0 = -88;
  uint8 r0 = v0;
  uint8 r4 = v0;
  uint8 r2 = 87;
  uint8 v1 = 0;
  do {
    uint8 v2 = kHandleTNTExplosion_DATA_0CCC9F[r8];
    if (v2) {
      OamEnt *oam = get_OamEnt(oam_buf, v1);
      oam[1].charnum = v2;
      int8 v4 = 53;
      if ((l1_l2_scroll_spr_scroll_type_index[0] & 0x80) == 0 && (l1_l2_scroll_spr_scroll_type_index[0] & 2) != 0)
        v4 = 57;
      oam[1].flags = v4;
      oam[1].xpos = r0;
      oam[1].ypos = r2;
      sprites_oamtile_size_buffer[(v1 >> 2) + 1] = 2;
    }
    ++r8;
    r0 += 16;
    v1 += 4;
    if (v1 == 12) {
      r0 = r4;
      r2 += 16;
    }
  } while (v1 != 24);
}

void HandleCastleCrumblingDown() {  // 0ccd23
  if ((uint8)mirror_current_layer1_ypos == 0xC0) {
    mirror_current_layer1_xpos = 0;
  } else {
    sprites_cutscene_sprite_ypos_hi[0] = HIBYTE(mirror_current_layer1_ypos);
    sprites_cutscene_sprite_ypos_lo[0] = mirror_current_layer1_ypos;
    sprites_cutscene_sprite_yspeed[0] = -16;
    CopyOfUpdateCutsceneSpritePosition_Y(0);
    ShakeCutsceneCastle();
    HIBYTE(mirror_current_layer1_ypos) = sprites_cutscene_sprite_ypos_hi[0];
    LOBYTE(mirror_current_layer1_ypos) = sprites_cutscene_sprite_ypos_lo[0];
    if (sprites_cutscene_sprite_ypos_lo[0] == 0xFD)
      l1_l2_scroll_spr_timer[0] = 1;
    if ((uint8)mirror_current_layer1_ypos == 0xE8)
      InitializeCastleDestructionTextTimers_DontIncrementCutsceneProcess();
    if ((uint8)mirror_current_layer1_ypos == 0xC0) {
      io_sound_ch1 = 34;
      HandleCastleCrumblingDown_DrawCastleRubble();
      sprites_cutscene_sprite_yspeed[1] = 8;
    }
  }
  if ((sprites_cutscene_sprite_yspeed[1] & 0x80) != 0) {
    if (sprites_cutscene_sprite_ypos_lo[1] < 0x68)
      goto LABEL_15;
    goto LABEL_14;
  }
  if (sprites_cutscene_sprite_ypos_lo[1] != 120) {
LABEL_14:
    CopyOfUpdateCutsceneSpritePosition_Y(1);
LABEL_15:
    sprites_cutscene_sprite_xspeed[0] = 4;
    CopyOfUpdateCutsceneSpritePosition_X(0);
    goto LABEL_16;
  }
  ++l1_l2_scroll_spr_current_state[0];
LABEL_16:
  HandleCastleLiftoff_0CCE2A();
}

void HandleCastleLiftoff() {  // 0ccda1
  if ((counter_global_frames & 3) == 0) {
    PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
    uint8 v1 = HIBYTE(pt->x) + 2;
    HIBYTE(pt->x) = v1;
    if (v1 >= 0x80)
      HIBYTE(pt->x) = 127;
  }
  uint16 v2 = mirror_current_layer1_ypos;
  sprites_cutscene_sprite_ypos_hi[0] = HIBYTE(v2);
  sprites_cutscene_sprite_ypos_lo[0] = v2;
  sprites_cutscene_sprite_yspeed[0] = HIBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)->x);
  CopyOfUpdateCutsceneSpritePosition_Y(0);
  if (sprites_cutscene_sprite_ypos_lo[0] <= 0x1F)
    ShakeCutsceneCastle();
  HIBYTE(mirror_current_layer1_ypos) = sprites_cutscene_sprite_ypos_hi[0];
  LOBYTE(mirror_current_layer1_ypos) = sprites_cutscene_sprite_ypos_lo[0];
  if (sprites_cutscene_sprite_ypos_lo[0] >= 0x20)
    sprites_cutscene_sprite_yspeed[1] = 8;
  if (sprites_cutscene_sprite_ypos_lo[0] < 0xA8) {
    if ((sprites_cutscene_sprite_yspeed[1] & 0x80) == 0) {
      if (sprites_cutscene_sprite_ypos_lo[1] >= 0x78)
        goto LABEL_15;
    } else if (sprites_cutscene_sprite_ypos_lo[1] < 0x68) {
      goto LABEL_15;
    }
    CopyOfUpdateCutsceneSpritePosition_Y(1);
    goto LABEL_15;
  }
  l1_l2_scroll_spr_spriteid[1] = 127;
  ++l1_l2_scroll_spr_current_state[0];
LABEL_15:
  sprites_cutscene_sprite_ypos_lo[2] = 119 - sprites_cutscene_sprite_ypos_lo[0];
  HandleCastleLiftoff_DrawCastleRocketFlame();
  HandleCastleLiftoff_0CCE2A();
}

void HandleCastleLiftoff_0CCE2A() {  // 0cce2a
  HandleCastleLiftoff_DrawCastleDust();
  uint8 r0 = -88;
  uint8 r2 = -88;
  uint8 r1 = 95 - sprites_cutscene_sprite_ypos_lo[0];
  DrawCastleDestructionCastleDoor_Entry3(0x14, r0, r1, r2);
}

void HandleCastleLiftoff_DrawCastleDust() {  // 0cce48
  if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0) {
    l1_l2_scroll_spr_spriteid[1] = 5;
    l1_l2_scroll_spr_scroll_type_index[0] ^= 1;
  }
  uint8 r0 = -104;
  uint8 v0 = 33;
  if (l1_l2_scroll_spr_scroll_type_index[0])
    v0 = 97;
  uint8 r4 = v0;
  uint8 v1 = 4 * l1_l2_scroll_spr_scroll_type_index[0];
  uint8 v2 = 0;
  uint8 v4;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam[1].xpos = r0;
    oam[1].ypos = sprites_cutscene_sprite_ypos_lo[1];
    oam[1].charnum = kHandleCastleLiftoff_CastleDustTiles[v1];
    oam[1].flags = r4;
    v4 = v2;
    sprites_oamtile_size_buffer[(v2 >> 2) + 1] = 2;
    r0 += 16;
    ++v1;
    v2 += 4;
  } while (v4 != 12);
}

void HandleCastleLiftoff_DrawCastleRocketFlame() {  // 0cceab
  OamEnt *oam = get_OamEnt(oam_buf, 0x30);
  oam->xpos = -80;
  oam->ypos = sprites_cutscene_sprite_ypos_lo[2];
  uint8 v1 = (uint8)(counter_global_frames & 6) >> 1;
  oam->charnum = kHandleCastleLiftoff_RocketFlameTiles[v1];
  oam->flags = kHandleCastleLiftoff_RocketFlameProp[v1];
  sprites_oamtile_size_buffer[12] = 2;
}

void HandleFarawayCastleRocket() {  // 0ccee2
  if (l1_l2_scroll_spr_scroll_type_index[0] >= 2) {
LABEL_7:
    if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0) {
      PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
      uint8 v1 = HIBYTE(pt->x) + 1;
      HIBYTE(pt->x) = v1;
      l1_l2_scroll_spr_scroll_type_index[0] = kHandleFarawayCastleRocket_DATA_0CCED4[v1];
      l1_l2_scroll_spr_spriteid[1] = kHandleFarawayCastleRocket_DATA_0CCEDB[v1];
      if (v1 == 1)
        io_sound_ch1 = 8;
      if (v1 == 6)
        InitializeCastleDestructionTextTimers();
    }
    goto LABEL_12;
  }
  if ((counter_global_frames & 1) != 0)
    l1_l2_scroll_spr_scroll_type_index[0] ^= 1;
  CopyOfUpdateCutsceneSpritePosition_Y(2);
  CopyOfUpdateCutsceneSpritePosition_X(2);
  if (sprites_cutscene_sprite_ypos_lo[2] >= 0x5C) {
    l1_l2_scroll_spr_scroll_type_index[0] = 2;
    goto LABEL_7;
  }
LABEL_12:
  HandleFarawayCastleRocket_DrawSprite();
}

void HandleFarawayCastleRocket_DrawSprite() {  // 0ccf49
  uint8 v0 = l1_l2_scroll_spr_scroll_type_index[0];
  if (l1_l2_scroll_spr_scroll_type_index[0] != 0xFF) {
    OamEnt *oam = get_OamEnt(oam_buf, 4);
    oam->xpos = sprites_cutscene_sprite_xpos_lo[2];
    oam->ypos = sprites_cutscene_sprite_ypos_lo[2];
    oam->charnum = kHandleFarawayCastleRocket_Tiles[v0];
    oam->flags = kHandleFarawayCastleRocket_Prop[v0];
    sprites_oamtile_size_buffer[1] = 0;
  }
}

void HandleDudTNTExplosion() {  // 0ccf72
  if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0 &&
      (l1_l2_scroll_spr_spriteid[1] = 3, ++l1_l2_scroll_spr_scroll_type_index[0], l1_l2_scroll_spr_scroll_type_index[0] == 4)) {
    ++l1_l2_scroll_spr_current_state[0];
    HandleDudTNTExplosion_0CCF90();
  } else {
    HandleDudTNTExplosion_DrawDudTNTExplosion(4);
    HandleDudTNTExplosion_0CCF90();
  }
}

void HandleDudTNTExplosion_0CCF90() {  // 0ccf90
  uint8 r0 = -88;
  uint8 r2 = -88;
  uint8 r1 = 95;
  DrawCastleDestructionCastleDoor_Entry3(8, r0, r1, r2);
}

void HandleDudTNTExplosion_DrawDudTNTExplosion(uint8 k) {  // 0ccfa3
  uint8 v1 = kHandleDudTNTExplosion_TilesAndProp[l1_l2_scroll_spr_scroll_type_index[0]];
  OamEnt *oam = get_OamEnt(oam_buf, k);
  oam->charnum = v1;
  oam->flags = v1;
  oam->xpos = -84;
  oam->ypos = 99;
  sprites_oamtile_size_buffer[k >> 2] = 2;
}

void DelayTNTExplosionUntilPlayerComesBy() {  // 0ccfc5
  if (l1_l2_scroll_spr_timer[1] == 3) {
    if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0)
      ++l1_l2_scroll_spr_current_state[0];
  } else {
    l1_l2_scroll_spr_spriteid[1] = 8;
  }
  HandleDudTNTExplosion_0CCF90();
}

void CheckIfPlayerCanEndCastleDestructionCutscene() {  // 0ccfde
  if (!(HIBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)[1].y) | l1_l2_scroll_spr_current_state[1]) &&
      ((io_controller_press2 | io_controller_press1) & 0xC0) != 0) {
    l1_l2_scroll_spr_current_state[0] = 0;
    misc_game_mode = 11;
  }
}

void WaitForCastleDestructionTextToFinishInRoyCutscene() {  // 0ccff7
  if (l1_l2_scroll_spr_current_state[1]) {
    ++l1_l2_scroll_spr_current_state[0];
    CheckIfPlayerCanEndCastleDestructionCutscene();
  }
}

void PlayerDropkicksAndStompsCastle() {  // 0cd003
  if (l1_l2_scroll_spr_spriteid[0] == 1) {
    l1_l2_scroll_spr_spriteid[1] = 63;
    l1_l2_scroll_spr_spriteid[0] = 3;
LABEL_10:
    if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0)
      ++l1_l2_scroll_spr_current_state[0];
    goto LABEL_12;
  }
  if (l1_l2_scroll_spr_spriteid[0] != 2) {
    if (l1_l2_scroll_spr_spriteid[0] != 3) {
      l1_l2_scroll_spr_spriteid[1] = 16;
      goto LABEL_12;
    }
    goto LABEL_10;
  }
  if ((l1_l2_scroll_spr_spriteid[1] & 0xF8) != 0)
    DrawCutsceneContactEffect();
  ShakeCutsceneCastle();
  if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0) {
    l1_l2_scroll_spr_spriteid[0] = 0;
    mirror_current_layer1_xpos = 0;
  }
LABEL_12:;
  uint8 v0 = -88;
  if ((uint8)mirror_current_layer1_xpos) {
    if ((mirror_current_layer1_xpos & 0x80) == 0)
      v0 = -89;
    else
      v0 = -87;
  }
  uint8 r0 = v0;
  uint8 r2 = v0;
  uint8 r1 = 95;
  DrawCastleDestructionCastleDoor_Entry3(8, r0, r1, r2);
}

void DrawCutsceneContactEffect() {  // 0cd069
  uint8 v0 = 0;
  uint8 v1 = 4;
  uint8 r0 = player_xpos + 16;
  uint8 r2 = player_xpos + 16;
  uint8 r1 = player_ypos + 16;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam->xpos = r0;
    oam->ypos = r1;
    oam->charnum = kDrawCutsceneContactEffect_Tiles[v0];
    oam->flags = kDrawCutsceneContactEffect_Prop[v0];
    sprites_oamtile_size_buffer[v1 >> 2] = 0;
    r0 += 8;
    if (++v0 == 2) {
      r0 = r2;
      r1 += 8;
    }
    v1 += 4;
  } while (v0 != 4);
}

void WaitBeforeMakingHammeredCastleCrumble() {  // 0cd0bc
  if (l1_l2_scroll_spr_spriteid[0] == 1)
    ++l1_l2_scroll_spr_current_state[0];
  HandleDudTNTExplosion_0CCF90();
}

void WaitForWendysCastleToBeFullyMopped() {  // 0cd0c9
  if (l1_l2_scroll_spr_spriteid[0])
    InitializeCastleDestructionTextTimers();
}

void UprootCastleFromGround() {  // 0cd0d2
  if (l1_l2_scroll_spr_spriteid[0] == 1) {
    sprites_cutscene_sprite_ypos_hi[0] = HIBYTE(mirror_current_layer1_ypos);
    sprites_cutscene_sprite_ypos_lo[0] = mirror_current_layer1_ypos;
    sprites_cutscene_sprite_yspeed[0] = 8;
    CopyOfUpdateCutsceneSpritePosition_Y(0);
    if (sprites_cutscene_sprite_ypos_lo[0] < 9) {
      LOBYTE(mirror_current_layer1_ypos) = sprites_cutscene_sprite_ypos_lo[0];
      HIBYTE(mirror_current_layer1_ypos) = sprites_cutscene_sprite_ypos_hi[0];
    } else {
      ++l1_l2_scroll_spr_current_state[0];
      HIBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)->x) = 40;
    }
  }
}

void KickCastleAway() {  // 0cd108
  if (l1_l2_scroll_spr_spriteid[0] == 2) {
    PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
    if ((int8)--HIBYTE(pt->x) >= 36)
      DrawCutsceneContactEffect();
    if (HIBYTE(pt->x) == 0xC8) {
      l1_l2_scroll_spr_spriteid[1] = 64;
      io_sound_ch3 = 26;
      ++l1_l2_scroll_spr_current_state[0];
    } else {
      sprites_cutscene_sprite_ypos_hi[0] = HIBYTE(mirror_current_layer1_ypos);
      sprites_cutscene_sprite_ypos_lo[0] = mirror_current_layer1_ypos;
      sprites_cutscene_sprite_xpos_hi[0] = HIBYTE(mirror_current_layer1_xpos);
      sprites_cutscene_sprite_xpos_lo[0] = mirror_current_layer1_xpos;
      sprites_cutscene_sprite_yspeed[0] = HIBYTE(pt->x);
      sprites_cutscene_sprite_xspeed[0] = -24;
      CopyOfUpdateCutsceneSpritePosition_Y(0);
      CopyOfUpdateCutsceneSpritePosition_X(0);
      LOBYTE(mirror_current_layer1_ypos) = sprites_cutscene_sprite_ypos_lo[0];
      HIBYTE(mirror_current_layer1_ypos) = sprites_cutscene_sprite_ypos_hi[0];
      LOBYTE(mirror_current_layer1_xpos) = sprites_cutscene_sprite_xpos_lo[0];
      HIBYTE(mirror_current_layer1_xpos) = sprites_cutscene_sprite_xpos_hi[0];
    }
  }
}

void KickedCastleCreatesQuake() {  // 0cd16f
  if ((counter_global_frames & 2) != 0)
    --mirror_current_layer2_ypos;
  else
    ++mirror_current_layer2_ypos;
  if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0) {
    mirror_current_layer2_ypos = 0;
    ++l1_l2_scroll_spr_current_state[0];
  }
}

void WaitForPlayerVictoryPoseAfterCastleQuake() {  // 0cd19c
  if (l1_l2_scroll_spr_spriteid[0] == 3)
    InitializeCastleDestructionTextTimers();
}

void HandleCastleCrumblingDown_DrawCastleRubble() {  // 0cd1d0
  int8 v0 = 40;
  uint8 v1 = stripe_image_upload + 40;
  do
    stripe_image_upload_data[v1--] = kHandleCastleCrumblingDown_RubbleTiles[(uint8)v0--];
  while (v0 >= 0);
  LOBYTE(stripe_image_upload) = stripe_image_upload + 40;
}

void ProcessMop_EraseColumn() {  // 0cd22d
  uint8 r1 = stripe_image_upload;
  int8 v0 = 12;
  uint8 v1 = stripe_image_upload + 12;
  do
    stripe_image_upload_data[v1--] = kProcessMop_DATA_0CD1F0[(uint8)v0--];
  while (v0 >= 0);
  LOBYTE(stripe_image_upload) = stripe_image_upload + 12;
  uint8 r0 = player_xpos + 96;
  uint8 v2 = player_xpos + 96 + ((uint8)(LOBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)->x) - 56) >> 2);
  int v3 = v2 >> 1;
  int v4 = r1;
  *(uint16 *)&stripe_image_upload_data[r1] = kProcessMop_DATA_0CD1FD[v3];
  *(uint16 *)&stripe_image_upload_data[v4 + 6] = kProcessMop_DATA_0CD1FD[v3 + 1];
  if (v2 == 28)
    l1_l2_scroll_spr_timer[0] = 1;
}

void ShakeCutsceneCastle() {  // 0cd283
  if ((counter_global_frames & 1) != 0)
    ++mirror_current_layer1_xpos;
  else
    --mirror_current_layer1_xpos;
}

void InitializeTNTExplosion() {  // 0cd295
  io_sound_ch3 = 26;
  l1_l2_scroll_spr_scroll_type_index[0] = -1;
  l1_l2_scroll_spr_scroll_type_index[1] = 48;
  l1_l2_scroll_spr_spriteid[1] = 1;
  ++l1_l2_scroll_spr_current_state[0];
  DrawCastleDestructionCastleDoor();
  HandleTNTExplosion();
}

void InitializeCastleCrumblingDown() {  // 0cd2b2
  io_sound_ch1 = 33;
  InitializeCastleDust();
  HandleCastleCrumblingDown();
}

void InitializeCastleLiftoff() {  // 0cd2bd
  io_sound_ch3 = 23;
  sprites_cutscene_sprite_ypos_lo[2] = 119;
  HIBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)->x) = 0;
  InitializeCastleDust();
  HandleCastleLiftoff();
}

void InitializeDudTNTExplosion() {  // 0cd2d0
  l1_l2_scroll_spr_spriteid[1] = 3;
  l1_l2_scroll_spr_scroll_type_index[0] = 0;
  io_sound_ch3 = 25;
  ++l1_l2_scroll_spr_current_state[0];
  DrawCastleDestructionCastleDoor();
  HandleDudTNTExplosion();
}

void InitializeFarawayCastleRocket() {  // 0cd2e6
  if ((--l1_l2_scroll_spr_spriteid[1] & 0x80) != 0) {
    ClearCutsceneSpritesSubpixelPosition();
    sprites_cutscene_sprite_ypos_lo[2] = 15;
    sprites_cutscene_sprite_ypos_hi[2] = 0;
    sprites_cutscene_sprite_xpos_lo[2] = -112;
    sprites_cutscene_sprite_xpos_hi[2] = 0;
    sprites_cutscene_sprite_yspeed[2] = 8;
    sprites_cutscene_sprite_xspeed[2] = -1;
    l1_l2_scroll_spr_spriteid[1] = 2;
    l1_l2_scroll_spr_scroll_type_index[0] = 0;
    HIBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)->x) = 0;
    ++l1_l2_scroll_spr_current_state[0];
    HandleFarawayCastleRocket();
  }
}

void InitializeCastleDust() {  // 0cd31a
  sprites_cutscene_sprite_ypos_lo[1] = 119;
  sprites_cutscene_sprite_xpos_lo[0] = 95;
  sprites_cutscene_sprite_yspeed[1] = -8;
  l1_l2_scroll_spr_scroll_type_index[0] = 0;
  l1_l2_scroll_spr_spriteid[1] = 5;
  ++l1_l2_scroll_spr_current_state[0];
  ClearCutsceneSpritesSubpixelPosition();
  DrawCastleDestructionCastleDoor();
}

void CopyOfUpdateCutsceneSpritePosition_Y(uint8 k) {  // 0cd33a
  uint16 sub = sprites_cutscene_sprite_sub_ypos[k] + (uint8)(16 * sprites_cutscene_sprite_yspeed[k]);
  sprites_cutscene_sprite_sub_ypos[k] = sub;
  uint16 pos = PAIR16(sprites_cutscene_sprite_ypos_hi[k], sprites_cutscene_sprite_ypos_lo[k]) + (sub >> 8) +
               ((int8)sprites_cutscene_sprite_yspeed[k] >> 4);
  sprites_cutscene_sprite_ypos_lo[k] = pos;
  sprites_cutscene_sprite_ypos_hi[k] = pos >> 8;
}

void CopyOfUpdateCutsceneSpritePosition_X(uint8 k) {  // 0cd368
  CopyOfUpdateCutsceneSpritePosition_Y(k + 15);
}

void ClearCutsceneSpritesSubpixelPosition() {  // 0cd373
  sprites_cutscene_sprite_sub_ypos[0] = 0;
  sprites_cutscene_sprite_sub_xpos[0] = 0;
  sprites_cutscene_sprite_sub_ypos[1] = 0;
  sprites_cutscene_sprite_sub_xpos[1] = 0;
  sprites_cutscene_sprite_sub_xpos[2] = 0;
}

void SpawnHammerDebris() {  // 0cd3a6
  if ((uint8)(l1_l2_scroll_spr_timer[1] - 1) < 0xE7 && (counter_global_frames & 1) == 0) {
    uint8 v0 = 14;
    while (cutscene_spr_hammer_debris_current_status[v0]) {
      if (--v0 == 3)
        return;
    }
    cutscene_spr_hammer_debris_current_status[v0] = 1;
    cutscene_spr_hammer_debris_yacceleration[v0] = 4;
    sprites_cutscene_sprite_yspeed[v0] = kSpawnHammerDebris_YSpeed[v0];
    sprites_cutscene_sprite_xspeed[v0] = kSpawnHammerDebris_XSpeed[v0];
    sprites_cutscene_sprite_xpos_lo[v0] = player_xpos + 24;
    sprites_cutscene_sprite_ypos_lo[v0] = player_ypos + 32;
    if ((counter_global_frames & 2) == 0)
      io_sound_ch3 = 7;
  }
}

void ProcessHammerDebris() {  // 0cd3f4
  for (uint8 i = 14; i != 3; --i) {
    if (cutscene_spr_hammer_debris_current_status[i]) {
      int8 v1 = sprites_cutscene_sprite_yspeed[i];
      if (v1 <= 63)
        sprites_cutscene_sprite_yspeed[i] = cutscene_spr_hammer_debris_yacceleration[i] + v1;
      CopyOfUpdateCutsceneSpritePosition_Y(i);
      CopyOfUpdateCutsceneSpritePosition_X(i);
      if (sprites_cutscene_sprite_ypos_lo[i] >= 0x80)
        cutscene_spr_hammer_debris_current_status[i] = 0;
    }
  }
  uint8 v2 = 14;
  uint8 v3 = 20;
  do {
    if (cutscene_spr_hammer_debris_current_status[v2]) {
      if (sprites_cutscene_sprite_xpos_lo[v2] >= 0x50) {
        OamEnt *oam = get_OamEnt(oam_buf, v3);
        oam->xpos = sprites_cutscene_sprite_xpos_lo[v2];
        oam->ypos = sprites_cutscene_sprite_ypos_lo[v2];
        oam->charnum = kProcessHammerDebris_DATA_0CD423[(uint8)(counter_global_frames & 2) >> 1];
        oam->flags = 34;
        sprites_oamtile_size_buffer[v3 >> 2] = 0;
      }
    }
    v3 += 4;
    --v2;
  } while (v2 != 3);
}

void DrawQuestionMark() {  // 0cd4a4
  uint8 v0 = 0;
  if (!player_current_power_up)
    v0 = 8;
  uint8 r2 = v0;
  uint8 v1 = 64;
  uint8 r0 = 2;
  uint8 v2 = 4 * l1_l2_scroll_spr_timer[1];
  do {
    if (kDrawQuestionMark_XDisp[v2] != 0x80) {
      OamEnt *oam = get_OamEnt(oam_buf, v1);
      oam->xpos = player_xpos + kDrawQuestionMark_XDisp[v2];
      oam->ypos = r2 + player_ypos + kDrawQuestionMark_YDisp[v2];
      oam->charnum = -74;
      oam->flags = 49;
      sprites_oamtile_size_buffer[v1 >> 2] = 0;
      v1 += 4;
    }
    ++v2;
    --r0;
  } while ((r0 & 0x80) == 0);
}

void DrawPlayerCough_RoyCutscene() {  // 0cd4f8
  PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
  if (LOBYTE(pt->x)) {
    sprites_cutscene_sprite_yspeed[2] = -3;
    CopyOfUpdateCutsceneSpritePosition_Y(2);
    if ((uint8)-sprites_cutscene_sprite_ypos_lo[2] < 0xD) {
      uint8 v1 = 0;
      if (!player_current_power_up)
        v1 = 8;
      uint8 r0 = v1;
      OamEnt *oam = get_OamEnt(oam_buf, 0x34);
      oam->xpos = player_xpos + 4;
      oam->ypos = r0 + player_ypos + sprites_cutscene_sprite_ypos_lo[2];
      oam->charnum = kDrawPlayerCough_Tiles[(uint8)-sprites_cutscene_sprite_ypos_lo[2] >> 2];
      oam->flags = 51;
      sprites_oamtile_size_buffer[13] = 0;
    } else {
      LOBYTE(pt->x) = 0;
    }
  } else {
    sprites_cutscene_sprite_ypos_lo[2] = 0;
  }
}

void DrawPlayerCough_MortonCutscene() {  // 0cd557
  PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
  if (LOBYTE(pt->x)) {
    sprites_cutscene_sprite_xspeed[3] = 6;
    sprites_cutscene_sprite_yspeed[3] = 1;
    CopyOfUpdateCutsceneSpritePosition_Y(3);
    CopyOfUpdateCutsceneSpritePosition_X(3);
    if (sprites_cutscene_sprite_xpos_lo[3] < 0xD) {
      uint8 v1 = 15;
      if (!player_current_power_up)
        v1 = 19;
      uint8 r0 = v1;
      OamEnt *oam = get_OamEnt(oam_buf, 0x34);
      oam->xpos = player_xpos + sprites_cutscene_sprite_xpos_lo[3] + 12;
      oam->ypos = r0 + player_ypos + sprites_cutscene_sprite_ypos_lo[3];
      oam->charnum = kDrawPlayerCough_Tiles[sprites_cutscene_sprite_xpos_lo[3] >> 2];
      oam->flags = 51;
      sprites_oamtile_size_buffer[13] = 0;
    } else {
      LOBYTE(pt->x) = 0;
      ++l1_l2_scroll_spr_current_state[0];
    }
  } else {
    sprites_cutscene_sprite_ypos_lo[3] = 0;
    sprites_cutscene_sprite_xpos_lo[3] = 0;
  }
}

void InitializeCastleDestructionTextTimers() {  // 0cd5c6
  ++l1_l2_scroll_spr_current_state[0];
  InitializeCastleDestructionTextTimers_DontIncrementCutsceneProcess();
}

void InitializeCastleDestructionTextTimers_DontIncrementCutsceneProcess() {  // 0cd5c9
  l1_l2_scroll_spr_current_state[1] = -1;
  HIBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)[1].y) = -48;
  io_music_ch1 = 19;
}

void DrawWoodHammer() {  // 0cd65b
  uint8 v1;
  if (LOBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)[1].x) >> 1) {
    uint8 v0 = l1_l2_scroll_spr_timer[1];
    if (l1_l2_scroll_spr_timer[1]) {
      --l1_l2_scroll_spr_timer[1];
      if (v0 >= 0xF0)
        v0 = 15;
      v1 = (v0 & 0xF) + 3;
      player_current_pose = kDrawWoodHammer_HammerSwingPlayerPoses[v1 - 3];
    } else {
      v1 = player_walking_frame;
    }
    uint8 v2 = 0;
    uint8 v3 = kDrawWoodHammer_Tiles[v1];
    int8 v4 = v3 & 1;
    int8 v5 = v3 >> 1;
    if (v4)
      v2 = 48;
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam[63].charnum = 2 * v5;
    int8 v7 = 0;
    if (player_facing_direction & 1)
      v7 = 0x80;
    oam[63].flags = kDrawWoodHammer_Prop[v1] ^ ((uint8)((player_facing_direction >> 2) + v7) >> 1);
    uint8 v8 = 2 * v1;
    if (player_current_power_up)
      ++v8;
    oam[63].ypos = kDrawWoodHammer_YDisp[v8] + player_ypos;
    uint8 v9 = kDrawWoodHammer_XDisp[v8];
    if (!player_facing_direction)
      v9 = -v9;
    oam[63].xpos = player_xpos + v9;
    sprites_oamtile_size_buffer[(v2 >> 2) + 63] = 2;
  }
}

void ProcessMop() {  // 0cd6ec
  if (!(LOBYTE(get_PointU16(l1_l2_scroll_spr_speed, 0)[1].x) >> 1))
    return;
  for (int8 i = 4; i >= 0; --i)
    sprites_oamtile_size_buffer[(uint8)i + 80] = 2;
  PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
  if (!LOBYTE(pt->x)) {
    uint8 v2 = 2 * player_walking_frame;
    if (player_current_power_up)
      ++v2;
    uint8 r0 = kProcessMop_DATA_0CD6C4[v2];
    uint8 r1 = kProcessMop_DATA_0CD6CA[v2];
    int8 v3 = 0;
    if (player_facing_direction & 1)
      v3 = 0x80;
    uint8 r2 = ((uint8)((player_facing_direction >> 2) + v3) >> 1) ^ 0x61;
    for (uint8 j = 2; (j & 0x80) == 0; --j) {
      int8 v5 = kProcessMop_DATA_0CD6D0[j] + r0;
      if ((r2 & 0x40) != 0)
        v5 = -v5;
      OamEnt *oam = get_OamEnt(oam_buf, (uint8)(4 * j));
      oam[80].xpos = player_xpos + v5;
      oam[80].ypos = player_ypos + kProcessMop_DATA_0CD6D3[j] + r1;
      oam[80].charnum = kProcessMop_Tiles[j];
      oam[80].flags = r2;
    }
    return;
  }
  if ((pt->x & 7) == 0)
    ProcessMop_EraseColumn();
  uint8 v7 = 37;
  uint8 x = get_PointU16(l1_l2_scroll_spr_speed, 0)->x;
  if (x >= 0x4C)
    v7 = 56;
  player_current_pose = v7;
  uint8 v9 = 0;
  uint8 r0 = x - 1;
  int8 v10 = -84;
  do {
    OamEnt *v11 = get_OamEnt(oam_buf, v9);
    v11[80].charnum = v10;
    v11[80].flags = 33;
    v11[80].xpos = player_xpos;
    uint8 v12 = r0;
    v11[80].ypos = r0;
    uint8 v13 = v12 + 16;
    if (v13 >= 0x68)
      v13 = 104;
    r0 = v13;
    v9 += 4;
    v10 = -82;
  } while (v9 < 0x14);
  uint8 v14 = l1_l2_scroll_spr_timer[1];
  PointU16 *v15 = get_PointU16(l1_l2_scroll_spr_speed, 0);
  if (LOBYTE(v15->x) != kProcessMop_DATA_0CD6E0[l1_l2_scroll_spr_timer[1]]) {
    LOBYTE(v15->x) += kProcessMop_DATA_0CD6D9[l1_l2_scroll_spr_timer[1]];
    goto LABEL_38;
  }
  if (HIBYTE(v15->y)) {
    --HIBYTE(v15->y);
    return;
  }
  if (l1_l2_scroll_spr_timer[1] && !(l1_l2_scroll_spr_timer[1] & 1)) {
    if ((counter_global_frames & 4) != 0)
      player_current_pose = 57;
    int8 v16 = player_xpos;
    if ((uint8)player_xpos != kProcessMop_DATA_0CD6E5[l1_l2_scroll_spr_timer[1]]) {
      LOBYTE(player_xpos) = player_xpos + 1;
      if (((v16 + 1) & 0xF) != 0)
        return;
LABEL_38:
      HIBYTE(v15->y) = 16;
      return;
    }
  }
  ++l1_l2_scroll_spr_timer[1];
  if (v14 < 6) {
    if (!(v14 & 1))
      io_sound_ch1 = 15;
  } else {
    LOBYTE(v15->x) = 0;
  }
}

void CarryEggAwayFromCastle() {  // 0cd803
  uint8 v2;

  PointU16 *pt = get_PointU16(l1_l2_scroll_spr_speed, 0);
  if (LOBYTE(pt[1].x)) {
LABEL_10:
    if ((uint8)player_xpos > 5)
      goto LABEL_13;
    LOBYTE(player_xpos) = 5;
    if ((player_xspeed & 0x80) != 0)
      goto LABEL_13;
    goto LABEL_12;
  }
  if (timer_display_player_pick_up_pose) {
    if (timer_display_player_pick_up_pose >> 1)
      goto LABEL_14;
LABEL_12:
    ++LOBYTE(pt[1].x);
LABEL_13:
    ++HIBYTE(pt[1].x);
LABEL_14:
    v2 = kCarryEggAwayFromCastle_YDisp[HIBYTE(pt[1].x) & 0xF];
    goto LABEL_15;
  }
  uint8 v1 = player_current_power_up;
  if (player_current_power_up)
    v1 = 1;
  LOBYTE(pt[1].y) = kCarryEggAwayFromCastle_DATA_0CD7EB[v1] + player_xpos;
  v2 = kCarryEggAwayFromCastle_DATA_0CD7ED[(uint8)(2 * player_walking_frame + (v1 & 1))];
  if ((uint8)player_xpos < 0x40 && !player_xspeed) {
    timer_display_player_pick_up_pose = 16;
    player_carrying_something_flag2 = 0;
    goto LABEL_10;
  }
LABEL_15:;
  OamEnt *oam = get_OamEnt(oam_buf, 0);
  oam[96].ypos = v2;
  oam[96].xpos = pt[1].y;
  oam[96].charnum = 0;
  oam[96].flags = 33;
  sprites_oamtile_size_buffer[96] = 2;
}
