#pragma once
#include "CharacterCtrlBase.h"
#include "PX/PXUserDataCharacterCtrl.h"
#include "Draw/Texture.h"

template<typename T>
class CharacterAttribute
{
    T m_value;
    T m_min;
    T m_max;

public:
	T GetValue() const { return m_value; }
	T GetMin() const { return m_min; }
	T GetMax() const { return m_max; }

	void SetValue(T value) { m_value = value; }
	void SetMin(T min) { m_min = min; }
	void SetMax(T max) { m_max = max; }
};

class CharacterCtrl : public CharacterCtrlBase
{
    class SpEffectOwner 
    {
        void** _vfptr;
        CharacterCtrl* m_pCharacter;
        dl_pointer m_pStatusAbonrmalities;
        dl_pointer field3_0x18;
        dl_pointer m_pStatusAbnormalities2;
        dl_pointer m_pSpEffectCtrl;
        dl_pointer m_pSpEffectSlotWatcher;
        dl_pointer field7_0x38;
        dl_pointer field8_0x40;
    };

    dl_pointer m_pChrResource;
    DLMT::DL_VECTOR4 m_lookAt;
    DLMT::DL_VECTOR4 field3_0x70;
    DLMT::DL_VECTOR4 field4_0x80;
    DLMT::DL_VECTOR4 m_position;
    DLMT::DL_VECTOR4 field6_0xa0;
    dl_pointer m_pChrSfxData;
    dl_pointer m_chrFlags;
    dl_pointer m_attackStateFlags;
    dl_pointer field10_0xc8;
    dl_pointer field11_0xd0;
    dl_pointer m_pEquipWeaponCtrl;
    dl_pointer m_pActionCtrl;
    dl_pointer m_pOperator;
    dl_pointer m_pModelCtrl;
    dl_pointer m_pMotionCtrl;
    dl_pointer m_pPhysicsCtrl;
    dl_int field18_0x108;
    dl_int field19_0x10c;
    dl_uint m_mapFlags;
    dl_int field21_0x114;
    DLTX::DLString m_entityName;
    dl_int m_pxGroupIdx;
    PXUserDataCharacterCtrl m_PXUserData;
    dl_float32 field29_0x160[2];
    dl_int m_hp;
    dl_int m_hpMin;
    dl_int m_hpCap;
    dl_int m_hpMax;
    dl_int field34_0x178;
    dl_int field35_0x17c;
    dl_int field36_0x180;
    dl_int field37_0x184;
    dl_int field38_0x188;
    dl_int field39_0x18c;
    dl_int field40_0x190;
    dl_int field41_0x194;
    dl_int field42_0x198;
    dl_int field43_0x19c;
    dl_int field44_0x1a0;
    dl_int field45_0x1a4;
    dl_int16 field46_0x1a8;
    CharacterAttribute<dl_float32> m_stamina;
    CharacterAttribute<dl_float32> m_posture;
    CharacterAttribute<dl_float32> m_poison;
    CharacterAttribute<dl_float32> m_bleed;
    CharacterAttribute<dl_float32> m_oil;
    CharacterAttribute<dl_float32> m_curse;
    CharacterAttribute<dl_float32> m_unusuedStatus;
    CharacterAttribute<dl_float32> m_toxicity;
    CharacterAttribute<dl_float32> m_petrification;
    CharacterAttribute<dl_float32> m_poise;
    dl_int field59_0x224;
    dl_pointer field60_0x228;
    dl_pointer m_pAttackDamageCtrl;
    dl_pointer m_pFootEffectCtrl;
    dl_pointer m_pCullingGroupCtrl;
    dl_pointer m_pSfxSlotCtrl;
    dl_pointer m_pHorizontalSfxSlotCtrl;
    dl_pointer m_pFullBodySfxCtrl;
    dl_pointer m_pWepSfxCtrl;
    dl_pointer field68_0x268;
    dl_int m_lockRelated[12];
    dl_int field70_0x2a0;
    dl_float32 field71_0x2a4;
    dl_float32 m_playbackSpeed;
    dl_float32 field73_0x2ac;
    DLMT::DL_VECTOR4 field74_0x2b0;
    DLMT::DL_VECTOR4 field75_0x2c0;
    DLMT::DL_VECTOR4 field76_0x2d0;
    DLMT::DL_VECTOR4 field77_0x2e0;
    DLMT::DL_VECTOR4 field78_0x2f0;
    DLMT::DL_VECTOR4 field79_0x300;
    DLMT::DL_VECTOR4 field80_0x310;
    DLMT::DL_VECTOR4 field81_0x320;
    DLMT::DL_VECTOR4 field82_0x330;
    DLMT::DL_VECTOR4 field83_0x340;
    DLMT::DL_VECTOR4 field84_0x350;
    DLMT::DL_VECTOR4 field85_0x360;
    dl_float32 field86_0x370;
    dl_float32 field87_0x374;
    dl_pointer m_pAsmCtrl;
    dl_pointer field89_0x380;
    dl_pointer field90_0x388;
    dl_pointer m_pEventTriggerCtrl;
    dl_pointer m_pGameParamCalculator;
    dl_pointer m_pLockTargetCtrl;
    dl_pointer m_pCollideReactionCtrl;
    dl_pointer m_pNaviGraphLocationComponent;
    SpEffectOwner m_spEffectOwner;
    dl_pointer m_pSoundCtrlCharacterInterface;
    dl_pointer field98_0x408;
    dl_pointer m_pSoundSlotCtrl;
    dl_pointer field100_0x418;
    dl_pointer field101_0x420;
    dl_bool field102_0x428;
    dl_bool field103_0x429;
    byte field104_0x42a;
    byte field105_0x42b;
    dl_int field106_0x42c[12];
    byte field107_0x45c;
    byte field108_0x45d;
    byte field109_0x45e;
    byte field110_0x45f;
    TextureCube* m_pTextureCube;
    dl_pointer m_pCollisionStandingOn;
    byte field113_0x470;
    byte field114_0x471;
    dl_int field117_0x474;
    dl_int field118_0x478;
    dl_int field119_0x47c;
};