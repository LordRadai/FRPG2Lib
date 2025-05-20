#pragma once
#include "dantelion2/Core/Util/DLVector.h"
#include "dantelion2/Core/Util/DLReferenceCountObject.h"
#include "dantelion2/Core/Math/Math.h"
#include "MdlObj.h"
#include "MdlMtx.h"
#include "MdlPrim2.h"
#include "MdlIdxBuf2.h"
#include "MdlVtfBuf2.h"
#include "MdlVtxDecl2.h"
#include "MdlDmy.h"
#include <SimpleMath.h>
#include <vector>

using namespace DirectX::SimpleMath;

namespace Flver
{
	struct FlverModelData : public DLUT::DLReferenceCountObject
	{
		MdlObj m_mdlObj;
		MdlMtx m_mdlMtx;
		MdlMtx m_mdlMtx2;
		MdlDmy m_mdlDmy;
		MdlPrim2 m_mdlPrim;
		MdlIdxBuf2 m_mdlIdxBuf;
		MdlVtxBuf2 m_mdlVtxBuf;
		MdlVtxDecl2 m_mdlVtxDecl;
		MdlMtx m_mdlMtx3;
		short m_sVar1a0;
		short m_sVar1a2;
		int m_iVar1a4;
		int m_lodLevel;
		int m_iVar1ac;
		bool m_bDraw;
		bool m_bVar1b1;
		bool m_bVar1b2;
		bool m_bVar1b3;
		int m_iVar1b4;
		int m_iVar1b8;
		int m_memoryRequirements;
		int m_polygonCount;
		int m_visiblePolygonCount;
		int m_iVar1c8;
		int m_iVar1cc;
		DLMT::DL_VECTOR4 m_bbMin;
		DLMT::DL_VECTOR4 m_bbMax;
		DLUT::DLVector<void*> m_materials;
		DLUT::DLVector<void*> m_textures;
		void* m_pMdlSkeleton;
		DLKR::DLAllocator* m_pSkeletonAllocator;
	};
}