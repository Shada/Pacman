#pragma once
#include "AI.h"

class SmartAI :
	public AI
{
public:
	SmartAI();
	~SmartAI();

	char decideMovement(Tile *currentTile);
};