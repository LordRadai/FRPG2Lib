#pragma once
#include "hkpConvexShape.h"

namespace Havok
{
    struct hkpSphereShape : public hkpConvexShape {
        UINT m_pad16[3];

        hkpSphereShape() {}
        hkpSphereShape(float radius)
        {
            this->m_type = ShapeType::SPHERE;
            this->m_dispatchType = ShapeDispatchType::USER;
            this->m_radius = radius;
        }
    };
}