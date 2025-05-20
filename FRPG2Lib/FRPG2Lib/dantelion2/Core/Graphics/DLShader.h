#pragma once
#include "DLGPUResource.h"
#include "DLDrawDevice.h"

namespace DLGR
{
	class DLShader : public DLGPUResource
	{
		dl_pointer m_pVar28;
		dl_int m_iVar30;
		dl_int m_iVar34;
	};

	class DLVertexShader : public DLShader
	{
		dl_pointer m_pVar38;
		dl_int m_iVar40;
		dl_int m_iVar44;
		dl_pointer m_pVar48;
		DLDrawDevice* m_pDrawDevice;
		DLKR::DLAllocator* m_pAllocator;
	};

	class DLPixelShader : public DLShader
	{
	};
}