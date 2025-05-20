#pragma once
#include "../GUITweakerBase/GUITweakerBase.h"
#include "../GUIRangeData/TGUIRangeData.inl"
#include "../GUIMultiNumericEditor/GUIMultiNumericEditor.h"
#include "../GUITweakerGroup/GUITweakerGroup.h"

namespace GuiFramework
{
	class GUIMultiTweaker : public GUITweakerBase
	{
	public:
		GUIMultiTweaker() : GUITweakerBase() {}
		GUIMultiTweaker(UINT count, GUIText* title);

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)((UINT64)(g_moduleAddr)+0x1618148); }
		virtual ~GUIMultiTweaker() {}
		virtual void onDestroy();
		virtual void unregister();

		void RegisterWidgets(GUITweakerGroup* pParent, GUIText* title);

		GUIMultiNumericEditor* m_pMultiNumericEditor = nullptr;
	};
}