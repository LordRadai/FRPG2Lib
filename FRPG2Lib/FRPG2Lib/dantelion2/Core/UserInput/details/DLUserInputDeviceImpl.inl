#pragma once
#include "../DLUserInputDevice.inl"

namespace DLUID
{
	template<class ThreadingPolicy>
	class DLUserInputDeviceImpl : public DLUI::DLUserInputDevice<ThreadingPolicy>
	{
		ThreadingPolicy m_sync;
		DLUT::DLVector<dl_pointer> m_vVar98;
		dl_float32 m_activeTime;
		dl_float32 m_fVarBC;
		DLUT::DLVector<dl_pointer> m_vVarC0;
	};
}