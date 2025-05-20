#pragma once
#include "DebugManager/DebugManager.h"

class AppDebugManager : public DebugManager
{
public:
	AppDebugManager() : DebugManager() {};
	~AppDebugManager() { DebugManager::~DebugManager(); };
	void Update(dl_float32* pDeltaTime) {};
	dl_bool Initialize() { return DebugManager::Initialize(); }
	void Finalize() { DebugManager::Finalize(); };
};