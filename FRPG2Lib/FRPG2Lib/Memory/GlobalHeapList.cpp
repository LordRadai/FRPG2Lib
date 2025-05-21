#include "GlobalHeapList.h"

const dl_wchar* WorldHeapList::GetHeapName(int idx)
{
	switch (idx) 
	{
	case 0:  return L"MapControl";
	case 1:  return L"MapResource";
	case 2:  return L"ObjControl";
	case 3:  return L"ObjResrouce";
	case 4:  return L"NaviMeshControl";
	case 5:  return L"NaviMeshResource";
	case 6:  return L"EnemyControl";
	case 7:  return L"EnemyResource";
	case 8:  return L"EventControl";
	case 9:  return L"EventResource";
	case 10: return L"AiControl";
	case 11: return L"AiResource";
	case 12: return L"DamageControl";
	case 13: return L"DamageResource";
	case 14: return L"BulletControl";
	case 15: return L"BulletResource";
	case 16: return L"SoundControl";
	case 17: return L"SoundResource";
	case 18: return L"SignControl";
	case 19: return L"SignResource";
	case 20: return L"StateActControl";
	case 21: return L"StateActResource";
	case 22: return L"FrontendControl";
	case 23: return L"FrontendResource";
	case 24: return L"MorphemeNetworkInstance";
	case 25: return L"Unknown";
	default: return L"Unknown";
	}
}