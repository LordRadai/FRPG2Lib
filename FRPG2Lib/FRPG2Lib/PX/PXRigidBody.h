#pragma once
#include "PXEntity.h"

class IDrawContext;

struct PXRigidBody : public PXEntity {
    Havok::hkpRigidBody* m_pHkpRigidBody;
    sPXUserValue m_userValue;
    bool m_collidable;

    void Draw(IDrawContext* pDrawContext, bool wireframe, bool showAabb, Vector4 color);
};

struct PXFixedRigidBody : public PXRigidBody {
};

struct PXKeyframedRigidBody : public PXRigidBody {
    void** field1_0x40;
    BYTE field2_0x48;
    BYTE field3_0x49;
    BYTE field4_0x4a;
    BYTE field5_0x4b;
    BYTE field6_0x4c;
    BYTE field7_0x4d;
    BYTE field8_0x4e;
    BYTE field9_0x4f;
    Vector4 m_position;
    void* field12_0x60;
    float field13_0x68;
    float field14_0x6c;
    int field15_0x70;
    BYTE field16_0x74;
    BYTE field17_0x75;
    BYTE field18_0x76;
    BYTE field19_0x77;
    BYTE field20_0x78;
    BYTE field21_0x79;
    BYTE field22_0x7a;
    BYTE field23_0x7b;
    BYTE field24_0x7c;
    BYTE field25_0x7d;
    BYTE field26_0x7e;
    BYTE field27_0x7f;

    void Draw(IDrawContext* pDrawContext, bool wireframe, bool showAabb, Vector4 color);
};

struct PXModelRigidBody : public PXEntity {
    DLKR::DLAllocator* m_pAllocator;
    sPXUserValue m_userValue;
    UINT64 field3_0x38;
    UINT64 field4_0x40;
    short* field5_0x48;
    UINT64 field6_0x50;
    UINT field7_0x58;
    int field8_0x5c;
    DLUT::DLVector<Havok::hkpRigidBody*> m_rigidBodyList;
    DynamicBitset m_unkBitset;
    void* field16_0xa0;
    void* field17_0xa8;
    PXUserData* field18_0xb0;
    UINT64 field19_0xb8;
    void* field20_0xc0;
    void* field21_0xc8;
    UINT64 field22_0xd0;
    UINT64 field23_0xd8;
    UINT64 field24_0xe0;
    void* field25_0xe8;
    byte m_unkFlags;
};

struct PXKeyframedModelRigidBody : public PXModelRigidBody {
    void Draw(IDrawContext* pDrawContext, bool wireframe, bool showAabb, Vector4 color);
};