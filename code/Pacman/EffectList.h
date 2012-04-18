#pragma once
#include "stdafx.h"
#include "BuffEffect.h"
class EffectList
{
private:
	vector<BuffEffect*> list;
public:
	EffectList();
	~EffectList();

	void update(float dt);

	//could perhaps check if that effect already exist and if so
	//replace it with the new one instead of just adding it
	void addEffect(BuffEffect* effect);
};

