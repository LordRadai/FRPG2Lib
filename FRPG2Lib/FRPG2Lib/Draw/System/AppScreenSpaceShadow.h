#pragma once
#include "GX/GXScreenSpaceShadow.h"

class AppScreenSpaceShadow : public GXScreenSpaceShadow
{
public:
	enum FilterMode
	{
		FLTMODE_PCF4,
		FLTMODE_PCF9
	};

	dl_float32 m_fVar90;
	dl_int m_filterMode;
	dl_int m_iVar98;
};