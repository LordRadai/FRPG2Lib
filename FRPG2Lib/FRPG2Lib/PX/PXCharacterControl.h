#pragma once
#include "PXEntity.h"
#include <SimpleMath.h>
#include "Havok/Havok.h"
#include "Draw/DrawContext.h"

using namespace DirectX::SimpleMath;

struct PXCharacterRigidBody;

struct sPXContactRigidBodyInfo {
    struct hkpRigidBody* m_pHkpRigidBody;
    byte field1_0x8;
    byte field2_0x9;
    short field3_0xa;
};

struct PXCharacterControlBase : public PXEntity {
    void** super_PXWorldPreSimulationListener;
    void** super_PXWorldPostSimulationListener;
    UINT64 field3_0x30;
    UINT64 field4_0x38;
    UINT field5_0x40;
    float field6_0x44;
    float field7_0x48;
    float field8_0x4c;
    float field9_0x50;
    float field10_0x54;
    float field11_0x58;
    float field12_0x5c;
    int field13_0x60;
    BYTE field14_0x64;
    BYTE field15_0x65;
    BYTE field16_0x66;
    BYTE field17_0x67;
    BYTE field18_0x68;
    BYTE field19_0x69;
    BYTE field20_0x6a;
    BYTE field21_0x6b;
    BYTE field22_0x6c;
    BYTE field23_0x6d;
    BYTE field24_0x6e;
    BYTE field25_0x6f;
    Vector4 field26_0x70;
    Vector4 field27_0x80;
    Vector4 field28_0x90;
    Vector4 field29_0xa0;
    Vector4 field30_0xb0;
    Vector4 field31_0xc0;
    Vector4 field32_0xd0;
    Vector4 field33_0xe0;
    Vector4 field34_0xf0;
    sPXContactRigidBodyInfo field35_0x100;
    sPXContactRigidBodyInfo m_groundCollisionInfo;
    UINT field37_0x120;
    BYTE field38_0x124;
    BYTE field39_0x125;
    BYTE field40_0x126;
    BYTE field41_0x127;
    BYTE field42_0x128;
    BYTE field43_0x129;
    BYTE field44_0x12a;
    BYTE field45_0x12b;
    BYTE field46_0x12c;
    BYTE field47_0x12d;
    BYTE field48_0x12e;
    BYTE field49_0x12f;
    Vector4 field50_0x130;
    UINT64 field51_0x140;
    void* field52_0x148;
    UINT field53_0x150;
    BYTE field54_0x154;
    BYTE field55_0x155;
    BYTE field56_0x156;
    BYTE field57_0x157;
    BYTE field58_0x158;
    BYTE field59_0x159;
    BYTE field60_0x15a;
    BYTE field61_0x15b;
    BYTE field62_0x15c;
    BYTE field63_0x15d;
    BYTE field64_0x15e;
    BYTE field65_0x15f;
    void* field66_0x160;
    BYTE field67_0x168;
    BYTE field68_0x169;
    BYTE field69_0x16a;
    BYTE field70_0x16b;
    BYTE field71_0x16c;
    BYTE field72_0x16d;
    BYTE field73_0x16e;
    BYTE field74_0x16f;
    float field75_0x170;
    float field76_0x174;
    float field77_0x178;
    float field78_0x17c;
    float field79_0x180;
    float field80_0x184;
    float field81_0x188;
    float field82_0x18c;
    int field83_0x190;
    int field84_0x194;
    int field85_0x198;
    BYTE field86_0x19c;
    BYTE field87_0x19d;
    BYTE field88_0x19e;
    BYTE field89_0x19f;
    UINT64 field90_0x1a0;
    UINT64 field91_0x1a8;
    float field92_0x1b0;
    float field93_0x1b4;
    float field94_0x1b8;
    float field95_0x1bc;
    short field96_0x1c0;
    BYTE field97_0x1c2;
    BYTE field98_0x1c3;
};

struct PXCharacterRigidBodyContactListener : public Havok::hkpContactListener {
    PXCharacterRigidBody* m_pOwnerRigidBody;
    void* field2_0x10;
    void* field3_0x18;
    void* field4_0x20;
    void* field5_0x28;
    void* field6_0x30;
    void* field7_0x38;
    void* field8_0x40;
    void* field9_0x48;
};

struct PXCharacterRigidBody : public PXCharacterControlBase {
    BYTE field5_0x1c8;
    BYTE field6_0x1c9;
    BYTE field7_0x1ca;
    BYTE field8_0x1cb;
    BYTE field9_0x1cc;
    BYTE field10_0x1cd;
    BYTE field11_0x1ce;
    BYTE field12_0x1cf;
    Havok::hkpCharacterRigidBody* m_pHkpCharacterRigidBody;
    sPXUserValue m_userValue;
    PXCharacterRigidBodyContactListener m_contactListener;
    BYTE field16_0x238;
    BYTE field17_0x239;
    BYTE field18_0x23a;
    BYTE field19_0x23b;
    BYTE field20_0x23c;
    BYTE field21_0x23d;
    BYTE field22_0x23e;
    BYTE field23_0x23f;

    void Draw(IDrawContext* pDrawContext, bool wireframe, bool showAabb, Vector4 color);
};