#include "GUITexture.h"
#include "Draw/AppGUIRender.h"

namespace GuiFramework
{
	GUITexture::GUITexture(DLGR::DLTexture2D* pTexture)
	{
		this->m_pDLTexture = pTexture;

		if (pTexture)
		{
			pTexture->Ref();
			this->Initialize();
		}
	}

	GUITexture::GUITexture(GXRenderToTexture* pRenderToTexture, uint32_t index)
	{
		DLGR::DLTexture2D* pTexture = nullptr;

		switch (index)
		{
		case 0:
			pTexture = pRenderToTexture->GetTexture0().GetTexture();
			break;
		case 1:
			pTexture = pRenderToTexture->GetTexture1().GetTexture();
			break;
		case 2:
			pTexture = pRenderToTexture->GetTexture2().GetTexture();
			break;
		}

		this->m_pDLTexture = pTexture;

		if (pTexture)
		{
			this->m_pDLTexture->Ref();
			this->Initialize();
		}
	}

	uint32_t GUITexture::getTextureWidth()
	{
		if (this->getTextureFormat() == 0)
			return 0;

		DLGR::DLTexture2D* pTexture = this->getTexture();

		if (pTexture == nullptr)
			return 0;

		DLCG2::CGTexture2D* pCGTexture = pTexture->GetTexture();

		if (pCGTexture == nullptr)
			return 0;

		return pCGTexture->GetWidth();
	}

	uint32_t GUITexture::getTextureHeight()
	{
		if (this->getTextureFormat() == 0)
			return 0;

		DLGR::DLTexture2D* pTexture = this->getTexture();

		if (pTexture == nullptr)
			return 0;

		DLCG2::CGTexture2D* pCGTexture = pTexture->GetTexture();

		if (pCGTexture == nullptr)
			return 0;

		return pCGTexture->GetHeight();
	}

	DLGR::DLTextureType GUITexture::getTextureType()
	{
		DLGR::DLTexture2D* pTexture = this->getTexture();

		if (pTexture == nullptr)
			return DLGR::DLTEXTYPE_UNKNOWN;

		return pTexture->GetTextureType();
	}

	DLGR::DLTextureFormat GUITexture::getTextureFormat()
	{
		DLGR::DLTexture2D* pTexture = this->getTexture();

		if (pTexture == nullptr)
			return DLGR::DLTEXFMT_NUM;

		return pTexture->GetTextureFormat();
	}

	uint32_t GUITexture::getMipNum()
	{
		DLGR::DLTexture2D* pTexture = this->getTexture();

		if (pTexture == nullptr)
			return 0;

		DLCG2::CGTexture2D* pCGTexture = pTexture->GetTexture();

		if (pCGTexture == nullptr)
			return 0;

		return pCGTexture->GetMipLevel();
	}

	bool GUITexture::draw(uint32_t mode, AppGUIRender* pAppGUIRender)
	{
		pAppGUIRender->DrawTexture2D(mode, this->getTexture());

		return true;
	}

	DLCG2::CGShaderResourceView* GUITexture::getShaderResourceView()
	{
		DLGR::DLTexture2D* pTexture = this->getTexture();

		if (pTexture == nullptr)
			return nullptr;

		if (this->m_pShaderResourceView != nullptr)
			return this->m_pShaderResourceView;

		return pTexture->GetShaderResourceView();
	}

	void GUITexture::Initialize()
	{
		if (!this->m_bInit)
		{
			this->m_bInit = true;

			/*
			DLCG2::CGShaderResourceView* pShaderResourceView = this->getTexture()->GetShaderResourceView();

			D3D11_SHADER_RESOURCE_VIEW_DESC desc;
			pShaderResourceView->GetDXShaderResourceView()->GetDesc(&desc);
			*/
		}
	}
}