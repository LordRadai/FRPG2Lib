#pragma once
#include "../DLUserInputDevice.inl"

namespace DLUID
{
	template<class ThreadingPolicy>
	class DLUserInputDeviceImpl : public DLUserInputDevice<ThreadingPolicy>
	{
		ThreadingPolicy m_sync;
	};
}