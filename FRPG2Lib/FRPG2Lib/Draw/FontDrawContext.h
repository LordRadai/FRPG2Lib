#pragma once
#include "DrawContext.h"
#include "../Memory/Memory.h"

_declspec(align(8))
class FontDrawContext
{
	char data[688];
public:
	struct PositionData
	{
		float x = 0.f;
		float y = 0.f;
		float f8 = 0.f;
		float fC = 0.f;

		PositionData() {}

		PositionData(float x, float y)
		{
			this->x = x;
			this->y = y;
		}
	};

	static void* operator new(size_t size)
	{
		return DLKR::AllocateAligned(sizeof(FontDrawContext), 8, GetHeap(HEAPTYPE_TEMP));
	}

	static void operator delete(void* block)
	{
		return DLKR::Free(block, GetHeap(HEAPTYPE_TEMP));
	}

	FontDrawContext(IDrawContext* pDrawContext);

	bool Initialize(dl_uint fontId, dl_pointer pUnkResource);
	void Finalize();
	void SetColor(dl_uint color);
	void SetHasShadow(dl_bool bHasShadow);
	void SetIsBold(dl_bool bHasShadow);
	void SetSize(DLMT::DL_VECTOR2 size);
	void SetShadowOffset(DLMT::DL_VECTOR2 shadowOffset);
	void Draw(PositionData* pPositionData, const dl_wchar* text);
	DLMT::DL_VECTOR2* GetTextSize(DLMT::DL_VECTOR2 pBuffer[2], const dl_wchar* text);
};