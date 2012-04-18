#include "BluePill.h"


BluePill::BluePill()
	:Pill()
{
	color = D3DXCOLOR(0,0,255,255);
}

BuffEffect* BluePill::getEffect()
{
	return new BlueEffect();
}


BluePill::~BluePill()
{
}
