#include "FontDrawContext.h"
#include "FRPG2Call.h"

typedef void* (_fastcall* oConstructor)(FontDrawContext* pThis, IDrawContext* pDrawContext);
typedef bool(_fastcall* oInitialise)(FontDrawContext* pThis, dl_int font_id, dl_pointer param_3);
typedef void(_fastcall* oSetColor)(FontDrawContext* pThis, dl_uint color);
typedef void(_fastcall* oSetStyleFlag)(FontDrawContext* pThis, dl_bool bHasShadow);
typedef void(_fastcall* oSetSize)(FontDrawContext* pThis, DLMT::DL_VECTOR2 size);
typedef void(_fastcall* oDestroy)(FontDrawContext* pThis);
typedef void(_fastcall* oDraw)(FontDrawContext* pThis, FontDrawContext::PositionData* pPositionData, const wchar_t* text);
typedef DLMT::DL_VECTOR2*(_fastcall* oGetTextSize)(FontDrawContext* pThis, DLMT::DL_VECTOR2* pOut, const wchar_t* text);

FontDrawContext::FontDrawContext(IDrawContext* pDrawContext)
{
	FRPG2_CALL(oConstructor, 0xb66a00, this, pDrawContext);
}

bool FontDrawContext::Initialize(dl_uint fontId, dl_pointer pUnkResource)
{
	return FRPG2_CALL(oInitialise, 0xb66a70, this, fontId, pUnkResource);
}

void FontDrawContext::Finalize()
{
	FRPG2_CALL(oDestroy, 0xb66a50, this);
}

void FontDrawContext::SetColor(dl_uint color)
{
	FRPG2_CALL(oSetColor, 0xb67330, this, color);
}

void FontDrawContext::SetHasShadow(dl_bool bHasShadow)
{
	FRPG2_CALL(oSetStyleFlag, 0xb67110, this, bHasShadow);
}

void FontDrawContext::SetIsBold(dl_bool bBold)
{
	FRPG2_CALL(oSetStyleFlag, 0xb670b0, this, bBold);
}

void FontDrawContext::SetSize(DLMT::DL_VECTOR2 size)
{
	FRPG2_CALL(oSetSize, 0xb67360, this, size);
}

void FontDrawContext::SetShadowOffset(DLMT::DL_VECTOR2 shadowOffset)
{
	FRPG2_CALL(oSetSize, 0xb673c0, this, shadowOffset);
}

void FontDrawContext::Draw(FontDrawContext::PositionData* pPositionData, const dl_wchar* text)
{
	FRPG2_CALL(oDraw, 0xb67070, this, pPositionData, text);
}

DLMT::DL_VECTOR2* FontDrawContext::GetTextSize(DLMT::DL_VECTOR2 pBuffer[2], const dl_wchar* text)
{
	return FRPG2_CALL(oGetTextSize, 0xb671b0, this, pBuffer, text);
}