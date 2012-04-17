#include "AverageAI.h"


AverageAI::AverageAI(int tileAmount)
	:AI(tileAmount)
{
}

Direction AverageAI::decideMovement(Tile *currentTile)
{
	return Direction::size;
}

AverageAI::~AverageAI()
{
}