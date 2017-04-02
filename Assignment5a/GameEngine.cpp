
#include <time.h>
#include <iostream>
#include <string>
#include <vector>
#include "GameGold.h"
#include "GameEngine.h"

bool GameEngine::ProcessInput()
{
	do {
		cout << ">";
		getline(cin, input);
	}
	while (input.size() == 0);

	// Quit if the user enters quit
	if (input == "quit") return true;

	// Handle movement controls
	switch (input.at(0)) {
		case 'w':
			player.Move(0, -1);
			break;
		case 'a':
			player.Move(-1, 0);
			break;
		case 's':
			player.Move(0, 1);
			break;
		case 'd':
			player.Move(1, 0);
			break;
	}
	return false;
}

void GameEngine::DrawGame()
{
	const unsigned int BOARD_SIZE_X = terrain.GetBoardSizeX();
	const unsigned int BOARD_SIZE_Y = terrain.GetBoardSizeY();
	const int NUM_GOLD_PICKUPS = 50;
	vector<GameGold> goldPickups(NUM_GOLD_PICKUPS);
	unsigned int i, x, y;

	
	// Populate goldPickups
	for (i = 0; i < NUM_GOLD_PICKUPS; i++)
	{
		//srand(time(NULL));
		srand(time(NULL) + i);
		goldPickups.at(i) = GameGold(rand() % BOARD_SIZE_X + 1, rand() % BOARD_SIZE_Y + 1, rand() % 10 + 1);

		/*
		cout << "Gold Position: " << goldPickups.at(i).GetPositionX();
		cout << ", " << goldPickups.at(i).GetPositionY();
		cout << "\nGold Value: " << goldPickups.at(i).GetGoldValue() << "\n\n";
		*/
	}
	
	// Clear the board
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	// Print the stats
	cout << " Player Gold: " << player.GetGold() << endl;
	
	// Draw the image
	for (y = 0; y < BOARD_SIZE_Y; y++)
	{
		for (x = 0; x < BOARD_SIZE_X; x++)
		{
			/*
			for (i = 0; i < NUM_GOLD_PICKUPS; i++)
			{

			}
			*/
			
			if ((x == player.GetPositionX()) && (y == player.GetPositionY()))
			{		
				// Draw the player
				cout << player.GetSymbol() << ' ';
			}
			else
			{
				// Use periods to represent the empty space
				cout << " .";
			}
		}
		cout << endl;
	}
}

void GameEngine::Run()
{
	bool done = false;

	while (!done)
	{
		DrawGame();
		done = ProcessInput();
	}
}

GameEngine::GameEngine()
{
	terrain.SetBoardSize(32, 24);
	player.SetPosition(16, 12);
}