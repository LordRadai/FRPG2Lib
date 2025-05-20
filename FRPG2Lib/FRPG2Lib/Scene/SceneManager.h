#pragma once
#include "Scene.h"

class SceneManager
{
	void** _vfptr;
	Scene* m_pScene;
	Scene* m_pTempScene;
	Scene* m_pCopyOfScene;

public:
	void SetScene(Scene* pScene);
};