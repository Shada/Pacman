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

Tile *Tile::checkDirection(char direction)
{
	switch(direction)
	{
		case 'n':
			return neighbouringTiles.at(0);
			break;
		case 's':
			return neighbouringTiles.at(1);
			break;
		case 'e':
			return neighbouringTiles.at(2);
			break;
		case 'w':
			return neighbouringTiles.at(3);
			break;
	}
	return NULL;
}

Tile::~Tile()
{
}