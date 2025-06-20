#pragma once
#include "GameObject/GameObject.h"

class GameEntity : public GameObject
{
	DLKR::DLAllocator* m_pAllocator;
	dl_pointer m_pVar18;
};