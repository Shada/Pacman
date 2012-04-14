#include "GraphicsManager.h"

GraphicsManager *GraphicsManager::_this = NULL;
GraphicsManager::GraphicsManager(HWND g_hWnd)
{
	g_driverType = D3D10_DRIVER_TYPE_NULL;
	g_pd3dDevice = NULL;
	g_pSwapChain = NULL;
	g_pRenderTargetView = NULL;
	g_pDepthStencil = NULL;
	g_pDepthStencilView = NULL;

	hWnd = g_hWnd;
	initDevice();
}
GraphicsManager* GraphicsManager::createInstance(HWND g_hWnd)
{
	if(!_this)
		_this = new GraphicsManager(g_hWnd);
	return _this;
}
GraphicsManager* GraphicsManager::getInstance()
{
	if(_this)
		return _this;
	else return NULL;
}
HRESULT GraphicsManager::initDevice()
{
	HRESULT hr = S_OK;;

	RECT rc;
	GetClientRect( hWnd, &rc );
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
createDeviceFlags |= D3D10_CREATE_DEVICE_DEBUG;
#endif

	D3D10_DRIVER_TYPE driverTypes[] =
	{
		D3D10_DRIVER_TYPE_HARDWARE,
		D3D10_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = sizeof(driverTypes) / sizeof(driverTypes[0]);

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory( &sd, sizeof(sd) );
	sd.BufferCount = 1;
	sd.BufferDesc.Width = width;
	sd.BufferDesc.Height = height;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = TRUE;

	for( UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++ )
	{
		g_driverType = driverTypes[driverTypeIndex];
		hr = D3D10CreateDeviceAndSwapChain( NULL, g_driverType, NULL, createDeviceFlags,
		D3D10_SDK_VERSION, &sd, &g_pSwapChain, &g_pd3dDevice );
		if( SUCCEEDED( hr ) )
			break;
	}
	if( FAILED(hr) )
		return hr;

	// Create a render target view
	ID3D10Texture2D* pBackBuffer;
	hr = g_pSwapChain->GetBuffer( 0, __uuidof( ID3D10Texture2D ), (LPVOID*)&pBackBuffer );
	if( FAILED(hr) )
		return hr;

	hr = g_pd3dDevice->CreateRenderTargetView( pBackBuffer, NULL, &g_pRenderTargetView );
	SAFE_RELEASE(pBackBuffer);
	if( FAILED(hr) )
		return hr;

	// Create depth stencil texture
	D3D10_TEXTURE2D_DESC descDepth;
	descDepth.Width = width;
	descDepth.Height = height;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D32_FLOAT;
	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D10_USAGE_DEFAULT;
	descDepth.BindFlags = D3D10_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;
	hr = g_pd3dDevice->CreateTexture2D( &descDepth, NULL, &g_pDepthStencil );
	if( FAILED(hr) )
		return hr;

	// Create the depth stencil view
	D3D10_DEPTH_STENCIL_VIEW_DESC descDSV;
	descDSV.Format = descDepth.Format;
	descDSV.ViewDimension = D3D10_DSV_DIMENSION_TEXTURE2D;
	descDSV.Texture2D.MipSlice = 0;
	hr = g_pd3dDevice->CreateDepthStencilView( g_pDepthStencil, &descDSV, &g_pDepthStencilView );
	if( FAILED(hr) )
		return hr;


	g_pd3dDevice->OMSetRenderTargets( 1, &g_pRenderTargetView, g_pDepthStencilView );
	// Setup the viewport
	D3D10_VIEWPORT vp;
	vp.Width = width;
	vp.Height = height;
	vp.MinDepth = 0.0f;
	vp.MaxDepth = 1.0f;
	vp.TopLeftX = 0;
	vp.TopLeftY = 0;
	g_pd3dDevice->RSSetViewports( 1, &vp );
	//Init shader effect
	DWORD dwShaderFlags = D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY;
	if(FAILED(D3DX10CreateEffectFromFile( "shader.fx",
		NULL,
		NULL,
		"fx_4_0",
		dwShaderFlags,
		0,
		g_pd3dDevice,
		NULL,
		NULL,
		&g_pEffect,
		NULL,
		NULL)))
	{
		MessageBox(0, "Error compiling shader!", "Shader error!", 0);
		return E_FAIL;
	}

	g_pTechRender = g_pEffect->GetTechniqueByName("DrawScene");

	const D3D10_INPUT_ELEMENT_DESC vertexLayout[] =
	{
		{ "POS", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORM", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, sizeof(float) * 3, D3D10_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, sizeof(float) * 6, D3D10_INPUT_PER_VERTEX_DATA, 0 }
	};

	D3D10_PASS_DESC PassDesc;
	g_pTechRender->GetPassByIndex(0)->GetDesc(&PassDesc);

	//Create Input Layout (== Vertex Declaration)
	g_pd3dDevice->CreateInputLayout(vertexLayout,
	sizeof(vertexLayout) / sizeof(D3D10_INPUT_ELEMENT_DESC),
	PassDesc.pIAInputSignature,
	PassDesc.IAInputSignatureSize,
	&g_pVertexLayout );
}
void GraphicsManager::useBuffer(ID3D10Buffer* vB)
{
	//The stride and offset
	UINT stride = sizeof(Vertex), offset = 0;

	//Set the layouts and topology
	g_pd3dDevice->IASetInputLayout( g_pVertexLayout );
	g_pd3dDevice->IASetPrimitiveTopology( D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST );
	g_pd3dDevice->IASetVertexBuffers( 0, 1, &vB, &stride, &offset );
}
void GraphicsManager::useMaterial()
{

}
void GraphicsManager::resetBlendState()
{
	g_pd3dDevice->OMSetBlendState( NULL, 0, 0xffffffff );
}
void GraphicsManager::useTechnique(ID3D10EffectTechnique* tech)
{
	//should prob be send in in the render function instead.
}
void GraphicsManager::useWorldMatrices(D3DXMATRIX m[], int size)
{
	g_pEffect->GetVariableByName("mWorld")->AsMatrix()->SetMatrixArray((float*)&m,0,size);
}
void GraphicsManager::render()
{

}
void GraphicsManager::clearRenderTarget()
{
	//clear render target
	g_pd3dDevice->ClearRenderTargetView( g_pRenderTargetView, D3DXVECTOR4(.3f,.3f,.3f,.3f) );

	//clear depth info
	g_pd3dDevice->ClearDepthStencilView( g_pDepthStencilView, D3D10_CLEAR_DEPTH, 1.0f, 0 );
}
void GraphicsManager::swapChain()
{
	//swap the chain
	g_pSwapChain->Present( 0, 0 );
}
void GraphicsManager::createFont(LPD3DX10FONT* font, int height,LPCSTR fontname)
{
	D3DX10CreateFont( g_pd3dDevice,height,0,FW_BOLD,0,FALSE,DEFAULT_CHARSET,
							OUT_TT_ONLY_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, fontname, font );
}
void GraphicsManager::createSprite(LPD3DX10SPRITE* sprite)
{
	D3DX10CreateSprite( g_pd3dDevice, 256, sprite);
}
GraphicsManager::~GraphicsManager()
{
	SAFE_RELEASE(g_pd3dDevice);
	SAFE_RELEASE(g_pSwapChain);
	SAFE_RELEASE(g_pRenderTargetView);
	SAFE_RELEASE(g_pDepthStencil);
	SAFE_RELEASE(g_pDepthStencilView);
	SAFE_RELEASE(g_pEffect);
	SAFE_RELEASE(g_pVertexLayout);
}