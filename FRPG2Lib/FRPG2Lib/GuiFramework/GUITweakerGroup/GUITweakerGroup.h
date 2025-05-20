#pragma once
#include "../GUIAutoVLayout/GUIAutoVLayout.h"
#include "../GUITweakerItem/GUITweakerItem.h"

namespace GuiFramework
{
	class GUITweakerGroupItem;

	class GUITweakerGroup : public GUIAutoVLayout
	{
		DLUT::DLVector<GUITweakerGroupItem*> m_pTweakerGroupItems;
		dl_int m_iVar138;
		dl_int m_iVar13C;
		dl_int m_iVar140;
		dl_int m_iVar144;
		dl_int m_iVar148;
		dl_int m_iVar14C;
		dl_int m_iVar150;

	public:
		void AddTweakerAsChild(GUITweakerItem* pTweakerItem);
	};
}