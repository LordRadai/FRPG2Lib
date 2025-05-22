#pragma once
#include "../GUIMsgReceiver/GUIMsgReceiver.h"
#include "../GUIWindowManager/GUIWindowManager.h"
#include "../GUIWindowPainter/GUIWindowPainter.h"
#include "../GUIFont/GUIFont.h"
#include "../GUIStringStorage/TGUIStringStorage.inl"
#include "../GUIPopUpMenuNode/GUIPopUpMenuNode.h"
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

	protected:
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

		GUITweakerDialog* AddTweakerDialog(const dl_wchar* title, dl_bool bUnique = true, dl_int width = 290, dl_int m_height = 400, dl_uint flags = GuiFramework::GUITweakerBase::GuiStyleFlags_Invisible | GuiFramework::GUITweakerBase::GuiStyleFlags_Titlebar | GuiFramework::GUITweakerBase::GuiStyleFlags_3DFrame | GuiFramework::GUITweakerBase::GuiStyleFlags_VScrollbar | GuiFramework::GUITweakerBase::GuiStyleFlags_Collapse | GuiFramework::GUITweakerBase::GuiStyleFlags_Destroy);
		GUIPopUpMenuNode* AddPopUpMenuNode(const dl_wchar* title, dl_uint flags = 0);
		dl_bool IsGUIOpen();

		/*
		* @brief Create GUISystem editor window.
		* Make sure to allocate enough space in the heap for the window!
		*/
		void CreateSystemEditorGUI();
	};
}