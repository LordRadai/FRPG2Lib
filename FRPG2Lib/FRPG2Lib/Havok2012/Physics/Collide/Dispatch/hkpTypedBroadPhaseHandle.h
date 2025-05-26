#pragma once
#include "hkpBroadPhaseHandle.h"

namespace Havok
{
    struct hkpTypedBroadPhaseHandle : public hkpBroadPhaseHandle {
        byte m_type;
        byte m_ownerOffset;
        byte m_objectQualityType;
        UINT m_collisionFilterInfo;
    };
}