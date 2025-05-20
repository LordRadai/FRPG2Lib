#pragma once
#include "dantelion2/dantelion2.h"

class AppResourceManager;

class ResourceObject
{
    void** _vfptr;

public:
    dl_wchar* m_filename;
    dl_int field2_0x10;
    dl_int field3_0x14;
    AppResourceManager* AppResourceManager;
    dl_uint64 field5_0x20;
    dl_uint m_tickCount;
    dl_uint m_iVar2C;
    dl_int field8_0x30;
    dl_int m_status;
    dl_int field10_0x38;
    dl_int field14_0x3c;
    dl_int field18_0x40;
    dl_int field19_0x44;
    dl_int field20_0x48;
    dl_int m_type;
    dl_int field22_0x50;
    dl_int field23_0x54;
    dl_wchar* field24_0x58;
    dl_uint64 field25_0x60;
    dl_uint64 field26_0x68;
    DLKR::DLAllocator* m_pAllocator;
    dl_bool m_bLoaded;
    dl_bool m_bIsReading;
    dl_bool field30_0x7a;
    dl_bool field31_0x7b;
    dl_bool field32_0x7c;
    dl_bool field33_0x7d;
    dl_bool field34_0x7e;
    dl_bool field35_0x7f;
};