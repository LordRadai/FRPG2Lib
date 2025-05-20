#include "GUIComboTweaker.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oGUIComboTweaker)(GUIComboTweaker* pThis, GUITweakerGroup* pParent, GUIText* title, int param_3);
	typedef void(_fastcall* oOnDestroy)(GUIComboTweaker* pThis);
	typedef void(_fastcall* oUnregister)(GUIComboTweaker* pThis);

	GUIComboTweaker::GUIComboTweaker(GUITweakerGroup* pParent, GUIText* title, int param_3)
	{
		FRPG2_CALL(oGUIComboTweaker, 0x547be0, this, pParent, title, param_3);
	}

	void GUIComboTweaker::onDestroy()
	{
		FRPG2_CALL(oOnDestroy, 0x547f60, this);
	}

	void GUIComboTweaker::unregister()
	{
		FRPG2_CALL(oOnDestroy, 0x547fb0, this);
	}
}