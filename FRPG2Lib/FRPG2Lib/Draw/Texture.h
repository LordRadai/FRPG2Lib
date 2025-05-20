#pragma once
#include "dantelion2/dantelion2.h"

class TextureBase
{
protected:
	void** _vfptr;
	dl_float32 m_fVar8;
	dl_bool m_bVar1c;
};

class Texture2D : public TextureBase
{
	DLGR::DLTexture2D* m_pDLTexture;
	dl_float32 m_fVar18;

public:
	DLGR::DLTexture2D* GetTexture() const { return this->m_pDLTexture; }
};

class TextureVolume : public TextureBase
{
	dl_pointer m_pVar10;
	dl_float32 m_fVar14;
};