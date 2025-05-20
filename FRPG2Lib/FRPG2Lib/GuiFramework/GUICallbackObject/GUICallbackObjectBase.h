#pragma once
#include "../GUIMsgReceiver/GUIMsgReceiver.h"

namespace GuiFramework
{
	class GUICallbackObjectBase : public GUIMsgReceiver
	{
	public:
		GUICallbackObjectBase() : GUIMsgReceiver() {}

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)((UINT64)(g_moduleAddr)+0x1616f00); }
		virtual ~GUICallbackObjectBase() {}
		virtual void invoke() {};

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUICallbackObjectBase), 8, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetHeap(HEAPTYPE_GUIDEFAULT));
		}
	};
}