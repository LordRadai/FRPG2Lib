#pragma once

namespace DLUT
{
	class DLNonCopyable
	{
	protected:
		void** _vfptr;
	};
}