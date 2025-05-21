#pragma once
#include "GUICallbackObjectBase.h"

namespace GuiFramework
{
	class TGUICallbackObject : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject() {}

		TGUICallbackObject(std::function<void()> callback) : GUICallbackObjectBase()
		{
			this->callback = callback;
		}

		~TGUICallbackObject() {}

		void invoke()
		{
			if (this->m_interactionFlags & 0x40000000)
			{
				this->callback();
			}
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUICallbackObject), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		std::function<void()> callback;
	};

	template<typename T>
	class TGUICallbackObject1 : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject1() {}

		TGUICallbackObject1(std::function<void(T)> callback, T param_1) : GUICallbackObjectBase()
		{
			this->param_1 = param_1;
			this->callback = callback;
		}

		~TGUICallbackObject1() {}

		void invoke()
		{
			if (this->m_interactionFlags & 0x40000000)
			{
				this->callback(this->param_1);
			}
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUICallbackObject1), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		T param_1;
		std::function<void(T)> callback;
	};

	template<typename T, typename U>
	class TGUICallbackObject2 : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject2() {}

		TGUICallbackObject2(std::function<void(T, U)> callback, T param_1, U param_2) : GUICallbackObjectBase()
		{
			this->param_1 = param_1;
			this->param_2 = param_2;
			this->callback = callback;
		}

		~TGUICallbackObject2() {}

		void invoke()
		{
			if (this->m_interactionFlags & 0x40000000)
			{
				this->callback(this->param_1, this->param_2);
			}
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUICallbackObject2), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		T param_1;
		U param_2;
		std::function<void(T, U)> callback;
	};

	template<typename T, typename U, typename V>
	class TGUICallbackObject3 : public GUICallbackObjectBase
	{
	public:
		TGUICallbackObject3() {}

		TGUICallbackObject3(std::function<void(T, U)> callback, T param_1, U param_2, V param_3) : GUICallbackObjectBase()
		{
			this->param_1 = param_1;
			this->param_2 = param_2;
			this->param_3 = param_3;
			this->callback = callback;
		}

		~TGUICallbackObject3() {}

		void invoke()
		{
			if (this->m_interactionFlags & 0x40000000)
			{
				this->callback(this->param_1, this->param_2, this->param_3);
			}
		}

		static void* operator new(size_t size)
		{
			return DLKR::AllocateAligned(sizeof(TGUICallbackObject2), 8, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		static void operator delete(void* block)
		{
			return DLKR::Free(block, GetRootHeap(HEAPTYPE_GUIDEFAULT));
		}

		T param_1;
		U param_2;
		V param_3;
		std::function<void(T, U, V)> callback;
	};
}