#pragma once
#include "GameObject.h"
#include "stdafx.h"
#include "BuffEffect.h"

class Pill : public GameObject
{
protected:
	D3DXCOLOR color;
	BuffEffect *effect;

	float rotSpeed, hoverSpeed;
public:
	Pill(Tile* t, ID3D10EffectTechnique* tech, Model* m);
	~Pill();

	virtual BuffEffect* getEffect() { return effect; }

	//make the pill float up and down and/or rotate
	void update(double dt);
};