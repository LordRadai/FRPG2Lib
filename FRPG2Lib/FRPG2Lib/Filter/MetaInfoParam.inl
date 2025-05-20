#pragma once
#include "MetaInfoRangeBase.h"

template<typename T>
class MetaInfoParam : public MetaInfoRangeBase
{
public:
	T m_min;
	T m_max;
	T m_step;

	dl_float32 m_mult;
};