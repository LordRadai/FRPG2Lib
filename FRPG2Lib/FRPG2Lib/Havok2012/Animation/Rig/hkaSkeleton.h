#pragma once
#include "../../Common/hkReferencedObject.h"
#include "hkaBone.h"

namespace Havok
{
    struct hkaSkeleton : public hkReferencedObject {
        const char* m_name;
        hkArray<short> m_parentIndices;
        hkArray<hkaBone> m_bones;
        hkArray<hkQsTransform> m_referencePose;
        hkArray<float> m_referenceFloats;
        hkArray<const char*> m_floatSlots;
        hkArray<void*> m_localFrames;
        hkArray<void*> m_partitions;
    };
}