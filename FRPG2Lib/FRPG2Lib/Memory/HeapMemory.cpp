#include "HeapMemory.h"
#include "FRPG2Call.h"

typedef DLKR::DLAllocator* (_fastcall* oGetAllocator)(HeapMemory* pThis);

DLKR::DLAllocator* HeapMemory::GetAllocator()
{
	return FRPG2_VCALL(this, 7, oGetAllocator, this);
}