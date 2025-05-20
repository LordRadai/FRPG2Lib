#include "GUIPopUpMenu.h"
#include "../GUIPopUpMenuNode/GUIPopUpMenuNode.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef GUIPopUpMenu*(_fastcall* oAddGUIPopUpMenu)(GUIPopUpMenu* pThis, GUIPopUpMenuNode* pGuiPopUpMenuNode);
	typedef dl_bool(_fastcall* oShowPopUpMenu)(GUIPopUpMenu* pThis, GUIWindowBase* pParent, GUIWindowBase* param_3, dl_int* param_4);

	GUIPopUpMenu::GUIPopUpMenu(GUIPopUpMenuNode* pPopUpMenuNode)
	{
		FRPG2_CALL(oAddGUIPopUpMenu, 0x5587e0, this, pPopUpMenuNode);
	}

	dl_bool GUIPopUpMenu::Show(GUIWindowBase* pParent, dl_int* pPosition)
	{
		return FRPG2_CALL(oShowPopUpMenu, 0x5589f0, this, pParent, pParent, pPosition);
	}
}