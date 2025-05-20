#pragma once
#include "dantelion2/dantelion2.h"

namespace GuiFramework
{
	struct StringContainer
	{
		DLTX::DLString m_string;
		int m_init = 0;
	};

	struct GUIText
	{
		StringContainer* pStringContainer = nullptr;
		const dl_wchar* text = nullptr;

		GUIText() {}
		GUIText(const dl_wchar* text, dl_int charset = DLTX::CS_PLATFORM);

		/*
		 @brief: Free the string container.
		*/
		void Free();

		/*
		 @brief Set the text of the GUIText object.
		 @param _other: Pointer to another GUIText object.
		*/
		void SetText(GUIText* _other);

		/*
		 @brief Reset the string container and return it.
		 @return Pointer to the string container.
		*/
		StringContainer* ClearAndBuildStringContainer();

		void Format(const dl_wchar* fmt, ...);
		void FormatV(const dl_wchar* fmt, va_list args);
	};
}