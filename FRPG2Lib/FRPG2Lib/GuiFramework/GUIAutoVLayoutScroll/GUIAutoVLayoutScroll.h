#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "../GUIAutoVLayout/GUIautoVLayout.h"

namespace GuiFramework
{
	class GUIAutoVLayoutScroll : public GUIWidget
	{
		GUIAutoVLayout* m_pAutoVLayout = nullptr;
		dl_int16 m_sizeData[6];
	};
}