#pragma once
#include "../../../../Common/hkBaseDefs.h"
#include "../hkpShape.h"

namespace Havok
{
    struct hkpShapeContainer {
        void** _vfptr;
    };

    struct hkpSingleShapeContainer : public hkpShapeContainer {
        hkpShape* m_childShape;
    };
}