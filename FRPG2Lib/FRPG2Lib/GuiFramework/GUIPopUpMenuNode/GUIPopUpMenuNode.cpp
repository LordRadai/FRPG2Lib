#include "GUIPopUpMenuNode.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oAddGUIPopUpMenuNode)(GUIPopUpMenuNode* pThis, GUISystem* pAppGUISystem, GUIText* title, dl_uint styleFlags);
	typedef dl_bool(_fastcall* oSetChildFlags)(GUIPopUpMenuNode* pThis, dl_int id, dl_uint setMask, dl_uint clearMask);
	typedef GUIPopUpMenuString*(_fastcall* oAddGUIPopUpMenuString)(GUIPopUpMenuNode* pThis, GUIText* title, dl_int id, dl_int index);
	typedef GUIPopUpMenuSeparator*(_fastcall* oAddGUIPopUpMenuSeparator)(GUIPopUpMenuNode* pThis, dl_int id, dl_int index);
	typedef GUIPopUpMenuNode*(_fastcall* oAddGUIPopUpMenuSubNode)(GUIPopUpMenuNode* pThis, GUIText* title, dl_int id, dl_int index);

	GUIPopUpMenuNode::GUIPopUpMenuNode(GUISystem* pAppGUISystem, GUIText* title, dl_uint styleFlags)
	{
		FRPG2_CALL(oAddGUIPopUpMenuNode, 0x524b50, this, pAppGUISystem, title, styleFlags);
	}

	dl_bool GUIPopUpMenuNode::SetChildStyleFlags(dl_int id, dl_uint setMask, dl_uint clearMask)
	{
		return FRPG2_CALL(oSetChildFlags, 0x525350, this, id, setMask, clearMask);
	}

	GUIPopUpMenuString* GUIPopUpMenuNode::AddString(const dl_wchar* title, dl_int id, dl_int index)
	{
		GUIText label(title);

		GUIPopUpMenuString* pString = FRPG2_CALL(oAddGUIPopUpMenuString, 0x524c60, this, &label, id, index);

		label.Free();

		return pString;
	}

	GUIPopUpMenuSeparator* GUIPopUpMenuNode::AddSeparator(dl_int id, dl_int index)
	{
		return FRPG2_CALL(oAddGUIPopUpMenuSeparator, 0x5250c0, this, id, index);
	}

	GUIPopUpMenuString* GUIPopUpMenuNode::AddSelectableString(const dl_wchar* title, dl_int id, dl_bool bSelectable)
	{
		GUIPopUpMenuString* pPopUpMenuString = this->AddString(title, id);

		if (bSelectable)
			this->SetChildStyleFlags(id, GuiFramework::PopUpStringFlag_Selectable, 0);
		else
			this->SetChildStyleFlags(id, GuiFramework::PopUpStringFlag_None, 1);

		return pPopUpMenuString;
	}

	GUIPopUpMenuString* GUIPopUpMenuNode::AddCheckboxString(const dl_wchar* title, dl_int id, dl_bool bSelected, dl_bool bSelectable)
	{
		GUIPopUpMenuString* pPopUpMenuString = this->AddString(title, id);

		if (bSelectable)
		{
			if (bSelected)
				this->SetChildStyleFlags(id, GuiFramework::PopUpStringFlag_Selectable | GuiFramework::PopUpStringFlag_Checkbox | GuiFramework::PopUpStringFlag_Enabled, 0);
			else
				this->SetChildStyleFlags(id, GuiFramework::PopUpStringFlag_Selectable | GuiFramework::PopUpStringFlag_Checkbox, 0);
		}
		else
		{
			if (bSelected)
				this->SetChildStyleFlags(id, GuiFramework::PopUpStringFlag_Checkbox | GuiFramework::PopUpStringFlag_Enabled, 0);
			else
				this->SetChildStyleFlags(id, GuiFramework::PopUpStringFlag_Checkbox, 1);
		}

		return pPopUpMenuString;
	}

	GUIPopUpMenuNode* GUIPopUpMenuNode::AddSubNode(const dl_wchar* title, dl_int id, dl_int index)
	{
		GUIText label(title);

		GUIPopUpMenuNode* pNode = FRPG2_CALL(oAddGUIPopUpMenuSubNode, 0x5251d0, this, &label, id, index);

		return pNode;
	}

	GUIPopUpMenu* GUIPopUpMenuNode::AddPopUpMenu()
	{
		return new GUIPopUpMenu(this);
	}
}