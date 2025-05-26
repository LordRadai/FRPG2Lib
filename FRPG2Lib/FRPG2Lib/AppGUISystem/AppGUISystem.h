#pragma once
#include "GuiFramework/GuiFramework.h"
#include "Draw/DrawContext.h"

class AppGUISystem : public GuiFramework::GUISystem
{
	struct ShaderResources
	{
		DLGR::DLVertexDeclaration* m_pVertexDecls[3];
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
	typedef void(_fastcall* oUpdate)(AppGUISystem* pThis, dl_float32 deltaTime);
	typedef void(_fastcall* oDraw)(AppGUISystem* pThis, IDrawContext* pDrawContext);
};