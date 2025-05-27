#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "../GUITexture/GUITexture.h"

namespace GuiFramework
{
	class GUITextureViewer : public GUIWidget
	{
		GUITexture* m_pTexture;
		dl_int m_iVar118;
		dl_int16 m_iVar11C;
		dl_int16 m_iVar11E;
		dl_int16 m_iVar120;
		dl_int m_iVar124;
		dl_int m_iVar128;
		dl_int m_iVar12C;
		dl_int m_iVar130;
		dl_uint m_showInfoOptions;
		dl_int m_fitOptions;

	public:
		void SetTexture(GUITexture* pTexture);
	};
}