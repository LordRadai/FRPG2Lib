#pragma once
#include "dantelion2/Core/Kernel/DLAllocator.h"
#include "DynamicHeapMemoryTemplate.inl"
#include "WinAssertHeapStrategy.h"

enum HeapType
{
	HEAPTYPE_NONE,
	HEAPTYPE_SYSTEM,
	HEAPTYPE_GLOBAL,
	HEAPTYPE_GRAPHICSMAIN,
	HEAPTYPE_4,
	HEAPTYPE_5,
	HEAPTYPE_6,
	HEAPTYPE_DRAWCMDBUFFER,
	HEAPTYPE_8,
	HEAPTYPE_9,
	HEAPTYPE_FILEDATA,
	HEAPTYPE_SOUNDSYS,
	HEAPTYPE_12,
	HEAPTYPE_NETWORK,
	HEAPTYPE_STRING,
	HEAPTYPE_TEMP,
	HEAPTYPE_TEMP2,
	HEAPTYPE_DEBUG,
	HEAPTYPE_GUIDEFAULT,
	HEAPTYPE_19,
	HEAPTYPE_20,
	HEAPTYPE_21,
	HEAPTYPE_PLAYER,
	HEAPTYPE_HAVOK,
	HEAPTYPE_SFXSYSTEM,
	HEAPTYPE_MORPHEME,
	HEAPTYPE_SCENEGRAPH,
	HEAPTYPE_FACEGEN,
	HEAPTYPE_MENU,
	HEAPTYPE_29,
	HEAPTYPE_REGULATION,
	HEAPTYPE_NUM
};

DLKR::DLAllocator* GetRootHeap(int heapType);
const dl_wchar* GetRootHeapName(int heapType);

class Memory
{
	void** _vfptr;
	DLKR::DLAllocator* m_pAllocator;
	dl_pointer m_pVar10;
	dl_pointer m_pVar18;
	dl_bool m_bVar20;
	dl_bool m_bVar21;

public:
	dl_pointer FindParamEntry(dl_uint rowID);
};