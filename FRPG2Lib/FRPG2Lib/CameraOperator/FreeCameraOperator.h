#pragma once
#include "PerspectiveCameraOperator.h"

class FreeCameraOperator : public PerspectiveCameraOperator
{
	alignas(16) DLMT::DL_MATRIX44 m_transform;
	alignas(16) DLMT::DL_VECTOR4 m_targetPosition;
	dl_float32 m_distanceFromTarget;
	dl_float32 m_angleY;
	dl_float32 m_angleX;
	dl_float32 m_angleZ;
	dl_bool m_bAllowTargetDistanceAdjustments;
	dl_bool bVar2D;
	dl_bool m_bAllowTargetMovement;
	dl_bool bVar2F;
	dl_bool m_bAllowZoom;
	dl_float32 fVar34;
	dl_float32 fVar38;
	dl_float32 fVar3C;
	dl_float32 fVar40;
	dl_float32 m_movementSpeed;
	dl_float32 m_turnRate;
	dl_float32 fVar4C;
	dl_float32 m_zoomSpeed;
	dl_int16 sVar54;
	dl_bool bVar56;

public:
	void SetAngle(dl_float32 angleX, dl_float32 angleY, dl_float32 angleZ)
	{
		this->m_angleX = angleX;
		this->m_angleY = angleY;
		this->m_angleZ = angleZ;
	}

	void SetTarget(Vector3 target)
	{
		this->m_targetPosition = Vector4(target.x, target.y, target.z, 0.f);
	}
};