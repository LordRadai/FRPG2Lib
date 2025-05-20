#pragma once
#include "../GUIWidget/GUIWidget.h"

namespace GuiFramework
{
	class GUIRootWindow : public GUIWidget
	{
	public:
		virtual ~GUIRootWindow();
		virtual void draw(AppGUIRender* pAppGUIRender) {}
		virtual void vf1C0() {}
	};
}