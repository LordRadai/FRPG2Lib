#pragma once
#include "dantelion2/Core/Platform/Platform.h"

namespace DLKR
{
	class DLRobustHeap
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

		dl_size m_totalSize;
		dl_size m_freeSize;
		dl_size m_useSize;
		HeapBlock m_root;
	};
}