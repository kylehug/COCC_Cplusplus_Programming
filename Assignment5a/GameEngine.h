// See GameCharacter for notes about classes.

#pragma once

#include <string>
#include "GameBoard.h"
#include "GamePlayer.h"

class GameEngine
{
private:

	string input;
	GameBoard terrain;
	GamePlayer player;

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