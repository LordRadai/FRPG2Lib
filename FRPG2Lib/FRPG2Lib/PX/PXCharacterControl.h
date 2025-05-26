#pragma once
#include "PXEntity.h"
#include "PXWorldPostSimulationListener.h"
#include "PXWorldPreSimulationListener.h"
#include "Havok2012/Havok2012.h"
#include "Draw/DrawContext.h"

struct PXCharacterRigidBody;

struct PXContactRigidBodyInfo {
    Havok::hkpRigidBody* m_pHkpRigidBody;
    byte field1_0x8;
    byte field2_0x9;
    short field3_0xa;
};

struct PXCharacterControlBase : public PXEntity, public PXWorldPreSimulationListener, public PXWorldPostSimulationListener
{
    dl_uint64 field3_0x30;
    dl_uint64 field4_0x38;
    dl_uint field5_0x40;
    dl_float32 field6_0x44;
    dl_float32 field7_0x48;
    dl_float32 field8_0x4c;
    dl_float32 field9_0x50;
    dl_float32 field10_0x54;
    dl_float32 field11_0x58;
    dl_float32 field12_0x5c;
    dl_int field13_0x60;
    dl_uchar field14_0x64;
    dl_uchar field15_0x65;
    dl_uchar field16_0x66;
    dl_uchar field17_0x67;
    dl_uchar field18_0x68;
    dl_uchar field19_0x69;
    dl_uchar field20_0x6a;
    dl_uchar field21_0x6b;
    dl_uchar field22_0x6c;
    dl_uchar field23_0x6d;
    dl_uchar field24_0x6e;
    dl_uchar field25_0x6f;
    DLMT::DL_VECTOR4 field26_0x70;
    DLMT::DL_VECTOR4 field27_0x80;
    DLMT::DL_VECTOR4 field28_0x90;
    DLMT::DL_VECTOR4 field29_0xa0;
    DLMT::DL_VECTOR4 field30_0xb0;
    DLMT::DL_VECTOR4 field31_0xc0;
    DLMT::DL_VECTOR4 field32_0xd0;
    DLMT::DL_VECTOR4 field33_0xe0;
    DLMT::DL_VECTOR4 field34_0xf0;
    PXContactRigidBodyInfo field35_0x100;
    PXContactRigidBodyInfo m_groundCollisionInfo;
    dl_uint field37_0x120;
    dl_uchar field38_0x124;
    dl_uchar field39_0x125;
    dl_uchar field40_0x126;
    dl_uchar field41_0x127;
    dl_uchar field42_0x128;
    dl_uchar field43_0x129;
    dl_uchar field44_0x12a;
    dl_uchar field45_0x12b;
    dl_uchar field46_0x12c;
    dl_uchar field47_0x12d;
    dl_uchar field48_0x12e;
    dl_uchar field49_0x12f;
    DLMT::DL_VECTOR4 field50_0x130;
    dl_uint64 field51_0x140;
    dl_pointer field52_0x148;
    dl_uint field53_0x150;
    dl_uchar field54_0x154;
    dl_uchar field55_0x155;
    dl_uchar field56_0x156;
    dl_uchar field57_0x157;
    dl_uchar field58_0x158;
    dl_uchar field59_0x159;
    dl_uchar field60_0x15a;
    dl_uchar field61_0x15b;
    dl_uchar field62_0x15c;
    dl_uchar field63_0x15d;
    dl_uchar field64_0x15e;
    dl_uchar field65_0x15f;
    dl_pointer field66_0x160;
    dl_uchar field67_0x168;
    dl_uchar field68_0x169;
    dl_uchar field69_0x16a;
    dl_uchar field70_0x16b;
    dl_uchar field71_0x16c;
    dl_uchar field72_0x16d;
    dl_uchar field73_0x16e;
    dl_uchar field74_0x16f;
    dl_float32 field75_0x170;
    dl_float32 field76_0x174;
    dl_float32 field77_0x178;
    dl_float32 field78_0x17c;
    dl_float32 field79_0x180;
    dl_float32 field80_0x184;
    dl_float32 field81_0x188;
    dl_float32 field82_0x18c;
    dl_int field83_0x190;
    dl_int field84_0x194;
    dl_int field85_0x198;
    dl_uchar field86_0x19c;
    dl_uchar field87_0x19d;
    dl_uchar field88_0x19e;
    dl_uchar field89_0x19f;
    dl_uint64 field90_0x1a0;
    dl_uint64 field91_0x1a8;
    dl_float32 field92_0x1b0;
    dl_float32 field93_0x1b4;
    dl_float32 field94_0x1b8;
    dl_float32 field95_0x1bc;
    dl_int16 field96_0x1c0;
    dl_uchar field97_0x1c2;
    dl_uchar field98_0x1c3;
};

struct PXCharacterRigidBodyContactListener : public Havok::hkpContactListener {
    PXCharacterRigidBody* m_pOwnerRigidBody;
    dl_pointer field2_0x10;
    dl_pointer field3_0x18;
    dl_pointer field4_0x20;
    dl_pointer field5_0x28;
    dl_pointer field6_0x30;
    dl_pointer field7_0x38;
    dl_pointer field8_0x40;
    dl_pointer field9_0x48;
};

struct PXCharacterRigidBody : public PXCharacterControlBase {
    dl_uchar field5_0x1c8;
    dl_uchar field6_0x1c9;
    dl_uchar field7_0x1ca;
    dl_uchar field8_0x1cb;
    dl_uchar field9_0x1cc;
    dl_uchar field10_0x1cd;
    dl_uchar field11_0x1ce;
    dl_uchar field12_0x1cf;
    Havok::hkpCharacterRigidBody* m_pHkpCharacterRigidBody;
    PXUserValue m_userValue;
    PXCharacterRigidBodyContactListener m_contactListener;
    dl_uchar field16_0x238;
    dl_uchar field17_0x239;
    dl_uchar field18_0x23a;
    dl_uchar field19_0x23b;
    dl_uchar field20_0x23c;
    dl_uchar field21_0x23d;
    dl_uchar field22_0x23e;
    dl_uchar field23_0x23f;

    void Draw(IDrawContext* pDrawContext, bool wireframe, bool showAabb, DLMT::DL_VECTOR4 color);
};