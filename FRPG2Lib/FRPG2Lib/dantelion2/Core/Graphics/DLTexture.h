#pragma once
#include "Core/Core.h"
#include "DLGPUResource.h"
#include "dantelion2/Core/Graphics/DLDrawContextDefines.h"

namespace DLGR
{
	class DLTextureBase : public DLGPUResource
	{
	protected:
		DLCG2::CGResource* m_pCGTexture;
		DLCG2::CGShaderResourceView* m_pCGShaderResourceView;
		dl_int m_iVar38;
		dl_int m_iVar3C;
		dl_uint m_width;
		dl_uint m_height;
		dl_int m_iVar48;
		dl_bool m_bVar4C;
		dl_pointer m_pVar50;
		dl_pointer m_pVar58;
	};

	class DLTexture2D : public DLTextureBase
	{
		dl_pointer m_pVar60;

	public:
		DLCG2::CGTexture2D* GetTexture() const { return static_cast<DLCG2::CGTexture2D*>(this->m_pCGTexture); }
		DLCG2::CGShaderResourceView* GetShaderResourceView() const { return this->m_pCGShaderResourceView; }
		DLTextureType GetTextureType() const { return DLTEXTYPE_2D; }
		DLTextureFormat GetTextureFormat() const;
	};
}