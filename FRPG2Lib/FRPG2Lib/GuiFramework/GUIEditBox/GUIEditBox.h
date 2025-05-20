#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "../GUITextEditorUtil/GUITextEditorUtil.h"

namespace GuiFramework
{
	class GUIEditBox : public GUIWidget
	{
		GUITextEditorUtil* m_pTextEditorUtil;
		dl_pointer m_pVar118;
		GUIText m_backgroundText;
		TGUI_RECT<dl_uint16> m_rVar130;
		dl_int16 m_sVar138;
		dl_int16 m_sVar13A;
		dl_int m_editFlags;

	public:
		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUIEditBox), 8, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		GUIEditBox(GUIWidget* pParent, GUIText* title, dl_uint numLines, dl_uint flags);

		void InsertCharacters(const dl_wchar* text);
		void DeleteLastCharacter();
		void ClearText();
		void SetText(const dl_wchar* text, dl_uint lineIdx = 0);
		const dl_wchar* GetText(dl_uint lineIdx = 0);
		void SetBackgroundText(const dl_wchar* text);
	};
}