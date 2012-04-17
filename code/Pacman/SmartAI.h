#pragma once
#include "AI.h"

class SmartAI :
	public AI
{
public:
	SmartAI(int tileAmount);
	~SmartAI();

	Direction decideMovement(Tile *currentTile);
};