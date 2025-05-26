#pragma once
#include "hkpEntity.h"

namespace Havok
{
	struct hkpRigidBody : public hkpEntity {
		hkpShape* getCollidableShape() const { return this->m_collidable.m_shape; }
		CollisionGroup getCollisionFilterGroup() const { return static_cast<CollisionGroup>(this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo & 0b111111); }
		short getCollisionMask() const { return (this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo & 0b11111000000); }
		short getCollisionFilterLayer() const { return this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo & 0xFFFF0000; }

		Matrix getWorldPosition() const 
		{
			hkTransform* transform = static_cast<hkTransform*>(this->m_collidable.m_motion);

			return Matrix(Vector3(&transform->m_rotation[0]), Vector3(&transform->m_rotation[4]), Vector3(&transform->m_rotation[8])) * Matrix::CreateTranslation(Vector3(transform->m_translation));
		}

		UINT getVdbColor() { return static_cast<UINT>(this->getPropertyValue(4400)); }
	};
}