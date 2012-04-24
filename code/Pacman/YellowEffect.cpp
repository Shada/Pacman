#include "YellowEffect.h"


YellowEffect::YellowEffect()
	: BuffEffect(100)
{
	counter = 1.0f;
}

void YellowEffect::update(double dt)
{
	//give points to owner and/or decrease number of total
	//yellowpills left

	//make sure update() is only called once
	counter = 0;
}

YellowEffect::~YellowEffect()
{
}