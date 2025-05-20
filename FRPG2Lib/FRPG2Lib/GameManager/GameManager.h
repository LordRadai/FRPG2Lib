#pragma once
#include "dantelion2/dantelion2.h"
#include "Steam/SteamShutdown.h"
#include "Steam/CCallback.inl"
#include "ResourceManager/AppResourceManager.h"

class GameManager
{
    void** _vfptr;

public:
    DLKR::DLAllocator* m_pAllocator;
    dl_pointer m_pDamageManager;
    dl_pointer m_pCharacterManager;
    dl_pointer m_pCameraManager;
    dl_pointer m_pAiManager;
    AppResourceManager* m_pAppResourceManager;
    dl_pointer m_pMapManager;
    dl_pointer m_pEnemyGeneratorManager;
    dl_pointer m_pTargetManager;
    dl_pointer m_pPadOwnershipManager;
    dl_pointer field11_0x58;
    dl_pointer m_pBulletManager;
    dl_pointer field13_0x68;
    dl_pointer m_pEventManager;
    dl_pointer m_pGameEntityComponentUpdateGroupList;
    dl_pointer m_pFaceGenManager;
    dl_pointer m_pRumbleManager;
    dl_pointer m_pSignManager;
    dl_pointer field19_0x98;
    dl_pointer m_pStateActManager;
    dl_pointer m_pGameDataManager;
    dl_pointer m_pEventMakerManager;
    dl_pointer m_pSaveLoadSystem;
    dl_pointer field24_0xc0;
    dl_pointer m_pAppDLCContentsInfoAccessor;
    dl_pointer m_pPlayerCharacter;
    dl_int field27_0xd8;
    dl_int field28_0xdc;
    DLMT::DL_VECTOR4 field29_0xe0;
    DWORD m_rngSeed;
    dl_int m_rng[4];
    dl_uint m_frameNo;
    dl_bool field33_0x108;
    dl_int field37_0x10c;
    DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_playerHeap;
    dl_pointer m_pPXHeapMemory;
    dl_pointer m_pPXSystem;
    dl_pointer m_pPXWorld;
    dl_pointer m_pPXClothWorld;
    dl_pointer field43_0x670;
    DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_havokHeap;
    dl_bool field45_0xbb8;
    dl_int field49_0xbbc;
    dl_pointer m_pNvNavigationSystem;
    dl_pointer m_pKatanaSfxSystem;
    DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_sfxSystemHeap;
    dl_bool field53_0x1110;
    dl_int field57_0x1114;
    dl_pointer m_pAppTrophyManager;
    dl_pointer m_pAppPresenceManager;
    dl_pointer m_pStatsManager;
    dl_pointer field61_0x1130;
    dl_pointer field62_0x1138;
    dl_int field63_0x1140;
    dl_int field64_0x1144;
    dl_pointer m_pAppDecalManager;
    dl_pointer m_pChrAspectManager;
    dl_pointer m_pCameraParameters;
    dl_float32* field68_0x1160;
    dl_bool field69_0x1168;
    dl_int field73_0x116c;
    dl_pointer m_pDemoManager;
    dl_uchar field75_0x1178;
    dl_pointer m_pSGWorld;
    dl_pointer m_pSGLayerDynamicTree;
    dl_pointer m_pSGLayerFlat;
    dl_int16 field86_0x1198;
    dl_int16 field87_0x119a;
    dl_int field88_0x119c;
    DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_sceneGraphHeap;
    dl_bool field90_0x16e0;
    dl_float32 field94_0x16e4;
    dl_pointer m_pSGVisbTestSystem;
    dl_pointer m_pSGVisbTester;
    dl_bool m_bEnableFrustumCulling;
    dl_float32 field101_0x16fc;
    DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLBiHeapStrategy<DLKR::DLRobustHeap, DLKR::DLMultiThreadingPolicy>>> m_morphemeHeap;
    dl_pointer m_pVar1838;
    DLKR::DLAllocator* m_pMorphemeAllocator;
    dl_pointer m_pMorphemeSystem;
    dl_pointer m_pAppPrefabSystem;
    dl_bool field106_0x1858;
    dl_int field110_0x185c;
    DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_faceGenHeap;
    DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_menuHeap;
    dl_pointer m_pMenuManager;
    dl_bool field114_0x22e8;
    dl_int field118_0x22ec;
    DLKR::DLPlainLightMutex* m_lightMutex;
    DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLBiHeapStrategy<DLKR::DLBiHeap, DLKR::DLMultiThreadingPolicy>>> m_regulationHeap;
    dl_bool field121_0x2460;
    dl_bool m_bIsLoadingResource;
    dl_bool field123_0x2462;
    dl_bool field124_0x2463;
    dl_float32 field125_0x2464;
    dl_int field126_0x2468;
    dl_int field127_0x246c;
    DLMT::DL_VECTOR4 m_cameraFocus;
};

class GameManagerImp : public GameManager
{
    class GameManagerCallbackObjectBase 
    {
        void*** _vfptr;
        dl_pointer arg;
        void* function;
        dl_uchar field3_0x18;
        dl_uchar field4_0x19;
        dl_uchar field5_0x1a;
        dl_uchar field6_0x1b;
        dl_uchar field7_0x1c;
    };

    enum FlowCommand : dl_uchar
    {
        GameCommand_UnkTitle = 1,
        GameCommand_ToTitle = 2,
        GameCommand_QuitToTitle = 4,
        GameCommand_QuitToInGame = 8,
        GameCommand_LoadInGame = 16,
        GameCommand_5 = 32
    };

    struct InitLocationData 
    {
        dl_int type;
        dl_int fadeCategory;
        dl_int demoID;
        dl_int cameraMode;
        dl_int field4_0x10;
        dl_uchar startupCategory;
        dl_uchar field6_0x15;
        dl_uchar field7_0x16;
        dl_uchar field8_0x17;
        dl_int locationID;
        dl_int field10_0x1c;
        dl_float32 field11_0x20;
        dl_int field12_0x24;
        dl_float32 field13_0x28;
        dl_float32 field14_0x2c;
        dl_uint field15_0x30;
        dl_int field16_0x34;
        dl_int mapID;
        dl_uchar field18_0x3c;
        dl_bool isDarkSpirit;
        dl_uchar field20_0x3e;
        dl_uchar field21_0x3f;
    };

public:
    dl_float32 field1_0x2480;
    dl_float32 field2_0x2484;
    GameManagerCallbackObjectBase* field3_0x2488;
    GameManagerCallbackObjectBase* m_pIngameSceneCallback;
    GameManagerCallbackObjectBase* field5_0x2498;
    GameManagerCallbackObjectBase* field6_0x24a0;
    dl_int m_playerStatusParamID;
    dl_int m_gameState;
    dl_uchar field9_0x24b0;
    FlowCommand m_flowCommand;
    dl_uchar field11_0x24b2;
    dl_uchar field12_0x24b3;
    dl_float32 field13_0x24b4;
    dl_int field14_0x24b8;
    dl_int field15_0x24bc;
    dl_int field16_0x24c0;
    dl_bool field17_0x24c4;
    InitLocationData m_locationInitData;
    dl_int field22_0x2508;
    dl_float32 field23_0x250c;
    DLMT::DL_VECTOR4 m_playerInitialPosition;
    DLMT::DL_VECTOR4 m_playerInitialRotation;
    DLMT::DL_VECTOR4 field26_0x2530;
    dl_bool field27_0x2540;
    dl_int field31_0x2544;
    dl_wchar** m_sfxArchivePaths;
    dl_wchar** m_shaderArchivePaths;
    dl_int field34_0x2558;
    dl_int field35_0x255c;
    CCallback<GameManagerImp, SteamShutdown_t, false> m_steamShutdownCallback;
};