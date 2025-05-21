#pragma once
#include "DLString.inl"

namespace DLTX
{
	class DLStringUtil
	{
	public:
		static void Copy(DLString* dst, const DLString* src, dl_size size);
		static void Assign(DLString* dst, DLString* src, DLKR::DLAllocator* pAllocator);
		static DLString ToWide(const DLAsciiString& pSrc);
	};
}
