#include "GUIMultiTweaker.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oGUIMultiTweaker)(GUIMultiTweaker* pThis, UINT count, GUIText* titleStruct);
	typedef void(_fastcall* oOnDestroy)(GUIMultiTweaker* pThis);
	typedef void(_fastcall* oUnregister)(GUIMultiTweaker* pThis);

	typedef UINT64(_fastcall* oSetWidgetsAsChildren)(GUIMultiTweaker* pThis, GUITweakerGroup* pParent, GUIText* titleStruct);

	GUIMultiTweaker::GUIMultiTweaker(UINT count, GUIText* title) : GUITweakerBase()
	{
		FRPG2_CALL(oGUIMultiTweaker, 0x5b3e30, this, count, title);
	}

	void GUIMultiTweaker::onDestroy()
	{
		FRPG2_CALL(oOnDestroy, 0x5b40b0, this);
	}

	void GUIMultiTweaker::unregister()
	{
		FRPG2_CALL(oUnregister, 0x5b40e0, this);
	}

	void GUIMultiTweaker::RegisterWidgets(GUITweakerGroup* pParent, GUIText* title)
	{
		FRPG2_CALL(oSetWidgetsAsChildren, 0x5b3f90, this, pParent, title);
	}
}