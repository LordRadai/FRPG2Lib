#include "DrawParameters.h"
#include "FRPG2Globals.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oCreateDrawParameters)(DebugDrawParameters* pDrawInfo, IDrawContext* pDrawContext);
typedef void(_fastcall* oDrawInfoApplyTransform)(DebugDrawParameters* pDrawInfo, const Matrix& transform);

DebugDrawParameters::DebugDrawParameters(IDrawContext* pDrawContext)
{
	FRPG2_CALL(oCreateDrawParameters, 0xb40490, this, pDrawContext);
}

void DebugDrawParameters::ApplyTransform(const Matrix& transform)
{
	FRPG2_CALL(oDrawInfoApplyTransform, 0xb40ce0, this, transform);
}