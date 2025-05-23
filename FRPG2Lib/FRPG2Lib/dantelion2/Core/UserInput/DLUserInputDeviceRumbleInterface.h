#pragma once
#include "DLUserInputDeviceOutputInterface.h"
#include "details/DLUserInputDeviceImpl.inl"

namespace DLUI
{
	class DLUserInputDeviceRumbleInterface : public DLUserInputDeviceOutputInterface
	{
		dl_pointer m_pDevice;
		dl_pointer m_pVar10;
		dl_pointer m_pVar18;
		dl_pointer m_pVar20;
		dl_int16 m_sVar28;
		dl_int16 m_sVar2A;
		dl_int16 m_sVar2C;
		dl_int16 m_sVar2E;
		dl_int m_iVar30;
		dl_int m_iVar34;
		dl_int m_pVar38;
		dl_int m_iVar3C;
		dl_int m_iVar40;
		dl_int m_iVar44;
		dl_int m_iVar48;
		dl_int m_iVar4C;
		dl_int m_iVar50;
		dl_int m_iVar54;
		dl_int m_iVar58;
		dl_int m_iVar5C;
		dl_int m_iVar60;
		dl_int m_iVar64;
		dl_int m_iVar68;
		dl_int m_iVar6C;
		dl_int m_iVar70;
		dl_int m_iVar74;
		dl_int m_iVar78;
		dl_int m_iVar7C;
		dl_int m_iVar80;
		dl_int m_iVar84;
		dl_int m_iVar88;
		dl_int m_iVar8C;
	};
}