#pragma once
#include "DLGfxReferenceCountObject.h"
#include "DLDrawDevice.h"
#include "dantelion2/Core/Platform/Platform.h"

namespace DLGR
{
	class DLGPUResource : public DLGfxReferenceCountObject
	{
	protected:
		DLDrawDevice* m_pDrawDevice;
		dl_int iVar20;
	};
}