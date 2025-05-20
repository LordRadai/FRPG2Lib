#include "Scene.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oScene)(Scene* pThis, dl_uint sceneID);
typedef void(_fastcall* oSceneHandleMouseInputs)(Scene* pThis, dl_int* pInputData);

Scene::Scene(dl_int sceneID)
{
	FRPG2_CALL(oScene, 0xb3fa70, this, sceneID);
}

void Scene::HandleMouseInputs(dl_int* pInputData)
{
	FRPG2_CALL(oSceneHandleMouseInputs, 0xb3fc10, this, pInputData);
}