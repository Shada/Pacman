#pragma once
#include "Map.h"
#include "GraphicsManager.h"
class Game
{
private:
	Map map;
	static Game *instance;
	
	Game();
public:
	~Game();
	static Game *getInstance();

	void update(double time);
	void draw(double time);
};