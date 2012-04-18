#pragma once
#include "BuffEffect.h"
class YellowEffect : public BuffEffect
{
public:
	YellowEffect(void);
	~YellowEffect(void);

	void update(float dt);
};

