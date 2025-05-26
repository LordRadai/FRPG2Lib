#pragma once
#include "../Common/hkpWorldObject.h"

namespace Havok
{
    struct hkpPhantom : public hkpWorldObject {
        hkArray<void*> m_overlapListeners;
        hkArray<void*> m_phantomListeners;
    };
}