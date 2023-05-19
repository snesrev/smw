#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"

void (*kProcessExtendedObjects_ExtendedObjectPtrs[256])(uint8 k) = {
    &ExtObj00_ScreenExit,
    &ExtObj01_ScreenJump,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObjXX_Generic1TileObject_GreenStarBlockEntry,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj18_3upMoon,
    &ExtObj41_YoshiCoin,
    &ExtObj42_TopLeftSlope,
    &ExtObj42_TopLeftSlope,
    &ExtObjXX_PurpleTriangle,
    &ExtObjXX_PurpleTriangle,
    &ExtObj46_MidwayBar,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj49_GhostHouseExit,
    &ExtObj4A_ClimbingNetDoor,
    &ExtObj4B_ConveyorEndTile1,
    &ExtObj4B_ConveyorEndTile1,
    &ExtObjXX_LineGuideQuarterLargeCircle,
    &ExtObjXX_LineGuideQuarterLargeCircle,
    &ExtObjXX_LineGuideQuarterLargeCircle,
    &ExtObjXX_LineGuideQuarterLargeCircle,
    &ExtObjXX_LineGuideQuarterSmallCircle,
    &ExtObjXX_LineGuideQuarterSmallCircle,
    &ExtObjXX_LineGuideQuarterSmallCircle,
    &ExtObjXX_LineGuideQuarterSmallCircle,
    &ExtObj55_HorizontalLineGuideEnd,
    &ExtObj56_VerticalLineGuideEnd,
    &ExtObj5B_BitOfBrickBackground1,
    &ExtObj5B_BitOfBrickBackground1,
    &ExtObj5B_BitOfBrickBackground1,
    &ExtObj5B_BitOfBrickBackground1,
    &ExtObj5B_BitOfBrickBackground1,
    &ExtObj5B_BitOfBrickBackground1,
    &ExtObj5B_BitOfBrickBackground1,
    &ExtObj5B_BitOfBrickBackground1,
    &ExtObj5F_LargeBackgroundArea,
    &ExtObj60_CaveLavaInnerCorner,
    &ExtObj61_GhostHouseClock,
    &ExtObj61_GhostHouseClock,
    &ExtObj61_GhostHouseClock,
    &ExtObj65_TopLeftCobweb,
    &ExtObj65_TopLeftCobweb,
    &ExtObj66_GhostHouseTopRightToBottomLeftBeam2,
    &ExtObj66_GhostHouseTopRightToBottomLeftBeam2,
    &ExtObj6B_CloudFringeBottomLeft,
    &ExtObj6B_CloudFringeBottomLeft,
    &ExtObj6B_CloudFringeBottomLeft,
    &ExtObj6B_CloudFringeBottomLeft,
    &ExtObj6B_CloudFringeBottomLeft,
    &ExtObj6B_CloudFringeBottomLeft,
    &ExtObj6B_CloudFringeBottomLeft,
    &ExtObj6B_CloudFringeBottomLeft,
    &ExtObj70_BitOfCanvas1,
    &ExtObj71_Canvas1,
    &ExtObj71_Canvas1,
    &ExtObj71_Canvas1,
    &ExtObj71_Canvas1,
    &ExtObj75_CanvasTile1,
    &ExtObj75_CanvasTile1,
    &ExtObj75_CanvasTile1,
    &ExtObj75_CanvasTile1,
    &ExtObj75_CanvasTile1,
    &ExtObj75_CanvasTile1,
    &ExtObj75_CanvasTile1,
    &ExtObj7C_BitOfCanvas1,
    &ExtObj7C_BitOfCanvas1,
    &ExtObj7C_BitOfCanvas1,
    &ExtObj7F_TorpedoLauncher,
    &ExtObj80_GhostHouseEntrance,
    &ExtObj81_Seaweed,
    &ExtObjXX_LargeBush_BigBushEntry,
    &ExtObjXX_LargeBush_SmallBushEntry,
    &ExtObj84_CastleEntrance,
    &ExtObj85_YoshisHouse,
    &ExtObj86_GoalSign,
    &ExtObj8E_YellowSwitchBlock_GreenSwitchBlockEntry,
    &ExtObj89_LeftTreeBranch,
    &ExtObj89_LeftTreeBranch,
    &ExtObj8D_SwitchPalaceSwitch,
    &ExtObj8D_SwitchPalaceSwitch,
    &ExtObj8D_SwitchPalaceSwitch,
    &ExtObj8D_SwitchPalaceSwitch,
    &ExtObj8E_YellowSwitchBlock,
    &ExtObj8F_GhostHouseWindow,
    &ExtObj90_LargeBossDoor,
    &ExtObj91_VerticalLevelSteepLeftSlope,
    &ExtObj91_VerticalLevelSteepLeftSlope,
    &ExtObj93_VerticalLevelNormalLeftSlope,
    &ExtObj93_VerticalLevelNormalLeftSlope,
    &ExtObj95_VerticalLevelVerySteepLeftSlope,
    &ExtObj95_VerticalLevelVerySteepLeftSlope,
    &ExtObj97_SwitchPalaceRightAndBottomEdgeTile,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
    &ExtObj47_Door,
};

void (*kProcessStandardAndTilesetSpecificObjects_TilesetPtrs[15])(void) = {
    &ProcessGrasslandObjects,  &ProcessCastleObjects,      &ProcessRopeObjects,        &ProcessUndergroundObjects,
    &ProcessGhostHouseObjects, &ProcessGhostHouseObjects,  &ProcessRopeObjects,        &ProcessGrasslandObjects,
    &ProcessRopeObjects,       &ProcessUndergroundObjects, &ProcessUndergroundObjects, &ProcessUndergroundObjects,
    &ProcessGrasslandObjects,  &ProcessGhostHouseObjects,  &ProcessUndergroundObjects,
};
void (*kProcessGrasslandObjects_GrasslandPtrs[63])(uint8 k) = {
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj0F_VerticalPipes,
    &StdObj10_HorizontalPipes,
    &StdObj11_BulletShooter,
    &StdObj12_Slopes,
    &StdObj13_GroundEdgesAndVine,
    &StdObj21_WideScaleGroundLedge_StandardLedgeEntry,
    &StdObj15_MidwayAndGoalPoint,
    &StdObj16_PurpleCoins,
    &StdObj17_RopeAndCloudLine,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &StdObj1C_DonutBridge,
    &StdObj1D_ClimbingNetWithBottomEdge,
    &StdObj1E_ClimbingNetWithSideEdge,
    &StdObj1F_SkinnyVerticalPipeBoneLog,
    &StdObj20_SkinnyHorizontalPipeBoneLog,
    &StdObj21_WideScaleGroundLedge,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &GrassObj30_IcyVerticalPipe,
    &StdObjXX_Generic1RepeatedTileObject_IcyTurnBlockEntry,
    &RopeObj33_BlueSwitchBlocks,
    &GrassObj33_ForestTreeTop,
    &GrassObj34_ForestGroundEdges,
    &GrassObj35_ForestGround,
    &GrassObj36_LargeTreeTrunk,
    &GrassObj37_SmallTreeTrunk,
    &GrassObj32_BlueSwitchBlocks_RedSwitchBlockEntry,
    &GrassObj39_RightFacingDiagonalPipe,
    &GrassObjXX_DiagonalLedge_LeftFacingDiagonalLedgeEntry,
    &GrassObjXX_DiagonalLedge_RightFacingDiagonalLedgeEntry,
    &GrassObj3C_ArchLedge,
    &GrassObj3D_TopCloudFridge,
    &GrassObj3E_SideCloudFridges,
    &GrassObj3F_SmallBushes,
};
void (*kStdObj12_Slopes_SlopesPtrs[10])(void) = {
    &StdObj12_SlopesLeftSlope,           &StdObj12_Slopes_SteepLeftSlope,
    &StdObj12_Slopes_GradualLeftSlope,          &StdObj12_SlopesRightSlope,
    &StdObj12_Slopes_SteepRightSlope,           &StdObj12_Slopes_GradualRightSlope,
    &StdObj12_Slopes_UpsideDownNormalLeftSlope, &StdObj12_Slopes_UpsideDownNormalRightSlope,
    &StdObj12_Slopes_UpsideDownSteepLeftSlope,  &StdObj12_Slopes_UpsideDownSteepRightSlope,
};
void (*kProcessCastleObjects_CastlePtrs[63])(uint8 k) = {
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj0F_VerticalPipes,
    &StdObj10_HorizontalPipes,
    &StdObj11_BulletShooter,
    &StdObj12_Slopes,
    &StdObj13_GroundEdgesAndVine,
    &StdObj21_WideScaleGroundLedge_StandardLedgeEntry,
    &StdObj15_MidwayAndGoalPoint,
    &StdObj16_PurpleCoins,
    &StdObj17_RopeAndCloudLine,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &StdObj1C_DonutBridge,
    &StdObj1D_ClimbingNetWithBottomEdge,
    &StdObj1E_ClimbingNetWithSideEdge,
    &StdObj1F_SkinnyVerticalPipeBoneLog,
    &StdObj20_SkinnyHorizontalPipeBoneLog,
    &StdObj21_WideScaleGroundLedge,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &CastleObj34_VerticalDoubleEndedPipe,
    &CastleObj35_RockWallBackground,
    &CastleObj36_LargeSpikedPillar,
    &RopeObj38_HorizontalLineGuide,
    &CastleObj38_VerticalLineGuide,
    &RopeObj33_BlueSwitchBlocks,
    &GrassObj32_BlueSwitchBlocks_RedSwitchBlockEntry,
    &CastleObj3B_GrassLedge,
    &CastleObj3C_StoneBlock,
    &CastleObj3D_Escalator,
    &CastleObj3E_HorizontalLineOfSpikes,
    &CastleObj3F_VerticalLineOfSpikes,
};
void (*kCastleObj3D_Escalator_EscalatorPtrs[2])(void) = {
    &CastleObj3D_Escalator_LeftSlope,
    &CastleObj3D_Escalator_RightSlope,
};
void (*kProcessRopeObjects_RopePtrs[63])(uint8 k) = {
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj0F_VerticalPipes,
    &StdObj10_HorizontalPipes,
    &StdObj11_BulletShooter,
    &StdObj12_Slopes,
    &StdObj13_GroundEdgesAndVine,
    &StdObj21_WideScaleGroundLedge_StandardLedgeEntry,
    &StdObj15_MidwayAndGoalPoint,
    &StdObj16_PurpleCoins,
    &StdObj17_RopeAndCloudLine,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &StdObj1C_DonutBridge,
    &StdObj1D_ClimbingNetWithBottomEdge,
    &StdObj1E_ClimbingNetWithSideEdge,
    &StdObj1F_SkinnyVerticalPipeBoneLog,
    &StdObj20_SkinnyHorizontalPipeBoneLog,
    &StdObj21_WideScaleGroundLedge,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj32_LogBridge,
    &RopeObj33_BlueSwitchBlocks,
    &GrassObj32_BlueSwitchBlocks_RedSwitchBlockEntry,
    &RopeObj35_ColumnWithPlantOnTop,
    &RopeObj36_HorizontalConveyorRope,
    &CastleObj3D_Escalator,
    &RopeObj38_HorizontalLineGuide,
    &CastleObj38_VerticalLineGuide,
    &RopeObj3A_SlopedLineGuide,
    &RopeObj3B_VerySteepSlopedLineGuide,
    &RopeObj3C_MushroomTop,
    &RopeObj3D_MushroomColumn,
    &RopeObj3E_HorizontalLog,
    &RopeObj3F_VerticalLog,
};
void (*kRopeObj3A_SlopedLineGuide_SlopedLineGuidePtrs[6])(uint8 k) = {
    &RopeObj3A_SlopedLineGuideLeftSlope, &RopeObj3A_SlopedLineGuide_ONOFFLeftSlope, &RopeObj3A_SlopedLineGuideRightSlope,
    &RopeObj3A_SlopedLineGuide_ONOFFRightSlope, &RopeObj3A_SlopedLineGuide_ONOFFLeftSlope, &RopeObj3A_SlopedLineGuide_ONOFFRightSlope,
};
void (*kRopeObj3B_VerySteepSlopedLineGuide_VerySteepSlopedLineGuidePtrs[2])(void) = {
    &RopeObj3B_VerySteepSlopedLineGuide_VerySteepLeftSlope,
    &RopeObj3B_VerySteepSlopedLineGuide_VerySteepRightSlope,
};
void (*kProcessUndergroundObjects_UndergroundPtrs[63])(uint8 k) = {
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj0F_VerticalPipes,
    &StdObj10_HorizontalPipes,
    &StdObj11_BulletShooter,
    &StdObj12_Slopes,
    &StdObj13_GroundEdgesAndVine,
    &StdObj21_WideScaleGroundLedge_StandardLedgeEntry,
    &StdObj15_MidwayAndGoalPoint,
    &StdObj16_PurpleCoins,
    &StdObj17_RopeAndCloudLine,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &StdObj1C_DonutBridge,
    &StdObj1D_ClimbingNetWithBottomEdge,
    &StdObj1E_ClimbingNetWithSideEdge,
    &StdObj1F_SkinnyVerticalPipeBoneLog,
    &StdObj20_SkinnyHorizontalPipeBoneLog,
    &StdObj21_WideScaleGroundLedge,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj33_BlueSwitchBlocks,
    &GrassObj32_BlueSwitchBlocks_RedSwitchBlockEntry,
    &UndergroundObj36_4SidedGround,
    &UndergroundObj37_LargeCanvas,
    &UndergroundObj38_RightLavaEdge,
    &UndergroundObj39_SlopedCaveLava,
    &UndergroundObj3B_CaveLava,
    &UndergroundObj3B_CaveLava,
    &UndergroundObj3C_VerySteepSlope,
    &UndergroundObj3D_CeilingLedge,
    &UndergroundObj3E_CeilingEdges,
    &UndergroundObj3F_SolidDirt,
};
void (*kUndergroundObj39_SlopedCaveLava_SlopedCaveLavaPtrs[4])(void) = {
    &UndergroundObj39_SlopedCaveLavaLeftSlope,
    &UndergroundObj39_SlopedCaveLava_SteepLeftSlope,
    &UndergroundObj39_SlopedCaveLavaRightSlope,
    &UndergroundObj39_SlopedCaveLava_SteepRightSlope,
};
void (*kUndergroundObj3C_VerySteepSlope_VerySteepSlopePtrs[2])(void) = {
    &UndergroundObj3C_VerySteepSlope_VerySteepLeftSlope,
    &UndergroundObj3C_VerySteepSlope_VerySteepRightSlope,
};
void (*kProcessGhostHouseObjects_GhostHousePtrs[63])(uint8 k) = {
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj05_Coins,
    &StdObj0F_VerticalPipes,
    &StdObj10_HorizontalPipes,
    &StdObj11_BulletShooter,
    &StdObj12_Slopes,
    &StdObj13_GroundEdgesAndVine,
    &StdObj21_WideScaleGroundLedge_StandardLedgeEntry,
    &StdObj15_MidwayAndGoalPoint,
    &StdObj16_PurpleCoins,
    &StdObj17_RopeAndCloudLine,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &StdObj1C_DonutBridge,
    &StdObj1D_ClimbingNetWithBottomEdge,
    &StdObj1E_ClimbingNetWithSideEdge,
    &StdObj1F_SkinnyVerticalPipeBoneLog,
    &StdObj20_SkinnyHorizontalPipeBoneLog,
    &StdObj21_WideScaleGroundLedge,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &RopeObj2E_Unused,
    &GhostHouseObj2E_HorizontalLineOfSpikes,
    &GhostHouseObj35_BrickBackground_LogBackgroundEntry,
    &GhostHouseObj30_GrassLedge1,
    &GhostHouseObj31_WoodCrate,
    &GhostHouseObj32_GrassLedge2,
    &GhostHouseObj33_Cloud,
    &GhostHouseObj34_WoodLedgeOnColumn,
    &GhostHouseObj36_WoodenBlocks,
    &GhostHouseObj36_WoodenBlocks,
    &GhostHouseObj37_HorizontalBackgroundLogAndRailing,
    &GhostHouseObj38_WoodenLedge,
    &GhostHouseObj39_VerticalBackgroundLog,
    &GhostHouseObj3A_SolidBrickWallAndVerticalLineOfSpikes,
    &GhostHouseObj3B_BonusGameLedge,
    &GhostHouseObj3C_SwitchPalaceCeiling,
    &GhostHouseObj3D_SwitchPalaceLedge,
    &GhostHouseObj3E_SwitchPalaceRightFacingWall,
    &GhostHouseObj3F_SwitchPalaceLeftFacingWall,
};

void ProcessExtendedObjects() {  // 0da100
  FuncU8 *p = kProcessExtendedObjects_ExtendedObjectPtrs[blocks_size_or_type];
  if (p)
    p(blocks_size_or_type);
  else
    Unreachable();
}

void ProcessStandardAndTilesetSpecificObjects() {  // 0da415
  kProcessStandardAndTilesetSpecificObjects_TilesetPtrs[misc_level_tileset_setting]();
}

void ProcessGrasslandObjects() {  // 0da44b
  kProcessGrasslandObjects_GrasslandPtrs[(uint8)(blocks_object_number - 1)](blocks_object_number - 1);
}

void ExtObj00_ScreenExit(uint8 k) {  // 0da512
  blocks_object_number = *IndirPtr(&temp65, 0);
  WORD(temp65) += 1;
  uint8 v2 = R10_ & 0x1F;
  misc_subscreen_exit_entrance_number_lo[v2] = blocks_object_number;
  misc_subscreen_exit_properties[v2] = R11_ & 1;
  flag_use_secondary_entrance = R11_ >> 1;
}

void ExtObj01_ScreenJump(uint8 k) {  // 0da53d
  blocks_screen_to_place_current_object = R10_ & 0x1F;
  blocks_screen_to_place_next_object = R10_ & 0x1F;
}

void ExtObj18_3upMoon(uint8 k) {  // 0da57b
  ExtObjXX_Generic1TileObject_0DA57F(k, k - 16);
}

void ExtObjXX_Generic1TileObject_0DA57F(uint8 k, uint8 a) {  // 0da57f
  int8 v6;

  R0_ = a;
  if (k >= 0x18 && k < 0x1D) {
    uint8 v2 = ow_level_number_lo >> 3;
    uint8 v3 = ow_level_number_lo & 7;
    if (R0_ == 8) {
      if ((kBitTable_Bank0D[v3] & flag_collected_moons[v2]) != 0)
        return;
    } else if ((kBitTable_Bank0D[v3] & flag_collected1up_checkpoints[v2]) != 0) {
      return;
    }
  }
  uint8 v4 = blocks_sub_scr_pos;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  uint8 v5 = R0_;
  if ((int8)(R0_ - 19) >= 0)
    SetMap16HighByteForCurrentObject_Page01(v4);
  R12_ = kExtObjXX_Generic1TileObject_Tiles[v5];
  if (v5 == 1 || v5 == 7 || v5 == 50 || v5 == 38 ||
      v5 == 27 && ((v6 = v4 & 0xF, (v4 & 0xF) == 1) || v6 == 4 || v6 == 7 || v6 == 10 || v6 == 13)) {
    R8_W = PAIR16(kBank0DItemMemoryIndexes_Hi[misc_item_memory_setting], kBank0DItemMemoryIndexes_Lo[misc_item_memory_setting]) + 0x19f8;
    R14_ = 4 * blocks_screen_to_place_next_object;
    if ((R10_ & 0x10) != 0)
      R14_ |= 2;
    if ((v4 & 8) != 0)
      R14_ |= 1;
    R15_ = kBitTable_Bank0D[blocks_sub_scr_pos & 7] & RomPtr_RAM(R8_W)[R14_];
    if (R15_) {
      if (v5 == 7)
        return;
      SetMap16HighByteForCurrentObject_Page01(v4);
      R12_ = 50;
    }
  }
  IndirWriteByte(&ptr_lo_map16_data, v4, R12_);
}

void ExtObjXX_Generic1TileObject_GreenStarBlockEntry(uint8 k) {  // 0da64d
  ExtObjXX_Generic1TileObject_0DA57F(k, 0x32);
}

void ExtObj42_TopLeftSlope(uint8 k) {  // 0da656
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = k - 66;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kExtObj42_TopLeftSlope_LeftTiles[v2]);
  IndirWriteByte(&ptr_lo_map16_data, v3, kExtObj42_TopLeftSlope_RightTiles[v2]);
  SetMap16HighByteForCurrentObject_Page01(v3);
}

void ExtObjXX_PurpleTriangle(uint8 k) {  // 0da673
  uint8 v1 = blocks_sub_scr_pos;
  IndirWriteByte(&ptr_lo_map16_data, blocks_sub_scr_pos, kExtObjXX_PurpleTriangle_TriangleTiles[(uint8)(k - 68)]);
  SetMap16HighByteForCurrentObject_Page01(v1);
  uint8 v2 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  IndirWriteByte(&ptr_lo_map16_data, v2, 0xEB);
  SetMap16HighByteForCurrentObject_Page01(v2);
}

void ExtObj46_MidwayBar(uint8 k) {  // 0da68e
  if ((ow_level_tile_settings[ow_level_number_lo] & 0x40) == 0 && !flag_got_midpoint) {
    uint8 v1 = blocks_sub_scr_pos - 1;
    SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos - 1);
    uint8 v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x35);
    SetMap16HighByteForCurrentObject_Page00(v2);
    IndirWriteByte(&ptr_lo_map16_data, v2, 0x38);
  }
}

void PreserveLevelDataPointerInObjects() {  // 0da6b1
  uint16 v0 = ptr_lo_map16_data;
  R5_ = HIBYTE(v0);
  R4_ = v0;
}

void RestoreLevelDataPointerInObjects() {  // 0da6ba
  ptr_lo_map16_data = __PAIR16__(R5_, R4_);
  ptr_hi_map16_data = __PAIR16__(R5_, R4_);
  blocks_screen_to_place_next_object = blocks_screen_to_place_current_object;
}

void ExtObj47_Door(uint8 k) {  // 0da6d1
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = k - 71;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v1, kExtObj47_Door_TopTiles[v2]);
  uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  SetMap16HighByteForCurrentObject_Page00(v3);
  IndirWriteByte(&ptr_lo_map16_data, v3, kExtObj47_Door_BottomTiles[v2]);
}

void ExtObjXX_LargeBush_BigBushEntry(uint8 k) {  // 0da71b
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = 8;
  R1_ = 4;
  uint8 v2 = 0;
  PreserveLevelDataPointerInObjects();
  do {
    R2_ = R0_;
    do {
      SetMap16HighByteForCurrentObject_Page00(v1);
      v1 = ExtObjXX_LargeBush_HandleOverlappingBigBushTiles(v1, kExtObjXX_LargeBush_BigBushTiles[v2++]);
      --R2_;
    } while ((R2_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R1_;
  } while ((R1_ & 0x80) == 0);
}

void ExtObjXX_LargeBush_SmallBushEntry(uint8 k) {  // 0da760
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = 5;
  R1_ = 3;
  uint8 v2 = 0;
  PreserveLevelDataPointerInObjects();
  do {
    R2_ = R0_;
    do {
      SetMap16HighByteForCurrentObject_Page00(v1);
      v1 = ExtObjXX_LargeBush_HandleOverlappingBigBushTiles(v1, kExtObjXX_LargeBush_SmallBushTiles[v2++]);
      --R2_;
    } while ((R2_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R1_;
  } while ((R1_ & 0x80) == 0);
}

uint8 ExtObjXX_LargeBush_HandleOverlappingBigBushTiles(uint8 j, uint8 a) {  // 0da78d
  R15_ = a;
  if (a == 37) {
    return HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(j);
  } else {
    if (a >= 0x54) {
      uint8 v2 = *IndirPtr(&ptr_lo_map16_data, j);
      if (v2 != 37) {
        if (v2 != 73)
          ++R15_;
        ++R15_;
      }
    }
    return HandleHorizontalSubScreenCrossingForCurrentObject(j, R15_);
  }
}

void ExtObj4A_ClimbingNetDoor(uint8 k) {  // 0da7c1
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = 0;
  PreserveLevelDataPointerInObjects();
  do {
    R2_ = 3;
    do {
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kExtObj4A_ClimbingNetDoor_Tiles[v1++]);
      --R2_;
    } while ((R2_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while (v1 != 16);
}

void ExtObj86_GoalSign(uint8 k) {  // 0da7e7
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = 0;
  PreserveLevelDataPointerInObjects();
  do {
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kExtObj86_GoalSign_Tiles[v1++]);
    } while ((v1 & 1) != 0);
    RestoreLevelDataPointerInObjects();
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while (v1 != 4);
}

void ExtObj91_VerticalLevelSteepLeftSlope(uint8 k) {  // 0da80d
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = k + 111;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v1, kExtObj91_VerticalLevelSteepLeftSlope_TopTiles[v2]);
  uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_VerticalLevel();
  SetMap16HighByteForCurrentObject_Page01(v3);
  IndirWriteByte(&ptr_lo_map16_data, v3, kExtObj91_VerticalLevelSteepLeftSlope_BottomTiles[v2]);
}

uint8 HandleVerticalSubScreenCrossingForCurrentObject_VerticalLevel() {  // 0da82a
  uint16 t = blocks_sub_scr_pos + 16;
  blocks_sub_scr_pos = t;
  if (t >= 256)
    HIBYTE(ptr_hi_map16_data) = (HIBYTE(ptr_lo_map16_data) += 2);
  return t;
}

void ExtObj93_VerticalLevelNormalLeftSlope(uint8 k) {  // 0da846
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = k + 109;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kExtObj93_VerticalLevelNormalLeftSlope_TopLeftTiles[v2]);
  SetMap16HighByteForCurrentObject_Page01(v3);
  IndirWriteByte(&ptr_lo_map16_data, v3, kExtObj93_VerticalLevelNormalLeftSlope_TopRightTiles[v2]);
  uint8 v4 = HandleVerticalSubScreenCrossingForCurrentObject_VerticalLevel();
  SetMap16HighByteForCurrentObject_Page01(v4);
  uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, kExtObj93_VerticalLevelNormalLeftSlope_BottomLeftTiles[v2]);
  SetMap16HighByteForCurrentObject_Page01(v5);
  IndirWriteByte(&ptr_lo_map16_data, v5, kExtObj93_VerticalLevelNormalLeftSlope_BottomRightTiles[v2]);
}

void ExtObj95_VerticalLevelVerySteepLeftSlope(uint8 k) {  // 0da87d
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = k + 107;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v1, kExtObj95_VerticalLevelVerySteepLeftSlope_TopTiles[v2]);
  uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_VerticalLevel();
  SetMap16HighByteForCurrentObject_Page01(v3);
  IndirWriteByte(&ptr_lo_map16_data, v3, kExtObj95_VerticalLevelVerySteepLeftSlope_MiddleTiles[v2]);
  uint8 v4 = HandleVerticalSubScreenCrossingForCurrentObject_VerticalLevel();
  SetMap16HighByteForCurrentObject_Page01(v4);
  IndirWriteByte(&ptr_lo_map16_data, v4, kExtObj95_VerticalLevelVerySteepLeftSlope_BottomTiles[v2]);
}

void StdObj05_Coins(uint8 k) {  // 0da8c3
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R2_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  while (1) {
    if (k != 4)
      goto LABEL_9;
    R8_W = PAIR16(kBank0DItemMemoryIndexes_Hi[misc_item_memory_setting], kBank0DItemMemoryIndexes_Lo[misc_item_memory_setting]) + 0x19f8;
    R14_ = 4 * blocks_screen_to_place_next_object;
    if ((R10_ & 0x10) != 0)
      R14_ |= 2;
    if ((v1 & 8) != 0)
      R14_ |= 1;
    R15_ = kBitTable_Bank0D[v1 & 7] & RomPtr_RAM(R8_W)[R14_];
    k = 4;
    if (R15_) {
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(v1);
    } else {
LABEL_9:
      R12_ = kStdObjXX_Generic1RepeatedTileObject_Tiles[k];
      SetMap16HighByteForCurrentObject_Page00(v1);
      if ((int8)(k - 7) >= 0)
        SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, R12_);
    }
    if ((--R2_ & 0x80) != 0) {
      RestoreLevelDataPointerInObjects();
      v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      R2_ = R0_;
      if ((--R1_ & 0x80) != 0)
        break;
    }
  }
}

uint8 HandleHorizontalSubScreenCrossingForCurrentObject(uint8 j, uint8 a) {  // 0da95b
  IndirWriteByte(&ptr_lo_map16_data, j, a);
  return HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(j);
}

uint8 HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(uint8 j) {  // 0da95d
  uint8 result = j + 1;
  if ((result & 0xF) == 0) {
    ptr_lo_map16_data += 0x1b0;
    ptr_hi_map16_data = ptr_lo_map16_data;
    ++blocks_screen_to_place_next_object;
    result = blocks_sub_scr_pos & 0xF0;
  }
  return result;
}

uint8 HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel() {  // 0da97d
  if (blocks_sub_scr_pos + 16 >= 256)
    HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
  blocks_sub_scr_pos += 16;
  return blocks_sub_scr_pos;
}

void HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(uint8 cr) {  // 0da987
  HIBYTE(ptr_lo_map16_data) += cr;
  HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
  R5_ = HIBYTE(ptr_lo_map16_data);
}

uint8 GoDownLeftAndUpdateLevelDataPointerInObjects() {  // 0da992
  uint8 result = blocks_sub_scr_pos + 15;
  if (blocks_sub_scr_pos + 15 >= 256)
    HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
  if ((result & 0xF) == 15) {
    if (result + 16 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    result += 16;
    GoBackOneScreenAndUpdateLevelDataPointerInObjects();
  }
  blocks_sub_scr_pos = result;
  return result;
}

uint8 GoDownRightAndUpdateLevelDataPointerInObjects() {  // 0da9b4
  uint8 v0 = blocks_sub_scr_pos + 17;
  if (blocks_sub_scr_pos + 17 >= 256)
    HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
  if (sign8((v0 & 0xF) - 1)) {
    bool v1 = v0 >= 0x10;
    if (!v1)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(v1);
    v0 -= 16;
    GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
  }
  blocks_sub_scr_pos = v0;
  return v0;
}

void GoBackOneScreenAndUpdateLevelDataPointerInObjects() {  // 0da9d6
  ptr_lo_map16_data -= 0x1b0;
  ptr_hi_map16_data = ptr_lo_map16_data;
  R4_W = ptr_lo_map16_data;
  --blocks_screen_to_place_next_object;
}

void GoForwardOneScreenAndUpdateLevelDataPointerInObjects() {  // 0da9ef
  ptr_lo_map16_data += 0x1b0;
  ptr_hi_map16_data = ptr_lo_map16_data;
  R4_W = ptr_lo_map16_data;
  ++blocks_screen_to_place_next_object;
}

void SetMap16HighByteForCurrentObject_Page01(uint8 j) {  // 0daa08
  IndirWriteByte(&ptr_hi_map16_data, j, 1);
}

void SetMap16HighByteForCurrentObject_Page00(uint8 j) {  // 0daa0d
  IndirWriteByte(&ptr_hi_map16_data, j, 0);
}

void StdObj0F_VerticalPipes(uint8 k) {  // 0daa26
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  uint8 v2 = blocks_size_or_type & 0xF;
  PreserveLevelDataPointerInObjects();
  if ((int8)(v2 - 3) >= 0)
    goto LABEL_3;
  SetMap16HighByteForCurrentObject_Page01(v1);
  uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kStdObj0F_VerticalPipes_TopLeftPipeEndTiles[v2]);
  SetMap16HighByteForCurrentObject_Page01(v3);
  IndirWriteByte(&ptr_lo_map16_data, v3, kStdObj0F_VerticalPipes_TopRightPipeEndTiles[v2]);
  while (1) {
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if (v2 != 5 && (int8)(v2 - 2) >= 0)
      break;
    if ((--R0_ & 0x80) != 0)
      return;
LABEL_3:
    if (v2 == 5) {
      SetMap16HighByteForCurrentObject_Page01(v1);
      uint8 v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x68);
      SetMap16HighByteForCurrentObject_Page01(v4);
      IndirWriteByte(&ptr_lo_map16_data, v4, 0x69);
    } else {
LABEL_5:
      SetMap16HighByteForCurrentObject_Page01(v1);
      uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x35);
      SetMap16HighByteForCurrentObject_Page01(v5);
      IndirWriteByte(&ptr_lo_map16_data, v5, 0x36);
    }
  }
  if (--R0_)
    goto LABEL_5;
  SetMap16HighByteForCurrentObject_Page01(v1);
  uint8 v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kStdObj0F_VerticalPipes_BottomLeftPipeEndTiles[v2]);
  SetMap16HighByteForCurrentObject_Page01(v6);
  IndirWriteByte(&ptr_lo_map16_data, v6, kStdObj0F_VerticalPipes_BottomRightPipeEndTiles[v2]);
}

void StdObj10_HorizontalPipes(uint8 k) {  // 0daab4
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type & 0xF;
  uint8 v2 = (uint8)(blocks_size_or_type & 0xF0) >> 3;
  PreserveLevelDataPointerInObjects();
  while (1) {
    if ((int8)(v2 - 4) < 0) {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kStdObj10_HorizontalPipes_EndTiles[v2]);
      goto LABEL_5;
    }
    while (1) {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kStdObj10_HorizontalPipes_ShaftTiles[v2]);
LABEL_5:
      if ((int8)(v2 - 4) >= 0)
        break;
      if ((--R1_ & 0x80) != 0)
        goto LABEL_10;
    }
    if (!--R1_) {
      SetMap16HighByteForCurrentObject_Page01(v1);
      IndirWriteByte(&ptr_lo_map16_data, v1, kStdObj10_HorizontalPipes_EndTiles[v2]);
LABEL_10:
      R1_ = R0_;
      RestoreLevelDataPointerInObjects();
      v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      if ((++v2 & 1) == 0)
        break;
    }
  }
}

void StdObj11_BulletShooter(uint8 k) {  // 0dab0d
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type >> 4;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v1, 0x41);
  uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  int8 v4 = v2 - 1;
  if (v4 >= 0) {
    SetMap16HighByteForCurrentObject_Page01(v3);
    IndirWriteByte(&ptr_lo_map16_data, v3, 0x42);
    uint8 v5 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    for (int8 i = v4 - 1; i >= 0; --i) {
      SetMap16HighByteForCurrentObject_Page01(v5);
      IndirWriteByte(&ptr_lo_map16_data, v5, 0x43);
      v5 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    }
  }
}

void StdObj12_Slopes(uint8 k) {  // 0dab3e
  uint8 i;
  for (i = blocks_size_or_type & 0xF; !sign8(i - 10); i -= 10)
    ;
  kStdObj12_Slopes_SlopesPtrs[i]();
}

void StdObj12_SlopesLeftSlope() {  // 0dab6e
  bool v8;

  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 1;
  R0_ = 1;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  while (1) {
    uint8 v1 = R2_;
    SetMap16HighByteForCurrentObject_Page01(v0);
    uint8 v2 = FillInSlopeTileAir(v0, 0x96);
    SetMap16HighByteForCurrentObject_Page01(v2);
    uint8 v3 = FillInSlopeTileAir(v2, 0x9B);
    int8 v4 = v1 - 2;
    if (v4 < 0)
      goto LABEL_6;
    while (1) {
      SetMap16HighByteForCurrentObject_Page01(v3);
      uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xDE);
      SetMap16HighByteForCurrentObject_Page01(v5);
      uint8 v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, 0xE6);
      int8 v7 = v4 - 1;
      while (--v7 >= 0) {
        SetMap16HighByteForCurrentObject_Page00(v6);
        v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, 0x3F);
      }
LABEL_6:
      RestoreLevelDataPointerInObjects();
      ++R2_;
      ++R2_;
      v8 = (--R0_ & 0x80) != 0;
      if (R0_)
        break;
      v4 = R2_ - 2;
      v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    }
    if (v8)
      break;
    v0 = blocks_sub_scr_pos + 14;
    if (blocks_sub_scr_pos + 14 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if (!sign8((v0 & 0xF) - 14)) {
      if (v0 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v0 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v0;
  }
}

uint8 FillInSlopeTileAir(uint8 j, uint8 a) {  // 0dabfd
  R12_ = a;
  uint8 v2 = 2;
  uint8 v3 = *IndirPtr(&ptr_lo_map16_data, j);
  while (v3 != kFillInSlopeTileAir_DATA_0DABF7[v2]) {
    if ((--v2 & 0x80) != 0)
      return HandleHorizontalSubScreenCrossingForCurrentObject(j, R12_);
  }
  R12_ += kFillInSlopeTileAir_DATA_0DABFA[v2];
  return HandleHorizontalSubScreenCrossingForCurrentObject(j, R12_);
}

void StdObj12_Slopes_SteepLeftSlope() {  // 0dac21
  uint8 v0 = blocks_sub_scr_pos;
  R0_ = (blocks_size_or_type >> 4) + 1;
  R2_ = 0;
  PreserveLevelDataPointerInObjects();
  bool v5;
  while (1) {
    uint8 v1 = R2_;
    SetMap16HighByteForCurrentObject_Page01(v0);
    for (uint8 i = FillInSlopeTileAir(v0, 0xAA);; i = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel()) {
      int8 v3 = v1 - 1;
      if (v3 >= 0) {
        SetMap16HighByteForCurrentObject_Page01(i);
        for (uint8 j = HandleHorizontalSubScreenCrossingForCurrentObject(i, 0xE2); --v3 >= 0;
             j = HandleHorizontalSubScreenCrossingForCurrentObject(j, 0x3F)) {
          SetMap16HighByteForCurrentObject_Page00(j);
        }
      }
      RestoreLevelDataPointerInObjects();
      ++R2_;
      v5 = (--R0_ & 0x80) != 0;
      if (R0_)
        break;
      v1 = R2_;
    }
    if (v5)
      break;
    v0 = blocks_sub_scr_pos + 15;
    if (blocks_sub_scr_pos + 15 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if ((v0 & 0xF) == 15) {
      if (v0 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v0 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v0;
  }
}

void StdObj12_Slopes_GradualLeftSlope() {  // 0dac92
  bool v12;
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 3;
  R0_ = 3;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  while (1) {
    uint8 v1 = R2_;
    SetMap16HighByteForCurrentObject_Page01(v0);
    uint8 v2 = FillInSlopeTileAir(v0, 0x6E);
    SetMap16HighByteForCurrentObject_Page01(v2);
    uint8 v3 = FillInSlopeTileAir(v2, 0x73);
    SetMap16HighByteForCurrentObject_Page01(v3);
    uint8 v4 = FillInSlopeTileAir(v3, 0x78);
    SetMap16HighByteForCurrentObject_Page01(v4);
    uint8 v5 = FillInSlopeTileAir(v4, 0x7D);
    int8 v6 = v1 - 4;
    if (v6 < 0)
      goto LABEL_6;
    while (1) {
      SetMap16HighByteForCurrentObject_Page01(v5);
      uint8 v7 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, 0xD8);
      SetMap16HighByteForCurrentObject_Page01(v7);
      uint8 v8 = HandleHorizontalSubScreenCrossingForCurrentObject(v7, 0xDA);
      SetMap16HighByteForCurrentObject_Page01(v8);
      uint8 v9 = HandleHorizontalSubScreenCrossingForCurrentObject(v8, 0xE6);
      SetMap16HighByteForCurrentObject_Page01(v9);
      uint8 v10 = HandleHorizontalSubScreenCrossingForCurrentObject(v9, 0xE6);
      int8 v11 = v6 - 3;
      while (--v11 >= 0) {
        SetMap16HighByteForCurrentObject_Page00(v10);
        v10 = HandleHorizontalSubScreenCrossingForCurrentObject(v10, 0x3F);
      }
LABEL_6:
      RestoreLevelDataPointerInObjects();
      R2_ += 4;
      v12 = (--R0_ & 0x80) != 0;
      if (R0_)
        break;
      v6 = R2_ - 4;
      v5 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    }
    if (v12)
      break;
    v0 = blocks_sub_scr_pos + 12;
    if (blocks_sub_scr_pos + 12 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if (!sign8((v0 & 0xF) - 12)) {
      if (v0 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v0 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v0;
  }
}

void StdObj12_SlopesRightSlope() {  // 0dad44
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 1;
  R0_ = 1;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  do {
    SetMap16HighByteForCurrentObject_Page01(v0);
    uint8 v4 = FillInSlopeTileAir(v0, 0xA0);
    SetMap16HighByteForCurrentObject_Page01(v4);
    FillInSlopeTileAir(v4, 0xA5);
    RestoreLevelDataPointerInObjects();
    uint8 v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    ++R2_;
    uint8 v2 = ++R2_;
    if ((--R0_ & 0x80) != 0)
      break;
    while (v2 != 3) {
      SetMap16HighByteForCurrentObject_Page00(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x3F);
      --v2;
    }
    SetMap16HighByteForCurrentObject_Page01(v1);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xE6);
    SetMap16HighByteForCurrentObject_Page01(v3);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xE0);
  } while (R0_);
}

void StdObj12_Slopes_SteepRightSlope() {  // 0dada3
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 0;
  R0_ = 0;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  while (R0_) {
    SetMap16HighByteForCurrentObject_Page01(v0);
    FillInSlopeTileAir(v0, 0xAF);
    RestoreLevelDataPointerInObjects();
    uint8 v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    uint8 v2 = ++R2_;
    if ((--R0_ & 0x80) != 0)
      break;
    while (v2 != 1) {
      SetMap16HighByteForCurrentObject_Page00(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x3F);
      --v2;
    }
    SetMap16HighByteForCurrentObject_Page01(v1);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xE4);
  }
}

void StdObj12_Slopes_GradualRightSlope() {  // 0dadeb
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 3;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  do {
    SetMap16HighByteForCurrentObject_Page01(v0);
    uint8 v6 = FillInSlopeTileAir(v0, 0x82);
    SetMap16HighByteForCurrentObject_Page01(v6);
    uint8 v7 = FillInSlopeTileAir(v6, 0x87);
    SetMap16HighByteForCurrentObject_Page01(v7);
    uint8 v8 = FillInSlopeTileAir(v7, 0x8C);
    SetMap16HighByteForCurrentObject_Page01(v8);
    FillInSlopeTileAir(v8, 0x91);
    RestoreLevelDataPointerInObjects();
    uint8 v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    R2_ += 4;
    uint8 v2 = R2_;
    if ((--R0_ & 0x80) != 0)
      break;
    while (v2 != 7) {
      SetMap16HighByteForCurrentObject_Page00(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x3F);
      --v2;
    }
    SetMap16HighByteForCurrentObject_Page01(v1);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xE6);
    SetMap16HighByteForCurrentObject_Page01(v3);
    uint8 v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xE6);
    SetMap16HighByteForCurrentObject_Page01(v4);
    uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0xDB);
    SetMap16HighByteForCurrentObject_Page01(v5);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, 0xDC);
  } while (R0_);
}

void StdObj12_Slopes_UpsideDownNormalLeftSlope() {  // 0dae6d
  uint8 v0 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  R2_ = 2 * (blocks_size_or_type >> 4);
  --R2_;
  R1_ = 0;
  int8 v1 = R2_;
  PreserveLevelDataPointerInObjects();
LABEL_3:
  SetMap16HighByteForCurrentObject_Page01(v0);
  uint8 v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xEE);
  SetMap16HighByteForCurrentObject_Page01(v4);
  uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0xF0);
  int8 v6 = v1 - 1;
  while (--v6 >= 0) {
    SetMap16HighByteForCurrentObject_Page01(v5);
    v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, 0x65);
  }
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v7;
    if (R1_) {
      R2_ -= 2;
      v7 = blocks_sub_scr_pos + 18;
      if (blocks_sub_scr_pos + 18 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      if (sign8((v7 & 0xF) - 2)) {
        bool v8 = v7 >= 0x10;
        v7 -= 16;
        if (!v8)
          HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(v8);
        GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
      }
    } else {
      ++R1_;
      v7 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    }
    blocks_sub_scr_pos = v7;
    if ((--R0_ & 0x80) != 0)
      break;
    uint8 v2 = R2_;
    SetMap16HighByteForCurrentObject_Page01(v7);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v7, 0xC6);
    SetMap16HighByteForCurrentObject_Page01(v3);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xC7);
    v1 = v2 - 2;
    if (v1 >= 0)
      goto LABEL_3;
  }
}

void StdObj12_Slopes_UpsideDownNormalRightSlope() {  // 0daefc
  uint8 v0 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  R2_ = 2 * (blocks_size_or_type >> 4);
  ++R2_;
  R1_ = 0;
  PreserveLevelDataPointerInObjects();
  uint8 v1 = R2_;
  uint8 v2;
  do {
    while ((int8)(v1 - 4) >= 0) {
      SetMap16HighByteForCurrentObject_Page01(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0x65);
      --v1;
    }
    if ((int8)(v1 - 2) < 0 ||
        (SetMap16HighByteForCurrentObject_Page01(v0), v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xF0),
         SetMap16HighByteForCurrentObject_Page01(v2), v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, 0xEF), R1_)) {
      SetMap16HighByteForCurrentObject_Page01(v0);
      uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xC8);
      SetMap16HighByteForCurrentObject_Page01(v3);
      HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xC9);
    }
    RestoreLevelDataPointerInObjects();
    R2_ -= 2;
    v1 = R2_;
    ++R1_;
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void StdObj12_Slopes_UpsideDownSteepLeftSlope() {  // 0daf61
  uint8 v0 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  R2_ = (blocks_size_or_type >> 4) - 1;
  R1_ = 0;
  int8 v1 = (blocks_size_or_type >> 4) - 1;
  PreserveLevelDataPointerInObjects();
LABEL_3:
  SetMap16HighByteForCurrentObject_Page01(v0);
  for (uint8 i = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xEC); --v1 >= 0;
       i = HandleHorizontalSubScreenCrossingForCurrentObject(i, 0x65)) {
    SetMap16HighByteForCurrentObject_Page01(i);
  }
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v4;
    if (R1_) {
      --R2_;
      v4 = blocks_sub_scr_pos + 17;
      if (blocks_sub_scr_pos + 17 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      if (sign8((v4 & 0xF) - 1)) {
        bool v5 = v4 >= 0x10;
        v4 -= 16;
        if (!v5)
          StdObj12_Slopes_0DAFDF(v5);
        GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
      }
    } else {
      ++R1_;
      v4 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    }
    blocks_sub_scr_pos = v4;
    if ((--R0_ & 0x80) != 0)
      break;
    uint8 v2 = R2_;
    SetMap16HighByteForCurrentObject_Page01(v4);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0xC4);
    v1 = v2 - 1;
    if (v1 >= 0)
      goto LABEL_3;
  }
}

void StdObj12_Slopes_0DAFDF(uint8 cr) {  // 0dafdf
  HIBYTE(ptr_lo_map16_data) -= !(cr & 1);
  HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
  R5_ = HIBYTE(ptr_lo_map16_data);
}

void StdObj12_Slopes_UpsideDownSteepRightSlope() {  // 0dafea
  uint8 v0 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  R2_ = blocks_size_or_type >> 4;
  R1_ = 0;
  PreserveLevelDataPointerInObjects();
  uint8 v1 = R2_;
  do {
    while ((int8)(v1 - 2) >= 0) {
      SetMap16HighByteForCurrentObject_Page01(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0x65);
      --v1;
    }
    if ((int8)(v1 - 1) < 0 ||
        (SetMap16HighByteForCurrentObject_Page01(v0), v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xED), R1_)) {
      SetMap16HighByteForCurrentObject_Page01(v0);
      HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xC5);
    }
    RestoreLevelDataPointerInObjects();
    v1 = --R2_;
    ++R1_;
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void StdObj13_GroundEdgesAndVine(uint8 k) {  // 0db075
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  uint8 v2 = blocks_size_or_type & 0xF;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  if ((int8)(v2 - 3) >= 0)
    SetMap16HighByteForCurrentObject_Page01(v1);
  uint8 v3 = StdObj13_GroundEdgesAndVine_0DB114(v2, v1, kStdObj13_GroundEdgesAndVine_TopTiles[v2]);
  IndirWriteByte(&ptr_lo_map16_data, v1, v3);
  uint8 v4 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  if ((--R0_ & 0x80) == 0) {
    SetMap16HighByteForCurrentObject_Page00(v4);
    if ((int8)(v2 - 9) >= 0 || (int8)(v2 - 7) < 0 && (int8)(v2 - 3) >= 0)
      SetMap16HighByteForCurrentObject_Page01(v4);
    uint8 v5 = StdObj13_GroundEdgesAndVine_0DB198(v2, v4, kStdObj13_GroundEdgesAndVine_MiddleTiles1[v2]);
    IndirWriteByte(&ptr_lo_map16_data, v4, v5);
    v4 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R0_ & 0x80) == 0) {
      do {
        SetMap16HighByteForCurrentObject_Page00(v4);
        if ((int8)(v2 - 9) >= 0 || (int8)(v2 - 7) < 0 && (int8)(v2 - 3) >= 0)
          SetMap16HighByteForCurrentObject_Page01(v4);
        uint8 v6 = StdObj13_GroundEdgesAndVine_0DB198(v2, v4, kStdObj13_GroundEdgesAndVine_MiddleTiles2[v2]);
        IndirWriteByte(&ptr_lo_map16_data, v4, v6);
        v4 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
        --R0_;
      } while ((R0_ & 0x80) == 0);
    }
  }
  if ((int8)(v2 - 11) >= 0) {
    SetMap16HighByteForCurrentObject_Page01(v4);
    IndirWriteByte(&ptr_lo_map16_data, v4, kStdObj13_GroundEdgesAndVine_BottomTiles[v2]);
  }
}

uint8 StdObj13_GroundEdgesAndVine_0DB114(uint8 k, uint8 j, uint8 a) {  // 0db114
  if (((int8)(k - 3) < 0 || (int8)(k - 9) < 0 || (int8)(k - 11) >= 0) && k != 2) {
    R11_ = k;
    R12_ = a;
    uint8 v3 = 17;
    uint8 v4 = *IndirPtr(&ptr_lo_map16_data, j);
    do {
      if (v4 == kStdObj13_GroundEdgesAndVine_DATA_0DB0F0[v3]) {
        SetMap16HighByteForCurrentObject_Page01(j);
        return kStdObj13_GroundEdgesAndVine_DATA_0DB102[v3];
      }
      --v3;
    } while ((v3 & 0x80) == 0);
    if (v4 != 37 && (R12_ == 1 || R12_ == 3 || R12_ == 69 || R12_ == 72))
      ++R12_;
    return R12_;
  }
  return a;
}

uint8 StdObj13_GroundEdgesAndVine_0DB198(uint8 k, uint8 j, uint8 a) {  // 0db198
  if (((int8)(k - 3) < 0 || (int8)(k - 7) >= 0 && (int8)(k - 9) < 0) && k != 2) {
    R11_ = k;
    R12_ = a;
    uint8 v3 = 29;
    uint8 v4 = *IndirPtr(&ptr_lo_map16_data, j);
    while (v4 != kStdObj13_GroundEdgesAndVine_DATA_0DB15C[v3]) {
      if ((--v3 & 0x80) != 0)
        return R12_;
    }
    SetMap16HighByteForCurrentObject_Page01(j);
    return kStdObj13_GroundEdgesAndVine_DATA_0DB17A[v3];
  }
  return a;
}

void StdObj21_WideScaleGroundLedge(uint8 k) {  // 0db1c8
  R0_ = blocks_size_or_type;
  R2_ = 2;
  StdObj21_WideScaleGroundLedge_0DB1E3(blocks_size_or_type);
}

void StdObj21_WideScaleGroundLedge_StandardLedgeEntry(uint8 k) {  // 0db1d4
  R0_ = blocks_size_or_type & 0xF;
  R2_ = blocks_size_or_type >> 4;
  StdObj21_WideScaleGroundLedge_0DB1E3(blocks_size_or_type & 0xF);
}

void StdObj21_WideScaleGroundLedge_0DB1E3(uint8 k) {  // 0db1e3
  PreserveLevelDataPointerInObjects();
  uint8 v1 = blocks_sub_scr_pos;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0);
    --k;
  } while (k != 0xFF);
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v2 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    uint8 v3 = R0_;
    if ((--R2_ & 0x80) != 0)
      break;
    do {
      SetMap16HighByteForCurrentObject_Page00(v2);
      v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, 0x3F);
      --v3;
    } while (v3 != 0xFF);
  }
}

void StdObj15_MidwayAndGoalPoint(uint8 k) {  // 0db224
  uint8 v1 = blocks_sub_scr_pos;
  R2_ = blocks_size_or_type & 0xF;
  R0_ = blocks_size_or_type >> 4;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  for (uint8 i = 0; i != 3; ++i) {
    R3_ = kStdObj15_MidwayAndGoalPoint_TopMidwayTiles[i];
    if (R2_)
      R3_ = kStdObj15_MidwayAndGoalPoint_TopGoalTiles[i];
    SetMap16HighByteForCurrentObject_Page00(v1);
    IndirWriteByte(&ptr_lo_map16_data, v1, R3_);
    if (v1 + 16 >= 256) {
      HIBYTE(ptr_lo_map16_data) += 1;
      HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
    }
    uint8 v4 = v1 + 16;
    if (--R1_) {
      do {
        R3_ = kStdObj15_MidwayAndGoalPoint_MiddleMidwayTiles[i];
        if (R2_)
          R3_ = kStdObj15_MidwayAndGoalPoint_MiddleGoalTiles[i];
        SetMap16HighByteForCurrentObject_Page00(v4);
        IndirWriteByte(&ptr_lo_map16_data, v4, R3_);
        if (v4 + 16 >= 256) {
          HIBYTE(ptr_lo_map16_data) += 1;
          HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
        }
        v4 += 16;
      } while (--R1_);
    }
    R3_ = kStdObj15_MidwayAndGoalPoint_BottomMidwayTiles[i];
    if (R2_)
      R3_ = kStdObj15_MidwayAndGoalPoint_BottomGoalTiles[i];
    SetMap16HighByteForCurrentObject_Page00(v4);
    IndirWriteByte(&ptr_lo_map16_data, v4, R3_);
    RestoreLevelDataPointerInObjects();
    v1 = blocks_sub_scr_pos + 1;
    if (((blocks_sub_scr_pos + 1) & 0xF) == 0) {
      GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
      v1 = blocks_sub_scr_pos & 0xF0;
    }
    blocks_sub_scr_pos = v1;
    R1_ = R0_;
  }
}

void ExtObj41_YoshiCoin(uint8 k) {  // 0db2ca
  if ((kBitTable_Bank0D[ow_level_number_lo & 7] & flag_collected5_yoshi_coins[ow_level_number_lo >> 3]) == 0) {
    R8_W = PAIR16(kBank0DItemMemoryIndexes_Hi[misc_item_memory_setting], kBank0DItemMemoryIndexes_Lo[misc_item_memory_setting]) + 0x19f8;
    R14_ = 4 * blocks_screen_to_place_next_object;
    if ((R10_ & 0x10) != 0)
      R14_ |= 2;
    if ((blocks_sub_scr_pos & 8) != 0)
      R14_ |= 1;
    if ((kBitTable_Bank0D[blocks_sub_scr_pos & 7] & RomPtr_RAM(R8_W)[R14_]) == 0) {
      uint8 v2 = blocks_sub_scr_pos;
      SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
      IndirWriteByte(&ptr_lo_map16_data, v2, 0x2D);
      uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      SetMap16HighByteForCurrentObject_Page00(v3);
      IndirWriteByte(&ptr_lo_map16_data, v3, 0x2E);
    }
  }
}

void StdObj16_PurpleCoins(uint8 k) {  // 0db336
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  int8 v2 = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  while (1) {
    R8_W = PAIR16(kBank0DItemMemoryIndexes_Hi[misc_item_memory_setting], kBank0DItemMemoryIndexes_Lo[misc_item_memory_setting]) + 0x19f8;
    R14_ = 4 * blocks_screen_to_place_next_object;
    if ((R10_ & 0x10) != 0)
      R14_ |= 2;
    if ((v1 & 8) != 0)
      R14_ |= 1;
    R15_ = kBitTable_Bank0D[v1 & 7] & RomPtr_RAM(R8_W)[R14_];
    SetMap16HighByteForCurrentObject_Page00(v1);
    R12_ = 44;
    if (R15_)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(0);
    else
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, R12_);
    if (--v2 < 0) {
      RestoreLevelDataPointerInObjects();
      v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      v2 = R0_;
      if ((--R1_ & 0x80) != 0)
        break;
    }
  }
}

void StdObj17_RopeAndCloudLine(uint8 k) {  // 0db3bd
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kStdObj17_RopeAndCloudLine_Tiles[v2]);
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void RopeObj2E_Unused(uint8 k) {  // 0db3e3
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R2_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  uint8 v2 = k - 23;
  PreserveLevelDataPointerInObjects();
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kStdObj18_WaterWithAnimatedSurface_TopTiles[v2]);
    --R2_;
  } while ((R2_ & 0x80) == 0);
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    R2_ = R0_;
    if ((--R1_ & 0x80) != 0)
      break;
    do {
      SetMap16HighByteForCurrentObject_Page00(v3);
      v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, kStdObj18_WaterWithAnimatedSurface_BottomTiles[v2]);
      --R2_;
    } while ((R2_ & 0x80) == 0);
  }
}

void StdObj1C_DonutBridge(uint8 k) {  // 0db42d
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type & 0xF;
  PreserveLevelDataPointerInObjects();
  uint8 v2 = 0;
  while (1) {
    SetMap16HighByteForCurrentObject_Page00(v1);
    if (v2)
      SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kStdObj1C_DonutBridge_Tiles[v2]);
    if ((--R1_ & 0x80) != 0) {
      RestoreLevelDataPointerInObjects();
      v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      R1_ = R0_;
      if (++v2 == 2)
        break;
    }
  }
}

void StdObj1D_ClimbingNetWithBottomEdge(uint8 k) {  // 0db461
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  R1_ = blocks_size_or_type & 0xF;
  int8 v2 = blocks_size_or_type & 0xF;
  PreserveLevelDataPointerInObjects();
  for (; R0_; --R0_) {
    do {
      SetMap16HighByteForCurrentObject_Page00(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xB);
      --v2;
    } while (v2 >= 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    v2 = R1_;
  }
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xE);
    --v2;
  } while (v2 >= 0);
}

void StdObj1E_ClimbingNetWithSideEdge(uint8 k) {  // 0db49e
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  uint8 v2 = blocks_size_or_type & 0xF;
  StdObj1E_ClimbingNetWithSideEdge_0DB4D9(v2, blocks_sub_scr_pos, kStdObj1E_ClimbingNetWithSideEdge_SideTiles[v2]);
  while (1) {
    if (v1 + 16 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    v1 += 16;
    if (!--R0_)
      break;
    SetMap16HighByteForCurrentObject_Page00(v1);
    IndirWriteByte(&ptr_lo_map16_data, v1, kStdObj1E_ClimbingNetWithSideEdge_SideTiles[v2]);
  }
  StdObj1E_ClimbingNetWithSideEdge_0DB4FE(v2, v1, kStdObj1E_ClimbingNetWithSideEdge_SideTiles[v2]);
}

void StdObj1E_ClimbingNetWithSideEdge_0DB4D9(uint8 k, uint8 j, uint8 a) {  // 0db4d9
  R12_ = a;
  uint8 v3 = *IndirPtr(&ptr_lo_map16_data, j);
  uint8 v4;
  if (v3 == 8) {
    v4 = kStdObj1E_ClimbingNetWithSideEdge_TopCornerTiles[k];
LABEL_5:
    R12_ = v4;
    goto LABEL_6;
  }
  if (v3 == 14) {
    v4 = kStdObj1E_ClimbingNetWithSideEdge_TopInnerCornerTiles[k];
    goto LABEL_5;
  }
LABEL_6:
  SetMap16HighByteForCurrentObject_Page00(j);
  IndirWriteByte(&ptr_lo_map16_data, j, R12_);
}

void StdObj1E_ClimbingNetWithSideEdge_0DB4FE(uint8 k, uint8 j, uint8 a) {  // 0db4fe
  R12_ = a;
  uint8 v3 = *IndirPtr(&ptr_lo_map16_data, j);
  uint8 v4;
  if (v3 == 14) {
    v4 = kStdObj1E_ClimbingNetWithSideEdge_BottomCornerTiles[k];
LABEL_5:
    R12_ = v4;
    goto LABEL_6;
  }
  if (v3 == 8) {
    v4 = kStdObj1E_ClimbingNetWithSideEdge_BottomInnerCornerTiles[k];
    goto LABEL_5;
  }
LABEL_6:
  SetMap16HighByteForCurrentObject_Page00(j);
  IndirWriteByte(&ptr_lo_map16_data, j, R12_);
}

void StdObj1F_SkinnyVerticalPipeBoneLog(uint8 k) {  // 0db51f
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = (uint8)(blocks_size_or_type & 0xF0) >> 4;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  for (uint8 i = 83;; i = 84) {
    IndirWriteByte(&ptr_lo_map16_data, v1, i);
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if (!--v2)
      break;
    SetMap16HighByteForCurrentObject_Page01(v1);
  }
  SetMap16HighByteForCurrentObject_Page01(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, 0x55);
}

void StdObj20_SkinnyHorizontalPipeBoneLog(uint8 k) {  // 0db547
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type & 0xF;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  for (uint8 i = 86;; i = 87) {
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, i);
    if (!--v2)
      break;
    SetMap16HighByteForCurrentObject_Page01(v1);
  }
  SetMap16HighByteForCurrentObject_Page01(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, 0x58);
}

void ExtObj6B_CloudFringeBottomLeft(uint8 k) {  // 0db571
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = blocks_size_or_type - 104;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj68_CloudFringeBottomAndRightEdge_Tiles[v1]);
}

void ExtObj8E_YellowSwitchBlock(uint8 k) {  // 0db583
  ExtObj8E_YellowSwitchBlock_0DB58D(1);
}

void ExtObj8E_YellowSwitchBlock_GreenSwitchBlockEntry(uint8 k) {  // 0db58b
  ExtObj8E_YellowSwitchBlock_0DB58D(0);
}

void ExtObj8E_YellowSwitchBlock_0DB58D(uint8 k) {  // 0db58d
  uint8 v1 = blocks_sub_scr_pos;
  if (flag_activated_switches[k]) {
    SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
    IndirWriteByte(&ptr_lo_map16_data, v1, kExtObj8E_YellowSwitchBlock_ActiveTiles[k]);
  } else {
    SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
    IndirWriteByte(&ptr_lo_map16_data, v1, kExtObj8E_YellowSwitchBlock_InactiveTiles[k]);
  }
}

void GrassObj3F_SmallBushes(uint8 k) {  // 0db5b7
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_size_or_type >> 4;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  for (uint8 i = kGrassObj3F_SmallBushes_LeftTiles[v2];; i = kGrassObj3F_SmallBushes_MiddleTiles[v2]) {
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, i);
    if (!--R0_)
      break;
    SetMap16HighByteForCurrentObject_Page00(v1);
  }
  SetMap16HighByteForCurrentObject_Page00(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, kGrassObj3F_SmallBushes_RightTiles[v2]);
}

void GrassObj3C_ArchLedge(uint8 k) {  // 0db604
  R0_ = blocks_size_or_type & 0xF;
  R3_ = 3;
  uint8 v1 = 0;
  PreserveLevelDataPointerInObjects();
  uint8 v2 = blocks_sub_scr_pos;
  R2_ = R0_;
  R1_ = 2;
  do {
    SetMap16HighByteForCurrentObject_Page01(v2);
    v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, kGrassObj3C_ArchLedge_Tiles[v1++]);
    --R1_;
  } while ((R1_ & 0x80) == 0);
  if (--R2_) {
    do {
      SetMap16HighByteForCurrentObject_Page01(v2);
      uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, kGrassObj3C_ArchLedge_Tiles[v1]);
      SetMap16HighByteForCurrentObject_Page01(v3);
      uint8 v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, kGrassObj3C_ArchLedge_Tiles[v1 + 1]);
      SetMap16HighByteForCurrentObject_Page01(v4);
      v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, kGrassObj3C_ArchLedge_Tiles[v1 + 2]);
      --R2_;
    } while (R2_);
  }
  uint8 v5 = v1 + 3;
  SetMap16HighByteForCurrentObject_Page01(v2);
  HandleHorizontalSubScreenCrossingForCurrentObject(v2, kGrassObj3C_ArchLedge_Tiles[v5]);
  while (1) {
    uint8 v7 = v5 + 1;
    RestoreLevelDataPointerInObjects();
    HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R3_ & 0x80) != 0)
      break;
    uint8 v6 = blocks_sub_scr_pos;
    R2_ = R0_;
    R1_ = 2;
    do {
      SetMap16HighByteForCurrentObject_Page00(v6);
      v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, kGrassObj3C_ArchLedge_Tiles[v7++]);
      --R1_;
    } while ((R1_ & 0x80) == 0);
    if (--R2_) {
      do {
        SetMap16HighByteForCurrentObject_Page00(v6);
        uint8 v8 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, kGrassObj3C_ArchLedge_Tiles[v7]);
        SetMap16HighByteForCurrentObject_Page00(v8);
        uint8 v9 = HandleHorizontalSubScreenCrossingForCurrentObject(v8, kGrassObj3C_ArchLedge_Tiles[v7 + 1]);
        SetMap16HighByteForCurrentObject_Page00(v9);
        v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v9, kGrassObj3C_ArchLedge_Tiles[v7 + 2]);
        --R2_;
      } while (R2_);
    }
    v5 = v7 + 3;
    SetMap16HighByteForCurrentObject_Page00(v6);
    HandleHorizontalSubScreenCrossingForCurrentObject(v6, kGrassObj3C_ArchLedge_Tiles[v5]);
  }
}

void GrassObj3D_TopCloudFridge(uint8 k) {  // 0db6c3
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kGrassObj3D_TopCloudFridge_Tiles[v2]);
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void ExtObj89_LeftTreeBranch(uint8 k) {  // 0db6e3
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = blocks_size_or_type + 120;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj88_RightTreeBranch_Tiles[v1]);
}

void GrassObj3E_SideCloudFridges(uint8 k) {  // 0db705
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  uint8 v2 = blocks_size_or_type & 0xF;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  for (uint8 i = kGrassObj3E_SideCloudFridges_TopTiles[v2];; i = kGrassObj3E_SideCloudFridges_BottomTiles[v2]) {
    IndirWriteByte(&ptr_lo_map16_data, v1, i);
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R0_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page00(v1);
  }
}

void GrassObj39_RightFacingDiagonalPipe(uint8 k) {  // 0db73f
  uint8 updated = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  R1_ = 1;
  uint8 v2 = 0;
  PreserveLevelDataPointerInObjects();
  while (1) {
    R2_ = R1_;
    do {
      SetMap16HighByteForCurrentObject_Page01(updated);
      updated = HandleHorizontalSubScreenCrossingForCurrentObject(updated, kGrassObj39_RightFacingDiagonalPipe_Tiles[v2++]);
      --R2_;
    } while ((R2_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    updated = GoDownLeftAndUpdateLevelDataPointerInObjects();
    ++R1_;
    ++R1_;
    if ((--R0_ & 0x80) != 0)
      break;
    if (v2 == 6) {
      --R1_;
      do {
        R2_ = R1_;
        do {
          SetMap16HighByteForCurrentObject_Page01(updated);
          updated = HandleHorizontalSubScreenCrossingForCurrentObject(updated, kGrassObj39_RightFacingDiagonalPipe_Tiles[v2++]);
          --R2_;
        } while ((R2_ & 0x80) == 0);
        RestoreLevelDataPointerInObjects();
        updated = GoDownLeftAndUpdateLevelDataPointerInObjects();
        if (v2 == 16)
          v2 = 11;
        --R0_;
      } while ((R0_ & 0x80) == 0);
      break;
    }
  }
  uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(updated);
  SetMap16HighByteForCurrentObject_Page01(v3);
  IndirWriteByte(&ptr_lo_map16_data, v3, 0xEB);
}

void GrassObjXX_DiagonalLedge_LeftFacingDiagonalLedgeEntry(uint8 k) {  // 0db7aa
  uint8 v7;
  uint8 j = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R2_ = blocks_size_or_type & 0xF;
  R3_ = blocks_size_or_type >> 4;
  R1_ = 1;
  PreserveLevelDataPointerInObjects();
  SetMap16HighByteForCurrentObject_Page01(j);
  j = FillInSlopeTileAir(j, 0xAA);
  GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(j, 0xA1);
  while (1) {
    RestoreLevelDataPointerInObjects();
    j = GoDownLeftAndUpdateLevelDataPointerInObjects();
    ++R1_;
    v7 = ++R1_;
    if ((--R2_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page01(j);
    j = FillInSlopeTileAir(j, 0xAA);
    int8 v4 = v7 - 1;
    SetMap16HighByteForCurrentObject_Page01(j);
    j = HandleHorizontalSubScreenCrossingForCurrentObject(j, 0xE2);
    while (--v4) {
      SetMap16HighByteForCurrentObject_Page00(j);
      j = HandleHorizontalSubScreenCrossingForCurrentObject(j, 0x3F);
    }
    SetMap16HighByteForCurrentObject_Page00(j);
    GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(j, 0xA6);
  }
  j = HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(j);
  blocks_sub_scr_pos = j;
  PreserveLevelDataPointerInObjects();
  uint8 v9 = v7 - 1;
  R1_ = v9;
  SetMap16HighByteForCurrentObject_Page01(j);
  j = FillInSlopeTileAir(j, 0xF7);
  for (;;) {
    while (--v9) {
      SetMap16HighByteForCurrentObject_Page00(j);
      j = HandleHorizontalSubScreenCrossingForCurrentObject(j, 0x3F);
    }
    SetMap16HighByteForCurrentObject_Page00(j);
    j = GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(j, 0xA6);
    RestoreLevelDataPointerInObjects();
    j = GoDownRightAndUpdateLevelDataPointerInObjects();
    v9 = R1_;
    if ((--R3_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page00(j);
    j = GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(j, 0xA3);
  }
}

uint8 GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(uint8 j, uint8 a) {  // 0db84e
  R15_ = a;
  uint8 v2 = *IndirPtr(&ptr_lo_map16_data, j);
  if (v2 != 37) {
    if (v2 != 63)
      ++R15_;
    ++R15_;
  }
  return HandleHorizontalSubScreenCrossingForCurrentObject(j, R15_);
}

void GrassObjXX_DiagonalLedge_RightFacingDiagonalLedgeEntry(uint8 k) {  // 0db863
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R2_ = blocks_size_or_type & 0xF;
  R3_ = blocks_size_or_type >> 4;
  R1_ = 1;
  PreserveLevelDataPointerInObjects();
  uint8 v2 = GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(v1, 0xAF);
  SetMap16HighByteForCurrentObject_Page01(v2);
  FillInSlopeTileAir(v2, 0xAF);
  uint8 updated;
  while (1) {
    RestoreLevelDataPointerInObjects();
    updated = GoDownLeftAndUpdateLevelDataPointerInObjects();
    ++R1_;
    uint8 v4 = ++R1_;
    if ((--R2_ & 0x80) != 0)
      break;
    uint8 i;
    SetMap16HighByteForCurrentObject_Page00(updated);
    for (i = GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(updated, 0xA9); --v4 != 1;
         i = HandleHorizontalSubScreenCrossingForCurrentObject(i, 0x3F)) {
      SetMap16HighByteForCurrentObject_Page00(i);
    }
    SetMap16HighByteForCurrentObject_Page01(i);
    uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(i, 0xE4);
    SetMap16HighByteForCurrentObject_Page01(v5);
    FillInSlopeTileAir(v5, 0xAF);
  }
  uint8 v7 = --R1_;
  SetMap16HighByteForCurrentObject_Page00(updated);
  uint8 j;
  for (j = GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(updated, 0xA9); --v7;
       j = HandleHorizontalSubScreenCrossingForCurrentObject(j, 0x3F)) {
    SetMap16HighByteForCurrentObject_Page00(j);
  }
  SetMap16HighByteForCurrentObject_Page01(j);
  GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(j, 0xF9);
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v11 = GoDownLeftAndUpdateLevelDataPointerInObjects();
    uint8 v10 = R1_;
    if ((--R3_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page00(v11);
    uint8 m;
    for (m = GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(v11, 0xA9); --v10;
         m = HandleHorizontalSubScreenCrossingForCurrentObject(m, 0x3F)) {
      SetMap16HighByteForCurrentObject_Page00(m);
    }
    SetMap16HighByteForCurrentObject_Page00(m);
    GrassObjXX_DiagonalLedge_AddDiagonalBlackLinesToDirt(m, 0xAC);
  }
}

void RopeObj33_BlueSwitchBlocks(uint8 k) {  // 0db916
  GrassObj32_BlueSwitchBlocks_0DB920(0);
}

void GrassObj32_BlueSwitchBlocks_RedSwitchBlockEntry(uint8 k) {  // 0db91e
  GrassObj32_BlueSwitchBlocks_0DB920(1);
}

void GrassObj32_BlueSwitchBlocks_0DB920(uint8 k) {  // 0db920
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  do {
    R2_ = R0_;
    PreserveLevelDataPointerInObjects();
    do {
      SetMap16HighByteForCurrentObject_Page00(v1);
      R15_ = kGrassObj32_BlueSwitchBlocks_InactiveTiles[k];
      if (flag_activated_switches[k + 2]) {
        SetMap16HighByteForCurrentObject_Page01(v1);
        R15_ = kGrassObj32_BlueSwitchBlocks_ActiveTiles[k];
      }
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, R15_);
      --R2_;
    } while ((R2_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R1_;
  } while ((R1_ & 0x80) == 0);
}

void GrassObj37_SmallTreeTrunk(uint8 k) {  // 0db966
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = blocks_size_or_type & 0xF;
  R0_ = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    GrassObj37_SmallTreeTrunk_0DB997(v2, v1, kGrassObj37_SmallTreeTrunk_TopTiles[v2]);
    uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R0_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page00(v3);
    IndirWriteByte(&ptr_lo_map16_data, v3, kGrassObj37_SmallTreeTrunk_BottomTiles[v2]);
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void GrassObj37_SmallTreeTrunk_0DB997(uint8 k, uint8 j, uint8 a) {  // 0db997
  R15_ = a;
  if (k == 1) {
    uint8 v3 = *IndirPtr(&ptr_lo_map16_data, j);
    if (v3 == 0xB1 || v3 == 0xB6)
      R15_ = v3 + 1;
  } else if (*IndirPtr(&ptr_lo_map16_data, j) == 14) {
    SetMap16HighByteForCurrentObject_Page01(j);
    R15_ = 13;
  }
  IndirWriteByte(&ptr_lo_map16_data, j, R15_);
}

void GrassObj36_LargeTreeTrunk(uint8 k) {  // 0db9c0
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  do {
    PreserveLevelDataPointerInObjects();
    GrassObj36_LargeTreeTrunk_0DB9F6(0xB9, v1);
    RestoreLevelDataPointerInObjects();
    uint8 v2 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R0_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page00(v2);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, 0xBB);
    SetMap16HighByteForCurrentObject_Page00(v3);
    IndirWriteByte(&ptr_lo_map16_data, v3, 0xBC);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void GrassObj36_LargeTreeTrunk_0DB9F6(uint8 k, uint8 j) {  // 0db9f6
  if (*IndirPtr(&ptr_lo_map16_data, j) == 14) {
    SetMap16HighByteForCurrentObject_Page01(j);
    k = 11;
  }
  uint8 v2 = HandleHorizontalSubScreenCrossingForCurrentObject(j, k);
  IndirWriteByte(&ptr_lo_map16_data, v2, k + 1);
}

void GrassObj35_ForestGround(uint8 k) {  // 0dba0a
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  int8 v2 = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xE);
    --v2;
  } while (v2 >= 0);
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    int8 v4 = R0_;
    if ((--R1_ & 0x80) != 0)
      break;
    do {
      SetMap16HighByteForCurrentObject_Page00(v3);
      v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xB8);
      --v4;
    } while (v4 >= 0);
  }
}

void GrassObj34_ForestGroundEdges(uint8 k) {  // 0dba4c
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = blocks_size_or_type & 0xF;
  R0_ = blocks_size_or_type >> 4;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v1, kGrassObj34_ForestGroundEdges_TopTiles[v2]);
  while (1) {
    uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R0_ & 0x80) != 0)
      break;
    if ((int8)(v2 - 2) < 0)
      SetMap16HighByteForCurrentObject_Page01(v3);
    IndirWriteByte(&ptr_lo_map16_data, v3, kGrassObj34_ForestGroundEdges_BottomTiles[v2]);
  }
}

void GrassObj33_ForestTreeTop(uint8 k) {  // 0dbadc
  R15_ = blocks_size_or_type;
  do {
    R14_ = blocks_sub_scr_pos;
    uint8 v1 = blocks_sub_scr_pos;
    uint8 v2 = 0;
    R1_ = 5;
    R0_ = 15;
    PreserveLevelDataPointerInObjects();
    do {
      R2_ = R0_;
      do {
        v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kGrassObj33_ForestTreeTop_Tiles[v2++]);
      } while ((--R2_ & 0x80) == 0);
      RestoreLevelDataPointerInObjects();
      if (R14_ + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      R14_ += 16;
      v1 = R14_;
    } while ((--R1_ & 0x80) == 0);
    ptr_lo_map16_data += 0xb0;
    ptr_hi_map16_data = ptr_lo_map16_data;
  } while ((--R15_ & 0x80) == 0);
}

void GrassObj30_IcyVerticalPipe(uint8 k) {  // 0dbb2c
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  SetMap16HighByteForCurrentObject_Page01(v1);
  uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x61);
  SetMap16HighByteForCurrentObject_Page01(v3);
  IndirWriteByte(&ptr_lo_map16_data, v3, 0x62);
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v5 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if (--v2 < 0)
      break;
    SetMap16HighByteForCurrentObject_Page01(v5);
    uint8 v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, 0x63);
    SetMap16HighByteForCurrentObject_Page01(v4);
    IndirWriteByte(&ptr_lo_map16_data, v4, 0x64);
  }
}

void StdObjXX_Generic1RepeatedTileObject_IcyTurnBlockEntry(uint8 k) {  // 0dbb63
  StdObj05_Coins(0xE);
}

void ProcessCastleObjects() {  // 0dc190
  kProcessCastleObjects_CastlePtrs[(uint8)(blocks_object_number - 1)](blocks_object_number - 1);
}

void ExtObj4B_ConveyorEndTile1(uint8 k) {  // 0dc259
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = blocks_size_or_type - 75;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj4B_ConveyorEndTile1_Tiles[v1]);
}

void ExtObj84_CastleEntrance(uint8 k) {  // 0dc2e9
  uint8 v0 = blocks_sub_scr_pos;
  for (uint8 i = 0; i != 126; ++i) {
    R0_ = 8;
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      if (kExtObj84_CastleEntrance_Tiles[i] != 37)
        IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj84_CastleEntrance_Tiles[i]);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(v0);
      ++i;
      --R0_;
    } while (R0_);
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj84_CastleEntrance_Tiles[i]);
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  }
}

void ExtObj90_LargeBossDoor(uint8 k) {  // 0dc31e
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = 0;
  R0_ = 1;
  do {
    R1_ = R0_;
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kExtObj90_LargeBossDoor_Tiles[v1++]);
      --R1_;
    } while ((R1_ & 0x80) == 0);
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while (v1 != 6);
}

void CastleObj3D_Escalator(uint8 k) {  // 0dc341
  kCastleObj3D_Escalator_EscalatorPtrs[(uint8)(blocks_size_or_type & 2) >> 1]();
}

void CastleObj3D_Escalator_LeftSlope() {  // 0dc358
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 0;
  uint8 v1 = blocks_size_or_type & 3;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  bool v4;
  while (1) {
    R3_ = R2_;
    SetMap16HighByteForCurrentObject_Page01(v0);
    for (uint8 i = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kCastleObj3D_Escalator_ConveyorTiles[v1]);;
         i = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel()) {
      if ((--R3_ & 0x80) == 0) {
        SetMap16HighByteForCurrentObject_Page01(i);
        for (uint8 j = HandleHorizontalSubScreenCrossingForCurrentObject(i, kCastleObj3D_Escalator_ConveyorCornerTiles[v1]);
             (--R3_ & 0x80) == 0; j = HandleHorizontalSubScreenCrossingForCurrentObject(j, 0x3F)) {
          SetMap16HighByteForCurrentObject_Page00(j);
        }
      }
      RestoreLevelDataPointerInObjects();
      ++R2_;
      v4 = (--R0_ & 0x80) != 0;
      if (R0_)
        break;
      R3_ = R2_;
    }
    if (v4)
      break;
    v0 = blocks_sub_scr_pos + 15;
    if (blocks_sub_scr_pos + 15 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if ((v0 & 0xF) == 15) {
      if (v0 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v0 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v0;
  }
}

void CastleObj3D_Escalator_RightSlope() {  // 0dc3d8
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 0;
  uint8 v1 = blocks_size_or_type & 3;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  while (R0_) {
    SetMap16HighByteForCurrentObject_Page01(v0);
    HandleHorizontalSubScreenCrossingForCurrentObject(v0, kCastleObj3D_Escalator_ConveyorTiles[v1]);
    RestoreLevelDataPointerInObjects();
    uint8 v2 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    R3_ = ++R2_;
    if ((--R0_ & 0x80) != 0)
      break;
    while (R3_ != 1) {
      SetMap16HighByteForCurrentObject_Page00(v2);
      v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, 0x3F);
      --R3_;
    }
    SetMap16HighByteForCurrentObject_Page01(v2);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, kCastleObj3D_Escalator_ConveyorCornerTiles[v1]);
  }
}

void CastleObj3E_HorizontalLineOfSpikes(uint8 k) {  // 0dc42e
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kCastleObj3E_HorizontalLineOfSpikes_Tiles[v2]);
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void CastleObj3F_VerticalLineOfSpikes(uint8 k) {  // 0dc44f
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  uint8 v2 = blocks_size_or_type & 0xF;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    IndirWriteByte(&ptr_lo_map16_data, v1, kCastleObj3F_VerticalLineOfSpikes_Tiles[v2]);
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void CastleObj3C_StoneBlock(uint8 k) {  // 0dc478
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  uint8 v2 = 0;
  while (1) {
    R2_ = R0_;
    SetMap16HighByteForCurrentObject_Page01(v1);
    uint8 i;
    for (i = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kCastleObj3C_StoneBlock_LeftTiles[v2]); --R2_;
         i = HandleHorizontalSubScreenCrossingForCurrentObject(i, kCastleObj3C_StoneBlock_MiddleTiles[v2])) {
      SetMap16HighByteForCurrentObject_Page01(i);
    }
    SetMap16HighByteForCurrentObject_Page01(i);
    IndirWriteByte(&ptr_lo_map16_data, i, kCastleObj3C_StoneBlock_RightTiles[v2]);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    v2 = 1;
    bool v4 = R1_-- == 1;
    if ((R1_ & 0x80) != 0)
      break;
    if (v4)
      v2 = 2;
  }
}

void CastleObj3B_GrassLedge(uint8 k) {  // 0dc4c9
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  for (int8 i = blocks_size_or_type & 0xF; i >= 0; --i) {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 9);
  }
  uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  int8 v4 = R0_;
  do {
    SetMap16HighByteForCurrentObject_Page00(v3);
    v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0x86);
    --v4;
  } while (v4 >= 0);
}

void CastleObj36_LargeSpikedPillar(uint8 k) {  // 0dc4ef
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type & 0xF;
  R0_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  if (v2) {
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(v1);
    SetMap16HighByteForCurrentObject_Page00(v3);
    uint8 v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0x87);
    SetMap16HighByteForCurrentObject_Page00(v4);
    HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0x88);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  }
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x89);
    SetMap16HighByteForCurrentObject_Page01(v5);
    uint8 v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, 0x66);
    SetMap16HighByteForCurrentObject_Page01(v6);
    uint8 v7 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, 0x67);
    SetMap16HighByteForCurrentObject_Page00(v7);
    HandleHorizontalSubScreenCrossingForCurrentObject(v7, 0x8A);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R0_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page00(v1);
    uint8 v8 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x8B);
    SetMap16HighByteForCurrentObject_Page01(v8);
    uint8 v9 = HandleHorizontalSubScreenCrossingForCurrentObject(v8, 0x68);
    SetMap16HighByteForCurrentObject_Page01(v9);
    uint8 v10 = HandleHorizontalSubScreenCrossingForCurrentObject(v9, 0x69);
    SetMap16HighByteForCurrentObject_Page00(v10);
    HandleHorizontalSubScreenCrossingForCurrentObject(v10, 0x8C);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
  if (!v2) {
    uint8 v11 = HandleHorizontalSubScreenCrossingForCurrentObject_Entry2(v1);
    SetMap16HighByteForCurrentObject_Page00(v11);
    uint8 v12 = HandleHorizontalSubScreenCrossingForCurrentObject(v11, 0x8D);
    SetMap16HighByteForCurrentObject_Page00(v12);
    HandleHorizontalSubScreenCrossingForCurrentObject(v12, 0x8E);
  }
}

void CastleObj35_RockWallBackground(uint8 k) {  // 0dc58a
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  do {
    int8 v2 = R0_;
    do {
      SetMap16HighByteForCurrentObject_Page00(v1);
      uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x94);
      SetMap16HighByteForCurrentObject_Page00(v3);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0x95);
      --v2;
    } while (v2 >= 0);
    RestoreLevelDataPointerInObjects();
    uint8 v4 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    int8 v5 = R0_;
    do {
      SetMap16HighByteForCurrentObject_Page00(v4);
      uint8 v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0x96);
      SetMap16HighByteForCurrentObject_Page00(v6);
      v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, 0x97);
      --v5;
    } while (v5 >= 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R1_;
  } while ((R1_ & 0x80) == 0);
}

void CastleObj34_VerticalDoubleEndedPipe(uint8 k) {  // 0dc5d8
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  SetMap16HighByteForCurrentObject_Page01(v1);
  uint8 v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x33);
  SetMap16HighByteForCurrentObject_Page01(v2);
  IndirWriteByte(&ptr_lo_map16_data, v2, 0x34);
  uint8 v4;
  while (1) {
    RestoreLevelDataPointerInObjects();
    v4 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if (!--R0_)
      break;
    SetMap16HighByteForCurrentObject_Page00(v4);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0x9D);
    SetMap16HighByteForCurrentObject_Page00(v3);
    IndirWriteByte(&ptr_lo_map16_data, v3, 0x9E);
  }
  SetMap16HighByteForCurrentObject_Page01(v4);
  uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0x33);
  SetMap16HighByteForCurrentObject_Page01(v5);
  IndirWriteByte(&ptr_lo_map16_data, v5, 0x34);
}

void ProcessRopeObjects() {  // 0dcd90
  kProcessRopeObjects_RopePtrs[(uint8)(blocks_object_number - 1)](blocks_object_number - 1);
}

void ExtObjXX_LineGuideQuarterLargeCircle(uint8 k) {  // 0dce67
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = 4 * (blocks_size_or_type - 77);
  PreserveLevelDataPointerInObjects();
  do {
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kExtObjXX_LineGuideQuarterLargeCircle_Tiles[v1++]);
    } while ((v1 & 1) != 0);
    RestoreLevelDataPointerInObjects();
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while ((v1 & 3) != 0);
}

void ExtObjXX_LineGuideQuarterSmallCircle(uint8 k) {  // 0dce94
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = blocks_size_or_type - 81;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, kExtObjXX_LineGuideQuarterSmallCircle_Tiles[v1]);
}

void ExtObj70_BitOfCanvas1(uint8 k) {  // 0dcea6
  uint8 v0 = blocks_sub_scr_pos;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  uint8 v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0x84);
  SetMap16HighByteForCurrentObject_Page00(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, 0x85);
}

void ExtObj55_HorizontalLineGuideEnd(uint8 k) {  // 0dcec0
  uint8 v0 = blocks_sub_scr_pos;
  for (uint8 i = 0; i != 2; ++i) {
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj55_HorizontalLineGuideEnd_Tiles[i]);
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  }
}

void ExtObj56_VerticalLineGuideEnd(uint8 k) {  // 0dceda
  uint8 v0 = blocks_sub_scr_pos;
  for (uint8 i = 0; i != 2; ++i) {
    SetMap16HighByteForCurrentObject_Page00(v0);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kExtObj56_VerticalLineGuideEnd_Tiles[i]);
  }
}

void RopeObj36_HorizontalConveyorRope(uint8 k) {  // 0dcef2
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kRopeObj36_HorizontalConveyorRope_Tiles[v2]);
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void RopeObj38_HorizontalLineGuide(uint8 k) {  // 0dcf12
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kCastleObj37_HorizontalLineGuide_Tiles[v2]);
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void CastleObj38_VerticalLineGuide(uint8 k) {  // 0dcf33
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = blocks_size_or_type & 0xF;
  R0_ = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    IndirWriteByte(&ptr_lo_map16_data, v1, kCastleObj38_VerticalLineGuide_Tiles[v2]);
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void RopeObj3A_SlopedLineGuide(uint8 k) {  // 0dcf53
  kRopeObj3A_SlopedLineGuide_SlopedLineGuidePtrs[blocks_size_or_type & 0xF](blocks_size_or_type & 0xF);
}

void RopeObj3A_SlopedLineGuideLeftSlope(uint8 k) {  // 0dcf6e
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x8C);
    SetMap16HighByteForCurrentObject_Page00(v3);
    IndirWriteByte(&ptr_lo_map16_data, v3, 0x8D);
    RestoreLevelDataPointerInObjects();
    v1 = blocks_sub_scr_pos + 14;
    if (blocks_sub_scr_pos + 14 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if (!sign8((v1 & 0xF) - 14)) {
      if (v1 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v1 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v1;
    --v2;
  } while (v2 >= 0);
}

void RopeObj3A_SlopedLineGuide_ONOFFLeftSlope(uint8 k) {  // 0dcfb1
  uint8 v1 = 0x86;
  if (k == 4)
    v1 = 0x94;
  R0_ = v1;
  uint8 v2 = blocks_sub_scr_pos;
  int8 v3 = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page00(v2);
    IndirWriteByte(&ptr_lo_map16_data, v2, R0_);
    v2 = blocks_sub_scr_pos + 15;
    if (blocks_sub_scr_pos + 15 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if (!sign8((v2 & 0xF) - 15)) {
      if (v2 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v2 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v2;
    --v3;
  } while (v3 >= 0);
}

void RopeObj3A_SlopedLineGuideRightSlope(uint8 k) {  // 0dcff0
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  do {
    SetMap16HighByteForCurrentObject_Page00(v1);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x8E);
    SetMap16HighByteForCurrentObject_Page00(v3);
    IndirWriteByte(&ptr_lo_map16_data, v3, 0x8F);
    RestoreLevelDataPointerInObjects();
    uint8 v4 = blocks_sub_scr_pos + 16;
    if (blocks_sub_scr_pos + 16 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    v1 = v4 + 2;
    if (sign8((v1 & 0xF) - 2)) {
      v1 = (v1 - 16) & 0xF1;
      GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v1;
    --v2;
  } while (v2 >= 0);
}

void RopeObj3A_SlopedLineGuide_ONOFFRightSlope(uint8 k) {  // 0dd034
  uint8 v1 = -121;
  if (k == 5)
    v1 = -107;
  R0_ = v1;
  uint8 v2 = blocks_sub_scr_pos;
  int8 v3 = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page00(v2);
    IndirWriteByte(&ptr_lo_map16_data, v2, R0_);
    uint8 v4 = blocks_sub_scr_pos + 16;
    if (blocks_sub_scr_pos + 16 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    v2 = v4 + 1;
    if ((v2 & 0xF) == 0) {
      v2 = (v2 - 1) & 0xF0;
      GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v2;
    --v3;
  } while (v3 >= 0);
}

void RopeObj3B_VerySteepSlopedLineGuide(uint8 k) {  // 0dd070
  kRopeObj3B_VerySteepSlopedLineGuide_VerySteepSlopedLineGuidePtrs[blocks_size_or_type >> 4]();
}

void RopeObj3B_VerySteepSlopedLineGuide_VerySteepLeftSlope() {  // 0dd080
  uint8 v0 = blocks_sub_scr_pos;
  for (int8 i = blocks_size_or_type & 0xF; i >= 0; --i) {
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0x88);
    if (v0 + 16 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    v0 += 16;
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0x8A);
    if (v0 + 15 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    v0 = v0 + 15;
    if ((v0 & 0xF) == 15) {
      if (v0 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v0 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v0;
  }
}

void RopeObj3B_VerySteepSlopedLineGuide_VerySteepRightSlope() {  // 0dd0c3
  uint8 v0 = blocks_sub_scr_pos;
  for (int8 i = blocks_size_or_type & 0xF; i >= 0; --i) {
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0x89);
    if (v0 + 16 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    v0 = v0 + 16;
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0x8B);
    if (v0 + 16 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    v0 = v0 + 16;
    v0 = v0 + 1;
    if ((v0 & 0xF) == 0) {
      v0 = (v0 - 1) & 0xF0;
      GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v0;
  }
}

void RopeObj3C_MushroomTop(uint8 k) {  // 0dd103
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  uint8 v2 = 7;
  uint8 v3 = *IndirPtr(&ptr_lo_map16_data, v1);
  if (!sign8(v3 - 115) && sign8(v3 - 118))
    v2 = 10;
  uint8 i;
  for (i = HandleHorizontalSubScreenCrossingForCurrentObject(v1, v2); --R0_;
       i = HandleHorizontalSubScreenCrossingForCurrentObject(i, 8)) {
    SetMap16HighByteForCurrentObject_Page01(i);
  }
  SetMap16HighByteForCurrentObject_Page01(i);
  uint8 v5 = 9;
  uint8 v6 = *IndirPtr(&ptr_lo_map16_data, i);
  if (!sign8(v6 - 115) && sign8(v6 - 118))
    v5 = 11;
  HandleHorizontalSubScreenCrossingForCurrentObject(i, v5);
}

void RopeObj3D_MushroomColumn(uint8 k) {  // 0dd145
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  do {
    uint8 v2 = R0_;
    SetMap16HighByteForCurrentObject_Page00(v1);
    for (uint8 i = 115;; i = 116) {
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, i);
      if (!--v2)
        break;
      SetMap16HighByteForCurrentObject_Page00(v1);
    }
    SetMap16HighByteForCurrentObject_Page00(v1);
    HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x75);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R1_;
  } while ((R1_ & 0x80) == 0);
}

void RopeObj3E_HorizontalLog(uint8 k) {  // 0dd182
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type & 0xF;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  for (uint8 i = 89;; i = 90) {
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, i);
    if (!--v2)
      break;
    SetMap16HighByteForCurrentObject_Page01(v1);
  }
  SetMap16HighByteForCurrentObject_Page01(v1);
  HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x5B);
}

void RopeObj3F_VerticalLog(uint8 k) {  // 0dd1a5
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type >> 4;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  for (uint8 i = 92;; i = 93) {
    IndirWriteByte(&ptr_lo_map16_data, v1, i);
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if (!--v2)
      break;
    SetMap16HighByteForCurrentObject_Page01(v1);
  }
  SetMap16HighByteForCurrentObject_Page01(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, 0x5E);
}

void RopeObj35_ColumnWithPlantOnTop(uint8 k) {  // 0dd1d9
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = blocks_size_or_type & 0xF;
  R0_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  SetMap16HighByteForCurrentObject_Page00(v1);
  uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kRopeObj35_ColumnWithPlantOnTop_LeftPlantTiles[v2]);
  SetMap16HighByteForCurrentObject_Page00(v3);
  IndirWriteByte(&ptr_lo_map16_data, v3, kRopeObj35_ColumnWithPlantOnTop_RightPlantTiles[v2]);
  if ((--R0_ & 0x80) == 0) {
    RestoreLevelDataPointerInObjects();
    uint8 v4 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    SetMap16HighByteForCurrentObject_Page01(v4);
    uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0x5F);
    SetMap16HighByteForCurrentObject_Page01(v5);
    IndirWriteByte(&ptr_lo_map16_data, v5, 0x60);
    if ((--R0_ & 0x80) == 0) {
      RestoreLevelDataPointerInObjects();
      uint8 v6 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      uint8 v7 = 0;
      do {
        SetMap16HighByteForCurrentObject_Page01(v6);
        uint8 v8 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, kRopeObj35_ColumnWithPlantOnTop_ColumnTiles[v7]);
        uint8 v9 = v7 + 1;
        SetMap16HighByteForCurrentObject_Page01(v8);
        IndirWriteByte(&ptr_lo_map16_data, v8, kRopeObj35_ColumnWithPlantOnTop_ColumnTiles[v9]);
        v7 = v9 + 1;
        RestoreLevelDataPointerInObjects();
        v6 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
        if (v7 == 6)
          v7 = 0;
        --R0_;
      } while ((R0_ & 0x80) == 0);
    }
  }
}

void RopeObj32_LogBridge(uint8 k) {  // 0dd24e
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type & 0xF;
  PreserveLevelDataPointerInObjects();
  uint8 v2 = 0;
  while (1) {
    SetMap16HighByteForCurrentObject_Page00(v1);
    if (v2)
      SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kRopeObj32_LogBridge_Tiles[v2]);
    if ((--R1_ & 0x80) != 0) {
      RestoreLevelDataPointerInObjects();
      v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      R1_ = R0_;
      if (++v2 == 2)
        break;
    }
  }
}

void ProcessUndergroundObjects() {  // 0dd990
  kProcessUndergroundObjects_UndergroundPtrs[(uint8)(blocks_object_number - 1)](blocks_object_number - 1);
}

void ExtObj60_CaveLavaInnerCorner(uint8 k) {  // 0dda57
  uint8 v0 = blocks_sub_scr_pos;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, 0xFE);
}

void ExtObj75_CanvasTile1(uint8 k) {  // 0dda68
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = blocks_size_or_type - 117;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj75_CanvasTile1_Tiles[v1]);
}

void ExtObj7C_BitOfCanvas1(uint8 k) {  // 0dda80
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = blocks_size_or_type - 124;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj7C_BitOfCanvas1_TopTiles[v1]);
  uint8 v2 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  SetMap16HighByteForCurrentObject_Page00(v2);
  IndirWriteByte(&ptr_lo_map16_data, v2, kExtObj7C_BitOfCanvas1_BottomTiles[v1]);
}

void ExtObj7F_TorpedoLauncher(uint8 k) {  // 0ddaa2
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = 0;
  PreserveLevelDataPointerInObjects();
  do {
    do {
      SetMap16HighByteForCurrentObject_Page01(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kExtObj7F_TorpedoLauncher_Tiles[v1++]);
    } while ((v1 & 1) != 0);
    RestoreLevelDataPointerInObjects();
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while (v1 != 4);
}

void UndergroundObj38_RightLavaEdge(uint8 k) {  // 0ddac8
  uint8 v1 = blocks_sub_scr_pos;
  uint8 v2 = blocks_size_or_type & 0xF;
  R0_ = blocks_size_or_type >> 4;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  UndergroundObj38_RightLavaEdge_0DDAE8(v2, v1, kUndergroundObj38_RightLavaEdge_TopTiles[v2]);
}

void UndergroundObj38_RightLavaEdge_0DDAE8(uint8 k, uint8 j, uint8 a) {  // 0ddae8
  while (1) {
    IndirWriteByte(&ptr_lo_map16_data, j, a);
    j = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R0_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page01(j);
    a = kUndergroundObj38_RightLavaEdge_MiddleTiles[k];
  }
}

void UndergroundObj39_SlopedCaveLava(uint8 k) {  // 0ddaf2
  kUndergroundObj39_SlopedCaveLava_SlopedCaveLavaPtrs[blocks_size_or_type & 3]();
}

void UndergroundObj39_SlopedCaveLavaLeftSlope() {  // 0ddb06
  bool v8;
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 1;
  R0_ = 1;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  while (1) {
    uint8 v1 = R2_;
    SetMap16HighByteForCurrentObject_Page01(v0);
    uint8 v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xD2);
    SetMap16HighByteForCurrentObject_Page01(v2);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, 0xD3);
    int8 v4 = v1 - 2;
    if (v4 < 0)
      goto LABEL_6;
    while (1) {
      SetMap16HighByteForCurrentObject_Page01(v3);
      uint8 v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xFB);
      SetMap16HighByteForCurrentObject_Page01(v5);
      uint8 v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, 0xFF);
      int8 v7 = v4 - 1;
      while (--v7 >= 0) {
        SetMap16HighByteForCurrentObject_Page01(v6);
        v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, 0xFF);
      }
LABEL_6:
      RestoreLevelDataPointerInObjects();
      ++R2_;
      ++R2_;
      v8 = (--R0_ & 0x80) != 0;
      if (R0_)
        break;
      v4 = R2_ - 2;
      v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    }
    if (v8)
      break;
    v0 = blocks_sub_scr_pos + 14;
    if (blocks_sub_scr_pos + 14 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if (!sign8((v0 & 0xF) - 14)) {
      if (v0 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v0 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v0;
  }
}

void UndergroundObj39_SlopedCaveLava_SteepLeftSlope() {  // 0ddb8f
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 0;
  R0_ = 0;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  UndergroundObj39_SlopedCaveLava_0DDBA4(v0);
}

void UndergroundObj39_SlopedCaveLava_0DDBA4(uint8 j) {  // 0ddba4
  bool v5;
  while (1) {
    uint8 v1 = R2_;
    SetMap16HighByteForCurrentObject_Page01(j);
    for (uint8 i = HandleHorizontalSubScreenCrossingForCurrentObject(j, 0xD6);;
         i = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel()) {
      int8 v3 = v1 - 1;
      if (v3 >= 0) {
        SetMap16HighByteForCurrentObject_Page01(i);
        for (uint8 k = HandleHorizontalSubScreenCrossingForCurrentObject(i, 0xFD); --v3 >= 0;
             k = HandleHorizontalSubScreenCrossingForCurrentObject(k, 0xFF)) {
          SetMap16HighByteForCurrentObject_Page01(k);
        }
      }
      RestoreLevelDataPointerInObjects();
      ++R2_;
      v5 = (--R0_ & 0x80) != 0;
      if (R0_)
        break;
      v1 = R2_;
    }
    if (v5)
      break;
    j = blocks_sub_scr_pos + 15;
    if (blocks_sub_scr_pos + 15 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if ((j & 0xF) == 15) {
      if (j + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      j += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = j;
  }
}

void UndergroundObj39_SlopedCaveLavaRightSlope() {  // 0ddc02
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 1;
  R0_ = 1;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  do {
    SetMap16HighByteForCurrentObject_Page01(v0);
    uint8 v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xD4);
    SetMap16HighByteForCurrentObject_Page01(v4);
    HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0xD5);
    RestoreLevelDataPointerInObjects();
    uint8 v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    ++R2_;
    uint8 v2 = ++R2_;
    if ((--R0_ & 0x80) != 0)
      break;
    while (v2 != 3) {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xFF);
      --v2;
    }
    SetMap16HighByteForCurrentObject_Page01(v1);
    uint8 v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xFF);
    SetMap16HighByteForCurrentObject_Page01(v3);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xFC);
  } while (R0_);
}

void UndergroundObj39_SlopedCaveLava_SteepRightSlope() {  // 0ddc61
  uint8 v0 = blocks_sub_scr_pos;
  R2_ = 0;
  R0_ = 0;
  PreserveLevelDataPointerInObjects();
  R0_ = (blocks_size_or_type >> 4) + 1;
  while (R0_) {
    SetMap16HighByteForCurrentObject_Page01(v0);
    HandleHorizontalSubScreenCrossingForCurrentObject(v0, 0xD7);
    RestoreLevelDataPointerInObjects();
    uint8 v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    uint8 v2 = ++R2_;
    if ((--R0_ & 0x80) != 0)
      break;
    while (v2 != 1) {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xFF);
      --v2;
    }
    SetMap16HighByteForCurrentObject_Page01(v1);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xFE);
  }
}

void UndergroundObj3B_CaveLava(uint8 k) {  // 0ddca9
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  int8 v3 = R0_;
  if (k != 57)
    goto LABEL_4;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x59);
    --v3;
  } while (v3 >= 0);
  while (1) {
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    v3 = R0_;
    if ((--R1_ & 0x80) != 0)
      break;
    do {
LABEL_4:
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xFF);
      --v3;
    } while (v3 >= 0);
  }
}

void UndergroundObj3D_CeilingLedge(uint8 k) {  // 0ddcea
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  R1_ = blocks_size_or_type & 0xF;
  PreserveLevelDataPointerInObjects();
  for (; R0_; --R0_) {
    int8 v2 = R1_;
    do {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x65);
      --v2;
    } while (v2 >= 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  }
  int8 v3 = R1_;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x4E);
    --v3;
  } while (v3 >= 0);
}

void UndergroundObj3E_CeilingEdges(uint8 k) {  // 0ddd2e
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  uint8 v2 = blocks_size_or_type & 0xF;
  if (blocks_size_or_type >> 4) {
    do {
      SetMap16HighByteForCurrentObject_Page01(v1);
      IndirWriteByte(&ptr_lo_map16_data, v1, kUndergroundObj3E_CeilingEdges_TopTiles[v2]);
      v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      --R0_;
    } while (R0_);
  }
  SetMap16HighByteForCurrentObject_Page01(v1);
  HandleHorizontalSubScreenCrossingForCurrentObject(v1, kUndergroundObj3E_CeilingEdges_BottomTiles[v2]);
}

void UndergroundObj3F_SolidDirt(uint8 k) {  // 0ddd5c
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  R1_ = blocks_size_or_type & 0xF;
  PreserveLevelDataPointerInObjects();
  do {
    int8 v2 = R1_;
    do {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x65);
      --v2;
    } while (v2 >= 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void UndergroundObj3C_VerySteepSlope(uint8 k) {  // 0ddd87
  kUndergroundObj3C_VerySteepSlope_VerySteepSlopePtrs[(blocks_size_or_type & 0x10) != 0]();
}

void UndergroundObj3C_VerySteepSlope_VerySteepLeftSlope() {  // 0ddd99
  uint8 v0 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = 2 * (blocks_size_or_type & 0xF) + 2;
  do {
    PreserveLevelDataPointerInObjects();
    uint8 v1 = R1_;
    SetMap16HighByteForCurrentObject_Page01(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0xCA);
    if (v0 + 16 >= 256) {
      HIBYTE(ptr_lo_map16_data) += 1;
      HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
    }
    v0 += 16;
    SetMap16HighByteForCurrentObject_Page01(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0xCB);
    if (v0 + 16 >= 256) {
      HIBYTE(ptr_lo_map16_data) += 1;
      HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
    }
    v0 += 16;
    SetMap16HighByteForCurrentObject_Page01(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0xF1);
    if (v0 + 16 >= 256) {
      HIBYTE(ptr_lo_map16_data) += 1;
      HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
    }
    v0 += 16;
    int8 v8 = v1 - 2;
    while (--v8 >= 0) {
      SetMap16HighByteForCurrentObject_Page00(v0);
      IndirWriteByte(&ptr_lo_map16_data, v0, 0x3F);
      if (v0 + 16 >= 256) {
        HIBYTE(ptr_lo_map16_data) += 1;
        HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
      }
      v0 += 16;
    }
    RestoreLevelDataPointerInObjects();
    v0 = blocks_sub_scr_pos + 31;
    if (blocks_sub_scr_pos + 31 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    if ((v0 & 0xF) == 15) {
      if (v0 + 16 >= 256)
        HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
      v0 += 16;
      GoBackOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v0;
    R1_ -= 2;
  } while ((--R0_ & 0x80) == 0);
}

void UndergroundObj3C_VerySteepSlope_VerySteepRightSlope() {  // 0dde3c
  uint8 v0 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = 2 * (blocks_size_or_type & 0xF) + 2;
  do {
    PreserveLevelDataPointerInObjects();
    uint8 v1 = R1_;
    SetMap16HighByteForCurrentObject_Page01(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0xCC);
    if (v0 + 16 >= 256) {
      HIBYTE(ptr_lo_map16_data) += 1;
      HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
    }
    v0 += 16;
    SetMap16HighByteForCurrentObject_Page01(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0xCD);
    if (v0 + 16 >= 256) {
      HIBYTE(ptr_lo_map16_data) += 1;
      HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
    }
    v0 += 16;
    SetMap16HighByteForCurrentObject_Page01(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, 0xF2);
    if (v0 + 16 >= 256) {
      HIBYTE(ptr_lo_map16_data) += 1;
      HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
    }
    v0 += 16;
    int8 v8 = v1 - 2;
    while (--v8 >= 0) {
      SetMap16HighByteForCurrentObject_Page00(v0);
      IndirWriteByte(&ptr_lo_map16_data, v0, 0x3F);
      if (v0 + 16 >= 256) {
        HIBYTE(ptr_lo_map16_data) += 1;
        HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
      }
      v0 += 16;
    }
    RestoreLevelDataPointerInObjects();
    uint8 v10 = blocks_sub_scr_pos + 32;
    if (blocks_sub_scr_pos + 32 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    v0 = v10 + 1;
    if ((v0 & 0xF) == 0) {
      GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
      v0 = (v0 - 1) & 0xF0;
    }
    blocks_sub_scr_pos = v0;
    R1_ -= 2;
  } while ((--R0_ & 0x80) == 0);
}

void UndergroundObj37_LargeCanvas(uint8 k) {  // 0ddf3a
  blocks_size_or_type &= 0xF;
  PreserveLevelDataPointerInObjects();
  uint8 v1 = 80;
  blocks_sub_scr_pos = 80;
  R0_ = 15;
  R1_ = 4;
  do {
    int8 v2 = R0_;
    do {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x61);
      --v2;
    } while (v2 >= 0);
    RestoreLevelDataPointerInObjects();
    if (blocks_sub_scr_pos + 64 >= 256)
      HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
    blocks_sub_scr_pos += 64;
    v1 = blocks_sub_scr_pos;
  } while ((--R1_ & 0x80) == 0);
  LOBYTE(ptr_lo_map16_data) = 0;
  R4_ = 0;
  LOBYTE(ptr_hi_map16_data) = 0;
  R0_ = 0;
  R3_ = 7;
  while (1) {
    R1_ = 2;
    blocks_sub_scr_pos = kUndergroundObj37_LargeCanvas_CanvasPosLo[R0_];
    uint8 v4 = blocks_sub_scr_pos;
    HIBYTE(ptr_lo_map16_data) = kUndergroundObj37_LargeCanvas_CanvasPosHi[R0_];
    R5_ = HIBYTE(ptr_lo_map16_data);
    HIBYTE(ptr_hi_map16_data) = HIBYTE(ptr_lo_map16_data);
    R2_ = 3;
    uint8 v5 = 0;
    do {
      SetMap16HighByteForCurrentObject_Page01(v4);
      v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, kUndergroundObj37_LargeCanvas_CanvasTiles[v5++]);
      --R2_;
    } while ((R2_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    uint8 v6 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    do {
      SetMap16HighByteForCurrentObject_Page00(v6);
      uint8 v7 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, kUndergroundObj37_LargeCanvas_CanvasTiles[v5]);
      SetMap16HighByteForCurrentObject_Page00(v7);
      uint8 v8 = HandleHorizontalSubScreenCrossingForCurrentObject(v7, kUndergroundObj37_LargeCanvas_CanvasTiles[v5 + 1]);
      SetMap16HighByteForCurrentObject_Page00(v8);
      IndirWriteByte(&ptr_lo_map16_data, v8, kUndergroundObj37_LargeCanvas_CanvasTiles[v5 + 2]);
      v6 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    } while ((--R1_ & 0x80) == 0);
    uint8 v9 = v5 + 3;
    R2_ = 3;
    do {
      SetMap16HighByteForCurrentObject_Page01(v6);
      v6 = HandleHorizontalSubScreenCrossingForCurrentObject(v6, kUndergroundObj37_LargeCanvas_CanvasTiles[v9++]);
    } while ((--R2_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    R2_ = 2;
    uint8 v10 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    do {
      SetMap16HighByteForCurrentObject_Page00(v10);
      v10 = HandleHorizontalSubScreenCrossingForCurrentObject(v10, kUndergroundObj37_LargeCanvas_CanvasTiles[v9++]);
    } while ((--R2_ & 0x80) == 0);
    if ((--R3_ & 0x80) != 0)
      break;
    ++R0_;
  }
  R8_ = 1;
  R9_ = 0;
  while (1) {
    int v11 = (uint16)(2 * R8_W) >> 1;
    R4_W = kUndergroundObj37_LargeCanvas_ScreenPosLo[v11];
    R6_W = kUndergroundObj37_LargeCanvas_ScreenPosHi[v11];
    R0_W = 432;
    R2_W = 0xc800;
    uint8 *v12 = g_ram + R4_W;
    uint8 *v13 = g_ram + 0xC800;
    MemCpy(v12, v13, 0x1B1);
    R0_W = 432;
    R2_W = 0xc800;
    uint8 *v14 = g_ram + 0x10000 + (R6_W);
    uint8 *v15 = g_ram + 0x10000 + 0xC800;
    MemCpy(v14, v15, 0x1B1);
    if (!--blocks_size_or_type)
      break;
    ++R8_;
  }
}

void ExtObj71_Canvas1(uint8 k) {  // 0de0ae
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = kExtObj71_Canvas1_TileIndex[(uint8)(blocks_size_or_type - 113)];
  PreserveLevelDataPointerInObjects();
  R1_ = 2;
  R2_ = 3;
  do {
    SetMap16HighByteForCurrentObject_Page01(v0);
    v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kExtObj71_Canvas1_Tiles[v1++]);
  } while ((--R2_ & 0x80) == 0);
  RestoreLevelDataPointerInObjects();
  uint8 v2 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  do {
    R2_ = 2;
    do {
      SetMap16HighByteForCurrentObject_Page00(v2);
      v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, kExtObj71_Canvas1_Tiles[v1++]);
    } while ((--R2_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    v2 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while ((--R1_ & 0x80) == 0);
  R2_ = 2;
  do {
    SetMap16HighByteForCurrentObject_Page00(v2);
    v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, kExtObj71_Canvas1_Tiles[v1++]);
  } while ((--R2_ & 0x80) == 0);
  SetMap16HighByteForCurrentObject_Page01(v2);
  IndirWriteByte(&ptr_lo_map16_data, v2, 0x5F);
  RestoreLevelDataPointerInObjects();
  R2_ = 2;
  uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  do {
    SetMap16HighByteForCurrentObject_Page00(v3);
    v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, kExtObj71_Canvas1_Tiles[v1++]);
  } while ((--R2_ & 0x80) == 0);
}

void UndergroundObj36_4SidedGround(uint8 k) {  // 0de135
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  uint8 v2 = 0;
  while (1) {
    R2_ = R0_;
    SetMap16HighByteForCurrentObject_Page01(v1);
    uint8 i;
    for (i = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kUndergroundObj36_4SidedGround_LeftTiles[v2]); --R2_;
         i = HandleHorizontalSubScreenCrossingForCurrentObject(i, kUndergroundObj36_4SidedGround_MiddleTiles[v2])) {
      SetMap16HighByteForCurrentObject_Page01(i);
    }
    SetMap16HighByteForCurrentObject_Page01(i);
    IndirWriteByte(&ptr_lo_map16_data, i, kUndergroundObj36_4SidedGround_RightTiles[v2]);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    v2 = 1;
    bool v4 = R1_-- == 1;
    if ((R1_ & 0x80) != 0)
      break;
    if (v4)
      v2 = 2;
  }
}

void ProcessGhostHouseObjects() {  // 0de890
  kProcessGhostHouseObjects_GhostHousePtrs[(uint8)(blocks_object_number - 1)](blocks_object_number - 1);
}

void ExtObj5B_BitOfBrickBackground1(uint8 k) {  // 0de95f
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = blocks_size_or_type - 87;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj57_SwitchPalaceBottomRightInnerCorner_Tiles[v1]);
}

void ExtObj5F_LargeBackgroundArea(uint8 k) {  // 0de971
  R0_ = 3;
  uint8 v0 = 0;
  do {
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      IndirWriteByte(&ptr_lo_map16_data, v0++, 0x77);
    } while (v0);
    HIBYTE(ptr_hi_map16_data) = ++HIBYTE(ptr_lo_map16_data);
  } while ((--R0_ & 0x80) == 0);
}

void ExtObj61_GhostHouseClock(uint8 k) {  // 0de9aa
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = 9 * (blocks_size_or_type - 97);
  R0_ = 2;
  R1_ = 2;
  PreserveLevelDataPointerInObjects();
  do {
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, kExtObj61_GhostHouseClock_Tiles[v1++]);
    } while ((--R0_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    R0_ = 2;
  } while ((--R1_ & 0x80) == 0);
}

void ExtObj65_TopLeftCobweb(uint8 k) {  // 0de9ed
  ExtObj64_TopRightCobweb_GhostHouseWindowEntry(4 * (blocks_size_or_type - 100));
}

void ExtObj64_TopRightCobweb_GhostHouseWindowEntry(uint8 k) {  // 0de9f5
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = 1;
  R1_ = 1;
  PreserveLevelDataPointerInObjects();
  do {
    do {
      SetMap16HighByteForCurrentObject_Page00(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, *((uint8 *)kExtObj64_TopRightCobweb_Tiles + k++));
    } while ((--R0_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    R0_ = 1;
  } while ((--R1_ & 0x80) == 0);
}

void ExtObj66_GhostHouseTopRightToBottomLeftBeam2(uint8 k) {  // 0dea3e
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = 16 * (blocks_size_or_type - 102);
  R0_ = 3;
  R1_ = 3;
  PreserveLevelDataPointerInObjects();
  do {
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(
          v0, *((uint8 *)kExtObj66_GhostHouseTopRightToBottomLeftBeam2_Tiles + v1++));
    } while ((--R0_ & 0x80) == 0);
    RestoreLevelDataPointerInObjects();
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    R0_ = 3;
  } while ((--R1_ & 0x80) == 0);
}

void ExtObj49_GhostHouseExit(uint8 k) {  // 0deabf
  uint8 v0 = blocks_sub_scr_pos;
  uint8 v1 = 0;
  do {
    R0_ = 5;
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, *((uint8 *)kExtObj49_GhostHouseExit_Tiles + v1++));
    } while ((--R0_ & 0x80) == 0);
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while (v1 != 78);
}

void ExtObj80_GhostHouseEntrance(uint8 k) {  // 0deb6a
  uint8 v0 = blocks_sub_scr_pos;
  for (uint8 i = 0; i != 0x8C; ++i) {
    R0_ = 9;
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, *((uint8 *)kExtObj80_GhostHouseEntrance_Tiles + i++));
    } while (--R0_);
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, *((uint8 *)kExtObj80_GhostHouseEntrance_Tiles + i));
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  }
}

void ExtObj85_YoshisHouse(uint8 k) {  // 0dec33
  uint8 v0 = blocks_sub_scr_pos;
  for (uint8 i = 0; i != 0xA0; ++i) {
    R0_ = 15;
    do {
      SetMap16HighByteForCurrentObject_Page00(v0);
      v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, *((uint8 *)kExtObj85_YoshisHouse_Tiles + i++));
    } while (--R0_);
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, *((uint8 *)kExtObj85_YoshisHouse_Tiles + i));
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  }
}

void ExtObj97_SwitchPalaceRightAndBottomEdgeTile(uint8 k) {  // 0dec5c
  uint8 v0 = blocks_sub_scr_pos;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  IndirWriteByte(&ptr_lo_map16_data, v0, 0x10);
}

void ExtObj81_Seaweed(uint8 k) {  // 0dec68
  uint8 v0 = blocks_sub_scr_pos;
  for (uint8 i = 0; i != 2; ++i) {
    SetMap16HighByteForCurrentObject_Page00(v0);
    IndirWriteByte(&ptr_lo_map16_data, v0, kExtObj81_Seaweed_Tiles[i]);
    v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  }
}

void ExtObj8D_SwitchPalaceSwitch(uint8 k) {  // 0dec8e
  uint8 v0 = blocks_sub_scr_pos;
  if (!flag_activated_switches[(uint8)(blocks_size_or_type + 118)]) {
    uint8 v1 = 4 * (blocks_size_or_type + 118);
    R0_ = 1;
    R1_ = 1;
    do {
      R2_ = R0_;
      do {
        SetMap16HighByteForCurrentObject_Page00(v0);
        v0 = HandleHorizontalSubScreenCrossingForCurrentObject(v0, *((uint8 *)kExtObj8A_GreenSwitchPalaceSwitch_Tiles + v1++));
      } while ((--R2_ & 0x80) == 0);
      v0 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    } while ((--R1_ & 0x80) == 0);
  }
}

void ExtObj8F_GhostHouseWindow(uint8 k) {  // 0decc1
  ExtObj64_TopRightCobweb_GhostHouseWindowEntry(8);
}

void GhostHouseObj36_WoodenBlocks(uint8 k) {  // 0decc9
  GhostHouseObj35_BrickBackground_0DECCE(k - 52);
}

void GhostHouseObj35_BrickBackground_0DECCE(uint8 k) {  // 0decce
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R2_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  while (1) {
    SetMap16HighByteForCurrentObject_Page00(v1);
    if (k == 1)
      SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, kGhostObj35_BrickBackground_Tiles[k]);
    if ((--R2_ & 0x80) != 0) {
      RestoreLevelDataPointerInObjects();
      v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
      R2_ = R0_;
      if ((--R1_ & 0x80) != 0)
        break;
    }
  }
}

void GhostHouseObj37_HorizontalBackgroundLogAndRailing(uint8 k) {  // 0ded12
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_size_or_type >> 4;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  for (uint8 i = kGhostObj37_HorizontalBackgroundLogAndRailing_LeftTiles[v2];;
       i = kGhostObj37_HorizontalBackgroundLogAndRailing_MiddleTiles[v2]) {
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, i);
    if (!--R0_)
      break;
    SetMap16HighByteForCurrentObject_Page00(v1);
  }
  SetMap16HighByteForCurrentObject_Page00(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, kGhostObj37_HorizontalBackgroundLogAndRailing_RightTiles[v2]);
}

void GhostHouseObj38_WoodenLedge(uint8 k) {  // 0ded43
  GhostHouseObj38_WoodenLedge_WoodLedgeOnColumnEntry(blocks_size_or_type & 0xF, blocks_sub_scr_pos);
}

void GhostHouseObj38_WoodenLedge_WoodLedgeOnColumnEntry(uint8 k, uint8 j) {  // 0ded4a
  SetMap16HighByteForCurrentObject_Page01(j);
  for (uint8 i = 10;; i = 11) {
    j = HandleHorizontalSubScreenCrossingForCurrentObject(j, i);
    if (!--k)
      break;
    SetMap16HighByteForCurrentObject_Page01(j);
  }
  SetMap16HighByteForCurrentObject_Page01(j);
  IndirWriteByte(&ptr_lo_map16_data, j, 0xC);
}

void GhostHouseObj39_VerticalBackgroundLog(uint8 k) {  // 0ded6b
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  uint8 v2 = blocks_size_or_type & 0xF;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  for (uint8 i = kGhostObj39_VerticalBackgroundLog_TopTiles[v2];; i = kGhostObj39_VerticalBackgroundLog_BottomTiles[v2]) {
    IndirWriteByte(&ptr_lo_map16_data, v1, i);
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R0_ & 0x80) != 0)
      break;
    SetMap16HighByteForCurrentObject_Page00(v1);
  }
}

void GhostHouseObj3A_SolidBrickWallAndVerticalLineOfSpikes(uint8 k) {  // 0ded99
  uint8 v1 = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page01(v2);
    IndirWriteByte(&ptr_lo_map16_data, v2, kGhostObj3A_SolidBrickWallAndVerticalLineOfSpikes_Tiles[v1]);
    v2 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    --R0_;
  } while ((R0_ & 0x80) == 0);
}

void GhostHouseObj3B_BonusGameLedge(uint8 k) {  // 0dedb9
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type & 0xF;
  SetMap16HighByteForCurrentObject_Page01(blocks_sub_scr_pos);
  for (uint8 i = 7;; i = 8) {
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, i);
    if (!--v2)
      break;
    SetMap16HighByteForCurrentObject_Page01(v1);
  }
  SetMap16HighByteForCurrentObject_Page01(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, 9);
}

void GhostHouseObj3C_SwitchPalaceCeiling(uint8 k) {  // 0deddb
  int8 i;
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  for (i = R0_; R1_; --R1_) {
    do {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x53);
      --i;
    } while (i >= 0);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    i = R0_;
  }
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x54);
    --i;
  } while (i >= 0);
}

void GhostHouseObj3D_SwitchPalaceLedge(uint8 k) {  // 0dee17
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  int8 v2 = R0_;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x5D);
    --v2;
  } while (v2 >= 0);
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    int8 v4 = R0_;
    if ((--R1_ & 0x80) != 0)
      break;
    do {
      SetMap16HighByteForCurrentObject_Page01(v3);
      v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0x53);
      --v4;
    } while (v4 >= 0);
  }
}

void GhostHouseObj3E_SwitchPalaceRightFacingWall(uint8 k) {  // 0dee52
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  do {
    for (uint8 i = R0_; i; --i) {
      SetMap16HighByteForCurrentObject_Page01(v1);
      v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x53);
    }
    SetMap16HighByteForCurrentObject_Page01(v1);
    HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x55);
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while ((--R1_ & 0x80) == 0);
}

void GhostHouseObj3F_SwitchPalaceLeftFacingWall(uint8 k) {  // 0dee89
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    uint8 v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0x5C);
    int8 v3 = R0_;
    if (R0_) {
      do {
        SetMap16HighByteForCurrentObject_Page01(v2);
        v2 = HandleHorizontalSubScreenCrossingForCurrentObject(v2, 0x53);
        --v3;
      } while (v3 >= 0);
    }
    RestoreLevelDataPointerInObjects();
    v1 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
  } while ((--R1_ & 0x80) == 0);
}

void GhostHouseObj34_WoodLedgeOnColumn(uint8 k) {  // 0deec0
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = 4 * (blocks_size_or_type & 0xF) + 2;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  GhostHouseObj38_WoodenLedge_WoodLedgeOnColumnEntry(v2, v1);
  RestoreLevelDataPointerInObjects();
  int8 v3 = blocks_sub_scr_pos + 1;
  if (((blocks_sub_scr_pos + 1) & 0xF) == 0) {
    v3 = blocks_sub_scr_pos & 0xF0;
    GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
  }
  if (v3 + 16 >= 256)
    HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel_Entry2(1);
  blocks_sub_scr_pos = v3 + 16;
  uint8 v5 = v3 + 16;
  do {
    RestoreLevelDataPointerInObjects();
    uint8 v6 = R1_;
    SetMap16HighByteForCurrentObject_Page00(v5);
    for (uint8 i = 120;; i = 121) {
      IndirWriteByte(&ptr_lo_map16_data, v5, i);
      if (v5 + 16 >= 256)
        HIBYTE(ptr_hi_map16_data) = ++HIBYTE(ptr_lo_map16_data);
      v5 += 16;
      if (!--v6)
        break;
      SetMap16HighByteForCurrentObject_Page00(v5);
    }
    RestoreLevelDataPointerInObjects();
    v5 = blocks_sub_scr_pos + 4;
    if (sign8(((blocks_sub_scr_pos + 4) & 0xF) - 4)) {
      v5 = blocks_sub_scr_pos - 12;
      GoForwardOneScreenAndUpdateLevelDataPointerInObjects();
    }
    blocks_sub_scr_pos = v5;
  } while ((--R0_ & 0x80) == 0);
}

void GhostHouseObj33_Cloud(uint8 k) {  // 0def45
  uint8 v1 = blocks_sub_scr_pos;
  int8 v2 = blocks_size_or_type & 0xF;
  SetMap16HighByteForCurrentObject_Page00(blocks_sub_scr_pos);
  for (uint8 i = -96;; i = -95) {
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, i);
    if (!--v2)
      break;
    SetMap16HighByteForCurrentObject_Page00(v1);
  }
  SetMap16HighByteForCurrentObject_Page00(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, 0xA2);
}

void GhostHouseObj32_GrassLedge2(uint8 k) {  // 0def67
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  int8 v2 = blocks_size_or_type & 0xF;
  PreserveLevelDataPointerInObjects();
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xE);
  } while (--v2 >= 0);
  while ((--R1_ & 0x80) == 0) {
    RestoreLevelDataPointerInObjects();
    uint8 v3 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    int8 v4 = R0_;
    do {
      SetMap16HighByteForCurrentObject_Page00(v3);
      v3 = HandleHorizontalSubScreenCrossingForCurrentObject(v3, 0xA3);
    } while (--v4 >= 0);
  }
}

void GhostHouseObj31_WoodCrate(uint8 k) {  // 0defa8
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  R2_ = R0_;
  SetMap16HighByteForCurrentObject_Page01(v1);
  for (uint8 i = 97;; i = 13) {
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, i);
    if (!--R2_)
      break;
    SetMap16HighByteForCurrentObject_Page01(v1);
  }
  SetMap16HighByteForCurrentObject_Page01(v1);
  IndirWriteByte(&ptr_lo_map16_data, v1, 0x62);
  uint8 v5;
  for (uint8 j = 1;;) {
    RestoreLevelDataPointerInObjects();
    R2_ = R0_;
    j ^= 1;
    v5 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if (!--R1_)
      break;
    SetMap16HighByteForCurrentObject_Page01(v5);
    uint8 v4 = kGhostObj31_WoodCrate_LeftEdgeTiles[j];
    if (v4)
      goto LABEL_7;
    do {
      SetMap16HighByteForCurrentObject_Page00(v5);
      v4 = kGhostObj31_WoodCrate_MiddleTiles[j];
LABEL_7:
      v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, v4);
    } while (--R2_);
    SetMap16HighByteForCurrentObject_Page01(v5);
    IndirWriteByte(&ptr_lo_map16_data, v5, kGhostObj31_WoodCrate_RightEdgeTiles[j]);
  }
  SetMap16HighByteForCurrentObject_Page01(v5);
  for (uint8 m = 107;; m = 108) {
    v5 = HandleHorizontalSubScreenCrossingForCurrentObject(v5, m);
    if (!--R0_)
      break;
    SetMap16HighByteForCurrentObject_Page01(v5);
  }
  SetMap16HighByteForCurrentObject_Page01(v5);
  IndirWriteByte(&ptr_lo_map16_data, v5, 0x6D);
}

void GhostHouseObj30_GrassLedge1(uint8 k) {  // 0df02b
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  R1_ = blocks_size_or_type >> 4;
  PreserveLevelDataPointerInObjects();
  int8 v2 = R0_;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, 0xF);
  } while (--v2 >= 0);
  while (1) {
    RestoreLevelDataPointerInObjects();
    uint8 v4 = HandleVerticalSubScreenCrossingForCurrentObject_HorizontalLevel();
    if ((--R1_ & 0x80) != 0)
      break;
    int8 v3 = R0_;
    do {
      SetMap16HighByteForCurrentObject_Page00(v4);
      v4 = HandleHorizontalSubScreenCrossingForCurrentObject(v4, 0xEA);
    } while (--v3 >= 0);
  }
}

void GhostHouseObj35_BrickBackground_LogBackgroundEntry(uint8 k) {  // 0df066
  GhostHouseObj35_BrickBackground_0DECCE(2);
}

void GhostHouseObj2E_HorizontalLineOfSpikes(uint8 k) {  // 0df06c
  uint8 v1 = blocks_sub_scr_pos;
  R0_ = blocks_size_or_type & 0xF;
  uint8 v2 = blocks_size_or_type >> 4;
  do {
    SetMap16HighByteForCurrentObject_Page01(v1);
    v1 = HandleHorizontalSubScreenCrossingForCurrentObject(v1, *(&kGhostObj2E_HorizontalLineOfSpikes_Tiles + v2));
  } while ((--R0_ & 0x80) == 0);
}
