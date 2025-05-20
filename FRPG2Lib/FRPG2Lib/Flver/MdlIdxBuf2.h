#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlIdxBuf2
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		dl_pointer m_pVar10;
		dl_pointer m_pVar18;
		dl_pointer m_pVar20;
		DLKR::DLAllocator* m_pAllocator2;
		dl_pointer m_pData;
		dl_pointer m_pVar38;
		dl_pointer m_pVar40;
		DLKR::DLAllocator* m_pAllocator3;
	};
}