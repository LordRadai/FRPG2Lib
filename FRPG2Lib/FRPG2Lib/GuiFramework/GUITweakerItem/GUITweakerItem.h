#pragma once
#include "../GUIMsgReceiver/GUIMsgReceiver.h"

namespace GuiFramework
{
	class GUITweakerItem : public GUIMsgReceiver
	{
	public:
		GUITweakerItem() : GUIMsgReceiver() {}

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617d90); }
		virtual ~GUITweakerItem() {}
		virtual void onDestroy() {}
		virtual void update() {}
		virtual void unregister() {}
	};
}