#pragma once
#include "AppResourceManagerBase.h"
#include "ResourceObject/FontBinderFileResourceObject.h"

class AppResourceManager : public AppResourceManagerBase
{
public:
	FontBinderFileResourceObject* LoadFont(const dl_wchar* filename, dl_uint fontID, DLKR::DLAllocator* pAllocator, DLKR::DLAllocator* pAllocator2, dl_uint fileFlags = 65);
	dl_bool LoadAndCreateFontResource(const dl_wchar* filename, dl_uint fontID, DLKR::DLAllocator* pAllocator, DLKR::DLAllocator* pAllocator2, dl_uint fileFlags = 65);
	dl_pointer GetChrAsmCommonResData();

	typedef void(_fastcall* oLoadCoreComponents)(AppResourceManager* pThis, DLKR::DLAllocator* pAllocator);
};