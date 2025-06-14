#pragma once
#include <Windows.h>

class KatanaMainApp;
class GameManagerImp;
class NetworkManager;
class WorldHeapList;

extern HMODULE g_hModule;

#define MODULE_ADDR ((UINT64)g_hModule)

#define KATANA_MAIN_APP (*(KatanaMainApp**)(MODULE_ADDR + 0x16751f8))
#define GAME_MANAGER_IMP (*(GameManagerImp**)(MODULE_ADDR + 0x16148f0))
#define NETWORK_MANAGER (*(NetworkManager**)(MODULE_ADDR + 0x1616cf8))
#define FRPG2_HINSTANCE (*(HINSTANCE*)(MODULE_ADDR + 0x16142b0))
#define WORLD_HEAP_LIST (*(WorldHeapList**)(MODULE_ADDR + 0x1616cc0))