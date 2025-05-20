#pragma once
#include "dantelion2/dantelion2.h"

class HeapMemory
{
	struct HeapInfo
	{
		dl_char* m_pBuffer;
		dl_char m_smallStr[8];
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
	HeapMemory* m_pAllocatorMemory;
	dl_size m_size;
	HeapInfo m_heapInfo;
	dl_uint m_blockID;
	dl_size m_iVar90;
	dl_size m_id;
	dl_int16* m_pVarA0;
};