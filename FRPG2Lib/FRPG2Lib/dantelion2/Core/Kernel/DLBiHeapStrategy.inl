#pragma once

namespace DLKR
{
	template<typename _Heap, typename ThreadingPolicy>
	class DLBiHeapStrategy
	{
		_Heap m_heap;
		ThreadingPolicy m_sync;
	};
}