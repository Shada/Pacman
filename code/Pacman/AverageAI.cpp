#include "AverageAI.h"


AverageAI::AverageAI(vector<Tile*> *tiles, Tile *spawn)
	:AI(tiles, spawn)
{
}

Direction AverageAI::decideMovement(Tile *currentTile)
{
	return D_SIZE;
}

AverageAI::~AverageAI()
{
}