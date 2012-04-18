#include "SmartAI.h"


SmartAI::SmartAI(int tileAmount)
	:AI(tileAmount)
{
}

Direction SmartAI::decideMovement(Tile *currentTile)
{
	return D_SIZE;
}

SmartAI::~SmartAI()
{
}