#include "YellowPill.h"


YellowPill::YellowPill(Tile* t, ID3D10EffectTechnique* tech, Model* m)
	:Pill(t, tech, model)
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