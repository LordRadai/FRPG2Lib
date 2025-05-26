#pragma once
#include "../hkpShape.h"
#include "QuickHull/QuickHull.hpp"

namespace Havok
{
    struct hkpConvexShape : public hkpShape {
        float m_radius;
    };
}