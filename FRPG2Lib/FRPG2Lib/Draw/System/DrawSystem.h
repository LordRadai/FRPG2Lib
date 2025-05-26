#pragma once
#include "DrawScene.h"
#include "GX/GXLightManager.h"
#include "GX/GXMotionBlurFilter.h"
#include "GX/GXCubeMapBlurFilter.h"
#include "AppSystemMessageListener/AppSystemMessageListener.h"
#include "Flver/AppFlverShaderReloadListener.h"

class KatanaDrawSystem : public AppFlverShaderReloadListener, public AppSystemMessageListener
{
    struct sUnkStruct0 
    {
        struct sData 
        {
            dl_float32 field0_0x0;
            dl_float32 field1_0x4;
            dl_float32 field2_0x8;
            dl_float32 field3_0xc;
            dl_float32 field4_0x10;
            dl_float32 field5_0x14;
            dl_float32 field6_0x18;
            dl_bool field7_0x1c;
            dl_float32 field11_0x20;
            dl_float32 field12_0x24;
            dl_float32 field13_0x28;
            dl_float32 field18_0x30;
            dl_float32 field19_0x34;
            dl_float32 field20_0x38;
            dl_float32 field21_0x3c;
            dl_float32 field22_0x40;
            dl_float32 field23_0x44;
            dl_float32 field24_0x48;
            dl_float32 field25_0x4c;
            dl_float32 field26_0x50;
            dl_float32 field27_0x54;
            dl_float32 field28_0x58;
            dl_float32 field29_0x5c;
        };

        DLKR::DLAllocator* m_pAllocator;
        dl_int m_numElems;
        dl_int field2_0xc;
        sData* field3_0x10;
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