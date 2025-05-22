#pragma once
#include "../GUIWidget/GUIWidget.h"

namespace GuiFramework
{
	class GUIListBox : public GUIWidget
	{
	public:
		DLUT::DLVector<dl_pointer> m_pItems;
		dl_int m_iVar130;
		dl_int m_iVar134;
		dl_int m_iVar138;
		dl_int m_iVar13C;
		dl_int m_iVar140;
		dl_int16 m_itemHeight;
		dl_int16 m_iVar146;
		dl_int m_iVar148;
	};
}