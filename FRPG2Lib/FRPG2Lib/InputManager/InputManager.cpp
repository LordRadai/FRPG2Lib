#include "InputManager.h"
#include "FRPG2Call.h"

typedef GamePad*(_fastcall* oGetMainGamePad)(InputManager* pThis);

GamePad* InputManager::GetMainGamePad()
{
	return FRPG2_CALL(oGetMainGamePad, 0xaf3f30, this);
}