#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "../GUIRangeData/GUIRangeDataBase.h"
#include "../GUITextEditorUtil/GUITextEditorUtil.h"
#include "../GUINumericEditBox/GUINumericEditBox.h"

namespace GuiFramework
{
	class GUIRangeTweakWidget : public GUIWidget
	{
		GUITextEditorUtil* m_pTextEditorUtil;
		GUINumericEditBox* m_pNumericEditBox;
		GUIRangeDataBase* m_pRangeData;
		dl_int16 m_sVar128;

	public:
		void UpdateDisplayValue();
	};
}