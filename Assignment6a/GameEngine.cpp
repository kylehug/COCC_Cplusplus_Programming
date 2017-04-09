#include "GameEngine.h"

using namespace std;

void GameEngine::Tick()
{	
	unsigned int z;
	int roll;

	srand((unsigned int)time(NULL));
	
	// Spawn a random zombie type up to a max number of 10. A zombie has an increasing chance of spawning each frame.
	if (zombies.size() < 10)
	{
		roll = rand() % spawnChance;

		if (roll <= 1)
		{
			SpawnRandomZombie();
			spawnChance = 25;
		}
		else
		{
			spawnChance -= 1;
		}
	}
	
	for (z = 0; z < zombies.size(); z++)
	{
		Zombie * this_zombie = zombies.at(z);		

		// Move the zombie
		this_zombie->move();
	}
	
	// Draw the image of the board on the screen
	board.drawBoard(zombies);
}

void GameEngine::SpawnRandomZombie()
{
	int roll, rx, ry;

	srand((unsigned int)time(NULL));
	rx = rand() % board_x_width;
	ry = rand() % board_y_height;

	roll = rand() % 4;

	if (roll == 0)
	{
		zombies.push_back(new Zombie(rx, ry, board_x_width, board_y_height));
	}
	else if (roll == 1)
	{
		zombies.push_back(new EastZombie(rx, ry, board_x_width, board_y_height));
	}
	else if (roll == 2)
	{
		zombies.push_back(new NorthZombie(rx, ry, board_x_width, board_y_height));
	}
	else
	{
		zombies.push_back(new RandomZombie(rx, ry, board_x_width, board_y_height));
	}
}

void GameEngine::Run()
{
	bool done = false;

	while (!done) // FIXME: Eventually, once the "people" class has been added, make it continue until there are no more people >:D
	{		
		// Execute the game tick for this frame
		Tick();

		// Freeze the game for a half second
		this_thread::sleep_for(chrono::milliseconds(500));
	}
}

GameEngine::GameEngine()
{
	board_x_width = board.getXWidth();
	board_y_height = board.getYHeight();
	spawnChance = 10;
}