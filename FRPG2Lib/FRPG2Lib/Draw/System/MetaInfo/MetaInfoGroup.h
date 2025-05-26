#pragma once
#include "MetaInfoItem.h"

class MetaInfoGroup
{
	DLUT::DLVector<MetaInfoItem>* m_pMetaInfoItemList;
	const dl_char* m_name;
	dl_pointer m_pVar10;

public:
	const dl_char* GetName() const { return this->m_name; }
	
	dl_uint GetNumItems() const
	{
		if (this->m_pMetaInfoItemList == nullptr)
			return 0;

		return this->m_pMetaInfoItemList->size();
	}

	MetaInfoItem* GetMetaInfoItem(dl_uint idx);
};