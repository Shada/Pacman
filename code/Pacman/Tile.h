#pragma once
#include "stdafx.h"

class Tile
{
private:
	D3DXVECTOR3 position;
	D3DXVECTOR2 dimensions;

	vector<Tile*> neighbouringTiles;
public:
	Tile(D3DXVECTOR3 pos, D3DXVECTOR2 dim);
	~Tile();
	bool visited;

	void setNeighbours(vector<Tile*> neighbours);

	// returns the tile you want to go to, if the direction is valid
	Tile *checkDirection(Direction direction);
};