#pragma once
#include "Tile.h"

class AI
{
protected:
	//when it sees a player and he is invinsible. Will find a tile far away from tha player and 
	//begin running towards it.
	void flee();

	//calulates closest path to the tile sent in using dijksksstras algorithm
	void calcRoute(Tile* tile);

	//follow that route
	void followRoute();

	//the ghost turns around and looks for the player in all directions
	void checkAllDirections();
public:
	AI();
	~AI();

	virtual char decideMovement(Tile *currentTile);
};