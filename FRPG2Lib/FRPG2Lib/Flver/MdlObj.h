#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlObj
	{
		void** _vfptr;
		int m_numObjects;
		float* m_pPositions;
		DLKR::DLAllocator* m_pAllocator;
		wchar_t* m_pNames;
	};
}