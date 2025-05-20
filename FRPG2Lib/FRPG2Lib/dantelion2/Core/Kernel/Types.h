#pragma once
#include "dantelion2/Core/Platform/Platform.h"

namespace DLKR
{
    enum {
        DL_STATIC_HEAPID_MAX = 1023,
        DL_HEAPID_DUMMY = 1024,
        DL_HEAPID_RUNTIME = 1025,
        DL_SYSTEM_HEAPID_BEGIN = 2048,
        DL_DYNAMIC_HEAPID_BEGIN = 4096,
    };

    enum {
        DL_FORMAL_ALLOCATOR_ID = -1,
    };

    typedef dl_int DLAllocatorIdentifier;
    typedef dl_int DLHandle;
    typedef dl_int DLTimeout;
}