#include "Player.h"


Player::Player(Tile* t, ID3D10EffectTechnique* tech, Model* m)
	: GameObject(t, tech, m)
{
	currentDirection = D_NORTH;
	nextTile = currentTile;
}

void Player::handleKeyStrokes(int key)
{
	switch ( key )
	{
	case VK_RIGHT:
		{
			const Direction worldDir = getWorldDirection(D_EAST) ;
			if(currentTile->checkDirection( worldDir ))
			{
				nextTile = currentTile->checkDirection( worldDir );
			}
			break;
		}
	case VK_LEFT:
		{
			const Direction worldDir = getWorldDirection(D_WEST) ;
			if(currentTile->checkDirection( worldDir ))
			{
				nextTile = currentTile->checkDirection( worldDir );
			}
			break;
		}
	case VK_DOWN:
		{
			const Direction worldDir = getWorldDirection(D_SOUTH) ;
			if(currentTile->checkDirection( worldDir ))
			{
				nextTile = currentTile->checkDirection( worldDir );
			}
			break;
		}
	}
}

const Direction Player::getWorldDirection(const Direction d)
{
	switch ( d )
	{
		case D_EAST:
			break;
	}
	Direction dir = D_NORTH;
	//means the player wants to turn right, in his own perspective so east is a bit missleading
	if( d == D_EAST )
		// since he wants to turn right increase direction if it
		// has not reached the max amount of direction if it has reset to
		// the first direction.
		if( currentDirection + 1 < D_SIZE )
			dir = (Direction)(currentDirection + 1);
		else
			dir = D_EAST;

	//means the player wants to turn left
	if( d == D_WEST )
		if( currentDirection - 1 > 0 )
			dir = (Direction)(currentDirection -1);
		else
			dir = D_WEST;

	if( d == D_NORTH ) 
		dir = currentDirection;

	// means the player wants to turn around, hence the returned direction should be
	// the opposite of the local currentdirection. This became a bit ugly and locked to
	// just 4 possible directions
	if( d == D_SOUTH )
		if ( currentDirection - 2 > 0 )
			dir = (Direction)(currentDirection -2);
		else if ( currentDirection -2 == -1 )
			dir = D_WEST;
		else if ( currentDirection -2 == -2)
			dir = D_SOUTH;

	return dir;
}

void Player::draw()
{
}

void Player::update(double dt)
{
}

Player::~Player()
{
}