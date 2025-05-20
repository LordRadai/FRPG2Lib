#pragma once
#include "hkpConvexTransformShape.h"

namespace Havok
{
    struct hkpConvexTranslateShape : public hkpConvexTransformShapeBase {
        hkVector4 m_translation;
    };
}