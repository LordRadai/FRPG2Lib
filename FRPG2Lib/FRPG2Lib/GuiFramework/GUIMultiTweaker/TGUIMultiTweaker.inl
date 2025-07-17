#pragma once
#include "GUIMultiTweaker.h"
#include "FRPG2Call.h"
#include "../GUITweakerGroup/GUITweakerGroup.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIMultiTweaker : public GUIMultiTweaker
	{
	public:
		TGUIMultiTweaker() {}
		TGUIMultiTweaker(GUITweakerGroup* pParent, GUIText* title, BYTE count, T* pValues, T min, T max, T step, float mult = 1.f) : GUIMultiTweaker(count, title)
		{
			this->numElements = count;
			this->pValues = pValues;

			this->pOldValues = static_cast<T*>(DLKR::AllocateAligned(count * sizeof(T), 4, GetRootHeap(HEAPTYPE_GUIDEFAULT)));

			for (BYTE i = 0; i < count; i++)
			{
				TGUIRangeData<T>* pRangeData = new TGUIRangeData<T>(pValues[i], min, max, step, mult);
				this->m_pMultiNumericEditor->SetRangeData(i, pRangeData);

				this->pOldValues[i] = this->pValues[i];
			}

			this->RegisterWidgets(pParent, title);
			this->ResetFlags();

			pParent->AddTweakerAsChild(this);
		}

		virtual ~TGUIMultiTweaker() {}
		virtual void OnDestroy()
		{
			if (this->pOldValues)
			{
				DLKR::Free(this->pOldValues, GetRootHeap(HEAPTYPE_GUIDEFAULT));

				this->pOldValues = nullptr;
			}

			GUIMultiTweaker::OnDestroy();
		}

		virtual void update()
		{
			if (this->pValues)
			{
				bool changed = false;

				for (int idx = 0; idx < this->numElements; idx++)
				{
					TGUIRangeData<T>* pRangeData = dynamic_cast<TGUIRangeData<T>*>(this->m_pMultiNumericEditor->GetRangeData(idx));

					if (pRangeData)
					{
						if (this->pValues[idx] == this->pOldValues[idx])
						{
							if (this->pOldValues[idx] != pRangeData->value)
							{
								if ((this->styleFlags & 1) == 0)
								{
									this->pOldValues[idx] = pRangeData->value;
									this->pValues[idx] = this->pOldValues[idx];
									changed = true;
								}
								else
								{
									pRangeData->value = this->pOldValues[idx];

									this->m_pMultiNumericEditor->UpdateValue(idx);
								}
							}
						}
						else
						{
							this->pOldValues[idx] = this->pValues[idx];
							pRangeData->value = this->pOldValues[idx];

							this->m_pMultiNumericEditor->UpdateValue(idx);
						}
					}
				}
			}
		}

		virtual void unregister()
		{
			this->pValues = nullptr;
			GUIMultiTweaker::unregister();
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUIMultiTweaker<T>), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		dl_uchar numElements = 0;
		T* pValues = nullptr;
		T* pOldValues = nullptr;
	};
}