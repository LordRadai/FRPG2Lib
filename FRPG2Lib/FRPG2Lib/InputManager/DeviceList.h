#pragma once
#include "dantelion2/dantelion2.h"

class DeviceList
{
	DLKR::DLAllocator* m_pAllocator;
	dl_pointer m_pPadDevices[4];
	dl_pointer m_pKeyboardDevice;
};