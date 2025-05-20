#pragma once
#include "dantelion2/dantelion2.h"

class CameraOperator
{
	void** _vfptr;
	dl_float32 iVar0;
	dl_float32 iVar4;
	alignas(16) DLMT::DL_MATRIX44 m_transform;
	alignas(16) DLMT::DL_MATRIX44 m_transform2;
};