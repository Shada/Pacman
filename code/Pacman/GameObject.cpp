#include "GameObject.h"


GameObject::GameObject(void)
	:KeyListener()
{
	pos = new D3DXVECTOR3(0,0,0);
}


GameObject::~GameObject(void)
{
	SAFE_DELETE(pos);
}
