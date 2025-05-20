#pragma once
#include "hkpConvexShape.h"

namespace Havok
{
    struct hkpConvexVerticesConnectivity : public hkReferencedObject {
        hkArray<UINT16> m_verticesIndices;
        hkArray<UINT8> m_numVerticesPerFace;
    };

    struct hkFourTransposedPointsf {
        hkVector4 m_vertices[3];
    };

    struct hkpConvexVerticesShape : public hkpConvexShape {
        hkVector4 m_aabbHalfExtents;
        hkVector4 m_aabbCenter;
        hkArray<hkFourTransposedPointsf> m_rotatedVertices;
        int m_numVertices;
        bool m_useSpuBuffer;
        hkArray<hkVector4> m_planeEquations;
        hkpConvexVerticesConnectivity* m_connectivity;

        void getOriginalVertices(hkVector4* vertices);
    };
}