#pragma once
#include "../GUIEditBox/GUIEditBox.h"
#include "../GUIRangeData/GUIRangeDataBase.h"

namespace GuiFramework
{
	class GUINumericEditBox : public GUIEditBox
	{
		dl_int m_iVar140;
		dl_int m_iVar144;
		GUIRangeDataBase* m_pRangeData;
		dl_uint m_flags;
	};
}