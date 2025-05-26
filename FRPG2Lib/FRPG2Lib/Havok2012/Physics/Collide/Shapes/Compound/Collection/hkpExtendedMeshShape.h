#pragma once
#include "hkpShapeCollection.h"
#include "../../Convex/hkpConvexShape.h"

namespace Havok
{
    enum WeldingType : BYTE {
        WELDING_TYPE_ANTICLOCKWISE = 0,
        WELDING_TYPE_CLOCKWISE = 4,
        WELDING_TYPE_TWO_SIDED = 5,
        WELDING_TYPE_NONE = 6
    };

    enum IndexStridingType : BYTE {
        INDICES_INVALID = 0,
        INDICES_INT8 = 1,
        INDICES_INT16 = 2,
        INDICES_INT32 = 3,
        INDICES_MAX_ID = 4
    };

    struct Subpart {
        USHORT m_typeAndFlags;
        USHORT m_shapeInfo;
        USHORT m_materialStriding;
        USHORT m_materialIndexStriding;
        void* m_materialIndexBase;
        void* m_materialBase;
        UINT64 m_userData;
    };

    struct TrianglesSubpart : public Subpart {
        int m_numTriangleShapes;
        float* m_vertexBase;
        int m_numVertices;
        void* m_indexBase;
        USHORT m_vertexStriding;
        int m_triangleOffset;
        USHORT m_indexStriding;
        IndexStridingType m_stridingType;
        byte m_flipAlternateTriangles;
        hkVector4 m_extrusion;
        hkQsTransform m_transform;
    };

    struct ShapesSubpart : public Subpart {
        hkArray<hkpConvexShape*> m_childShapes;
        hkQuaternion m_rotation;
        hkVector4 m_translation;
    };

    struct hkpExtendedMeshShape : public hkpShapeCollection {
        TrianglesSubpart m_embeddedTrianglesSubpart;
        hkVector4 m_aabbHalfExtents;
        hkVector4 m_aabbCenter;
        void* m_materialClass;
        UINT m_numBitsForSubpartIndex;
        hkArray<TrianglesSubpart> m_trianglesSubparts;
        hkArray<ShapesSubpart> m_shapesSubparts;
        hkArray<UINT16> m_weldingInfo;
        WeldingType m_weldingType;
        UINT m_collisionFilterInfo;
        int m_cachedNumChildShapes;
        float m_triangleRadius;
        int m_padding;
    };
}