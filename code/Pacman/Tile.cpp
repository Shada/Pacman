#include "Tile.h"

Tile::Tile(D3DXVECTOR3 pos, D3DXVECTOR2 dim)
{
	position = pos;
	dimensions = dim;
	neighbouringTiles = vector<Tile*>();
	visited = false;
}

Tile *Tile::checkDirection(Direction direction)
{
	return neighbouringTiles.at(direction);
}

void Tile::setNeighbours(vector<Tile*> neighbours)
{
	neighbouringTiles = neighbours;
}

Tile::~Tile()
{
}