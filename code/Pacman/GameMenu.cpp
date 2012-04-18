#include "GameMenu.h"
#include "Game.h"

GameMenu::GameMenu()
	:KeyListener()
{
	selected = 0;
	numberofButtons = 0;

	vB = NULL;
}


void GameMenu::handleKeyStrokes(int key)
{
	if(key == VK_UP)
		changeSelected(-1);
	else if(key == VK_DOWN)
		changeSelected(1);
	else if(key == VK_RETURN)
	{
		buttons.at(selected)->press();
	} 
}

void GameMenu::changeSelected(int dir)
{
	if(abs(dir) == 1)
	{
		buttons.at(selected)->setUnselected();

		selected += dir;
		
		if(selected == buttons.size())
			selected = 0;
		else if(selected < 0)
			selected = buttons.size()-1;

		buttons.at(selected)->setSelected();
	}
	//else wrong input
}
void GameMenu::clearButtons()
{
	for(unsigned int i = 0; i < buttons.size(); i++)
		SAFE_DELETE(buttons.at(i));
}
void GameMenu::draw()
{
	GraphicsManager* m = GraphicsManager::getInstance();
	if(m)
	{
		//m->useBuffer(vB);
		
		for(unsigned int i = 0; i < buttons.size(); i++)
			buttons.at(i)->draw();
	}
}
GameMenu::~GameMenu()
{
	
	clearButtons();
	SAFE_RELEASE(vB);
}