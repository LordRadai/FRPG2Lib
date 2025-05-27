#pragma once
#include "GUITextureBase.h"
#include "Draw/System/GX/GXRenderToTexture.h"

namespace GuiFramework
{
	class GUITexture : public GUITextureBase
	{
	public:
		GUITexture(DLGR::DLTexture2D* pTexture);

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUITexture), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		virtual ~GUITexture() {}

		virtual uint32_t getTextureWidth();
		virtual uint32_t getTextureHeight();
		virtual DLGR::DLTextureType getTextureType();
		virtual DLGR::DLTextureFormat getTextureFormat();
		virtual uint32_t getMipNum();
		virtual bool draw(uint32_t mode, AppGUIRender* pAppGUIRender);
		virtual DLGR::DLTexture2D* getTexture() { return static_cast<DLGR::DLTexture2D*>(this->m_pDLTexture); }
		virtual DLCG2::CGShaderResourceView* getShaderResourceView();
	private:
		dl_bool m_bVar20 = false;
		dl_bool m_bInit = false;

		// TODO: Finish implementing this
		void Initialize();
	};
}