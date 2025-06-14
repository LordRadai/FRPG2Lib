#pragma once
#include "dantelion2/dantelion2.h"
#include "Scene/SceneManager.h"
#include "Properties/Properties.h"
#include "DebugManager/AppDebugManager.h"
#include "InputManager/InputManager.h"
#include "Memory/Memory.h"
#include "Draw/System/DrawSystem.h"
#include "FilterManager/FilterManager.h"

class AppGUISystem;

class MainApp
{
    struct sMainApp_0xa0
    {
		DLKR::DLAllocator* m_pAllocator;
        dl_pointer m_pVar8;
		DLUT::DLVector<dl_pointer> m_vVar10;
    };

    struct DeltaTimeData
    {
        dl_float32 m_totalDeltaTimeSum;
        dl_float32 m_recentDeltaTimeSum;
        dl_float32 m_rollingDeltaTimeSum;
        dl_int m_currentDeltaTimeIndex;
        dl_int m_consecutiveShortFrames;
        dl_int field5_0x14;
        dl_uint64 m_lastFrameCounter;
        dl_uint64 m_performanceFrequency;
        dl_uint64 field8_0x28;
        dl_float32 m_deltaTime;
        dl_float32 m_frameTimeAdjustment;
        dl_uint64 m_frameCount;
        dl_float32 m_lastFPSUpdateTime;
        dl_float32 field13_0x44;
        dl_float32 m_fps;
        dl_float32 field15_0x4c;
        dl_bool m_enableDynamicAdjustment;
        dl_bool m_dynamicAdjustmentFlag;
        dl_float32 m_frameTimeOffset;
        dl_uint m_targetFrameRate;
    };

    void** _vfptr;

public:
    struct WindowCreationInfo
    {
        dl_int windowX;
        dl_int windowY;
        dl_int width;
        dl_int height;
        dl_int iVar10;
        dl_uint exStyle;
        dl_uint style;
        dl_bool bHasMenu;
        HINSTANCE hInstance;
    };

    class HeapMemoryList
    {
    public:
        dl_bool m_bInitialised;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_systemHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLBiHeapStrategy<DLKR::DLRobustHeap, DLKR::DLMultiThreadingPolicy>>> m_globalHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_fileDataHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_soundSystemHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLBiHeapStrategy<DLKR::DLBiHeap, DLKR::DLMultiThreadingPolicy>>> m_networkHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLSmallObjectWrapper<DLKR::DLRegularHeap, 0, 4096, 128, 16>, DLKR::DLMultiThreadingPolicy>>> m_stringHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_tempHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_temp2Heap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_debugHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLSmallObjectWrapper<DLKR::DLRegularHeap, 0, 4096, 80, 8>, DLKR::DLMultiThreadingPolicy>>> m_guiDefaultHeap;
        DynamicHeapMemoryTemplate<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>> m_graphicsMainHeap;
        dl_uint m_heapSizes[20];
        DLKR::DLBackAllocator m_backAllocator;
        HeapMemory* m_pRegisteredHeaps[161];
        dl_size m_numRegisteredHeaps;
        HeapMemory** m_pRootHeaps;
        dl_int m_numRootHeaps;
    };

    HWND m_hwnd;
    dl_uint* field2_0x10;
    HCURSOR m_hcursor;
    dl_pointer field4_0x20;
    dl_int m_width;
    dl_int m_height;
    dl_bool m_bIsIconic;
    dl_char field8_0x31;
    dl_char field9_0x32;
    dl_char field10_0x33;
    dl_char field11_0x34;
    dl_char field12_0x35;
    dl_char field13_0x36;
    dl_char field14_0x37;
    HeapMemoryList* m_pMainHeapMemory;
    DrawSystem* m_pDrawSystem;
    dl_pointer m_pGraphicsHeapList;
    dl_pointer m_pFileManager;
    dl_pointer m_pSystemFontResources;
    InputManager* m_pInputManager;
    AppDebugManager* m_pAppDebugManager;
    dl_pointer m_pLogWindowManager;
    FilterManager* m_pFilterManager;
    dl_pointer m_pAppSoundManager;
    AppGUISystem* m_pAppGUISystem;
    dl_pointer field26_0x90;
    dl_pointer field27_0x98;
    sMainApp_0xa0 field28_0xa0;
    DeltaTimeData m_deltaTimeData;
    dl_bool m_bShowFps;
    dl_bool m_bKeepWindowOnTop;
    dl_bool m_bSuppressUpdateTime;
    dl_bool m_bKeyboardOperation;
    dl_bool m_bDisableAppCursor;
    dl_bool m_bDebugDrawEnabled;
    dl_bool m_bKillTimer;
    dl_bool field37_0x137;
    dl_bool m_bHasUpdated;
    dl_bool field39_0x139;
    dl_bool m_bShutdown;
    dl_bool field41_0x13b;
    dl_uchar field42_0x13c;
    dl_bool m_bResetWindowPos;
    dl_char field44_0x13e;
    dl_char field45_0x13f;
    dl_uint m_screenWidth;
    dl_uint m_screenHeight;
    dl_bool field48_0x148;
    dl_bool field49_0x149;
    dl_bool field50_0x14a;
    dl_bool field51_0x14b;
    dl_int m_multiSampleType;
    dl_bool m_bUseStandardWindowStyle;
    dl_uint m_fpsMode;
    dl_bool m_fixedDt;
    dl_char field59_0x159;
    dl_char field60_0x15a;
    dl_char field61_0x15b;
    dl_char field62_0x15c;
    dl_char field63_0x15d;
    dl_char field64_0x15e;
    dl_char field65_0x15f;
    Properties m_configProperties;
    Properties m_userConfigProperties;
    DLUT::DLVector<dl_pointer>* m_pMessageListeners;
    dl_int field69_0x198;
    dl_char field70_0x19c;
    dl_char field71_0x19d;
    dl_char field72_0x19e;
    dl_char field73_0x19f;
    dl_uchar field74_0x1a0;
    dl_bool m_bIsDrawComplete;
    dl_char field76_0x1a2;
    dl_char field77_0x1a3;
    dl_char field78_0x1a4;
    dl_char field79_0x1a5;
    dl_char field80_0x1a6;
    dl_char field81_0x1a7;
    dl_int64 field82_0x1a8;
    DLKR::DLPlainLightMutex m_mutex;
    dl_bool m_bDeltaTimeDynamicAdjustment;
    dl_char field85_0x1e9;
    dl_char field86_0x1ea;
    dl_char field87_0x1eb;
    dl_char field88_0x1ec;
    dl_char field89_0x1ed;
    dl_char field90_0x1ee;
    dl_char field91_0x1ef;
    dl_char field92_0x1f0;
    dl_char field93_0x1f1;
    dl_char field94_0x1f2;
    dl_char field95_0x1f3;
    dl_char field96_0x1f4;
    dl_char field97_0x1f5;
    dl_char field98_0x1f6;
    dl_char field99_0x1f7;
    dl_int64 field100_0x1f8;
    dl_int64 field101_0x200;
    dl_bool field102_0x208;
    dl_uchar field102_0x209;
    dl_char field104_0x20a;
    dl_char field105_0x20b;
    dl_char field106_0x20c;
    dl_char field107_0x20d;
    dl_char field108_0x20e;
    dl_char field109_0x20f;
    dl_char field110_0x210;
    dl_char field111_0x211;
    dl_char field112_0x212;
    dl_char field113_0x213;
    dl_char field114_0x214;
    dl_char field115_0x215;
    dl_char field116_0x216;
    dl_char field117_0x217;
    dl_char field118_0x218;
    dl_char field119_0x219;
    dl_char field120_0x21a;
    dl_char field121_0x21b;
    dl_char field122_0x21c;
    dl_char field123_0x21d;
    dl_char field124_0x21e;
    dl_char field125_0x21f;
    dl_char field126_0x220;
    dl_char field127_0x221;
    dl_char field128_0x222;
    dl_char field129_0x223;
    dl_char field130_0x224;
    dl_char field131_0x225;
    dl_char field132_0x226;
    dl_char field133_0x227;
    dl_char field134_0x228;
    dl_char field135_0x229;
    dl_char field136_0x22a;
    dl_char field137_0x22b;
    dl_char field138_0x22c;
    dl_char field139_0x22d;
    dl_char field140_0x22e;
    dl_char field141_0x22f;
    dl_char field142_0x230;
    dl_char field143_0x231;
    dl_char field144_0x232;
    dl_char field145_0x233;
    dl_char field146_0x234;
    dl_char field147_0x235;
    dl_char field148_0x236;
    dl_char field149_0x237;
    dl_char field150_0x238;
    dl_char field151_0x239;
    dl_char field152_0x23a;
    dl_char field153_0x23b;
    dl_char field154_0x23c;
    dl_char field155_0x23d;
    dl_char field156_0x23e;
    dl_char field157_0x23f;
    dl_char field158_0x240;
    dl_char field159_0x241;
    dl_char field160_0x242;
    dl_char field161_0x243;
    dl_char field162_0x244;
    dl_char field163_0x245;
    dl_char field164_0x246;
    dl_char field165_0x247;
    dl_char field166_0x248;
    dl_char field167_0x249;
    dl_char field168_0x24a;
    dl_char field169_0x24b;
    dl_char field170_0x24c;
    dl_char field171_0x24d;
    dl_char field172_0x24e;
    dl_char field173_0x24f;
    dl_char field174_0x250;
    dl_char field175_0x251;
    dl_char field176_0x252;
    dl_char field177_0x253;
    dl_char field178_0x254;
    dl_char field179_0x255;
    dl_char field180_0x256;
    dl_char field181_0x257;
    dl_char field182_0x258;
    dl_char field183_0x259;
    dl_char field184_0x25a;
    dl_char field185_0x25b;
    dl_char field186_0x25c;
    dl_char field187_0x25d;
    dl_char field188_0x25e;
    dl_char field189_0x25f;
    dl_char field190_0x260;
    dl_char field191_0x261;
    dl_char field192_0x262;
    dl_char field193_0x263;
    dl_char field194_0x264;
    dl_char field195_0x265;
    dl_char field196_0x266;
    dl_char field197_0x267;
    dl_char field198_0x268;
    dl_char field199_0x269;
    dl_char field200_0x26a;
    dl_char field201_0x26b;
    dl_char field202_0x26c;
    dl_char field203_0x26d;
    dl_char field204_0x26e;
    dl_char field205_0x26f;
    dl_char field206_0x270;
    dl_char field207_0x271;
    dl_char field208_0x272;
    dl_char field209_0x273;
    dl_char field210_0x274;
    dl_char field211_0x275;
    dl_char field212_0x276;
    dl_char field213_0x277;
    dl_char field214_0x278;
    dl_char field215_0x279;
    dl_char field216_0x27a;
    dl_char field217_0x27b;
    dl_char field218_0x27c;
    dl_char field219_0x27d;
    dl_char field220_0x27e;
    dl_char field221_0x27f;
    dl_char field222_0x280;
    dl_char field223_0x281;
    dl_char field224_0x282;
    dl_char field225_0x283;
    dl_char field226_0x284;
    dl_char field227_0x285;
    dl_char field228_0x286;
    dl_char field229_0x287;
    dl_char field230_0x288;
    dl_char field231_0x289;
    dl_char field232_0x28a;
    dl_char field233_0x28b;
    dl_char field234_0x28c;
    dl_char field235_0x28d;
    dl_char field236_0x28e;
    dl_char field237_0x28f;
    dl_char field238_0x290;
    dl_char field239_0x291;
    dl_char field240_0x292;
    dl_char field241_0x293;
    dl_char field242_0x294;
    dl_char field243_0x295;
    dl_char field244_0x296;
    dl_char field245_0x297;
    dl_int64 field246_0x298;
    dl_char field247_0x2a0;
    dl_char field248_0x2a1;
    dl_char field249_0x2a2;
    dl_char field250_0x2a3;
    dl_char field251_0x2a4;
    dl_char field252_0x2a5;
    dl_char field253_0x2a6;
    dl_char field254_0x2a7;
    dl_char field255_0x2a8;
    dl_char field256_0x2a9;
    dl_char field257_0x2aa;
    dl_char field258_0x2ab;
    dl_char field259_0x2ac;
    dl_char field260_0x2ad;
    dl_char field261_0x2ae;
    dl_char field262_0x2af;
    dl_char field263_0x2b0;
    dl_char field264_0x2b1;
    dl_char field265_0x2b2;
    dl_char field266_0x2b3;
    dl_char field267_0x2b4;
    dl_char field268_0x2b5;
    dl_char field269_0x2b6;
    dl_char field270_0x2b7;
    dl_char field271_0x2b8;
    dl_char field272_0x2b9;
    dl_char field273_0x2ba;
    dl_char field274_0x2bb;
    dl_char field275_0x2bc;
    dl_char field276_0x2bd;
    dl_char field277_0x2be;
    dl_char field278_0x2bf;
    dl_char field279_0x2c0;
    dl_char field280_0x2c1;
    dl_char field281_0x2c2;
    dl_char field282_0x2c3;
    dl_char field283_0x2c4;
    dl_char field284_0x2c5;
    dl_char field285_0x2c6;
    dl_char field286_0x2c7;
    dl_char field287_0x2c8;
    dl_char field288_0x2c9;
    dl_char field289_0x2ca;
    dl_char field290_0x2cb;
    dl_char field291_0x2cc;
    dl_char field292_0x2cd;
    dl_char field293_0x2ce;
    dl_char field294_0x2cf;
    dl_char field295_0x2d0;
    dl_char field296_0x2d1;
    dl_char field297_0x2d2;
    dl_char field298_0x2d3;
    dl_char field299_0x2d4;
    dl_char field300_0x2d5;
    dl_char field301_0x2d6;
    dl_char field302_0x2d7;
    dl_char field303_0x2d8;
    dl_char field304_0x2d9;
    dl_char field305_0x2da;
    dl_char field306_0x2db;
    dl_char field307_0x2dc;
    dl_char field308_0x2dd;
    dl_char field309_0x2de;
    dl_char field310_0x2df;
    dl_char field311_0x2e0;
    dl_char field312_0x2e1;
    dl_char field313_0x2e2;
    dl_char field314_0x2e3;
    dl_char field315_0x2e4;
    dl_char field316_0x2e5;
    dl_char field317_0x2e6;
    dl_char field318_0x2e7;
    dl_char field319_0x2e8;
    dl_char field320_0x2e9;
    dl_char field321_0x2ea;
    dl_char field322_0x2eb;
    dl_char field323_0x2ec;
    dl_char field324_0x2ed;
    dl_char field325_0x2ee;
    dl_char field326_0x2ef;
    dl_char field327_0x2f0;
    dl_char field328_0x2f1;
    dl_char field329_0x2f2;
    dl_char field330_0x2f3;
    dl_char field331_0x2f4;
    dl_char field332_0x2f5;
    dl_char field333_0x2f6;
    dl_char field334_0x2f7;
    dl_char field335_0x2f8;
    dl_char field336_0x2f9;
    dl_char field337_0x2fa;
    dl_char field338_0x2fb;
    dl_char field339_0x2fc;
    dl_char field340_0x2fd;
    dl_char field341_0x2fe;
    dl_char field342_0x2ff;
    dl_char field343_0x300;
    dl_char field344_0x301;
    dl_char field345_0x302;
    dl_char field346_0x303;
    dl_char field347_0x304;
    dl_char field348_0x305;
    dl_char field349_0x306;
    dl_char field350_0x307;
    dl_char field351_0x308;
    dl_char field352_0x309;
    dl_char field353_0x30a;
    dl_char field354_0x30b;
    dl_char field355_0x30c;
    dl_char field356_0x30d;
    dl_char field357_0x30e;
    dl_char field358_0x30f;
    dl_char field359_0x310;
    dl_char field360_0x311;
    dl_char field361_0x312;
    dl_char field362_0x313;
    dl_char field363_0x314;
    dl_char field364_0x315;
    dl_char field365_0x316;
    dl_char field366_0x317;
    dl_char field367_0x318;
    dl_char field368_0x319;
    dl_char field369_0x31a;
    dl_char field370_0x31b;
    dl_char field371_0x31c;
    dl_char field372_0x31d;
    dl_char field373_0x31e;
    dl_char field374_0x31f;
    dl_char field375_0x320;
    dl_char field376_0x321;
    dl_char field377_0x322;
    dl_char field378_0x323;
    dl_char field379_0x324;
    dl_char field380_0x325;
    dl_char field381_0x326;
    dl_char field382_0x327;
    dl_int field383_0x328;
    dl_int field384_0x32c;

	AppGUISystem* GetAppGUISystem() const { return m_pAppGUISystem; }
};

class KatanaMainApp : public MainApp
{
public:
    dl_pointer m_pVar330;
	SceneManager* m_pSceneManager;
	dl_pointer m_pGXDrawSceneManager;
	KatanaDrawSystem* m_pKatanaDrawSystem;
	dl_pointer m_pFeRenderSystem;
	dl_pointer m_pVar358;
	dl_pointer m_pVar360;
	dl_pointer m_pAppFileChunkManager;
	dl_pointer m_pVar370;
	dl_uint m_titleMode;

    typedef void(_fastcall* oInitVirtualMemory)(dl_pointer pHeapMemoryList, dl_uint* pHeapSizes);
    typedef dl_bool(_fastcall* oInitialise)(KatanaMainApp* pThis, WindowCreationInfo* pWindowCreationInfo);
    typedef AppDebugManager*(_fastcall* oCreateAppDebugManager)(KatanaMainApp* pThis, DLKR::DLAllocator* pAllocator);
    typedef dl_bool(_fastcall* oCreateScene)(KatanaMainApp* pThis);
};