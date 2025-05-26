#pragma once
#include <Windows.h>
#include "PXUserData.h"
#include "dantelion2/dantelion2.h"
#include "Havok2012/Havok2012.h"

struct PXEntity {
    void** _vfptr;
    PXUserData* m_pPXUserData;
    dl_int field2_0x10;
    dl_pointer m_pPXWorld;
};

struct PXUserValue {
    dl_int value;
    PXEntity* pOwner;
};