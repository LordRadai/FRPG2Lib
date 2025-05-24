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
        DLKR::DLAllocator* m_pAllocator = nullptr;
#endif

        dl_int32 m_charset = CS_PLATFORM;

    public:
		DLBasicString() : std::basic_string<_Elem, _Traits>() {}

		DLBasicString(const DLBasicString& other) : std::basic_string<_Elem, _Traits>(other)
		{
#ifndef _DEBUG
			this->m_pAllocator = other.m_pAllocator;
#endif
			this->m_charset = other.m_charset;
		}
		
		DLBasicString(DLKR::DLAllocator* pAllocator) : std::basic_string<_Elem, _Traits>()
		{
#ifndef _DEBUG
			this->m_pAllocator = pAllocator;
#endif
		}

        DLBasicString(const _Elem* str, DLKR::DLAllocator* pAllocator = nullptr, dl_int32 charset = CS_PLATFORM) : std::basic_string<_Elem, _Traits>(str)
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
#ifndef _DEBUG
				m_pAllocator = other.m_pAllocator;
#endif
				m_charset = other.m_charset;
			}
			return *this;
		}
    };

    typedef DLBasicString<dl_wchar> DLString;
    typedef DLBasicString<dl_char> DLAsciiString;
}