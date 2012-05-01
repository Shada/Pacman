#pragma once
#include "ObjReader.h"
#include "GameObject.h"
#include "LevelReader.h"
#include "Floor.h"
#include "Ghost.h"
#include "InstanceManager.h"

class Map
{
private:
	vector<GameObject*> walls;
	vector<Tile*> tiles;

	LevelReader *lreader;
	ObjReader *objReader;
	Model *wall, *corner;
	Floor *floor;
	vector<Ghost*> ghosts;

	ID3D10Buffer* instanceBuffer;

	InstanceManager *iWalls, *iCorners, *iPills;

public:
	Map();
	~Map();

	void draw();
};