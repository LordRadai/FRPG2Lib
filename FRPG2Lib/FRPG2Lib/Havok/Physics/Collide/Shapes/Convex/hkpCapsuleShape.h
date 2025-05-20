#pragma once
#include "hkpConvexShape.h"

namespace Havok
{
    struct hkpCapsuleShape : public hkpConvexShape {
        hkVector4 m_vertexA;
        hkVector4 m_vertexB;

        hkpCapsuleShape() {}

        hkpCapsuleShape(float radius, Vector4 vertexA, Vector4 vertexB)
        {
            this->m_type = ShapeType::CAPSULE;
            this->m_dispatchType = ShapeDispatchType::USER;
            this->m_radius = radius;
            this->m_vertexA = vertexA;
            this->m_vertexB = vertexB;
        }

        hkpCapsuleShape(float radius, Vector3 vertexA, Vector3 vertexB)
        {
            hkpCapsuleShape(radius, Vector4(vertexA), Vector4(vertexB));
        }
    };
}