#include "DebugManager.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oConstructor)(DebugManager* pThis);
typedef void(_fastcall* oDestructor)(DebugManager* pThis);
typedef void(_fastcall* oUpdate)(DebugManager* pThis, dl_float32* pDeltaTime);
typedef dl_bool(_fastcall* oLoadResources)(DebugManager* pThis);
typedef void(_fastcall* oFinalize)(DebugManager* pThis);

typedef bool(_fastcall* oApplyShaderPreset)(DebugManager::Resources* pResources, IDrawContext* pDrawContext, dl_int presetIdx);

DebugManager::DebugManager()
{
	FRPG2_CALL(oConstructor, 0xaf4830, this);
}

DebugManager::~DebugManager()
{
	FRPG2_CALL(oDestructor, 0xaf48a0, this);
}

void DebugManager::Update(dl_float32* pDeltaTime)
{
	FRPG2_CALL(oUpdate, 0xaf4910, this, pDeltaTime);
}

dl_bool DebugManager::Initialize()
{
	return FRPG2_CALL(oLoadResources, 0xaf48f0, this);
}

void DebugManager::Finalize()
{
	FRPG2_CALL(oFinalize, 0xaf48e0, this);
}

void DebugManager::ApplyPreset(IDrawContext* pDrawContext, dl_int presetIdx)
{
	FRPG2_CALL(oApplyShaderPreset, 0xb4f6b0, &this->m_resources, pDrawContext, presetIdx);
}