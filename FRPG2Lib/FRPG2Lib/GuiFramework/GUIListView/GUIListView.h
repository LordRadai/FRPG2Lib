#pragma once
#include "../GUIWidget/GUIWidget.h"
#include "GUIListViewItem.h"

namespace GuiFramework
{
    class GUIListView : public GUIWidget
    {
    public:
        struct GUIListViewColumn
        {
			GUIText label;
            short width;
            short idx;
            int iVar14;
        };

        GUIListView() {}
        GUIListView(GUIText* title);
        GUIListView(GUIWidget* pRoot, GUIText* title, GUIWidgetInitData* param_3);
        GUIListView(GUIWidget* pRoot, GUIText* title, int flags, int param_4);

        virtual UINT64 GetRuntimeClassImpl() { return *(UINT64*)(MODULE_ADDR+0x16185d0); }
        virtual ~GUIListView() {}
        virtual void OnDestroy();
        virtual int OnMouseOverContent(MousePosData* mousePos);
        virtual int Input9(MousePosData* mousePos);
        virtual int OnMouseWheelScroll(MousePosData* mousePos);
        virtual int OnLeftClick(MousePosData* mousePos);
        virtual int OnLeftClickReleased(MousePosData* mousePos);
        virtual int OnRightClick(MousePosData* mousePos);
        virtual int Vf118(BYTE* pUnkAction);
        virtual int Vf158(short* param_1);
        virtual int Vf170();
        virtual int Initialise();
        virtual void DestroyChildren();
        virtual void Draw(AppGUIRender* pAppGUIRender);
        virtual void Vf200(int* param_1) {}
        virtual void Vf208(int* param_1) {}
        virtual void Vf210(int* param_1) {}

        bool RegisterListViewItem(GUIListViewItem* pItem);
        int GetNumListViews() const { return this->m_listViewItems.size(); }
        int GetNumColumns() const { return this->m_columns.size(); }
        bool AddColumn(const wchar_t* label, short width);
        bool SetColumnWidth(short id, short width);
        bool SetColumnLabel(short id, GUIText* label);

        GUIListViewItem* GetListView(int idx) { return this->m_listViewItems[idx]; }
        GUIListViewItem* GetListView(int idx) const { return this->m_listViewItems[idx]; }

        GUIListViewItem* AddListViewItem(const dl_wchar* title);

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(sizeof(GUIListView), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

    protected:
        DLUT::DLVector<GUIListViewItem*> m_listViewItems;
        DLUT::DLVector<GUIListViewColumn> m_columns;
        dl_int16 m_textHeight = 0;
        dl_int16 m_lineHeight = 0;
        dl_int16 m_headerHeight = 0;
        dl_int16 m_tableWidth = 0;
        dl_bool m_resizingColumn = false;
        dl_int16 m_lastResizeColumnIdx = 0;
        dl_int16 m_lastResizeColumnWidth = 0;
        dl_int m_lastResizeMouseX = 0;
        dl_int m_lastResizeMouseY = 0;
        dl_int m_selectedItem = -1;
    };
}