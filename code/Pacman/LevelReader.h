#pragma once
#include "YellowPill.h"
#include "BluePill.h"
#include "Model.h"

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

	Model *m;
	vector<Ghost*> ghosts;

	void createTiles();
	void mapTiles(int x, int y, int tileIndex);
	void placePillsAndGhosts();

	AI *chooseAIType(Pixel data);
public:
	LevelReader();
	~LevelReader();

	vector<Ghost*> getGhosts() { return ghosts; }

	vector<Tile*> readFile(char* filename, const int _width, const int _height);
};