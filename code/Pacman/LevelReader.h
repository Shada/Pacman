#pragma once
#include "YellowPill.h"
#include "BluePill.h"
#include "Model.h"
#include "ObjReader.h"

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
	vector<vector<Pixel>> pixelData;
	vector<Tile*> tiles;

	int height, width, nTilesX, nTilesY;

	Model *m, *corner;
	ObjReader *reader;
	vector<Ghost*> ghosts;
	vector<GameObject*> objects;

	void createTiles();
	void mapTiles(int x, int y, int tileIndex);
	void placePillsAndGhosts();
	void placeCornerWalls();

	AI *chooseAIType(Pixel data);
public:
	LevelReader();
	~LevelReader();

	vector<Ghost*>		getGhosts()			{ return ghosts; }
	vector<GameObject*> getCornerWalls()	{ return objects; }

	vector<Tile*> readFile(char* filename, const int _width, const int _height);
};