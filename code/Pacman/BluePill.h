#pragma once
#include "Pill.h"
#include "BlueEffect.h"

class BluePill :
	public Pill
{
public:
	BluePill(Tile* t, ID3D10EffectTechnique* tech, Model* m);
	~BluePill();

	BuffEffect* getEffect();
};