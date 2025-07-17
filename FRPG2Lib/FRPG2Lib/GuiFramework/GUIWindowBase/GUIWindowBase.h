#pragma once
#include "../GUIMsgReceiver/GUIMsgReceiver.h"
#include "../Util/MousePosData.h"

namespace GuiFramework
{
    struct GUIInputData
    {
        dl_uint actionID;
        dl_int iVar4;
        MousePosData mousePosition;
    };

    struct GUITextInputData
    {
        dl_int16 sVar0;
        dl_wchar character;
        dl_int16 sVar2;
    };

    struct GUIWidgetInitData
    {
        TGUI_RECT<dl_uint16> position;
        dl_uint flags;
        dl_int iVarC = 0;

        GUIWidgetInitData(dl_uint16 minX, dl_uint16 minY, dl_uint16 maxX, dl_uint16 maxY, dl_uint flags)
        {
            this->position = TGUI_RECT<dl_uint16>(minX, minY, maxX, maxY);
            this->flags = flags;
        }
    };

    class GUIWindowBase : public GUIMsgReceiver
    {
    public:
        GUIWindowBase() : GUIMsgReceiver() {}

        virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617520); }
        virtual ~GUIWindowBase() {}
        virtual void OnDestroy();
        virtual dl_int OnUpdate(GUIWindowBase* param_1) { return 0; }
        virtual UINT64 GetChildren() { return NULL; }
        virtual dl_int* Vf30(dl_int* param_1);
        virtual GUIWindowBase* Vf38(GUIWindowBase* param_1, dl_int param_2) { return nullptr; }
        virtual dl_int Vf40() { return 1; }
        virtual dl_int Vf48() { return 1; }
        virtual dl_bool HandleUserInput(GUIInputData* pInputData);
        virtual dl_int OnMouseOverContent(MousePosData* mousePos) { return 0; }
        virtual dl_int OnMouseOverFrame(MousePosData* mousePos) { return 0; }
        virtual dl_int OnLeftClick(MousePosData* mousePos) { return 0; }
        virtual dl_int OnLeftClickReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int OnRightClick(MousePosData* mousePos) { return 0; }
        virtual dl_int OnRightClickReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int OnMouseWheelPressed(MousePosData* mousePos) { return 0; }
        virtual dl_int OnMouseWheelReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int Input9(MousePosData* mousePos) { return 0; }
        virtual dl_int Input10(MousePosData* mousePos) { return 0; }
        virtual dl_int Input11(MousePosData* mousePos) { return 0; }
        virtual dl_int OnMouseWheelScroll(MousePosData* mousePos) { return 0; }
        virtual dl_int OnActionButtonLeftClick(MousePosData* mousePos) { return 0; }
        virtual dl_int OnActionButtonLeftClickReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int OnActionButtonRightClick(MousePosData* mousePos) { return 0; }
        virtual dl_int OnActionButtonRightClickReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int Input19(MousePosData* mousePos) { return 0; }
        virtual dl_int Input20(MousePosData* mousePos) { return 0; }
        virtual dl_int Input21(MousePosData* mousePos) { return 0; }
        virtual dl_int Input22(MousePosData* mousePos) { return 0; }
        virtual dl_int Input23(MousePosData* mousePos) { return 0; }
        virtual dl_int Input24(MousePosData* mousePos) { return 0; }
        virtual dl_int Input2(MousePosData* mousePos) { return 0; }
        virtual dl_int Input14(MousePosData* mousePos) { return 0; }
        virtual dl_int Vf118(dl_uchar* pUnkAction);
        virtual dl_int Vf120() { return 0; }
        virtual dl_int CalculateContentSize(dl_int* pDst);
        virtual dl_int Vf130(dl_int* pDst);
        virtual dl_bool HandlePopUpMenuSelection(dl_int actionId) { return 0; }
        virtual dl_int Vf140() { return 0; }
        virtual dl_int Vf148() { return 0; }
        virtual dl_int Vf150() { return 0; }
        virtual dl_int Vf158(dl_int16* param_1) { return 0; }
        virtual dl_int Vf160() { return 0; }
        virtual dl_int HandleTextInput(GUITextInputData* textInputData) { return 0; }
        virtual dl_int Vf170() { return 0; }
        virtual dl_int Vf178() { return 0; }
        virtual dl_int Vf180() { return 0; }
        virtual void Vf188() {}
        virtual void Vf190() {}
        virtual void Vf198() {}
        virtual dl_int Initialise() { return 1; }
        virtual dl_int Vf1A8(GUIWindowBase* param_1);
        virtual void DestroyChildren();
        virtual void Draw(AppGUIRender* pAppGUIRender);
        virtual void Vf1C0();
        virtual void Vf1C8();
        virtual void Vf1D0() {}

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(sizeof(GUIWindowBase), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

        const dl_wchar* GetName() const;

        GUIWindowBase* pParentWindow = nullptr;
        GUIWindowBase* pVar18 = nullptr;
        dl_pointer* pAppGuiSystem = nullptr;
        dl_pointer* pGUIWindowPainter = nullptr;
        GUIText m_name;
        TGUI_RECT<dl_int> m_position;
        dl_uint m_styleFlags = 0;
        dl_int m_iVar54 = 0;
        TGUI_RECT<dl_int16> m_contentOffset;
        TGUI_RECT<dl_int16> m_rect60;
        dl_char m_bVar68 = 0;
        dl_char m_bVar69 = 8;
        dl_char m_bVar6a = 0;
        dl_char m_bVar6b = 8;
        dl_char m_bVar6c = 0;
        dl_char m_bVar6d = 0;
        dl_char m_bVar6e = 255;
        dl_char m_bVar6f = 0;
        dl_int16 m_sVar70 = 0;
        dl_int16 m_sVar72 = 0;
        dl_int m_iVar74 = 0;
    };
}