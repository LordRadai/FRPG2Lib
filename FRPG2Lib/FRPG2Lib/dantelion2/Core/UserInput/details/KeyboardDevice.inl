#pragma once
#include "DLUserInputDeviceImpl.inl"

namespace DLUID
{
	template<class ThreadingPolicy>
	class KeyboardDevice : public DLUserInputDeviceImpl<ThreadingPolicy>
	{
		HINSTANCE m_hHinstance;
		dl_pointer m_pVarE8;
		dl_uchar m_keyStates[256];
		dl_bool m_bVar1F0;
		dl_bool m_bVar1F1;
	};
}