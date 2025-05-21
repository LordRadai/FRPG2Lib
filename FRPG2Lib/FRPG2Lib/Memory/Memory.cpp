#include "Memory.h"
#include "FRPG2Globals.h"
#include "FRPG2Call.h"

typedef DLKR::DLAllocator*(_fastcall* oGetHeap)(int heapType);

DLKR::DLAllocator* GetRootHeap(int heapType)
{
	return FRPG2_CALL(oGetHeap, 0xaee210, heapType);
}

const dl_wchar* GetRootHeapName(int heapType)
{
	switch (heapType)
	{
	case HEAPTYPE_SYSTEM:
		return L"SystemHeap";
	case HEAPTYPE_GLOBAL:
		return L"GlobalHeap";
	case HEAPTYPE_GRAPHICSMAIN:
		return L"GraphicsMainHeap";
	case HEAPTYPE_DRAWCMDBUFFER:
		return L"DrawCmdBuffer";
	case HEAPTYPE_FILEDATA:
		return L"FileDataHeap";
	case HEAPTYPE_SOUNDSYS:
		return L"SoundSysHeap";
	case HEAPTYPE_NETWORK:
		return L"NetworkHeap";
	case HEAPTYPE_STRING:
		return L"StringHeap";
	case HEAPTYPE_TEMP:
		return L"TempHeap";
	case HEAPTYPE_TEMP2:
		return L"Temp2Heap";
	case HEAPTYPE_DEBUG:
		return L"DebugHeap";
	case HEAPTYPE_GUIDEFAULT:
		return L"GuiDefaultHeap";
	case HEAPTYPE_PLAYER:
		return L"PlayerHeap";
	case HEAPTYPE_HAVOK:
		return L"HavokHeap";
	case HEAPTYPE_SFXSYSTEM:
		return L"SfxSystemHeap";
	case HEAPTYPE_MORPHEME:
		return L"MorphemeHeap";
	case HEAPTYPE_SCENEGRAPH:
		return L"SceneGraphHeap";
	case HEAPTYPE_FACEGEN:
		return L"FaceGenHeap";
	case HEAPTYPE_MENU:
		return L"Menu";
	case HEAPTYPE_REGULATION:
		return L"Regulation";
	default:
		return L"Unknown";
	}
}