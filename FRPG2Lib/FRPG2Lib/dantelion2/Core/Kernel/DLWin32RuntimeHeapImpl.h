#pragma once
#include "dantelion2/Core/Kernel/detail/HeapAllocator.inl"
#include "dantelion2/Core/Kernel/DLLightMutex.h"

namespace DLKR
{
	class DLWin32RuntimeHeapImpl
	{
		void** _vfptr;
		DLKRD::HeapAllocator<DLWin32RuntimeHeapImpl>* m_pAllocator;
		DLKR::DLPlainLightMutex m_sync;
	};
}