#pragma once
#include "../GUIObject/GUIObject.h"
#include "dantelion2/dantelion2.h"

namespace GuiFramework
{
	template<typename T>
	struct TGUIComboItem
	{
		const wchar_t* m_name;
		T m_value;
	};

	template<typename T>
	struct TValueStringPair
	{
		TValueStringPair(const wchar_t* name, T value)
		{
			this->name = name;
			this->value = value;
		}

		UINT64 lVar0 = 0;
		const wchar_t* name;
		T value;
	};

	template<typename T>
	class TGUIValueStringPairData : public GUIObject
	{
	public:
		TGUIValueStringPairData() : GUIObject() {}
		TGUIValueStringPairData(TGUIComboItem<T>* comboItems, int numValues) : GUIObject()
		{
			for (int i = 0; i < numValues; i++)
			{
				TValueStringPair<T> valueStringPair(comboItems[i].m_name, comboItems[i].m_value);
				this->m_valueStringPairs.push_back(valueStringPair);
			}
		}

		virtual ~TGUIValueStringPairData() {}
		virtual void onDestroy() {}

		TValueStringPair<T>* getValueStringPair(int idx)
		{
			int numValueStringPars = m_valueStringPairs.size();

			if (idx < numValueStringPars)
				return &this->m_valueStringPairs[idx];

			return nullptr;
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUIValueStringPairData<T>), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		DLUT::DLVector<TValueStringPair<T>> m_valueStringPairs;
	};
}