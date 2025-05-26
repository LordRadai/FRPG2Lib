#include "PXCharacterControl.h"
#include "Draw/DebugDraw/HavokDebugDraw.h"

void PXCharacterRigidBody::Draw(IDrawContext* pDrawContext, dl_bool wireframe, dl_bool showAabb, DLMT::DL_VECTOR4 color)
{
	if (this->m_pHkpCharacterRigidBody == nullptr)
		return;

	if (this->m_pHkpCharacterRigidBody->m_character == nullptr)
		return;

	HavokDebugDraw::DrawShape(pDrawContext, this->m_pHkpCharacterRigidBody->m_character->getCollidableShape(), this->m_pHkpCharacterRigidBody->m_character->getWorldPosition(), wireframe, showAabb, color);
}