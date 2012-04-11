#include "KeyManager.h"


KeyManager::KeyManager(void)
{
}
void KeyManager::attach(KeyListener* listener)
{
	subscribers.push_back(listener);
}
void KeyManager::detach(KeyListener* listener)
{
	for(int i = 0; i < subscribers.size(); i++)
		if(subscribers.at(i) == listener)
			subscribers.erase(subscribers.begin() + i);
}
void KeyManager::notify()
{
	for(int i = 0; i < subscribers.size(); i++)
		subscribers.at(i)->handleKeyStrokes(pressedKey);
}
KeyManager::~KeyManager(void)
{
}
