#pragma once
#include "dantelion2/dantelion2.h"
#include "Draw/DrawContext.h"

class DebugManager
{
public:
	struct ShaderPreset
	{
		DLGR::DLVertexDeclaration** m_ppVertexDecl;
		DLGR::DLVertexShader** m_ppVertexShader;
		DLGR::DLPixelShader** m_ppPixelShader;
	};

	struct Resources
	{
		DLKR::DLAllocator* m_pAllocator;
		ShaderPreset m_presets[7];
		DLGR::DLVertexDeclaration** m_ppVertexDeclList[3];
		DLGR::DLVertexShader** m_ppVertexShaderList[5];
		DLGR::DLPixelShader** m_ppPixelShaderList[3];
	};

	DebugManager();

	virtual ~DebugManager();
	virtual void Update(dl_float32 deltaTime);
	virtual dl_bool Initialize();
	virtual void Finalize();

	void ApplyPreset(IDrawContext* pDrawContext, dl_uint preset);
private:
	Resources m_resources;
	dl_int m_iVar110;
	dl_bool m_bVar114;
	dl_bool m_bVar115;
	dl_bool m_bVar116;
};