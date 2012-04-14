#pragma once
#include "Tile.h"
#include "stdafx.h"
#include "ObjReader.h"
//#include "GameObject"

class Map
{
private:
	//vector<GameObject*> objects;
	vector<Tile*> tiles;
	ObjReader *objReader;
	Model *floor;

public:
	Map();
	void draw();
	~Map();
};