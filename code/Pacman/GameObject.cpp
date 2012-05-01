#include "GameObject.h"


GameObject::GameObject(Tile *t, ID3D10EffectTechnique* tech, Model *m)
	: KeyListener()
{
	this->model = m;
	this->tech = tech;
	this->position = t->getPos();
	this->currentTile = t;
}

GameObject::GameObject(Tile *t, ID3D10EffectTechnique* tech, Model *m, D3DXVECTOR3 pos, float yRot)
{
	this->model = m;
	this->tech = tech;
	this->position = pos;
	this->currentTile = t;
	this->rotation = yRot;

	D3DXMatrixRotationY(&mRot, rotation);
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixTranslation( &mTranslate, position.x, position.y, position.z );
}

void GameObject::update(double dt)
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