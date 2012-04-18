#pragma once
#include "ObjReader.h"
#include "GameObject.h"
#include "LevelReader.h"
#include "Floor.h"

class Map
{
private:
	vector<GameObject*> objects;
	vector<Tile*> tiles;

	LevelReader *lreader;
	ObjReader *objReader;
	Model *wall;
	Floor *floor;

	void generateWalls();
	void generatePills();
	void placeWall(int indexTile, int indexNeighbour);

public:
	Map();
	~Map();

	void draw();
};