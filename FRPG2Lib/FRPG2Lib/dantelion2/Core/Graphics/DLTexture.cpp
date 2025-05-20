#include "DLTexture.h"
#include "FRPG2Call.h"

typedef DLGR::DLTextureFormat(_fastcall* oGetDLTextureFormat)(DXGI_FORMAT dxFormat);

namespace DLGR
{
	DLTextureFormat DLTexture2D::GetTextureFormat() const
	{
		DLCG2::CGTexture2D* pTexture = this->GetTexture();

		if (pTexture == nullptr)
			return DLTEXFMT_NUM;

		return FRPG2_CALL(oGetDLTextureFormat, 0xf28b90, pTexture->GetFormat());
	}
}