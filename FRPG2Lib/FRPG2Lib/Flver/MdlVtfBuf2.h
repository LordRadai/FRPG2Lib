#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlVtxBuf2
	{
		void** _vfptr;
		int m_iVar8;
		float* m_pData;
		DLKR::DLAllocator* m_pAllocator;
	};
}