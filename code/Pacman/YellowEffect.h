#pragma once
#include "BuffEffect.h"

class YellowEffect : public BuffEffect
{
public:
	YellowEffect();
	~YellowEffect();

	void update(double dt);
};