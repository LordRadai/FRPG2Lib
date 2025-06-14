#pragma once
#include "../GUIListBox/GUIListBox.h"

namespace GuiFramework
{
	class GUIDropDownList : public GUIListBox
	{
	public:
		static void** GetVTableAddr() { return (void**)(MODULE_ADDR + 0x1102fc8); }

		typedef dl_bool(_fastcall* oInitialize)(GUIDropDownList* pThis);
	};
}