#pragma once
#include "CGResource.h"
#include <d3d11.h>

namespace DLCG2
{
	class CGTexture1D : public CGResource
	{
		ID3D11Texture1D* m_pDXTexture1D;
		ID3D11ShaderResourceView* m_pShaderResourceView;

	public:
		ID3D11Texture1D* GetDXTexture() const { return this->m_pDXTexture1D; }
		dl_uint GetFormat();
		dl_uint GetWidth();
		dl_uint GetMipsLevel();
	};

	class CGTexture2D : public CGResource
	{
		ID3D11Texture2D* m_pDXTexture2D;
		ID3D11ShaderResourceView* m_pShaderResourceView;

	public:
		ID3D11Texture2D* GetDXTexture() const { return this->m_pDXTexture2D; }
		DXGI_FORMAT GetFormat();
		dl_uint GetWidth();
		dl_uint GetHeight();
		dl_uint GetMipLevel();
	};

	class CGTexture3D : public CGResource
	{
		ID3D11Texture3D* m_pDXTexture3D;
		ID3D11ShaderResourceView* m_pShaderResourceView;

	public:
		ID3D11Texture3D* GetDXTexture() const { return this->m_pDXTexture3D; }
		dl_uint GetFormat();
		dl_uint GetWidth();
		dl_uint GetHeight();
		dl_uint GetMipsLevel();
	};
}