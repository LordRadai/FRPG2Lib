#include "DLNew.h"
#include "FRPG2Globals.h"
#include "FRPG2Call.h"

typedef dl_pointer(_fastcall* oAlloc)(size_t size, size_t alignment, DLKR::DLAllocator* pAllocator);
typedef void(_fastcall* oFree)(dl_pointer memoryBlock, DLKR::DLAllocator* pAllocator);

namespace DLKR
{
	dl_pointer AllocateAligned(size_t blockSize, size_t alignment, DLAllocator* pAllocator)
	{
		return FRPG2_CALL(oAlloc, 0x833320, blockSize, alignment, pAllocator);
	}

	void Free(dl_pointer pMem, DLAllocator* pAllocator)
	{
		return FRPG2_CALL(oFree, 0x8332d0, pMem, pAllocator);
	}
}