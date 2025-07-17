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
			return DLKR::AllocateAligned(sizeof(GUIPropertyLabel), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617668); }
		virtual ~GUIPropertyLabel() {}
		virtual void OnDestroy() { GUIWindowBase::OnDestroy(); }
		virtual void Draw(AppGUIRender* pAppGUIRender);
		virtual int updateLabel(DLTX::DLString* buffer) { return 0; }
	};
}