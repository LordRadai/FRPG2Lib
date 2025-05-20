#pragma once
#include "DLAtomicInt.h"
#include "DLSyncObject.h"
#include "dantelion2/Core/Platform/GeneralUtility.h"
#include "Types.h"
#include <Windows.h>

namespace DLKR
{
    class DLPlainConditionSignal : public DLSyncObject {

        enum {
            INVALID_MUTEX_ID = 0
        };

        sys_mutex_t m_mutex_id;
    };
}