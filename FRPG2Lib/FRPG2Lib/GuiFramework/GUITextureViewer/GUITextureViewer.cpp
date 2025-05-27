#include "GUITextureViewer.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oSetTexture)(GUITextureViewer* pThis, GUITexture* pTexture);

	void GUITextureViewer::SetTexture(GUITexture* pTexture)
	{
		FRPG2_CALL(oSetTexture, 0x5a7920, this, pTexture);
	}
}