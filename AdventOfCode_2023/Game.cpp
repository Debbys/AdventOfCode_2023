#include "Game.h"

Game::Game(unsigned ID)
{
	Game::ID = ID;
}

unsigned Game::getID(void)
{
	return Game::ID;
}

unsigned Game::getMaxAmountRed(void)
{
	return Game::maxAmountRed;
}

unsigned Game::getMaxAmountBlue(void)
{
	return Game::maxAmountBlue;
}

unsigned Game::getMaxAmountGreen(void)
{
	return Game::maxAmountGreen;
}

void Game::setMaxAmountRed(unsigned redCubes)
{
	Game::maxAmountRed = max(redCubes, maxAmountRed);
}

void Game::setMaxAmountBlue(unsigned blueCubes)
{
	Game::maxAmountBlue = max(blueCubes, maxAmountBlue);
}

void Game::setMaxAmountGreen(unsigned greenCubes)
{
	Game::maxAmountGreen = max(greenCubes, maxAmountGreen);
}


