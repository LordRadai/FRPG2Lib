#pragma once
#include <string>
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "dantelion2/Core/Platform/Platform.h"
#include "DLCharSet.h"

namespace DLTX
{
    template<class _Elem, typename _Traits = ::std::char_traits<_Elem>>
    class DLBasicString : public ::std::basic_string<_Elem, _Traits> 
    {
#ifndef _DEBUG
        DLKR::DLAllocator* m_pAllocator;
#endif

        dl_int32 m_charset;

    public:
		DLBasicString() : std::basic_string<_Elem, _Traits>(), m_pAllocator(nullptr), m_charset(CS_PLATFORM) {}

		DLBasicString(const DLBasicString& other) : std::basic_string<_Elem, _Traits>(other), m_pAllocator(other.m_pAllocator), m_charset(other.m_charset) {}
		
		DLBasicString(DLKR::DLAllocator* pAllocator) : std::basic_string<_Elem, _Traits>(), m_pAllocator(pAllocator), m_charset(CS_PLATFORM) {}

        DLBasicString(const _Elem* str, DLKR::DLAllocator* pAllocator, dl_int32 charset = CS_PLATFORM) : std::basic_string<_Elem, _Traits>(str)
        {
#ifndef _DEBUG
            this->m_pAllocator = pAllocator;
#endif
			this->m_charset = charset;
        }

		DLBasicString& operator=(const DLBasicString& other)
		{
			if (this != &other)
			{
				std::basic_string<_Elem, _Traits>::operator=(other);
				m_pAllocator = other.m_pAllocator;
				m_charset = other.m_charset;
			}
			return *this;
		}
    };

    typedef DLBasicString<dl_wchar> DLString;
    typedef DLBasicString<dl_char> DLAsciiString;
}