#pragma once
#include "pill.h"
#include "BlueEffect.h"
class BluePill :
	public Pill
{
public:
	BluePill(Tile* t, D3DXVECTOR3 *pos,ID3D10EffectTechnique* tech, Model* m);
	~BluePill();

	BuffEffect* getEffect();
};

