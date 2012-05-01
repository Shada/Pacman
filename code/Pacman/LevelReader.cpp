#include "LevelReader.h"


LevelReader::LevelReader()
{
	black.r = black.g = black.b = 0;
	yellow.r = 255; yellow.g = 210; yellow.b = 0;
	blue.r = blue.g = 0; blue.b = 255;
	green.r = green.b = 0; green.g = 255;
	white.r = white.g = white.b = 255;

	iCorners = NULL;
	iWalls = NULL;
	iPills = NULL;

	corner = pill = wall = NULL;
	reader = new ObjReader();

	ghosts = vector<Ghost*>();
}

vector<Tile*> LevelReader::readFile(char* filename, const int _width, const int _height)
{
	height = _height;
	width = _width;

	nTilesX = width / 3;
	nTilesY = height / 3;

	tiles = vector<Tile*>();
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

	generateWalls();

	placeCornerWalls();

	placePillsAndGhosts();

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

	// if x + 1 or y + 1 is either less than 0 or greater than width/height, then the neightboring tile is on the
	// other side of the map, i.e exit the map to the right, reapper on the left

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

void LevelReader::generateWalls()
{
	wall = new Model("wall");
	reader->readData("Models/wall.obj", wall);
	iWalls = new InstanceManager( wall, 0 );

	for(unsigned int i = 0; i < tiles.size(); i++)
		for(int j = 0; j < 4; j++)
			if(tiles.at(i)->checkDirection((Direction)j) == NULL)
				placeWall(i, j);
		
	iWalls->mapBuffers();
}

void LevelReader::placeWall(int indexTile, int indexNeighbour)
{
	ID3D10EffectTechnique *tech = GraphicsManager::getInstance()->g_pTechRender;
	float rotation, pi;
	pi = (float)D3DX_PI;
	D3DXVECTOR3 pos = tiles.at(indexTile)->getPos();
	
	if(indexNeighbour == 0 || indexNeighbour == 1)
		rotation = indexNeighbour == 0.f ? 0 : pi;
	else
		rotation = indexNeighbour == 3 ? pi * 1.5f : pi * 0.5f;

	iWalls->addObject(new GameObject(tiles.at(indexTile), tech, wall, pos, rotation));
}

void LevelReader::placePillsAndGhosts()
{
	ID3D10EffectTechnique *tech = GraphicsManager::getInstance()->g_pTechRender;
	pill = new Model("pill");
	ghost = new Model("ghost");
	reader->readData("Models/pill.obj", pill);
	reader->readData("Models/ghost.obj", ghost);
	iPills = new InstanceManager(pill, 0.001f);

	for(unsigned int i = 0; i < tiles.size(); i++)
	{
		int x, y;
		x = i % (width / 3) * 3 + 1;
		y = (int)(i / (width / 3) * 3 + 1);

		D3DXVECTOR3 pos = tiles.at(i)->getPos();

		if(pixelData[x][y] == yellow)
		{
			tiles.at(i)->setPill(new Pill(tiles.at(i), tech, pill));
			iPills->addObject(tiles.at(i)->getPill());
		}
			
		else if(pixelData[x][y] == blue)
		{
			tiles.at(i)->setPill(new Pill(tiles.at(i), tech, pill));
			iPills->addObject(tiles.at(i)->getPill());
		}

		else if( pixelData[x][y].g == 255 && pixelData[x][y] != white )
			ghosts.push_back(new Ghost(chooseAIType(pixelData[x][y], tiles.at(i)), tiles.at(i), tech, ghost));
	}
	iPills->mapBuffers();
}

void LevelReader::placeCornerWalls()
{
	
	D3DXVECTOR3 startPos = tiles.front()->getPos();
	D3DXVECTOR2 dimensions = tiles.front()->getDim();
	
	corner = new Model("corner");
	reader->readData("Models/corner.obj", corner);

	iCorners = new InstanceManager(corner, 0);
	
	ID3D10EffectTechnique *tech = GraphicsManager::getInstance()->g_pTechRender;

	for(int i = 0; i < height / 3 + 1; i++)
		for(int j = 0; j < width / 3 + 1; j++)
			iCorners->addObject(new GameObject(NULL, tech, corner, 
								D3DXVECTOR3(startPos.x + dimensions.x * j, 
								startPos.y, startPos.z + dimensions.y * i), 0));
		
	iCorners->mapBuffers();
}

AI *LevelReader::chooseAIType(Pixel data, Tile *t)
{
	AI *ai;
	if(data.r == 0)
		ai = new SimpleAI(&tiles, t);
	else if (data.r == 1)
		ai = new AverageAI(&tiles, t);
	else if (data.r == 2)
		ai = new SmartAI(&tiles, t);
	 
	return ai;
}

LevelReader::~LevelReader()
{
	//these will have to be deleted in the map later.
	SAFE_DELETE( pill );
	SAFE_DELETE( corner );
	SAFE_DELETE( wall );
	SAFE_DELETE( reader );
}