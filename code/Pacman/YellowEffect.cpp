#include "YellowEffect.h"


YellowEffect::YellowEffect()
	: BuffEffect()
{
	counter = 1.0f;
}

void YellowEffect::update(float dt)
{
	//give points to owner and/or decrease number of total
	//yellowpills left

	//make sure update() is only called once
	counter = 0;
}

YellowEffect::~YellowEffect()
{
}
