#pragma once
#include "../GUIMsgReceiver/GUIMsgReceiver.h"
#include "../GUIWindowManager/GUIWindowManager.h"
#include "../GUIWindowPainter/GUIWindowPainter.h"
#include "../GUIFont/GUIFont.h"
#include "../GUIStringStorage/TGUIStringStorage.inl"
#include "../Util/TGUIRect.inl"

namespace GuiFramework
{
	class GUISystem : public GUIMsgReceiver
	{
		class GUISystemEvents
		{
			DLUT::DLVector<dl_pointer> m_pEvents[31];
			DLUT::DLVector<dl_pointer> m_pVar3E0[2];
			dl_int m_state;
		};

		dl_int m_isDrawing;
		GUIWindowManager* m_pGUIWindowManager;
		GUIWindowPainter* m_pGUIWindowPainter;
		GUISystemEvents* m_pEvents;
		dl_uint* m_pVar30;
		dl_char* m_pVar38;
		DLMT::DL_COLOR_32* m_pColors;
		GUIFont** m_pFonts;
		dl_int m_iVar50;
		dl_float32 m_fVar54;
		DLTX::DLString m_string;
		dl_int16 m_sVar88;
		dl_int m_iVar8C;
		dl_int m_iVar90;
		dl_uint64 m_rng;
		TGUIStringStorage<dl_wchar> m_stringStorage;

	public:
		GUIWindowManager* GetWindowManager() const { return m_pGUIWindowManager; }
	};
}