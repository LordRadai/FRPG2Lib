#pragma once
#include "../DLUserInputMapper.inl"

namespace DLUID
{
	template<class ThreadingPolicy>
	class DLUserInputMapperImpl : public DLUI::DLUserInputMapper<ThreadingPolicy>
	{
	};
}