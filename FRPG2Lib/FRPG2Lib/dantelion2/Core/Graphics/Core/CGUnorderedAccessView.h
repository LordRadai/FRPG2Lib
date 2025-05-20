#pragma once
#include "CGView.h"
#include <d3d11.h>

namespace DLCG2
{
	class CGUnorderedAccessView : public CGView
	{
		ID3D11UnorderedAccessView* m_pDXUnorderedAccessView;
	};
}