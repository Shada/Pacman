#include "BlueEffect.h"


BlueEffect::BlueEffect()
	: BuffEffect(300)
{
	counter = 10.0f;
}

void BlueEffect::update(double dt)
{
	//make the owner invernable to ghosts

	BuffEffect::setMultiplier(2.0f);
	counter -= dt;
}

BlueEffect::~BlueEffect()
{
	//this will not work if the effectlist has multiple 
	//instances of the same effect
	BuffEffect::setMultiplier(1.0f);
}