#pragma once
#include "PXEntity.h"
#include <SimpleMath.h>
#include "Havok/Physics/Dynamics/Entity/hkpRigidBody.h"
#include "Havok/Physics/Dynamics/Phantom/hkpSimpleShapePhantom.h"

using namespace DirectX::SimpleMath;

struct PXBulletBase : public PXEntity {
    Vector4 m_position;
    Vector4 m_rotation;
    Vector4 field3_0x40;
    Vector4 field4_0x50;
    Vector4 field5_0x60;
    Vector4 field6_0x70;
    Vector4 field7_0x80;
    Vector4 field8_0x90;
    float field9_0xa0;
    float field10_0xa4;
    float field11_0xa8;
    float field12_0xac;
    float field13_0xb0;
    float field14_0xb4;
    float field15_0xb8;
    float field16_0xbc;
    float field17_0xc0;
    int field18_0xc4;
    float field19_0xc8;
    float field20_0xcc;
    float field21_0xd0;
    float field22_0xd4;
    float field23_0xd8;
    float field24_0xdc;
    float field25_0xe0;
    float field26_0xe4;
    PXUserData* m_pPXUserData;
};

struct PXBulletRigidBody : public PXBulletBase {
    void** _vfptr2;
    sPXUserValue m_userValue;
    Havok::hkpRigidBody* m_pHkpRigidBody[2];
    int field6_0x118;
    float field7_0x11c;
};

struct PXBulletPhantom  : public PXBulletBase {
    Havok::hkpSimpleShapePhantom* m_pHkpShapePhantom;
    int field2_0xf8;
    float field3_0xfc;
    float field4_0x100;
    float field5_0x104;
    float field6_0x108;
    float field7_0x10c;
    float field8_0x110;
    float field9_0x114;
    PXBulletPhantom* m_pPXBulletPhantom;
    sPXUserValue m_userValue;
};