#pragma once
#include "../GUIMsgReceiver/GUIMsgReceiver.h"

namespace GuiFramework
{
	class GUICallbackObjectBase : public GUIMsgReceiver
	{
	public:
		GUICallbackObjectBase() : GUIMsgReceiver() {}

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1616f00); }
		virtual ~GUICallbackObjectBase() {}
		virtual void invoke() {};

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUICallbackObjectBase), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}
	};
}