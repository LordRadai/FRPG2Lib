#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "dantelion2/Core/Util/DLReferenceCountObject.h"

namespace DLGR
{
	class DLGfxReferenceCountObject : public DLUT::DLReferenceCountObject
	{
	protected:
		DLKR::DLAllocator* m_pAllocator;
	};
}