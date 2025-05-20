#include "GUIText.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef void(_fastcall* oFree)(GUIText* pThis);
	typedef void(_fastcall* oCopy)(GUIText* pThis, GUIText* pOther);
	typedef StringContainer*(_fastcall* oReset)(GUIText* pThis);
	typedef void(_fastcall* oFormatV)(GUIText* pThis, const dl_wchar* fmt, va_list args);

	GUIText::GUIText(const dl_wchar* text, dl_int charset)
	{
		this->pStringContainer = nullptr;
		this->text = text;
	}

	void GUIText::Free()
	{
		FRPG2_CALL(oFree, 0x523980, this);
	}

	void GUIText::SetText(GUIText* _other)
	{
		FRPG2_CALL(oCopy, 0x523850, this, _other);
	}

	StringContainer* GUIText::ClearAndBuildStringContainer()
	{
		return FRPG2_CALL(oReset, 0x524280, this);
	}

	void GUIText::Format(const dl_wchar* fmt, ...)
	{
		va_list args;
		va_start(args, fmt);

		FormatV(fmt, args);

		va_end(args);
	}

	void GUIText::FormatV(const dl_wchar* fmt, va_list args)
	{
		FRPG2_CALL(oFormatV, 0x524980, this, fmt, args);
	}
}