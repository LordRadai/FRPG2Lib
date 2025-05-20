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

        virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)((UINT64)(g_moduleAddr)+0x1617520); }
        virtual ~GUIWindowBase() {}
        virtual void onDestroy();
        virtual dl_int onUpdate(GUIWindowBase* param_1) { return 0; }
        virtual UINT64 getChildren() { return NULL; }
        virtual dl_int* vf30(dl_int* param_1);
        virtual GUIWindowBase* vf38(GUIWindowBase* param_1, dl_int param_2) { return nullptr; }
        virtual dl_int vf40() { return 1; }
        virtual dl_int vf48() { return 1; }
        virtual dl_bool handleUserInput(GUIInputData* pInputData);
        virtual dl_int onMouseOverContent(MousePosData* mousePos) { return 0; }
        virtual dl_int onMouseOverFrame(MousePosData* mousePos) { return 0; }
        virtual dl_int onLeftClick(MousePosData* mousePos) { return 0; }
        virtual dl_int onLeftClickReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int onRightClick(MousePosData* mousePos) { return 0; }
        virtual dl_int onRightClickReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int onMouseWheelPressed(MousePosData* mousePos) { return 0; }
        virtual dl_int onMouseWheelReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int input9(MousePosData* mousePos) { return 0; }
        virtual dl_int input10(MousePosData* mousePos) { return 0; }
        virtual dl_int input11(MousePosData* mousePos) { return 0; }
        virtual dl_int onMouseWheelScroll(MousePosData* mousePos) { return 0; }
        virtual dl_int onActionButtonLeftClick(MousePosData* mousePos) { return 0; }
        virtual dl_int onActionButtonLeftClickReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int onActionButtonRightClick(MousePosData* mousePos) { return 0; }
        virtual dl_int onActionButtonRightClickReleased(MousePosData* mousePos) { return 0; }
        virtual dl_int input19(MousePosData* mousePos) { return 0; }
        virtual dl_int input20(MousePosData* mousePos) { return 0; }
        virtual dl_int input21(MousePosData* mousePos) { return 0; }
        virtual dl_int input22(MousePosData* mousePos) { return 0; }
        virtual dl_int input23(MousePosData* mousePos) { return 0; }
        virtual dl_int input24(MousePosData* mousePos) { return 0; }
        virtual dl_int input2(MousePosData* mousePos) { return 0; }
        virtual dl_int input14(MousePosData* mousePos) { return 0; }
        virtual dl_int vf118(dl_uchar* pUnkAction);
        virtual dl_int vf120() { return 0; }
        virtual dl_int calculateContentSize(dl_int* pDst);
        virtual dl_int vf130(dl_int* pDst);
        virtual dl_bool handlePopUpMenuSelection(dl_int actionId) { return 0; }
        virtual dl_int vf140() { return 0; }
        virtual dl_int vf148() { return 0; }
        virtual dl_int vf150() { return 0; }
        virtual dl_int vf158(dl_int16* param_1) { return 0; }
        virtual dl_int vf160() { return 0; }
        virtual dl_int handleTextInput(GUITextInputData* textInputData) { return 0; }
        virtual dl_int vf170() { return 0; }
        virtual dl_int vf178() { return 0; }
        virtual dl_int vf180() { return 0; }
        virtual void vf188() {}
        virtual void vf190() {}
        virtual void vf198() {}
        virtual dl_int initialise() { return 1; }
        virtual dl_int vf1A8(GUIWindowBase* param_1);
        virtual void destroyChildren();
        virtual void draw(AppGUIRender* pAppGUIRender);
        virtual void vf1C0();
        virtual void vf1C8();
        virtual void vf1D0() {}

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(sizeof(GUIWindowBase), 8, GetHeap(HEAPTYPE_GUIDEFAULT));
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GetHeap(HEAPTYPE_GUIDEFAULT));
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