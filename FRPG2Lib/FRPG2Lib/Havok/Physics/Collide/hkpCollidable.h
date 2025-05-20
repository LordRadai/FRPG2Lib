#pragma once
#include <Windows.h>
#include "hkpCdBody.h"
#include "../../Common/hkAabb.h"
#include "Dispatch/hkpTypedBroadPhaseHandle.h"

namespace Havok
{
    struct hkpCollidable : public hkpCdBody {
        struct BoundingVolumeData {
            UINT m_min[3];
            byte m_expansionMin[3];
            byte m_expansionShift;
            UINT m_max[3];
            byte m_expansionMax[3];
            byte m_padding;
            USHORT m_numChildShapesAabb;
            USHORT m_capacityChildShapesAabb;
            hkAabbUInt32* m_childShapeAabbs;
            UINT* m_childShapeKeys;
        };

        byte m_ownerOffset;
        byte m_forceCollideOntoPpu;
        USHORT m_shapeSizeOnSpu;
        hkpTypedBroadPhaseHandle m_broadPhaseHandle;
        BoundingVolumeData m_boundingVolumeData;
        float m_allowedPenetrationDepth;
    };
}