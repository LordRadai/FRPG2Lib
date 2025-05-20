#pragma once
#include "dantelion2/dantelion2.h"
#include "Draw/DrawContext.h"

class Scene
{
	dl_int m_sceneID;
	dl_pointer m_pVar10;
	dl_pointer m_pVar18;
	dl_pointer m_pVar20;
	dl_pointer m_pVar28;
	dl_pointer m_pVar30;

public:
	Scene() {};
	Scene(dl_int sceneID);

	virtual ~Scene() {};
	virtual void Initialise() {};
	virtual void Update(float deltaTime) {};
	virtual void Draw(IDrawContext* pDrawContext) {};
	virtual void vfunction4(DLGR::DLDrawDevice* pDrawDevice) {};
	virtual void DestroySceneImpl() {};
	virtual bool vfunction6() { return true; }
	virtual void vfunction7() {};
	virtual void vfunction8() {};
	virtual void vfunction9() {};
	virtual void HandleMouseInputs(dl_int* pInputData);
};