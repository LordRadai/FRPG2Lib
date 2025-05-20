#pragma once
#include "dantelion2/Core/Util/DLNonCopyable.h"
#include "dantelion2/Core/Platform/Platform.h"
#include "Types.h"
#include "SyncTraits.h"

namespace DLKR
{
	class DLSyncObject : public DLUT::DLNonCopyable
	{
    public:
        enum ERROR_CODE 
        {
            ERR_NONE,
            ERR_RESOURCE,
            ERR_BUSY,
            ERR_TIMEOUT,
            ERR_UNKNOWN,
        };

        ~DLSyncObject();
        dl_bool IsValid(void) const;
        dl_int32 Lock(DLTimeout timeout = DL_TIMEOUT_INFINITE);
        dl_int32 TryLock(void);
        dl_int32 Unlock(void);
	};
}