#include "GameObject.h"


GameObject::GameObject(Tile *t)
	: KeyListener()
{
	model = NULL;
	tech = NULL;
	position = NULL;
	currentTile = t;
}
void GameObject::draw()
{
	GraphicsManager::getInstance()->useWorldMatrix(mWorld);
	model->draw(tech);
}


GameObject::~GameObject()
{
	SAFE_DELETE( position );
}