#include "DLFormat.h"
#include "FRPG2Call.h"

namespace DLTX
{
	typedef void(_fastcall* oFormatV)(DLString* pBuffer, const wchar_t* fmt, va_list args);

	void DLFormat::Format(DLString* buf, const dl_wchar* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		FormatV(buf, fmt, args);

		va_end(args);
	}

	void DLFormat::FormatV(DLString* buf, const dl_wchar* fmt, va_list args)
	{
		FRPG2_CALL(oFormatV, 0x296c0, buf, fmt, args);
	}
}