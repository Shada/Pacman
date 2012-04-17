#pragma once
#include "stdafx.h"
#include "Tile.h"

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
	Pixel black;
	vector<vector<Pixel>> pixelData;
	vector<Tile*> tiles;

	int height, width;

	void createTiles();
	void mapTiles(int px, int py, int tileIndex);
public:
	LevelReader();
	~LevelReader();

	vector<Tile*> readFile(char* filename, const int _width, const int _height);
};