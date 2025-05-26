#pragma once
#include "../../hkpShape.h"

namespace Havok
{
    enum BvTreeType : BYTE {
        BVTREE_MOPP = 0,
        BVTREE_TRISAMPLED_HEIGHTFIELD = 1,
        BVTREE_STATIC_COMPOUND = 2,
        BVTREE_COMPRESSED_MESH = 3,
        BVTREE_USER = 4,
        BVTREE_MAX = 5
    };

    struct hkpBvTreeShape : public hkpShape {
        BvTreeType m_bvTreeType;
    };
}