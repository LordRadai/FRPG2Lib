#pragma once
#include "PXEntity.h"

class IDrawContext;

struct PXRigidBody : public PXEntity {
    Havok::hkpRigidBody* m_pHkpRigidBody;
    PXUserValue m_userValue;
    dl_bool m_collidable;

    void Draw(IDrawContext* pDrawContext, dl_bool wireframe, dl_bool showAabb, DLMT::DL_VECTOR4 color);
};

struct PXFixedRigidBody : public PXRigidBody {
};

struct PXKeyframedRigidBody : public PXRigidBody {
    dl_pointer field1_0x40;
    dl_uchar field2_0x48;
    dl_uchar field3_0x49;
    dl_uchar field4_0x4a;
    dl_uchar field5_0x4b;
    dl_uchar field6_0x4c;
    dl_uchar field7_0x4d;
    dl_uchar field8_0x4e;
    dl_uchar field9_0x4f;
    DLMT::DL_VECTOR4 m_position;
    dl_pointer field12_0x60;
    dl_float32 field13_0x68;
    dl_float32 field14_0x6c;
    dl_int field15_0x70;
    dl_uchar field16_0x74;
    dl_uchar field17_0x75;
    dl_uchar field18_0x76;
    dl_uchar field19_0x77;
    dl_uchar field20_0x78;
    dl_uchar field21_0x79;
    dl_uchar field22_0x7a;
    dl_uchar field23_0x7b;
    dl_uchar field24_0x7c;
    dl_uchar field25_0x7d;
    dl_uchar field26_0x7e;
    dl_uchar field27_0x7f;

    void Draw(IDrawContext* pDrawContext, dl_bool wireframe, dl_bool showAabb, DLMT::DL_VECTOR4 color);
};

struct PXModelRigidBody : public PXEntity {
    DLKR::DLAllocator* m_pAllocator;
    PXUserValue m_userValue;
    dl_uint64 field3_0x38;
    dl_uint64 field4_0x40;
    dl_int16* field5_0x48;
    dl_uint64 field6_0x50;
    dl_uint field7_0x58;
    dl_int field8_0x5c;
    DLUT::DLVector<Havok::hkpRigidBody*> m_rigidBodyList;
    DLUID::DynamicBitset m_unkBitset;
    dl_pointer field16_0xa0;
    dl_pointer field17_0xa8;
    PXUserData* field18_0xb0;
    dl_uint64 field19_0xb8;
    dl_pointer field20_0xc0;
    dl_pointer field21_0xc8;
    dl_uint64 field22_0xd0;
    dl_uint64 field23_0xd8;
    dl_uint64 field24_0xe0;
    dl_pointer field25_0xe8;
    byte m_unkFlags;
};

struct PXKeyframedModelRigidBody : public PXModelRigidBody {
    void Draw(IDrawContext* pDrawContext, dl_bool wireframe, dl_bool showAabb, DLMT::DL_VECTOR4 color);
};