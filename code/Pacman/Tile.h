#pragma once
#include "stdafx.h"

class Tile
{
private:
	D3DXVECTOR3 position;
	D3DXVECTOR2 dimensions;
	vector<Tile*> neighbouringTiles;
public:
	Tile(vector<Tile*> neighbours, D3DXVECTOR3 pos, D3DXVECTOR2 dim);
	Tile(D3DXVECTOR3 pos, D3DXVECTOR2 dim);
	~Tile();

	bool checkDirection(char direction);
};