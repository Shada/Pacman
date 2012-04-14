#include "Game.h"

Game *Game::instance = NULL;
Game::Game()
{
	menu = NULL;
	createMainMenu();

	keyManager = new KeyManager();
	keyManager->attach((KeyListener*)menu);
}

Game *Game::getInstance()
{
	if(!instance)
		instance = new Game();
	
	return instance;
}

void Game::update(double time)
{
	keyManager->update(time);
}

void Game::draw(double time)
{
	menu->draw();
}
void Game::createMainMenu()
{
	if(!menu)
		menu = new GameMenu();
	else
		menu->clearButtons();

	//menu->addButton([]{ newGame(); },D3DXVECTOR2(50,240), "new game");
	menu->addButton([]{ ; }, D3DXVECTOR2(50,140), "leaderboard");
	menu->addButton([]{ PostQuitMessage(0); }, D3DXVECTOR2(50,40), "exit");
	
	menu->setFirstSelected();
}
void Game::createIngameMenu()
{
	if(!menu)
		menu = new GameMenu();
	else
		menu->clearButtons();
}
Game::~Game()
{
	SAFE_DELETE(menu);
	SAFE_DELETE(keyManager);
}