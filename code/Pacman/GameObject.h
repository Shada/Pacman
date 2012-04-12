#pragma once
#include "KeyListener.h"
#include "stdafx.h"
class GameObject : KeyListener
{
private:
	D3DXVECTOR3* pos;
public:
	GameObject(void);
	~GameObject(void);
};

