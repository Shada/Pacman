#include "SimpleAI.h"


SimpleAI::SimpleAI(int tileAmount)
	:AI(tileAmount)
{
}

Direction SimpleAI::decideMovement(Tile *currentTile)
{
	return Direction::size;
}

SimpleAI::~SimpleAI()
{
}