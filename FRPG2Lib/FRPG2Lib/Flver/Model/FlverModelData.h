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
		dl_int16 m_sVar1a0;
		dl_int16 m_sVar1a2;
		dl_int m_iVar1a4;
		dl_int m_lodLevel;
		dl_int m_iVar1ac;
		dl_bool m_bDraw;
		dl_bool m_bVar1b1;
		dl_bool m_bVar1b2;
		dl_bool m_bVar1b3;
		dl_int m_iVar1b4;
		dl_int m_iVar1b8;
		dl_int m_memoryRequirements;
		dl_int m_polygonCount;
		dl_int m_visiblePolygonCount;
		dl_int m_iVar1c8;
		dl_int m_iVar1cc;
		DLMT::DL_VECTOR4 m_bbMin;
		DLMT::DL_VECTOR4 m_bbMax;
		DLUT::DLVector<dl_pointer> m_materials;
		DLUT::DLVector<dl_pointer> m_textures;
		dl_pointer m_pMdlSkeleton;
		DLKR::DLAllocator* m_pSkeletonAllocator;
	};
}