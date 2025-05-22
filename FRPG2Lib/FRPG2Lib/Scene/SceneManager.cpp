#include "SceneManager.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oSetScene)(SceneManager* pThis, Scene* pScene);
typedef void(_fastcall* oDestroyScene)(SceneManager* pThis);

void SceneManager::SetScene(Scene* pScene)
{
	FRPG2_CALL(oSetScene, 0xb314c0, this, pScene);
}

void SceneManager::DestroyScene()
{
	FRPG2_CALL(oDestroyScene, 0xb315f0, this);
}