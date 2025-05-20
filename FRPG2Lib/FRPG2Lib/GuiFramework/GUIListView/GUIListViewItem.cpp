#include "GUIListViewItem.h"
#include "GUIListView.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef UINT64(_fastcall* oGUIListView)(GUIListViewItem* pThis, GUIListView* pListView, GUIText* title);
	typedef void(_fastcall* oOnDestroy)(GUIListViewItem* pThis);

	GUIListViewItem::GUIListViewItem(GUIListView* pListView, GUIText* label)
	{
		FRPG2_CALL(oGUIListView, 0x5d2d50, this, pListView, label);

		pListView->registerListViewItem(this);
	}

	void GUIListViewItem::onDestroy()
	{
		FRPG2_CALL(oOnDestroy, 0x5d3340, this);
	}
}