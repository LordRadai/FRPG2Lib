#include "AppGUISystem.h"
#include "FRPG2Globals.h"
#include "MainApp/MainApp.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oCreateGUISystemValueEditorGroup)(AppGUISystem* pThis, GuiFramework::GUITweakerDialog* pWnd);

GuiFramework::GUITweakerDialog* AppGUISystem::AddTweakerDialog(const dl_wchar* title, dl_bool bUnique, dl_int width, dl_int height, dl_uint flags)
{
	GuiFramework::GUIWindowManager* pGUIWindowManager = this->GetWindowManager();

	if (bUnique && (pGUIWindowManager->FindWindowByName(title) != nullptr))
		return nullptr;

	AppGUIRootWindow* pAppGUIRootWindow = pGUIWindowManager->GetAppGUIRootWindow();

	GuiFramework::GUIText guiText(title);

	GuiFramework::GUITweakerDialog* pWnd = nullptr;

	if (pAppGUIRootWindow)
	{
		pWnd = new GuiFramework::GUITweakerDialog(pAppGUIRootWindow, &guiText, flags);

		dl_int pos_x = pWnd->m_position.m_min[0];
		dl_int pos_y = pWnd->m_position.m_min[1];

		pWnd->EditPosSize(pos_x, pos_y, width, height);
	}

	guiText.Free();

	return pWnd;
}

GuiFramework::GUIPopUpMenuNode* AppGUISystem::AddPopUpMenuNode(const dl_wchar* title, dl_uint flags)
{
	GuiFramework::GUIText guiText(title);
	GuiFramework::GUIPopUpMenuNode* pPopUpMenuNode = new GuiFramework::GUIPopUpMenuNode(this, &guiText, flags);
	guiText.Free();

	return pPopUpMenuNode;
}

dl_bool AppGUISystem::IsGUIOpen()
{
	if (this->m_pGUIWindowManager)
		return this->m_pGUIWindowManager->GetNumWindows() > 1;

	return false;
}

void AppGUISystem::CreateSystemEditorGUI()
{
	GuiFramework::GUITweakerDialog* pWnd = this->AddTweakerDialog(L"SystemValue");

	if (pWnd)
		FRPG2_CALL(oCreateGUISystemValueEditorGroup, 0x52b640, this, pWnd);
}