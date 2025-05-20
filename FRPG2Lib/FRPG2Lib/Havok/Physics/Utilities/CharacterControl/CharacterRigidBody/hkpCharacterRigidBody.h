#pragma once
#include "../../../../Common/hkReferencedObject.h"
#include "../../../Dynamics/World/Listener/hkpWorldPostSimulationListener.h"
#include "../../../Dynamics/Entity/hkpEntityListener.h"
#include "../../../Dynamics/Entity/hkpRigidBody.h"
#include "hkpCharacterRigidBodyListener.h"

namespace Havok
{
    struct hkpCharacterRigidBody : public hkReferencedObject, public hkpEntityListener, public hkpWorldPostSimulationListener {
        hkpRigidBody* m_character;
        hkpCharacterRigidBodyListener* m_listener;
        hkVector4 m_up;
        float m_unweldingHeightOffsetFactor;
        float m_maxSlopeCosine;
        float m_maxSpeedForSimplexSolver;
        float m_supportDistance;
        float m_hardSupportDistance;
        BYTE field11_0x54;
        BYTE field12_0x55;
        BYTE field13_0x56;
        BYTE field14_0x57;
        BYTE field15_0x58;
        BYTE field16_0x59;
        BYTE field17_0x5a;
        BYTE field18_0x5b;
        BYTE field19_0x5c;
        BYTE field20_0x5d;
        BYTE field21_0x5e;
        BYTE field22_0x5f;
        hkVector4 m_acceleration;
        float m_maxForce;
        hkArray<void*> m_verticalContactPoints;
    };
}