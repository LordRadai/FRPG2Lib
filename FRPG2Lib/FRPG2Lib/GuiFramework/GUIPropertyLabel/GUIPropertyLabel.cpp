#include "GUIPropertyLabel.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef UINT64(_fastcall* oGUIPropertyLabel)(GUIPropertyLabel* pThis, GUIWidget* pParent, GUIText* title, UINT param_3);
	typedef void(_fastcall* oDraw)(GUIPropertyLabel* pThis, AppGUIRender* pAppGUIRender);

	GUIPropertyLabel::GUIPropertyLabel(GUITweakerGroup* pParent, GUIText* title, UINT param_3)
	{
		FRPG2_CALL(oGUIPropertyLabel, 0x5566c0, this, pParent, title, param_3);
	}

	void GUIPropertyLabel::draw(AppGUIRender* pAppGUIRender)
	{
		FRPG2_CALL(oDraw, 0x556920, this, pAppGUIRender);
	}
}