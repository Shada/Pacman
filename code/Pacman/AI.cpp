#include "AI.h"


AI::AI(vector<Tile*> *tiles, Tile *spawn)
{
	state = S_REGULAR;
	this->tiles = tiles;
	this->spawn = spawn;
}

Direction AI::decideMovement(D3DXVECTOR3 position)
{
	switch(state)
	{
	case S_REGULAR:
		{
			regular(position);
			break;
		}
	case S_DEAD:
		{
			dead(position);
			break;
		}
	case S_FLEE:
		{
			flee(position);
			break;
		}
	}
	
	if(getTileClosestAt(position) == destination || !destination)
	{
		for(int i = 0; i < 1000000; i++)
		{
			destination = tiles->at( rand()%tiles->size() );
			if(calcRoute(getTileClosestAt(position),destination))
				break;
		}
	}
	if(!route.empty())
	{
		Direction dir = route.front();
		route.pop_front();
		return dir;
	}
	return D_SIZE;
}

void AI::regular(D3DXVECTOR3 position)
{
}

void AI::flee(D3DXVECTOR3 position)
{
}

void AI::dead(D3DXVECTOR3 position)
{
}

bool AI::calcRoute(Tile *startTile, Tile *endTile)
{
	//calculate costs and find shortest path
	int cost = tryAllDirs(startTile, endTile, 0);
	if(cost != INT_MAX)
	{
		route.clear();
		Tile* currentTile = startTile;
		//build list of directions as route
		while(true)
		{
			currentTile = currentTile->checkDirection(currentTile->shortestDir);
			if(currentTile != endTile)
				route.push_back(currentTile->shortestDir);
			else
				return true;
		}
		return true;
	}
	return false;
}

Tile* AI::getTileClosestAt(D3DXVECTOR3 pos)
{
	float distance = FLT_MAX;
	float tempDist;
	Tile* closestTile = NULL;
	for(unsigned int i = 0; i < tiles->size(); i++)
	{
		tempDist = D3DXVec3Length(&(tiles->at(i)->getPos() - pos));
		if(tempDist < distance)
		{
			distance = tempDist;
			closestTile = tiles->at(i);
		}
	}
	return closestTile;
}

void AI::checkAllDirs()
{

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