#pragma once
#include "FRPG2Globals.h"
#include "Draw/AppGUIRender.h"
#include "dantelion2/dantelion2.h"
#include "GuiFramework/Util/GUIText.h"
#include "GuiFramework/Util/TGUIRect.inl"
#include "Memory/Memory.h"

namespace GuiFramework
{
	class GUIObject
	{
	protected:
		dl_uint m_interactionFlags = 0x40000000;

	public:
		GUIObject() {}

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)((UINT64)(g_moduleAddr)+0x1616de8); }
		virtual ~GUIObject() {}
		virtual void onDestroy() {}
		virtual void free();

		void Destroy();
		void ResetFlags();
	};
}