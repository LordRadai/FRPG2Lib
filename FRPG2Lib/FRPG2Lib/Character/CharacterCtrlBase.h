#pragma once
#include "GameObject/GameObject.h"

class CharacterCtrlBase : public GameObject
{
public:
	enum EntityType : dl_uint8
	{
		ENTITYTYPE_CHR,
		ENTITYTYPE_PLAYER
	};

	struct EntityID 
	{
		dl_uint value;

		dl_uint GetID() const { return value & 0x00FFFFFF; }
		EntityType GetType() const { return static_cast<EntityType>(value >> 24); }
	};

	DLKR::DLAllocator* m_pAllocator;
	dl_int m_chrParamID;
	dl_int m_generatorID;
	dl_int m_chrType;
	dl_int m_iVar34;
	dl_pointer m_pChrParam;
	dl_pointer m_pChrCommonParam;
	dl_pointer m_pChrMoveParam;
	EntityID m_entityTypeAndID;
	dl_char m_bVar54;
	dl_char m_bVar55;
};