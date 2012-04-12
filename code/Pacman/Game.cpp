#include "Game.h"

Game *Game::instance = NULL;
Game::Game()
{
}

Game *Game::getInstance()
{
	if(!instance)
		instance = new Game();
	
	return instance;
}

void Game::update(double time)
{

}

void Game::draw(double time)
{

}

Game::~Game()
{
	
}