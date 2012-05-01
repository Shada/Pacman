#pragma once
#include "AI.h"

class AverageAI :
	public AI
{
public:
	AverageAI(vector<Tile*> *tiles, Tile *spawn);
	~AverageAI();

	Direction decideMovement(Tile *currentTile);
};