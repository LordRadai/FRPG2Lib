#pragma once
#include "CGView.h"
#include <d3d11.h>

namespace DLCG2
{
	class CGRenderTargetView : public CGView
	{
		ID3D11RenderTargetView* m_pDXRenderTargetView;
	};
}