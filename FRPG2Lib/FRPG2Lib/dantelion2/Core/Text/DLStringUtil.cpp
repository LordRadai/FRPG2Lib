#include <cstdlib>
#include "DLStringUtil.h"
#include "FRPG2Call.h"
#include "Draw/DrawContext.h"

typedef void(_fastcall* oCreateDLString)(UINT64 ModelTestScene, IDrawContext* DrawContext);

namespace DLTX
{
	typedef void(_fastcall* oCopySize)(DLString* dst, const DLString* src, dl_size size);
	typedef void(_fastcall* oAssignAllocator)(DLString* dst, DLString* src, DLKR::DLAllocator* pAllocator);

	void DLStringUtil::Copy(DLString* dst, const DLString* src, dl_size size)
	{
		FRPG2_CALL(oCopySize, 0x3dc00, dst, src, size);
	}

	void DLStringUtil::Assign(DLString* dst, DLString* src, DLKR::DLAllocator* pAllocator)
	{
		FRPG2_CALL(oAssignAllocator, 0x3d780, dst, src, pAllocator);
	}

	DLString DLStringUtil::ToWide(const DLAsciiString& pSrc)
	{
        const dl_char* src = pSrc.c_str();
        size_t srcLen = std::char_traits<dl_char>::length(src);

        DLUT::DLVector<dl_wchar> wideBuffer(srcLen + 1, nullptr);
        size_t convertedChars = 0;

        errno_t err = mbstowcs_s(
            &convertedChars,
            wideBuffer.data(),
            wideBuffer.size(),
            src,
            _TRUNCATE
        );

        if (err != 0)
            return DLString();

        return DLString(wideBuffer.data());
	}
}