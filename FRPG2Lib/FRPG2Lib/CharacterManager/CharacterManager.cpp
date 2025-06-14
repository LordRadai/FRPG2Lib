#include "CharacterManager.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oDestructor)(CharacterManager* pThis);
typedef void(_fastcall* oUpdate)(CharacterManager* pThis, dl_float32* pDeltaTime);
typedef void(_fastcall* oRegisterPostPhysicsTasks)(CharacterManager* pThis, dl_float32* pDeltaTime);
typedef void(_fastcall* oRegisterPreDrawTasks)(CharacterManager* pThis, dl_float32* pDeltaTime);
typedef void(_fastcall* oDrawCharacterModels)(CharacterManager* pThis, dl_pointer pDrawCtxWrapper);
typedef void(_fastcall* oDrawUnknownModel)(CharacterManager* pThis, dl_pointer pDrawCtxWrapper);
typedef void(_fastcall* oDrawCharacterIcons)(CharacterManager* pThis, IDrawContext* pDrawContext);

typedef dl_bool(_fastcall* oInitialize)(CharacterManager* pThis);
typedef void(_fastcall* oClearEntityListAndResources)(CharacterManager* pThis);

CharacterManager::CharacterManager()
{
	FRPG2_CALL(oConstructor, 0x3546c0, this);
}

CharacterManager::~CharacterManager()
{
	FRPG2_CALL(oDestructor, 0x354c00, this);
}

void CharacterManager::Update(dl_float32* pDeltaTime)
{
	FRPG2_CALL(oUpdate, 0x35a1e0, this, pDeltaTime);
}

void CharacterManager::RegisterPostPhysicsTasks(dl_float32* pDeltaTime)
{
	FRPG2_CALL(oRegisterPostPhysicsTasks, 0x359e80, this, pDeltaTime);
}

void CharacterManager::RegisterPreDrawTasks(dl_float32* pDeltaTime)
{
	FRPG2_CALL(oRegisterPreDrawTasks, 0x359fd0, this, pDeltaTime);
}

void CharacterManager::DrawCharacterModels(dl_pointer pDrawCtxWrapper)
{
	FRPG2_CALL(oDrawCharacterModels, 0x354ee0, this, pDrawCtxWrapper);
}

void CharacterManager::DrawUnknownModel(dl_pointer pDrawCtxWrapper)
{
	FRPG2_CALL(oDrawUnknownModel, 0x354f30, this, pDrawCtxWrapper);
}

void CharacterManager::DrawCharacterIcons(IDrawContext* pDrawContext)
{
	FRPG2_CALL(oDrawCharacterIcons, 0x354f80, this, pDrawContext);
}

dl_bool CharacterManager::Initialize()
{
	return FRPG2_CALL(oInitialize, 0x359270, this);
}

void CharacterManager::ClearEntityListAndResources()
{
	FRPG2_CALL(oClearEntityListAndResources, 0x3596c0, this);
}