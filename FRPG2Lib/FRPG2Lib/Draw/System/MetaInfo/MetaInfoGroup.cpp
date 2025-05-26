#include "MetaInfoGroup.h"

MetaInfoItem* MetaInfoGroup::GetMetaInfoItem(dl_uint idx)
{
	if (this->m_pMetaInfoItemList == nullptr)
		return nullptr;

	if (idx < this->m_pMetaInfoItemList->size())
		return &this->m_pMetaInfoItemList->at(idx);

	return nullptr;
}