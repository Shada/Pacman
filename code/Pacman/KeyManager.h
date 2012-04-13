#pragma once
#include "KeyListener.h"
#include "stdafx.h"
class KeyManager
{
private:
	vector<KeyListener*> subscribers;
	//These two have same amount of elements and use the same index. ((CHANGE TO SHORT!½!!!))
	vector<int> usedkeys;
	vector<bool> prevKeyState;
public:
	KeyManager();
	//adds a subscriber
	void attach(KeyListener* listener);
	//removes a subscriber, but does not delete it
	void detach(KeyListener* listener);
	void notify(int key);
	
	void update(float dt);
	~KeyManager();
};

