#pragma once
#include "ModelTestSceneImpl.h"
#include "Scene.h"

class ModelTestScene : public Scene
{
public:
	ModelTestSceneImpl* m_pModelTestSceneImpl;
	DLTX::DLString m_initMapName;
	dl_int m_iVar70;
	CharacterManager::CharacterResources m_characterResources;

	virtual ~ModelTestScene();
	virtual void Initialise();
	virtual void Update(float deltaTime);
	virtual void Draw(IDrawContext* pDrawContext);
	virtual void vfunction4(DLGR::DLDrawDevice* pDrawDevice);
	virtual void DestroySceneImpl();
	virtual dl_bool vfunction6();
	virtual void vfunction9();
	virtual void HandleMouseInputs(dl_int* pInputData);
	virtual dl_pointer GetRuntimeClassImpl();
};