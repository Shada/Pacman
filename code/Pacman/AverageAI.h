#pragma once
#include "AI.h"

class AverageAI :
	public AI
{
public:
	AverageAI();
	~AverageAI();

	char decideMovement(Tile *currentTile);
};