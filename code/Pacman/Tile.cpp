#include "Tile.h"


Tile::Tile(vector<Tile*> neighbours, D3DXVECTOR3 pos, D3DXVECTOR2 dim)
{
	position = pos;
	dimensions = dim;
	neighbouringTiles = neighbours;
}
Tile::Tile(D3DXVECTOR3 pos, D3DXVECTOR2 dim)
{
	position = pos;
	dimensions = dim;
	neighbouringTiles = vector<Tile*>();
}
bool Tile::checkDirection(char direction)
{
	switch(direction)
	{
		case 'n':
			if(neighbouringTiles.at(0))
				return true;
			break;
		case 's':
			if(neighbouringTiles.at(1))
				return true;
			break;
		case 'e':
			if(neighbouringTiles.at(2))
				return true;
			break;
		case 'w':
			if(neighbouringTiles.at(3))
				return true;
			break;
	}
	return false;
}

Tile::~Tile()
{
}