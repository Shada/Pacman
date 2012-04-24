#pragma once
#include "Map.h"
#include "GraphicsManager.h"
#include "GameMenu.h"
#include "KeyManager.h"
#include "Camera.h"

/////////////////////////////////////
//for testing should not be in here//
/////////////////////////////////////
#include "EffectList.h"
#include "BlueEffect.h"
#include "YellowEffect.h"
/////////////////////////////////////
//           end testing           //
/////////////////////////////////////

class Game
{
private:
	Map *map;
	GameMenu* menu;
	KeyManager* keyManager;
	static Game *instance;
	Camera *cam;

	//these two takes the menu and first clears the buttons and then
	//sets the buttons asociated with either Main menu or ingame menu.
	void createMainMenu();
	void createIngameMenu();
	

	EffectList list;

	Game();
public:
	~Game();
	static Game *getInstance();

	void showLeaderboard();
	void newGame();
	void update(double time);
	void draw(double time);
};