#pragma once
#include "dantelion2/Core/Platform/Platform.h"

namespace DLKR
{
	class DLRegularHeap
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

		dl_size m_freeSize;
		dl_pointer m_pVar8;
		dl_pointer m_pVar10;
		dl_size m_useSize;
		dl_size m_numBlocks;
		HeapBlockLink m_links[64];
		dl_pointer m_pVar428;
		dl_pointer m_pVar430;
		dl_size m_totalSize;
	};
}