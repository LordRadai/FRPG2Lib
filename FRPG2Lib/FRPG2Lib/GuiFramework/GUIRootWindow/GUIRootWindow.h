#pragma once
#include "../GUIWidget/GUIWidget.h"

namespace GuiFramework
{
	class GUIRootWindow : public GUIWidget
	{
	public:
		virtual ~GUIRootWindow();
		virtual void Draw(AppGUIRender* pAppGUIRender) {}
		virtual void Vf1C0() {}
	};
}