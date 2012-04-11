#pragma once
#include "KeyListener.h"
#include <math.h>
#include "stdafx.h"
class GameMenu : KeyListener
{
private:
	//selected is the ID of the button currently selected
	int selected, numberofButtons;

	//used to change which button is selected, the dir can be 1 or -1
	void changeSelected(int dir);

	string buttonText[3];
public:
	GameMenu();
	void handleKeyStrokes(char Key);
	void draw();
	~GameMenu();
};

