#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace Flver
{
	struct MdlIdxBuf2
	{
		void** _vfptr;
		DLKR::DLAllocator* m_pAllocator;
		void* m_pVar10;
		void* m_pVar18;
		void* m_pVar20;
		DLKR::DLAllocator* m_pAllocator2;
		void* m_pData;
		void* m_pVar38;
		void* m_pVar40;
		DLKR::DLAllocator* m_pAllocator3;
	};
}