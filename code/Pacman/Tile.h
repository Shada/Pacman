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
	int cost;
	Direction shortestDir;

	void setNeighbours(vector<Tile*> neighbours);

	D3DXVECTOR3 getPos() { return position; }
	D3DXVECTOR2 getDim() { return dimensions; }

	// returns the tile you want to go to, if the direction is valid
	Tile *checkDirection(Direction direction);
};