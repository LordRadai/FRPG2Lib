#pragma once
#include "LiveResourceManager.h"
#include "ResourceObject/CommonbndFileCap.h"
#include "ResourceObject/RegulationResourceObject.h"

class AppResourceManagerBase : public LiveResourceManager
{
public:
    template<typename Resource>
    struct ResourceContainer
    {
        Resource* m_pResource;
        dl_uint m_iVar0;
        dl_uint m_iVar4;
    };

    DLKRD::HeapAllocator<DLKR::DLDynamicHeap<WinAssertHeapStrategy<DLKR::DLBiHeapStrategy<DLKR::DLRobustHeap, DLKR::DLMultiThreadingPolicy>>>>* m_pResourceAllocator;
    DLKRD::HeapAllocator<DLKR::DLDynamicHeap<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>>>* m_pUnkAllocator;
    dl_pointer m_pFlverResourceFactory;
    dl_int* field4_0x100;
    ResourceContainer<CommonbndFileCap> m_modelPartsResource;
    ResourceContainer<RegulationResourceObject> m_regulationResource;
    ResourceContainer<CommonbndFileCap> m_modelPartsLqResource;
    dl_bool m_bLoadedResources;
    dl_int field18_0x13c;
    AppResourceMemoryWatchDog m_appResourceMemoryWatchdog;
    dl_bool field20_0x148;
};