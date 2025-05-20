#include "CGTexture.h"

namespace DLCG2
{
	dl_uint CGTexture1D::GetFormat()
	{
		if (this->m_pDXTexture1D == nullptr)
			return 0;

		D3D11_TEXTURE1D_DESC desc;
		this->m_pDXTexture1D->GetDesc(&desc);

		return desc.Format;
	}

	dl_uint CGTexture1D::GetWidth()
	{
		if (this->m_pDXTexture1D == nullptr)
			return 0;

		D3D11_TEXTURE1D_DESC desc;
		this->m_pDXTexture1D->GetDesc(&desc);

		return desc.Width;
	}

	dl_uint CGTexture1D::GetMipsLevel()
	{
		if (this->m_pDXTexture1D == nullptr)
			return 0;

		D3D11_TEXTURE1D_DESC desc;
		this->m_pDXTexture1D->GetDesc(&desc);

		return desc.MipLevels;
	}

	DXGI_FORMAT CGTexture2D::GetFormat()
	{
		if (this->m_pDXTexture2D == nullptr)
			return DXGI_FORMAT_UNKNOWN;

		D3D11_TEXTURE2D_DESC desc;
		this->m_pDXTexture2D->GetDesc(&desc);

		return desc.Format;
	}

	dl_uint CGTexture2D::GetWidth()
	{
		if (this->m_pDXTexture2D == nullptr)
			return 0;

		D3D11_TEXTURE2D_DESC desc;
		this->m_pDXTexture2D->GetDesc(&desc);

		return desc.Width;
	}

	dl_uint CGTexture2D::GetHeight()
	{
		if (this->m_pDXTexture2D == nullptr)
			return 0;

		D3D11_TEXTURE2D_DESC desc;
		this->m_pDXTexture2D->GetDesc(&desc);

		return desc.Height;
	}

	dl_uint CGTexture2D::GetMipLevel()
	{
		if (this->m_pDXTexture2D == nullptr)
			return 0;

		D3D11_TEXTURE2D_DESC desc;
		this->m_pDXTexture2D->GetDesc(&desc);

		return desc.MipLevels;
	}

	dl_uint CGTexture3D::GetFormat()
	{
		if (this->m_pDXTexture3D == nullptr)
			return 0;

		D3D11_TEXTURE3D_DESC desc;
		this->m_pDXTexture3D->GetDesc(&desc);

		return desc.Format;
	}

	dl_uint CGTexture3D::GetWidth()
	{
		if (this->m_pDXTexture3D == nullptr)
			return 0;

		D3D11_TEXTURE3D_DESC desc;
		this->m_pDXTexture3D->GetDesc(&desc);

		return desc.Width;
	}

	dl_uint CGTexture3D::GetHeight()
	{
		if (this->m_pDXTexture3D == nullptr)
			return 0;

		D3D11_TEXTURE3D_DESC desc;
		this->m_pDXTexture3D->GetDesc(&desc);

		return desc.Width;
	}

	dl_uint CGTexture3D::GetMipsLevel()
	{
		if (this->m_pDXTexture3D == nullptr)
			return 0;

		D3D11_TEXTURE3D_DESC desc;
		this->m_pDXTexture3D->GetDesc(&desc);

		return desc.MipLevels;
	}
}