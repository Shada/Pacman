#include "BlueEffect.h"


BlueEffect::BlueEffect()
	: BuffEffect()
{
	counter = 10.0f;
}
void BlueEffect::update(float dt)
{
	//make the owner invernable to ghosts

	counter-=dt;
}
BlueEffect::~BlueEffect()
{
}
