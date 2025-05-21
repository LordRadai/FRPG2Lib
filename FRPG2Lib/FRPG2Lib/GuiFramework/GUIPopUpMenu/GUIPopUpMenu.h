#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "../GUIPopUpMenuItem/GUIPopUpMenuItem.h"

namespace GuiFramework
{
	class GUIPopUpMenuNode;

	class GUIPopUpMenu : public GUIWidget
	{
		struct GUIPopUpChildItem
		{
			TGUI_RECT<dl_uint> m_collidable;
			GUIPopUpMenuItem* m_pItem;
		};

		GUIWidget* m_pParent;
		GUIPopUpMenuNode* m_pPopUpMenuNode;
		dl_int m_iVar120;
		dl_int m_iVar124;
		dl_int m_iVar128;
		dl_int m_iVar12C;
		DLUT::DLVector<GUIPopUpChildItem> m_children;
		dl_int m_hoveredItem;
		dl_int m_iVar154;

	public:
		GUIPopUpMenu(GUIPopUpMenuNode* pPopUpMenuNode);

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUIPopUpMenu), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		dl_bool Show(GUIWindowBase* pParent, dl_int* pPosition);
	};
}