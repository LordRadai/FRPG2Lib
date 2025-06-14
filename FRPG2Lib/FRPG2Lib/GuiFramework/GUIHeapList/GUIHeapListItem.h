#pragma once
#include "../GUIListView/GUIListViewItem.h"

namespace GuiFramework
{
	class GUIHeapList;

	class GUIHeapListItem : public GUIListViewItem
	{
	public:
		enum MemDispFmt
		{
			MEMDISPFMT_AUTO,
			MEMDISPFMT_B,
			MEMDISPFMT_KB,
			MEMDISPFMT_MB,
			MEMDISPFMT_GB
		};

		GUIHeapListItem() {}
		GUIHeapListItem(GUIHeapList* pHeapList, GUIText* label, DLKR::DLAllocator* pAllocator);

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1878b68); }
		virtual ~GUIHeapListItem() {}
		virtual void onDestroy();
		virtual int onUpdate(GUIText* param_1, int columnIdx);

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUIHeapListItem), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void FormatMemoryStringByType(dl_int* pDisplayFmt, DLTX::DLString* pBuffer, dl_size value);

		DLKR::DLAllocator* m_pHeap = nullptr;
	};
}