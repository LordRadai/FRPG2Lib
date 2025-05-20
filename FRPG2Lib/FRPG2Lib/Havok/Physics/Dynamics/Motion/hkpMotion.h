#pragma once
#include "../../../Common/hkReferencedObject.h"
#include "../../../Common/hkBaseDefs.h"

namespace Havok
{
    enum MotionType : BYTE {
        MOTION_INVALID = 0,
        MOTION_DYNAMIC = 1,
        MOTION_SPHERE_INERTIA = 2,
        MOTION_BOX_INERTIA = 3,
        MOTION_KEYFRAMED = 4,
        MOTION_FIXED = 5,
        MOTION_THIN_BOX_INERTIA = 6,
        MOTION_CHARACTER = 7,
        MOTION_MAX_ID = 8
    };

    struct hkpMotion : public hkReferencedObject {
        struct hkMotionState {
            hkTransform m_transform;
            hkSweptTransformf m_sweptTransform;
            hkVector4 m_deltaAngle;
            float m_objectRadius;
            WORD m_linearDamping;
            WORD m_angularDamping;
            WORD m_timeFactor;
            byte m_maxLinearVelocity;
            byte m_maxAngularVelocity;
            byte m_deactivationClass;
        };

        MotionType m_type;
        byte m_deactivationIntegrateCounter;
        short m_deactivationNumInactiveFrames[2];
        hkMotionState m_motionState;
        hkVector4 m_inertiaAndMassInv;
        hkVector4 m_linearVelocity;
        hkVector4 m_angularVelocity;
        hkVector4 m_deactivationRefPosition[2];
        UINT m_deactivationRefOrientation[2];
        struct hkpMaxSizeMotion* m_savedMotion;
        USHORT m_savedQualityTypeIndex;
        hkHalf m_gravityFactor;
    };
}