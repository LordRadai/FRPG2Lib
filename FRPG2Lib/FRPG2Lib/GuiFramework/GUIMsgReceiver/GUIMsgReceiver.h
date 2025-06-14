#pragma once
#include "../GUIObject/GUIObject.h"

namespace GuiFramework
{
	class GUIMsgReceiver : public GUIObject
	{
	public:
		GUIMsgReceiver() : GUIObject() {}

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1616e58); }
		virtual ~GUIMsgReceiver() {}
	};
}