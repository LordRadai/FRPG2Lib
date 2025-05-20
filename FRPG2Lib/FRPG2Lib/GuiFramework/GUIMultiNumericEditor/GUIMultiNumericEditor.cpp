#include "GUIMultiNumericEditor.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oUpdateValue)(GUIMultiNumericEditor* pThis, dl_uint idx);
	typedef GUIRangeDataBase*(_fastcall* oGetRangeData)(GUIMultiNumericEditor* pThis, dl_uint idx);
	typedef void(_fastcall* oAddGUIRangeData)(GUIMultiNumericEditor* pThis, dl_uint idx, GUIRangeDataBase* pGUIRangeData);

	void GUIMultiNumericEditor::UpdateValue(dl_uint idx)
	{
		FRPG2_CALL(oUpdateValue, 0x5b4bb0, this, idx);
	}

	GUIRangeDataBase* GUIMultiNumericEditor::GetRangeData(dl_uint idx)
	{
		return FRPG2_CALL(oGetRangeData, 0x5b4c70, this, idx);
	}

	void GUIMultiNumericEditor::SetRangeData(dl_uint idx, GUIRangeDataBase* pRangeData)
	{
		FRPG2_CALL(oAddGUIRangeData, 0x5b4c10, this, idx, pRangeData);
	}
}