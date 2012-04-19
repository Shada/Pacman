#include "Pill.h"


Pill::Pill(Tile* t, D3DXVECTOR3 *pos,ID3D10EffectTechnique* tech, Model* m)
	:GameObject(t, pos, tech, m)
{
	color = D3DXCOLOR(255,0,255,255);
}

void Pill::update(float dt)
{
}


Pill::~Pill()
{
}
