#pragma once
#include "../GUITweakerBase/GUITweakerBase.h"
#include "../GUICallbackObject/GUICallbackObjectBase.h"
#include "../GUITweakerGroup/GUITweakerGroup.h"

namespace GuiFramework
{
	class GUITriggerTweaker : public GUITweakerBase
	{
		DLUT::DLVector<GUICallbackObjectBase*> m_callbackObjects;
		dl_pointer m_pTriggerTweakWidget;

	public:
		void AddButton(const dl_wchar* label, GUICallbackObjectBase* GUICallbackObject);
	};
}