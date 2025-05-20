#pragma once
#include "Filter/MetaInfo.inl"
#include "Filter/MetaInfoCombo.inl"

class MetaInfoItem
{
	const dl_char* m_name;
	dl_pointer m_pStorage;
	MetaInfoRangeBase* m_pRangeDataInfo;
	MetaInfoComboBase* m_pComboInfo;
	dl_pointer m_pVar20;
	dl_pointer m_pMetaInfoInit;
	MetaInfoParamType m_type;
	MetaInfoParamSemantic m_semantic;
	dl_int m_iVar38;
	dl_bool m_bVar3C;
	dl_bool m_bVar3D;
	dl_bool m_bVar3E;
	dl_bool m_bVar3F;
	dl_int m_iVar40;
	dl_int m_iVar44;

public:
	const dl_char* GetName() const { return this->m_name; }
	dl_pointer GetStorage() const { return this->m_pStorage; }
	MetaInfoRangeBase* GetRangeDataInfo() const { return this->m_pRangeDataInfo; }
	MetaInfoComboBase* GetComboInfo() const { return this->m_pComboInfo; }
	MetaInfoParamType GetMetaInfoParamType() const { return this->m_type; }
	MetaInfoParamSemantic GetMetaInfoParamSemantic() const { return this->m_semantic; }
};