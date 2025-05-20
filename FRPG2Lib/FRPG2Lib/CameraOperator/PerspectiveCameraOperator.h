#pragma once
#include "CameraOperator.h"

class PerspectiveCameraOperator : public CameraOperator
{
	dl_float32 m_fov;
	dl_float32 m_aspectRatio;
	dl_float32 m_nearZ;
	dl_float32 m_farZ;
	dl_float32 fVar16;
};