#pragma once
#include "hkpShapeCollection.h"

namespace Havok
{
    struct ChildInfo {
        HK_ALIGN16(hkpShape* m_shape);
        UINT m_collisionFilterInfo;
        UINT16 m_shapeInfo;
        UINT16 m_shapeSize;
        int m_numChildShapes;
    };

    struct hkpListShape : public hkpShapeCollection {
        hkArray<ChildInfo> m_childInfo;
        UINT16 m_flags;
        UINT16 m_numDisabledChildren;
        hkVector4 m_aabbHalfExtents;
        hkVector4 m_aabbCenter;
        UINT m_enabledChildren[8];
    };
}