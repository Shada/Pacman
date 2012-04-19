#include "Player.h"


Player::Player(Tile* t, D3DXVECTOR3 *pos, ID3D10EffectTechnique* tech, Model* m)
	: GameObject(t, pos, tech, m)
{
	currentDirection = Direction::D_NORTH;
	nextTile = currentTile;
}
void Player::handleKeyStrokes(int key)
{
	switch ( key )
	{
	case VK_RIGHT:
		{
			const Direction worldDir = getWorldDirection(Direction::D_EAST) ;
			if(currentTile->checkDirection( worldDir ))
			{
				nextTile = currentTile->checkDirection( worldDir );
			}
			break;
		}
	case VK_LEFT:
		{
			const Direction worldDir = getWorldDirection(Direction::D_WEST) ;
			if(currentTile->checkDirection( worldDir ))
			{
				nextTile = currentTile->checkDirection( worldDir );
			}
			break;
		}
	case VK_DOWN:
		{
			const Direction worldDir = getWorldDirection(Direction::D_SOUTH) ;
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
		case Direction::D_EAST:
			break;
	}
	Direction dir = Direction::D_NORTH;
	//means the player wants to turn right, in his own perspective so east is a bit missleading
	if( d == Direction::D_EAST )
		// since he wants to turn right increase direction if it
		// has not reached the max amount of direction if it has reset to
		// the first direction.
		if( currentDirection + 1 < Direction::D_SIZE )
			dir = (Direction)(currentDirection + 1);
		else
			dir = Direction::D_EAST;

	//means the player wants to turn left
	if( d == Direction::D_WEST )
		if( currentDirection - 1 > 0 )
			dir = (Direction)(currentDirection -1);
		else
			dir = Direction::D_WEST;

	if( d == Direction::D_NORTH ) 
		dir = currentDirection;

	// means the player wants to turn around, hence the returned direction should be
	// the opposite of the local currentdirection. This became a bit ugly and locked to
	// just 4 possible directions
	if( d == Direction::D_SOUTH )
		if ( currentDirection - 2 > 0 )
			dir = (Direction)(currentDirection -2);
		else if ( currentDirection -2 == -1 )
			dir = Direction::D_WEST;
		else if ( currentDirection -2 == -2)
			dir = Direction::D_SOUTH;

	return dir;
}
void Player::draw()
{
}
void Player::update(float dt)
{
}
Player::~Player()
{
}
