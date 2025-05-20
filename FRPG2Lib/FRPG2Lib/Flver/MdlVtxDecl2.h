#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlVtxDecl2
	{
		void** _vfptr;
		int m_iVar8;
		void* m_pVar10;
		void* m_pVar18;
		void* m_pVar20;
		int m_iVar28;
		DLKR::DLAllocator* m_pAllocator;
		DLKR::DLAllocator* m_pAllocator2;
		void* m_pVar40;
	};
}