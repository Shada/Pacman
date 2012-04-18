#include "SimpleAI.h"


SimpleAI::SimpleAI(int tileAmount)
	:AI(tileAmount)
{
}

Direction SimpleAI::decideMovement(Tile *currentTile)
{
	return D_SIZE;
}

SimpleAI::~SimpleAI()
{
}