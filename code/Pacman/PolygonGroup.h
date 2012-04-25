#pragma once
#include "stdafx.h"
#include "Material.h"
#include "GraphicsManager.h"

class PolygonGroup
{
private:

	string name;
	int bufferIndex;
	vector<Vertex> vertices;
public:

	Material material;
	
	PolygonGroup(string name);
	~PolygonGroup();

	//first sets the material to be used by the graphicsmanager
	//to this groups material, then calls render.
	void draw(ID3D10EffectTechnique* tech);

	void feedData(D3DXVECTOR3* vertex, D3DXVECTOR2* textureCoordinate, D3DXVECTOR3* normal);
	void feedToPData(Vertex* pData);

	void setStartPos(int x) { bufferIndex = x; } 
	
	string getName()						{ return name;					}
	int getStartPos()						{ return bufferIndex;			}
	int getVertexAmount()					{ return vertices.size();		}
	D3DXVECTOR3 getVertexPosAt(int index)	{ return vertices[index].position;	}
};