#include "Properties.h"
#include "FRPG2Call.h"

typedef dl_int(_fastcall* oGetPropertyInt)(Properties* pThis, DLTX::DLString name, dl_int defaultValue);
typedef dl_bool(_fastcall* oGetPropertyBool)(Properties* pThis, DLTX::DLString name, dl_bool defaultValue);
typedef dl_float32(_fastcall* oGetPropertyFloat)(Properties* pThis, DLTX::DLString name, dl_float32 defaultValue);
typedef void(_fastcall* oGetPropertyString)(Properties* pThis, DLTX::DLString* pBuffer, DLTX::DLString name, DLTX::DLString defaultValue);
typedef void(_fastcall* oSetPropertyValue)(Properties* pThis, DLTX::DLString name, DLTX::DLString string);

dl_int Properties::GetIntProperty(DLTX::DLString name, dl_int defaultValue)
{
	return FRPG2_CALL(oGetPropertyInt, 0x87cd40, this, name, defaultValue);
}

dl_bool Properties::GetBoolProperty(DLTX::DLString name, dl_bool defaultValue)
{
	return FRPG2_CALL(oGetPropertyBool, 0x87d010, this, name, defaultValue);
}

dl_float32 Properties::GetFloatProperty(DLTX::DLString name, dl_float32 defaultValue)
{
	return FRPG2_CALL(oGetPropertyFloat, 0x87d440, this, name, defaultValue);
}

void Properties::GetStringProperty(DLTX::DLString* pBuf, DLTX::DLString name, DLTX::DLString defaultValue)
{
	FRPG2_CALL(oGetPropertyString, 0x87d320, this, pBuf, name, defaultValue);
}

void Properties::SetPropertyValue(DLTX::DLString name, DLTX::DLString value)
{
	FRPG2_CALL(oSetPropertyValue, 0x87d720, this, name, value);
}