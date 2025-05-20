#include "GUIEditBox.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oAddGUIEditBox)(GUIEditBox* pThis, GUIWidget* pParent, GUIText* title, dl_uint numLines, dl_uint flags);

	GUIEditBox::GUIEditBox(GUIWidget* pParent, GUIText* title, dl_uint numLines, dl_uint flags)
	{
		FRPG2_CALL(oAddGUIEditBox, 0x5327d0, this, pParent, title, numLines, flags);
	}

	void GUIEditBox::DeleteLastCharacter()
	{
		this->m_pTextEditorUtil->DeleteLastCharacter();

		this->m_pTextEditorUtil->m_selectionEnd = this->m_pTextEditorUtil->m_iVar40;
		this->m_pTextEditorUtil->m_iVar48 = this->m_pTextEditorUtil->m_selectionStart;
	}

	void GUIEditBox::ClearText()
	{
		GUITextEditorUtil* pTextEditorUtil = this->m_pTextEditorUtil;

		for (size_t i = 0; i < pTextEditorUtil->m_lines.size(); i++)
		{
			const dl_wchar* line = pTextEditorUtil->m_lines[i];

			if (line != nullptr)
			{
				for (size_t i = wcslen(line); i > 0; i--)
					this->DeleteLastCharacter();
			}
		}
	}

	void GUIEditBox::InsertCharacters(const dl_wchar* chars)
	{
		this->m_pTextEditorUtil->InsertCharacters(chars, wcslen(chars));

		this->m_pTextEditorUtil->m_selectionEnd = this->m_pTextEditorUtil->m_iVar40;
		this->m_pTextEditorUtil->m_iVar48 = this->m_pTextEditorUtil->m_selectionStart;
	}

	void GUIEditBox::SetText(const dl_wchar* text, dl_uint lineIdx)
	{
		GUITextEditorUtil* pTextEditorUtil = this->m_pTextEditorUtil;

		if (lineIdx < pTextEditorUtil->m_lines.size())
		{
			const dl_wchar* line = pTextEditorUtil->m_lines[lineIdx];

			if (line)
			{
				if (wcscmp(line, text) != 0)
				{
					this->ClearText();
					this->InsertCharacters(text);
				}
			}
			else if (wcscmp(text, L"") != 0)
				this->InsertCharacters(text);
		}
	}

	const dl_wchar* GUIEditBox::GetText(dl_uint lineIdx)
	{
		GUITextEditorUtil* pTextEditorUtil = this->m_pTextEditorUtil;

		return pTextEditorUtil->m_lines[lineIdx];
	}

	void GUIEditBox::SetBackgroundText(const dl_wchar* text)
	{
		this->m_backgroundText.Free();
		this->m_backgroundText = GUIText(text);
	}
}