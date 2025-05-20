#pragma once
#include <Windows.h>

namespace Havok
{
    struct hkSimplePropertyValue
    {
        UINT64 m_data;
    };

    struct hkSimpleProperty
    {
        UINT m_key;
        UINT m_alignmentPadding;
        hkSimplePropertyValue m_value;
    };
}