#include "AI.h"


AI::AI(unsigned int tileAmount)
{
	this->tileAmount = tileAmount;
	handledTiles = vector<Tile*>();
}

Direction AI::decideMovement(Tile *currentTile)
{
	return D_SIZE;
}

void AI::calcRoute(Tile *startTile, Tile *endTile)
{
	int cost = tryAllDirs(startTile, endTile, 0);
}

int AI::tryAllDirs(Tile *tile, Tile *endTile, int cost)
{
	//if the current tile is the end tile we've reached our goal.
	if(tile == endTile)
		return cost;
	bool allVisited = true;
	//for every direction
	for(int i = 0; i < D_SIZE; i++)
	{
		//if not null
		if(tile->checkDirection((Direction)i))
		{
			if(!tile->checkDirection((Direction)i)->visited)
			{
				tile->checkDirection((Direction)i)->cost = cost + 1;
				allVisited = false;
			}
		}
	}
	//if all are already visited we've reached a dead end.
	if(allVisited)
		return INT_MAX;

	//recursively call this function for all unvisited neighbor tiles.
	for(int i = 0; i < D_SIZE; i++)
	{
		if(tile->checkDirection((Direction)i))
		{
			//if tile is not visited and has higher cost than this.
			if(!tile->checkDirection((Direction)i)->visited && tile->checkDirection((Direction)i)->cost > cost + 1)
			{
				cost = tryAllDirs(tile->checkDirection((Direction)i),endTile,cost+1);
				tile->shortestDir = (Direction)i;
			}
		}
	}
	return cost;
}

AI::~AI()
{
}