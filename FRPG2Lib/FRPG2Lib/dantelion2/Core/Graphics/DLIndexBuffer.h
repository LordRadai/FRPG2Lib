#pragma once
#include "Core/CGBuffer.h"
#include "DLGPUResource.h"
#include "dantelion2/Core/Platform/Platform.h"

namespace DLGR
{
	class DLIndexBuffer : public DLGPUResource
	{
	public:
		DLCG2::CGBuffer* pCGBuffer;
		dl_int bufferSize;
		dl_int iVar10;
		dl_pointer pVar11;
	};
}