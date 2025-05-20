#pragma once
#include "hkBaseDefs.h"

namespace Havok
{
    struct hkMotionState {
        hkTransform m_transform;
        hkSweptTransformf m_sweptTransform;
        hkVector4 m_deltaAngle;
        float m_objectRadius;
        hkHalf m_linearDamping;
        hkHalf m_angularDamping;
        hkHalf m_timeFactor;
        byte m_maxLinearVelocity;
        byte m_maxAngularVelocity;
        byte m_deactivationClass;
    };
}