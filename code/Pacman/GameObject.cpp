#include "GameObject.h"


GameObject::GameObject(Tile *t)
	: KeyListener()
{
	vB = NULL;
	currentTile = t;
}

GameObject::~GameObject()
{
	SAFE_DELETE( position );
	SAFE_RELEASE( vB );
}