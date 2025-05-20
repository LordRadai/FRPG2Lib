#include "HavokDebugDraw.h"

using namespace DirectX;

void HavokDebugDraw::DrawShape(IDrawContext* pDrawContext, Havok::hkpShape* pShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color)
{
	if (pShape == nullptr)
		return;

	switch (pShape->m_type)
	{
	case Havok::ShapeType::SPHERE:
		HavokDebugDraw::DrawSphereShape(pDrawContext, static_cast<Havok::hkpSphereShape*>(pShape), transform, wireframe, color);
		break;
	case Havok::ShapeType::BOX:
		HavokDebugDraw::DrawBoxShape(pDrawContext, static_cast<Havok::hkpBoxShape*>(pShape), transform, wireframe, color);
		break;
	case Havok::ShapeType::CAPSULE:
		HavokDebugDraw::DrawCapsuleShape(pDrawContext, static_cast<Havok::hkpCapsuleShape*>(pShape), transform, wireframe, color);
		break;
	case Havok::ShapeType::CONVEX_VERTICES:
		HavokDebugDraw::DrawConvexVerticesShape(pDrawContext, static_cast<Havok::hkpConvexVerticesShape*>(pShape), transform, wireframe, showAabb, color);
		break;
	case Havok::ShapeType::CYLINDER:
		HavokDebugDraw::DrawCylinderShape(pDrawContext, static_cast<Havok::hkpCylinderShape*>(pShape), transform, wireframe, color);
		break;
	case Havok::ShapeType::CONVEX_TRANSLATE:
		HavokDebugDraw::DrawConvexTranslateShape(pDrawContext, static_cast<Havok::hkpConvexTranslateShape*>(pShape), transform, wireframe, showAabb, color);
		break;
	case Havok::ShapeType::EXTENDED_MESH:
		HavokDebugDraw::DrawStorageExtendedMeshShape(pDrawContext, static_cast<Havok::hkpStorageExtendedMeshShape*>(pShape), transform, wireframe, showAabb, color);
		break;
	case Havok::ShapeType::MOPP:
		HavokDebugDraw::DrawMoppBvTreeShape(pDrawContext, static_cast<Havok::hkpMoppBvTreeShape*>(pShape), transform, wireframe, showAabb, color);
		break;
	case Havok::ShapeType::LIST:
		HavokDebugDraw::DrawListShape(pDrawContext, static_cast<Havok::hkpListShape*>(pShape), transform, wireframe, showAabb, color);
		break;
	default:
		Vector3 position = transform.Translation();

		DebugDraw::DrawLine(pDrawContext, position, position + Vector3(0, 1, 0), Vector4(DirectX::Colors::Purple));
		break;
	}
}

void HavokDebugDraw::DrawSphereShape(IDrawContext* pDrawContext, Havok::hkpSphereShape* pSphere, Matrix transform, bool wireframe, Vector4 color)
{
	if (pSphere == nullptr)
		return;

	DebugDraw::DrawSphere(pDrawContext, transform, pSphere->m_radius, wireframe, color);
}

void HavokDebugDraw::DrawCapsuleShape(IDrawContext* pDrawContext, Havok::hkpCapsuleShape* pCapsule, Matrix transform, bool wireframe, Vector4 color)
{
	if (pCapsule == nullptr)
		return;

	DebugDraw::DrawCapsule(pDrawContext, transform, Vector3(pCapsule->m_vertexA), Vector3(pCapsule->m_vertexB), pCapsule->m_radius, wireframe, color);
}

void HavokDebugDraw::DrawCylinderShape(IDrawContext* pDrawContext, Havok::hkpCylinderShape* pCylinderShape, Matrix transform, bool wireframe, Vector4 color)
{
	if (pCylinderShape == nullptr)
		return;

	DebugDraw::DrawCylinder(pDrawContext, transform, Vector3(pCylinderShape->m_vertexA), Vector3(pCylinderShape->m_vertexB), pCylinderShape->m_cylRadius, wireframe, color);
}

void HavokDebugDraw::DrawBoxShape(IDrawContext* pDrawContext, Havok::hkpBoxShape* pBox, Matrix transform, bool wireframe, Vector4 color)
{
	if (pBox == nullptr)
		return;

	DebugDraw::DrawBox(pDrawContext, transform, Vector3(pBox->m_halfExtents), wireframe, color);
}

void HavokDebugDraw::DrawConvexTranslateShape(IDrawContext* pDrawContext, Havok::hkpConvexTranslateShape* pConvexTranslate, Matrix transform, bool wireframe, bool showAabb, Vector4 color)
{
	if (pConvexTranslate == nullptr)
		return;

	HavokDebugDraw::DrawShape(pDrawContext, pConvexTranslate->m_childShape.m_childShape, Matrix::CreateTranslation(Vector3(pConvexTranslate->m_translation)) * transform, wireframe, showAabb, color);
}

void HavokDebugDraw::DrawConvexVerticesShape(IDrawContext* pDrawContext, Havok::hkpConvexVerticesShape* pConvexVerticesShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color)
{
	if (pConvexVerticesShape == nullptr)
		return;

	Vector4* vertex_list = new Vector4[pConvexVerticesShape->m_numVertices];

	pConvexVerticesShape->getOriginalVertices(vertex_list);

	quickhull::QuickHull<float> qh;

	std::vector<quickhull::Vector3<float>> vertices_v3;
	vertices_v3.reserve(pConvexVerticesShape->m_numVertices);

	for (size_t i = 0; i < pConvexVerticesShape->m_numVertices; i++)
		vertices_v3.push_back(quickhull::Vector3(vertex_list[i].x, vertex_list[i].y, vertex_list[i].z));

	auto hull = qh.getConvexHull(vertices_v3, pConvexVerticesShape->m_numVertices, true, false);
	const auto& indexBuffer = hull.getIndexBuffer();
	const auto& vertexBuffer = hull.getVertexBuffer();

	if (showAabb)
		DebugDraw::DrawBoundingBox(pDrawContext, transform, Vector3(pConvexVerticesShape->m_aabbCenter), Vector3(pConvexVerticesShape->m_aabbHalfExtents));

	std::vector<Vector3> vertices;
	vertices.reserve(vertexBuffer.size());

	for (size_t i = 0; i < vertexBuffer.size(); i++)
		vertices.push_back(Vector3(vertexBuffer[i].x, vertexBuffer[i].y, vertexBuffer[i].z));

	std::vector<UINT> indicesWireframe;
	indicesWireframe.reserve(indexBuffer.size() * 2);

	for (size_t i = 0; i < indexBuffer.size(); i += 3)
	{
		indicesWireframe.push_back(indexBuffer[i]);
		indicesWireframe.push_back(indexBuffer[i + 1]);

		indicesWireframe.push_back(indexBuffer[i + 1]);
		indicesWireframe.push_back(indexBuffer[i + 2]);

		indicesWireframe.push_back(indexBuffer[i + 2]);
		indicesWireframe.push_back(indexBuffer[i]);
	}

	std::vector<UINT> indices;
	indices.reserve(indexBuffer.size());

	for (size_t i = 0; i < indexBuffer.size(); i++)
		indices.push_back(indexBuffer[i]);

	DebugDraw::DrawMesh(pDrawContext, transform, vertices, indices, indicesWireframe, wireframe, color);

	delete[] vertex_list;
}

void HavokDebugDraw::DrawStorageExtendedMeshShape(IDrawContext* pDrawContext, Havok::hkpStorageExtendedMeshShape* pStorageExtendedMeshShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color)
{
	if (pStorageExtendedMeshShape == nullptr)
		return;

    if (showAabb)
		DebugDraw::DrawBoundingBox(pDrawContext, transform, Vector3(pStorageExtendedMeshShape->m_aabbCenter), Vector3(pStorageExtendedMeshShape->m_aabbHalfExtents));

    // We're only interested in the mesh storage part of this class
    if (pStorageExtendedMeshShape->m_meshstorage.size() > 0)
    {
        for (int meshIdx = 0; meshIdx < pStorageExtendedMeshShape->m_meshstorage.size(); meshIdx++)
        {
            Havok::MeshSubpartStorage* meshSubpart = pStorageExtendedMeshShape->m_meshstorage.at(meshIdx);

            hkVector4* vertex_list = meshSubpart->m_vertices.data();
            int vertex_count = meshSubpart->m_vertices.size();

            std::vector<Vector3> vertices;
            vertices.reserve(vertex_count);

            for (int vertIdx = 0; vertIdx < vertex_count; vertIdx++)
                vertices.push_back(Vector3(vertex_list[vertIdx]));

            if (meshSubpart->m_indices8.size())
            {
                int index_count = meshSubpart->m_indices8.size();
                UINT8* index_list = meshSubpart->m_indices8.data();

                std::vector<UINT> indices;
                indices.reserve(index_count);

                std::vector<UINT> indicesWireframe;
                indicesWireframe.reserve(index_count * 2);

                for (int indicesIdx = 0; indicesIdx < index_count; indicesIdx += 4)
                {
                    UINT16 idx_1 = index_list[indicesIdx];
                    UINT16 idx_2 = index_list[indicesIdx + 1];
                    UINT16 idx_3 = index_list[indicesIdx + 2];

                    if ((idx_1 < vertex_count) && (idx_2 < vertex_count) && (idx_3 < vertex_count))
                    {
                        indices.push_back(idx_1);
                        indices.push_back(idx_2);
                        indices.push_back(idx_3);

                        indicesWireframe.push_back(idx_1);
                        indicesWireframe.push_back(idx_2);

                        indicesWireframe.push_back(idx_2);
                        indicesWireframe.push_back(idx_3);

                        indicesWireframe.push_back(idx_3);
                        indicesWireframe.push_back(idx_1);
                    }
                }

				DebugDraw::DrawMesh(pDrawContext, transform, vertices, indices, indicesWireframe, wireframe, color);
            }

            if (meshSubpart->m_indices16.size())
            {
                int index_count = meshSubpart->m_indices16.size();
                UINT16* index_list = meshSubpart->m_indices16.data();

                std::vector<UINT> indices;
                indices.reserve(index_count);

                std::vector<UINT> indicesWireframe;
                indicesWireframe.reserve(index_count * 2);

                for (int indicesIdx = 0; indicesIdx < index_count; indicesIdx += 4)
                {
                    UINT16 idx_1 = index_list[indicesIdx];
                    UINT16 idx_2 = index_list[indicesIdx + 1];
                    UINT16 idx_3 = index_list[indicesIdx + 2];

                    if ((idx_1 < vertex_count) && (idx_2 < vertex_count) && (idx_3 < vertex_count))
                    {
                        indices.push_back(idx_1);
                        indices.push_back(idx_2);
                        indices.push_back(idx_3);

                        indicesWireframe.push_back(idx_1);
                        indicesWireframe.push_back(idx_2);

                        indicesWireframe.push_back(idx_2);
                        indicesWireframe.push_back(idx_3);

                        indicesWireframe.push_back(idx_3);
                        indicesWireframe.push_back(idx_1);
                    }
                }

                DebugDraw::DrawMesh(pDrawContext, transform, vertices, indices, indicesWireframe, wireframe, color);
            }

            if (meshSubpart->m_indices32.size())
            {
                int index_count = meshSubpart->m_indices32.size();
                UINT* index_list = meshSubpart->m_indices32.data();

                std::vector<UINT> indices;
                indices.reserve(index_count);

                std::vector<UINT> indicesWireframe;
                indicesWireframe.reserve(index_count * 2);

                for (int indicesIdx = 0; indicesIdx < index_count; indicesIdx += 4)
                {
                    int idx_1 = index_list[indicesIdx];
                    int idx_2 = index_list[indicesIdx + 1];
                    int idx_3 = index_list[indicesIdx + 2];

                    if ((idx_1 < vertex_count) && (idx_2 < vertex_count) && (idx_3 < vertex_count))
                    {
                        indices.push_back(idx_1);
                        indices.push_back(idx_2);
                        indices.push_back(idx_3);

                        indicesWireframe.push_back(idx_1);
                        indicesWireframe.push_back(idx_2);

                        indicesWireframe.push_back(idx_2);
                        indicesWireframe.push_back(idx_3);

                        indicesWireframe.push_back(idx_3);
                        indicesWireframe.push_back(idx_1);
                    }
                }

				DebugDraw::DrawMesh(pDrawContext, transform, vertices, indices, indicesWireframe, wireframe, color);
            }
        }
    }
}

void HavokDebugDraw::DrawMoppBvTreeShape(IDrawContext* pDrawContext, Havok::hkpMoppBvTreeShape* pMoppBvTreeShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color)
{
	if (pMoppBvTreeShape == nullptr)
		return;

	HavokDebugDraw::DrawShape(pDrawContext, pMoppBvTreeShape->m_child.m_childShape, transform, wireframe, showAabb, color);
}

void HavokDebugDraw::DrawListShape(IDrawContext* pDrawContext, Havok::hkpListShape* pListShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color)
{
	if (pListShape == nullptr)
		return;

	for (uint32_t i = 0; i < pListShape->m_childInfo.size(); i++)
		HavokDebugDraw::DrawShape(pDrawContext, pListShape->m_childInfo.at(i).m_shape, transform, wireframe, showAabb, color);
}