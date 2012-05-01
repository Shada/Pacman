#pragma once
#include "AI.h"

class SimpleAI :
	public AI
{
private:
	void regular(D3DXVECTOR3 position);
	void flee(D3DXVECTOR3 position);
	void dead(D3DXVECTOR3 position);
public:
	SimpleAI(vector<Tile*> *tiles, Tile *spawn);
	~SimpleAI();
};