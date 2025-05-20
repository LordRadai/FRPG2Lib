#pragma once
#include "DLSyncObject.h"
#include "Types.h"

namespace DLKR
{
    class DLPlainEventSignal : public DLSyncObject {

        enum {
            INVALID_MUTEX_ID = 0
        };

        sys_mutex_t m_mutex_id;
    };
}
