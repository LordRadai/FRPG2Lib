#pragma once
#include <Windows.h>
#include "../../../Common/hkReferencedObject.h"
#include "../../../Common/hkSimpleProperty.h"
#include "../../Collide/hkpLinkedCollidable.h"
#include "../World/hkpWorld.h"

namespace Havok
{
    struct hkpWorldObject : public hkReferencedObject {
        hkpWorld* m_world;
        UINT64 m_userData;
        hkpLinkedCollidable m_collidable;
        hkMultiThreadCheck m_multiThreadCheck;
        char* m_name;
        hkArray<hkSimpleProperty> m_properties;

        UINT64 getPropertyValue(UINT key) 
        {
            for (size_t i = 0; i < m_properties.size(); i++)
            {
                hkSimpleProperty property = m_properties.at(i);

                if (property.m_key == key)
                    return property.m_value.m_data;
            }

            return -1;
        }
    };
}