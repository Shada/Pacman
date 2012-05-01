#include "SmartAI.h"


SmartAI::SmartAI(vector<Tile*> *tiles, Tile *spawn)
	:AI(tiles, spawn)
{
}

Direction SmartAI::decideMovement()
{
	return D_SIZE;
}

SmartAI::~SmartAI()
{
}