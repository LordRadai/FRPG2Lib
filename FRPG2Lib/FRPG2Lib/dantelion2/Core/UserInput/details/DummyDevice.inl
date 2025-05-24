#pragma once
#include "DLUserInputDeviceImpl.inl"

namespace DLUID
{
	template<class ThreadingPolicy>
	class DummyDevice : public DLUserInputDeviceImpl<ThreadingPolicy>
	{
	};
}