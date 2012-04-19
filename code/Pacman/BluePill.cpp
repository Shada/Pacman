#include "BluePill.h"


BluePill::BluePill(Tile* t, D3DXVECTOR3 *pos,ID3D10EffectTechnique* tech, Model* m)
	:Pill(t, pos, tech, m)
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
