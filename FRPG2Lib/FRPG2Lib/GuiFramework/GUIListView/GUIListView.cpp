#include "GUIListView.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef UINT64(_fastcall* oGUIListView)(GUIListView* pThis, GUIWidget* pRoot, GUIText* title, int flags, int param_4);
	typedef UINT64(_fastcall* oGUIListViewAlt)(GUIListView* pThis, GUIText* title);
	typedef UINT64(_fastcall* oGUIListViewAlt2)(GUIListView* pThis, GUIWidget* pRoot, GUIText* title, GUIWidgetInitData* param_3);
	typedef void(_fastcall* oOnDestroy)(GUIListView* pThis);
	typedef int(_fastcall* oInputAction)(GUIListView* pThis, MousePosData* mousePos);
	typedef int(_fastcall* oVf118)(GUIListView* pThis, BYTE* pUnkAction);
	typedef int(_fastcall* oVf130)(GUIListView* pThis, int* pDst);
	typedef int(_fastcall* oVf158)(GUIListView* pThis, short* pDst);
	typedef int(_fastcall* oVf170)(GUIListView* pThis);
	typedef int(_fastcall* oInitialise)(GUIListView* pThis);
	typedef void(_fastcall* oDestroyChildren)(GUIListView* pThis);
	typedef void(_fastcall* oDraw)(GUIListView* pThis, AppGUIRender* pAppGUIRender);

	typedef bool(_fastcall* oAddListViewItemToListView)(GUIListView* pListView, GUIListViewItem* pListViewItem, int id);
	typedef bool(_fastcall* oAddListViewColumn)(GUIListView* pThis, GUIText* label, short id, short width, int param_5);
	typedef bool(_fastcall* oSetColumnLabel)(GUIListView* pThis, short id, GUIText* label);
	typedef bool(_fastcall* oSetColumnWidth)(GUIListView* pThis, short id, short width);

	GUIListView::GUIListView(GUIText* title)
	{
		FRPG2_CALL(oGUIListViewAlt, 0x5ca3b0, this, title);
	}

	GUIListView::GUIListView(GUIWidget* pRoot, GUIText* title, GUIWidgetInitData* param_3)
	{
		FRPG2_CALL(oGUIListViewAlt2, 0x5ca450, this, pRoot, title, param_3);
	}

	GUIListView::GUIListView(GUIWidget* pRoot, GUIText* title, int flags, int param_4)
	{
		FRPG2_CALL(oGUIListView, 0x5ca510, this, pRoot, title, flags, param_4);
	}

	void GUIListView::onDestroy()
	{
		FRPG2_CALL(oOnDestroy, 0x5cd450, this);
	}

	int GUIListView::onMouseOverContent(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x5ccf90, this, mousePos);
	}

	int GUIListView::input9(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x5ccd60, this, mousePos);
	}

	int GUIListView::onMouseWheelScroll(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x5cd140, this, mousePos);
	}

	int GUIListView::onLeftClick(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x5ccb10, this, mousePos);
	}

	int GUIListView::onLeftClickReleased(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x5ccf10, this, mousePos);
	}

	int GUIListView::onRightClick(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x5cccb0, this, mousePos);
	}

	int GUIListView::vf118(BYTE* pUnkAction)
	{
		return FRPG2_CALL(oVf118, 0x5cbfe0, this, pUnkAction);
	}

	int GUIListView::vf158(short* param_1)
	{
		return FRPG2_CALL(oVf158, 0x5cd240, this, param_1);
	}

	int GUIListView::vf170()
	{
		return FRPG2_CALL(oVf170, 0x5ccae0, this);
	}

	int GUIListView::initialise()
	{
		return FRPG2_CALL(oInitialise, 0x5cc930, this);
	}

	void GUIListView::destroyChildren()
	{
		FRPG2_CALL(oDestroyChildren, 0x5cd570, this);
	}

	void GUIListView::draw(AppGUIRender* pAppGUIRender)
	{
		FRPG2_CALL(oDraw, 0x5cc3f0, this, pAppGUIRender);
	}

	bool GUIListView::registerListViewItem(GUIListViewItem* pItem)
	{
		return FRPG2_CALL(oAddListViewItemToListView, 0x5ca910, this, pItem, -1);
	}

	bool GUIListView::addColumn(const wchar_t* label, short width)
	{
		GUIText guiTextItem(label);

		const int idx = this->getNumColumns();

		bool status = FRPG2_CALL(oAddListViewColumn, 0x5ca970, this, &guiTextItem, idx, width, -1);
		this->setColumnWidth(idx, width);

		guiTextItem.Free();

		return status;
	}

	bool GUIListView::setColumnWidth(short idx, short width)
	{
		return FRPG2_CALL(oSetColumnWidth, 0x5cad90, this, idx, width);
	}

	bool GUIListView::setColumnLabel(short idx, GUIText* label)
	{
		return FRPG2_CALL(oSetColumnLabel, 0x5cac70, this, idx, label);
	}

	GUIListViewItem* GUIListView::AddListViewItem(const dl_wchar* title)
	{
		GUIText guiTextItem(title);

		GUIListViewItem* pListViewItem = new GUIListViewItem(this, &guiTextItem);
		guiTextItem.Free();

		return pListViewItem;
	}
}