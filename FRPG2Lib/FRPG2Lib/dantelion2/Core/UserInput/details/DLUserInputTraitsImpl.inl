#pragma once
#include "../DLUserInputTraits.inl"

namespace DLUID
{
	template<class ThreadingPolicy>
	class DLUserInputTraitsImpl : public DLUserInputTraits<ThreadingPolicy>
	{
	};
}