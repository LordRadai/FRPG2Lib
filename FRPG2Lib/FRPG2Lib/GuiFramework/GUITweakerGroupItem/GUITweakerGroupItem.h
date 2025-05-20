#pragma once
#include "../GUITweakerItem/GUITweakerItem.h"
#include "../GUITweakerGroup/GUITweakerGroup.h"

namespace GuiFramework
{
	class GUITweakerGroupItem : public GUITweakerItem
	{
		GUITweakerGroup* m_pTweakerGroup;
	};
}