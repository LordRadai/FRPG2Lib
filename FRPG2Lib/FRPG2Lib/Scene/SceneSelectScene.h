#pragma once
#include "Scene.h"
#include "Memory/Memory.h"
#include "GuiFramework/GuiFramework.h"

class SceneSelectScene : public Scene
{
    dl_bool m_bInit = false;
    GuiFramework::GUITweakerDialog* pSceneSelectWindow = nullptr;

public:
	SceneSelectScene(dl_uint sceneID) : Scene(sceneID) {};
	~SceneSelectScene() {};

    static void* operator new(size_t size)
    {
        return DLKR::AllocateAligned(sizeof(SceneSelectScene), 8, GetRootHeap(HEAPTYPE_SYSTEM));
    }

    static void operator delete(void* block)
    {
        return DLKR::Free(block, GetRootHeap(HEAPTYPE_SYSTEM));
    }

	void Initialise();
    void Update(float deltaTime);
    void Draw(IDrawContext* pDrawContext);
};