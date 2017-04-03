// See GameCharacter for notes about classes.

#pragma once

#include <string>
#include "GameBoard.h"
#include "GamePlayer.h"
#include "GameGold.h"

class GameEngine
{
private:

	string input;
	GamePlayer player;
	static const unsigned int BOARD_SIZE_X = 16;
	static const unsigned int BOARD_SIZE_Y = 12;
	GameGold goldMap[BOARD_SIZE_Y][BOARD_SIZE_X];

	// Handles user input
	bool ProcessInput();

	// Draws the game world to the screen
	void DrawGame();

public:
	// Run the Game
	void Run();

	// Default Constructor
	GameEngine();
};