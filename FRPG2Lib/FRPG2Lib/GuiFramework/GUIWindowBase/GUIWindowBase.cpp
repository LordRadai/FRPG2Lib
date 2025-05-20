#include "GUIWindowBase.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oOnDestroy)(GUIWindowBase* pThis);
	typedef dl_int* (_fastcall* oVf30)(GUIWindowBase* pThis, dl_int* param_2);
	typedef dl_int(_fastcall* oHandleUserInput)(GUIWindowBase* pThis, GUIInputData* pInputData);
	typedef dl_int(_fastcall* oVf118)(GUIWindowBase* pThis, dl_uchar* pUnkAction);
	typedef dl_int(_fastcall* oCalcContentSize)(GUIWindowBase* pThis, dl_int* pDst);
	typedef dl_int(_fastcall* oVf130)(GUIWindowBase* pThis, dl_int* pDst);
	typedef dl_int(_fastcall* oVf1A8)(GUIWindowBase* pThis, GUIWindowBase* param_1);
	typedef void(_fastcall* oDestroyChildren)(GUIWindowBase* pThis);
	typedef void(_fastcall* oDraw)(GUIWindowBase* pThis, AppGUIRender* pAppGUIRender);
	typedef void(_fastcall* oVf1C0)(GUIWindowBase* pThis);
	typedef void(_fastcall* oVf1C8)(GUIWindowBase* pThis);

	void GUIWindowBase::onDestroy()
	{
		FRPG2_CALL(oOnDestroy, 0x551c50, this);
	}

	dl_int* GUIWindowBase::vf30(dl_int* param_1)
	{
		return FRPG2_CALL(oVf30, 0x3c0600, this, param_1);
	}

	dl_bool GUIWindowBase::handleUserInput(GUIInputData* pInputData)
	{
		return FRPG2_CALL(oHandleUserInput, 0x550f90, this, pInputData);
	}

	dl_int GUIWindowBase::vf118(dl_uchar* pUnkAction)
	{
		return FRPG2_CALL(oVf118, 0x551670, this, pUnkAction);
	}

	dl_int GUIWindowBase::calculateContentSize(dl_int* pDst)
	{
		return FRPG2_CALL(oCalcContentSize, 0x3c2300, this, pDst);
	}

	dl_int GUIWindowBase::vf130(dl_int* pDst)
	{
		return FRPG2_CALL(oVf130, 0x551870, this, pDst);
	}

	dl_int GUIWindowBase::vf1A8(GUIWindowBase* param_1)
	{
		return FRPG2_CALL(oVf1A8, 0x551cf0, this, param_1);
	}

	void GUIWindowBase::destroyChildren()
	{
		FRPG2_CALL(oDestroyChildren, 0x551d30, this);
	}

	void GUIWindowBase::draw(AppGUIRender* pAppGUIRender)
	{
		FRPG2_CALL(oDraw, 0x551d60, this, pAppGUIRender);
	}

	void GUIWindowBase::vf1C0()
	{
		FRPG2_CALL(oVf1C0, 0x551e40, this);
	}

	void GUIWindowBase::vf1C8()
	{
		FRPG2_CALL(oVf1C8, 0x5520c0, this);
	}

	const dl_wchar* GUIWindowBase::GetName() const
	{
		if (this->m_name.pStringContainer == nullptr)
			return this->m_name.text;

		return this->m_name.pStringContainer->m_string.c_str();
	}
}