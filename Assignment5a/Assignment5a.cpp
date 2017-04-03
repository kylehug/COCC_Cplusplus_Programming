// COCC C++ - Kyle Hug - Assignment 5A
//
//	GOALS:
//	[X] 1. Add a Player Class and Object to hold info about the player.
//	[ ] 2. Add a Board Class and Object to hold info and funcitonality about the board.
//	[X] 3. Add a Game Class and Object that has a reference to a Player and Board and manages, input, output and running the game in general.
//	
//	EXTRAS:
//	[ ] 1. Add a Monster Class to hold monsters and add combat.
//	[X] 2. Add a second board layer to the Game that holds the items that can be picked up.
//	[ ] 3. Add walls to the terrain board layer that the user and monsters cannot pass through.
//	[X] 4. Split out the classes into different header files and #include them.
//
//	NOTES FOR BEEJ:
//		


#include <iostream>
#include <string>
#include "GameEngine.h"

using namespace std;

int main()
{
	GameEngine game;
	game.Run();
	return 0;
}

