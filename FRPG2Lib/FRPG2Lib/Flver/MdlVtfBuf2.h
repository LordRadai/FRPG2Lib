#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlVtxBuf2
	{
		void** _vfptr;
		dl_int m_iVar8;
		dl_float32* m_pData;
		DLKR::DLAllocator* m_pAllocator;
	};
}