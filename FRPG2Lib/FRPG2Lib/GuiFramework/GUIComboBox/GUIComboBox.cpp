#include "GUIComboBox.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oSetComboBoxSelectedItem)(GUIComboBox* pComboBox, int idx);

	void GUIComboBox::SetDisplayItem(dl_int idx)
	{
		FRPG2_CALL(oSetComboBoxSelectedItem, 0x59e0f0, this, idx);
	}
}