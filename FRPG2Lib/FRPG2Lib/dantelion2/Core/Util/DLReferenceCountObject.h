#pragma once

namespace DLUT
{
	class DLReferenceCountObject
	{
	protected:
		void** _vfptr;
		int m_nRefCount;

	public:
		void Ref();
		void Unref();
	};
}