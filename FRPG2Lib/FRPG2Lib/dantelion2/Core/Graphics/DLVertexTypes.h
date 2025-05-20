#pragma once
#include "dantelion2/Core/Math/Math.h"
#include <DirectXColors.h>

using namespace DirectX::SimpleMath;

namespace DLGR
{
	class DLVertexPositionColor
	{
	public:
		DLMT::DL_VECTOR4 m_position = DLMT::DL_VECTOR4::Zero;
		DLMT::DL_VECTOR4 m_color = DLMT::DL_VECTOR4(DirectX::Colors::White);

		DLVertexPositionColor() {}
		DLVertexPositionColor(DLMT::DL_VECTOR3 position, DirectX::XMVECTORF32 color);
		DLVertexPositionColor(DLMT::DL_VECTOR3 position, DLMT::DL_VECTOR4 color);
		DLVertexPositionColor(DLMT::DL_VECTOR4 position, DLMT::DL_VECTOR4 color);
		DLVertexPositionColor(DLMT::DL_VECTOR4 position, DirectX::XMVECTORF32 color);
	};
}