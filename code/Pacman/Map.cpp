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

	iWalls = lreader->getWalls();

	iPills = lreader->getPills();

	iCorners = lreader->getCornerWalls();
}

void Map::draw()
{
	iPills->update(79856);

	iWalls->draw();
	iCorners->draw();
	iPills->draw();
	
	floor->draw();
}

Map::~Map()
{
	unsigned int i;
	for(i = 0; i < tiles.size(); i++)
		SAFE_DELETE( tiles.at(i) );
	for(i = 0; i < ghosts.size(); i++)
		SAFE_DELETE( ghosts.at(i) );

	SAFE_DELETE( objReader );
	SAFE_DELETE( lreader );
	SAFE_DELETE( floor );
	SAFE_DELETE( wall );
	SAFE_DELETE( iWalls );
	SAFE_DELETE( iCorners );
}