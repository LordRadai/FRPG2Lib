#include "GUIObject.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oFree)(GUIObject* pThis);
	typedef void(_fastcall* oDestroyGUIObject)(GUIObject* pThis);
	typedef void(_fastcall* oResetFlags)(GUIObject* pThis);

	void GUIObject::free()
	{
		FRPG2_CALL(oFree, 0x527840, this);
	}

	void GUIObject::Destroy()
	{
		FRPG2_CALL(oDestroyGUIObject, 0x30b560, this);
	}

	void GUIObject::ResetFlags()
	{
		FRPG2_CALL(oResetFlags, 0x30b460, this);
	}
}