#pragma once
#include "Model.h"
#include "Material.h"

class Floor
{
private:
	Model *model;
	D3DXMATRIX mWorld;
public:
	Floor(D3DXVECTOR3 *startPos, D3DXVECTOR2 dimensions);
	~Floor();

	void draw();
};