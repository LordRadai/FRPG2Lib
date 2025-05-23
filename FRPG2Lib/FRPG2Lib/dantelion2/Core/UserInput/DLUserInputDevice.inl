#pragma once
#include "details/VirtualInputData.h"
#include "details/UserInputExtension.h"
#include "details/DLUserInputTraitsImpl.inl"
#include "details/DLUserInputMapperImpl.inl"

namespace DLUI
{
	template<class ThreadingPolicy>
	class DLUserInputDevice
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		DLUID::VirtualInputData m_virtualInputData;
		DLUT::DLVector<DLUID::UserInputExtension*> m_userInputExtensions;
		DLUID::DLUserInputTraitsImpl<ThreadingPolicy>* m_pUserInputTraits;
		DLUID::DLUserInputMapperImpl<ThreadingPolicy>* m_pUserInputMapper;
	};
}