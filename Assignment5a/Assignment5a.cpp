// COCC C++ - Kyle Hug - Assignment 5A
//
//	GOALS:
//	[ ] 1. Add a Player Class and Object to hold info about the player.
//	[X] 2. Add a Board Class and Object to hold info and funcitonality about the board.
//	[ ] 3. Add a Game Class and Object that has a reference to a Player and Board and manages, input, output and running the game in general.
//	
//	EXTRAS:
//	[ ] 1. Add a Monster Class to hold monsters and add combat.
//	[ ] 2. Add a second board layer to the Game that holds the items that can be picked up.
//	[ ] 3. Add walls to the terrain board layer that the user and monsters cannot pass through.
//	[ ] 4. Split out the classes into different header files and #include them.
//
//	NOTES FOR BEEJ:
//		I was having trouble getting a vector to work for storing the GameBoard GetPositionX and GetPositionY sizes. It seems I wasn't allowed to specify the size of the vector on declaration.


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

