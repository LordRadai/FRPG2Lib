#pragma once
#include "dantelion2/Core/Platform/Platform.h"

namespace DLKR
{
    enum DLHeapDirection {
        HD_FRONT,
        HD_BACK,
    };

    class DLHeapCapability
    {
        const dl_int32 m_capability;
    public:

        enum HeapFuncionality {
            CAN_ALLOCATE = 0x0001,
            CAN_FREE = 0x0002,
            CAN_USE_HANDLE = 0x0004,
            CAN_RELOCATE = 0x0008,
            IS_THREAD_SAFE = 0x0010,
            CAN_USE_FOR_CONTAINERS = 0x0020,
			UNK_40 = 0x0040,
        };
    };
}