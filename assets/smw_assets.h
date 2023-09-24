#pragma once
#include "../src/types.h"

enum {
  kNumberOfAssets = 178
};
extern const uint8 *g_asset_ptrs[kNumberOfAssets];
extern uint32 g_asset_sizes[kNumberOfAssets];
extern MemBlk FindInAssetArray(int asset, int idx);
extern const uint8 *FindPtrInAsset(int asset, uint32 addr);

#define kGraphicsPtrs(idx) FindInAssetArray(0, idx)
#define kGfx32 g_asset_ptrs[1]
#define kGfx32_SIZE (g_asset_sizes[1])
#define kGfx33 g_asset_ptrs[2]
#define kGfx33_SIZE (g_asset_sizes[2])
#define kLoadStripeImagePtrs(idx) FindInAssetArray(3, idx)
#define kLayer3ImagePtrs(idx) FindInAssetArray(4, idx)
#define kSpcCreditsMusicBank g_asset_ptrs[5]
#define kSpcCreditsMusicBank_SIZE (g_asset_sizes[5])
#define kSpcLevelMusicBank g_asset_ptrs[6]
#define kSpcLevelMusicBank_SIZE (g_asset_sizes[6])
#define kSpcEngine g_asset_ptrs[7]
#define kSpcEngine_SIZE (g_asset_sizes[7])
#define kSpcSamples g_asset_ptrs[8]
#define kSpcSamples_SIZE (g_asset_sizes[8])
#define kSpcOverworldMusicBank g_asset_ptrs[9]
#define kSpcOverworldMusicBank_SIZE (g_asset_sizes[9])
#define kMap16Data_OverworldLayer1 ((uint16*)g_asset_ptrs[10])
#define kMap16Data_OverworldLayer1_SIZE (g_asset_sizes[10])
#define kMap16Data ((uint16*)g_asset_ptrs[11])
#define kMap16Data_SIZE (g_asset_sizes[11])
#define kMap16Data_Castle ((uint16*)g_asset_ptrs[12])
#define kMap16Data_Castle_SIZE (g_asset_sizes[12])
#define kMap16Data_Rope ((uint16*)g_asset_ptrs[13])
#define kMap16Data_Rope_SIZE (g_asset_sizes[13])
#define kMap16Data_Underground ((uint16*)g_asset_ptrs[14])
#define kMap16Data_Underground_SIZE (g_asset_sizes[14])
#define kMap16Data_GhostHouse ((uint16*)g_asset_ptrs[15])
#define kMap16Data_GhostHouse_SIZE (g_asset_sizes[15])
#define kGlobalPalettes_Sky ((uint16*)g_asset_ptrs[16])
#define kGlobalPalettes_Sky_SIZE (g_asset_sizes[16])
#define kGlobalPalettes_Background ((uint16*)g_asset_ptrs[17])
#define kGlobalPalettes_Background_SIZE (g_asset_sizes[17])
#define kGlobalPalettes_Layer3 ((uint16*)g_asset_ptrs[18])
#define kGlobalPalettes_Layer3_SIZE (g_asset_sizes[18])
#define kGlobalPalettes_Foreground ((uint16*)g_asset_ptrs[19])
#define kGlobalPalettes_Foreground_SIZE (g_asset_sizes[19])
#define kGlobalPalettes_Objects ((uint16*)g_asset_ptrs[20])
#define kGlobalPalettes_Objects_SIZE (g_asset_sizes[20])
#define kPlayerPalettes ((uint16*)g_asset_ptrs[21])
#define kPlayerPalettes_SIZE (g_asset_sizes[21])
#define kGlobalPalettes_Sprites ((uint16*)g_asset_ptrs[22])
#define kGlobalPalettes_Sprites_SIZE (g_asset_sizes[22])
#define kGlobalPalettes_YoshiBerry ((uint16*)g_asset_ptrs[23])
#define kGlobalPalettes_YoshiBerry_SIZE (g_asset_sizes[23])
#define kGlobalPalettes_Flashing ((uint16*)g_asset_ptrs[24])
#define kGlobalPalettes_Flashing_SIZE (g_asset_sizes[24])
#define kGlobalPalettes_OW_Objects ((uint16*)g_asset_ptrs[25])
#define kGlobalPalettes_OW_Objects_SIZE (g_asset_sizes[25])
#define kGlobalPalettes_OW_Sprites ((uint16*)g_asset_ptrs[26])
#define kGlobalPalettes_OW_Sprites_SIZE (g_asset_sizes[26])
#define kGlobalPalettes_B5EC ((uint16*)g_asset_ptrs[27])
#define kGlobalPalettes_B5EC_SIZE (g_asset_sizes[27])
#define kGlobalPalettes_OW_Areas ((uint16*)g_asset_ptrs[28])
#define kGlobalPalettes_OW_Areas_SIZE (g_asset_sizes[28])
#define kGlobalPalettes_OW_AreasPassed ((uint16*)g_asset_ptrs[29])
#define kGlobalPalettes_OW_AreasPassed_SIZE (g_asset_sizes[29])
#define kGlobalPalettes_Bowser ((uint16*)g_asset_ptrs[30])
#define kGlobalPalettes_Bowser_SIZE (g_asset_sizes[30])
#define kGlobalPalettes_Layer3Smasher ((uint16*)g_asset_ptrs[31])
#define kGlobalPalettes_Layer3Smasher_SIZE (g_asset_sizes[31])
#define kGameMode1B_EndingCinema_Tilemaps g_asset_ptrs[32]
#define kGameMode1B_EndingCinema_Tilemaps_SIZE (g_asset_sizes[32])
#define kGameMode1B_EndingCinema_RowPointers ((uint16*)g_asset_ptrs[33])
#define kGameMode1B_EndingCinema_RowPointers_SIZE (g_asset_sizes[33])
#define kLevelInfo_05F000 g_asset_ptrs[34]
#define kLevelInfo_05F000_SIZE (g_asset_sizes[34])
#define kLevelInfo_05F200 g_asset_ptrs[35]
#define kLevelInfo_05F200_SIZE (g_asset_sizes[35])
#define kLevelInfo_05F400 g_asset_ptrs[36]
#define kLevelInfo_05F400_SIZE (g_asset_sizes[36])
#define kLevelInfo_05F600 g_asset_ptrs[37]
#define kLevelInfo_05F600_SIZE (g_asset_sizes[37])
#define kLoadLevel_DATA_05D608 g_asset_ptrs[38]
#define kLoadLevel_DATA_05D608_SIZE (g_asset_sizes[38])
#define kDisplayMessage_DATA_05A5D9 g_asset_ptrs[39]
#define kDisplayMessage_DATA_05A5D9_SIZE (g_asset_sizes[39])
#define kOverworldLightningAndRandomCloudSpawning g_asset_ptrs[40]
#define kOverworldLightningAndRandomCloudSpawning_SIZE (g_asset_sizes[40])
#define kLevelNames ((uint16*)g_asset_ptrs[41])
#define kLevelNames_SIZE (g_asset_sizes[41])
#define kLineGuideSpeedTableData g_asset_ptrs[42]
#define kLineGuideSpeedTableData_SIZE (g_asset_sizes[42])
#define kLevelData_Layer1(idx) FindInAssetArray(43, idx)
#define kEntranceData_Layer1(idx) FindInAssetArray(44, idx)
#define kChoclateIsland2_Layer1(idx) FindInAssetArray(45, idx)
#define kRollCallData_Layer1(idx) FindInAssetArray(46, idx)
#define kLevelData_Layer2(idx) FindInAssetArray(47, idx)
#define kLevelData_Layer2_IsBg g_asset_ptrs[48]
#define kLevelData_Layer2_IsBg_SIZE (g_asset_sizes[48])
#define kEntranceData_Layer2(idx) FindInAssetArray(49, idx)
#define kEntranceData_Layer2_IsBg g_asset_ptrs[50]
#define kEntranceData_Layer2_IsBg_SIZE (g_asset_sizes[50])
#define kChoclateIsland2_Layer2(idx) FindInAssetArray(51, idx)
#define kChoclateIsland2_Layer2_IsBg g_asset_ptrs[52]
#define kChoclateIsland2_Layer2_IsBg_SIZE (g_asset_sizes[52])
#define kRollCallData_Layer2(idx) FindInAssetArray(53, idx)
#define kRollCallData_Layer2_IsBg g_asset_ptrs[54]
#define kRollCallData_Layer2_IsBg_SIZE (g_asset_sizes[54])
#define kBufferCreditsBackgrounds_Layer2(idx) FindInAssetArray(55, idx)
#define kBufferCreditsBackgrounds_Layer2_IsBg g_asset_ptrs[56]
#define kBufferCreditsBackgrounds_Layer2_IsBg_SIZE (g_asset_sizes[56])
#define kLvlSprBlob(addr) FindPtrInAsset(57, addr)
#define kLmSpritePtrBankByte g_asset_ptrs[58]
#define kLmSpritePtrBankByte_SIZE (g_asset_sizes[58])
#define kLoadLevel_SpriteDataPtrs ((uint16*)g_asset_ptrs[59])
#define kLoadLevel_SpriteDataPtrs_SIZE (g_asset_sizes[59])
#define kFileSelectText_EraseFile g_asset_ptrs[60]
#define kFileSelectText_EraseFile_SIZE (g_asset_sizes[60])
#define kInitializeMode7TilemapsAndPalettes_TilemapData g_asset_ptrs[61]
#define kInitializeMode7TilemapsAndPalettes_TilemapData_SIZE (g_asset_sizes[61])
#define kLayer2EventData_TileEntries ((uint16*)g_asset_ptrs[62])
#define kLayer2EventData_TileEntries_SIZE (g_asset_sizes[62])
#define kChangingLayer1OverworldTiles_Layer1TileLocation ((uint16*)g_asset_ptrs[63])
#define kChangingLayer1OverworldTiles_Layer1TileLocation_SIZE (g_asset_sizes[63])
#define kOwEventProcess01_DestroyTileAnimation_DATA_04E587 ((uint16*)g_asset_ptrs[64])
#define kOwEventProcess01_DestroyTileAnimation_DATA_04E587_SIZE (g_asset_sizes[64])
#define kCheckIfDestroyTileEventIsActive_DATA_04E5B6 ((uint16*)g_asset_ptrs[65])
#define kCheckIfDestroyTileEventIsActive_DATA_04E5B6_SIZE (g_asset_sizes[65])
#define kOwEventProcess01_DestroyTileAnimation_DATA_04D93D ((uint16*)g_asset_ptrs[66])
#define kOwEventProcess01_DestroyTileAnimation_DATA_04D93D_SIZE (g_asset_sizes[66])
#define kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles g_asset_ptrs[67]
#define kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_SIZE (g_asset_sizes[67])
#define kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileLayer g_asset_ptrs[68]
#define kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileLayer_SIZE (g_asset_sizes[68])
#define kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileNum ((uint16*)g_asset_ptrs[69])
#define kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TileNum_SIZE (g_asset_sizes[69])
#define kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TilemapLocation ((uint16*)g_asset_ptrs[70])
#define kOwEventProcess07_SilentEventsAndEndOfEvent_SilentEventTiles_TilemapLocation_SIZE (g_asset_sizes[70])
#define kOwDestruction_TileToIdx_04E5A7 g_asset_ptrs[71]
#define kOwDestruction_TileToIdx_04E5A7_SIZE (g_asset_sizes[71])
#define kOwDestruction_TopTile_04E5AC g_asset_ptrs[72]
#define kOwDestruction_TopTile_04E5AC_SIZE (g_asset_sizes[72])
#define kOwDestruction_BottomTile_04E5B1 g_asset_ptrs[73]
#define kOwDestruction_BottomTile_04E5B1_SIZE (g_asset_sizes[73])
#define kOwDestruction_TriggerEvent_04E5D6 g_asset_ptrs[74]
#define kOwDestruction_TriggerEvent_04E5D6_SIZE (g_asset_sizes[74])
#define kLmEventStuff1 ((uint16*)g_asset_ptrs[75])
#define kLmEventStuff1_SIZE (g_asset_sizes[75])
#define kLmEventStuff2 ((uint16*)g_asset_ptrs[76])
#define kLmEventStuff2_SIZE (g_asset_sizes[76])
#define kLmEventStuff3 ((uint16*)g_asset_ptrs[77])
#define kLmEventStuff3_SIZE (g_asset_sizes[77])
#define kLmEventStuff4 g_asset_ptrs[78]
#define kLmEventStuff4_SIZE (g_asset_sizes[78])
#define kOverworldLayer2EventTilemap_Tiles g_asset_ptrs[79]
#define kOverworldLayer2EventTilemap_Tiles_SIZE (g_asset_sizes[79])
#define kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap g_asset_ptrs[80]
#define kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap_SIZE (g_asset_sizes[80])
#define kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap_Prop g_asset_ptrs[81]
#define kLoadOverworldLayer2AndEventsTilemaps_OverworldLayer2Tilemap_Prop_SIZE (g_asset_sizes[81])
#define kOverworldLayer2EventTilemap_Prop g_asset_ptrs[82]
#define kOverworldLayer2EventTilemap_Prop_SIZE (g_asset_sizes[82])
#define kLoadOverworldLayer1AndEvents_DATA_0CF7DF g_asset_ptrs[83]
#define kLoadOverworldLayer1AndEvents_DATA_0CF7DF_SIZE (g_asset_sizes[83])
#define kRom g_asset_ptrs[84]
#define kRom_SIZE (g_asset_sizes[84])
#define kUpdateLevelName_LevelNameStrings g_asset_ptrs[85]
#define kUpdateLevelName_LevelNameStrings_SIZE (g_asset_sizes[85])
#define kGameMode25_ShowEnemyRollcallScreen_TileData g_asset_ptrs[86]
#define kGameMode25_ShowEnemyRollcallScreen_TileData_SIZE (g_asset_sizes[86])
#define kLmPalettes(idx) FindInAssetArray(87, idx)
#define kPlayerGFXRt_HeadTilePointerIndex g_asset_ptrs[88]
#define kPlayerGFXRt_HeadTilePointerIndex_SIZE (g_asset_sizes[88])
#define kPlayerGFXRt_BodyTilePointerIndex g_asset_ptrs[89]
#define kPlayerGFXRt_BodyTilePointerIndex_SIZE (g_asset_sizes[89])
#define kLvlInitialFlags g_asset_ptrs[90]
#define kLvlInitialFlags_SIZE (g_asset_sizes[90])
#define kLoadOverworldSprites_SpriteSlotData g_asset_ptrs[91]
#define kLoadOverworldSprites_SpriteSlotData_SIZE (g_asset_sizes[91])
#define kChangingLayer1OverworldTiles_TilesThatChange g_asset_ptrs[92]
#define kChangingLayer1OverworldTiles_TilesThatChange_SIZE (g_asset_sizes[92])
#define kChangingLayer1OverworldTiles_TilesToBecome g_asset_ptrs[93]
#define kChangingLayer1OverworldTiles_TilesToBecome_SIZE (g_asset_sizes[93])
#define kOverworldEventProcess01_DestroyTileAnimation_DATA_04EE7A g_asset_ptrs[94]
#define kOverworldEventProcess01_DestroyTileAnimation_DATA_04EE7A_SIZE (g_asset_sizes[94])
#define kLevelTileAnimations_FrameData ((uint16*)g_asset_ptrs[95])
#define kLevelTileAnimations_FrameData_SIZE (g_asset_sizes[95])
#define kSetPlayerPose_WalkingPoseCount g_asset_ptrs[96]
#define kSetPlayerPose_WalkingPoseCount_SIZE (g_asset_sizes[96])
#define kDrawLoadingLetters_TileData g_asset_ptrs[97]
#define kDrawLoadingLetters_TileData_SIZE (g_asset_sizes[97])
#define kDrawLoadingLetters_TileData_BottomTiles g_asset_ptrs[98]
#define kDrawLoadingLetters_TileData_BottomTiles_SIZE (g_asset_sizes[98])
#define kDrawLoadingLetters_TileData_TopProp g_asset_ptrs[99]
#define kDrawLoadingLetters_TileData_TopProp_SIZE (g_asset_sizes[99])
#define kDrawLoadingLetters_TileData_BottomProp g_asset_ptrs[100]
#define kDrawLoadingLetters_TileData_BottomProp_SIZE (g_asset_sizes[100])
#define kOwTileAnimations_WaterTileNumbers ((uint16*)g_asset_ptrs[101])
#define kOwTileAnimations_WaterTileNumbers_SIZE (g_asset_sizes[101])
#define kOwTileAnimations_TileNumbers ((uint16*)g_asset_ptrs[102])
#define kOwTileAnimations_TileNumbers_SIZE (g_asset_sizes[102])
#define kOwStarPipeWarp_SrcX_048431 ((uint16*)g_asset_ptrs[103])
#define kOwStarPipeWarp_SrcX_048431_SIZE (g_asset_sizes[103])
#define kOwStarPipeWarp_SrcY_048467 ((uint16*)g_asset_ptrs[104])
#define kOwStarPipeWarp_SrcY_048467_SIZE (g_asset_sizes[104])
#define kOwStarPipeWarp_DstX_04849D ((uint16*)g_asset_ptrs[105])
#define kOwStarPipeWarp_DstX_04849D_SIZE (g_asset_sizes[105])
#define kOwStarPipeWarp_DstY_0484D3 ((uint16*)g_asset_ptrs[106])
#define kOwStarPipeWarp_DstY_0484D3_SIZE (g_asset_sizes[106])
#define kOwLevelsForcedMusicChange_048D74 ((uint16*)g_asset_ptrs[107])
#define kOwLevelsForcedMusicChange_048D74_SIZE (g_asset_sizes[107])
#define kOwSubmapMusic_048D8A g_asset_ptrs[108]
#define kOwSubmapMusic_048D8A_SIZE (g_asset_sizes[108])
#define kOw_KoopaKidTeleportXYPos_048E49 ((uint16*)g_asset_ptrs[109])
#define kOw_KoopaKidTeleportXYPos_048E49_SIZE (g_asset_sizes[109])
#define kOwTriggerSaveTiles_048F7F g_asset_ptrs[110]
#define kOwTriggerSaveTiles_048F7F_SIZE (g_asset_sizes[110])
#define kOwNoAutoMoveLevels_04906C ((uint16*)g_asset_ptrs[111])
#define kOwNoAutoMoveLevels_04906C_SIZE (g_asset_sizes[111])
#define kOwHardcodedPathLevel_049078 g_asset_ptrs[112]
#define kOwHardcodedPathLevel_049078_SIZE (g_asset_sizes[112])
#define kOwHardcodedPathChocolateIsland2_049082 ((uint16*)g_asset_ptrs[113])
#define kOwHardcodedPathChocolateIsland2_049082_SIZE (g_asset_sizes[113])
#define kOwHardcodedPathTiles_049086 g_asset_ptrs[114]
#define kOwHardcodedPathTiles_049086_SIZE (g_asset_sizes[114])
#define kOwHardcodedPathDirs_0490CA g_asset_ptrs[115]
#define kOwHardcodedPathDirs_0490CA_SIZE (g_asset_sizes[115])
#define kOwHardcodedPathStartIndex_04910E g_asset_ptrs[116]
#define kOwHardcodedPathStartIndex_04910E_SIZE (g_asset_sizes[116])
#define kOwExitLevelTiles_049426 g_asset_ptrs[117]
#define kOwExitLevelTiles_049426_SIZE (g_asset_sizes[117])
#define kUpdateLevelName_DATA_049C91 ((uint16*)g_asset_ptrs[118])
#define kUpdateLevelName_DATA_049C91_SIZE (g_asset_sizes[118])
#define kUpdateLevelName_DATA_049CCF ((uint16*)g_asset_ptrs[119])
#define kUpdateLevelName_DATA_049CCF_SIZE (g_asset_sizes[119])
#define kUpdateLevelName_DATA_049CED ((uint16*)g_asset_ptrs[120])
#define kUpdateLevelName_DATA_049CED_SIZE (g_asset_sizes[120])
#define kOwExitSource_049964 g_asset_ptrs[121]
#define kOwExitSource_049964_SIZE (g_asset_sizes[121])
#define kOwExitDest_0499AA g_asset_ptrs[122]
#define kOwExitDest_0499AA_SIZE (g_asset_sizes[122])
#define kOwExitExtra_0499F0 g_asset_ptrs[123]
#define kOwExitExtra_0499F0_SIZE (g_asset_sizes[123])
#define kOwExitLayerPosition_049A0C ((uint16*)g_asset_ptrs[124])
#define kOwExitLayerPosition_049A0C_SIZE (g_asset_sizes[124])
#define kOwUnknownTableA_From_04A03C g_asset_ptrs[125]
#define kOwUnknownTableA_From_04A03C_SIZE (g_asset_sizes[125])
#define kOwUnknownTableA_Alpha_04A054 ((uint16*)g_asset_ptrs[126])
#define kOwUnknownTableA_Alpha_04A054_SIZE (g_asset_sizes[126])
#define kOwUnknownTableA_XY_04A084 ((uint16*)g_asset_ptrs[127])
#define kOwUnknownTableA_XY_04A084_SIZE (g_asset_sizes[127])
#define kOwUnknownTableA_Direction_04A0E4 g_asset_ptrs[128]
#define kOwUnknownTableA_Direction_04A0E4_SIZE (g_asset_sizes[128])
#define kOwDirectionAfterBeatingLevel_04D678 g_asset_ptrs[129]
#define kOwDirectionAfterBeatingLevel_04D678_SIZE (g_asset_sizes[129])
#define kOwSubmapTileset_04DC02 g_asset_ptrs[130]
#define kOwSubmapTileset_04DC02_SIZE (g_asset_sizes[130])
#define kLayer2EventData_Ptrs_04E359 ((uint16*)g_asset_ptrs[131])
#define kLayer2EventData_Ptrs_04E359_SIZE (g_asset_sizes[131])
#define kLmInitSaveData g_asset_ptrs[132]
#define kLmInitSaveData_SIZE (g_asset_sizes[132])
#define kInitializeSaveData_InitialOWPlayerPos g_asset_ptrs[133]
#define kInitializeSaveData_InitialOWPlayerPos_SIZE (g_asset_sizes[133])
#define kOWSpr07_Smoke_DATA_04FC1E ((uint16*)g_asset_ptrs[134])
#define kOWSpr07_Smoke_DATA_04FC1E_SIZE (g_asset_sizes[134])
#define kLoadOverworldSprites_SubmapBooXPosOffset ((uint16*)g_asset_ptrs[135])
#define kLoadOverworldSprites_SubmapBooXPosOffset_SIZE (g_asset_sizes[135])
#define kLoadOverworldSprites_SubmapBooYPosOffset ((uint16*)g_asset_ptrs[136])
#define kLoadOverworldSprites_SubmapBooYPosOffset_SIZE (g_asset_sizes[136])
#define kLoadLevelHeader_LevelMusicTable g_asset_ptrs[137]
#define kLoadLevelHeader_LevelMusicTable_SIZE (g_asset_sizes[137])
#define kLevelsThatTriggerCutscenes g_asset_ptrs[138]
#define kLevelsThatTriggerCutscenes_SIZE (g_asset_sizes[138])
#define kLmExgfx(idx) FindInAssetArray(139, idx)
#define kLmSuperExgfx(idx) FindInAssetArray(140, idx)
#define kLmGraphicsRemapped g_asset_ptrs[141]
#define kLmGraphicsRemapped_SIZE (g_asset_sizes[141])
#define kLmModifyMap16Ids ((uint16*)g_asset_ptrs[142])
#define kLmModifyMap16Ids_SIZE (g_asset_sizes[142])
#define kLm5DE00 g_asset_ptrs[143]
#define kLm5DE00_SIZE (g_asset_sizes[143])
#define kLm6FC00 g_asset_ptrs[144]
#define kLm6FC00_SIZE (g_asset_sizes[144])
#define kLm6FE00 g_asset_ptrs[145]
#define kLm6FE00_SIZE (g_asset_sizes[145])
#define kLm10B8BC g_asset_ptrs[146]
#define kLm10B8BC_SIZE (g_asset_sizes[146])
#define kLmLevelData3FE00 g_asset_ptrs[147]
#define kLmLevelData3FE00_SIZE (g_asset_sizes[147])
#define kLmLevelData5DC85 g_asset_ptrs[148]
#define kLmLevelData5DC85_SIZE (g_asset_sizes[148])
#define kLmLevelData5DC8A g_asset_ptrs[149]
#define kLmLevelData5DC8A_SIZE (g_asset_sizes[149])
#define kLm5FE00 g_asset_ptrs[150]
#define kLm5FE00_SIZE (g_asset_sizes[150])
#define kLevelInfo_05F800 g_asset_ptrs[151]
#define kLevelInfo_05F800_SIZE (g_asset_sizes[151])
#define kLevelInfo_05FA00 g_asset_ptrs[152]
#define kLevelInfo_05FA00_SIZE (g_asset_sizes[152])
#define kLevelInfo_05FC00 g_asset_ptrs[153]
#define kLevelInfo_05FC00_SIZE (g_asset_sizes[153])
#define kMap16_0 ((uint16*)g_asset_ptrs[154])
#define kMap16_0_SIZE (g_asset_sizes[154])
#define kMap16_1 ((uint16*)g_asset_ptrs[155])
#define kMap16_1_SIZE (g_asset_sizes[155])
#define kMap16_2 ((uint16*)g_asset_ptrs[156])
#define kMap16_2_SIZE (g_asset_sizes[156])
#define kMap16_3 ((uint16*)g_asset_ptrs[157])
#define kMap16_3_SIZE (g_asset_sizes[157])
#define kMap16_4 ((uint16*)g_asset_ptrs[158])
#define kMap16_4_SIZE (g_asset_sizes[158])
#define kMap16_5 ((uint16*)g_asset_ptrs[159])
#define kMap16_5_SIZE (g_asset_sizes[159])
#define kMap16_6 ((uint16*)g_asset_ptrs[160])
#define kMap16_6_SIZE (g_asset_sizes[160])
#define kMap16_7 ((uint16*)g_asset_ptrs[161])
#define kMap16_7_SIZE (g_asset_sizes[161])
#define kMap16_TS ((uint16*)g_asset_ptrs[162])
#define kMap16_TS_SIZE (g_asset_sizes[162])
#define kLmLvlExAnim g_asset_ptrs[163]
#define kLmLvlExAnim_SIZE (g_asset_sizes[163])
#define kLmExanimBlob(addr) FindPtrInAsset(164, addr)
#define kLmOverworldPal g_asset_ptrs[165]
#define kLmOverworldPal_SIZE (g_asset_sizes[165])
#define kLmDisplayMessage_Tab0 g_asset_ptrs[166]
#define kLmDisplayMessage_Tab0_SIZE (g_asset_sizes[166])
#define kLmDisplayMessage_3BC7F ((uint16*)g_asset_ptrs[167])
#define kLmDisplayMessage_3BC7F_SIZE (g_asset_sizes[167])
#define kLmDisplayMessage_3BE80 ((uint16*)g_asset_ptrs[168])
#define kLmDisplayMessage_3BE80_SIZE (g_asset_sizes[168])
#define kLmDisplayMessage_Tab1 g_asset_ptrs[169]
#define kLmDisplayMessage_Tab1_SIZE (g_asset_sizes[169])
#define kLmTitleScreenMoves g_asset_ptrs[170]
#define kLmTitleScreenMoves_SIZE (g_asset_sizes[170])
#define kLmLevelNamesPatch g_asset_ptrs[171]
#define kLmLevelNamesPatch_SIZE (g_asset_sizes[171])
#define kOwLayer1AndEvents g_asset_ptrs[172]
#define kOwLayer1AndEvents_SIZE (g_asset_sizes[172])
#define kOwLayer1AndEvents2 g_asset_ptrs[173]
#define kOwLayer1AndEvents2_SIZE (g_asset_sizes[173])
#define kLmLvlInfo ((uint16*)g_asset_ptrs[174])
#define kLmLvlInfo_SIZE (g_asset_sizes[174])
#define kLmCustomMap16Bg(idx) FindInAssetArray(175, idx)
#define kLmSprExtraSize g_asset_ptrs[176]
#define kLmSprExtraSize_SIZE (g_asset_sizes[176])
#define kLmFeatures g_asset_ptrs[177]
#define kLmFeatures_SIZE (g_asset_sizes[177])
#define kAssets_Sig 83, 109, 119, 95, 118, 48, 32, 32, 32, 32, 32, 32, 32, 32, 10, 0, 85, 177, 205, 26, 249, 0, 56, 113, 186, 11, 242, 196, 157, 30, 113, 190, 86, 157, 53, 15, 96, 246, 11, 95, 59, 106, 128, 210, 127, 126, 117, 134
