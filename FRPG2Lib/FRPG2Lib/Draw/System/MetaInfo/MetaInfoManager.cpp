#include "MetaInfoManager.h"

MetaInfoGroup* MetaInfoManager::GetMetaInfoGroup(dl_uint idx)
{
	if (idx < this->m_metaInfoGroupList.size())
		return &this->m_metaInfoGroupList[idx];

	return nullptr;
}