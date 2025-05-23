#pragma once
#include "DynamicBitset.h"
#include "dantelion2/Core/Util/DLVector.h"

namespace DLUID
{
	template<typename T>
	class VirtualAnalogKeyInfo
	{
		void** _vfptr;
		DLUT::DLVector<T> m_keyInfoList;
	};

	class VirtualInputData
	{
		void** _vfptr;
		VirtualAnalogKeyInfo<dl_float32> m_analogKeyInfo;
		DynamicBitset m_flags;
	};
}