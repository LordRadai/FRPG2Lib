#pragma once
#include "dantelion2/dantelion2.h"
#include "DeviceList.h"

class GamePad
{
public:
	enum class Buttons : dl_uint16
	{
		GAMEPAD_DPAD_UP = 0x0001,
		GAMEPAD_DPAD_DOWN = 0x0002,
		GAMEPAD_DPAD_LEFT = 0x0004,
		GAMEPAD_DPAD_RIGHT = 0x0008,
		GAMEPAD_START = 0x0010,
		GAMEPAD_BACK = 0x0020,
		GAMEPAD_LEFT_SHOULDER = 0x0040,
		GAMEPAD_RIGHT_SHOULDER = 0x0080,
		GAMEPAD_LEFT_TRIGGER = 0x0100,
		GAMEPAD_RIGHT_TRIGGER = 0x0200,
		GAMEPAD_LEFT_THUMB = 0x0400,
		GAMEPAD_RIGHT_THUMB = 0x0800,
		GAMEPAD_A = 0x1000,
		GAMEPAD_B = 0x2000,
		GAMEPAD_X = 0x4000,
		GAMEPAD_Y = 0x8000
	};

private:
	DECLSPEC_ALIGN(8)
	struct GamePadState
	{
		dl_int16 wButtons;
		dl_int16 sVar2;
		dl_uchar unk0[28];
		dl_float32 fThumbRX;
		dl_float32 fThumbRY;
		dl_float32 fThumbLX;
		dl_float32 fThumbLY;
		dl_uchar unk1[200];
	};

public:
	dl_int m_gamePadID;
	GamePadState m_state;
	GamePadState m_statePrev;
	DeviceList* m_pDeviceList;
	dl_int m_iVar200;
	dl_int m_iVar204;
	dl_int16 m_svar208;
	dl_int m_iVar20C;
	dl_float32 m_fVar210;
	dl_float32 m_fVar214;
	dl_bool m_bVar218;
	dl_bool m_bVar219;
	dl_int m_iVar21C;
	dl_int m_iVar220;
	dl_int m_iVar224;
	dl_int m_iVar228;
	dl_int m_iVar22C;
	dl_int m_iVar230;
	dl_int m_iVar234;
	dl_int m_iVar238;
	dl_int m_iVar23C;
	dl_int m_iVar240;
	dl_int m_iVar244;
	dl_int m_iVar248;
	dl_int m_iVar24C;
	dl_int m_iVar250;
	dl_int m_iVar254;
	dl_int m_iVar258;
	dl_int m_iVar25C;
	dl_int m_iVar260;
	dl_int m_iVar264;
	dl_uchar m_flags;
	dl_char m_unk[28];
};