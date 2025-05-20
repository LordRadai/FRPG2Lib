#include "CharacterRigidBody.h"
#include "Draw/DrawContext.h"
#include "FRPG2Globals.h"

void CharacterRigidBody::Draw(IDrawContext* pDrawContext, Vector4 color)
{
	if (!this->m_useKeyframedModelRigidBody)
	{
		for (size_t i = 0; i < 11; i++)
		{
			PXKeyframedRigidBody pxRigidBody = this->m_keyFramedRigidBodies[i];

			if (pxRigidBody.m_pHkpRigidBody && (pxRigidBody.m_pHkpRigidBody->_vfptr == (void**)((UINT64)g_moduleAddr + 0x1126578)))
				pxRigidBody.Draw(pDrawContext, true, false, color);
		}
	}
	else
	{
		this->m_keyframeModelRigidBody.Draw(pDrawContext, true, false, color);
	}
}