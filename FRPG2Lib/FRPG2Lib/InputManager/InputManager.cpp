#include "InputManager.h"
#include "FRPG2Call.h"

typedef GamePad*(_fastcall* oGetMainGamePad)(InputManager* pThis);
typedef GamePad*(_fastcall* oGetGamePad)(InputManager* pThis, dl_int idx);

GamePad* InputManager::GetMainGamePad()
{
	return FRPG2_CALL(oGetMainGamePad, 0xaf3f30, this);
}

GamePad* InputManager::GetGamePad(dl_int idx)
{
	return FRPG2_CALL(oGetGamePad, 0xaf3f10, this, idx);
}