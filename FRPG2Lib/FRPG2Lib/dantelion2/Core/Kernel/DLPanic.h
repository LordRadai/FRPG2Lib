#pragma once

namespace DLKR
{
    #define DL_PANIC(error) InvokePanic(__FILE__, __LINE__, error)

    enum DLPanicMode
    {
        DLPANICMODE_INVOKEDEBUGGER,
        DLPANICMODE_COREDUMP,
        DLPANICMODE_THROWEXCEPTION,
        DLPANICMODE_NUM
    };

	void InvokePanic(const char* srcModule, int lineNum, char* error);
}