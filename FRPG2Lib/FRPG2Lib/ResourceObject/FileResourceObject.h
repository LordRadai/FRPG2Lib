#pragma once
#include "ResourceObject.h"

class FileResourceObject : public ResourceObject
{
public:
	DLTX::DLString m_filename;
	DLKR::DLAllocator* m_pAllocator;
	dl_pointer m_pFileReadOperation;
	dl_uint m_fileFlags;
	dl_bool m_bVarC4;
	dl_bool m_bDoneReading;
	dl_bool m_bVarC6;
	dl_bool m_bVarC7;

	void ReadFile();
};