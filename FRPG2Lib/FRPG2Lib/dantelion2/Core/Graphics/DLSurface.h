#pragma once
#include "DLGPUResource.h"
#include "dantelion2/dantelion2.h"

namespace DLGR
{
	class DLSurface : public DLGPUResource
	{
		DLCG2::CGTexture2D* m_pCGTexture;
		DLCG2::CGRenderTargetView* m_pCGRenderTargetView;
		DLCG2::CGDepthStencilView* m_pCGDepthStencilView;
		DLGR::DLTexture2D* m_pDLTexture;
		dl_int m_iVar48;
		dl_int m_iVar4C;
		dl_int m_width;
		dl_int m_height;
		dl_int m_iVar58;
		dl_int m_iVar5C;
		dl_int m_iVar60;
		dl_int m_iVar64;
		dl_int m_iVar68;
		dl_int m_iVar6C;
		dl_int m_iVar70;
		dl_int m_iVar74;
		dl_int m_iVar78;
		dl_int m_iVar7C;
		dl_int m_iVar80;
		dl_int m_iVar84;
		dl_int m_iVar88;
		dl_int m_iVar8C;
		dl_int m_iVar90;
		dl_bool m_iVar94;
		dl_int m_surfaceType;
	};
}