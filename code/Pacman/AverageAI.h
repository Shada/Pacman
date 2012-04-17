#pragma once
#include "AI.h"

class AverageAI :
	public AI
{
public:
	AverageAI(int tileAmount);
	~AverageAI();

	Direction decideMovement(Tile *currentTile);
};