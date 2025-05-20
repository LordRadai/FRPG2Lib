#include "GUITriggerTweaker.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oAddGUIButton)(GUITriggerTweaker* pThis, GUIText* title, GUICallbackObjectBase* GUICallbackObject);

	void GUITriggerTweaker::AddButton(const dl_wchar* label, GUICallbackObjectBase* GUICallbackObject)
	{
		GUIText title(label);

		FRPG2_CALL(oAddGUIButton, 0x53d260, this, &title, GUICallbackObject);

		title.Free();
	}
}