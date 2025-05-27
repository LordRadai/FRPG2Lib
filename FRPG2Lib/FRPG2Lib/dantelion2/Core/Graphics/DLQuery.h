#pragma once
#include "DLGfxReferenceCountObject.h"
#include "DLDrawDevice.h"

namespace DLGR
{
	class DLQuery : public DLGfxReferenceCountObject
	{
        DLGR::DLDrawDevice* m_pDrawDevice;
        dl_pointer field2_0x20;
        dl_bool m_bHasBegun;
        dl_bool m_bHasEnded;
        dl_int field6_0x2c;
        dl_int field7_0x30;
	};
}