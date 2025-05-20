#pragma once
#include <Windows.h>

typedef signed char dl_int8;
typedef signed short dl_int16;
typedef signed int dl_int32;
typedef signed long long dl_int64;
typedef unsigned char dl_uint8;
typedef unsigned short dl_uint16;
typedef unsigned int dl_uint32;
typedef unsigned long long dl_uint64;
typedef float dl_float32;
typedef double dl_float64;
typedef unsigned long long dl_size;
typedef char dl_char;
typedef unsigned char dl_uchar;
typedef wchar_t dl_wchar;
typedef int dl_int;
typedef unsigned int dl_uint;
typedef unsigned long long int dl_address;
typedef void* dl_pointer;
typedef int* dl_pointer_int;
typedef float* dl_pointer_float32;
typedef double* dl_pointer_float64;
typedef bool dl_bool;

typedef HANDLE sys_mutex_t;
typedef CRITICAL_SECTION sys_lwmutex_t;
typedef HANDLE sys_rwlock_t;
typedef HANDLE sys_semaphore_t;