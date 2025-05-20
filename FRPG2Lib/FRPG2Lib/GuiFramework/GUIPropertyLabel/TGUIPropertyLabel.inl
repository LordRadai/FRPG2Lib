#pragma once
#include "GUIPropertyLabel.h"
#include "FRPG2Globals.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIPropertyLabel : public GUIPropertyLabel
	{
	public:
		TGUIPropertyLabel() {}
		TGUIPropertyLabel(GUITweakerGroup* pParent, GUIText* title, T* pValue) : GUIPropertyLabel(pParent, title, 1)
		{
			this->pValue = pValue;
		}

		virtual ~TGUIPropertyLabel() {}

		virtual int updateLabel(DLTX::DLString* buffer)
		{
			if (this->pValue == nullptr)
				return false;

			DLTX::DLFormat::Format(buffer, L"%d", *this->pValue);
			return (buffer->c_str() != nullptr);
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUIPropertyLabel<T>), 8, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		T* pValue;
	};

	template<>
	inline int TGUIPropertyLabel<dl_float32>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		DLTX::DLFormat::Format(buffer, L"%.3f", *this->pValue);
		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<const dl_char*>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		DLTX::DLFormat::Format(buffer, L"%s", *this->pValue);
		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<const dl_wchar*>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		DLTX::DLFormat::Format(buffer, L"%ws", *this->pValue);
		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<DLMT::DL_VECTOR3>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		DLMT::DL_VECTOR3 value = *(DLMT::DL_VECTOR3*)this->pValue;

		DLTX::DLFormat::Format(buffer, L"%.3f, %.3f, %.3f", value.x, value.y, value.z);
		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<DLMT::DL_VECTOR4>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		DLMT::DL_VECTOR4 value = *(DLMT::DL_VECTOR4*)this->pValue;

		DLTX::DLFormat::Format(buffer, L"%.3f, %.3f, %.3f, %.3f", value.x, value.y, value.z, value.w);
		return (buffer->c_str() != nullptr);
	}

	/*
	template<>
	inline int TGUIPropertyLabel<PXUserDataChrHp>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		int* value = (int*)this->pValue;

		DLTX::DLFormat::Format(buffer, L"%d/%d", value[0], value[3]);
		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<PXUserDataChrStatus>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		float* value = (float*)this->pValue;

		DLTX::DLFormat::Format(buffer, L"%.3f/%.3f", value[0], value[2]);
		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<NetworkStatus>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		int value = *(int*)this->pValue;

		switch (value)
		{
		case 0:
			DLTX::DLFormat::Format(buffer, L"Offline");
			break;
		case 1:
			DLTX::DLFormat::Format(buffer, L"Online");
			break;
		case 2:
			DLTX::DLFormat::Format(buffer, L"Sign Down");
			break;
		case 5:
			DLTX::DLFormat::Format(buffer, L"Hosting");
			break;
		case 6:
			DLTX::DLFormat::Format(buffer, L"Guest");
			break;
		default:
			DLTX::DLFormat::Format(buffer, L"%d", value);
			break;
		}

		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<WindowMode>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		int value = *(int*)this->pValue;

		switch (value)
		{
		case 0:
			DLTX::DLFormat::Format(buffer, L"Windowed");
			break;
		case 1:
			DLTX::DLFormat::Format(buffer, L"Fullscreen");
			break;
		default:
			DLTX::DLFormat::Format(buffer, L"WindowMode_%d", value);
			break;
		}

		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<MapName>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		int value = *(int*)this->pValue;

		DLTX::DLFormat::Format(buffer, L"%ls", DebugHelper::GetMapNameW(value).c_str());

		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<MapEntityStatus>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		bool value = *(bool*)this->pValue;

		if (value)
			DLTX::DLFormat::Format(buffer, L"■ Active");
		else
			DLTX::DLFormat::Format(buffer, L"□ Inactive");

		return (buffer->c_str() != nullptr);
	}

	template<>
	inline int TGUIPropertyLabel<MapEntityInterface*>::updateLabel(DLTX::DLString* buffer)
	{
		if (this->pValue == nullptr)
			return false;

		MapEntityInterface* MapEntity = *(MapEntityInterface**)this->pValue;

		DLTX::DLFormat::Format(buffer, L"%ws", MapEntity->m_wName);

		return (buffer->c_str() != nullptr);
	}
	*/
}