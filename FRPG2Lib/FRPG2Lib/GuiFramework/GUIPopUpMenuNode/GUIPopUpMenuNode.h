#pragma once
#include "../GUIPopUpMenuItem/GUIPopUpMenuItem.h"
#include "../GUIPopUpMenuString/GUIPopUpMenuString.h"
#include "../GUIPopUpMenuSeparator/GUIPopUpMenuSeparator.h"
#include "../GUIPopUpMenu/GUIPopUpMenu.h"

namespace GuiFramework
{
	class GUISystem;
	class GUIPopUpMenu;

	enum GUIPopUpMenuNodeFlags
	{
		PopUpStringFlag_None = 0,
		PopUpStringFlag_Selectable = 1 << 0,
		PopUpStringFlag_Checkbox = 1 << 1,
		PopUpStringFlag_Enabled = 1 << 2,
	};

	class GUIPopUpMenuNode : public GUIPopUpMenuItem
	{
		DLUT::DLVector<GUIPopUpMenuItem*> m_pChildren;
		GUIText m_label;
		dl_bool m_bDisallowChildren;
		dl_uint m_flags;

	public:
		GUIPopUpMenuNode() {}
		GUIPopUpMenuNode(GUISystem* pAppGUISystem, GUIText* title, dl_uint param_3);

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUIPopUpMenuNode), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		/*
		* @brief Set the style flags for the child item with the specified actionID.
		* @param id: The ID of the child item.
		* @param setMask: The mask of flags to set.
		* @param clearMask: The mask of flags to clear.
		*/
		dl_bool SetChildStyleFlags(dl_int id, dl_uint setMask, dl_uint clearMask);

		/*
		* @brief Add a string to the pop-up menu.
		* @param label: The label of the string.
		* @param id: The ID for the string.
		* @param index: The index where to insert the string. If it's -1, it's inserted in the last position. Default is -1.
		* @return Pointer to the created string.
		*/
		GUIPopUpMenuString* AddString(const dl_wchar* title, dl_int id, dl_int index = -1);

		/*
		* @brief Add a separator to the pop-up menu.
		* @param id: The ID for the separator. Default is -1.
		* @param index: The index where to insert the string. If it's -1, it's inserted in the last position. Default is -1.
		* @return Pointer to the created separator.
		*/
		GUIPopUpMenuSeparator* AddSeparator(dl_int id = -1, dl_int index = -1);

		/*
		* @brief Add a selectable string to the pop-up menu.
		* @param label: The label of the string.
		* @param ID: The ID for the string.
		* @param bSelectable: Whether the string is selectable or not.
		* @return Pointer to the created string.
		*/
		GUIPopUpMenuString* AddSelectableString(const dl_wchar* label, dl_int id, dl_bool bSelectable);

		/*
		* @brief Add a checkbox string to the pop-up menu.
		* @param label: The label of the string.
		* @param id: The ID for the string.
		* @param bSelected: Whether the checkbox is selected or not.
		* @param bSelectable: Whether the string is selectable or not.
		* @return Pointer to the created string.
		*/
		GUIPopUpMenuString* AddCheckboxString(const dl_wchar* label, dl_int id, dl_bool bSelected, dl_bool bSelectable);

		/*
		* @brief Add a sub-node to the pop-up menu.
		* @param label: The label of the sub-node.
		* @param id: The ID for the sub-node.
		* @param index: The index where to insert the sub-node. If it's -1, it's inserted in the last position. Default is -1.
		* @return Pointer to the created sub-node.
		*/
		GUIPopUpMenuNode* AddSubNode(const dl_wchar* title, dl_int id, dl_int index = -1);

		/*
		* @brief Add a pop-up menu to the node.
		*/
		GUIPopUpMenu* AddPopUpMenu();
	};
}