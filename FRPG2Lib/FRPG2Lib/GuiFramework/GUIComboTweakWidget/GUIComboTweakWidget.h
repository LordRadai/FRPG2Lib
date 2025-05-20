#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "dantelion2/dantelion2.h"
#include "../GUIComboBox/GUIComboBox.h"

namespace GuiFramework
{
	class GUIComboTweakWidget : public GUIWidget
	{
	public:
		GUIComboBox* m_pComboBox;
		dl_int16 m_sVar118;
	};
}