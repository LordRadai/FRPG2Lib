#pragma once
#include "GXFilterBase.h"

class GXAntiAliasingFilter : public GXFilterBase
{
    DLKR::DLAllocator* m_pAllocator;
    dl_float32 field2_0x10;
    dl_bool field3_0x14;
    dl_int m_aaMode;
    dl_int16 field8_0x1c;
    dl_float32 field11_0x20;
    dl_float32 field12_0x24;
    dl_float32 field13_0x28;
    dl_float32 field14_0x2c;
    dl_float32 field15_0x30;
    dl_float32 field16_0x34;
    dl_float32 field17_0x38;
    dl_float32 field18_0x3c;
    dl_float32 field19_0x40;
    dl_float32 field20_0x44;
    dl_float32 field21_0x48;
    dl_float32 field22_0x4c;
    dl_float32 field23_0x50;
    dl_float32 field24_0x54;
    dl_float32 field25_0x58;
    dl_float32 field26_0x5c;
    dl_bool field27_0x60;
    Texture2D m_textures[3];
    dl_int field36_0xc8;
    dl_int field40_0xcc;
    dl_int field44_0xd0;
    dl_int field48_0xd4;
    dl_int field52_0xd8;
    dl_int field56_0xdc;
    dl_int field60_0xe0;
    dl_int field64_0xe4;
    dl_int field68_0xe8;
    dl_float32 m_alpha;
    dl_float32 m_reduceMin;
    dl_float32 m_reduceMul;
    dl_float32 m_spanMax;
    dl_bool field73_0xfc;
    dl_bool field74_0xfd;
};