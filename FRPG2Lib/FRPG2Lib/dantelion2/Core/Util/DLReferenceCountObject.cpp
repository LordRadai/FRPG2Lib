#include "DLReferenceCountObject.h"

namespace DLUT
{
	void DLReferenceCountObject::Ref()
	{
		this->m_nRefCount += 1;
	}

	void DLReferenceCountObject::Unref()
	{
		this->m_nRefCount -= 1;
	}
}