#pragma once
#include "CGView.h"
#include <d3d11.h>

namespace DLCG2
{
	class CGDepthStencilView : public CGView
	{
		ID3D11DepthStencilView* m_pDXDepthStencilView;
	};
}