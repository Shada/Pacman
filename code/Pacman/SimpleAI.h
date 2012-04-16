#pragma once
#include "AI.h"

class SimpleAI :
	public AI
{
private:
	char decideMovement(Tile *currentTile);
public:
	SimpleAI();
	~SimpleAI();
};