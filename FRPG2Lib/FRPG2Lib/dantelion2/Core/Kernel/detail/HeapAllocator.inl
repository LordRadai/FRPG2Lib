#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace DLKRD
{
	template<class _Heap>
	class HeapAllocator : public DLKR::DLAllocator
	{
		_Heap m_pHeap;
	};
}