#include "DLStringUtil.h"
#include "FRPG2Call.h"
#include "Draw/DrawContext.h"

typedef void(_fastcall* oCreateDLString)(UINT64 ModelTestScene, IDrawContext* DrawContext);

namespace DLTX
{
	typedef void(_fastcall* oCopySize)(DLString* dst, const DLString* src, dl_size size);
	typedef void(_fastcall* oAssignAllocator)(DLString* dst, DLString* src, DLKR::DLAllocator* pAllocator);

	void Copy(DLString* dst, const DLString* src, dl_size size)
	{
		FRPG2_CALL(oCopySize, 0x3dc00, dst, src, size);
	}

	void Assign(DLString* dst, DLString* src, DLKR::DLAllocator* pAllocator)
	{
		FRPG2_CALL(oAssignAllocator, 0x3d780, dst, src, pAllocator);
	}
}