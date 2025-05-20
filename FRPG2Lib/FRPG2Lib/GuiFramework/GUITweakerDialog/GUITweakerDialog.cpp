#include "GUITweakerDialog.h"
#include "FRPG2Call.h"
#include "AppGUIRootWindow/AppGUIRootWindow.h"

namespace GuiFramework
{
	typedef void(_fastcall* oCreateGUIWindow)(GUITweakerDialog* pThis, AppGUIRootWindow* pAppGUIRootWindow, GUIText* title, dl_uint flags);
	typedef void(_fastcall* oResetStackLevel)(GUITweakerDialog* pThis);
	typedef GUITweakerGroup*(_fastcall* oAddGroup)(GUITweakerDialog* pThis, GUIText* title, dl_bool bExpanded);
	typedef GUITweakerGroup*(_fastcall* oGetLastTweakerGroup)(GUITweakerDialog* pThis);

	typedef TGUIOnOffTweaker<dl_uchar>* (_fastcall* oAddOnOffTweaker)(GUITweakerGroup* pThis, GUIText* title, dl_bool* v);
	typedef TGUIColorTweaker<DLMT::DL_COLOR_32>* (_fastcall* oAddColorTweakerU32)(GUITweakerGroup* pThis, GUIText* title, uint32_t* v, dl_bool expanded);
	typedef TGUIColorTweaker<DLMT2::DL_COLOR_U8>* (_fastcall* oAddColorTweakerU8)(GUITweakerGroup* pThis, GUIText* title, dl_uchar* v, dl_bool expanded);
	typedef TGUIColorTweaker<DLMT::DL_VECTOR4>* (_fastcall* oAddColorTweakerVector4)(GUITweakerGroup* pThis, GUIText* title, dl_float32* v, dl_bool expanded);
	typedef GUITriggerTweaker* (_fastcall* oAddTriggerTweaker)(GUITweakerGroup* pThis, GUIText* title);
	typedef GUIYawPitchTweaker* (_fastcall* oAddYawPitchRollTweaker)(GUITweakerGroup* pThis, GUIText* title, dl_float32* v, dl_uint16 param_4);
	typedef GUITextureViewer* (_fastcall* oAddTextureViewer)(GUITweakerGroup* pThis, GUIText* title, GUITexture* pTexture);
	typedef GUITextureList* (_fastcall* oAddTextureList)(GUITweakerGroup* pThis, GUIText* title);

	GUITweakerDialog::GUITweakerDialog(AppGUIRootWindow* pAppGUIRootWindow, GUIText* title, dl_uint flags)
	{
		FRPG2_CALL(oCreateGUIWindow, 0x538a30, this, pAppGUIRootWindow, title, flags);
	}

	void GUITweakerDialog::PopStackLevel()
	{
		FRPG2_CALL(oResetStackLevel, 0x538d60, this);
	}

	GUITweakerGroup* GUITweakerDialog::AddTweakerGroup(const dl_wchar* title, bool bExpanded)
	{
		GUIText label(title);

		GUITweakerGroup* pGroup = FRPG2_CALL(oAddGroup, 0x538c40, this, &label, bExpanded);

		label.Free();

		return pGroup;
	}

	GUITweakerGroup* GUITweakerDialog::GetLastTweakerGroup()
	{
		return FRPG2_CALL(oGetLastTweakerGroup, 0x539650, this);
	}

	TGUIOnOffTweaker<dl_uchar>* GUITweakerDialog::AddOnOffTweaker(const dl_wchar* title, dl_bool* v)
	{
		GUIText guiTextItem(title);

		TGUIOnOffTweaker<dl_uchar>* pTweaker = FRPG2_CALL(oAddOnOffTweaker, 0x563770, this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return pTweaker;
	}

	TGUIMultiTweaker<dl_float32>* GUITweakerDialog::AddMultiTweakerFloat(const dl_wchar* title, dl_int count, dl_float32* v, dl_float32 min, dl_float32 max, dl_float32 step, dl_float32 mult)
	{
		GUIText guiTextItem(title);

		TGUIMultiTweaker<dl_float32>* multiTweaker = new TGUIMultiTweaker<dl_float32>(this->GetLastTweakerGroup(), &guiTextItem, count, v, min, max, step, mult);

		guiTextItem.Free();

		return multiTweaker;
	}

	TGUIMultiTweaker<dl_int>* GUITweakerDialog::AddMultiTweakerInt(const dl_wchar* title, dl_int count, dl_int* v, dl_int min, dl_int max, dl_int step, dl_float32 mult)
	{
		GUIText guiTextItem(title);

		TGUIMultiTweaker<dl_int>* multiTweaker = new TGUIMultiTweaker<dl_int>(this->GetLastTweakerGroup(), &guiTextItem, count, v, min, max, step, mult);

		guiTextItem.Free();

		return multiTweaker;
	}

	TGUIMultiTweaker<dl_uchar>* GUITweakerDialog::AddMultiTweakerByte(const dl_wchar* title, dl_int count, dl_uchar* v, dl_uchar min, dl_uchar max, dl_uchar step, dl_float32 mult)
	{
		GUIText guiTextItem(title);

		TGUIMultiTweaker<dl_uchar>* multiTweaker = new TGUIMultiTweaker<dl_uchar>(this->GetLastTweakerGroup(), &guiTextItem, count, v, min, max, step, mult);

		guiTextItem.Free();

		return multiTweaker;
	}

	GUITweakerGroup* GUITweakerDialog::AddMultiTweakerFloatAlt(const dl_wchar* title, dl_int count, dl_float32* v, dl_float32 min, dl_float32 max, dl_float32 step, dl_float32 mult)
	{
		GUITweakerGroup* pGroup = this->AddTweakerGroup(title, true);

		for (size_t i = 0; i < count; i++)
			this->AddMultiTweakerFloat(L"", 1, &v[i], min, max, step, mult);

		this->PopStackLevel();

		return pGroup;
	}

	GUITweakerGroup* GUITweakerDialog::AddMultiTweakerIntAlt(const dl_wchar* title, dl_int count, dl_int* v, dl_int min, dl_int max, dl_int step, dl_float32 mult)
	{
		GUITweakerGroup* pGroup = this->AddTweakerGroup(title, true);

		for (size_t i = 0; i < count; i++)
			this->AddMultiTweakerInt(L"", 1, &v[i], min, max, step, mult);

		this->PopStackLevel();

		return pGroup;
	}

	GUITweakerGroup* GUITweakerDialog::AddMultiTweakerByteAlt(const dl_wchar* title, dl_int count, dl_uchar* v, dl_uchar min, dl_uchar max, dl_uchar step, dl_float32 mult)
	{
		GUITweakerGroup* pGroup = this->AddTweakerGroup(title, true);

		for (size_t i = 0; i < count; i++)
			this->AddMultiTweakerByte(L"", 1, &v[i], min, max, step, mult);

		this->PopStackLevel();

		return pGroup;
	}

	TGUIRangeTweaker<dl_uchar>* GUITweakerDialog::AddRangeTweakerByte(const dl_wchar* title, dl_uchar* v, dl_uchar min, dl_uchar max, dl_uchar step, dl_float32 mult)
	{
		GUIText guiTextItem(title);

		TGUIRangeTweaker<dl_uchar>* rangeTweaker = new TGUIRangeTweaker<dl_uchar>(this->GetLastTweakerGroup(), &guiTextItem, v, min, max, step, 1.f);

		guiTextItem.Free();

		return rangeTweaker;
	}

	TGUIRangeTweaker<dl_int>* GUITweakerDialog::AddRangeTweakerInt(const dl_wchar* title, dl_int* v, dl_int min, dl_int max, dl_int step, dl_float32 mult)
	{
		GUIText guiTextItem(title);

		TGUIRangeTweaker<dl_int>* rangeTweaker = new TGUIRangeTweaker<dl_int>(this->GetLastTweakerGroup(), &guiTextItem, v, min, max, step, 1.f);
		guiTextItem.Free();

		return rangeTweaker;
	}

	TGUIRangeTweaker<dl_float32>* GUITweakerDialog::AddRangeTweakerFloat(const dl_wchar* title, dl_float32* v, dl_float32 min, dl_float32 max, dl_float32 step, dl_float32 mult)
	{
		GUIText guiTextItem(title);

		TGUIRangeTweaker<dl_float32>* rangeTweaker = new TGUIRangeTweaker<dl_float32>(this->GetLastTweakerGroup(), &guiTextItem, v, min, max, step, 1.f);
		guiTextItem.Free();

		return rangeTweaker;
	}

	TGUIComboTweaker<dl_uchar>* GUITweakerDialog::AddComboTweakerByte(const dl_wchar* title, dl_uchar* v, dl_int count, TGUIComboItem<dl_uchar>* items)
	{
		GUIText guiTextItem(title);

		TGUIComboTweaker<dl_uchar>* combo = new TGUIComboTweaker<dl_uchar>(this->GetLastTweakerGroup(), &guiTextItem, v, items, count);
		guiTextItem.Free();

		return combo;
	}

	TGUIComboTweaker<dl_int>* GUITweakerDialog::AddComboTweakerInt(const dl_wchar* title, dl_int* v, dl_int count, TGUIComboItem<dl_int>* items)
	{
		GUIText guiTextItem(title);

		TGUIComboTweaker<dl_int>* combo = new TGUIComboTweaker<dl_int>(this->GetLastTweakerGroup(), &guiTextItem, v, items, count);
		guiTextItem.Free();

		return combo;
	}

	TGUIColorTweaker<DLMT::DL_COLOR_32>* GUITweakerDialog::AddColorTweakerU32(const dl_wchar* title, uint32_t* v, dl_bool bExpanded)
	{
		GUIText guiTextItem(title);

		TGUIColorTweaker<DLMT::DL_COLOR_32>* color_tweaker = FRPG2_CALL(oAddColorTweakerU32, 0x54b900, this->GetLastTweakerGroup(), &guiTextItem, v, bExpanded);
		guiTextItem.Free();

		return color_tweaker;
	}

	TGUIColorTweaker<DLMT2::DL_COLOR_U8>* GUITweakerDialog::AddColorTweakerU8(const dl_wchar* title, dl_uchar* v, dl_bool bExpanded)
	{
		GUIText guiTextItem(title);

		TGUIColorTweaker<DLMT2::DL_COLOR_U8>* color_tweaker = FRPG2_CALL(oAddColorTweakerU8, 0x54ba40, this->GetLastTweakerGroup(), &guiTextItem, v, bExpanded);
		guiTextItem.Free();

		return color_tweaker;
	}

	TGUIColorTweaker<DLMT::DL_VECTOR4>* GUITweakerDialog::AddColorTweakerVector4(const dl_wchar* title, dl_float32* v, dl_bool bExpanded)
	{
		GUIText guiTextItem(title);

		TGUIColorTweaker<DLMT::DL_VECTOR4>* color_tweaker = FRPG2_CALL(oAddColorTweakerVector4, 0x54bb80, this->GetLastTweakerGroup(), &guiTextItem, v, bExpanded);
		guiTextItem.Free();

		return color_tweaker;
	}

	GUITriggerTweaker* GUITweakerDialog::AddTriggerTweaker(const dl_wchar* title)
	{
		GUIText guiTextItem(title);

		GUITriggerTweaker* TriggerTweaker = FRPG2_CALL(oAddTriggerTweaker, 0x54cf60, this->GetLastTweakerGroup(), &guiTextItem);
		guiTextItem.Free();

		return TriggerTweaker;
	}

	GUITriggerTweaker* GUITweakerDialog::AddSingleButton(const dl_wchar* title, GUICallbackObjectBase* GUICallbackObject)
	{
		GUITriggerTweaker* pGroup = this->AddTriggerTweaker(L"");

		if (pGroup)
			pGroup->AddButton(title, GUICallbackObject);

		return pGroup;
	}

	GUIYawPitchTweaker* GUITweakerDialog::AddYawPitchTweaker(const dl_wchar* title, dl_float32* v)
	{
		GUIText guiTextItem(title);

		GUIYawPitchTweaker* YawPitchTweaker = FRPG2_CALL(oAddYawPitchRollTweaker, 0x54c580, this->GetLastTweakerGroup(), &guiTextItem, v, 0);
		guiTextItem.Free();

		return YawPitchTweaker;
	}

	GUIEditBox* GUITweakerDialog::AddEditBox(const dl_wchar* text, dl_bool bReadOnly)
	{
		dl_uint flags = GUITweakerBase::GuiStyleFlags_TransparentBg | GUITweakerBase::GuiStyleFlags_TitlebarFrame;

		if (bReadOnly)
			flags |= GUITweakerBase::GuiStyleFlags_NoInteract;

		GUIText guiTextItem(L"");
		GUIEditBox* pEditBox = new GUIEditBox(this->GetLastTweakerGroup(), &guiTextItem, 1, flags);
		guiTextItem.Free();

		pEditBox->SetText(text);

		return pEditBox;
	}

	GUIEditBox* GUITweakerDialog::AddLabelEditBox(const dl_wchar* title, const dl_wchar* text, dl_bool bReadOnly)
	{
		this->AddLabel(title);

		return this->AddEditBox(text, bReadOnly);
	}

	GUIHeapList* GUITweakerDialog::AddHeapList(const dl_wchar* title)
	{
		GUIText guiTextItem(title);

		GUIHeapList* heapList = new GUIHeapList(this->GetLastTweakerGroup(), &guiTextItem);
		guiTextItem.Free();

		return heapList;
	}

	GUIListView* GUITweakerDialog::AddListView(const dl_wchar* title, short titleWidth, UINT style_flags)
	{
		GUIText guiTextItem(title);

		GUIListView* pListView = new GUIListView(this->GetLastTweakerGroup(), &guiTextItem, style_flags, 0);
		guiTextItem.Free();

		return pListView;
	}

	TGUIPropertyLabel<dl_uchar>* GUITweakerDialog::AddPropertyLabelByte(const dl_wchar* title, dl_uchar* v)
	{
		GUIText guiTextItem(title);

		TGUIPropertyLabel<dl_uchar>* propertyLabel = new TGUIPropertyLabel<dl_uchar>(this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return propertyLabel;
	}

	TGUIPropertyLabel<dl_int16>* GUITweakerDialog::AddPropertyLabelShort(const dl_wchar* title, short* v)
	{
		GUIText guiTextItem(title);

		TGUIPropertyLabel<dl_int16>* propertyLabel = new TGUIPropertyLabel<dl_int16>(this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return propertyLabel;
	}

	TGUIPropertyLabel<dl_int>* GUITweakerDialog::AddPropertyLabelInt(const dl_wchar* title, dl_int* v)
	{
		GUIText guiTextItem(title);

		TGUIPropertyLabel<dl_int>* propertyLabel = new TGUIPropertyLabel<dl_int>(this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return propertyLabel;
	}

	TGUIPropertyLabel<dl_float32>* GUITweakerDialog::AddPropertyLabelFloat(const dl_wchar* title, dl_float32* v)
	{
		GUIText guiTextItem(title);

		TGUIPropertyLabel<dl_float32>* propertyLabel = new TGUIPropertyLabel<dl_float32>(this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return propertyLabel;
	}

	TGUIPropertyLabel<const dl_char*>* GUITweakerDialog::AddPropertyLabelString(const dl_wchar* title, const char** v)
	{
		GUIText guiTextItem(title);

		TGUIPropertyLabel<const char*>* propertyLabel = new TGUIPropertyLabel<const char*>(this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return propertyLabel;
	}

	TGUIPropertyLabel<const dl_wchar*>* GUITweakerDialog::AddPropertyLabelWideString(const dl_wchar* title, const dl_wchar** v)
	{
		GUIText guiTextItem(title);

		TGUIPropertyLabel<const dl_wchar*>* propertyLabel = new TGUIPropertyLabel<const dl_wchar*>(this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return propertyLabel;
	}

	TGUIPropertyLabel<DLMT::DL_VECTOR3>* GUITweakerDialog::AddPropertyLabelVector3(const dl_wchar* title, DLMT::DL_VECTOR3* v)
	{
		GUIText guiTextItem(title);

		TGUIPropertyLabel<DLMT::DL_VECTOR3>* propertyLabel = new TGUIPropertyLabel<DLMT::DL_VECTOR3>(this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return propertyLabel;
	}

	TGUIPropertyLabel<DLMT::DL_VECTOR4>* GUITweakerDialog::AddPropertyLabelVector4(const dl_wchar* title, DLMT::DL_VECTOR4* v)
	{
		GUIText guiTextItem(title);

		TGUIPropertyLabel<DLMT::DL_VECTOR4>* propertyLabel = new TGUIPropertyLabel<DLMT::DL_VECTOR4>(this->GetLastTweakerGroup(), &guiTextItem, v);
		guiTextItem.Free();

		return propertyLabel;
	}

	GUITweakerGroup* GUITweakerDialog::AddRenderToTextureViewer(const dl_wchar* title, GXRenderToTexture* pGXRenderToTexture)
	{
		GUITweakerGroup* pGroup = this->AddTweakerGroup(title, true);

		if (pGroup)
		{
			GUITexture* guiTexture0 = new GUITexture(pGXRenderToTexture, 0);
			this->AddTextureViewer(L"Texture0", guiTexture0);

			GUITexture* guiTexture1 = new GUITexture(pGXRenderToTexture, 1);
			this->AddTextureViewer(L"Texture1", guiTexture1);

			GUITexture* guiTexture2 = new GUITexture(pGXRenderToTexture, 2);
			this->AddTextureViewer(L"Texture2", guiTexture2);

			this->AddPropertyLabelInt(L"Width", &pGXRenderToTexture->m_width);
			this->AddPropertyLabelInt(L"Height", &pGXRenderToTexture->m_height);

			this->PopStackLevel();
		}

		return pGroup;
	}

	GUITriggerTweaker* GUITweakerDialog::AddLabel(const dl_wchar* title)
	{
		return this->AddTriggerTweaker(title);
	}

	GUITextureViewer* GUITweakerDialog::AddTextureViewer(const dl_wchar* title, GUITexture* pTexture)
	{
		GUIText guiTextItem(title);

		GUITextureViewer* pTextureViewer = FRPG2_CALL(oAddTextureViewer, 0x54ca80, this->GetLastTweakerGroup(), &guiTextItem, pTexture);
		guiTextItem.Free();

		return pTextureViewer;
	}

	GUITextureViewer* GUITweakerDialog::AddDLTexture2DViewer(const dl_wchar* title, DLGR::DLTexture2D* pTexture)
	{
		GUITexture* pGUITexture = new GUITexture(pTexture);

		return this->AddTextureViewer(title, pGUITexture);
	}

	GUITextureList* GUITweakerDialog::AddTextureList(const dl_wchar* title)
	{
		GUIText guiTextItem(title);

		GUITextureList* pTextureList = FRPG2_CALL(oAddTextureList, 0x54cd00, this->GetLastTweakerGroup(), &guiTextItem);
		guiTextItem.Free();

		return pTextureList;
	}
}