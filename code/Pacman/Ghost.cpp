#include "Ghost.h"

Ghost::Ghost(AI *aiType, Tile *t, ID3D10EffectTechnique *tech, Model *model)
	: GameObject(t, tech, model)
{
	ai = aiType;
	speed = 5;
	dead = false;

	mWorld._11 = mWorld._22 = mWorld._33 = 0.2f;
}

void Ghost::live()
{
	dead = false;
}
void Ghost::move(double dt, Tile *currentTile)
{
	directionVec = currentTile->getPos() - position;
	D3DXVec3Normalize(&directionVec, &directionVec);

	float length = D3DXVec3Length(&(position - currentTile->getPos()));
	if(length < speed)
		position = currentTile->getPos();
	else
	{
		position.x += directionVec.x * speed;
		position.y += directionVec.y * speed;
		position.z += directionVec.z * speed;
	}
}
void Ghost::update(double dt)
{
	//if we've reached the next tile, let's move on.
	if(position == currentTile->getPos())
	{
		Tile *nextTile = currentTile->checkDirection(ai->decideMovement(position));

		if(nextTile != NULL)
			currentTile = nextTile;
	}
	move(dt, currentTile);
	// go towards current tile.
	// when tilepos - pos < epsilon
	// set pos to tilepos
	// check new direction ( checkDirection() )
}

void Ghost::draw()
{
	GameObject::draw();
}

Ghost::~Ghost()
{
} 