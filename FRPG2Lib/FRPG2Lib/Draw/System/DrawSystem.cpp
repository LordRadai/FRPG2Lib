#include "DrawSystem.h"
#include "MainApp/MainApp.h"
#include "AppGUISystem/AppGUISystem.h"

void KatanaDrawSystem::CreateDrawSystemGUI()
{
	AppGUISystem* pAppGUISystem = KATANA_MAIN_APP->m_pAppGUISystem;

	GuiFramework::GUITweakerDialog* pWnd = pAppGUISystem->AddTweakerDialog(L"Draw System", true, 430, 400);

	if (pWnd == nullptr)
		return;

	GuiFramework::TGUIComboItem<dl_int> shading_mode[2];

	shading_mode[0].m_value = 0;
	shading_mode[0].m_name = L"ForwardShading";

	shading_mode[1].m_value = 1;
	shading_mode[1].m_name = L"LightPrepass";

	pWnd->AddComboTweakerInt(L"Shading Mode", &this->m_katanaDrawScene.m_shadingMode, 2, shading_mode);

	GuiFramework::GUITweakerGroup* pBasicDrawSystem = pWnd->AddTweakerGroup(L"BasicDrawSystem");

	if (pBasicDrawSystem)
	{
		GuiFramework::TGUIComboItem<BYTE> draw_mode[2];

		draw_mode[0].m_value = 0;
		draw_mode[0].m_name = L"Immediate";

		draw_mode[1].m_value = 1;
		draw_mode[1].m_name = L"Deferred";

		pWnd->AddComboTweakerByte(L"Execution Mode", &KATANA_MAIN_APP->m_drawExecMode, 2, draw_mode);

		pWnd->AddPropertyLabelInt(L"Screen Width", &KATANA_MAIN_APP->m_width);
		pWnd->AddPropertyLabelInt(L"Screen Height", &KATANA_MAIN_APP->m_height);

		GUISystem::AddGuiDLTexture2DViewer(pWnd, L"Render Target", pGraphicsCtxInterface->m_pRenderTargetTexture);

		pWnd->PopStackLevel();
	}

	GuiFramework::GUITweakerGroup* pDrawScene = GUISystem::AddGuiGroup(pWnd, L"Scene");

	if (pDrawScene)
	{
		TGUIComboItem<BYTE> shading_mode[2];

		shading_mode[0].m_value = 0;
		shading_mode[0].m_name = L"ForwardShading";

		shading_mode[1].m_value = 1;
		shading_mode[1].m_name = L"LightPrepass";

		GUISystem::AddGuiComboTweakerByte(pWnd, L"ShadingMode", pKatanaInterface->m_pKatanaDrawSystemInterface->m_pShadingMode, 2, shading_mode);

		TGUIComboItem<BYTE> shadow_mode[2];

		shadow_mode[0].m_value = 0;
		shadow_mode[0].m_name = L"Model";

		shadow_mode[1].m_value = 1;
		shadow_mode[1].m_name = L"ScreenSpace";

		GUISystem::AddGuiComboTweakerByte(pWnd, L"Shadow Mode", pKatanaInterface->m_pKatanaDrawSystemInterface->m_pShadowMode, 2, shadow_mode);

		CreateSceneSettingGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface);
		CreateRenderTargetsGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface);
		CreateFilterGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface);
		CreateCascadeShadowGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface->m_pCascadedShadowScene);
		CreateScreenSpaceShadowGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface->m_pAppScreenSpaceShadow);
		CreateDepthScaleGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface->m_pDepthScaleFilter);

		pWnd->PopStackLevel();
	}

	CreateRenderTargetsGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface);
	CreateFilterGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface);
	CreateCascadeShadowGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface->m_pCascadedShadowScene);
	CreateScreenSpaceShadowGroup(pWnd, pKatanaInterface->m_pKatanaDrawSystemInterface->m_pAppScreenSpaceShadow);

	GuiFramework::GUITweakerGroup* pDebug = GUISystem::AddGuiGroup(pWnd, L"Debug");

	if (pDebug)
	{
		GUISystem::AddGuiOnOffTweaker(pWnd, L"Only Draw Instanced Items", &pKatanaInterface->m_pKatanaDrawSystemInterface->m_drawOnlyInstanced);
		GUISystem::AddGuiOnOffTweaker(pWnd, L"Only Draw Non-Instanced Items", &pKatanaInterface->m_pKatanaDrawSystemInterface->m_drawOnlyNonInstanced);

		pWnd->PopStackLevel();
	}
}