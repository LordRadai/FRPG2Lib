#pragma once

namespace DLKR
{
	template<typename _Heap, typename ThreadingPolicy>
	class DLDefaultHeapStrategy
	{
		_Heap m_heap;
		ThreadingPolicy m_sync;
	};
}