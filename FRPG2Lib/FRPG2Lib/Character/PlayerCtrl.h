#pragma once
#include "CharacterCtrl.h"

class PlayerCtrl : public CharacterCtrl
{
public:
	dl_pointer m_pPlayerActionCtrl;
	dl_pointer m_pVar488;
	dl_pointer m_pPlayerStatus;
	dl_pointer m_pVar498;
};