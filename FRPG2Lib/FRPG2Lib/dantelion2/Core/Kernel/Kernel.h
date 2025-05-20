#pragma once
#include "DLAllocator.h"
#include "DLNew.h"
#include "SyncObjects.h"
#include "detail/HeapAllocator.inl"
#include "DLWin32RuntimeHeapImpl.h"

#include "DLDynamicHeap.inl"
#include "DLSmallObjectWrapper.inl"

#include "DLRegularHeap.h"
#include "DLBiHeap.h"
#include "DLRobustHeap.h"

#include "DLBiHeapStrategy.inl"
#include "DLDefaultHeapStrategy.inl"

#include "DLMultiThreadingPolicy.h"
#include "DLSingleThreadingPolicy.h"