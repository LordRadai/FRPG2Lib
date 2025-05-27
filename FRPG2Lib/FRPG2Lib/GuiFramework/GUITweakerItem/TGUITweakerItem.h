#pragma once
#include "GUITweakerItem.h"

class GUIWindowManager;

namespace GuiFramework
{
	template <typename T>
	class TGUITweakerItem : public GUITweakerItem
	{
		T* m_pGUITweaker;
		GUIWindowManager* m_pWindowManager;
		dl_pointer m_pVar20;
		dl_pointer m_pGUIInvoker;

	public:
		T* GetGUITweaker() const { return m_pGUITweaker; }
	};
}