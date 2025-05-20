#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "../GUIRangeData/GUIRangeDataBase.h"

namespace GuiFramework
{
	class GUIMultiNumericEditor : public GUIWidget
	{
		dl_int16 m_sVar110;
		dl_uchar m_numValues;
		dl_uchar m_bVar113;
		dl_pointer m_pEditors;

	public:
		void UpdateValue(dl_uint idx);
		GUIRangeDataBase* GetRangeData(dl_uint idx);
		void SetRangeData(dl_uint idx, GUIRangeDataBase* pRangeData);
	};
}