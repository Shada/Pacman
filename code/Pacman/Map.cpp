#include "Map.h"

Map::Map()
{
	lreader = new LevelReader();

	objReader = new ObjReader();

	tiles = lreader->readFile("map.raw", 60, 60);
	ghosts = lreader->getGhosts();

	floor = new Floor(new D3DXVECTOR3(0, 0, 0), D3DXVECTOR2(200, 200));
	wall = new Model("wall");
	
	objReader->readData("Models/wall.obj", wall);
	
	objects = lreader->getCornerWalls();

	generateWalls();
}

void Map::draw()
{
	for(unsigned int i = 0; i < objects.size(); i++)
		objects.at(i)->draw();
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
	ID3D10EffectTechnique *tech = GraphicsManager::getInstance()->g_pTechRender;
	float rotation, pi;
	pi = (float)D3DX_PI;
	D3DXVECTOR3 pos = tiles.at(indexTile)->getPos();
	
	if(indexNeighbour == 0 || indexNeighbour == 1)
		rotation = indexNeighbour == 0.f ? 0 : pi;
	else
		rotation = indexNeighbour == 2 ? pi * 1.5f : pi * 0.5f;

	objects.push_back(new GameObject(tiles.at(indexTile), tech, wall, pos, rotation));
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