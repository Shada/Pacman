#pragma once
#include "KeyListener.h"
#include "stdafx.h"
#include "Tiles.h"
class GameObject : KeyListener
{
private:
	Tiles* currentTile;
	D3DXVECTOR3* pos;
	ID3D10Buffer* vB;
public:
	GameObject();
	~GameObject();
};

