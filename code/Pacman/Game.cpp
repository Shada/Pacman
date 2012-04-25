#include "Game.h"


Game *Game::instance = NULL;
Game::Game()
{
	menu = NULL;
	createMainMenu();

	cam = new Camera();

	keyManager = new KeyManager();
	keyManager->attach((KeyListener*)menu);

	list.addEffect(new YellowEffect());
	list.addEffect(new BlueEffect());
	map = NULL;

	fpsUpdate = fps = 0;

	GraphicsManager::getInstance()->createFont(&font, 16, "Verdana");
}

Game *Game::getInstance()
{
	if(!instance)
		instance = new Game();
	
	return instance;
}

void Game::update(double time)
{
	fpsUpdate += time;
	if(fpsUpdate >= 1)
	{
		fps = (int)(1.0 / time + 0.5);
		fpsUpdate = 0;
	}

	keyManager->update(time);
	cam->update(D3DXVECTOR3(0, 0, 0),time);
	GraphicsManager::getInstance()->useViewAndProjection(cam->getViewMatrix(), cam->getProjMatrix());


	list.update(time);
}

void Game::draw(double time)
{
	//menu->draw();
	if (map)
		map->draw();

	RECT t;
	t.top = 100;
	t.bottom = 150;
	t.left = 100;
	t.right = 200;

	char buf[5];
	sprintf_s(buf, "%d", fps);
	string text = "FPS: " + (string)buf;

	font->DrawTextA(NULL, text.c_str(), -1, &t, DT_LEFT | DT_CENTER , D3DXCOLOR(1, 1, 1, 1.0f));
	GraphicsManager::getInstance()->resetBlendState();
}

void Game::newGame()
{
	map = new Map();
}

void Game::showLeaderboard()
{

}

void Game::createMainMenu()
{
	if(!menu)
		menu = new GameMenu();
	else
		menu->clearButtons();

	menu->addButton([]{ Game::getInstance()->newGame(); },D3DXVECTOR2(50,40), "new game");
	menu->addButton([]{ Game::getInstance()->showLeaderboard(); }, D3DXVECTOR2(50,140), "leaderboard");
	menu->addButton([]{ PostQuitMessage(0); }, D3DXVECTOR2(50,240), "exit");
	
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
	SAFE_DELETE( map );
	SAFE_DELETE( cam );
}