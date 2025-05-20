#include "GUITextEditorUtil.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oDeleteCharacter)(GUITextEditorUtil* pThis);
	typedef void(_fastcall* oInsertCharacters)(GUITextEditorUtil* pThis, const dl_wchar* chars, dl_uint num);

	void GUITextEditorUtil::DeleteLastCharacter()
	{
		FRPG2_CALL(oDeleteCharacter, 0x58b7c0, this);
	}

	void GUITextEditorUtil::InsertCharacters(const dl_wchar* chars, dl_uint num)
	{
		FRPG2_CALL(oInsertCharacters, 0x58c650, this, chars, num);
	}
}