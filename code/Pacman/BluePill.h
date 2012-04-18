#pragma once
#include "pill.h"
#include "BlueEffect.h"
class BluePill :
	public Pill
{
public:
	BluePill(void);
	~BluePill(void);

	BuffEffect* getEffect();
};

