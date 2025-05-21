#pragma once
#include "../GUIObject/GUIObject.h"
#include "dantelion2/dantelion2.h"

namespace GuiFramework
{
	class GUITextureBase : public GUIObject
	{
	public:
		GUITextureBase() : GUIObject() {}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUITextureBase), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)((UINT64)(g_moduleAddr)+0x1616d78); }
		virtual ~GUITextureBase() {}
		virtual uint32_t getTextureWidth() { return 0; }
		virtual uint32_t getTextureHeight() { return 0; }
		virtual void vfunction6() {}
		virtual DLGR::DLTextureType getTextureType() { return DLGR::DLTEXTYPE_UNKNOWN; }
		virtual DLGR::DLTextureFormat getTextureFormat() { return DLGR::DLTEXFMT_NUM; }
		virtual uint32_t getMipNum() { return 0; }
		virtual bool draw(uint32_t mode, AppGUIRender* pAppGUIRender) { return true; }
		virtual void vfunction11() {}
		virtual DLGR::DLTextureBase* getTexture() { return this->m_pDLTexture; }
		virtual DLCG2::CGShaderResourceView* getShaderResourceView() { return this->m_pShaderResourceView; }

	protected:
		DLGR::DLTextureBase* m_pDLTexture = nullptr;
		DLCG2::CGShaderResourceView* m_pShaderResourceView = nullptr;
	};
}