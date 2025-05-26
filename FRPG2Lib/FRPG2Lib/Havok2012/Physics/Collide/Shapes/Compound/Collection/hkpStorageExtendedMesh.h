#pragma once
#include "hkpExtendedMeshShape.h"

namespace Havok
{
	struct hkpMeshMaterial
	{
		UINT m_filterInfo;
	};

	struct hkpNamedMeshMaterial : public hkpMeshMaterial
	{
		const char* m_name;
	};

	struct Material : public hkpMeshMaterial
	{
		hkHalf m_restitution;
		hkHalf m_friction;
		UINT64 m_userData;
	};

	struct MeshSubpartStorage : public hkReferencedObject
	{
		hkArray<hkVector4> m_vertices;
		hkArray<UINT8> m_indices8;
		hkArray<UINT16> m_indices16;
		hkArray<UINT32> m_indices32;
		hkArray<UINT8> m_materialIndices;
		hkArray<Material> m_materials;
		hkArray<hkpNamedMeshMaterial> m_namedMaterials;
		hkArray<UINT16> m_materialIndices16;
	};

	struct ShapeSubpartStorage : public hkReferencedObject
	{
		hkArray<UINT8> m_materialIndices;
		hkArray<Material> m_materials;
		hkArray<UINT16> m_materialIndices16;
	};

	struct hkpStorageExtendedMeshShape : public hkpExtendedMeshShape {
		hkArray<MeshSubpartStorage*> m_meshstorage;
		hkArray<ShapeSubpartStorage*> m_shapestorage;
	};
}