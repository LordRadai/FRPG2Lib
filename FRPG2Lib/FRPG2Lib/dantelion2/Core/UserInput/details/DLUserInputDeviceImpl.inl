#pragma once
#include "../DLUserInputDevice.inl"

namespace DLUID
{
	template<class ThreadingPolicy>
	class DLUserInputDeviceImpl : public DLUI::DLUserInputDevice<ThreadingPolicy>
	{
		ThreadingPolicy m_sync;
	};
}