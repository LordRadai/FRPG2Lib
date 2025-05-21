#include "GUISystem.h"
#include "FRPG2Globals.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oCreateGUISystemValueEditorGroup)(GUISystem* pThis, GUITweakerDialog* pWnd);

	GUITweakerDialog* GUISystem::AddTweakerDialog(const dl_wchar* title, dl_bool bUnique, dl_int width, dl_int height, dl_uint flags)
	{
		GUIWindowManager* pGUIWindowManager = this->GetWindowManager();

		if (bUnique && (pGUIWindowManager->FindWindowByName(title) != nullptr))
			return nullptr;

		AppGUIRootWindow* pAppGUIRootWindow = pGUIWindowManager->GetAppGUIRootWindow();

		GUIText guiText(title);

		GUITweakerDialog* pWnd = nullptr;

		if (pAppGUIRootWindow)
		{
			pWnd = new GUITweakerDialog(pAppGUIRootWindow, &guiText, flags);

			dl_int pos_x = pWnd->m_position.m_min[0];
			dl_int pos_y = pWnd->m_position.m_min[1];

			pWnd->EditPosSize(pos_x, pos_y, width, height);
		}

		guiText.Free();

		return pWnd;
	}

	GUIPopUpMenuNode* GUISystem::AddPopUpMenuNode(const dl_wchar* title, dl_uint flags)
	{
		GUIText guiText(title);
		GUIPopUpMenuNode* pPopUpMenuNode = new GUIPopUpMenuNode(this, &guiText, flags);
		guiText.Free();

		return pPopUpMenuNode;
	}

	dl_bool GUISystem::IsGUIOpen()
	{
		if (this->m_pGUIWindowManager)
			return this->m_pGUIWindowManager->GetNumWindows() > 1;

		return false;
	}

	void GUISystem::CreateSystemEditorGUI()
	{
		GUITweakerDialog* pWnd = this->AddTweakerDialog(L"SystemValue");

		if (pWnd)
			FRPG2_CALL(oCreateGUISystemValueEditorGroup, 0x52b640, this, pWnd);
	}
}