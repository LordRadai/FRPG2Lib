#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLLifeCycleAdapter.h"
#include "DLReadWriteLock.h"

namespace DLKR
{
	class DLBiHeap
	{
		struct HeapName
		{
			dl_size m_size;
			dl_size m_capacity;
			dl_char m_name[16];
		};

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

		HeapBlockLink m_root;
		dl_int m_iVar10;
		dl_int m_iVar14;
		HeapName m_name;
		DLUT::DLLifeCycleAdapter<DLPlainReadWriteLock>* m_pLock;
		dl_pointer m_pVar40;
		dl_size m_iVar48;
		dl_size m_iVar50;
		HeapBlockLink m_unkLink;
	};
}