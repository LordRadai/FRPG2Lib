#pragma once
#include "Core/CGBuffer.h"
#include "DLGPUResource.h"
#include "dantelion2/Core/Platform/Platform.h"

namespace DLGR
{
	class DLVertexBuffer : public DLGPUResource
	{
	public:	
		DLCG2::CGBuffer* m_pCGBuffer;
		dl_pointer m_pVar30;
		dl_int16 m_sVar38;
		dl_pointer m_pVar40;
		dl_pointer m_pVar48;
		dl_pointer_float32* m_pVertices;
	};
}