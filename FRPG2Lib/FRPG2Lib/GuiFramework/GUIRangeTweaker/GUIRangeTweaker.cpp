#include "GUIRangeTweaker.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oOnDestroy)(GUIRangeTweaker* GUIRangeTweaker);
	typedef void(_fastcall* oUnregister)(GUIRangeTweaker* GUIRangeTweaker);

	typedef void(_fastcall* oCreateRangeTweakWidget)(GUIRangeTweaker* pThis, GUIWidget* pParent, GUIText* title);

	void GUIRangeTweaker::onDestroy()
	{
		FRPG2_CALL(oOnDestroy, 0x541fc0, this);
	}

	void GUIRangeTweaker::unregister()
	{
		FRPG2_CALL(oUnregister, 0x541ff0, this);
	}

	void GUIRangeTweaker::CreateRangeTweakWidget(GUIWidget* pParent, GUIText* title)
	{
		FRPG2_CALL(oCreateRangeTweakWidget, 0x541d60, this, pParent, title);
	}
}