#pragma once
#include "../../hkpShape.h"
#include "../../ShapeContainer/hkpShapeContainer.h"

namespace Havok
{
    enum CollectionType : char {
        COLLECTION_LIST = 0,
        COLLECTION_EXTENDED_MESH = 1,
        COLLECTION_TRISAMPLED_HEIGHTFIELD = 2,
        COLLECTION_USER = 3,
        COLLECTION_SIMPLE_MESH = 4,
        COLLECTION_MESH_SHAPE = 5,
        COLLECTION_COMPRESSED_MESH = 6,
        COLLECTION_MAX = 7
    };

    struct hkpShapeCollection : public hkpShape, public hkpShapeContainer {
        bool m_disableWelding;
        CollectionType m_collectionType;
    };
}