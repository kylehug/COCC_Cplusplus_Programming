#include "GameEngine.h"

using namespace std;

void GameEngine::Tick()
{	
	unsigned int z, h;
	int zx, zy, hx, hy;
	
	// Human Actions
	for (h = 0; h < humans.size(); h++)
	{
		Human * this_human = humans.at(h);
		
		// Move human
		this_human->move();
	}
	
	// Zombie/Human Actions
	for (z = 0; z < zombies.size(); z++)
	{
		Zombie * this_zombie = zombies.at(z);
		zx = this_zombie->getPositionX();
		zy = this_zombie->getPositionY();

		// If the zombie overlaps a human, bite them, turning the human into a zombie. Nom Nom Nom! >:)
		for (h = 0; h < humans.size(); h++)
		{
			Human * this_human = humans.at(h);
			hx = this_human->getPositionX();
			hy = this_human->getPositionY();
			
			if ((zx == hx) && (zy == hy))
			{
				SpawnRandomZombie(hx, hy);
				humans.erase(humans.begin() + (signed)h);
			}
		}

		// Move Zombie
		this_zombie->move();
	}
	
	// Draw the image of the board on the screen
	board.drawBoard(zombies, humans);
}

void GameEngine::SpawnRandomZombie(int rx, int ry)
{
	int roll;

	srand((unsigned int)time(NULL));

	if (rx == -1)
	{
		rx = rand() % board_x_width;
	}
	
	if (ry == -1)
	{
		ry = rand() % board_y_height;
	}

	roll = rand() % 5;

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
	else // Random Zombies will spawn more often
	{
		zombies.push_back(new RandomZombie(rx, ry, board_x_width, board_y_height));
	}
}

void GameEngine::SpawnHuman(unsigned int spawnSeed)
{
	int rx, ry;

	srand(spawnSeed);
	rx = rand() % board_x_width;
	ry = rand() % board_y_height;

	humans.push_back(new Human(rx, ry, board_x_width, board_y_height));
}

void GameEngine::Run()
{
	bool done = false;

	while (!done)
	{		
		// Execute the game tick for this frame
		Tick();

		// Freeze the game for a half second
		this_thread::sleep_for(chrono::milliseconds(500));

		// End when humanity has been whiped out
		if (humans.size() == 0)
		{
			done = true;
			cout << "\n          GAME OVER";
			cout << "\n Humanity has been whiped out!";
			cout << "\n OH THE NON-EXISTENT HUMANITY!\n";
		}
	}
}

GameEngine::GameEngine()
{
	board_x_width = board.getXWidth();
	board_y_height = board.getYHeight();
	unsigned int i;
	int rx, ry;

	// Populate a random RandomZombie
	srand((unsigned int)time(NULL));
	rx = rand() % board_x_width;
	ry = rand() % board_y_height;
	zombies.push_back(new RandomZombie(rx, ry, board_x_width, board_y_height));
	
	// Populate a dozen humans
	for (i = 0; i < 12; i++)
	{
		SpawnHuman(i);
	}
}