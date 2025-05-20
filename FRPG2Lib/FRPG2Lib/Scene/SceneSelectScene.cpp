#include "SceneSelectScene.h"
#include "AppGUISystem/AppGUISystem.h"

void SceneSelectScene::Initialise()
{
	if (this->m_bInit)
		return;

	/*
	UINT64 pKatanaMainApp = *(UINT64*)((UINT64)g_moduleAddr + 0x16751F8);
	UINT64 pAppGUISystem = *(UINT64*)(pKatanaMainApp + 0x88);

	GUIWindowManager* pGUIWindowManager = *(GUIWindowManager**)(pAppGUISystem + 0x18);

	dl_pointer AppGUIRootWindow = pGUIWindowManager->GetAppGUIRootWindow();

	if (AppGUIRootWindow)
	{
		this->pSceneSelectWindow = AppGUISystem::CreateGuiWindow(L"SceneSelect", 360, 530, GuiFramework::GUITweakerBase::GuiStyleFlags_Invisible | GuiFramework::GUITweakerBase::GuiStyleFlags_Titlebar | GuiFramework::GUITweakerBase::GuiStyleFlags_3DFrame | GuiFramework::GUITweakerBase::GuiStyleFlags_VScrollbar | GuiFramework::GUITweakerBase::GuiStyleFlags_Collapse, true);

		GuiFramework::GUITweakerGroup* pMainGroup = AppGUISystem::AddGuiGroup(this->pSceneSelectWindow, L"Main", true);

		if (pMainGroup)
		{
			this->pSceneSelectWindow->PopStackLevel();
		}

		this->m_bInit = true;
	}
	*/
}

void SceneSelectScene::Update(float deltaTime)
{
	this->Initialise();
}

void SceneSelectScene::Draw(IDrawContext* pDrawContext)
{
	pDrawContext->ClearRenderTargetsView(1, RGB(31, 48, 0));
}