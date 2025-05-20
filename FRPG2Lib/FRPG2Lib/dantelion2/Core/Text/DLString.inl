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
        DLBasicString(const _Elem* str, DLKR::DLAllocator* pAllocator, dl_int32 charset = CS_PLATFORM) : std::basic_string<_Elem, _Traits>(str)
        {
#ifndef _DEBUG
            this->m_pAllocator = pAllocator;
#endif
			this->m_charset = charset;
        }
    };

    typedef DLBasicString<dl_wchar> DLString;
    typedef DLBasicString<dl_char> DLAsciiString;
}