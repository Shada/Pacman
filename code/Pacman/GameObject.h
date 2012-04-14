#pragma once
#include "KeyListener.h"
#include "stdafx.h"
#include "Tile.h"
class GameObject : KeyListener
{
private:
	Tile* currentTile;
	D3DXVECTOR3* pos;
	ID3D10Buffer* vB;
public:
	GameObject();
	~GameObject();
};

