#pragma once
#include "stdafx.h"

class Pill;
class Tile
{
private:
	D3DXVECTOR3 position;
	D3DXVECTOR2 dimensions;

	Pill *pill;

	vector<Tile*> neighbouringTiles;
public:
	Tile(D3DXVECTOR3 pos, D3DXVECTOR2 dim);
	~Tile();
	bool visited;
	int cost;
	Direction shortestDir;

	void setNeighbours(vector<Tile*> neighbours);
	void setPill(Pill *p) { pill = p; }

	Pill *getPill() { return pill; }
	D3DXVECTOR3 getPos() { return position; }
	D3DXVECTOR2 getDim() { return dimensions; }

	// returns the tile you want to go to, if the direction is valid
	Tile *checkDirection(Direction direction);
};