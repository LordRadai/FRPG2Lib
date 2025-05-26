#pragma once
#include "dantelion2/dantelion2.h"
#include "MetaInfoGroup.h"

class MetaInfoManager
{
	DLKR::DLAllocator* m_pAllocator;
	DLUT::DLVector<dl_pointer>* m_pMetaInfoCreationBuffer;
	dl_float32 m_fVar10;
	DLUT::DLVector<MetaInfoGroup> m_metaInfoGroupList;
	dl_bool m_bInit;

public:
	dl_bool IsInitialised() const { return this->m_bInit; }
	dl_uint GetNumGroups() const { return this->m_metaInfoGroupList.size(); }
	MetaInfoGroup* GetMetaInfoGroup(dl_uint idx);
};