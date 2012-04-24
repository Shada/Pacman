#include "Model.h"



Model::Model(string name)
{
	//The models name is saved, so that it can be used for searching
	//it's not used, but it might be in the future
	this->name = name;
	//The vector with groups
	groups = vector<PolygonGroup>();

	g_pVB = NULL;
}

void Model::draw(ID3D10EffectTechnique* tech)
{
	GraphicsManager::getInstance()->useBuffer(g_pVB);
	for( unsigned int i = 0; i < groups.size(); i++ )
		groups.at(i).draw(tech);
}
void Model::feedData()
{ 
	// Set the correct startpositions within the buffer and count the total amount 
	//of vertex points
	vertexAmount = 0;
	unsigned int i;
	for( i = 1; i < groups.size(); i++)
	{
		vertexAmount += groups.at(i - 1).getVertexAmount();
		groups.at(i).setStartPos(vertexAmount);
	}
	vertexAmount += groups.back().getVertexAmount();
}

void Model::createBuffer()
{
	GraphicsManager::getInstance()->createBuffer(getVertexAmount(), &g_pVB);

	createPData();
}

void Model::createPData()
{
	Vertex* pData = NULL;
	//model has its own VB
	g_pVB->Map( D3D10_MAP_WRITE_DISCARD, 0, reinterpret_cast< void** >((void**)&pData) );
	for(unsigned int i=0;i < groups.size();i++)
		groups.at(i).feedToPData(pData);

	g_pVB->Unmap();
}

void Model::loadImageData()
{
	for(unsigned int i = 0; i < groups.size(); i++)
	{
		groups.at(i).material->loadImageData();
		groups.at(i).material->loadAlphaMap();
	}
}

Model::~Model()
{
	SAFE_RELEASE(g_pVB);
}