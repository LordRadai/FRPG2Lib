#pragma once
#include "../../../../Common/hkReferencedObject.h"

namespace Havok
{
	struct CustomMeshParameter : public hkReferencedObject {
        int field1_0x10;
        int field2_0x14;
        int field3_0x18;
        int field4_0x1c;
        int field5_0x20;
        int field6_0x24;
        int field7_0x28;
        int field8_0x2c;
        int field9_0x30;
        int field10_0x34;
        int field11_0x38;
        int field12_0x3c;
        int field13_0x40;
        int field14_0x44;
        int field15_0x48;
        int field16_0x4c;
	};

    struct CustomMeshTriangleParameter : public CustomMeshParameter {
    };
}