#pragma once
#include "FileResourceObject.h"

class RegulationResourceObject : public FileResourceObject
{
	dl_int m_iVarC8;
	dl_int m_iVarCC;
	dl_int m_fileSize;
	dl_int m_iVarD4;
	dl_pointer m_pFileData;
	dl_int m_iVarE0;
	dl_int m_iVarE4;
	dl_int m_iVarE8;
	dl_int16 m_iVarEC;
};