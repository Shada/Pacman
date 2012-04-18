#pragma once

#include "ObjReader.h"
#include "GameObject.h"
#include "LevelReader.h"

class Map
{
private:
	vector<GameObject*> objects;
	vector<Tile*> tiles;
	ObjReader *objReader;
	Model *floor;

public:
	Map();
	void draw();
	~Map();
};