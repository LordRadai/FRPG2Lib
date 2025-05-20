#pragma once
#include <vector>
#include "dantelion2/Core/Kernel/DLAllocator.h"

namespace DLUT
{
	template<typename T>
	class DLVector : public std::vector<T>
	{
		DLKR::DLAllocator* m_pAllocator;

	public:
		DLVector() : std::vector<T>(), m_pAllocator(nullptr) {}

		DLVector(DLKR::DLAllocator* pAllocator) : std::vector<T>(), m_pAllocator(pAllocator) {}

		DLVector(size_t size, DLKR::DLAllocator* pAllocator) : std::vector<T>(size), m_pAllocator(pAllocator)
		{
			this->reserve(size);
		}

		DLVector(const DLVector& other) : std::vector<T>(other), m_pAllocator(other.m_pAllocator) {}

		DLVector& operator=(const DLVector& other)
		{
			if (this != &other)
			{
				std::vector<T>::operator=(other);
				m_pAllocator = other.m_pAllocator;
			}
			return *this;
		}
	};
}