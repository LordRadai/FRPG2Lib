#pragma once
#include "hkpShapePhantom.h"

namespace Havok
{
    struct hkpSimpleShapePhantom : public hkpShapePhantom {
        hkArray<void*> m_collisionDetails;
        bool m_orderDirty;

		hkpShape* getCollidableShape() const { return this->m_collidable.m_shape; }
		UINT getCollisionFilterInfo() const { return this->m_collidable.m_broadPhaseHandle.m_collisionFilterInfo; }
		Matrix* getWorldPosition() const { return static_cast<Matrix*>(this->m_collidable.m_motion); }
	};
}