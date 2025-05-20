#include "GUIRootWindow.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oDestructor)(GUIRootWindow* pThis);

	GUIRootWindow::~GUIRootWindow()
	{
		FRPG2_CALL(oDestructor, 0x572c20, this);
	}
}