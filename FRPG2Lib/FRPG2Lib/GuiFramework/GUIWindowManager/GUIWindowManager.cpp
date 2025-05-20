#include "GUIWindowManager.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef bool(_fastcall* oSetActiveWindow)(GUIWindowManager* pThis, GUITweakerDialog* pWnd);

	GUITweakerDialog* GUIWindowManager::GetWindow(int idx)
	{
		if (idx == 0)
			return nullptr;

		if (idx < this->m_pWindows.size())
			return this->m_pWindows[idx];

		return nullptr;
	}

	GUITweakerDialog* GUIWindowManager::FindWindowByName(const wchar_t* name)
	{
		for (size_t i = 1; i < this->m_pWindows.size(); i++)
		{
			if (this->m_pWindows[i]->GetName() == name)
				return m_pWindows[i];
		}

		return nullptr;
	}

	bool GUIWindowManager::SetActiveWindow(GUITweakerDialog* pWnd)
	{
		return FRPG2_CALL(oSetActiveWindow, 0x56bf60, this, pWnd);
	}
}