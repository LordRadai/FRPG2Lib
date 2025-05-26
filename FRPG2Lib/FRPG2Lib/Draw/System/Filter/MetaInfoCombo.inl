#pragma once
#include "MetaInfoComboBase.h"
#include "GuiFramework/GUIValueStringPairData/TGUIValueStringPairData.inl"

template<typename T>
class MetaInfoCombo : public MetaInfoComboBase
{
public:
	GuiFramework::TGUIComboItem<T>* m_valueStringPairList;
	DLKR::DLAllocator* m_pAllocator;
	dl_int m_numValues;
};