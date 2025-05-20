#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlDmy
	{
		void** _vfptr;
		int m_numDummies;
		float* m_pDummies;
		DLKR::DLAllocator* m_pAllocator;
	};
}