#pragma once

namespace GuiFramework
{
    template<typename T>
    struct TGUI_RECT
    {
        T m_min[2] = { 0, 0 };
        T m_max[2] = { 0, 0 };

        TGUI_RECT() {}
        TGUI_RECT(T minX, T minY, T maxX, T maxY)
        {
            this->m_min[0] = minX;
			this->m_min[1] = minY;

			this->m_max[0] = maxX;
			this->m_max[1] = maxY;
        }
    };
}