#pragma once
#include "../GUIObject/GUIObject.h"
#include "../GUITweakerDialog/GUITweakerDialog.h"

class AppGUISystem;
class AppGUIRootWindow;

namespace GuiFramework
{
	class GUIWindowManager : public GUIObject
	{
		AppGUISystem* m_pAppGUISystem;
		AppGUIRootWindow* m_pRootWindow;
		GUITweakerDialog* m_pActiveWindow;
		GUITweakerDialog* m_pLastActiveWindow;
		DLUT::DLVector<GUITweakerDialog*> m_pWindows;
		DLUT::DLVector<GUITweakerDialog*> m_pCreateWindows;
		dl_int16 m_sVar70;
		dl_int16 m_sVar72;
		dl_int m_mouseX;
		dl_int m_mouseY;
		dl_uint m_mouseActionFlags;
		dl_int m_iVar80;
		dl_int m_iVar84;
		GUITweakerDialog* m_pInteractingWindow;
		dl_uint m_interactingWindowIdx;
		DLUT::DLVector<dl_pointer> m_vVar98;
		DLUT::DLVector<dl_pointer> m_vVarB8;
		dl_int m_nextWindowX;
		dl_int m_nextWindowY;
		dl_int m_iVarE0;
		dl_int m_iVarE4;
		dl_uint m_width;
		dl_uint m_height;
		dl_int m_iVarF0;
		dl_float32 m_timeSinceLastClick;
		dl_float32 m_timeSinceLastClickPrev;
		dl_int m_lastClickX;
		dl_int m_lastClickY;

	public:
		dl_uint GetNumWindows() const { return m_pWindows.size(); }
		AppGUIRootWindow* GetAppGUIRootWindow() const { return this->m_pRootWindow; }

		GUITweakerDialog* GetWindow(int idx);
		GUITweakerDialog* FindWindowByName(const wchar_t* name);

		bool SetActiveWindow(GUITweakerDialog* pWnd);
	};
}