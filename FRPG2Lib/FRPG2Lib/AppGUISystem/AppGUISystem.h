#pragma once
#include "GuiFramework/GuiFramework.h"
#include "Draw/DrawContext.h"

class AppGUISystem : public GuiFramework::GUISystem
{
	struct ShaderResources
	{
		DLGR::DLVertexDecl* m_pVertexDecls[3];
		DLGR::DLVertexShader* m_pVertexShaders[3];
		DLGR::DLPixelShader* m_pPixelShaders[10];
	};

	struct FontDrawContextSyncObject : public DLKR::DLDummySyncObject
	{
		dl_uchar m_data[648];
	};

	ShaderResources m_shaderResources;
	FontDrawContextSyncObject m_fontDrawContextSyncObject;
	dl_pointer m_pVarB30;
	HCURSOR m_cursors[14];
	dl_pointer m_pVarA8;
	dl_pointer m_pVarB0;
	DLKR::DLAllocator* m_pAllocator;

public:
	GuiFramework::GUITweakerDialog* AddTweakerDialog(const dl_wchar* title, dl_bool bUnique = false, dl_int width = 290, dl_int m_height = 400, dl_uint flags = GuiFramework::GUITweakerBase::GuiStyleFlags_Invisible | GuiFramework::GUITweakerBase::GuiStyleFlags_Titlebar | GuiFramework::GUITweakerBase::GuiStyleFlags_3DFrame | GuiFramework::GUITweakerBase::GuiStyleFlags_VScrollbar | GuiFramework::GUITweakerBase::GuiStyleFlags_Collapse | GuiFramework::GUITweakerBase::GuiStyleFlags_Destroy);
	GuiFramework::GUIPopUpMenuNode* AddPopUpMenuNode(const dl_wchar* title, dl_uint flags = 0);
	dl_bool IsGUIOpen();
	void CreateSystemEditorGUI();

	typedef void(_fastcall* oUpdate)(AppGUISystem* pThis, dl_float32 deltaTime);
	typedef void(_fastcall* oDraw)(AppGUISystem* pThis, IDrawContext* pDrawContext);
};