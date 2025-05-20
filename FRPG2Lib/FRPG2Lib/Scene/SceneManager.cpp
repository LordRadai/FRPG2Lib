#include "SceneManager.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oSetScene)(SceneManager* pSceneManager, Scene* pScene);

void SceneManager::SetScene(Scene* pScene)
{
	FRPG2_CALL(oSetScene, 0xb314c0, this, pScene);
}