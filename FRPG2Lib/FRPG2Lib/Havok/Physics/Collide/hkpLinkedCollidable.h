#pragma once
#include <Windows.h>
#include "hkpCollidable.h"
#include "../../Common/hkBaseDefs.h"

namespace Havok
{
    struct hkpLinkedCollidable : public hkpCollidable {
		struct CollisionEntry
		{
			void* m_agentEntry;
			hkpLinkedCollidable* m_partner;
		};

        hkArray<CollisionEntry> m_collisionEntries;
    };
}