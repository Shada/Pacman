#pragma once
#include "stdafx.h"
#include "Material.h"
//Regular vertex buffer data type
struct Vertex
{
	D3DXVECTOR3 position;
	D3DXVECTOR3 normal;
	D3DXVECTOR2 texCoord;
};
class GraphicsManager
{
private:
	D3D10_DRIVER_TYPE g_driverType;
	HWND hWnd;
	ID3D10Device *g_pd3dDevice;
	IDXGISwapChain *g_pSwapChain;
	ID3D10RenderTargetView *g_pRenderTargetView;
	ID3D10Texture2D *g_pDepthStencil;
	ID3D10DepthStencilView *g_pDepthStencilView;
	
	ID3D10Effect *g_pEffect;
	
	//Instance of self (Singleton)
	static GraphicsManager* _this;
	//Singleton constructor
	GraphicsManager(HWND g_hWnd);
public:

	~GraphicsManager();
	
	static GraphicsManager* getInstance();
	static GraphicsManager* createInstance(HWND g_hWnd);
	//initialize device data
	HRESULT initDevice();
	void clearRenderTarget();
	//switch backbuffer
	void swapChain();

	//remember to call all the use functions needed before calling this one
	//render() should be called from the object itself, while the renderInstanced()
	//should be called from the class that holds all objects that are to be drawed.
	void render(ID3D10EffectTechnique* tech, int bufferIndex, int numberOfVertices);
	void renderInstanced(ID3D10EffectTechnique* tech,int instanceCount, int bufferIndex, int numberOfVertices);
	

	void useMaterial(Material* mat);

	void useBuffer(ID3D10Buffer* vB);
	void useWorldMatrix(D3DXMATRIX m);
	//used when using instancing
	void useWorldMatrices(const D3DXMATRIX m[], int size);

	void resetBlendState();

	void createBuffer(int vertexAmount, ID3D10Buffer **g_pVB);

	ID3D10Device* getDevice() { return g_pd3dDevice; }
	//could not be const
	ID3D10Effect* getEffect()		{ return g_pEffect;    }

	void createFont(LPD3DX10FONT *font, int height,LPCSTR fontname);
	void createSprite(LPD3DX10SPRITE* sprite);
	//shader techniques
	ID3D10EffectTechnique *g_pTechRender;

	ID3D10InputLayout *g_pVertexLayout;
};