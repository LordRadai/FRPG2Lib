#pragma once
#include "dantelion2/dantelion2.h"
#include "InputDevices.h"

DECLSPEC_ALIGN(16)
class InputManager
{
	struct sUnkState
	{
		dl_uint64 m_iVar0;
		dl_uint64 m_iVar8;
		dl_uint64 m_iVar10;
		dl_uint64 m_iVar18;
		dl_uint64 m_iVar20;
		dl_uint64 m_iVar28;
		dl_uint64 m_iVar30;
		dl_uint64 m_iVar38;
		dl_uint64 m_iVar40;
		dl_uint64 m_iVar48;
		dl_uint64 m_iVar50;
		dl_uint64 m_iVar58;
		dl_uint64 m_iVar60;
		dl_uint64 m_iVar68;
		dl_uint64 m_iVar70;
		dl_uint64 m_iVar78;
	};

public:
	InputDevices* m_pInputDevices;
	dl_pointer m_pMouseDevice;
	dl_int m_iVar10;
	dl_int m_iVar14;
	sUnkState m_unkState0[2];
	sUnkState m_unkState1[2];
	sUnkState m_unkState2;
	sUnkState m_unkState3;
	sUnkState m_unkState4;
	sUnkState m_unkState5;
	sUnkState m_unkState6;
	sUnkState m_unkState7;
	dl_bool m_bVar518[256];
	dl_uchar m_bVar618;
	dl_uchar m_bVar619;
	DLKR::DLAllocator* m_pAllocator;
	dl_float32 m_fVar628[12];
	dl_pointer m_pSoftKeyManager;
	dl_int m_iVar660;
	dl_int m_iVar664;
	dl_int m_iVar668;
	dl_int m_mouseFlags;
	dl_int m_cursorX;
	dl_int m_cursorY;
	dl_int m_cursorXPrev;
	dl_int m_cursorYPrev;
	dl_int m_iVar680;
	dl_int m_iVar684;
};