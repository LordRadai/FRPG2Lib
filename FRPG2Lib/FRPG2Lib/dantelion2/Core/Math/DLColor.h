#pragma once
#include "DLVector.h"
#include "dantelion2/Core/Platform/Platform.h"

namespace DLMT
{
	typedef dl_uint DL_COLOR_32;

	static DL_COLOR_32 GetDLColor32(const DLMT::DL_VECTOR4& pColor)
	{
		auto Clamp255 = [](float c) -> dl_uchar {
			return (dl_uchar)(std::max(0.0f, std::min(c, 1.0f)) * 255.0f);
			};

		dl_uchar r = Clamp255(pColor.x);
		dl_uchar g = Clamp255(pColor.y);
		dl_uchar b = Clamp255(pColor.z);
		dl_uchar a = Clamp255(pColor.w);

		return ((DL_COLOR_32)a << 24) |
			((DL_COLOR_32)r << 16) |
			((DL_COLOR_32)g << 8) |
			((DL_COLOR_32)b);
	}

	namespace DL_COLORS
	{
		static const DL_VECTOR4 WHITE = {1.f, 1.f, 1.f, 1.f};
		static const DL_VECTOR4 BLACK = { 0.f, 0.f, 0.f, 1.f };
		static const DL_VECTOR4 RED = { 1.f, 0.f, 0.f, 1.f };
		static const DL_VECTOR4 GREEN = { 0.f, 1.f, 0.f, 1.f };
		static const DL_VECTOR4 BLUE = { 0.f, 0.f, 1.f, 1.f };
		static const DL_VECTOR4 YELLOW = { 1.f, 1.f, 0.f, 1.f };
		static const DL_VECTOR4 CYAN = { 0.f, 1.f, 1.f, 1.f };
		static const DL_VECTOR4 MAGENTA = { 1.f, 0.f, 1.f, 1.f };
		static const DL_VECTOR4 GRAY = { 0.5f, 0.5f, 0.5f, 1.f };
		static const DL_VECTOR4 ORANGE = { 1.f, 0.5f, 0.f, 1.f };
		static const DL_VECTOR4 PURPLE = { 0.5f, 0.f, 0.5f, 1.f };
		static const DL_VECTOR4 PINK = { 1.f, 0.75f, 0.8f, 1.f };
		static const DL_VECTOR4 BROWN = { 0.6f, 0.4f, 0.2f, 1.f };
		static const DL_VECTOR4 LIGHT_GRAY = { 0.8f, 0.8f, 0.8f, 1.f };
		static const DL_VECTOR4 DARK_GRAY = { 0.2f, 0.2f, 0.2f, 1.f };
		static const DL_VECTOR4 GOLD = { 1.f, 0.84f, 0.f, 1.f };
		static const DL_VECTOR4 SILVER = { 0.75f, 0.75f, 0.75f, 1.f };
		static const DL_VECTOR4 BRONZE = { 0.8f, 0.5f, 0.2f, 1.f };
		static const DL_VECTOR4 TEAL = { 0.f, 0.5f, 0.5f, 1.f };
		static const DL_VECTOR4 INDIGO = { 0.29f, 0.f, 0.51f, 1.f };
		static const DL_VECTOR4 LIME = { 0.5f, 1.f, 0.f, 1.f };
		static const DL_VECTOR4 OLIVE = { 0.5f, 0.5f, 0.f, 1.f };
		static const DL_VECTOR4 NAVY = { 0.f, 0.f, 0.5f, 1.f };
		static const DL_VECTOR4 MAROON = { 0.5f, 0.f, 0.f, 1.f };
		static const DL_VECTOR4 AQUA = { 0.f, 1.f, 1.f, 1.f };
		static const DL_VECTOR4 CORAL = { 1.f, 0.5f, 0.31f, 1.f };
		static const DL_VECTOR4 SALMON = { 1.f, 0.55f, 0.41f, 1.f };
		static const DL_VECTOR4 PEACH = { 1.f, 0.85f, 0.7f, 1.f };
		static const DL_VECTOR4 PLUM = { 0.87f, 0.63f, 0.87f, 1.f };
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