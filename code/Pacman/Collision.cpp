#include "Collision.h"

Collision *Collision::_this = NULL;
Collision::Collision(vector<Player> *players)
{
	this->players = players;
}

Collision *Collision::createInstance(vector<Player> *players)
{
	if(!_this)
		_this = new Collision(players);
	return _this;
}

bool Collision::sphereVsSphere(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float radius1, float radius2)
{
	return D3DXVec3Length(&(pos1 - pos2)) < radius1 + radius2;
}

bool Collision::rayVsSphere(D3DXVECTOR3 rayOrigin, D3DXVECTOR3 rayDir, D3DXVECTOR3 spherePos, float radius, float &intersect1, float &intersect2)
{
	D3DXVECTOR3 p = rayOrigin-spherePos;
	float det, b;
	b = -D3DXVec3Dot(&p,&rayDir);
	det = b*b - D3DXVec3Dot(&p,&p) + radius*radius;
	if(det<0)
	{
		return false;
	}
	det = sqrt(det);
	intersect1 = b - det;
	intersect2 = b + det;
	if(intersect2 < 0)
		return false;
	if(intersect1 < 0)
		intersect1 = 0;
	return true;
}

bool Collision::lookForPlayers(D3DXVECTOR3 &out, D3DXVECTOR3 rayOrigin)
{
	float i1, i2;
	for(unsigned int i = 0; i < players->size(); i++)
	{
		if(rayVsSphere(rayOrigin,D3DXVECTOR3(0,0,1),players->at(i).getPosition(),players->at(i).getRadius(),i1,i2) ||
			rayVsSphere(rayOrigin,D3DXVECTOR3(1,0,0),players->at(i).getPosition(),players->at(i).getRadius(),i1,i2) ||
			rayVsSphere(rayOrigin,D3DXVECTOR3(0,0,-1),players->at(i).getPosition(),players->at(i).getRadius(),i1,i2) ||
			rayVsSphere(rayOrigin,D3DXVECTOR3(-1,0,0),players->at(i).getPosition(),players->at(i).getRadius(),i1,i2))
		{
			out = players->at(i).getPosition();
			return true;
		}
	}
	return false;
}

Collision *Collision::getInstance()
{
	if(_this)
		return _this;
	else return NULL;
}

Collision::~Collision()
{
}