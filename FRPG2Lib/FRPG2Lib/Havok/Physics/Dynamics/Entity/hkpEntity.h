#pragma once
#include "../Common/hkpMaterial.h"
#include "../Common/hkpWorldObject.h"
#include "../Motion/hkpMaxSizeMotion.h"

namespace Havok
{
    struct hkpEntity : public hkpWorldObject {
        struct SpuCollisionCallback {
            void* m_util;
            USHORT m_capacity;
            byte m_eventFilter;
            byte m_userFilter;
        };

        hkpMaterial m_material;
        void* m_limitContactInfoUtilAndFlag;
        float m_damageMultiplier;
        void* m_breakableBody;
        UINT m_solverData;
        USHORT m_storageIndex;
        USHORT m_contactPointCallbackDelay;
        hkSmallArray<void*> m_constraintsMaster;
        hkArray<void*> m_constraintsSlave;
        hkArray<void*> m_constraintRuntime;
        void* m_simulationIsland;
        byte m_autoRemoveLevel;
        byte m_numShapeKeysInContactProperties;
        byte m_responseModifierFlags;
        UINT m_uid;
        SpuCollisionCallback m_spuCollisionCallback;
        hkpMaxSizeMotion m_maxSizeMotion;
        hkSmallArray<void*> m_contactListeners;
        hkSmallArray<void*> m_actions;
        void* m_localFrame;
        void* m_extendedListeners;
        UINT m_npData;
    };
}