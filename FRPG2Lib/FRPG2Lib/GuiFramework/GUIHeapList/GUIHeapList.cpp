#include "GUIHeapList.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef UINT64(_fastcall* oGUIHeapList)(GUIHeapList* pThis, GUIWidget* pParent, GUIText* title, GUIWidgetInitData* param_4);

	GUIHeapList::GUIHeapList(GUIWidget* pParent, GUIText* title)
	{
		GUIWidgetInitData widgetData(0, 0, 900, 300, 1);
		FRPG2_CALL(oGUIHeapList, 0xc531e0, this, pParent, title, &widgetData);
	}

	void GUIHeapList::onDestroy()
	{
		for (size_t i = 0; i < this->m_listViewItems.size(); i++)
		{
			auto item = this->getItem(i);

			if (item)
				item->Destroy();
		}

		this->m_listViewItems.clear();

		GUIListView::onDestroy();
	}

	void GUIHeapList::destroyChildren()
	{
		for (size_t i = 0; i < this->m_listViewItems.size(); i++)
		{
			auto item = this->getItem(i);

			if (item)
				item->Destroy();
		}

		this->m_listViewItems.clear();

		GUIListView::destroyChildren();
	}

	int GUIHeapList::initialise()
	{
		int initStatus = GUIListView::initialise();

		if (initStatus)
		{
			this->addColumn(L"HeapID", 50);
			this->addColumn(L"AllocatorID", 50);
			this->addColumn(L"FreeSize", 100);
			this->addColumn(L"UseSize", 100);
			this->addColumn(L"Use (%)", 50);
			this->addColumn(L"Total Size", 100);
			this->addColumn(L"MaxUseSize", 100);
			this->addColumn(L"MaxUse (%)", 50);
		}

		return initStatus;
	}

	GUIHeapListItem* GUIHeapList::AddHeapListItem(const dl_wchar* title, DLKR::DLAllocator* pAllocator)
	{
		GUIText guiTextItem(title);

		GUIHeapListItem* pHeapListItem = new GUIHeapListItem(this, &guiTextItem, pAllocator);
		guiTextItem.Free();

		return pHeapListItem;
	}
}