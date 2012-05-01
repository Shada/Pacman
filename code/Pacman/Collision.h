#pragma once
#include "stdafx.h"
#include "Player.h"

class Collision
{
private:
	Collision(vector<Player> *players);

	static Collision		*_this;
	vector<Player>			*players;

public:
	~Collision();

	static Collision		*getInstance();
	static Collision		*createInstance(vector<Player> *players);
	
	//collision detections
	bool sphereVsSphere(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2, float radius1, float radius2);
	bool rayVsSphere(D3DXVECTOR3 rayOrigin, D3DXVECTOR3 rayDir, D3DXVECTOR3 spherePos, float radius, float &intersect1, float &intersect2);

	//returns position of player if found
	bool lookForPlayers(D3DXVECTOR3 &out, D3DXVECTOR3 rayOrigin);
};