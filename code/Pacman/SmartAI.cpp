#include "SmartAI.h"


SmartAI::SmartAI(int tileAmount)
	:AI(tileAmount)
{
}

Direction SmartAI::decideMovement(Tile *currentTile)
{
	return Direction::size;
}

SmartAI::~SmartAI()
{
}