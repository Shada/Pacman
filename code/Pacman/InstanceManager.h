#pragma once
#include "GameObject.h"
#include "Model.h"

class InstanceManager
{
private:
	Model				*model;

	Material			material;

	vector<GameObject*> objects;
	vector<D3DXVECTOR3> positions;
	vector<float>		rotations;
	
	D3DXMATRIX			mWorld, 
						mRot;
	
	float				rotSpeed, 
						rotation;

	int					numberOfInstances;

	ID3D10Buffer		*vb[2];
	UINT				stride[2], 
						offset[2];

public:
	InstanceManager(Model* model, float rotSpeed);
	~InstanceManager();

	void draw();
	void update(double dt);

	void addObject(GameObject* object);
	void removeObject(GameObject* object);

	void mapBuffers();

	int getNumberOfInstances() { return numberOfInstances; }
};

