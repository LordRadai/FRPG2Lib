#pragma once
#include "PXRigidBody.h"

namespace DLGR
{
	class IDrawContext;
}

struct CharacterRigidBody {
	void** _vfptr;
	dl_pointer m_pCharacter;
	dl_int field2_0x10;
	dl_int field3_0x14;
	dl_int field4_0x18;
	dl_int field5_0x1c;
	dl_int field6_0x20;
	dl_int field7_0x24;
	dl_int field8_0x28;
	dl_int field9_0x2c;
	dl_int field10_0x30;
	dl_int field11_0x34;
	dl_int field12_0x38;
	dl_int field13_0x3c;
	dl_int field14_0x40;
	dl_int field15_0x44;
	dl_int field16_0x48;
	dl_int field17_0x4c;
	dl_int field18_0x50;
	dl_int field19_0x54;
	dl_int field20_0x58;
	dl_int field21_0x5c;
	PXKeyframedRigidBody m_keyFramedRigidBodies[11];
	dl_bool m_useKeyframedModelRigidBody;
	PXKeyframedModelRigidBody m_keyframeModelRigidBody;
	dl_pointer m_pVar6e0;
	dl_uchar field40_0x6e8;
	dl_uchar field41_0x6e9;
	dl_uchar field42_0x6ea;
	dl_uchar field43_0x6eb;
	dl_uchar field44_0x6ec;
	dl_uchar field45_0x6ed;
	dl_uchar field46_0x6ee;
	dl_uchar field47_0x6ef;

	void Draw(IDrawContext* pDrawContext, DLMT::DL_VECTOR4 color);
};
