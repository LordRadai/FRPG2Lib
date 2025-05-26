#pragma once
#include "dantelion2/dantelion2.h"

class GXLightManager
{
    void** _vfptr;
    DLKR::DLAllocator* m_pAllocator;
    DLUT::DLVector<dl_pointer> m_lightList;
    DLKR::DLPlainLightMutex m_sync;
};