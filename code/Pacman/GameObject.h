#pragma once
#include "KeyListener.h"
#include "stdafx.h"
#include "Tile.h"
#include "Model.h"
#include "GraphicsManager.h"

class GameObject : KeyListener
{
protected:
	Model* model;
	Tile *currentTile;

	D3DXVECTOR3 *position;
	D3DXMATRIX mWorld;

	ID3D10EffectTechnique* tech;
public:
	GameObject(Tile *t);
	~GameObject();

	//if instanced this should not be called. Instead the game
	//class will say draw everyone of these and collect all the object's 
	//worldmatrices and send them into the shader

	//Will first send in the objects worldmatrix to the shader
	//then call its model's draw()
	virtual void draw(); 

	//used for instancing when game will collect all objects it  
	//wants to draw instanced's worldmatrices.
	const D3DXMATRIX getmWorld() { return mWorld; }
};