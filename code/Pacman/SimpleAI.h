#pragma once
#include "AI.h"

class SimpleAI :
	public AI
{
private:
	Direction decideMovement(Tile *currentTile);
public:
	SimpleAI(int tileAmount);
	~SimpleAI();
};