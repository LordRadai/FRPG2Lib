#include "GUIRangeTweakWidget.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oUpdateDisplayValue)(GUIRangeTweakWidget* pThis);

	void GUIRangeTweakWidget::UpdateDisplayValue()
	{
		FRPG2_CALL(oUpdateDisplayValue, 0x5435f0, this);
	}
}