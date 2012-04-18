#include "YellowPill.h"


YellowPill::YellowPill()
	:Pill()
{
	color = D3DXCOLOR(255,242,0,255);
}

BuffEffect* YellowPill::getEffect()
{
	return new YellowEffect();
}

YellowPill::~YellowPill()
{
}
