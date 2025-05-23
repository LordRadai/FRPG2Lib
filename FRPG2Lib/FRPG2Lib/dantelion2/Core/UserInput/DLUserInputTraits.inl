#pragma once
#include "dantelion2/Core/Util/DLVector.h"
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "dantelion2/Core/Platform/Platform.h"
#include "details/UserInputExtension.h"

namespace DLUI
{
	template<class ThreadingPolicy>
	class DLUserInputTraits
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		ThreadingPolicy m_sync;
		DLUT::DLVector<DLUID::UserInputExtension*> m_extensions;
	};
}