#include "BluePill.h"


BluePill::BluePill(Tile* t, ID3D10EffectTechnique* tech, Model* m)
	:Pill(t, tech, m)
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
