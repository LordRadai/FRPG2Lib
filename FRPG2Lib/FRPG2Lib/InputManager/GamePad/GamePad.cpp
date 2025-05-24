#include "GamePad.h"

dl_bool GamePad::IsKeyPressed(dl_uint16 button) const
{
	if ((this->m_state.wButtons & button) && !(this->m_statePrev.wButtons & button))
		return true;

	return false;
}

dl_bool GamePad::IsKeyReleased(dl_uint16 button) const
{
	if (!(this->m_state.wButtons & button) && (this->m_statePrev.wButtons & button))
		return true;

	return false;
}

dl_bool GamePad::IsKeyHeld(dl_uint16 button) const
{
	if ((this->m_state.wButtons & button) && (this->m_statePrev.wButtons & button))
		return true;

	return false;
}