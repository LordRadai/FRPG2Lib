#include "AppGUIRender.h"
#include "FRPG2Call.h"

typedef UINT64(_fastcall* oDrawTexture2DEx)(AppGUIRender* pAppGUIRender, dl_uint param_1, DLGR::DLTexture2D* pTexture2D);

void AppGUIRender::DrawTexture2D(dl_uint param_1, DLGR::DLTexture2D* pTexture2D)
{
	FRPG2_VCALL(this, 30, oDrawTexture2DEx, this, param_1, pTexture2D);
}