#include "ModelTestScene.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oDestructor)(ModelTestScene* pThis);
typedef void(_fastcall* oInitialise)(ModelTestScene* pThis);
typedef void(_fastcall* oUpdate)(ModelTestScene* pThis, float deltaTime);
typedef void(_fastcall* oDraw)(ModelTestScene* pThis, IDrawContext* pDrawContext);
typedef void(_fastcall* oVFunction4)(ModelTestScene* pThis, DLGR::DLDrawDevice* pDrawDevice);
typedef void(_fastcall* oDestroySceneImpl)(ModelTestScene* pThis);
typedef bool(_fastcall* oVFunction6)(ModelTestScene* pThis);
typedef void(_fastcall* oVFunction7)(ModelTestScene* pThis);
typedef void(_fastcall* oVFunction8)(ModelTestScene* pThis);
typedef void(_fastcall* oVFunction9)(ModelTestScene* pThis);
typedef void(_fastcall* oHandleMouseInputs)(ModelTestScene* pThis, dl_int* pInputData);
typedef dl_pointer(_fastcall* oGetRuntimeClassImpl)(ModelTestScene* pThis);

ModelTestScene::~ModelTestScene()
{
	FRPG2_CALL(oDestructor, 0x30bd00, this);
}

void ModelTestScene::Initialise()
{
	FRPG2_CALL(oInitialise, 0x30bf10, this);
}

void ModelTestScene::Update(float deltaTime)
{
	FRPG2_CALL(oUpdate, 0x30c0d0, this, deltaTime);
}

void ModelTestScene::Draw(IDrawContext* pDrawContext)
{
	FRPG2_CALL(oDraw, 0x30be10, this, pDrawContext);
}

void ModelTestScene::vfunction4(DLGR::DLDrawDevice* pDrawDevice)
{
	FRPG2_CALL(oVFunction4, 0x30bf00, this, pDrawDevice);
}

void ModelTestScene::DestroySceneImpl()
{
	FRPG2_CALL(oDestroySceneImpl, 0x30be20, this);
}

dl_bool ModelTestScene::vfunction6()
{
	return FRPG2_CALL(oVFunction6, 0x30bd70, this);
}

void ModelTestScene::HandleMouseInputs(dl_int* pInputData)
{
	FRPG2_CALL(oHandleMouseInputs, 0x30c0b0, this, pInputData);
}

dl_pointer ModelTestScene::GetRuntimeClassImpl()
{
	return FRPG2_CALL(oGetRuntimeClassImpl, 0x30c1a0, this);
}