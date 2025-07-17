#pragma once
#include "../GUIWindowBase/GUIWindowBase.h"

namespace GuiFramework
{
    class GUIWidget : public GUIWindowBase
    {
    public:
        GUIWidget() : GUIWindowBase() {}

        virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1617980); }
        virtual ~GUIWidget() {}
        virtual void OnDestroy();
        virtual int OnUpdate(GUIWindowBase* param_1);
        virtual UINT64 GetChildren();
        virtual int* Vf30(int* pDst);
        virtual GUIWindowBase* Vf38(GUIWindowBase* param_1, int param_2);
        virtual int OnMouseOverContent(MousePosData* mousePos);
        virtual int OnMouseOverFrame(MousePosData* mousePos);
        virtual int OnActionButtonLeftClick(MousePosData* mousePos);
        virtual int OnActionButtonLeftClickReleased(MousePosData* mousePos);
        virtual int Input2(MousePosData* mousePos);
        virtual int Input14(MousePosData* mousePos);
        virtual int Vf118(BYTE* pUnkAction);
        virtual int CalculateContentSize(int* pDst);
        virtual int Vf130(int* pDst);
        virtual int Initialise();
        virtual int Vf1A8(GUIWindowBase* param_1);
        virtual void DestroyChildren();
        virtual void Draw(AppGUIRender* pAppGUIRender);
        virtual void Vf1C0();

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