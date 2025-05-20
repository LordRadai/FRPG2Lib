#include "AppResourceManager.h"
#include "FRPG2Call.h"

typedef FontBinderFileResourceObject*(_fastcall* oLoadFont)(AppResourceManager* pThis, const dl_wchar* filename, dl_uint fontID, DLKR::DLAllocator* pAllocator, DLKR::DLAllocator* pAllocator2, dl_uint fileFlags);

FontBinderFileResourceObject* AppResourceManager::LoadFont(const dl_wchar* filename, dl_uint fontID, DLKR::DLAllocator* pAllocator, DLKR::DLAllocator* pAllocator2, dl_uint fileFlags)
{
	return FRPG2_CALL(oLoadFont, 0x2dd8e0, this, filename, fontID, pAllocator, pAllocator2, fileFlags);
}

dl_bool AppResourceManager::LoadAndCreateFontResource(const dl_wchar* filename, dl_uint fontID, DLKR::DLAllocator* pAllocator, DLKR::DLAllocator* pAllocator2, dl_uint fileFlags = 65)
{
	FontBinderFileResourceObject* pFontBinderFileResource = LoadFont(filename, fontID, pAllocator, pAllocator2, fileFlags);

	if (pFontBinderFileResource)
	{
		pFontBinderFileResource->field2_0x10++;
		pFontBinderFileResource->field3_0x14++;
		pFontBinderFileResource->ReadFile();

		return true;
	}

	return false;
}