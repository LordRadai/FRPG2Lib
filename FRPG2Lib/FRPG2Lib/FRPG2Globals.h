#pragma once
#include <Windows.h>

class KatanaMainApp;
class GameManagerImp;
class NetworkManager;

extern HMODULE g_moduleAddr;

#define KATANA_MAIN_APP (*(KatanaMainApp**)((UINT64)g_moduleAddr + 0x16751f8))
#define GAME_MANAGER_IMP (*(GameManagerImp**)((UINT64)g_moduleAddr + 0x16148f0))
#define NETWORK_MANAGER (*(NetworkManager**)((UINT64)g_moduleAddr + 0x1616cf8))
#define FRPG2_HINSTANCE (*(HINSTANCE*)((UINT64)g_moduleAddr + 0x16142b0))