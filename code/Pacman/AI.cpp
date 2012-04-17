#include "AI.h"


AI::AI(unsigned int tileAmount)
{
	this->tileAmount = tileAmount;
}

Direction AI::decideMovement(Tile *currentTile)
{
	return Direction::size;
}

void AI::calcRoute(Tile *startTile, Tile *endTile)
{
	list<Route> *routes;
	tryAllDirs(startTile, endTile, 0);
}

//requires optimization (faster "handled nodes" check)
int AI::tryAllDirs(Tile *tile, Tile *endTile, int cost)
{
	int costReturn = INT_MAX;
	handledTiles.push_back(tile);
	if(tile == endTile)
		return cost;
	//for every direction
	for(int i = 0; i < Direction::size; i++)
	{
		//if not null
		if(tile->checkDirection((Direction)i))
		{
			bool found = false;
			//and not visited
			for(unsigned int k = 0; k < handledTiles.size(); k++)
				if(handledTiles.at(k) == tile->checkDirection((Direction)i))
					found = true;
			//repeat for next tile
			costReturn = tryAllDirs(tile->checkDirection((Direction)i),endTile, ++cost);
		}
	}
	return 0;
}

AI::~AI()
{
}