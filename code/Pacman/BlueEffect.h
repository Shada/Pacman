#pragma once
#include "buffeffect.h"

class BlueEffect :
	public BuffEffect
{
public:
	BlueEffect();
	~BlueEffect();

	void update(double dt);
};