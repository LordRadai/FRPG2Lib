#pragma once
#include "DLUserInputDeviceImpl.inl"

namespace DLUID
{
	template<class ThreadingPolicy>
	class MouseDevice : public DLUserInputDeviceImpl<ThreadingPolicy>
	{
		HINSTANCE m_hHinstance;
		dl_pointer m_pVarE8;
		dl_int m_speedX;
		dl_int m_speedY;
		dl_int m_scrollSpeed;
		dl_int m_buttonStates;
		dl_int m_iVar100;
		dl_bool m_bVar104;
		dl_bool m_bVar105;
		dl_float32 m_fSpeedX;
		dl_float32 m_fSpeedY;
		dl_float32 m_fScrollSpeed;
		dl_int m_iVar114;
	};
}