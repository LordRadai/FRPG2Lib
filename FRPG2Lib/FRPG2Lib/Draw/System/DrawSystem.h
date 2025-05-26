#pragma once
#include "DrawScene.h"
#include "GX/GXLightManager.h"
#include "GX/GXMotionBlurFilter.h"
#include "GX/GXCubeMapBlurFilter.h"
#include "AppSystemMessageListener/AppSystemMessageListener.h"
#include "Flver/AppFlverShaderReloadListener.h"
#include "DrawDevice.h"

class DrawSystem 
{
    struct sGraphicsCtx_030 
    {
        struct sData 
        {
            dl_int width;
            dl_int height;
            dl_int field2_0x8;
            dl_int field3_0xc;
            dl_int field4_0x10;
            dl_int field5_0x14;
            dl_int field6_0x18;
            dl_int field7_0x1c;
            dl_int field8_0x20;
            dl_int field9_0x24;
            HWND field10_0x28;
            dl_int field11_0x30;
            dl_int field12_0x34;
            HWND field13_0x38;
            dl_int field14_0x40;
            dl_int field15_0x44;
            dl_int field16_0x48;
            dl_int field17_0x4c;
            dl_int field18_0x50;
            dl_int field19_0x54;
            dl_bool field20_0x58;
            dl_bool field21_0x59;
            dl_bool field22_0x5a;
            dl_bool field23_0x5b;
            dl_int field24_0x5c;
            dl_int field25_0x60;
            dl_int field26_0x64;
            dl_int field27_0x68;
            dl_int field28_0x6c;
            dl_int field29_0x70;
            dl_int field30_0x74;
            dl_int field31_0x78;
            dl_int field32_0x7c;
        };

        sData data[3];
    };

    struct SceneData 
    {
        dl_int width;
        dl_int height;
        dl_int defaultWidth;
        dl_int defaultHeight;
        dl_uchar windowMode;
        dl_int field8_0x14;
        dl_int field9_0x18;
        dl_int field10_0x1c;
        dl_int field11_0x20;
        dl_int field12_0x24;
        dl_int field13_0x28;
        dl_int field14_0x2c;
        dl_int field15_0x30;
        dl_int field16_0x34;
        dl_int field17_0x38;
        dl_int field18_0x3c;
        dl_int field19_0x40;
        dl_int field20_0x44;
        dl_bool field21_0x48;
    };

public:
    DLKR::DLAllocator* m_pAllocator;
    dl_int m_viewportWidth;
    dl_int m_viewportHeight;
    dl_int field3_0x10;
    dl_int field4_0x14;
    dl_bool field5_0x18;
    dl_bool field6_0x19;
    dl_bool field7_0x1a;
    dl_bool field8_0x1b;
    dl_bool field9_0x1c;
    dl_bool field10_0x1d;
    dl_bool field11_0x1e;
    dl_bool field12_0x1f;
    HWND m_hwnd;
    dl_int m_fpsCap;
    dl_int m_numRenderTargets;
    sGraphicsCtx_030 field16_0x30;
    DLGR::DLDrawDevice* m_pDLDrawDevice;
    DLGR::DLSDObjectFactory* m_pDLSDObjectFactory;
    Texture2D* m_pRenderTarget;
    DLGR::DLSurface* m_pRenderTargetSurface;
    Texture2D* m_pTexture1;
    DLGR::DLSurface* m_pDLSurface1;
    Texture2D* m_pTexture2;
    TextureCube* m_pTextureCube;
    dl_pointer m_pMdlErrorTexture;
    DrawDevice m_drawDevice0;
    DrawDevice m_drawDevice1;
    DrawDevice m_drawDevice2;
    DrawDevice m_drawDevice3;
    DrawDeviceBase m_gameSceneDrawDevice;
    dl_int field31_0xae8;
    dl_int field32_0xaec;
    dl_int field33_0xaf0;
    dl_int field34_0xaf4;
    DLGR::DLSurface* m_pDLSurface;
    dl_uchar field36_0xb00;
    dl_uchar field37_0xb01;
    dl_uchar field38_0xb02;
    dl_uchar field39_0xb03;
    dl_uchar field40_0xb04;
    dl_uchar m_drawExecMode;
    dl_uchar field42_0xb06;
    dl_uchar field43_0xb07;
    dl_bool field44_0xb08;
    dl_bool m_bSceneBegun;
    dl_bool field46_0xb0a;
    dl_bool field47_0xb0b;
    dl_int field48_0xb0c;
    dl_pointer field49_0xb10;
    dl_int field50_0xb18;
    dl_int field51_0xb1c;
    dl_int field52_0xb20;
    dl_int field53_0xb24;
    DLGR::DLVertexDeclaration* m_pVertexDecl;
    dl_int field55_0xb30;
    dl_float32 field56_0xb34;
    dl_float32 field57_0xb38;
    dl_float32 field58_0xb3c;
    dl_float32 field59_0xb40;
    dl_float32 field60_0xb44;
    dl_float32 field61_0xb48;
    dl_float32 field62_0xb4c;
    dl_float32 field63_0xb50;
    dl_float32 field64_0xb54;
    dl_float32 field65_0xb58;
    dl_float32 field66_0xb5c;
    dl_float32 field67_0xb60;
    dl_float32 field68_0xb64;
    dl_float32 field69_0xb68;
    dl_float32 field70_0xb6c;
    dl_int field71_0xb70;
    dl_int field72_0xb74;
    dl_int field73_0xb78;
    dl_int field74_0xb7c;
    dl_int field75_0xb80;
    dl_bool field76_0xb84;
    dl_int field80_0xb88;
    dl_int field81_0xb8c;
    DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> m_sync;
    dl_int m_numRefs;
    dl_int m_threadID;
    DLUT::DLLifecycleAdapter<DLKR::DLPlainLightMutex> field85_0xbd0;
    dl_pointer field86_0xc08[3];
    dl_int field87_0xc20;
    dl_int field88_0xc24;
    dl_int field89_0xc28;
    dl_int field90_0xc2c;
    dl_int field91_0xc30;
    dl_int field92_0xc34;
    dl_int field93_0xc38;
    dl_int field94_0xc3c;
    DLGR::DLQuery* m_pDLQuery;
    dl_int field96_0xc48;
    dl_int field97_0xc4c;
    dl_float32 field98_0xc50;
    dl_float32 field99_0xc54;
    SceneData m_sceneData;
    SceneData m_sceneDataPrev;
    dl_int field102_0xcf0;
    dl_bool field103_0xcf4;
    dl_int field107_0xcf8;
    dl_int field108_0xcfc;
    dl_int field109_0xd00;
    dl_int field110_0xd04;
    dl_int field111_0xd08;
    dl_int field112_0xd0c;
    dl_int field113_0xd10;
    dl_int field114_0xd14;
    dl_int field115_0xd18;
    dl_int field116_0xd1c;
};

class KatanaDrawSystem : public AppFlverShaderReloadListener, public AppSystemMessageListener
{
    struct sUnkStruct0 
    {
        DLKR::DLAllocator* m_pAllocator;
        dl_int m_numElems;
        dl_int field2_0xc;
        dl_pointer* field3_0x10;
    };

    struct sUnkStruct1 
    {
        DLKR::DLAllocator* m_pAllocator;
        sUnkStruct0 field1_0x8;
    };

    struct sUnkStruct2 
    {
        struct sData
        {
            DLKR::DLAllocator* m_pAllocator;
            sUnkStruct1 field1_0x8;
            dl_uchar field2_0x28[88];
            GXRenderToTexture m_renderToTexture;
            dl_bool field4_0x118;
        };

        DLKR::DLAllocator* m_pAllocator;
        sData field1_0x8;
        DLUT::DLVector<dl_pointer> m_vVar10;
        dl_int field6_0x148;
        dl_int field7_0x14c;
        dl_int field8_0x150;
        dl_int field9_0x154;
        dl_int field10_0x158;
        dl_int field11_0x15c;
        dl_int field12_0x160;
        dl_int field13_0x164;
        dl_int field14_0x168;
        dl_int field15_0x16c;
        dl_int field16_0x170;
        dl_int field17_0x174;
        dl_int field18_0x178;
        dl_int field19_0x17c;
        dl_int field20_0x180;
        dl_int field21_0x184;
    };

public:
    DLKR::DLAllocator* m_pAllocator;
    KatanaDrawScene m_katanaDrawScene;
    KatanaDrawScene* m_pDrawingScene;
    sUnkStruct0 field13_0x1ce8;
    sUnkStruct1 field14_0x1d00;
    GXLightManager m_lightManager;
    sUnkStruct2 field16_0x1d88;
    GXMotionBlurFilter m_motionBlurFilter;
    GXCubeMapBlurFilter m_cubeMapBlurFilter;
    dl_bool field19_0x1f20;
    dl_bool field20_0x1f21;
    dl_bool m_bDrawFilterTexture;
    dl_bool field22_0x1f23;
    dl_bool field23_0x1f24;
    dl_bool field24_0x1f25;
    dl_bool field25_0x1f26;
    dl_bool field26_0x1f27;
    DLGR::DLVertexShader* m_pVertexShader;
    dl_pointer field28_0x1f30;
    Texture2D m_textures[4];
    dl_int field30_0x1fb8;
    dl_int field31_0x1fbc;
    dl_int16 field32_0x1fc0;
    dl_float32 field35_0x1fc4;
    dl_float32 field36_0x1fc8;
    dl_bool field37_0x1fcc;
    dl_bool field38_0x1fcd;
    dl_bool field39_0x1fce;
    dl_bool field40_0x1fcf;
    dl_bool m_bDisableAntiAliasing;
    dl_bool field42_0x1fd1;
    dl_bool field43_0x1fd2;
    dl_bool field44_0x1fd3;
    dl_bool field45_0x1fd4;
    dl_bool field46_0x1fd5;
    dl_bool field47_0x1fd6;
    dl_bool field48_0x1fd7;
    dl_bool field49_0x1fd8;
    dl_bool field50_0x1fd9;
    dl_bool field51_0x1fda;
    dl_bool field52_0x1fdb;
    dl_bool m_bDrawCharacters;
    dl_bool m_bDrawObjects;
    dl_bool m_bDrawMap;
    dl_bool field56_0x1fdf;
};