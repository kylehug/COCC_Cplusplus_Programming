#include "GameEngine.h"

using namespace std;

void GameEngine::Tick()
{	
	unsigned int z;

	// Tell the zombies to move
	for (z = 0; z < zombies.size(); z++)
	{
		Zombie * this_zombie = zombies.at(z);		

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
	zombies.push_back(new Zombie(4, 8, BOARD_X_WIDTH, BOARD_Y_HEIGHT));
	zombies.push_back(new EastZombie(3, 5, BOARD_X_WIDTH, BOARD_Y_HEIGHT));
	zombies.push_back(new NorthZombie(2, 7, BOARD_X_WIDTH, BOARD_Y_HEIGHT));
}