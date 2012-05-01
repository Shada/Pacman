#pragma once
#include "GameObject.h"
#include "Tile.h"
#include "AI.h"

class Ghost :
	public GameObject
{
private:
	//if the ghost is killed by the player while he is invinsible the ghost will turn into even more a ghost
	//and start going towards the spawn, this is the flag that will be used for that
	bool dead;
	float speed;
	D3DXVECTOR3 directionVec;
	//resurect, used when a dead ghost reaches the spawn
	void live();
	void move(double dt, Tile *currentTile);

	//determines how the ghost will behave 
	AI* ai;
public:
	Ghost(AI *aiType, Tile *t, ID3D10EffectTechnique *tech, Model *model);
	~Ghost();

	void draw();
	void update(double dt);
};