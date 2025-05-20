#include "DrawParameters.h"
#include "FRPG2Globals.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oCreateDrawParameters)(DrawParameters* pDrawInfo, IDrawContext* pDrawContext);
typedef void(_fastcall* oDrawInfoApplyTransform)(DrawParameters* pDrawInfo, Matrix* pTransform);

DrawParameters::DrawParameters(IDrawContext* pDrawContext)
{
	FRPG2_CALL(oCreateDrawParameters, 0xb40490, this, pDrawContext);
}

void DrawParameters::ApplyTransform(Matrix* pTransform)
{
	pTransform->m[3][3] = 1.f;

	FRPG2_CALL(oDrawInfoApplyTransform, 0xb40ce0, this, pTransform);
}