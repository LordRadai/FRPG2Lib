#pragma once
#include "CGView.h"
#include <d3d11.h>

namespace DLCG2
{
	class CGShaderResourceView : public CGView
	{
		ID3D11ShaderResourceView* m_pDXShaderResourceView;

	public:
		ID3D11ShaderResourceView* GetDXShaderResourceView() const { return this->m_pDXShaderResourceView; }
		dl_uint GetShaderFormat();
	};
}