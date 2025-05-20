#pragma once
#include "Havok/Physics/PhysicsIncludes.h"
#include "DebugDraw.h"

static class HavokDebugDraw
{
public:
	static void DrawShape(IDrawContext* pDrawContext, Havok::hkpShape* pShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color);

private:
	static void DrawSphereShape(IDrawContext* pDrawContext, Havok::hkpSphereShape* pSphere, Matrix transform, bool wireframe, Vector4 color);
	static void DrawCapsuleShape(IDrawContext* pDrawContext, Havok::hkpCapsuleShape* pCapsule, Matrix transform, bool wireframe, Vector4 color);
	static void DrawCylinderShape(IDrawContext* pDrawContext, Havok::hkpCylinderShape* pCylinderShape, Matrix transform, bool wireframe, Vector4 color);
	static void DrawBoxShape(IDrawContext* pDrawContext, Havok::hkpBoxShape* pBox, Matrix transform, bool wireframe, Vector4 color);
	static void DrawConvexTranslateShape(IDrawContext* pDrawContext, Havok::hkpConvexTranslateShape* pConvexTranslate, Matrix transform, bool wireframe, bool showAabb, Vector4 color);
	static void DrawConvexVerticesShape(IDrawContext* pDrawContext, Havok::hkpConvexVerticesShape* pConvexVerticesShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color);
	static void DrawStorageExtendedMeshShape(IDrawContext* pDrawContext, Havok::hkpStorageExtendedMeshShape* pStorageExtendedMeshShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color);
	static void DrawMoppBvTreeShape(IDrawContext* pDrawContext, Havok::hkpMoppBvTreeShape* pMoppBvTreeShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color);
	static void DrawListShape(IDrawContext* pDrawContext, Havok::hkpListShape* pListShape, Matrix transform, bool wireframe, bool showAabb, Vector4 color);
};