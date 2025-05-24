#pragma once
#include "GamePad/GamePad.h"
#include "DeviceList.h"

class InputManager;

class InputDevices
{
	GamePad* m_pGamePads;
	DeviceList* m_pDeviceList;
	InputManager* m_pInputManager;
	dl_int m_iVar18;
	dl_int m_iVar1C;
	GamePad m_defaultGamePad;
	dl_bool m_bVar2A8;
	dl_bool m_bVar2A9;
	dl_bool m_bVar2AA;
	dl_bool m_bVar2AB;
	dl_int m_iVar2AC;
	dl_int m_iVar2B0;
	dl_int m_iVar2B4;
	DLKR::DLAllocator* m_pAllocator;
};