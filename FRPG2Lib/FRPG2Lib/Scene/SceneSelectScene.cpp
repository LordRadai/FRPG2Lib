#include "SceneSelectScene.h"
#include "AppGUISystem/AppGUISystem.h"
#include "MainApp/MainApp.h"

void SceneSelectScene::Initialise()
{
	if (this->m_bInit)
		return;

	AppGUISystem* pAppGUISystem = KATANA_MAIN_APP->m_pAppGUISystem;

	GuiFramework::GUITweakerDialog* pSceneSelectWindow = pAppGUISystem->AddTweakerDialog(L"SceneSelect", true, 360, 530, GuiFramework::GUITweakerBase::GuiStyleFlags_Invisible | GuiFramework::GUITweakerBase::GuiStyleFlags_Titlebar | GuiFramework::GUITweakerBase::GuiStyleFlags_3DFrame | GuiFramework::GUITweakerBase::GuiStyleFlags_VScrollbar | GuiFramework::GUITweakerBase::GuiStyleFlags_Collapse);
	this->m_pSceneSelectWindow = pSceneSelectWindow;

	if (pSceneSelectWindow)
	{
		GuiFramework::GUITweakerGroup* pMainGroup = pSceneSelectWindow->AddTweakerGroup(L"Main");

		if (pMainGroup)
		{
			pSceneSelectWindow->PopStackLevel();
		}
	}
}

void SceneSelectScene::Update(float deltaTime)
{
	this->Initialise();
}

void SceneSelectScene::Draw(IDrawContext* pDrawContext)
{
	pDrawContext->ClearRenderTargetsView(1, RGB(31, 48, 0));
}