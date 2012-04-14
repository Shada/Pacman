#pragma once
#include "KeyListener.h"
#include <math.h>
#include "stdafx.h"
#include "GameButton.h"


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
	void clearButtons();
	//adds a new button, code is the command that the button will execute when pressed.
	template<typename T> void addButton(T const &code, D3DXVECTOR2 pos,string text)
	{
		buttons.push_back(new GameButton(code,pos,text));
	}

	//Used to set the first button in the menu to selected so 
	//that a button is selected before the user has changed it.
	//The first button to be pushed in is the last element in the vector.
	void setFirstSelected()
	{
		if(buttons.size() > 0)
			buttons.at(buttons.size()-1)->setSelected();
	}
	void handleKeyStrokes(int key);
	void draw();
};