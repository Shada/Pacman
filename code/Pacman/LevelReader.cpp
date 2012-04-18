#include "LevelReader.h"


LevelReader::LevelReader()
{
	black.r = black.g = black.b = 0;
	yellow.r = 255; yellow.g = 210; yellow.b = 0;
	blue.r = blue.g = 0; blue.b = 255;
	green.r = green.b = 0; green.g = 255;
}

vector<Tile*> LevelReader::readFile(char* filename, const int _width, const int _height)
{
	height = _height;
	width = _width;

	pixelData.resize(width);
	for (int i = 0; i < width; ++i)
		pixelData[i].resize(height);

	ifstream file;
	file.open(filename, ios::binary);

	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			file >> pixelData[j][i].r;
			file >> pixelData[j][i].g;
			file >> pixelData[j][i].b;
		}
	}
	file.close();

	createTiles();

	return tiles;
}

void LevelReader::createTiles()
{
	D3DXVECTOR2 dim(10, 10);
	D3DXVECTOR3 pos(5, 0, 5);

	for(int i = 1; i < width - 1; i += 3)
		for(int j = 1; j < height - 1; j += 3)
			tiles.push_back(new Tile(D3DXVECTOR3(	pos.x + dim.x * (j - 1) / 3, 
													pos.y, 
													pos.z + dim.y * (i - 1) / 3), dim));
	
	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		int x, y;
		x = i % (width / 3);
		y = (int)(i / (width / 3));
		mapTiles(x, y, i);
	}
}

void LevelReader::mapTiles(int x, int y, int tileIndex)
{
	vector<Tile*> neighbours(4);

	int px, py;
	px = x * 3 + 1;
	py = y * 3 + 1;

	int nTilesX = width / 3;
	int nTilesY = height / 3;

	if(pixelData[px][py - 1] != black)	
		neighbours.at(0) = tiles.at(y - 1 < 0 ? width - tileIndex - 1 : tileIndex - nTilesX);

	if(pixelData[px][py + 1] != black)
		neighbours.at(1) = tiles.at(y + 1 >= nTilesY ? width - tileIndex - 1 : tileIndex + nTilesX);

	if(pixelData[px + 1][py] != black)
		neighbours.at(2) = tiles.at(x + 1 >= nTilesX ? tileIndex - nTilesX + 1 : tileIndex + 1);

	if(pixelData[px - 1][py] != black)
		neighbours.at(3) = tiles.at(x - 1 < 0 ? tileIndex + nTilesX - 1 : tileIndex - 1);

	tiles.at(tileIndex)->setNeighbours(neighbours);
}

LevelReader::~LevelReader()
{
}