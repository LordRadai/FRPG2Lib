#pragma once
#include "dantelion2/dantelion2.h"

struct PropertyItem 
{
    PropertyItem* m_pPrev;
    PropertyItem* m_pNext;
    PropertyItem* m_pStart;
    bool field3_0x18;
    bool m_bValid;
    bool field5_0x1a;
    bool field6_0x1b;
    int field7_0x1c;
    DLTX::DLString m_name;
    DLTX::DLString m_value;
};

class Properties 
{
    PropertyItem* m_pRootProperty;
    dl_pointer field1_0x8;
    DLKR::DLAllocator* pAllocator;

public:
    dl_int GetIntProperty(DLTX::DLString name, dl_int defaultValue);
    dl_bool GetBoolProperty(DLTX::DLString name, dl_bool defaultValue);
    dl_float32 GetFloatProperty(DLTX::DLString name, dl_float32 defaultValue);
    void GetStringProperty(DLTX::DLString* pBuf, DLTX::DLString name, DLTX::DLString defaultValue);
    void SetPropertyValue(DLTX::DLString name, DLTX::DLString value);
};