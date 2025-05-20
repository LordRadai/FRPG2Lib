#pragma once
#include "dantelion2/dantelion2.h"

template<typename T>
class TGUIStringStorage
{
	void** _vfptr;
	DLUT::DLVector<T> m_pStringStorageList[53];
	dl_char m_buffer[212];
};