#include "Material.h"


Material::Material(string name)
{
	this->name				= name;
	textureFileName			= "Images/default.png";
	alphaMapFileName		= "Images/DefaultAlpha.jpg";
	ka						= D3DXVECTOR3( 0.2f, 0.2f, 0.2f);
	kd						= D3DXVECTOR3( 0.8f, 0.8f, 0.8f);
	ks						= D3DXVECTOR3( 0.9f, 0.9f, 0.9f);
	illum					= 0;
	ns						= .0f;
	alpha					= 1.0f;
	g_pTextureResource		= NULL;
	g_pAlphaResource		= NULL;
}

void Material::loadImageData(ID3D10Device* g_pd3dDevice)
{
	//Load image, if the image cannot be found, the defaulttexture will be loaded instead
	if(FAILED(D3DX10CreateShaderResourceViewFromFile(g_pd3dDevice, textureFileName.c_str(), NULL, NULL, &g_pTextureResource, NULL)))
		if(FAILED(D3DX10CreateShaderResourceViewFromFile(g_pd3dDevice, "Images/default.png", NULL, NULL, &g_pTextureResource, NULL)))
			MessageBox(0, "Failed to create shader resource in Material ", "SR Error", 0);
}
void Material::loadAlphaMap(ID3D10Device* g_pd3dDevice)
{
	//load alpha-map, if the image cannot be found, the defaultalphamap will be loaded instead
	if(FAILED(D3DX10CreateShaderResourceViewFromFile(g_pd3dDevice, alphaMapFileName.c_str(), NULL, NULL, &g_pAlphaResource, NULL)))
		if(FAILED(D3DX10CreateShaderResourceViewFromFile(g_pd3dDevice, "Images/DefaultAlpha.jpg", NULL, NULL, &g_pAlphaResource, NULL)))
			MessageBox(0, "Failed to create shader resource in Material ", "SR Error", 0);
}

Material::~Material()
{
	//release the resources
	SAFE_RELEASE(g_pTextureResource);
	SAFE_RELEASE(g_pAlphaResource);
}