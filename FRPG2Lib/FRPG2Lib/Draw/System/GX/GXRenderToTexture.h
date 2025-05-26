#pragma once
#include "../../Texture.h"
#include "GXDrawItem.h"

class GXRenderToTexture : public GXDrawItem
{
public:
	DLKR::DLAllocator* m_pAllocator;
	dl_bool m_bInit;
	Texture2D m_texture0;
	DLGR::DLSurface* m_pSurface0;
	Texture2D m_texture1;
	DLGR::DLSurface* m_pSurface1;
	Texture2D m_texture2;
	dl_int m_iVar88;
	dl_int m_width;
	dl_int m_height;
	dl_int m_iVar94;

	dl_int GetWidth() const { return this->m_width; }
	dl_int GetHeight() const { return this->m_height; }
	Texture2D GetTexture0() const { return this->m_texture0; }
	Texture2D GetTexture1() const { return this->m_texture1; }
	Texture2D GetTexture2() const { return this->m_texture2; }
};