#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainSemaphore : public DLSyncObject {

        enum {
            INVALID_SEMA_ID = 0
        };

        sys_semaphore_t m_semaphore;
        dl_int32 m_initial;
        dl_int32 m_max;
    };
}