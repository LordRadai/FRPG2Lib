#pragma once
#include "MetaInfoBase.h"
#include "MetaInfoParam.inl"

enum class MetaInfoParamType
{
	TYPE_INVALID,
	TYPE_SIGNED_CHAR,
	TYPE_SHORT,
	TYPE_INT,
	TYPE_INT64,
	TYPE_UNSIGNED_CHAR,
	TYPE_UNSIGNED_SHORT,
	TYPE_UNSIGNED_INT,
	TYPE_UNSIGNED_INT64,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_BOOL,
	TYPE_DLVECTOR2,
	TYPE_DLVECTOR3,
	TYPE_DLVECTOR4,
	TYPE_DLCOLOR32
};

enum class MetaInfoParamSemantic
{
	SEMANTIC_DEFAULT,
	SEMANTIC_VECTOR_COLOR32,
	SEMANTIC_VECTOR4AL_A2,
	SEMANTIC_VECTOR4AL_A8,
	SEMANTIC_COMBO,
	SEMANTIC_VECTOR2AL_YAWPITCH
};

template<typename ParamType, typename T>
class MetaInfo : public MetaInfoBase
{
public:
	T* m_pStorage;
	MetaInfoParamType m_type;
	MetaInfoParamSemantic m_semantic;
	MetaInfoParam<ParamType> m_param;
};