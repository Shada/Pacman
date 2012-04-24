#include "Map.h"

Map::Map()
{
	lreader = new LevelReader();

	objReader = new ObjReader();

	tiles = lreader->readFile("map.raw", 60, 60);
	ghosts = lreader->getGhosts();

	generateWalls();

	floor = new Floor(new D3DXVECTOR3(0, 10, 0), D3DXVECTOR2(600, 600));
	wall = new Model("wall");

	//objReader->readData("wall.obj", wall);
}

void Map::draw()
{
	floor->draw();
}

void Map::generateWalls()
{
	for(unsigned int i = 0; i < tiles.size(); i++)
		for(int j = 0; j < 4; j++)
			if(tiles.at(i)->checkDirection((Direction)j) == NULL)
				placeWall(i, j);
}

void Map::placeWall(int indexTile, int indexNeighbour)
{
	double rotation;
	D3DXVECTOR3 tempPos;
	D3DXVECTOR3 pos = tiles.at(indexTile)->getPos();
	D3DXVECTOR2 dim = tiles.at(indexTile)->getDim();
	
	if(indexNeighbour == 0 || indexNeighbour == 1)
	{
		rotation = indexNeighbour == 0.f ? 0 : D3DX_PI;

		pos.z = indexNeighbour == 0 ? pos.z + dim.y * 0.4f : pos.z - dim.y * 0.4f;
		tempPos = D3DXVECTOR3(pos.x, pos.y, pos.z);
	}
	else
	{
		rotation = indexNeighbour == 2 ? D3DX_PI * 0.5 : D3DX_PI * 1.5;

		pos.x = indexNeighbour == 2 ? pos.x + dim.x * 0.4f : pos.x - dim.x * 0.4f;
		tempPos = D3DXVECTOR3(pos.x, pos.y, pos.z);
	}

	objects.push_back(new GameObject(tiles.at(indexTile), NULL, wall, tempPos));
}

Map::~Map()
{
	unsigned int i;
	for(i = 0; i < tiles.size(); i++)
		SAFE_DELETE( tiles.at(i) );
	for(i = 0; i < objects.size(); i++)
		SAFE_DELETE( objects.at(i) );
	for(i = 0; i < ghosts.size(); i++)
		SAFE_DELETE( ghosts.at(i) );

	SAFE_DELETE( objReader );
	SAFE_DELETE( lreader );
	SAFE_DELETE( floor );
	SAFE_DELETE( wall );
}