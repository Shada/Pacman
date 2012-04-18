#pragma once
#include "Route.h"

class AI
{
protected:
	unsigned int tileAmount;
	vector<Tile*> handledTiles;
	//when it sees a player and he is invinsible. Will find a tile far away from tha player and 
	//begin running towards it.
	void flee();

	//calulates closest path to the tile sent in using dijksksstras algorithm
	void calcRoute(Tile *startTile, Tile *endTile);

	//follow that route
	void followRoute();
	int tryAllDirs(Tile *tile, Tile *endTile, int cost);
	//the ghost turns around and looks for the player in all directions
	void checkAllDirections();
public:
	AI(unsigned int tileAmount);
	~AI();

	virtual Direction decideMovement(Tile *currentTile);
};