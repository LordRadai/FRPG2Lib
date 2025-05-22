#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "../GUIDropDownList/GUIDropDownList.h"
#include "../GUINumericEditBox/GUINumericEditBox.h"

namespace GuiFramework
{
	class GUIComboBox : public GUIWidget
	{
	public:
		struct ValueStringPair
		{
			dl_int64 m_value;
			dl_wchar* m_string;
		};

		DLUT::DLVector<ValueStringPair> m_valueStringPairs;
		TGUI_RECT<dl_uint16> m_rect;
		GUIDropDownList* m_pDropDownList;
		GUINumericEditBox* m_pNumericEditBox;
		dl_int m_selectedItem;

		void SetDisplayItem(dl_int idx);
	};
}