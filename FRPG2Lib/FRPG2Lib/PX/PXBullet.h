#pragma once
#include "PXEntity.h"
#include "Havok2012/Physics/Dynamics/Entity/hkpRigidBody.h"
#include "Havok2012/Physics/Dynamics/Phantom/hkpSimpleShapePhantom.h"

struct PXBulletBase : public PXEntity {
    DLMT::DL_VECTOR4 m_position;
    DLMT::DL_VECTOR4 m_rotation;
    DLMT::DL_VECTOR4 field3_0x40;
    DLMT::DL_VECTOR4 field4_0x50;
    DLMT::DL_VECTOR4 field5_0x60;
    DLMT::DL_VECTOR4 field6_0x70;
    DLMT::DL_VECTOR4 field7_0x80;
    DLMT::DL_VECTOR4 field8_0x90;
    dl_float32 field9_0xa0;
    dl_float32 field10_0xa4;
    dl_float32 field11_0xa8;
    dl_float32 field12_0xac;
    dl_float32 field13_0xb0;
    dl_float32 field14_0xb4;
    dl_float32 field15_0xb8;
    dl_float32 field16_0xbc;
    dl_float32 field17_0xc0;
    dl_int field18_0xc4;
    dl_float32 field19_0xc8;
    dl_float32 field20_0xcc;
    dl_float32 field21_0xd0;
    dl_float32 field22_0xd4;
    dl_float32 field23_0xd8;
    dl_float32 field24_0xdc;
    dl_float32 field25_0xe0;
    dl_float32 field26_0xe4;
    PXUserData* m_pPXUserData;
};

struct PXBulletRigidBody : public PXBulletBase {
    void** _vfptr2;
    PXUserValue m_userValue;
    Havok::hkpRigidBody* m_pHkpRigidBody[2];
    dl_int field6_0x118;
    dl_float32 field7_0x11c;
};

struct PXBulletPhantom  : public PXBulletBase {
    Havok::hkpSimpleShapePhantom* m_pHkpShapePhantom;
    dl_int field2_0xf8;
    dl_float32 field3_0xfc;
    dl_float32 field4_0x100;
    dl_float32 field5_0x104;
    dl_float32 field6_0x108;
    dl_float32 field7_0x10c;
    dl_float32 field8_0x110;
    dl_float32 field9_0x114;
    PXBulletPhantom* m_pPXBulletPhantom;
    PXUserValue m_userValue;
};