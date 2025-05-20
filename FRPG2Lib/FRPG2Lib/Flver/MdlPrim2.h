#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlPrim2
	{
		void** _vfptr;
		dl_int m_numPrims;
		dl_pointer m_pPrims;
		dl_bool m_bVar18;
		DLKR::DLAllocator* m_pAllocator;
		dl_pointer m_pUnkData;
	};
}