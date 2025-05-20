#pragma once
#include "GXDrawItem.h"
#include "dantelion2/dantelion2.h"
#include "../Texture.h"

class GXScreenSpaceShadow : public GXDrawItem
{
public:
	dl_int m_iVar8;
	dl_int m_iVarC;
	dl_float32 m_fVar10;
	dl_float32 m_fVar14;
	dl_float32 m_fVar18;
	dl_float32 m_fVar1C;
	dl_float32 m_fVar20;
	dl_float32 m_fVar24;
	dl_float32 m_fVar28;
	dl_float32 m_fVar2C;
	dl_bool m_bVar30;
	Texture2D m_shadowBuffer;
	dl_bool m_bUseDepthOptimize;
	dl_bool m_bUseStencilOptimize;
	dl_uint m_width;
	dl_uint m_height;
	dl_bool m_iVar64;
	dl_bool m_iVar65;
	dl_int m_iVar68;
	dl_int m_iVar6C;
	Texture2D m_shadowTexture1;
};