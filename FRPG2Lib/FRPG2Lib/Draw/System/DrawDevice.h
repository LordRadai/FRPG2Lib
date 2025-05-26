#pragma once
#include "dantelion2/dantelion2.h"

class DrawDeviceBase 
{
    DLGR::DLDrawDevice* m_pDLDrawDevice;
    dl_int m_id;
    DLGR::DLSurface* m_pSurfaces[15];
    dl_int m_surfaceIdx;
    dl_int field8_0x8c;
};

class DrawDevice : public DrawDeviceBase
{
    struct sData 
    {
        dl_float32 field0_0x0;
        dl_float32 field1_0x4;
        dl_bool field2_0x8;
        dl_bool field3_0x9;
        dl_bool field4_0xa;
        dl_bool field5_0xb;
        dl_int field6_0xc;
        dl_int field7_0x10;
        dl_int field8_0x14;
    };

    dl_int m_idx;
    sData field2_0x94[15];
    dl_uint width;
    dl_uint height;
    dl_uint field9_0x208;
    dl_uint field10_0x20c;
    dl_uint field11_0x210;
    dl_uint field12_0x214;
};