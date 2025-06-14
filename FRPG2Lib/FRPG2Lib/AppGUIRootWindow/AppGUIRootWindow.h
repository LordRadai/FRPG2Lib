#pragma once
#include "GuiFramework/GUIRootWindow/GUIRootWindow.h"
#include "AppGUISystem/AppGUISystem.h"

class AppGUIRootWindow : public GuiFramework::GUIRootWindow
{
	AppGUISystem* m_pAppGUISystem;
	dl_int m_iVar118;
	dl_int m_iVar11C;
	dl_int m_iVar120;

public:
	static void** GetVTableAddr() { return (void**)(MODULE_ADDR + 0x11dd908); }
};

typedef dl_int(_fastcall* oOnMouseClicked)(AppGUIRootWindow* pThis, GuiFramework::MousePosData* mousePos);
typedef dl_bool(_fastcall* oHandlePopUpMenuAction)(AppGUIRootWindow* pThis, dl_int actionID);