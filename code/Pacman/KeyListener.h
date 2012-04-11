#pragma once
class KeyListener
{
public:
	KeyListener();

	//only classes which will use key input will implement this function
	//every other class will do nothing when this is called
	virtual void handleKeyStrokes(char Key) { ;}
	~KeyListener();
};

