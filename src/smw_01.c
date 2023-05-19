#include "consts.h"
#include "funcs.h"
#include "smw_rtl.h"
#include "variables.h"

void (*kUnk_18137[13])(uint8) = {
    &SprStatus00_EmptySlot,   &SprStatus01_Init,         &SprStatus02_Dead,
    &SprStatus03_Smushed,     &SprStatus04_SpinJumpKill, &SprStatus02_Dead_Status05Entry,
    &SprStatus06_GoalCoins,   &SprStatus00_EmptySlot_Return,  &SprStatus08_Return,
    &SprStatus09_Stunned,     &SprStatus0A_Kicked,       &SprStatus0B_Carried,
    &SprStatus0C_GoalPowerUp,
};

void (*kUnk_1817d[201])(uint8) = {
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &Spr06F_DinoTorch_Init_01855D,
    &Spr00E_Keyhole_Init,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &Spr012_Unused_Init,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &SprXXX_FixedMovementCheepCheep_Init_Return,
    &Spr016_VerticalCheepCheep_Init,
    &Spr017_GeneratorCheepCheep_Init,
    &Spr017_GeneratorCheepCheep_Init,
    &Spr019_DisplayMessage_Init,
    &SprXXX_RegularPiranhaPlant_Init_ShiftSpriteDown,
    &SprStatus08_Return,
    &Spr01C_BulletBill_Init,
    &SprXXX_Generic_Init_StandardSpritesInit,
    &Spr01E_Lakitu_Init,
    &Spr01F_MagiKoopa_Init,
    &SprXXX_Generic_Init_Return,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &SprXXX_NetKoopas_Init_VerticalNetKoopaEntry,
    &SprXXX_NetKoopas_Init_VerticalNetKoopaEntry,
    &SprXXX_NetKoopas_Init_HorizontalNetKoopaEntry,
    &SprXXX_NetKoopas_Init_HorizontalNetKoopaEntry,
    &Spr026_Thwomp_Init,
    &Spr026_Thwomp_Init_Return,
    &SprXXX_Eeries_Init_SetInitialFrameCounter,
    &Spr029_KoopaKids_Init,
    &SprXXX_RegularPiranhaPlant_Init,
    &SprStatus08_Return,
    &Spr02C_YoshiEgg_Init,
    &Spr080_Key_Init,
    &SprXXX_WallFollowers_Init_SpikeTopEntry,
    &SprStatus08_Return,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &Spr033_Podoboo_Init,
    &SprStatus08_Return,
    &Spr035_Yoshi_Init,
    &SprStatus08_Return,
    &SprXXX_Eeries_Init_SetInitialFrameCounter,
    &SprXXX_Eeries_Init,
    &SprXXX_Eeries_Init,
    &SprXXX_WallFollowers_Init_01841B,
    &SprXXX_WallFollowers_Init_01841B,
    &SprXXX_WallFollowers_Init_WallFollowUrchinEntry,
    &SprXXX_WallFollowers_Init_RipVanFishEntry,
    &Spr03E_PSwitch_Init,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &Spr081_ChangingItem_Init_Return,
    &Spr081_ChangingItem_Init_Return,
    &Spr081_ChangingItem_Init_Return,
    &Spr081_ChangingItem_Init_Return,
    &SprStatus08_Return,
    &Spr095_ClappinChuck_Init_DigginChuckEntry,
    &Spr035_Yoshi_Init_Return,
    &Spr035_Yoshi_Init_Return,
    &Spr049_ShiftingPipe_Init,
    &Spr035_Yoshi_Init_Return,
    &SprXXX_RegularPiranhaPlant_Init_ShiftSpriteDown,
    &Spr04C_ExplodingBlock_Init_MainV,
    &Spr01E_Lakitu_Init_SetLakituType,
    &Spr01E_Lakitu_Init_SetLakituType,
    &SprXXX_RegularPiranhaPlant_Init_ShiftSpriteDown,
    &SprXXX_RegularPiranhaPlant_Init_ShiftSpriteDown,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &Spr052_MovingLedgeHole_Init,
    &SprStatus08_Return,
    &Spr054_ClimbingNetDoor_Init,
    &Spr057_VerticalCheckerboardPlatform_Init,
    &SprXXX_BuoyantPlatformsAndMine_Init_Return,
    &Spr057_VerticalCheckerboardPlatform_Init,
    &SprXXX_BuoyantPlatformsAndMine_Init_Return,
    &SprXXX_BuoyantPlatformsAndMine_Init_HorizontalTurnBlockBridgeEntry,
    &SprXXX_BuoyantPlatformsAndMine_Init_HorizontalTurnBlockBridgeEntry,
    &SprXXX_BuoyantPlatformsAndMine_Init_InitFloatingPlat,
    &SprXXX_BuoyantPlatformsAndMine_Init_BuoyantCheckboardPlatformEntry,
    &SprXXX_BuoyantPlatformsAndMine_Init_InitFloatingPlat,
    &SprXXX_BuoyantPlatformsAndMine_Init_FloatingOrangePlatformEntry,
    &Spr05F_BrownChainedPlatform_Init,
    &Spr060_FlatPalaceSwitch_Init,
    &Spr061_SkullRaft_Init,
    &SprXXX_LineGuided_Init_BrownLineGuidePlatformEntry,
    &SprXXX_LineGuided_Init_CheckerboardLineGuidePlatformEntry,
    &SprXXX_LineGuided_Init_LineGuideRopeEntry,
    &SprXXX_LineGuided_Init_ChainsawEntry,
    &SprXXX_LineGuided_Init_ChainsawEntry,
    &SprXXX_LineGuided_Init_ChainsawEntry,
    &SprXXX_LineGuided_Init_ChainsawEntry,
    &SprXXX_ParachutingEnemy_Return,
    &SprStatus08_Return,
    &Spr081_ChangingItem_Init_Return,
    &Spr06C_RightWallSpringboard_Init,
    &SprStatus08_Return,
    &Spr06E_DinoRhino_Init,
    &Spr06E_DinoRhino_Init,
    &Spr070_Pokey_Init,
    &Spr071_RedCapeSuperKoopa_Init,
    &Spr071_RedCapeSuperKoopa_Init,
    &Spr073_GroundSuperKoopa_Init,
    &Spr076_Star_Init,
    &Spr076_Star_Init,
    &Spr076_Star_Init,
    &Spr076_Star_Init,
    &Spr076_Star_Init,
    &SprXXX_Generic_Init_Return,
    &SprXXX_Generic_Init_Return,
    &Spr07B_GoalTape_Init,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &Spr080_Key_Init,
    &Spr081_ChangingItem_Init,
    &Spr082_BonusGame_Init,
    &Spr085_Unused,
    &Spr085_Unused,
    &SprStatus08_Return,
    &Spr086_Wiggler_Init,
    &SprStatus08_Return,
    &Spr088_WingedCage_Init,
    &Spr081_ChangingItem_Init_Return,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &Spr019_DisplayMessage_Init,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &Spr08F_ScalePlatform_Init,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &Spr091_CharginChuck_Init,
    &Spr095_ClappinChuck_Init_BouncinChuckEntry,
    &Spr095_ClappinChuck_Init_BouncinChuckEntry,
    &Spr095_ClappinChuck_Init_WhistlinChuckEntry,
    &Spr095_ClappinChuck_Init,
    &Spr091_CharginChuck_Init,
    &Spr095_ClappinChuck_Init_PuntinChuckEntry,
    &Spr095_ClappinChuck_Init_PitchinChuckEntry,
    &Spr035_Yoshi_Init_Return,
    &Spr09A_SumoBro_Init,
    &Spr09B_HammerBro_Init,
    &SprStatus08_Return,
    &Spr09D_BubbleWithSprite_Init,
    &Spr09E_BallNChain_Init,
    &Spr09F_BanzaiBill_Init,
    &Spr0A0_ActivateBowserBattle_Init,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &Spr09E_BallNChain_Init_GreyChainedPlatformEntry,
    &SprXXX_BuoyantPlatformsAndMine_Init_SpikeBallEntry,
    &SprXXX_WallFollowers_Init_SparkyEntry,
    &SprXXX_WallFollowers_Init_SparkyEntry,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &Spr0A9_Reznor_Init,
    &Spr0AA_Fishbone_Init,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &Spr0AC_DownFirstWoodenSpike_Init,
    &Spr0AD_UpDownFirstWoodenSpike_Init,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &SprXXX_ReflectingEnemy_Init,
    &Spr0B1_CreateEatBlock_Init,
    &SprStatus08_Return,
    &Spr0B3_BowserStatueFire_Init,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &SprStatus08_Return,
    &SprXXX_ReflectingEnemy_Init,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &SprStatus08_Return,
    &Spr0BA_TimedPlatform_Init,
    &SprStatus08_Return,
    &Spr0BC_BowserStatue_Init,
    &Spr0BD_SlidingNakedBlueKoopa_Init,
    &SprStatus08_Return,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &Spr0C0_SinkingLavaPlatform_Init,
    &Spr01E_Lakitu_Init_SetLakituType,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &SprStatus08_Return,
    &SprXXX_Generic_Init_MakeSpriteFacePlayerV,
    &Spr0C0_SinkingLavaPlatform_Init_Return,
    &SprStatus08_Return,
    &SprStatus08_Return,
};
void (*kSprStatus08SpriteNormalPtrs[201])(uint8 k) = {
    &SprXXX_Generic_NakedKoopaEntry,
    &SprXXX_Generic_NakedKoopaEntry,
    &SprXXX_Generic_NakedKoopaEntry,
    &SprXXX_Generic_NakedKoopaEntry,
    &SprXXX_Generic_SpinyEntry,
    &SprXXX_Generic_SpinyEntry,
    &SprXXX_Generic_SpinyEntry,
    &SprXXX_Generic_SpinyEntry,
    &SprXXX_Generic_GreenParaKoopaEntry,
    &SprXXX_Generic_GreenParaKoopaEntry,
    &SprXXX_Generic_VerticalRedParaKoopaEntry,
    &SprXXX_Generic_HorizontalRedParaKoopaEntry,
    &SprXXX_Generic_SpinyEntry,
    &SprXXX_Generic_BobOmbEntry,
    &Spr00E_Keyhole,
    &SprXXX_Generic_SpinyEntry,
    &Spr010_ParaGoomba,
    &SprXXX_Generic_SpinyEntry,
    &Spr012_Unused_Init_Return,
    &SprXXX_Generic_SpinyEntry,
    &Spr014_SpinyEgg,
    &Spr016_VerticalCheepCheep,
    &Spr016_VerticalCheepCheep,
    &Spr017_GeneratorCheepCheep,
    &Spr018_SurfaceJumpingCheepCheep,
    &Spr03E_PSwitch,
    &Spr01A_ClassicPiranhaPlant,
    &Spr0A0_ActivateBowserBattle,
    &Spr01C_BulletBill,
    &Spr01D_HoppingFlame,
    &Spr01E_Lakitu,
    &Spr01F_MagiKoopa,
    &Spr020_Magic,
    &SprXXX_PowerUps_StarEntry,
    &SprXXX_NetKoopas,
    &SprXXX_NetKoopas,
    &SprXXX_NetKoopas,
    &SprXXX_NetKoopas,
    &Spr026_Thwomp,
    &Spr027_Thwimp,
    &SprXXX_NonBossBoos_BigBooEntry,
    &Spr029_KoopaKids,
    &Spr01A_ClassicPiranhaPlant,
    &Spr02B_SumoLightning,
    &Spr02C_YoshiEgg,
    &SprStatus08_Return,
    &Spr0A5_Sparky,
    &Spr02F_PortableSpringboard,
    &Spr031_BonyBeetle,
    &Spr031_BonyBeetle,
    &Spr031_BonyBeetle,
    &Spr033_Podoboo,
    &Spr034_LudwigFireball,
    &Spr035_Yoshi,
    NULL,
    &SprXXX_NonBossBoos_BooEntry,
    &SprXXX_Eeries,
    &SprXXX_Eeries,
    &Spr0A5_Sparky,
    &Spr0A5_Sparky,
    &Spr0A5_Sparky,
    &Spr03D_RipVanFish,
    &Spr03E_PSwitch,
    &Spr03F_ParachuteGoomba,
    &Spr03F_ParachuteGoomba,
    &SprXXX_Dolphins,
    &SprXXX_Dolphins,
    &SprXXX_Dolphins,
    &Spr044_TorpedoTed,
    &Spr045_DirectionalCoins,
    &Spr046_DigginChuck,
    &Spr047_SwimmingAndJumpingCheepCheep,
    &Spr048_DigginChuckRock,
    &Spr049_ShiftingPipe,
    &Spr04A_GoalSphere,
    &Spr04B_PipeLakitu,
    &Spr04C_ExplodingBlock,
    &Spr04E_LedgeMontyMole,
    &Spr04E_LedgeMontyMole,
    &Spr04F_JumpingPiranhaPlant,
    &Spr04F_JumpingPiranhaPlant,
    &Spr0A0_ActivateBowserBattle,
    &Spr052_MovingLedgeHole,
    &SprStatus08_Return,
    &Spr054_ClimbingNetDoor,
    &Spr058_VerticalRockPlatform,
    &Spr058_VerticalRockPlatform,
    &Spr058_VerticalRockPlatform,
    &Spr058_VerticalRockPlatform,
    &SprXXX_TurnBlockBridge_HorizontalAndVerticalTurnBlockBridgeEntry,
    &SprXXX_TurnBlockBridge_HorizontalTurnBlockBridgeEntry,
    &SprXXX_BuoyantPlatformsAndMine_01B563,
    &SprXXX_BuoyantPlatformsAndMine_01B563,
    &SprXXX_BuoyantPlatformsAndMine_01B563,
    &SprXXX_BuoyantPlatformsAndMine_FloatingOrangePlatformEntry,
    &Spr05F_BrownChainedPlatform,
    &Spr060_FlatPalaceSwitch,
    &Spr061_SkullRaft,
    &SprXXX_LineGuided_LineFuzzyPlats,
    &SprXXX_LineGuided_LineFuzzyPlats,
    &SprXXX_LineGuided_ChainsawEntry,
    &SprXXX_LineGuided_ChainsawEntry,
    &SprXXX_LineGuided_ChainsawEntry,
    &SprXXX_LineGuided_LineGuideGrinderEntry,
    &SprXXX_LineGuided_LineFuzzyPlats,
    &SprXXX_ParachutingEnemy_Return,
    &Spr06A_CoinGameCloud,
    &SprXXX_WallSpringboard,
    &SprXXX_WallSpringboard,
    &Spr06E_DinoRhino,
    &Spr06E_DinoRhino,
    &Spr06E_DinoRhino,
    &Spr070_Pokey,
    &SprXXX_SuperKoopas,
    &SprXXX_SuperKoopas,
    &SprXXX_SuperKoopas,
    &SprXXX_PowerUps_StarEntry,
    &SprXXX_PowerUps_FireFlowerEntry,
    &SprXXX_PowerUps_StarEntry,
    &Spr077_Feather,
    &SprXXX_PowerUps_StarEntry,
    &Spr079_VineHead,
    &Spr0A0_ActivateBowserBattle,
    &Spr07B_GoalTape,
    &Spr0A0_ActivateBowserBattle,
    &Spr080_Key,
    &Spr080_Key,
    &Spr080_Key,
    &Spr080_Key,
    &SprXXX_PowerUps_ChangingItemEntry,
    &Spr082_BonusGame,
    &Spr083_LeftFlyingBlock,
    &Spr083_LeftFlyingBlock,
    &Spr085_Unused,
    &Spr086_Wiggler,
    &Spr087_LakituCloud,
    &Spr088_WingedCage,
    &Spr089_Layer3Smasher,
    &Spr08A_Bird,
    &Spr08B_FireplaceSmoke,
    &Spr08C_SideExitAndFireplace,
    &Spr08D_GhostHouseDoor,
    &Spr08E_WarpHole,
    &Spr08F_ScalePlatform,
    &Spr090_GreenGasBubble,
    &Spr046_DigginChuck,
    &Spr046_DigginChuck,
    &Spr046_DigginChuck,
    &Spr046_DigginChuck,
    &Spr046_DigginChuck,
    &Spr046_DigginChuck,
    &Spr046_DigginChuck,
    &Spr046_DigginChuck,
    &Spr099_VolcanoLotus,
    &Spr09A_SumoBro,
    &Spr09B_HammerBro,
    &Spr09C_HammerBroPlatform,
    &Spr09D_BubbleWithSprite,
    &Spr09E_BallNChain,
    &Spr09E_BallNChain,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr09E_BallNChain,
    &SprXXX_BuoyantPlatformsAndMine_SpikeBallEntry,
    &Spr0A5_Sparky,
    &Spr0A5_Sparky,
    &Spr0A7_IggyBall,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &SprXXX_NonBossBoos_BooEntry,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0B4_NonLineGuideGrinder,
    &Spr033_Podoboo,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,
    &Spr0A0_ActivateBowserBattle,

};

void (*kSpr026_Thwomp_ThwompPtrs[3])(uint8 k) = {
    &Spr026_Thwomp_Waiting,
    &Spr026_Thwomp_Falling,
    &Spr026_Thwomp_Rising,
};
void (*kSpr01F_MagiKoopa_MagiKoopaPtrs[4])(uint8 k) = {
    &Spr01F_MagiKoopa_State00_FindOpenSpace,
    &Spr01F_MagiKoopa_State01_FadeIn,
    &Spr01F_MagiKoopa_State02_Shoot,
    &Spr01F_MagiKoopa_State03_FadeOut,
};
void (*kSprXXX_PowerUps_HandlePowerUpPtrs[6])(uint8 k) = {
    &SprXXX_PowerUps_GiveMarioMushroom, &SprXXX_PowerUps_01C56F,   &SprXXX_PowerUps_GiveMarioStar,
    &SprXXX_PowerUps_GiveMarioCape,     &SprXXX_PowerUps_GiveMarioFire, &SprXXX_PowerUps_GiveMario1Up,
};
void (*kSpr029_KoopaKid_MortonRoyLudwig_StatePtrs[6])(uint8 k) = {
    &Spr029_KoopaKid_MortonRoyLudwig_01CE1E,    &Spr029_KoopaKid_MortonRoyLudwig_01CE3E,
    &Spr029_KoopaKid_MortonRoyLudwig_State02, &Spr029_KoopaKid_MortonRoyLudwig_State03_Hurt,
    &Spr029_KoopaKid_MortonRoyLudwig_State04_Dying,  &Spr029_KoopaKid_MortonRoyLudwig_State05_ActivateLevelEnd,
};
void (*kSpr029_KoopaKid_MortonRoyLudwig_AttackRoutinePtrs[3])(uint8 k) = {
    &Spr029_KoopaKid_MortonRoyLudwig_ProcessRoysAttacks,
    &Spr029_KoopaKid_MortonRoyLudwig_ProcessRoysAttacks,
    &Spr029_KoopaKid_MortonRoyLudwig_ProcessLudwigsAttacks,
};
void (*kSprXXX_LineGuided_Ptrs01D762[3])(uint8 k) = {
    &SprXXX_LineGuided_State00_AtEndOfTile,
    &SprXXX_LineGuided_State01_OnLineGuide,
    &SprXXX_LineGuided_State02_Falling,
};
void (*kSprXXX_SmallMontyMole_GroundMontyMolePtrs[4])(uint8 k) = {
    &SprXXX_SmallMontyMole_State00_Invisible,
    &SprXXX_SmallMontyMole_State01_AboutToEmerge,
    &SprXXX_SmallMontyMole_State02_PopOutOfGround,
    &SprXXX_SmallMontyMole_State03_Walking,
};
void (*kSpr035_Yoshi_Ptrs01F0CB[4])(uint8 k) = {
    &Spr035_Yoshi_MouthState00,
    &Spr035_Yoshi_MouthState01_ExtendTongue,
    &Spr035_Yoshi_MouthState02_RetractTongue,
    &Spr035_Yoshi_MouthState03_Spitting,
};
void (*kSpr029_KoopaKids_KoopaKidPtrs[7])(uint8 k) = {
    &Spr029_KoopaKid_MortonRoyLudwig, &Spr029_KoopaKid_MortonRoyLudwig,
    &Spr029_KoopaKid_MortonRoyLudwig, &Spr029_KoopaKid_IggyLarry,
    &Spr029_KoopaKid_IggyLarry,       &Spr029_KoopaKid_WendyLemmy,
    &Spr029_KoopaKid_WendyLemmy,
};

uint8 CheckNormalSpriteLevelColl_Wall(uint8 k) {  // 018008
  return spr_table1588[k] & 3;
}

uint8 CheckNormalSpriteLevelColl_Floor(uint8 k) {  // 01800e
  return spr_table1588[k] & 4;
}

uint8 CheckNormalSpriteLevelColl_Ceiling(uint8 k) {  // 018014
  return spr_table1588[k] & 8;
}

void SpawnNormalSpriteTurnAroundSmoke(uint8 k) {  // 01804e
  if (spr_table1588[k]) {
    if (!(flag_ice_level | counter_global_frames & 3)) {
      R0_ = 4;
      R1_ = 10;
      SpawnNormalSpriteTurnAroundSmoke_Entry2(k);
    }
  }
}

void SpawnNormalSpriteTurnAroundSmoke_Entry2(uint8 k) {  // 018063
  if (!CheckIfNormalSpriteOffScreen(k)) {
    uint8 j = 3;
    while (smoke_spr_spriteid[j]) {
      if ((--j & 0x80) != 0)
        return;
    }
    smoke_spr_spriteid[j] = 3;
    smoke_spr_xpos_lo[j] = R0_ + spr_xpos_lo[k];
    smoke_spr_ypos_lo[j] = R1_ + spr_ypos_lo[k];
    smoke_spr_timer[j] = 19;
  }
}

void ProcessNormalSprites() {  // 01808c
  player_carrying_something_flag1 = player_carrying_something_flag2;
  player_carrying_something_flag2 = 0;
  misc_player_on_solid_sprite = 0;
  flag_player_in_lakitus_cloud = 0;
  yoshi_stray_yoshi_flag = sprites_yoshi_slot_index;
  sprites_yoshi_slot_index = 0;
  for (int8 i = 11; i >= 0; --i) {
    spr_current_slotid = i;
    ProcessNormalSprites_GetNormalSpriteOAMIndexAndDecrementTimers(i);
    ProcessNormalSprites_HandleSprite(i);
  }
  if (flag_run_cluster_sprites)
    ProcessClusterSprites();
  if (!sprites_yoshi_slot_index) {
    player_riding_yoshi_flag = 0;
    player_relative_yposition_during_screen_shake = 0;
  }
}

uint8 CheckIfNormalSpriteOffScreen(uint8 k) {  // 0180cb
  return spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k];
}

void ProcessNormalSprites_GetNormalSpriteOAMIndexAndDecrementTimers(uint8 k) {  // 0180d2
  spr_oamindex[k] =
      kProcessNormalSpritesSpriteOAMIndexes[(uint8)(kProcessNormalSprites_DATA_07F0B4[sprites_sprite_memory_setting] + k)];
  if (spr_current_status[k] && !flag_sprites_locked) {
    if (spr_decrementing_table1540[k])
      --spr_decrementing_table1540[k];
    if (spr_decrementing_table154c[k])
      --spr_decrementing_table154c[k];
    if (spr_decrementing_table1558[k])
      --spr_decrementing_table1558[k];
    if (spr_decrementing_table1564[k])
      --spr_decrementing_table1564[k];
    if (spr_decrementing_table1fe2[k])
      --spr_decrementing_table1fe2[k];
    if (spr_decrementing_table15ac[k])
      --spr_decrementing_table15ac[k];
    if (spr_decrementing_table163e[k])
      --spr_decrementing_table163e[k];
  }
}

void ProcessNormalSprites_HandleSprite(uint8 k) {  // 018127
  uint8 v1 = spr_current_status[k];
  if (v1) {
    if (v1 == 8)
      SprStatus08(k);
    else
      kUnk_18137[v1](k);
  } else {
    SprStatus00_EmptySlot(k);
  }
}

void SprStatus00_EmptySlot(uint8 k) {  // 018151
  spr_load_status_table_index[k] = -1;
}

void SprStatus00_EmptySlot_Return(uint8 k) {  // 018156
  ;
}

void SprStatus0C_GoalPowerUp(uint8 k) {  // 018157
  SprStatus08(k);
  SubOffscreen_Bank01_Entry1(k);
  HandleNormalSpriteGravity(k);
  spr_yspeed[k] -= 2;
  if (CheckNormalSpriteLevelColl_Floor(k))
    SetNormalSpriteYSpeedBasedOnSlope(k);
}

void SprStatus01_Init(uint8 k) {  // 018172
  spr_current_status[k] = 8;
  kUnk_1817d[spr_spriteid[k]](k);
}

void Spr0C0_SinkingLavaPlatform_Init(uint8 k) {  // 01830f
  spr_ypos_lo[k] += 2;
}

void Spr0C0_SinkingLavaPlatform_Init_Return(uint8 k) {  // 018313
  ;
}

void Spr0BC_BowserStatue_Init(uint8 k) {  // 018314
  ++spr_table157c[k];
  uint8 v1 = Spr04C_ExplodingBlock_Init(k);
  spr_table00c2[k] = v1;
  if (v1 == 2)
    spr_table15f6[k] = 1;
}

void Spr0BA_TimedPlatform_Init(uint8 k) {  // 018326
  spr_table1570[k] = (spr_xpos_lo[k] & 0x10) == 0 ? -1 : 63;
}

void Spr02C_YoshiEgg_Init(uint8 k) {  // 018339
  spr_table15f6[k] = kSpr02C_YoshiEgg_Init_EggPalette[(spr_xpos_lo[k] >> 4) & 3];
  ++spr_table187b[k];
}

void SprXXX_ReflectingEnemy_Init(uint8 k) {  // 01834e
  spr_xspeed[k] = kSprXXX_ReflectingEnemy_Init_InitYSpeed[SprXXX_Generic_Init_MakeSpriteFacePlayer(k)];
  spr_yspeed[k] = -16;
}

void Spr0AC_DownFirstWoodenSpike_Init(uint8 k) {  // 01835b
  AddSprYPos(k, -64);
}

void Spr0AD_UpDownFirstWoodenSpike_Init(uint8 k) {  // 01836b
  Spr01E_Lakitu_Init_SetLakituType(k);
}

void Spr09A_SumoBro_Init(uint8 k) {  // 018373
  spr_table00c2[k] = 3;
  spr_decrementing_table1540[k] = 112;
}

void Spr0BD_SlidingNakedBlueKoopa_Init(uint8 k) {  // 01837d
  spr_decrementing_table1540[k] = 4;
}

void Spr049_ShiftingPipe_Init(uint8 k) {  // 018381
  spr_table1534[k] = 64;
}

void Spr09F_BanzaiBill_Init(uint8 k) {  // 018387
  if (CheckPlayerPositionRelativeToSprite_Bank01_X(k))
    io_sound_ch3 = 9;
  else
    SubOffscreen_Bank01_EraseSprite(k);
}

void Spr09E_BallNChain_Init(uint8 k) {  // 018396
  spr_table187b[k] = 56;
}

void Spr09E_BallNChain_Init_GreyChainedPlatformEntry(uint8 k) {  // 01839a
  spr_table187b[k] = 48;
}

uint8 Spr04C_ExplodingBlock_Init(uint8 k) {  // 0183a4
  uint8 result = (spr_xpos_lo[k] >> 4) & 3;
  spr_table00c2[k] = kSpr04C_ExplodingBlock_Init_ExplodingBlkSpr[result];
  return result;
}

void Spr04C_ExplodingBlock_Init_MainV(uint8 k) {
  Spr04C_ExplodingBlock_Init(k);
}

void Spr08F_ScalePlatform_Init(uint8 k) {  // 0183b5
  SetHiLo(&spr_table151c[k], &spr_table1534[k], GetSprYPos(k));
  uint8 v1 = (uint8)(spr_xpos_lo[k] & 0x10) >> 4;
  SetHiLo(&spr_table1602[k], &spr_table00c2[k], GetSprXPos(k) + kSpr08F_ScalePlatform_Init_ScalePlatWidth[v1]);
}

void Spr019_DisplayMessage_Init(uint8 k) {  // 0183da
  spr_decrementing_table1564[k] = 40;
}

void Spr035_Yoshi_Init(uint8 k) {  // 0183e0
  --spr_table160e[k];
  ++spr_table157c[k];
  if (yoshi_carry_over_levels_flag)
    spr_current_status[k] = 0;
}

void Spr035_Yoshi_Init_Return(uint8 k) {  // 0183ee
  ;
}

void SprXXX_WallFollowers_Init_SpikeTopEntry(uint8 k) {  // 0183f2
  uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  SprXXX_WallFollowers_Init_01841D(k, 16 * (v1 ^ 1));
  spr_table164a[k] = 0;
  SprXXX_WallFollowers_Init_SparkyEntry2(k);
}

void SprXXX_WallFollowers_Init_WallFollowUrchinEntry(uint8 k) {  // 018404
  AddSprYPos(k, 1);
  SprXXX_WallFollowers_Init_SparkyEntry(k);
}

void SprXXX_WallFollowers_Init_SparkyEntry(uint8 k) {  // 01840b
  SprXXX_WallFollowers_Init_01841B(k);
  SprXXX_WallFollowers_Init_SparkyEntry2(k);
}

void SprXXX_WallFollowers_Init_SparkyEntry2(uint8 k) {  // 01840e
  uint8 v1 = spr_table151c[k] ^ 0x10;
  spr_table151c[k] = v1;
  spr_table00c2[k] = v1 >> 2;
}

void SprXXX_WallFollowers_Init_01841B(uint8 k) {  // 01841b
  SprXXX_WallFollowers_Init_01841D(k, spr_xpos_lo[k]);
}

void SprXXX_WallFollowers_Init_01841D(uint8 k, uint8 a) {  // 01841d
  uint8 v2 = 0;
  uint8 v3 = a & 0x10;
  spr_table151c[k] = v3;
  if (!v3)
    v2 = 1;
  spr_xspeed[k] = kSprXXX_WallFollowers_Init_DATA_0183EF[v2];
  spr_yspeed[k] = kSprXXX_WallFollowers_Init_DATA_0183EF[v2 + 1];
  SprXXX_WallFollowers_Init_RipVanFishEntry(k);
}

void SprXXX_WallFollowers_Init_RipVanFishEntry(uint8 k) {  // 018431
  ++spr_table164a[k];
}

void Spr080_Key_Init(uint8 k) {  // 018435
  spr_current_status[k] = 9;
}

void Spr081_ChangingItem_Init(uint8 k) {  // 01843b
  ++spr_table00c2[k];
}

void Spr081_ChangingItem_Init_Return(uint8 k) {  // 01843d
  ;
}

void Spr06C_RightWallSpringboard_Init(uint8 k) {  // 01843e
  AddSprXPos(k, -8);
}

void Spr03E_PSwitch_Init(uint8 k) {  // 01844e
  bool v1 = (spr_xpos_lo[k] & 0x10) != 0;
  spr_table151c[k] = v1;
  spr_table15f6[k] = kSpr03E_PSwitch_Init_PSwitchPal[v1];
  spr_current_status[k] = 9;
}

void Spr01E_Lakitu_Init(uint8 k) {  // 01846b
  for (uint8 i = 9; (i & 0x80) == 0; --i) {
    if (i != spr_current_slotid && spr_current_status[i] == 8 && (spr_spriteid[i] == 0x87 || spr_spriteid[i] == 30)) {
      SubOffscreen_Bank01_EraseSprite(k);
      return;
    }
  }
  timer_respawn_sprite = 0;
  timer_disappearing_sprite = 0;
  gen_spr_spriteid = 0;
  sprites_ypos_of_respawning_sprite = GetSprYPos(k);
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) == 0) {
    sprites_lakitu_cloud_slot_index = j;
    spr_spriteid[j] = -121;
    spr_current_status[j] = 8;
    SetSprXPos(j, GetSprXPos(k));
    SetSprYPos(j, GetSprYPos(k));
    InitializeNormalSpriteRAMTables(j);
    timer_despawn_lakitu_cloud = 0;
  }
  Spr01E_Lakitu_Init_SetLakituType(k);
}

void Spr01E_Lakitu_Init_SetLakituType(uint8 k) {  // 0184ce
  spr_table151c[k] = spr_xpos_lo[k] & 0x10;
}

void Spr0B1_CreateEatBlock_Init(uint8 k) {  // 0184d6
  flag_active_create_eat_block = -1;
  Spr01E_Lakitu_Init_SetLakituType(k);
}

void Spr01C_BulletBill_Init(uint8 k) {  // 0184dd
  spr_table00c2[k] = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  spr_decrementing_table1540[k] = 16;
}

void Spr095_ClappinChuck_Init(uint8 k) {  // 0184e9
  Spr095_ClappinChuck_Init_ChuckEntry_Comon(k, 8);
}

void Spr095_ClappinChuck_Init_PitchinChuckEntry(uint8 k) {  // 0184ed
  spr_table187b[k] = (uint8)(spr_xpos_lo[k] & 0x30) >> 4;
  Spr095_ClappinChuck_Init_ChuckEntry_Comon(k, 0xA);
}

void Spr095_ClappinChuck_Init_PuntinChuckEntry(uint8 k) {  // 0184fc
  Spr095_ClappinChuck_Init_ChuckEntry_Comon(k, 9);
}

void Spr095_ClappinChuck_Init_WhistlinChuckEntry(uint8 k) {  // 018500
  Spr095_ClappinChuck_Init_ChuckEntry_Comon(k, 0xB);
}

void Spr095_ClappinChuck_Init_BouncinChuckEntry(uint8 k) {  // 018504
  Spr095_ClappinChuck_Init_ChuckEntry_Comon(k, 5);
}

void Spr095_ClappinChuck_Init_DigginChuckEntry(uint8 k) {  // 018508
  spr_decrementing_table1540[k] = 48;
  spr_table157c[k] = (uint8)(spr_xpos_lo[k] & 0x10) >> 4;
  Spr095_ClappinChuck_Init_ChuckEntry_Comon(k, 4);
}

void Spr095_ClappinChuck_Init_ChuckEntry_Comon(uint8 k, uint8 a) {  // 01851a
  spr_table00c2[k] = a;
  spr_table151c[k] = kSpr095_ClappinChuck_Init_DATA_018526[SprXXX_Generic_Init_MakeSpriteFacePlayer(k)];
}

void Spr071_RedCapeSuperKoopa_Init(uint8 k) {  // 018528
  spr_yspeed[k] = 40;
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

void Spr073_GroundSuperKoopa_Init(uint8 k) {  // 01852e
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
  if ((spr_xpos_lo[k] & 0x10) != 0) {
    spr_property_bits1656[k] = 16;
    spr_property_bits1662[k] = 0x80;
    spr_property_bits1686[k] = 16;
  } else {
    ++spr_table1534[k];
  }
}

void Spr070_Pokey_Init(uint8 k) {  // 01854b
  spr_table00c2[k] = player_riding_yoshi_flag ? 31 : 7;
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

void Spr06E_DinoRhino_Init(uint8 k) {  // 018558
  spr_table151c[k] = 4;
  Spr06F_DinoTorch_Init_01855D(k);
}

void Spr06F_DinoTorch_Init_01855D(uint8 k) {  // 01855d
  spr_decrementing_table1540[k] = -1;
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

void Spr09D_BubbleWithSprite_Init(uint8 k) {  // 018564
  spr_table00c2[k] = Spr04C_ExplodingBlock_Init(k);
  --spr_table1534[k];
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

void SprXXX_Generic_Init(uint8 k) {  // 01856e
  spr_table160e[k] = spr_ypos_lo[k] & 0x10;
  SprXXX_Generic_Init_StandardSpritesInit(k);
}

void SprXXX_Generic_Init_StandardSpritesInit(uint8 k) {  // 018575
  spr_table1570[k] = GetRand();
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

uint8 SprXXX_Generic_Init_MakeSpriteFacePlayer(uint8 k) {  // 01857c
  uint8 result = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  spr_table157c[k] = result;
  return result;
}

void SprXXX_Generic_Init_MakeSpriteFacePlayerV(uint8 k) {
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

void SprXXX_Generic_Init_Return(uint8 k) {  // 018583
  ;
}

void Spr0B3_BowserStatueFire_Init(uint8 k) {  // 018584
  io_sound_ch3 = 23;
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

void Spr076_Star_Init(uint8 k) {  // 01858b
  ++spr_table00c2[k];
}

void Spr0AA_Fishbone_Init(uint8 k) {  // 01858e
  spr_decrementing_table1540[k] = GetRand() & 0x1F;
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

void SprXXX_RegularPiranhaPlant_Init(uint8 k) {  // 01859a
  spr_table15f6[k] |= 0x80;
  AddSprYPos(k, -16);
  SprXXX_RegularPiranhaPlant_Init_ShiftSpriteDown(k);
}

void SprXXX_RegularPiranhaPlant_Init_ShiftSpriteDown(uint8 k) {  // 0185b0
  spr_xpos_lo[k] += 8;
  AddSprYPos(k, -1);
}

void SprStatus08_Return(uint8 k) {  // 0185c2
  ;
}

void SprStatus08(uint8 k) {  // 0185c3
  sprites_position_disp = 0;
  kSprStatus08SpriteNormalPtrs[spr_spriteid[k]](k);
}

void Spr06E_DinoRhino(uint8 k) {  // 01875e
  Spr06F_DinoTorch(k);
}

void Spr04A_GoalSphere(uint8 k) {  // 018763
  GenericGFXRtDraw1Tile16x16(k);
  if (!flag_sprites_locked) {
    SpawnSparkles_GoalSphereEntry(k, flag_sprites_locked | counter_global_frames & 0x1F);
    if (CheckPlayerToNormalSpriteCollision(k) & 1) {
      spr_current_status[k] = 0;
      timer_end_level = -1;
      misc_music_register_backup = -1;
      io_music_ch1 = 11;
    }
  }
}

void Spr091_CharginChuck_Init(uint8 k) {  // 018869
}

void Spr052_MovingLedgeHole_Init(uint8 k) {  // 018890
  --spr_ypos_lo[k];
}

void SprXXX_Generic_JumpOverKickedObject(uint8 k) {  // 018898
  if (((counter_global_frames ^ k) & 3) == 0) {
    uint8 v1 = 9;
    while (1) {
      if (spr_current_status[v1] == 10) {
        SetHiLo(&R8_, &R0_, GetSprXPos(v1) - 26);
        R2_ = 68;
        SetHiLo(&R9_, &R1_, GetSprYPos(v1));
        R3_ = 16;
        StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
        if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
          if (CheckNormalSpriteLevelColl_Floor(k))
            break;
        }
      }
      if ((--v1 & 0x80) != 0)
        return;
    }
    if (spr_table157c[v1] != spr_table157c[k]) {
      spr_yspeed[k] = -64;
      spr_decrementing_table163e[k] = 0;
    }
  }
}

void SprXXX_Generic_NakedKoopaEntry(uint8 k) {  // 018904
  if (flag_sprites_locked)
    SprXXX_Generic_018908(k);
  else
    SprXXX_Generic_018952(k);
}

void SprXXX_Generic_018908(uint8 k) {  // 018908
  if (spr_decrementing_table163e[k] < 0x80 || flag_sprites_locked)
    sub_1891F(k);
  else
    SprXXX_Generic_018913(k);
}

void SprXXX_Generic_018913(uint8 k) {  // 018913
  SetNormalSpriteAnimationFrame(k);
  spr_table1602[k] += 5;
  sub_1891F(k);
}

void sub_1891F(uint8 k) {  // 01891f
  SprXXX_Generic_018931(k);
  HandleNormalSpriteGravity(k);
  spr_xspeed[k] = 0;
  if (CheckNormalSpriteLevelColl_Floor(k))
    spr_yspeed[k] = 0;
  CheckNormalSpriteToNormalSpriteCollision(k);
  SprXXX_Generic_Spr0to13Gfx(k);
}

void SprXXX_Generic_018931(uint8 k) {  // 018931
  if (spr_spriteid[k] == 2) {
    CheckPlayerToNormalSpriteCollision(k);
  } else {
    spr_property_bits167a[k] |= 0x80;
    if (CheckPlayerToNormalSpriteCollision(k) & 1)
      KickHelplessSprite(k);
    spr_property_bits167a[k] &= ~0x80;
  }
}

void SprXXX_Generic_018952(uint8 k) {  // 018952
  uint8 v2;

  uint8 v1 = spr_decrementing_table163e[k];
  if (v1) {
    if (v1 == 0x80) {
      SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
      v1 = spr_spriteid[k];
      if (v1 != 2) {
        v1 = -32; // bug?
        spr_yspeed[k] = -32;
      }
      spr_decrementing_table163e[k] = 0;
    }
    if (v1 != 1 || (v2 = spr_table160e[k], spr_current_status[v2] != 9) || (uint8)(spr_xpos_lo[k] - spr_xpos_lo[v2] + 18) >= 0x24) {
      SprXXX_Generic_018908(k);
      return;
    }
    CheckNormalSpriteToNormalSpriteColl_PlayKickSfx();
    CheckNormalSpriteToNormalSpriteColl_01A755(k);
    uint8 v3 = spr_table160e[k];
    spr_xspeed[v3] = kCheckNormalSpriteToNormalSpriteColl_DATA_01A6D7[spr_table157c[k]];
    spr_current_status[v3] = 10;
    spr_table00c2[v3] = spr_decrementing_table1540[v3];
    spr_decrementing_table1564[v3] = 8;
    if ((spr_property_bits167a[v3] & 0x10) != 0)
      spr_yspeed[v3] = -32;
  }
  if (!spr_table1528[k]) {
    if (spr_table1534[k]) {
      uint8 v8 = spr_table160e[k];
      if (spr_current_status[v8] != 10) {
        spr_table1534[k] = 0;
LABEL_43:
        spr_table1570[k] = 0;
        SprXXX_Generic_018B43(k);
        return;
      }
      spr_table1528[v8] = 10;
      if (CheckNormalSpriteLevelColl_Wall(k)) {
        spr_xspeed[v8] = 0;
        spr_xspeed[k] = 0;
      }
      if (!CheckNormalSpriteLevelColl_Floor(k))
        goto LABEL_43;
      R0_ = flag_ice_level ? 1 : 2;
      uint8 v10 = spr_xspeed[v8];
      if (v10 >= 2) {
        if ((int8)(v10 - 2) < 0)
          v10 += 2 * R0_;
        uint8 v11 = v10 - R0_;
        spr_xspeed[v8] = v11;
        spr_xspeed[k] = v11;
        SpawnNormalSpriteTurnAroundSmoke(k);
        goto LABEL_43;
      }
      spr_xspeed[k] = 0;
      spr_xspeed[v8] = 0;
      spr_table1534[k] = 0;
      spr_current_status[v8] = 9;
      CheckPlayerToNormalSpriteColl_01AA0B(v8);
      if (spr_decrementing_table1540[v8])
        spr_decrementing_table1540[v8] = -1;
    }
    uint8 t0 = spr_table00c2[k];
    if (t0) {
      --spr_table00c2[k];
      spr_table1602[k] = (t0 < 8) ? 0 : 4;
      CheckPlayerToNormalSpriteCollision(k);
      CheckNormalSpriteToNormalSpriteCollision(k);
      SprXXX_Generic_Spr0to13Gfx(k);
    } else if (spr_decrementing_table1558[k] == 1) {
      uint8 v13 = spr_table1594[k];
      if (spr_current_status[v13] >= 8 && (spr_yspeed[v13] & 0x80) == 0 && spr_spriteid[v13] != 33) {
        StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
        StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(v13);
        if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
          SubOffscreen_Bank01_EraseSprite(k);
          uint8 v14 = spr_table1594[k];
          spr_decrementing_table1558[v14] = 16;
          spr_table160e[v14] = spr_spriteid[k];
        }
      }
    } else {
      SprXXX_Generic_Spr0to13Main(k);
    }
    return;
  }
  if (CheckNormalSpriteLevelColl_Wall(k))
    spr_xspeed[k] = 0;
  if (!CheckNormalSpriteLevelColl_Floor(k))
    goto LABEL_23;
  uint8 v4 = 2;
  if (flag_ice_level)
    v4 = 1;
  R0_ = v4;
  uint8 v5 = spr_xspeed[k];
  if (v5 >= 2) {
    if ((int8)(v5 - 2) < 0)
      v5 += R0_ + R0_;
    spr_xspeed[k] = v5 - R0_;
    SpawnNormalSpriteTurnAroundSmoke(k);
LABEL_23:
    spr_table1570[k] = 0;
    SprXXX_Generic_018B43(k);
    get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = (spr_spriteid[k] != 2) ? 0x86 : 0xE6;
    return;
  }
  if (CheckNormalSpriteLevelColl_Floor(k)) {
    spr_decrementing_table163e[k] = (spr_spriteid[k] == 2) ? -96 : -1;
  }
  spr_table1528[k] = 0;
  SprXXX_Generic_018913(k);
}

void SprXXX_Generic_ExplodeBomb(uint8 k) {  // 018ada
  BobOmbExplosion(k);
}

void SprXXX_Generic_BobOmbEntry(uint8 k) {  // 018ae5
  if (spr_table1534[k]) {
    SprXXX_Generic_ExplodeBomb(k);
  } else if (spr_decrementing_table1540[k]) {
    SprXXX_Generic_SpinyEntry(k);
  } else {
    spr_current_status[k] = 9;
    spr_decrementing_table1540[k] = 64;
    GenericGFXRtDraw1Tile16x16(k);
  }
}

void SprXXX_Generic_SpinyEntry(uint8 k) {  // 018afc
  if (flag_sprites_locked) {
    CheckPlayerToNormalSpriteCollision(k);
    CheckNormalSpriteToNormalSpriteCollision(k);
    SprXXX_Generic_Spr0to13Gfx(k);
  } else {
    SprXXX_Generic_Spr0to13Main(k);
  }
}

void SprXXX_Generic_Spr0to13Main(uint8 k) {  // 018b0a
  if (CheckNormalSpriteLevelColl_Floor(k)) {
    uint8 v1 = spr_table157c[k];
    if (kSprXXX_Generic_Spr0to13Prop[spr_spriteid[k]] & 1)
      v1 += 2;
    uint8 v2 = kSprXXX_Generic_Spr0to13SpeedX[v1];
    if ((v2 ^ spr_slope_surface_its_on[k]) & 0x80)
      v2 += spr_slope_surface_its_on[k];
    spr_xspeed[k] = v2;
  }
  if ((spr_table1588[k] & (uint8)(spr_table157c[k] + 1) & 3) != 0)
    spr_xspeed[k] = 0;
  if (CheckNormalSpriteLevelColl_Ceiling(k))
    spr_yspeed[k] = 0;
  SprXXX_Generic_018B43(k);
}

void SprXXX_Generic_018B43(uint8 k) {  // 018b43
  SubOffscreen_Bank01_Entry1(k);
  HandleNormalSpriteGravity(k);
  SetNormalSpriteAnimationFrame(k);
  if (CheckNormalSpriteLevelColl_Floor(k)) {
    SetNormalSpriteYSpeedBasedOnSlope(k);
    spr_table151c[k] = 0;
    uint8 v3 = kSprXXX_Generic_Spr0to13Prop[spr_spriteid[k]];
    if ((v3 & 4) != 0 && (spr_table1570[k] & 0x7F) == 0) {
      uint8 v2 = spr_table157c[k];
      SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
      if (v2 != spr_table157c[k])
        spr_decrementing_table15ac[k] = 8;
    }
    if ((v3 & 8) != 0)
      SprXXX_Generic_JumpOverKickedObject(k);
  } else {
    uint8 v1 = spr_spriteid[k];
    if ((kSprXXX_Generic_Spr0to13Prop[v1] & 0x80) == 0)
      spr_table1570[k] = 0;
    else
      SetNormalSpriteAnimationFrame(k);
    if ((kSprXXX_Generic_Spr0to13Prop[v1] & 2) != 0 &&
        !(spr_table1534[k] | (uint8)(spr_table1528[k] | spr_decrementing_table1558[k] | spr_table151c[k]))) {
      ChangeNormalSpriteDirection(k);
      spr_table151c[k] = 1;
    }
  }
  if (spr_table1528[k])
    SprXXX_Generic_018931(k);
  else
    CheckPlayerToNormalSpriteCollision(k);
  CheckNormalSpriteToNormalSpriteCollision(k);
  ChangeNormalSpriteDirection_CheckIfTouchingWall(k);
  SprXXX_Generic_Spr0to13Gfx(k);
}

void SprXXX_Generic_Spr0to13Gfx(uint8 k) {  // 018bc3
  uint8 v5 = spr_table157c[k];
  uint8 v1 = spr_decrementing_table15ac[k];
  if (v1) {
    spr_table1602[k] = 2;
    spr_table157c[k] ^= v1 >= 5;
  }
  if ((kSprXXX_Generic_Spr0to13Prop[spr_spriteid[k]] & 0x40) != 0) {
    uint16 old_y = GetSprYPos(k);
    SetSprYPos(k, old_y - (!(spr_table1602[k] & 1) + 15));
    GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
    SetSprYPos(k, old_y);
    if (spr_spriteid[k] >= 8)
      DrawWingTiles_ParaKoopaEntry(k);
  } else {
    GenericGFXRtDraw1Tile16x16(k);
  }
  spr_table157c[k] = v5;
}

void Spr014_SpinyEgg(uint8 k) {  // 018c18
  if (!flag_sprites_locked && spr_current_status[k] == 8) {
    SetNormalSpriteAnimationFrame(k);
    HandleNormalSpriteGravity(k);
    --spr_yspeed[k];
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      spr_spriteid[k] = 19;
      InitializeNormalSpriteRAMTables(k);
      SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
      MakeStunnedSpriteBounceOrSlowDownOnGround(k);
    }
    ChangeNormalSpriteDirection_CheckIfTouchingWall(k);
    CheckPlayerAndNormalSpriteCollisions(k);
  }
  SubOffscreen_Bank01_Entry1(k);
  GenericGFXRtDraw4Tiles8x8Square(k, 2);
}

void SprXXX_Generic_GreenParaKoopaEntry(uint8 k) {  // 018c4d
  if (flag_sprites_locked) {
    SprXXX_Generic_018CB7(k);
  } else {
    uint8 v1 = spr_table157c[k];
    uint8 v2 = kSprXXX_Generic_Spr0to13SpeedX[v1];
    if ((v2 ^ spr_slope_surface_its_on[k]) & 0x80)
      v2 += spr_slope_surface_its_on[k];
    spr_xspeed[k] = v2;
    if ((spr_table1588[k] & (uint8)(v1 + 1) & 3) != 0)
      spr_xspeed[k] = 0;
    if (spr_spriteid[k] == 8) {
      UpdateNormalSpritePosition_X(k);
      spr_yspeed[k] = (spr_table1570[k] & 0x20) ? 4 : -4;
      UpdateNormalSpritePosition_Y(k);
    } else {
      HandleNormalSpriteGravity(k);
      --spr_yspeed[k];
    }
    CheckPlayerAndNormalSpriteCollisions(k);
    if (CheckNormalSpriteLevelColl_Ceiling(k))
      spr_yspeed[k] = 0;
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      SetNormalSpriteYSpeedBasedOnSlope(k);
      spr_yspeed[k] = spr_table160e[k] ? -48 : -80;
    }
    ChangeNormalSpriteDirection_CheckIfTouchingWall(k);
    SetNormalSpriteAnimationFrame(k);
    SubOffscreen_Bank01_Entry1(k);
    SprXXX_Generic_018CB7(k);
  }
}

void SprXXX_Generic_018CB7(uint8 k) {  // 018cb7
  SprXXX_Generic_Spr0to13Gfx(k);
}

void SprXXX_Generic_HorizontalRedParaKoopaEntry(uint8 k) {  // 018cbe
  SubOffscreen_Bank01_Entry2(k);
  SprXXX_Generic_018CC6(k);
}

void SprXXX_Generic_VerticalRedParaKoopaEntry(uint8 k) {  // 018cc3
  SubOffscreen_Bank01_Entry1(k);
  SprXXX_Generic_018CC6(k);
}

void SprXXX_Generic_018CC6(uint8 k) {  // 018cc6
  if (!flag_sprites_locked) {
    uint8 v4 = spr_table157c[k];
    SetFacingDirectionBasedOnSpeed(k);
    if (v4 != spr_table157c[k])
      spr_decrementing_table15ac[k] = 8;
    SetNormalSpriteAnimationFrame(k);
    if (spr_spriteid[k] == 10) {
      UpdateNormalSpritePosition_Y(k);
    } else {
      spr_yspeed[k] = ((spr_table1570[k] & 0x20) != 0) ? 4 : -4;
      UpdateNormalSpritePosition_Y(k);
      UpdateNormalSpritePosition_X(k);
    }
    if (!spr_decrementing_table1540[k] && (++spr_table00c2[k] & 3) == 0) {
      uint8 v2 = spr_table151c[k] & 1;
      uint8 v3 = kSprXXX_Generic_DATA_018CBA[v2] + spr_xspeed[k];
      spr_yspeed[k] = v3;
      spr_xspeed[k] = v3;
      if (v3 == kSprXXX_Generic_DATA_018CBC[v2]) {
        ++spr_table151c[k];
        spr_decrementing_table1540[k] = 48;
      }
    }
    CheckPlayerAndNormalSpriteCollisions(k);
  }
  SprXXX_Generic_018CB7(k);
}

void Spr010_ParaGoomba(uint8 k) {  // 018d2e
  SubOffscreen_Bank01_Entry1(k);
  if (flag_sprites_locked) {
    Spr010_ParaGoomba_018DAC(k);
  } else {
    SetXSpeedBasedOnNormalSpriteFacingDirection(k);
    HandleNormalSpriteGravity(k);
    --spr_yspeed[k];
    spr_table1602[k] = (spr_table00c2[k] & 8) != 0;
    Spr010_ParaGoomba_018DAC(k);
    ++spr_table00c2[k];
    if (!spr_table151c[k] && (spr_yspeed[k] & 0x80) != 0)
      spr_table1570[k] += 2;
    ++spr_table1570[k];
    if (CheckNormalSpriteLevelColl_Ceiling(k))
      spr_yspeed[k] = 0;
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      if ((spr_table00c2[k] & 0x3F) == 0)
        SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
      SetNormalSpriteYSpeedBasedOnSlope(k);
      if (!spr_table151c[k])
        spr_table1570[k] = 0;
      if (!spr_decrementing_table1540[k]) {
        ++spr_table151c[k];
        uint8 v1 = -16;
        if (spr_table151c[k] == 4) {
          spr_table151c[k] = 0;
          spr_decrementing_table1540[k] = GetRand() & 0x2F | 0x50;
          v1 = -48;
        }
        spr_yspeed[k] = v1;
      }
    }
    ChangeNormalSpriteDirection_CheckIfTouchingWall(k);
    CheckPlayerAndNormalSpriteCollisions(k);
  }
}

void Spr010_ParaGoomba_018DAC(uint8 k) {  // 018dac
  Spr010_ParaGoomba_GoombaWingDraw(k);
  spr_oamindex[k] += 4;
  GenericGFXRtDraw1Tile16x16(k);
}

void SetXSpeedBasedOnNormalSpriteFacingDirection(uint8 k) {  // 018dbb
  uint8 v1 = -8;
  if (!spr_table157c[k])
    v1 = 8;
  spr_xspeed[k] = v1;
}

void Spr010_ParaGoomba_GoombaWingDraw(uint8 k) {  // 018de9
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
  R5_ = spr_table1602[k] + ((spr_table1570[k] >> 2) & 2);
  R2_ = 2 * R5_;
  R4_ = spr_table157c[k];
  uint8 v1 = spr_oamindex[k];
  for (int8 i = 1; i >= 0; i--) {
    R3_ = i;
    uint8 v3 = R2_ + i;
    uint8 v8 = R2_ + i;
    if (!R4_)
      v3 += 8;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    oam[64].xpos = kSpr010_ParaGoomba_WingXDisp[v3] + R0_;
    oam[64].ypos = kSpr010_ParaGoomba_WingYDisp[v8] + R1_;
    int v5 = R5_;
    oam[64].charnum = kSpr010_ParaGoomba_WingTiles[R5_];
    sprites_oamtile_size_buffer[(v1 >> 2) + 64] = kSpr010_ParaGoomba_WingTileSize[v5];
    uint8 v6 = R3_;
    uint8 v7 = kSpr010_ParaGoomba_WingProp[R3_];
    if (!(R4_ & 1))
      v7 ^= 0x40;
    get_OamEnt(oam_buf, v1)[64].flags = sprites_tile_priority | v7;
    v1 += 8;
  }
  FinishOAMWrite(k, 0xFF, 2);
}

void SetNormalSpriteAnimationFrame(uint8 k) {  // 018e5f
  spr_table1602[k] = (++spr_table1570[k] & 8) != 0;
}

void Spr01A_ClassicPiranhaPlant(uint8 k) {  // 018e76
  if (!spr_table1594[k]) {
    uint8 v3 = sprites_tile_priority;
    if (!spr_table15d0[k])
      sprites_tile_priority = 16;
    GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    oam[66].flags = oam[66].flags & 0xF0 | 0xB;
    sprites_tile_priority = v3;
  }
  SubOffscreen_Bank01_Entry1(k);
  if (!flag_sprites_locked) {
    SetNormalSpriteAnimationFrame(k);
    if (!spr_table1594[k])
      CheckPlayerAndNormalSpriteCollisions(k);
    if (spr_decrementing_table1540[k]) {
      uint8 v2 = kSprXXX_RegularPiranhaPlant_YSpeed[spr_table00c2[k] & 3];
      if (spr_spriteid[k] == 42)
        v2 = -v2;
      spr_yspeed[k] = v2;
      UpdateNormalSpritePosition_Y(k);
    } else {
      R0_ = spr_table00c2[k] & 3;
      if (R0_ || (CheckPlayerPositionRelativeToSprite_Bank01_X(k), spr_table1594[k] = 1, (uint8)(R15_ + 0x1b) >= 0x37)) {
        spr_table1594[k] = 0;
        spr_decrementing_table1540[k] = kSprXXX_RegularPiranhaPlant_PhaseTimers[R0_];
        ++spr_table00c2[k];
      }
    }
  }
}

uint8 CheckAvailableExtendedSpriteSlot(uint8 k) {  // 018eef
  uint8 j = 7;
  while (ext_spr_spriteid[j]) {
    if ((--j & 0x80) != 0) {
      if ((--ext_spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
        ext_spr_slot_to_overwrite_when_slots_full = 7;
      return ext_spr_slot_to_overwrite_when_slots_full;
    }
  }
  return j;
}

void Spr01D_HoppingFlame(uint8 k) {  // 018f0d
  if (!flag_sprites_locked) {
    ++spr_table1602[k];
    SetNormalSpriteAnimationFrame(k);
    HandleNormalSpriteGravity(k);
    --spr_yspeed[k];
    SetXSpeedBasedOnNormalSpriteFacingDirection(k);
    spr_xspeed[k] *= 2;
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      spr_xspeed[k] = 0;
      SetNormalSpriteYSpeedBasedOnSlope(k);
      uint8 v1 = spr_decrementing_table1540[k];
      if (v1) {
        if (v1 == 1)
          Spr01D_HoppingFlame_018F50(k);
      } else {
        spr_decrementing_table1540[k] = GetRand() & 0x1F | 0x20;
      }
    }
    ChangeNormalSpriteDirection_CheckIfTouchingWall(k);
    CheckPlayerToNormalSpriteCollision(k);
  }
  SubOffscreen_Bank01_Entry1(k);
  GenericGFXRtDraw1Tile16x16(k);
}

void Spr01D_HoppingFlame_018F50(uint8 k) {  // 018f50
  spr_yspeed[k] = GetRand() & 0xF | 0xD0;
  if ((misc_random_byte1 & 3) == 0)
    SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
  if (!CheckIfNormalSpriteOffScreen(k)) {
    uint8 j = CheckAvailableExtendedSpriteSlot(k);
    SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], GetSprXPos(k) + 4);
    SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], GetSprYPos(k) + 8);
    ext_spr_spriteid[j] = 3;
    ext_spr_decrementing_table176f[j] = -1;
  }
}

void Spr01E_Lakitu(uint8 k) {  // 018f97
  spr_table1602[k] = spr_decrementing_table1558[k] ? 2 : 0;
  GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
  if (spr_decrementing_table1558[k]) {
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    oam[65].ypos -= 3;
  }
  if (spr_table151c[k])
    Spr01E_Lakitu_LakituFishingLineDraw(k);
  CheckPlayerAndNormalSpriteCollisions(k);
}

void CheckPlayerAndNormalSpriteCollisions(uint8 k) {  // 018fc1
  CheckNormalSpriteToNormalSpriteCollision(k);
  CheckPlayerToNormalSpriteCollision(k);
}

void Spr01C_BulletBill(uint8 k) {  // 018fe7
  spr_table157c[k] = 1;
  if (!flag_sprites_locked) {
    uint8 v1 = spr_table00c2[k];
    spr_table15f6[k] = kSpr01C_BulletBill_Prop[v1];
    spr_table1602[k] = kSpr01C_BulletBill_AnimationFrame[v1];
    spr_xspeed[k] = kSpr01C_BulletBill_XSpeed[v1];
    spr_yspeed[k] = kSpr01C_BulletBill_YSpeed[v1];
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
    HandleNormalSpriteLevelCollision(k);
    CheckPlayerAndNormalSpriteCollisions(k);
  }
  SubOffscreen_Bank01_Entry1(k);
  if ((uint8)(spr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xF0)
    spr_current_status[k] = 0;
  if (spr_decrementing_table1540[k])
    SprStatus09_Stunned_BulletBillEntry(k);
  else
    GenericGFXRtDraw1Tile16x16(k);
}

void HandleNormalSpriteGravity(uint8 k) {  // 019032
  UpdateNormalSpritePosition_Y(k);
  uint8 v1 = 0;
  if (spr_table164a[k]) {
    v1 = 1;
    if ((int8)spr_yspeed[k] <= -25)
      spr_yspeed[k] = -24;
  }
  uint8 v2 = spr_yspeed[k];
  bool v3 = (int8)(kHandleNormalSpriteGravity_YAcceleration[v1] + v2) < 0;
  uint8 v4 = kHandleNormalSpriteGravity_YAcceleration[v1] + v2;
  spr_yspeed[k] = v4;
  if (!v3 && v4 >= kHandleNormalSpriteGravity_MaxYSpeed[v1])
    spr_yspeed[k] = kHandleNormalSpriteGravity_MaxYSpeed[v1];
  uint8 old_xspeed = spr_xspeed[k];
  if (spr_table164a[k]) {
    uint8 v7 = (int8)old_xspeed >> 1;
    spr_xspeed[k] = ((int8)v7 >> 1) + v7;
  }
  UpdateNormalSpritePosition_X(k);
  spr_xspeed[k] = old_xspeed;
  if (spr_no_level_collision_flag[k])
    spr_table1588[k] = 0;
  else
    HandleNormalSpriteLevelCollision(k);
}

void ChangeNormalSpriteDirection_CheckIfTouchingWall(uint8 k) {  // 019089
  if ((spr_table1588[k] & (uint8)(spr_table157c[k] + 1) & 3) != 0)
    ChangeNormalSpriteDirection(k);
}

void ChangeNormalSpriteDirection(uint8 k) {  // 019098
  if (!spr_decrementing_table15ac[k]) {
    spr_decrementing_table15ac[k] = 8;
    ChangeNormalSpriteDirection_FlipXSpeedAndDirection(k);
  }
}

void ChangeNormalSpriteDirection_FlipXSpeedAndDirection(uint8 k) {  // 0190a2
  spr_xspeed[k] = -spr_xspeed[k];
  spr_table157c[k] ^= 1;
}

void HandleNormalSpriteLevelCollision(uint8 k) {  // 019140
  sprites_distance_to_snap_down_to_nearest_tile = 0;
  spr_table1588[k] = 0;
  spr_slope_surface_its_on[k] = 0;
  misc_scratch7e185e = 0;
  sprites_second_tracked_sprite_index = spr_table164a[k];
  spr_table164a[k] = 0;
  HandleNormalSpriteLevelColl_019211(k);
  if ((misc_level_layout_flags & 0x80) != 0) {
    ++misc_scratch7e185e;
    AddSprXYPos(k, misc_second_level_layer_xpos, misc_second_level_layer_ypos);
    HandleNormalSpriteLevelColl_019211(k);
    AddSprXYPos(k, -misc_second_level_layer_xpos, -misc_second_level_layer_ypos);
    int8 v6 = spr_table1588[k];
    if (v6 < 0 && (v6 & 3) == 0)
      AddSprXPos(k, -(int8)misc_layer2_xdisp);
  }
  if ((spr_property_bits190f[k] & 0x80) != 0 && (spr_table1588[k] & 3) != 0) {
    uint8 v8 = spr_table1588[k] & 3;
    if (!spr_table15d0[k]) {
      AddSprXPos(k, PAIR16(kHandleNormalSpriteLevelColl_DATA_019286[v8 - 1], kHandleNormalSpriteLevelColl_DATA_019284[v8 - 1]));
      if (!spr_xspeed[k])
        spr_table1588[k] &= 0xFC;
    }
  }
  // note: carry issue
  uint8 t = sprites_second_tracked_sprite_index ^ spr_table164a[k];
  if (t && !(spr_decrementing_table1fe2[k] | spr_property_bits166e[k] & 0x40)) {
    if ((t & 0x80) || (misc_nmito_use_flag & 0x80) != 0)
      SpawnLavaSplash(k);
    else
      SpawnWaterSplash(k);
  }
}

void HandleNormalSpriteLevelColl_019211(uint8 k) {  // 019211
  uint8 v3;

  if (sprites_sprite_buoyancy_settings) {
    uint8 v1 = flag_underwater_level;
    if (flag_underwater_level) {
LABEL_13:
      spr_table164a[k] = v1;
      goto LABEL_14;
    }
    if (HandleNormalSpriteLevelColl_01944D(k, 0x3C)) {
      if (blocks_currently_processed_map16_tile_lo < 0x6E)
        goto LABEL_14;
      int8 v2 = CheckWaterSlope(blocks_currently_processed_map16_tile_lo) & 1;
      v3 = blocks_currently_processed_map16_tile_lo;
      if (!v2)
        goto LABEL_14;
      if (v2)
        goto LABEL_8;
    }
    v3 = blocks_currently_processed_map16_tile_lo;
    if (blocks_currently_processed_map16_tile_lo < 6) {
LABEL_8:;
      uint8 v4 = v3;
      v1 = spr_table164a[k] | 1;
      if (v4 == 4) {
        int8 v6 = spr_table164a[k] | 1;
        if (spr_spriteid[k] == 53 || (spr_property_bits167a[k] & 2) == 0)
          HandleNormalSpriteLevelColl_019330(k);
        v1 = v6 | 0x80;
      }
      goto LABEL_13;
    }
  }
LABEL_14:
  if ((spr_property_bits1686[k] & 0x80) == 0 &&
      (!misc_scratch7e185e || (sprites_sprite_buoyancy_settings & 0x40) == 0 && (spr_property_bits166e[k] & 0x80) == 0)) {
    HandleNormalSpriteLevelColl_0192C9(k);
    if ((spr_property_bits190f[k] & 0x80) == 0 || spr_decrementing_table15ac[k] | spr_xspeed[k]) {
      uint8 v5 = spr_xspeed[k];
      if (v5)
        HandleNormalSpriteLevelColl_01928E(k, 4 * v5 + __CFSHL__(v5, 1));
    } else {
      HandleNormalSpriteLevelColl_01928E(k, counter_global_frames);
    }
  }
}

void HandleNormalSpriteLevelColl_01928E(uint8 k, uint8 a) {  // 01928e
  a &= 1;

  sprites_map16_tile_touched_horiz_hi = HandleNormalSpriteLevelColl_019441(k, a);
  if (sprites_map16_tile_touched_horiz_hi) {
    if (blocks_currently_processed_map16_tile_lo >= 0x11 && blocks_currently_processed_map16_tile_lo < 0x6E) {
      HandleNormalSpriteLevelColl_019425(k);
      blocks_copy_of_currently_processed_map16_tile_lo2 = blocks_currently_processed_map16_tile_lo;
      if (misc_scratch7e185e)
        spr_table1588[k] |= 0x40;
    }
  }
  sprites_map16_tile_touched_horiz_lo = blocks_currently_processed_map16_tile_lo;
}

void HandleNormalSpriteLevelColl_0192C9(uint8 k) {  // 0192c9
  uint8 v1 = ((spr_yspeed[k] & 0x80) != 0) ? 3 : 2;
  sprites_map16_tile_being_touched_vertically_hi = HandleNormalSpriteLevelColl_019441(k, v1);
  sprites_map16_tile_touched_vert_lo = blocks_currently_processed_map16_tile_lo;
  if (sprites_map16_tile_being_touched_vertically_hi) {
    uint8 v2 = blocks_currently_processed_map16_tile_lo;
    if (v1 == 2) {
      if (blocks_currently_processed_map16_tile_lo >= 0x59 && blocks_currently_processed_map16_tile_lo < 0x5C &&
          (misc_level_tileset_setting == 14 || misc_level_tileset_setting == 3) &&
          (spr_spriteid[k] == 53 || (v2 = spr_property_bits167a[k] & 2) == 0)) {
        HandleNormalSpriteLevelColl_019330(k);
      } else {
        HandleNormalSpriteLevelColl_01933B(k, v2);
      }
    } else if (blocks_currently_processed_map16_tile_lo >= 0x11 &&
               (blocks_currently_processed_map16_tile_lo < 0x6E ||
                blocks_currently_processed_map16_tile_lo >= blocks_lowest_number_solid_map16_tile_for_sprites &&
                    blocks_currently_processed_map16_tile_lo < blocks_highest_number_solid_map16_tile_for_sprites)) {
      HandleNormalSpriteLevelColl_019425(k);
      blocks_copy_of_currently_processed_map16_tile_lo1 = blocks_currently_processed_map16_tile_lo;
      if (misc_scratch7e185e)
        spr_table1588[k] |= 0x20;
    }
  }
}

void HandleNormalSpriteLevelColl_019330(uint8 k) {  // 019330
  spr_current_status[k] = 5;
  spr_decrementing_table1558[k] = 64;
}

void HandleNormalSpriteLevelColl_01933B(uint8 k, uint8 a) {  // 01933b
  if (a < 0x11) {
    if ((R12_ & 0xF) >= 5)
      return;
  } else if (a >= 0x6E) {
    if (a >= 0xD8)
      goto LABEL_18;
    uint8 v2 = CheckWhatSlopeSpriteIsOn(a);
    uint8 *v3 = IndirPtr(&R5_, v2);
    if (*v3 == 16)
      return;
    if (*v3 >= 0x10) {
LABEL_18:
      if ((R12_ & 0xF) < 5) {
        uint8 v6 = spr_current_status[k];
        if (v6 != 2 && v6 != 5 && v6 != 11) {
          AddSprYPos(k, -1);
          HandleNormalSpriteLevelColl_0192C9(k);
        }
      }
      return;
    }
    uint8 v4 = R0_;
    if (R0_ < 0xC && v4 < *IndirPtr(&R5_, v2))
      return;
    sprites_distance_to_snap_down_to_nearest_tile = *IndirPtr(&R5_, v2);
    uint8 v5 = kSlopeDataTables_SlopeType[R8_];
    spr_slope_surface_its_on[k] = v5;
    if (v5 == 4 || v5 == 0xFC) {
      if (((spr_xspeed[k] ^ v5) & 0x80) != 0 && spr_xspeed[k])
        ChangeNormalSpriteDirection(k);
      HandleNormalSpriteLevelColl_03C1CA(k);
    }
  }
  if ((spr_property_bits1686[k] & 4) != 0) {
LABEL_35:
    HandleNormalSpriteLevelColl_019435(k);
    if (misc_scratch7e185e)
      spr_table1588[k] |= 0x80;
    return;
  }
  uint8 v8 = spr_current_status[k];
  if (v8 != 2 && v8 != 5 && v8 != 11) {
    uint8 v9 = blocks_currently_processed_map16_tile_lo;
    if ((v9 == 12 || v9 == 13) &&
        (counter_global_frames & 3) == 0 && !CheckNormalSpriteLevelColl_Wall(k) &&
        (misc_level_tileset_setting == 2 || misc_level_tileset_setting == 8)) {
      AddSprXPos(k, PAIR16(kHandleNormalSpriteLevelColl_DATA_0192C7[v9 - 12], kHandleNormalSpriteLevelColl_DATA_0192C5[v9 - 12]));
    }
    if (!spr_table15d0[k])
      spr_ypos_lo[k] = sprites_distance_to_snap_down_to_nearest_tile + (spr_ypos_lo[k] & 0xF0);
    goto LABEL_35;
  }
}

void HandleNormalSpriteLevelColl_019425(uint8 k) {  // 019425
  blocks_xpos = __PAIR16__(R11_, R10_);
  blocks_ypos = __PAIR16__(R13_, R12_);
  HandleNormalSpriteLevelColl_019435(k);
}

void HandleNormalSpriteLevelColl_019435(uint8 k) {  // 019435
  spr_table1588[k] |= kHandleNormalSpriteLevelColl_DATA_019134[R15_];
}

uint8 HandleNormalSpriteLevelColl_019441(uint8 k, uint8 j) {  // 019441
  R15_ = j;
  return HandleNormalSpriteLevelColl_01944D(k, j + 4 * (spr_property_bits1656[k] & 0xF));
}

uint8 HandleNormalSpriteLevelColl_01944D(uint8 k, uint8 j) {  // 01944d
  if ((misc_level_layout_flags & (uint8)(misc_scratch7e185e + 1)) != 0) {
    uint16 ypos = GetSprYPos(k) + kHandleNormalSpriteLevelColl_SpriteObjClippingY[j];
    R12_ = ypos;
    R0_ = ypos & 0xF0;
    if ((ypos >> 8) < misc_screens_in_lvl) {
      R13_ = (ypos >> 8);
      R10_W = GetSprXPos(k) + kHandleNormalSpriteLevelColl_SpriteObjClippingX[j];
      if (R11_ < 2) {
        R0_ |= R10_ >> 4;
        uint8 v4 = kLevelDataLayoutTables_EightBitLo_Vertical[R13_];
        uint8 v5 = kLevelDataLayoutTables_EightBitHi_Vertical[R13_];
        if (misc_scratch7e185e) {
          v4 = kLevelDataLayoutTables_EightBitLo_Vertical_L2[R13_];
          v5 = kLevelDataLayoutTables_EightBitHi_Vertical_L2[R13_];
        }
        R5_W = PAIR16(R11_, R0_) + PAIR16(v5, v4);
        return HandleNormalSpriteLevelColl_019523(R13_);
      }
    }
LABEL_9:
    blocks_currently_processed_map16_tile_lo = 0;
    sprites_distance_to_snap_down_to_nearest_tile = 0;
    return 0;
  }
  R12_W = GetSprYPos(k) + kHandleNormalSpriteLevelColl_SpriteObjClippingY[j];
  if (R12_W >= 0x1B0)
    goto LABEL_9;
  R10_W = GetSprXPos(k) + kHandleNormalSpriteLevelColl_SpriteObjClippingX[j];
  if ((int8)R11_ < 0 || (uint8)R11_ >= misc_screens_in_lvl)
    goto LABEL_9;
  R0_ = (R12_ & 0xF0) | (R10_ >> 4);
  uint16 v10 = PAIR16(kLevelDataLayoutTables_EightBitHi[R11_], kLevelDataLayoutTables_EightBitLo[R11_]);
  if (misc_scratch7e185e) {
    v10 = PAIR16(kLevelDataLayoutTables_EightBitHi_Horizontal_L2[R11_], kLevelDataLayoutTables_EightBitLo_Horizontal_L2[R11_]);
  }
  R5_W = PAIR16(R13_, R0_) + v10;
  return HandleNormalSpriteLevelColl_019523(R11_);
}

uint8 HandleNormalSpriteLevelColl_019523(uint8 k) {  // 019523
  R7_ = 126;
  blocks_currently_processed_map16_tile_lo = *IndirPtr(&R5_, 0);
  ++R7_;
  uint8 *v1 = IndirPtr(&R5_, 0);
  return ModifyMap16IDForSpecialBlocks(*v1);
}

void SprStatus09_Stunned(uint8 k) {  // 01953c
  if (spr_spriteid[k] == 44) {
    if (spr_table00c2[k])
      SprStatus09_Stunned_BulletBillEntry(k);
    else
      SprStatus09_Stunned_01956A(k);
  } else {
    SprStatus09_Stunned_019554(k, spr_spriteid[k]);
  }
}

void SprStatus09_Stunned_BulletBillEntry(uint8 k) {  // 019546
  uint8 v1 = sprites_tile_priority;
  sprites_tile_priority = 16;
  GenericGFXRtDraw1Tile16x16(k);
  sprites_tile_priority = v1;
}

void SprStatus09_Stunned_019554(uint8 k, uint8 a) {  // 019554
  if (a == 47 || a == 0x85) {
    SprStatus09_Stunned_SetNormalStatus2(k);
  } else if (a == 125) {
    spr_yspeed[k] = 0;
    SprStatus09_Stunned_SetNormalStatus2(k);
  } else {
    SprStatus09_Stunned_01956A(k);
  }
}

void SprStatus09_Stunned_SetNormalStatus2(uint8 k) {  // 019562
  spr_current_status[k] = 8;
  ProcessStunnedNormalSprite(k);
}

void SprStatus09_Stunned_01956A(uint8 k) {  // 01956a
  if (!flag_sprites_locked) {
    SprStatus09_Stunned_019624(k);
    HandleNormalSpriteGravity(k);
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      MakeStunnedSpriteBounceOrSlowDownOnGround(k);
      uint8 v1 = spr_spriteid[k];
      if (v1 == 22 || v1 == 21) {
        SprStatus09_Stunned_SetNormalStatus2(k);
        return;
      }
      if (v1 == 44) {
        spr_yspeed[k] = -16;
        PrepareToHatchNormalSpriteYoshiEgg_Entry2(k);
      }
    }
    if (CheckNormalSpriteLevelColl_Ceiling(k)) {
      spr_yspeed[k] = 16;
      if (!CheckNormalSpriteLevelColl_Wall(k)) {
        blocks_xpos = GetSprXPos(k) + 8;
        blocks_ypos = GetSprYPos(k) & ~0xf;
        LOBYTE(misc_current_layer_being_processed) = spr_table1588[k] >> 5 & 1;
        CheckIfBlockWasHit(blocks_copy_of_currently_processed_map16_tile_lo1, 0);
        spr_decrementing_table1fe2[k] = 8;
      }
    }
    if (CheckNormalSpriteLevelColl_Wall(k)) {
      if (spr_spriteid[k] >= 0xD)
        MakeNormalSpriteReboundOffWall(k);
      spr_xspeed[k] = (int8)spr_xspeed[k] >> 2;
    }
    CheckPlayerAndNormalSpriteCollisions(k);
  }
  ProcessStunnedNormalSprite(k);
  SubOffscreen_Bank01_Entry1(k);
}

void SprStatus09_Stunned_019624(uint8 k) {  // 019624
  if (spr_spriteid[k] == 13) {
    uint8 v1 = spr_decrementing_table1540[k];
    if (v1 == 1) {
      io_sound_ch3 = 9;
      spr_table1534[k] = 1;
      spr_decrementing_table1540[k] = 64;
      spr_current_status[k] = 8;
      spr_property_bits1686[k] &= ~8;
    } else if (v1 < 0x40) {
      spr_table15f6[k] ^= (2 * v1) & 0xE;
    }
  } else {
    spr_table00c2[k] = spr_decrementing_table1558[k] | spr_decrementing_table1540[k];
    if (spr_decrementing_table1558[k] != 1 || spr_table15d0[spr_table1594[k]]) {
      uint8 v3 = spr_decrementing_table1540[k];
      if (!v3)
        return;
      if (v3 == 3 || v3 == 1) {
        uint8 v4 = spr_spriteid[k];
        switch (v4) {
        case 0x11:
        case 0x2E: goto LABEL_25;
        case 0x2D: return;
        case 0xA2:
        case 0xF:
LABEL_25:
          spr_current_status[k] = 8;
          spr_table15f6[k] &= ~0x80;
          return;
        }
        if (v4 != 44) {
          if (v4 == 83) {
            SprStatus02_Dead_SetNorSprStatus04(k);
          } else {
            uint8 j = FindFreeNormalSpriteSlot_HighPriority();
            if ((j & 0x80) == 0) {
              spr_current_status[j] = 8;
              spr_spriteid[j] = kSprStatus09_Stunned_SpriteKoopasSpawn[spr_spriteid[k]];
              InitializeNormalSpriteRAMTables(j);
              SetSprXPos(j, GetSprXPos(k));
              SetSprYPos(j, GetSprYPos(k));
              spr_table157c[j] = 0;
              spr_decrementing_table1564[j] = 16;
              spr_table164a[j] = spr_table164a[k];
              uint8 v7 = spr_decrementing_table1540[k];
              spr_decrementing_table1540[k] = 0;
              if (v7 == 1) {
                uint8 v9 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
                uint8 v10 = kSprStatus09_Stunned_DATA_0197AD[v9];
                R0_ = v9;
                spr_xspeed[j] = v10;
                uint8 v11 = R0_ ^ 1;
                spr_table157c[j] = R0_ ^ 1;
                R1_ = v11;
                spr_decrementing_table154c[j] = 16;
                spr_table1528[j] = 16;
                if (spr_spriteid[k] == 7) {
                  uint8 v12 = 8;
                  while (spr_current_status[v12]) {
                    if ((--v12 & 0x80) != 0)
                      return;
                  }
                  spr_current_status[v12] = 8;
                  spr_spriteid[v12] = 33;
                  SetSprXPos(v12, GetSprXPos(k));
                  SetSprYPos(v12, GetSprYPos(k));
                  InitializeNormalSpriteRAMTables(v12);
                  spr_yspeed[v12] = -48;
                  spr_table157c[v12] = R1_;
                  spr_decrementing_table154c[v12] = 32;
                }
              } else {
                spr_yspeed[j] = -48;
                uint8 v8 = CheckPlayerPositionRelativeToSprite_Bank01_X(k) ^ 1;
                spr_table157c[j] = v8;
                spr_xspeed[j] = kSprXXX_Generic_Spr0to13SpeedX[v8];
              }
            }
          }
        }
      } else if ((counter_global_frames & 1) == 0) {
        ++spr_decrementing_table1540[k];
      }
    } else {
      InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
      SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
      spr_table15f6[k] &= ~0x80;
      uint8 v2 = 8;
      if (spr_table160e[k] == 3) {
        ++spr_table187b[k];
        spr_property_bits166e[k] |= 0x30;
        v2 = 10;
      }
      spr_current_status[k] = v2;
    }
  }
}

void MakeStunnedSpriteBounceOrSlowDownOnGround(uint8 k) {  // 0197d5
  int8 v1 = spr_xspeed[k];
  if (v1 < 0)
    v1 = -v1;
  uint8 v2 = (uint8)v1 >> 1;
  if (spr_xspeed[k] & 0x80)
    v2 = -v2;
  spr_xspeed[k] = v2;
  uint8 v4 = spr_yspeed[k];
  SetNormalSpriteYSpeedBasedOnSlope(k);
  uint8 v3 = (v4 >> 2) + ((spr_spriteid[k] == 15) ? 19 : 0);
  if ((spr_table1588[k] & 0x80) == 0)
    spr_yspeed[k] = kMakeStunnedSpriteBounceOrSlowDownOnGround_DATA_0197AF[v3];
}

void StunnedShellDraw(uint8 k) {  // 019806
  if (spr_oamindex[k])
    StunnedShellGFXRt_01980F(k, 6);
  else
    StunnedShellGFXRt_01980F(k, 8);
}

void StunnedShellGFXRt_01980F(uint8 k, uint8 a) {  // 01980f
  spr_table1602[k] = a;
  uint8 v2 = spr_oamindex[k];
  uint8 v16 = v2;
  if (v2)
    v2 += 8;
  spr_oamindex[k] = v2;
  GenericGFXRtDraw1Tile16x16(k);
  spr_oamindex[k] = v16;
  if ((ow_level_tile_settings[73] & 0x80) == 0 && spr_table1602[k] == 6) {
    uint8 v3 = spr_oamindex[k];
    uint8 v4 = spr_decrementing_table1558[k];
    if (v4)
      goto LABEL_8;
    v4 = spr_decrementing_table1540[k];
    if (!v4)
      return;
    if (v4 < 0x30) {
LABEL_8:;
      OamEnt *oam = get_OamEnt(oam_buf, v3);
      int xpos = oam[66].xpos + (v4 & 1);
      if (xpos < 256)
        oam[66].xpos = xpos;
    }
    if (spr_spriteid[k] != 17 && !CheckIfNormalSpriteOffScreen(k)) {
      R0_ = __CFSHL__(spr_table15f6[k], 1) ? 0 : 8;
      OamEnt *v9 = get_OamEnt(oam_buf, v3);
      uint8 v10 = v9[66].xpos + 2;
      v9[64].xpos = v10;
      v9[65].xpos = v10 + 4;
      uint8 v11 = R0_ + v9[66].ypos;
      v9[64].ypos = v11;
      v9[65].ypos = v11;
      uint8 v17 = v3;
      uint8 v12 = ((counter_local_frames & 0xF8) == 0) ? 77 : 100;
      OamEnt *v13 = get_OamEnt(oam_buf, v17);
      v13[64].charnum = v12;
      v13[65].charnum = v12;
      uint8 v14 = sprites_tile_priority;
      v13[64].flags = sprites_tile_priority;
      v13[65].flags = v14;
      uint8 v15 = v17 >> 2;
      sprites_oamtile_size_buffer[v15 + 64] = 0;
      sprites_oamtile_size_buffer[v15 + 65] = 0;
    }
  }
}

void SprStatus0A_Kicked_0198A9(uint8 k) {  // 0198a9
  if (flag_sprites_locked) {
    KickedShellDraw(k);
  } else {
    HandleNormalSpriteGravity(k);
    if ((spr_table151c[k] & 0x1F) == 0)
      SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
    uint8 v1 = spr_xspeed[k];
    if (spr_table157c[k]) {
      if (!sign8(v1 + 32))
        spr_xspeed[k] -= 2;
    } else if (sign8(v1 - 32)) {
      spr_xspeed[k] += 2;
    }
    uint8 v2 = CheckNormalSpriteLevelColl_Wall(k);
    if (v2) {
      uint8 v3 = v2;
      MakeNormalSpriteReboundOffWall(k);
      spr_xspeed[k] = kSprStatus0A_Kicked_XSpeed[(v3 & 3) - 1];
    }
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      SetNormalSpriteYSpeedBasedOnSlope(k);
      spr_yspeed[k] = 16;
    }
    if (CheckNormalSpriteLevelColl_Ceiling(k))
      spr_yspeed[k] = 0;
    if ((counter_global_frames & 1) == 0)
      spr_table15f6[k] = (spr_table15f6[k] + 2) & 0xCF;
    SprStatus0A_Kicked_01998C(k);
  }
}

void SprStatus0A_Kicked(uint8 k) {  // 019913
  if (spr_table187b[k]) {
    SprStatus0A_Kicked_0198A9(k);
    return;
  }
  if ((spr_property_bits167a[k] & 0x10) != 0) {
    CheckPlayerToNormalSpriteColl_01AA0B(k);
    ProcessStunnedNormalSprite(k);
    return;
  }
  if (!spr_table1528[k] && (uint8)(spr_xspeed[k] + 32) < 0x40)
    CheckPlayerToNormalSpriteColl_01AA0B(k);
  spr_table1528[k] = 0;
  if (spr_decrementing_table163e[k] | flag_sprites_locked) {
    SprStatus0A_Kicked_01998F(k);
    return;
  }
  SetFacingDirectionBasedOnSpeed(k);
  uint8 v1 = spr_slope_surface_its_on[k];
  HandleNormalSpriteGravity(k);
  if (v1) {
    R0_ = v1;
    if (!spr_table164a[k] && v1 != spr_slope_surface_its_on[k] && ((spr_xspeed[k] ^ v1) & 0x80) == 0) {
      spr_yspeed[k] = -8;
LABEL_17:
      if (sprites_map16_tile_touched_horiz_lo == 0xB5 || sprites_map16_tile_touched_horiz_lo == 0xB4) {
        spr_yspeed[k] = -72;
      }
      goto LABEL_20;
    }
  }
  if (CheckNormalSpriteLevelColl_Floor(k)) {
    SetNormalSpriteYSpeedBasedOnSlope(k);
    spr_yspeed[k] = 16;
    goto LABEL_17;
  }
LABEL_20:
  if (CheckNormalSpriteLevelColl_Wall(k))
    MakeNormalSpriteReboundOffWall(k);
  SprStatus0A_Kicked_01998C(k);
}

void SprStatus0A_Kicked_01998C(uint8 k) {  // 01998c
  CheckPlayerAndNormalSpriteCollisions(k);
  SprStatus0A_Kicked_01998F(k);
}

void SprStatus0A_Kicked_01998F(uint8 k) {  // 01998f
  SubOffscreen_Bank01_Entry1(k);
  if (spr_spriteid[k] == 83)
    ProcessStunnedNormalSprite_StunnedThrowBlock(k);
  else
    KickedShellDraw(k);
}

void MakeNormalSpriteReboundOffWall(uint8 k) {  // 01999e
  io_sound_ch1 = 1;
  ChangeNormalSpriteDirection_FlipXSpeedAndDirection(k);
  if (!spr_xoffscreen_flag[k] && (uint8)(spr_xpos_lo[k] - mirror_current_layer1_xpos + 20) >= 0x1C) {
    LOBYTE(misc_current_layer_being_processed) = (spr_table1588[k] >> 6) & 1;
    CheckIfBlockWasHit(blocks_copy_of_currently_processed_map16_tile_lo2, 0);
    spr_decrementing_table1fe2[k] = 5;
  }
  if (spr_spriteid[k] == 83)
    BreakThrowBlock(k);
}

void BreakThrowBlock(uint8 k) {  // 0199dc
  spr_current_status[k] = 0;
  BreakThrowBlock_MontyMoleEntry(k, 0xFF);
}

void BreakThrowBlock_MontyMoleEntry(uint8 k, uint8 j) {  // 0199e1
  if (!CheckIfNormalSpriteOffScreen(k)) {
    blocks_xpos = GetSprXPos(k);
    blocks_ypos = GetSprYPos(k);
    SpawnBrickPieces(j);
  }
}

void SetNormalSpriteYSpeedBasedOnSlope(uint8 k) {  // 019a04
  uint8 v1;
  if ((spr_table1588[k] & 0x80) != 0 || (v1 = 0, spr_slope_surface_its_on[k]))
    v1 = 24;
  spr_yspeed[k] = v1;
}

void SetFacingDirectionBasedOnSpeed(uint8 k) {  // 019a15
  if (spr_xspeed[k])
    spr_table157c[k] = (int8)spr_xspeed[k] < 0;
}

void KickedShellDraw(uint8 k) {  // 019a2a
  spr_decrementing_table1558[k] = spr_table00c2[k];
  uint8 v2 = (counter_local_frames >> 2) & 3;
  StunnedShellGFXRt_01980F(k, kKickedShellGFXRt_ShellAniTiles[v2]);
  spr_decrementing_table1558[k] = 0;
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[66].flags ^= kKickedShellGFXRt_Prop[v2];
}

void SprStatus04_SpinJumpKill(uint8 k) {  // 019a52
  if (spr_decrementing_table1540[k]) {
    GenericGFXRtDraw1Tile16x16(k);
    uint8 v1 = kSprStatus04_SpinJumpKill_SmokeTiles[(spr_decrementing_table1540[k] >> 3) & 3];
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    oam[64].charnum = v1;
    oam[64].flags = v1;
    oam[64].flags = v1 & 0x30;
  } else {
    SubOffscreen_Bank01_EraseSprite(k);
  }
}

void SprStatus02_Dead_Status05Entry(uint8 k) {  // 019a7b
  if (spr_decrementing_table1558[k]) {
    spr_yspeed[k] = 4;
    spr_property_bits190f[k] *= 2;
    spr_property_bits190f[k] >>= 1;
    int8 v1 = spr_xspeed[k];
    if (v1) {
      if (v1 >= 0) {
        --spr_xspeed[k];
        if (CheckNormalSpriteLevelColl_Wall(k))
          spr_xspeed[k] = 0;
      } else {
        ++spr_xspeed[k];
      }
    }
    spr_table1632[k] = 1;
    SprStatus02_Dead(k);
  } else {
    SubOffscreen_Bank01_EraseSprite(k);
  }
}

void SprStatus02_Dead(uint8 k) {  // 019aa2
  uint8 v1 = spr_spriteid[k];
  if (v1 == 0x86) {
    SprStatus08(k);
  } else {
    if (v1 == 30)
      timer_despawn_lakitu_cloud = -1;
    if (v1 == 83) {
      BreakThrowBlock(k);
    } else {
      if (v1 == 76)
        ShatterExplodingBlock(k);
      if ((spr_property_bits1656[k] & 0x80) != 0)
        SprStatus02_Dead_SetNorSprStatus04(k);
      else
        SprStatus02_Dead_019AD6(k);
    }
  }
}

void SprStatus02_Dead_SetNorSprStatus04(uint8 k) {  // 019acb
  spr_current_status[k] = 4;
  spr_decrementing_table1540[k] = 31;
}

void SprStatus02_Dead_019AD6(uint8 k) {  // 019ad6
  if (!flag_sprites_locked)
    HandleNormalSpriteGravity(k);
  SubOffscreen_Bank01_Entry1(k);
  //  if (g_debug_flag)
  //    printf("What is Y?!\n");
  uint8 v1 = 0;
  SprStatus02_Dead_HandleGenericSpriteDeath(k, v1);
}

void SprStatus03_Smushed(uint8 k) {  // 019ae4
  if (!flag_sprites_locked) {
    if (!spr_decrementing_table1540[k]) {
      spr_current_status[k] = 0;
      return;
    }
    HandleNormalSpriteGravity(k);
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      SetNormalSpriteYSpeedBasedOnSlope(k);
      spr_xspeed[k] = 0;
    }
  }
  if (spr_spriteid[k] == 111) {
    GenericGFXRtDraw1Tile16x16(k);
    get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = -84;
  } else {
    GenericSmushedSpriteDraw(k);
  }
}

void SprStatus02_Dead_HandleGenericSpriteDeath(uint8 k, uint8 j) {  // 019b13
  if ((spr_property_bits167a[k] & 1) != 0) {
    SprStatus08(k);
    return;
  }
  spr_table1602[k] = 0;
  if ((spr_property_bits190f[k] & 0x20) != 0) {
    if ((spr_property_bits1662[k] & 0x40) == 0) {
      if (spr_spriteid[k] != 30) {
        if (spr_spriteid[k] != 75) {
          spr_table15f6[k] |= 0x80;
          goto LABEL_10;
        }
        spr_table1632[k] = 1;
      }
      spr_table1602[k] = 1;
LABEL_10:;
      uint8 v2 = sprites_tile_priority;
      uint8 v5 = sprites_tile_priority;
      if (spr_table1632[k])
        v2 = 16;
      sprites_tile_priority = v2;
      GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
      sprites_tile_priority = v5;
      return;
    }
    spr_table1602[k] = 6;
  }
  uint8 v3 = 0;
  if (j != 28)
    v3 = 0x80;
  R0_ = v3;
  uint8 v4 = sprites_tile_priority;
  uint8 v6 = sprites_tile_priority;
  if (spr_table1632[k])
    v4 = 16;
  sprites_tile_priority = v4;
  GenericGFXRtDraw1Tile16x16_Sub(k, R0_);
  sprites_tile_priority = v6;
}

void GenericGFXRtDraw4Tiles8x8Square(uint8 k, uint8 a) {  // 019cf3
  GenericGFXRtDraw4Tiles8x8Square_Entry1(k, a, 0);
}

void GenericGFXRtDraw4Tiles8x8Square_Entry1(uint8 k, uint8 a, uint8 j) {  // 019cf5
  R5_ = a;
  R15_ = j;
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
  R1_ += R15_;
  R2_ = kGenericSpriteOAMData_TilesOffset[spr_spriteid[k]] + __CFSHL__(2 * spr_table1602[k], 1) + 4 * spr_table1602[k];
  R3_ = sprites_tile_priority | spr_table15f6[k];
  uint8 v3 = spr_oamindex[k];
  R4_ = 3;
  do {
    uint8 v4 = R4_;
    OamEnt *oam = get_OamEnt(oam_buf, v3);
    oam[64].xpos = kGenericSpriteOAMData_XDisp[R4_] + R0_;
    oam[64].ypos = kGenericSpriteOAMData_YDisp[v4] + R1_;
    oam[64].charnum = *((uint8 *)kGenericSpriteOAMData_Tiles + (uint8)(R4_ + R2_));
    oam[64].flags = R3_ | kGenericSpriteOAMData_Prop[(uint8)(R4_ + __CFSHL__(2 * R5_, 1) + 4 * R5_)];
    v3 += 4;
    --R4_;
  } while ((R4_ & 0x80) == 0);
  FinishOAMWrite(k, 0, 3);
}

void GenericGFXRtDraw2Tiles16x16sStacked_Sub(uint8 k) {  // 019d67
  uint8 drt;

  if ((spr_table15f6[k] & 0x80) == 0) {
    if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
      return;
    R2_ = spr_table157c[k];
    uint8 v2 = drt;
    uint8 v3 = spr_spriteid[k];
    if (v3 < 0xF)
      v2 += (v3 >= 0xF) + 4;
    uint8 v4 = v2;
    uint8 v5 = kGenericSpriteOAMData_TilesOffset[spr_spriteid[k]] + 2 * spr_table1602[k];
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam[64].charnum = *((uint8 *)kGenericSpriteOAMData_Tiles + v5);
    oam[65].charnum = *((uint8 *)kGenericSpriteOAMData_Tiles + v5 + 1);
    uint8 v7 = spr_current_slotid;
    uint8 v8 = R1_;
    oam[64].ypos = R1_;
    oam[65].ypos = v8 + 16;
    GenericGFXRtDraw2Tiles16x16sStacked_019DA9(v7, v4);
  } else {
    GenericGFXRtDraw2Tiles16x16sStacked_UpsideDown(k);
  }
}

void GenericGFXRtDraw2Tiles16x16sStacked_019DA9(uint8 k, uint8 j) {  // 019da9
  uint8 v2 = R0_;
  OamEnt *oam = get_OamEnt(oam_buf, j);
  oam[64].xpos = R0_;
  oam[65].xpos = v2;
  uint8 v4 = sprites_tile_priority | spr_table15f6[k];
  if (!(spr_table157c[k] & 1))
    v4 |= 0x40;
  oam[64].flags = v4;
  oam[65].flags = v4;
  uint8 v5 = j >> 2;
  uint8 v6 = spr_xoffscreen_flag[k] | 2;
  sprites_oamtile_size_buffer[v5 + 64] = v6;
  sprites_oamtile_size_buffer[v5 + 65] = v6;
  GenericGFXRtMoveTileOffscreenVertically(k, v5);
}

void GenericGFXRtDraw2Tiles16x16sStacked_UpsideDown(uint8 k) {  // 019dd9
  uint8 drt;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  R2_ = spr_table157c[k];
  uint8 v2 = kGenericSpriteOAMData_TilesOffset[spr_spriteid[k]] + 2 * spr_table1602[k];
  OamEnt *oam = get_OamEnt(oam_buf, (uint8)(drt + 8));
  oam[65].charnum = *((uint8 *)kGenericSpriteOAMData_Tiles + v2);
  oam[64].charnum = *((uint8 *)kGenericSpriteOAMData_Tiles + v2 + 1);
  uint8 v4 = spr_current_slotid;
  uint8 v5 = R1_;
  oam[64].ypos = R1_;
  oam[65].ypos = v5 + 16;
  GenericGFXRtDraw2Tiles16x16sStacked_019DA9(v4, drt + 8);
}

void DrawWingTiles_ParaKoopaEntry(uint8 k) {  // 019e28
  if (CheckNormalSpriteLevelColl_Floor(k))
    DrawWingTiles_019E35(k, 0);
  else
    DrawWingTiles_019E35(k, spr_table1602[k] & 1);
}

void DrawWingTiles_019E35(uint8 k, uint8 j) {  // 019e35
  R2_ = j;
  DrawWingTiles_019E37(k);
}

void DrawWingTiles_019E37(uint8 k) {  // 019e37
  if (!spr_yoffscreen_flag[k]) {
    SetHiLo(&R4_, &R0_, GetSprXPos(k));
    R1_ = spr_ypos_lo[k];
    uint8 v1 = spr_oamindex[k];
    uint8 v2 = R2_ + 2 * spr_table157c[k];
    uint16 t = PAIR16(R4_, R0_) + PAIR16(kDrawWingTiles_XDispHi[v2], kDrawWingTiles_XDispLo[v2]);
    R0_ = t;
    OamEnt *oam = get_OamEnt(oam_buf, v1);
    uint16 t2 = t - mirror_current_layer1_xpos;
    oam[64].xpos = t2;
    if (t2 < 256) {
      oam[64].ypos = kDrawWingTiles_YDisp[v2] + R1_ - mirror_current_layer1_ypos;
      oam[64].charnum = kDrawWingTiles_Tiles[v2];
      oam[64].flags = kDrawWingTiles_Prop[v2] | sprites_tile_priority;
      sprites_oamtile_size_buffer[(v1 >> 2) + 64] = kDrawWingTiles_TileSize[v2];
    }
  }
}

void DrawWingTiles(uint8 k) {  // 019e95
  uint16 old_x = GetSprXPos(k), old_y = GetSprYPos(k);
  AddSprXYPos(k, -2, 2);
  uint8 v3 = spr_oamindex[k];
  uint8 v2 = spr_table157c[k];
  spr_oamindex[k] = v3 + 4;
  spr_table157c[k] = 0;
  DrawWingTiles_019E35(k, (spr_table1570[k] & 8) != 0);
  AddSprXPos(k, 4);
  spr_oamindex[k] += 4;
  spr_table157c[k] = 1;
  DrawWingTiles_019E37(k);
  spr_table157c[k] = v2;
  spr_oamindex[k] = v3;
  SetSprXPos(k, old_x);
  SetSprYPos(k, old_y);
}

void GenericGFXRtDraw1Tile16x16_Sub(uint8 k, uint8 a) {  // 019f09
  R4_ = a;
  GenericGFXRtDraw1Tile16x16_019F0F(k);
}

void GenericGFXRtDraw1Tile16x16(uint8 k) {  // 019f0d
  R4_ = 0;
  GenericGFXRtDraw1Tile16x16_019F0F(k);
}

void GenericGFXRtDraw1Tile16x16_019F0F(uint8 k) {  // 019f0f
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
  R2_ = spr_table157c[k];
  uint8 v1 = spr_oamindex[k];
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[64].charnum =
      *((uint8 *)kGenericSpriteOAMData_Tiles + (uint8)(kGenericSpriteOAMData_TilesOffset[spr_spriteid[k]] + spr_table1602[k]));
  uint8 v3 = spr_current_slotid;
  oam[64].xpos = R0_;
  oam[64].ypos = R1_;
  uint8 a = spr_table15f6[v3];
  if (!(spr_table157c[k] & 1))
    a ^= 0x40;
  oam[64].flags = sprites_tile_priority | R4_ | a;
  v1 >>= 2;
  sprites_oamtile_size_buffer[v1 + 64] = spr_xoffscreen_flag[v3] | 2;
  GenericGFXRtMoveTileOffscreenVertically(v3, v1);
}

void SprStatus0B_Carried(uint8 k) {  // 019f71
  SprStatus0B_Carried_019F9B(k);
  if (player_turning_around_flag || yoshi_in_pipe || timer_display_player_face_screen_pose)
    spr_oamindex[k] = 0;
  uint8 v1 = sprites_tile_priority;
  if (yoshi_in_pipe)
    sprites_tile_priority = 16;
  ProcessStunnedNormalSprite(k);
  sprites_tile_priority = v1;
}

void SprStatus0B_Carried_019F9B(uint8 k) {  // 019f9b
  if (spr_spriteid[k] == 125) {
    if ((counter_global_frames & 3) == 0) {
      if (!--timer_player_has_pballoon) {
LABEL_9:
        timer_inflate_from_pballoon = 0;
        SubOffscreen_Bank01_EraseSprite(k);
        return;
      }
      if (timer_player_has_pballoon < 0x30) {
        uint8 v1 = 1;
        if ((timer_player_has_pballoon & 4) != 0)
          v1 = 9;
        timer_inflate_from_pballoon = v1;
      }
    }
    if (player_current_state)
      goto LABEL_9;
    HandleHeldPBalloonAndInLakituCloudMovement(k);
    SprStatus0B_Carried_01A0B1(k);
    get_OamEnt(oam_buf, spr_oamindex[k])[64].ypos = -16;
    return;
  }
  HandleNormalSpriteLevelCollision(k);
  if (player_current_state && !yoshi_in_pipe) {
    spr_current_status[k] = 9;
    return;
  }
  if (spr_current_status[k] != 8) {
    if (flag_sprites_locked) {
      SprStatus0B_Carried_01A0B1(k);
      return;
    }
    SprStatus09_Stunned_019624(k);
    CheckNormalSpriteToNormalSpriteCollision(k);
    if (yoshi_in_pipe || (io_controller_hold1 & 0x40) != 0) {
      SprStatus0B_Carried_01A0B1(k);
      return;
    }
    spr_table1626[k] = 0;
    uint8 v2 = 0;
    if (spr_spriteid[k] == 15 && !player_in_air_flag)
      v2 = -20;
    spr_yspeed[k] = v2;
    spr_current_status[k] = 9;
    if ((io_controller_hold1 & 8) != 0) {
      SpawnContactEffectFromSide(k);
      spr_yspeed[k] = -112;
      uint8 v5 = player_xspeed;
      spr_xspeed[k] = player_xspeed;
      int8 v6 = 0;
      if (__CFSHL__(v5, 1))
        v6 = 0x80;
      spr_xspeed[k] = (spr_xspeed[k] >> 1) + v6;
      goto LABEL_39;
    }
    if (spr_spriteid[k] >= 0x15) {
      if ((io_controller_hold1 & 3) == 0) {
LABEL_29:;
        SetSprXPos(k, player_current_xpos + PAIR16(kSprStatus0B_Carried_PlacedSpriteInitialXPosHi[player_facing_direction], kSprStatus0B_Carried_PlacedSpriteInitialXPosLo[player_facing_direction]));
        spr_xspeed[k] = player_xspeed + kSprStatus0B_Carried_PlacedSpriteInitiaXSpeed[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
        spr_yspeed[k] = 0;
LABEL_39:
        spr_decrementing_table154c[k] = 16;
        timer_display_player_kicking_pose = 12;
        return;
      }
    } else if ((io_controller_hold1 & 4) != 0) {
      goto LABEL_29;
    }
    SpawnContactEffectFromSide(k);
    spr_table00c2[k] = spr_decrementing_table1540[k];
    spr_current_status[k] = 10;
    uint8 v7 = player_facing_direction + (player_riding_yoshi_flag ? 2 : 0);
    spr_xspeed[k] = kSprStatus0B_Carried_ShellXSpeed[v7];
    if (((player_xspeed ^ spr_xspeed[k]) & 0x80) == 0) {
      R0_ = 2 * player_xspeed;
      uint8 v9 = __CFSHL__(player_xspeed, 1) ? 0x80 : 0;
      spr_xspeed[k] = kSprStatus0B_Carried_ShellXSpeed[v7] + (player_xspeed >> 1) + v9;
    }
    goto LABEL_39;
  }
}

void SprStatus0B_Carried_01A0B1(uint8 k) {  // 01a0b1
  int8 v1 = player_facing_direction == 0;
  if (timer_display_player_face_screen_pose) {
    v1 += 2;
    if (timer_display_player_face_screen_pose >= 5)
      ++v1;
  }
  if (yoshi_in_pipe == 2 || player_climbing_flag | player_turning_around_flag)
    v1 = 5;
  uint16 px = (misc_player_on_solid_sprite == 3) ? player_xpos : player_current_xpos;
  uint16 py = (misc_player_on_solid_sprite == 3) ? player_ypos : player_current_ypos;
  SetSprXPos(k, px + PAIR16(kSprStatus0B_Carried_CarriedSpriteXOffsetHi[v1], kSprStatus0B_Carried_CarriedSpriteXOffsetLo[v1]));
  uint8 v4 = 13;
  if (player_ducking_flag || !player_current_power_up || timer_display_player_pick_up_pose)
    v4 = 15;
  SetSprYPos(k, py + v4);
  player_carrying_something_flag2 = 1;
  player_carrying_something_flag1 = 1;
}

void ProcessStunnedNormalSprite_StunnedGoomba(uint8 k) {  // 01a12f
  int8 v1 = counter_local_frames >> 2;
  uint8 v2 = spr_decrementing_table1540[k];
  if (v2 >= 0x30)
    v1 = counter_local_frames >> 3;
  spr_table1602[k] = v1 & 1;
  if (v2 == 8 && CheckNormalSpriteLevelColl_Floor(k))
    spr_yspeed[k] = -40;
  GenericGFXRtDraw1Tile16x16_Sub(k, 0x80);
}

void ProcessStunnedNormalSprite_StunnedMechaKoopa(uint8 k) {  // 01a152
  int8 v1 = mirror_current_layer1_xpos;
  if (spr_decrementing_table1540[k] < 0x30)
    LOBYTE(mirror_current_layer1_xpos) = mirror_current_layer1_xpos ^ spr_decrementing_table1540[k] & 1;
  Spr0A2_MechaKoopa_Draw(k);
  LOBYTE(mirror_current_layer1_xpos) = v1;
  ProcessStunnedNormalSprite_StunnedMechaKoopa_01A169(k);
}

void ProcessStunnedNormalSprite_StunnedMechaKoopa_01A169(uint8 k) {  // 01a169
  if (spr_current_status[k] == 11)
    spr_table157c[k] = player_facing_direction ^ 1;
}

void ProcessStunnedNormalSprite_StunnedFish(uint8 k) {  // 01a178
  SetNormalSpriteAnimationFrame(k);
  spr_table15f6[k] |= 0x80;
  GenericGFXRtDraw1Tile16x16(k);
}

void ProcessStunnedNormalSprite(uint8 k) {  // 01a187
  if ((spr_property_bits167a[k] & 8) == 0) {
LABEL_20:
    StunnedShellDraw(k);
    return;
  }
  uint8 v1 = spr_spriteid[k];
  switch (v1) {
  case 0xA2: ProcessStunnedNormalSprite_StunnedMechaKoopa(k); return;
  case 0x15:
  case 0x16: ProcessStunnedNormalSprite_StunnedFish(k); return;
  case 0xF: ProcessStunnedNormalSprite_StunnedGoomba(k); return;
  case 0x53: ProcessStunnedNormalSprite_StunnedThrowBlock(k); return;
  case 0x2C: GenericGFXRtDraw1Tile16x16(k); return;
  case 0x80:
    ProcessStunnedNormalSprite_StunnedMechaKoopa_01A169(k);
    GenericGFXRtDraw1Tile16x16(k);
    int8 v2 = -20;
    goto LABEL_30;
  case 0x7D: return;
  case 0x3E:;
    uint8 v3 = spr_decrementing_table163e[k];
    if (v3) {
      if (v3 == 1) {
        SprStatus02_Dead_SetNorSprStatus04(k);
      } else {
        GenericSmushedSpriteDraw(k);
        OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
        oam[64].flags &= ~1;
      }
      return;
    }
    spr_table157c[k] = 1;
    GenericGFXRtDraw1Tile16x16(k);
    v2 = 66;
LABEL_30:
    get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = v2;
    return;
  case 0x2F: Spr02F_PortableSpringboard_01E6F0(k); return;
  case 0xD:
    GenericGFXRtDraw1Tile16x16(k);
    v2 = -54;
    goto LABEL_30;
  }
  if (v1 != 45) {
    if (v1 == 0x85) {
      GenericGFXRtDraw1Tile16x16(k);
      get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = 71;
      return;
    }
    goto LABEL_20;
  }
  if (flag_sprites_locked) {
LABEL_40:
    ProcessStunnedNormalSprite_StunnedBabyYoshi_01A34F(k);
    return;
  }
  SetHiLo(&R8_, &R0_, GetSprXPos(k) + 8);
  SetHiLo(&R9_, &R1_, GetSprYPos(k) + 8);
  CheckBerryTileCollisionWithYoshiTongue();
  CheckIfBabyYoshiCanEatNormalSprite2(k);
  uint8 v7 = spr_decrementing_table163e[k];
  if (!v7) {
    spr_table160e[k] = -1;
    if (spr_current_status[k] == 9 && CheckNormalSpriteLevelColl_Floor(k))
      spr_yspeed[k] = -16;
    spr_table1602[k] = (counter_local_frames & 0x18) == 0 ? 3 : 0;
    goto LABEL_40;
  }
  spr_oamindex[k] = 0;
  if (v7 == 32) {
    uint8 v9 = spr_table160e[k];
    spr_current_status[v9] = 0;
    io_sound_ch1 = 6;
    if (spr_table160e[v9])
      goto LABEL_49;
    uint8 v10 = spr_spriteid[v9];
    if (v10 == 0x81)
      v10 = kSprXXX_PowerUps_ChangingItemSprite[(counter_local_frames >> 4) & 3];
    if (v10 < 0x74 || v10 >= 0x78)
LABEL_49:
      ProcessStunnedNormalSprite_StunnedBabyYoshi_01A2F4(k);
    else
      ProcessStunnedNormalSprite_StunnedBabyYoshi_01A2B5(k);
  } else {
    ProcessStunnedNormalSprite_StunnedBabyYoshi_01A30A(k);
  }
}

void ProcessStunnedNormalSprite_StunnedThrowBlock(uint8 k) {  // 01a1d4
  if (spr_decrementing_table1540[k] >= 0x40 || !(spr_decrementing_table1540[k] & 1))
    spr_table15f6[k] = (spr_table15f6[k] + 2) & 0xF;
  GenericGFXRtDraw1Tile16x16(k);
}

void ProcessStunnedNormalSprite_StunnedBabyYoshi_01A2B5(uint8 k) {  // 01a2b5
  yoshi_swallow_timer = 0;
  yoshi_yoshi_has_wings = 0;
  spr_spriteid[k] = 53;
  spr_current_status[k] = 8;
  io_sound_ch3 = 31;
  AddSprYPos(k, -16);
  uint8 v2 = spr_table15f6[k];
  InitializeNormalSpriteRAMTables(k);
  spr_table15f6[k] = v2 & 0xFE;
  spr_table1602[k] = 12;
  --spr_table160e[k];
  growing_yoshi_timer = 64;
}

void ProcessStunnedNormalSprite_StunnedBabyYoshi_01A2F4(uint8 k) {  // 01a2f4
  if (++spr_table1570[k] == 5)
    ProcessStunnedNormalSprite_StunnedBabyYoshi_01A2B5(k);
  else
    ProcessStunnedNormalSprite_StunnedBabyYoshi_01A300(k);
}

void ProcessStunnedNormalSprite_StunnedBabyYoshi_01A300(uint8 k) {  // 01a300
  GiveCoins_OneCoin();
  GivePoints(k, 1);
  ProcessStunnedNormalSprite_StunnedBabyYoshi_01A30A(k);
}

void ProcessStunnedNormalSprite_StunnedBabyYoshi_01A30A(uint8 k) {  // 01a30a
  spr_table1602[k] = kProcessStunnedNormalSprite_StunnedBabyYoshi_DATA_01A35A[spr_decrementing_table163e[k] >> 3];
  if (spr_decrementing_table163e[k] >= 0x20) {
    uint8 v1 = (spr_decrementing_table163e[k] - 16) >> 2;
    if (spr_table157c[k])
      v1 = -v1;
    SetSprXYPos(spr_table160e[k], GetSprXPos(k) + (int8)v1, GetSprYPos(k) - 2);
    ProcessStunnedNormalSprite_StunnedBabyYoshi_01A34F(k);
  } else {
    ProcessStunnedNormalSprite_StunnedBabyYoshi_01A34F(k);
  }
}

void ProcessStunnedNormalSprite_StunnedBabyYoshi_01A34F(uint8 k) {  // 01a34f
  ProcessStunnedNormalSprite_StunnedMechaKoopa_01A169(k);
  GenericGFXRtDraw1Tile16x16(k);
  SetBabyYoshiDynamicGraphicsPointer(k);
}

uint8 GetDrawInfo_Bank01_ReturnsTwice(uint8 k) {  // 01a365
  spr_yoffscreen_flag[k] = 0;
  spr_xoffscreen_flag[k] = (uint16)(GetSprXPos(k) - mirror_current_layer1_xpos) >= 256;

  R0_ = spr_xpos_lo[k] - mirror_current_layer1_xpos;
  R1_ = spr_ypos_lo[k] - mirror_current_layer1_ypos;

  uint16 tx = GetSprXPos(k) + 0x40 - mirror_current_layer1_xpos;
  spr_table15c4[k] = (tx >= 0x180);
  if (tx >= 0x180) {
    return 0xff;
  } else {
    uint8 v2 = (spr_current_status[k] != 9 && (spr_property_bits190f[k] & 0x20) != 0) ? 1 : 0;
    do {
      uint16 ty = GetSprYPos(k) + kGetDrawInfo_DATA_01A361[v2] - mirror_current_layer1_ypos;
      if (ty >= 256)
        spr_yoffscreen_flag[k] |= kGetDrawInfo_DATA_01A363[v2];
    } while ((--v2 & 0x80) == 0);
    return spr_oamindex[k];
  }
}

void GenericGFXRtMoveTileOffscreenVertically(uint8 k, uint8 j) {  // 01a3df
  OamEnt *oam = get_OamEnt(oam_buf, (uint8)(4 * j));
  uint8 v2 = spr_yoffscreen_flag[k];
  if (v2 & 1) {
    sprites_oamtile_size_buffer[j + 64] = 1;
    oam[64].xpos = 0x80;
  }
  if (v2 & 2) {
    sprites_oamtile_size_buffer[j + 65] = 1;
    oam[65].xpos = 0x80;
  }
}

void CheckNormalSpriteToNormalSpriteCollision(uint8 j) {  // 01a40d
  if (j && ((counter_global_frames ^ j) & 1)) {
    uint8 k = j - 1;
    do {
      if (spr_current_status[k] >= 8 &&
          spr_table1632[j] == (spr_table1632[k] | spr_table15d0[k] | spr_decrementing_table1564[j] | spr_decrementing_table1564[k] |
                                (spr_property_bits1686[j] | spr_property_bits1686[k]) & 8)) {
        sprites_second_tracked_sprite_index = k;
        R0_W = GetSprXPos(k);
        R2_W = GetSprXPos(j);
        if ((uint16)(R0_W - R2_W + 16) < 0x20) {
          R0_W = GetSprYPos(k) + kCheckNormalSpriteToNormalSpriteColl_DATA_01A40B[(spr_property_bits1662[k] & 0xF) != 0];
          R2_W = GetSprYPos(j) + kCheckNormalSpriteToNormalSpriteColl_DATA_01A40B[(spr_property_bits1662[j] & 0xF) != 0];
          if ((uint16)(R0_W - R2_W + 12) < 0x18)
            CheckNormalSpriteToNormalSpriteColl_01A4BA(k, j);
        }
      }
    } while ((--k & 0x80) == 0);
  }
}

void CheckNormalSpriteToNormalSpriteColl_01A4BA(uint8 k, uint8 j) {  // 01a4ba
  uint8 v2 = spr_current_status[j];
  if (v2 == 8) {
    uint8 v3 = spr_current_status[k];
    if (v3 == 8)
      goto LABEL_41;
    if (v3 != 9) {
      if (v3 != 10) {
        if (v3 != 11)
          return;
        goto LABEL_39;
      }
      goto LABEL_50;
    }
    goto LABEL_35;
  }
  if (v2 != 9) {
    if (v2 != 10) {
      if (v2 != 11)
        return;
      uint8 v6 = spr_current_status[k];
      if (v6 != 8 && v6 != 9 && v6 != 10 && v6 != 11)
        return;
LABEL_39:
      sub_1A685(k, j);
      return;
    }
    goto LABEL_19;
  }
  if ((spr_table1588[j] & 4) != 0) {
    uint8 v4 = spr_current_status[k];
    if (v4 != 8) {
      if (v4 != 9) {
        if (v4 != 10) {
          if (v4 != 11)
            return;
          goto LABEL_39;
        }
        goto LABEL_50;
      }
LABEL_36:
      if (spr_current_status[k] == 9 && !CheckNormalSpriteLevelColl_Floor(k)) {
        if (spr_spriteid[k] == 15)
          goto LABEL_39;
LABEL_50:
        if ((uint8)(spr_spriteid[j] + 125) < 2) {
          ChangeNormalSpriteDirection(k);
          spr_yspeed[k] = 0;
          CheckNormalSpriteToNormalSpriteColl_01A5D3(j);
        } else {
          sub_1A5DA();
        }
        return;
      }
LABEL_41:
      R0_ = GetSprXPos(k) >= GetSprXPos(j);
      if ((spr_property_bits1686[j] & 0x10) == 0) {
        uint8 v7 = spr_current_slotid;
        uint8 ka = spr_table157c[v7];
        spr_table157c[v7] = R0_;
        if (ka != spr_table157c[v7] && !spr_decrementing_table15ac[v7])
          spr_decrementing_table15ac[v7] = 8;
      }
      if ((spr_property_bits1686[k] & 0x10) == 0) {
        uint8 kb = spr_table157c[k];
        spr_table157c[k] = R0_ ^ 1;
        if (kb != spr_table157c[k] && !spr_decrementing_table15ac[k])
          spr_decrementing_table15ac[k] = 8;
      }
      return;
    }
LABEL_35:
    CheckNormalSpriteToNormalSpriteColl_01A6D9(k, j);
    CheckNormalSpriteToNormalSpriteColl_01A6D9(j, k);
    if (spr_decrementing_table1558[j] | spr_decrementing_table1558[k])
      return;
    goto LABEL_36;
  }
  if (spr_spriteid[j] == 15)
    goto LABEL_39;
LABEL_19:;
  uint8 v5 = spr_current_status[k];
  switch (v5) {
  case 8: sub_1A625(k, j); return;
  case 9: sub_1A642(k, j); return;
  case 0xA:
  case 0xB: goto LABEL_39;
  }
}

void CheckNormalSpriteToNormalSpriteColl_01A5D3(uint8 j) {  // 01a5d3
  SolidSpriteBlock_Entry2(j);
}

void sub_1A5DA() {  // 01a5da
  if (CheckNormalSpriteToNormalSpriteColl_01A77C_ReturnsTwice(spr_current_slotid, sprites_second_tracked_sprite_index))
    return;
  uint8 v1 = spr_current_slotid;
  uint8 v0 = sprites_second_tracked_sprite_index;
  spr_current_status[v1] = 2;
  SpawnContactEffectFromSide_NoKickSound(v1);
  spr_xspeed[v1] = spr_xspeed[v0] & 0x80 ? -16 : 16;
  spr_yspeed[v1] = -48;
  uint8 j = v1;
  uint8 v3 = ++spr_table1626[v0];
  if (v3 < 8)
    io_sound_ch1 = kStompSoundTable_Bank01[v3 - 1];
  uint8 v4 = v3;
  if (v3 >= 8)
    v4 = 8;
  GivePoints_Entry2(j, v4);
}

void sub_1A625(uint8 k, uint8 j) {  // 01a625
  if ((uint8)(spr_spriteid[k] + 125) >= 2) {
    if (CheckNormalSpriteToNormalSpriteColl_01A77C_ReturnsTwice(k, j))
      return;
    k = sprites_second_tracked_sprite_index;
    j = spr_current_slotid;
    sub_1A64A(k, j);
  } else {
    ChangeNormalSpriteDirection(j);
    spr_yspeed[j] = 0;
    SolidSpriteBlock_Entry2(k);
  }
}

void sub_1A642(uint8 k, uint8 j) {  // 01a642
  if (CheckNormalSpriteLevelColl_Floor(k))
    sub_1A64A(k, j);
  else
    sub_1A685(k, j);
}

void sub_1A64A(uint8 k, uint8 j) {  // 01a64a
  uint8 v2 = ++spr_table1626[j];
  if (v2 < 8)
    io_sound_ch1 = kStompSoundTable_Bank01[v2 - 1];
  uint8 v3 = v2;
  if (v2 >= 8)
    v3 = 8;
  GivePoints(k, v3);
  spr_current_status[k] = 2;
  SpawnContactEffectFromSide_NoKickSound(k);
  uint8 v4 = 16;
  if (spr_xspeed[j] & 0x80)
    v4 = -16;
  spr_xspeed[k] = v4;
  spr_yspeed[k] = -48;
}

void sub_1A685(uint8 k, uint8 j) {  // 01a685
  if (spr_spriteid[k] == 0x83 || spr_spriteid[k] == 0x84) {
    SolidSpriteBlock_Entry2(k);
  } else {
    spr_current_status[k] = 2;
    spr_yspeed[k] = -48;
  }
  uint8 v2 = spr_spriteid[j];
  if (v2 != 0x80) {
    if (v2 == 0x83 || v2 == 0x84) {
      CheckNormalSpriteToNormalSpriteColl_01A5D3(j);
    } else {
      spr_current_status[j] = 2;
      spr_yspeed[j] = -48;
    }
  }
  SpawnContactEffectFromSide(k);
  GivePoints(k, 4);
  spr_xspeed[k] = (spr_xspeed[k] & 0x80) ? 16 : -16;
  spr_xspeed[j] = -spr_xspeed[k];
}

void CheckNormalSpriteToNormalSpriteColl_01A6D9(uint8 k, uint8 j) {  // 01a6d9
  R0_ = j;
  if (CheckNormalSpriteLevelColl_Floor(k) && (spr_table1588[j] & 4) != 0 && (spr_property_bits1656[k] & 0x40) != 0 &&
      !(spr_decrementing_table1558[k] | spr_decrementing_table1558[j])) {
    R2_ = 0;
    int8 v2 = spr_xpos_lo[k] - spr_xpos_lo[j];
    if (v2 >= 0)
      ++R2_;
    if ((uint8)(v2 + 8) >= 0x10 && spr_table157c[k] == R2_) {
      if (spr_spriteid[k] == 2) {
        spr_decrementing_table163e[k] = 32;
        spr_decrementing_table1558[k] = 32;
        spr_decrementing_table1564[k] = 35;
        spr_table160e[k] = j;
      } else {
        sub_1A72E(k, j);
      }
    }
  }
}

void CheckNormalSpriteToNormalSpriteColl_PlayKickSfx() {  // 01a728
  io_sound_ch1 = 3;
}

void sub_1A72E(uint8 k, uint8 j) {  // 01a72e
  if (!spr_decrementing_table1540[j] && spr_spriteid[j] < 0xF && (spr_table1588[j] & 4) != 0) {
    int8 v2 = spr_table15f6[j];
    if (v2 >= 0) {
      spr_yspeed[k] = -32;
      uint8 v3 = 24;
      if (spr_table164a[k])
        v3 = 44;
      spr_decrementing_table1558[k] = v3;
      spr_table1594[j] = k;
      spr_table1594[k] = j;
    } else {
      spr_table15f6[j] = v2 & 0x7F;
      spr_yspeed[j] = -32;
      spr_decrementing_table1564[j] = 32;
      CheckNormalSpriteToNormalSpriteColl_01A755(k);
    }
  }
}

void CheckNormalSpriteToNormalSpriteColl_01A755(uint8 k) {  // 01a755
  spr_table00c2[k] = 32;
  spr_decrementing_table1558[k] = 32;
}

uint8 CheckNormalSpriteToNormalSpriteColl_01A77C_ReturnsTwice(uint8 k, uint8 j) {  // 01a77c
  if (spr_spriteid[k] == 2 && !spr_table187b[j]) {
    uint8 v2 = spr_table157c[k];
    if (v2 != spr_table157c[j]) {
      R1_ = j;
      if (!spr_table1534[k]) {
        spr_table1528[k] = 0;
        spr_decrementing_table163e[k] = 0;
        R0_ = v2;
        SetSprXPos(j, GetSprXPos(k) + PAIR16(kCheckNormalSpriteToNormalSpriteColl_DATA_01A77A[v2], kCheckNormalSpriteToNormalSpriteColl_DATA_01A778[v2]));
        spr_table160e[k] = j;
        spr_table1534[k] = 1;
      }
      return true;
    }
  }
  return false;
}

uint8 CheckPlayerToNormalSpriteCollision(uint8 k) {  // 01a7e4
  if ((spr_property_bits167a[k] & 0x20) != 0 || !(spr_xoffscreen_flag[k] | (counter_global_frames ^ k) & 1))
    return CheckPlayerToNormalSpriteColl_ProcessInteract(k);
  else
    return 0;
}

uint8 CheckPlayerToNormalSpriteColl_ReturnNoContact() {  // 01a7f5
  return 0;
}

uint8 CheckPlayerToNormalSpriteColl_ProcessInteract(uint8 k) {  // 01a7f7
  CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  if ((uint8)(R15_ + 80) >= 0xA0)
    return 0;
  CheckPlayerPositionRelativeToSprite_Bank01_Y(k);
  if ((uint8)(R14_ + 96) >= 0xC0)
    return 0;
  else
    return CheckPlayerToNormalSpriteColl_01A80F(k);
}

uint8 CheckPlayerToNormalSpriteColl_01A80F(uint8 k) {  // 01a80f
  uint8 v8;

  if (player_current_state)
    return 0;
  int8 v2 = 0;
  if ((misc_nmito_use_flag & 0x40) == 0)
    v2 = spr_table1632[k] ^ player_current_layer_priority;
  if (v2)
    return 0;
  StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
  if (!StandardSpriteToSpriteCollisionChecks_CheckContact())
    return 0;
  if ((spr_property_bits167a[k] & 0x80) != 0)
    return 1;
  if (timer_star_power && (spr_property_bits167a[k] & 2) == 0)
    return CheckPlayerToNormalSpriteColl_01A847(k);
  player_star_kill_count = 0;
  if (spr_decrementing_table154c[k])
    return 0;
  spr_decrementing_table154c[k] = 8;
  if (spr_current_status[k] == 9) {
    CheckPlayerToNormalSpriteColl_01AA42(k);
    return 0;
  }
  R1_ = 20;
  R0_ = 2 * R0_ + (R5_ >= 0x14);
  uint8 v3 = R0_ & 1;
  R0_ >>= 1;
  if ((int8)(R11_ - !v3 - (((uint8)(R5_ - 20) < (uint8)player_current_ypos) + HIBYTE(player_current_ypos))) < 0 ||
      (player_yspeed & 0x80) != 0 && (spr_property_bits190f[k] & 0x10) == 0 && !counter_consecutive_enemies_stomped ||
      CheckNormalSpriteLevelColl_Floor(k) && !player_in_air_flag) {
LABEL_27:
    if (!player_sliding_on_ground || (spr_property_bits190f[k] & 4) != 0) {
      v3 = 0;
      if (!timer_player_hurt) {
        v3 = 0;
        if (!player_riding_yoshi_flag) {
          if ((spr_property_bits1686[k] & 0x10) == 0)
            spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
          uint8 v4 = spr_spriteid[k];
          v3 = v4 >= 0x53;
          if (v4 != 83)
            DamagePlayer_Hurt();
        }
      }
      return v3;
    } else {
      CheckNormalSpriteToNormalSpriteColl_PlayKickSfx();
      return CheckPlayerToNormalSpriteColl_01A847(k);
    }
  }
  if ((spr_property_bits1656[k] & 0x10) == 0) {
    if (player_riding_yoshi_flag | player_spin_jump_flag) {
      CheckPlayerToNormalSpriteColl_01A8D8(k);
      return v3;
    }
    goto LABEL_27;
  }
  if (player_riding_yoshi_flag | player_spin_jump_flag) {
    SpawnContactEffectFromAbove(k);
    player_yspeed = -8;
    if (player_riding_yoshi_flag)
      BoostMarioSpeed();
    SprStatus02_Dead_SetNorSprStatus04(k);
    SpawnSpinJumpStars(k);
    CheckPlayerToNormalSpriteColl_01AB46(k);
    io_sound_ch1 = 8;
LABEL_62:;
    uint8 v10 = spr_spriteid[k];
    if (v10 == 30)
      spr_decrementing_table1540[sprites_lakitu_cloud_slot_index] = 31;
    return v10 >= 0x1E;
  }
  CheckPlayerToNormalSpriteColl_01A8D8(k);
  if (spr_table187b[k]) {
    uint8 v5 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
    uint8 v6 = 24;
    if (v5)
      v6 = -24;
    player_xspeed = v6;
    return 1;
  } else {
    CheckPlayerToNormalSpriteColl_01AB46(k);
    uint8 v7 = spr_spriteid[k];
    if ((spr_property_bits1686[k] & 0x40) == 0) {
      if ((uint8)(spr_spriteid[k] - 4) < 0xD && player_cape_flying_phase || (spr_property_bits1656[k] & 0x20) != 0) {
        spr_current_status[k] = 3;
        spr_decrementing_table1540[k] = 32;
        spr_xspeed[k] = spr_yspeed[k] = 0;
        return 0;
      }
      if ((spr_property_bits1662[k] & 0x80) == 0) {
        uint8 v11 = spr_current_status[k];
        spr_table1626[k] = 0;
        if (v11 == 8)
          CheckPlayerToNormalSpriteColl_SetStunnedTimer(k);
        else
          CheckPlayerToNormalSpriteColl_01AA0B(k);
        printf("Unknown return value in carry!\n");
        return 0;
      }
      spr_current_status[k] = 2;
      spr_xspeed[k] = spr_yspeed[k] = 0;
      goto LABEL_62;
    }
    if (v7 < 0x72) {
      if (v7 == 110) {
        spr_table00c2[k] = 2;
        spr_decrementing_table1540[k] = -1;
        v8 = 111;
      } else if (v7 < 0x3F) {
        v8 = kGenericSpriteToSpawnTable[v7];
      } else {
        spr_decrementing_table1540[k] = 0x80;
        v8 = kGenericSpriteToSpawnTable[v7 - 46];
      }
    } else {
      CheckPlayerToNormalSpriteColl_SpawnFeatherFromSuperKoopa(k);
      v8 = 2;
    }
    spr_spriteid[k] = v8;
    R15_ = spr_table15f6[k] & 0xE;
    InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
    spr_table15f6[k] = R15_ | spr_table15f6[k] & 0xF1;
    spr_yspeed[k] = 0;
    uint8 v9 = spr_spriteid[k];
    if (v9 == 2)
      ++spr_table151c[k];
    return v9 >= 2;
  }
}

uint8 CheckPlayerToNormalSpriteColl_01A847(uint8 k) {  // 01a847
  SpawnContactEffectFromSide(k);
  uint8 v1 = ++player_star_kill_count;
  if (player_star_kill_count >= 8) {
    v1 = 8;
    player_star_kill_count = 8;
  }
  GivePoints(k, v1);
  if (player_star_kill_count < 8)
    io_sound_ch1 = kStompSoundTable_Bank01[player_star_kill_count - 1];
  spr_current_status[k] = 2;
  spr_yspeed[k] = -48;
  spr_xspeed[k] = kCheckPlayerToNormalSpriteColl_DATA_01A839[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
  return 0;
}

uint8 CheckPlayerToNormalSpriteColl_ReturnNoContact2() {  // 01a87c
  return 0;
}

void CheckPlayerToNormalSpriteColl_01A8D8(uint8 k) {  // 01a8d8
  io_sound_ch1 = 2;
  BoostMarioSpeed();
  SpawnContactEffectFromAbove(k);
}

void CheckPlayerToNormalSpriteColl_01AA0B(uint8 k) {  // 01aa0b
  if (spr_table00c2[k]) {
    CheckPlayerToNormalSpriteColl_SetStunnedTimer(k);
  } else {
    spr_decrementing_table1540[k] = 0;
    spr_current_status[k] = 9;
  }
}

void CheckPlayerToNormalSpriteColl_SetStunnedTimer(uint8 k) {  // 01aa14
  uint8 v2 = spr_spriteid[k];
  uint8 v1 = (v2 == 15 || v2 == 17 || v2 == 0xA2 || v2 == 13) ? -1 : 2;
  spr_decrementing_table1540[k] = v1;
  spr_current_status[k] = 9;
}

void BoostMarioSpeed() {  // 01aa33
  if (!player_climbing_flag) {
    player_yspeed = ((io_controller_hold1 & 0x80) != 0) ? -88 : -48;
  }
}

void CheckPlayerToNormalSpriteColl_01AA42(uint8 k) {  // 01aa42
  if (player_riding_yoshi_flag | player_spin_jump_flag && (player_yspeed & 0x80) == 0 && (spr_property_bits1656[k] & 0x10) != 0) {
    SpawnContactEffectFromAbove(k);
    player_yspeed = -8;
    if (player_riding_yoshi_flag)
      BoostMarioSpeed();
    SprStatus02_Dead_SetNorSprStatus04(k);
    SpawnSpinJumpStars(k);
    CheckPlayerToNormalSpriteColl_01AB46(k);
    io_sound_ch1 = 8;
    if (spr_spriteid[k] == 30)
      spr_decrementing_table1540[sprites_lakitu_cloud_slot_index] = 31;
  } else {
    if ((io_controller_hold1 & 0x40) != 0 && !(player_riding_yoshi_flag | player_carrying_something_flag1)) {
      spr_current_status[k] = 11;
      ++player_carrying_something_flag1;
      timer_display_player_pick_up_pose = 8;
      return;
    }
    uint8 v1 = spr_spriteid[k];
    if (v1 != 0x80) {
      if (v1 != 62) {
        if (v1 != 13 && v1 != 45 && v1 != 0xA2) {
          if (v1 == 15)
            spr_yspeed[k] = -16;
          else
            CheckPlayerToNormalSpriteColl_01AB46(k);
        }
        CheckNormalSpriteToNormalSpriteColl_PlayKickSfx();
        spr_table00c2[k] = spr_decrementing_table1540[k];
        spr_current_status[k] = 10;
        spr_decrementing_table154c[k] = 16;
        spr_xspeed[k] = kSprStatus0B_Carried_ShellXSpeed[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
        return;
      }
      if (spr_decrementing_table163e[k])
        return;
    }
    spr_decrementing_table154c[k] = 0;
    if ((uint8)(spr_ypos_lo[k] - player_current_ypos + 8) >= 0x20) {
      if ((int8)(spr_ypos_lo[k] - player_current_ypos - 24) >= 0) {
        if ((player_yspeed & 0x80) == 0) {
          player_yspeed = 0;
          player_in_air_flag = 0;
          ++misc_player_on_solid_sprite;
          R0_ = player_riding_yoshi_flag ? 47 : 31;
          player_ypos = GetSprYPos(k) - R0_;
          if (spr_spriteid[k] == 62) {
            spr_property_bits167a[k] &= ~0x80;
            io_sound_ch1 = 11;
            if ((misc_music_register_backup & 0x80) == 0)
              io_music_ch1 = 14;
            spr_decrementing_table163e[k] = 32;
            spr_table15f6[k] &= ~1;
            uint8 v4 = spr_table151c[k];
            *(&timer_blue_pswitch + v4) = -80;
            timer_shake_layer1 = 32;
            if (v4 == 1)
              CheckPlayerToNormalSpriteColl_TurnSpritesIntoSilverCoins();
          }
        }
      } else {
        player_yspeed = 16;
      }
    } else {
      CheckPlayerToNormalSpriteColl_01AB31(k);
    }
  }
}

void CheckPlayerToNormalSpriteColl_01AB31(uint8 k) {  // 01ab31
  player_xspeed = 0;
  player_xpos += kCheckPlayerToNormalSpriteColl_DATA_01AB2D[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
}

void CheckPlayerToNormalSpriteColl_01AB46(uint8 k) {  // 01ab46
  int8 v1 = spr_table1626[k] + counter_consecutive_enemies_stomped++;
  uint8 v2 = v1 + 1;
  if ((uint8)(v1 + 1) < 8)
    io_sound_ch1 = kStompSoundTable_Bank01[v2 - 1];
  uint8 v3 = v1 + 1;
  if (v2 >= 8)
    v3 = 8;
  GivePoints(k, v3);
}

void SpawnContactEffectFromSide(uint8 k) {  // 01ab6f
  CheckNormalSpriteToNormalSpriteColl_PlayKickSfx();
  SpawnContactEffectFromSide_NoKickSound(k);
}

void SpawnContactEffectFromSide_NoKickSound(uint8 k) {  // 01ab72
  if (!CheckIfNormalSpriteOffScreen(k)) {
    uint8 j = 3;
    while (smoke_spr_spriteid[j]) {
      if ((--j & 0x80) != 0) {
        ++j;
        break;
      }
    }
    smoke_spr_spriteid[j] = 2;
    smoke_spr_xpos_lo[j] = spr_xpos_lo[k];
    smoke_spr_ypos_lo[j] = spr_ypos_lo[k];
    smoke_spr_timer[j] = 8;
  }
}

void SpawnContactEffectFromAbove(uint8 k) {  // 01ab99
  if (!CheckIfNormalSpriteOffScreen(k)) {
    uint8 j = 3;
    while (smoke_spr_spriteid[j]) {
      if ((--j & 0x80) != 0) {
        ++j;
        break;
      }
    }
    smoke_spr_spriteid[j] = 2;
    smoke_spr_xpos_lo[j] = player_xpos;
    smoke_spr_ypos_lo[j] = player_ypos + (player_riding_yoshi_flag ? 30 : 20);
    smoke_spr_timer[j] = 8;
  }
}

void SubOffscreen_Bank01_Entry4(uint8 k) {  // 01ac21
  R3_ = 6;
  SubOffscreen_Bank01_01AC2D(k, 6);
}

void SubOffscreen_Bank01_Entry3(uint8 k) {  // 01ac27
  SubOffscreen_Bank01_01AC2D(k, 4);
}

void SubOffscreen_Bank01_Entry2(uint8 k) {  // 01ac2b
  SubOffscreen_Bank01_01AC2D(k, 2);
}

void SubOffscreen_Bank01_01AC2D(uint8 k, uint8 a) {  // 01ac2d
  R3_ = a;
  SubOffscreen_Bank01_01AC33(k);
}

void SubOffscreen_Bank01_Entry1(uint8 k) {  // 01ac31
  R3_ = 0;
  SubOffscreen_Bank01_01AC33(k);
}

void SubOffscreen_Bank01_01AC33(uint8 k) {  // 01ac33
  if (CheckIfNormalSpriteOffScreen(k)) {
    if ((misc_level_layout_flags & 1) != 0) {
      if ((spr_property_bits167a[k] & 4) == 0 && !(counter_global_frames & 1)) {
        if (spr_xpos_hi[k] >= 2) {
          SubOffscreen_Bank01_EraseSprite(k);
        } else {
          uint8 v4 = (counter_global_frames & 2) != 0;
          if (!v4 || spr_spriteid[k] != 34 && spr_spriteid[k] != 36) {
            uint16 t = PAIR16(kSubOffscreen_Bank01_SpriteOffScreen1_Hi[v4], kSubOffscreen_Bank01_SpriteOffScreen1_Lo[v4]) + 
                mirror_current_layer1_ypos - GetSprYPos(k);
            R0_ = (t >> 8) ^ (v4 ? 0x80 : 0);
            if ((R0_ & 0x80) != 0)
              SubOffscreen_Bank01_EraseSprite(k);
          }
        }
      }
    } else {
      uint16 y = GetSprYPos(k) + 80;
      if (!sign8((y >> 8) - 2)) {
        SubOffscreen_Bank01_EraseSprite(k);
      } else if ((spr_property_bits167a[k] & 4) == 0) {
        uint8 v4 = R3_ | counter_global_frames & 1;
        uint16 t = PAIR16(kSubOffscreen_Bank01_SpriteOffScreen2_Hi[v4], kSubOffscreen_Bank01_SpriteOffScreen2_Lo[v4]) +
            mirror_current_layer1_xpos - GetSprXPos(k);
        R0_ = (t >> 8) ^ (v4 & 1 ? 0x80 : 0);
        if ((R0_ & 0x80) != 0)
          SubOffscreen_Bank01_EraseSprite(k);
      }
    }
  }
}

void SubOffscreen_Bank01_EraseSprite(uint8 k) {  // 01ac80
  if (spr_spriteid[k] == 31) {
    sprites_sprite_to_respawn = spr_spriteid[k];
    timer_respawn_sprite = -1;
  }
  if (spr_current_status[k] >= 8) {
    uint8 v1 = spr_load_status_table_index[k];
    if (v1 != 0xFF)
      sprites_load_status[v1] = 0;
  }
  spr_current_status[k] = 0;
}

uint8 GetRand() {  // 01acf9
  GetRand_01AD07(1);
  return GetRand_01AD07(0);
}

uint8 GetRand_01AD07(uint8 j) {  // 01ad07
  misc_rngroutine_scratchram148b += 4 * misc_rngroutine_scratchram148b + 1;
  uint8 carry = misc_rngroutine_scratchram148c >> 7;
  misc_rngroutine_scratchram148c *= 2;
  misc_rngroutine_scratchram148c ^= carry ^ (misc_rngroutine_scratchram148c >> 5 & 1) ^ 1;
  uint8 rv = misc_rngroutine_scratchram148b ^ misc_rngroutine_scratchram148c;
  *(&misc_random_byte1 + j) = rv;
  return rv;
}

uint8 CheckPlayerPositionRelativeToSprite_Bank01_X(uint8 k) {  // 01ad30
  int t = player_current_xpos - GetSprXPos(k);
  R15_ = t;
  return sign16(t) != 0;
}

uint8 CheckPlayerPositionRelativeToSprite_Bank01_Y(uint8 k) {  // 01ad42
  int t = player_current_ypos - GetSprYPos(k);
  R14_ = t;
  return sign16(t) != 0;
}

void Spr085_Unused(uint8 k) {  // 01ad59
  spr_table151c[k] = (spr_xpos_lo[k] >> 4) & 3;
  ++spr_table157c[k];
}

void Spr083_LeftFlyingBlock(uint8 k) {  // 01ad6e
  if (spr_decrementing_table163e[k]) {
    spr_oamindex[k] = 0;
    if (!player_riding_yoshi_flag)
      spr_oamindex[k] = 4;
  }
  GenericGFXRtDraw1Tile16x16(k);
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  --oam[64].ypos;
  spr_table1528[k] = 0;
  if (!spr_table00c2[k]) {
    DrawWingTiles(k);
    if (!flag_sprites_locked) {
      if ((counter_global_frames & 1) == 0) {
        uint8 v2 = spr_table1594[k] & 1;
        spr_yspeed[k] += kSpr083_LeftFlyingBlock_Acceleration[v2];
        if (spr_yspeed[k] == kSpr083_LeftFlyingBlock_MaxYSpeed[v2])
          ++spr_table1594[k];
      }
      UpdateNormalSpritePosition_Y(k);
      if (spr_spriteid[k] == 0x83) {
        spr_xspeed[k] = -12;
      } else if (!spr_decrementing_table1540[k] && (counter_global_frames & 3) == 0) {
        uint8 v4 = spr_table1534[k] & 1;
        spr_xspeed[k] += kSpr083_LeftFlyingBlock_Acceleration[v4];
        if (spr_xspeed[k] == kSpr083_LeftFlyingBlock_MaxXSpeed[v4]) {
          ++spr_table1534[k];
          spr_decrementing_table1540[k] = 32;
        }
      }
      UpdateNormalSpritePosition_X(k);
      spr_table1528[k] = sprites_position_disp;
      ++spr_table1570[k];
    }
  }
  CheckNormalSpriteToNormalSpriteCollision(k);
  SolidSpriteBlock(k);
  SubOffscreen_Bank01_Entry1(k);
  uint8 v6 = spr_decrementing_table1558[k];
  if (v6 == 8 && spr_table00c2[k] != 2) {
    uint8 v12 = spr_decrementing_table1558[k];
    ++spr_table00c2[k];
    spr_decrementing_table163e[k] = 80;
    blocks_xpos = GetSprXPos(k);
    blocks_ypos = GetSprYPos(k);
    spr_load_status_table_index[k] = -1;
    uint8 v7 = spr_table151c[k];
    if (!player_current_power_up)
      v7 += 4;
    R5_ = kSpr083_LeftFlyingBlock_DATA_01AE88[v7];
    SpawnBounceSprite_02887D();
    uint8 v8 = misc_scratch7e185e;
    int v9 = misc_scratch7e185e;
    spr_table1528[misc_scratch7e185e] = 1;
    if (spr_spriteid[v9] == 117)
      spr_table00c2[v8] = -1;
    v6 = v12;
  }
  R0_ = kSpr083_LeftFlyingBlock_DATA_01AE7F[v6 >> 1];
  OamEnt *v10 = get_OamEnt(oam_buf, spr_oamindex[k]);
  v10[64].ypos -= R0_;
  v10[64].charnum = spr_table00c2[k] ? 46 : 42;
}

void Spr060_FlatPalaceSwitch_Init(uint8 k) {  // 01ae90
  ;
}

void Spr060_FlatPalaceSwitch(uint8 k) {  // 01ae91
  Spr060_FlatPalaceSwitch_Sub(k);
}

void Spr026_Thwomp_Init(uint8 k) {  // 01ae96
  spr_table151c[k] = spr_ypos_lo[k];
  spr_xpos_lo[k] += 8;
}

void Spr026_Thwomp_Init_Return(uint8 k) {  // 01aea2
  ;
}

void Spr026_Thwomp(uint8 k) {  // 01aea3
  Spr026_Thwomp_Draw(k);
  if (spr_current_status[k] == 8 && !flag_sprites_locked) {
    SubOffscreen_Bank01_Entry1(k);
    CheckPlayerToNormalSpriteCollision(k);
    kSpr026_Thwomp_ThwompPtrs[spr_table00c2[k]](k);
  }
}

void Spr026_Thwomp_Waiting(uint8 k) {  // 01aec3
  if (spr_yoffscreen_flag[k])
    goto LABEL_6;
  if (!spr_xoffscreen_flag[k]) {
    spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
    spr_table1528[k] = 0;
    if ((uint8)(R15_ + 64) < 0x80)
      spr_table1528[k] = 1;
    if ((uint8)(R15_ + 36) < 0x50) {
LABEL_6:
      spr_table1528[k] = 2;
      ++spr_table00c2[k];
      spr_yspeed[k] = 0;
    }
  }
}

void Spr026_Thwomp_Falling(uint8 k) {  // 01aefa
  UpdateNormalSpritePosition_Y(k);
  if (spr_yspeed[k] < 0x3E)
    spr_yspeed[k] += (spr_yspeed[k] >= 0x3E) + 4;
  HandleNormalSpriteLevelCollision(k);
  if (CheckNormalSpriteLevelColl_Floor(k)) {
    SetNormalSpriteYSpeedBasedOnSlope(k);
    timer_shake_layer1 = 24;
    io_sound_ch3 = 9;
    spr_decrementing_table1540[k] = 64;
    ++spr_table00c2[k];
  }
}

void Spr026_Thwomp_Rising(uint8 k) {  // 01af24
  if (!spr_decrementing_table1540[k]) {
    spr_table1528[k] = 0;
    if (spr_ypos_lo[k] == spr_table151c[k]) {
      spr_table00c2[k] = 0;
    } else {
      spr_yspeed[k] = -16;
      UpdateNormalSpritePosition_Y(k);
    }
  }
}

void Spr026_Thwomp_Draw(uint8 k) {  // 01af54
  uint8 drt;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  R2_ = spr_table1528[k];
  uint8 v2 = 3;
  if (R2_)
    v2 = 4;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSpr026_Thwomp_XDisp[v2] + R0_;
    oam[64].ypos = kSpr026_Thwomp_YDisp[v2] + R1_;
    oam[64].flags = sprites_tile_priority | kSpr026_Thwomp_Prop[v2];
    uint8 v4 = kSpr026_Thwomp_Tiles[v2];
    if (v2 == 4) {
      if (R2_ == 2)
        v4 = -54;
      v2 = 4;
    }
    oam[64].charnum = v4;
    drt += 4;
  } while ((--v2 & 0x80) == 0);
  NormalSpritePlatformGFXRt_01B37E(k, 4);
}

void Spr027_Thwimp(uint8 k) {  // 01af9f
  uint8 v2;
  if (spr_current_status[k] != 8 || flag_sprites_locked)
    goto LABEL_17;
  SubOffscreen_Bank01_Entry1(k);
  CheckPlayerToNormalSpriteCollision(k);
  UpdateNormalSpritePosition_X(k);
  UpdateNormalSpritePosition_Y(k);
  HandleNormalSpriteLevelCollision(k);
  int8 v1 = spr_yspeed[k];
  if (v1 >= 0) {
    if ((uint8)v1 >= 0x40) {
      v2 = 64;
      goto LABEL_8;
    }
    v1 += ((uint8)v1 >= 0x40) + 5;
  }
  v2 = v1 + 3;
LABEL_8:
  spr_yspeed[k] = v2;
  if (CheckNormalSpriteLevelColl_Ceiling(k))
    spr_yspeed[k] = 16;
  if (CheckNormalSpriteLevelColl_Floor(k)) {
    SetNormalSpriteYSpeedBasedOnSlope(k);
    spr_xspeed[k] = spr_yspeed[k] = 0;
    uint8 v3 = spr_decrementing_table1540[k];
    if (v3) {
      if (v3 == 1) {
        spr_yspeed[k] = -96;
        ++spr_table00c2[k];
        spr_xspeed[k] = (spr_table00c2[k] & 1) ? -16 : 16;
      }
    } else {
      io_sound_ch1 = 1;
      spr_decrementing_table1540[k] = 64;
    }
  }
LABEL_17:
  GenericGFXRtDraw4Tiles8x8Square(k, 1);
}

void Spr016_VerticalCheepCheep_Init(uint8 k) {  // 01b00b
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
  ++spr_table151c[k];
}

void SprXXX_FixedMovementCheepCheep_Init_Return(uint8 k) {  // 01b011
  ;
}

void Spr017_GeneratorCheepCheep_Init(uint8 k) {  // 01b014
  spr_xspeed[k] = kSpr017_GeneratorCheepCheep_Init_InitXSpeed[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
}

void Spr016_VerticalCheepCheep(uint8 k) {  // 01b033
  if (spr_current_status[k] != 8 || flag_sprites_locked)
    goto LABEL_23;
  SetNormalSpriteAnimationFrame(k);
  if (spr_table164a[k]) {
    HandleNormalSpriteLevelCollision(k);
    SetFacingDirectionBasedOnSpeed(k);
    spr_table15f6[k] &= ~0x80;
    if ((kSprXXX_FixedMovementCheepCheep_DATA_01B031[spr_table151c[k]] & spr_table1588[k]) != 0 ||
        !spr_decrementing_table1540[k]) {
      spr_decrementing_table1540[k] = 0x80;
      ++spr_table00c2[k];
    }
    uint8 v1 = spr_table00c2[k] & 1;
    if (spr_table151c[k])
      v1 += 2;
    spr_xspeed[k] = kSprXXX_FixedMovementCheepCheep_SwimmingXSpeed[v1];
    spr_yspeed[k] = kSprXXX_FixedMovementCheepCheep_SwimmingYSpeed[v1];
    if ((UpdateNormalSpritePosition_X(k) & 0xC) == 0)
      UpdateNormalSpritePosition_Y(k);
  } else {
    HandleNormalSpriteGravity(k);
    if (CheckNormalSpriteLevelColl_Wall(k))
      ChangeNormalSpriteDirection(k);
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      if (sprites_sprite_buoyancy_settings)
        SpawnWaterSplash_VerticalCheepCheepEntry(k);
      spr_xspeed[k] = kSprXXX_FixedMovementCheepCheep_FloppingXSpeed[(counter_global_frames + GetRand()) & 7];
      GetRand();
      spr_yspeed[k] = kSprXXX_FixedMovementCheepCheep_FloppingYSpeed[misc_random_byte2 & 3];
      if ((misc_random_byte1 & 0x40) == 0)
        spr_table15f6[k] ^= 0x80;
      GetRand();
      if ((misc_random_byte1 & 0x80) == 0)
        SetFacingDirectionBasedOnSpeed(k);
    }
    spr_table1602[k] += 2;
  }
  CheckNormalSpriteToNormalSpriteCollision(k);
  if (!(CheckPlayerToNormalSpriteCollision(k) & 1))
    goto LABEL_23;
  if (spr_table164a[k] && !timer_star_power) {
    if (!player_riding_yoshi_flag)
      DamagePlayer_Hurt();
LABEL_23:
    SprXXX_FixedMovementCheepCheep_01B10A(k);
    return;
  }
  KickHelplessSprite(k);
  SprXXX_FixedMovementCheepCheep_01B10A(k);
}

void SprXXX_FixedMovementCheepCheep_01B10A(uint8 k) {  // 01b10a
  R0_ = (spr_table1602[k] >> 1) ^ 1;
  spr_table15f6[k] = R0_ | spr_table15f6[k] & 0xFE;
  GenericGFXRtDraw1Tile16x16(k);
  SubOffscreen_Bank01_Entry1(k);
  spr_table15f6[k] >>= 1;
  spr_table15f6[k] = 2 * spr_table15f6[k] + 1;
}

void KickHelplessSprite(uint8 k) {  // 01b12a
  timer_display_player_kicking_pose = 16;
  io_sound_ch1 = 3;
  uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  spr_xspeed[k] = kSprXXX_FixedMovementCheepCheep_KickedXSpeed[v1];
  spr_yspeed[k] = -32;
  spr_current_status[k] = 2;
  player_facing_direction = v1;
  GivePoints(k, 1);
}

void SpawnSparklesSpriteEntry(uint8 k) {  // 01b14e
  SpawnSparkles_GoalSphereEntry(k, counter_global_frames & 3);
}

void SpawnSparkles_GoalSphereEntry(uint8 k, uint8 a) {  // 01b152
  if (!(flag_sprites_locked | (uint8)(spr_yoffscreen_flag[k] | a))) {
    int8 v3 = (GetRand() & 0xF) - 4;
    uint16 x = GetSprXPos(k) + v3;
    R2_ = x;
    if ((uint16)(x - mirror_current_layer1_xpos) < 256) {
      uint8 v5 = (misc_random_byte2 & 0xF) - 2;  // not signed?
      R0_W = GetSprYPos(k) + v5;
      SpawnSparkles();
    }
  }
}

void Spr017_GeneratorCheepCheep(uint8 k) {  // 01b192
  Spr018_SurfaceJumpingCheepCheep_01B209(k);
  if (!flag_sprites_locked) {
    SetNormalSpriteAnimationFrame(k);
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
    HandleNormalSpriteLevelCollision(k);
    uint8 v1 = spr_yspeed[k];
    if (sign8(v1 - 32))
      ++v1;
    spr_yspeed[k] = v1;
  }
}

void Spr018_SurfaceJumpingCheepCheep(uint8 k) {  // 01b1b4
  if (flag_sprites_locked) {
    Spr018_SurfaceJumpingCheepCheep_01B209(k);
  } else {
    spr_table151c[k] = spr_table164a[k];
    HandleNormalSpriteGravity(k);
    if (spr_table164a[k]) {
      uint8 v1 = spr_table00c2[k];
      if (v1 == 3) {
        spr_yspeed[k] -= ((counter_global_frames & 3) == 0) ? 2 : 1;
      } else {
        ++spr_table00c2[k];
        spr_yspeed[k] = kSpr018_SurfaceJumpingCheepCheep_YSpeed[v1];
        spr_decrementing_table1540[k] = 16;
        spr_table164a[k] = 0;
      }
    } else {
      spr_table1570[k] += 2;
      if (spr_table151c[k]) {
        spr_decrementing_table1540[k] = 16;
        if (spr_table00c2[k] == 3) {
          spr_table00c2[k] = 0;
          spr_yspeed[k] = -48;
        }
      }
    }
    SetNormalSpriteAnimationFrame(k);
    Spr018_SurfaceJumpingCheepCheep_01B209(k);
  }
}

void Spr018_SurfaceJumpingCheepCheep_01B209(uint8 k) {  // 01b209
  CheckPlayerAndNormalSpriteCollisions(k);
  SetFacingDirectionBasedOnSpeed(k);
  SprXXX_FixedMovementCheepCheep_01B10A(k);
}

void SprXXX_BuoyantPlatformsAndMine_Init_SpikeBallEntry(uint8 k) {  // 01b216
  SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
  uint8 v1 = spr_table157c[k];
  if ((spr_xpos_lo[k] & 0x10) != 0)
    v1 += 2;
  spr_xspeed[k] = kSprXXX_BuoyantPlatformsAndMine_Init_InitialXSpeed[v1];
  SprXXX_BuoyantPlatformsAndMine_Init_InitFloatingPlat(k);
}

void SprXXX_BuoyantPlatformsAndMine_Init_BuoyantCheckboardPlatformEntry(uint8 k) {  // 01b22b
  ++spr_table1602[k];
  SprXXX_BuoyantPlatformsAndMine_Init_FloatingOrangePlatformEntry(k);
}

void SprXXX_BuoyantPlatformsAndMine_Init_FloatingOrangePlatformEntry(uint8 k) {  // 01b22e
  if (sprites_sprite_buoyancy_settings)
    SprXXX_BuoyantPlatformsAndMine_Init_InitFloatingPlat(k);
  else
    ++spr_table00c2[k];
}

void SprXXX_BuoyantPlatformsAndMine_Init_InitFloatingPlat(uint8 k) {  // 01b236
  spr_table151c[k] = 3;
  do {
    HandleNormalSpriteLevelCollision(k);
    if (spr_table164a[k])
      break;
    if ((--spr_table151c[k] & 0x80) != 0) {
      SprXXX_BuoyantPlatformsAndMine_Init_01B262(k);
      return;
    }
    SetSprYPos(k, GetSprYPos(k) + 8);
  } while ((GetSprYPos(k) >> 8) < 2);
}

void SprXXX_BuoyantPlatformsAndMine_Init_Return(uint8 k) {  // 01b25d
  ;
}

void Spr057_VerticalCheckerboardPlatform_Init(uint8 k) {  // 01b25e
  ++spr_table1602[k];
}

void SprXXX_BuoyantPlatformsAndMine_Init_01B262(uint8 k) {  // 01b262
  spr_current_status[k] = 1;
}

void SprXXX_BuoyantPlatformsAndMine_Init_HorizontalTurnBlockBridgeEntry(uint8 k) {  // 01b267
  ;
}

void Spr058_VerticalRockPlatform(uint8 k) {  // 01b26c
  NormalSpritePlatformDraw(k);
  if (!flag_sprites_locked) {
    if (!spr_decrementing_table1540[k] && (++spr_table00c2[k] & 3) == 0) {
      uint8 v1 = spr_table151c[k] & 1;
      uint8 v2 = kSpr055_HorizontalCheckerboardPlatform_DATA_01B268[v1] + spr_yspeed[k];
      spr_yspeed[k] = v2;
      spr_xspeed[k] = v2;
      if (v2 == kSpr055_HorizontalCheckerboardPlatform_DATA_01B26A[v1]) {
        ++spr_table151c[k];
        spr_decrementing_table1540[k] = (spr_spriteid[k] == 85) ? 8 : 24;
      }
    }
    if (spr_spriteid[k] >= 0x57) {
      UpdateNormalSpritePosition_Y(k);
      sprites_position_disp = 0;
    } else {
      UpdateNormalSpritePosition_X(k);
    }
    spr_table1528[k] = sprites_position_disp;
    SolidSpriteBlock(k);
    SubOffscreen_Bank01_Entry2(k);
  }
}

void NormalSpritePlatformDraw(uint8 k) {  // 01b2d1
  uint8 drt;

  if (kNormalSpritePlatformGFXRt_DATA_01B2C3[(uint8)(spr_spriteid[k] - 85)]) {
    if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
      return;
    R0_ = spr_spriteid[k] == 94;
    uint8 v1 = drt;
    int8 v2 = spr_ypos_lo[k] - mirror_current_layer1_ypos;
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].ypos = v2;
    oam[66].ypos = v2;
    oam[68].ypos = v2;
    if (R0_) {
      oam[70].ypos = v2;
      oam[72].ypos = v2;
    }
    int8 v4 = v2 + 16;
    oam[65].ypos = v4;
    oam[67].ypos = v4;
    if (R0_) {
      oam[69].ypos = v4;
      oam[71].ypos = v4;
    }
    uint8 v5 = 8;
    if (!R0_)
      v5 = 4;
    R1_ = v5;
    R2_ = v5 - 1;
    R3_ = spr_table15f6[spr_current_slotid];
    int8 v6 = 0;
    if (spr_spriteid[spr_current_slotid] < 0x5B)
      v6 = 9;
    int8 v17 = v6;
    int8 v7 = spr_xpos_lo[spr_current_slotid] - mirror_current_layer1_xpos;
    uint8 v8 = v17;
    do {
      OamEnt *v9 = get_OamEnt(oam_buf, v1);
      v9[64].xpos = v7;
      int8 v18 = v7 + 8;
      v9[64].charnum = kNormalSpritePlatformGFXRt_DiagPlatTiles[v8];
      int8 v10 = R3_ | sprites_tile_priority;
      if (R1_ < R2_)
        v10 |= 0x40;
      v9[64].flags = v10;
      v7 = v18;
      v1 += 4;
      ++v8;
    } while ((--R1_ & 0x80) == 0);
    uint8 v11 = spr_current_slotid;
    uint8 v12 = spr_oamindex[spr_current_slotid];
    if (!R0_) {
      if (spr_spriteid[spr_current_slotid] >= 0x5B) {
        OamEnt *v14 = get_OamEnt(oam_buf, v12);
        v14[68].charnum = -53;
        v14[67].charnum = -28;
      } else {
        OamEnt *v13 = get_OamEnt(oam_buf, v12);
        v13[68].charnum = -123;
        v13[67].charnum = -120;
      }
    }
    uint8 v15 = 8;
    if (!R0_)
      v15 = 4;
    NormalSpritePlatformGFXRt_01B37E(v11, v15);
  } else {
    NormalSpritePlatformGFXRt_DrawFlatPlatform(k);
  }
}

void NormalSpritePlatformGFXRt_DrawFlatPlatform(uint8 k) {  // 01b2df
  uint8 drt;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  R1_ = spr_table1602[k];
  int8 v2 = spr_ypos_lo[k] - mirror_current_layer1_ypos;
  OamEnt *oam = get_OamEnt(oam_buf, drt);
  oam[64].ypos = v2;
  oam[65].ypos = v2;
  oam[66].ypos = v2;
  if (R1_) {
    oam[67].ypos = v2;
    oam[68].ypos = v2;
  }
  int8 v4 = spr_xpos_lo[spr_current_slotid] - mirror_current_layer1_xpos;
  oam[64].xpos = v4;
  v4 += 16;
  oam[65].xpos = v4;
  int8 v5 = v4 + 16;
  oam[66].xpos = v5;
  if (R1_) {
    int8 v6 = v5 + 16;
    oam[67].xpos = v6;
    oam[68].xpos = v6 + 16;
  }
  uint8 v7 = spr_current_slotid;
  if (R1_) {
    oam[64].charnum = -22;
    oam[65].charnum = -21;
    oam[66].charnum = -21;
    oam[67].charnum = -21;
    oam[68].charnum = -20;
  } else {
    oam[64].charnum = 96;
    oam[65].charnum = 97;
    oam[66].charnum = 97;
    oam[67].charnum = 97;
    oam[68].charnum = 98;
  }
  int8 v8 = spr_table15f6[v7] | sprites_tile_priority;
  oam[64].flags = v8;
  oam[65].flags = v8;
  oam[66].flags = v8;
  oam[67].flags = v8;
  oam[68].flags = v8;
  if (!R1_)
    oam[66].charnum = 98;
  if (R1_)
    NormalSpritePlatformGFXRt_01B37E(v7, 4);
  else
    NormalSpritePlatformGFXRt_01B37E(v7, 2);
}

void NormalSpritePlatformGFXRt_01B37E(uint8 k, uint8 a) {  // 01b37e
  FinishOAMWrite(k, 2, a);
}

uint8 SolidSpriteBlock(uint8 k) {  // 01b457
  uint8 r = CheckPlayerToNormalSpriteColl_ProcessInteract(k);
  if (!r)
    return 0;
  
  R0_ = spr_ypos_lo[k] - mirror_current_layer1_ypos;
  if (sign8(player_on_screen_pos_y + 24 - R0_)) {
    if ((player_yspeed & 0x80) == 0 && (player_blocked_flags & 8) == 0) {
      player_yspeed = 16;
      misc_player_on_solid_sprite = 1;
      R1_ = player_riding_yoshi_flag ? 47 : 31;
      player_ypos = GetSprYPos(k) - R1_;
      if ((player_blocked_flags & 3) == 0)
        player_xpos += (int8)spr_table1528[k];
      return 1;
    }
    return 0;
  }
  if (spr_property_bits190f[k] & 1)
    return 0;
  uint8 v7 = 0;
  if (player_ducking_flag || !player_current_power_up)
    v7 = 8;
  if (player_riding_yoshi_flag)
    v7 += 8;
  if ((uint8)(player_on_screen_pos_y + v7) < R0_)
    return sub_1B505(k);
  if ((player_yspeed & 0x80) == 0)
    return 0;
  player_yspeed = 16;
  if (spr_spriteid[k] >= 0x83)
    return SolidSpriteBlock_Entry2(k);
  io_sound_ch1 = 1;
  return 0;
}

uint8 SolidSpriteBlock_Entry2(uint8 k) {  // 01b4e2
  spr_decrementing_table1564[k] = 15;
  if (!spr_table00c2[k]) {
    ++spr_table00c2[k];
    spr_decrementing_table1558[k] = 16;
  }
  io_sound_ch1 = 1;
  return 0;
}

uint8 sub_1B505(uint8 k) {  // 01b505
  uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  uint8 v2 = spr_spriteid[k];
  if (v2 == 0xA9)
    goto LABEL_7;
  if (v2 == 0x9C || v2 == 0xBB || v2 == 96 || v2 == 73) {
    v1 += 2;
LABEL_7:
    v1 += 2;
  }
  player_xpos = GetSprXPos(k) + PAIR16(kSolidSpriteBlock_DATA_01B4FF[v1], kSolidSpriteBlock_DATA_01B4F9[v1]);
  player_xspeed = 0;
  return 0;
}

void SprXXX_BuoyantPlatformsAndMine_FloatingOrangePlatformEntry(uint8 k) {  // 01b536
  if (spr_table00c2[k]) {
    NormalSpritePlatformDraw(k);
    if (!flag_sprites_locked) {
      UpdateNormalSpritePosition_X(k);
      spr_table1528[k] = sprites_position_disp;
      if (SolidSpriteBlock(k)) {
        flag_active_fast_background_scroll_generator = 1;
        spr_xspeed[k] = 8;
      }
    }
  } else {
    SprXXX_BuoyantPlatformsAndMine_01B563(k);
  }
}

void SprXXX_BuoyantPlatformsAndMine_SpikeBallEntry(uint8 k) {  // 01b559
  if (spr_current_status[k] == 8)
    SprXXX_BuoyantPlatformsAndMine_01B563(k);
  else
    SprXXX_BuoyantPlatformsAndMine_SpikeBallDraw(k);
}

void SprXXX_BuoyantPlatformsAndMine_01B563(uint8 k) {  // 01b563
  if (!flag_sprites_locked) {
    if ((spr_table1588[k] & 0xC) == 0)
      UpdateNormalSpritePosition_Y(k);
    sprites_position_disp = 0;
    if (spr_spriteid[k] == 0xA4)
      UpdateNormalSpritePosition_X(k);
    if (sign8(spr_yspeed[k] - 64))
      ++spr_yspeed[k];
    if (spr_table164a[k]) {
      R0_ = (spr_spriteid[k] >= 0x5D) ? -4 : -8;
      uint8 v2 = spr_yspeed[k];
      if ((v2 & 0x80) == 0 || v2 >= R0_)
        spr_yspeed[k] = v2 - 2;
    }
    uint8 v10 = player_yspeed;
    int8 v3;
    if (spr_spriteid[k] == 0xA4) {
      CheckPlayerToNormalSpriteCollision(k);
      v3 = 0;
    } else {
      v3 = SolidSpriteBlock(k);
    }
    R0_ = v10;
    misc_scratch7e185e = 0;
    if (v3) {
      if (spr_spriteid[k] >= 0x5D) {
        R0_ = player_current_power_up ? 3 : 2;
        if (sign8(spr_yspeed[k] - R0_))
          spr_yspeed[k] += 2;
      }
      ++misc_scratch7e185e;
      if (R0_ >= 0x20)
        spr_yspeed[k] = R0_ >> 2;
    }
    bool v5 = misc_scratch7e185e == spr_table151c[k];
    spr_table151c[k] = misc_scratch7e185e;
    if (!v5 && !misc_scratch7e185e && (player_yspeed & 0x80) != 0) {
      R0_ = player_current_power_up ? 8 : 6;
      if (sign8(spr_yspeed[k] - 32))
        spr_yspeed[k] += R0_;
    }
    if ((counter_global_frames & 1) == 0) {
      int8 v7 = spr_yspeed[k];
      if (v7)
        spr_yspeed[k] = v7 + (v7 < 0 ? 2 : 0) - 1;
      uint8 v8 = misc_scratch7e185e;
      if (misc_scratch7e185e) {
        v8 = player_current_power_up ? 5 : 2;
      }
      R0_ = v8;
      uint16 old_y = GetSprYPos(k);
      SetSprYPos(k, old_y - v8);
      HandleNormalSpriteLevelCollision(k);
      SetSprYPos(k, old_y);
    }
  }
  SubOffscreen_Bank01_Entry1(k);
  if (spr_spriteid[k] == 0xA4)
    SprXXX_BuoyantPlatformsAndMine_SpikeBallDraw(k);
  else
    NormalSpritePlatformDraw(k);
}

void SprXXX_BuoyantPlatformsAndMine_SpikeBallDraw(uint8 k) {  // 01b666
  uint8 drt;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSprXXX_BuoyantPlatformsAndMine_SpikeBallXDisp[i] + R0_;
    oam[64].ypos = kSprXXX_BuoyantPlatformsAndMine_SpikeBallYDisp[i] + R1_;
    oam[64].charnum = ((uint8)((counter_local_frames >> 2) & 4) >> 1) - 86;
    oam[64].flags = kSprXXX_BuoyantPlatformsAndMine_SpikeBallProp[i];
    drt += 4;
  }
  FinishOAMWrite(k, 2, 3);
}

void SprXXX_TurnBlockBridge_HorizontalAndVerticalTurnBlockBridgeEntry(uint8 k) {  // 01b6a5
  SubOffscreen_Bank01_Entry1(k);
  SprXXX_TurnBlockBridge_Draw(k);
  SprXXX_TurnBlockBridge_01B852(k);
  SprXXX_TurnBlockBridge_01B6B2(k);
}

void SprXXX_TurnBlockBridge_01B6B2(uint8 k) {  // 01b6b2
  uint8 v1 = spr_table00c2[k] & 1;
  if (spr_table151c[k] == kSprXXX_TurnBlockBridge_BlkBridgeLength[v1]) {
    spr_decrementing_table1540[k] = kSprXXX_TurnBlockBridge_BlkBridgeTiming[v1];
    ++spr_table00c2[k];
  } else if (!(flag_sprites_locked | spr_decrementing_table1540[k])) {
    spr_table151c[k] += kSprXXX_TurnBlockBridge_TurnBlkBridgeSpeed[v1];
  }
}

void SprXXX_TurnBlockBridge_HorizontalTurnBlockBridgeEntry(uint8 k) {  // 01b6da
  SubOffscreen_Bank01_Entry1(k);
  SprXXX_TurnBlockBridge_Draw(k);
  SprXXX_TurnBlockBridge_01B852(k);
  SprXXX_TurnBlockBridge_01B6E7(k);
}

void SprXXX_TurnBlockBridge_01B6E7(uint8 k) {  // 01b6e7
  uint8 v1 = spr_table00c2[k];
  if (spr_table151c[k] == kSprXXX_TurnBlockBridge_BlkBridgeLength[v1]) {
    spr_decrementing_table1540[k] = kSprXXX_TurnBlockBridge_BlkBridgeTiming[v1];
    spr_table00c2[k] ^= 1;
  } else if (!(flag_sprites_locked | spr_decrementing_table1540[k])) {
    spr_table151c[k] += kSprXXX_TurnBlockBridge_TurnBlkBridgeSpeed[v1];
  }
}

void SprXXX_TurnBlockBridge_Draw(uint8 k) {  // 01b710
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
  R0_ = 0;
  R1_ = 0;
  R2_ = 0;
  R3_ = 0;
  uint8 v1 = spr_table00c2[k] & 2;
  uint8 v2 = spr_table151c[k];
  *(&R0_ + v1) = v2;
  *(&R1_ + v1) = v2 >> 1;
  int8 v3 = spr_ypos_lo[k] - mirror_current_layer1_ypos;
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[68].ypos = v3;
  oam[66].ypos = v3 - R2_;
  oam[67].ypos = v3 - R3_;
  oam[64].ypos = R2_ + v3;
  oam[65].ypos = R3_ + v3;
  int8 v5 = spr_xpos_lo[k] - mirror_current_layer1_xpos;
  oam[68].xpos = v5;
  oam[66].xpos = v5 - R0_;
  oam[67].xpos = v5 - R1_;
  oam[64].xpos = R0_ + v5;
  oam[65].xpos = R1_ + v5;
  oam[65].charnum = 64;
  oam[67].charnum = 64;
  oam[68].charnum = 64;
  oam[66].charnum = 64;
  oam[64].charnum = 64;
  uint8 v6 = sprites_tile_priority;
  oam[67].flags = sprites_tile_priority;
  oam[65].flags = v6;
  oam[66].flags = v6;
  oam[68].flags = v6;
  oam[64].flags = v6 | 0x60;
  uint8 v8 = R0_;
  uint8 v7 = R2_;
  NormalSpritePlatformGFXRt_01B37E(k, 4);
  R2_ = v7;
  R0_ = v8;
}

void FinishOAMWrite(uint8 k, uint8 j, uint8 a) {  // 01b7bb
  R11_ = j;
  R8_ = a;
  uint8 v3 = spr_oamindex[k];
  R0_W = GetSprYPos(k);
  R6_ = R0_W - mirror_current_layer1_ypos;
  R2_W = GetSprXPos(k);
  R7_ = R2_W - mirror_current_layer1_xpos;
  do {
    uint8 v4 = v3 >> 2;
    uint8 v5 = R11_;
    if ((R11_ & 0x80) != 0)
      v5 = sprites_oamtile_size_buffer[v4 + 64] & 2;
    sprites_oamtile_size_buffer[v4 + 64] = v5;
    OamEnt *oam = get_OamEnt(oam_buf, v3);
    R4_W = R2_W + (int8)(oam[64].xpos - R7_);
    if (FinishOAMWrite_01B844())
      sprites_oamtile_size_buffer[(v3 >> 2) + 64] |= 1;
    R9_W = R0_W + (int8)(oam[64].ypos - R6_);
    if (Spr05F_BrownChainedPlatform_01C9BF())
      oam[64].ypos = -16;
    v3 += 4;
  } while ((--R8_ & 0x80) == 0);
}

uint8 FinishOAMWrite_01B844() {  // 01b844
  return (uint16)(R4_W - mirror_current_layer1_xpos) >= 0x100;
}

void SprXXX_TurnBlockBridge_Return01B851() {  // 01b851
  ;
}

void SprXXX_TurnBlockBridge_01B852(uint8 k) {  // 01b852
  if (!spr_table15c4[k] && !player_current_state && SprXXX_TurnBlockBridge_01B8FF(k) & 1) {
    R2_ = spr_ypos_lo[k] - mirror_current_layer1_ypos;
    R9_ = R2_ - R13_;
    if ((uint8)(player_on_screen_pos_y + 24) >= (uint8)(R2_ - R13_)) {
      R2_ += R13_;
      int8 v5 = -1;
      if (player_ducking_flag || !player_current_power_up)
        v5 = 8;
      if ((uint8)(player_on_screen_pos_y + v5) < R2_) {
        R0_ = R14_ + 16;
        if ((uint8)(spr_xpos_lo[k] - mirror_current_layer1_xpos) >= (uint8)player_on_screen_pos_x)
          R0_ = -R0_;
        player_xpos = GetSprXPos(k) + (int8)R0_;
        player_xspeed = 0;
      } else if ((player_yspeed & 0x80) != 0) {
        player_yspeed = 16;
      }
    } else if ((player_yspeed & 0x80) == 0) {
      player_yspeed = 0;
      misc_player_on_solid_sprite = 1;
      R0_ = R13_ + (player_riding_yoshi_flag ? 47 : 31);
      player_ypos = GetSprYPos(k) - R0_;
      player_xpos += (int8)sprites_position_disp;
    }
  }
}

uint8 SprXXX_TurnBlockBridge_01B8FF(uint8 k) {  // 01b8ff
  R14_ = R0_;
  R13_ = R2_;
  SetHiLo(&R10_, &R4_, GetSprXPos(k) - R0_);
  R6_ = 2 * R0_ + 16;
  SetHiLo(&R11_, &R5_, GetSprYPos(k) - R2_);
  R7_ = 2 * R2_ + 16;
  StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
  return StandardSpriteToSpriteCollisionChecks_CheckContact();
}

void SprXXX_NetKoopas_Init_HorizontalNetKoopaEntry(uint8 k) {  // 01b93e
  spr_xspeed[k] = kSprXXX_NetKoopas_Init_InitXSpeed[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
  SprXXX_NetKoopas_Init_01B950(k);
}

void SprXXX_NetKoopas_Init_VerticalNetKoopaEntry(uint8 k) {  // 01b948
  ++spr_table00c2[k];
  ++spr_xspeed[k];
  spr_yspeed[k] = -8;
  SprXXX_NetKoopas_Init_01B950(k);
}

void SprXXX_NetKoopas_Init_01B950(uint8 k) {  // 01b950
  spr_table1632[k] = (spr_xpos_lo[k] & 0x10) == 0;
  if ((spr_table15f6[k] & 2) == 0) {
    spr_xspeed[k] *= 2;
    spr_yspeed[k] *= 2;
  }
}

void SprXXX_NetKoopas(uint8 k) {  // 01b97f
  uint8 v1 = spr_decrementing_table1540[k];
  if (!v1) {
    if (flag_sprites_locked) {
LABEL_30:;
      uint8 v10 = spr_table157c[k];
      spr_table157c[k] = (uint8)(spr_table1570[k] & 8) >> 3;
      uint8 v8 = sprites_tile_priority;
      spr_table1602[k] = spr_table1632[k];
      if (spr_table1632[k])
        sprites_tile_priority = 16;
      GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
      sprites_tile_priority = v8;
      spr_table157c[k] = v10;
      return;
    }
    HandleNormalSpriteLevelCollision(k);
    if ((kSprXXX_NetKoopas_DATA_01B97D[spr_table00c2[k]] & spr_table1588[k]) != 0)
      goto LABEL_16;
    uint8 v4 = sprites_map16_tile_touched_vert_lo;
    int8 v5 = spr_yspeed[k];
    if (v5) {
      if (v5 < 0) {
LABEL_22:
        if (v4 < 7 || v4 >= 0x1D)
          spr_decrementing_table1540[k] = 80;
        goto LABEL_25;
      }
      if (sprites_map16_tile_touched_vert_lo < 7 || sprites_map16_tile_touched_vert_lo >= 0x1D) {
LABEL_16:
        ChangeNormalSpriteDirection(k);
        SprXXX_NetKoopas_01BA7F(k);
        goto LABEL_25;
      }
    }
    v4 = sprites_map16_tile_touched_horiz_lo;
    goto LABEL_22;
  }
  if (v1 < 0x30) {
LABEL_25:
    if (!flag_sprites_locked) {
      ++spr_table1570[k];
      SetFacingDirectionBasedOnSpeed(k);
      if (spr_table00c2[k])
        UpdateNormalSpritePosition_Y(k);
      else
        UpdateNormalSpritePosition_X(k);
      CheckPlayerToNormalSpriteCollision(k);
      SubOffscreen_Bank01_Entry1(k);
    }
    goto LABEL_30;
  }
  if (v1 >= 0x40) {
    if (v1 == 64 && !flag_sprites_locked) {
      spr_table1632[k] ^= 1;
      ChangeNormalSpriteDirection(k);
      SprXXX_NetKoopas_01BA7F(k);
    }
    goto LABEL_25;
  }
  uint16 old_y = GetSprYPos(k);
  uint8 v2 = v1 >= 0x38;
  if (spr_table00c2[k]) {
    v2 += 2;
    AddSprYPos(k, -12);
    if (spr_table1632[k])
      ++v2;
  }
  if ((ow_level_tile_settings[73] & 0x80) != 0)
    v2 += 5;
  spr_table1602[k] = kSprXXX_NetKoopas_DATA_01B969[v2];
  uint8 v6 = spr_table15f6[k];
  spr_table15f6[k] = kSprXXX_NetKoopas_DATA_01B973[v2] | v6 & 0xFE;
  GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
  spr_table15f6[k] = v6;
  SetSprYPos(k, old_y);
}

void SprXXX_NetKoopas_01BA7F(uint8 k) {  // 01ba7f
  spr_yspeed[k] = -spr_yspeed[k];
}

void Spr054_ClimbingNetDoor_Init(uint8 k) {  // 01ba87
  AddHiLo(&spr_ypos_lo[k], &spr_xpos_lo[k], 0x708);  // wtf?
}

void Spr054_ClimbingNetDoor(uint8 k) {  // 01bacd
  SubOffscreen_Bank01_Entry1(k);
  if (spr_decrementing_table154c[k] == 1) {
    io_sound_ch1 = 15;
    Spr054_ClimbingNetDoor_UpdateClimbingNetDoorTiles(k, 0x19);
    spr_decrementing_table1540[k] = 31;
    timer_on_swinging_climbing_net_door = 31;
    sprites_player_xspeed_on_swinging_net_door = player_xpos - 16 - spr_xpos_lo[k];
  }
  if (!(spr_decrementing_table154c[k] | spr_decrementing_table1540[k])) {
    StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
    Spr054_ClimbingNetDoor_01BC1D();
    if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
      if (timer_display_player_net_punch_pose == 1)
        spr_decrementing_table154c[k] = 6;
    }
  }
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 == 1) {
      Spr054_ClimbingNetDoor_UpdateClimbingNetDoorTiles(k, 0x1A);
      v1 = 1;
    }
    if (v1 == 16)
      player_current_layer_priority ^= 1;
    spr_oamindex[k] = 48;
    R3_ = 48;
    uint8 v2 = 48;
    R0_ = spr_xpos_lo[k] - mirror_current_layer1_xpos;
    R1_ = spr_ypos_lo[k] - mirror_current_layer1_ypos;
    R2_ = spr_decrementing_table1540[k] >> 1;
    uint8 v3 = R2_;
    R6_ = kSpr054_ClimbingNetDoor_AnimationFrame[R2_];
    int8 v4 = kSpr054_ClimbingNetDoor_XDisp[R2_] + R0_;
    OamEnt *oam = get_OamEnt(oam_buf, 0x30);
    oam[64].xpos = v4;
    oam[65].xpos = v4;
    oam[66].xpos = v4;
    if (R6_ != 2) {
      int8 v6 = R0_ + 32 - kSpr054_ClimbingNetDoor_XDisp[v3];
      oam[67].xpos = v6;
      oam[68].xpos = v6;
      oam[69].xpos = v6;
      if (!R6_) {
        int8 v7 = R0_ + 16;
        oam[70].xpos = R0_ + 16;
        oam[71].xpos = v7;
        oam[72].xpos = v7;
      }
    }
    uint8 v8 = R1_;
    oam[64].ypos = R1_;
    oam[67].ypos = v8;
    oam[70].ypos = v8;
    v8 += 16;
    oam[65].ypos = v8;
    oam[68].ypos = v8;
    oam[71].ypos = v8;
    v8 += 16;
    oam[66].ypos = v8;
    oam[69].ypos = v8;
    oam[72].ypos = v8;
    R7_ = 8;
    uint8 v9 = R6_ + __CFSHL__(4 * R6_, 1) + 8 * R6_;
    do {
      get_OamEnt(oam_buf, v2)[64].charnum = kSpr054_ClimbingNetDoor_Tiles[v9];
      v2 += 4;
      ++v9;
      --R7_;
    } while ((R7_ & 0x80) == 0);
    uint8 v10 = R3_;
    for (int8 i = 8; i >= 0; --i) {
      int8 v12 = sprites_tile_priority | 9;
      if ((uint8)i < 6)
        v12 = sprites_tile_priority | 0x49;
      if (!i || i == 3 || i == 6)
        v12 |= 0x80;
      get_OamEnt(oam_buf, v10)[64].flags = v12;
      v10 += 4;
    }
    uint8 v13 = R6_;
    NormalSpritePlatformGFXRt_01B37E(spr_current_slotid, 8);
    if (v13) {
      if (v13 == 2) {
        sprites_oamtile_size_buffer[79] = 3;
        sprites_oamtile_size_buffer[80] = 3;
        sprites_oamtile_size_buffer[81] = 3;
      }
      sprites_oamtile_size_buffer[82] = 3;
      sprites_oamtile_size_buffer[83] = 3;
      sprites_oamtile_size_buffer[84] = 3;
    }
  }
}

void Spr054_ClimbingNetDoor_01BC1D() {  // 01bc1d
  SetHiLo(&R8_, &R0_, player_xpos);
  SetHiLo(&R9_, &R1_, player_ypos);
  R2_ = 16;
  R3_ = 16;
}

void Spr020_Magic(uint8 k) {  // 01bc38
  uint8 v3;
  if (flag_sprites_locked ||
      (SpawnSparklesSpriteEntry(k), UpdateNormalSpritePosition_Y(k), UpdateNormalSpritePosition_X(k),
       v3 = spr_yspeed[k], spr_yspeed[k] = -1, HandleNormalSpriteLevelCollision(k), spr_yspeed[k] = v3,
       !CheckNormalSpriteLevelColl_Ceiling(k)) ||
      spr_xoffscreen_flag[k]) {
    CheckPlayerAndNormalSpriteCollisions(k);
    spr_table15f6[k] = kSpr020_Magic_Palettes[(counter_global_frames >> 2) & 3];
    Spr020_Magic_Draw(k);
    SubOffscreen_Bank01_Entry1(k);
    if ((uint8)(spr_ypos_lo[k] - mirror_current_layer1_ypos) >= 0xE0)
      spr_current_status[k] = 0;
  } else {
    io_sound_ch1 = 1;
    spr_current_status[k] = 0;
    if ((uint8)(sprites_map16_tile_touched_vert_lo - 17) < 0x1D) {
      uint8 tt = GetRand();
      uint8 v1 = counter_global_frames + player_xspeed + misc_random_byte2 + tt;
      uint8 v2 = 120;
      if (v1 != 53) {
        v2 = 33;
        if (v1 >= 8) {
          v2 = 39;
          if (v1 < 0xF7)
            v2 = 7;
        }
      }
      spr_spriteid[k] = v2;
      spr_current_status[k] = 8;
      InitializeNormalSpriteRAMTables(k);
      SetSprXPos(k, blocks_xpos & ~0xf);
      SetSprYPos(k, blocks_ypos & ~0xf);
      blocks_map16_to_generate = 2;
      GenerateTile();
    }
    Spr020_Magic_01BD98(k);
  }
}

void Spr020_Magic_Draw(uint8 k) {  // 01bcf0
  uint8 drt;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  R3_ = (counter_local_frames >> 1) & 0xF;
  R2_ = (R3_ + 12) & 0xF;
  R1_ -= 4;
  R0_ -= 4;
  OamEnt *oam = get_OamEnt(oam_buf, drt);
  oam[64].ypos = kSpr020_Magic_Disp[(R3_ + 12) & 0xF] + R1_;
  oam[64].xpos = kSpr020_Magic_Disp[R3_] + R0_;
  R2_ = (R2_ + 5) & 0xF;
  oam[65].ypos = kSpr020_Magic_Disp[R2_] + R1_;
  R3_ = (R3_ + 5) & 0xF;
  oam[65].xpos = kSpr020_Magic_Disp[R3_] + R0_;
  R2_ = (R2_ + 5) & 0xF;
  oam[66].ypos = kSpr020_Magic_Disp[R2_] + R1_;
  R3_ = (R3_ + 5) & 0xF;
  oam[66].xpos = kSpr020_Magic_Disp[R3_] + R0_;
  uint8 v3 = spr_current_slotid;
  int8 v4 = sprites_tile_priority | spr_table15f6[spr_current_slotid];
  oam[64].flags = v4;
  oam[65].flags = v4;
  oam[66].flags = v4;
  oam[64].charnum = -120;
  oam[65].charnum = -119;
  oam[66].charnum = -104;
  FinishOAMWrite(v3, 0, 2);
}

void Spr020_Magic_01BD98(uint8 k) {  // 01bd98
  uint8 v1 = 3;
  while (smoke_spr_spriteid[v1]) {
    if ((--v1 & 0x80) != 0)
      return;
  }
  smoke_spr_spriteid[v1] = 1;
  smoke_spr_xpos_lo[v1] = spr_xpos_lo[k];
  smoke_spr_ypos_lo[v1] = spr_ypos_lo[k];
  smoke_spr_timer[v1] = 27;
}

void Spr01F_MagiKoopa_Init(uint8 k) {  // 01bdb8
  for (uint8 i = 9; (i & 0x80) == 0; --i) {
    if (i != spr_current_slotid && spr_current_status[i] && spr_spriteid[i] == 31) {
      spr_current_status[k] = 0;
      return;
    }
  }
  timer_disappearing_sprite = 0;
}

void Spr01F_MagiKoopa(uint8 k) {  // 01bdd6
  spr_table15d0[k] = 1;
  if (spr_xoffscreen_flag[k])
    spr_table00c2[k] = 0;
  kSpr01F_MagiKoopa_MagiKoopaPtrs[spr_table00c2[k] & 3](k);
}

void Spr01F_MagiKoopa_State00_FindOpenSpace(uint8 k) {  // 01bdf2
  if (timer_disappearing_sprite) {
    spr_current_status[k] = 0;
  } else if (!flag_sprites_locked) {
    mirror_color_math_select_and_enable = 36;
    if (!spr_decrementing_table1540[k]) {
      uint8 r = GetRand();
      if (r < 0xD1) {
        SetSprYPos(k, (mirror_current_layer1_ypos + r) & ~0xf);
        SetSprXPos(k, (mirror_current_layer1_xpos + GetRand()) & ~0xf);
        CheckPlayerPositionRelativeToSprite_Bank01_X(k);
        if ((uint8)(R15_ + 32) >= 0x40) {
          spr_yspeed[k] = 0;
          spr_xspeed[k] = 1;
          HandleNormalSpriteLevelCollision(k);
          if (CheckNormalSpriteLevelColl_Floor(k)) {
            uint8 v2 = sprites_map16_tile_touched_horiz_hi;
            if (!sprites_map16_tile_touched_horiz_hi) {
              ++spr_table00c2[k];
              spr_table1570[k] = 0;
              Spr01F_MagiKoopa_BE82(k, v2);
              spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
            }
          }
        }
      }
    }
  }
}

void Spr01F_MagiKoopa_State01_FadeIn(uint8 k) {  // 01be5f
  Spr01F_MagiKoopa_01C004(k);
  spr_table1602[k] = 0;
  GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
}

void Spr01F_MagiKoopa_State02_Shoot(uint8 k) {  // 01be6e
  spr_table15d0[k] = 0;
  CheckPlayerAndNormalSpriteCollisions(k);
  spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    Spr01F_MagiKoopa_BE86(k, v1);
  } else {
    ++spr_table00c2[k];
    Spr01F_MagiKoopa_BE82(k, 0);
  }
}

void Spr01F_MagiKoopa_BE82(uint8 k, uint8 a) {  // 01be82
  mirror_color_math_select_and_enable = 52;
  Spr01F_MagiKoopa_BE86(k, a);
}

void Spr01F_MagiKoopa_BE86(uint8 k, uint8 a) {  // 01be86
  if (a == 64) {
    if (!(spr_xoffscreen_flag[k] | flag_sprites_locked))
      Spr01F_MagiKoopa_01BF1D(k);
    a = 64;
  }
  int8 v6 = a >> 6;
  spr_table1602[k] = kSpr01F_MagiKoopa_DATA_01BE69[a >> 6] | ((spr_decrementing_table1540[k] & 8) != 0);
  GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
  if ((uint8)(spr_table1602[k] - 2) >= 2 && (spr_table1602[k] - 2) & 1) {
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    ++oam[64].ypos;
    k = spr_current_slotid;
  }
  if (v6 == 1)
    SpawnSparklesSpriteEntry(k);
  if (spr_table1602[k] >= 4) {
    uint8 v3 = spr_oamindex[k];
    OamEnt *v4 = get_OamEnt(oam_buf, v3);
    v4[66].xpos = kSpr01F_MagiKoopa_WandXDisp[spr_table157c[k]] + spr_xpos_lo[k] - mirror_current_layer1_xpos;
    v4[66].ypos = spr_ypos_lo[k] - mirror_current_layer1_ypos + 16;
    int8 v5 = 0;
    if (!(spr_table157c[k] & 1))
      v5 = 64;
    v4[66].flags = spr_table15f6[k] | sprites_tile_priority | v5;
    v4[66].charnum = -103;
    sprites_oamtile_size_buffer[(v3 >> 2) + 66] = spr_xoffscreen_flag[k];
  }
}

void Spr01F_MagiKoopa_State03_FadeOut(uint8 k) {  // 01bf16
  if (Spr01F_MagiKoopa_01BFE3_ReturnsTwice(k))
    return;
  GenericGFXRtDraw2Tiles16x16sStacked_Sub(k);
}

void Spr01F_MagiKoopa_01BF1D(uint8 k) {  // 01bf1d
  uint8 j = 9;
  while (spr_current_status[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  io_sound_ch1 = 16;
  spr_current_status[j] = 8;
  spr_spriteid[j] = 32;
  SetSprXPos(j, GetSprXPos(k));
  SetSprYPos(j, GetSprYPos(k) + 10);
  InitializeNormalSpriteRAMTables(j);
  AimTowardsPlayer_Bank01(j, 0x20);
  spr_yspeed[j] = R0_;
  spr_xspeed[j] = R1_;
}

void AimTowardsPlayer_Bank01(uint8 k, uint8 a) {  // 01bf6a
  R1_ = a;
  R2_ = CheckPlayerPositionRelativeToSprite_Bank01_Y(k);
  uint8 v2 = R14_;
  if ((R14_ & 0x80) != 0)
    v2 = -R14_;
  R12_ = v2;
  R3_ = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  uint8 v3 = R15_;
  if ((R15_ & 0x80) != 0)
    v3 = -R15_;
  R13_ = v3;
  int8 v4 = 0;
  uint8 v5 = R13_;
  if (R13_ < R12_) {
    v4 = 1;
    R13_ = R12_;
    R12_ = v5;
  }
  R11_ = 0;
  R0_ = 0;
  uint8 v6 = R1_;
  do {
    uint8 v7 = R12_ + R11_;
    if ((uint8)(R12_ + R11_) >= R13_) {
      v7 -= ((uint8)(R12_ + R11_) < R13_) + R13_;
      ++R0_;
    }
    R11_ = v7;
    --v6;
  } while (v6);
  if (v4) {
    uint8 v8 = R0_;
    R0_ = R1_;
    R1_ = v8;
  }
  if (R2_)
    R0_ = -R0_;
  if (R3_)
    R1_ = -R1_;
}

bool Spr01F_MagiKoopa_01BFE3_ReturnsTwice(uint8 k) {  // 01bfe3
  if (!spr_decrementing_table1540[k]) {
    spr_decrementing_table1540[k] = 2;
    if (--spr_table1570[k]) {
      Spr01F_MagiKoopa_01C028(k);
    } else {
      ++spr_table00c2[k];
      spr_decrementing_table1540[k] = 16;
      return true;
    }
  }
  return false;
}

void Spr01F_MagiKoopa_01C004(uint8 k) {  // 01c004
  if (!spr_decrementing_table1540[k]) {
    spr_decrementing_table1540[k] = 4;
    uint8 v1 = ++spr_table1570[k];
    if (v1 == 9)
      mirror_color_math_select_and_enable = 36;
    if (v1 == 9) {
      ++spr_table00c2[k];
      spr_decrementing_table1540[k] = 112;
    } else {
      Spr01F_MagiKoopa_01C028(k);
    }
  }
}

void Spr01F_MagiKoopa_01C028(uint8 k) {  // 01c028
  unsigned int v4;

  uint8 v1 = 16 * (spr_table1570[k] - 1);
  R0_ = 0;
  uint8 v2 = palettes_dynamic_palette_upload_index;
  do {
    palettes_dynamic_palette_colors[v2++] = *((uint8 *)kSpr01F_MagiKoopa_MagiKoopaFadePalettes + v1++);
    ++R0_;
  } while (R0_ != 16);
  uint8 v3 = palettes_dynamic_palette_upload_index;
  v4 = palettes_dynamic_palette_upload_index;
  *(&palettes_dynamic_palette_bytes_to_upload + palettes_dynamic_palette_upload_index) = 16;
  *(&palettes_dynamic_palette_cgramaddress + v4) = -16;
  palettes_dynamic_palette_colors[v3 + 16] = 0;
  palettes_dynamic_palette_upload_index = v3 + 18;
}

void Spr07B_GoalTape_Init_01C062(uint8 k) {  // 01c062
  Spr07B_GoalTape_Init(k);
  AddSprYPos(k, -76);
}

void Spr07B_GoalTape_Init(uint8 k) {  // 01c075
  SetHiLo(&spr_table151c[k], &spr_table00c2[k], GetSprXPos(k) - 8);
  spr_table1528[k] = spr_ypos_lo[k];
  uint8 v2 = spr_ypos_hi[k];
  spr_table187b[k] = v2;
  v2 &= 1;
  spr_ypos_hi[k] = v2;
  spr_table1534[k] = v2;
}

void Spr07B_GoalTape(uint8 k) {  // 01c098
  Spr07B_GoalTape_Draw(k);
  if (!flag_sprites_locked && !spr_table1602[k]) {
    if (!spr_decrementing_table1540[k]) {
      spr_decrementing_table1540[k] = 124;
      ++spr_table1588[k];
    }
    spr_yspeed[k] = kSpr07B_GoalTape_YSpeed[spr_table1588[k] & 1];
    UpdateNormalSpritePosition_Y(k);
    R0_ = spr_table00c2[k];
    R1_ = spr_table151c[k];
    if ((uint16)(player_xpos - R0_W) < 0x10 &&
        (uint8)(spr_table1534[k] & 1) >= (HIBYTE(player_ypos) + (spr_table1528[k] < LOBYTE(player_ypos)))) {
      flag_secret_goal_sprite = spr_table187b[k] >> 2;
      io_music_ch1 = 12;
      misc_music_register_backup = -1;
      timer_end_level = -1;
      timer_star_power = 0;
      ++spr_table1602[k];
      if (CheckPlayerToNormalSpriteCollision(k)) {
        io_sound_ch3 = 9;
        ++spr_table160e[k];
        spr_table1594[k] = spr_table1528[k] - spr_ypos_lo[k];
        spr_decrementing_table1540[k] = 0x80;
        Spr07B_GoalTape_GiveBonusStars(k);
      } else {
        spr_property_bits1686[k] = 0;
      }
      Spr07B_GoalTape_TriggerGoalTape();
    }
  }
}

void Spr07B_GoalTape_Draw(uint8 k) {  // 01c12d
  uint8 drt;

  if (spr_table160e[k]) {
    if (spr_decrementing_table1540[k])
      Spr07B_GoalTape_BonusStarNumbersDraw(k);
    else
      spr_current_status[k] = 0;
  } else {
    if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
      return;
    int8 v2 = R0_ - 8;
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = R0_ - 8;
    v2 += 8;
    oam[65].xpos = v2;
    oam[66].xpos = v2 + 8;
    int8 v4 = R1_ + 8;
    oam[64].ypos = R1_ + 8;
    oam[65].ypos = v4;
    oam[66].ypos = v4;
    oam[64].charnum = -44;
    oam[65].charnum = -43;
    oam[66].charnum = -43;
    oam[64].flags = 50;
    oam[65].flags = 50;
    oam[66].flags = 50;
    FinishOAMWrite(k, 0, 2);
  }
}

void Spr079_VineHead(uint8 k) {  // 01c183
  uint8 v2 = sprites_tile_priority;
  if (spr_decrementing_table1540[k] >= 0x20)
    sprites_tile_priority = 16;
  GenericGFXRtDraw1Tile16x16(k);
  int8 v1 = -84;
  if ((counter_local_frames & 8) != 0)
    v1 = -82;
  get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = v1;
  sprites_tile_priority = v2;
  if (!flag_sprites_locked) {
    spr_yspeed[k] = -16;
    UpdateNormalSpritePosition_Y(k);
    if (spr_decrementing_table1540[k] < 0x20 &&
        ((HandleNormalSpriteLevelCollision(k), spr_table1588[k]) || (spr_ypos_hi[k] & 0x80) != 0)) {
      SubOffscreen_Bank01_EraseSprite(k);
    } else if ((spr_ypos_lo[k] & 0xF) == 0) {
      blocks_xpos = GetSprXPos(k);
      blocks_ypos = GetSprYPos(k);
      blocks_map16_to_generate = 3;
      GenerateTile();
    }
  }
}

void Spr080_Key(uint8 k) {  // 01c1f2
  if (spr_current_status[k] != 12 && !flag_sprites_locked) {
    if (spr_spriteid[k] == 125 && spr_decrementing_table1540[k]) {
      uint8 v6 = sprites_tile_priority;
      sprites_tile_priority = 16;
      PowerUpAndItemDraw(k);
      sprites_tile_priority = v6;
      spr_yspeed[k] = -8;
      UpdateNormalSpritePosition_Y(k);
      return;
    }
    if ((counter_global_frames & 1) == 0) {
      uint8 v1 = spr_table151c[k] & 1;
      uint8 v2 = kSprXXX_FlyingItems_YAcceleration[v1] + spr_yspeed[k];
      spr_yspeed[k] = v2;
      if (v2 == kSprXXX_FlyingItems_MaxYSpeed[v1])
        ++spr_table151c[k];
    }
    spr_xspeed[k] = 12;
    UpdateNormalSpritePosition_X(k);
    uint8 v7 = spr_yspeed[k];
    spr_yspeed[k] = v7 - 2;
    UpdateNormalSpritePosition_Y(k);
    spr_yspeed[k] = v7;
    SubOffscreen_Bank01_Entry1(k);
    ++spr_table1570[k];
  }
  if (spr_spriteid[k] == 125) {
    spr_table157c[k] = 1;
  } else {
    if (spr_table00c2[k] == 2) {
      if ((counter_global_frames & 3) == 0)
        SpawnSparklesSpriteEntry(k);
      spr_table15f6[k] ^= (counter_local_frames >> 1) & 0xE;
    }
    DrawWingTiles(k);
  }
  if (spr_table00c2[k]) {
    if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
      return;
    return;
  }
  PowerUpAndItemDraw(k);
  if (CheckPlayerToNormalSpriteCollision(k) & 1) {
    uint8 v3 = spr_spriteid[k];
    switch (v3) {
    case 0x7E:
      SprXXX_PowerUps_01C4F0(k);
      GiveCoins_MultipleCoins(5);
      GivePoints(k, 3);
LABEL_37:
      spr_current_status[k] = 0;
      return;
    case 0x7F: SprXXX_PowerUps_GiveMario1Up(k); goto LABEL_37;
    case 0x80:
      if ((player_yspeed & 0x80) == 0) {
        spr_current_status[k] = 9;
        player_yspeed = -48;
        spr_yspeed[k] = 0;
        spr_decrementing_table1540[k] = 0;
        spr_property_bits167a[k] &= ~0x80;
      }
      break;
    case 0x7D:
      for (uint8 i = 11; (i & 0x80) == 0; --i) {
        if (spr_current_status[i] == 11 && spr_spriteid[i] != 125)
          spr_current_status[i] = 9;
      }
      uint8 v5 = 0;
      if (!timer_inflate_from_pballoon)
        v5 = 11;
      spr_current_status[k] = v5;
      spr_yspeed[k] = player_yspeed;
      spr_xspeed[k] = player_xspeed;
      timer_inflate_from_pballoon = 9;
      timer_player_has_pballoon = -1;
      io_sound_ch1 = 30;
      break;
    }
  }
}

void SprXXX_PowerUps_ChangingItemEntry(uint8 k) {  // 01c317
  spr_table151c[k] = 1;
  if (!spr_table15d0[k])
    ++spr_table187b[k];
  spr_spriteid[k] = kSprXXX_PowerUps_ChangingItemSprite[(spr_table187b[k] >> 6) & 3];
  InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
  SprXXX_PowerUps_StarEntry(k);
  spr_spriteid[k] = -127;
  InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
}

void SprXXX_PowerUps_FireFlowerEntry(uint8 k) {  // 01c349
  spr_table157c[k] = (uint8)(counter_local_frames & 8) >> 3;
  SprXXX_PowerUps_StarEntry(k);
}

void SprXXX_PowerUps_StarEntry(uint8 k) {  // 01c353
  if (spr_table160e[k]) {
    GenericGFXRtDraw1Tile16x16(k);
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    oam[64].charnum = 0x80;
    oam[64].flags = sprites_tile_priority | kSprXXX_PowerUps_EatenBerryGfxProp[yoshi_berry_being_eaten];
    return;
  }
  uint8 v7 = sprites_tile_priority;
  SprXXX_PowerUps_01C4AC(k);
  if (!spr_table1534[k]) {
    if (spr_decrementing_table1540[k]) {
      HandleNormalSpriteLevelCollision(k);
      if (!spr_table1528[k])
        sprites_tile_priority = 16;
      if (!flag_sprites_locked) {
        spr_yspeed[k] = -4;
        UpdateNormalSpritePosition_Y(k);
      }
    } else if (!flag_sprites_locked && spr_current_status[k] != 12) {
      ++spr_table1570[k];
      SetXSpeedBasedOnNormalSpriteFacingDirection(k);
      uint8 v2 = spr_spriteid[k];
      if (v2 == 117) {
        v2 = spr_table151c[k];
        if (!v2)
          spr_xspeed[k] = 0;
      }
      if (v2 != 118 && v2 != 33 && !spr_table151c[k])
        spr_xspeed[k] *= 2;
      int8 v3 = spr_table00c2[k];
      if (v3) {
        if (v3 >= 0) {
          HandleNormalSpriteLevelCollision(k);
          if (!spr_table1588[k])
            spr_table00c2[k] = 0;
        }
      } else {
        if (misc_nmito_use_flag == 0xC1 || (misc_nmito_use_flag & 0x40) == 0) {
          HandleNormalSpriteGravity(k);
        } else {
          spr_table1588[k] = 0;
          spr_xspeed[k] = 0;
          if (!spr_ypos_hi[k] && spr_ypos_lo[k] >= 0xA0) {
            spr_ypos_lo[k] &= 0xF0;
            spr_table1588[k] |= 4;
            SetXSpeedBasedOnNormalSpriteFacingDirection(k);
          }
          UpdateNormalSpritePosition_X(k);
          UpdateNormalSpritePosition_Y(k);
          spr_yspeed[k] += 3;
        }
        if ((counter_global_frames & 3) != 0)
          --spr_yspeed[k];
      }
      SubOffscreen_Bank01_Entry1(k);
      if (CheckNormalSpriteLevelColl_Ceiling(k))
        spr_yspeed[k] = 0;
      if (CheckNormalSpriteLevelColl_Floor(k)) {
        if (spr_spriteid[k] == 33) {
          SetXSpeedBasedOnNormalSpriteFacingDirection(k);
          uint8 v6 = spr_yspeed[k] + 1;
          SetNormalSpriteYSpeedBasedOnSlope(k);
          uint8 v4 = -(v6 >> 1);
          if (v4 < 0xFC && (spr_table1588[k] & 0x80) == 0)
            spr_yspeed[k] = v4;
        } else {
          SetNormalSpriteYSpeedBasedOnSlope(k);
          if (spr_table151c[k] || spr_spriteid[k] == 118)
            spr_yspeed[k] = -56;
        }
      }
      if (!(spr_table00c2[k] | spr_decrementing_table1558[k]) && CheckNormalSpriteLevelColl_Wall(k))
        ChangeNormalSpriteDirection(k);
    }
    goto LABEL_51;
  }
  if (!flag_sprites_locked) {
    spr_yspeed[k] = 16;
    UpdateNormalSpritePosition_Y(k);
  }
  if ((counter_local_frames & 0xC) != 0) {
LABEL_51:
    if (spr_decrementing_table1540[k] < 0x36) {
      uint8 v5 = spr_table00c2[k];
      if (v5 && v5 != 0xFF || spr_table1632[k])
        sprites_tile_priority = 16;
      PowerUpAndItemDraw(k);
    }
    sprites_tile_priority = v7;
  }
}

void SprXXX_PowerUps_01C4AC(uint8 k) {  // 01c4ac
  if (CheckPlayerToNormalSpriteColl_01A80F(k) & 1 && (!spr_table151c[k] || !spr_table00c2[k]) &&
      !spr_decrementing_table154c[k]) {
    SprXXX_PowerUps_01C4BF(k);
  }
}

void SprXXX_PowerUps_01C4BF(uint8 k) {  // 01c4bf
  if (spr_decrementing_table1540[k] < 0x18) {
    spr_current_status[k] = 0;
    if (spr_spriteid[k] == 33) {
      GiveCoins_OneCoin();
      uint8 v1;
      if ((spr_table15f6[k] & 0xE) == 2) {
        v1 = counter_current_silver_coins++;
        if (v1 >= 0xA)
          v1 = 10;
      } else {
        v1 = 1;
      }
      GivePoints(k, v1);
      SprXXX_PowerUps_01C4F0(k);
    } else {
      SprXXX_PowerUps_01C538(k, spr_spriteid[k]);
    }
  }
}

void SprXXX_PowerUps_01C4F0(uint8 k) {  // 01c4f0
  uint8 v1 = 3;
  while (smoke_spr_spriteid[v1]) {
    if ((--v1 & 0x80) != 0)
      return;
  }
  smoke_spr_spriteid[v1] = 5;
  smoke_spr_xpos_lo[v1] = spr_xpos_lo[k];
  smoke_spr_ypos_lo[v1] = spr_ypos_lo[k];
  smoke_spr_timer[v1] = 16;
}

void SprXXX_PowerUps_01C538(uint8 k, uint8 a) {  // 01c538
  uint8 v2 = player_current_power_up | (4 * (a - 116));
  if (kSprXXX_PowerUps_ItemBoxSprite[v2]) {
    player_current_item_box = kSprXXX_PowerUps_ItemBoxSprite[v2];
    io_sound_ch3 = 11;
  }
  kSprXXX_PowerUps_HandlePowerUpPtrs[kSprXXX_PowerUps_GivePowerPtrIndex[v2]](k);
}

void SprXXX_PowerUps_Return01C560() {  // 01c560
  ;
}

void SprXXX_PowerUps_GiveMarioMushroom(uint8 k) {  // 01c561
  player_current_state = 2;
  player_anim_timer = 47;  // bug fixed!
  flag_sprites_locked = 47;
  SprXXX_PowerUps_01C56F(k);
}

void SprXXX_PowerUps_01C56F(uint8 k) {  // 01c56f
  if (!spr_table1534[k])
    GivePoints(k, 4);
  io_sound_ch1 = 10;
}

void GivePlayerStarPower() {  // 01c580
  timer_star_power = -1;
  io_music_ch1 = 13;
  misc_music_register_backup |= 0x80;
}

void SprXXX_PowerUps_GiveMarioStar(uint8 k) {  // 01c592
  GivePlayerStarPower();
  SprXXX_PowerUps_01C56F(k);
}

void SprXXX_PowerUps_GiveMarioCape(uint8 k) {  // 01c598
  player_current_power_up = 2;
  io_sound_ch1 = 13;
  GivePoints(k, 4);
  SprXXX_PowerUps_01C5AE();
  ++flag_sprites_locked;
}

void SprXXX_PowerUps_01C5AE() {  // 01c5ae
  if (!(HIBYTE(player_on_screen_pos_x) | HIBYTE(player_on_screen_pos_y))) {
    player_current_state = 3;
    player_anim_timer = 24;
    uint8 v0 = 3;
    while (smoke_spr_spriteid[v0]) {
      if ((--v0 & 0x80) != 0) {
        if ((--smoke_spr_slot_to_overwrite_when_slots_full & 0x80) != 0)
          smoke_spr_slot_to_overwrite_when_slots_full = 3;
        v0 = smoke_spr_slot_to_overwrite_when_slots_full;
        break;
      }
    }
    smoke_spr_spriteid[v0] = -127;
    smoke_spr_timer[v0] = 27;
    smoke_spr_ypos_lo[v0] = player_ypos + 8;
    smoke_spr_xpos_lo[v0] = player_xpos;
  }
}

void SprXXX_PowerUps_GiveMarioFire(uint8 k) {  // 01c5ec
  timer_player_palette_cycle = 32;
  flag_sprites_locked = 32;
  player_current_state = 4;
  player_current_power_up = 3;
  SprXXX_PowerUps_01C56F(k);
}

void SprXXX_PowerUps_GiveMario1Up(uint8 k) {  // 01c5fe
  GivePoints(k, spr_table1594[k] + 8);
}

void PowerUpAndItemDraw(uint8 k) {  // 01c61a
  uint8 drt;
  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  R10_ = 0;
  if (!flag_reznor_room_oamindex_timer && misc_nmito_use_flag != 0xC1 && (misc_nmito_use_flag & 0x40) != 0) {
    spr_oamindex[k] = 0xD8;
    drt = 0xD8;
  }
  if (spr_spriteid[k] == 33) {
    PowerUpAndItemGFXRt_DrawCoinSprite(k);
  } else {
    if (spr_spriteid[k] == 118)
      R10_ = kPowerUpAndItemGFXRt_StarPalValues[(counter_global_frames >> 1) & 3];
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = R0_;
    oam[64].ypos = R1_ - 1;
    int8 v3 = 0;
    if (!(spr_table157c[k] & 1))
      v3 = 64;
    oam[64].flags = R10_ ^ (spr_table15f6[k] | sprites_tile_priority | v3);
    oam[64].charnum = kPowerUpAndItemGFXRt_PowerUpTiles[(uint8)(spr_spriteid[k] - 116)];
    NormalSpritePlatformGFXRt_01B37E(spr_current_slotid, 0);
  }
}

void PowerUpAndItemGFXRt_DrawCoinSprite(uint8 k) {  // 01c645
  uint8 drt;
  uint8 v3;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  OamEnt *oam = get_OamEnt(oam_buf, drt);
  oam[64].xpos = R0_;
  oam[64].ypos = R1_;
  oam[64].charnum = -24;
  oam[64].flags = sprites_tile_priority | spr_table15f6[k];
  if ((((uint8)(counter_local_frames + k) >> 2) & 3) != 0) {
    uint8 ka = k;
    uint8 v4 = ((uint8)(counter_local_frames + k) >> 2) & 3;
    int8 v5 = R0_ + 4;
    OamEnt *v6 = get_OamEnt(oam_buf, drt);
    v6[64].xpos = R0_ + 4;
    v6[65].xpos = v5;
    v6[65].ypos = R1_ + 8;
    uint8 v7 = kPowerUpAndItemGFXRt_DrawCoinSprite_Tiles[v4 - 1];
    v6[64].charnum = v7;
    v6[65].charnum = v7;
    v6[65].flags = v6[64].flags | 0x80;
    k = ka;
    v3 = 0;
  } else {
    v3 = 2;
  }
  FinishOAMWrite(k, v3, 1);
}

void Spr077_Feather(uint8 k) {  // 01c6ed
  if (!flag_sprites_locked) {
    if (spr_table00c2[k]) {
      HandleNormalSpriteLevelCollision(k);
      if (!spr_table1588[k])
        spr_table00c2[k] = 0;
LABEL_14:
      SetFacingDirectionBasedOnSpeed(k);
      goto LABEL_15;
    }
    if (spr_current_status[k] != 12) {
      if (spr_decrementing_table154c[k]) {
        UpdateNormalSpritePosition_Y(k);
        ++spr_yspeed[k];
      } else {
        uint8 v1 = spr_table1528[k] & 1;
        uint8 v2 = kSpr077_Feather_XAccelerarion[v1] + spr_xspeed[k];
        spr_xspeed[k] = v2;
        if (v2 == kSpr077_Feather_MaxXSpeed[v1])
          ++spr_table1528[k];
        if ((spr_xspeed[k] & 0x80) != 0)
          ++v1;
        spr_yspeed[k] = kSpr077_Feather_YSpeed[v1] + 6;
        SubOffscreen_Bank01_Entry1(k);
        UpdateNormalSpritePosition_X(k);
        UpdateNormalSpritePosition_Y(k);
      }
      goto LABEL_14;
    }
  }
LABEL_15:
  SprXXX_PowerUps_01C4AC(k);
  PowerUpAndItemDraw(k);
}

void Spr05F_BrownChainedPlatform_Init(uint8 k) {  // 01c74a
  spr_table151c[k] = 0x80;
  spr_table1528[k] = 1;
  AddSprXYPos(k, 120, 104);
}

void Spr05F_BrownChainedPlatform(uint8 k) {  // 01c773
  SubOffscreen_Bank01_Entry3(k);
  if (!flag_sprites_locked && !(spr_table1602[k] | counter_global_frames & 3)) {
    int8 v1 = 1;
    int8 v2 = spr_table1504[k];
    if (v2) {
      if (v2 >= 0)
        v1 = -1;
      spr_table1504[k] += v1;
    }
  }
  uint8 v24 = spr_table151c[k];
  uint8 v23 = spr_table1528[k];
  spr_table151c[k] = -v24;
  spr_table1528[k] = (2 - ((v24 != 0) + spr_table1528[k])) & 1;
  Spr05F_BrownChainedPlatform_01CACB(k);
  GetSineAndCosineOfTiltingPlatform();
  CalculateCircleCoordinatesForTiltingPlaform();
  spr_table1528[k] = v23;
  spr_table151c[k] = v24;
  sprites_position_disp = temp14b8 - spr_table00c2[k];
  spr_table00c2[k] = temp14b8;
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].ypos = temp14ba - mirror_current_layer1_ypos - 8;
  oam[64].xpos = temp14b8 - mirror_current_layer1_xpos - 8;
  oam[64].charnum = -94;
  oam[64].flags = 49;
  uint8 v4 = 0;
  uint8 v5 = temp14ba - temp14b2;
  if ((int8)(temp14ba - temp14b2) < 0) {
    v5 = temp14b2 - temp14ba;
    v4 = 1;
  }
  R0_ = v4;
  WriteReg(WRDIVH, v5);
  WriteReg(WRDIVL, 0);
  WriteReg(WRDIVB, 5);
  R2_ = ReadReg(RDDIVL);
  R6_ = R2_;
  R3_ = ReadReg(RDDIVH);
  R7_ = R3_;
  uint8 v6 = 0;
  uint8 v7 = temp14b8 - temp14b0;
  if ((int8)(temp14b8 - temp14b0) < 0) {
    v7 = temp14b0 - temp14b8;
    v6 = 1;
  }
  R1_ = v6;
  WriteReg(WRDIVH, v7);
  WriteReg(WRDIVL, 0);
  WriteReg(WRDIVB, 5);
  R4_ = ReadReg(RDDIVL);
  R8_ = R4_;
  R5_ = ReadReg(RDDIVH);
  R9_ = R5_;
  uint8 v8 = spr_oamindex[k] + 4;
  R10_ = temp14b2 - mirror_current_layer1_ypos - 8;
  OamEnt *v9 = get_OamEnt(oam_buf, v8);
  v9[64].ypos = temp14b2 - mirror_current_layer1_ypos - 8;
  R11_ = temp14b0 - mirror_current_layer1_xpos - 8;
  v9[64].xpos = R11_;
  v9[64].charnum = -94;
  v9[64].flags = 49;
  for (int8 i = 3; i >= 0; --i) {
    v8 += 4;
    OamEnt *v12 = get_OamEnt(oam_buf, v8);
    if (R0_)
      v12[64].ypos = R10_ - R7_;
    else
      v12[64].ypos = R7_ + R10_;
    R6_W += R2_W;
    if (R1_)
      v12[64].xpos = R11_ - R9_;
    else
      v12[64].xpos = R9_ + R11_;
    R8_W += R4_W;
    v12[64].charnum = -94;
    v12[64].flags = 49;
  }
  for (uint8 j = 3; (j & 0x80) == 0; --j) {
    R2_ = j;
    v8 += 4;
    OamEnt *v14 = get_OamEnt(oam_buf, v8);
    v14[64].ypos = temp14ba - mirror_current_layer1_ypos - 16;
    v14[64].xpos = kSpr05F_BrownChainedPlatform_PlatformXDisp[j] + temp14b8 - mirror_current_layer1_xpos;
    v14[64].charnum = kSpr05F_BrownChainedPlatform_PlatformTiles[j];
    v14[64].flags = 49;
  }
  R8_ = 9;
  R0_ = temp14b2 - 8;
  R1_ = temp14b3 - (temp14b2 < 8);
  R2_ = temp14b0 - 8;
  R3_ = temp14b1 - (temp14b0 < 8);
  uint8 v15 = spr_oamindex[spr_current_slotid];
  OamEnt *v16 = get_OamEnt(oam_buf, v15);
  R6_ = v16[65].ypos;
  R7_ = v16[65].xpos;
  do {
    sprites_oamtile_size_buffer[(v15 >> 2) + 64] = 2;
    int8 v17 = 0;
    OamEnt *v18 = get_OamEnt(oam_buf, v15);
    int8 v19 = v18[64].xpos - R7_;
    R4_W = R2_W + (int8)v19;
    if (FinishOAMWrite_01B844() & 1)
      sprites_oamtile_size_buffer[(v15 >> 2) + 64] = 3;
    int8 v21 = v18[64].ypos - R6_;
    R9_W = R0_W + (int8)v21;
    if (Spr05F_BrownChainedPlatform_01C9BF() & 1)
      v18[64].ypos = -16;
    if (R8_ == 9) {
      temp14b8 = R4_;
      temp14b9 = R5_;
      temp14ba = R9_;
      temp14bb = R10_;
    }
    v15 += 4;
    --R8_;
  } while ((R8_ & 0x80) == 0);
  uint8 v22 = spr_current_slotid;
  get_OamEnt(oam_buf, spr_oamindex[spr_current_slotid])[65].ypos = -16;
  if (!flag_sprites_locked) {
    Spr05F_BrownChainedPlatform_UpdateAngle(v22);
    sub_1C9EC(v22);
  }
}

uint8 Spr05F_BrownChainedPlatform_01C9BF() {  // 01c9bf
  return (uint16)(*(uint16 *)&R9_ + 16 - mirror_current_layer1_ypos) >= 0x100;
}

void sub_1C9DA(uint8 k) {  // 01c9da
  if (spr_table160e[k]) {
    spr_table160e[k] = 0;
    Spr05F_BrownChainedPlatform_01C9E2(k);
  }
}

void Spr05F_BrownChainedPlatform_01C9E2(uint8 k) {  // 01c9e2
  PlayerDraw();
  spr_current_slotid = k;
}

void sub_1C9EC(uint8 k) {  // 01c9ec
  uint16 t = __PAIR16__(temp14b9, temp14b8) - mirror_current_layer1_xpos + 16;
  uint8 v1 = flag_sprites_locked | (t >= 0x120);
  spr_table15c4[k] = v1;
  if (!v1) {
    uint8 v2 = Spr05F_BrownChainedPlatform_01CA9C(k);
    spr_table1602[k] = 0;
    if (v2 & 1) {
      spr_table160e[k] = 1;
      R3_ = temp14ba - mirror_current_layer1_ypos;
      R14_ = temp14ba - mirror_current_layer1_ypos - 8;
      if ((uint8)(player_on_screen_pos_y + 24) < R14_) {
        if ((player_yspeed & 0x80) == 0) {
          player_yspeed = 0;
          misc_player_on_solid_sprite = 3;
          spr_table1602[k] = 3;
          R15_ = player_riding_yoshi_flag ? 56 : 40;
          player_ypos = WORD(temp14ba) - R15_;
          if ((player_blocked_flags & 3) == 0)
            player_xpos += (int8)sprites_position_disp;
          Spr05F_BrownChainedPlatform_01C9E2(k);
          if ((io_controller_press1 & 0x80) == 0)
            player_hide_player_tile_flags = -1;
          if (counter_global_frames & 1) {
            uint8 v6 = (PAIR16(spr_table1528[k], spr_table151c[k]) + 0x80) >> 8 & 1;
            uint8 v7 = spr_table1504[k];
            if (v7 != kSpr05F_BrownChainedPlatform_DATA_01C9D8[v6])
              spr_table1504[k] = kSpr05F_BrownChainedPlatform_DATA_01C9D6[v6] + v7;
          }
        } else {
          Spr05F_BrownChainedPlatform_01C9E2(k);
        }
      }
    } else {
      sub_1C9DA(k);
    }
  }
}

uint8 Spr05F_BrownChainedPlatform_01CA9C(uint8 k) {  // 01ca9c
  SetHiLo(&R10_, &R4_, WORD(temp14b8) - 24);
  R6_ = 64;
  SetHiLo(&R11_, &R5_, WORD(temp14ba) - 12);
  R7_ = 19;
  StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
  return StandardSpriteToSpriteCollisionChecks_CheckContact();
}

void Spr05F_BrownChainedPlatform_01CACB(uint8 k) {  // 01cacb
  temp14bc = 80;
  temp14bf = 0;
  misc_rotating_object_xradius_hi = 0;
  temp14c0 = 0;
  WORD(temp14b4) = GetSprXPos(k);
  WORD(temp14b0) = WORD(temp14b4) - 80;
  WORD(temp14b6) = GetSprYPos(k);
  WORD(temp14b2) = WORD(temp14b6);
  misc_m7_rotation = PAIR16(spr_table1528[k], spr_table151c[k]);
}

void GetSineAndCosineOfTiltingPlatform() {  // 01cb20
  sprites_brown_roating_platform_angle_sign1 = HIBYTE(misc_m7_rotation);
  sprites_brown_rotating_platform_sine = kCircleCoordinates[(uint16)((2 * misc_m7_rotation) & 0x1FF) >> 1];
  R0_W = misc_m7_rotation + 128;
  sprites_brown_rotating_platform_cosine = kCircleCoordinates[(uint16)((2 * (misc_m7_rotation + 128)) & 0x1FF) >> 1];
  sprites_brown_roating_platform_angle_sign2 = R1_;
}

void CalculateCircleCoordinatesForTiltingPlaform() {  // 01cb53
  unsigned int v5;
  unsigned int v10;

  R2_W = sprites_brown_rotating_platform_cosine;
  R0_W = *(uint16 *)&temp14bc;
  CalculateCircleCoordinatesForTiltingPlaform_01CC28();
  bool sign = sprites_brown_roating_platform_angle_sign2 & 1;
  uint16 v0 = R4_W;
  if (sign)
    v0 = -v0;
  R8_W = v0;
  uint16 v1 = R6_W;
  if (sign)
    v1 = -v1;
  R10_W = v1;
  R2_W = sprites_brown_rotating_platform_sine;
  R0_W = *(uint16 *)&temp14bf;
  CalculateCircleCoordinatesForTiltingPlaform_01CC28();
  sign = sprites_brown_roating_platform_angle_sign1 & 1;
  uint16 v2 = R4_W;
  if (sign)
    v2 = -v2;
  R4_W = v2;
  uint16 v3 = R6_W;
  if (sign)
    v3 = -v3;
  v5 = __PAIR32__(R10_W, R8_W) + __PAIR32__(v3, R4_W);
  R4_W = v5;
  R6_W = v5 >> 16;
  *(uint16 *)&temp14b8 = *(uint16 *)&temp14b0 + *(uint16 *)&R5_;
  R2_W = sprites_brown_rotating_platform_cosine;
  R0_W = *(uint16 *)&temp14bf;
  CalculateCircleCoordinatesForTiltingPlaform_01CC28();
  sign = sprites_brown_roating_platform_angle_sign2 & 1;
  uint16 v6 = R4_W;
  if (sign)
    v6 = -v6;
  R8_W = v6;
  uint16 v7 = R6_W;
  if (sign)
    v7 = -v7;
  R10_W = v7;
  R2_W = sprites_brown_rotating_platform_sine;
  R0_W = *(uint16 *)&temp14bc;
  CalculateCircleCoordinatesForTiltingPlaform_01CC28();
  sign = sprites_brown_roating_platform_angle_sign1 & 1;
  uint16 v8 = R4_W;
  if (sign)
    v8 = -v8;
  R4_W = v8;
  uint16 v9 = R6_W;
  if (sign)
    v9 = -v9;
  v10 = __PAIR32__(v9, R4_W) - __PAIR32__(R10_W, R8_W);
  R6_W = HIWORD(v10);
  R4_W = v10;
  *(uint16 *)&temp14ba = *(uint16 *)&temp14b2 - *(uint16 *)&R5_;
}

void CalculateCircleCoordinatesForTiltingPlaform_01CC28() {  // 01cc28
  WriteReg(WRMPYA, R0_);
  WriteReg(WRMPYB, R2_);
  R4_ = ReadReg(RDMPYL);
  R5_ = ReadReg(RDMPYH);

  WriteReg(WRMPYA, R0_);
  WriteReg(WRMPYB, R3_);
  uint16 t = R5_ + ReadReg(RDMPYL);
  R5_ = t;
  R6_ = (t >> 8) + ReadReg(RDMPYH);

  WriteReg(WRMPYA, R1_);
  WriteReg(WRMPYB, R2_);
  t = R5_ + ReadReg(RDMPYL);
  R5_ = t;
  R6_ += (t >> 8) + ReadReg(RDMPYH);

  WriteReg(WRMPYA, R1_);
  WriteReg(WRMPYB, R3_);
  t = R6_ + ReadReg(RDMPYL);
  R6_ = t;
  R7_ = (t >> 8) + ReadReg(RDMPYH);
}

uint8 CheckTiltingPlatformCollision() {  // 01cc9d
  if (temp14b7 | temp14b5)
    return 0;
  CheckTiltingPlatformColl_01CCC7();
  GetSineAndCosineOfTiltingPlatform();
  CalculateCircleCoordinatesForTiltingPlaform();
  R0_ = temp14ba & 0xF0;
  return sprites_cutscene_sprite_table_0AF6[temp14ba & 0xF0 | (temp14b8 >> 4)] >= 0x15;
}

void CheckTiltingPlatformColl_01CCC7() {  // 01ccc7
  *(uint16 *)&temp14b0 = mirror_m7_center_xpos;
  *(uint16 *)&temp14b2 = mirror_m7_center_ypos;
  *(uint16 *)&temp14bc = *(uint16 *)&temp14b4 - mirror_m7_center_xpos;
  *(uint16 *)&temp14bf = *(uint16 *)&temp14b6 - mirror_m7_center_ypos;
}

void CheckTiltingPlatformColl_Return01CCEA() {  // 01ccea
  ;
}

void CheckTiltingPlatformColl_Return01CCEB() {  // 01cceb
  ;
}

void Spr05F_BrownChainedPlatform_UpdateAngle(uint8 k) {  // 01ccf0
  uint16 t = spr_table1510[k] + (uint8)(16 * spr_table1504[k]);
  spr_table1510[k] = t;
  int8 spd = (int8)spr_table1504[k] >> 4;
  uint16 pos = PAIR16(spr_table1528[k], spr_table151c[k]) + spd + (t >> 8);
  spr_table151c[k] = pos;
  spr_table1528[k] = pos >> 8;
}

void Spr029_KoopaKids_Init(uint8 k) {  // 01cd2f
  uint8 v1 = spr_ypos_lo[k] >> 4;
  spr_table00c2[k] = v1;
  if (v1 < 5) {
    spr_ypos_lo[k] = -112;
    if (v1 < 3) {
      spr_table157c[k] = 1;
      misc_m7_angle = 0x2020;
      InitializeMode7TilemapsAndPalettes(k);
      uint8 v2 = kSpr029_KoopaKids_Init_DATA_01CD92[spr_table00c2[k]];
      spr_table187b[k] = v2;
      if (v2 == 1) {
        spr_table1534[k] = 38;
        spr_table160e[k] = -40;
      } else {
        if (!v2)
          spr_xpos_lo[k] = 112;
        spr_xpos_hi[k] = 1;
      }
    } else {
      Spr029_KoopaKids_Init_SetPosition(k);
      SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
    }
  } else {
    spr_xpos_lo[k] = 120;
    SetSprYPos(k, 0x140);
    spr_decrementing_table1540[k] = 0x80;
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_GetDrawInfo(uint8 k) {  // 01cda7
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
}

void Spr029_KoopaKid_MortonRoyLudwig(uint8 k) {  // 01cdab
  player_freeze_player_flag = 0;
  uint8 v1 = spr_table1602[k];
  if (v1 < 0x1B) {
    uint8 v2 = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01CDA5[spr_table157c[k]];
    if (spr_decrementing_table15ac[k] < 8)
      v2 ^= 0x80;
    R0_ = v2;
    v1 = v2 + kSpr029_KoopaKid_MortonRoyLudwig_DATA_01CD9C[spr_table1602[k]] +
         kSpr029_KoopaKid_MortonRoyLudwig_DATA_01CD99[spr_table00c2[k]];
  }
  misc_mode7_tilemap_index = v1;
  UpdateMode7SpriteAnimations(k);
  Spr029_KoopaKid_MortonRoyLudwig_GetDrawInfo(k);
  if (!flag_sprites_locked) {
    Spr029_KoopaKid_MortonRoyLudwig_01D2A8(k);
    Spr029_KoopaKid_MortonRoyLudwig_01D3B1(k);
    if (spr_table187b[k] != 1 && !spr_decrementing_table163e[k]) {
      uint8 v3 = spr_table157c[k];
      spr_table157c[k] = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
      if (v3 != spr_table157c[k])
        spr_decrementing_table15ac[k] = 16;
    }
    kSpr029_KoopaKid_MortonRoyLudwig_StatePtrs[spr_table151c[k]](k);
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_01CE1E(uint8 k) {  // 01ce1e
  if (spr_table187b[k] == 1) {
    flag_layer1_horiz_scroll_level_setting = 0;
    ++sprites_morton_and_roy_left_pillar_status;
    sprites_morton_and_roy_left_pillar_yposition = 0;
    ++flag_sprites_locked;
    ++spr_table151c[k];
  } else if ((uint8)mirror_current_layer1_xpos >= 0x7E) {
    ++spr_table151c[k];
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_01CE3E(uint8 k) {  // 01ce3e
  player_xspeed = 0;
  UpdateNormalSpritePosition_Y(k);
  uint8 v1 = spr_yspeed[k];
  if (sign8(v1 - 64))
    v1 += 3;
  spr_yspeed[k] = v1;
  if (Spr029_KoopaKid_MortonRoyLudwig_01D0C0(k) & 1) {
    ++spr_table151c[k];
    if (spr_table00c2[k] >= 2)
      spr_decrementing_table1540[k] = -1;
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_State02(uint8 k) {  // 01ce5f
  kSpr029_KoopaKid_MortonRoyLudwig_AttackRoutinePtrs[spr_table00c2[k]](k);
}

void Spr029_KoopaKid_MortonRoyLudwig_ProcessLudwigsAttacks(uint8 k) {  // 01ce6b
  uint8 v5;

  uint8 v1 = spr_table1528[k];
  if (v1) {
    if (v1 == 1) {
      if (spr_decrementing_table1540[k] || (v5 = CheckPlayerPositionRelativeToSprite_Bank01_X(k), v5 != spr_xpos_hi[k])) {
        uint8 v6 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
        if (spr_xspeed[k] != kSpr029_KoopaKid_MortonRoyLudwig_LudwigMaxXSpeed[v6])
          spr_xspeed[k] += kSprXXX_ParachutingEnemy_DATA_01D4E7[v6];
        UpdateNormalSpritePosition_X(k);
        spr_table1602[k] = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01CEB0[(counter_local_frames >> 2) & 3];
      } else {
        ++spr_table1528[k];
        spr_table160e[k] = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01CEB4[v5];
        spr_decrementing_table1540[k] = 48;
        spr_decrementing_table1558[k] = 96;
        spr_yspeed[k] = -40;
      }
    } else {
      if (v1 != 2) {
        Unreachable();
        return;
      }
      uint8 v8 = spr_decrementing_table1540[k];
      if (v8) {
        if (v8 == 1) {
          spr_xspeed[k] = spr_table160e[k];
          io_sound_ch3 = 8;
        }
        int8 v9 = spr_xspeed[k];
        if (v9) {
          spr_xspeed[k] += (v9 < 0) ? 1 : -1;
        }
        return;
      }
      if (Spr029_KoopaKid_MortonRoyLudwig_01D0C0(k) && (spr_yspeed[k] & 0x80) == 0) {
        spr_xspeed[k] = spr_yspeed[k] = 0;
        spr_table1528[k] = 0;
        goto LABEL_14;
      }
      UpdateNormalSpritePosition_X(k);
      UpdateNormalSpritePosition_Y(k);
      if (!(counter_global_frames & 1) && (int8)spr_yspeed[k] <= 111)
        ++spr_yspeed[k];
      if (spr_decrementing_table1558[k] || misc_m7_rotation) {
        int8 v10 = __CFSHL__(spr_xspeed[k], 1) ? -4 : 4;
        misc_m7_rotation = (misc_m7_rotation + v10) & 0x1ff;
      }
      uint8 v13 = 6;
      if ((int8)spr_yspeed[k] >= 8) {
        v13 = 5;
        if (spr_yspeed[k] >= 0x10)
          v13 = 2;
      }
      spr_table1602[k] = v13;
    }
  } else {
    misc_m7_rotation = 0;
    uint8 v2 = spr_decrementing_table1540[k];
    if (!v2) {
      ++spr_table1528[k];
LABEL_14:
      spr_decrementing_table1540[k] = -1;
      return;
    }
    int8 v3 = 3;
    if ((v2 & 0x30) == 0)
      v3 = 4;
    uint8 v4 = v3;
    if (spr_decrementing_table15ac[k])
      v4 = 5;
    spr_table1602[k] = v4;
    if ((spr_decrementing_table1540[k] & 0x3F) == 46) {
      spr_decrementing_table163e[k] = 48;
      Spr029_KoopaKid_MortonRoyLudwig_01D059(k);
    }
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_State03_Hurt(uint8 k) {  // 01cf7d
  UpdateNormalSpritePosition_Y(k);
  ++spr_yspeed[k];
  Spr029_KoopaKid_MortonRoyLudwig_01D0C0(k);
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 < 0x40) {
      if ((uint8)misc_m7_angle != 32)
        LOBYTE(misc_m7_angle) = misc_m7_angle + 1;
      if (HIBYTE(misc_m7_angle) != 32)
        --HIBYTE(misc_m7_angle);
      spr_table1602[k] = 7;
    } else if (v1 == 64) {
      if (++spr_table1626[k] >= 3)
        Spr029_KoopaKid_MortonRoyLudwig_01CFD0(k);
    } else {
      spr_table1602[k] = (counter_local_frames & 4) != 0 ? 7 : 6;
    }
  } else {
    spr_table151c[k] = 2;
    if (spr_table00c2[k])
      spr_table164a[k] = 32;
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_01CFD0(uint8 k) {  // 01cfd0
  io_sound_ch1 = 31;
  spr_table151c[k] = 4;
  spr_decrementing_table1540[k] = 19;
}

void Spr029_KoopaKid_MortonRoyLudwig_State04_Dying(uint8 k) {  // 01cfe0
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    AddSprYPos(k, -1);
    --HIBYTE(misc_m7_angle);
    if ((v1 & 3) != 0)
      LOBYTE(misc_m7_angle) = misc_m7_angle - 1;
  } else {
    misc_m7_rotation = (misc_m7_rotation + 6) & 0x1ff;
    LOBYTE(misc_m7_angle) = misc_m7_angle + 1;
    ++HIBYTE(misc_m7_angle);
  }
  if (HIBYTE(misc_m7_angle) >= 0xA0) {
    if (!spr_xoffscreen_flag[k]) {
      smoke_spr_spriteid[0] = 1;
      smoke_spr_xpos_lo[0] = spr_xpos_lo[k] - 8;
      smoke_spr_ypos_lo[0] = spr_ypos_lo[k] + 8;
      smoke_spr_timer[0] = 27;
    }
    spr_ypos_lo[k] = -48;
    UpdateMode7SpriteAnimations(k);
    ++spr_table151c[k];
    spr_decrementing_table1540[k] = 48;
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_State05_ActivateLevelEnd(uint8 k) {  // 01d043
  if (!spr_decrementing_table1540[k]) {
    ++misc_currently_active_boss_end_cutscene;
    --timer_end_level;
    io_music_ch1 = 11;
    spr_current_status[k] = 0;
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_01D059(uint8 k) {  // 01d059
  io_sound_ch3 = 23;
  uint8 j = 4;
  while (spr_current_status[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  spr_current_status[j] = 8;
  spr_spriteid[j] = 52;
  SetSprYPos(j, GetSprYPos(k) + 3);
  SetSprXPos(j, GetSprXPos(k) + (int8)kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D057[spr_table157c[k]]);
  InitializeNormalSpriteRAMTables(j);
  spr_table157c[j] = spr_table157c[k];
  spr_xspeed[j] = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D0BE[spr_table157c[j]];
  spr_decrementing_table1540[j] = 48;
}

uint8 Spr029_KoopaKid_MortonRoyLudwig_01D0C0(uint8 k) {  // 01d0c0
  if ((spr_yspeed[k] & 0x80) != 0 || spr_ypos_hi[k])
    return 0;
  uint8 t = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D0DE[(HIBYTE(misc_m7_angle) >> 1) - 8];
  if (spr_ypos_lo[k] < t)
    return 0;
  spr_ypos_lo[k] = t;
  spr_yspeed[k] = 0;
  return 1;
}

void Spr029_KoopaKid_MortonRoyLudwig_ProcessRoysAttacks(uint8 k) {  // 01d116
  uint8 v1 = spr_table1528[k];
  if (v1) {
    if (v1 == 1) {
      uint8 v14 = spr_decrementing_table1540[k];
      if (v14) {
        if (v14 == 1) {
          spr_table1528[k] = 0;
          uint8 v15 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
          spr_table157c[k] = v15;
          spr_table1594[k] = (2 * v15) ^ 2;
          spr_decrementing_table15ac[k] = 10;
        }
      } else {
        spr_table1602[k] = 6;
        UpdateNormalSpritePosition_Y(k);
        if (spr_yspeed[k] < 0x70)
          spr_yspeed[k] += 4;
        if (misc_m7_rotation)
          misc_m7_rotation = (misc_m7_rotation + 8) & 0x1ff;
        if (Spr029_KoopaKid_MortonRoyLudwig_01D0C0(k)) {
          timer_shake_layer1 = 32;
          if (!player_in_air_flag)
            timer_stun_player = 40;
          io_sound_ch3 = 9;
          spr_decrementing_table1540[k] = 40;
          misc_m7_rotation = 0;
        }
      }
    } else {
      Unreachable();
    }
    return;
  }
  int8 v2 = counter_local_frames >> 1;
  if (spr_table1626[k] < 2)
    v2 = counter_local_frames >> 2;
  uint8 v3 = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D142[v2 & 3];
  if (spr_decrementing_table15ac[k])
    v3 = 5;
  spr_table1602[k] = v3;
  uint8 v4 = spr_table164a[k];
  if (v4) {
    if ((int8)spr_xpos_lo[k] >= 80) {
      --spr_table164a[k];
      if (!(v4 & 1)) {
        ++spr_table1534[k];
        --spr_table160e[k];
      }
    }
  }
  R5_ = spr_table1534[k];
  R6_ = R5_;
  R11_ = R5_;
  R12_ = R5_;
  R7_ = spr_table160e[k];
  R8_ = R7_;
  R9_ = R7_;
  R10_ = R7_;
  if ((uint8)(2 * misc_m7_rotation)) {
LABEL_34:;
    uint8 v12 = spr_table157c[k];
    misc_m7_rotation = (misc_m7_rotation + PAIR16(kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D23B[v12], kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D239[v12])) & 0x1ff;
    return;
  }
  uint8 v5 = spr_table1594[k];
  if (!(v5 & 1)) {
    uint8 v6 = spr_xpos_lo[k];
    if (v5) {
      if (v6 < spr_table160e[k])
        goto LABEL_25;
    } else if (v6 >= spr_table1534[k]) {
      goto LABEL_25;
    }
    goto LABEL_33;
  }
  if (!spr_table157c[k])
    v5 += 4;
  spr_xpos_lo[k] = *(&R5_ + v5);
  uint8 v7 = spr_table1594[k];
  uint8 v8 = spr_ypos_lo[k];
  if (v7 != 3) {
    if (v8 >= kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D13E[v7])
      goto LABEL_25;
    goto LABEL_33;
  }
  if (v8 >= kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D13E[3]) {
LABEL_33:
    spr_table1594[k] = (kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D23D[spr_table157c[k]] + spr_table1594[k]) & 3;
    goto LABEL_34;
  }
LABEL_25:;
  uint8 v9 = spr_table1626[k];
  if (v9 >= 2)
    v9 = 2;
  uint8 v10 = spr_table1594[k] + 4 * v9;
  spr_xspeed[k] = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D122[v10];
  spr_yspeed[k] = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D12E[v10];
  UpdateNormalSpritePosition_X(k);
  UpdateNormalSpritePosition_Y(k);
  uint8 v11 = spr_table1594[k];
  if (!spr_table157c[k])
    v11 ^= 2;
  if (v11 == 2) {
    CheckPlayerPositionRelativeToSprite_Bank01_X(k);
    if ((uint8)(R15_ + 16) < 0x20)
      ++spr_table1528[k];
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_01D2A8(uint8 k) {  // 01d2a8
  if (spr_table151c[k] < 3 && (spr_table187b[k] != 3 || spr_table1528[k] < 3)) {
    StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
    Spr029_KoopaKid_MortonRoyLudwig_01D40B(k);
    if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
      if (!spr_decrementing_table1fe2[k]) {
        spr_decrementing_table1fe2[k] = 8;
        if (player_in_air_flag) {
          if (spr_table1602[k] < 0x10 && spr_table1602[k] >= 6 || (uint8)(player_ypos + 8) >= spr_ypos_lo[k]) {
            sub_1D31E(k);
          } else if (spr_table1594[k] & 1) {
            sub_1D334(k);
          } else if ((player_yspeed & 0x80) == 0) {
            Spr029_KoopaKid_MortonRoyLudwig_01D351(k);
            player_yspeed = -48;
            io_sound_ch1 = 2;
            if (spr_table1602[k] < 0x1B) {
              uint8 v1 = HIBYTE(misc_m7_angle) >> 1;
              misc_m7_angle = 0x2818;
              uint8 v2 = kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D0DE[12] - kSpr029_KoopaKid_MortonRoyLudwig_DATA_01D0DE[v1 - 8];
              AddSprYPos(k, v2);
              spr_xspeed[k] = 0;
              spr_yspeed[k] = 0;
              spr_decrementing_table1540[k] = 0x80;
              spr_table151c[k] = 3;
              io_sound_ch3 = 40;
            } else {
              Spr029_KoopaKid_MortonRoyLudwig_01D309(k);
            }
          }
        } else {
          DamagePlayer_Hurt();
        }
      }
    }
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_01D309(uint8 k) {  // 01d309
  player_xspeed = sign8(spr_xpos_lo[k] - 8 - player_xpos) ? 32 : -32;
}

void sub_1D31E(uint8 k) {  // 01d31e
  io_sound_ch1 = 1;
  if ((player_yspeed & 0x80) == 0) {
    Spr029_KoopaKid_MortonRoyLudwig_01D309(k);
    player_yspeed = -48;
  } else {
    player_yspeed = 16;
  }
}

void sub_1D334(uint8 k) {  // 01d334
  io_sound_ch1 = 1;
  if ((player_yspeed & 0x80) == 0) {
    player_xspeed = ((spr_xpos_lo[k] & 0x80) != 0) ? -32 : 32;
    player_yspeed = -80;
  } else {
    player_yspeed = 32;
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_01D351(uint8 k) {  // 01d351
  uint16 xpos = GetSprXPos(k), ypos = GetSprYPos(k);
  SetSprXPos(k, xpos - 8);
  spr_ypos_lo[k] += 8;
  SpawnContactEffectFromAbove(k);
  SetSprXYPos(k, xpos, ypos);
}

void Spr029_KoopaKid_MortonRoyLudwig_01D3B1(uint8 k) {  // 01d3b1
  if (spr_table151c[k] < 3) {
    for (uint8 i = 10; i != 7; --i) {
      sprites_second_tracked_sprite_index = i;
      if (ext_spr_spriteid[i] == 5) {
        SetHiLo(&R8_, &R0_, PAIR16(ext_spr_xpos_hi[i], ext_spr_xpos_lo[i]));
        SetHiLo(&R9_, &R1_, PAIR16(ext_spr_ypos_hi[i], ext_spr_ypos_lo[i]));
        R2_ = 8;
        R3_ = 8;
        Spr029_KoopaKid_MortonRoyLudwig_01D40B(k);
        if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
          ext_spr_spriteid[i] = 1;
          ext_spr_decrementing_table176f[i] = 15;
          io_sound_ch1 = 1;
          if (++spr_table1626[k] >= 0xC)
            Spr029_KoopaKid_MortonRoyLudwig_01CFD0(k);
        }
      }
    }
  }
}

void Spr029_KoopaKid_MortonRoyLudwig_01D40B(uint8 k) {  // 01d40b
  SetHiLo(&R10_, &R4_, GetSprXPos(k) - 8);
  R6_ = 16;
  R7_ = 16;
  uint8 v2 = (spr_table1602[k] >= 0x69) ? 19 : 8;
  SetHiLo(&R11_, &R5_, GetSprYPos(k) + v2);
}

void Spr034_LudwigFireball(uint8 k) {  // 01d44e
  if (!(player_freeze_player_flag | flag_sprites_locked) && spr_decrementing_table1540[k] < 0x10) {
    if (!spr_decrementing_table1540[k]) {
      SetNormalSpriteAnimationFrame(k);
      SetNormalSpriteAnimationFrame(k);
      CheckPlayerToNormalSpriteCollision(k);
    }
    UpdateNormalSpritePosition_X(k);
    R0_W = GetSprXPos(k) + 32;
    if (R0_W >= 0x230)
      spr_current_status[k] = 0;
  }
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
  R3_ = 2 * spr_table1602[k];
  R2_ = 2 * spr_table157c[k];
  uint8 v2 = kSpr034_LudwigFireball_OAMIndexes[k];
  spr_oamindex[k] = v2;
  uint8 v3 = v2;
  int8 v4 = spr_decrementing_table1540[k] < 8;
  uint8 v9;
  do {
    v9 = v4;
    int8 v8 = v4;
    uint8 v5 = R2_ + v4;
    OamEnt *oam = get_OamEnt(oam_buf, v3);
    oam[64].xpos = kSpr034_LudwigFireball_XDisp[v5] + R0_;
    uint8 v7 = ((counter_local_frames & 2) != 0) ? 0x80 : 0;
    oam[64].flags = kSpr034_LudwigFireball_Prop[v5] | v7;
    oam[64].ypos = R1_ + 2;
    oam[64].charnum = kSpr034_LudwigFireball_Tiles[(uint8)(R3_ + v8)];
    v3 += 4;
    v4 = v9 - 1;
  } while (v4 >= 0);
  FinishOAMWrite(k, 2, 1);
}

void Spr03F_ParachuteGoomba(uint8 k) {  // 01d4fb
  if (spr_current_status[k] != 8)
    goto LABEL_25;
  if (!flag_sprites_locked && !spr_decrementing_table1540[k]) {
    if (counter_global_frames & 1)
      AddSprYPos(k, 1);
    if (!spr_table151c[k]) {
      if (counter_global_frames & 1) {
        uint8 v2 = spr_table00c2[k] & 1;
        uint8 v3 = kSprXXX_ParachutingEnemy_DATA_01D4E7[v2] + spr_table1570[k];
        spr_table1570[k] = v3;
        if (v3 == kSprXXX_ParachutingEnemy_DATA_01D4E9[v2])
          ++spr_table00c2[k];
      }
      uint8 v17 = spr_xspeed[k];
      uint8 v4 = kSprXXX_ParachutingEnemy_DATA_01D4EB[spr_table1570[k]];
      if (spr_table00c2[k] & 1)
        v4 = -v4;
      spr_xspeed[k] += v4;
      UpdateNormalSpritePosition_X(k);
      spr_xspeed[k] = v17;
    }
  }
  SubOffscreen_Bank01_Entry1(k);
  misc_scratch7e185e = 0;
  uint8 v5 = -16;
  uint8 v6 = spr_decrementing_table1540[k];
  if (v6) {
    misc_scratch7e185e = (v6 >> 1) ^ 0xF;
    v5 = misc_scratch7e185e - 16;
  }
  R0_ = v5;
  uint16 old_y = GetSprYPos(k);
  SetSprYPos(k, old_y + (0xff00 | v5));
  uint8 v14 = spr_table15f6[k];
  spr_table15f6[k] = v14 & 0xF1 | 6;
  uint8 v7 = spr_table1570[k];
  spr_table1602[k] = kSprXXX_ParachutingEnemy_DATA_01D55E[v7];
  spr_table157c[k] = kSprXXX_ParachutingEnemy_DATA_01D56E[v7];
  GenericGFXRtDraw1Tile16x16(k);
  spr_table15f6[k] = v14;
  spr_oamindex[k] += 4;
  uint16 old_x = GetSprXPos(k);
  uint8 v8 = spr_table1570[k];
  AddSprXPos(k, PAIR16(kSprXXX_ParachutingEnemy_DATA_01D58E[v8], kSprXXX_ParachutingEnemy_DATA_01D57E[v8]));
  AddSprYPos(k, (int8)(kSprXXX_ParachutingEnemy_DATA_01D59E[v8] - misc_scratch7e185e));
  uint8 v11 = spr_table1602[k] - 12;
  if (spr_table1602[k] == 13)
    v11 += spr_table157c[k];
  spr_table1602[k] = v11;
  if (spr_decrementing_table1540[k])
    spr_table1602[k] = 0;
  GenericGFXRtDraw4Tiles8x8Square(k, kSprXXX_ParachutingEnemy_DATA_01D5B0[spr_table1602[k]]);
  CheckPlayerAndNormalSpriteCollisions(k);
  uint8 v12 = spr_decrementing_table1540[k];
  if (v12) {
    if (v12 == 1) {
      spr_yspeed[k] = 0;
      SetSprYPos(k, old_y);
      spr_decrementing_table1540[k] = 0x80;
LABEL_25:
      spr_spriteid[k] = kSprXXX_ParachutingEnemy_DATA_01D5AE[(uint8)(spr_spriteid[k] - 63)];
      InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(k);
      return;
    }
    HandleNormalSpriteLevelCollision(k);
    if (CheckNormalSpriteLevelColl_Floor(k))
      SetNormalSpriteYSpeedBasedOnSlope(k);
    UpdateNormalSpritePosition_Y(k);
    ++spr_yspeed[k];
  } else if ((counter_global_frames ^ k) & 1) {
    HandleNormalSpriteLevelCollision(k);
    if (CheckNormalSpriteLevelColl_Wall(k)) {
      spr_table151c[k] = 1;
      spr_table1570[k] = 7;
    }
    if (CheckNormalSpriteLevelColl_Floor(k))
      spr_decrementing_table1540[k] = 32;
  }
  SetSprXPos(k, old_x);
  SetSprYPos(k, old_y);
}

void SprXXX_ParachutingEnemy_Return(uint8 k) {  // 01d6c3
  ;
}

void SprXXX_LineGuided_Init_LineGuideRopeEntry(uint8 k) {  // 01d6c4
  if (k >= 6 && sprites_sprite_memory_setting)
    ++spr_property_bits1662[k];
  ++spr_decrementing_table1540[k];
  SprXXX_LineGuided_LineFuzzyPlats(k);
  SprXXX_LineGuided_LineFuzzyPlats(k);
  ++spr_table1626[k];
}

void SprXXX_LineGuided_Init_CheckerboardLineGuidePlatformEntry(uint8 k) {  // 01d6d2
  bool v1 = (spr_xpos_lo[k] & 0x10) == 0x10;
  spr_table1602[k] = spr_xpos_lo[k] & 0x10 ^ 0x10;
  if (!v1)
    ++spr_property_bits1662[k];
  ++spr_decrementing_table1540[k];
  SprXXX_LineGuided_LineFuzzyPlats(k);
  SprXXX_LineGuided_LineFuzzyPlats(k);
  ++spr_table1626[k];
}

void SprXXX_LineGuided_Init_ChainsawEntry(uint8 k) {  // 01d6ed
  ++spr_table187b[k];
  if ((spr_xpos_lo[k] & 0x10) != 0) {
    ++spr_table157c[k];
    spr_xpos_lo[k] += 15;
  } else {
    AddSprXPos(k, -0x140);
  }
  SprXXX_LineGuided_Init_BrownLineGuidePlatformEntry(k);
}

void SprXXX_LineGuided_Init_BrownLineGuidePlatformEntry(uint8 k) {  // 01d711
  spr_decrementing_table1540[k] = 2;
}

void SprXXX_LineGuided_ChainsawEntry(uint8 k) {  // 01d719
  R2_ = counter_local_frames ^ (4 * k);
  if (!(flag_sprites_locked | R2_ & 7)) {
    R0_ = kSprXXX_LineGuided_DATA_01D717[(R2_ & 8) != 0];
    R1_ = -14;
    SpawnNormalSpriteTurnAroundSmoke_Entry2(k);
  }
  SprXXX_LineGuided_LineGuideGrinderEntry(k);
}

void SprXXX_LineGuided_LineGuideGrinderEntry(uint8 k) {  // 01d73a
  if (!(flag_sprites_locked | spr_table1626[k] | counter_global_frames & 7))
    io_sound_ch2 = 4;
  SprXXX_LineGuided_LineFuzzyPlats(k);
}

void SprXXX_LineGuided_LineFuzzyPlats(uint8 k) {  // 01d74a
  uint8 v1 = spr_spriteid[k];
  if (v1 == 100) {
    SprXXX_LineGuided_01DC54(k);
    uint8 v17 = spr_xpos_lo[k];
    uint8 v14 = spr_ypos_lo[k];
    SprXXX_LineGuided_01D74D(k);
    misc_scratch7e185e = spr_ypos_lo[k] - v14;
    misc_scratch7e18b6 = spr_xpos_lo[k] - v17;
    if ((player_blocked_flags & 3) != 0)
      return;
    if (!(CheckPlayerToNormalSpriteColl_01A80F(k) & 1))
      goto LABEL_13;
    if (spr_current_status[k]) {
      if (player_riding_yoshi_flag | player_carrying_something_flag1) {
LABEL_13:
        if (spr_decrementing_table163e[k]) {
          spr_decrementing_table163e[k] = 0;
          flag_player_climb_on_air = 0;
        }
        return;
      }
      spr_decrementing_table163e[k] = 3;
      if (spr_decrementing_table154c[k])
        return;
      if (!flag_player_climb_on_air) {
        if ((io_controller_hold1 & 8) == 0)
          return;
        flag_player_climb_on_air = io_controller_hold1 & 8;
      }
      if ((io_controller_press1 & 0x80) == 0) {
LABEL_25:
        player_ypos += (int8)misc_scratch7e185e;
        if (sign16(player_ypos - GetSprYPos(k)))
          ++player_ypos;
        SprXXX_LineGuided_01DA90(misc_scratch7e18b6);
        int8 v4 = spr_xpos_lo[k] - 8 - player_xpos;
        if (v4)
          SprXXX_LineGuided_01DA90(v4 >= 0 ? 1 : -1);
        if (spr_table1626[k]) {
          spr_table1626[k] = 0;
          spr_decrementing_table1540[k] = 0;
        }
        return;
      }
      player_yspeed = -80;
    }
    flag_player_climb_on_air = 0;
    spr_decrementing_table154c[k] = 16;
    goto LABEL_25;
  }
  if (v1 >= 0x65) {
    if (v1 == 104) {
      SprXXX_LineGuided_01DBD4(k);
    } else {
      if (v1 != 103) {
        CheckPlayerToNormalSpriteCollision(k);
        SprXXX_LineGuided_ChainsawDraw(k);
        goto LABEL_9;
      }
      SprXXX_LineGuided_01DC0B(k);
    }
    CheckPlayerToNormalSpriteCollision(k);
LABEL_9:
    SprXXX_LineGuided_01D74D(k);
    return;
  }
  R0_ = spr_table1602[k] ? 40 : 24;
  uint16 old_x = GetSprXPos(k), old_y = GetSprYPos(k);
  AddSprXYPos(k, -R0_, -8);
  NormalSpritePlatformGFXRt_DrawFlatPlatform(k);
  SetSprXPos(k, old_x);
  SetSprYPos(k, old_y);
  uint8 v19 = spr_xpos_lo[k];
  SprXXX_LineGuided_01D74D(k);
  int8 v7 = v19 - spr_xpos_lo[k];
  uint8 v20 = spr_table1528[k];
  spr_table1528[k] = -v7;
  old_x = GetSprXPos(k), old_y = GetSprYPos(k);
  R0_ = spr_table1602[k] ? 40 : 24;
  AddSprXYPos(k, -R0_, -8);
  if (SolidSpriteBlock(k)) {
    if (spr_table1626[k]) {
      spr_table1626[k] = 0;
      spr_decrementing_table1540[k] = 0;
    }
  }
  SetSprXPos(k, old_x);
  SetSprYPos(k, old_y);
  spr_table1528[k] = v20;
}

void SprXXX_LineGuided_01D74D(uint8 k) {  // 01d74d
  SubOffscreen_Bank01_Entry2(k);
  if (spr_decrementing_table1540[k] || !(spr_table1626[k] | flag_sprites_locked))
    kSprXXX_LineGuided_Ptrs01D762[spr_table00c2[k]](k);
}

void SprXXX_LineGuided_State01_OnLineGuide(uint8 k) {  // 01d768
  if (!flag_sprites_locked) {
    if (spr_table157c[k]) {
      SprXXX_LineGuided_01D7B0(k, spr_table1570[k] - 1);
      bool v1 = spr_table1570[k]-- == 1;
      if (v1 || spr_table187b[k] && counter_global_frames & 1 && (v1 = spr_table1570[k] == 1, --spr_table1570[k], v1))
        spr_table00c2[k] = 0;
    } else {
      SprXXX_LineGuided_01D7B0(k, spr_table1534[k]);
      ++spr_table1534[k];
      if (spr_table187b[k] && counter_global_frames & 1)
        ++spr_table1534[k];
      if (spr_table1534[k] >= spr_table1570[k])
        spr_table00c2[k] = 0;
    }
  }
}

void SprXXX_LineGuided_01D7B0(uint8 k, uint8 j) {  // 01d7b0
  R4_ = spr_table151c[k];
  R5_ = spr_table1528[k];
  R6_ = RomPtr_07(*(uint16 *)&R4_)[j] & 0xF;
  R7_ = RomPtr_07(*(uint16 *)&R4_)[j] >> 4;
  spr_ypos_lo[k] = R7_ + (spr_ypos_lo[k] & 0xF0);
  spr_xpos_lo[k] = R6_ + (spr_xpos_lo[k] & 0xF0);
}

void SprXXX_LineGuided_State00_AtEndOfTile(uint8 k) {  // 01d7f4
  uint8 v1 = 3;
  do {
    sprites_second_tracked_sprite_index = v1;
    R2_W = GetSprXPos(k) + PAIR16(kSprXXX_LineGuided_DATA_01D7E5[v1], kSprXXX_LineGuided_DATA_01D7E1[v1]);
    R0_W = GetSprYPos(k) + PAIR16(kSprXXX_LineGuided_DATA_01D7ED[v1], kSprXXX_LineGuided_DATA_01D7E9[v1]);
    if (spr_decrementing_table1540[k] || (R4_ = R0_ & 0xF0, (spr_ypos_lo[k] & 0xF0) != (R0_ & 0xF0)) ||
        (R5_ = R2_ & 0xF0, (spr_xpos_lo[k] & 0xF0) != (R2_ & 0xF0))) {
      if (SprXXX_LineGuided_01D94D())
        goto LABEL_22;
      if (blocks_currently_processed_map16_tile_lo == 0x94) {
        if (flag_on_off_switch)
          goto LABEL_13;
      } else if (blocks_currently_processed_map16_tile_lo == 0x95 && !flag_on_off_switch) {
        goto LABEL_13;
      }
      if (blocks_currently_processed_map16_tile_lo < 0x76 || blocks_currently_processed_map16_tile_lo >= 0x9A)
        goto LABEL_13;
      uint8 v7 = blocks_currently_processed_map16_tile_lo - 118;
      if (blocks_currently_processed_map16_tile_lo >= 0x96) {
LABEL_22:
        v7 = spr_table160e[k];
      } else {
        R8_W = GetSprYPos(k);
        R10_W = GetSprXPos(k);
        SetSprYPos(k, R0_W);
        SetSprXPos(k, R2_W);
      }
      spr_table151c[k] = kLineGuideSpeedTable_PtrsLo[v7];
      spr_table1528[k] = kLineGuideSpeedTable_PtrsHi[v7];
      spr_table1570[k] = kSprXXX_LineGuided_DATA_01DCD1[v7];
      spr_table1534[k] = 0;
      spr_table160e[k] = v7;
      if (spr_decrementing_table1540[k]) {
        spr_table00c2[k] = 1;
        return;
      }
      spr_table157c[k] = 0;
      uint8 v8;
      if (kSprXXX_LineGuided_DATA_01DCF1[v7]) {
        v8 = spr_ypos_lo[k] ^ ((kSprXXX_LineGuided_DATA_01DCF1[v7] == 1) ? 0xf : 0);
      } else {
        v8 = spr_xpos_lo[k];
      }
      if ((v8 & 0xF) >= 0xA && spr_table00c2[k] != 2)
        spr_table157c[k] = 1;
      R12_ = spr_ypos_lo[k];
      R13_ = spr_xpos_lo[k];
      SprXXX_LineGuided_State01_OnLineGuide(k);
      if ((uint8)(R12_ - spr_ypos_lo[k] + 8) < 0x10 && (uint8)(R13_ - spr_xpos_lo[k] + 8) < 0x10) {
        spr_table00c2[k] = 1;
        return;
      }
      SetSprYPos(k, R8_W);
      SetSprXPos(k, R10_W);
    }
LABEL_13:
    v1 = sprites_second_tracked_sprite_index - 1;
  } while ((int8)(sprites_second_tracked_sprite_index - 1) >= 0);
  if (spr_table00c2[k] != 2) {
    spr_table00c2[k] = 2;
    uint8 v5 = spr_table160e[k];
    if (spr_table157c[k])
      v5 += 32;
    int8 v6 = kSprXXX_LineGuided_DATA_01DD11[v5];
    if (v6 < 0)
      v6 *= 2;
    spr_yspeed[k] = 2 * v6;
    spr_xspeed[k] = 2 * kSprXXX_LineGuided_DATA_01DD51[v5];
    spr_decrementing_table1540[k] = 16;
  }
}

uint8 SprXXX_LineGuided_01D94D() {  // 01d94d

  R6_ = R0_ & 0xF0;
  uint8 v4 = R2_ >> 4;
  uint8 v3 = R0_ & 0xF0 | (R2_ >> 4);
  if ((misc_level_layout_flags & 1) != 0) {
    WORD(R5_) = PAIR16(kLevelDataLayoutTables_EightBitHi_Vertical[R1_], kLevelDataLayoutTables_EightBitLo_Vertical[R1_]) + PAIR16(R3_, v3);
  } else {
    WORD(R5_) = PAIR16(kLevelDataLayoutTables_EightBitHi[R3_], kLevelDataLayoutTables_EightBitLo[R3_]) + PAIR16(R1_, v3);
  }
  R7_ = 126;
  blocks_currently_processed_map16_tile_lo = *IndirPtr(&R5_, 0);
  ++R7_;
  uint8 v1 = *IndirPtr(&R5_, 0);
  R5_ = v4;
  return kSprXXX_LineGuided_DATA_018000[v4 & 7] & v1;
}

void SprXXX_LineGuided_01DA90(uint8 a) {  // 01da90
  player_xpos += (int8)a;
}

void SprXXX_LineGuided_State02_Falling(uint8 k) {  // 01db44
  if (!flag_sprites_locked) {
    HandleNormalSpriteGravity(k);
    if (!spr_decrementing_table1540[k] && !sign8(spr_yspeed[k] - 32))
      SprXXX_LineGuided_State00_AtEndOfTile(k);
  }
}

void Spr0B4_NonLineGuideGrinder(uint8 k) {  // 01db5c
  Spr0B4_NonLineGuideGrinder_Draw(k);
  if (spr_current_status[k] == 8 && !flag_sprites_locked) {
    if ((counter_global_frames & 3) == 0)
      io_sound_ch2 = 4;
    SubOffscreen_Bank01_Entry1(k);
    CheckPlayerToNormalSpriteCollision(k);
    spr_xspeed[k] = kSpr0B4_NonLineGuideGrinder_XSpeed[spr_table157c[k]];
    HandleNormalSpriteGravity(k);
    if (CheckNormalSpriteLevelColl_Floor(k))
      spr_yspeed[k] = 0;
    if (CheckNormalSpriteLevelColl_Wall(k))
      ChangeNormalSpriteDirection(k);
  }
}

void Spr0B4_NonLineGuideGrinder_Draw(uint8 k) {  // 01dba2
  uint8 drt;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSpr0B4_NonLineGuideGrinder_XDisp[i] + R0_;
    oam[64].ypos = kSpr0B4_NonLineGuideGrinder_YDisp[i] + R1_;
    oam[64].charnum = counter_local_frames & 2 | 0x6C;
    oam[64].flags = kSpr0B4_NonLineGuideGrinder_Prop[i];
    drt += 4;
  }
  FinishOAMWrite(k, 2, 3);
}

void SprXXX_LineGuided_01DBD4(uint8 k) {  // 01dbd4
  GenericGFXRtDraw1Tile16x16(k);
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].xpos -= 8;
  oam[64].ypos -= 8;
  bool v2 = (counter_local_frames & 4) != 0;
  oam[64].charnum = -56;
  oam[64].flags = sprites_tile_priority | kSprXXX_LineGuided_DATA_01DC09[v2];
  FinishOAMWrite(k, 2, 0);
}

void SprXXX_LineGuided_01DC0B(uint8 k) {  // 01dc0b
  uint8 drt;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  for (uint8 i = 3; (i & 0x80) == 0; --i) {
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = kSprXXX_LineGuided_DATA_01DC3B[i] + R0_;
    oam[64].ypos = kSprXXX_LineGuided_DATA_01DC3F[i] + R1_;
    oam[64].charnum = counter_local_frames & 2 | 0x6C;
    oam[64].flags = kSprXXX_LineGuided_DATA_01DC43[i];
    drt += 4;
  }
  FinishOAMWrite(k, 2, 3);
}

void SprXXX_LineGuided_01DC54(uint8 k) {  // 01dc54
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
  R0_ -= 8;
  R1_ -= 8;
  R2_ = ((uint8)(counter_local_frames ^ (4 * k)) >> 3) & 3;
  uint8 v1 = 5;
  if (k >= 6 && sprites_sprite_memory_setting)
    v1 = 9;
  R3_ = v1;
  uint8 v2 = spr_oamindex[k];
  uint8 v3 = 0;
  do {
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam[64].xpos = R0_;
    uint8 v5 = R1_;
    oam[64].ypos = R1_;
    R1_ = v5 + 16;
    oam[64].charnum = v3 ? kSprXXX_LineGuided_LineGuideRopeTiles[v3] : kSprXXX_LineGuided_RopeMotorTiles[R2_];
    oam[64].flags = v3 ? 49 : 55;
    v2 += 4;
  } while (++v3 != R3_);
  get_OamEnt(oam_buf, v2)[63].charnum = -34;
  uint8 v8 = (spr_current_slotid >= 6 && sprites_sprite_memory_setting) ? 8 : 4;
  FinishOAMWrite(spr_current_slotid, 2, v8);
}

void Spr082_BonusGame_Init(uint8 k) {  // 01ddac
  if (flag_disable_bonus_game_sprite) {
    spr_current_status[k] = 0;
  } else {
    uint8 v1 = 9;
    do {
      spr_current_status[v1] = 8;
      spr_spriteid[v1] = -126;
      SetSprXYPos(v1, kSpr082_BonusGame_Init_DATA_01DD90[v1], 
        (int8)kSpr082_BonusGame_Init_DATA_01DD99[v1] + 256);
      InitializeNormalSpriteRAMTables(v1);
      spr_table157c[v1] = kSpr082_BonusGame_Init_DATA_01DDA2[v1];
      spr_table1570[v1] = (counter_global_frames + v1) & 7;
      --v1;
    } while (v1);
    sprites_bonus_game_is_over_flag = 0;
    counter_number_of_bonus_game1ups_to_spawn = 0;
    spr_table1570[9] = kSpr082_BonusGame_DATA_01DE21[(counter_local_frames + (counter_global_frames ^ GetRand())) & 7];
    spr_table00c2[9] = 1;
    ++flag_disable_bonus_game_sprite;
  }
}

void Spr082_BonusGame(uint8 k) {  // 01de2a
  spr_xoffscreen_flag[k] = 0;
  if (k == 1)
    Spr082_BonusGame_Spawn1ups();
  Spr082_BonusGame_01DF19(k);
  if (!flag_sprites_locked && !sprites_bonus_game_is_over_flag) {
    if (!spr_table00c2[k]) {
      if ((counter_local_frames & 3) == 0 && ++spr_table1570[k] == 9)
        spr_table1570[k] = 0;
      if (CheckPlayerToNormalSpriteCollision(k) & 1 && (player_yspeed & 0x80) != 0) {
        int8 v1 = -12;
        if (player_current_power_up)
          v1 = 0;
        if ((uint8)(spr_ypos_lo[k] + v1 - mirror_current_layer1_ypos) < (uint8)player_on_screen_pos_y) {
          player_yspeed = 16;
          io_sound_ch1 = 11;
          ++spr_table00c2[k];
          spr_table1570[k] = kSpr082_BonusGame_DATA_01DE21[spr_table1570[k]];
          spr_decrementing_table1540[k] = 16;
        }
      }
    }
    uint8 v2 = spr_table157c[k];
    if ((v2 & 0x80) == 0) {
      if (spr_xpos_lo[k] == kSpr082_BonusGame_DATA_01DE19[v2] && spr_ypos_lo[k] == kSpr082_BonusGame_DATA_01DE1D[v2]) {
        uint8 v3 = 9;
        while (spr_table00c2[v3]) {
          spr_ypos_lo[v3] = (spr_ypos_lo[v3] + 4) & 0xF8;
          spr_xpos_lo[v3] = (spr_xpos_lo[v3] + 4) & 0xF8;
          if (!--v3) {
            ++sprites_bonus_game_is_over_flag;
            Spr082_BonusGame_01DFD9();
            return;
          }
        }
        v2 = (spr_table157c[k] + 1) & 3;
        spr_table157c[k] = v2;
      }
      spr_xspeed[k] = kSpr082_BonusGame_DATA_01DE11[v2];
      spr_yspeed[k] = kSpr082_BonusGame_DATA_01DE15[v2];
      UpdateNormalSpritePosition_X(k);
      UpdateNormalSpritePosition_Y(k);
    }
  }
}

void Spr082_BonusGame_01DF19(uint8 k) {  // 01df19
  R0_ = kSpr082_BonusGame_DATA_01DF10[spr_decrementing_table1540[k] >> 1];
  uint8 v1 = spr_oamindex[k];
  int8 v2 = spr_xpos_lo[k] - mirror_current_layer1_xpos;
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[68].xpos = v2;
  oam[64].xpos = v2;
  oam[66].xpos = v2;
  v2 += 8;
  oam[65].xpos = v2;
  oam[67].xpos = v2;
  uint8 t4 = spr_decrementing_table154c[k];
  uint8 t5 = t4 ? (t4 & 0x10) != 0 : 0;

  int8 v4 = spr_ypos_lo[k] - R0_ - mirror_current_layer1_ypos;
  oam[68].ypos = v4;
  if (!t5) {
    oam[64].ypos = v4;
    oam[65].ypos = v4;
    int8 v5 = v4 + 8;
    oam[66].ypos = v5;
    oam[67].ypos = v5;
  }
  uint8 v8 = spr_table1570[k];
  oam[64].charnum = kSpr082_BonusGame_DATA_01DEE3[(uint8)(4 * v8)];
  oam[65].charnum = kSpr082_BonusGame_DATA_01DEE3[(uint8)(4 * v8) + 1];
  oam[66].charnum = kSpr082_BonusGame_DATA_01DEE3[(uint8)(4 * v8) + 2];
  oam[67].charnum = kSpr082_BonusGame_DATA_01DEE3[(uint8)(4 * v8) + 3];
  oam[68].charnum = -28;
  int8 v6 = kSpr082_BonusGame_DATA_01DF07[v8] | sprites_tile_priority;
  oam[64].flags = v6;
  oam[65].flags = v6;
  oam[66].flags = v6;
  oam[67].flags = v6;
  oam[68].flags = v6 | 1;
  uint8 v7 = v1 >> 2;
  sprites_oamtile_size_buffer[v7 + 64] = 0;
  sprites_oamtile_size_buffer[v7 + 65] = 0;
  sprites_oamtile_size_buffer[v7 + 66] = 0;
  sprites_oamtile_size_buffer[v7 + 67] = 0;
  sprites_oamtile_size_buffer[v7 + 68] = 2;
}

void Spr082_BonusGame_01DFD9() {  // 01dfd9
  R0_ = 7;
  do {
    for (uint8 i = 2; (i & 0x80) == 0; --i) {
      R1_ = i;
      uint8 v1 = kSpr082_BonusGame_DATA_01DFC1[(uint8)(i + R0_ + __CFSHL__(R0_, 1) + 2 * R0_)];
      R2_ = kSpr082_BonusGame_Init_DATA_01DD99[v1 + 1];
      R3_ = kSpr082_BonusGame_Init_DATA_01DD90[v1 + 1];
      uint8 j;
      for (j = 9; j != 1; --j) {
        if (spr_ypos_lo[j] == R2_ && spr_xpos_lo[j] == R3_)
          break;
      }
      *(&R4_ + i) = spr_table1570[j];
      *(&R7_ + i) = j;
    }
    if (R4_ == R5_ && R4_ == R6_) {
      ++counter_number_of_bonus_game1ups_to_spawn;
      spr_decrementing_table154c[R7_] = 112;
      spr_decrementing_table154c[R8_] = 112;
      spr_decrementing_table154c[R9_] = 112;
    }
    --R0_;
  } while ((R0_ & 0x80) == 0);
  uint8 v3 = 41;
  counter_remaining_bonus_game1ups = counter_number_of_bonus_game1ups_to_spawn;
  if (!counter_number_of_bonus_game1ups_to_spawn) {
    timer_bonus_game_end = 88;
    v3 = 42;
  }
  io_sound_ch3 = v3;
}

void Spr033_Podoboo_Init(uint8 k) {  // 01e050
  SetHiLo(&spr_table151c[k], &spr_table1528[k], GetSprYPos(k));
  do {
    AddSprYPos(k, 16);
    HandleNormalSpriteLevelCollision(k);
  } while (!spr_table164a[k]);
  Spr033_Podoboo_01E0E2(k);
  spr_decrementing_table1540[k] = 32;
}

void Spr033_Podoboo(uint8 k) {  // 01e093
  spr_table15d0[k] = 0;
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    spr_table15d0[k] = v1;
    if (v1 == 1)
      io_sound_ch3 = 39;
  } else {
    if (!flag_sprites_locked) {
      CheckPlayerToNormalSpriteCollision(k);
      SetNormalSpriteAnimationFrame(k);
      SetNormalSpriteAnimationFrame(k);
      uint8 v2 = spr_table15f6[k] & 0x7F;
      if ((spr_yspeed[k] & 0x80) == 0) {
        spr_table1602[k] += 2;
        v2 |= 0x80;
      }
      spr_table15f6[k] = v2;
      HandleNormalSpriteLevelCollision(k);
      if (spr_table164a[k] && (spr_yspeed[k] & 0x80) == 0) {
        spr_decrementing_table1540[k] = (GetRand() & 0x3F) + 96;
        Spr033_Podoboo_01E0E2(k);
        return;
      }
      UpdateNormalSpritePosition_Y(k);
      if (!(spr_table00c2[k] | counter_local_frames & 7))
        Spr033_Podoboo_SpawnPodobooFire(k);
      if (!spr_decrementing_table1564[k]) {
        int8 v3 = spr_yspeed[k];
        if (v3 < 0 || (uint8)v3 < kSpr033_Podoboo_DATA_01E091[spr_table00c2[k]])
          spr_yspeed[k] = v3 + 2;
      }
      SubOffscreen_Bank01_Entry1(k);
    }
    if (spr_table00c2[k]) {
      if (!flag_sprites_locked) {
        if ((spr_table1588[k] & 4) != 0) {
          spr_yspeed[k] = 0;
          uint8 v4 = spr_decrementing_table1558[k];
          if (v4) {
            if (v4 == 1) {
              SprStatus02_Dead_SetNorSprStatus04(k);
              return;
            }
          } else {
            spr_decrementing_table1558[k] = 0x80;
          }
        } else {
          spr_xspeed[k] = (((counter_global_frames + 4 * k) & 4) != 0) ? 16 : -16;
          UpdateNormalSpritePosition_X(k);
        }
      }
      if (spr_ypos_lo[k] >= 0xF0)
        spr_current_status[k] = 0;
      GenericGFXRtDraw1Tile16x16(k);
      uint8 v6 = spr_oamindex[k];
      uint8 v7 = ((uint8)(spr_current_slotid + ((uint8)(counter_local_frames & 0xC) >> 1)) >> 1) & 3;
      OamEnt *oam = get_OamEnt(oam_buf, v6);
      oam[64].charnum = kSpr033_Podoboo_BowserFlameTiles[v7];
      oam[64].flags = sprites_tile_priority | kSpr033_Podoboo_BowserFlameProp[v7];
    } else {
      GenericGFXRtDraw4Tiles8x8Square(k, 1);
      *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[6] = 0x8600;
      *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[6] = 0x8800;
    }
  }
}

void Spr033_Podoboo_01E0E2(uint8 k) {  // 01e0e2
  uint8 v1 = spr_ypos_lo[k];
  bool v2 = v1 < spr_table1528[k];
  R0_ = v1 - spr_table1528[k];
  int8 v3 = 0;
  if ((spr_ypos_hi[k] - (v2 + spr_table151c[k])) & 1)
    v3 = 0x80;
  R0_ = (R0_ >> 1) + v3;
  int8 v4 = kSpr033_Podoboo_DATA_01E07B[R0_ >> 3];
  if (v4 >= 0) {
    spr_decrementing_table1564[k] = v4;
    v4 = 0x80;
  }
  spr_yspeed[k] = v4;
}

void Spr00E_Keyhole_Init(uint8 k) {  // 01e1b8
  AddSprXPos(k, 8);
}

void Spr00E_Keyhole(uint8 k) {  // 01e1c8
  uint8 drt;
  uint8 i;
  for (i = 11; (i & 0x80) == 0; --i) {
    if (spr_current_status[i] >= 8 && spr_spriteid[i] == 0x80)
      break;
  }
  if (player_riding_yoshi_flag && yoshi_key_in_mouth_flag) {
    StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
  } else {
    spr_table151c[k] = i;
    if ((i & 0x80) != 0 || spr_current_status[i] != 11)
      goto LABEL_15;
    StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(i);
  }
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
  if (StandardSpriteToSpriteCollisionChecks_CheckContact() && !spr_decrementing_table154c[k]) {
    timer_end_level_via_keyhole = 48;
    io_music_ch1 = 16;
    ++player_freeze_player_flag;
    ++flag_sprites_locked;
    WORD(temp1436) = GetSprXPos(k);
    WORD(temp1438) = GetSprYPos(k);
    spr_decrementing_table154c[k] = 48;
  }
LABEL_15:
  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  OamEnt *oam = get_OamEnt(oam_buf, drt);
  oam[64].xpos = R0_;
  oam[65].xpos = R0_;
  oam[64].ypos = R1_;
  oam[65].ypos = R1_ + 8;
  oam[64].charnum = -21;
  oam[65].charnum = -5;
  oam[64].flags = 48;
  oam[65].flags = 48;
  FinishOAMWrite(k, 0, 1);
}

void Spr082_BonusGame_Spawn1ups() {  // 01e26a
  if ((counter_global_frames & 0x3F) == 0 && counter_number_of_bonus_game1ups_to_spawn) {
    --counter_number_of_bonus_game1ups_to_spawn;
    Spr082_BonusGame_01E281();
  }
  flag_run_cluster_sprites = 1;
}

void Spr082_BonusGame_01E281() {  // 01e281
  uint8 v0 = 7;
  while (cluster_spr_spriteid[v0]) {
    if ((--v0 & 0x80) != 0)
      return;
  }
  cluster_spr_spriteid[v0] = 1;
  cluster_spr_ypos_lo[v0] = 0;
  cluster_spr_ypos_hi[v0] = 1;
  cluster_spr_xpos_lo[v0] = 24;
  cluster_spr_xpos_hi[v0] = 0;
  cluster_spr_table1e66[v0] = 1;
  cluster_spr_table1e52[v0] = 16;
}

void Spr04E_LedgeMontyMole(uint8 k) {  // 01e2cf
  SubOffscreen_Bank01_Entry1(k);
  kSprXXX_SmallMontyMole_GroundMontyMolePtrs[spr_table00c2[k]](k);
}

void SprXXX_SmallMontyMole_State00_Invisible(uint8 k) {  // 01e2e0
  CheckPlayerPositionRelativeToSprite_Bank01_X(k);
  if ((uint8)(R15_ + 96) < 0xC0 && !spr_xoffscreen_flag[k]) {
    ++spr_table00c2[k];
    uint8 v1 = 104;
    if (ow_players_map[player_current_character] != 1)
      v1 = 32;
    spr_decrementing_table1540[k] = v1;
  }
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
}

void SprXXX_SmallMontyMole_State01_AboutToEmerge(uint8 k) {  // 01e309
  if (!(spr_table15d0[k] | spr_decrementing_table1540[k])) {
    ++spr_table00c2[k];
    spr_yspeed[k] = -80;
    if (!CheckIfNormalSpriteOffScreen(k))
      BreakThrowBlock_MontyMoleEntry(k, 0);
    SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
    if (spr_spriteid[k] == 78) {
      blocks_xpos = GetSprXPos(k);
      blocks_ypos = GetSprYPos(k);
      blocks_map16_to_generate = 8;
      GenerateTile();
    }
  }
  if (spr_spriteid[k] == 77) {
    bool v1 = (counter_local_frames & 0x10) != 0;
    spr_table1602[k] = kSprXXX_SmallMontyMole_DATA_01E35F[v1];
    GenericGFXRtDraw4Tiles8x8Square(k, kSprXXX_SmallMontyMole_DATA_01E361[v1]);
  } else {
    spr_table15f6[k] = (4 * counter_local_frames) & 0xC0 | 0x31;
    spr_table1602[k] = 3;
    GenericGFXRtDraw1Tile16x16(k);
    spr_table15f6[k] &= 0x3F;
  }
}

void SprXXX_SmallMontyMole_State02_PopOutOfGround(uint8 k) {  // 01e37f
  if (SprXXX_SmallMontyMole_01E3EF_ReturnsTwice(k))
    return;
  spr_table1602[k] = 2;
  if (CheckNormalSpriteLevelColl_Floor(k))
    ++spr_table00c2[k];
}

void SprXXX_SmallMontyMole_State03_Walking(uint8 k) {  // 01e393
  if (SprXXX_SmallMontyMole_01E3EF_ReturnsTwice(k))
    return;
  if (spr_table151c[k]) {
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      SetNormalSpriteAnimationFrame(k);
      SetNormalSpriteAnimationFrame(k);
      spr_xspeed[k] = kSprXXX_SmallMontyMole_NoFollowXSpeed[spr_table157c[k]];
      if (!spr_decrementing_table1558[k]) {
        spr_decrementing_table1558[k] = 80;
        spr_yspeed[k] = -40;
      }
    } else {
      spr_table1602[k] = 1;
    }
  } else {
    SetNormalSpriteAnimationFrame(k);
    SetNormalSpriteAnimationFrame(k);
    if ((GetRand() & 1) == 0) {
      uint8 t = SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
      uint8 v3 = spr_xspeed[k];
      if (v3 != kSprXXX_SmallMontyMole_FollowMaxXSpeed[t]) {
        spr_xspeed[k] = kGenericNormalSpriteAccelerationTable[t] + v3;
        int8 v4 = 0;
        if (t & 1)
          v4 = 0x80;
        if (((spr_xspeed[k] ^ ((t >> 2) + v4)) & 0x80) != 0) {
          SpawnNormalSpriteTurnAroundSmoke(k);
          SetNormalSpriteAnimationFrame(k);
        }
      }
    }
  }
}

uint8 SprXXX_SmallMontyMole_01E3EF_ReturnsTwice(uint8 k) {  // 01e3ef
  uint8 v1 = sprites_tile_priority;
  if (spr_decrementing_table1540[k])
    sprites_tile_priority = 16;
  GenericGFXRtDraw1Tile16x16(k);
  sprites_tile_priority = v1;
  if (flag_sprites_locked) {
    return true;
  } else {
    CheckPlayerAndNormalSpriteCollisions(k);
    HandleNormalSpriteGravity(k);
    if (CheckNormalSpriteLevelColl_Floor(k))
      SetNormalSpriteYSpeedBasedOnSlope(k);
    if (CheckNormalSpriteLevelColl_Wall(k))
      ChangeNormalSpriteDirection(k);
    return false;
  }
}

void Spr031_BonyBeetle(uint8 k) {  // 01e42b
  if (spr_current_status[k] != 8) {
    spr_table15f6[k] *= 2;
    spr_table15f6[k] = (spr_table15f6[k] >> 1) + 0x80;
LABEL_57:
    Spr030_ThrowingDryBones_DryBonesAndBonyBeetleDraw(k);
    return;
  }
  if (!spr_table1534[k]) {
    if (spr_decrementing_table163e[k] | flag_sprites_locked) {
LABEL_56:
      Spr030_ThrowingDryBones_01E5C4(k);
      CheckNormalSpriteToNormalSpriteCollision(k);
      ChangeNormalSpriteDirection_CheckIfTouchingWall(k);
      goto LABEL_57;
    }
    uint8 v8 = spr_table157c[k];
    uint8 v9 = kSpr030_ThrowingDryBones_XSpeed[v8];
    if (__CFSHL__(spr_slope_surface_its_on[k] ^ v9, 1))
      v9 += spr_slope_surface_its_on[k];
    spr_xspeed[k] = v9;
    if (spr_decrementing_table1540[k] || (spr_table1588[k] & (uint8)(v8 + 1) & 3) != 0)
      spr_xspeed[k] = 0;
    if (CheckNormalSpriteLevelColl_Ceiling(k))
      spr_yspeed[k] = 0;
    SubOffscreen_Bank01_Entry1(k);
    HandleNormalSpriteGravity(k);
    uint8 v10 = spr_spriteid[k];
    if (v10 == 49) {
      uint8 v11 = spr_decrementing_table1540[k];
      if (v11) {
        uint8 v12 = 0;
        if (v11 < 0x70) {
          v12 = 2;
          if (v11 >= 8 && v11 < 0x68)
            v12 = 3;
        }
        spr_table1602[k] = v12;
        goto LABEL_43;
      }
    } else if (v10 == 48 || v10 == 50 && ow_level_number_lo == 49) {
      uint8 v13 = spr_decrementing_table1540[k];
      if (v13) {
        if (v13 == 1)
          Spr030_ThrowingDryBones_SpawnDryBonesBone(k);
        spr_table1602[k] = 2;
        goto LABEL_56;
      }
    }
    if (CheckNormalSpriteLevelColl_Floor(k)) {
      SetNormalSpriteYSpeedBasedOnSlope(k);
      SetNormalSpriteAnimationFrame(k);
      if (spr_spriteid[k] == 50) {
        spr_table00c2[k] = 0;
      } else if ((spr_table1570[k] & 0x7F) == 0) {
        SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
      }
      goto LABEL_46;
    }
LABEL_43:
    spr_table1570[k] = 0;
    if (spr_spriteid[k] == 50 && !spr_table00c2[k]) {
      ++spr_table00c2[k];
      ChangeNormalSpriteDirection(k);
      UpdateNormalSpritePosition_X(k);
      UpdateNormalSpritePosition_X(k);
    }
LABEL_46:;
    uint8 v14 = spr_spriteid[k];
    if (v14 == 49) {
      if (counter_global_frames & 1)
        ++spr_table1528[k];
      if (!spr_table1528[k]) {
        ++spr_table1528[k];
        spr_decrementing_table1540[k] = -96;
      }
    } else if ((v14 == 48 || v14 == 50 && ow_level_number_lo == 49) && ((spr_table1570[k] + 64) & 0x7F) == 0) {
      spr_decrementing_table1540[k] = 63;
    }
    goto LABEL_56;
  }
  GenericGFXRtDraw1Tile16x16(k);
  uint8 v1 = spr_decrementing_table1540[k];
  if (!v1) {
    spr_table1534[k] = 0;
    SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
    v1 = 0;
  }
  int8 v2 = 72;
  if (v1 >= 0x10 && v1 < 0xF0)
    v2 = 46;
  uint8 v3 = spr_oamindex[k];
  OamEnt *oam = get_OamEnt(oam_buf, v3);
  oam[64].charnum = v2;
  spr_oamindex[k] = v3 + 4;
  oam[65].xpos = kSpr030_ThrowingDryBones_DATA_01E43C[spr_table157c[k]] + oam[64].xpos;
  oam[65].ypos = oam[64].ypos;
  oam[65].flags = oam[64].flags;
  oam[65].charnum = oam[64].charnum - 1;
  uint8 v5 = spr_decrementing_table1540[k];
  if (v5 && v5 < 0x40) {
    oam[64].xpos += (v5 & 2) != 0;
    oam[65].xpos += (v5 & 2) != 0;
  }
  FinishOAMWrite(k, 2, 1);
  HandleNormalSpriteGravity(k);
  if (CheckNormalSpriteLevelColl_Floor(k)) {
    spr_xspeed[k] = spr_yspeed[k] = 0;
  }
}

void Spr030_ThrowingDryBones_01E5C4(uint8 k) {  // 01e5c4
  if (CheckPlayerToNormalSpriteCollision(k) & 1) {
    if ((int8)(player_current_ypos + 20 - spr_ypos_lo[k]) >= 0 || 
      !counter_consecutive_enemies_stomped && (player_yspeed & 0x80) != 0 ||
        spr_spriteid[k] == 49 && (uint8)(spr_decrementing_table1540[k] - 8) < 0x60) {
      DamagePlayer_Hurt();
      if (!timer_player_hurt)
        SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
    } else {
      CheckPlayerToNormalSpriteColl_01AB46(k);
      SpawnContactEffectFromAbove(k);
      io_sound_ch1 = 7;
      BoostMarioSpeed();
      ++spr_table1534[k];
      spr_decrementing_table1540[k] = -1;
    }
  }
}

void Spr02F_PortableSpringboard(uint8 k) {  // 01e623
  if (flag_sprites_locked)
    goto LABEL_33;
  SubOffscreen_Bank01_Entry1(k);
  HandleNormalSpriteGravity(k);
  if (CheckNormalSpriteLevelColl_Floor(k))
    MakeStunnedSpriteBounceOrSlowDownOnGround(k);
  if (CheckNormalSpriteLevelColl_Wall(k)) {
    ChangeNormalSpriteDirection(k);
    spr_xspeed[k] = (int8)spr_xspeed[k] >> 2;
  }
  if (CheckNormalSpriteLevelColl_Ceiling(k))
    spr_yspeed[k] = 0;
  uint8 v2 = spr_decrementing_table1540[k];
  if (v2) {
    uint8 v3 = v2 >> 1;
    uint8 v4 = kSpr02F_PortableSpringboard_PlayerYDisp[v2 >> 1];
    if (player_riding_yoshi_flag)
      v4 += 18;
    R0_ = v4;
    spr_table1602[k] = kSpr02F_PortableSpringboard_AnimationFrames[v3];
    player_ypos = GetSprYPos(k) - R0_;
    player_in_air_flag = 0;
    player_xspeed = 0;
    misc_player_on_solid_sprite = 2;
    if (spr_decrementing_table1540[k] >= 7)
      goto LABEL_33;
    misc_player_on_solid_sprite = 0;
    uint8 v6 = -80;
    if ((io_controller_hold2 & 0x80) == 0) {
      if ((io_controller_hold1 & 0x80) == 0) {
LABEL_18:
        player_yspeed = v6;
        io_sound_ch3 = 8;
LABEL_33:
        Spr02F_PortableSpringboard_01E6F0(k);
        return;
      }
    } else {
      player_spin_jump_flag = 1;
    }
    player_in_air_flag = 11;
    v6 = 0x80;
    camera_bounce_off_spring_flag = 0x80;
    goto LABEL_18;
  }
  if (!(CheckPlayerToNormalSpriteColl_ProcessInteract(k) & 1))
    goto LABEL_33;
  spr_decrementing_table154c[k] = 0;
  if ((uint8)(spr_ypos_lo[k] - player_ypos + 4) >= 0x1C) {
    if ((int8)(spr_ypos_lo[k] - player_ypos - 24) >= 0) {
      if ((player_yspeed & 0x80) == 0)
        spr_decrementing_table1540[k] = 17;
    } else if ((player_yspeed & 0x80) != 0) {
      player_yspeed = 0;
    }
    goto LABEL_33;
  }
  if ((io_controller_hold1 & 0x40) != 0 && !(player_riding_yoshi_flag | player_carrying_something_flag1)) {
    spr_current_status[k] = 11;
    spr_table1602[k] = 0;
  }
  CheckPlayerToNormalSpriteColl_01AB31(k);
  Spr02F_PortableSpringboard_01E6F0(k);
}

void Spr02F_PortableSpringboard_01E6F0(uint8 k) {  // 01e6f0
  GenericGFXRtDraw4Tiles8x8Square_Entry1(k, 2, kSpr02F_PortableSpringboard_YDispOffset[spr_table1602[k]]);
}

void GenericSmushedSpriteDraw(uint8 k) {  // 01e700
  uint8 drt;

  if ((drt = GetDrawInfo_Bank01_ReturnsTwice(k)) == 0xff)
    return;
  if (!CheckIfNormalSpriteOffScreen(k)) {
    uint8 v2 = R0_;
    OamEnt *oam = get_OamEnt(oam_buf, drt);
    oam[64].xpos = R0_;
    oam[65].xpos = v2 + 8;
    int8 v4 = R1_ + 8;
    oam[64].ypos = R1_ + 8;
    oam[65].ypos = v4;
    uint8 v5 = spr_spriteid[k];
    int8 v6 = -2;
    if (v5 != 62) {
      v6 = -18;
      if (v5 != 0xBD && v5 >= 4) {
        v6 = -57;
        if (v5 < 0xF)
          v6 = 77;
      }
    }
    oam[64].charnum = v6;
    oam[65].charnum = v6;
    int8 v7 = spr_table15f6[k] | sprites_tile_priority;
    oam[64].flags = v7;
    oam[65].flags = v7 | 0x40;
    uint8 v8 = drt >> 2;
    sprites_oamtile_size_buffer[v8 + 64] = 0;
    sprites_oamtile_size_buffer[v8 + 65] = 0;
  }
}

void Spr03E_PSwitch(uint8 k) {  // 01e75b
  if (spr_decrementing_table1564[k] == 1) {
    ow_players_map[0] = spr_decrementing_table1564[k];
    ow_save_buffer[111] = 1;
    spr_current_status[k] = 0;
    ++misc_display_message;
  }
}

void Spr087_LakituCloud(uint8 k) {  // 01e7a4
  if (flag_sprites_locked)
    goto LABEL_2;
  if (timer_despawn_lakitu_cloud && (counter_local_frames & 3) == 0) {
    if (timer_despawn_lakitu_cloud && !--timer_despawn_lakitu_cloud)
      spr_decrementing_table1540[k] = 31;
  }
  uint8 v1 = spr_decrementing_table1540[k];
  if (v1) {
    if (v1 != 1) {
LABEL_2:
      Spr087_LakituCloud_Draw(k);
      return;
    }
    spr_current_status[k] = 0;
    timer_respawn_sprite = -1;
    sprites_sprite_to_respawn = 30;
  } else {
    for (uint8 i = 9; (i & 0x80) == 0; --i) {
      if (spr_current_status[i] == 8 && spr_spriteid[i] == 30) {
        spr_table160e[k] = i;
        Spr087_LakituCloud_01E98D(k);
        R0_ = kSpr087_LakituCloud_CloudYPosOffset[(counter_local_frames >> 3) & 7];
        SetSprXPos(i, GetSprXPos(k));
        SetSprYPos(i, GetSprYPos(k) - R0_);
        spr_decrementing_table154c[k] = 16;
        Spr087_LakituCloud_Draw(k);
        return;
      }
    }
    if (!spr_table00c2[k]) {
      if (spr_table151c[k]) {
        UpdateNormalSpritePosition_X(k);
        UpdateNormalSpritePosition_Y(k);
      }
      if (!spr_decrementing_table154c[k] && CheckPlayerToNormalSpriteColl_ProcessInteract(k) & 1 && (player_yspeed & 0x80) == 0) {
        ++spr_table00c2[k];
        uint8 v3 = player_riding_yoshi_flag ? 34 : 17;
        SetSprYPos(k, player_current_ypos + v3);
        SetSprXPos(k, player_current_xpos);
        spr_yspeed[k] = 16;
        spr_table151c[k] = 16;
        spr_xspeed[k] = player_xspeed;
      }
      goto LABEL_2;
    }
    Spr087_LakituCloud_Draw(k);
    HandleHeldPBalloonAndInLakituCloudMovement(k);
    player_yspeed = spr_yspeed[k] + 3;
    uint8 v4 = (counter_local_frames >> 3) & 7 | (player_riding_yoshi_flag ? 8 : 0);
    SetSprYPos(k, player_current_ypos + kSpr087_LakituCloud_CloudYPosOffset[v4]);
    SetSprXPos(k, player_current_xpos);
    player_in_air_flag = 0;
    ++misc_player_on_solid_sprite;
    ++flag_player_in_lakitus_cloud;
    if ((io_controller_press1 & 0x80) != 0) {
      player_yspeed = -64;
      spr_decrementing_table154c[k] = 16;
      spr_table00c2[k] = 0;
    }
  }
}

void Spr087_LakituCloud_Draw(uint8 k) {  // 01e8ca
  if (GetDrawInfo_Bank01_ReturnsTwice(k) == 0xff)
    return;
  if (!spr_yoffscreen_flag[k]) {
    R12_ = -8;
    R13_ = -4;
    uint8 v1 = 0;
    if (!spr_table00c2[k])
      v1 = 48;
    R14_ = v1;
    misc_scratch7e18b6 = v1;
    R15_ = v1 | 4;
    temp14b0 = R0_;
    temp14b2 = R1_;
    R2_ = (counter_local_frames >> 2) & 0xC;
    R3_ = 3;
    do {
      uint8 v2 = R2_ + R3_;
      OamEnt *oam = get_OamEnt(oam_buf, *(&R12_ + R3_));
      oam[64].xpos = temp14b0 + kSpr087_LakituCloud_XDisp[(uint8)(R2_ + R3_)];
      oam[64].ypos = temp14b2 + kSpr087_LakituCloud_YDisp[v2];
      uint8 v4 = spr_current_slotid;
      oam[64].charnum = 96;
      uint8 v5 = spr_decrementing_table1540[v4];
      if (v5)
        oam[64].charnum = kSpr087_LakituCloud_EvaporatingCloudTiles[v5 >> 3];
      oam[64].flags = sprites_tile_priority;
      --R3_;
    } while ((R3_ & 0x80) == 0);
    uint8 v6 = spr_current_slotid;
    spr_oamindex[spr_current_slotid] = -8;
    FinishOAMWrite(v6, 2, 1);
    spr_oamindex[v6] = misc_scratch7e18b6;
    FinishOAMWrite(v6, 2, 1);
    if (!spr_xoffscreen_flag[v6]) {
      OamEnt *v7 = get_OamEnt(oam_buf, 0);
      v7[2].xpos = temp14b0 + 4;
      v7[2].ypos = temp14b2 + 7;
      v7[2].charnum = 77;
      v7[2].flags = 57;
      sprites_oamtile_size_buffer[2] = 0;
    }
  }
}

void Spr087_LakituCloud_01E98D(uint8 k) {  // 01e98d
  if (!flag_sprites_locked) {
    uint8 v1 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
    spr_table157c[spr_table160e[k]] = v1;
    R0_ = v1;
    uint8 v2 = R0_;
    if (timer_disappearing_sprite) {
      uint8 v10 = R0_;
      uint8 ka = k;
      uint8 v3 = spr_table160e[k];
      SubOffscreen_Bank01_Entry1(v3);
      uint8 v4 = spr_current_status[v3];
      k = ka;
      if (!v4)
        spr_current_status[ka] = 0;
      v2 = v10 ^ 1;
    }
    if ((counter_global_frames & 1) == 0) {
      uint8 v5 = spr_xspeed[k];
      if (v5 != kSpr087_LakituCloud_MaxLakituXSpeed[v2])
        spr_xspeed[k] = kGenericNormalSpriteAccelerationTable[v2] + v5;
      uint8 v6 = spr_table1534[k] & 1;
      uint8 v7 = kGenericNormalSpriteAccelerationTable[v6] + spr_yspeed[k];
      spr_yspeed[k] = v7;
      if (v7 == kSpr087_LakituCloud_MaxLakituYSpeed[v6])
        ++spr_table1534[k];
    }
    uint8 v11 = spr_xspeed[k];
    if (!timer_disappearing_sprite)
      spr_xspeed[k] += 8 * misc_layer1_xdisp;
    UpdateNormalSpritePosition_X(k);
    spr_xspeed[k] = v11;
    UpdateNormalSpritePosition_Y(k);
    uint8 v8 = spr_table160e[k];
    if (!(spr_table151c[v8] | counter_global_frames & 0x7F)) {
      spr_decrementing_table1558[v8] = 32;
      MakeLakituThrowSpiny(k);
    }
  }
}

void MakeLakituThrowSpiny(uint8 k) {  // 01ea21
  uint8 j = FindFreeNormalSpriteSlot_HighPriority();
  if ((j & 0x80) == 0) {
    spr_current_status[j] = 8;
    uint8 v2 = timer_silver_pswitch ? 33 : 20;
    spr_spriteid[j] = v2;
    SetSprXPos(j, GetSprXPos(k));
    SetSprYPos(j, GetSprYPos(k));
    InitializeNormalSpriteRAMTables(j);
    spr_yspeed[j] = -40;
    spr_xspeed[j] = kMakeLakituThrowSpiny_InitialXSpeed[CheckPlayerPositionRelativeToSprite_Bank01_X(j)];
    if (spr_spriteid[j] == 33)
      spr_table15f6[j] = 2;
  }
}

void PlayerGFXRt_01EA70() {  // 01ea70
  if (yoshi_stray_yoshi_flag) {
    player_relative_yposition_during_screen_shake = 0;
    yoshi_key_in_mouth_flag = 0;
    uint8 v0 = spr_current_slotid;
    spr_current_slotid = yoshi_stray_yoshi_flag - 1;
    PlayerGFXRt_01EA8F(yoshi_stray_yoshi_flag - 1);
    spr_current_slotid = v0;
  }
}

void PlayerGFXRt_01EA8F(uint8 k) {  // 01ea8f
  uint8 v1, v2;

  if (misc_currently_active_boss_end_cutscene | growing_yoshi_timer)
    goto LABEL_35;
  yoshi_ducking_flag = 0;
  if (spr_table00c2[k] < 2) {
    v2 = 0;
    v1 = player_xspeed;
    if (!player_xspeed) {
      spr_table1570[k] = 0;
      goto LABEL_14;
    }
    if ((player_xspeed & 0x80) != 0)
      v1 = -player_xspeed;
  } else {
    v1 = 48;
  }
  if (!flag_sprites_locked && (--spr_table1570[k] & 0x80) != 0) {
    spr_table1570[k] = kSpr035_Yoshi_DATA_01EDF5[v1 >> 4];
    if ((--yoshi_walking_frames & 0x80) != 0)
      yoshi_walking_frames = 2;
  }
  v2 = kSpr035_Yoshi_YoshiWalkFrames[yoshi_walking_frames];
  if (spr_table00c2[k] >= 2)
    goto LABEL_31;
LABEL_14:
  if (player_in_air_flag) {
    v2 = 2;
    if ((player_yspeed & 0x80) != 0)
      v2 = 5;
  }
  if (spr_decrementing_table15ac[k])
    v2 = 3;
  if (player_in_air_flag)
    goto LABEL_28;
  if (spr_table151c[k]) {
    v2 = 7;
    if ((io_controller_hold1 & 8) != 0)
      v2 = 6;
    goto LABEL_28;
  }
  if (timer_yoshi_squatting) {
    --timer_yoshi_squatting;
LABEL_27:
    v2 = 4;
    ++yoshi_ducking_flag;
    goto LABEL_28;
  }
  if ((io_controller_hold1 & 4) != 0)
    goto LABEL_27;
LABEL_28:
  if (spr_table00c2[k] != 1 && !spr_table151c[k])
    v2 = 4;
LABEL_31:
  if (player_riding_yoshi_flag && yoshi_in_pipe == 1)
    v2 = ((uint8)(counter_global_frames & 8) >> 3) + 8;
  spr_table1602[k] = v2;
LABEL_35:
  if (spr_table00c2[k] == 1) {
    uint8 v4 = spr_table157c[k];
    SetSprXPos(k, player_xpos + PAIR16(kSpr035_Yoshi_DATA_01EDF3[v4], kSpr035_Yoshi_YoshiPositionX[v4]));
    SetSprYPos(k, player_ypos + 16);
    player_relative_yposition_during_screen_shake = kSpr035_Yoshi_DATA_01EDE4[spr_table1602[k]];
    player_riding_yoshi_flag = (spr_table1602[k] == 3) ? 2 : 1;
    yoshi_carry_over_levels_flag = 1;
    yoshi_current_yoshi_color = spr_table15f6[k];
    player_facing_direction = spr_table157c[k] ^ 1;
  }
  uint8 v8 = sprites_tile_priority;
  if (!player_riding_yoshi_flag || !yoshi_in_pipe)
    goto LABEL_43;
  if (!flag_about_to_warp_in_pipe) {
    sprites_tile_priority = 16;
LABEL_43:
    Spr035_Yoshi_HandleOffYoshi(k);
  }
  sprites_tile_priority = v8;
}

void Spr035_Yoshi(uint8 k) {  // 01ebca
  player_freeze_player_flag = 0;
  flag_display_yoshis_wings = yoshi_yoshi_has_wings;
  yoshi_yoshi_has_wings = 0;
  yoshi_stomp_ground_flag = 0;
  unusedram_7e191b = 0;
  if (spr_current_status[k] != 8) {
    yoshi_carry_over_levels_flag = 0;
    Spr035_Yoshi_HandleOffYoshi(k);
    return;
  }
  sprites_yoshi_slot_index = k + 1;
  if (!player_riding_yoshi_flag) {
    SubOffscreen_Bank01_Entry1(k);
    if (!spr_current_status[k]) {
      if (!in_yoshi_wings_bonus_area)
        yoshi_carry_over_levels_flag = 0;
      return;
    }
  }
  if ((!player_riding_yoshi_flag || !yoshi_in_pipe) && !yoshi_egg_lay_timer) {
    uint8 v1 = growing_yoshi_timer;
    if (growing_yoshi_timer) {
      --growing_yoshi_timer;
      flag_sprites_locked = v1;
      player_freeze_player_flag = v1;
      if (v1 == 1) {
        flag_sprites_locked = 0;
        player_freeze_player_flag = 0;
        v1 = misc_intro_level_flag | flag_yoshi_saved | (ow_players_map[player_current_character] - 1);
        if (!v1) {
          ++flag_yoshi_saved;
          v1 = 3;
          misc_display_message = 3;
        }
      }
      spr_table1602[k] = kSpr035_Yoshi_GrowingAniSequence[(uint8)(v1 - 1) >> 3];
      return;
    }
    if (flag_sprites_locked) {
      sub_1EC50();
      return;
    }
  }
  if (player_in_air_flag)
    goto LABEL_27;
  uint8 v2 = yoshi_egg_lay_timer;
  if (!yoshi_egg_lay_timer)
    goto LABEL_27;
  --yoshi_egg_lay_timer;
  if (v2 == 1) {
    flag_sprites_locked = 0;
LABEL_27:
    if (spr_table00c2[k] != 1) {
      HandleNormalSpriteGravity(k);
      if (CheckNormalSpriteLevelColl_Floor(k)) {
        SetNormalSpriteYSpeedBasedOnSlope(k);
        if (spr_table00c2[k] < 2) {
          spr_xspeed[k] = 0;
          spr_yspeed[k] = -16;
        }
      }
      SetFacingDirectionBasedOnSpeed(k);
      if (CheckNormalSpriteLevelColl_Wall(k))
        ChangeNormalSpriteDirection_FlipXSpeedAndDirection(k);
      SetHiLo(&R10_, &R4_, GetSprXPos(k) + 4);
      SetHiLo(&R11_, &R5_, GetSprYPos(k) + 19);
      R7_ = 8;
      R6_ = 8;
      StandardSpriteToSpriteCollisionChecks_GetMarioClipping();
      if (StandardSpriteToSpriteCollisionChecks_CheckContact() && player_in_air_flag &&
          !(player_riding_yoshi_flag | player_carrying_something_flag1) && (player_yspeed & 0x80) == 0) {
        Spr035_Yoshi_01EDCE(k, 1);
        player_xspeed = 0;
        player_yspeed = 0;
        timer_yoshi_squatting = 12;
        spr_table00c2[k] = 1;
        io_sound_ch2 = 2;
        io_sound_ch3 = 31;
        Spr035_Yoshi_SpawnUnusedYoshiSmoke(k);
        spr_decrementing_table163e[k] = 32;
        ++counter_consecutive_enemies_stomped;
      }
    }
    if (spr_table00c2[k] == 1) {
      Spr035_Yoshi_01F622(k);
      if ((io_controller_hold1 & 3) != 0 && (io_controller_hold1 & 3) - 1 != spr_table157c[k] &&
          !(yoshi_ducking_flag | (uint8)(spr_table151c[k] | spr_decrementing_table15ac[k]))) {
        spr_decrementing_table15ac[k] = 16;
      }
      if (timer_inflate_from_pballoon || (io_controller_press2 & 0x80) != 0) {
        spr_decrementing_table1fe2[k] = 2;
        spr_table00c2[k] = 0;
        io_sound_ch2 = 3;
        yoshi_carry_over_levels_flag = 0;
        spr_xspeed[k] = player_xspeed;
        uint8 v8 = -96;
        if (!player_in_air_flag) {
          player_xspeed = kSpr035_Yoshi_DismountXSpeed[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
          v8 = -64;
        }
        player_yspeed = v8;
        player_riding_yoshi_flag = 0;
        spr_yspeed[k] = 0;
        Spr035_Yoshi_01EDCC(k);
      }
    }
    return;
  }
  ++player_freeze_player_flag;
  flag_sprites_locked = sub_1EC50();

  if (v2 == 2) {
    uint8 slot = FindFreeNormalSpriteSlot_HighPriority();
    if ((slot & 0x80) == 0) {
      spr_current_status[slot] = 9;
      spr_spriteid[slot] = 44;
      R15_ = spr_table157c[k];
      SetSprXPos(slot, GetSprXPos(k) + PAIR16(kSpr035_Yoshi_YoshiEggInitialXOffsetHi[spr_table157c[k]], kSpr035_Yoshi_YoshiEggInitialXOffsetLo[spr_table157c[k]]));
      SetSprYPos(slot, GetSprYPos(k) + 8);
      InitializeNormalSpriteRAMTables(slot);
      spr_xspeed[slot] = kSpr035_Yoshi_YoshiEggInitialXSpeed[R15_];
      spr_yspeed[slot] = -16;
      spr_decrementing_table154c[slot] = 16;
      spr_table151c[slot] = yoshi_laid_egg_contents;
    }
  }
}

uint8 sub_1EC50() {  // 01ec50
  if (!player_riding_yoshi_flag)
    return 0;
  player_relative_yposition_during_screen_shake = 6;
  return 6;
}

void Spr035_Yoshi_01EDCC(uint8 k) {  // 01edcc
  Spr035_Yoshi_01EDCE(k, 0);
}

void Spr035_Yoshi_01EDCE(uint8 k, uint8 j) {  // 01edce
  player_ypos = GetSprYPos(k) - kSpr035_Yoshi_DATA_01EDE2[j];
  player_current_ypos = player_ypos;
}

void Spr035_Yoshi_HandleOffYoshi(uint8 k) {  // 01ee61
  uint8 v6 = spr_table1602[k];
  if (spr_decrementing_table15ac[k] == 8 && !(flag_sprites_locked | yoshi_in_pipe)) {
    player_facing_direction = spr_table157c[k];
    spr_table157c[k] = player_facing_direction ^ 1;
  }
  if (yoshi_in_pipe == 2)
    spr_table1602[k] = 3;
  Spr035_Yoshi_01EF18(k);
  OamEnt *oam = get_OamEnt(oam_buf, R14_);
  R0_ = oam[64].charnum;
  R1_ = 0;
  oam[64].charnum = 6;
  OamEnt *v2 = get_OamEnt(oam_buf, spr_oamindex[k]);
  R2_ = v2[64].charnum;
  R3_ = 0;
  v2[64].charnum = 8;
  *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[6] = 32 * R0_W + 0x8500;
  *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[6] = *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[6] + 512;
  *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[8] = 32 * R2_W + 0x8500;
  *(uint16 *)&graphics_dynamic_sprite_pointers_bottom_lo[8] = *(uint16 *)&graphics_dynamic_sprite_pointers_top_lo[8] + 512;
  spr_table1602[k] = v6;
  Spr035_Yoshi_01F0A2(k);
  if (flag_display_yoshis_wings >= 2) {
    uint8 v3 = player_riding_yoshi_flag;
    if (player_riding_yoshi_flag) {
      if (player_in_air_flag) {
        v3 = ((player_yspeed & 0x80) == 0) ? counter_local_frames >> 4 & 1 : counter_local_frames >> 2 & 1;
        if (!v3)
          io_sound_ch3 = 33;
      } else {
        uint8 v4 = player_xspeed;
        if ((player_xspeed & 0x80) != 0)
          v4 = -player_xspeed;
        v3 = v4 >= 0x28;
      }
    }
    Spr035_Yoshi_DrawYoshisWings(k, v3);
  }
}

void Spr035_Yoshi_01EF18(uint8 k) {  // 01ef18
  int8 v9, v11;

  uint8 v1 = spr_table1602[k];
  misc_scratch7e185e = v1;
  R15_ = spr_table1602[k] = kSpr035_Yoshi_YoshiHeadTiles[v1];
  uint16 old_x = GetSprXPos(k), old_y = GetSprYPos(k);
  AddSprYPos(k, kSpr035_Yoshi_YoshiPositionY[v1]);
  uint8 v4 = v1 + (spr_table157c[k] ? 13 : 0);
  AddSprXPos(k, PAIR16(kSpr035_Yoshi_DATA_01EE2D[v4], kSpr035_Yoshi_YoshiHeadXDisp[v4]));
  uint8 v15 = spr_oamindex[k];
  if (yoshi_in_pipe | spr_decrementing_table15ac[k])
    spr_oamindex[k] = 4;
  R14_ = spr_oamindex[k];
  GenericGFXRtDraw1Tile16x16(k);
  OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
  oam[64].ypos += kSpr035_Yoshi_YoshiHeadYDisp[misc_scratch7e185e];
  spr_oamindex[k] = v15 + 4;
  SetSprXPos(k, old_x);
  spr_table1602[k] = kSpr035_Yoshi_YoshiBodyTiles[misc_scratch7e185e];
  AddSprYPos(k, 16);
  GenericGFXRtDraw1Tile16x16(k);
  SetSprYPos(k, old_y);
  uint8 v7 = R14_;
  if ((R15_ & 0x80) != 0)
    get_OamEnt(oam_buf, R14_)[64].ypos = -16;
  uint8 v8 = spr_table00c2[k];
  if (!v8) {
    if ((counter_local_frames & 0x30) == 0) {
      v9 = 42;
LABEL_23:
      get_OamEnt(oam_buf, v7)[64].charnum = v9;
      goto LABEL_24;
    }
LABEL_17:
    if (spr_table1594[k] == 3 || spr_table151c[k] && get_OamEnt(oam_buf, v7)[64].charnum != 36)
      get_OamEnt(oam_buf, v7)[64].charnum = 42;
    if (timer_yoshi_tongue_init)
      goto LABEL_22;
    goto LABEL_24;
  }
  if (v8 != 2 || misc_currently_active_boss_end_cutscene | spr_table151c[k])
    goto LABEL_17;
  if ((counter_local_frames & 0x10) != 0) {
LABEL_22:
    v9 = 12;
    goto LABEL_23;
  }
LABEL_24:;
  uint8 v10 = spr_decrementing_table1564[k];
  if (yoshi_swallow_timer) {
    if (yoshi_swallow_timer >= 0x26 || (v10 = counter_local_frames & 0x18, (counter_local_frames & 0x18) != 0)) {
LABEL_33:
      v11 = 4;
      goto LABEL_34;
    }
  }
  v10 = spr_decrementing_table1564[k];
  if (!v10)
    return;
  v11 = 0;
  if (v10 >= 0xF) {
    if (v10 >= 0x1C) {
      if (v10 == 28) {
        uint8 v20 = R14_;
        Spr035_Yoshi_ChangeBerryIntoBushTile();
        Spr035_Yoshi_HandleYoshiSwallowingSomething();
        R14_ = v20;
      }
      ++player_freeze_player_flag;
      v10 = 0;
      v11 = 42;
      goto LABEL_34;
    }
    goto LABEL_33;
  }
LABEL_34:
  get_OamEnt(oam_buf, R14_)[64].charnum = v11;
  if (v10 < 0xF && v10 >= 5) {
    uint8 v12 = v10 - 5;
    if (spr_table157c[k])
      v12 += 10;
    if (spr_table1602[k] == 10)
      v12 += 20;
    R2_ = v12;
    if (!CheckIfNormalSpriteOffScreen(k)) {
      R0_ = spr_xpos_lo[k] - mirror_current_layer1_xpos;
      R1_ = spr_ypos_lo[k] - mirror_current_layer1_ypos;
      OamEnt *v14 = get_OamEnt(oam_buf, 0);
      v14[64].xpos = kSpr035_Yoshi_YoshiThroatXDisp[R2_] + R0_;
      v14[64].ypos = kSpr035_Yoshi_YoshiThroatYDisp[R2_] + R1_;
      v14[64].charnum = 63;
      v14[64].flags = get_OamEnt(oam_buf, spr_oamindex[k])[64].flags | 1;
      sprites_oamtile_size_buffer[64] = 0;
    }
  }
}

void Spr035_Yoshi_01F0A2(uint8 k) {  // 01f0a2
  if (spr_table00c2[k] == 1)
    Spr035_Yoshi_CheckBerryTileCollisionWithAdultYoshiMouth(k);
  if (flag_display_yoshis_wings != 1) {
    if (timer_yoshi_tongue_is_out == 16 && !timer_yoshi_tongue_init)
      timer_yoshi_tongue_init = 6;
    kSpr035_Yoshi_Ptrs01F0CB[spr_table1594[k]](k);
  }
}

void Spr035_Yoshi_HandleYoshiSwallowingSomething() {  // 01f0d3
  io_sound_ch1 = 6;
  GiveCoins_OneCoin();
  uint8 v0 = yoshi_berry_being_eaten;
  if (yoshi_berry_being_eaten) {
    yoshi_berry_being_eaten = 0;
    if (v0 == 1) {
      if (++counter_eaten_red_berries != 10)
        return;
      counter_eaten_red_berries = 0;
      yoshi_laid_egg_contents = 116;
      yoshi_egg_lay_timer = 32;
      return;
    }
    if (v0 != 3) {
      if (++counter_eaten_pink_berries != 2)
        return;
      counter_eaten_pink_berries = 0;
      yoshi_laid_egg_contents = 106;
      yoshi_egg_lay_timer = 32;
      return;
    }
    io_sound_ch3 = 41;
    uint8 v2 = counter_timer_tens + 2;
    if ((uint8)(counter_timer_tens + 2) >= 0xA) {
      v2 -= ((uint8)(counter_timer_tens + 2) < 0xA) + 10;
      ++counter_timer_hundreds;
    }
    counter_timer_tens = v2;
  }
}

void Spr035_Yoshi_MouthState03_Spitting(uint8 k) {  // 01f12e
  if (!spr_decrementing_table1558[k])
    spr_table1594[k] = 0;
}

void Spr035_Yoshi_MouthState00(uint8 k) {  // 01f14b
  if (in_yoshi_wings_bonus_area)
    yoshi_yoshi_has_wings = 2;
  if (yoshi_swallow_timer) {
    uint8 v1 = spr_table160e[k];
    uint8 v2 = spr_spriteid[v1];
    if (v2 == 0x80)
      ++yoshi_key_in_mouth_flag;
    if (v2 < 0xD) {
      uint8 v3 = 3;
      if (!spr_table187b[v1]) {
        R0_ = 4 * kSpr035_Yoshi_YoshiAbilityIndex[(spr_table15f6[k] >> 1) & 7];
        v3 = kSpr035_Yoshi_YoshiShellAbility[R0_ | kSpr035_Yoshi_YoshiAbilityIndex[(spr_table15f6[v1] >> 1) & 7]];
      }
      yoshi_yoshi_has_wings = v3 & 2;
      yoshi_stomp_ground_flag = v3 & 1;
    }
  }
  if ((counter_local_frames & 3) != 0 || !yoshi_swallow_timer || (--yoshi_swallow_timer, yoshi_swallow_timer)) {
    if (timer_yoshi_tongue_init) {
      if (!--timer_yoshi_tongue_init) {
        ++spr_table1594[k];
        spr_table151c[k] = 0;
        spr_table160e[k] = -1;
        spr_decrementing_table1564[k] = 0;
      }
    } else if (spr_table00c2[k] == 1 && (io_controller_press1 & 0x40) != 0) {
      if (yoshi_swallow_timer) {
        yoshi_swallow_timer = 0;
        uint8 j = spr_table160e[k];
        SetSprXPos(j, GetSprXPos(k) + PAIR16(kSpr035_Yoshi_DATA_01F307[spr_table157c[k]], kSpr035_Yoshi_DATA_01F305[spr_table157c[k]]));
        SetSprYPos(j, GetSprYPos(k));
        spr_table00c2[j] = 0;
        spr_table15d0[j] = 0;
        spr_table1626[j] = 0;
        spr_current_status[j] = yoshi_ducking_flag ? 9 : 10;
        uint8 v7 = spr_table157c[k];
        spr_table157c[j] = v7;
        uint8 v8 = v7 + (yoshi_ducking_flag ? 2 : 0);
        spr_xspeed[j] = kSpr035_Yoshi_SpatOutSpriteXSpeed[v8];
        spr_yspeed[j] = 0;
        spr_decrementing_table1558[k] = 16;
        spr_table1594[k] = 3;
        spr_table160e[k] = -1;
        if (spr_spriteid[j] < 0xD && (spr_table187b[j] || (spr_table15f6[j] & 0xE) == 8 || (spr_table15f6[k] & 0xE) == 8)) {
          spr_current_status[j] = 0;
          R0_ = 2;
          Spr035_Yoshi_01F295(j);
          Spr035_Yoshi_01F295(j);
          Spr035_Yoshi_01F295(j);
          io_sound_ch3 = 23;
        } else {
          Spr035_Yoshi_01F2DF(j);
        }
      } else {
        Spr035_Yoshi_01F309();
      }
    }
  } else {
    spr_current_status[spr_table160e[k]] = 0;
    spr_table160e[k] = -1;
    spr_decrementing_table1564[k] = 27;
    Spr035_Yoshi_HandleYoshiSwallowingSomething();
  }
}

void Spr035_Yoshi_01F295(uint8 k) {  // 01f295
  uint8 j = CheckAvailableExtendedSpriteSlot(k);
  ext_spr_spriteid[j] = 17;
  SetHiLo(&ext_spr_xpos_hi[j], &ext_spr_xpos_lo[j], GetSprXPos(k));
  SetHiLo(&ext_spr_ypos_hi[j], &ext_spr_ypos_lo[j], GetSprYPos(k));
  ext_spr_table1779[j] = 0;
  uint8 v2 = spr_table157c[k] & 1;
  uint8 v3 = R0_;
  uint8 v4 = kSpr035_Yoshi_YoshiFireballInitialXSpeed[R0_];
  ext_spr_xspeed[j] = v2 ? -v4 : v4;
  ext_spr_yspeed[j] = kSpr035_Yoshi_YoshiFireballInitialYSpeed[v3];
  ext_spr_decrementing_table176f[j] = -96;
  --R0_;
}

void Spr035_Yoshi_01F2DF(uint8 j) {  // 01f2df
  io_sound_ch1 = 32;
  if ((spr_property_bits1686[j] & 0x40) != 0) {
    spr_spriteid[j] = kGenericSpriteToSpawnTable[spr_spriteid[j]];
    InitializeNormalSpriteRAMTables_YXPPCCCTAndPropertyTables(j);
  }
}

void Spr035_Yoshi_01F309() {  // 01f309
  timer_yoshi_tongue_is_out = 18;
  io_sound_ch3 = 33;
}

void Spr035_Yoshi_MouthState01_ExtendTongue(uint8 k) {  // 01f314
  uint8 v1 = spr_table151c[k] + 3;
  spr_table151c[k] = v1;
  if (v1 >= 0x20) {
    spr_decrementing_table1558[k] = 8;
    ++spr_table1594[k];
  }
  Spr035_Yoshi_01F3FE(k);
  Spr035_Yoshi_01F4B2(k);
}

void Spr035_Yoshi_MouthState02_RetractTongue(uint8 k) {  // 01f332
  uint8 v5;

  if (!spr_decrementing_table1558[k]) {
    int8 v1 = spr_table151c[k] - 4;
    if (v1 < 0) {
      spr_table151c[k] = 0;
      spr_table1594[k] = 0;
      uint8 v2 = spr_table160e[k];
      if ((v2 & 0x80) == 0) {
        if ((spr_property_bits1686[v2] & 2) != 0) {
          spr_current_status[v2] = 7;
          yoshi_swallow_timer = -1;
          if (spr_spriteid[v2] < 0xD)
            spr_spriteid[v2] = kGenericSpriteToSpawnTable[spr_spriteid[v2]];
        } else {
          spr_current_status[v2] = 0;
          spr_decrementing_table1564[k] = 27;
          spr_table160e[k] = -1;
          R0_ = v2;
          if (spr_spriteid[v2] == 0x9D && spr_table00c2[v2] == 3) {
            spr_spriteid[v2] = 116;
            spr_property_bits167a[v2] |= 0x40;
          }
          uint8 v3 = spr_spriteid[v2];
          if (v3 == 0x81) {
            v3 = kSprXXX_PowerUps_ChangingItemSprite[(spr_table187b[v2] >> 6) & 3];
            spr_spriteid[R0_] = v3;
          }
          uint8 v4 = R0_;
          if (spr_property_bits167a[v4] & 0x40) {
            spr_table00c2[v4] = 0;
            SprXXX_PowerUps_01C4BF(v4);
            spr_table1602[k] = kSpr035_Yoshi_DATA_01F3D9[yoshi_ducking_flag];
          } else if (v3 == 126 && (v5 = spr_table00c2[v4]) != 0) {
            if (v5 == 2) {
              player_current_state = 8;
              io_sound_ch3 = 3;
            }
            Spr035_Yoshi_01F6CD(v4);
          } else {
            Spr035_Yoshi_HandleYoshiSwallowingSomething();
          }
        }
      }
    } else {
      spr_table151c[k] = v1;
    }
  }
  Spr035_Yoshi_01F3FE(k);
  Spr035_Yoshi_01F4B2(k);
}

void Spr035_Yoshi_Return01F3FD() {  // 01f3fd
  ;
}

void Spr035_Yoshi_01F3FE(uint8 k) {  // 01f3fe
  if (!(yoshi_in_pipe | (uint8)(spr_yoffscreen_flag[k] | spr_xoffscreen_flag[k]))) {
    uint8 v1 = spr_table1602[k];
    misc_scratch7e185e = kSpr035_Yoshi_DATA_01F61A[v1];
    R1_ = spr_ypos_lo[k] + misc_scratch7e185e - mirror_current_layer1_ypos;
    if (!spr_table157c[k])
      v1 += 8;
    R13_ = kSpr035_Yoshi_DATA_01F60A[v1];
    int t = (uint8)(spr_xpos_lo[k] - mirror_current_layer1_xpos) + R13_;
    R0_ = t;
    if (spr_table157c[k] ? !(t & 0x100) : (t & 0x100))
      return;
    WriteReg(WRDIVH, spr_table151c[k]);
    WriteReg(WRDIVL, 0);
    WriteReg(WRDIVB, 4);
    R7_ = spr_table157c[k];
    uint8 Reg = ReadReg(RDDIVH);
    if (R7_ & 1)
      Reg = -Reg;
    R5_ = Reg;
    R6_ = 4;
    uint8 v3 = 12;
    do {
      OamEnt *oam = get_OamEnt(oam_buf, v3);
      oam->xpos = R0_;
      uint16 t = R5_ + R0_;
      R0_ = t;
      if (sign8(R5_) ? (t & 0x100) == 0 : (t & 0x100) != 0)
        break;
      oam->ypos = R1_;
      int8 v6 = 118;
      if (!R6_)
        v6 = 102;
      oam->charnum = v6;
      int8 v7 = 9;
      if (!(R7_ & 1))
        v7 = 73;
      oam->flags = sprites_tile_priority | v7;
      sprites_oamtile_size_buffer[v3 >> 2] = 0;
      v3 += 4;
      --R6_;
    } while ((R6_ & 0x80) == 0);
  }
}

void Spr035_Yoshi_01F4B2(uint8 k) {  // 01f4b2
  int8 v8;

  if ((spr_table160e[k] & 0x80) != 0) {
    if ((R13_ & 0x80) != 0)
      v8 = R13_ - spr_table151c[k];
    else
      v8 = spr_table151c[k] + R13_;
    SetHiLo(&R8_, &R0_, GetSprXPos(k) + (int8)v8);
    SetHiLo(&R9_, &R1_, GetSprYPos(k) + (uint8)(misc_scratch7e185e + 2));
    R2_ = 8;
    R3_ = 4;
    for (uint8 i = 11; (i & 0x80) == 0; --i) {
      sprites_second_tracked_sprite_index = i;
      if (i != spr_current_slotid && (spr_table160e[k] & 0x80) != 0 && spr_current_status[i] >= 8 && !spr_table1632[i]) {
        Spr035_Yoshi_TryEatSprite(k, i);
      }
    }
    CheckBerryTileCollisionWithYoshiTongue();
  } else {
    uint8 v2;
    if ((R13_ & 0x80) != 0)
      v2 = R13_ - spr_table151c[k];
    else
      v2 = spr_table151c[k] + R13_;
    uint8 j = spr_table160e[k];
    SetSprXPos(j, GetSprXPos(k) + (int8)(v2 - 4));
    R0_ = -4;
    if ((spr_property_bits1662[j] & 0x40) == 0 && (spr_property_bits190f[j] & 0x20) != 0)
      R0_ = -8;
    uint8 v6 = misc_scratch7e185e + R0_;
    SetSprYPos(j, GetSprYPos(k) + (int8)v6);
    spr_yspeed[j] = 0;
    spr_xspeed[j] = 0;
    spr_table15d0[j] = 1;
  }
}

void Spr035_Yoshi_TryEatSprite(uint8 k, uint8 j) {  // 01f58e
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(j);
  if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
    if (spr_property_bits1686[j] & 1) {
      io_sound_ch1 = 1;
      return;
    }
    if (spr_spriteid[j] == 112) {
      misc_scratch7e185e = j;
      Spr070_Pokey_RemovePokeySegment(j, R1_ - spr_ypos_lo[j]);
      j = FindFreeNormalSpriteSlot_HighPriority();
      if ((j & 0x80) != 0)
        return;
      spr_current_status[j] = 8;
      spr_spriteid[j] = 112;
      SetSprXPos(j, PAIR16(R8_, R0_));
      SetSprYPos(j, PAIR16(R9_, R1_));
      InitializeNormalSpriteRAMTables(j);
      spr_table00c2[j] = R13_ & spr_table00c2[misc_scratch7e185e];
      spr_table1534[j] = 1;
    }
    spr_table160e[k] = j;
    spr_table1594[k] = 2;
    spr_decrementing_table1558[k] = 10;
  }
}

void Spr035_Yoshi_01F622(uint8 k) {  // 01f622
  if (!(flag_sprites_locked | spr_decrementing_table163e[k])) {
    uint8 v1 = 11;
    do {
      sprites_second_tracked_sprite_index = v1;
      if (((counter_global_frames ^ v1) & 1) == 0 && v1 != spr_table160e[k] && v1 != spr_current_slotid && spr_current_status[v1] >= 8 &&
          spr_current_status[v1] != 9 && !(spr_table1632[v1] | spr_table15d0[v1] | spr_property_bits167a[v1] & 2)) {
        Spr035_Yoshi_01F668(k, v1);
      }
      v1 = sprites_second_tracked_sprite_index - 1;
    } while ((int8)(sprites_second_tracked_sprite_index - 1) >= 0);
  }
}

void Spr035_Yoshi_01F668(uint8 k, uint8 j) {  // 01f668
  uint8 v6;
  uint8 ka = k;
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingB(j);
  StandardSpriteToSpriteCollisionChecks_GetSpriteClippingA(k);
  if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
    uint8 v2 = spr_spriteid[j];
    if (v2 != 0x9D) {
      if (v2 == 21 || v2 == 22) {
        if (!spr_table164a[j]) {
LABEL_9:
          KickHelplessSprite(j);
          return;
        }
      } else if (v2 < 4 && v2 != 2 && (spr_decrementing_table163e[j] & 0x80) != 0) {
        goto LABEL_9;
      }
      if (spr_spriteid[j] != 0xBF || !sign8(player_ypos - spr_ypos_lo[j] + 24)) {
        uint8 v3 = spr_spriteid[j];
        if (v3 == 126) {
          uint8 v4 = spr_table00c2[j];
          if (v4) {
            if (v4 == 2) {
              player_current_state = 8;
              io_sound_ch3 = 3;
            }
            Spr035_Yoshi_01F6CD(j);
          }
        } else if ((v3 != 78 && v3 != 77 || spr_table00c2[j] >= 2) && !sign8(R5_ + 13 - R1_)) {
          if (spr_current_status[j] != 10 ||
              (R0_ = CheckPlayerPositionRelativeToSprite_Bank01_X(j), v6 = spr_xspeed[j], k = ka, ((4 * v6 + __CFSHL__(v6, 1)) & 1) == R0_)) {
            if (!timer_star_power) {
              spr_decrementing_table163e[k] = 16;
              io_sound_ch2 = 3;
              io_sound_ch3 = 19;
              spr_table00c2[k] = 2;
              player_riding_yoshi_flag = 0;
              player_yspeed = -64;
              player_xspeed = 0;
              spr_xspeed[k] = kSpr035_Yoshi_PanicXSpeed[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
              spr_table1594[k] = 0;
              spr_table151c[k] = 0;
              timer_yoshi_tongue_init = 0;
              yoshi_carry_over_levels_flag = 0;
              timer_player_hurt = 48;
              Spr035_Yoshi_01EDCC(k);
            }
          }
        }
      }
    }
  }
}

void Spr035_Yoshi_01F6CD(uint8 j) {  // 01f6cd
  unusedram_7e14aa = 64;
  yoshi_yoshi_has_wings = 2;
  spr_current_status[j] = 0;
}

void PrepareToHatchNormalSpriteYoshiEgg_Entry2(uint8 k) {  // 01f74c
  spr_current_status[k] = 8;
  PrepareToHatchNormalSpriteYoshiEgg(k);
}

void PrepareToHatchNormalSpriteYoshiEgg(uint8 k) {  // 01f751
  spr_decrementing_table1540[k] = 32;
  io_sound_ch3 = 10;
}

void Spr02C_YoshiEgg(uint8 k) {  // 01f764
  if (spr_table187b[k]) {
    if (!CheckIfNormalSpriteOffScreen(k)) {
      CheckPlayerPositionRelativeToSprite_Bank01_X(k);
      if ((uint8)(R15_ + 32) < 0x40) {
        spr_table187b[k] = 0;
        PrepareToHatchNormalSpriteYoshiEgg(k);
        spr_table151c[k] = yoshi_stray_yoshi_flag ? 120 : 45;
      }
    }
    GenericGFXRtDraw1Tile16x16(k);
    get_OamEnt(oam_buf, spr_oamindex[k])[64].charnum = 0;
  } else {
    uint8 v2 = spr_decrementing_table1540[k];
    if (v2) {
      uint8 v3 = v2 >> 3;
      uint8 v8 = kSpr02C_YoshiEgg_YoshiEggTiles[v3];
      uint8 v7 = kSpr02C_YoshiEgg_DATA_01F75C[v3];
      GenericGFXRtDraw1Tile16x16(k);
      uint8 v4 = spr_oamindex[k];
      R0_ = v7;
      OamEnt *oam = get_OamEnt(oam_buf, v4);
      oam[64].flags = v7 | oam[64].flags & 0xFE;
      oam[64].charnum = v8;
    } else {
      Spr02C_YoshiEgg_01F7C8(k);
      uint8 v6 = spr_table151c[k];
      spr_spriteid[k] = v6;
      if (v6 == 53) {
        InitializeNormalSpriteRAMTables(k);
        ProcessStunnedNormalSprite_StunnedBabyYoshi_01A2B5(k);
      } else if (v6 == 45) {
        spr_current_status[k] = 9;
        uint8 v9 = spr_table15f6[k] & 0xE;
        InitializeNormalSpriteRAMTables(k);
        R0_ = v9;
        spr_table15f6[k] = v9 | spr_table15f6[k] & 0xF1;
      } else {
        InitializeNormalSpriteRAMTables(k);
      }
    }
  }
}

void Spr02C_YoshiEgg_01F7C8(uint8 k) {  // 01f7c8
  if (!CheckIfNormalSpriteOffScreen(k)) {
    R0_ = spr_xpos_lo[k];
    R2_W = GetSprYPos(k);
    uint8 v1 = 3;
    uint8 j = 11;
    while (1) {
      if (!mextspr_spriteid[j]) {
LABEL_8:
        mextspr_spriteid[j] = 3;
        mextspr_xpos_lo[j] = kSpr02C_YoshiEgg_EggShellInitialXPosLo[v1] + R0_;
        mextspr_ypos_lo[j] = kSpr02C_YoshiEgg_EggShellInitialYPosLo[v1] + R2_;
        mextspr_ypos_hi[j] = R3_;
        mextspr_yspeed[j] = kSpr02C_YoshiEgg_EggShellInitialYSpeed[v1];
        mextspr_xspeed[j] = kSpr02C_YoshiEgg_EggShellInitialXSpeed[v1];
        mextspr_timer[j] = (v1-- << 6) | 0x28;
        if ((v1 & 0x80) != 0)
          return;
      }
      if ((--j & 0x80) != 0) {
        if ((--mextspr_slot_to_overwrite_when_slots_full & 0x80) != 0)
          mextspr_slot_to_overwrite_when_slots_full = 11;
        j = mextspr_slot_to_overwrite_when_slots_full;
        goto LABEL_8;
      }
    }
  }
}

void Spr012_Unused_Init(uint8 k) {  // 01f875
  spr_table1534[k] = SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
}

void Spr012_Unused_Init_Return(uint8 k) {  // 01f87b
  ;
}

void SprXXX_Eeries_Init(uint8 k) {  // 01f87c
  spr_xspeed[k] = kSprXXX_Eeries_Init_XSpeed[CheckPlayerPositionRelativeToSprite_Bank01_X(k)];
  SprXXX_Eeries_Init_SetInitialFrameCounter(k);
}

void SprXXX_Eeries_Init_SetInitialFrameCounter(uint8 k) {  // 01f884
  spr_table1570[k] = GetRand();
}

void SprXXX_Eeries(uint8 k) {  // 01f890
  if (spr_current_status[k] == 8 && !flag_sprites_locked) {
    UpdateNormalSpritePosition_X(k);
    if (spr_spriteid[k] == 57) {
      uint8 v1 = spr_table00c2[k] & 1;
      spr_yspeed[k] = kGenericNormalSpriteAccelerationTable[v1] + spr_yspeed[k];
      if (spr_yspeed[k] == kSprXXX_Eeries_YSpeed[v1])
        ++spr_table00c2[k];
      UpdateNormalSpritePosition_Y(k);
      SubOffscreen_Bank01_Entry4(k);
    } else {
      SubOffscreen_Bank01_Entry1(k);
    }
    CheckPlayerToNormalSpriteCollision(k);
    SetNormalSpriteAnimationFrame(k);
  }
  SetFacingDirectionBasedOnSpeed(k);
  GenericGFXRtDraw1Tile16x16(k);
}

void SprXXX_NonBossBoos_BigBooEntry(uint8 k) {  // 01f8d5
  SubOffscreen_Bank01_Entry2(k);
  sub_1F8E1(k, 0x20);
}

void SprXXX_NonBossBoos_BooEntry(uint8 k) {  // 01f8dc
  SubOffscreen_Bank01_Entry1(k);
  sub_1F8E1(k, 0x10);
}

void sub_1F8E1(uint8 k, uint8 a) {  // 01f8e1
  misc_scratch7e18b6 = a;
  if (spr_current_status[k] == 8 && !flag_sprites_locked) {
    uint8 v2 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
    if (!spr_decrementing_table1540[k]) {
      spr_decrementing_table1540[k] = 32;
      if (spr_table00c2[k] && (uint8)(R15_ + 10) < 0x14)
        goto LABEL_13;
      spr_table00c2[k] = (v2 == player_facing_direction);
    }
    if ((uint8)(R15_ + 10) >= 0x14) {
      uint8 v3 = spr_decrementing_table15ac[k];
      if (v3) {
LABEL_25:
        if (v3 == 16) {
          spr_table157c[k] ^= 1;
          v3 = 16;
        }
        spr_table1602[k] = kSprXXX_NonBossBoos_DATA_01F8D1[v3 >> 3];
        goto LABEL_28;
      }
      if (v2 != spr_table157c[k]) {
        v3 = 31;
        spr_decrementing_table15ac[k] = 31;
        goto LABEL_25;
      }
    }
LABEL_13:
    spr_table1602[k] = 0;
    if (spr_table00c2[k]) {
      spr_table1602[k] = 3;
      uint8 v5 = spr_spriteid[k];

      int8 v4 = 3;
      if (v5 != 40)
        v4 = v5 != 0xAF;
      if ((counter_global_frames & (uint8)v4) == 0) {
        if (!++spr_table1570[k])
          spr_decrementing_table1558[k] = 32;
        if (spr_xspeed[k])
          spr_xspeed[k] += (int8)spr_xspeed[k] < 0 ? 1 : -1;
        if (spr_yspeed[k])
          spr_yspeed[k] += (int8)spr_yspeed[k] < 0 ? 1 : -1;
      }
      goto LABEL_33;
    }
LABEL_28:
    spr_table1570[k] = 0;
    if ((counter_global_frames & 7) == 0) {
      uint8 v8 = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
      uint8 v9 = spr_xspeed[k];
      if (v9 != kSprXXX_NonBossBoos_MaxSpeed[v8])
        spr_xspeed[k] = kGenericNormalSpriteAccelerationTable[v8] + v9;
      int8 v20 = player_current_ypos;
      bool v10 = (uint8)player_current_ypos >= misc_scratch7e18b6;
      LOBYTE(player_current_ypos) = player_current_ypos - misc_scratch7e18b6;
      int8 v18 = HIBYTE(player_current_ypos);
      HIBYTE(player_current_ypos) -= !v10;
      uint8 v11 = CheckPlayerPositionRelativeToSprite_Bank01_Y(k);
      HIBYTE(player_current_ypos) = v18;
      LOBYTE(player_current_ypos) = v20;
      uint8 v12 = spr_yspeed[k];
      if (v12 != kSprXXX_NonBossBoos_MaxSpeed[v11])
        spr_yspeed[k] = kGenericNormalSpriteAccelerationTable[v11] + v12;
    }
LABEL_33:
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
  }
  if (spr_spriteid[k] == 0xAF) {
    int8 v13 = spr_xspeed[k];
    if (v13 < 0)
      v13 = -v13;
    uint8 v14 = 0;
    if ((uint8)v13 >= 8) {
      if (spr_current_status[k] == 8) {
        CheckPlayerToNormalSpriteCollision(k);
        v14 = 0;
      }
    } else {
      int8 v21 = v13;
      uint8 v19 = spr_property_bits1662[k];
      uint8 v17 = spr_property_bits167a[k];
      spr_property_bits167a[k] = v17 | 0x80;
      spr_property_bits1662[k] = 12;
      SolidSpriteBlock(k);
      spr_property_bits167a[k] = v17;
      spr_property_bits1662[k] = v19;
      v14 = 1;
      if ((uint8)v21 < 4)
        v14 = 2;
    }
    spr_table1602[k] = v14;
    GenericGFXRtDraw1Tile16x16(k);
    uint8 v15 = spr_table1602[k];
    OamEnt *oam = get_OamEnt(oam_buf, spr_oamindex[k]);
    oam[64].charnum = kSprXXX_NonBossBoos_BooBlockTiles[v15];
    oam[64].flags = kSprXXX_NonBossBoos_BooBlockProp[v15] | oam[64].flags & 0xF1;
  } else {
    if (spr_current_status[k] == 8)
      CheckPlayerToNormalSpriteCollision(k);
    NormalSpriteBooDraw(k);
  }
}

void Spr0A7_IggyBall(uint8 k) {  // 01fa58
  GenericGFXRtDraw1Tile16x16(k);
  R0_ = kSpr0A7_IggyBall_XFlip[spr_table157c[k]];
  uint8 v1 = spr_oamindex[k];
  uint8 v2 = (counter_local_frames >> 2) & 3;
  OamEnt *oam = get_OamEnt(oam_buf, v1);
  oam[64].charnum = kSpr0A7_IggyBall_Tiles[v2];
  oam[64].flags = R0_ ^ kSpr0A7_IggyBall_Prop[v2];
  if (!flag_sprites_locked) {
    spr_xspeed[k] = kSpr0A7_IggyBall_XSpeed[spr_table157c[k]];
    UpdateNormalSpritePosition_X(k);
    UpdateNormalSpritePosition_Y(k);
    if (sign8(spr_yspeed[k] - 64))
      spr_yspeed[k] += 4;
    if (Spr0A7_IggyBall_CheckTiltingPlatformCollision(k) & 1)
      spr_yspeed[k] = -16;
    CheckPlayerToNormalSpriteCollision(k);
    if (spr_ypos_lo[k] >= 0x44 && spr_ypos_lo[k] < 0x50)
      SprStatus02_Dead_SetNorSprStatus04(k);
  }
}

void Spr029_KoopaKids(uint8 k) {  // 01fac1
  kSpr029_KoopaKids_KoopaKidPtrs[spr_table00c2[k]](k);
}

void Spr029_KoopaKid_IggyLarry(uint8 k) {  // 01faf5
  if (!(spr_decrementing_table154c[k] | flag_sprites_locked)) {
    R0_ = CheckPlayerPositionRelativeToSprite_Bank01_X(k);
    if (((4 * (uint8)misc_m7_rotation + __CFSHL__(misc_m7_rotation, 1)) & 1) == R0_ && (++spr_table1534[k] & 0x7F) == 0)
      spr_decrementing_table1564[k] = 127;
  }
  spr_xoffscreen_flag[k] = 0;
  uint8 v1 = spr_decrementing_table163e[k];
  if (v1) {
    if (v1 == 1) {
      ++misc_currently_active_boss_end_cutscene;
      timer_end_level = -1;
      io_music_ch1 = 11;
      spr_current_status[k] = 0;
    }
    return;
  }
  InitializeNormalSpriteRAMTables_PropertyTables(k);
  if (!flag_sprites_locked) {
    if (spr_table160e[k]) {
      UpdateNormalSpritePosition_X(k);
      UpdateNormalSpritePosition_Y(k);
      if (sign8(spr_yspeed[k] - 64))
        spr_yspeed[k] += 2;
      if ((int8)spr_ypos_lo[k] >= 88) {
        io_sound_ch3 = 32;
        spr_decrementing_table163e[k] = 80;
        DespawnNonBossSprites();
      }
      temp14b8 = spr_xpos_lo[k];
      temp14ba = spr_ypos_lo[k];
      goto LABEL_35;
    }
    UpdateNormalSpritePosition_X(k);
    if (!(spr_decrementing_table1564[k] | counter_global_frames & 0x1F)) {
      uint8 v8 = spr_table157c[k];
      SprXXX_Generic_Init_MakeSpriteFacePlayer(k);
      if (v8 != spr_table157c[k])
        spr_decrementing_table15ac[k] = 16;
    }
    spr_yspeed[k] = 0;
    spr_xspeed[k] = 0;
    R0_ = (uint8)(misc_m7_rotation + ((misc_m7_rotation & 0x80) != 0 ? 8 : 0)) >> 4;
    R1_ = -R0_ & 0xF;
    uint8 v2;
    if (spr_decrementing_table154c[k]) {
      uint8 v3;
      if (HIBYTE(misc_m7_rotation))
        v3 = kSpr029_KoopaKid_IggyLarry_HurtXSpeed[R1_ + 8];
      else
        v3 = -kSpr029_KoopaKid_IggyLarry_HurtXSpeed[R0_ + 8];
      v2 = 4 * v3;
    } else if (HIBYTE(misc_m7_rotation)) {
      if (spr_xpos_lo[k] >= 0x78)
        v2 = -1;
      else
        v2 = 1;
    } else if (spr_xpos_lo[k] < 0x78) {
      v2 = 1;
    } else {
      v2 = -1;
    }
    spr_xspeed[k] = v2;
    ++spr_table1570[k];
    if (spr_xspeed[k])
      ++spr_table1570[k];
    spr_table1602[k] = kSpr029_KoopaKid_IggyLarry_WalkingAnimationFrames[(spr_table1570[k] >> 2) & 0xF];
  }
  Spr029_KoopaKid_IggyLarry_01FD50(k);
  Spr029_KoopaKid_IggyLarry_01FC62(k);
LABEL_35:;
  uint8 v4 = spr_decrementing_table154c[k];
  if (v4) {
    if (v4 >= 0x10 || v4 < 8) {
      spr_table1602[k] = 3;
      Spr029_KoopaKid_IggyLarry_Draw(k);
    } else {
      Spr029_KoopaKid_IggyLarry_InShellDraw(k);
    }
  } else {
    uint8 v9 = spr_table157c[k];
    uint8 v5 = spr_decrementing_table15ac[k];
    if (v5) {
      if (v5 >= 8)
        spr_table157c[k] ^= 1;
      spr_table1602[k] = 6;
    }
    uint8 v6 = spr_decrementing_table1564[k];
    if (v6) {
      uint8 v7 = spr_decrementing_table1564[k];
      spr_table1602[k] = kSpr029_KoopaKid_IggyLarry_ThrowingAnimationFrames[v6 >> 3];
      if (v7 == 40 && !flag_sprites_locked)
        Spr029_KoopaKid_IggyLarry_ThrowBall(k);
    }
    Spr029_KoopaKid_IggyLarry_Draw(k);
    spr_table157c[k] = v9;
  }
}

void Spr029_KoopaKid_IggyLarry_01FC62(uint8 k) {  // 01fc62
  if (!player_current_state && !spr_table160e[k]) {
    if (spr_xpos_lo[k] < 0x20 || spr_xpos_lo[k] >= 0xD8) {
      spr_xpos_lo[k] = temp14b8;
      spr_ypos_lo[k] = temp14ba;
      ++spr_table160e[k];
    }
    R0_ = temp14b8 - 8;
    R1_ = temp14ba + 96;
    R2_ = 15;
    R3_ = 12;
    R8_ = 0;
    R9_ = 0;
    R4_ = player_on_screen_pos_x + 2;
    R5_ = player_on_screen_pos_y + 16;
    R6_ = 12;
    R7_ = 14;
    R10_ = 0;
    R11_ = 0;
    if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
      if (!spr_decrementing_table1558[k]) {
        spr_decrementing_table1558[k] = 8;
        if (player_in_air_flag) {
          io_sound_ch3 = 40;
          BoostMarioSpeed();
          uint8 v3 = spr_xpos_lo[k];
          uint8 v2 = spr_ypos_lo[k];
          spr_xpos_lo[k] = temp14b8 - 8;
          spr_ypos_lo[k] = temp14ba - 16;
          spr_xoffscreen_flag[k] = 0;
          SpawnContactEffectFromAbove(k);
          spr_ypos_lo[k] = v2;
          spr_xpos_lo[k] = v3;
          if (!spr_decrementing_table154c[k])
            spr_decrementing_table154c[k] = 24;
        } else {
          DamagePlayer_Hurt();
        }
      }
    } else {
      for (uint8 i = 10; i != 7; --i) {
        sprites_second_tracked_sprite_index = i;
        if (ext_spr_spriteid[i] == 5) {
          R4_ = ext_spr_xpos_lo[i] - mirror_current_layer1_xpos;
          R10_ = 0;
          R5_ = ext_spr_ypos_lo[i] - mirror_current_layer1_ypos;
          R11_ = 0;
          R6_ = 8;
          R7_ = 8;
          if (StandardSpriteToSpriteCollisionChecks_CheckContact()) {
            ext_spr_spriteid[i] = 1;
            ext_spr_decrementing_table176f[i] = 15;
            io_sound_ch1 = 1;
            spr_decrementing_table154c[k] = 16;
          }
        }
      }
    }
  }
}

void Spr029_KoopaKid_IggyLarry_01FD50(uint8 k) {  // 01fd50
  WORD(temp14b4) = GetSprXPos(k) + 8;
  WORD(temp14b6) = GetSprYPos(k) + 47;
  misc_m7_rotation = ((misc_m7_rotation ^ 0x1FF) + 1) & 0x1FF;
  CheckTiltingPlatformCollision();
  misc_m7_rotation = ((misc_m7_rotation ^ 0x1FF) + 1) & 0x1FF;
}

void Spr029_KoopaKid_IggyLarry_ThrowBall(uint8 k) {  // 01fda7
  uint8 j = 5;
  while (spr_current_status[j]) {
    if ((--j & 0x80) != 0)
      return;
  }
  io_sound_ch1 = 32;
  spr_current_status[j] = 8;
  spr_spriteid[j] = -89;
  InitializeNormalSpriteRAMTables(j);
  uint8 v2 = spr_table157c[k];
  spr_table157c[j] = v2;
  SetSprXPos(j, (uint8)(kSpr029_KoopaKid_IggyLarry_BallXDisp[v2] + temp14b8 - 8));
  SetSprYPos(j, temp14ba - 24);
}

void Spr029_KoopaKid_IggyLarry_Draw(uint8 k) {  // 01febc
  uint8 v1 = spr_table00c2[k];
  R13_ = *((uint8 *)kSpr029_KoopaKid_IggyLarry_TileSize + v1 + 1);
  R5_ = v1;
  uint8 v2 = spr_oamindex[k];
  uint8 v3 = spr_table157c[k];
  int8 v4 = v3 & 1;
  uint8 v5 = v3 >> 1;
  int8 v6 = 0;
  if (v4)
    v6 = 0x80;
  R2_ = ((uint8)((v5 >> 1) + v6) >> 1) & 0x40 ^ 0x40;
  R3_ = 4 * spr_table1602[k];
  int8 v7 = 3;
  int8 v13;
  do {
    v13 = v7;
    uint8 v8 = R3_ + v7;
    uint8 v12 = v8;
    if (R2_)
      v8 += 48;
    OamEnt *oam = get_OamEnt(oam_buf, v2);
    oam[64].xpos = kSpr029_KoopaKid_IggyLarry_XDisp[v8] + temp14b8 - 8;
    oam[64].ypos = kSpr029_KoopaKid_IggyLarry_YDisp[v12] + temp14ba + 96;
    uint8 v10 = kSpr029_KoopaKid_IggyLarry_Tiles[v12];
    oam[64].charnum = v10;
    if (R5_ == 3 && v10 < 5)
      oam[64].charnum = kSpr029_KoopaKid_IggyLarry_IggyTiles[v10 >> 1];
    uint8 v11 = R13_;
    if (oam[64].charnum >= 0x4A)
      v11 = 53;
    oam[64].flags = R2_ | v11;
    sprites_oamtile_size_buffer[(v2 >> 2) + 64] = *((uint8 *)kSpr029_KoopaKid_IggyLarry_TileSize + (v12 & 3));
    v2 += 4;
    v7 = v13 - 1;
  } while (v7 >= 0);
  FinishOAMWrite(k, 0xFF, 3);
}

void Spr029_KoopaKid_IggyLarry_InShellDraw(uint8 k) {  // 01ff5b
  R13_ = *((uint8 *)kSpr029_KoopaKid_IggyLarry_TileSize + spr_table00c2[k] + 1);
  OamEnt *oam = get_OamEnt(oam_buf, 0x70);
  oam[64].xpos = temp14b8 - 8;
  oam[64].ypos = temp14ba + 96;
  uint8 v2 = (counter_local_frames >> 1) & 3;
  oam[64].charnum = kSpr029_KoopaKid_IggyLarry_InShellTiles[v2];
  oam[64].flags = R13_ | kSpr029_KoopaKid_IggyLarry_InShellProp[v2] | 0x30;
  sprites_oamtile_size_buffer[92] = 2;
}

uint8 Spr0A7_IggyBall_CheckTiltingPlatformCollision(uint8 k) {  // 01ff98
  WORD(temp14b4) = GetSprXPos(k) + 8;
  WORD(temp14b6) = GetSprYPos(k) + 15;
  return CheckTiltingPlatformCollision();
}
