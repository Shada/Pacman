#pragma once
#include "KeyListener.h"
#include "stdafx.h"
#include "Tile.h"

class GameObject : KeyListener
{
protected:
	Tile *currentTile;

	D3DXVECTOR3 *position;

	ID3D10Buffer *vB;
public:
	GameObject(Tile *t);
	~GameObject();
};