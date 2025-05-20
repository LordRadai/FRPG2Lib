#pragma once
#include "DLMutex.h"
#include "DLLightMutex.h"

#include "DLSemaphore.h"
#include "DLReadWriteLock.h"
#include "DLConditionSignal.h"
#include "DLSingleSignal.h"
#include "DLEventSignal.h"

#include "DLDummySyncObject.h"

namespace DLKR
{
	typedef DLDummySyncObject DLPlainSpinLock;
	typedef DLDummySyncObject DLPlainJunction;
}