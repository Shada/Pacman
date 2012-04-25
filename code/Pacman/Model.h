#pragma once
#include "stdafx.h"
#include "PolygonGroup.h"
#include "GraphicsManager.h"


class Model
{
	friend class ObjReader;
	friend class MtlReader;
private:

	vector<PolygonGroup*> groups;
	string name;
	ID3D10Buffer* g_pVB;
	
	int vertexAmount;

	void createPData();
public:
	
	Model(string name);
	~Model();

	void draw(ID3D10EffectTechnique* tech);

	void feedData();
	void createBuffer();

	string getName()					{ return name;			}
	int getVertexAmount()				{ return vertexAmount;	}
	ID3D10Buffer* getBuffer()			{ return g_pVB;			}
	vector<PolygonGroup*> *getGroups()	{ return &groups;		}

	void loadImageData();
};