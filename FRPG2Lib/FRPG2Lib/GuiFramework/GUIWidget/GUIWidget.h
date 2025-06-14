#pragma once
#include "../GUIWindowBase/GUIWindowBase.h"

namespace GuiFramework
{
    class GUIWidget : public GUIWindowBase
    {
    public:
        GUIWidget() : GUIWindowBase() {}

        virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617980); }
        virtual ~GUIWidget() {}
        virtual void onDestroy();
        virtual int onUpdate(GUIWindowBase* param_1);
        virtual UINT64 getChildren();
        virtual int* vf30(int* pDst);
        virtual GUIWindowBase* vf38(GUIWindowBase* param_1, int param_2);
        virtual int onMouseOverContent(MousePosData* mousePos);
        virtual int onMouseOverFrame(MousePosData* mousePos);
        virtual int onActionButtonLeftClick(MousePosData* mousePos);
        virtual int onActionButtonLeftClickReleased(MousePosData* mousePos);
        virtual int input2(MousePosData* mousePos);
        virtual int input14(MousePosData* mousePos);
        virtual int vf118(BYTE* pUnkAction);
        virtual int calculateContentSize(int* pDst);
        virtual int vf130(int* pDst);
        virtual int initialise();
        virtual int vf1A8(GUIWindowBase* param_1);
        virtual void destroyChildren();
        virtual void draw(AppGUIRender* pAppGUIRender);
        virtual void vf1C0();

        virtual int* vf1D8(int* pDst);
        virtual int* vf1E0(int* pDst);
        virtual void vf1E8(int* pDst1, short* pDst2);
        virtual int vf1F0(UINT param_1, UINT64 param_2) { return 0; }
        virtual int vf1F8(UINT param_1, UINT64 param_2) { return 0; }

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(sizeof(GUIWidget), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

        void Destroy();
        void SetAsChild(GUIWidget* pChild, GUIWidgetInitData* pInitData);
		void EditPosSize(dl_uint x, dl_uint y, dl_uint width, dl_uint height);

        DLUT::DLVector<GUIWidget*> m_childWidgets;
        dl_pointer m_pScrollBars[2] = { 0 };
        dl_int m_iVar0xa8 = 0;
        dl_int m_iVar0xac = 0;
        dl_uchar m_actionType = 0;
        dl_uchar m_bVarB1 = 0;
        dl_uchar m_bVarB2 = 0;
        dl_uchar m_bVarB3 = 0;
        dl_uint m_iVarB4 = 0;
        dl_int16 m_sVarB8 = 0;
        dl_uchar m_bVarBA[74] = { 0 };
        dl_int m_iVar104 = 0;
        dl_int m_iVar108 = 0;
    };
}