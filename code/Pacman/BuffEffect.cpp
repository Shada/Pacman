#include "BuffEffect.h"
#include "Game.h"

float BuffEffect::multiplier = 1;

BuffEffect::BuffEffect(int score)
{
	this->score = score;
	counter = 0;
	addScore();
}

void BuffEffect::addScore()
{
	//Game::getInstance()->addScore(score*multiplier);
}

BuffEffect::~BuffEffect()
{
}