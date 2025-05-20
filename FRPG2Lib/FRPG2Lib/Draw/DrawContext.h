#pragma once
#include "dantelion2/dantelion2.h"

class IDrawContext
{
public:
	IDrawContext() {}
	~IDrawContext() {}

	void ClearRenderTargetsView(int numTargets, uint32_t color);
	bool Draw(DLGR::DLPrimitiveType topology, uint32_t numBuffers, void* pData, uint32_t bufferSize);
	bool DrawIndexed(DLGR::DLPrimitiveType topology, uint32_t startingVertexNum, uint32_t numVertices, uint32_t numIndices, void* pIndices, DLGR::DLIndexFormat indexFmt, void* pVertices, uint32_t stride);
	bool DrawTexture2D(dl_int mode, DLGR::DLTexture2D* pTexture);
private:
	void** vfptr = nullptr;
};