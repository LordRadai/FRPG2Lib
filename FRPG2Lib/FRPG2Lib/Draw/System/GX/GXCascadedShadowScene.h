#pragma once
#include "GXDrawItem.h"
#include "GXShadowMap.h"
#include "GXTestVolume.h"

class GXCascadedShadowScene : public GXDrawItem
{
public:
	struct CascadeShadow
	{
		GXShadowMap* m_pShadowMap;
		GXShadowMap::ShadowParameters m_internalParam;
		alignas(16) DLMT::DL_MATRIX44 m_mVar40;
		alignas(16) DLMT::DL_MATRIX44 m_mVar80;
		dl_float32 m_fVarC0;
		dl_float32 m_fVarC4;
		dl_float32 m_fVarC8;
		dl_float32 m_fVarCC;
		dl_float32 m_iVarD0;
	};

	DLKR::DLAllocator* m_pAllocator;
	GXShadowMap m_shadowMap;
	GXLightViewVolume m_lightViewVolumes[4];
	GXShadowMap::ShadowParameters m_cascadeShadowParameters[4];
	CascadeShadow m_cascadeShadows[4];
	dl_float32 m_fVar9A0;
	dl_float32 m_fVar9A4;
	dl_float32 m_fVar9A8;
	dl_float32 m_fVar9AC;
	dl_float32 m_near;
	dl_float32 m_farFadeStart;
	dl_float32 m_farFadeDist;
	dl_float32 m_cascadeTransitionDist0To1;
	dl_float32 m_cascadeTransitionDist1To2;
	dl_float32 m_cascadeTransitionDist2To3;
	dl_float32 m_fVar9C8;
	dl_float32 m_fVar9CC;
	dl_char m_pad[320];
	dl_int m_iVarB10;
	dl_int m_iVarB14;
	dl_int m_iVarB18;
	dl_bool m_bFrameSkip;
	dl_bool m_bCascadeShadowFrame[4][4];
};