#pragma once
#include "DLVector.h"
#include "dantelion2/Core/Platform/Platform.h"

namespace DLMT
{
	typedef DirectX::XMFLOAT3X3 DL_MATRIX33;
	typedef DirectX::XMFLOAT3X4 DL_MATRIX34;
	typedef Matrix DL_MATRIX44;

	static DL_MATRIX44 GetRotationFrom2Vectors(const DL_VECTOR3& v1, const DL_VECTOR3& v2)
	{
		DL_MATRIX44 result = DL_MATRIX44::Identity;

		DL_VECTOR3 euler = DL_VECTOR3::Zero;
		DL_VECTOR3 diff = v2 - v1;

		if (diff.x == 0 && diff.z == 0)
		{
			if (diff.y >= 0)
				result = DL_MATRIX44::CreateRotationZ(DirectX::XM_PI);
			else
				result = DL_MATRIX44::CreateRotationZ(0);

			return result;
		}

		dl_float32 distance = diff.Length();

		euler.y = asin(diff.y / distance);

		dl_float32 distance_xz = distance * cos(euler.y);

		euler.x = acos(diff.x / distance_xz);
		euler.z = acos(diff.z / distance_xz);

		DL_MATRIX44 rot_x = DL_MATRIX44::CreateRotationX(-euler.x);
		DL_MATRIX44 rot_y = DL_MATRIX44::CreateRotationY(-euler.y);
		DL_MATRIX44 rot_z = DL_MATRIX44::CreateRotationZ(-euler.z);

		result = rot_x * result;
		result = rot_y * result;
		result = rot_z * result;

		return result;
	}
}