#include "GUIHeapListItem.h"
#include "GUIHeapList.h"
#include "FRPG2Call.h"

namespace GuiFramework
{
	typedef UINT64(_fastcall* oOnUpdate)(GUIHeapListItem* pThis, GUIText* pBuffer, dl_int columnIdx);
	typedef UINT64(_fastcall* oFormatMemStringByType)(dl_int* pDisplayFmt, DLTX::DLString* pBuffer, dl_size value);

	GUIHeapListItem::GUIHeapListItem(GUIHeapList* pHeapList, GUIText* label, DLKR::DLAllocator* pAllocator) : GUIListViewItem(pHeapList, label)
	{
		this->m_pHeap = pAllocator;
	}

	void GUIHeapListItem::OnDestroy()
	{
		this->m_pHeap = nullptr;
		GUIListViewItem::OnDestroy();
	}

	int GUIHeapListItem::OnUpdate(GUIText* param_1, int columnIdx)
	{
		DLKR::DLAllocator* pHeap = this->m_pHeap;

		DLKR::DLHeapIdentifier heapID = pHeap->GetHeapID();
		DLKR::DLHeapIdentifier allocatorID = pHeap->GetAllocatorID();
		dl_size freeSize = pHeap->GetFreeSize();
		dl_size totalSize = pHeap->GetTotalSize();
		dl_size maxSize = pHeap->GetMaxSize();
		dl_size useSize = totalSize - freeSize;
		dl_float64 useSizeRatio = dl_float64(useSize) / dl_float64(totalSize);
		dl_float64 maxSizeRatio = dl_float64(maxSize) / dl_float64(totalSize);

		dl_int memFmt = MEMDISPFMT_B;

		switch (columnIdx)
		{
		case 1:
			param_1->Format(L"%d", heapID);
			return 1;
		case 2:
			param_1->Format(L"%d", allocatorID);
			return 1;
		case 3:
			param_1->ClearAndBuildStringContainer();
			FormatMemoryStringByType(&memFmt, &param_1->pStringContainer->m_string, freeSize);
			return 1;
		case 4:
			param_1->ClearAndBuildStringContainer();
			FormatMemoryStringByType(&memFmt, &param_1->pStringContainer->m_string, useSize);
			return 1;
		case 5:
			param_1->Format(L"%3.1f %%", useSizeRatio * 100.f);
			return 1;
		case 6:
			param_1->ClearAndBuildStringContainer();
			FormatMemoryStringByType(&memFmt, &param_1->pStringContainer->m_string, totalSize);
			return 1;
		case 7:
			param_1->ClearAndBuildStringContainer();
			FormatMemoryStringByType(&memFmt, &param_1->pStringContainer->m_string, maxSize);
			return 1;
		case 8:
			param_1->Format(L"%3.1f %%", maxSizeRatio * 100.f);
			return 1;
		default:
			return 0;
		}

		return 0;
	}

	void GUIHeapListItem::FormatMemoryStringByType(dl_int* pDisplayFmt, DLTX::DLString* pBuffer, dl_size value)
	{
		FRPG2_CALL(oFormatMemStringByType, 0xc54910, pDisplayFmt, pBuffer, value);
	}
}