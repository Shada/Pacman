#include "PolygonGroup.h"


PolygonGroup::PolygonGroup(string name)
{
	this->name = name;
	bufferIndex = 0;
	material = Material("default");
}

void PolygonGroup::draw(ID3D10EffectTechnique* tech )
{
	GraphicsManager* m = GraphicsManager::getInstance();

	m->useMaterial(material);
	m->render(tech,bufferIndex,getVertexAmount());
}
void PolygonGroup::feedData(D3DXVECTOR3* vertex, D3DXVECTOR2* textureCoordinate, D3DXVECTOR3* normal)
{
	Vertex ver;
	ver.position = *vertex;
	ver.normal = *normal;
	ver.texCoord = *textureCoordinate;
	vertices.push_back(ver);
}
void PolygonGroup::feedToPData(Vertex* pData)
{
	//saves the start position and size of this range in pdata
	//to make it more accessable
	int currentPDataPos = bufferIndex;
	for(unsigned int i = 0; i < vertices.size(); i++)
		pData[currentPDataPos++] = vertices.at(i);
}

PolygonGroup::~PolygonGroup()
{
}