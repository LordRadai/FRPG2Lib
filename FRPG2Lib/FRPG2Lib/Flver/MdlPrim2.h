#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlPrim2
	{
		void** _vfptr;
		int m_numPrims;
		void* m_pPrims;
		bool m_bVar18;
		DLKR::DLAllocator* m_pAllocator;
		void* m_pUnkData;
	};
}