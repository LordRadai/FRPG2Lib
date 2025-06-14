#pragma once
#include "../GUITweakerBase/GUITweakerBase.h"
#include "../GUIRangeData/GUIRangeDataBase.h"
#include "../GUIRangeTweakWidget/GUIRangeTweakWidget.h"

namespace GuiFramework
{
	class GUIRangeTweaker : public GUITweakerBase
	{
	public:
		GUIRangeTweaker() {}

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617220); }
		virtual ~GUIRangeTweaker() {}
		virtual void onDestroy();
		virtual void unregister();
		virtual void vf30() {}
		virtual GUIRangeDataBase* getRangeData() = 0;

		void CreateRangeTweakWidget(GUIWidget* pParent, GUIText* title);

		GUIRangeTweakWidget* m_pRangeTweakWidget = nullptr;
	};
}