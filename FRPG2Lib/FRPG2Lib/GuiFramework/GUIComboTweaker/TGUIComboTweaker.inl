#pragma once
#include "GUIComboTweaker.h"
#include "../GUIValueStringPairData/TGUIValueStringPairData.inl"
#include "FRPG2Call.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIComboTweaker : public GUIComboTweaker
	{
	public:
		TGUIComboTweaker() {}
		TGUIComboTweaker(GUITweakerGroup* pParent, GUIText* title, T* pValue, TGUIComboItem<T>* comboItems, int numValues) : GUIComboTweaker(pParent, title, 0)
		{
			this->m_pValue = pValue;
			this->m_oldValue = *pValue;
			this->m_valueStringPairData = new TGUIValueStringPairData<T>(comboItems, numValues);
			this->InitialiseComboBoxStrings();

			this->ResetFlags();
			pParent->AddTweakerAsChild(this);
		}

		virtual ~TGUIComboTweaker() {}
		virtual void onDestroy()
		{
			this->Destroy();
			this->m_pValue = nullptr;

			GUIComboTweaker::onDestroy();
		}

		virtual void update()
		{
			if (this->m_pValue && (this->m_oldValue != *this->m_pValue))
			{
				this->m_oldValue = *this->m_pValue;

				int stringPairIdx = getValueStringPairIndexByValue(this->m_oldValue);
				this->m_pGUIComboTweakWidget->m_pComboBox->SetDisplayItem(stringPairIdx);
			}
		}

		virtual void unregister()
		{
			this->m_pValue = nullptr;
			GUIComboTweaker::unregister();
		}

		virtual void updateValue(UINT idx)
		{
			if (((this->m_interactionFlags & 1) == 0))
			{
				TValueStringPair<T>* valueStringPair = this->m_valueStringPairData->getValueStringPair(idx);

				this->m_oldValue = static_cast<T>(valueStringPair->value);
				*this->m_pValue = this->m_oldValue;
			}
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUIComboTweaker<T>), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		int getValueStringPairIndexByValue(int value)
		{
			for (size_t i = 0; i < this->m_valueStringPairData->m_valueStringPairs.size(); i++)
			{
				TValueStringPair<T> valueStringPair = this->m_valueStringPairData->m_valueStringPairs[i];

				if (valueStringPair.value == value)
					return i;
			}
		}

		void InitialiseComboBoxStrings()
		{
			typedef void(_fastcall* oInitGUIComboBoxStrings)(TGUIComboTweaker<T>* pThis);

			FRPG2_CALL(oInitGUIComboBoxStrings, 0x566310, this);
		}

		T m_oldValue;
		T* m_pValue;
		TGUIValueStringPairData<T>* m_valueStringPairData;
	};
}