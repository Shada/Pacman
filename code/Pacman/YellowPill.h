#pragma once
#include "Pill.h"
#include "YellowEffect.h"
class YellowPill : public Pill
{
public:
	YellowPill();
	~YellowPill();

	BuffEffect* getEffect();
};

