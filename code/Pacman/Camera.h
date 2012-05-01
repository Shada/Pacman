#pragma once
#include "stdafx.h"

class Camera
{
private:
	D3DXMATRIX		*mView,		//view-matrix
					*mProj,
					mRot;				

	D3DXVECTOR3     vEyePt,     //eye point
					vDesiredPt,	//wanted point
                    vLookAtPt,  //look-at target
                    vUp,		//up-vector
					vDistance;	//distance to player
	
	float			fRot;

public:
	Camera();
	~Camera();

	void update		(D3DXVECTOR3 pos, double dt);	//update camera

	const D3DXMATRIX		*getViewMatrix(){ return mView; }
	const D3DXMATRIX		*getProjMatrix(){ return mProj; }

};