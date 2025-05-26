#pragma once
#include "hkpConvexShape.h"

namespace Havok
{
    struct hkpCylinderShape : public hkpConvexShape {
        float m_cylRadius;
        float m_cylBaseRadiusFactorForHeightFieldCollision;
        hkVector4 m_vertexA;
        hkVector4 m_vertexB;
        hkVector4 m_perpendicular1;
        hkVector4 m_perpendicular2;
    };
}