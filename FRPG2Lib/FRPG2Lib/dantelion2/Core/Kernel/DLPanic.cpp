#include "DLPanic.h"
#include "FRPG2Call.h"

typedef void (_fastcall* oInvokePanic)(const char* srcModule, int lineNum, char* error);

namespace DLKR
{
	void InvokePanic(const char* srcModule, int lineNum, char* error)
	{
		FRPG2_CALL(oInvokePanic, 0x832cb0, srcModule, lineNum, error);
	}
}