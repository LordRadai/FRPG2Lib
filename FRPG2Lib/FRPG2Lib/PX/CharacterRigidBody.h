#pragma once
#include "PXRigidBody.h"

namespace DLGR
{
	class IDrawContext;
}

struct CharacterRigidBody {
	void** _vfptr;
	void* m_pCharacter;
	int field2_0x10;
	int field3_0x14;
	int field4_0x18;
	int field5_0x1c;
	int field6_0x20;
	int field7_0x24;
	int field8_0x28;
	int field9_0x2c;
	int field10_0x30;
	int field11_0x34;
	int field12_0x38;
	int field13_0x3c;
	int field14_0x40;
	int field15_0x44;
	int field16_0x48;
	int field17_0x4c;
	int field18_0x50;
	int field19_0x54;
	int field20_0x58;
	int field21_0x5c;
	PXKeyframedRigidBody m_keyFramedRigidBodies[11];
	bool m_useKeyframedModelRigidBody;
	PXKeyframedModelRigidBody m_keyframeModelRigidBody;
	void* pad;
	BYTE field40_0x6e8;
	BYTE field41_0x6e9;
	BYTE field42_0x6ea;
	BYTE field43_0x6eb;
	BYTE field44_0x6ec;
	BYTE field45_0x6ed;
	BYTE field46_0x6ee;
	BYTE field47_0x6ef;

	void Draw(IDrawContext* pDrawContext, Vector4 color);
};
