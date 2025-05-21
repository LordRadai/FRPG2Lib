#pragma once
#include "../GUIAutoVLayoutScroll/GUIAutoVLayoutScroll.h"
#include "../GUITweakerGroup/GUITweakerGroup.h"
#include "../GUITweakerGroupItem/GUITweakerGroupItem.h"
#include "../GUIWidget/GUIWidget.h"
#include "../GUIOnOffTweaker/TGUIOnOffTweaker.inl"
#include "../GUIMultiTweaker/TGUIMultiTweaker.inl"
#include "../GUIRangeTweaker/TGUIRangeTweaker.inl"
#include "../GUIComboTweaker/TGUIComboTweaker.inl"
#include "../GUIColorTweaker/TGUIColorTweaker.inl"
#include "../GUIPropertyLabel/TGUIPropertyLabel.inl"
#include "../GUIYawPitchTweaker/GUIYawPitchTweaker.h"
#include "../GUIEditBox/GUIEditBox.h"
#include "../GUIListView/GUIListView.h"
#include "../GUITextureViewer/GUITextureViewer.h"
#include "../GUITextureList/GUITextureList.h"
#include "../GUIHeapList/GUIHeapList.h"
#include "../GUITriggerTweaker/GUITriggerTweaker.h"

class AppGUIRootWindow;

namespace GuiFramework
{
	class GUITweakerDialog : public GUIAutoVLayoutScroll
	{
		DLUT::DLVector<GUITweakerGroup*> m_pTweakerGroups;
		DLUT::DLVector<GUITweakerGroupItem*> m_pTweakerGroupItems;

	public:
		GUITweakerDialog(AppGUIRootWindow* pAppGUIRootWindow, GUIText* title, dl_uint flags);

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(GUITweakerDialog), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		void PopStackLevel();
		GUITweakerGroup* GetLastTweakerGroup();

		GUITweakerGroup* AddTweakerGroup(const dl_wchar* title, dl_bool bExpanded = false);

		TGUIOnOffTweaker<dl_uchar>* AddOnOffTweaker(const dl_wchar* title, dl_bool* v);

		TGUIMultiTweaker<dl_float32>* AddMultiTweakerFloat(const dl_wchar* title, dl_int count, dl_float32* v, dl_float32 min = -999999.f, dl_float32 max = 999999.f, dl_float32 step = 0.0001f, dl_float32 mult = 1.f);
		TGUIMultiTweaker<dl_int>* AddMultiTweakerInt(const dl_wchar* title, dl_int count, dl_int* v, dl_int min = 0, dl_int max = 999999, dl_int step = 1, dl_float32 mult = 1.f);
		TGUIMultiTweaker<dl_uchar>* AddMultiTweakerByte(const dl_wchar* title, dl_int count, dl_uchar* v, dl_uchar min = 0, dl_uchar max = 255, dl_uchar step = 1, dl_float32 mult = 1.f);
		GUITweakerGroup* AddMultiTweakerFloatAlt(const dl_wchar* title, dl_int count, dl_float32* v, dl_float32 min = -999999.f, dl_float32 max = 999999.f, dl_float32 step = 0.0001f, dl_float32 mult = 1.f);
		GUITweakerGroup* AddMultiTweakerIntAlt(const dl_wchar* title, dl_int count, dl_int* v, dl_int min = 0, dl_int max = 999999, dl_int step = 1, dl_float32 mult = 1.f);
		GUITweakerGroup* AddMultiTweakerByteAlt(const dl_wchar* title, dl_int count, dl_uchar* v, dl_uchar min = 0, dl_uchar max = 255, dl_uchar step = 1, dl_float32 mult = 1.f);

		TGUIRangeTweaker<dl_uchar>* AddRangeTweakerByte(const dl_wchar* title, dl_uchar* v, dl_uchar min, dl_uchar max, dl_uchar step = 1, dl_float32 mult = 1.f);
		TGUIRangeTweaker<dl_int>* AddRangeTweakerInt(const dl_wchar* title, dl_int* v, dl_int min, dl_int max, dl_int step = 1, dl_float32 mult = 1.f);
		TGUIRangeTweaker<dl_float32>* AddRangeTweakerFloat(const dl_wchar* title, dl_float32* v, dl_float32 min, dl_float32 max, dl_float32 step, dl_float32 mult = 1.f);
		TGUIComboTweaker<dl_uchar>* AddComboTweakerByte(const dl_wchar* title, dl_uchar* v, dl_int count, TGUIComboItem<dl_uchar>* items);
		TGUIComboTweaker<dl_int>* AddComboTweakerInt(const dl_wchar* title, dl_int* v, dl_int count, TGUIComboItem<dl_int>* items);

		TGUIColorTweaker<DLMT::DL_COLOR_32>* AddColorTweakerU32(const dl_wchar* title, uint32_t* v, dl_bool bExpanded = false);
		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* AddColorTweakerU8(const dl_wchar* title, dl_uchar* v, dl_bool bExpanded = false);
		TGUIColorTweaker<DLMT::DL_VECTOR4>* AddColorTweakerVector4(const dl_wchar* title, dl_float32* v, dl_bool bExpanded = false);

		GUITriggerTweaker* AddTriggerTweaker(const dl_wchar* title);
		GUITriggerTweaker* AddSingleButton(const dl_wchar* title, GUICallbackObjectBase* GUICallbackObject);

		GUIYawPitchTweaker* AddYawPitchTweaker(const dl_wchar* title, dl_float32* v);

		GUIEditBox* AddEditBox(const dl_wchar* text, dl_bool read_only = false);
		GUIEditBox* AddLabelEditBox(const dl_wchar* title, const dl_wchar* text, dl_bool bReadOnly = false);

		GUIListView* AddListView(const dl_wchar* title, short titleWidth, UINT style_flags = 0);
		GUIHeapList* AddHeapList(const dl_wchar* title);

		GUITextureViewer* AddTextureViewer(const dl_wchar* title, GUITexture* pTexture);
		GUITextureViewer* AddDLTexture2DViewer(const dl_wchar* title, DLGR::DLTexture2D* pTexture);
		GUITweakerGroup* AddRenderToTextureViewer(const dl_wchar* title, GXRenderToTexture* pGXRenderToTexture);

		GUITextureList* AddTextureList(const dl_wchar* title);

		TGUIPropertyLabel<dl_uchar>* AddPropertyLabelByte(const dl_wchar* title, dl_uchar* v);
		TGUIPropertyLabel<dl_int16>* AddPropertyLabelShort(const dl_wchar* title, short* v);
		TGUIPropertyLabel<dl_int>* AddPropertyLabelInt(const dl_wchar* title, dl_int* v);
		TGUIPropertyLabel<dl_float32>* AddPropertyLabelFloat(const dl_wchar* title, dl_float32* v);
		TGUIPropertyLabel<const dl_char*>* AddPropertyLabelString(const dl_wchar* title, const char** v);
		TGUIPropertyLabel<const dl_wchar*>* AddPropertyLabelWideString(const dl_wchar* title, const dl_wchar** v);
		TGUIPropertyLabel<DLMT::DL_VECTOR3>* AddPropertyLabelVector3(const dl_wchar* title, DLMT::DL_VECTOR3* v);
		TGUIPropertyLabel<DLMT::DL_VECTOR4>* AddPropertyLabelVector4(const dl_wchar* title, DLMT::DL_VECTOR4* v);

		GUITriggerTweaker* AddLabel(const dl_wchar* title);
	};
}