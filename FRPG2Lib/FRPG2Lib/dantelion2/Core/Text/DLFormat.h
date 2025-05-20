#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLFormat
	{
	public:
		static void Format(DLString* buf, const dl_wchar* fmt, ...);
		static void FormatV(DLString* buf, const dl_wchar* fmt, va_list args);
	};
}