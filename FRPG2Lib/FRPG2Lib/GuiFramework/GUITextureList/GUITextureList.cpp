#include "GUITextureList.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef dl_int(_fastcall* oAddTexture)(GUITextureList* pThis, GUIText* name, GUITexture* texture, GUIText* path);

	dl_int GUITextureList::AddTexture(const dl_wchar* name, GUITexture* pTexture, const dl_wchar* path)
	{
		GUIText textName(name);
		GUIText textLabel(path);

		dl_int ret = FRPG2_CALL(oAddTexture, 0x5ab370, this, &textName, pTexture, &textLabel);

		textName.Free();
		textLabel.Free();

		return ret;
	}
}