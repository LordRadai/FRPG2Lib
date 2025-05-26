#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlDmy
	{
		void** _vfptr;
		dl_int m_numDummies;
		dl_float32* m_pDummies;
		DLKR::DLAllocator* m_pAllocator;
	};
}