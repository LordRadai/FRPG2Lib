#pragma once
#include <Windows.h>
#include "Shapes/hkpShape.h"

namespace Havok
{
    struct hkpCdBody {
        hkpShape* m_shape;
        UINT m_shapeKey;
        void* m_motion;
        hkpCdBody* m_parent;
    };
}