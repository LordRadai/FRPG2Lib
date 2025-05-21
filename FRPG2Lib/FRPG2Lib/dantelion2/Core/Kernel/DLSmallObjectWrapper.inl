#pragma once
#include "dantelion2/Core/Platform/Platform.h"

namespace DLKR
{
	template<class _Heap, dl_uint ID, dl_uint Size, dl_uint BlockSize, dl_uint BlockAlignment>
	class DLSmallObjectWrapper
	{
		struct HeapBlockLink
		{
			HeapBlockLink* m_pPrev;
			HeapBlockLink* m_pNext;
		};

		struct HeapBlock
		{
			HeapBlockLink m_link;
			HeapBlockLink m_freeLink;
		};

		struct BlockWrapper
		{
			dl_size m_offset;
			dl_size m_iVar8;
			HeapBlockLink m_block;
		};

		_Heap m_heap;
		dl_pointer m_pTop;
		BlockWrapper m_heapData[BlockSize / BlockAlignment];
		dl_size m_iVar0;
		dl_size m_iVar8;
	};
}