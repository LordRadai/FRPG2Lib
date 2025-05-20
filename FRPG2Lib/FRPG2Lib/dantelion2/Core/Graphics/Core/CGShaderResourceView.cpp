#include "CGShaderResourceView.h"

namespace DLCG2
{
	dl_uint CGShaderResourceView::GetShaderFormat()
	{
		if (this->m_pDXShaderResourceView == nullptr)
			return 0;

		D3D11_SHADER_RESOURCE_VIEW_DESC desc;
		this->m_pDXShaderResourceView->GetDesc(&desc);

		return desc.Format;
	}
}