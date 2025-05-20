#pragma once
#include "dantelion2/dantelion2.h"

class ResourceMemoryWatchDog
{
	void** _vfptr;
};

class AppResourceMemoryWatchDog : public ResourceMemoryWatchDog
{
};