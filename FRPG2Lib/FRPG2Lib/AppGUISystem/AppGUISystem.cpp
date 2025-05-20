#include "AppGUISystem.h"
#include "FRPG2Globals.h"
#include "MainApp/MainApp.h"

GuiFramework::GUITweakerDialog* AppGUISystem::AddTweakerDialog(const dl_wchar* title, dl_int width, dl_int height, dl_uint flags)
{
	GuiFramework::GUIWindowManager* pGUIWindowManager = this->GetWindowManager();
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