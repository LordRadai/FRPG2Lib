#pragma once
#include "../DrawContext.h"

class DebugDrawParameters
{
	IDrawContext* m_pDrawContext = nullptr;
	int iVar4 = 0;
	int iVar8 = 0;
	Matrix m_transform = Matrix::Identity;
	int m_iVar50 = -1;

public:
	DebugDrawParameters(IDrawContext* pDrawContext);
	void ApplyTransform(Matrix* pTransform);
};