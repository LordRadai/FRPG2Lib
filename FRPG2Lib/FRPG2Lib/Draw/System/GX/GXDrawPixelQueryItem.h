#pragma once
#include "GXDrawItem.h"

class GXDrawPixelQueryItem : public GXDrawItem
{
    struct DrawPixelQueryItem 
    {
        DLGR::DLQuery* m_pQuery;
        dl_int field1_0x8;
        dl_bool field2_0xc;
        dl_bool field3_0xd;
    };

    DrawPixelQueryItem m_drawPixelQueryItem[5];
};