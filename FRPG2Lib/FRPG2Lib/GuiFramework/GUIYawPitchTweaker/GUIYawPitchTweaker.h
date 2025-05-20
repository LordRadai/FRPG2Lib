#pragma once
#include "../GUITweakerBase/GUITweakerBase.h"

namespace GuiFramework
{
	class GUIYawPitchTweaker : public GUITweakerBase
	{
		dl_float32** m_pDataOld;
		dl_float32* m_pData;
		dl_int16 m_iVar38;
	};
}