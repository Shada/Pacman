#include "GameMenu.h"


GameMenu::GameMenu()
	:KeyListener()
{
	selected = 0;
	numberofButtons = 3;

	buttonText[0] = "new game";
	buttonText[1] = "high score";
	buttonText[2] = "exit";
	string banan = buttonText[1];
}

void GameMenu::handleKeyStrokes(char Key)
{
	//should be up and down later
	if(Key == 'W')
		changeSelected(1);
	else if(Key == 'S')
		changeSelected(-1);
}

void GameMenu::changeSelected(int dir)
{
	if(abs(dir) == 1)
	{
		selected+= dir;
	
		if(selected >= numberofButtons)
			selected = 0;
		else if(selected < 0)
			selected = numberofButtons-1;
	}
	//else wrong input
}
void GameMenu::draw()
{
	//GraphicsManager::getInstance()->render(model)
}
GameMenu::~GameMenu()
{
}
