#pragma once
#include "stdafx.h"
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

	ID3D10Device *g_pd3dDevice;
	IDXGISwapChain *g_pSwapChain;
	ID3D10RenderTargetView *g_pRenderTargetView;
	ID3D10Texture2D *g_pDepthStencil;
	ID3D10DepthStencilView *g_pDepthStencilView;
	HWND hWnd;
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
	void render();
	
	void useMaterial();
	void useBuffer(ID3D10Buffer* vB);
	void useWorldMatrices(D3DXMATRIX m[], int size);
	void useTechnique(ID3D10EffectTechnique* tech);

	void resetBlendState();

	const ID3D10Device* getDevice() { return g_pd3dDevice; }

	void createFont(LPD3DX10FONT *font, int height,LPCSTR fontname);
	void createSprite(LPD3DX10SPRITE* sprite);
	//shader techniques
	ID3D10EffectTechnique *g_pTechRender;

	ID3D10InputLayout *g_pVertexLayout;
};