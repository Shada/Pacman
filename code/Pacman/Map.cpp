#include "Map.h"



Map::Map()
{
	D3DXVECTOR2 dim(10,10);
	int width = 20, height = 20;
	for(int y = 0; y < height-1; y++)
	{
		for(int x = 0; x < width-1; x++)
		{
			tiles.push_back(new Tile(D3DXVECTOR3(x * dim.x, y * dim.y, -10),dim));
		}
	}

	objReader = new ObjReader();


	floor = new Model("plane");
}
void Map::draw()
{
	
}
Map::~Map()
{
	for(unsigned int i = 0; i < tiles.size(); i++)
		SAFE_DELETE(tiles.at(i));
	SAFE_DELETE(floor);

	SAFE_DELETE(objReader);
	//for(unsigned int i = 0; i < objects.size(); i++)
		//SAFE_DELETE( objects.at(i) );
}