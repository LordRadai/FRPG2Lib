#include "hkpConvexVerticesShape.h"

typedef void(_fastcall* oHkpConvexVerticesShapeGetVertices)(Havok::hkpConvexVerticesShape* hkpConvexVerticesShape, Vector4* buffer);

namespace Havok
{
	void hkpConvexVerticesShape::getOriginalVertices(hkVector4* pBuffer)
	{
		oHkpConvexVerticesShapeGetVertices getConvexHullVerticesFn = (oHkpConvexVerticesShapeGetVertices)(this->_vfptr[13]);
		getConvexHullVerticesFn(this, pBuffer);
	}
}