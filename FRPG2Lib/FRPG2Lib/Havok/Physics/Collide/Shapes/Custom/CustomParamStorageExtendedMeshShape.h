#pragma once
#include "../../../../Common/hkBaseDefs.h"
#include "../../../../Common/hkReferencedObject.h"
#include "../Compound/Collection/hkpStorageExtendedMesh.h"
#include "CustomParam.h"

namespace Havok
{
	struct CustomParamStorageExtendedMeshShape : public hkpStorageExtendedMeshShape
	{
		hkArray<CustomMeshParameter> m_params;
	};
}