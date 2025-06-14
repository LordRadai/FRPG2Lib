#include "FRPG2Globals.h"
#include "PXRigidBody.h"
#include "Draw/DebugDraw/HavokDebugDraw.h"
#include "Draw/DrawContext.h"

void PXRigidBody::Draw(IDrawContext* pDrawContext, dl_bool wireframe, dl_bool showAabb, DLMT::DL_VECTOR4 color)
{
	if (this->m_pHkpRigidBody)
		HavokDebugDraw::DrawShape(pDrawContext, this->m_pHkpRigidBody->getCollidableShape(), this->m_pHkpRigidBody->getWorldPosition(), wireframe, showAabb, color);
}

void PXKeyframedRigidBody::Draw(IDrawContext* pDrawContext, dl_bool wireframe, dl_bool showAabb, DLMT::DL_VECTOR4 color)
{
	PXRigidBody::Draw(pDrawContext, wireframe, showAabb, color);
}

void PXKeyframedModelRigidBody::Draw(IDrawContext* pDrawContext, dl_bool wireframe, dl_bool showAabb, DLMT::DL_VECTOR4 color)
{
	for (size_t i = 0; i < this->m_rigidBodyList.size(); i++)
	{
		Havok::hkpRigidBody* pRigidBody = this->m_rigidBodyList[i];

		if (pRigidBody && (pRigidBody->_vfptr == (void**)(MODULE_ADDR + 0x1126578)))
			HavokDebugDraw::DrawShape(pDrawContext, pRigidBody->getCollidableShape(), pRigidBody->getWorldPosition(), wireframe, showAabb, color);
	}
}