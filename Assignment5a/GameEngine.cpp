
#include <iostream>
#include <string>
#include "GameEngine.h"

bool GameEngine::ProcessInput()
{
	do {
		// FIXME: Validate user input
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
	unsigned int x, y;
	const unsigned int BOARD_SIZE_X = terrain.GetBoardSizeX();
	const unsigned int BOARD_SIZE_Y = terrain.GetBoardSizeY();

	// Clear the board
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	// Print the stats
	cout << " Player Gold: " << player.GetGold() << endl;
	
	// Draw the image
	for (y = 0; y < BOARD_SIZE_Y; y++)
	{
		for (x = 0; x < BOARD_SIZE_X; x++)
		{
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