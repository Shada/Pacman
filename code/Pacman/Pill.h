#pragma once

#include "GameObject.h"
#include "stdafx.h"
#include "BuffEffect.h"

class Pill : public GameObject
{
protected:
	D3DXCOLOR color;
public:
	Pill(Tile* t, D3DXVECTOR3 *pos,ID3D10EffectTechnique* tech, Model* m);
	~Pill();

	virtual BuffEffect* getEffect() = 0;

	//make the pill float up and down and/or rotate
	void update(float dt);
};

