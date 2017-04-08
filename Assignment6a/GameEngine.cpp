#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include "GameEngine.h"
#include "EastZombie.h"

using namespace std;

void GameEngine::Tick()
{	
	int BOARD_X_WIDTH = board.getXWidth();
	int BOARD_Y_HEIGHT = board.getYWidth();
	unsigned int z;

	// Tell the zombies to move
	for (z = 0; z < zombies.size(); z++)
	{
		Zombie * this_zombie = zombies.at(z);
		
		// Wrap Zombie positive X movement
		if (this_zombie->getPositionX() == BOARD_X_WIDTH - 1)
		{
			this_zombie->setPositionX(-1);
		}

		// Wrap Zombie positive Y movement
		if (this_zombie->getPositionY() == BOARD_Y_HEIGHT - 1)
		{
			this_zombie->setPositionY(-1);
		}

		// Move the zombie
		this_zombie->move();
	}
	
	// Draw the image of the board on the screen
	board.drawBoard(zombies);
}

void GameEngine::Run()
{
	bool done = false;

	while (!done) // FIXME: Eventually, once the "people" class has been added, make it continue until there are no more people >:D
	{
		Tick();

		// Freeze the game for a half second
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

GameEngine::GameEngine()
{
	// Spawn inital zombies
	// FIXME: Should be a list and position should be random 
	zombies.push_back(new Zombie(4, 8));
	zombies.push_back(new EastZombie(3, 5));

	// Create the gameboard
	board = GameBoard();
}