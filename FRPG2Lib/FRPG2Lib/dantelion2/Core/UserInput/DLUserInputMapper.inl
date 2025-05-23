#pragma once
#include "dantelion2/Core/Platform/Platform.h"
#include "dantelion2/Core/Util/DLVector.h"

namespace DLUI
{
	template<class ThreadingPolicy>
	class DLUserInputMapper
	{
	public:
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		DLUT::DLVector<dl_pointer> m_A2AMappingContexts;
		DLUT::DLVector<dl_pointer> m_D2DMappingContexts;
		DLUT::DLVector<dl_pointer> m_D2AMappingContexts;
		DLUT::DLVector<dl_pointer> m_A2DMappingContexts;
		DLUT::DLVector<dl_pointer> m_AA2DMappingContexts;
		ThreadingPolicy m_sync;
	};
}