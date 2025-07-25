#pragma once
#include "../GUIListView/GUIListView.h"
#include "GUIHeapListItem.h"

namespace GuiFramework
{
	class GUIHeapList : public GUIListView
	{
	public:
		GUIHeapList() {}
		GUIHeapList(GUIWidget* pParent, GUIText* title);

		virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1878b58); }
		virtual ~GUIHeapList() {}
		virtual void OnDestroy();
		virtual void DestroyChildren();
		virtual int Initialise();

		GUIHeapListItem* GetItem(int idx) const { return static_cast<GUIHeapListItem*>(this->m_listViewItems[idx]); }

		GUIHeapListItem* AddHeapListItem(const dl_wchar* title, DLKR::DLAllocator* pAllocator);

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUIHeapList), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		dl_uchar m_bVar170 = 0;
		dl_float32 m_fVar174 = 1.f;
		dl_float32 m_fVar178 = 0.f;
	};
}