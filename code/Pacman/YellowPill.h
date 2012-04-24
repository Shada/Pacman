#pragma once
#include "Pill.h"
#include "YellowEffect.h"

class YellowPill : public Pill
{
public:
	YellowPill(Tile* t, ID3D10EffectTechnique* tech, Model* m);
	~YellowPill();

	BuffEffect* getEffect();
};