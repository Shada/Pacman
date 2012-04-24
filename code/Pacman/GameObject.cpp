#include "GameObject.h"


GameObject::GameObject(Tile *t, ID3D10EffectTechnique* tech, Model *m)
	: KeyListener()
{
	this->model = m;
	this->tech = tech;
	this->position = t->getPos();
	this->currentTile = t;
}

GameObject::GameObject(Tile *t, ID3D10EffectTechnique* tech, Model *m, D3DXVECTOR3 pos)
{
	this->model = m;
	this->tech = tech;
	this->position = pos;
	this->currentTile = t;
}

void GameObject::update(float dt)
{

}

void GameObject::draw()
{
	GraphicsManager::getInstance()->useWorldMatrix(mWorld);
	model->draw(tech);
}

GameObject::~GameObject()
{
}