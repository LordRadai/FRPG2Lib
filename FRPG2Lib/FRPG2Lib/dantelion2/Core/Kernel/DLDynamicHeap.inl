#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "dantelion2/Core/Kernel/detail/HeapAllocator.inl"

namespace DLKR
{
	template<typename HeapStrategy>
	class DLDynamicHeap
	{
		struct HeapInfo
		{
			dl_size m_iVar0;
			dl_size m_id;
			dl_pointer m_pVar10;
		};

		HeapInfo* m_pHeapInfo;
		HeapStrategy m_heapStrategy;
	};
}