#include "DrawContext.h"
#include "Memory/Memory.h"
#include "FRPG2Globals.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oClearRenderTargetView)(IDrawContext* pThis, int numTargets, uint32_t color);
typedef dl_bool(_fastcall* oDraw)(IDrawContext* pThis, DLGR::DLPrimitiveType topology, uint32_t numShapes, void* pData, uint32_t bufferSize);
typedef dl_bool(_fastcall* oDrawIndexed)(IDrawContext* pThis, DLGR::DLPrimitiveType topology, uint32_t startingVertexNum, uint32_t numVertices, uint32_t numIndices, void* pIndices, DLGR::DLIndexFormat indexFmt, void* pVertices, uint32_t stride);
typedef dl_bool(_fastcall* oDrawTexture2D)(IDrawContext* pThis, dl_int mode, DLGR::DLTexture2D* pTexture);
typedef void(_fastcall* oSetParameter)(IDrawContext* pThis, dl_uint id, dl_uint value);

void IDrawContext::ClearRenderTargetsView(int numTargets, uint32_t color)
{
	return FRPG2_VCALL(this, 5, oClearRenderTargetView, this, numTargets, color);
}

dl_bool IDrawContext::Draw(DLGR::DLPrimitiveType topology, uint32_t numShapes, void* pData, uint32_t bufferSize)
{
	return FRPG2_VCALL(this, 8, oDraw, this, topology, numShapes, pData, bufferSize);
}

dl_bool IDrawContext::DrawIndexed(DLGR::DLPrimitiveType topology, uint32_t startingVertexNum, uint32_t numVertices, uint32_t numIndices, void* pIndices, DLGR::DLIndexFormat indexFmt, void* pVertices, uint32_t stride)
{
	return FRPG2_VCALL(this, 11, oDrawIndexed, this, topology, startingVertexNum, numVertices, numIndices, pIndices, indexFmt, pVertices, stride);
}

void IDrawContext::SetParameter(dl_uint id, dl_uint value)
{
	FRPG2_VCALL(this, 21, oSetParameter, this, id, value);
}

dl_bool IDrawContext::DrawTexture2D(dl_int mode, DLGR::DLTexture2D* pTexture)
{
	return FRPG2_VCALL(this, 34, oDrawTexture2D, this, mode, pTexture);
}