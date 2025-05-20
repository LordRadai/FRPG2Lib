#pragma once
#include "hkpConvexShape.h"

namespace Havok
{
    struct hkpBoxShape : public hkpConvexShape {
        hkVector4 m_halfExtents;

        hkpBoxShape() {}
        hkpBoxShape(Vector4 halfExtents) 
        {
            this->m_type = ShapeType::BOX;
            this->m_dispatchType = ShapeDispatchType::USER;
            this->m_halfExtents = halfExtents; 
        }
        ~hkpBoxShape() {}
    };
}