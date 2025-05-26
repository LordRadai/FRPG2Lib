#pragma once
#include "GXFilterBase.h"

class GXDepthScaleFilter : public GXFilterBase
{
public:
	GXRenderToTexture m_depthScale22;
	GXRenderToTexture m_depthScale44;
	dl_bool m_bInitialised;
};