#pragma once
#include "../GUIMsgReceiver/GUIMsgReceiver.h"
#include "../GUIFont/GUIFont.h"

namespace GuiFramework
{
	class GUITextEditorUtil : public GUIMsgReceiver
	{
	public:
		dl_pointer m_pAppGUISystem;
		DLUT::DLVector<dl_wchar*> m_lines;
		GUIFont* m_pFont;
		dl_int m_iVar40;
		dl_int m_selectionStart;
		dl_int m_iVar48;
		dl_int m_selectionEnd;
		dl_int m_iVar50;
		dl_int m_iVar54;
		dl_int m_iVar58;
		dl_int m_iVar5C;
		dl_int m_iVar60;
		dl_int m_iVar64;

		void InsertCharacters(const dl_wchar* chars, dl_uint num);
		void DeleteLastCharacter();
	};
}