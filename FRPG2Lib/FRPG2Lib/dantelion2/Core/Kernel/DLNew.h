#pragma once
#include "DLAllocator.h"
#include "dantelion2/Core/Platform/Platform.h"

namespace DLKR
{
	dl_pointer AllocateAligned(size_t blockSize, size_t alignment, DLAllocator* pAllocator);
	void Free(dl_pointer pMem, DLAllocator* pAllocator);
}