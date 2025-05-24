#pragma once
#include "dantelion2/dantelion2.h"

class DeviceList
{
	DLKR::DLAllocator* m_pAllocator;
	DLUID::PadDevice<DLKR::DLSingleThreadingPolicy>* m_pPadDevices[4];
	DLUID::KeyboardDevice<DLKR::DLSingleThreadingPolicy>* m_pKeyboardDevice;
	dl_pointer m_pVar30;
	dl_pointer m_pVar38;
	dl_pointer m_pVar40;
	DLUID::DLUserInputMapperImpl<DLKR::DLSingleThreadingPolicy>* m_pInputMapper;
	DLUID::DLUserInputTraitsImpl<DLKR::DLSingleThreadingPolicy>* m_pInputTraits;
	dl_int m_iVar58;
	dl_pointer m_pVar60;
	dl_int m_iVar68;
	dl_bool m_bVar6C;
	dl_bool m_bVar6D;
};