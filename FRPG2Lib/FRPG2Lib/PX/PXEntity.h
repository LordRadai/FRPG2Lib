#pragma once
#include <Windows.h>
#include "PXUserData.h"
#include "dantelion2/dantelion2.h"
#include "Havok/Havok.h"

struct DynamicBitset : public DLUT::DLNonCopyable {
    void** field1_0x8;
    void** field2_0x10;
    UINT field3_0x18;
};

struct PXEntity {
    void** _vfptr;
    PXUserData* m_pPXUserData;
    int field2_0x10;
    void* m_pPXWorld;
};

struct sPXUserValue {
    int value;
    PXEntity* pOwner;
};