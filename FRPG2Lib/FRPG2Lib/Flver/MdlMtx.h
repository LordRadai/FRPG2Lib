#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlMtx
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		int m_numMaterials;
		void* m_pMaterials;
	};
}