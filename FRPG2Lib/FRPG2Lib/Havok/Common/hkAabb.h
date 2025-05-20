#pragma once
#include <Windows.h>
#include "hkBaseDefs.h"

namespace Havok
{
    HK_CLASSALIGN16(struct) hkAabbUInt32 {
        UINT m_min[3];
        byte m_expansionMin[3];
        byte m_expansionShift;
        UINT m_max[3];
        byte m_expansionMax[3];
        byte m_shapeKeyByte;
    };
}