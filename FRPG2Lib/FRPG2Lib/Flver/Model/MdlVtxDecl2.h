#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlVtxDecl2
	{
		void** _vfptr;
		dl_int m_iVar8;
		dl_pointer m_pVar10;
		dl_pointer m_pVar18;
		dl_pointer m_pVar20;
		dl_int m_iVar28;
		DLKR::DLAllocator* m_pAllocator;
		DLKR::DLAllocator* m_pAllocator2;
		dl_pointer m_pVar40;
	};
}