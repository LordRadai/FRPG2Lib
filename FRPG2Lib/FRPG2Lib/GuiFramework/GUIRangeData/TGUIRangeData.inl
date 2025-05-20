#pragma once
#include "GUIRangeDataBase.h"

namespace GuiFramework
{
	template<typename T>
	class TGUIRangeData : public GUIRangeDataBase
	{
	public:
		TGUIRangeData() : GUIRangeDataBase() {}
		TGUIRangeData(T value, T min, T max, T step, dl_float32 mult) : GUIRangeDataBase()
		{
			this->min = min;
			this->max = max;
			this->stepSize = step;
			this->mult = mult;
			this->value = value;
			this->oldValue = this->value;

			this->ResetFlags();
		}

		virtual ~TGUIRangeData() {}

		virtual bool setValueByText(const wchar_t* text)
		{
			T value = 0;

			if (wcscmp(text, L"") != 0)
				value = std::stoi(text) / mult;

			if (value > this->max)
				value = this->max;

			if (value < this->min)
				value = this->min;

			if (this->value == value)
				return false;

			this->value = value;
			return true;
		}

		virtual void getValueString(DLTX::DLString* pBuf)
		{
			T value = this->value * this->mult;

			DLTX::DLFormat::Format(pBuf, L"%d", value);
		}

		virtual bool stepIncrement(int stepDir, int stepFast)
		{
			T currentVal = this->value;

			int numStep = 1;
			if (stepFast)
				numStep = 10;

			T newValue = (stepDir * this->stepSize * numStep) + currentVal;
			this->value = newValue;

			if (stepDir < 1)
			{
				if (this->value < this->min)
					this->value = this->min;
			}
			else
			{
				if (this->value > this->max)
					this->value = this->max;
			}

			if (currentVal != this->value)
				return true;

			return false;
		}

		virtual void undo()
		{
			this->value = this->oldValue;
		}

		virtual void getNumSteps(int* param_1, UINT* pStepNum)
		{
			*param_1 = 0;

			double numSteps = ceil((this->max - this->min) / this->stepSize);

			if (numSteps > 65535.f)
			{
				*pStepNum = 0xFFFF;
				return;
			}

			*pStepNum = static_cast<int>(numSteps);
		}

		virtual bool setValueByStep(UINT step)
		{
			T oldValue = this->value;

			this->value = this->getValueAtStep(step);

			if (oldValue != this->value)
				return true;

			return false;
		}

		T getValueAtStep(UINT step)
		{
			double numSteps = ceil((this->max - this->min) / this->stepSize);

			float valueAtStep = this->stepSize * step + this->min;

			if (valueAtStep < this->min)
				valueAtStep = this->min;
			else if (valueAtStep > this->max)
				valueAtStep = this->max;

			return valueAtStep;
		}

		virtual int getStepNumber()
		{
			return (this->value - this->min) / this->stepSize;
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUIRangeData<T>), 8, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetHeap(HEAPTYPE_GUIDEFAULT));
		}

		T min;
		T max;
		T value;
		T stepSize;
		T oldValue;
		float mult;
	};

	template<>
	inline bool TGUIRangeData<float>::setValueByText(const wchar_t* text)
	{
		float value = 0;

		if (wcscmp(text, L"") != 0)
			value = std::stof(text) / mult;

		if (value > this->max)
			value = this->max;

		if (value < this->min)
			value = this->min;

		if (this->value == value)
			return false;

		this->value = value;
		return true;
	}

	template<>
	inline bool TGUIRangeData<double>::setValueByText(const wchar_t* text)
	{
		double value = 0;

		if (wcscmp(text, L"") != 0)
			value = std::stod(text) / mult;

		if (value > this->max)
			value = this->max;

		if (value < this->min)
			value = this->min;

		if (this->value == value)
			return false;

		this->value = value;
		return true;
	}

	template<>
	inline void TGUIRangeData<float>::getValueString(DLTX::DLString* pBuf)
	{
		float value = this->value * this->mult;

		DLTX::DLFormat::Format(pBuf, L"%.4f", value);
	}

	template<>
	inline void TGUIRangeData<double>::getValueString(DLTX::DLString* pBuf)
	{
		double value = this->value * this->mult;

		DLTX::DLFormat::Format(pBuf, L"%.4lf", value);
	}
}