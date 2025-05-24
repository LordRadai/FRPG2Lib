#pragma once
#include <vector>
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace DLUT
{
	template<typename T>
	class DLVector : public std::vector<T>
	{
#ifndef _DEBUG
		DLKR::DLAllocator* m_pAllocator;
#endif

	public:
		DLVector() : std::vector<T>() {}

		DLVector(DLKR::DLAllocator* pAllocator) : std::vector<T>() 
		{
#ifndef _DEBUG
			m_pAllocator = pAllocator;
#endif
		}

		DLVector(size_t size, DLKR::DLAllocator* pAllocator) : std::vector<T>(size)
		{
#ifndef _DEBUG
			m_pAllocator = pAllocator;
#endif
			this->reserve(size);
		}

		DLVector(const DLVector& other) : std::vector<T>(other) 
		{
#ifndef _DEBUG
			m_pAllocator = other.m_pAllocator;
#endif
		}

		DLVector& operator=(const DLVector& other)
		{
			if (this != &other)
			{
				std::vector<T>::operator=(other);
#ifndef _DEBUG
				m_pAllocator = other.m_pAllocator;
#endif
			}
			return *this;
		}
	};
}