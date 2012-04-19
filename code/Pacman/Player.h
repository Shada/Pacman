#pragma once
#include "GameObject.h"
class Player 
	: public GameObject
{
private:
	Tile* nextTile;

	Direction currentDirection;

	//will translate between the perspective of the player and the
	//global world directions. For this to work the Direction enum must be 
	//changed to NORTH, EAST, SOUTH, WEST
	const Direction getWorldDirection(const Direction d);
public:
	Player(Tile* t, D3DXVECTOR3 *pos, ID3D10EffectTechnique* tech, Model* m);
	~Player();

	void handleKeyStrokes(int key);
	
	void update(float dt);
	void draw();

};

