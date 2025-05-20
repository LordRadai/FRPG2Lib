#pragma once
#include <Windows.h>

enum ResponseType : BYTE {
    RESPONSE_INVALID = 0,
    RESPONSE_SIMPLE_CONTACT = 1,
    RESPONSE_REPORTING = 2,
    RESPONSE_NONE = 3,
    RESPONSE_MAX_ID = 4
};

struct hkpMaterial {
    ResponseType m_responseType;
    float m_friction;
    float m_restitution;
};