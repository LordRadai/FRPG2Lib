#include "CharacterManager.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oConstructor)(CharacterManager* pThis);
typedef void(_fastcall* oDestructor)(CharacterManager* pThis);
typedef dl_bool(_fastcall* oInitialize)(CharacterManager* pThis);
typedef void(_fastcall* oClearEntityListAndResources)(CharacterManager* pThis);
typedef void(_fastcall* oFreePlayerCharactersAsmResources)(CharacterManager* pThis, dl_pointer pChrAsmCommonResData);

CharacterManager::CharacterManager()
{
	FRPG2_CALL(oConstructor, 0x3546c0, this);
}

CharacterManager::~CharacterManager()
{
	FRPG2_CALL(oDestructor, 0x354c00, this);
}

dl_bool CharacterManager::Initialize()
{
	return FRPG2_CALL(oInitialize, 0x359270, this);
}

void CharacterManager::ClearEntityListAndResources()
{
	FRPG2_CALL(oClearEntityListAndResources, 0x3596c0, this);
}

void CharacterManager::FreePlayerCharactersAsmResources(dl_pointer pChrAsmCommonResData)
{
	FRPG2_CALL(oFreePlayerCharactersAsmResources, 0x153440, this, pChrAsmCommonResData);
}