#include "SimpleAI.h"


SimpleAI::SimpleAI(vector<Tile*> *tiles, Tile *spawn)
	:AI(tiles, spawn)
{
}

void SimpleAI::regular(D3DXVECTOR3 position)
{
	D3DXVECTOR3 targetPos;
	if(Collision::getInstance()->lookForPlayers(targetPos, position))
	{
		destination = getTileClosestAt(targetPos);
	}
}
void SimpleAI::flee(D3DXVECTOR3 position)
{
	
}
void SimpleAI::dead(D3DXVECTOR3 position)
{
	//I'm invisible with goofy eyes
	destination = spawn;
}
SimpleAI::~SimpleAI()
{
}