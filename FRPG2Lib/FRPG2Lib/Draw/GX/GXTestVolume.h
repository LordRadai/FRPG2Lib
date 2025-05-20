#pragma once
#include "dantelion2/dantelion2.h"

class GXTestVolume
{
protected:
	void** _vfptr;
};

class GXLightViewVolume : public GXTestVolume
{
public:
	dl_int m_iVar8;
	dl_char m_unkData[192];
	alignas(16) DLMT::DL_VECTOR4 m_bbMax;
	alignas(16) DLMT::DL_VECTOR4 m_bbMin;
	dl_float32 m_fVarF0;
};