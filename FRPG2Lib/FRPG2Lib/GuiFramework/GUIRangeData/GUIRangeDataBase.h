#pragma once
#include "../GUIObject/GUIObject.h"

namespace GuiFramework
{
	class GUIRangeDataBase : public GUIObject
	{
	public:
		GUIRangeDataBase() : GUIObject() {}

		virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617128); }
		virtual ~GUIRangeDataBase() {}
	};
}