#pragma once
#include "KeyListener.h"
#include "stdafx.h"
class KeyManager
{
private:
	vector<KeyListener*> subscribers;
	char pressedKey;
public:
	KeyManager(void);
	//adds a subscriber
	void attach(KeyListener* listener);
	//removes a subscriber, but does not delete it
	void detach(KeyListener* listener);
	void notify();
	~KeyManager(void);
};

