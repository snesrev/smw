#include "types.h"
#define kLoadStripeImage_StripeImagePtrs ((LongPtr*)RomFixedPtr(0x84D0))
#define kChangeNetDoorTiles_DATA_00C32E ((LongPtr*)RomFixedPtr(0xC32E))
#define kManipulateMode7Image_DATA_008B57 ((uint16*)RomFixedPtr(0x8B57))
#define kUpdatePaletteFromIndexedTable_DATA_00A47F ((uint8*)RomFixedPtr(0xA47F))

#define kLevelTileAnimations_FrameData ((uint16*)RomFixedPtr(0x5B999))

#define kPlayerGFXRt_XDisp ((uint16*)RomFixedPtr(0xDD4E))
#define kPlayerGFXRt_YDisp ((uint16*)RomFixedPtr(0xDE32))

#define kPlayerState0C_CastleDestructionMoves_CastleDestructionMovementData ((uint8*)RomFixedPtr(0xC5E8))

extern const uint8 kSlopeDataTables_SlopeType[33];

extern const uint8 kLevelDataLayoutTables_EightBitLo_Horizontal[32];
extern const uint8 kLevelDataLayoutTables_EightBitLo_Vertical[28];
extern const uint8 kLevelDataLayoutTables_EightBitHi_Horizontal[32];
extern const uint8 kLevelDataLayoutTables_EightBitHi_Vertical[28];

extern const uint16 kGlobalPalettes_BowserLightningFlash[11];
extern const uint16 kGlobalPalettes_Bowser[56];

extern const uint8 kGameModeXX_FadeInOrOut_DATA_009F2F[2];
extern const uint8 kGameModeXX_FadeInOrOut_DATA_009F31[2];
extern const uint8 kGameModeXX_FadeInOrOut_DATA_009F33[2];

extern const uint16 kLevelDataLayoutTables_LoTablePtrs[2];
extern const uint16 kLevelDataLayoutTables_HiTablePtrs[2];

extern const uint16 kGlobalPalettes_Sky[8];
extern const uint8 kGameMode19_Cutscene_SkyColorSetting[8];

extern const uint8 kGenericSpriteToSpawnTable[19];
extern const uint16 kSpr01F_MagiKoopa_MagiKoopaFadePalettes[64];

#define kDrawOverworldPlayer_PlayerRidingYoshiTilesAndProp ((uint8*)RomFixedPtr(0x489DE))

extern const uint8 kOverworldLightningAndRandomCloudSpawning_DATA_04F700[8];
extern const uint8 kOverworldLightningAndRandomCloudSpawning_DATA_04F6F8[8];
#define kDrawOverworldPlayer_PlayerTilesAndProp ((uint16*)RomFixedPtr(0x487CB))
#define kLevelNames ((uint16*)RomFixedPtr(0x4A0FC))

#define kHandleOverworldPathExits_DATA_049964 ((OwExits*)RomFixedPtr(0x49964))
#define kHandleOverworldPathExits_DATA_0499AA ((OwExits*)RomFixedPtr(0x499AA))
#define kOverworldLightningAndRandomCloudSpawning ((uint8*)RomFixedPtr(0x4F708))

#define kInitializeLevelLayer3_Layer3ImagePtrs ((LongPtr*)RomFixedPtr(0x59000))

extern const uint8 kBitTable_Bank05[8];
#define kDisplayMessage_DATA_05A5D9 ((uint8*)RomFixedPtr(0x5A5D9))
#define kLevelTileAnimations_DATA_05B93B ((LevelTileAnimations*)RomFixedPtr(0x5B93B))
#define kSpecifySublevelToLoad_DATA_05D608 ((uint8*)RomFixedPtr(0x5D608))
#define kSpecifySublevelToLoad_LevelEntranceLayer1 ((LongPtr*)RomFixedPtr(0x5D766))
#define kSpecifySublevelToLoad_LevelEntranceLayer2 ((LongPtr*)RomFixedPtr(0x5D778))

#define kSpecifySublevelToLoad_Layer1DataPtrs ((LongPtr*)RomFixedPtr(0x5E000))
#define kSpecifySublevelToLoad_Layer2DataPtrs ((LongPtr*)RomFixedPtr(0x5E600))
#define kSpecifySublevelToLoad_SpriteDataPtrs ((uint16*)RomFixedPtr(0x5EC00))
#define kSpecifySublevelToLoad_DATA_05F000 ((uint8*)RomFixedPtr(0x5F000))
#define kSpecifySublevelToLoad_DATA_05F200 ((uint8*)RomFixedPtr(0x5F200))
#define kSpecifySublevelToLoad_DATA_05F400 ((uint8*)RomFixedPtr(0x5F400))
#define kSpecifySublevelToLoad_DATA_05F600 ((uint8*)RomFixedPtr(0x5F600))
#define kSpecifySublevelToLoad_DATA_05F800 ((uint8*)RomFixedPtr(0x5F800))
#define kSpecifySublevelToLoad_DATA_05FA00 ((uint8*)RomFixedPtr(0x5FA00))
#define kSpecifySublevelToLoad_DATA_05FC00 ((uint8*)RomFixedPtr(0x5FC00))
#define kSpecifySublevelToLoad_DATA_05FE00 ((uint8*)RomFixedPtr(0x5FE00))

extern const uint8 kInitializeNormalSpriteRAMTables_Sprite190FVals[201];

#define kCircleCoordinates ((uint16*)RomFixedPtr(0x7F7DB))
#define kOverworldLayer2EventTilemap_Tiles ((uint8*)RomFixedPtr(0xC8000))
#define kGameMode1B_EndingCinema_Tilemaps ((uint8*)RomFixedPtr(0xC95C7))
#define kGameMode1B_EndingCinema_RowPointers ((uint16*)RomFixedPtr(0xC9D18))

