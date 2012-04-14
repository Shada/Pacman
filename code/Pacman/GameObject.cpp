#include "GameObject.h"


GameObject::GameObject()
	:KeyListener()
{
	pos = new D3DXVECTOR3(0, 0, 0);
	vB = NULL;
}

GameObject::~GameObject()
{
	SAFE_DELETE( pos );
	//SAFE_DELETE( currentTile );
	SAFE_RELEASE( vB );
}