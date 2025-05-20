#pragma once
#include "dantelion2/dantelion2.h"
#include "DrawContext.h"
#include <vector>

namespace DebugDraw
{
	/**
	 * @brief Draws an indexed geometry for testing purposes.
	 *
	 * Used to test IDrawContext->DrawIndexed with a simple line shape.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 applied to the geometry.
	 * @param color:       The color used to draw the geometry, in 0xAARRGGBB format.
	*/
	void DrawIndexedTest(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR4 color);

	/**
	 * @brief Draws a line between two points in 3D space.
	 *
	 * This function renders a line segment defined by two endpoints.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param pointA:      The starting point of the line segment.
	 * @param pointB:      The ending point of the line segment.
	 * @param color:       The color used to draw the line, in 0xAARRGGBB format.
	*/
	void DrawLine(IDrawContext* DrawContext, DLMT::DL_VECTOR3 pointA, DLMT::DL_VECTOR3 pointB, DLMT::DL_VECTOR4 color);

	/**
	 * @brief Draws a reference frame in 3D space.
	 *
	 * This function renders a reference frame defined by an origin and axis lengths.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 applied to the reference frame.
	 * @param axisLenght:  The length of each axis in the reference frame.
	*/
	void DrawReferenceFrame(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, dl_float32 axisLenght);

	/**
	 * @brief Draws a grid in 3D space.
	 *
	 * This function renders a grid defined by a transformation DLMT::DL_MATRIX44, number of divisions, and size.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 applied to the grid.
	 * @param numDivisions: The number of divisions in the grid.
	 * @param size:        The size of each division in the grid.
	 * @param color:       The color used to draw the grid, in 0xAARRGGBB format.
	*/
	void DrawGrid(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, uint32_t numDivisions, dl_float32 size, DLMT::DL_VECTOR4 color);

	/**
	 * @brief Draws a capsule shape between two points.
	 *
	 * This function renders a capsule defined by two end points and a radius.
	 * The capsule can be drawn as either a solid shape or a wireframe.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 to apply to the capsule (e.g., for world positioning).
	 * @param pointA:      The bottom vertex of the capsule's central line segment.
	 * @param pointB:      The top vertex of the capsule's central line segment.
	 * @param radius:      The radius of the capsule's hemispherical ends and cylindrical body.
	 * @param wireframe:   If true, the capsule is drawn in wireframe mode; otherwise, it's solid.
	 * @param color:       The color used to draw the capsule, in 0xAARRGGBB format.
	 */
	void DrawCapsule(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 pointA, DLMT::DL_VECTOR3 pointB, dl_float32 radius, bool wireframe, DLMT::DL_VECTOR4 color);

	/**
	 * @brief Draws a sphere shape at a specified position.
	 *
	 * This function renders a sphere defined by its center and radius.
	 * The sphere can be drawn as either a solid shape or a wireframe.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 to apply to the sphere (e.g., for world positioning).
	 * @param radius:      The radius of the sphere.
	 * @param wireframe:   If true, the sphere is drawn in wireframe mode; otherwise, it's solid.
	 * @param color:       The color used to draw the sphere, in 0xAARRGGBB format.
	 */
	void DrawSphere(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, dl_float32 radius, bool wireframe, DLMT::DL_VECTOR4 color);

	/**
	 * @brief Draws a cylinder shape between two points.
	 *
	 * This function renders a cylinder defined by two end points and a radius.
	 * The cylinder can be drawn as either a solid shape or a wireframe.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 to apply to the cylinder (e.g., for world positioning).
	 * @param pointA:      The bottom vertex of the cylinder's central line segment.
	 * @param pointB:      The top vertex of the cylinder's central line segment.
	 * @param radius:      The radius of the cylinder.
	 * @param wireframe:   If true, the cylinder is drawn in wireframe mode; otherwise, it's solid.
	 * @param color:       The color used to draw the cylinder, in 0xAARRGGBB format.
	 */
	void DrawCylinder(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 pointA, DLMT::DL_VECTOR3 pointB, dl_float32 radius, bool wireframe, DLMT::DL_VECTOR4 color);

	/**
	 * @brief Draws a box shape at a specified position.
	 *
	 * This function renders a box defined by its center and half extents.
	 * The box can be drawn as either a solid shape or a wireframe.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 to apply to the box (e.g., for world positioning).
	 * @param halfExtents: The half extents of the box in each dimension.
	 * @param wireframe:   If true, the box is drawn in wireframe mode; otherwise, it's solid.
	 * @param color:       The color used to draw the box, in 0xAARRGGBB format.
	 */
	void DrawBox(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 halfExtents, bool wireframe, DLMT::DL_VECTOR4 color);

	/**
	 * @brief Draws a bounding box in 3D space.
	 *
	 * This function renders a bounding box defined by its center and half extents.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 applied to the bounding box.
	 * @param center:	   The center of the bounding box.
	 * @param halfExtents: The half extents of the bounding box in each dimension.
	 * @param color:       The color used to draw the bounding box, in 0xAARRGGBB format.
	 */
	void DrawBoundingBox(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 center, DLMT::DL_VECTOR3 halfExtents, DLMT::DL_VECTOR4 color = DLMT::DL_VECTOR4(DirectX::Colors::DarkRed));

	/**
	 * @brief Draws an oriented bounding box in 3D space.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 applied to the bounding box.
	 * @param halfExtents: The half extents of the bounding box in each dimension.
	 * @param bUnk:        Unknown meaning
	 * @param color:       The color used to draw the bounding box, in 0xAARRGGBB format.
	 */
	void DrawOrientedBoundingBox(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, DLMT::DL_VECTOR3 halfExtents, bool bUnk, DLMT::DL_VECTOR4 color = DLMT::DL_VECTOR4(DirectX::Colors::White));

	/**
	 * @brief Draws a 3D arc in space.
	 *
	 * This function renders an arc defined by its center, radius, angle, and height.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 applied to the arc.
	 * @param radius:      The radius of the arc.
	 * @param angle:       The angle of the arc in radians.
	 * @param height:      The height of the arc.
	 * @param isFront:     If true, the arc is drawn in front; otherwise, it's drawn behind.
	 * @param color:       The color used to draw the arc, in 0xAARRGGBB format.
	 */
	void Draw3DArc(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, dl_float32 radius, dl_float32 angle, dl_float32 height, bool isFront, DLMT::DL_VECTOR4 color);

	/**
	 * @brief Draws a mesh using indexed geometry.
	 *
	 * This function renders a mesh defined by its vertices and indices.
	 *
	 * @param DrawContext: The drawing context used to issue rendering commands.
	 * @param transform:   The transformation DLMT::DL_MATRIX44 applied to the mesh.
	 * @param vertices:    The vertex data for the mesh.
	 * @param indices:     The index data for the mesh.
	 * @param indicesWireframe: The index data for the wireframe version of the mesh.
	 * @param wireframe:   If true, the mesh is drawn in wireframe mode; otherwise, it's solid.
	 * @param color:       The color used to draw the mesh, in 0xAARRGGBB format.
	 */
	void DrawMesh(IDrawContext* DrawContext, DLMT::DL_MATRIX44 transform, std::vector<DLMT::DL_VECTOR3> vertices, std::vector<uint32_t> indices, std::vector<uint32_t> indicesWireframe, bool wireframe, DLMT::DL_VECTOR4 color);
}