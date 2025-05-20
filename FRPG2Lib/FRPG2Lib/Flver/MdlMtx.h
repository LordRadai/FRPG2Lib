#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlMtx
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		dl_int m_numMaterials;
		dl_pointer m_pMaterials;
	};
}