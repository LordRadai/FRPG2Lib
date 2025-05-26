#pragma once
#include "GXFilterBase.h"
#include "../../Texture.h"

class GXToneMapFilter : public GXFilterBase
{
public:
    struct ToneMapFilterParameters {
        struct StarGlareFilterParams {
            char field0_0x0[128];
            alignas(16) DLMT::DL_VECTOR4 field1_0x80;
            dl_float32 field2_0x90;
            dl_float32 field3_0x94;
            dl_float32 field4_0x98;
            dl_float32 field5_0x9c;
            dl_float32 field6_0xa0;
            dl_float32 field7_0xa4;
            dl_float32 field8_0xa8;
            dl_float32 field9_0xac;
            dl_float32 field10_0xb0;
            dl_float32 field11_0xb4;
            dl_float32 field12_0xb8;
            dl_float32 field13_0xbc;
            dl_float32 field14_0xc0;
            dl_float32 field15_0xc4;
            dl_float32 field16_0xc8;
            dl_float32 field17_0xcc;
            dl_float32 field18_0xd0;
            dl_float32 field19_0xd4;
            dl_float32 field20_0xd8;
            dl_float32 field21_0xdc;
            dl_float32 field22_0xe0;
            dl_float32 field23_0xe4;
            dl_float32 field24_0xe8;
            dl_float32 field25_0xec;
            dl_float32 field26_0xf0;
            dl_float32 field27_0xf4;
            dl_float32 field28_0xf8;
            dl_float32 field29_0xfc;
            dl_float32 m_starGlareAlpha;
            dl_int m_starGlareNumberofLines;
            dl_int m_starGlareNumberOfPasses;
            dl_float32 m_starGlarePathLenght;
            dl_float32 m_starGlareAttenuation;
            dl_float32 m_starGlareAngle;
            dl_float32 m_starGlareChromaticAberration;
            dl_float32 m_starGlareColorCoefficient;
        };

        dl_float32 m_averageLuminance;
        alignas(16) DLMT::DL_VECTOR4 m_luminanceBalance;
        dl_float32 m_maxLuminance;
        alignas(16) DLMT::DL_VECTOR4 m_scaler;
        dl_int field28_0x40;
        dl_bool m_bEnableDynamicAdaption;
        dl_float32 m_dynamicAdaptionSpeed;
        dl_float32 field34_0x4c;
        dl_float32 m_adaptionSensibilityToDark;
        dl_float32 m_adaptionSensibilityToBright;
        dl_float32 m_adaptiveLuminanceCenter;
        dl_float32 m_adaptiveMinBrightness;
        dl_float32 m_adaptiveMaxBrightness;
        dl_bool field40_0x64;
        dl_float32 field44_0x68;
        dl_float32 field45_0x6c;
        dl_float32 field46_0x70;
        dl_float32 field47_0x74;
        dl_float32 field48_0x78;
        dl_float32 field49_0x7c;
        dl_float32 field50_0x80;
        dl_bool m_bBloomEnabled;
        dl_bool field52_0x85;
        dl_float32 m_bloomAlpha;
        alignas(16) DLMT::DL_VECTOR4 m_highBrightnessExtractionThreashold;
        alignas(16) DLMT::DL_VECTOR4 m_bloomColorScale;
        dl_float32 m_bloomSaturationControl;
        dl_float32 m_bloomColorCoefficient;
        dl_float32 field64_0xb8;
        dl_float32 m_bloomCouplingCoefficient0;
        dl_float32 m_bloomCouplingCoefficient1;
        dl_float32 m_bloomCouplingCoefficient2;
        dl_bool m_bLightShaftEnabled;
        dl_float32 m_lightShaftAlpha;
        dl_bool field73_0xd0;
        dl_float32 m_lightShaftSuppressionValue;
        dl_float32 m_lightShaftDampening;
        dl_float32 m_lightShaftSuppressionValue2;
        dl_float32 m_lightShaftDampening2;
        dl_float32 m_lightShaftParallelBeginAngle;
        dl_float32 m_lightShaftParallelCompletionAngle;
        dl_float32 m_lightShaftParallelLenght;
        dl_float32 m_lightShaftFadeOutBeginAngle;
        dl_float32 m_lightShaftFadeOutCompletionAngle;
        dl_float32 field86_0xf8;
        dl_bool m_bStarGlareEnabled;
        StarGlareFilterParams m_starGlareFilterParams;
        char field92_0x220[128];
        dl_bool m_bColorGradingEnabled;
        dl_bool field94_0x2a1;
        dl_bool field95_0x2a2;
        dl_bool field96_0x2a3;
    };

    struct ColorGradingParameters
    {
        DLKR::DLAllocator* m_pAllocator;
        dl_int m_conversionMode;
        dl_float32 m_hue;
        dl_float32 m_saturation;
        dl_float32 m_brightness;
        dl_int field5_0x18;
        dl_int field6_0x1c;
        dl_int field7_0x20;
        dl_int field8_0x24;
        dl_int field9_0x28;
        dl_int field10_0x2c;
        dl_int field11_0x30;
        dl_int field12_0x34;
        dl_int m_paletteFileID;
        dl_float32 field14_0x3c;
        dl_bool field15_0x40;
        TextureVolume m_textureVolumes[4];
        dl_int field56_0xc8;
    };

    DLKR::DLAllocator* m_pAllocator;
    dl_int m_width;
    dl_int m_height;
    dl_bool field4_0x18;
    ToneMapFilterParameters m_toneMapFilterParameters;
    DLGR::DLTexture2D* m_pTextures[20];
    Texture2D m_textures0[4];
    Texture2D m_textures1[2];
    dl_int field55_0x430;
    dl_bool field56_0x434;
    dl_bool field57_0x435;
    dl_float32 field60_0x438;
    dl_float32 field61_0x43c;
    ColorGradingParameters m_colorGradingParameters;
};