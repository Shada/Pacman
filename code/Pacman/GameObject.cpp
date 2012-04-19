#include "GameObject.h"


GameObject::GameObject(Tile *t, D3DXVECTOR3 *pos, ID3D10EffectTechnique* tech, Model *m)
	: KeyListener()
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
	SAFE_DELETE( position );
}