#pragma once
#include "../GUIWidget/GUIWidget.h"

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
		dl_int m_iVar138;
		dl_int m_iVar13C;
		dl_pointer* m_pEditBox;
		dl_int m_selectedItem;

		void SetDisplayItem(dl_int idx);
	};
}