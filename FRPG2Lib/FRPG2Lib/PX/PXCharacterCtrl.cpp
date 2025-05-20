#include "PXCharacterControl.h"
#include "Draw/DebugDraw/HavokDebugDraw.h"

void PXCharacterRigidBody::Draw(IDrawContext* pDrawContext, bool wireframe, bool showAabb, Vector4 color)
{
	if (this->m_pHkpCharacterRigidBody == nullptr)
		return;

	if (this->m_pHkpCharacterRigidBody->m_character == nullptr)
		return;

	HavokDebugDraw::DrawShape(pDrawContext, this->m_pHkpCharacterRigidBody->m_character->getCollidableShape(), this->m_pHkpCharacterRigidBody->m_character->getWorldPosition(), wireframe, showAabb, color);
}