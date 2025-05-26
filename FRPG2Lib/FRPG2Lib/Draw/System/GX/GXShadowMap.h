#pragma once
#include "dantelion2/dantelion2.h"
#include "../Texture.h"

class GXShadowMap
{
	void** _vfptr;

public:
	struct ShadowParameters
	{
		dl_int m_filterMode;
		dl_uchar m_shadowLightID;
		dl_float32 m_fadeStartDistance;
		dl_float32 m_fadeRange;
		dl_float32 m_depthOffset;
		dl_float32 m_depthOffsetPSM;
		dl_float32 m_clipAutomaticAdjustmentRatePSM;
		dl_float32 m_pulseAdjustmentPSM;
		dl_float32 m_volumeDepth;
		dl_float32 m_depthComparisonSmoothing;
		dl_float32 m_shadowMapGenerationDepthBias;
		dl_bool m_bShadowModelCullFlip;
		dl_bool m_bAlignTexel;
		DLMT::DL_COLOR_32 m_color;
	};

	ShadowParameters m_parameters;
	alignas(16) DLMT::DL_MATRIX44 m_mVar40;
	alignas(16) DLMT::DL_MATRIX44 m_mVar80;
	dl_float32 m_fVarC0;
	dl_float32 m_fVarC4;
	dl_int m_iVarC8;
	dl_int m_iVarCC;
	dl_float32 m_iVarD0;
	dl_int m_iVarD4;
	dl_float32 m_fVarD8;
	Texture2D m_depthTexture;
	dl_int m_iVar100;
	dl_int m_iVar104;
	dl_int m_iVar108;
	Texture2D m_texture1;
	dl_int16 m_sVar130;
	dl_bool m_bVar132;
};