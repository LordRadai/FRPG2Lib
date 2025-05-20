#pragma once

namespace DLTX
{
    enum DLCharacterSet {
        CS_UTF8,
        CS_UTF16,
        CS_UNICODE = CS_UTF16,
        CS_ISO_8859_1,
        CS_SHIFT_JIS,
        CS_EUC_JP,
        CS_PLATFORM = CS_UTF16,
    };
}