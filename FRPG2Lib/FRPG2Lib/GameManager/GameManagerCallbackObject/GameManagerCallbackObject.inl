#pragma once
#include "GameManagerCallbackObjectBase.h"

template<typename T>
class GameManagerCallbackObject : public GameManagerCallbackObjectBase
{
	T* m_pObj;
	void* m_pFunc;
};