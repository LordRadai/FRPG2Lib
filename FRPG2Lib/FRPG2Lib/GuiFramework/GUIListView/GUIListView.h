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

        virtual UINT64 getRuntimeClassImpl() { return *(UINT64*)((UINT64)(g_moduleAddr)+0x16185d0); }
        virtual ~GUIListView() {}
        virtual void onDestroy();
        virtual int onMouseOverContent(MousePosData* mousePos);
        virtual int input9(MousePosData* mousePos);
        virtual int onMouseWheelScroll(MousePosData* mousePos);
        virtual int onLeftClick(MousePosData* mousePos);
        virtual int onLeftClickReleased(MousePosData* mousePos);
        virtual int onRightClick(MousePosData* mousePos);
        virtual int vf118(BYTE* pUnkAction);
        virtual int vf158(short* param_1);
        virtual int vf170();
        virtual int initialise();
        virtual void destroyChildren();
        virtual void draw(AppGUIRender* pAppGUIRender);
        virtual void vf200(int* param_1) {}
        virtual void vf208(int* param_1) {}
        virtual void vf210(int* param_1) {}

        bool registerListViewItem(GUIListViewItem* pItem);
        int getNumListViews() const { return this->m_listViewItems.size(); }
        int getNumColumns() const { return this->m_columns.size(); }
        bool addColumn(const wchar_t* label, short width);
        bool setColumnWidth(short id, short width);
        bool setColumnLabel(short id, GUIText* label);

        GUIListViewItem* getListView(int idx) { return this->m_listViewItems[idx]; }
        GUIListViewItem* getListView(int idx) const { return this->m_listViewItems[idx]; }

        GUIListViewItem* AddListViewItem(const dl_wchar* title);

        static void* operator new(size_t size)
        {
            return DLKR::AllocateAligned(sizeof(GUIListView), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

        static void operator delete(void* block)
        {
            return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
        }

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