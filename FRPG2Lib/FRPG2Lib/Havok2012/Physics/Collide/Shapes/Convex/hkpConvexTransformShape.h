#pragma once
#include "../ShapeContainer/hkpShapeContainer.h"
#include "hkpConvexShape.h"

namespace Havok
{
    struct hkpConvexTransformShapeBase : public hkpConvexShape {
        hkpSingleShapeContainer m_childShape;
        int m_childShapeSizeOnSpu;
    };

    struct hkpConvexTransformShape : public hkpConvexTransformShapeBase {
        hkQsTransform m_transform;
        hkVector4 m_extraScale;
    };
}