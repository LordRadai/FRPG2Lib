#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainSingleSignal : public DLSyncObject {

        enum {
            INVALID_MUTEX_ID = 0
        };

        sys_semaphore_t m_id;
        dl_bool m_initialStatus;
    };
}