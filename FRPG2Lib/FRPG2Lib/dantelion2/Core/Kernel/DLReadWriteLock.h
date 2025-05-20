#pragma once
#include "DLSyncObject.h"

namespace DLKR
{
    class DLPlainReadWriteLock : public DLSyncObject {

        enum {
            INVALID_RWLOCK_ID = 0
        };

        sys_rwlock_t m_id;
        sys_rwlock_t m_10;
        sys_rwlock_t m_18;
        dl_int m_20;
    };
}