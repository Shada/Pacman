Texture2D diffuse, alpha;


struct VSSceneIn
{
	float3 pos		: POS;
	float3 norm		: NORM;
	float2 texCoord	: TEXCOORD;
};
struct VSInstanceIn
{
	float3 pos		: POS;
	float3 norm		: NORM;
	float2 texCoord	: TEXCOORD0;
	float3 insPos	: TEXCOORD1;
	float  rotation : TEXCOORD2;
};

struct PSSceneIn
{
	float4 pos		: SV_Position;
	float2 texCoord : TEXCOORD;
};

cbuffer cbEveryFrame
{
	float3 Ka;
	float4 CameraPos;
	float time;

	matrix mWorld;
	matrix mWorldIns[701];
	matrix mWorldViewProjection;
	matrix mProjection;	
	matrix mWorldView;
	matrix mView;
};

SamplerState linearSampler
{
	Filter = MIN_MAG_MIP_LINEAR;
	AddressU = Wrap;
	AddressV = Wrap;
};

SamplerState anisotropicSampler
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
	mWorldView = mul(mWorld, mView);
	mWorldViewProjection = mul(mWorldView, mProjection);

	output.pos = mul( float4(input.pos, 1.0), mWorldViewProjection );
	output.texCoord = input.texCoord;
	return output;
};
PSSceneIn VSInstance(VSInstanceIn input)
{
	PSSceneIn output = (PSSceneIn)0;
	float4 temp = float4(input.pos, 1.0f);
	input.pos = mul(temp, mWorld);
	
	float x = input.pos.x, z = input.pos.z;
	x = input.pos.x * cos(input.rotation) - input.pos.z * sin(input.rotation);
	z = input.pos.x * sin(input.rotation) + input.pos.z * cos(input.rotation);

	output.pos = float4(x, input.pos.y, z, 1);
	output.pos.xyz += input.insPos;
	output.pos = mul( output.pos, mul(mView, mProjection) );
	
	output.texCoord = input.texCoord;
	return output;
};

float4 PSScene(PSSceneIn input) : SV_Target
{
	float3 col = diffuse.Sample(anisotropicSampler, input.texCoord);

	return float4(col, 0);
};

technique10 DrawScene
{
    pass p0
    {
        SetVertexShader( CompileShader( vs_4_0, VSScene() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, PSScene() ) );
	    
	    SetRasterizerState( NoCulling );
	    SetDepthStencilState( EnableDepth, 0 );
    }  
}
technique10 RenderInstanced
{
    pass p0
    {
        SetVertexShader( CompileShader( vs_4_0, VSInstance() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, PSScene() ) );
	    
	    SetRasterizerState( NoCulling );
	    SetDepthStencilState( EnableDepth, 0 );
    }  
}