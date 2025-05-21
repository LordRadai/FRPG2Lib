#pragma once
#include "dantelion2/dantelion2.h"

class HeapMemory
{
	struct HeapInfo
	{
		dl_char* m_pBuffer;
		dl_pointer m_pVar8;
		dl_size m_size;
		dl_size m_capacity;
		dl_char m_name[32];
		dl_pointer m_pVar40;
		dl_pointer m_pVar48;
		dl_pointer m_pVar50;
		dl_pointer m_pVar58;
		dl_char m_bVar60;
		dl_int m_iVar64;
		dl_int m_iVar68;
	};

	void** _vfptr;
	dl_size m_pVar8;
	HeapMemory* m_pAllocatorMemory;
	HeapInfo m_heapInfo;
	dl_uint m_blockID;
	dl_size m_iVar90;
	dl_size m_id;
	dl_int16* m_pVarA0;

public:
	const dl_char* GetName() const { return this->m_heapInfo.m_pBuffer; }
	DLKR::DLAllocator* GetAllocator();
};