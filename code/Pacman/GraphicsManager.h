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
	D3D10_DRIVER_TYPE        g_driverType;

	ID3D10Device			*g_pd3dDevice;
	IDXGISwapChain			*g_pSwapChain;
	ID3D10RenderTargetView	*g_pRenderTargetView;
	ID3D10Texture2D			*g_pDepthStencil;
	ID3D10DepthStencilView	*g_pDepthStencilView;
	ID3D10Effect			*g_pEffect;

	HWND					hWnd;
	
	//Instance of self (Singleton)
	static GraphicsManager* _this;
	GraphicsManager(HWND g_hWnd);

public:
	//shader techniques
	ID3D10EffectTechnique	*g_pTechRender;

	ID3D10InputLayout		*g_pVertexLayout;

	//Singleton constructor
	static GraphicsManager* getInstance();
	static GraphicsManager* createInstance(HWND g_hWnd);
	~GraphicsManager();

	//initialize device data
	HRESULT initDevice();
	void clearRenderTarget();

	//switch backbuffer
	void swapChain();
	void render();
	void resetBlendState();	
	
	void useMaterial();
	void useBuffer(ID3D10Buffer* vB);
	void useWorldMatrices(D3DXMATRIX m[], int size);
};