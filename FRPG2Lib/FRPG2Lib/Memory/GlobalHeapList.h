#pragma once
#include "dantelion2/dantelion2.h"
#include "Memory/HeapMemory.h"

class WorldHeapList
{
public:
	HeapMemory* m_pMapSeamlessControlMemory;
	dl_pointer m_pVar8;
	DLKR::DLAllocator* m_pAllocators[25];

	const dl_wchar* GetHeapName(int idx);
};