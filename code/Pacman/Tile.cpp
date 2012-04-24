#include "Tile.h"
#include "Pill.h"

Tile::Tile(D3DXVECTOR3 pos, D3DXVECTOR2 dim)
{
	position = pos;
	dimensions = dim;
	neighbouringTiles = vector<Tile*>();
	visited = false;

	pill = NULL;
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
	SAFE_DELETE( pill );
}