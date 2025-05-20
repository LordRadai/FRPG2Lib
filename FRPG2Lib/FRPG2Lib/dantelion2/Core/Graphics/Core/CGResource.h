#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace DLCG2
{
	class CGResource
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		dl_int m_nRefCount;
	};
}