#pragma once
#include "Map.h"
#include "GraphicsManager.h"
#include "GameMenu.h"
#include "KeyManager.h"
class Game
{
private:
	Map map;
	GameMenu* menu;
	KeyManager* keyManager;
	static Game *instance;
	
	//these two takes the menu and first clears the buttons and then
	//sets the buttons asociated with either Main menu or ingame menu.
	void createMainMenu();
	void createIngameMenu();

	Game();
public:
	~Game();
	static Game *getInstance();

	void update(double time);
	void draw(double time);
};