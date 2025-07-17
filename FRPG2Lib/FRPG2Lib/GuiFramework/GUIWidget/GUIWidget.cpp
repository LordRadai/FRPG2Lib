#include "GUIWidget.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oOnDestroy)(GUIWidget* pThis);
	typedef int(_fastcall* oOnUpdate)(GUIWidget* pThis, GUIWindowBase* param_1);
	typedef UINT64(_fastcall* oGetChildren)(GUIWidget* pThis);
	typedef int* (_fastcall* oVf30)(GUIWidget* pThis, int* param_1);
	typedef GUIWidget*(_fastcall* oVf38)(GUIWidget* pThis, GUIWindowBase* param_1, int param_2);
	typedef int(_fastcall* oInputAction)(GUIWidget* pThis, MousePosData* mousePos);
	typedef int(_fastcall* oVf118)(GUIWidget* pThis, BYTE* pUnkAction);
	typedef int(_fastcall* oCalcContentSize)(GUIWidget* pThis, int* pDst);
	typedef int(_fastcall* oVf130)(GUIWidget* pThis, int* pDst);
	typedef int(_fastcall* oInitialise)(GUIWidget* pThis);
	typedef int(_fastcall* oVf1A8)(GUIWidget* pThis, GUIWidget* param_1);
	typedef void(_fastcall* oDestroyChildren)(GUIWidget* pThis);
	typedef void(_fastcall* oDraw)(GUIWidget* pThis, AppGUIRender* pAppGUIRender);
	typedef void(_fastcall* oVf1C0)(GUIWidget* pThis);
	typedef int* (_fastcall* oVf1D8)(GUIWidget* pThis, int* pDst);
	typedef int* (_fastcall* oVf1E0)(GUIWidget* pThis, int* pDst);
	typedef void(_fastcall* oVf1E8)(GUIWidget* pThis, int* pDst1, short* pDst2);

	typedef void(_fastcall* oSetAsChild)(GUIWidget* pThis, GUIWidget* pParent, GUIWidgetInitData* widgetData);
	typedef void(_fastcall* oEditPosSize)(GUIWidget* pThis, dl_uint pos_x, dl_uint pos_y, dl_uint size_x, dl_uint size_y);
	typedef void(_fastcall* oDestroy)(GUIWidget* pThis);

	void GUIWidget::OnDestroy()
	{
		FRPG2_CALL(oDestroy, 0x57abe0, this);
	}

	int GUIWidget::OnUpdate(GUIWindowBase* param_1)
	{
		return FRPG2_CALL(oOnUpdate, 0x57ae10, this, param_1);
	}

	UINT64 GUIWidget::GetChildren()
	{
		return FRPG2_CALL(oGetChildren, 0x537a50, this);
	}

	int* GUIWidget::Vf30(int* param_1)
	{
		return FRPG2_CALL(oVf30, 0x537a00, this, param_1);
	}

	GUIWindowBase* GUIWidget::Vf38(GUIWindowBase* param_1, int param_2)
	{
		return FRPG2_CALL(oVf38, 0x57ba90, this, param_1, param_2);
	}

	int GUIWidget::OnMouseOverContent(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x57fad0, this, mousePos);
	}

	int GUIWidget::OnMouseOverFrame(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x57e570, this, mousePos);
	}

	int GUIWidget::OnActionButtonLeftClick(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x57edd0, this, mousePos);
	}

	int GUIWidget::OnActionButtonLeftClickReleased(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x57f700, this, mousePos);
	}

	int GUIWidget::Input2(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x57fb00, this, mousePos);
	}

	int GUIWidget::Input14(MousePosData* mousePos)
	{
		return FRPG2_CALL(oInputAction, 0x57fb30, this, mousePos);
	}

	int GUIWidget::Vf118(BYTE* pUnkAction)
	{
		return FRPG2_CALL(oVf118, 0x57fcf0, this, pUnkAction);
	}

	int GUIWidget::CalculateContentSize(int* pDst)
	{
		return FRPG2_CALL(oCalcContentSize, 0x57cd90, this, pDst);
	}

	int GUIWidget::Vf130(int* pDst)
	{
		return FRPG2_CALL(oVf130, 0x537df0, this, pDst);
	}

	int GUIWidget::Initialise()
	{
		return FRPG2_CALL(oInitialise, 0x57cb70, this);
	}

	int GUIWidget::Vf1A8(GUIWindowBase* param_1)
	{
		return FRPG2_CALL(oVf1A8, 0x57cc40, this, (GUIWidget*)param_1);
	}

	void GUIWidget::DestroyChildren()
	{
		return FRPG2_CALL(oDestroyChildren, 0x57e460, this);
	}

	void GUIWidget::Draw(AppGUIRender* pAppGUIRender)
	{
		return FRPG2_CALL(oDraw, 0x57bec0, this, pAppGUIRender);
	}

	void GUIWidget::Vf1C0()
	{
		return FRPG2_CALL(oVf1C0, 0x57bf50, this);
	}

	int* GUIWidget::vf1D8(int* pDst)
	{
		return FRPG2_CALL(oVf1D8, 0x57bcd0, this, pDst);
	}

	int* GUIWidget::vf1E0(int* pDst)
	{
		return FRPG2_CALL(oVf1E0, 0x57bd50, this, pDst);
	}

	void GUIWidget::vf1E8(int* pDst1, short* pDst2)
	{
		return FRPG2_CALL(oVf1E8, 0x57cec0, this, pDst1, pDst2);
	}

	void GUIWidget::SetAsChild(GUIWidget* pParent, GUIWidgetInitData* pInitData)
	{
		FRPG2_CALL(oSetAsChild, 0x54f930, this, pParent, pInitData);
	}

	void GUIWidget::EditPosSize(dl_uint x, dl_uint y, dl_uint width, dl_uint height)
	{
		FRPG2_CALL(oEditPosSize, 0x550580, this, x, y, width, height);
	}

	void GUIWidget::Destroy()
	{
		FRPG2_CALL(oDestroy, 0x54fa10, this);
	}
}