#pragma once
#include "DLVector.h"
#include "dantelion2/Core/Platform/Platform.h"

namespace DLMT
{
	typedef dl_uint DL_COLOR_32;

	static DL_COLOR_32 GetDLColor32(DLMT::DL_VECTOR4& pColor)
	{
		return (DL_COLOR_32)((dl_uchar)(pColor.x * 255.0f) << 24) |
			(DL_COLOR_32)((dl_uchar)(pColor.y * 255.0f) << 16) |
			(DL_COLOR_32)((dl_uchar)(pColor.z * 255.0f) << 8) |
			(DL_COLOR_32)((dl_uchar)(pColor.w * 255.0f));
	}
}

namespace DLMT2
{
	struct DL_COLOR_U8
	{
		dl_uchar A;
		dl_uchar B;
		dl_uchar G;
		dl_uchar R;
	};
}