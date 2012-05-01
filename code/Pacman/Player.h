#pragma once
#include "GameObject.h"

class Player 
	: public GameObject
{
private:
	Tile* nextTile;

	D3DXVECTOR3		position;
	float			radius;

	Direction currentDirection;

	//will translate between the perspective of the player and the
	//global world directions. For this to work the Direction enum must be 
	//changed to NORTH, EAST, SOUTH, WEST
	const Direction getWorldDirection(const Direction d);
public:
	Player(Tile* t, ID3D10EffectTechnique* tech, Model* m);
	~Player();

	D3DXVECTOR3		getPosition()		{ return position; }
	float			getRadius()			{ return radius; }

	void handleKeyStrokes(int key);
	
	void update(double dt);
	void draw();
};