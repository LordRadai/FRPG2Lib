#pragma once
#include "Scene.h"

class SceneManager
{
	void** _vfptr;
	Scene* m_pScene;
	Scene* m_pTempScene;
	Scene* m_pCopyOfScene;

public:
	Scene* GetScene() const { return m_pScene; }
	void SetScene(Scene* pScene);
	void DestroyScene();
};