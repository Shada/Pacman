#include "Pill.h"


Pill::Pill(Tile* t, ID3D10EffectTechnique* tech, Model* m)
	:GameObject(t, tech, m)
{
	position.y += 4;
	color = D3DXCOLOR(255,0,255,255);
	rotSpeed = 0.002f;
	rotation = 0;
	hoverSpeed = rotSpeed * 0.75f;
	D3DXMatrixScaling(&mWorld, 0.2f, 0.2f, 0.2f);
}

void Pill::update(double dt)
{
	rotation += rotSpeed;
	D3DXMatrixRotationY(&mRot, rotSpeed);
	D3DXMatrixMultiply(&mWorld, &mWorld, &mRot);

	mWorld._42 += hoverSpeed;

	if(mWorld._42 > 3)
		hoverSpeed *= -1;
	else if( mWorld._42 < 0)
		hoverSpeed *= -1;
}

Pill::~Pill()
{
}