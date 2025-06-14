#pragma once
#include "FileResourceObject.h"
#include "Memory/Memory.h"

class ParamFileResourceObject_ForRegulation : public FileResourceObject
{
    Memory m_memory;
    dl_bool m_bVarF0;

public:
    template<typename PARAM_DATA>
    PARAM_DATA* GetParamEntryByID(dl_uint rowID) { return static_cast<PARAM_DATA*>(m_memory.FindParamEntry(rowID)); }
};