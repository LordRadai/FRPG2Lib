#pragma once
#include "HeapMemory.h"
#include "dantelion2/dantelion2.h"

template<class HeapStrategy>
class DynamicHeapMemoryTemplate : public HeapMemory
{
	DLKRD::HeapAllocator<DLKR::DLDynamicHeap<HeapStrategy>> m_heapAllocator;
	dl_int m_iVar0;
	dl_int m_ivar1;
	dl_char m_bVar2;
};