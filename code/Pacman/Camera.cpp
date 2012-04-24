#include "Camera.h"


Camera::Camera()
{
	vEyePt		= D3DXVECTOR3	( 0,  100, 0 );
	vLookAtPt	= D3DXVECTOR3	( 0, 0, 0 );
	vUp			= D3DXVECTOR3	( 0, 0, 1 );
	vDistance	= D3DXVECTOR3	( 0, -7, 15 );
	vDesiredPt	= D3DXVECTOR3	( 0,  10, -20 );
	
	fRot = 0;
	mView		= new D3DXMATRIX();
	mProj		= new D3DXMATRIX();

	D3DXMatrixLookAtLH( mView, &vEyePt, &vLookAtPt, &vUp );
	D3DXMatrixPerspectiveLH(mProj,	(float)D3DX_PI * .6f,
									(float)(SCREENWIDTH / _SCREENHEIGHT), 1.0f, 3000.0f);
}

void Camera::update(D3DXVECTOR3 pos, double dt)
{
	//vEyePt.z -= 0.05f;

	//vEyePt = pos / 2;
	D3DXMatrixLookAtLH( mView, &vEyePt, &vLookAtPt, &vUp );
}

Camera::~Camera()
{
	SAFE_DELETE(mView);
	SAFE_DELETE(mProj);
}