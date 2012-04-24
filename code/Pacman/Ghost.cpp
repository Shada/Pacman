#include "Ghost.h"


Ghost::Ghost(AI *aiType, Tile *t)
	: GameObject(t, NULL, NULL)
{
	ai = aiType;
	dead = false;
}

void Ghost::live()
{
	dead = false;
}

void Ghost::update(float dt)
{
	Tile *temp = currentTile->checkDirection(ai->decideMovement(currentTile));

	if(temp)
		currentTile = temp;

	// go towards current tile.
	// when tilepos - pos < epsilon
	// set pos to tilepos
	// check new direction ( checkDirection() )
}

void Ghost::draw()
{

}

Ghost::~Ghost()
{
	SAFE_DELETE( ai );
}