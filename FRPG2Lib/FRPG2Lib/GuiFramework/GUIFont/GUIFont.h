#pragma once
#include "../GUIObject/GUIObject.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	class GUIFont : public GUIObject
	{
	public:
		GUIFont() {}

		virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617840); }
		virtual ~GUIFont() {}
		virtual void OnDestroy() {}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUIFont), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		DLMT::DL_COLOR_32 m_color;
		dl_float32 m_size[2];
		dl_float32 m_shadowOffset[2];
		dl_bool m_hasShadow;
		dl_bool m_isBold;
		dl_uchar m_horizontalAlign;
		dl_uchar m_verticalAlign;
		dl_int m_fontId;
		dl_int m_height;
		dl_int m_defaultHeight;
	};
}