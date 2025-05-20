#pragma once
#include "../../../Common/hkReferencedObject.h"

namespace Havok
{
    namespace ShapeType
    {
        enum ShapeTypeEnum : BYTE {
            SPHERE,
            CYLINDER,
            TRIANGLE,
            BOX,
            CAPSULE,
            CONVEX_VERTICES,
            TRI_SAMPLED_HEIGHT_FIELD_COLLECTION,
            TRI_SAMPLED_HEIGHT_FIELD_BV_TREE,
            LIST,
            MOPP,
            CONVEX_TRANSLATE,
            CONVEX_TRANSFORM,
            SAMPLED_HEIGHT_FIELD,
            EXTENDED_MESH,
            TRANSFORM,
            COMPRESSED_MESH,
            STATIC_COMPOUND,
            BV_COMPRESSED_MESH,
            COLLECTION,
            USER0,
            USER1,
            USER2,
            BV_TREE,
            CONVEX,
            CONVEX_PIECE,
            MULTI_SPHERE,
            CONVEX_LIST,
            TRIANGLE_COLLECTION,
            HEIGHT_FIELD,
            SPHERE_REP,
            BV,
            PLANE,
            PHANTOM_CALLBACK,
            MULTI_RAY,
            INVALID,
        };
    }

    namespace ShapeDispatchType
    {
        enum ShapeDispatchTypeEnum : BYTE {
            CONVEX_IMPLICIT,
            CONVEX,
            HEIGHT_FIELD,
            COMPOSITE,
            USER,
            NUM_DISPATCH_TYPES
        };
    }

    namespace ShapeInfoCodecType
    {
        enum ShapeInfoCodecTypeEnum : BYTE {
            NULL_CODEC,
            UFM358,
            MAX_NUM_CODECS = 16
        };
    }

    struct hkcdShape : public hkReferencedObject {
        ShapeType::ShapeTypeEnum m_type;
        ShapeDispatchType::ShapeDispatchTypeEnum m_dispatchType;
        BYTE m_bitsPerKey;
        ShapeInfoCodecType::ShapeInfoCodecTypeEnum m_shapeInfoCodecType;
    };

    struct hkpShapeBase : public hkcdShape {
    };

    struct hkpShape : public hkpShapeBase {
        UINT64 m_userData;
    };
}