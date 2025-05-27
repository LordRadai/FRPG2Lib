#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "../GUITextureViewer/GUITextureViewer.h"
#include "../GUIListView/GUIListView.h"

namespace GuiFramework
{
	class GUITextureList : public GUIWidget
	{
		GUITextureViewer* m_pTextureViewer;
		GUIListView* m_pListView;

	public:
		dl_int AddTexture(const dl_wchar* name, GUITexture* pTexture, const dl_wchar* path = L"");
	};
}