#pragma once

// Convex shapes
#include "Collide/Shapes/Convex/hkpBoxShape.h"
#include "Collide/Shapes/Convex/hkpCapsuleShape.h"
#include "Collide/Shapes/Convex/hkpConvexTransformShape.h"
#include "Collide/Shapes/Convex/hkpConvexTranslateShape.h"
#include "Collide/Shapes/Convex/hkpConvexVerticesShape.h"
#include "Collide/Shapes/Convex/hkpCylinderShape.h"
#include "Collide/Shapes/Convex/hkpSphereShape.h"

// Compound shapes
#include "Collide/Shapes/Compound/Collection/hkpExtendedMeshShape.h"
#include "Collide/Shapes/Compound/Collection/hkpListShape.h"
#include "Collide/Shapes/Compound/Collection/hkpStorageExtendedMesh.h"
#include "Collide/Shapes/Compound/Tree/hkpMoppBvTreeShape.h"
#include "Collide/Shapes/Custom/CustomParamStorageExtendedMeshShape.h"

// Dynamics
#include "Dynamics/Entity/hkpRigidBody.h"
#include "Dynamics/Collide/hkpContactListener.h"

#include "Utilities/CharacterControl/CharacterRigidBody/hkpCharacterRigidBody.h"