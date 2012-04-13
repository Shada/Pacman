#include "KeyManager.h"


KeyManager::KeyManager()
{
	usedkeys.push_back(VK_UP);
	usedkeys.push_back(VK_DOWN);
	usedkeys.push_back(VK_LEFT);
	usedkeys.push_back(VK_RIGHT);
	usedkeys.push_back(VK_RETURN);
	for(int i = 0; i < 5; i++)
		prevKeyState.push_back(false);
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
void KeyManager::notify(int key)
{
	for(int i = 0; i < subscribers.size(); i++)
		subscribers.at(i)->handleKeyStrokes(key);
}
void KeyManager::update(float dt)
{
	for(int i= 0; i < usedkeys.size(); i++)
	{
		//NOT BOOL!!! SHORT!!!!!
		if(!GetKeyState(usedkeys.at(i)) && prevKeyState.at(i))
		{
			notify(usedkeys.at(i));
		}
		if(GetKeyState(usedkeys.at(i)))
			prevKeyState.at(i) = GetKeyState(usedkeys.at(i));
		prevKeyState.at(i) = GetKeyState(usedkeys.at(i));
	}
}
KeyManager::~KeyManager()
{
}
