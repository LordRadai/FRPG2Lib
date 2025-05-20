#pragma once
#include "DLLightMutex.h"
#include "DLMutex.h"

namespace DLKR
{
	class DLMultiThreadingPolicy
	{
		DLKR::DLPlainLightMutex m_sync;
	};
}