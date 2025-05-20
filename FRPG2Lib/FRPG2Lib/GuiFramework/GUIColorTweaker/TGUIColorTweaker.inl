#pragma once
#include "GUIColorTweaker.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIColorTweaker : public GUIColorTweaker
	{
		T m_valueOld;
		T* m_pValue;
	};
}