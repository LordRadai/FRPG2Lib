#include "DLSyncObject.h"
#include "FRPG2Call.h"

namespace DLKR
{
	typedef void(__fastcall* oDestructor)(DLSyncObject* pThis);
	typedef dl_bool(__fastcall* oIsValid)(DLSyncObject* pThis);
	typedef dl_int32(__fastcall* oLock)(DLSyncObject* pThis, DLTimeout);
	typedef dl_int32(__fastcall* oTryLock)(DLSyncObject* pThis);
	typedef dl_int32(__fastcall* oUnlock)(DLSyncObject* pThis);

	DLSyncObject::~DLSyncObject() {
		FRPG2_VCALL(this, 0, oDestructor, this);
	}

	dl_bool DLSyncObject::IsValid() const {
		return FRPG2_VCALL((DLSyncObject*)this, 1, oIsValid, (DLSyncObject*)this);
	}

	dl_int32 DLSyncObject::Lock(DLTimeout timeout) {
		return FRPG2_VCALL(this, 2, oLock, this, timeout);
	}

	dl_int32 DLSyncObject::TryLock() {
		return FRPG2_VCALL(this, 3, oTryLock, this);
	}

	dl_int32 DLSyncObject::Unlock() {
		return FRPG2_VCALL(this, 4, oUnlock, this);
	}
}