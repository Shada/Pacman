#pragma once
#include "AI.h"

class SmartAI :
	public AI
{
public:
	SmartAI(vector<Tile*> *tiles, Tile *spawn);
	~SmartAI();

	Direction decideMovement();
};