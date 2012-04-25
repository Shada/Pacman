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
	D3DXMatrixRotationY(&mRot, yRot);
	float scale = 0.5f;
	D3DXMatrixScaling(&mScale, scale, scale, scale);

	D3DXMatrixTranslation( &mTranslate, position.x, position.y, position.z );
	D3DXMatrixMultiply( &mWorld, &mScale, &mRot );
	D3DXMatrixMultiply( &mWorld, &mWorld, &mTranslate );
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