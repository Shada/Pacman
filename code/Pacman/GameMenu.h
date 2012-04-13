#pragma once
#include "KeyListener.h"
#include <math.h>
#include "stdafx.h"
#include "GameButton.h"
#include "Game.h"


class GameMenu : KeyListener
{
private:
	//selected is the ID of the button currently selected
	int selected, numberofButtons;

	//used to change which button is selected, the dir can be 1 or -1
	void changeSelected(int dir);

	//will contain one point which the gemotery shader will create a plane of.
	ID3D10Buffer* vB;

	vector<GameButton*> buttons;
public:
	GameMenu();
	~GameMenu();

	//adds a new button, code is the command that the button will execute when pressed.
	template<typename T> void addButton(T const &code, string text)
	{
		buttons.push_back(new GameButton(code,text));
	}
	void handleKeyStrokes(int key);
	void draw();
};