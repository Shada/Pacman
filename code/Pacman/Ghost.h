#pragma once
#include "gameobject.h"
#include "Tile.h"
#include "AI.h"

class Ghost :
	public GameObject
{
private:

	//if the ghost is killed by the player while he is invinsible the ghost will turn into even more a ghost
	//and start going towards the spawn, this is the flag that will be used for that
	bool dead;

	//resurect, used when a dead ghost reaches the spawn
	void live();

	//determines how the ghost will behave 
	AI* ai;
public:
	Ghost(AI *aiType, Tile *t);
	~Ghost();

	void draw();
	void update(float dt);
};