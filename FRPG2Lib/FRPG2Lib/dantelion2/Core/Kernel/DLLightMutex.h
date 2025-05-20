#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainLightMutex : public DLSyncObject 
    {
        sys_lwmutex_t m_id;
        dl_bool m_bIsValid;
    };
}