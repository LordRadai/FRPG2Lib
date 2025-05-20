#pragma once
#include "hkpPhantom.h"
#include "../../../Common/hkMotionState.h"

namespace Havok
{
    struct hkpShapePhantom : public hkpPhantom {
        BYTE field1_0xe8;
        BYTE field2_0xe9;
        BYTE field3_0xea;
        BYTE field4_0xeb;
        BYTE field5_0xec;
        BYTE field6_0xed;
        BYTE field7_0xee;
        BYTE field8_0xef;
        hkMotionState m_motionState;
    };
}