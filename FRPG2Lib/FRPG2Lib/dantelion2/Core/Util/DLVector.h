#pragma once
#include <vector>
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace DLUT
{
	template<typename T>
	class DLVector : public std::vector<T>
	{
		DLKR::DLAllocator* m_pAllocator;
	};
}