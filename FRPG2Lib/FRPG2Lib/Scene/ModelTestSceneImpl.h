#pragma once
#include "dantelion2/dantelion2.h"
#include "Draw/GX/GXDrawItem.h"
#include "CharacterResources/CharacterResources.h"
#include "GuiFramework/GuiFramework.h"

class Scene;

class ModelTestSceneImpl : public GXDrawItem
{
public:
	Scene* m_pScene;
	alignas(16) DLMT::DL_MATRIX44 m_projMatrix;
	alignas(16) DLMT::DL_VECTOR4 m_focusPoint;
	dl_float32 m_fov;
	dl_float32 m_nearZ;
	dl_float32 m_farZ;
	dl_int m_width;
	dl_int m_height;
	dl_float32 m_fVar74;
	dl_float32 m_fVar78;
	dl_float32 m_fVar7C;
	dl_float32 m_fVar80;
	dl_float32 m_fVar84;
	dl_float32 m_fVar88;
	dl_float32 m_fVar8C;
	DLTX::DLString* m_pInitMapName;
	dl_pointer m_pVar98;
	CharacterResources m_characterResources;
	GuiFramework::GUITweakerDialog* m_pDebugGUI;
	dl_bool m_bDrawAxis;
	dl_bool m_bDrawGrid;
	dl_bool m_bVar5A2;
	dl_bool m_bVar5A3;
	dl_bool m_bVar5A4;
	dl_bool m_bVar5A5;
	dl_bool m_bVar5A6;
	dl_bool m_bVar5A7;
	dl_bool m_bVar5A8;
	dl_bool m_bVar5A9;
	dl_bool m_bVar5AA;
	dl_bool m_bVar5AB;
	dl_float32 m_fVar5AC;
	dl_float32 m_fVar5B0;
};