#pragma once
#include "dantelion2/dantelion2.h"

template<class HeapStrategy>
class WinAssertHeapStrategy
{
	HeapStrategy m_heapStrategy;
};