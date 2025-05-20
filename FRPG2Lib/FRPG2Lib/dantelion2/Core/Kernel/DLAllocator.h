#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "Types.h"
#include "DLHeapCapability.h"
#include "DLHeapIdentifier.h"

namespace DLKR
{
	class DLAllocator
	{
    public:
        typedef dl_size size_type;

        typedef void* pointer;
        typedef const void* const_pointer;

        typedef dl_pointer_int ptrdiff_t;
        typedef dl_pointer_int difference_type;

		void** _vfptr;
        ~DLAllocator();

        DLHeapIdentifier GetHeapID() const;
        DLHeapIdentifier GetAllocatorID() const;
        DLHeapCapability GetCapability(DLHeapDirection d = HD_FRONT) const;

        dl_size GetTotalSize() const;
        dl_size GetFreeSize() const;
        dl_size GetMaxSize() const;
        dl_size GetBlockNumber() const;
        dl_size GetBlockSize(const void* block) const;

        pointer Allocate(size_type size);
        pointer AllocateAligned(size_type size, dl_uint align);
        pointer Reallocate(void* old, size_type size);
        pointer ReallocateAligned(void* old, dl_size size, dl_uint align);

        void Free(pointer p);
        void FreeAll();

        void* BackAllocate(dl_size size);
        void* BackAllocateAligned(dl_size size, dl_uint align);
        void* BackReallocate(void* old, dl_size size);
        void* BackReallocateAligned(void* old, dl_size size, dl_uint align);
        void BackFree(void* block);

        dl_bool SelfDiagnose() const;
        dl_bool IsValidBlock(const void* block) const;
	};
}