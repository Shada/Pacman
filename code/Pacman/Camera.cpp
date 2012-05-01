#include "Camera.h"


Camera::Camera()
{
	vEyePt		= D3DXVECTOR3	( 30,  100, -50 );
	vLookAtPt	= D3DXVECTOR3	( 100, 0, 100 );
	vUp			= D3DXVECTOR3	( 0, 1, 0 );
	vDistance	= D3DXVECTOR3	( 0, -7, 15 );
	vDesiredPt	= D3DXVECTOR3	( 0,  10, -20 );
	
	fRot		= .0008f;
	mView		= new D3DXMATRIX();
	mProj		= new D3DXMATRIX();

	D3DXMatrixLookAtLH( mView, &vEyePt, &vLookAtPt, &vUp );
	D3DXMatrixPerspectiveLH(mProj,	(float)D3DX_PI * .4f,
									(float)(SCREENWIDTH / _SCREENHEIGHT), 1.0f, 3000.0f);
}

void Camera::update(D3DXVECTOR3 pos, double dt)
{
	//vEyePt.z -= 0.05f;

	//vEyePt = pos / 2;

	//D3DXMatrixRotationAxis( &mRot, &vUp, fRot );
	//
	//D3DXVec3TransformCoord( &vEyePt, &vEyePt, &mRot );
	//D3DXVec3TransformCoord( &vLookAtPt, &vLookAtPt, &mRot );

	//vLookAtPt = D3DXVECTOR3	( 100, 0, 100 );
	//D3DXMatrixLookAtLH( mView, &vEyePt, &vLookAtPt, &vUp );
}

Camera::~Camera()
{
	SAFE_DELETE(mView);
	SAFE_DELETE(mProj);
}