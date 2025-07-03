#include "GameManager.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oConstructor)(GameManagerImp* pThis, DLKR::DLAllocator* pAllocator);

GameManagerImp::GameManagerImp(DLKR::DLAllocator* pAllocator)
{
	FRPG2_CALL(oConstructor, 0x1c03c0, this, pAllocator);
}