#include "GameEngine.h"
#include <time.h>

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

		// FIXME: Spawn a random zombie every once in awhile, instead of all at once at the beginning.
		
		Tick();

		// Freeze the game for a half second
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

GameEngine::GameEngine()
{
	int n, roll, rx, ry;

	// Spawn inital zombies - FIXME: Spawn a random zombie every once in awhile, instead of all at once at the beginning.
	srand(time(NULL));
	rx = rand() % BOARD_X_WIDTH;
	ry = rand() % BOARD_Y_HEIGHT;
	for (n = 0; n < 8; n++)
	{
		roll = rand() % 4;

		if (roll == 0)
		{
			zombies.push_back(new Zombie(rx, ry, BOARD_X_WIDTH, BOARD_Y_HEIGHT));
		}
		else if (roll == 1)
		{
			zombies.push_back(new EastZombie(rx, ry, BOARD_X_WIDTH, BOARD_Y_HEIGHT));
		}
		else if (roll == 2)
		{
			zombies.push_back(new NorthZombie(rx, ry, BOARD_X_WIDTH, BOARD_Y_HEIGHT));
		}
		else
		{
			zombies.push_back(new RandomZombie(rx, ry, BOARD_X_WIDTH, BOARD_Y_HEIGHT));
		}
	}
}