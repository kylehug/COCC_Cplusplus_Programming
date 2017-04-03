
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
	switch (input.at(0))
	{
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

	// Clear the screen
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
				cout << ' ' << player.GetSymbol();

				// Check for gold. If found pick it up.
				if (goldMap[y][x].GetGoldValue() != 0)
				{
					player.ChangeGold(goldMap[y][x].GetGoldValue());
					goldMap[y][x].SetGoldValue(0);
				}
			}
			else if (goldMap[y][x].GetGoldValue() != 0)
			{
				cout << " $";
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
	int playerX;
	int playerY;
	int roll;
	unsigned int x, y;

	// Populate the Gold Map
	for (y = 0; y < BOARD_SIZE_Y; y++)
	{
		for (x = 0; x < BOARD_SIZE_X; x++)
		{
			roll = rand() % 6 + 1;
			if (roll > 5)
			{
				goldMap[y][x] = GameGold(x, y, rand() % 10 + 1);
			}
			else
			{
				goldMap[y][x] = GameGold(x, y, 0);
			}
		}
	}
	
	bool done = false;
	
	while (!done)
	{
		
		// Don't let the player position leave the bounds of the world
		playerX = player.GetPositionX();
		playerY = player.GetPositionY();

		if (playerX <= 0)
		{
			player.SetPositionX(0);
		}
		else if (playerX >= BOARD_SIZE_X)
		{
			player.SetPositionX(BOARD_SIZE_X - 1);
		}
		
		if (playerY <= 0)
		{
			player.SetPositionY(0);
		}
		else if (playerY >= BOARD_SIZE_Y)
		{
			player.SetPositionY(BOARD_SIZE_Y - 1);
		}

		DrawGame();
		done = ProcessInput();
	}
}

GameEngine::GameEngine()
{
	player.SetPosition(BOARD_SIZE_X / 2, BOARD_SIZE_Y / 2);
}