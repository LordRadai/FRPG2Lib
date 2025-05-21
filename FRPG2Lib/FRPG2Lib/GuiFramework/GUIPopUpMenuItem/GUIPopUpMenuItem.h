#pragma once
#include "../GUIMsgReceiver/GUIMsgReceiver.h"

namespace GuiFramework
{
	class GUIPopUpMenuItem : public GUIMsgReceiver
	{
		dl_uint16 m_width;
		dl_uint16 m_height;
		dl_int m_id;
		dl_uint m_styleFlags;
		dl_pointer m_pAppGUISystem;

	public:
		GUIPopUpMenuItem() : GUIMsgReceiver() {}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUIPopUpMenuItem), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}
	};
}