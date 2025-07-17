#pragma once
#include "../GUITweakerItem/GUITweakerItem.h"

namespace GuiFramework
{
	class GUITweakerBase : public GUITweakerItem
	{
	public:
		enum GuiStyleFlags
		{
			GuiStyleFlags_TransparentBg = 1 << 0,
			GuiStyleFlags_Invisible = 1 << 1,
			GuiStyleFlags_Flag2 = 1 << 2,
			GuiStyleFlags_Flag3 = 1 << 3,
			GuiStyleFlags_Flag4 = 1 << 4,
			GuiStyleFlags_Flag5 = 1 << 5,
			GuiStyleFlags_Flag6 = 1 << 6,
			GuiStyleFlags_Flag7 = 1 << 7,
			GuiStyleFlags_Titlebar = 1 << 8,
			GuiStyleFlags_TitlebarFrame = 1 << 9,
			GuiStyleFlags_3DFrame = 1 << 10,
			GuiStyleFlags_ConvexFrame = 1 << 11,
			GuiStyleFlags_VScrollbar = 1 << 12,
			GuiStyleFlags_HScrollbar = 1 << 13,
			GuiStyleFlags_Flag14 = 1 << 14,
			GuiStyleFlags_Flag15 = 1 << 15,
			GuiStyleFlags_Collapse = 1 << 16,
			GuiStyleFlags_Flag17 = 1 << 17,
			GuiStyleFlags_Destroy = 1 << 18,
			GuiStyleFlags_Flag19 = 1 << 19,
			GuiStyleFlags_Flag20 = 1 << 20,
			GuiStyleFlags_Flag21 = 1 << 21,
			GuiStyleFlags_NoInteract = 1 << 22,
			GuiStyleFlags_Flag23 = 1 << 23,
			GuiStyleFlags_Flag24 = 1 << 24,
			GuiStyleFlags_Flag25 = 1 << 25,
			GuiStyleFlags_Flag26 = 1 << 26,
			GuiStyleFlags_Flag27 = 1 << 27,
			GuiStyleFlags_Flag28 = 1 << 28,
			GuiStyleFlags_Flag29 = 1 << 29,
			GuiStyleFlags_Group = 1 << 30,
			GuiStyleFlags_Flag31 = 1 << 31
		};

		GUITweakerBase() : GUITweakerItem() {}

		virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617198); }
		virtual ~GUITweakerBase() {}
		virtual void OnDestroy() {}
		virtual void unregister() {}

		dl_uint styleFlags = 0;
		dl_int iVar14 = 0;
		dl_int iVar18 = 0;
		dl_int iVar1C = 0;
	};
}