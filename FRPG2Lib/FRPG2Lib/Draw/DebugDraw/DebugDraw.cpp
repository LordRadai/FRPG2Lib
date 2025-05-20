#include "DebugDraw.h"
#include "FRPG2Globals.h"
#include "FRPG2Call.h"
#include "DrawParameters.h"
#include <vector>

#define SPHERE_STACKS 4
#define SPHERE_SLICES 12
#define ARC_SLICES 100
#define ARC_TIRET_FREQ 4
#define CAPSULE_SEG 12

namespace DebugDraw
{
	typedef void(_fastcall* oDebugDrawReferenceFrame)(DebugDrawParameters* pDrawInfo, DLMT::DL_MATRIX44* pTransform, dl_float32 axisLenght, dl_uint color);
	typedef void(_fastcall* oDebugDrawGrid)(DebugDrawParameters* pDrawInfo, DLMT::DL_MATRIX44* pTransform, dl_uint numDivisions, dl_float32 size, dl_uint color);
    typedef void(_fastcall* oDebugDrawOrientedBoundingBox)(DebugDrawParameters* pDrawInfo, DLMT::DL_MATRIX44* pTransform, DLMT::DL_VECTOR4* pHalfExtents, dl_uint color, dl_bool param_5);

    void DrawIndexedTest(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR4 color)
    {
		DebugDrawParameters drawInfo(DrawContext);
		drawInfo.ApplyTransform(&transform);

		DLGR::DLVertexPositionColor points[4];
		points[0] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3::Zero, color);
		points[1] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3::UnitX, color);
        points[2] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3::UnitY, color);
        points[3] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3::UnitZ, color);

        std::vector<uint16_t> indices;
        indices.push_back(0);
        indices.push_back(1);
        indices.push_back(0);
        indices.push_back(2);
        indices.push_back(0);
        indices.push_back(3);

		DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_LINELIST, 0, 4, indices.size(), indices.data(), DLGR::DLINDEXFMT_U16, points, sizeof(DLGR::DLVertexPositionColor));
    }

	void DrawLine(IDrawContext* DrawContext, DLMT::DL_VECTOR3 start, DLMT::DL_VECTOR3 end, DLMT::DL_VECTOR4 color)
	{
		DebugDrawParameters drawInfo(DrawContext);

		DLGR::DLVertexPositionColor points[2];
		points[0] = DLGR::DLVertexPositionColor(start, color);
		points[1] = DLGR::DLVertexPositionColor(end, color);

		DrawContext->Draw(DLGR::DLPRIMTYPE_LINELIST, 2, points, sizeof(DLGR::DLVertexPositionColor));
	}

	void DrawReferenceFrame(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, dl_float32 axisLenght)
	{
        DebugDrawParameters drawInfo(DrawContext);
		FRPG2_CALL(oDebugDrawReferenceFrame, 0xb40830, &drawInfo, &transform, axisLenght, 0xffffffff);
	}

	void DrawGrid(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, dl_uint numDivisions, dl_float32 size, DLMT::DL_VECTOR4 color)
	{
		DebugDrawParameters drawInfo(DrawContext);
		FRPG2_CALL(oDebugDrawGrid, 0xb40a50, &drawInfo, &transform, numDivisions, size, DLMT::GetDLColor32(color));
	}

	void DrawCapsule(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 pointA, DLMT::DL_VECTOR3 pointB, dl_float32 radius, dl_bool wireframe, DLMT::DL_VECTOR4 color)
	{
        const int numHeightSegments = 3;
        const int numSlices = SPHERE_SLICES;
        const int numStacks = SPHERE_STACKS;
        const dl_float32 stackAngleStep = DirectX::XM_PIDIV2 / numStacks;
        const dl_float32 sliceAngleStep = DirectX::XM_2PI / numSlices;

        const int numHemisphereVertices = numSlices * numStacks + 1;
        const int numVertices = 2 * numHemisphereVertices + numHeightSegments * numSlices;

        DebugDrawParameters drawInfo(DrawContext);
        drawInfo.ApplyTransform(&transform);

        DLMT::DL_VECTOR4 color_f32 = color;

        // Calculate vertex positions for the capsule
        DLGR::DLVertexPositionColor top_vertex;
        DLGR::DLVertexPositionColor bot_vertex;
        DLGR::DLVertexPositionColor top_vertices[numStacks][numSlices];
        DLGR::DLVertexPositionColor bot_vertices[numStacks][numSlices];
        DLGR::DLVertexPositionColor mid_vertices[numSlices];

        std::vector<DLGR::DLVertexPositionColor> vertices;
        vertices.reserve(numVertices);

        if (!wireframe)
            color_f32 = DirectX::Colors::Black;

        DLMT::DL_VECTOR3 center_bot = pointA;
        DLMT::DL_VECTOR3 center_top = pointB;

        if (center_bot.z > center_top.z)
            std::swap(center_bot, center_top);

        DLMT::DL_MATRIX44 rotation = DLMT::GetRotationFrom2Vectors(center_top, center_bot);

        std::vector<DLMT::DL_VECTOR3> mid_sections;
        mid_sections.reserve(numHeightSegments);

        for (size_t i = 0; i < numHeightSegments; i++)
        {
            dl_float32 t = static_cast<dl_float32>(i + 1) / (numHeightSegments + 1);

            DLMT::DL_VECTOR3 center = center_bot * (1 - t) + center_top * t;

            mid_sections.push_back(center);
        }

        bot_vertex = DLGR::DLVertexPositionColor(center_bot + DLMT::DL_VECTOR3::Transform(DLMT::DL_VECTOR3(0, -radius, 0), rotation), color_f32);
        top_vertex = DLGR::DLVertexPositionColor(center_top + DLMT::DL_VECTOR3::Transform(DLMT::DL_VECTOR3(0, radius, 0), rotation), color_f32);

        vertices.push_back(top_vertex);

        // Top hemisphere
        for (int i = 0; i < numStacks; i++)
        {
            dl_float32 stackAngle = i * stackAngleStep;

            for (int j = 0; j < numSlices; j++)
            {
                dl_float32 sliceAngle = j * sliceAngleStep;

                dl_float32 x = radius * cosf(stackAngle) * cosf(sliceAngle);
                dl_float32 y = radius * sinf(stackAngle);
                dl_float32 z = radius * cosf(stackAngle) * sinf(sliceAngle);

				top_vertices[i][j] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3::Transform(DLMT::DL_VECTOR3(x, y, z), rotation) + center_top, color_f32);

                vertices.push_back(top_vertices[i][j]);
            }
        }

        // Mid circle
        for (size_t midSectonIdx = 0; midSectonIdx < numHeightSegments; midSectonIdx++)
        {
            DLMT::DL_VECTOR3 center = mid_sections[midSectonIdx];

            for (int j = 0; j < numSlices; j++)
            {
                dl_float32 sliceAngle = j * sliceAngleStep;

                dl_float32 x = radius * cosf(sliceAngle);
                dl_float32 y = 0;
                dl_float32 z = radius * sinf(sliceAngle);

				mid_vertices[j] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3::Transform(DLMT::DL_VECTOR3(x, y, z), rotation) + center, color_f32);

                vertices.push_back(mid_vertices[j]);
            }
        }

        // Bottom hemisphere
        for (int i = 0; i < numStacks; i++)
        {
            dl_float32 stackAngle = -(i * stackAngleStep);

            for (int j = 0; j < numSlices; j++)
            {
                dl_float32 sliceAngle = j * sliceAngleStep;

                dl_float32 x = radius * cosf(stackAngle) * cosf(sliceAngle);
                dl_float32 y = radius * sinf(stackAngle);
                dl_float32 z = radius * cosf(stackAngle) * sinf(sliceAngle);

				bot_vertices[i][j] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3::Transform(DLMT::DL_VECTOR3(x, y, z), rotation) + center_bot, color_f32);

                vertices.push_back(bot_vertices[i][j]);
            }
        }

        vertices.push_back(bot_vertex);

        std::vector<uint16_t> indices;

        const int topFirstIndex = 1;

        // Top hemisphere connection
        {
            const int firstIndex = topFirstIndex;

            // Slices connection
            for (size_t stackIdx = 0; stackIdx < numStacks; stackIdx++)
            {
                const int firstSliceIdx = stackIdx * numSlices + firstIndex;

                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    indices.push_back(firstSliceIdx + sliceIdx);

                    if (sliceIdx + 1 < numSlices)
                        indices.push_back(firstSliceIdx + sliceIdx + 1);
                    else
                        indices.push_back(firstSliceIdx);
                }
            }

            // Top vertex connection
            for (size_t stackIdx = 0; stackIdx < numSlices; stackIdx++)
            {
                indices.push_back(0);
                indices.push_back(numSlices * (numStacks - 1) + stackIdx + firstIndex);
            }

            // Stacks connection
            for (size_t stackIdx = 0; stackIdx < numStacks; stackIdx++)
            {
                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    if (stackIdx + 1 < numStacks)
                    {
                        indices.push_back(stackIdx * numSlices + sliceIdx + firstIndex);
                        indices.push_back((stackIdx + 1) * numSlices + sliceIdx + firstIndex);
                    }
                }
            }
        }

        const int bottomFirstIndex = numHemisphereVertices + numHeightSegments * numSlices;

        {
            const int firstIndex = bottomFirstIndex;

            // Slices connection
            for (size_t stackIdx = 0; stackIdx < numStacks; stackIdx++)
            {
                const int firstSliceIdx = stackIdx * numSlices + firstIndex;

                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    indices.push_back(firstSliceIdx + sliceIdx);

                    if (sliceIdx + 1 < numSlices)
                        indices.push_back(firstSliceIdx + sliceIdx + 1);
                    else
                        indices.push_back(firstSliceIdx);
                }
            }

            // Top vertex connection
            for (size_t stackIdx = 0; stackIdx < numSlices; stackIdx++)
            {
                indices.push_back(numVertices - 1);
                indices.push_back(numSlices * (numStacks - 1) + stackIdx + firstIndex);
            }

            // Stacks connection
            for (size_t stackIdx = 0; stackIdx < numStacks; stackIdx++)
            {
                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    if (stackIdx + 1 < numStacks)
                    {
                        indices.push_back(stackIdx * numSlices + sliceIdx + firstIndex);
                        indices.push_back((stackIdx + 1) * numSlices + sliceIdx + firstIndex);
                    }
                }
            }
        }

        {
            for (size_t heightSegmentIdx = 0; heightSegmentIdx < numHeightSegments; heightSegmentIdx++)
            {
                const int firstIndex = numHemisphereVertices + heightSegmentIdx * numSlices;

                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    indices.push_back(firstIndex + sliceIdx);

                    if (sliceIdx + 1 < numSlices)
                        indices.push_back(firstIndex + sliceIdx + 1);
                    else
                        indices.push_back(firstIndex);
                }
            }

            for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
            {
                indices.push_back(bottomFirstIndex + sliceIdx);
                indices.push_back(topFirstIndex + sliceIdx);
            }
        }

        DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_LINELIST, 0, vertices.size(), indices.size(), indices.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));

        if (!wireframe)
        {
            for (size_t i = 0; i < vertices.size(); i++)
                vertices[i].m_color = DLMT::DL_VECTOR4(color);

            std::vector<uint16_t> indices_fill;

            // Top hemisphere
            {
                const int firstVertex = topFirstIndex;

                for (size_t i = 0; i < numSlices; i++)
                {
                    indices_fill.push_back(0);
                    indices_fill.push_back(numSlices * (numStacks - 1) + i + firstVertex);

                    if (numSlices * (numStacks - 1) + i + 1 + firstVertex < numSlices * (numStacks - 1) + numSlices + firstVertex)
                        indices_fill.push_back(numSlices * (numStacks - 1) + i + 1 + firstVertex);
                    else
                        indices_fill.push_back(numSlices * (numStacks - 1) + 1 + firstVertex);
                }

                for (size_t i = 0; i < numStacks; i++)
                {
                    for (size_t j = 0; j < numSlices; j++)
                    {
                        if (i + 1 < numStacks)
                        {
                            indices_fill.push_back(i * numSlices + j + firstVertex);
                            indices_fill.push_back((i + 1) * numSlices + j + firstVertex);

                            if (i * numSlices + j + 1 + firstVertex < i * numSlices + numSlices + firstVertex)
                                indices_fill.push_back(i * numSlices + j + 1 + firstVertex);
                            else
                                indices_fill.push_back(i * numSlices + firstVertex);

                            indices_fill.push_back((i + 1) * numSlices + j + firstVertex);

                            if ((i + 1) * numSlices + j + 1 + firstVertex < (i + 1) * numSlices + numSlices + firstVertex)
                            {
                                indices_fill.push_back(i * numSlices + j + 1 + firstVertex);
                                indices_fill.push_back((i + 1) * numSlices + j + 1 + firstVertex);
                            }
                            else
                            {
                                indices_fill.push_back(i * numSlices + firstVertex);
                                indices_fill.push_back((i + 1) * numSlices + firstVertex);
                            }
                        }
                    }
                }
            }

            // Top - bottom connection
            for (size_t i = 0; i < numSlices; i++)
            {
                indices_fill.push_back(i + 1);
                indices_fill.push_back(i + numHemisphereVertices + numHeightSegments * numSlices);

                if (i + 2 < numSlices + 1)
                    indices_fill.push_back(i + 1 + numHemisphereVertices + numHeightSegments * numSlices);
                else
                    indices_fill.push_back(numHemisphereVertices + numHeightSegments * numSlices);

                indices_fill.push_back(i + 1);

                if (i + 2 < numSlices + 1)
                {
                    indices_fill.push_back(i + 2);
                    indices_fill.push_back(i + 1 + numHemisphereVertices + numHeightSegments * numSlices);
                }
                else
                {
                    indices_fill.push_back(1);
                    indices_fill.push_back(numHemisphereVertices + numHeightSegments * numSlices);
                }
            }

            // Bottom hemisphere
            {
                const int firstVertex = bottomFirstIndex;

                for (size_t i = 0; i < numSlices; i++)
                {
                    indices_fill.push_back(numVertices - 1);
                    indices_fill.push_back(numSlices * (numStacks - 1) + i + firstVertex);

                    if (numSlices * (numStacks - 1) + i + 1 + firstVertex < numSlices * (numStacks - 1) + numSlices + firstVertex)
                        indices_fill.push_back(numSlices * (numStacks - 1) + i + 1 + firstVertex);
                    else
                        indices_fill.push_back(numSlices * (numStacks - 1) + 1 + firstVertex);
                }

                for (size_t i = 0; i < numStacks; i++)
                {
                    for (size_t j = 0; j < numSlices; j++)
                    {
                        if (i + 1 < numStacks)
                        {
                            indices_fill.push_back(i * numSlices + j + firstVertex);
                            indices_fill.push_back((i + 1) * numSlices + j + firstVertex);

                            if (i * numSlices + j + 1 + firstVertex < i * numSlices + numSlices + firstVertex)
                                indices_fill.push_back(i * numSlices + j + 1 + firstVertex);
                            else
                                indices_fill.push_back(i * numSlices + firstVertex);

                            indices_fill.push_back((i + 1) * numSlices + j + firstVertex);

                            if ((i + 1) * numSlices + j + 1 + firstVertex < (i + 1) * numSlices + numSlices + firstVertex)
                            {
                                indices_fill.push_back(i * numSlices + j + 1 + firstVertex);
                                indices_fill.push_back((i + 1) * numSlices + j + 1 + firstVertex);
                            }
                            else
                            {
                                indices_fill.push_back(i * numSlices + firstVertex);
                                indices_fill.push_back((i + 1) * numSlices + firstVertex);
                            }
                        }
                    }
                }
            }

            DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_TRIANGLELIST, 0, vertices.size(), indices_fill.size(), indices_fill.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));
        }
	}

    void DrawSphere(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, dl_float32 radius, dl_bool wireframe, DLMT::DL_VECTOR4 color)
    {
        const int numSlices = SPHERE_SLICES;
        const int numStacks = SPHERE_STACKS;
        const dl_float32 stackAngleStep = DirectX::XM_PIDIV2 / numStacks;
        const dl_float32 sliceAngleStep = DirectX::XM_2PI / numSlices;

        const int numHemisphereVertices = numSlices * numStacks + 1;
        const int numVertices = 2 * numHemisphereVertices;

        DebugDrawParameters drawInfo(DrawContext);
        drawInfo.ApplyTransform(&transform);

        DLMT::DL_VECTOR4 color_f32 = color;

        // Calculate vertex positions for the capsule
        DLGR::DLVertexPositionColor top_vertex;
        DLGR::DLVertexPositionColor bot_vertex;
        DLGR::DLVertexPositionColor top_vertices[numStacks][numSlices];
        DLGR::DLVertexPositionColor bot_vertices[numStacks][numSlices];

        std::vector<DLGR::DLVertexPositionColor> vertices;
        vertices.reserve(numVertices);

        if (!wireframe)
            color_f32 = DirectX::Colors::Black;

        bot_vertex = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3(0, -radius, 0), color_f32);
        top_vertex = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3(0, radius, 0), color_f32);

        vertices.push_back(top_vertex);

        // Top hemisphere
        for (int i = 0; i < numStacks; i++)
        {
            dl_float32 stackAngle = i * stackAngleStep;

            for (int j = 0; j < numSlices; j++)
            {
                dl_float32 sliceAngle = j * sliceAngleStep;

                dl_float32 x = radius * cosf(stackAngle) * cosf(sliceAngle);
                dl_float32 y = radius * sinf(stackAngle);
                dl_float32 z = radius * cosf(stackAngle) * sinf(sliceAngle);

                top_vertices[i][j] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3(x, y, z), color_f32);

                vertices.push_back(top_vertices[i][j]);
            }
        }

        // Bottom hemisphere
        for (int i = 0; i < numStacks; i++)
        {
            dl_float32 stackAngle = -(i * stackAngleStep);

            for (int j = 0; j < numSlices; j++)
            {
                dl_float32 sliceAngle = j * sliceAngleStep;

                dl_float32 x = radius * cosf(stackAngle) * cosf(sliceAngle);
                dl_float32 y = radius * sinf(stackAngle);
                dl_float32 z = radius * cosf(stackAngle) * sinf(sliceAngle);

                bot_vertices[i][j] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3(x, y, z), color_f32);

                vertices.push_back(bot_vertices[i][j]);
            }
        }

        vertices.push_back(bot_vertex);

        std::vector<uint16_t> indices;

        const int topFirstIndex = 1;

        {
            const int firstIndex = topFirstIndex;

            // Slices connection
            for (size_t stackIdx = 0; stackIdx < numStacks; stackIdx++)
            {
                const int firstSliceIdx = stackIdx * numSlices + firstIndex;

                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    indices.push_back(firstSliceIdx + sliceIdx);

                    if (sliceIdx + 1 < numSlices)
                        indices.push_back(firstSliceIdx + sliceIdx + 1);
                    else
                        indices.push_back(firstSliceIdx);
                }
            }

            // Top vertex connection
            for (size_t stackIdx = 0; stackIdx < numSlices; stackIdx++)
            {
                indices.push_back(0);
                indices.push_back(numSlices * (numStacks - 1) + stackIdx + firstIndex);
            }

            // Stacks connection
            for (size_t stackIdx = 0; stackIdx < numStacks; stackIdx++)
            {
                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    if (stackIdx + 1 < numStacks)
                    {
                        indices.push_back(stackIdx * numSlices + sliceIdx + firstIndex);
                        indices.push_back((stackIdx + 1) * numSlices + sliceIdx + firstIndex);
                    }
                }
            }
        }

        const int bottomFirstIndex = numHemisphereVertices;

        {
            const int firstIndex = bottomFirstIndex;

            // Slices connection
            for (size_t stackIdx = 0; stackIdx < numStacks; stackIdx++)
            {
                const int firstSliceIdx = stackIdx * numSlices + firstIndex;

                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    indices.push_back(firstSliceIdx + sliceIdx);

                    if (sliceIdx + 1 < numSlices)
                        indices.push_back(firstSliceIdx + sliceIdx + 1);
                    else
                        indices.push_back(firstSliceIdx);
                }
            }

            // Top vertex connection
            for (size_t stackIdx = 0; stackIdx < numSlices; stackIdx++)
            {
                indices.push_back(numVertices - 1);
                indices.push_back(numSlices * (numStacks - 1) + stackIdx + firstIndex);
            }

            // Stacks connection
            for (size_t stackIdx = 0; stackIdx < numStacks; stackIdx++)
            {
                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    if (stackIdx + 1 < numStacks)
                    {
                        indices.push_back(stackIdx * numSlices + sliceIdx + firstIndex);
                        indices.push_back((stackIdx + 1) * numSlices + sliceIdx + firstIndex);
                    }
                }
            }
        }

        DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_LINELIST, 0, vertices.size(), indices.size(), indices.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));

        if (!wireframe)
        {
            for (size_t i = 0; i < vertices.size(); i++)
                vertices[i].m_color = DLMT::DL_VECTOR4(color);

            std::vector<uint16_t> indices_fill;

            // Top hemisphere
            {
                const int firstVertex = topFirstIndex;

                for (size_t i = 0; i < numSlices; i++)
                {
                    indices_fill.push_back(0);
                    indices_fill.push_back(numSlices * (numStacks - 1) + i + firstVertex);

                    if (numSlices * (numStacks - 1) + i + 1 + firstVertex < numSlices * (numStacks - 1) + numSlices + firstVertex)
                        indices_fill.push_back(numSlices * (numStacks - 1) + i + 1 + firstVertex);
                    else
                        indices_fill.push_back(numSlices * (numStacks - 1) + 1 + firstVertex);
                }

                for (size_t i = 0; i < numStacks; i++)
                {
                    for (size_t j = 0; j < numSlices; j++)
                    {
                        if (i + 1 < numStacks)
                        {
                            indices_fill.push_back(i * numSlices + j + firstVertex);
                            indices_fill.push_back((i + 1) * numSlices + j + firstVertex);

                            if (i * numSlices + j + 1 + firstVertex < i * numSlices + numSlices + firstVertex)
                                indices_fill.push_back(i * numSlices + j + 1 + firstVertex);
                            else
                                indices_fill.push_back(i * numSlices + firstVertex);

                            indices_fill.push_back((i + 1) * numSlices + j + firstVertex);

                            if ((i + 1) * numSlices + j + 1 + firstVertex < (i + 1) * numSlices + numSlices + firstVertex)
                            {
                                indices_fill.push_back(i * numSlices + j + 1 + firstVertex);
                                indices_fill.push_back((i + 1) * numSlices + j + 1 + firstVertex);
                            }
                            else
                            {
                                indices_fill.push_back(i * numSlices + firstVertex);
                                indices_fill.push_back((i + 1) * numSlices + firstVertex);
                            }
                        }
                    }
                }
            }

            // Top - bottom connection
            for (size_t i = 0; i < numSlices; i++)
            {
                indices_fill.push_back(i + 1);
                indices_fill.push_back(i + numHemisphereVertices);

                if (i + 2 < numSlices + 1)
                    indices_fill.push_back(i + 1 + numHemisphereVertices);
                else
                    indices_fill.push_back(numHemisphereVertices);

                indices_fill.push_back(i + 1);

                if (i + 2 < numSlices + 1)
                {
                    indices_fill.push_back(i + 2);
                    indices_fill.push_back(i + 1 + numHemisphereVertices);
                }
                else
                {
                    indices_fill.push_back(1);
                    indices_fill.push_back(numHemisphereVertices);
                }
            }

            // Bottom hemisphere
            {
                const int firstVertex = bottomFirstIndex;

                for (size_t i = 0; i < numSlices; i++)
                {
                    indices_fill.push_back(numVertices - 1);
                    indices_fill.push_back(numSlices * (numStacks - 1) + i + firstVertex);

                    if (numSlices * (numStacks - 1) + i + 1 + firstVertex < numSlices * (numStacks - 1) + numSlices + firstVertex)
                        indices_fill.push_back(numSlices * (numStacks - 1) + i + 1 + firstVertex);
                    else
                        indices_fill.push_back(numSlices * (numStacks - 1) + 1 + firstVertex);
                }

                for (size_t i = 0; i < numStacks; i++)
                {
                    for (size_t j = 0; j < numSlices; j++)
                    {
                        if (i + 1 < numStacks)
                        {
                            indices_fill.push_back(i * numSlices + j + firstVertex);
                            indices_fill.push_back((i + 1) * numSlices + j + firstVertex);

                            if (i * numSlices + j + 1 + firstVertex < i * numSlices + numSlices + firstVertex)
                                indices_fill.push_back(i * numSlices + j + 1 + firstVertex);
                            else
                                indices_fill.push_back(i * numSlices + firstVertex);

                            indices_fill.push_back((i + 1) * numSlices + j + firstVertex);

                            if ((i + 1) * numSlices + j + 1 + firstVertex < (i + 1) * numSlices + numSlices + firstVertex)
                            {
                                indices_fill.push_back(i * numSlices + j + 1 + firstVertex);
                                indices_fill.push_back((i + 1) * numSlices + j + 1 + firstVertex);
                            }
                            else
                            {
                                indices_fill.push_back(i * numSlices + firstVertex);
                                indices_fill.push_back((i + 1) * numSlices + firstVertex);
                            }
                        }
                    }
                }
            }

            DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_TRIANGLELIST, 0, vertices.size(), indices_fill.size(), indices_fill.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));
        }
    }

    void DrawCylinder(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 pointA, DLMT::DL_VECTOR3 pointB, dl_float32 radius, dl_bool wireframe, DLMT::DL_VECTOR4 color)
    {
        const int numSlices = SPHERE_SLICES;
        const dl_float32 sliceAngleStep = DirectX::XM_2PI / numSlices;

        const int numHemisphereVertices = numSlices + 1;
        const int numVertices = 2 * numHemisphereVertices;

        DebugDrawParameters drawInfo(DrawContext);
        drawInfo.ApplyTransform(&transform);

        // Calculate vertex positions for the capsule
        DLGR::DLVertexPositionColor top_vertex;
        DLGR::DLVertexPositionColor bot_vertex;
        DLGR::DLVertexPositionColor top_vertices[numSlices];
        DLGR::DLVertexPositionColor bot_vertices[numSlices];

        std::vector<DLGR::DLVertexPositionColor> vertices;
        vertices.reserve(numVertices);

        DLMT::DL_VECTOR4 v_color = color;

        if (!wireframe)
            v_color = DirectX::Colors::Black;

        DLMT::DL_VECTOR3 center_bot = pointA;
        DLMT::DL_VECTOR3 center_top = pointB;

        DLMT::DL_MATRIX44 rotation = DLMT::GetRotationFrom2Vectors(center_top, center_bot);

        bot_vertex = DLGR::DLVertexPositionColor(center_bot, v_color);
		top_vertex = DLGR::DLVertexPositionColor(center_top, v_color);       

        vertices.push_back(top_vertex);

        // Top hemisphere
        for (int i = 0; i < numSlices; i++)
        {
            dl_float32 sliceAngle = i * sliceAngleStep;

            dl_float32 x = radius * cosf(sliceAngle);
            dl_float32 y = 0;
            dl_float32 z = radius * sinf(sliceAngle);

			top_vertices[i] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3(x, y, z) + center_top, v_color);

            vertices.push_back(top_vertices[i]);
        }

        // Bottom hemisphere
        for (int i = 0; i < numSlices; i++)
        {
            dl_float32 sliceAngle = i * sliceAngleStep;

            dl_float32 x = radius * cosf(sliceAngle);
            dl_float32 y = 0;
            dl_float32 z = radius * sinf(sliceAngle);

			bot_vertices[i] = DLGR::DLVertexPositionColor(DLMT::DL_VECTOR3(x, y, z) + center_bot, v_color);

            vertices.push_back(bot_vertices[i]);
        }

        vertices.push_back(bot_vertex);

        std::vector<uint16_t> indices;

        const int topFirstIndex = 1;

        // Top hemisphere connection
        {
            const int firstIndex = topFirstIndex;

            // Slices connection
            const int firstSliceIdx = firstIndex;

            for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
            {
                indices.push_back(firstSliceIdx + sliceIdx);

                if (sliceIdx + 1 < numSlices)
                    indices.push_back(firstSliceIdx + sliceIdx + 1);
                else
                    indices.push_back(firstSliceIdx);
            }

            // Top vertex connection
            for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
            {
                indices.push_back(0);
                indices.push_back(sliceIdx + firstIndex);
            }
        }

        const int bottomFirstIndex = numHemisphereVertices;

        // Top - bottom connection
        {
            for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
            {
                indices.push_back(sliceIdx + topFirstIndex);
                indices.push_back(sliceIdx + bottomFirstIndex);
            }
        }

        {
            const int firstIndex = bottomFirstIndex;

            // Slices connection
            const int firstSliceIdx = firstIndex;

            for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
            {
                indices.push_back(firstSliceIdx + sliceIdx);

                if (sliceIdx + 1 < numSlices)
                    indices.push_back(firstSliceIdx + sliceIdx + 1);
                else
                    indices.push_back(firstSliceIdx);
            }

            // Top vertex connection
            for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
            {
                indices.push_back(numVertices - 1);
                indices.push_back(sliceIdx + firstIndex);
            }
        }

		DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_LINELIST, 0, vertices.size(), indices.size(), indices.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));

        if (!wireframe)
        {
            for (size_t i = 0; i < vertices.size(); i++)
                vertices[i].m_color = DLMT::DL_VECTOR4(color);

            std::vector<uint16_t> indices_fill;

            // Top hemisphere
            {
                const int firstVertex = topFirstIndex;

                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    indices_fill.push_back(0);
                    indices_fill.push_back(sliceIdx + firstVertex);

                    if (sliceIdx + 1 < numSlices)
                        indices_fill.push_back(sliceIdx + 1 + firstVertex);
                    else
                        indices_fill.push_back(firstVertex);
                }
            }

            // Top - bottom connection
            for (size_t i = 0; i < numSlices; i++)
            {
                indices_fill.push_back(i + 1);
                indices_fill.push_back(i + numHemisphereVertices);

                if (i + 2 < numSlices + 1)
                    indices_fill.push_back(i + 1 + numHemisphereVertices);
                else
                    indices_fill.push_back(numHemisphereVertices);

                indices_fill.push_back(i + 1);

                if (i + 2 < numSlices + 1)
                {
                    indices_fill.push_back(i + 2);
                    indices_fill.push_back(i + 1 + numHemisphereVertices);
                }
                else
                {
                    indices_fill.push_back(1);
                    indices_fill.push_back(numHemisphereVertices);
                }
            }

            // Bottom hemisphere
            {
                const int firstVertex = bottomFirstIndex;

                for (size_t sliceIdx = 0; sliceIdx < numSlices; sliceIdx++)
                {
                    indices_fill.push_back(numVertices - 1);
                    indices_fill.push_back(sliceIdx + firstVertex);

                    if (sliceIdx + 1 < numSlices)
                        indices_fill.push_back(sliceIdx + 1 + firstVertex);
                    else
                        indices_fill.push_back(firstVertex);
                }
            }

			DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_TRIANGLELIST, 0, vertices.size(), indices_fill.size(), indices_fill.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));
        }
    }

    void DrawBox(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 halfExtents, dl_bool wireframe, DLMT::DL_VECTOR4 color)
    {
        DebugDrawParameters drawInfo(DrawContext);
        drawInfo.ApplyTransform(&transform);

        DLMT::DL_VECTOR4 color_f32 = color;

        DLGR::DLVertexPositionColor b1, b2, b3, b4;
        DLGR::DLVertexPositionColor t1, t2, t3, t4;

        std::vector<DLGR::DLVertexPositionColor> vertices;
        vertices.reserve(8);

        b1.m_position.x = -halfExtents.x;
        b1.m_position.y = -halfExtents.y;
        b1.m_position.z = +halfExtents.z;

        b2.m_position.x = +halfExtents.x;
        b2.m_position.y = -halfExtents.y;
        b2.m_position.z = +halfExtents.z;

        b3.m_position.x = +halfExtents.x;
        b3.m_position.y = -halfExtents.y;
        b3.m_position.z = -halfExtents.z;

        b4.m_position.x = -halfExtents.x;
        b4.m_position.y = -halfExtents.y;
        b4.m_position.z = -halfExtents.z;

        t1.m_position.x = b1.m_position.x;
        t1.m_position.y = b1.m_position.y + 2 * halfExtents.y;
        t1.m_position.z = b1.m_position.z;

        t2.m_position.x = b2.m_position.x;
        t2.m_position.y = b2.m_position.y + 2 * halfExtents.y;
        t2.m_position.z = b2.m_position.z;

        t3.m_position.x = b3.m_position.x;
        t3.m_position.y = b3.m_position.y + 2 * halfExtents.y;
        t3.m_position.z = b3.m_position.z;

        t4.m_position.x = b4.m_position.x;
        t4.m_position.y = b4.m_position.y + 2 * halfExtents.y;
        t4.m_position.z = b4.m_position.z;

        b1.m_color = color_f32;
        b2.m_color = color_f32;
        b3.m_color = color_f32;
        b4.m_color = color_f32;

        t1.m_color = color_f32;
        t2.m_color = color_f32;
        t3.m_color = color_f32;
        t4.m_color = color_f32;

        vertices.push_back(b1);
        vertices.push_back(b2);
        vertices.push_back(b3);
        vertices.push_back(b4);
        vertices.push_back(t1);
        vertices.push_back(t2);
        vertices.push_back(t3);
        vertices.push_back(t4);

        DLMT::DL_VECTOR4 v_color = color;

        if (!wireframe)
        {
            v_color = DirectX::Colors::Black;

            std::vector<uint16_t> indices_fill;

            b1.m_color = DLMT::DL_VECTOR4(color);
            b2.m_color = DLMT::DL_VECTOR4(color);
            b3.m_color = DLMT::DL_VECTOR4(color);
            b4.m_color = DLMT::DL_VECTOR4(color);

            t1.m_color = DLMT::DL_VECTOR4(color);
            t2.m_color = DLMT::DL_VECTOR4(color);
            t3.m_color = DLMT::DL_VECTOR4(color);
            t4.m_color = DLMT::DL_VECTOR4(color);

            vertices.push_back(b1);
            vertices.push_back(b2);
            vertices.push_back(b3);
            vertices.push_back(b4);
            vertices.push_back(t1);
            vertices.push_back(t2);
            vertices.push_back(t3);
            vertices.push_back(t4);

            indices_fill.push_back(0);
            indices_fill.push_back(1);
            indices_fill.push_back(2);

            indices_fill.push_back(0);
            indices_fill.push_back(2);
            indices_fill.push_back(3);

            indices_fill.push_back(4);
            indices_fill.push_back(5);
            indices_fill.push_back(6);

            indices_fill.push_back(4);
            indices_fill.push_back(6);
            indices_fill.push_back(7);

            indices_fill.push_back(0);
            indices_fill.push_back(4);
            indices_fill.push_back(5);

            indices_fill.push_back(0);
            indices_fill.push_back(1);
            indices_fill.push_back(5);

            indices_fill.push_back(1);
            indices_fill.push_back(5);
            indices_fill.push_back(6);

            indices_fill.push_back(1);
            indices_fill.push_back(2);
            indices_fill.push_back(6);

            indices_fill.push_back(2);
            indices_fill.push_back(6);
            indices_fill.push_back(7);

            indices_fill.push_back(2);
            indices_fill.push_back(3);
            indices_fill.push_back(7);

            indices_fill.push_back(3);
            indices_fill.push_back(7);
            indices_fill.push_back(4);

            indices_fill.push_back(3);
            indices_fill.push_back(0);
            indices_fill.push_back(4);

			DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_TRIANGLELIST, 0, vertices.size(), indices_fill.size(), indices_fill.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));

            vertices.clear();
        }

        b1.m_color = DLMT::DL_VECTOR4(v_color);
        b2.m_color = DLMT::DL_VECTOR4(v_color);
        b3.m_color = DLMT::DL_VECTOR4(v_color);
        b4.m_color = DLMT::DL_VECTOR4(v_color);

        t1.m_color = DLMT::DL_VECTOR4(v_color);
        t2.m_color = DLMT::DL_VECTOR4(v_color);
        t3.m_color = DLMT::DL_VECTOR4(v_color);
        t4.m_color = DLMT::DL_VECTOR4(v_color);

        const uint16_t s_indices[] =
        {
            0, 1,
            1, 2,
            2, 3,
            3, 0,
            4, 5,
            5, 6,
            6, 7,
            7, 4,
            0, 4,
            1, 5,
            2, 6,
            3, 7,
            0, 5,
            0, 7,
            1, 4,
            1, 6,
            2, 7,
            2, 5,
            3, 4,
            3, 6,
            0, 2,
            1, 3,
            4, 6,
            5, 7
        };

        std::vector<uint16_t> indices;
        indices.reserve(std::size(s_indices));

        for (size_t i = 0; i < std::size(s_indices); i++)
            indices.push_back(s_indices[i]);

        vertices.push_back(b1);
        vertices.push_back(b2);
        vertices.push_back(b3);
        vertices.push_back(b4);
        vertices.push_back(t1);
        vertices.push_back(t2);
        vertices.push_back(t3);
        vertices.push_back(t4);

		DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_LINELIST, 0, vertices.size(), indices.size(), indices.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));
    }

    void DrawBoundingBox(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 center, DLMT::DL_VECTOR3 halfExtents, DLMT::DL_VECTOR4 color)
    {
        DebugDrawParameters drawInfo(DrawContext);
        drawInfo.ApplyTransform(&transform);

        DLMT::DL_VECTOR4 color_f32 = color;

        DLGR::DLVertexPositionColor b1, b2, b3, b4;
        DLGR::DLVertexPositionColor t1, t2, t3, t4;

        std::vector<DLGR::DLVertexPositionColor> vertices;
        vertices.reserve(8);

        b1.m_position.x = center.x - halfExtents.x;
        b1.m_position.y = center.y - halfExtents.y;
        b1.m_position.z = center.z + halfExtents.z;

        b2.m_position.x = center.x + halfExtents.x;
        b2.m_position.y = center.y - halfExtents.y;
        b2.m_position.z = center.z + halfExtents.z;

        b3.m_position.x = center.x + halfExtents.x;
        b3.m_position.y = center.y - halfExtents.y;
        b3.m_position.z = center.z - halfExtents.z;

        b4.m_position.x = center.x - halfExtents.x;
        b4.m_position.y = center.y - halfExtents.y;
        b4.m_position.z = center.z - halfExtents.z;

        t1.m_position.x = b1.m_position.x;
        t1.m_position.y = b1.m_position.y + 2 * halfExtents.y;
        t1.m_position.z = b1.m_position.z;

        t2.m_position.x = b2.m_position.x;
        t2.m_position.y = b2.m_position.y + 2 * halfExtents.y;
        t2.m_position.z = b2.m_position.z;

        t3.m_position.x = b3.m_position.x;
        t3.m_position.y = b3.m_position.y + 2 * halfExtents.y;
        t3.m_position.z = b3.m_position.z;

        t4.m_position.x = b4.m_position.x;
        t4.m_position.y = b4.m_position.y + 2 * halfExtents.y;
        t4.m_position.z = b4.m_position.z;

        b1.m_color = color_f32;
        b2.m_color = color_f32;
        b3.m_color = color_f32;
        b4.m_color = color_f32;

        t1.m_color = color_f32;
        t2.m_color = color_f32;
        t3.m_color = color_f32;
        t4.m_color = color_f32;

        vertices.push_back(b1);
        vertices.push_back(b2);
        vertices.push_back(b3);
        vertices.push_back(b4);
        vertices.push_back(t1);
        vertices.push_back(t2);
        vertices.push_back(t3);
        vertices.push_back(t4);

        uint16_t indices[] =
        {
            0, 1,
            1, 2,
            2, 3,
            3, 0,
            4, 5,
            5, 6,
            6, 7,
            7, 4,
            0, 4,
            1, 5,
            2, 6,
            3, 7,
        };

        DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_LINELIST, 0, vertices.size(), 24, indices, DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));
    }

    void DrawOrientedBoundingBox(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 halfExtents, dl_bool bUnk, DLMT::DL_VECTOR4 color)
    {
        DebugDrawParameters drawInfo(DrawContext);
		FRPG2_CALL(oDebugDrawOrientedBoundingBox, 0xb40830, &drawInfo, &transform, (DLMT::DL_VECTOR4*)&halfExtents, DLMT::GetDLColor32(color), bUnk);
    }

    void Draw3DArc(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, dl_float32 radius, dl_float32 angle, dl_float32 height, dl_bool isFront, DLMT::DL_VECTOR4 color)
    {
        DebugDrawParameters drawInfo(DrawContext);
        drawInfo.ApplyTransform(&transform);

		DLMT::DL_VECTOR4 v_color = color;

        constexpr int sphere_seg = ARC_SLICES;
        dl_float32 correction = DirectX::XM_PI;

        DLMT::DL_VECTOR3 bottom_vertices_1[sphere_seg];
        DLMT::DL_VECTOR3 bottom_vertices_2[sphere_seg];
        DLMT::DL_VECTOR3 top_vertices_1[sphere_seg];
        DLMT::DL_VECTOR3 top_vertices_2[sphere_seg];
        DLMT::DL_VECTOR3 center_vertex;
        DLMT::DL_VECTOR3 center_top_vertex;
        DLMT::DL_VECTOR3 center_bot_vertex;

        DLMT::DL_VECTOR3 center_top = DLMT::DL_VECTOR3(0, height, 0);
        DLMT::DL_VECTOR3 center_bot = DLMT::DL_VECTOR3(0, -height, 0);

        std::vector<DLGR::DLVertexPositionColor> vertices;

        center_vertex = DLMT::DL_VECTOR3::Zero;
        center_top_vertex = center_top;
        center_bot_vertex = center_bot;

        if (isFront)
            correction = 0;

        DLMT::DL_VECTOR3 start_top = center_top + DLMT::DL_VECTOR3(cos(correction) * radius, 0, sin(correction) * radius);
        DLMT::DL_VECTOR3 start_bot = center_bot + DLMT::DL_VECTOR3(cos(correction) * radius, 0, sin(correction) * radius);

        //Top
        for (size_t i = 0; i < sphere_seg; i++)
        {
            dl_float32 x = cos(correction - angle / sphere_seg * i) * radius;
            dl_float32 y = 0;
            dl_float32 z = sin(correction - angle / sphere_seg * i) * radius;

            top_vertices_1[i] = center_top + DLMT::DL_VECTOR3(x, y, z);

            x = cos(correction + angle / sphere_seg * i) * radius;
            y = 0;
            z = sin(correction + angle / sphere_seg * i) * radius;

            top_vertices_2[i] = center_top + DLMT::DL_VECTOR3(x, y, z);
        }

        for (size_t i = 0; i < sphere_seg; i++)
            vertices.push_back(DLGR::DLVertexPositionColor(top_vertices_1[i], v_color));

        for (size_t i = 0; i < sphere_seg; i++)
            vertices.push_back(DLGR::DLVertexPositionColor(top_vertices_2[i], v_color));

        //Bottom
        for (size_t i = 0; i < sphere_seg; i++)
        {
            dl_float32 x = cos(correction - angle / sphere_seg * i) * radius;
            dl_float32 y = 0;
            dl_float32 z = sin(correction - angle / sphere_seg * i) * radius;

            bottom_vertices_1[i] = center_bot + DLMT::DL_VECTOR3(x, y, z);

            x = cos(correction + angle / sphere_seg * i) * radius;
            y = 0;
            z = sin(correction + angle / sphere_seg * i) * radius;

            bottom_vertices_2[i] = center_bot + DLMT::DL_VECTOR3(x, y, z);
        }

        for (size_t i = 0; i < sphere_seg; i++)
            vertices.push_back(DLGR::DLVertexPositionColor(bottom_vertices_1[i], v_color));

        for (size_t i = 0; i < sphere_seg; i++)
            vertices.push_back(DLGR::DLVertexPositionColor(bottom_vertices_2[i], v_color));

        vertices.push_back(DLGR::DLVertexPositionColor(center_top_vertex, v_color));
        vertices.push_back(DLGR::DLVertexPositionColor(center_bot_vertex, v_color));

        std::vector<uint16_t> indices;

        for (size_t i = 0; i < sphere_seg; i++)
        {
            if (i + 1 < sphere_seg)
            {
                indices.push_back(i);
                indices.push_back(i + 1);

                indices.push_back(sphere_seg + i);
                indices.push_back(sphere_seg + i + 1);

                indices.push_back(2 * sphere_seg + i);
                indices.push_back(2 * sphere_seg + i + 1);

                indices.push_back(3 * sphere_seg + i);
                indices.push_back(3 * sphere_seg + i + 1);

                if (i % (sphere_seg / ARC_TIRET_FREQ) == 0)
                {
                    indices.push_back(i);
                    indices.push_back(4 * sphere_seg);

                    indices.push_back(sphere_seg + i);
                    indices.push_back(4 * sphere_seg);

                    indices.push_back(2 * sphere_seg + i);
                    indices.push_back(4 * sphere_seg + 1);

                    indices.push_back(3 * sphere_seg + i);
                    indices.push_back(4 * sphere_seg + 1);

                    indices.push_back(i);
                    indices.push_back(2 * sphere_seg + i);

                    indices.push_back(sphere_seg + i);
                    indices.push_back(3 * sphere_seg + i);
                }
            }
        }

        indices.push_back(3 * sphere_seg - 1);
        indices.push_back(sphere_seg - 1);

        indices.push_back(4 * sphere_seg - 1);
        indices.push_back(2 * sphere_seg - 1);

        indices.push_back(3 * sphere_seg - 1);
        indices.push_back(4 * sphere_seg + 1);

        indices.push_back(4 * sphere_seg - 1);
        indices.push_back(4 * sphere_seg + 1);

        indices.push_back(sphere_seg - 1);
        indices.push_back(4 * sphere_seg);

        indices.push_back(2 * sphere_seg - 1);
        indices.push_back(4 * sphere_seg);

        indices.push_back(4 * sphere_seg);
        indices.push_back(4 * sphere_seg + 1);

		DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_LINELIST, 0, vertices.size(), indices.size(), indices.data(), DLGR::DLINDEXFMT_U16, vertices.data(), sizeof(DLGR::DLVertexPositionColor));
    }

    void DrawMesh(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, std::vector<DLMT::DL_VECTOR3> vertices, std::vector<dl_uint> indices, std::vector<dl_uint> indicesWireframe, dl_bool wireframe, DLMT::DL_VECTOR4 color)
    {
		DebugDrawParameters drawInfo(DrawContext);
		drawInfo.ApplyTransform(&transform);
        
        DLMT::DL_VECTOR4 v_color = color;
		std::vector<DLGR::DLVertexPositionColor> dlVertices;

		dlVertices.reserve(vertices.size());

		if (!wireframe)
			v_color = DirectX::Colors::Black;

		for (size_t i = 0; i < vertices.size(); i++)
			dlVertices.push_back(DLGR::DLVertexPositionColor(vertices[i], v_color));

        DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_LINELIST, 0, dlVertices.size(), indicesWireframe.size(), indicesWireframe.data(), DLGR::DLINDEXFMT_U32, dlVertices.data(), sizeof(DLGR::DLVertexPositionColor));

		if (!wireframe)
		{
            for (size_t i = 0; i < dlVertices.size(); i++)
                dlVertices[i].m_color = color;

			DrawContext->DrawIndexed(DLGR::DLPRIMTYPE_TRIANGLELIST, 0, dlVertices.size(), indices.size(), indices.data(), DLGR::DLINDEXFMT_U32, dlVertices.data(), sizeof(DLGR::DLVertexPositionColor));
		}
    }
}
