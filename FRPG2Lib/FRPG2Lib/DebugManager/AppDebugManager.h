#pragma once
#include "DebugManager/DebugManager.h"

class AppDebugManager : public DebugManager
{
public:
	AppDebugManager() : DebugManager() {};
	virtual ~AppDebugManager() { DebugManager::~DebugManager(); };
	virtual void Update(dl_float32 deltaTime) {};
	virtual dl_bool Initialize() { return DebugManager::Initialize(); }
	virtual void Finalize() { DebugManager::Finalize(); };
};