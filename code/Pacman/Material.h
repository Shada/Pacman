#pragma once
#include "stdafx.h"

class Material
{
	friend class MtlReader;
private:

	string name;
	
	int illum;
	float ns, alpha;

	string textureFileName,	alphaMapFileName;
	ID3D10ShaderResourceView* g_pTextureResource, *g_pAlphaResource;
public:
	Material();
	Material(string name);
	~Material();

	D3DXVECTOR3 ka, kd, ks;

	void loadImageData();
	void loadAlphaMap();

	void setTexture(string textureFileName)		{ this->textureFileName = textureFileName; }
	void setAlphaMap(string alphaMapFileName)	{ this->alphaMapFileName = alphaMapFileName; }

	const D3DXVECTOR3 getKa() { return ka; }
	const D3DXVECTOR3 getKd() { return kd; }
	const D3DXVECTOR3 getKs() { return ks; }

	ID3D10ShaderResourceView* getTextureResource() { return g_pTextureResource; }
	ID3D10ShaderResourceView* getAlphaResource()   { return g_pAlphaResource;   }
	string getName()			{ return name;				}
	string getTextureFileName() { return textureFileName;	}
};