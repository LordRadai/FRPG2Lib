#pragma once
#include "../GUIObject/GUIObject.h"

namespace GuiFramework
{
    class GUIListView;

    class GUIListViewItem : public GUIObject
    {
    public:
        GUIListViewItem() {}
        GUIListViewItem(GUIListView* pListView, GUIText* label);

        virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x1618638); }
        virtual ~GUIListViewItem() {}
        virtual void OnDestroy();
        virtual int OnUpdate(GUIText* param_1, int columnIdx) { return 0; }

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(sizeof(GUIListViewItem), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

        GUIListView* m_pGUIListView = nullptr;
        GUIText m_label;
        dl_pointer m_pVar28 = 0;
        dl_pointer pVar30 = 0;
    };
}