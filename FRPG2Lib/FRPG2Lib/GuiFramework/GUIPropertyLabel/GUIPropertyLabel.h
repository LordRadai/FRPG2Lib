#pragma once
#include "../GUIWindowBase/GUIWindowBase.h"
#include "../GUIWidget/GUIWidget.h"
#include "../GUITweakerGroup/GUITweakerGroup.h"

namespace GuiFramework
{
	class GUIPropertyLabel : public GUIWindowBase
	{
	public:
		GUIPropertyLabel() {}
		GUIPropertyLabel(GUITweakerGroup* pParent, GUIText* title, UINT param_3);

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUIPropertyLabel), 8, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)((UINT64)(g_moduleAddr)+0x1617668); }
		virtual ~GUIPropertyLabel() {}
		virtual void onDestroy() { GUIWindowBase::onDestroy(); }
		virtual void draw(AppGUIRender* pAppGUIRender);
		virtual int updateLabel(DLTX::DLString* buffer) { return 0; }
	};
}