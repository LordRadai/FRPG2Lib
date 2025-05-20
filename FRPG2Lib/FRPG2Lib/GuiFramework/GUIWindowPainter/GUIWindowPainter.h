#pragma once
#include "../GUIObject/GUIObject.h"

namespace GuiFramework
{
	class AppGUISystem;

	class GUIWindowPainter : public GUIObject
	{
		AppGUISystem* m_pAppGUISystem;
	};
}