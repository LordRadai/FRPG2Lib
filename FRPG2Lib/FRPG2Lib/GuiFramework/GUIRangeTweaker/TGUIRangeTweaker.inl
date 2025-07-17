#pragma once
#include "GUIRangeTweaker.h"
#include "../GUIRangeData/TGUIRangeData.inl"
#include "../GUITweakerGroup/GUITweakerGroup.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIRangeTweaker : public GUIRangeTweaker
	{
	public:
		TGUIRangeTweaker(GUITweakerGroup* pParent, GUIText* title, T* pValue, T min, T max, T step, float mult = 1.f) : GUIRangeTweaker()
		{
			this->pRangeData = new TGUIRangeData<T>(*pValue, min, max, step, mult);

			this->pValue = pValue;
			this->valueBak = *pValue;

			this->CreateRangeTweakWidget(pParent, title);
			this->ResetFlags();

			pParent->AddTweakerAsChild(this);
		}

		virtual ~TGUIRangeTweaker() {}

		virtual void OnDestroy()
		{
			this->pValue = nullptr;
			GUIRangeTweaker::OnDestroy();
		}

		virtual void update()
		{
			if (this->pValue)
			{
				if (*this->pValue == this->valueBak)
				{
					if (this->valueBak != this->pRangeData->value)
					{
						if ((this->styleFlags & 1) == 0)
						{
							this->valueBak = this->pRangeData->value;
							*this->pValue = this->valueBak;
						}
						else
						{
							this->pRangeData->value = this->valueBak;

							this->m_pRangeTweakWidget->UpdateDisplayValue();
						}
					}
				}
				else
				{
					this->valueBak = *this->pValue;
					this->pRangeData->value = this->valueBak;

					this->m_pRangeTweakWidget->UpdateDisplayValue();
				}
			}
		}

		virtual void unregister()
		{
			this->pValue = nullptr;
			GUIRangeTweaker::unregister();
		}

		virtual TGUIRangeData<T>* getRangeData()
		{
			return this->pRangeData;
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUIRangeTweaker<T>), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		TGUIRangeData<T>* pRangeData = nullptr;
		T* pValue = nullptr;
		T valueBak = 0;
	};
}