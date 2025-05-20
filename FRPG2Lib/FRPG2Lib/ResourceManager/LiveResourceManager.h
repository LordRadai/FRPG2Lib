#pragma once
#include "dantelion2/dantelion2.h"
#include "ResourceMemoryWatchdog.h"
#include "Memory/WinAssertHeapStrategy.h"
#include "ResourceObject/ResourceObject.h"

class LiveResourceManager
{
    void** _vfptr;

public:
    dl_int m_iVar8;
    DLKR::DLAllocator* m_pAllocator;
    dl_pointer field7_0x18;
    DLUT::DLVector<ResourceObject*>* m_pRegisteredResources;
    dl_pointer field9_0x28;
    dl_int field10_0x30;
    dl_int field14_0x34;
    dl_int field18_0x38;
    dl_int field22_0x3c;
    DLTX::DLString field26_0x40;
    dl_int field27_0x70;
    dl_int field31_0x74;
    dl_int field35_0x78;
    dl_int field39_0x7c;
    dl_int field43_0x80;
    dl_int field47_0x84;
    DLTX::DLString field51_0x88;
    dl_int field52_0xb8;
    dl_int field56_0xbc;
    ResourceMemoryWatchDog m_resourceMemoryWatchdog;
    ResourceMemoryWatchDog* m_pResourceMemoryWatchdog;
    dl_int field62_0xd0;
    dl_uint field63_0xd4;
    dl_uint field64_0xd8;
    dl_uint field65_0xdc;
    DLKRD::HeapAllocator<DLKR::DLDynamicHeap<WinAssertHeapStrategy<DLKR::DLDefaultHeapStrategy<DLKR::DLRegularHeap, DLKR::DLMultiThreadingPolicy>>>>* field66_0xe0;
};