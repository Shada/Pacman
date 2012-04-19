#include "YellowPill.h"


YellowPill::YellowPill(Tile* t, D3DXVECTOR3 *pos,ID3D10EffectTechnique* tech, Model* m)
	:Pill(t, pos, tech, model)
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
