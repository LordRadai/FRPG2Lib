#pragma once
#include "hkpBvTreeShape.h"
#include "../../ShapeContainer/hkpShapeContainer.h"

namespace Havok
{
    enum BuildType : BYTE {
        BUILT_WITH_CHUNK_SUBDIVISION = 0,
        BUILT_WITHOUT_CHUNK_SUBDIVISION = 1,
        BUILD_NOT_SET = 2
    };

    struct hkpMoppCode : public hkReferencedObject {
        hkVector4 m_offset;
        hkArray<UINT8> m_data;
        BuildType m_buildType;
    };

    struct hkpMoppBvTreeShape : public hkpBvTreeShape {
        hkpMoppCode* m_code;
        byte* m_moppData;
        UINT m_moppDataSize;
        hkVector4 m_codeInfoCopy;
        hkpSingleShapeContainer m_child;
        int m_childSize;
    };
}