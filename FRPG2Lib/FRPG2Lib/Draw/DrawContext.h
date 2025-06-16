#pragma once
#include "dantelion2/dantelion2.h"

class IDrawContext
{
public:
	enum DrawParameter
	{
		DRAWPARAM_DEPTH_TESTING_ENABLED = 6,
		DRAWPARAM_DEPTH_COMP_MODE,
		DRAWPARAM_8,
		DRAWPARAM_TRANSPARENCY_ENABLED = 25,
		DRAWPARAM_CLIPPING_ENABLED = 54,
		DRAWPARAM_SYNC_INTERVAL = 81,
	};

	IDrawContext() {}
	~IDrawContext() {}

	void ClearRenderTargetsView(int numTargets, uint32_t color);
	dl_bool Draw(DLGR::DLPrimitiveType topology, uint32_t numBuffers, void* pData, uint32_t bufferSize);
	dl_bool DrawIndexed(DLGR::DLPrimitiveType topology, uint32_t startingVertexNum, uint32_t numVertices, uint32_t numIndices, void* pIndices, DLGR::DLIndexFormat indexFmt, void* pVertices, uint32_t stride);
	
	/*
	* @brief Sets an unknown parameter for the draw context.
	* @param id: The ID for the parameter to set.
	* @param value: The value to set for the parameter.
	*/
	void SetParameter(dl_uint id, dl_uint value);
	dl_bool DrawTexture2D(dl_int mode, DLGR::DLTexture2D* pTexture);
private:
	void** vfptr = nullptr;
};