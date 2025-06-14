#pragma once
#include "dantelion2/dantelion2.h"
#include "ResourceManager/AppResourceManagerBase.h"
#include "ResourceObject/ParamFileResourceObject.h"
#include "Network/PacketReceiver/NetPacketReceiver.h"
#include "Draw/DrawContext.h"

#define NUM_MAX_CHR 74
#define NUM_MAX_PLAYER_CHR 6

typedef dl_pointer CharacterCtrl;
typedef dl_pointer PlayerCtrl;

class CharacterManager
{
public:
    // Placeholder, actual content is unknown
    _declspec(align(8))
    class CharacterResources
    {
        dl_uchar m_data[1272];
    };

    class CharacterManagerResources
    {
        DLKR::DLAllocator* m_pAllocator;
        dl_pointer field1_0x8;
        dl_pointer m_pResources;
        dl_int m_numResources;
    };

    DLKR::DLAllocator* m_pAllocator;
    DLUT::DLVector<CharacterCtrl> m_characterList;
    DLUT::DLVector<CharacterCtrl> m_newEntities;
    PlayerCtrl* m_pPlayerCharacters[NUM_MAX_PLAYER_CHR];
    CharacterCtrl* m_pCharacters[NUM_MAX_CHR];
    PlayerCtrl* m_pPlayerCharacters2[NUM_MAX_PLAYER_CHR];
    dl_char m_numCharacters;
    dl_char m_numPlayerCharacters;
    dl_bool m_bIsUpdating;
    dl_char field10_0x303;
    dl_char field11_0x304;
    dl_char field12_0x305;
    dl_char field13_0x306;
    dl_char field14_0x307;
    dl_char field15_0x308;
    dl_int field19_0x30c;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrCommonParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrMoveParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrEquipWeaponParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyCommonParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyMoveParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyEquipWeaponParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_playerCommonParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyBehaviourParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyBehaviourSecondParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyBehaviourThirdParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyComboBehaviourParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyColorParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyCullingParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrEquipLoadParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_fallingParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_weaponParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_weaponActionCategoryParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_weaponAttackMotionParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_weaponTypeParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_weaponStaminaCostParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_weaponReinforceParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_weaponStatsAffectParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_dualWieldingPermissionParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_armorParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_armorReinforceParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_armorHandsUpParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_equipInterfereParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_equipCullingTargetParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_customAttrSpecParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_customAttrCostParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_reinforceCostParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_arrowParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_ringParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_spellParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_spellSoulConsumeParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_footEffectSfxParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_playerChrGrowthParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_playerLevelUpSoulsParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_relatePhysicalStatToLevelParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_physicalStatsPerLevelValuesParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_menuStatsParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_hollowLevelStatsParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_playerLackOfStatsParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_npcGenerateParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrEditParamBodyScaleParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_materialParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_groundMaterialParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_lockOnParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_lockTargetParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_lockOnCameraOffsetParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_guardLevelMotionParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_bossParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_bossPartsParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_bossPartsModelParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_bossEnemyGenerateParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_grabParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_deadTypeParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_torchCtrlParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_torchOffCtrlParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrWetParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_hitBackMatrixParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_hitBackParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrFullBodySfxParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyAttackMoveParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_playerStatusParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_playerStatusItemParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_npcPlayerStatusParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_npcPlayerSkinParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_criminalAndDeceasedParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrPointWindParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_playerLightParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_vowParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrNetworkPhantomParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrNetworkPhantomSoulRateParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrModelParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_enemyShotSfxParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrRoundDamageParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrRoundDropSoulParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_chrMultiplayParam;
    AppResourceManagerBase::ResourceContainer<ParamFileResourceObject_ForRegulation> m_footEffectWaterSfxParam;
    CharacterManagerResources* m_pModelResources;
    dl_uint m_playerChrParamID;
    dl_uint m_playerChrID;
    dl_uint m_playerStatusParamID;
    CharacterResources m_characterResources;
    dl_bool field111_0xd40;
    dl_bool field112_0xd41;
    dl_int field115_0xd44;
    dl_int field116_0xd48;
    dl_int field117_0xd4c;
    dl_int field118_0xd50;
    dl_int field119_0xd54;
    dl_char field120_0xd58;
    dl_bool field121_0xd59;
    dl_bool field122_0xd5a;
    dl_bool m_bMultiThreadPreDrawTask;
    dl_pointer m_pChrAsmResidentResManager;
    dl_pointer field129_0xd68;
    dl_pointer m_pGrabManager;
    NetPacketReceiver* m_pGrabPacketReceiver;
    NetPacketReceiver* m_pDamagePacketReceiver;
    NetPacketReceiver* m_pDeadPacketReceiver;
    NetPacketReceiver* m_pEquipPacketReceiver;
    NetPacketReceiver* m_pMotionPacketReceiver;
    NetPacketReceiver* m_pLockOnPacketReceiver;
    NetPacketReceiver* m_pStatusPacketReceiver;

    CharacterManager();
	
    virtual ~CharacterManager();
    virtual void Update(dl_float32* pDeltaTime);
	virtual void RegisterPostPhysicsTasks(dl_float32* pDeltaTime);
    virtual void RegisterPreDrawTasks(dl_float32* pDeltaTime);
    virtual void DrawCharacterModels(dl_pointer pDrawCtxWrapper);
    virtual void DrawUnknownModel(dl_pointer pDrawCtxWrapper);
    virtual void DrawCharacterIcons(IDrawContext* pDrawContext);

    dl_bool Initialize();
    void ClearEntityListAndResources();

    typedef void(_fastcall* oConstructor)(CharacterManager* pThis);
};