#include "GUITweakerGroup.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oAddWidgetAsChild)(GUITweakerGroup* pThis, GUITweakerItem* pTweakerItem);

	void GUITweakerGroup::AddTweakerAsChild(GUITweakerItem* pTweakerItem)
	{
		FRPG2_CALL(oAddWidgetAsChild, 0x54d3a0, this, pTweakerItem);
	}
}