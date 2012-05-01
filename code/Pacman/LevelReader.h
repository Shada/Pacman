#pragma once
#include "Pill.h"
#include "Model.h"
#include "ObjReader.h"

#include "InstanceManager.h"
#include "Ghost.h"
#include "AverageAI.h"
#include "SmartAI.h"
#include "SimpleAI.h"

struct Pixel
{
	BYTE r, g, b;

	bool operator!=(Pixel x)
	{
		return (x.r != r || x.g != g || x.b != b);
	}
	bool operator==(Pixel x)
	{
		return (x.r == r && x.g == g && x.b == b);
	}
};

class LevelReader
{
private:
	Pixel black, yellow, blue, green, white;

	vector<Tile*> tiles;
	vector<Ghost*> ghosts;
	vector<vector<Pixel>> pixelData;

	int height, width, nTilesX, nTilesY;

	Model *corner, *wall, *pill, *ghost;
	ObjReader *reader;

	InstanceManager *iWalls, *iCorners, *iPills;

	void createTiles();
	void mapTiles(int x, int y, int tileIndex);
	
	void generateWalls();
	void placeWall(int indexTile, int indexNeighbour);
	
	void placePillsAndGhosts();
	void placeCornerWalls();
	
	AI *chooseAIType(Pixel data, Tile *t);

public:
	LevelReader();
	~LevelReader();

	
	vector<Ghost*>		getGhosts()			{ return ghosts; }
	InstanceManager		*getCornerWalls()	{ return iCorners; }
	InstanceManager		*getWalls()			{ return iWalls; }
	InstanceManager		*getPills()			{ return iPills; }

	vector<Tile*> readFile(char* filename, const int _width, const int _height);
};