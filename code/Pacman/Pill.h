#pragma once
#include "stdafx.h"
#include "BuffEffect.h"
class Pill
{
protected:
	D3DXCOLOR color;
public:
	Pill();
	~Pill();

	virtual BuffEffect* getEffect() = 0;
};

