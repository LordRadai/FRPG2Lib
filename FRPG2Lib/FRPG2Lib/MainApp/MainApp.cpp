#include "MainApp.h"
#include "AppGUISystem/AppGUISystem.h"
#include "Memory/GlobalHeapList.h"

void MainApp::HeapMemoryList::CreateHeapListGUI()
{
	AppGUISystem* pAppGUISystem = KATANA_MAIN_APP->GetAppGUISystem();

	GuiFramework::GUITweakerDialog* pRootHeapWnd = pAppGUISystem->AddTweakerDialog(L"HeapList(RootHeap)", true, 900, 250);

	if (pRootHeapWnd)
	{
		GuiFramework::GUIHeapList* pHeapList = pRootHeapWnd->AddHeapList(L"HeapList");

		for (size_t i = 0; i < this->m_numRootHeaps; i++)
		{
			HeapMemory* pHeap = this->m_pRootHeaps[i];

			if (pHeap)
			{
				DLTX::DLString* pStr = new DLTX::DLString(DLTX::DLStringUtil::ToWide(pHeap->GetName()));
				pHeapList->AddHeapListItem(pStr->c_str(), pHeap->GetAllocator());
			}
		}
	}

	GuiFramework::GUITweakerDialog* pWorldHeapWnd = pAppGUISystem->AddTweakerDialog(L"WorldHeap", true, 900, 250);

	if (pWorldHeapWnd)
	{
		GuiFramework::GUIHeapList* pHeapList = pWorldHeapWnd->AddHeapList(L"HeapList");

		WorldHeapList* pWorldHeapList = WORLD_HEAP_LIST;

		DLTX::DLString* pStr = new DLTX::DLString(DLTX::DLStringUtil::ToWide(pWorldHeapList->m_pMapSeamlessControlMemory->GetName()));
		pHeapList->AddHeapListItem(pStr->c_str(), pWorldHeapList->m_pMapSeamlessControlMemory->GetAllocator());
	}
}