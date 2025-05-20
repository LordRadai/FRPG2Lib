#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlObj
	{
		void** _vfptr;
		dl_int m_numObjects;
		dl_float32* m_pPositions;
		DLKR::DLAllocator* m_pAllocator;
		dl_wchar* m_pNames;
	};
}