#include "FileResourceObject.h"
#include "FRPG2Call.h"

typedef void(_fastcall* oReadFile)(FileResourceObject* pThis);

void FileResourceObject::ReadFile()
{
	FRPG2_CALL(oReadFile, 0xaff7a0, this);
}