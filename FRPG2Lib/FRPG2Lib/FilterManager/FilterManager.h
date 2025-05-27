#pragma once
#include "AppSystemMessageListener/AppSystemMessageListener.h"
#include "Draw/Texture.h"

class FilterManager : public AppSystemMessageListener
{
public:
	DLKR::DLAllocator* m_pAllocator;
	DLUT::DLVector<dl_pointer> m_vVar10;
	DLGR::DLVertexDeclaration* m_pVertexDeclaration;
	DLGR::DLPixelShader* m_pPixelShaders[12];
	DLGR::DLVertexShader* m_pVertexShaders[2];
	Texture2D m_textures0[16];
	Texture2D m_textures1[2];
	Texture2D m_texture2;
	Texture2D m_texture3;
	Texture2D m_texture4;
	dl_pointer m_pShaderList;
	dl_int m_numShaders;
	DLKR::DLAllocator* m_pAllocator2;
	dl_pointer m_pTextureList;
	dl_int m_numTextures;
	DLKR::DLAllocator* m_pAllocator3;
	dl_pointer m_pVar378;
	dl_pointer m_pVar380;
	dl_pointer m_pVar388;
	DLKR::DLAllocator* m_pAllocator4;
	DLKR::DLAllocator* m_pAllocator5;
	dl_pointer m_pVar3A0;
	dl_pointer m_pVar3A8;
	dl_pointer m_pVar3B0;
	DLKR::DLAllocator* m_pAllocator6;
	dl_int m_iVar3C0;
};