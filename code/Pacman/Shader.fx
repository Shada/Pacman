struct VSSceneIn
{
	float3 pos		: POS;
	float3 norm		: NORM;
	float2 texCoord	: TEXCOORD;
};
struct PSSceneIn
{
	float4 pos		: SV_Position;
	float4 norm		: NORM;
	float2 texCoord : TEXCOORD;
};

cbuffer cbOnce
{
}
cbuffer cbEveryFrame
{
	float3 Ka;
	float4 CameraPos;
	float time;

	matrix mWorld;
	matrix mWorldViewProjection;	
	matrix mWorldView;
	matrix mView;
};

SamplerState AnisotropicSampler
{
	Filter = ANISOTROPIC;
	AddressU = Wrap;
	AddressV = Wrap;
};

DepthStencilState EnableDepthTestOnly
{
    DepthEnable = TRUE;
    DepthWriteMask = ZERO;
};

DepthStencilState EnableDepth
{
    DepthEnable = TRUE;
    DepthWriteMask = ALL;
};

RasterizerState NoCulling
{
	CullMode = NONE;
};
RasterizerState backFaceCulling
{
	cullmode = back;
};
RasterizerState frontFaceCulling
{
	cullmode = front;
};

PSSceneIn VSScene(VSSceneIn input)
{
	PSSceneIn output = (PSSceneIn)0;
	output.pos = mul( float4(input.pos, 1.0), mWorldViewProjection );
	float3 tnorm = normalize(mul(input.norm, mWorldView));
	float4 eyeCoords = mul(float4(input.pos, 1.0), mWorldView);
	float3 cameraPos = mul(CameraPos, mView);

	return output;
};

float4 PSScene(PSSceneIn input) : SV_Target
{
	return float4(.8f,.5f,.3f,1);
};

technique10 DrawScene
{
    pass p0
    {
        SetVertexShader( CompileShader( vs_4_0, VSScene() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, PSScene() ) );
	    
	    SetRasterizerState( backFaceCulling );
	    SetDepthStencilState( EnableDepth, 0 );
    }  
}