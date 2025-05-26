#pragma once
#include "../../Common/hkReferencedObject.h"
#include "../Rig/hkaSkeleton.h"
#include "../../Physics/Dynamics/Entity/hkpRigidBody.h"

namespace Havok
{
    struct hkaRagdollInstance : public hkReferencedObject {
        hkArray<hkpRigidBody*> m_rigidBodies;
        hkArray<void*> m_constraints;
        hkArray<int> m_boneToRigidBodyMap;
        hkaSkeleton* m_skeleton;
    };
}