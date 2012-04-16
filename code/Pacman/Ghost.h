#pragma once
#include "gameobject.h"
#include "Tile.h"
class Ghost :
	public GameObject
{
private:

	//if the ghost is killed by the player while he is invinsible the ghost will turn into even more a ghost
	//and start going towards the spawn, this is the flag that will be used for that
	bool dead;

	//when it sees a player and he is invinsible. Will find a tile far away from tha player and 
	//begin running towards it.
	void flee();

	//calulates closest path to the tile sent in using dijksksstras algorithm
	void calcRoute(Tile* tile);

	//follow that route
	void followRoute();

	//resurect, used when a dead ghost reaches the spawn
	void live();

	//the ghost turns around and looks for the player in all directions
	void checkAllDirections();

	//determines how the ghost will behave 
	//AI* ai; (not implemented yet)
public:
	Ghost();
	~Ghost();

	void draw();
	void update(float dt);
};