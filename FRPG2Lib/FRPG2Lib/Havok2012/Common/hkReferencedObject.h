#pragma once
#include "hkBaseObject.h"

namespace Havok
{
    struct hkReferencedObject : public hkBaseObject {
        UINT m_memSizeAndRefCount;

        int getReferenceCount() { return this->m_memSizeAndRefCount & 0xFFFF; }
    };
}