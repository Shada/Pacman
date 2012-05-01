#pragma once
#include "Route.h"
#include "Collision.h"

enum State { S_REGULAR, S_FLEE, S_DEAD };
class AI
{
protected:
	State state;
	vector<Tile*> handledTiles;
	list<Direction> route;
	vector<Tile*> *tiles;
	Tile* spawn;
	Tile* destination;
	//when it sees a player and he is invinsible. Will find a tile far away from tha player and 
	//begin running towards it.

	//calulates closest path to the tile sent in using dijksksstras algorithm
	bool calcRoute(Tile *startTile, Tile *endTile);

	//follow that route
	void followRoute();

	void checkAllDirs();
	/*recursive function calculating the route by checking a tile,
	  asking it's neighbour tiles to do the same, and return the cost when it's found
	  (returns int_max is failed).*/
	int tryAllDirs(Tile *tile, Tile *endTile, int cost);

	//find the tile closest to selected position
	Tile* getTileClosestAt(D3DXVECTOR3 pos);
public:
	AI(vector<Tile*> *tiles, Tile *spawn);
	~AI();

	virtual Direction decideMovement(D3DXVECTOR3 position);
	virtual void regular(D3DXVECTOR3 position);
	virtual void flee(D3DXVECTOR3 position);
	virtual void dead(D3DXVECTOR3 position);
};