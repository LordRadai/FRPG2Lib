#pragma once
#include "../GUITweakerBase/GUITweakerBase.h"
#include "../GUIComboTweakWidget/GUIComboTweakWidget.h"
#include "../GUITweakerGroup/GUITweakerGroup.h"

namespace GuiFramework
{
	class GUIComboTweaker : public GUITweakerBase
	{
	public:
		GUIComboTweaker() {}
		GUIComboTweaker(GUITweakerGroup* pParent, GUIText* title, int param_3);

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)((UINT64)(g_moduleAddr)+0x1617348); }
		virtual ~GUIComboTweaker() {}
		virtual void onDestroy();
		virtual void update() {}
		virtual void unregister();
		virtual void updateValue(UINT idx) {}

		GUIComboTweakWidget* m_pGUIComboTweakWidget = nullptr;
	};
}