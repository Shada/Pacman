#include "InstanceManager.h"


InstanceManager::InstanceManager(Model* model, float rotSpeed)
{
	this->model = model;
	this->numberOfInstances = 0;
	this->rotSpeed = rotSpeed;
	rotation = 0;

	vb[0] = NULL;
	vb[1] = NULL;

	stride[0] = sizeof(Vertex);
	stride[1] = sizeof(InstanceType);
	
	offset[0] = 0;
	offset[1] = 0;

	D3DXMatrixIdentity( &mWorld );
	

	material = model->getGroups()->front()->material;
}

void InstanceManager::update(double dt)
{
	objects.front()->update(dt);
	mWorld = objects.front()->getmWorld();
}

void InstanceManager::draw()
{
	GraphicsManager *gm = GraphicsManager::getInstance();
	
	gm->useMaterial(material);
	gm->getDevice()->IASetPrimitiveTopology( D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST );
	gm->getDevice()->IASetVertexBuffers( 0, 2, vb, stride, offset );

	gm->useWorldMatrix(mWorld);

	gm->renderInstanced(gm->g_pTechInstanced, numberOfInstances, 0, model->getVertexAmount());
}

void InstanceManager::addObject(GameObject *object)
{
	objects.push_back(object);
	positions.push_back(object->getPos());
	rotations.push_back(object->getRot());
	
	numberOfInstances++;
}

void InstanceManager::removeObject(GameObject* object)
{
	return;
}

void InstanceManager::mapBuffers()
{
	vb[0] = model->getBuffer();

	GraphicsManager::getInstance()->createBuffer(numberOfInstances, &vb[1]);
	
	InstanceType* pDataI = NULL;
	
	vb[1]->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** >((void**)&pDataI) );
	
	for( unsigned int i = 0; i < objects.size(); i++ )
	{
		pDataI[i].position = positions.at(i);
		pDataI[i].rotation = rotations.at(i);
	}

	vb[1]->Unmap();

	mWorld = objects.front()->getmWorld();
}
InstanceManager::~InstanceManager()
{
	for(unsigned int i = 0; i < objects.size(); i++)
		SAFE_DELETE( objects.at(i));
}
