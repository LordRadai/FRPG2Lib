#pragma once
#include "GUIOnOffTweaker.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIOnOffTweaker : public GUIOnOffTweaker
	{
		T* m_pValue;
		T* m_pValueOld;
	};
}