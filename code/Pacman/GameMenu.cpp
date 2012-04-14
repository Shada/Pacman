#include "GameMenu.h"


GameMenu::GameMenu()
	:KeyListener()
{
	selected = 0;
	numberofButtons = 0;
	Game* game = Game::getInstance();

	vB = NULL;

	//addButton([]{ Game::getInstance()->newGame(); }, "new game");
	//addButton([]{ ; }, "leaderboard");
	addButton([]{ PostQuitMessage(0); }, "exit");
}


void GameMenu::handleKeyStrokes(int key)
{
	if(key == VK_UP)
		changeSelected(1);
	else if(key == VK_DOWN)
		changeSelected(-1);
	else if(key == VK_RETURN)
	{
		buttons.at(selected)->press();
	} 
}

void GameMenu::changeSelected(int dir)
{
	if(abs(dir) == 1)
	{
		selected += dir;
		
		if(selected >= buttons.size())
			selected = 0;
		else if(selected < 0)
			selected = buttons.size()-1;
	}
	//else wrong input
}

void GameMenu::draw()
{
	GraphicsManager *m = GraphicsManager::getInstance();
	if(m)
	{
		//m->useBuffer(vB);
		m->render();
	}
}
GameMenu::~GameMenu()
{
	SAFE_RELEASE( vB );
}